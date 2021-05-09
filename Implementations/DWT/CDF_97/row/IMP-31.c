// program for calculation of DWT based of Daubechies (9, 7) filter bank.
// 11/01/2007
//  Original version


#include  <stdio.h>
//#include  <stdlib.h>
//#include  <math.h>
#include  "pbmpak.h"
#include  "pbmpak.c"
//#include  <xmmintrin.h>
#define    N    2048
#define    M    N
  char *filein_name = "lena2048.pgm";
  char *fileou_name = "AF.pgm";
  int  result, ij;
  int  xsize,ysize,maxgray;
  int  *garray;
  long int   numbytes;
  unsigned long long  time_program[5];
  int      k, blocksize = 2048;                       // aggregation factor

  unsigned cyc_hi = 0;
  unsigned cyc_lo = 0;
  int i, j, jj, half_row, half_col;
  
  float in_image[N+8][M], ou_image[N+8][M];

  float low[] ={0.6029499018236360, 0.266864118442875, -0.078223266528990, -0.016864118442875, 0.026748757410810};
  float high[]={-0.591271763114250, -0.057543526228500, 0.091271763114250, 1.115087052457000};
//----------------------------------------------------------------------------------------------------------
 void access_counter(unsigned *hi,  unsigned *lo)
 {
   asm("rdtsc; mov %%edx, %0; mov  %%eax, %1"
        : "=r"  (*hi) , "=r"  (*lo)
        :  /* no input */
        : "%edx" , "%eax");
 }
//----------------------------------------------------------------------------------------------------------
void  start_counter()

{
    access_counter(&cyc_hi, &cyc_lo);
}
//----------------------------------------------------------------------------------------------------------
unsigned long long get_counter()
{

  unsigned ncyc_hi, ncyc_lo;
  unsigned hi, lo, borrow;
  unsigned long long  temp, result_cycle = 0;

  access_counter(&ncyc_hi, &ncyc_lo);
  lo = ncyc_lo - cyc_lo;
  borrow = cyc_lo > ncyc_lo;
  hi = ncyc_hi - cyc_hi - borrow;
  temp   = (unsigned long long) (hi);
  temp   = (temp <<= 32);
  result_cycle = (temp +  (unsigned long long) lo);
  if (result_cycle < 0) {
    printf("error: counter retures neg. value: %llu\n", result_cycle);
   }
   return result_cycle;
}
 //-----------------------------------------
int min(int x, int y) {
    if (x <= y)  return x;
    return y;
 }
/************************************************** ROW PROCESSING IN LEVEL 1 ***************************************/
void row_processing_level_1()
{
 for (i=0; i<N; i++)
   for(j=0, jj=4; jj<M - 4; j++, jj +=2)
   {
     ou_image[i][j]            = in_image[i][jj - 4] * low[4] + in_image[i][jj - 3] * low[3] +
                                 in_image[i][jj - 2] * low[2] + in_image[i][jj - 1] * low[1] +
                                 in_image[i][jj]     * low[0] +
                                 in_image[i][jj + 1] * low[1] + in_image[i][jj + 2] * low[2];
                                 in_image[i][jj + 3] * low[3] + in_image[i][jj + 4] * low[4];

     ou_image[i][j + half_col] = in_image[i][jj - 4] * high[2] + in_image[i][jj - 3] * high[1] +
                                 in_image[i][jj - 2] * high[0] + in_image[i][jj - 1] * high[3] +
                                 in_image[i][jj]     * high[0] +

                                 in_image[i][jj + 1] * high[1] +
                                 in_image[i][jj + 2] * high[2];

    }
}
//------------------------------------------------------------------------ with loop interchnage
void col_processing_level_1_loop_interchnage() {
  
  for (i=0,  jj=4; jj<N - 4; i++, jj +=2)
    for(j=0; j<M; j++)  {

     in_image[i][j]            =   ou_image[jj - 4][j] * low[4] + ou_image[jj - 3][j] * low[3] +
                                   ou_image[jj - 2][j] * low[2] + ou_image[jj - 1][j] * low[1] +
                                   ou_image[jj][j]     * low[0] +
                                   ou_image[jj + 1][j] * low[1] + ou_image[jj + 2][j] * low[2] +
                                   ou_image[jj + 3][j] * low[3] + ou_image[jj + 4][j] * low[4];

     in_image[i + half_row][j] = ou_image[jj - 4][j] * high[2] + ou_image[jj - 3][j] * high[1] +
                                 ou_image[jj - 2][j] * high[0] + ou_image[jj - 1][j] * high[3] +
                                 ou_image[jj][j]     * high[0] +
                                 ou_image[jj + 1][j] * high[1] +
                                 ou_image[jj + 2][j] * high[2];


      }
}
//---------------------------------------------Column processing using aggregation
 void col_processing_level_1_aggregation() {
   
  for (k=0; k<M; k+=blocksize)
   for (i=0,  jj=4; jj<N - 4; i++, jj +=2)
       for(j=k; j<min(M,k+blocksize); j++)  {
         in_image[i][j]            =   ou_image[jj - 4][j] * low[4] + ou_image[jj - 3][j] * low[3] +
                                       ou_image[jj - 2][j] * low[2] + ou_image[jj - 1][j] * low[1] +
                                       ou_image[jj][j]     * low[0] +
                                       ou_image[jj + 1][j] * low[1] + ou_image[jj + 2][j] * low[2] +
                                       ou_image[jj + 3][j] * low[3] + ou_image[jj + 4][j] * low[4];

         in_image[i + half_row][j] = ou_image[jj - 4][j] * high[2] + ou_image[jj - 3][j] * high[1] +
                                     ou_image[jj - 2][j] * high[0] + ou_image[jj - 1][j] * high[3] +
                                     ou_image[jj][j]     * high[0] +
                                     ou_image[jj + 1][j] * high[1] +
                                     ou_image[jj + 2][j] * high[2];
     }
}

//---------------------------------------------------------------------
 int  main(void) {
  int rep1; 
  result = pgmb_read ( filein_name, &xsize, &ysize, &maxgray,  &garray );
  if (result != 0)  { printf("!!!!...\n");  exit(1);}
  printf("\nxsize = %i\n\n",xsize);
  
 // half_row =  N / 2;      // with considering 64K aliasing
 half_row =  N / 2 + 1;  // to avoid  64K aliasing
 half_col =  M / 2;

 for (rep1 = 0; rep1 < 5; rep1++) {
   for (i=0; i<xsize; i++)
     for (j=0;j<ysize;j++)
       in_image[i][j]=(float) garray[j+i*xsize];
 
 start_counter();          //   Warmed-up cache
      row_processing_level_1();
 time_program[0] = get_counter();
 start_counter();
     row_processing_level_1();
 time_program[1] = get_counter();
 if (time_program[1] < time_program[0]) time_program[0] = time_program[1];
 //-----------------------------------------------
/*  start_counter();
       col_processing_level_1_normal();                        //  warmed up cache
  time_program[1] = get_counter();
  start_counter();
       col_processing_level_1_normal();
  time_program[2] = get_counter();
  if (time_program[2] < time_program[1]) time_program[1] = time_program[2];        */
  //-------------------------------
         time_program[1] = 0;
  start_counter();
         col_processing_level_1_loop_interchnage();                        //  warmed up cache
   time_program[2] = get_counter();
    start_counter();
         col_processing_level_1_loop_interchnage();
   time_program[3] = get_counter();
   if (time_program[3] < time_program[2]) time_program[2] = time_program[3];
    //-------------------------
   start_counter();
         col_processing_level_1_aggregation();                        //  warmed up cache
   time_program[3] = get_counter();
    start_counter();
         col_processing_level_1_aggregation();
   time_program[4] = get_counter();
   if (time_program[4] < time_program[3]) time_program[3] = time_program[4];
 }
 
 printf("\n (Row= %llu )  (Col-Normal= %llu )  (Col-Interchange= %llu  )  (Col-Aggregation= %llu )\n",
        time_program[0], time_program[1],   time_program[2] ,       time_program[3]);

 printf("\n Col_Normal/Row  = %3.1f                Col-Aggregation/Col-Interchange = %3.1f",
        ((float)time_program[1]) / time_program[0],  ((float)time_program[3]) / time_program[2]);

 printf("      Col_Aggregation/Row  = %3.1f\n\n", ((float)time_program[3]) / time_program[0]);
    
  //   Writting IMage in Output
 /*          for (i=0; i<xsize; i++)
     for (j=0;j<ysize;j++)
         garray[j+i*xsize]= (int) in_image[i][j];
    result= pgmb_write ( fileou_name, xsize,  ysize, maxgray, garray ) ;
   


 if (result != 0)  { printf("!!!...\n"); }
//close(fileou_name);   */     
return 0;
}

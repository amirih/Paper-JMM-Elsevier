// Program for Calcullating the Daub-4 transform
// 11/Sep/2007

#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include  "pbmpak.h"
#include  "pbmpak.c"
#define    N   512
#define    M   N
  char *filein_name = "lena.pgm";
  char *fileou_name = "AF.pgm";
  int  result, ij;
  int  xsize,ysize,maxgray;
  int  *garray;
  long int   numbytes;
  unsigned long long  time_program1, time_program2, time_program3, time_program4;
  int rep, i, j, jj, half_row, half_col, half_row_n64k;
  unsigned cyc_hi = 0;
  unsigned cyc_lo = 0;

  float in_image[N+3][M], ou_image[N+3][M];

  float low[] = {-0.1294, 0.2241, 0.8365, 0.4830};
  float high[]= {-0.4830, 0.8365, -0.2241, -0.1294};
//----------------------------------------------------------------------------------
 void access_counter(unsigned *hi,  unsigned *lo)
 {
   asm("rdtsc; mov %%edx, %0; mov  %%eax, %1"
        : "=r"  (*hi) , "=r"  (*lo)
        :  /* no input */
        : "%edx" , "%eax");
 }
//----------------------------------------------------------------------------------

void  start_counter() {
    access_counter(&cyc_hi, &cyc_lo);
}
//----------------------------------------------------------------------------------
 unsigned long long get_counter()    {
  unsigned ncyc_hi, ncyc_lo;
  unsigned hi, lo, borrow;
  unsigned long long  temp, result_cycle= 0;
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
//----------------------------------------------------------------------------------
void Horizontal_Filtering() {
 for (i=0; i<N; i++)
   for(j=0, jj=0; jj<M; j++, jj +=2)
   {
     ou_image[i][j]            = in_image[i][jj]     * low[0]  +  in_image[i][jj + 1] * low[1] +
                                 in_image[i][jj + 2] * low[2]  +  in_image[i][jj + 3] * low[3];

     ou_image[i][j + half_col] = in_image[i][jj]     * high[0] + in_image[i][jj  + 1] * high[1] +
                                  in_image[i][jj + 2] * high[2] + in_image[i][jj  + 3] * high[3];
   }
 }
//----------------------------------  Start of column processing function does not have 64K aliasing
 void Vertical_Filtering() {

   for (i=0,  jj=0; jj<N; i++, jj +=2)
      for(j=0; j<M; j++)
      {
        in_image[i][j]            = ou_image[jj][j]     * low[0] +  ou_image[jj + 1][j] * low[1] +
                                    ou_image[jj + 2][j] * low[2] +  ou_image[jj + 3][j] * low[3];

        in_image[i + half_row_n64k][j] = ou_image[jj][j]     * high[0] + ou_image[jj + 1][j] * high[1] +
                                         ou_image[jj + 2][j] * high[2] + ou_image[jj + 3][j] * high[3];
      }
}
/****************************************************     Start of Main Program    *******************************************/
 int  main(void) {
  result = pgmb_read ( filein_name, &xsize, &ysize, &maxgray,  &garray );
  if (result != 0)  { printf("!!!!...\n");  exit(1);}
  printf("xsize = %i\n",xsize);

 time_program1 =2000000000;
 time_program2 =0;

 time_program3 =2000000000;
 time_program4 =0;

 half_row_n64k = N/2 + 1;
 for (i=0; i<xsize; i++)
   for (j=0;j<ysize;j++) {
     in_image[i][j]=(float) garray[j+i*xsize];
     ou_image[i][j]=0.0;
   }

   start_counter();
       Horizontal_Filtering();
  time_program2 = get_counter();
  if (time_program2 < time_program1) time_program1 = time_program2;
  }
   start_counter();
       Vertical_Filtering();
     time_program4 = get_counter();
   if (time_program4 < time_program3) time_program3 = time_program4;
//}
 
 

 printf("\n               Horizontal_Filtering = %llu   \n               Vertical_Filtering   = %llu  \n",
      time_program1, time_program3); //   Writting IMage in Output


//   Writting Image in Output
    
   for (i=0; i<xsize; i++)
     for (j=0;j<ysize;j++)
         garray[j+i*xsize]= (int) in_image[i][j];

  result= pgmb_write ( fileou_name, xsize,  ysize, maxgray, garray ) ;
//  if (result != 0)  { printf("!!!...\n"); }  */
return 0;
}


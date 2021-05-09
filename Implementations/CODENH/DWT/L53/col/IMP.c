// This proram calcultes the lifting scheme of DWT using (5,3) filter and integer.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pbmpak.h"
#include  "pbmpak.c"
#include <limits.h>
#include <sys/time.h>

#define    N1   512
#define    M1   512

  char *filein_name = "lena.pgm";
  char *fileou_name = "Third.pgm";
  int result;
  int xsize,ysize,maxgray;
                                     
  int *garray;
  long int   numbytes;
  int i,j,jj;
  int N, M;
  long L,H;

  unsigned long long  time_program1, time_program2, time_program3, time_program4,
                      time_program5, time_program6, time_program7, time_program8;
  
  unsigned cyc_hi = 0;
  unsigned cyc_lo = 0;
  int rep, half_row, half_col,jj, ij;
  
  int in_image[N1][M1], ou_image[N1][M1], temp;
  
 // register int   temp;
 // register int *temp asm ("ax");
 ////////////////////////////////////////////////////////////////////////////////
 void access_counter(unsigned *hi,  unsigned *lo)
 {
   asm("rdtsc; mov %%edx, %0; mov  %%eax, %1"
        : "=r"  (*hi) , "=r"  (*lo)


        :  /* no input */
        : "%edx" , "%eax");
 }
//////////////////////////////////////////////////////////////////////////
void  start_counter()

{
    access_counter(&cyc_hi, &cyc_lo);
}
/////////////////////////////////////////////////////
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


 /////////////////////////////////////////////////////////////////////////////////////////////////////
  long random()
{
  static long randx=1;
  static double z=(double)0x7fffffff;
  long  i,j;
  double x;
  randx = (randx * 1103515245) + 12345;
  i= randx & 0x7ffffffe;
  x=((double)i)/z;
  x *=(L+H+1);
  j=x;
  return(j-L);
 }
 
/************ A **************************************    Start of horizontal filtering     *******************************************/
 void row_processing()
 {
   for (i=0; i< N; i++)
     for (j=1, jj=0; j<M; jj++, j +=2)                                                    
      {
         ou_image[i][jj + half_col] = in_image[i][j] -  ((in_image[i][j-1] + in_image[i][j+1]) >> 1);   //  Calculation of high-value
         ou_image[i][jj] = in_image[i][j-1] +  ((ou_image[i][jj + half_col] + ou_image[i][jj+ half_col - 1] + 2) >> 2);     // calculation of low value
      }
}
/************ B *********************************Vertical filtering ****************************************************/      
void col_processing()
{
  for (j=1, jj=0; j<N; jj++, j +=2)
    for (i=0; i<M; i++)
      {
        in_image[jj + half_row][i] = ou_image[j][i] -  ((ou_image[j-1][i] + ou_image[j+1][i]) >> 1);   //    Calculation of high-value
        in_image[jj][i] = ou_image[j-1][i] +  ((in_image[jj + half_row][i] + in_image[jj + half_row -1][i] + 2) >> 2);     //calculation of low value
      }
}  
/****************************************************************************************************/
               
int  main(void)
{
   //  Read Image
  result = pgmb_read ( filein_name, &xsize, &ysize, &maxgray,  &garray );
  if (result != 0)  { printf("!!!!...\n");  exit(1);}

//  printf("xsize = %i, ysize = %i, maxgray = %i\n", xsize, ysize, maxgray);
  printf("xsize = %i \n", xsize);

  time_program1 = 2000000000;
  time_program2 =0;

  time_program3 = 2000000000;
  time_program4 =0;
  
  time_program5 = 2000000000;
  time_program6 =0;

  time_program7 = 2000000000;
  time_program8 =0;
 N = N1;
 M = M1;
   
//for(ij=1; ij<3; ij++)
//{
  for (i=0; i<N; i++)
      for (j=0; j<M; j++)
          in_image[i][j] =   garray[j+i*xsize];
          
 cyc_hi = 0;
 cyc_lo = 0;
 
 half_row = N / 2;
 half_col = M / 2;

   ///*
 start_counter();   
    row_processing();
 time_program2 = get_counter();
 if (time_program2 < time_program1) time_program1 = time_program2;
           // */
           
 start_counter();
 //   row_processing();
 time_program2 = get_counter();
 if (time_program2 < time_program1) time_program1 = time_program2;


 start_counter();
    col_processing();
 time_program4 = get_counter();
 if (time_program4 < time_program3) time_program3 = time_program4;

 // /*
 start_counter();
  //  col_processing();
 time_program4 = get_counter();
 if (time_program4 < time_program3) time_program3 = time_program4;

  
//   level  2
   N = N/2;
   half_row = N/2;
   M = M/2;
   half_col = M/2;
   
    row_processing();
    col_processing();


     N = N/2;
   half_row = N/2;
   M = M/2;
   half_col = M/2;

    row_processing();
    col_processing();
    
/*
      for (i=0; i< N; i++)
         for (j=1, jj=0; j<M; jj++, j +=2)                                                     // /2
         {
           ou_image[i][jj + half_col] = in_image[i][j] -  ((in_image[i][j-1] + in_image[i][j+1]) >> 1);   //high
           ou_image[i][jj] = in_image[i][j-1] +  ((ou_image[i][jj + half_col] + ou_image[i][jj+ half_col - 1] + 2) >> 2);     //low
          }
    for (j=1, jj=0; j<N; jj++, j +=2)

       for (i=0; i<M; i++)
         {
           in_image[jj + half_row][i] = ou_image[j][i] -  ((ou_image[j-1][i] + ou_image[j+1][i]) >> 1);   //high
            in_image[jj][i] = ou_image[j-1][i] +  ((in_image[jj + half_row][i] + in_image[jj + half_row -1][i] + 2) >> 2);     //low

         }
    //*/
            /*
   start_counter();
      for (i=0; i< N; i++)
         for (j=1, jj=0; j<M; jj++, j +=2)                                                     // /2
         {
           ou_image[i][jj + half_col] = in_image[i][j] -  ((in_image[i][j-1] + in_image[i][j+1]) >> 1);   //high
           ou_image[i][jj] = in_image[i][j-1] +  ((ou_image[i][jj + half_col] + ou_image[i][jj+ half_col - 1] + 2) >> 2);     //low
          }
    for (j=1, jj=0; j<N; jj++, j +=2)
       for (i=0; i<M; i++)
         {
           in_image[jj + half_row][i] = ou_image[j][i] -  ((ou_image[j-1][i] + ou_image[j+1][i]) >> 1);   //high
           in_image[jj][i] = ou_image[j-1][i] +  ((in_image[jj + half_row][i] + in_image[jj + half_row -1][i] + 2) >> 2);     //low

         }
    time_program6 = get_counter();
    if (time_program6 < time_program5) time_program5 = time_program6;


    //level 3
   N = N/2;
   half_row = N/2;
   M = M/2;
   half_col = M/2;
   cyc_hi = 0;
   cyc_lo = 0;

     /*
       for (i=0; i< N; i++)
        for (j=1, jj=0; j<M; jj++, j +=2)                                                     // /2
         {


          ou_image[i][jj + half_col] = in_image[i][j] -  ((in_image[i][j-1] + in_image[i][j+1]) >> 1);   //high
          ou_image[i][jj] = in_image[i][j-1] +  ((ou_image[i][jj + half_col] + ou_image[i][jj+ half_col - 1] + 2) >> 2);     //low
         }
       for (j=1, jj=0; j<N; jj++, j +=2)
         for (i=0; i<M; i++)
         {
          in_image[jj + half_row][i] = ou_image[j][i] -  ((ou_image[j-1][i] + ou_image[j+1][i]) >> 1);   //high
          in_image[jj][i] = ou_image[j-1][i] +  ((in_image[jj + half_row][i] + in_image[jj + half_row -1][i] + 2) >> 2);     //low

         }
    // */
              /*
   start_counter();
      for (i=0; i< N; i++)
        for (j=1, jj=0; j<M; jj++, j +=2)                                                     // /2
         {
          ou_image[i][jj + half_col] = in_image[i][j] -  ((in_image[i][j-1] + in_image[i][j+1]) >> 1);   //high
          ou_image[i][jj] = in_image[i][j-1] +  ((ou_image[i][jj + half_col] + ou_image[i][jj+ half_col - 1] + 2) >> 2);     //low
         }
       for (j=1, jj=0; j<N; jj++, j +=2)
         for (i=0; i<M; i++)
         {
          in_image[jj + half_row][i] = ou_image[j][i] -  ((ou_image[j-1][i] + ou_image[j+1][i]) >> 1);   //high
          in_image[jj][i] = ou_image[j-1][i] +  ((in_image[jj + half_row][i] + in_image[jj + half_row -1][i] + 2) >> 2);     //low
         }

   time_program8 = get_counter();
   if (time_program8 < time_program7) time_program7 = time_program8;       */

 
  //}
    //rintf("time Row = %llu   col h = %llu  col L = %llu  \n",
     //      time_program1, time_program3,  time_program5);
      
    //printf(" SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n");                             
   //    printf("time Row = %llu   col = %llu  level 1 = %llu  level 2 = %llu   level 1+2 = %llu  level 3 = %llu level 1+2+3 = %llu \n",
     //          time_program1, time_program3,  time_program1 + time_program3,
       //        time_program5, time_program1 + time_program3 + time_program5, time_program7,
         //      time_program1 + time_program3 + time_program5 + time_program7);
   
       printf("\ncol row = %llu   col = %llu   Level 1 = %llu\n",time_program1, time_program3, time_program1 + time_program3);

//  printf(" EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n");             
// }
               
          
//   Writting IMage in Output                                            

  
          for (i=0; i<xsize; i++)
          for (j=0;j<ysize;j++)
           garray[j+i*xsize]=  in_image[i][j];


     result= pgmb_write ( fileou_name, xsize,  ysize, maxgray, garray ) ;

                     
 if (result != 0)  { printf("!!!...\n"); }
 //   printf("End\n");  
  //  getchar();
   
 // printf("\n Max = %4d  Min = %4d \n", max1, min1);           */
                                         
return 0;

}

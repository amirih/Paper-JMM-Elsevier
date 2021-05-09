// program for calculation of DWT based of Daubechies (9, 7) filter bank.
// 11/01/2007
//  Original version

#include "MAX.h"

#define    N    MAX1
#define    M    N

  int i, j, jj, half_row, half_col;
  
  float in_image[N][M], ou_image[N][M];

  float low[] ={0.6029499018236360, 0.266864118442875, -0.078223266528990, -0.016864118442875, 0.026748757410810};
  float high[]={-0.591271763114250, -0.057543526228500, 0.091271763114250, 1.115087052457000};
//------------------------------------------------------------------------ with loop interchnage
//void col_processing_level_1_loop_interchnage() {
  
//---------------------------------------------------------------------
 int  main(void) {
	 singleCore
    programName= "CDF97COL";

  
 // half_row =  N / 2;      // with considering 64K aliasing
 half_row =  N / 2 ;  // to avoid  64K aliasing
 half_col =  M / 2;

		assignImagef32(ou_image);
 
		begin_rdtsc
		for(j=0; j<M; j++)
			for (i=0,  jj=4; jj<N - 4; i++, jj +=2)
				  {

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
		end_rdtsc  
         printf ( "output = %f\n", in_image[N/2][M/2]);
         savefloatMatrixFileForOutPuts(in_image);
        
return 0;
}

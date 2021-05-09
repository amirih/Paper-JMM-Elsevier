// Program for Calcullating the Daub-4 transform


#include "MAX.h"

#define    N    MAX1
#define    M    N

 float low[] = {-0.1294, 0.2241, 0.8365, 0.4830};
 float high[]= {-0.4830, 0.8365, -0.2241, -0.1294};
  
int i, j, jj, half_row, half_col;
float in_image[N+4][M+4], ou_image[N+4][M+4];

 int  main(void) {
	 singleCore
  programName= "DUB4COLUnroll1";
	  
	half_row = N / 2;
	 half_col = M / 2;

		assignImagef32(ou_image);
 
		begin_rdtsc
			
			  for(j=0; j<M; j+=8)
			  for (i=0,  jj=0; jj<N; i++, jj +=2)
			  {
				 //j=0
				in_image[i][j]            = ou_image[jj][j]     * low[0] +  ou_image[jj + 1][j] * low[1] +
											ou_image[jj + 2][j] * low[2] +  ou_image[jj + 3][j] * low[3];

				in_image[i + half_row][j] = ou_image[jj][j]     * high[0] + ou_image[jj + 1][j] * high[1] +
												 ou_image[jj + 2][j] * high[2] + ou_image[jj + 3][j] * high[3]; 
												 
												 
				 //j=1
				in_image[i][j+1]            = ou_image[jj][j+1]     * low[0] +  ou_image[jj + 1][j+1] * low[1] +
											ou_image[jj + 2][j+1] * low[2] +  ou_image[jj + 3][j+1] * low[3];

				in_image[i + half_row][j+1] = ou_image[jj][j+1]     * high[0] + ou_image[jj + 1][j+1] * high[1] +
												 ou_image[jj + 2][j+1] * high[2] + ou_image[jj + 3][j+1] * high[3]; 
												 
												 
				 //j=2
				in_image[i][j+2]            = ou_image[jj][j+2]     * low[0] +  ou_image[jj + 1][j+2] * low[1] +
											ou_image[jj + 2][j+2] * low[2] +  ou_image[jj + 3][j+2] * low[3];

				in_image[i + half_row][j+2] = ou_image[jj][j+2]     * high[0] + ou_image[jj + 1][j+2] * high[1] +
												 ou_image[jj + 2][j+2] * high[2] + ou_image[jj + 3][j+2] * high[3]; 
												 
												 
				 //j=3
				in_image[i][j+3]            = ou_image[jj][j+3]     * low[0] +  ou_image[jj + 1][j+3] * low[1] +
											ou_image[jj + 2][j+3] * low[2] +  ou_image[jj + 3][j+3] * low[3];

				in_image[i + half_row][j+3] = ou_image[jj][j+3]     * high[0] + ou_image[jj + 1][j+3] * high[1] +
												 ou_image[jj + 2][j+3] * high[2] + ou_image[jj + 3][j+3] * high[3]; 
												 
												 
				 //j=4
				in_image[i][j+4]            = ou_image[jj][j+4]     * low[0] +  ou_image[jj + 1][j+4] * low[1] +
											ou_image[jj + 2][j+4] * low[2] +  ou_image[jj + 3][j+4] * low[3];

				in_image[i + half_row][j+4] = ou_image[jj][j+4]     * high[0] + ou_image[jj + 1][j+4] * high[1] +
												 ou_image[jj + 2][j+4] * high[2] + ou_image[jj + 3][j+4] * high[3]; 
												 
												 
				 //j=5
				in_image[i][j+5]            = ou_image[jj][j+5]     * low[0] +  ou_image[jj + 1][j+5] * low[1] +
											ou_image[jj + 2][j+5] * low[2] +  ou_image[jj + 3][j+5] * low[3];

				in_image[i + half_row][j+5] = ou_image[jj][j+5]     * high[0] + ou_image[jj + 1][j+5] * high[1] +
												 ou_image[jj + 2][j+5] * high[2] + ou_image[jj + 3][j+5] * high[3]; 
												 
												 
				 //j=6
				in_image[i][j+6]            = ou_image[jj][j+6]     * low[0] +  ou_image[jj + 1][j+6] * low[1] +
											ou_image[jj + 2][j+6] * low[2] +  ou_image[jj + 3][j+6] * low[3];

				in_image[i + half_row][j+6] = ou_image[jj][j+6]     * high[0] + ou_image[jj + 1][j+6] * high[1] +
												 ou_image[jj + 2][j+6] * high[2] + ou_image[jj + 3][j+6] * high[3]; 
												 
				 //j=7
				in_image[i][j+7]            = ou_image[jj][j+7]     * low[0] +  ou_image[jj + 1][j+7] * low[1] +
											ou_image[jj + 2][j+7] * low[2] +  ou_image[jj + 3][j+7] * low[3];

				in_image[i + half_row][j+7] = ou_image[jj][j+7]     * high[0] + ou_image[jj + 1][j+7] * high[1] +
												 ou_image[jj + 2][j+7] * high[2] + ou_image[jj + 3][j+7] * high[3]; 
				
												 
												 							 
			  }
      
		end_rdtsc  
		                  printf ( "output = %f\n", in_image[N/2][M/2]);
                  savefloatMatrixFileForOutPuts(in_image);

         
return 0;
}

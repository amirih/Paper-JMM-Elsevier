// Program for Calcullating the Daub-4 transform


#include "MAX.h"

#define    N    MAX1
#define    M    N

 float low[] = {-0.1294, 0.2241, 0.8365, 0.4830};
 float high[]= {-0.4830, 0.8365, -0.2241, -0.1294};
  
int i, j, jj, half_row, half_col;
float in_image[N+3][M+4], ou_image[N+3][M+4];

 int  main(void) {
	 singleCore
  programName= "DUB4COL ";
	  
	half_row = N / 2;
	 half_col = M / 2;

		assignImagef32(ou_image);
 
		begin_rdtsc
			
			  for(j=0; j<M; j++)
			  for (i=0,  jj=0; jj<N; i++, jj +=2)
			  {
				in_image[i][j]            = ou_image[jj][j]     * low[0] +  ou_image[jj + 1][j] * low[1] +
											ou_image[jj + 2][j] * low[2] +  ou_image[jj + 3][j] * low[3];

				in_image[i + half_row][j] = ou_image[jj][j]     * high[0] + ou_image[jj + 1][j] * high[1] +
												 ou_image[jj + 2][j] * high[2] + ou_image[jj + 3][j] * high[3];
			  }
      
		end_rdtsc  
		                  printf ( "output = %f\n", in_image[N/2][M/2]);
		                                    savefloatMatrixFileForOutPuts(in_image);


         
return 0;
}

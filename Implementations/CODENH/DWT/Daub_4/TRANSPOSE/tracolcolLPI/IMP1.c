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
		programName= "DUB4FULTRACOLCOLLPI";

		half_row = N / 2;
		half_col = M / 2;

		int i, j;
		float swap = 0;	

		assignImagef32(in_image);
 
		begin_rdtsc
		
		//Transpose
		for (i=0; i<MAX1; i++)
			for(j=0; j<i; j++){
				swap = in_image[i][j];
				in_image[i][j] = in_image[j][i];
				in_image[j][i]=swap;
			}
		//column processing on transposed image
	
		  for(j=0; j<M; j++)
		  	for (i=0,  jj=0; jj<N; i++, jj +=2)
		  {
			ou_image[i][j]            = in_image[jj][j]     * low[0] +  in_image[jj + 1][j] * low[1] +
										in_image[jj + 2][j] * low[2] +  in_image[jj + 3][j] * low[3];

			ou_image[i + half_row][j] = in_image[jj][j]     * high[0] + in_image[jj + 1][j] * high[1] +
											 in_image[jj + 2][j] * high[2] + in_image[jj + 3][j] * high[3];
		  }
			//col processing
			
			  for(j=0; j<M; j++)
			  for (i=0,  jj=0; jj<N; i++, jj +=2)
			  {
				in_image[i][j]            = ou_image[jj][j]     * low[0] +  ou_image[jj + 1][j] * low[1] +
											ou_image[jj + 2][j] * low[2] +  ou_image[jj + 3][j] * low[3];

				in_image[i + half_row][j] = ou_image[jj][j]     * high[0] + ou_image[jj + 1][j] * high[1] +
												 ou_image[jj + 2][j] * high[2] + ou_image[jj + 3][j] * high[3];
			  }
			  
      
		end_rdtsc  
                  printf ( "output = %f\n", in_image[N/2][M/2]);                                    savefloatMatrixFileForOutPuts(in_image);


return 0;
}

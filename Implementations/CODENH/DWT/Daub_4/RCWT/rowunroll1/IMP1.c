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
		programName= "DUB4ROWunrol1";

		half_row = N / 2;
		half_col = M / 2;

		assignImagef32(in_image);
 
		begin_rdtsc
			for (i=0; i<N; i+=8)
			   for(j=0, jj=0; jj<M; j++, jj +=2)
			   {
				   //i=0
				   
				 ou_image[i][j]            = in_image[i][jj]     * low[0]  +  in_image[i][jj + 1] * low[1] +
											 in_image[i][jj + 2] * low[2]  +  in_image[i][jj + 3] * low[3];

				 ou_image[i][j + half_col] = in_image[i][jj]     * high[0] + in_image[i][jj  + 1] * high[1] +
											  in_image[i][jj + 2] * high[2] + in_image[i][jj  + 3] * high[3];
											  
											  //i=1
				   
				 ou_image[i+1][j]            = in_image[i+1][jj]     * low[0]  +  in_image[i+1][jj + 1] * low[1] +
											 in_image[i+1][jj + 2] * low[2]  +  in_image[i+1][jj + 3] * low[3];

				 ou_image[i+1][j + half_col] = in_image[i+1][jj]     * high[0] + in_image[i+1][jj  + 1] * high[1] +
											  in_image[i+1][jj + 2] * high[2] + in_image[i+1][jj  + 3] * high[3];
											  
											  //i=2
				   
				 ou_image[i+2][j]            = in_image[i+2][jj]     * low[0]  +  in_image[i+2][jj + 1] * low[1] +
											 in_image[i+2][jj + 2] * low[2]  +  in_image[i+2][jj + 3] * low[3];

				 ou_image[i+2][j + half_col] = in_image[i+2][jj]     * high[0] + in_image[i+2][jj  + 1] * high[1] +
											  in_image[i+2][jj + 2] * high[2] + in_image[i+2][jj  + 3] * high[3];
											  
											  //i=3
				   
				 ou_image[i+3][j]            = in_image[i+3][jj]     * low[0]  +  in_image[i+3][jj + 1] * low[1] +
											 in_image[i+3][jj + 2] * low[2]  +  in_image[i+3][jj + 3] * low[3];

				 ou_image[i+3][j + half_col] = in_image[i+3][jj]     * high[0] + in_image[i+3][jj  + 1] * high[1] +
											  in_image[i+3][jj + 2] * high[2] + in_image[i+3][jj  + 3] * high[3];
											  
											  //i=4
				   
				 ou_image[i+4][j]            = in_image[i+4][jj]     * low[0]  +  in_image[i+4][jj + 1] * low[1] +
											 in_image[i+4][jj + 2] * low[2]  +  in_image[i+4][jj + 3] * low[3];

				 ou_image[i+4][j + half_col] = in_image[i+4][jj]     * high[0] + in_image[i+4][jj  + 1] * high[1] +
											  in_image[i+4][jj + 2] * high[2] + in_image[i+4][jj  + 3] * high[3];
											  
											  //i=5
				   
				 ou_image[i+5][j]            = in_image[i+5][jj]     * low[0]  +  in_image[i+5][jj + 1] * low[1] +
											 in_image[i+5][jj + 2] * low[2]  +  in_image[i+5][jj + 3] * low[3];

				 ou_image[i+5][j + half_col] = in_image[i+5][jj]     * high[0] + in_image[i+5][jj  + 1] * high[1] +
											  in_image[i+5][jj + 2] * high[2] + in_image[i+5][jj  + 3] * high[3];
											  
											  //i=6
				   
				 ou_image[i+6][j]            = in_image[i+6][jj]     * low[0]  +  in_image[i+6][jj + 1] * low[1] +
											 in_image[i+6][jj + 2] * low[2]  +  in_image[i+6][jj + 3] * low[3];

				 ou_image[i+6][j + half_col] = in_image[i+6][jj]     * high[0] + in_image[i+6][jj  + 1] * high[1] +
											  in_image[i+6][jj + 2] * high[2] + in_image[i+6][jj  + 3] * high[3];
											  
											  //i=7
				   
				 ou_image[i+7][j]            = in_image[i+7][jj]     * low[0]  +  in_image[i+7][jj + 1] * low[1] +
											 in_image[i+7][jj + 2] * low[2]  +  in_image[i+7][jj + 3] * low[3];

				 ou_image[i+7][j + half_col] = in_image[i+7][jj]     * high[0] + in_image[i+7][jj  + 1] * high[1] +
											  in_image[i+7][jj + 2] * high[2] + in_image[i+7][jj  + 3] * high[3];
			   }
      
		end_rdtsc  
                  printf ( "output = %f\n", ou_image[N/2][M/2]);                                    savefloatMatrixFileForOutPuts(ou_image);


return 0;
}

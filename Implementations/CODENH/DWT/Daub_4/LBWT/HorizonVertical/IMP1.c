// Program for Calcullating the Daub-4 transform


#include "MAX.h"
#define    N    MAX1
#define    M    N



 float low[] = {-0.1294, 0.2241, 0.8365, 0.4830};
 float high[]= {-0.4830, 0.8365, -0.2241, -0.1294};
  
int i, j, k, ii, jj, half_row, half_col;
float in_image[N][M], ou_image[N][M], BufLow[4][M]={0};

 int  main(void) {
		singleCore
		programName= "DUB4FULBothHandV";

		half_row = N / 2;
		half_col = M / 2;

		assignImagef32(in_image);
 		savefloatMatrixFileName(in_image, "inputs");

		begin_rdtsc
			/*for (i=0, ii=0; i<N; ii++, i +=2) {
				k = ( ii % 2 ) * 2;
				for(j=0, jj=0; jj<M; j++, jj +=2) {
					BufLow[k][jj]  = in_image[i][jj] * low[0]+ in_image[i][jj + 1] * low[1]+ in_image[i][jj + 2]* low[2]+ in_image[i][jj + 3] * low[3];
					printf("1: BufLow[%d][%d] = %lf\n", k,jj,BufLow[k][jj]);
					
					BufLow[k][jj + 1]= in_image[i][jj]* high[0]+ in_image[i][jj + 1] * high[1] +in_image[i][jj + 2]* high[2]+ in_image[i][jj + 3] * high[3];
					printf("2: BufLow[%d][%d] = %lf\n", k,jj+1,BufLow[k][jj+1]);
					
					BufLow[k+1][jj]= in_image[i+1][jj]* low[0]+in_image[i+1][jj + 1] * low[1]+in_image[i+1][jj + 2]* low[2]+in_image[i+1][jj + 3] * low[3];
					printf("3: BufLow[%d][%d] = %lf\n", k+1,jj,BufLow[k+1][jj]);
					
					BufLow[k+1][jj + 1]= in_image[i+1][jj]* high[0] + in_image[i+1][jj+ 1] * high[1] +in_image[i+1][jj + 2]* high[2] + in_image[i+1][jj+ 3] * high[3];
					printf("4: BufLow[%d][%d] = %lf\n", k+1,jj+1,BufLow[k+1][jj+1]);
				}
				
			for(j=0, jj=0; jj<M; j++, jj +=2) {
				ou_image[ii][j]= BufLow[0][jj]* low[0]+BufLow[1][jj] * low[1]+BufLow[2][jj]	* low[2]+BufLow[3][jj] * low[3];
				printf("1: ou_image[%d][%d] = %lf\n", ii,j,ou_image[ii][j]);
				
				ou_image[ii + N/2][j] = BufLow[0][jj]* high[0] +BufLow[1][jj] * high[1] +BufLow[2][jj]* high[2] +BufLow[3][jj] * high[3];
				printf("2: ou_image[%d][%d] = %lf\n", ii+N/2,j,ou_image[ii+N/2][j]);
				
				ou_image[ii][j + M/2]= BufLow[0][jj + 1]* low[0] +BufLow[1][jj + 1] * low[1]+BufLow[2][jj + 1]* low[2] +BufLow[3][jj + 1] * low[3];
				printf("3: ou_image[%d][%d] = %lf\n", ii,j+M/2,ou_image[ii][j+M/2]);
				
				ou_image[ii + N/2][j + M/2] = BufLow[0][jj + 1] * high[0] + BufLow[1][jj + 1] * high[1] +BufLow[2][jj + 1] * high[2] + BufLow[2][jj + 1] * high[3];
				printf("3: ou_image[%d][%d] = %lf\n", ii+N/2,j+M/2,ou_image[ii+N/2][j+M/2]);
				}
			}*/
			
			for (i=0, ii=0; i<N; ii++, i +=2) {
			   k = ( ii % 2 ) * 2;
			   for(j=0, jj=0; jj<M; j++, jj +=2) {

					BufLow[k][jj]  		= in_image[i][jj]     * low[0]  +  in_image[i][jj + 1] * low[1] +
										in_image[i][jj + 2] * low[2]  +  in_image[i][jj + 3] * low[3];
					BufLow[k][jj + 1]  	= in_image[i][jj]     * high[0] + in_image[i][jj  + 1] * high[1] +
										 in_image[i][jj + 2] * high[2] + in_image[i][jj  + 3] * high[3];

					BufLow[k+1][jj]  	= in_image[i+1][jj]     * low[0]  +  in_image[i+1][jj + 1] * low[1] +
									   in_image[i+1][jj + 2] * low[2]  +  in_image[i+1][jj + 3] * low[3];
					BufLow[k+1][jj + 1]  = in_image[i+1][jj]     * high[0] + in_image[i+1][jj  + 1] * high[1] +
										   in_image[i+1][jj + 2] * high[2] + in_image[i+1][jj  + 3] * high[3];
				  }
				   for(j=0, jj=0; jj<M; j++, jj +=2) {
			  

					ou_image[ii][j]  = BufLow[0][jj]     * low[0] +  BufLow[1][jj] * low[1] +
									   BufLow[2][jj]     * low[2] +  BufLow[3][jj] * low[3];
					ou_image[ii + half_row][j] = BufLow[0][jj] * high[0] + BufLow[1][jj] * high[1] +
													  BufLow[2][jj] * high[2] + BufLow[3][jj] * high[3];

					ou_image[ii][j + half_row]  = BufLow[0][jj + 1]  * low[0] +  BufLow[1][jj + 1] * low[1] +
											  BufLow[2][jj + 1]  * low[2] +  BufLow[3][jj + 1] * low[3];

					ou_image[ii + half_row][j + half_row] = BufLow[0][jj + 1] * high[0] + BufLow[1][jj + 1] * high[1] +
														  BufLow[2][jj + 1] * high[2] + BufLow[2][jj + 1] * high[3];

			  }
		  }
		
			   
		end_rdtsc  
                  printf ( "output = %f\n", ou_image[N/2][M/2]);
                  savefloatMatrixFileForOutPuts(ou_image);


return 0;
}

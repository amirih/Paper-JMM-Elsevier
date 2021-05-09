// Program for Calcullating the Daub-4 transform


#include "MAX.h"
#define    N    MAX1
#define    M    N



 float low[] = {-0.1294, 0.2241, 0.8365, 0.4830};
 float high[]= {-0.4830, 0.8365, -0.2241, -0.1294};
  
int i, j, k, ii, jj, half_row, half_col;
float in_image[N+4][M+4], ou_image[N+4][M+4], BufLow[4][M+4];

 int  main(void) {
		singleCore
		programName= "DUB4FULBothHandVunroll2";

		half_row = N / 2;
		half_col = M / 2;

		assignImagef32(in_image);
 
		begin_rdtsc
			for (i=0, ii=0; i<N; ii++, i +=2) {
				k = ( ii % 2 ) * 2;
				for(j=0, jj=0; jj<M; j+=8, jj +=16) {
					//j=0 jj=0
					BufLow[k][jj]  = in_image[i][jj] * low[0]+ in_image[i][jj + 1] * low[1]+ in_image[i][jj + 2]* low[2]+ in_image[i][jj + 3] * low[3];
					BufLow[k][jj + 1]= in_image[i][jj]* high[0]+ in_image[i][jj + 1] * high[1] +in_image[i][jj + 2]* high[2]+ in_image[i][jj + 3] * high[3];
					BufLow[k+1][jj]= in_image[i+1][jj]* low[0]+in_image[i+1][jj + 1] * low[1]+in_image[i+1][jj + 2]* low[2]+in_image[i+1][jj + 3] * low[3];
					BufLow[k+1][jj + 1]= in_image[i+1][jj]* high[0] + in_image[i+1][jj+ 1] * high[1] +in_image[i+1][jj + 2]* high[2] + in_image[i+1][jj+ 3] * high[3];
					
					//j+1 jj+2
					BufLow[k][jj+2]      = in_image[i][jj+2] * low[0]+ in_image[i][jj+2 + 1] * low[1]+ in_image[i][jj+2 + 2]* low[2]+ in_image[i][jj+2 + 3] * low[3];
					BufLow[k][jj+2 + 1]  = in_image[i][jj+2]* high[0]+ in_image[i][jj+2 + 1] * high[1] +in_image[i][jj+2 + 2]* high[2]+ in_image[i][jj+2 + 3] * high[3];
					BufLow[k+1][jj+2]    = in_image[i+1][jj+2]* low[0]+in_image[i+1][jj+2 + 1] * low[1]+in_image[i+1][jj+2 + 2]* low[2]+in_image[i+1][jj+2 + 3] * low[3];
					BufLow[k+1][jj+2 + 1]= in_image[i+1][jj+2]* high[0] + in_image[i+1][jj+2+ 1] * high[1] +in_image[i+1][jj+2 + 2]* high[2] + in_image[i+1][jj+2+ 3] * high[3];
					
					//j+2 jj+4
					BufLow[k][jj+4]  = in_image[i][jj+4] * low[0]+ in_image[i][jj+4 + 1] * low[1]+ in_image[i][jj+4 + 2]* low[2]+ in_image[i][jj+4 + 3] * low[3];
					BufLow[k][jj+4 + 1]= in_image[i][jj+4]* high[0]+ in_image[i][jj+4 + 1] * high[1] +in_image[i][jj+4 + 2]* high[2]+ in_image[i][jj+4 + 3] * high[3];
					BufLow[k+1][jj+4]= in_image[i+1][jj+4]* low[0]+in_image[i+1][jj+4 + 1] * low[1]+in_image[i+1][jj+4 + 2]* low[2]+in_image[i+1][jj+4 + 3] * low[3];
					BufLow[k+1][jj+4 + 1]= in_image[i+1][jj+4]* high[0] + in_image[i+1][jj+4+ 1] * high[1] +in_image[i+1][jj+4 + 2]* high[2] + in_image[i+1][jj+4+ 3] * high[3];
					
					//j+3 jj+6
					BufLow[k][jj+6]  = in_image[i][jj+6] * low[0]+ in_image[i][jj+6 + 1] * low[1]+ in_image[i][jj+6 + 2]* low[2]+ in_image[i][jj+6 + 3] * low[3];
					BufLow[k][jj+6 + 1]= in_image[i][jj+6]* high[0]+ in_image[i][jj+6 + 1] * high[1] +in_image[i][jj+6 + 2]* high[2]+ in_image[i][jj+6 + 3] * high[3];
					BufLow[k+1][jj+6]= in_image[i+1][jj+6]* low[0]+in_image[i+1][jj+6 + 1] * low[1]+in_image[i+1][jj+6 + 2]* low[2]+in_image[i+1][jj+6 + 3] * low[3];
					BufLow[k+1][jj+6 + 1]= in_image[i+1][jj+6]* high[0] + in_image[i+1][jj+6+ 1] * high[1] +in_image[i+1][jj+6 + 2]* high[2] + in_image[i+1][jj+6+ 3] * high[3];
					
					//j+4 jj+8
					BufLow[k][jj+8]  = in_image[i][jj+8] * low[0]+ in_image[i][jj+8 + 1] * low[1]+ in_image[i][jj+8 + 2]* low[2]+ in_image[i][jj+8 + 3] * low[3];
					BufLow[k][jj+8 + 1]= in_image[i][jj+8]* high[0]+ in_image[i][jj+8 + 1] * high[1] +in_image[i][jj+8 + 2]* high[2]+ in_image[i][jj+8 + 3] * high[3];
					BufLow[k+1][jj+8]= in_image[i+1][jj+8]* low[0]+in_image[i+1][jj+8 + 1] * low[1]+in_image[i+1][jj+8 + 2]* low[2]+in_image[i+1][jj+8 + 3] * low[3];
					BufLow[k+1][jj+8 + 1]= in_image[i+1][jj+8]* high[0] + in_image[i+1][jj+8+ 1] * high[1] +in_image[i+1][jj+8 + 2]* high[2] + in_image[i+1][jj+8+ 3] * high[3];
					
					//j+5 jj+10
					BufLow[k][jj+10]  = in_image[i][jj+10] * low[0]+ in_image[i][jj+10 + 1] * low[1]+ in_image[i][jj+10 + 2]* low[2]+ in_image[i][jj+10 + 3] * low[3];
					BufLow[k][jj+10 + 1]= in_image[i][jj+10]* high[0]+ in_image[i][jj+10 + 1] * high[1] +in_image[i][jj+10 + 2]* high[2]+ in_image[i][jj+10 + 3] * high[3];
					BufLow[k+1][jj+10]= in_image[i+1][jj+10]* low[0]+in_image[i+1][jj+10 + 1] * low[1]+in_image[i+1][jj+10 + 2]* low[2]+in_image[i+1][jj+10 + 3] * low[3];
					BufLow[k+1][jj+10 + 1]= in_image[i+1][jj+10]* high[0] + in_image[i+1][jj+10+ 1] * high[1] +in_image[i+1][jj+10 + 2]* high[2] + in_image[i+1][jj+10+ 3] * high[3];
					
					//j+6 jj+12
					BufLow[k][jj+12]  = in_image[i][jj+12] * low[0]+ in_image[i][jj+12 + 1] * low[1]+ in_image[i][jj+12 + 2]* low[2]+ in_image[i][jj+12 + 3] * low[3];
					BufLow[k][jj+12 + 1]= in_image[i][jj+12]* high[0]+ in_image[i][jj+12 + 1] * high[1] +in_image[i][jj+12 + 2]* high[2]+ in_image[i][jj+12 + 3] * high[3];
					BufLow[k+1][jj+12]= in_image[i+1][jj+12]* low[0]+in_image[i+1][jj+12 + 1] * low[1]+in_image[i+1][jj+12 + 2]* low[2]+in_image[i+1][jj+12 + 3] * low[3];
					BufLow[k+1][jj+12 + 1]= in_image[i+1][jj+12]* high[0] + in_image[i+1][jj+12+ 1] * high[1] +in_image[i+1][jj+12 + 2]* high[2] + in_image[i+1][jj+12+ 3] * high[3];
					
					//j+7 jj+14
					BufLow[k][jj+14]  = in_image[i][jj+14] * low[0]+ in_image[i][jj+14 + 1] * low[1]+ in_image[i][jj+14 + 2]* low[2]+ in_image[i][jj+14 + 3] * low[3];
					BufLow[k][jj+14 + 1]= in_image[i][jj+14]* high[0]+ in_image[i][jj+14 + 1] * high[1] +in_image[i][jj+14 + 2]* high[2]+ in_image[i][jj+14 + 3] * high[3];
					BufLow[k+1][jj+14]= in_image[i+1][jj+14]* low[0]+in_image[i+1][jj+14 + 1] * low[1]+in_image[i+1][jj+14 + 2]* low[2]+in_image[i+1][jj+14 + 3] * low[3];
					BufLow[k+1][jj+14 + 1]= in_image[i+1][jj+14]* high[0] + in_image[i+1][jj+14+ 1] * high[1] +in_image[i+1][jj+14 + 2]* high[2] + in_image[i+1][jj+14+ 3] * high[3];
				}
				
			for(j=0, jj=0; jj<M; j+=8, jj +=16) {
				
				//j+0 jj+0
				ou_image[ii][j]= BufLow[0][jj]* low[0]+BufLow[1][jj] * low[1]+BufLow[2][jj]	* low[2]+BufLow[3][jj] * low[3];
				ou_image[ii + N/2][j] = BufLow[0][jj]* high[0] +BufLow[1][jj] * high[1] +BufLow[2][jj]* high[2] +BufLow[3][jj] * high[3];
				ou_image[ii][j + M/2]= BufLow[0][jj + 1]* low[0] +BufLow[1][jj + 1] * low[1]+BufLow[2][jj + 1]* low[2] +BufLow[3][jj + 1] * low[3];
				ou_image[ii + N/2][j + M/2] = BufLow[0][jj + 1] * high[0] + BufLow[1][jj + 1] * high[1] +BufLow[2][jj + 1] * high[2] + BufLow[2][jj + 1] * high[3];
				
				//j+1 jj+2
				ou_image[ii][j+1]= BufLow[0][jj+2]* low[0]+BufLow[1][jj+2] * low[1]+BufLow[2][jj+2]	* low[2]+BufLow[3][jj+2] * low[3];
				ou_image[ii + N/2][j+1] = BufLow[0][jj+2]* high[0] +BufLow[1][jj+2] * high[1] +BufLow[2][jj+2]* high[2] +BufLow[3][jj+2] * high[3];
				ou_image[ii][j+1 + M/2]= BufLow[0][jj+2 + 1]* low[0] +BufLow[1][jj+2 + 1] * low[1]+BufLow[2][jj+2 + 1]* low[2] +BufLow[3][jj+2 + 1] * low[3];
				ou_image[ii + N/2][j+1 + M/2] = BufLow[0][jj+2 + 1] * high[0] + BufLow[1][jj+2 + 1] * high[1] +BufLow[2][jj+2 + 1] * high[2] + BufLow[2][jj+2 + 1] * high[3];
				
				//j+2 jj+4
				ou_image[ii][j+2]= BufLow[0][jj+4]* low[0]+BufLow[1][jj+4] * low[1]+BufLow[2][jj+4]	* low[2]+BufLow[3][jj+4] * low[3];
				ou_image[ii + N/2][j+2] = BufLow[0][jj+4]* high[0] +BufLow[1][jj+4] * high[1] +BufLow[2][jj+4]* high[2] +BufLow[3][jj+4] * high[3];
				ou_image[ii][j+2 + M/2]= BufLow[0][jj+4 + 1]* low[0] +BufLow[1][jj+4 + 1] * low[1]+BufLow[2][jj+4 + 1]* low[2] +BufLow[3][jj+4 + 1] * low[3];
				ou_image[ii + N/2][j+2 + M/2] = BufLow[0][jj+4 + 1] * high[0] + BufLow[1][jj+4 + 1] * high[1] +BufLow[2][jj+4 + 1] * high[2] + BufLow[2][jj+4 + 1] * high[3];
				
				//j+3 jj+6
				ou_image[ii][j+3]= BufLow[0][jj+6]* low[0]+BufLow[1][jj+6] * low[1]+BufLow[2][jj+6]	* low[2]+BufLow[3][jj+6] * low[3];
				ou_image[ii + N/2][j+3] = BufLow[0][jj+6]* high[0] +BufLow[1][jj+6] * high[1] +BufLow[2][jj+6]* high[2] +BufLow[3][jj+6] * high[3];
				ou_image[ii][j+3 + M/2]= BufLow[0][jj+6 + 1]* low[0] +BufLow[1][jj+6 + 1] * low[1]+BufLow[2][jj+6 + 1]* low[2] +BufLow[3][jj+6 + 1] * low[3];
				ou_image[ii + N/2][j+3 + M/2] = BufLow[0][jj+6 + 1] * high[0] + BufLow[1][jj+6 + 1] * high[1] +BufLow[2][jj+6 + 1] * high[2] + BufLow[2][jj+6 + 1] * high[3];
				
				//j+4 jj+8
				ou_image[ii][j+4]= BufLow[0][jj+8]* low[0]+BufLow[1][jj+8] * low[1]+BufLow[2][jj+8]	* low[2]+BufLow[3][jj+8] * low[3];
				ou_image[ii + N/2][j+4] = BufLow[0][jj+8]* high[0] +BufLow[1][jj+8] * high[1] +BufLow[2][jj+8]* high[2] +BufLow[3][jj+8] * high[3];
				ou_image[ii][j+4 + M/2]= BufLow[0][jj+8 + 1]* low[0] +BufLow[1][jj+8 + 1] * low[1]+BufLow[2][jj+8 + 1]* low[2] +BufLow[3][jj+8 + 1] * low[3];
				ou_image[ii + N/2][j+4 + M/2] = BufLow[0][jj+8 + 1] * high[0] + BufLow[1][jj+8 + 1] * high[1] +BufLow[2][jj+8 + 1] * high[2] + BufLow[2][jj+8 + 1] * high[3];
				
				//j+5 
				ou_image[ii][j+5]= BufLow[0][jj+10]* low[0]+BufLow[1][jj+10] * low[1]+BufLow[2][jj+10]	* low[2]+BufLow[3][jj+10] * low[3];
				ou_image[ii + N/2][j+5] = BufLow[0][jj+10]* high[0] +BufLow[1][jj+10] * high[1] +BufLow[2][jj+10]* high[2] +BufLow[3][jj+10] * high[3];
				ou_image[ii][j+5 + M/2]= BufLow[0][jj+10 + 1]* low[0] +BufLow[1][jj+10 + 1] * low[1]+BufLow[2][jj+10 + 1]* low[2] +BufLow[3][jj+10 + 1] * low[3];
				ou_image[ii + N/2][j+5 + M/2] = BufLow[0][jj+10 + 1] * high[0] + BufLow[1][jj+10 + 1] * high[1] +BufLow[2][jj+10 + 1] * high[2] + BufLow[2][jj+10 + 1] * high[3];
				
				//j+6 jj+12
				ou_image[ii][j+6]= BufLow[0][jj+12]* low[0]+BufLow[1][jj+12] * low[1]+BufLow[2][jj+12]	* low[2]+BufLow[3][jj+12] * low[3];
				ou_image[ii + N/2][j+6] = BufLow[0][jj+12]* high[0] +BufLow[1][jj+12] * high[1] +BufLow[2][jj+12]* high[2] +BufLow[3][jj+12] * high[3];
				ou_image[ii][j+6 + M/2]= BufLow[0][jj+12 + 1]* low[0] +BufLow[1][jj+12 + 1] * low[1]+BufLow[2][jj+12 + 1]* low[2] +BufLow[3][jj+12 + 1] * low[3];
				ou_image[ii + N/2][j+6 + M/2] = BufLow[0][jj+12 + 1] * high[0] + BufLow[1][jj+12 + 1] * high[1] +BufLow[2][jj+12 + 1] * high[2] + BufLow[2][jj+12 + 1] * high[3];
				
				
				//j+7 jj+14
				ou_image[ii][j+7]= BufLow[0][jj+14]* low[0]+BufLow[1][jj+14] * low[1]+BufLow[2][jj+14]	* low[2]+BufLow[3][jj+14] * low[3];
				ou_image[ii + N/2][j+7] = BufLow[0][jj+14]* high[0] +BufLow[1][jj+14] * high[1] +BufLow[2][jj+14]* high[2] +BufLow[3][jj+14] * high[3];
				ou_image[ii][j+7 + M/2]= BufLow[0][jj+14 + 1]* low[0] +BufLow[1][jj+14 + 1] * low[1]+BufLow[2][jj+14 + 1]* low[2] +BufLow[3][jj+14 + 1] * low[3];
				ou_image[ii + N/2][j+7 + M/2] = BufLow[0][jj+14 + 1] * high[0] + BufLow[1][jj+14 + 1] * high[1] +BufLow[2][jj+14 + 1] * high[2] + BufLow[2][jj+14 + 1] * high[3];
				
				}
			}
		
			   
		end_rdtsc  
                  printf ( "output = %f\n", ou_image[N/2][M/2]);
                                    savefloatMatrixFileForOutPuts(ou_image);


return 0;
}

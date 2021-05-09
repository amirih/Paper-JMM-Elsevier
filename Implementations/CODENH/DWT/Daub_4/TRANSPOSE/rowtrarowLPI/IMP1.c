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
  programName= "DUB4FULROWTRAROWLPI";
	  
	half_row = N / 2;
	 half_col = M / 2;
			float swap = 0;	

		assignImagef32(in_image);
 
		begin_rdtsc
			
			   for(j=0, jj=0; jj<M; j++, jj +=2)
			   for (i=0; i<N; i++)
			   {
				 ou_image[i][j]            = in_image[i][jj]     * low[0]  +  in_image[i][jj + 1] * low[1] +
											 in_image[i][jj + 2] * low[2]  +  in_image[i][jj + 3] * low[3];

				 ou_image[i][j + half_col] = in_image[i][jj]     * high[0] + in_image[i][jj  + 1] * high[1] +
											  in_image[i][jj + 2] * high[2] + in_image[i][jj  + 3] * high[3];
			   }
			   
			   //Transpose
				for (i=0; i<MAX1; i++)
					for(j=0; j<i; j++){
						swap = ou_image[i][j];
						ou_image[i][j] = ou_image[j][i];
						ou_image[j][i]=swap;
					}
					
			
			   for(j=0, jj=0; jj<M; j++, jj +=2)
			   for (i=0; i<N; i++)
			   {
				 in_image[i][j]            = ou_image[i][jj]     * low[0]  +  ou_image[i][jj + 1] * low[1] +
											 ou_image[i][jj + 2] * low[2]  +  ou_image[i][jj + 3] * low[3];

				 in_image[i][j + half_col] = ou_image[i][jj]     * high[0] + ou_image[i][jj  + 1] * high[1] +
											  ou_image[i][jj + 2] * high[2] + ou_image[i][jj  + 3] * high[3];
			   }
			   
			  
      
		end_rdtsc  
                  printf ( "output = %f\n", in_image[N/2][M/2]);                                    savefloatMatrixFileForOutPuts(in_image);


return 0;
}

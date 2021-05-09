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
  programName= "DUB4FULROWTRAROWunroll";
	  
	half_row = N / 2;
	 half_col = M / 2;
			float swap = 0;	

		assignImagef32(in_image);
 
		begin_rdtsc
			for (i=0; i<N; i++)
			   for(j=0, jj=0; jj<M; j+=8, jj +=16)
			   {
				//j=0 jj=0
				 ou_image[i][j]            = in_image[i][jj]     * low[0]  +  in_image[i][jj + 1] * low[1] +
											 in_image[i][jj + 2] * low[2]  +  in_image[i][jj + 3] * low[3];

				 ou_image[i][j + half_col] = in_image[i][jj]     * high[0] + in_image[i][jj  + 1] * high[1] +
											  in_image[i][jj + 2] * high[2] + in_image[i][jj  + 3] * high[3];
											  
											  //j=1 jj=2
				 ou_image[i][j+1]            = in_image[i][jj+2]     * low[0]  +  in_image[i][jj+2 + 1] * low[1] +
											 in_image[i][jj+2 + 2] * low[2]  +  in_image[i][jj+2 + 3] * low[3];

				 ou_image[i][j+1 + half_col] = in_image[i][jj+2]     * high[0] + in_image[i][jj+2  + 1] * high[1] +
											  in_image[i][jj+2 + 2] * high[2] + in_image[i][jj+2  + 3] * high[3];
											  
											  //j=2 jj=4
				 ou_image[i][j+2]            = in_image[i][jj+4]     * low[0]  +  in_image[i][jj+4 + 1] * low[1] +
											 in_image[i][jj+4 + 2] * low[2]  +  in_image[i][jj+4 + 3] * low[3];

				 ou_image[i][j+2 + half_col] = in_image[i][jj+4]     * high[0] + in_image[i][jj+4  + 1] * high[1] +
											  in_image[i][jj+4 + 2] * high[2] + in_image[i][jj+4  + 3] * high[3];
											  
											  //j=3 jj=6
				 ou_image[i][j+3]            = in_image[i][jj+6]     * low[0]  +  in_image[i][jj+6 + 1] * low[1] +
											 in_image[i][jj+6 + 2] * low[2]  +  in_image[i][jj+6 + 3] * low[3];

				 ou_image[i][j+3 + half_col] = in_image[i][jj+6]     * high[0] + in_image[i][jj+6  + 1] * high[1] +
											  in_image[i][jj+6 + 2] * high[2] + in_image[i][jj+6  + 3] * high[3];
											  
											  //j=4 jj=8
				 ou_image[i][j+4]            = in_image[i][jj+8]     * low[0]  +  in_image[i][jj+8 + 1] * low[1] +
											 in_image[i][jj+8 + 2] * low[2]  +  in_image[i][jj+8 + 3] * low[3];

				 ou_image[i][j+4 + half_col] = in_image[i][jj+8]     * high[0] + in_image[i][jj+8  + 1] * high[1] +
											  in_image[i][jj+8 + 2] * high[2] + in_image[i][jj+8  + 3] * high[3];
											  
											  //j=5 jj=10
				 ou_image[i][j+5]            = in_image[i][jj+10]     * low[0]  +  in_image[i][jj+10 + 1] * low[1] +
											 in_image[i][jj+10 + 2] * low[2]  +  in_image[i][jj+10 + 3] * low[3];

				 ou_image[i][j+5 + half_col] = in_image[i][jj+10]     * high[0] + in_image[i][jj+10  + 1] * high[1] +
											  in_image[i][jj+10 + 2] * high[2] + in_image[i][jj+10  + 3] * high[3];
											  
											  //j=6 jj=12
				 ou_image[i][j+6]            = in_image[i][jj+12]     * low[0]  +  in_image[i][jj+12 + 1] * low[1] +
											 in_image[i][jj+12 + 2] * low[2]  +  in_image[i][jj+12 + 3] * low[3];

				 ou_image[i][j+6 + half_col] = in_image[i][jj+12]     * high[0] + in_image[i][jj+12  + 1] * high[1] +
											  in_image[i][jj+12 + 2] * high[2] + in_image[i][jj+12  + 3] * high[3];
											  
											  //j=7 jj=14
				 ou_image[i][j+7]            = in_image[i][jj+14]     * low[0]  +  in_image[i][jj+14 + 1] * low[1] +
											 in_image[i][jj+14 + 2] * low[2]  +  in_image[i][jj+14 + 3] * low[3];

				 ou_image[i][j+7 + half_col] = in_image[i][jj+14]     * high[0] + in_image[i][jj+14  + 1] * high[1] +
											  in_image[i][jj+14 + 2] * high[2] + in_image[i][jj+14  + 3] * high[3];
			   }
			   
			   //Transpose
				for (i=0; i<MAX1; i++)
					for(j=0; j<i; j++){
						swap = ou_image[i][j];
						ou_image[i][j] = ou_image[j][i];
						ou_image[j][i]=swap;
					}
					
			for (i=0; i<N; i++)
			   for(j=0, jj=0; jj<M; j+=8, jj +=16)
			   {
				//j=0 jj=0
				 in_image[i][j]            = ou_image[i][jj]     * low[0]  +  ou_image[i][jj + 1] * low[1] +
											 ou_image[i][jj + 2] * low[2]  +  ou_image[i][jj + 3] * low[3];

				 in_image[i][j + half_col] = ou_image[i][jj]     * high[0] + ou_image[i][jj  + 1] * high[1] +
											  ou_image[i][jj + 2] * high[2] + ou_image[i][jj  + 3] * high[3];
											  
											  //j=1 jj=2
				 in_image[i][j+1]            = ou_image[i][jj+2]     * low[0]  +  ou_image[i][jj+2 + 1] * low[1] +
											 ou_image[i][jj+2 + 2] * low[2]  +  ou_image[i][jj+2 + 3] * low[3];

				 in_image[i][j+1 + half_col] = ou_image[i][jj+2]     * high[0] + ou_image[i][jj+2  + 1] * high[1] +
											  ou_image[i][jj+2 + 2] * high[2] + ou_image[i][jj+2  + 3] * high[3];
											  
											  //j=2 jj=4
				 in_image[i][j+2]            = ou_image[i][jj+4]     * low[0]  +  ou_image[i][jj+4 + 1] * low[1] +
											 ou_image[i][jj+4 + 2] * low[2]  +  ou_image[i][jj+4 + 3] * low[3];

				 in_image[i][j+2 + half_col] = ou_image[i][jj+4]     * high[0] + ou_image[i][jj+4  + 1] * high[1] +
											  ou_image[i][jj+4 + 2] * high[2] + ou_image[i][jj+4  + 3] * high[3];
											  
											  //j=3 jj=6
				 in_image[i][j+3]            = ou_image[i][jj+6]     * low[0]  +  ou_image[i][jj+6 + 1] * low[1] +
											 ou_image[i][jj+6 + 2] * low[2]  +  ou_image[i][jj+6 + 3] * low[3];

				 in_image[i][j+3 + half_col] = ou_image[i][jj+6]     * high[0] + ou_image[i][jj+6  + 1] * high[1] +
											  ou_image[i][jj+6 + 2] * high[2] + ou_image[i][jj+6  + 3] * high[3];
											  
											  //j=4 jj=8
				 in_image[i][j+4]            = ou_image[i][jj+8]     * low[0]  +  ou_image[i][jj+8 + 1] * low[1] +
											 ou_image[i][jj+8 + 2] * low[2]  +  ou_image[i][jj+8 + 3] * low[3];

				 in_image[i][j+4 + half_col] = ou_image[i][jj+8]     * high[0] + ou_image[i][jj+8  + 1] * high[1] +
											  ou_image[i][jj+8 + 2] * high[2] + ou_image[i][jj+8  + 3] * high[3];
											  
											  //j=5 jj=10
				 in_image[i][j+5]            = ou_image[i][jj+10]     * low[0]  +  ou_image[i][jj+10 + 1] * low[1] +
											 ou_image[i][jj+10 + 2] * low[2]  +  ou_image[i][jj+10 + 3] * low[3];

				 in_image[i][j+5 + half_col] = ou_image[i][jj+10]     * high[0] + ou_image[i][jj+10  + 1] * high[1] +
											  ou_image[i][jj+10 + 2] * high[2] + ou_image[i][jj+10  + 3] * high[3];
											  
											  //j=6 jj=12
				 in_image[i][j+6]            = ou_image[i][jj+12]     * low[0]  +  ou_image[i][jj+12 + 1] * low[1] +
											 ou_image[i][jj+12 + 2] * low[2]  +  ou_image[i][jj+12 + 3] * low[3];

				 in_image[i][j+6 + half_col] = ou_image[i][jj+12]     * high[0] + ou_image[i][jj+12  + 1] * high[1] +
											  ou_image[i][jj+12 + 2] * high[2] + ou_image[i][jj+12  + 3] * high[3];
											  
											  //j=7 jj=14
				 in_image[i][j+7]            = ou_image[i][jj+14]     * low[0]  +  ou_image[i][jj+14 + 1] * low[1] +
											 ou_image[i][jj+14 + 2] * low[2]  +  ou_image[i][jj+14 + 3] * low[3];

				 in_image[i][j+7 + half_col] = ou_image[i][jj+14]     * high[0] + ou_image[i][jj+14  + 1] * high[1] +
											  ou_image[i][jj+14 + 2] * high[2] + ou_image[i][jj+14  + 3] * high[3];
			   }
			  
      
		end_rdtsc  
                  printf ( "output = %f\n", in_image[N/2][M/2]);                                    savefloatMatrixFileForOutPuts(in_image);


return 0;
}

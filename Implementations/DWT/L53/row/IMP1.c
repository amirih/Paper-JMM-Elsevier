// This proram calcultes the lifting scheme of DWT using (5,3) filter and integer.


#include "MAX.h"

#define    N    MAX1
#define    M    N


int i, j, jj, half_row, half_col;
int in_image[N][M+3], ou_image[N][M+3];

 int  main(void) {
	 singleCore
  programName= "L53ROW ";
	  
	half_row = N / 2;
	 half_col = M / 2;

		assignImagei32(in_image);
 
		begin_rdtsc
			for (i=0; i< N; i++)
				 for (j=1, jj=0; j<M; jj++, j +=2)                                                    
				  {
					 ou_image[i][jj + half_col] = in_image[i][j] -  ((in_image[i][j-1] + in_image[i][j+1]) >> 1);   //  Calculation of high-value
					 ou_image[i][jj] = in_image[i][j-1] +  ((ou_image[i][jj + half_col] + ou_image[i][jj+ half_col - 1] + 2) >> 2);     // calculation of low value
				  }
      
		end_rdtsc  
		printf ( "output = %d\n", ou_image[N/2][M/2]);

         
return 0;
}

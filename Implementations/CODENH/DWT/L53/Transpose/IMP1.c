// This proram calcultes the lifting scheme of DWT using (5,3) filter and integer.


#include "MAX.h"

#define    N    MAX1
#define    M    N


int i, j, jj, half_row, half_col;
int in_image[N+4][M+4], ou_image[N+4][M+4];

 int  main(void) {
		singleCore
		programName= "L53FULLTRACOLCOL";

		half_row = N / 2;
		half_col = M / 2;
		int i, j;
		float swap = 0;	

		assignImagei32(in_image);
		saveintMatrixFileName(in_image,"inputs");
 
		begin_rdtsc
		//Transpose
		for (i=0; i<MAX1; i++)
			for(j=0; j<i; j++){
				swap = in_image[i][j];
				in_image[i][j] = in_image[j][i];
				in_image[j][i]=swap;
			}
			
		//column processing on transposed image
		
			for (i=0; i<M; i++)
			 for (j=1, jj=0; j<N; jj++, j +=2)
			  {
				ou_image[jj + half_row][i] = in_image[j][i] -  ((in_image[j-1][i] + in_image[j+1][i]) >> 1);   //    Calculation of high-value
				ou_image[jj][i] = in_image[j-1][i] +  ((in_image[jj + half_row][i] + in_image[jj + half_row -1][i] + 2) >> 2);     //calculation of low value
			  }
			  
		//col processing		  
		
			for (i=0; i<M; i++)
			for (j=1, jj=0; j<N; jj++, j +=2)
			  {
				in_image[jj + half_row][i] = ou_image[j][i] -  ((ou_image[j-1][i] + ou_image[j+1][i]) >> 1);   //    Calculation of high-value
				in_image[jj][i] = ou_image[j-1][i] +  ((in_image[jj + half_row][i] + in_image[jj + half_row -1][i] + 2) >> 2);     //calculation of low value
			  }
      
		end_rdtsc  
		printf ( "output = %d\n", in_image[N/2][M/2]);
		         				saveintMatrixFileForOutPuts(in_image);


         
return 0;
}

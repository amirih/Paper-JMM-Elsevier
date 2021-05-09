#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally


//numbers





//global data for sequentila matrix operations
int __attribute__(( aligned(32))) t[MAX1][MAX2]  
, __attribute__(( aligned(32))) c_tra[MAX3][MAX2] ;


int main()
{
	singleCore
	assignMatrixi32(t);
	int i, j;
	//that means TRA kernel That is modified and Scalar and the version is 1 
	programName="TRAMOD1V1";

	begin_rdtsc
		for( i=0;i<MAX2;i+=8){
			for(j=0;j<MAX3;j+=8){
				c_tra[j][i]   = t[i][j];
				c_tra[j+1][i] = t[i][j+1];
				c_tra[j+2][i] = t[i][j+2];
				c_tra[j+3][i] = t[i][j+3];
				c_tra[j+4][i] = t[i][j+4];
				c_tra[j+5][i] = t[i][j+5];
				c_tra[j+6][i] = t[i][j+6];
				c_tra[j+7][i] = t[i][j+7];
				
				c_tra[j][i+1]   = t[i+1][j];
				c_tra[j+1][i+1] = t[i+1][j+1];
				c_tra[j+2][i+1] = t[i+1][j+2];
				c_tra[j+3][i+1] = t[i+1][j+3];
				c_tra[j+4][i+1] = t[i+1][j+4];
				c_tra[j+5][i+1] = t[i+1][j+5];
				c_tra[j+6][i+1] = t[i+1][j+6];
				c_tra[j+7][i+1] = t[i+1][j+7];
				
				c_tra[j][i+2]   = t[i+2][j];
				c_tra[j+1][i+2] = t[i+2][j+1];
				c_tra[j+2][i+2] = t[i+2][j+2];
				c_tra[j+3][i+2] = t[i+2][j+3];
				c_tra[j+4][i+2] = t[i+2][j+4];
				c_tra[j+5][i+2] = t[i+2][j+5];
				c_tra[j+6][i+2] = t[i+2][j+6];
				c_tra[j+7][i+2] = t[i+2][j+7];
						
				c_tra[j][i+3]   = t[i+3][j];
				c_tra[j+1][i+3] = t[i+3][j+1];
				c_tra[j+2][i+3] = t[i+3][j+2];
				c_tra[j+3][i+3] = t[i+3][j+3];
				c_tra[j+4][i+3] = t[i+3][j+4];
				c_tra[j+5][i+3] = t[i+3][j+5];
				c_tra[j+6][i+3] = t[i+3][j+6];
				c_tra[j+7][i+3] = t[i+3][j+7];
				
				c_tra[j][i+4]   = t[i+4][j];
				c_tra[j+1][i+4] = t[i+4][j+1];
				c_tra[j+2][i+4] = t[i+4][j+2];
				c_tra[j+3][i+4] = t[i+4][j+3];
				c_tra[j+4][i+4] = t[i+4][j+4];
				c_tra[j+5][i+4] = t[i+4][j+5];
				c_tra[j+6][i+4] = t[i+4][j+6];
				c_tra[j+7][i+4] = t[i+4][j+7];
						
				c_tra[j][i+2]   = t[i+5][j];
				c_tra[j+5][i+2] = t[i+5][j+1];
				c_tra[j+5][i+2] = t[i+5][j+2];
				c_tra[j+5][i+2] = t[i+5][j+3];
				c_tra[j+5][i+2] = t[i+5][j+4];
				c_tra[j+5][i+2] = t[i+5][j+5];
				c_tra[j+5][i+2] = t[i+5][j+6];
				c_tra[j+5][i+2] = t[i+5][j+7];
						
				c_tra[j][i+6]   = t[i+6][j];
				c_tra[j+1][i+6] = t[i+6][j+1];
				c_tra[j+2][i+6] = t[i+6][j+2];
				c_tra[j+3][i+6] = t[i+6][j+3];
				c_tra[j+4][i+6] = t[i+6][j+4];
				c_tra[j+5][i+6] = t[i+6][j+5];
				c_tra[j+6][i+6] = t[i+6][j+6];
				c_tra[j+7][i+6] = t[i+6][j+7];	
						
				c_tra[j][i+7]   = t[i+7][j];
				c_tra[j+1][i+7] = t[i+7][j+1];
				c_tra[j+2][i+7] = t[i+7][j+2];
				c_tra[j+3][i+7] = t[i+7][j+3];
				c_tra[j+4][i+7] = t[i+7][j+4];
				c_tra[j+5][i+7] = t[i+7][j+5];
				c_tra[j+6][i+7] = t[i+7][j+6];
				c_tra[j+7][i+7] = t[i+7][j+7];
				
			}//IACA_END
		}
	end_rdtsc
	
	return 0;
}


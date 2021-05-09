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
	programName="TRAMOD1V2";

	begin_rdtsc
		for( i=0;i<MAX2;i++){
			for(j=0;j<MAX3;j+=8){
				c_tra[j][i]   = t[i][j];
				c_tra[j+1][i] = t[i][j+1];
				c_tra[j+2][i] = t[i][j+2];
				c_tra[j+3][i] = t[i][j+3];
				c_tra[j+4][i] = t[i][j+4];
				c_tra[j+5][i] = t[i][j+5];
				c_tra[j+6][i] = t[i][j+6];
				c_tra[j+7][i] = t[i][j+7];
			
			}//IACA_END
		}
	end_rdtsc
	
	return 0;
}


#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally


//numbers
#define FMAX1 MAX1*MAX1
#define COEFF 8 




//global data for sequentila matrix operations
int __attribute__(( aligned(32))) input[FMAX1+COEFF];			//= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
int __attribute__(( aligned(32))) output[FMAX1];
int __attribute__(( aligned(32))) coeff[COEFF] = {1,2,3,4,5,6,7,8};//= {1,1,1,1,1,1,1,1};//;			//= {1,2,1,2,1,2,1,2,2,1};



int main()
{
	singleCore
	assignArrayi32(input);
	int i, j;
	//that means FIR kernel That is modified and Scalar and the version is 1 
	programName="FIRMOD1V1";

	begin_rdtsc
		
		
		for(i = 0; i < FMAX1; i++){
			for(j = 0; j < COEFF; j+=8){// 	IACA_START
				output[i] += coeff[j] * input[i+j+0];	
				output[i] += coeff[j+1] * input[i+j+1];	
				output[i] += coeff[j+2] * input[i+j+2];	
				output[i] += coeff[j+3] * input[i+j+3];	
				output[i] += coeff[j+4] * input[i+j+4];	
				output[i] += coeff[j+5] * input[i+j+5];	
				output[i] += coeff[j+6] * input[i+j+6];	
				output[i] += coeff[j+7] * input[i+j+7];	
			
			}//IACA_END
		}

		end_rdtsc
	
	return 0;
}


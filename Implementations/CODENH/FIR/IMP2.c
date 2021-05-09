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
	programName="FIRMOD1V2";
	
	begin_rdtsc
		
		
		for(i = 0; i < FMAX1; i+=8){
			for(j = 0; j < COEFF; j++){// 	IACA_START
				output[i] += coeff[j] * input[i+j+0];	
				output[i+1] += coeff[j] * input[i+j+1];	
				output[i+2] += coeff[j] * input[i+j+2];	
				output[i+3] += coeff[j] * input[i+j+3];	
				output[i+4] += coeff[j] * input[i+j+4];	
				output[i+5] += coeff[j] * input[i+j+5];	
				output[i+6] += coeff[j] * input[i+j+6];	
				output[i+7] += coeff[j] * input[i+j+7];	
			
			}//IACA_END
		}

		end_rdtsc
	
	return 0;
}


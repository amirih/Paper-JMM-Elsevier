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
	programName="FIR1";
	//REP_CODE(
	begin_rdtsc
		
		
		for(i = 0; i < FMAX1; i++){
			for(j = 0; j < COEFF; j++){//IACA_START
				output[i] += coeff[j] * input[i+j];	
			
			}//IACA_END
		}

		end_rdtsc//)
	
	return 0;
}


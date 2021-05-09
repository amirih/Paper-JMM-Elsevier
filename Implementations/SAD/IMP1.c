
//#define MAX1 256
//#define MAX1 384


//#define MAX1 672

//#define MAX1 1600
//#define MAX1 1888
//#define MAX1 2016

//#define MAX1 448
//#define MAX1 512
//#define MAX1 1024
//#define MAX1 4096


#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
//#include "iacaMarks.h"






char ca;
short sa;
int ia;
long la;


//global data for sequentila matrix operations
unsigned char a_char[MAX1][MAX2] __attribute__(( aligned(32))) ;//= {{1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8,9,10,11}};
unsigned char b_char[MAX2][MAX3] __attribute__(( aligned(32))) ;// = {{2,3,4,5,6,7,8,9,10,11,6,7,8,9,10,2,3,4,5,6,7,8}};
unsigned char c_char[MAX1][MAX3] __attribute__(( aligned(32)));


int main()
{
	singleCore
	assignMatrixi8(a_char);
	assignMatrixi8(b_char);
	int i, j, sad=0;
		programName="SAD1";

	//REP_CODE(
	begin_rdtsc
		for(i=0; i<MAX1; i++){
			for(j=0; j<MAX2; j++){//IACA_START
				sad += (((a_char[i][j]-b_char[i][j]<0))?-1*(a_char[i][j]-b_char[i][j]):(a_char[i][j]-b_char[i][j]));
			}//IACA_END
		}
	end_rdtsc//)
	//printf(" The best time:repetition for %dX matrix result is %d \n", MAX1, sad);
	
	return sad;
}


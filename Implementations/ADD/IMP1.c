#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally

int __attribute__(( aligned(32))) a[MAX1][MAX2],
	__attribute__(( aligned(32))) b[MAX2][MAX3],
	__attribute__(( aligned(32))) c_tra[MAX3][MAX2],
	__attribute__(( aligned(32))) c_result[MAX1][MAX3];// 	//will be used for operation 

//int a[MAX1], b[MAX1], c[MAX1] ;

int main()
{
	singleCore
	assignMatrixi32(a);
	assignMatrixi32(b);
	int i, j;
	programName="ADD1";
	//REP_CODE(
	begin_rdtsc

		for( i=0;i<MAX1;i++){
			for(j=0;j<MAX2;j++){//IACA_START
				c_result[i][j]= a[i][j] + b[i][j];
			}//IACA_END
		}
		
	end_rdtsc //)
	
	//printf(" The best time: %lf sec in %d repetition for %dX%d matrix , result is %d \n",tBest,w, MAX1, MAX1, c_result[i/2][j/2]);
	//printf(" The best time: %lld sec in %d repetition for %dX%d matrix , result is %d \n",tBest,w, MAX1, MAX1, c_result[i/2][j/2]);

	
	
	
	return 0;
}

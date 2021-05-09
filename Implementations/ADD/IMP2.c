#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
#include "nmmintrin.h"

int __attribute__(( aligned(16))) a[MAX1][MAX2],
	__attribute__(( aligned(16))) b[MAX2][MAX3],
	__attribute__(( aligned(16))) c_tra[MAX3][MAX2],
	__attribute__(( aligned(16))) c_result[MAX1][MAX3];// 	//will be used for operation 


int main()
{
	singleCore
	assignMatrixi32(a);
	assignMatrixi32(b);
	int i, j;
	programName="ADD2";
	__m128i a0_i;
	
//REP_CODE(
		begin_rdtsc  
		
		for(i = 0 ; i < MAX1 ; i++ ){	
			for(j = 0 ; j < MAX2 ; j += 4){//IACA_START
				a0_i = _mm_add_epi32( _mm_load_si128( (__m128i *)&a[ i ][ j ]) ,  _mm_load_si128( (__m128i *) &b[ i ][ j]));		//add 2 vector 
				_mm_store_si128( (__m128i *) &c_result[ i ][ j ], a0_i);

			}//IACA_END
		}
		
		end_rdtsc//)
		
	printf(" The best time: repetition for %dX%d matrix , result is %d \n", MAX1, MAX1, c_result[i/2][j/2]);
	//printf(" The best time: %lld sec in %d repetition for %dX%d matrix , result is %d \n",tBest,w, MAX1, MAX1, c_result[i/2][j/2]);
	return 0;
}








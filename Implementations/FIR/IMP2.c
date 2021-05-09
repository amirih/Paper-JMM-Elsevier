#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally

//numbers
#define FMAX1 MAX1*MAX1
#define COEFF 8 




//global data for sequentila matrix operations
int __attribute__(( aligned(16))) output[FMAX1];			//= {1,2,1,2,1,2,1,2,2,1};= {1111,2222,3333,4444,5555,6666,7777,8888}
int __attribute__(( aligned(16))) input_avx[FMAX1+COEFF];	//  = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
int __attribute__(( aligned(16))) coeff_avx[COEFF][4]  = {{1, 1, 1, 1},//{1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1}};/*
														  {2, 2, 2, 2},
														  {3, 3, 3, 3},
														  {4, 4, 4, 4},
														  {5, 5, 5, 5},
														  {6, 6, 6, 6},
														  {7, 7, 7, 7},
														  {8, 8, 8, 8}};


int main()
{
	singleCore
	assignArrayi32(input_avx);
	int i, j;
	programName="FIR2";
	__m128i input_v, coeff_v, temp_v, sum_v;
	//REP_CODE(
	begin_rdtsc
		for(i=0; i < FMAX1; i += 4){
			sum_v = _mm_setzero_si128 ();
			input_v = _mm_load_si128 ( (__m128i *) &input_avx[i]);		
			coeff_v = _mm_load_si128 ( (__m128i *) &coeff_avx[0]);	
			temp_v = _mm_mullo_epi32 ( coeff_v , input_v);
			sum_v  = _mm_add_epi32( temp_v, sum_v);
			
						
			for(j=1; j < COEFF; j++){//IACA_START 
				input_v = _mm_loadu_si128( (__m128i *)&input_avx[i+j]);
				coeff_v = _mm_load_si128( (__m128i *)& coeff_avx[j]);
				temp_v  = _mm_mullo_epi32( coeff_v, input_v); 		
				sum_v  = _mm_add_epi32( temp_v, sum_v);				
							
			}//IACA_END
			_mm_store_si128((__m128i *)&output[i], sum_v);
		}
		
		
		end_rdtsc//)
		printf("%i", output[MAX1/2]);
	return 0;
}


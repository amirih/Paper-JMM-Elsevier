#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
#include "immintrin.h"

//numbers
#define FMAX1 MAX1*MAX1
#define COEFF 8 






//global data for sequentila matrix operations
int __attribute__(( aligned(32))) output[FMAX1];			//= {1,2,1,2,1,2,1,2,2,1};
int __attribute__(( aligned(32))) input_avx[FMAX1+8];	//  = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
int __attribute__(( aligned(32))) coeff_avx[COEFF][8]= 	 {{1, 1, 1, 1, 1, 1, 1, 1},//{1, 1, 1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 1, 1, 1, 1}};/*
														  {2, 2, 2, 2, 2, 2, 2, 2},
														  {3, 3, 3, 3, 3, 3, 3, 3},
														  {4, 4, 4, 4, 4, 4, 4, 4},
														  {5, 5, 5, 5, 5, 5, 5, 5},
														  {6, 6, 6, 6, 6, 6, 6, 6},
														  {7, 7, 7, 7, 7, 7, 7, 7},
														  {8, 8, 8, 8, 8, 8, 8, 8}};
int __attribute__(( aligned(32))) coeff[COEFF] = {1,2,3,4,5,6,7,8};	


int main()
{
	singleCore
	assignArrayi32(input_avx);
	int i, j;
	programName="FIR3";
	__m256i input_v, coeff_v, temp_v, sum_v ;
	//REP_CODE(
	begin_rdtsc

		for(i=0; i < FMAX1; i += 8){
			input_v = _mm256_load_si256 ( (__m256i *) &input_avx[i]);		
			coeff_v = _mm256_set1_epi32 (coeff[0]);
			//coeff_v = _mm256_set1_epi32 (a);
			//coeff_v = _mm256_broadcastd_epi32 (c_vec);
			sum_v = _mm256_mullo_epi32 ( coeff_v , input_v);				
			for(j=1; j < COEFF; j++){//IACA_START 
				input_v = _mm256_loadu_si256( (__m256i *)&input_avx[i+j]);
				coeff_v = _mm256_set1_epi32 (coeff[j]);;
				temp_v  = _mm256_mullo_epi32( coeff_v, input_v); 		
				sum_v  = _mm256_add_epi32( temp_v, sum_v);				
							
			}//IACA_END
			_mm256_store_si256((__m256i *)&output[i], sum_v);
		}
			

		
		
	end_rdtsc//)	
	printf("%i", output[MAX1/2]);
	return 0;
}


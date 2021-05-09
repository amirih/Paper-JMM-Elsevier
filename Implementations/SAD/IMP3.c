//#define MAX1 448
//#define MAX1 512
//#define MAX1 1024
//#define MAX1 4096

#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
//#include "iacaMarks.h"


//global data for sequentila matrix operations
unsigned char a_char[MAX1][MAX2] __attribute__(( aligned(32))) = {{1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8,9,10,11}};
unsigned char b_char[MAX2][MAX3] __attribute__(( aligned(32))) = {{2,3,4,5,6,7,8,9,10,11,6,7,8,9,10,2,3,4,5,6,7,8}};
unsigned char c_char[MAX1][MAX3] __attribute__(( aligned(32)));
unsigned short int tempu16[16] __attribute__(( aligned(32)));


int main()
{
	singleCore
	assignMatrixi8(a_char);
	assignMatrixi8(b_char);
	int i, j, sad=0;
			programName="SAD3";

 	__m256i  vec1, vec2, vecT, sad_total;
 	
		assignMatrixi8(a_char);
		assignMatrixi8(b_char);
		
		sad_total= _mm256_setzero_si256();
		//REP_CODE(
		begin_rdtsc
		
		
		for(i=0; i<MAX1; i++){
			//sad_temp= _mm256_setzero_si256();
			for(j=0; j<MAX2; j+=32){//IACA_START
					
					//SAD3
					//sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i][j]) ,  _mm256_load_si256((__m256i *)&b_char[i][j]));
					//sad_temp = _mm256_abs_epi8(sad_temp);
					
					//SAD2
					//sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i][j]) ,  _mm256_load_si256((__m256i *)&b_char[i][j]));
					//sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					//sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					/*
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i][j+32]) ,  _mm256_load_si256((__m256i *)&b_char[i][j+32]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);*/
					/*
					
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i+1][j]) ,  _mm256_load_si256((__m256i *)&b_char[i+1][j]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i+1][j+32]) ,  _mm256_load_si256((__m256i *)&b_char[i+1][j+32]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					*/
					
					/*
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i+2][j]) ,  _mm256_load_si256((__m256i *)&b_char[i+2][j]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i+3][j]) ,  _mm256_load_si256((__m256i *)&b_char[i+3][j]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i+4][j]) ,  _mm256_load_si256((__m256i *)&b_char[i+4][j]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i+5][j]) ,  _mm256_load_si256((__m256i *)&b_char[i+5][j]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i+6][j]) ,  _mm256_load_si256((__m256i *)&b_char[i+6][j]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					
					sad_temp = _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i+7][j]) ,  _mm256_load_si256((__m256i *)&b_char[i+7][j]));
					sad_temp = _mm256_sign_epi8(sad_temp , sad_temp);
					sad_total = _mm256_add_epi16 ( sad_total , sad_temp);
					*/
					
					//SAD1
					vec1 = _mm256_load_si256((__m256i *)&a_char[i][j]);
					vec2 = _mm256_load_si256((__m256i *)&b_char[i][j]);
					vecT = _mm256_sad_epu8( vec1 , vec2);
					sad_total = _mm256_add_epi32(vecT, sad_total);
					
					//vecT  = _mm256_sad_epu8 ( _mm256_load_si256((__m256i *)&a_char[i][j]) ,  _mm256_load_si256((__m256i *)&b_char[i][j]));
					//sad_total = _mm256_add_epi32 ( sad_total , _mm256_sad_epu8 ( _mm256_load_si256((__m256i *)&a_char[i][j]) ,  _mm256_load_si256((__m256i *)&b_char[i][j])));

				}//IACA_END
			}
			
		_mm256_store_si256((__m256i *)&tempu16[0], sad_total);
		sad = tempu16[0]+tempu16[4]+tempu16[8]+tempu16[12];
		//sad= _mm256_haddsad_si256(sad_total);
	end_rdtsc//)
		
	
	printf("%d \n", sad);
	return 0;
}


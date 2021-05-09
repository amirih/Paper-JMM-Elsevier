#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
#include "immintrin.h"



//global data for sequentila matrix operations
short int  a_short[MAX1][MAX2]__attribute__(( aligned(32)));// = {{1},{2}};
short int b_short[MAX2][MAX3] __attribute__(( aligned(32)));
unsigned short int temp[16];


int main()
{
	singleCore
	assignMatrixi16(a_short);
	assignMatrixi16(b_short);
	__m256i ssd_temp1,ssd_temp2, ssd_total;
	int i, j, ssd=0;
				programName="SSD3";

		ssd_total= _mm256_setzero_si256();
		//REP_CODE(
		begin_rdtsc
		
		for(i=0; i<MAX1; i++){
			ssd_temp1 = _mm256_setzero_si256();
				for(j=0; j<MAX2; j+=16){//IACA_START
					ssd_temp1  = _mm256_sub_epi16 ( _mm256_load_si256((__m256i *)&a_short[i][j]),  _mm256_load_si256((__m256i *)&b_short[i][j]));
					ssd_temp2  = _mm256_mullo_epi16(ssd_temp1, ssd_temp1);
					//ssd_temp  = _mm256_mullo_epi16(_mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i][j]),  _mm256_load_si256((__m256i *)&b_char[i][j])) , _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i][j]),  _mm256_load_si256((__m256i *)&b_char[i][j])));
					ssd_total = _mm256_add_epi16 ( ssd_temp2, ssd_total);
					
				}//IACA_END
		}	
		asm("#kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");
			_mm256_store_si256((__m256i *)&temp[0], ssd_total);
			ssd = temp[0]+temp[2]+temp[4]+temp[6] +temp[1]+temp[3]+temp[5]+temp[7]+temp[8]+temp[9]+temp[10]+temp[11] +temp[12]+temp[13]+temp[14]+temp[15];//
		
		
	end_rdtsc//)
	printf(" The best time repetition for %dX result is %d\n",MAX1, ssd);
	
	return 0;
}


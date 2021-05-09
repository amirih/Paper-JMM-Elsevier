#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
#include "immintrin.h"
//#include "print.h"



//global data for sequentila matrix operations
short int a_short[MAX1][MAX2] __attribute__(( aligned(16)));
short int b_short[MAX2][MAX3] __attribute__(( aligned(16)));
unsigned short int temp[8];


int main()
{
	singleCore
	assignMatrixi16(a_short);
	assignMatrixi16(b_short);
	int i, j, ssd=0;
				programName="SSD2";

	__m128i ssd_temp1,ssd_temp2, ssd_total;
	
		ssd_total= _mm_setzero_si128();
		//REP_CODE(
		begin_rdtsc
		
		
		
		
		for(i=0; i<MAX1; i++){
			ssd_temp1 = _mm_setzero_si128();
				for(j=0; j<MAX2; j+=8){//IACA_START
					ssd_temp1  = _mm_sub_epi16 ( _mm_load_si128((__m128i *)&a_short[i][j]),  _mm_load_si128((__m128i *)&b_short[i][j]));
					ssd_temp2  = _mm_mullo_epi16(ssd_temp1, ssd_temp1);
					//ssd_temp  = _mm256_mullo_epi16(_mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i][j]),  _mm256_load_si256((__m256i *)&b_char[i][j])) , _mm256_sub_epi8 ( _mm256_load_si256((__m256i *)&a_char[i][j]),  _mm256_load_si256((__m256i *)&b_char[i][j])));
					ssd_total = _mm_add_epi16 ( ssd_temp2, ssd_total);
					
				}//IACA_END
		}	
				asm("#kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");

			//ssd= _mm_haddssd_si128(ssd_total);
			_mm_store_si128((__m128i *)&temp[0], ssd_total);//printVeci16s(ssd_total);
			ssd = temp[0]+temp[2]+temp[4]+temp[6] +temp[1]+temp[3]+temp[5]+temp[7];
		
		
		end_rdtsc//)
		printf("%i", ssd);
	return 0;
}


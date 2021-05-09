#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
#include "immintrin.h"
//#include "print.h"




int __attribute__(( aligned(16))) a[MAX1][MAX2]  
  , __attribute__(( aligned(16))) t[MAX2][MAX3] 
  , __attribute__(( aligned(16))) c_result[MAX1][MAX3] 
  , __attribute__(( aligned(16))) c_tra[MAX3][MAX2]
  , __attribute__(( aligned(16))) f[32];


int main()
{
	singleCore
	assignMatrixi32(a);
	assignMatrixi32(t);//1727022 . 1077776 . 1086318  1077988   -fno-vectorize -fno-slp-vectorize  
	programName="MUL2";

	int i, j, k;
	//int __attribute__(( aligned(16)))temp4[4]  ;
			__m128i row0, row1, row2, row3;
	__m128i __t0, __t1, __t2, __t3;
		__m128i  sum0_i;
		//REP_CODE(
		begin_rdtsc  

		

		for( i=0;i<MAX2;i+=4){
			for(j=0;j<MAX3;j+=4){//IACA_START

				row0 = _mm_load_si128((__m128i *)&t[i][j]);
				row1 = _mm_load_si128((__m128i *)&t[i+1][j]);
				row2 = _mm_load_si128((__m128i *)&t[i+2][j]);
				row3 = _mm_load_si128((__m128i *)&t[i+3][j]);

				__t0 = _mm_unpacklo_epi32(row0, row1);
				__t1 = _mm_unpacklo_epi32(row2, row3);
				__t2 = _mm_unpackhi_epi32(row0, row1);
				__t3 = _mm_unpackhi_epi32(row2, row3);

				/* Assigning transposed values back into I[0-3] */
				row0 = _mm_unpacklo_epi64(__t0, __t1);
				row1 = _mm_unpackhi_epi64(__t0, __t1);
				row2 = _mm_unpacklo_epi64(__t2, __t3);
				row3 = _mm_unpackhi_epi64(__t2, __t3);

				_mm_store_si128((__m128i *)&c_tra[j][i], row0);
				_mm_store_si128((__m128i *)&c_tra[j+1][i], row1);
				_mm_store_si128((__m128i *)&c_tra[j+2][i], row2);
				_mm_store_si128((__m128i *)&c_tra[j+3][i], row3);



			}//IACA_END
		}
		
	
		for( i=0;i<MAX1;i++){
			for(j=0;j<MAX3;j++){
				sum0_i = _mm_setzero_si128();
				for(k=0;k<MAX2;k=k+4){//IACA_START
					
					sum0_i = _mm_add_epi32(sum0_i,_mm_mullo_epi32(_mm_load_si128((__m128i *)&a[i][k]) , _mm_load_si128((__m128i *)&c_tra[j][k])));
		
				}//IACA_END
				
				//_mm_store_si128((__m128i *)&temp4[0] , sum0_i);//printf("%d", temp4[0]+temp4[1]+temp4[2]+temp4[3]);
				//c_result[i][j]= temp4[0]+temp4[1]+temp4[2]+temp4[3];//+temp8[4]+temp8[5]+temp8[6]+temp8[7];
				
				//c_result[i][j] = _mm256_haddmul_si128( sum0_i);
				//add horizontall using shift
				/*											//printf("\n\n\n\nsum0_i");printVec128i32(sum0_i);
			__m128i vec1 = _mm_bsrli_si128 (sum0_i, 4);  	//printf("vec1");printVec128i32(vec1);
			__m128i vec2 = _mm_bsrli_si128 (vec1, 4);		//printf("vec2");printVec128i32(vec2);
			__m128i vec3 = _mm_bsrli_si128 (vec2, 4);		//printf("vec3");printVec128i32(vec3);
					vec1 = _mm_add_epi32 (vec1, sum0_i);	//printf("vec1");printVec128i32(vec1);
					vec2 = _mm_add_epi32 (vec2, vec3);		//printf("vec2");printVec128i32(vec2);
					vec1 = _mm_add_epi32 (vec1, vec2);		//printf("vec1");printVec128i32(vec1);
					*/
					
					//add horizontally using hadd intrinsic
															//printf("\n\n\n\nsum0_i");printVec128i32(sum0_i);
				  sum0_i = _mm_hadd_epi32(sum0_i, sum0_i);	//printf("sum0_i");printVec128i32(sum0_i);
				 sum0_i = _mm_hadd_epi32(sum0_i, sum0_i);	//printf("sum0_i");printVec128i32(sum0_i);
				  
		  c_result[i][j] = _mm_extract_epi32 (sum0_i, 0);		//printf("result = %d",  c_result[i][j]);*/

			}
		}
	end_rdtsc//)
			saveintMatrixFileForOutPuts(c_result);

		
	//printf(" \nThe best time: repetition for %dX%d matrix , result is %d \n", MAX1, MAX1, c_result[i/2][j/2]);
	
	return 0;
}


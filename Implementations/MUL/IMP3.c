#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
#include "immintrin.h"
//#include "simpleintrin.h"


int __attribute__(( aligned(32))) A[MAX1][MAX2]  ={{1,2,3,4,5,6,7,8,9}}
  , __attribute__(( aligned(32))) B[MAX2][MAX3]  ={{1,2,3,4,5,6,7,8,9}}
  , __attribute__(( aligned(32))) C[MAX1][MAX3] 
  , __attribute__(( aligned(32))) B_T[MAX3][MAX2];



int main()
{
	singleCore
	assignMatrixi32(A);
	assignMatrixi32(B);

	int i, j, k;
		programName="MUL3";

	int vindexm [8]={0, MAX1, MAX1*2, MAX1*3, MAX1*4, MAX1*5, MAX1*6, MAX1*7 };
	__m256i vindex = _mm256_load_si256((__m256i *) &vindexm[0]);
	__m256i vec1, vec2, vec3, vec4, vec5, vec6, vec7, vec8;
	int __attribute__(( aligned(32)))temp8[8]  ;
	__m256i  vsum1;//,vsum2,vsum3,vsum4,vsum5,vsum6,vsum7,vsum8;
	   //REP_CODE(
		begin_rdtsc  
		
	for(i=0; i<MAX1;  i+=8){
			for(j=0; j<MAX2;  j+=8){//IACA_START
				
				//loading from columns
				vec1 = _mm256_i32gather_epi32 ((int const *)&B[i][j+0],vindex,4);
				vec2 = _mm256_i32gather_epi32 ((int const *)&B[i][j+1],vindex,4);
				vec3 = _mm256_i32gather_epi32 ((int const *)&B[i][j+2],vindex,4);
				vec4 = _mm256_i32gather_epi32 ((int const *)&B[i][j+3],vindex,4);
				vec5 = _mm256_i32gather_epi32 ((int const *)&B[i][j+4],vindex,4);
				vec6 = _mm256_i32gather_epi32 ((int const *)&B[i][j+5],vindex,4);
				vec7 = _mm256_i32gather_epi32 ((int const *)&B[i][j+6],vindex,4);
				vec8 = _mm256_i32gather_epi32 ((int const *)&B[i][j+7],vindex,4);
				
				//storing to the rows
				_mm256_store_si256((__m256i *)&B_T[j+0][i], vec1);
				_mm256_store_si256((__m256i *)&B_T[j+1][i], vec2);
				_mm256_store_si256((__m256i *)&B_T[j+2][i], vec3);
				_mm256_store_si256((__m256i *)&B_T[j+3][i], vec4);
				_mm256_store_si256((__m256i *)&B_T[j+4][i], vec5);
				_mm256_store_si256((__m256i *)&B_T[j+5][i], vec6);
				_mm256_store_si256((__m256i *)&B_T[j+6][i], vec7);
				_mm256_store_si256((__m256i *)&B_T[j+7][i], vec8);

				
			}//IACA_END//ii++;
		}
		
		
		//__m256i a_hi;
		for( i=0;i<MAX1;i++){
			for(j=0;j<MAX3;j++){
				vsum1 = _mm256_setzero_si256();
				//vsum2 = _mm256_setzero_si256();
				//vsum3 = _mm256_setzero_si256();
				//vsum4 = _mm256_setzero_si256();
				//vsum5 = _mm256_setzero_si256();
				//vsum6 = _mm256_setzero_si256();
				//vsum7 = _mm256_setzero_si256();
				//vsum8 = _mm256_setzero_si256();
				
				for(k=0;k<MAX2;k=k+8){//IACA_START
					
					vsum1 = _mm256_add_epi32(vsum1,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i][k]) , _mm256_load_si256((__m256i *)&B_T[j][k])));


					/*vec1    = _mm256_load_si256( (__m256i *) &A[i][k] );
					vec2    = _mm256_load_si256( (__m256i *) &B_T[j][k]);
					vec3    = _mm256_mullo_epi32(vec1, vec2);	
					vsum1 = _mm256_add_epi32(vsum1, vec3);*/
/*
					vsum1 = _mm256_add_epi32(vsum1,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i][k]) , _mm256_load_si256((__m256i *)&B_T[j][k])));
					vsum2 = _mm256_add_epi32(vsum2,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i+1][k]) , _mm256_load_si256((__m256i *)&B_T[j+1][k])));
					vsum3 = _mm256_add_epi32(vsum3,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i+2][k]) , _mm256_load_si256((__m256i *)&B_T[j+2][k])));
					vsum4 = _mm256_add_epi32(vsum4,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i+3][k]) , _mm256_load_si256((__m256i *)&B_T[j+3][k])));
					vsum5 = _mm256_add_epi32(vsum5,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i+4][k]) , _mm256_load_si256((__m256i *)&B_T[j+4][k])));
					vsum6 = _mm256_add_epi32(vsum6,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i+5][k]) , _mm256_load_si256((__m256i *)&B_T[j+5][k])));
					vsum7 = _mm256_add_epi32(vsum7,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i+6][k]) , _mm256_load_si256((__m256i *)&B_T[j+6][k])));
					vsum8 = _mm256_add_epi32(vsum8,_mm256_mullo_epi32(_mm256_load_si256((__m256i *)&A[i+7][k]) , _mm256_load_si256((__m256i *)&B_T[j+7][k])));*/

				}//IACA_END 
				
				//a_hi = _mm256_permute2x128_si256(sum0_i, sum0_i, 1); //maybe it should be 4 
				//sum0_i = _mm256_hadd_epi32(sum0_i, a_hi);
				//sum0_i = _mm256_hadd_epi32(sum0_i, sum0_i);
				//sum0_i = _mm256_hadd_epi32(sum0_i, sum0_i);
				//c_result[i][j] = _mm256_extract_epi32(sum0_i,0);
				_mm256_store_si256((__m256i *)&temp8[0] , vsum1);
				//C[i][j] =_mm256_hadd2_epi32(vsum1);
				//
				
				C[i][j]= temp8[0]+temp8[1]+temp8[2]+temp8[3]+temp8[4]+temp8[5]+temp8[6]+temp8[7];
				/*C[i][j] =_mm256_hadd2_epi32(vsum1);
				C[i+1][j] =_mm256_hadd2_epi32(vsum2);
				C[i+2][j] =_mm256_hadd2_epi32(vsum3);
				C[i+3][j] =_mm256_hadd2_epi32(vsum4);
				C[i+4][j] =_mm256_hadd2_epi32(vsum5);
				C[i+5][j] =_mm256_hadd2_epi32(vsum6);
				C[i+6][j] =_mm256_hadd2_epi32(vsum7);
				C[i+7][j] =_mm256_hadd2_epi32(vsum8);*/

			}
		}
				
		end_rdtsc//)
				saveintMatrixFileForOutPuts(C);

	//printf(" The best time: repetition for %dX%d matrix , result is %d \n", MAX1, MAX1, C[i/2][j/2]);
	
	return 0;
}

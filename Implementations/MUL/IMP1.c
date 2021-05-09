#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally





int __attribute__(( aligned(32))) a[MAX1][MAX2]  
  , __attribute__(( aligned(32))) b[MAX2][MAX3] 
  , __attribute__(( aligned(32))) c_result[MAX1][MAX3] 
  , __attribute__(( aligned(32))) c_tra[MAX3][MAX2];

//

int main()
{
	singleCore
	assignMatrixi32(a);
	assignMatrixi32(b);
	int i, j, k, temp;
	programName="MUL1";
	//REP_CODE(
	begin_rdtsc  
	
		for( i=0;i<MAX2;i++){
			for(j=0;j<MAX3;j++){//IACA_START
				c_tra[j][i] = b[i][j];

			 }//IACA_END
		}
		
		for( i=0;i<MAX1;i++){
			for(j=0;j<MAX3;j++){
				temp=0;
				for(k=0;k<MAX2;k++)	{//IACA_START
					temp += a[i][k] * c_tra[j][k];
				}//IACA_END		
				c_result[i][j] = temp;

			}
		}
	end_rdtsc//)
	
		saveintMatrixFileForOutPuts(c_result);
	//printf(" The best time:repetition for %dX%d matrix , result is %d \n", MAX1, MAX1, c_result[i/2][j/2]);
	
	return 0;
}

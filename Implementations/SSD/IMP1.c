

#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally




//global data for sequentila matrix operations
short int a_short[MAX1][MAX2] __attribute__(( aligned(32)));
short int b_short[MAX2][MAX3] __attribute__(( aligned(32)));


int main()
{
	singleCore
	assignMatrixi16(a_short);
	assignMatrixi16(b_short);
	int i, j, ssd=0;
			programName="SSD1";

	//REP_CODE(
	begin_rdtsc
		for(i=0; i<MAX1; i++){
			for(j=0; j<MAX2; j++){//IACA_START
				ssd+= ((a_short[i][j]-b_short[i][j]))*((a_short[i][j]-b_short[i][j]));
			}//IACA_END
		}
	
		end_rdtsc//)
		printf("%i", ssd);
		
	return ssd;
}


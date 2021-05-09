#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
#define N MAX1
#define M N
#define	P 5
#define Q P
#define	Cdiv  (P*P)//div for filter 
#define Coffset 2


short int kernel[P][Q] __attribute__(( aligned(32)));
// input and out put matrix MAX1 and MAX2 should be equla to xsize and ysize
unsigned short int input[N][M] __attribute__(( aligned(32)));
unsigned short int output[N][M] __attribute__((aligned(32)));
inline void kernelBuilder( short int kernel[P][Q])
{ 
	int i, j, k=1;
	for(i=0;i<P;i++){
		for(j=0;j<Q;j++)
		{
			kernel[i][j]=1;//k;
			k++;
		}
	}
}	
int main()
{
	singleCore
	assignMatrixui16(input);
	kernelBuilder(kernel);
	int i, j,k=0,temp;
	//That means Conc=volution code which is modified for a 5x5 and the code is written in C and IPM is not used Number 1 means the basic implementation
	programName="CONMOD51";

	
		
		//function to be executed here :
		begin_rdtsc
			for (i=P/2; i< N-P/2; i++){
				for(j=Q/2; j< M-Q/2; j++){
					temp=0;
						temp += (kernel[k/Q][k%Q]) * (input[i - (P/2) + (k/Q)][j - (Q/2) + (k%Q)]);
						temp += (kernel[(k+1)/Q][(k+1)%Q]) * (input[i - (P/2) + ((k+1)/Q)][j - (Q/2) + ((k+1)%Q)]);
						temp += (kernel[(k+2)/Q][(k+2)%Q]) * (input[i - (P/2) + ((k+2)/Q)][j - (Q/2) + ((k+2)%Q)]);
						temp += (kernel[(k+3)/Q][(k+3)%Q]) * (input[i - (P/2) + ((k+3)/Q)][j - (Q/2) + ((k+3)%Q)]);
						temp += (kernel[(k+4)/Q][(k+4)%Q]) * (input[i - (P/2) + ((k+4)/Q)][j - (Q/2) + ((k+4)%Q)]);
						temp += (kernel[(k+5)/Q][(k+5)%Q]) * (input[i - (P/2) + ((k+5)/Q)][j - (Q/2) + ((k+5)%Q)]);
						temp += (kernel[(k+6)/Q][(k+6)%Q]) * (input[i - (P/2) + ((k+6)/Q)][j - (Q/2) + ((k+6)%Q)]);
						temp += (kernel[(k+7)/Q][(k+7)%Q]) * (input[i - (P/2) + ((k+7)/Q)][j - (Q/2) + ((k+7)%Q)]);
						temp += (kernel[(k+8)/Q][(k+8)%Q]) * (input[i - (P/2) + ((k+8)/Q)][j - (Q/2) + ((k+8)%Q)]);
						temp += (kernel[(k+9)/Q][(k+9)%Q]) * (input[i - (P/2) + ((k+9)/Q)][j - (Q/2) + ((k+9)%Q)]);
						temp += (kernel[(k+10)/Q][(k+10)%Q]) * (input[i - (P/2) + ((k+10)/Q)][j - (Q/2) + ((k+10)%Q)]);
						temp += (kernel[(k+11)/Q][(k+11)%Q]) * (input[i - (P/2) + ((k+11)/Q)][j - (Q/2) + ((k+11)%Q)]);
						temp += (kernel[(k+12)/Q][(k+12)%Q]) * (input[i - (P/2) + ((k+12)/Q)][j - (Q/2) + ((k+12)%Q)]);
						temp += (kernel[(k+13)/Q][(k+13)%Q]) * (input[i - (P/2) + ((k+13)/Q)][j - (Q/2) + ((k+13)%Q)]);
						temp += (kernel[(k+14)/Q][(k+14)%Q]) * (input[i - (P/2) + ((k+14)/Q)][j - (Q/2) + ((k+14)%Q)]);
						temp += (kernel[(k+15)/Q][(k+15)%Q]) * (input[i - (P/2) + ((k+15)/Q)][j - (Q/2) + ((k+15)%Q)]);
						temp += (kernel[(k+16)/Q][(k+16)%Q]) * (input[i - (P/2) + ((k+16)/Q)][j - (Q/2) + ((k+16)%Q)]);
						temp += (kernel[(k+17)/Q][(k+17)%Q]) * (input[i - (P/2) + ((k+17)/Q)][j - (Q/2) + ((k+17)%Q)]);
						temp += (kernel[(k+18)/Q][(k+18)%Q]) * (input[i - (P/2) + ((k+18)/Q)][j - (Q/2) + ((k+18)%Q)]);
						temp += (kernel[(k+19)/Q][(k+19)%Q]) * (input[i - (P/2) + ((k+19)/Q)][j - (Q/2) + ((k+19)%Q)]);
						temp += (kernel[(k+20)/Q][(k+20)%Q]) * (input[i - (P/2) + ((k+20)/Q)][j - (Q/2) + ((k+20)%Q)]);
						temp += (kernel[(k+21)/Q][(k+21)%Q]) * (input[i - (P/2) + ((k+21)/Q)][j - (Q/2) + ((k+21)%Q)]);
						temp += (kernel[(k+22)/Q][(k+22)%Q]) * (input[i - (P/2) + ((k+22)/Q)][j - (Q/2) + ((k+22)%Q)]);
						temp += (kernel[(k+23)/Q][(k+23)%Q]) * (input[i - (P/2) + ((k+23)/Q)][j - (Q/2) + ((k+23)%Q)]);
						temp += (kernel[(k+24)/Q][(k+24)%Q]) * (input[i - (P/2) + ((k+24)/Q)][j - (Q/2) + ((k+24)%Q)]);
					output[i][j]=((temp/(Cdiv))+Coffset);
				}
			}
		end_rdtsc
	printf("\nThe  %d X matrix \n", output[N/2][ M/2]);

	return 0;
}

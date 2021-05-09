#include "MAX.h" //this header is for assigning MAX values and NUM_LOOP globally
#define N MAX1
#define M N
#define	P 7
#define Q P
#define	Cdiv  P*P //div for filter 
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
	//assignMatrixui16(input);
	//kernelBuilder(kernel);
	int i, j,k=0,temp;
	//That means Conc=volution code which is modified for a 7x7 and the code is written in C and IPM is not used Number 1 means the basic implementation
	programName="CONMOD71";

	
		
		//function to be executed here :
		begin_rdtsc
		
		
	for (i=P/2; i< N-P/2; i++){
		//
		for(j=Q/2; j< M-Q/2; j++){//__asm__ __volatile__ ( "#mark1");
			temp=0;

			//for(k=0; k< (P*Q)-6; k+=7){//IACA_START
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
				temp += (kernel[(k+25)/Q][(k+25)%Q]) * (input[i - (P/2) + ((k+25)/Q)][j - (Q/2) + ((k+25)%Q)]);
				temp += (kernel[(k+26)/Q][(k+26)%Q]) * (input[i - (P/2) + ((k+26)/Q)][j - (Q/2) + ((k+26)%Q)]);
				temp += (kernel[(k+27)/Q][(k+27)%Q]) * (input[i - (P/2) + ((k+27)/Q)][j - (Q/2) + ((k+27)%Q)]);
				temp += (kernel[(k+28)/Q][(k+28)%Q]) * (input[i - (P/2) + ((k+28)/Q)][j - (Q/2) + ((k+28)%Q)]);
				temp += (kernel[(k+29)/Q][(k+29)%Q]) * (input[i - (P/2) + ((k+29)/Q)][j - (Q/2) + ((k+29)%Q)]);
				temp += (kernel[(k+30)/Q][(k+30)%Q]) * (input[i - (P/2) + ((k+30)/Q)][j - (Q/2) + ((k+30)%Q)]);
				temp += (kernel[(k+31)/Q][(k+31)%Q]) * (input[i - (P/2) + ((k+31)/Q)][j - (Q/2) + ((k+31)%Q)]);
				temp += (kernel[(k+32)/Q][(k+32)%Q]) * (input[i - (P/2) + ((k+32)/Q)][j - (Q/2) + ((k+32)%Q)]);
				temp += (kernel[(k+33)/Q][(k+33)%Q]) * (input[i - (P/2) + ((k+33)/Q)][j - (Q/2) + ((k+33)%Q)]);
				temp += (kernel[(k+34)/Q][(k+34)%Q]) * (input[i - (P/2) + ((k+34)/Q)][j - (Q/2) + ((k+34)%Q)]);
				temp += (kernel[(k+35)/Q][(k+35)%Q]) * (input[i - (P/2) + ((k+35)/Q)][j - (Q/2) + ((k+35)%Q)]);
				temp += (kernel[(k+36)/Q][(k+36)%Q]) * (input[i - (P/2) + ((k+36)/Q)][j - (Q/2) + ((k+36)%Q)]);
				temp += (kernel[(k+37)/Q][(k+37)%Q]) * (input[i - (P/2) + ((k+37)/Q)][j - (Q/2) + ((k+37)%Q)]);
				temp += (kernel[(k+38)/Q][(k+38)%Q]) * (input[i - (P/2) + ((k+38)/Q)][j - (Q/2) + ((k+38)%Q)]);
				temp += (kernel[(k+39)/Q][(k+39)%Q]) * (input[i - (P/2) + ((k+39)/Q)][j - (Q/2) + ((k+39)%Q)]);
				temp += (kernel[(k+40)/Q][(k+40)%Q]) * (input[i - (P/2) + ((k+40)/Q)][j - (Q/2) + ((k+40)%Q)]);
				temp += (kernel[(k+41)/Q][(k+41)%Q]) * (input[i - (P/2) + ((k+41)/Q)][j - (Q/2) + ((k+41)%Q)]);
				temp += (kernel[(k+42)/Q][(k+42)%Q]) * (input[i - (P/2) + ((k+42)/Q)][j - (Q/2) + ((k+42)%Q)]);
				temp += (kernel[(k+43)/Q][(k+43)%Q]) * (input[i - (P/2) + ((k+43)/Q)][j - (Q/2) + ((k+43)%Q)]);
				temp += (kernel[(k+44)/Q][(k+44)%Q]) * (input[i - (P/2) + ((k+44)/Q)][j - (Q/2) + ((k+44)%Q)]);
				temp += (kernel[(k+45)/Q][(k+45)%Q]) * (input[i - (P/2) + ((k+45)/Q)][j - (Q/2) + ((k+45)%Q)]);
				temp += (kernel[(k+46)/Q][(k+46)%Q]) * (input[i - (P/2) + ((k+46)/Q)][j - (Q/2) + ((k+46)%Q)]);
				temp += (kernel[(k+47)/Q][(k+47)%Q]) * (input[i - (P/2) + ((k+47)/Q)][j - (Q/2) + ((k+47)%Q)]);
				temp += (kernel[(k+48)/Q][(k+48)%Q]) * (input[i - (P/2) + ((k+48)/Q)][j - (Q/2) + ((k+48)%Q)]);
 

				
			//}//IACA_END
			output[i][j]=((temp/(Cdiv))+Coffset);//__asm__ __volatile__ ( "#mark2");
		}
	}
		end_rdtsc
		
	printf("\nThe  %d X matrix \n", output[N/2][ M/2]);

	return 0;
}

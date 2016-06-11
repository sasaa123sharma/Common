//Position of right most set bit
//Ideas are
//
//take a number and do bitwise 'and' with 2's compliment
//finally take the log
//
//Take a number and take numnber -1, now the revert the bits of number -1 
//Do biwise operation of num & ~(num -1) and finally take log of that 
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int RightSetBit(int num)
{
	return log2(num & ~(num - 1));	
}


int RightSetBit1(int num)
{
	return log2(num & -num);	
	//here negative numbers are being repseneted as two's compliment
	// -num = ~(num) and add 1(on last bit) 
}

int main()
{
	int num = 0;
	
	printf("enter the numnber\n");
	scanf("%d", &num);
	printf("right most set bit = %d\n", RightSetBit(num));
	printf("right most set bit = %d\n", RightSetBit1(num));

	return 0;
}

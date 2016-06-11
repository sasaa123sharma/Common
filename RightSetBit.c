//Position of right most set bit
//Ideas are
//
//Take number and a counter; try bitwise & with 1; print the counter value if it is '&' operation gives 1;
//Else number right shift by 1
//Repeat above step
//
//Take a number and do bitwise 'and' with 2's compliment
//finally take the log
//
//Take a number and take numnber -1, now the revert the bits of number -1 
//Do biwise operation of num & ~(num -1) and finally take log of that 
//
//One Special case if number got only one set bit, so do log2(num) will give the 
//Position of set bit

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


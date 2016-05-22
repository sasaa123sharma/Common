//A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.
//
#include <stdio.h>
#include <stdlib.h>
unsigned int CountBits(unsigned int n)
{
	unsigned int count = 0;
	while(n)
	{
		n = n & (n-1);
		count++;
	}
	return count;
}

int CheckBleak(unsigned int  n)
{
	unsigned int i = 1;
	
	for(; i < n; i++)
	{
		if(i + CountBits(i) == n)
			return 1;
	}
	return 0;
}

int main()
{
	
	unsigned int n = 0;
	
	scanf("%u", &n);
	
	if(CheckBleak(n))
		printf("Number is not bleak number\n");
	else
		printf("Number is bleak number\n");
		
	return 0;
}

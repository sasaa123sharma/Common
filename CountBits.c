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

int main()
{

	unsigned int n  = 0;
		
	scanf("%d", &n);
	
	printf("%u\n", CountBits(n));

	//We can use also another built in function for this
	//this is provided by gcc
	//— Built-in Function: int __builtin_popcount (unsigned int x)
	//
	//    Returns the number of 1-bits in x. 
	printf("%u\n", __builtin_popcount(n));
	return 0;
}

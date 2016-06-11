//Check if number id power of two
//So number should have only one set bit
//
//Idea is 
//
//If output num & (num -1) is 0 i.e. we had only one bit set >> so number is power of two
//
//Keep dividing number by two till num is one and check if num%2 is non zero at any point
//Denotes num is not power of two else it is power of two  
//
#include <stdio.h>

int PowerOfTwo(int num)
{
	if(num < 1)//expecting number is >= 1
		return 0;
	return (!(num & (num-1)))?1:0; 
}


int PowerOfTwo1(int num)
{
	if(num < 1)////expecting number is >= 1
		return 0;

	
	while(num > 1)
	{
		if(num%2)
			return 0;
		num = num >> 1;
	}
	return 1; 
}


int main()
{

	int num = 0;
	printf("Enter number \n");
	
	scanf("%d", &num);

	if(PowerOfTwo(num))
		printf("YES\n");
	else
		printf("NO\n");

	
	if(PowerOfTwo(num))
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}


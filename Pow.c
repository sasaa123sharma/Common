//Calculate x^y, recursively and using iteration
//Ideas
//
//1. Multiply x, y time
//
//2. Do half every time and calculate recursively /Iterative ==O(logn)  
//

#include <stdio.h>
#include <stdlib.h>

int Pow(int a, int b)
{
	int i = 0;
	int result = 1;

	while(i < b)
	{
		result = result *a;
		i++;
	}
	return result;
}

//Recursive 
int Pow1(int a, int b)
{
	if(!b) 
		return 1;
 
	int temp = Pow1(a, b/2);

	if(!(b%2))//in case of even powers
		return temp * temp;

	else //in case of odd powers
		return a * temp * temp; 
}

//Iterative
int Pow2(int a, int b)
{
	int result  = 1;

	while(b)
	{
		if((b%2))//power is odd, min input can be 1
			result = result * a;

		//now divide by 2
		b = b >> 1;
		a = a *a;
	}

	return result;
}


//power for negative powers and floating numbers
float Pow3(float a, int b)
{
	if(!b)
		return 1; 

	int flag = 0;
	float result = 1;
		

	if(b < 0) //for negative powers
	{
		b = b * -1;
		flag = 1;
	}

	printf("%d\n", b);

	while(b)
	{
		if(b & 1) //if power is odd
			result = result * a;

		b = b >> 1;
		a = a * a;
	}	

	if(flag)
		return 1/result;
		
	return result;
}


int main()
{
	//int a = 10;
	//int b = 4;

	float a = 3.412;
	int b = -2;

	//printf("10^4 = %d\n", Pow(a, b));
	//printf("10^4 = %d\n", Pow1(a, b));
	//printf("10^4 = %d\n", Pow2(a, b));
	printf("10^4 = %f\n", Pow3(a, b));

	return 0;
}

//find missing number
//
//Use summation method 
//Also XOR method can be used


#include <stdio.h>
#include <stdlib.h>

int XOR(int a, int b)
{
	int X = a & b;
	int Y = ~a & ~b;
	return (~X & ~Y); 
}


//Sum 
//In summation method we can get overflow if numbers are two large
//so take a known number and subtract from each element
//Just one guess -- use middle number, should be helping
//Then use this method
int MissingBySum(int *a, int size)
{	
	//sum of n numbers from 1 to n
	int sum = ((size+1) *(size+1+1))/2;
	int temp_sum = 0;

	int i = 0;
	for(i = 0; i < size ; i++)
		temp_sum = temp_sum + a[i];
	

	return sum - temp_sum;
}


//By XOR
//XOR of two same numbers gives 0
int MissingByXor(int *a, int size)
{
	int i = 0;
	int Xor1 = a[0];
	int Xor2 = 1;

	for(i = 1; i < size; i++)
		Xor1 = XOR(Xor1, a[i]); 

	for(i = 2; i <= size+1; i++)
		Xor2 = XOR(Xor2, i);

	
	return XOR(Xor1, Xor2);
}


int main()
{
	int a[] = {1, 2, 3, 5, 6, 7, 8};

	int size = sizeof(a)/sizeof(int);

	printf("missing number = %d\n", MissingBySum(a, size)); 
	printf("missing number = %d\n", MissingByXor(a, size)); 

	return 0;
}


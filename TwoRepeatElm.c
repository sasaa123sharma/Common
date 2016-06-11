//Find the two repeating elements in a given array
//You are given an array of n+2 elements. All elements of the array are in range 1 to n.
//And all elements occur once except two numbers which occur twice. Find the two repeating numbers. 
//
//Solutions 
//
//Sort the array and find out the repeating elements ==> O(nlogn)
//
//Mark the visited elements
//traverse array and mark element negative at Abs(a[i]) and if element is already negative it is repeat of Abs(a[i]) ==>O(n)
//
//
//XOR method
//do XOR of whole array and numbers from 1 to n
//now this XOR will contain both nnumbers
//find right most set bit in this XOR 
//now divide the org array in two sets one set of elements which has same bit set as right most set bit of above XOR
//take the xor(xor2) of all elements on the org array and of numbers 1 to n which has same bit set as right most set bit
//other xor2 of all elements on the org array and of numbers 1 to n which does not have same bit set as right most set bit 
//these two xor1 and xor2 will be the two repeated elements
//
//
//Take one count array of size n-1(1 to n)
//traverse org array, increase count in count array if count is more than one then it is repeated => O(n), space also O(n)
//
//Use sum and product method
//
//
//Use basic method
//here take each element one by one and see if this element is present in array ==> O(n2)  
//


#include <stdio.h>
#include <stdlib.h>

int XOR(int a, int b)
{
	int x = a & b;
	int y = ~a & ~b;
	return (~x & ~y);
}

void TwoRepeatElm(int *a, int size, int *x, int *y)
{
	int i = 0;
	
	int Xor = 0, RtSetBit = 0, Xor1 = 0, Xor2 = 0;
	
	for(i = 0 ; i < size ; i++)
		Xor = XOR(Xor, a[i]);

	for(i = 1 ; i <= size - 2 ; i++)
		Xor = XOR(Xor, i);

	RtSetBit = Xor & ~(Xor-1); 
	

	for(i = 0 ; i < size ; i++)
	{
		if(a[i] & RtSetBit)
			Xor1 = XOR(Xor1, a[i]);
		else
			Xor2 = XOR(Xor2, a[i]);
	}

	for(i = 1 ; i <= size -2; i++)
	{
		if(i & RtSetBit)
			Xor1 = XOR(Xor1, i);
		else
			Xor2 = XOR(Xor2, i);
	}
		
	*x = Xor1;
	*y = Xor2;

	return ;
}


int main()
{
	//int arr[] = {1, 3, 2, 2, 1};
	int arr[] = {4, 2, 4, 5, 2, 3, 1};
	int size = sizeof(arr)/sizeof(int);

	int elm1, elm2;

	TwoRepeatElm(arr, size, &elm1, &elm2);
	printf("two elements elm1 = %d and elm2 = %d\n", elm1, elm2);

	return 0;
}


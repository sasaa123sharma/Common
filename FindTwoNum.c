/*
1. Sorting - O(nlogn)
	a. Do sorting
	b. Find out who is reapeating and missing	
	
2. XOR method
	a. Do XOR of actual array and range 1 to n >> X1 = 2 XOR 3 -- missing and repeating number
	b. Now if we take any set bit in the XOR and we divide the number in two sets. One set will contain the numbers which has the same set bit and another
	   one will have the numbers, which does not have that particular bit set.
	c. If we do the XOR of nummbers in first set then we will get one number and from another set we will get Y.
	
	For ex:
			1 2 2 4 5 6 7 ==> given actual - 1 2 3 4 5 6 7
			X1 = 2 ^ 3
			
			lets take one set bit of X1 which is right most bit
			Now take the XOR of all numbers which has set bit set
			X = 1 ^5 ^7
			Y = 1 ^2 ^2 ^4 ^6
			
			and if we do the same thing the actual array
			
			X = 1 ^ 5 ^ 7 ^ 1 ^ 3 ^ 5 ^ 7 = 3
			Y = 1 ^2 ^2 ^4 ^6 ^ 1 ^2 ^4 ^6 = 2 
			
	
3. Take array, size of same range, initiliaze with INT_MIN
	a. scan orginal array and put element at correct location
	b. If element exist then this would be repeating 
	c. And scan the other array, if at place we have left with INT_MIN then this would be the missing element.
	
4. 	Take array and traverse , while traversing use absolute value as index and make value at that index negative. 
	Now while traversing if get any element that is already negative, it will be repeating number.(we can use this method as range is 1 to n)
	TO find missing, again traverse the array again and see the positive element. (we can use this method as range is 1 to n, so all positive)


5.  Another method we can use is - 
	a. Lets take two elements X(repeating) and Y is missing.
	b. Use sum funda
		Actual sum from 1 to n = n(n+1)/2
		But the given array sum would be equal to (n(n+1)/2 + X - Y) ==> remove missing and add repeated element
	3. Use multiplication 
		Actual multi of 1 to n = 1*2*3*....*n
		But the given array multiplication would be equal to 1*2*3*...*n*X/Y ==> divide by missing and multiplying by repeated element
		
	But this method can cause Integer overlfow issue.
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Abs(int input)
{
	return input < 0 ? (input * -1) : input;
	
}

//Mark the visited place
//don't change the original array
void FindTwoNum(const int *arr, int size, int *missed, int *repeat)
{
	int i = 0; 
	int temp = 0;
	*repeat = INT_MIN;
	

	//Don't change array here so make a local copy gere
	int a[size];

	for(i = 0; i < size ; i++)
		a[i] = arr[i];

	for(i = 0; i < size ; i++)
	{
		//temp = a[Abs(a[i])];
		temp = a[Abs(a[i]) - 1]; //as we are starting from 0
		if(temp < 0)
		{
			*repeat = Abs(a[i]);
			//break; //don't break from here, mark whole array as negative so it will easy to find missing element
		}
		else
			a[Abs(a[i]) -1 ] = temp * -1; 
	}
	
	//for missed number, check if at all in any position number is positive
	//That means element equal to position +1 is not there in the array
	for(i = 0; i < size ; i++)
	{
		if(a[i] > 0)
		{
			*missed = i+1;
			break;
		}
	}
	printf("repeat = %d and missed = %d\n", *repeat, *missed);

	return;
}


int XOR(int a, int b)
{
	int X = a & b;
	int Y = ~a & ~b;
	return (~X & ~Y);
}

void FindTwoNumXor(int *arr, int size, int *missed, int *repeat)
{
	int i = 0, j = 0;
	int Xor = 0;

	for(i = 0; i < size ; i++)
		Xor = XOR(Xor, arr[i]);

	for(i = 1; i <= size ; i++)
		Xor = XOR(Xor, i);

	printf("XOR = %d\n", Xor);

	//Now Xor wil have only repeating and missing element
	int Rt_Set_Bit = 0; //right most set bit 
	Rt_Set_Bit = Xor & ~(Xor -1);

	printf("Rt_Set_Bit = %d\n", Rt_Set_Bit);
	
	//divide numbers in two sets 
	//one which has same set bit and another one which does not have right most bit set
		
	int Xor1 = 0;
	int Xor2 = 0;
	for(i = 0; i < size ; i++)
	{
		if(arr[i] & Rt_Set_Bit)
			Xor1 = XOR(Xor1, arr[i]);
		else
			Xor2 = XOR(Xor2, arr[i]);

		//move below loop here
		if((i+1) & Rt_Set_Bit)
			Xor1 = XOR(Xor1, i+1);
		else
			Xor2 = XOR(Xor2, i+1);
	}
	
	//moved this loop up
	/*for(i = 1; i <= size ; i++)
	{
		if(i *Rt_Set_Bit)
			Xor1 = XOR(Xor1, i);
		else
			Xor2 = XOR(Xor2, i);
	}
	*/

	//here we have now two numbers Xor1 and Xor2 
	//But we need to find out who is repeating and missing
	
	//scan array once more and see if one of element is there
	//if it is there then it is reapeting else this will be missing
	
	*repeat = Xor2;
	*missed = Xor1;
	for(i = 0; i < size ; i++)
	{
		if(arr[i] == Xor1)
		{
			*repeat = Xor1;
			*missed = Xor2;
			break;
		}
	}

	return;
}

int main()
{
	int arr[] = {7, 3, 4, 5, 5, 6, 2};
	int size = sizeof(arr)/sizeof(int);
	
	int missed = 0;
	int repeat = 0;
	
	//FindTwoNum(arr, size, &missed, &repeat);
	FindTwoNumXor(arr, size, &missed, &repeat);

	int i = 0;
	for(i = 0; i < size ; i++)
		printf("%d  ", arr[i]);

	printf("\n");

	printf("repeat = %d and missed = %d\n", repeat, missed);

	return 0;
}



//Absolute distinct count in a sorted array
//Given a sorted array of integers, return the number of distinct absolute values among the elements of the array. The input can contain duplicates values.

//Idea can be as follows
//
//Since array is sorted 
//So if we would have need to consider only the values
//we can check only if prev scanned element is same as  current scanned element or not
//
//But here we need to consider Absolute values also 
//So--
//scan array from left and right together
//since it is sorted array so maximum element will be at end
//scan fist element from left and see last element if it matching or greater or small
//If last element is matching then do not increase count
//If it is greater then increase count
//scan the array from right till last elements are not smaller for this particular left scan -- as in case of negative and postive elements left element and right element can only be matched till right array is greater/equal to left part of array 
//Now scan array from left again 
//If previous left scanned element and this element is not same then only increase the count
//Now scan array from right again where you had left earlier
//repeat this
//
//Note here we need to scan array from left, only till the our untouched right array  

#include <stdio.h>
#include <stdlib.h>

//absolute of a
int Abs(int a)
{
	if(a < 0)
		return a*(-1);
	return a;
}

int AbsDistCount(int *a, int size)
{
	int i = 0, j = size -1;
	int count = 1;
	int temp = 0;
	
	for( i  = 0; i <= j; i++)
	{
		if( i > 0 && (Abs(a[i-1]) != Abs(a[i])))
			count++;

		while((Abs(a[j]) >= Abs(a[i])) && j >= i )
		{
			if(j == (size -1))
			{
				if(Abs(a[i]) != Abs(a[j]))
					count++;
			}
			else
			{
				if(Abs(a[j]) != Abs(a[j+1]) && Abs(a[j]) != Abs(a[i]))	
					count++;
			}
			j--;
		}
		
	}
	return count;
}


int main()
{
	//int a[] = {-1,-1,-1,-1,0};
	//int a[] = {-1, -1, -1, -1, 0, 1, 1, 1, 1};
	//int a[] = {-3, -2, 0, 3, 4, 5};
	//int a[] = {-2, -1, 0, 1, 1};
	//int a[] = {-21, -11, -10, -9, -8};
	int a[] = {0, 0, 0, 0, 0};
	printf("%d\n", AbsDistCount(a, sizeof(a)/sizeof(int)));
	return 0;
}

//find missing elements in a range and misssing elements should be printed in sorted order
//
//Given an array arr[0..n-1] of distinct elements and a range [low, high], find all numbers that are in range, but not in array. 
//The missing elements should be printed in sorted order.
//
//For Ex: 
//Input: arr[] = {10, 12, 11, 15}, 
//low = 10, hight = 15
//Output: 13, 14
//
//Solutions - 
//use sorting method- sort it and print elements in sorted order whatever is missing -- O(nlogn), space we can optimise here
//
//Use another array with elements equal to range
//scan given array and mark that element in another array with like INT_MIN or something
//better way is -- scan given array and see if that element is there else print it -- But this does not gaurantee give you sorting order  
//Whatever is non INT_MIN, print that - O(n)  but we need equal to range

#include <limits.h>
#include <stdio.h>

void MissingInRange(int *a, int size, int low, int high)
{
	int n = high - low +1;
	int i = 0;
	int new[n];
	
	for(i = 0; i < n ; i++)
		new[i] = i + low;


	for(i = 0; i < size ; i++)
	{
		if(a[i] == new[a[i] - low])
			new[a[i] - low] = INT_MIN;
	}

	printf("Missing Elements are\n");
	for(i = 0; i < n ; i++)
	{
		if(new[i] != INT_MIN)
			printf("%d  ", new[i]);
	}
	
	printf("\n");

	return;
}


int QPart(int *a, int low, int high)
{
	int pivot = a[high];
	int i = low;
	int index = low; 

	for(i = low; i < high ; i++)
	{
		if(a[i] < pivot)
		{
			int temp = a[i];
			a[i] = a[index];
			a[index] = temp;
			index++;
		}
	}

	//swap a[high] and a[index]
	
	int temp = a[index];
	a[index] = a[high];
	a[high] = temp;
	
	return index;
}


void QSort(int *a, int low, int high)
{
	if(low < high)
	{
		int Pvt = QPart(a, low, high); 
		QSort(a, low, Pvt - 1);		
		QSort(a, Pvt + 1, high);		
	}
	return ;
}

void MsngInRngUsngSrtng(int *a, int size, int low, int high)
{
	//QSort(a, 0, size);
	QSort(a, 0, size - 1);
		
	int i = 0, j = 0;
	//for(i = 0; i < size ; i++)
	//	printf("%d  ", a[i]);
	
	//printf("\n");

	printf("missed elements\n");
	for(i = 0; i < size ; i++)
	{
		if(!i)
		{
			if(a[i] > low)
			{
				j = low;
				while( j < a[i])
				{
					printf("%d  ", j);
					j++;
				}
			}
		}
		else if(a[i] != a[i-1] +1)
		{
			j = a[i- 1]; 
			while( ++j < a[i])//first increase j and then print as need to print one more than previous element
				printf("%d  ", j);
		}
	}
	
	//check for last element here, in case if it is less than the high
	if(a[i-1] < high)
	{
		j = a[i- 1]; 
		while( ++j <= high )//first increase j and then print
			printf("%d  ", j);
	}
	
	return;
}


int main()
{
	//int arr[] = {10, 12, 11, 15};
	//int arr[] = {12, 11};
	//int arr[] = {10, 12, 11};
	//int arr[] = {12, 11, 15};
	int arr[] = {11};
	
	
	MissingInRange(arr, sizeof(arr)/sizeof(int), 10, 15);
	MsngInRngUsngSrtng(arr, sizeof(arr)/sizeof(int), 10, 15);

	return 0;
}

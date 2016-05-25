//Find the smallest and second smallest element in an array
//
//
//Idea is --
//
//we can do it after sorting the array -- O(nlogn)
//
//we can do it in two scans --- first find min and then second min
//
//Also we can do it in one scan
//
//Min element you can find it normal way 
//Just update if SecMin also if a[i] < Min, In this case SecMin can be equal to of Min value 
//For the SecMin check, if a[i] > Min and a[i] < SecMin then update SecMin only
//In case if we started with min element so SecMin and Min is not going to update 
//So use one condition if both are equal then update SecMin

#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	//int a[] = {4,5,1,3,2};
	int a[] = {5,4,3,2,1};
	//int a[] = {1,4,3,2,1};
	//int a[] = {1, 2, 3, 4, 5};
	//int a[] = {1, 1, 1, 1, 1};
	//int a[] = {1, 3, 2, 3, 1};
	
	int i = 0, size ;
	size = sizeof(a)/sizeof(int);
	//int Min = a[0], SecMin = a[size -1];//working
	int Min = a[0], SecMin = a[0];//working
	
	
	for(i = 1; i < size; i++)
	{	
		//If Min is greater than a[i]
		//then it is trivial that a[i] will be lesser than second min
		if(Min > a[i])
		{
			SecMin = Min; 
			Min = a[i];		
		}
		//if a[i] is greater than min
		//check, if it is lesser than SecMin, 
		//in that case we can update the SecMin 
		else//a[i] => Min
		{
			if(SecMin > a[i] && a[i] > Min)
				SecMin = a[i];
			else if(SecMin == Min)
				SecMin = a[i];
		}
	}
	printf(" Min = %d and Second Min = %d\n", Min, SecMin);
	return 0;
}

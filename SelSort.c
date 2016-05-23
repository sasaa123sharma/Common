#include <stdio.h>
#include <stdlib.h>


void SelSort(int *a, int size)
{
	int i = 0, j =0;
	int iMin = 0, temp = 0;
	
	//for(i = 0; i < size ; i++)
	for(i = 0; i < size-1 ; i++)
	{
		iMin = i;
		for(j = i ; j < size ; j++)
			if(a[j] < a[iMin])
				iMin = j;

		//swap elements at i and iMin position
		temp = a[i];
		a[i] = a[iMin];
		a[iMin] = temp;	
	}
	return ;
}


int main() 
{
	int i = 0;
	
	int a[] = {2,1,0,3,-1};
	int size = sizeof(a)/sizeof(int);
	SelSort(a, size);
	
	for(i = 0; i < size; i++)
		printf("%d  ", a[i]);
	
	printf("\n");
	return 0;
}

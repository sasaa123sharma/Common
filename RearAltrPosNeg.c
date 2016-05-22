//Modify array with alternate positive & negative items with O(1) extra space
//Solutions
//One way could be use of stacks, if we are allowed to use more space-- use two stacks one for positive and another for negative
//and put elements back one by one alternatively
//
//Another ides is traverse array from left to right if element is correct then move on 
//else find the correct element from back end and swap this element
//complexity will be O(n2) as every time you have to search appropriate element from back
//
//Another approach is -- rearrange elements i.e. negative number and postive number at one side of the array 
//either left array will contain neagtive numbers or positive numbers 
//then in next traverse swap elements at correct position


#include <stdio.h>
#include <stdlib.h>

//first rearrange elements
//then swap
void RearAltrPosNegOther(int *a, int size)
{
	int i =0, j = size -1;
	int flag = 0, temp = 0;

	if(a[i] < 0) flag = 1; //flag one for negative numbers
	
	for( i = 1 ; i <= j ; i++)
	{
		if(flag == 1)//then keep left of array negative else keep positive
		{
			if(a[i] > 0)
			{
				for( ; j > i ; j--)
				{
					if(a[j] < 0) 
					{
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;

						if(i < j)
							j--;
						break;
					}
				}	

			}

		} 
		else
		{
			if(a[i] < 0)
			{
				for( ; j > i ; j--)
				{
					if(a[j] > 0) 
					{
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
						j--;
						break;
					}
				}	
			}
		}
	}

	if(flag && a[j] < 0) j++;
	if(!flag && a[j] >0 ) j++;
	//now interchange elements
	flag = 0;
	i = 0;

	if(a[i] > 0) flag = 1;

	for( i = 1; i < size && j < size; i++)
	{
		if(!flag )
		{
			if(a[i] < 0)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				j++;	
			}
			//next element should be negative
			flag = 1;
		}
		else
		{
			if(a[i] > 0)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				j++;	
			}
			//next element should be positive
			flag = 0;
		}
	}
	return ;
}//complexity O(n)


//first rearrange elements
//then swap
//sorter version
//use quicksort concept to rearrange the elements
void RearAltrPosNegOther2(int *a, int size)
{
	int i = 0;
	int temp = 0;
	int index = 0;
	
	int flag = 0;
	
	if(a[i] < 0)
		flag = 1;

	//quicksort concept to rearrange elements
	//Assume 0 as pivot element
	for( ; i < size ; i++)
	{
		if(flag)//put negative elements at left
		{
			if(a[i] <= 0)
			{
				temp = a[i];
				a[i] = a[index];
				a[index] = temp;
				index++;
			}
		}
		else
		{
			if(a[i] >= 0)
			{
				temp = a[i];
				a[i] = a[index];
				a[index] = temp;
				index++;
			}
		}
	} 
	int j = index ;
	//now interchage the element

	for(i = 1; i < j && j < size; i = i+2, j++)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp ;	
	}
	
	return ;
}//complexity O(n)

void RearAltrPosNeg(int *a, int size)
{
	int i =1, j = size -1, temp =0;
	int flag = 0;//0 for postive and 1 for  negative 
	
	if (a[0] > 0) flag = 1;
	//for(i = 1; i < size ; i++)
	for(i = 1; i < size -1 ; i++)//here size -1 as last element should be as it is
	//for(; j > 0; j--)
	{
		j = size - 1;

		if(flag)
		{
			if(a[i] < 0 ) flag = 0;//next number should be positve
			else
			{
				for(;j>0;j--)
				{
					if(a[j] < 0)
					{
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
						//we should not chane j value 
						//think case -5 3 4 5 -6-2 -8 -9 -1 -4
						//j--
							flag = 0;//next number should be postive 
						break;		
					}
				}
			}
		}
		else
		{
			if(a[i] > 0) flag = 1;//next number should ve negative 
			else
			{
				for(;j>0;j--)
				{
					if(a[j] > 0)
					{
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
						//j--; //do not change j, it will fail
						flag = 1;//next number should be negative
						break;
						
					}
				}
			}
		}
	}
	return ;
}//complexity n2


int main()
{
	int i = 0;
	//int a[] = {-5, 3, -2, 5, -6, 4, -4, 9, -1, 8};
	//int a[] = {-5, 3, -2, 5, -6, -7, -4, 9, -1, 8};
	//int a[] = {-5, -3, -2, -8, -6, -7, -4, -9, -1, -18};
	//int a[] = {5, 3, 2, 8, 6, 7, 4, 9, 1, 18};
	int a[] = {5, -3, -2, 8, 6, -7, -4, 9, -1, 18};
	
	RearAltrPosNeg(a, 10);
	for( i = 0; i < 10; i++)
			printf("%d  ", a[i]);
	printf("\n");
	//int a1[] = {-5, 3, -2, 5, -6, -7, -4, 9, -1, 8};
	//int a1[] = {-5, -3, -2, -8, -6, -7, -4, -9, -1, -18};
	//int a1[] = {5, 3, 2, 8, 6, 7, 4, 9, 1, 18};
	int a1[] = {5, -3, -2, 8, 6, -7, -4, 9, -1, 18};
	RearAltrPosNegOther2(a1, 10);
	for( i = 0; i < 10; i++)
			printf("%d  ", a1[i]);
	printf("\n");
	return 0;
}

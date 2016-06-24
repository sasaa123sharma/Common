//Idea is use 4 for loops to print column and row
//take 4 variables to keep track of Row/Column from front/start
//Also from back
//while looping second time start from increased row/column
//
//Also we can do other way around where we decrease column and row after we done with the last column and bottom row
//increase the count of new top row and new top column also so next time no need to come
//second technique
//
//
//Complexity is O(mn) for both methods

#include <stdio.h>
#include <stdlib.h>

#define R 4
#define C 6

void printSpiral(int a[R][C])
{
	int i = 0, j = 0; //for looping
	int k = 0, l = 0; //keep track of rows and column from back,k == row and l == column
	int p = 0, q = 0; //keep track of rows and column from front,p == row and q == column

	
	while((k+p) < R && (l+q) < C)//once we are done with either rows or columns we can get away
	{
		//print first row first
		for(j = q; j < C -l ; j++)
			printf("%d ", a[i][j]);
	
		p++; //as one row is done
		j--; //as has reached beyond boundary, decrease it by 1
		
		//print the last column
		for(i = p; i <  R - k; i++)
			printf("%d ", a[i][j]);
		l++;//one column is done
		i--;
		if((k+p) < R)
		//now we need to go back row wise and then column wise
			for(j = C-1-l ; j >= q; j--)
				printf("%d ", a[i][j]);
				
		j++;
		k++;

		if((l+q) < C)
			for(i = R-k-1 ; i >= p; i--)
				printf("%d ", a[i][j]);
		i++;
		q++;
	}
	printf("\n");
	return ;
} 

void printSpiral1(int a[R][C])
{
	int i = 0, j = 0; //for looping
	int p = 0, q = 0; //keep track of rows and column from front,p == row and q == column
	int m = R, n = C; //m/n denotes the more number of rows/columns need to track

	
	while(p < m && q < n)//once we are done with either rows or columns we can get away
	{
		//print first row first
		for(j = q; j < n ; j++)
			printf("%d ", a[i][j]);
	
		p++; //as one row is done, so need to start next time from this row only
		j--; //as has reached beyond boundary, decrease it by 1
		
		//print the last column
		for(i = p; i <  m; i++)
			printf("%d ", a[i][j]);

		n--;//one column is done from back, so no need to come till this point from next time 
		i--; //i is now m, just reached beyond boundary so reduce by 1

		//now we need to go back row wise and then column wise
		//if any row/column is remaining then go 
		if(p< m)
		{
			for(j = n-1 ; j >= q; j--)
				printf("%d ", a[i][j]);
			j++;
			m--; //one row is done from bottom, so no need to come till here next time
		}
		if(q < n)
		{
			for(i = m-1 ; i >= p; i--)
				printf("%d ", a[i][j]);
			i++;
			q++;//on column is done, so need to start next time from this column only
		}
	}
	
	printf("\n");
	return ;
} 


int main()
{
	/*
	int matrix[R][C] = { 
						{1,  2,  3,  4,  5,  6},
        				{7,  8,  9,  10, 11, 12},
       					{13, 14, 15, 16, 17, 18},
					   };
	*/

	int matrix[R][C] = { 
						{1,  2,  3,  4,  5,  6},
        				{7,  8,  9,  10, 11, 12},
       					{13, 14, 15, 16, 17, 18},
       					{19, 20, 21, 22, 23, 24}
					   };

	printSpiral(matrix);
	printSpiral1(matrix);

	return 0;
}

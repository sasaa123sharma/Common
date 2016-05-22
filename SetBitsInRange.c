//Copy set bits in a range
//Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in range [l, r] and set these bits in x also
#include <stdio.h>
#include <stdlib.h>

int SetBitsInRange(int x, int y, int l, int r)
{
	int temp = ( y >> (l -1)) & (~(1<< (r-l+1)));
	temp <<= (l -1);
	temp = x | temp;
	return temp;
}

int main()
{
	int l = 0, r = 0;//range
	int x = 0;
	int y = 0;
	printf("enter numbers x and y respectively\n");
	scanf("%d%d", &x, &y);	
	
	printf("enter lower and higher range respectively\n");
	scanf("%d%d", &l, &r);
	printf("%d\n", SetBitsInRange(x,y,l,r));
	
	return 0;
}

//Turn off the rightmost set bit

#include <stdio.h>

int main()
{
	int num = 0;
	
	printf("enter the number\n");
	scanf("%d", &num);

	printf("after turning off the right most set bit %d\n", num & (num-1));
	return 0;
}

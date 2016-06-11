//Two's compliment 
//~(n-1)

#include <stdio.h>

int main()
{
	int num = 0;
	int i = 0;	
	int temp = 0;

	printf("enter the num \n");
	scanf("%d", &num);	
	temp = num;

	printf("binary representation of number\n");
	for(i = 0; i < 32 ; i++)
	{
		if(num & 1)
			printf("%d", 1);
		else 
			printf("%d", 0);

		num = num >> 1;
	}

	num  = -temp;
	printf("\n\nbinary representation of negative number\n");
	for(i = 0; i < 32 ; i++)
	{
		if(num & 1)
			printf("%d", 1);
		else 
			printf("%d", 0);

		num = num >> 1;
	}
	
	//two's compliment
	num  = ~(temp -1);
	printf("\n\nbinary representation of two's compliment\n");
	for(i = 0; i < 32 ; i++)
	{
		if(num & 1)
			printf("%d", 1);
		else 
			printf("%d", 0);

		num = num >> 1;
	}


	return 0;
}

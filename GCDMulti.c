//GCD of multiple numbers
//keep taking GCD of two numbers and gcd of previous two numbers and the next input

#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b);

int main()
{
	printf("enter numbers, to exit enter negative number\n");
	int x =0, y = -1;
	int counter = 0;

	while(1)
	{
		scanf("%d", &x);	
		counter++;

		if(x < 0)
			break;
		else if(y == -1) //for first time
			y = x;
		else
		{
			//x = (x < 0) ? -x : x;
			//y = (y < 0) ? -y : y;
			if(x < y)		
				y = gcd(y, x);
			else
				y = gcd(x, y);
		}			
	}
	if(counter > 1)
		printf("GCD is %d\n", y);
	return 0;
}

//Euclid
int gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b, a%b);
}

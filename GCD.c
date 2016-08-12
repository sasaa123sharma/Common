//greatest common divisor
//GCD of (0, a) = a (where a includes 0)
// http://math.stackexchange.com/questions/495119/what-is-gcd0-0
// http://www.programiz.com/c-programming/examples/hcf-gcd
// http://quiz.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/
// http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/
//http://www.cquestions.com/2008/01/write-c-program-to-find-gcd-of-two.html

#include <stdio.h>
#include <stdlib.h>

//Using loop
//A number max can be divisible either by itself or half of the number 
//for ex: 14 can be divisible by max 7 or 14
//28 max cab be divisible by 14 or 28
int FindGCDloop(int a, int b)
{
	int i = 1;
	int gcd = 1; 
	
	for(;i <= a/2 && i <= b/2 ; i++)
	{
		if(!(a%i) && !(b%i))
			gcd = i;
	}
	//check number itself also, both numbers can be divided by the lessor number
	if(a < b && !(b%a))
		gcd = a;
	else if(!(a%b))//here either a==b or b<a
		gcd = b;
		
	return gcd;
}

//other loop approach can be 
//a and b can be divided by min of a and b
//start loop from the min of two till 1
int FindGCDloop1(int a, int b)
{
	int gcd = 1;
	int i = 0;
	if(a < b)
		i = a;
	else
		i = b;

	for(; i > 0; i--)
		if(!(a%i) && !(b%i))
			return i;	
}

//using subtraction
//subtract lesser from larger, if both are unequal
//GCD of two numbers does not change if smaller number is subtracted from a bigger number. 
int FindGCDsub(int a, int b)
{
	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

//Euclid Algorithm
//complexity => Log Min(a, b)
int FindGCDrec(int a, int b)
{
	if(!a)
		return b;
	return FindGCDrec(b%a, a); //Note ==> order changed

	//Below will work
	/*
 		if(a == b)
			return a;
		if(a< b)
			return FindGCDrec(a, b-a);
		else
			return FindGCDrec(a-b, b);
	*/
	
}

int main()
{
	int a, b;
	
	printf("enter two numbers\n");

	scanf("%d%d", &a, &b);
	
	if(!a)
	{
		printf("GCD of %d and %d is %d\n", a, b, b);
		return 0;
	}

	if(!b)
	{
		printf("GCD of %d and %d is %d\n", a, b, a);
		return 0;
	}

	//modifying it for negative numbers also
	a = (a < 0)? -a : a; 
	b = (b < 0)? -b : b; 
	
	/*if(a < 1 || b < 1)
	{
		printf("Invalid number(s)\n");
		return 0;
	}
	*/
	printf("GCD of %d and %d is %d\n", a, b, FindGCDloop(a, b));
	printf("GCD of %d and %d is %d\n", a, b, FindGCDloop1(a, b));
	printf("GCD of %d and %d is %d\n", a, b, FindGCDsub(a, b));
	printf("GCD of %d and %d is %d\n", a, b, FindGCDrec(a, b));
	return 0;
}

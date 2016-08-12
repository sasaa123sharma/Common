//Extended Euclid algorithm
//http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/
//https://comeoncodeon.wordpress.com/tag/c/page/2/
//http://www.di-mgt.com.au/euclidean.html
//http://stackoverflow.com/questions/12826114/euclids-extended-algorithm-c

//Euclid Algorithm
/*
INPUT: Two non-negative integers a and b with a ≥ b.
OUTPUT: gcd(a, b).
    While b > 0, do
        Set r = a mod b,
        a = b,
        b = r
    Return a.

*/

//Extended Euclid algorithm
/*
INPUT: Two non-negative integers a and b with a ≥ b.
OUTPUT: d = gcd(a, b) and integers x and y satifying ax + by = d.
    If b = 0 
		then set d = a, x = 1, y = 0, 
		and return(d, x, y).
		
    Set x2 = 1, x1 = 0, y2 = 0, y1 = 1
    While b > 0, do
        q = floor(a/b), r = a - qb, x = x2 - qx1, y = y2 - q y1.
        a = b, b = r, x2 = x1, x1 = x, y2 = y1, y1 = y.
		
    Set d = a, x = x2, y = y2, and return(d, x, y).
*/


#include <stdio.h>
#include <stdlib.h>

int EuclidItr(int a, int b);
int EuclidRec(int a, int b);
int ExtendEuclidItr(int a, int b);
int ExtendEuclidRec(int a, int b);
int ExtendEuclidRecUtil(int a, int b, int *x, int *y);

int main()
{
	int a, b;
	int a1, b1, a2;
	printf("enter two numbers\n");
	scanf("%d%d", &a, &b);
	
	//as euclidean algo is only for a >= b where a, b > 0, so modifyimg below
	
	//deal with negative numbers also
	a1 = (a < 0)? -a : a;
	b1 = (b < 0)? -b : b;
	
	if(a1 < b1)
	{
		a2 = a1;
		a1 = b1; 
		b1 = a2;
	}
	
	printf("GCF of %d and %d is %d\n", a, b, EuclidItr(a1, b1));
	printf("GCF of %d and %d is %d\n", a, b, EuclidRec(a1, b1));
	printf("GCF of %d and %d is %d\n", a, b, ExtendEuclidItr(a1, b1));
	printf("GCF of %d and %d is %d\n", a, b, ExtendEuclidRec(a1, b1));
	return 0;
}

int EuclidItr(int a, int b)
{
	int q = 0; 
	while(b > 0)
	{
		q = a%b;
		a = b;
		b = q;
	}
	return a;
}

int EuclidRec(int a, int b)
{
	if(!b)
		return a;
	return EuclidRec(b, a%b);
}

//ax+by = GCD(a, b)
int ExtendEuclidItr(int a, int b)
{
	int x, y ;
	
	if(!a && !b) //0*0 + 0*0 = GCD
	{
		x = 0;
		y = 0;
		return a;
	}
	
	if(!b) //1*a + 0*b  = a 
	{
		x = 1;
		y = 0;
		return a;
	}
	//else
	int x1 = 0, y1 = 1, x2 = 1, y2 = 0;
	int q, r ; 
	while(b > 0)
	{
		q = a/b;
		r = a - q*b; 
		
		x = x2 - q*x1;
		y = y2 - q*y1;
        
		a = b; 
		b = r; 
		
		x2 = x1; 
		x1 = x;
		
		y2 = y1; 
		y1 = y;
	}
	x = x2; 
	y = y2;
	printf("In 'ax + by', x = %d and y = %d\n", x, y);
	//If initially b > a then x = y2 and y = x2
	return a;
}

int ExtendEuclidRec(int a, int b)
{
	int x, y;
	int gcd = ExtendEuclidRecUtil(a, b, &x, &y);
	printf("In 'ax + by', x = %d and y = %d\n", x, y);
	//If initially b > a then x = y and y = x(x and y should be reversed as we are reversing a and b above)
	return gcd;
}

//GCD of two numbers does not change if smaller number is subtracted from a bigger number.
//ax+ by = gcd 
//bx1 + (a%b) y1 = gcd == recursion result
//a%b = a - floor(a/b)*b;
//ay1 + b(x1 - floor(a/b)*y1) = gcd
//x = y1 and y = x1 - floor(a/b)*y1 
int ExtendEuclidRecUtil(int a, int b, int *x, int *y)
{
	//base cases
	if(!a && !b)
	{
		*x = 0;
		*y = 0;
		return a;
	}
	if(!b)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	int x1, y1;
	int gcd  = ExtendEuclidRecUtil(b, a%b, &x1, &y1);
	*y = x1 - (a/b)*y1;
	*x = y1;
	
	return gcd;
}

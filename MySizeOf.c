//sizeof for particular type can be implemented as a function in C. 
//But at a time for all types , function implementation isn't possible. As C does not support function overloading.
//
//So better go with macro

#include <stdio.h>
#include <stdlib.h>

#define mysizeof(type) (char*)(&type+1) - (char *)(&type)

int main()
{
	int a = 0;

	printf("size = %lu\n", mysizeof(a));
	
	return 0;
}

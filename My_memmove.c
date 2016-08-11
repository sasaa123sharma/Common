//copy data from source to temporary buffer and then from temporary buffer to destination buffer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *My_memmove(void *dest, const void *src, size_t n)
{
	char *src_ = (char *)src;
	char *dest_ = (char *)dest;
			
	char temp[n];	
	int i = 0;	
	while( i < n)
	{
		temp[i] = src_[i];	
		i++;
	}
 	
	i = 0;
 	
	while( i < n)
	{
		dest_[i] = temp[i];	
		i++;
	}
	return dest_;
}


int main()
{
	char src[] = "abcdefgh";
	char dest[100];
	
	My_memmove(dest, src, strlen(src)+1);
	
	printf("%s\n", dest);
	printf("%s\n", (char *)My_memmove(dest, src, strlen(src)+1));
	return 0;
}

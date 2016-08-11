//memcpy
//copy character by character from source to destination

#include <stdio.h>
#include <string.h>

void *MyMemcpy(void *dest, const void *src, size_t n)
{
	char *src_ = (char *) src;
	char *dest_ = (char *)dest;
	int i = 0;
	while( i < n)
	{
		dest_[i] = src_[i];
		i++;
	}
	return dest_;
}

int main()
{	
	char src[] = "abcdefgh";
	char dest[100]; 
	MyMemcpy(dest, src, strlen(src)+1);
	printf("%s\n", dest);
	char dest1[100]; 
	printf("return value - %s\n", (char *)MyMemcpy(dest1, src, strlen(src)+1));
	return 0;
}

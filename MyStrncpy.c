#include <stdio.h>
#include <stdlib.h>

char *MyStrncpy(char *dest, const char *src, size_t len);

int main()
{
	char src[] = "sandeepsharma";
	char dest[20];
	MyStrncpy(dest, src, 20);
	
	puts(dest);

	return 0;
}
char *MyStrncpy(char *dest, const char *src, size_t len)
{
	int i = 0;

	while(i < len && src[i] != '\0')
	{	
		dest[i] = src[i];
		i++;
	}

	//if length of src is less than len then it will write additional NULL to dest to make sure those many bytes are written
	while(i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}

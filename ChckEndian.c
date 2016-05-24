//check whether machine is little or big endian
//
//in BIG endian ==> MSB is stored at lower address
//In LITTLE endian ==> LSB is stored at lower address.
//RHS byte called LSB and LHS called MSB

#include <stdio.h>
#include <stdlib.h>

void ChckEndian()
{
	unsigned int iTemp = 1;
	//memory representtaion
	//00000001 ==> in little endian
	//where 01 1is stored at lower address
	//while in big endian
	//01000000 ==> 00 is stored at lower address
	char *ch = (char *)&iTemp;

	if(*ch & 1)
		printf("little endian\n");		
	else
		printf("big endian\n");		

	//you can check the address of bytes of iTemp, one by one 
	printf("%.2x %.2x %.2x %.2x\n", *ch, *(ch+1), *(ch+2), *(ch+3));	
	
	
	return ;		
}

int main()
{
	ChckEndian();
	return 0;
}

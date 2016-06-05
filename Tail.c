//Implementaing code similar to tail command
//here we can read last n lines whenever we need
//but tail functionlity is not there 
//like it will keep upadting the output as file grows i.e. it will replace the current content with next 10 lines
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 100
#define COUNT 20

void Tail(FILE *fp, FILE *fp1);
static int pos;
static int i; 

int main()
{
	//we need two FP here as one for reading next line and one for holding that position
	FILE *fp, *fp1 = NULL;

	fp = fopen("./putty_1.log", "r");
	fp1 = fopen("./putty_1.log", "r");
	//fp1 = fopen("./putty.txt", "r");
	//fp  = fopen("./putty.txt", "r");

	if(!fp)
	{
		printf("failed to open file\n");
		return EXIT_FAILURE;
	}

	//keep it in infinte while loop
	//int j = 0;
	//while(j < 3)
	while(1)
	{
		i = 0;
		pos = 0;
		//printf("j = %d\n", j);
		//Go at the end	
		if(fseek(fp, 0, SEEK_END) == -1)
		{
			printf("fseek failed\n");
			return EXIT_FAILURE;
		} 
		fseek(fp1, 0, SEEK_END);
	
		Tail(fp, fp1);
	
		printf("\n");

		sleep(1);
		//system("clear");	
		//tput();
		//j++;
	}

	fclose(fp);
	fclose(fp1);

	return 0;

}
void Tail(FILE *fp, FILE *fp1)
{
	char buf[SIZE+1] = {0};	
	unsigned int ch = 0;
	int flag = 0;

	//memset(buf, 0x00, SIZE);

	//Go one position back and see if next character is new line
	//This might not possible in case if there is nothing in the file
	fseek(fp, -1, SEEK_CUR);

	//ignore this error here as we need to print the last line here
	//if(fseek(fp, -1, SEEK_CUR) == -1)
	{
	//	printf("fseek failed2\n");
	//	return EXIT_FAILURE;
	} 

	ch = fgetc(fp);

	while(ch != '\n' && ch != EOF)//EOF as there could be nothing in the file
	{
		pos = pos + 1;
		
		//-2 as every time fp will increase by one position, so we need to go two positions back to read the previous char
		if(fseek(fp, -2, SEEK_CUR) == -1)//see failure case if it can't go back two positions
		{
			//for exmaple file has only one character
			//shift one position ahead and break		
			
			fseek(fp, +1, SEEK_CUR);
			break;
		}
		else
		{
			ch = fgetc(fp);
			//printf("%c\n", ch);
		}
	}	

	fseek(fp1, -pos, SEEK_CUR);//read this line using other pointer
	fgets(buf, SIZE, fp1); 

	fseek(fp, -1, SEEK_CUR);//to go back to next upper line

	fseek(fp1, -pos, SEEK_CUR);//as above read operation will change fp1 to end so go back again

	pos = 0;
	pos = pos + 1;

	ch = fgetc(fp);
	fseek(fp, -1, SEEK_CUR);//as above read opeartion wil shift fp one postion ahead so go back one position

	if(ch == '\n' && ++i < COUNT)
	{
		//if ch is '\n' means there are some more lines above
		//printf("came here 3....\n");
		//i++;	//don't check here as it will cause one more iteration to cause
		Tail(fp, fp1);
	}

	printf("%s", buf);

	return ; 
}

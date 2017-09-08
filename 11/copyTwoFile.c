/**
* Source code opening specified file.
*/
#include "copyheader.h"

int main(int argc, char *argv[]){
	
	char buff[100] = {'\0'};	
	int fdRead,fdWrite,readcnt,writecnt;
	fdRead = fdWrite = readcnt = writecnt = 0;

	validateNumberOfArguement(&argc);

	if ((fdRead = open(argv[1],O_RDONLY)) < 0)
	{
		perror("failed Open file");
		return -1;
	}

	if ((fdWrite = creat(argv[2],0666)) < 0)
	{
		printf("Unable to create new file\n");
		return -1;
	}

	while((readcnt = read(fdRead,buff,sizeof(buff)) )!= 0)
	{
		if(writecnt = write(fdWrite,buff,readcnt) == -1)
		{
			printf("Problem in writting");
		}
	}
	close(fdRead);
	close(fdWrite);

	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 3)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
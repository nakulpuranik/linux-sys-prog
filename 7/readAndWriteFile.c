/**
* Source code opening specified file.
*/
#include "customfile.h"

int main(int argc, char *argv[]){
	int fileDesc;
	int ret;
	char buff[256];

	validateNumberOfArguement(&argc);

	fileDesc = open(argv[1],O_WRONLY | O_TRUNC);
	if(fileDesc == -1){
		perror("openSysCall::\n");
		return -1;
	}

	//accept the string to write from the user lmit is 256 byte
	printf("Enter the string to write in file :\n");
	scanf("%[^\n]",buff);

	//write system call
	ret = write(fileDesc,buff,strlen(buff));
	if(ret != strlen(buff)){
		printf("Error: Unable to write all accepted content");
	}
	printf("\n");
	close(fileDesc);
	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 2)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
/**
* Source code opening specified file.
*/
#include "customfile.h"

int main(int argc, char *argv[]){
	int fileDesc;
	int ret;
	char buff[256];

	validateNumberOfArguement(&argc);

	fileDesc = open(argv[1],O_RDONLY);
	if(ret == -1){
		perror("openSysCall::\n");
		return -1;
	}

	//read the actual information form the file 

	while(( read(fileDesc,buff,256)) != 0){
		printf("%s",buff);
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
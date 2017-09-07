/**
* Source code opening specified file.
*/
#include "customopen.h"
int main(int argc, char *argv[]){
	int fileDesc;

	validateNumberOfArguement(&argc);

	fileDesc = open(argv[1],O_RDONLY);
	if(fileDesc == -1){
		perror("PERROR::open failed");
	}
	else{
		printf("File is successfully opened with FileDescriptor = %d\n",fileDesc);
	}
	close(fileDesc);

	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 2)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
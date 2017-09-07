/**
* Source code opening specified file.
*/
#include "customopen.h"
int main(int argc, char *argv[]){
	int fileDesc;
	int mode;

	validateNumberOfArguement(&argc);

	//check the mode
	if(strcmp(argv[2],"read")==0){
		mode = O_RDONLY;
	}
	else if (strcmp(argv[2],"write")==0){
		mode = O_WRONLY;
	}
	else if (strcmp(argv[2],"read&write")==0)
	{
		mode = O_RDWR;
	}
	else if (strcmp(argv[2],"trunc")==0)
	{
		mode = O_WRONLY | O_TRUNC;
	}
	else if (strcmp(argv[2],"create")==0)
	{
		mode = O_CREAT;
	}
	else{
		printf("Invalid argument\n");
		return -1;
	}

	fileDesc = open(argv[1],mode);
	if(fileDesc == -1){
		perror("PERROR::open failed");
	}
	else{
		printf("File is successfully opened in \"%s\" mode \n",argv[2]);
	}
	close(fileDesc);

	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 3)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
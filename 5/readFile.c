/**
* Source code opening specified file.
*/
#include "customfile.h"

int main(int argc, char *argv[]){
	int fileDesc;
	int ret;
	char *buff = NULL;

	validateNumberOfArguement(&argc);

	fileDesc = open(argv[1],O_RDONLY);
	if(ret == -1){
		printf("Unable to open the file\n");
		return -1;
	}

	//assign the memory in bytes to the
	buff = (char*)malloc(sizeof(char)*atoi(argv[2]));
	
	//read the actual information form the file 

	ret = read(fileDesc,buff,atoi(argv[2]));

	if(ret != atoi(argv[2])){
		printf("Unable to read the exact number of byte from file\n");
	}
	else{
		printf("File contents are :\n%s\n",(char*)buff);
	}

	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 3)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
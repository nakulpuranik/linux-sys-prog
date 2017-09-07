/**
* Source code opening specified file.
*/
#include "customaccess.h"
int main(int argc, char *argv[]){
	int fileDesc;
	int mode;

	validateNumberOfArguement(&argc);

	//check the mode
	if(strcmp(argv[2],"read")==0){
		mode = R_OK;
	}
	else if (strcmp(argv[2],"write")==0){
		mode = W_OK;
	}
	else if (strcmp(argv[2],"execut")==0){
		mode = X_OK;
	}
	else{
		printf("Invalid argument\n");
		return -1;
	}

	//check for the access
	if (access(argv[1],mode)<1)
	{
		printf("Process can not access input file for %sing purposes \n",argv[2]);
	}
	else
	{
		printf("Process has %sing access\n",argv[2]);
	}

	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 3)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
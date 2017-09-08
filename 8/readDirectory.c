/**
* Source code opening specified file.
*/
#include "directoryheader.h"

int main(int argc, char *argv[]){
	DIR *dir;
	struct dirent *entry;

	validateNumberOfArguement(&argc);

	if((dir = opendir(argv[1])) == NULL){
		printf("Unable to open specified direcotory.\n");
		return -1;
	}

	printf("Directory contents are as : \n");

	while((entry = readdir(dir)) != NULL){
		printf("File Name: %s \tInode number:\t%d\n",entry->d_name,entry->d_ino );
	}
	
	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 2)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
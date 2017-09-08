/**
* Source code opening specified file.
*/
#include "searchheader.h"

int main(int argc, char *argv[]){
	
	DIR *dir;
	struct dirent *entry;

	validateNumberOfArguement(&argc);

	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	// Traverse directory
	while ((entry = readdir(dir)) != NULL)
	{
		if(strcmp(argv[2],(char*)entry->d_name)==0)
		{
			printf("%s file is present in directory\n",argv[2]);	
			break;
		}
	}

	closedir(dir);
	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 3)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
/**
* Source code opening specified file.
*/
#include "customheader.h"

int main(int argc, char *argv[]){
	
	DIR *dir;
	struct dirent *entry;
	char oldpath[256] = {'\0'};
	char newpath[256] = {'\0'};

	validateNumberOfArguement(&argc);

	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	// Traverse directory
	while ((entry = readdir(dir)) != NULL)
	{
		// Form source and destination path
		sprintf(oldpath,"%s/%s",argv[1],entry->d_name);
		sprintf(newpath,"%s/%s",argv[2],entry->d_name);
		
		// Move that file		
		rename(oldpath,newpath);
		memset(&oldpath,0,sizeof(oldpath));
		memset(&newpath,0,sizeof(newpath));
	}
	
	// close that opened directory
	closedir(dir);
	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 3)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
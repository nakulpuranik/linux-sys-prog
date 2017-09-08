/**
* Source code opening specified file.
*/
#include "directoryheader.h"

int main(int argc, char *argv[]){
	DIR *dir;
	struct dirent *entry;
	struct stat filestat;
	char name[100] = {'\0'};
	char fileName[256];
	int maxFileSize = 0;

	validateNumberOfArguement(&argc);

	if((dir = opendir(argv[1])) == NULL){
		printf("Unable to open specified direcotory.\n");
		return -1;
	}

	printf("Finding largest file in direcotory : \n");

	while((entry = readdir(dir)) != NULL){
		sprintf(name,"%s/%s", argv[1],entry->d_name); //create relative path in name 
		stat(name,&filestat); // fetch files info
		if((int)filestat.st_size >= maxFileSize){
			maxFileSize = (int)filestat.st_size;
			memset(fileName,0,sizeof(entry->d_name));
			strcpy(fileName,entry->d_name);
		}	
	}
	
	printf("Largest File is %s with size %d\n", fileName,maxFileSize);
	closedir(dir);
	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 2)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
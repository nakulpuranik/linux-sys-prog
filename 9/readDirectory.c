/**
* Source code opening specified file.
*/
#include "directoryheader.h"

int main(int argc, char *argv[]){
	DIR *dir;
	struct dirent *entry;
	struct stat filestat;
	char name[100] = {'\0'};

	validateNumberOfArguement(&argc);

	if((dir = opendir(argv[1])) == NULL){
		printf("Unable to open specified direcotory.\n");
		return -1;
	}

	printf("Directory contents are as : \n");

	while((entry = readdir(dir)) != NULL){
		sprintf(name,"%s/%s", argv[1],entry->d_name); //create relative path in name 
		stat(name,&filestat); // fetch files info

		printf("%30s : ",entry->d_name);
		// Check file type			
		if(S_ISREG(filestat.st_mode))
			printf("Regular file\n");
		else if(S_ISDIR(filestat.st_mode))
			printf("Directory\n");
		else if(S_ISLNK(filestat.st_mode))
			printf("Link\n");	
	}
	
	closedir(dir);
	return 0;
}

void validateNumberOfArguement(const int *input){
	if(*input != 2)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
	}
}
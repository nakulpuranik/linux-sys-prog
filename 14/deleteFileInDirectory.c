/**
* Source code opening specified file.
*/
#include "customheader.h"

int main(int argc, char *argv[]){
	
	DIR *dir;
	struct dirent *entry;
	struct stat filestat;
	char buffer[256];

	validateNumberOfArguement(&argc);

	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	// Traverse directory
	while ((entry = readdir(dir)) != NULL)
	{
		sprintf(buffer,"%s/%s",argv[1],entry->d_name);
		stat(buffer,&filestat);

		if(filestat.st_size == 0){
			printf("Deleting empty file \t %s\n",entry->d_name);
		}
		//delete the file, not checking the access permission
		//deleting only regular file
		if(S_ISREG(filestat.st_mode)){
			if((unlink(buffer))==-1){
				perror("Problem in deleting the file");
			}
			else{
				printf("File Deleted \t %s\n",entry->d_name);	
			}		
		}
		else{
			printf("File is not regular file \t %s \n", entry->d_name);
		}
		
	}

	closedir(dir);
	return 0;
}

int validateNumberOfArguement(const int *input){
	if(*input != 2)
	{
		printf("Error : Not sufficient arguments\n Passed arguments %d",*input);
		return -1;
	}
}
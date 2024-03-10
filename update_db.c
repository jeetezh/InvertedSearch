#include "inverted_Search.h"

void update_database(Wlist *head[],Flist **f_head)
{
	char filename[FNAME_SIZE];

	printf("Enter the file name : ");
	scanf("%s",filename);

	//Validation

	int empty=isFileEmpty(filename);

	if(empty==FILE_NOTAVAILABLE)
	{
		printf("The file %s is not available\n",filename);
	}
	else if(empty==FILE_EMPTY)
	{
		printf("The file %s is empty\n",filename);
	}
	else
	{
		int ret=to_create_list_of_files(f_head,filename);
		if(ret==REPEATATION)
			printf("File %s is repeated\n",filename);
		else
			printf("suceessfully inserted file %s into linked list\n",filename);

		read_datafile(*f_head,head,filename);
	}
	
}


	



	



/*Doc
Name: Jeetesh R
Date: 10--303-2024
Description: Inverted search using c programming
Tool used : GCC
Doc*/

#include "inverted_Search.h"

int main(int argc , char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};

    //validate CLA
    if(argc <= 1)
    {
	printf("Enter the valid no. of arguments\n");
	printf("./Slist.exe file1.txt file2.txt....");
	return 0;
    }

    //create the file linked list
    // create head pointer

    Flist *f_head = NULL;


    //validate the file names
    file_validation_n_file_list(&f_head , argv);

    if(f_head == NULL)
    {
	printf("No files are available in the file linked list\n");
	printf("Hence the process got terminated\n");
	return 1;
    }

	char option='y';
	int choice;

	while(option=='y' || option=='Y')
	{
		printf("1. CREATE DATABASE\n2. DISPLAY DATABASE\n3. UPDATE DATABASE\n4. SEARCH\n5. SAVE DATABASE\nEnter your choice\n");
        scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				create_database(f_head , head);
				break;
				
			case 2:
				display_database(head);
				break;
			case 3:
				update_database(head,&f_head);
				break;
			case 4:
				{
				char word[WORD_SIZE];
				printf("Enter the word to be searched : ");
				scanf("%s",word);
				search(head[tolower(word[0])%97],word);
				break;
				}

			case 5:
				save_database(head);
				break;


		}
		getchar();
		printf("Do you want to continue Y/N\n");
		scanf("%c",&option);
	}
}


























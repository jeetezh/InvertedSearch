#include "inverted_Search.h"

void create_database(Flist *f_head, Wlist *head[])
{
	printf("------------------------------CREATING A DATABASE------------------------------\n");
    //traverse through file list
    while(f_head)
    {
	read_datafile(f_head , head,f_head->file_name);
	printf("Database is created for %s\n",f_head->file_name);
	f_head = f_head->link;
    }
	printf("------------------------------DATABASE IS CREATED------------------------------\n");
	
}

// read contents of file
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    int flag = 1;
    //open the file read mode
    FILE *fptr = fopen(filename , "r");
	if(fptr==NULL)
	{
		printf("Failed to open file %s\n",filename);
	}


    //declare an array to store words
    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
	//index 
	int index = tolower(word[0]) % 97 ;

	//other than alphabets
	if(!(index >= 0 && index <= 25))
	    index = 26;

	//check whether words are repeated or not
	if(head[index] != NULL)
	{
	    Wlist *temp = head[index];
	    //compare the words at each node with new word 
	    while(temp)
	    {
		if(!(strcmp(temp->word , word)))
		{
			//printf("%s\n",word);
		    update_word_count(&temp , filename);
		    flag = 0;
		    break;
		}
		temp=temp->link;
	    }
	}
	if(flag == 1)
	{
	    //if words are not repeated
    	    insert_at_last(&head[index] , word,filename);
	}
    }
}

int update_word_count(Wlist ** head, char * filename)
{
    //check whether the filenames are same or not
    // if filenames are same ----- > increment word_count
    //if filenames are different  ---- > increment file_count , create Ltable node


	Ltable *temp1=(*head)->Tlink;
	Ltable *temp2=NULL;

	while(temp1)
	{
		if(strcmp(temp1->file_name,filename)==0)
		{
			temp1->word_count=temp1->word_count+1;
			return SUCCESS;
		}
		temp2=temp1;
		temp1=temp1->table_link;
	}

	Ltable *new=malloc(sizeof(Ltable));
	if(new==NULL)
	{
		printf("Failed to create a node\n");
		return FAILURE;
	}

	new->word_count=1;
	strcpy(new->file_name,filename);
	new->table_link=NULL;

	temp2->table_link=new;

	(*head)->file_count=((*head)->file_count)+1;
	return SUCCESS;

}





















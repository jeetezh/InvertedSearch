#include "inverted_Search.h"

void display_database(Wlist *head[])
{
	printf("----------------------------DISPLAYING DATABASE--------------------------------\n");
	printf("[Index]\t[Word]\tFilecount File/s\tFile: File name\tWord_count\n");


	int i;

	for(i=0;i<27;i++)
	{
		if(head[i]!=NULL)
		{
			print_word_count(head[i]);
		}
	}
	printf("-------------------------------------------------------------------------------\n");
}


int print_word_count(Wlist *head)
{
	//Traverse through the list

	while(head!=NULL)
	{
		printf("[%d]\t[%-8s]\t%d File/s\t",tolower(head->word[0])%97,head->word,head->file_count);

		Ltable *Thead=head->Tlink;

		while(Thead)
		{
			printf("File: %-8s\t%d ",Thead->file_name,Thead->word_count);
			Thead=Thead->table_link;
		}
			printf("\n");
			head=head->link;
	}
			
}



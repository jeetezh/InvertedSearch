#include "inverted_Search.h"

int search(Wlist *head,char *word)
{
	if(head==NULL)
	{
		printf("Search is failed, List is empty\n");
		return 1;
	}

	while(head)
	{
		if(!strcmp(head->word,word))
		{
			printf("Word %s is present in %d file/s\n",word,head->file_count);
			Ltable *Thead=head->Tlink;

			while(Thead)
			{
				printf("In file: %s  %d times\n",Thead->file_name,Thead->word_count);
				Thead=Thead->table_link;
			}
			printf("\n");
			return 1;
		}
		head=head->link;
	}
	printf("Search word is not present\n");
}

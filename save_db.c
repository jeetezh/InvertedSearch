#include "inverted_Search.h"

void save_database(Wlist *head[])
{
	char filename[FNAME_SIZE];
	printf("Enter the file name: \n");
	scanf("%s",filename);

	FILE *fptr=fopen(filename,"w");

	int i;
    char *s="[index] : [word] : [file_count] : [filename] : [word_count]";
	fprintf(fptr,"%s\n",s);
	for(i=0;i<27;i++)
	{
		if(head[i]!=NULL)
		{
			write_database(head[i],fptr);
		}
	}
	printf("Database is saved\n");

}

void write_database(Wlist *head, FILE *databasefile)
{

	while(head!=NULL)
	{
		int index=tolower(head->word[0])%97;
		fprintf(databasefile,"[%d] : [%s] : [%d] file/s: ",index,head->word,head->file_count);

		Ltable *Tlink=head->Tlink;
		while(Tlink)
		{
			fprintf(databasefile,"[%s] : %d\n",Tlink->file_name,Tlink->word_count);
			Tlink=Tlink->table_link;
		}
		head=head->link;
	}
}



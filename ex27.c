#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	/*int c;
FILE *file;
file = fopen("t1.txt", "r");
if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);
}}*/
	int i=1,j=0,k=0,m=0;
	unsigned char A=0,B,rc=0;
	FILE *fpt;
	char AB[100],op1[100],op2[100];
	fpt=fopen("compressed.rle","rb");
	fread(&A,1,1,fpt);
	printf("%c",A);
	fread(&B,1,1,fpt);
	printf("%c",B);
	fread(&B,1,1,fpt);
	printf("%c",B);

	//for(i=0;i<(A);i++)
	//	printf("%c",B);
	fclose(fpt);
	/*fpt=fopen("t1.txt","rb");
	while((j=getc(fpt))!=EOF)
	{
		i++;
	}
	fclose(fpt);
	fpt=fopen("t1.txt","rb");
	printf("%d",i);
		rc++;
		while(j<15)
		{
			fread(&B,1,1,fpt);
			printf("%c",B);
			j++;
		}
		//fpt--;
		fseek(fpt,0,SEEK_SET);
		//op1[1]=fgetc(fpt);
		//printf("%c\n",op1[1] );
	fclose(fpt);
	fpt=fopen("t3.txt","wb");
	fprintf(fpt,"%d",rc);
	fwrite(&B,1,1,fpt);
	fclose(fpt);*/
}

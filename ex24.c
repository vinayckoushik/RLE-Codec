#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int i=0,j=0,k=0,m=0;
	unsigned char A,B,rc=0;
	unsigned char *img;
	img=(unsigned char *)malloc(1000);
	FILE *fpt;
	char /*AB[100]="11A4B0xCDEFGH0x"*/op1[100],op2[100];
	fpt=fopen(argv[1],"r");
	fread(img,1,1000,fpt);
	fclose(fpt);
	printf("%d\n",img[0]-'0');
	printf("%c",img[1]);
}
	
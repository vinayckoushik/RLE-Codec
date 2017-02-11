#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int i=0,j=1,k=1,m=0,n;
	unsigned char A,B,rc=0,C,mx='0',x='x';
	FILE *fpt;
	FILE *fpo;
	fpt=fopen("compressed.rle","rb");
	fpo=fopen("compressed.urle","wb");

	if((j=fgetc(fpt))==EOF)
	{
		exit(0);
	}
	while(fgetc(fpt)!=EOF)
		k++;
	printf("%d\n",k);
	unsigned char *ip;
	unsigned char *op;
	ip=(unsigned char *)malloc(k);
	op=(unsigned char *)malloc(k);
	fseek(fpt,i,SEEK_SET);
	fread(ip,1,k,fpt);
	j=0;
	for(;i<k;i++)
	{
		if(ip[i]==0 && ip[i]==0)
		{
			i=i+2;
			for(;;i++)
			{
				if(ip[i]==0 && ip[i+1]==0)
				{
					i=i+2;
					j=j-1;
					break;
				}
				else
				{
				op[j]=ip[i];
				j++;
				}
			}
		}
		else
		{
			rc=ip[i];
			m=ip[i+1];
			for(k=0;k<rc;k++)
			{
				op[j]=m;
				j++;
			}
			j--;
			i+=2;
		}
	}
	for(i=0;i<k;i++)
	printf("%d  %d\n",ip[i],op[i]);
	fwrite(op,1,j,fpo);
	fclose(fpo);
	fclose(fpt);
}




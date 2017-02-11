#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	unsigned char A,B,rc=1;
	char s[]="AAA BBB CC DD EE FFFF GG 6868 68";
	char op[10];
	int i,j=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==' ')
			continue;
		A=s[i];
		B=s[i+1];
		if(A==B)
			rc++;
		else
		{
			//printf("%d%c ",rc,A);
			op[j]='\0';
			op[j]='0'+rc;
			op[j+1]=A;
			j=j+2;
			rc=1;
		}
	}
	for(;j<strlen(op);j++)
		op[j]='\0';
	puts(op);
	i=0;
	j=0;
	while(op[i]!='\0')
	{
		rc=op[i]-'0';
		A=op[i+1];
		for(j=0;j<rc;j++)
			printf("%c",A);
		i=i+2;
	}

}
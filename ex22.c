#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int i=0,j=0,k=0,m=0;
	unsigned char A=0,B=1,rc=0;
	FILE *fpt;
	char AB[100],op1[100],op2[100];
	fpt=fopen(argv[1],"r");
	fgets(AB,100,fpt);
	A=AB[0];

	for(i=1;B != '\0' ;i++)
	{
		B=AB[i];
		if(A==B)
		{
			if(rc<256)
				rc++;
			else
			{
				op1[j]='0'+(rc+1);
				op1[j+1]=A;
				j=j+2;
				A=B;
				rc=0;
			}
		}

		else if(A != B && B != AB[i+1] && m!=1 && AB[i+1]!=EOF && rc==0)
		{
			op1[j]='0';
			op1[j+1]='x';
			j+=2;
			m=1;
		}
		else if(m==1)
		{
			for(k=i;;k++)
			{
				B=AB[k];
				if(A==B)
				{
					i=k-1;
					break;
				}
				op1[j]=A;
				A=B;
				j++;

			}

			op1[j]='0';
			op1[j+1]='x';
			m=0;
			j=j+2;
				
		}
		else 
		{
			if((rc+1) > 9 && (rc+1)<100)
			{
				op1[j]='0'+((rc+1)/10);
				op1[j+1]='0'+((rc+1)%10);
				op1[j+2]=A;
				j+=3;
				A=B;
				rc=0;
			}
			else if((rc+1) > 99)
			{
				op1[j]='0'+((rc+1)/100);
				op1[j+1]='0'+(((rc+1)/10)%10);
				op1[j+2]='0'+((rc+1)%10);
				op1[j+3]=A;
				j+=4;
				A=B;
				rc=0;
			}
			else if((rc+1)<10)
			{
				op1[j]='0' +(rc+1);
				op1[j+1]=A;
				j=j+2;
				A=B;
				rc=0;
			}
			op1[j]='.';
			j++;
		}
	}
	op1[j]='\0';
	puts(op1);
	fclose(fpt);
	fpt=fopen("lab2.rle","w");
	fputs(op1,fpt);
	fclose(fpt);
	
}
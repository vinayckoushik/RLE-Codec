#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int i=0,j=1,k=1,k1=0,m=0,n;
	unsigned char A,B,rc=0,C,mx='0',x='x';
	FILE *fpt;
	FILE *fpo;
	fpt=fopen(argv[1],"rb");
	fpo=fopen("compressed.rle","wb");

	if((j=fgetc(fpt))==EOF)
	{
		exit(0);
	}
	while(fgetc(fpt)!=EOF)
		k++;
	unsigned char *ip;
	unsigned char *op;
	unsigned char *op1;
	unsigned char *op2;
	op1=(unsigned char *)malloc(k);
	ip=(unsigned char *)malloc(k);
	op=(unsigned char *)malloc(k);
	op2=(unsigned char *)malloc(k);
	fseek(fpt,i,SEEK_SET);
	fread(ip,1,k,fpt);
	A=ip[i];
	i++;
	j=0;
	for(;i <= k ;i++)
	{
		B=ip[i];
		if(A==B)
		{
			if(rc==254)
			{
				op[j]=(rc+1);
				op[j+1]=A;
				j=j+2;
				A=B;
				rc=0;
			}
			else
			{
				rc++;
			}
		}

		else if(A != B && B != ip[i+1] && m!=1 && rc==0)
		{
			op[j]=0;
			op[j+1]=0;
			j+=2;
			m=1;
			i--;
		}
		else if(m==1)
		{
			for(n=i;;n++)
			{
				B=ip[n];
				if(A==B)
				{
					i=n-1;
					break;
				}
				op[j]=A;
				A=B;
				j++;

			}

			op[j]=0;
			op[j+1]=0;
			m=0;
			j=j+2;
				
		}
		else 
		{
			op[j]=(rc+1);
			op[j+1]=A;
			A=B;
			rc=0;
			j+=2;		
		}
	}
	fwrite(op,1,j,fpo);
	fclose(fpt);
	fclose(fpo);

	i=0;
	fpt=fopen("compressed.rle","rb");
	fpo=fopen("compressed.urle","wb");
	if((j=fgetc(fpt))==EOF)
	{
		exit(0);
	}
	while(fgetc(fpt)!=EOF)
		k1++;
	fseek(fpt,i,SEEK_SET);
	fread(op2,1,k,fpt);
	j=0;
	for(i=0;i<k;)
	{
		if(op2[j]==0 && op2[j+1]==0)
		{
			j=j+2;
			for(;;j++)
			{
				if(op2[j]==0 && op2[j+1]==0)
				{
					j=j+2;
					break;
				}
				else
				{
					op1[i]=op2[j];
					i++;
				}
			}
		}
		else
		{
			rc=op2[j];
			m=op2[j+1];
			for(n=0;n<rc;n++)
			{
				op1[i]=m;
				i++;
			}
			j+=2;
		}
	}
	fwrite(op1,1,k,fpo);
	fclose(fpo);
	fclose(fpt);
}




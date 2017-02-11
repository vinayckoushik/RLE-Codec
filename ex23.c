#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int i=0,j=0,A=0,m=0;
	unsigned char k,B,rc=0;
	FILE *fpt;
	char /*AB[100]="11A4B0xCDEFGH0x"*/op1[100],op2[100];
	fpt=fopen("t1.txt","r");
	//fgets(op2,100,fpt);
	//fclose(fpt);
	//puts(op2);
	//printf("2");
	//printf("1");
	//puts(op2);

	for (i=0; i<=4; i++){

        fscanf(fpt,"%d%c",&A,&k);
		printf("%d%c",A,k);
	}

	/*while(1)
	{
		fscanf(fpt,"%c%d",&A,&k);
		printf("%d%c",k,A);
		printf("%c", );
		//fscanf(fpt,"%c",&B);
		//printf("%c", *fpt);
		//fpt--;
		
		if(A =='\0')
		{
			break;
		}
		else if(k==0 && A=='x')
		{
			while(B!='0')
			{
				fscanf(fpt,"%c",&B);
				//printf("%c",B);
				if(B=='0')
				{
					break;
				}
				else
				{
					op1[j]=B;
					j++;
				}
			}
		}
		else
		{
			for(m=0;m<k;m++)
			{
				op1[j]=A;
				j++;
			}
			//puts(op1);
		}
		i++;
	}*/
	fclose(fpt);
	puts(op1);
}
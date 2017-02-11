#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int i=0,j=0,k=0,m=0;
	unsigned char A=0,B=1,rc=0;
	FILE *fpt;
	int				ROWS,COLS,MAX;
	unsigned char	*img;
	unsigned char	*dd;
	char header[80];
	fpt=fopen("golfcore.ppm","rb");
	fscanf(fpt,"%s %d %d %d",header,&ROWS,&COLS,&MAX);
	header[79]=fgetc(fpt);
	img=(unsigned char *)malloc(ROWS*COLS);
	dd=(unsigned char *)malloc(ROWS*COLS);
	fread(img,1,ROWS*COLS,fpt);
	fclose(fpt);
	A=img[0];
	for(i=1;i <= ROWS*COLS ;i++)
	{
		B=img[i];
		if(A==B)
		{
			if(rc<256)
				rc++;
			else
			{
				dd[j]=(rc+1);
				dd[j+1]=A;
				j=j+2;
				A=B;
				rc=0;
			}
		}

		else if(A != B && B != img[i+1] && m!=1 && (i+1) !=(ROWS*COLS) && rc==0)
		{
			dd[j]=0;
			dd[j+1]='x';
			j+=2;
			m=1;
		}
		else if(m==1)
		{
			for(k=i;;k++)
			{
				B=img[k];
				if(A==B)
				{
					i=k-1;
					break;
				}
				dd[j]=A;
				A=B;
				j++;

			}

			dd[j]=0;
			dd[j+1]='x';
			m=0;
			j=j+2;
				
		}
		else 
		{
			dd[j]=(rc+1);
			dd[j+1]=A;
			A=B;
			rc=0;
			j+=2;		
		}
	}
	//for(i=0;i<20;i++)
	//	printf("%d\n",dd[i]);
	fpt=fopen("lab22.ppm","wb");
	fwrite(dd,1,k,fpt);
	fclose(fpt);
	
}

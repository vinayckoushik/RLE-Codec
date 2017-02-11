#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	int i=0,j=0,k=0,m=0;
	unsigned char A=0,B=1,rc=0;
	FILE *fpt;
	int				ROWS,COLS,MAX;
	unsigned char	*img;
	unsigned char	*dd;
	unsigned char	*op;
	unsigned char	*op2;
	char header[80];
	fpt=fopen("golfcore.ppm","rb");
	fscanf(fpt,"%s %d %d %d",header,&COLS,&ROWS,&MAX );
	header[79]=fgetc(fpt);
	img=(unsigned char *)malloc(ROWS*COLS);
	dd=(unsigned char *)malloc(ROWS*COLS);
	op=(unsigned char *)malloc(ROWS*COLS);
	op2=(unsigned char *)malloc(ROWS*COLS);
	fread(img,1,ROWS*COLS,fpt);
	fclose(fpt);
	A=img[0];
	//printf("%d",img[0]);
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
			dd[j+1]=0;
			j+=2;
			m=1;
			i--;
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
			dd[j+1]=0;
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
	//for(i=0;i<100;i++)
	//	printf("%d  %d\n",img[i],dd[i]);
	fpt=fopen("lab21.ppm","w");
	fprintf(fpt,"%s %d %d %d ",header,COLS,ROWS,MAX);
	fwrite(dd,1,j,fpt);
	fclose(fpt);

fpt=fopen("lab21.ppm","rb");
fscanf(fpt,"%s %d %d %d",header,&COLS,&ROWS,&MAX );
header[79]=fgetc(fpt);
fread(op,1,ROWS*COLS,fpt);
fclose(fpt);
j=0;
for(i=0;i<ROWS*COLS;i++)
{
	if(op[j]==0 && op[j+1]==0)
	{
		j=j+2;
		for(;;j++)
		{
			if(op[j]==0 && op[j+1]==0)
			{
				j=j+2;
				i=i-1;
				break;
			}
			else
			{
				op2[i]=op[j];
				i++;
			}
		}
	}
	else
	{
		rc=op[j];
		m=op[j+1];
		for(k=0;k<rc;k++)
		{
			op2[i]=m;
			i++;
		}
		i--;
		j+=2;
	}
}
for(i=0;i<100;i++)
	printf("%d  %d\n",img[i],op2[i]);
fpt=fopen("lab23.ppm","wb");
fprintf(fpt,"%s %d %d %d \n",header,COLS,ROWS,MAX);
fwrite(op2,1,ROWS*COLS,fpt);
fclose(fpt);
}



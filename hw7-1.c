#include <stdio.h>
#include <stdlib.h>
#define MAX 416

int main(){
int a[MAX][MAX],e[MAX][MAX],l[MAX][MAX],ee[MAX],le[MAX];
int i,j,k,n,max,min;
FILE *fptr1, *fptr2;

fptr1=fopen("Sample_input.txt","r");
fptr2=fopen("Sample_output.txt","w");

for(i=0;i<MAX;i++)
{
	for(j=0;j<MAX;j++)
	{
		a[i][j]=0;
		e[i][j]=0;
		l[i][j]=0;
	}
}
for(i=0;i<MAX;i++)
{
	ee[i]=0;
	le[i]=0;
}
fscanf(fptr1,"%d",&n);    // get the total number of nodes

for(i=0;i<n;i++)				//把所有activity edge放入a[][]
{
	for(j=0;j<n;j++)
	{
		fscanf(fptr1,"%d",&a[i][j]);
	}
}

for(i=0;i<n;i++)				// is it feasible
{
	for(j=0;j<n;j++)
	{
		if(a[i][j]>0 && a[j][i]>0)
		{
			printf("Not feasible.\n");
			return 0;
		}
	}
}

for(j=0;j<n;j++)					//算ee[]
{
	max=0;
	for(i=0;i<n;i++)
	{
		if(a[i][j]>0)
		{
			if(ee[i]+a[i][j]>max)
			{
				max=ee[i]+a[i][j];
			}
		}
	}
	ee[j]=max;
}

le[n-1]=ee[n-1];                 //給定le[n-1]

for(i=n-2;i>=0;i--)				//算le[]
{
	min=2147483647;
	for(j=0;j<n;j++)
	{
		if(a[i][j]>0)
		{
			if(le[j]-a[i][j]<min)
			{
				min=le[j]-a[i][j];
			}
		}
	}
	le[i]=min;
}
for(i=0;i<n;i++)		         //取得e[][],l[][]
{
	for(j=0;j<n;j++)
	{
		if(a[i][j]>0)
		{
			e[i][j]=ee[i];
			l[i][j]=le[j]-a[i][j];
		}
	}
}

fprintf(fptr2,"activity   e       l      l-e\n");

for(i=0;i<n;i++)			//列印結果
{
	for(j=0;j<n;j++)
	{
		if(a[i][j]>0)
		{
			fprintf(fptr2,"(%d,%d)	   %d	   %d	   %d",i,j,e[i][j],l[i][j],l[i][j]-e[i][j]);
			fprintf(fptr2,"\n");
		}
	}
}

fclose(fptr1);
fclose(fptr2);
return 0;
}

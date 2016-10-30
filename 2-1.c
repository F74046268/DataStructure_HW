#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200
int temp[20][20];

void C(int n, int a, int b, int i, int j, int e[]);
int main(){
	FILE *fptr;
	char filename[MAX_SIZE];
	int e[MAX_SIZE],a,b,n,i,j;
	scanf("%s",filename);     //let user choose which file to open
	fptr = fopen(filename,"r");
	fscanf(fptr,"%d",&n);

	while(1)
	{
		printf("a:");scanf("%d",&a); 
		printf("b:");scanf("%d",&b);
		if(a<1||b<1)
		{
			printf("a and b must bigger than 0,thanks\n");
			continue;
		}
		else if(a>n||b>n)
		{
			printf("a and b must smaller than n,thanks\n");
			continue;
		}
		break;
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			fscanf(fptr,"%d",&temp[i][j]); //store data in 2-dimensional array
		}
	}
	
	C(n,a,b,i,j,e);

	fclose(fptr);
	return 0;
}

void C(int n, int a, int b, int i, int j, int e[])
{
	int k,count=0;
                     //count lower band
	for(k=a;k>=2;k--)
	{
		i=k;
		for(;i<=n;i++)
		{
			e[count]=temp[i][i-k+1];
			printf("e[%d]=%d d(%d,%d)\n",count,e[count],i-1,i-k+1-1);
			count++;
		}
	}
	
					     //count main diagonal
	for(k=1;k<=n;k++)
	{
		e[count]=temp[k][k];
		printf("e[%d]=%d d(%d,%d)\n",count,e[count],k-1,k-1);
		count++;
	}

	                     //count upper band
	for(k=2;k<=b;k++)
	{
		j=k;
		for(;j<=n;j++)
		{
			e[count]=temp[j-k+1][j];
			printf("e[%d]=%d d(%d,%d)\n",count,e[count],j-k+1-1,j-1);
			count++;
		}
		
	}

	return;
}

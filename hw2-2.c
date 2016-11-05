#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

FILE *fptr;
int k, n, m, ibug, jbug, tempibug, tempjbug, i, j, count=0, imove[8]={-1,0,1,1,1,0,-1,-1}, jmove[8]={1,1,1,0,-1,-1,-1,0};
unsigned int map[40][20],total=0;
srand(time(NULL));
fptr=fopen("Sample_output.txt","w");

for(i=0;i<40;++i)										//初始化陣列
{
	for(j=0;j<20;++j)
	{
		map[i][j]=0;
	}
}

while(1){ 													//input condition
	printf("N:");scanf("%d",&n);
	printf("M:");scanf("%d",&m);
	printf("Initial bug position X:");scanf("%d",&jbug);
	printf("Initial bug position Y:");scanf("%d",&ibug);
	if(n>40||m>20)
	{
		printf("2<n<=40 , 2<m<=20\n");continue;
	}
	else if(n<2||m<2)
	{
		printf("2<n<=40 , 2<m<=20\n");continue;
	}
	else if(ibug>=n||jbug>=m)
	{
		printf("out of room\n");continue;
	}
	else if(ibug<0||jbug<0)
	{
		printf("out of room\n");continue;
	}
	break;
}

while(1){
	while(1){									//選擇要走哪 超出範圍就重選
		tempibug=ibug;
		tempjbug=jbug;
		k=rand()%8;
		ibug=ibug+imove[k];
		jbug=jbug+jmove[k];
		if(ibug<0||jbug<0||ibug>=n||jbug>=m)
		{
			ibug=tempibug;
			jbug=tempjbug;
			continue;
		}

		break;
	}
	total++;
	map[ibug][jbug]++;

	
	if(map[ibug][jbug]==1){++count;} 			//計算走過的磁磚數 都走過了就跳離回圈
	if(count==(n*m))break;

}

fprintf(fptr,"總共走了%u次\n",total);
for(j=m-1;j>=0;j--)
{
	for(i=0;i<n;i++)
	{
		fprintf(fptr,"%3u ",map[i][j]);
	}
	fprintf(fptr,"\n");
}



fclose(fptr);

return 0;
}

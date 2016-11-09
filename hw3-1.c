#include <stdio.h>

int main(){

typedef struct{
	int x;
	int y;
} stack;


FILE *ptr1, *ptr2;
ptr1=fopen("in.txt","r");
ptr2=fopen("out.txt","w");

char map[200][200],test[200][200];
stack p[8],t[8],back[1000],record[2000],start,end,now,choice[8];
int top_t=0,top_b=0,top_r=0,top_c=0,a=0,i=0,j=0,k=0,m=0,n=0,count_0=0, count_d=0,count=0,count_s=0;

for(i=0;i<200;++i)				//initialize the map
{
	for(j=0;j<200;++j)
	{
		map[i][j]='0';
		test[i][j]='0';
	}
}

								//initialize the stacks

p[0].x=-1;p[0].y=-1;
p[1].x= 0;p[1].y=-1;
p[2].x= 1;p[2].y=-1;
p[3].x=-1;p[3].y= 0;
p[4].x= 1;p[4].y= 0;
p[5].x=-1;p[5].y= 1;
p[6].x= 0;p[6].y= 1;
p[7].x= 1;p[7].y= 1;

for(i=0;i<8;i++)
{
	t[i].x=300;t[i].y=300;
}
for(i=0;i<1000;i++)
{
	back[i].x=300;back[j].y=300;
}
for(i=0;i<2000;i++)
{
	record[i].x=300;record[i].y=300;
}

i=0;j=0;
while(1){						//get the in.txt into the map


fscanf(ptr1,"%c",&map[i][j++]);
if(map[i][j-1]=='\r\n')
{
	n=j-1;
	map[i][j-1]='4';i++;j=0;count++;m=count;
	fscanf(ptr1,"%c",&map[i][j]);
	if(feof(ptr1))
	{
		break;
	}
	else
	{
		j++;
	}
}
}


for(i=0;i<m;i++)				//copy the map to the test,and find the s and d
{
	for(j=0;j<n;j++)
	{
		test[i][j]=map[i][j];
		if(map[i][j]=='s'){start.x=i;start.y=j;}
		if(map[i][j]=='d'){end.x=i;end.y=j;}
	}
}

for(k=0;k<8;k++)				//set the position of 0 which beside the s to the t[],and change the value to 2
{
	if((start.x+p[k].x) > m-1 || (start.y+p[k].y) > n-1){continue;}
	else if((start.x+p[k].x) < 0 || (start.y+p[k].y) < 0){continue;}

	if(map[start.x+p[k].x][start.y+p[k].y]=='0')
	{
		t[top_t].x=start.x+p[k].x;
		t[top_t].y=start.y+p[k].y;
		test[start.x+p[k].x][start.y+p[k].y]='2';
		top_t++;
	}
}

if(t[0].x==300 && t[0].y==300)							//開始處全被封死
{
	fprintf(ptr2,"No route");
	fclose(ptr1);
	fclose(ptr2);
	return 0;
}

now.x=t[top_t-1].x;now.y=t[top_t-1].y; 						//take the top of t[] be the now position
back[top_b].x=now.x;back[top_b].y=now.y;top_b++;		//set the now position to the back point



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

while(1){												//start search


count_d=0;
count_0=0;
top_c=0;
for(k=0;k<8;k++)
{
	choice[k].x=300;
	choice[k].y=300;
}

record[top_r].x=now.x;								//record the now position
record[top_r].y=now.y;
top_r++;






for(k=0;k<8;k++)										//search the 8 choices surround now
{
	if((now.x+p[k].x) > m-1 || (now.y+p[k].y) > n-1){continue;}
	else if((now.x+p[k].x) < 0 || (now.y+p[k].y) < 0){continue;}
	if(test[now.x+p[k].x][now.y+p[k].y]=='0')
	{
		
		choice[top_c].x=now.x+p[k].x;
		choice[top_c].y=now.y+p[k].y;
		count_0++;
		top_c++;
	}
	if(test[now.x+p[k].x][now.y+p[k].y]=='d')
	{
		count_d++;
	}
}

if(count_0 == 0 && count_d == 0)					// if there is no road can choice
{


	if(back[top_b-1].x == t[top_t-1].x && back[top_b-1].y == t[top_t-1].y)   //this route have no more choice
	{
		
		if((top_t-1)==0)													//所有路線全死光
		{
			fprintf(ptr2,"No route\r\n");
			fclose(ptr1);
			fclose(ptr2);
			return 0;
		}
		t[top_t-1].x=300;													//這條路線死掉 但是還有其他路線的話 把record歸0 t的top pop掉 把新的t-top設為back point
		t[top_t-1].y=300;
		top_t--;
		back[top_b-1].x=t[top_t-1].x;
		back[top_b-1].y=t[top_t-1].y;
		now.x=back[top_b-1].x;
		now.y=back[top_b-1].y;
		
		a=top_r;
		for(k=0;k<a;k++)
		{
			record[k].x=300;record[k].y=300;
		}
		top_r=0;

		continue;
	}
	while(1)																//back to back point
	{
		if((record[top_r-1].x != back[top_b-1].x) || (record[top_r-1].y != back[top_b-1].y))
		{
			test[record[top_r-1].x][record[top_r-1].y]='3';
			record[top_r-1].x=300;
			record[top_r-1].y=300;
			top_r--;
		}
		else
			break;
	}
	
	now.x=back[top_b-1].x;
	now.y=back[top_b-1].y;
	back[top_b-1].x=300;
	back[top_b-1].y=300;
	top_b--;
	record[top_r-1].x=300;
	record[top_r-1].y=300;
	top_r--;

	continue;
}
else if(count_d>0)														// there is an exit,print out the result
{


	a=top_r;
	for(k=0;k<a;k++)
	{
		map[record[k].x][record[k].y]='*';
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(ptr2,"%c",map[i][j]);
		}
		fprintf(ptr2,"\r\n");
	}
	fprintf(ptr2,"\n The total path : %d \r\n",a+1);
	fclose(ptr1);
	fclose(ptr2);
	return 0;
}
else if(count_0 == 1)													// only one way road
{
	test[now.x][now.y]='2';
	now.x=choice[top_c-1].x;
	now.y=choice[top_c-1].y;
}
else if(count_0 > 1)													// more than 1 road can choice,set now to the back point
{
	test[now.x][now.y]='2';
	back[top_b].x=now.x;
	back[top_b].y=now.y;
	now.x=choice[top_c-1].x;
	now.y=choice[top_c-1].y;
	top_b++;
}
}		// end of search while


fclose(ptr1);
fclose(ptr2);
return 0;
}

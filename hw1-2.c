#include <stdio.h>
#include <stdlib.h>
#define MAX 200

char data[MAX];
char used[MAX];
int size;
int total;
void recursive(int pos);
void print();

int main(){
	
	int i=0;
	scanf("%s",data);
	
	while(1){
		if(data[i]=='\0')
		{
			size=(i-1)/2;
			break;
		}
		++i;
	}

	for(i=0;i<size;++i)
		used[i]=0;
	recursive(0);
	printf("Powerset裡總共有%d個集合\n",total);


	return 0;
}

void recursive(int pos){
	int i;
	if(pos==size)
	{
		print();
		total++;
	}
	else
	{
		used[pos]=0;
		recursive(pos+1);
		used[pos]=1;
		recursive(pos+1);
	}


}

void print(){
	int i;
	printf("{");
	for(i=0;i<size;i++)
		if(used[i]){printf(" %c",data[2*i+1]);}
	
	printf(" }\n");
}

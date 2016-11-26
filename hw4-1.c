#include <stdio.h>
#include <stdlib.h>
typedef struct matrixnode *matrixptr;
typedef struct entrynode{
	int row;
	int col;
	int value;
}entrynode;
typedef struct matrixnode{
	matrixptr down;
	matrixptr right;
	entrynode entry;
}matrixnode;

int main(){
int i=0,j=0,k,num=0;
int m,n1=1,n2=2,p;
matrixptr first,temp,second,r_node,d_node;
while(n1!=n2){
printf("Please input the m,n:\n");
scanf("%d",&m);
scanf("%d",&n1);
for(i=0;i<m;i++)
{
	for(j=0;j<n1;j++)
	{		
		temp=malloc(sizeof(*temp));
		temp->entry.row=i;
		temp->entry.col=j;
		scanf("%d",&temp->entry.value);
		if(i==0 && j==0){first=temp;r_node=temp;d_node=temp;first->right=first;first->down=first;continue;}  //第一個為空 把temp塞進去 自己串自己
		if(i>0)                				//上下串
		{
			temp->down=d_node->down;
			d_node->down=temp;
			d_node=d_node->right;
		}
		if(j>0) 						//頭一個element為空時 temp當作頭一個 頭一個不為空 就向右串起來
		{
			temp->right=r_node->right;
			r_node->right=temp;
			r_node=temp;
		}
		else
		{
			r_node=temp;
		}
		if(i==0)r_node->down=r_node;   //第1列時 自己往下串自己
		if(j==0)r_node->right=r_node;  //頭一個element時 自己往右串自己
	}
	
	d_node=d_node->down;
}
//結束後 r_node指向最後一個element d_node指向最後一列的頭一個element

printf("Please input the n,p and matrix:\n");
scanf("%d",&n2);
scanf("%d",&p);
for(i=0;i<n2;i++)
{
	for(j=0;j<p;j++)
	{		
		temp=malloc(sizeof(*temp));
		temp->entry.row=i;
		temp->entry.col=j;
		scanf("%d",&temp->entry.value);
		if(i==0 && j==0){second=temp;r_node=temp;d_node=temp;second->right=second;second->down=second;continue;}  //第一個為空 把temp塞進去 自己串自己
		if(i>0)                				//上下串
		{
			temp->down=d_node->down;
			d_node->down=temp;
			d_node=d_node->right;
		}
		if(j>0) 						//頭一個element為空時 temp當作頭一個 頭一個不為空 就向右串起來
		{
			temp->right=r_node->right;
			r_node->right=temp;
			r_node=temp;
		}
		else
		{
			r_node=temp;
		}
		if(i==0)r_node->down=r_node;   //第1列時 自己往下串自己
		if(j==0)r_node->right=r_node;  //頭一個element時 自己往右串自己
	}
	
	d_node=d_node->down;
}

//結束後 r_node指向最後一個element d_node指向最後一列的頭一個element
}

printf("\nOutput:\n");
for(i=0;i<m;i++)						//乘起來
{
	for(j=0;j<p;j++)
	{
		for(k=0;k<n1;k++)
		{
			num=num+(first->entry.value)*(second->entry.value);
			first=first->right;
			second=second->down;
		}
		printf("%-2d ",num);
		second=second->right;
		num=0;
	}
	printf("\n");
	first=first->down;
}
return 0;
}

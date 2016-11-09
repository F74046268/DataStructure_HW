#include <stdio.h>

int main(){

char input1[10],input2[10],input3[10],input4[10];
for(int i=0;i<10;i++)
{
	input1[i]='\0';
	input2[i]='\0';
	input3[i]='\0';
	input4[i]='\0';
}
int choice,number,front=0,rear=0,queue[4];
while(1){
	printf("Insert(1)delete(2):");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Insert number:");
		scanf("%d",&number);
		if(rear == front-1 || (front == 0 && rear == 3))
		{printf("Queue if full\n");printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);continue;}
		++rear;
		switch(rear)
		{
			case 4:
				rear=0;
				queue[rear]=number;
				sprintf(input4,"%d",queue[0]);
				printf("Front=%d,Rear=%d \n",front,rear);
				printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);
				break;
			case 1:
				queue[rear]=number;
				sprintf(input1,"%d",queue[1]);
				printf("Front=%d,Rear=%d \n",front,rear);
				printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);
				break;
			case 2:
				queue[rear]=number;
				sprintf(input2,"%d",queue[2]);
				printf("Front=%d,Rear=%d \n",front,rear);
				printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);
				break;
			case 3:
				queue[rear]=number;	
				sprintf(input3,"%d",queue[3]);
				printf("Front=%d,Rear=%d \n",front,rear);
				printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);
		}
	}
	else if(choice==2)
	{
		if(front == rear)
		{
			for(int i=0;i<10;i++)
			{
				input1[i]='\0';
				input2[i]='\0';
				input3[i]='\0';
				input4[i]='\0';
			}

			printf("Queue is empty\n");continue;
		}
		++front;
		switch(front)
		{
			case 4:
				front=0;
				printf("delete:%d\n",queue[0]);
				for(int i=0;i<10;i++)
				{
					input4[i]='\0';
				}
				printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);
				break;
			case 1:
				printf("delete:%d\n",queue[1]);
				for(int i=0;i<10;i++)
				{
					input1[i]='\0';
				}
				printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);
				break;
			case 2:
				printf("delete:%d\n",queue[2]);
				for(int i=0;i<10;i++)
				{
					input2[i]='\0';
				}
				printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);
				break;
			case 3:
				printf("delete:%d\n",queue[3]);
				for(int i=0;i<10;i++)
				{
					input3[i]='\0';
				}
				printf("Queue:[%s][%s][%s][%s]\n",input4,input1,input2,input3);

		}
	}
	else
	{
		printf("Only 1 and 2\n");
		continue;
	}


}

return 0;
}


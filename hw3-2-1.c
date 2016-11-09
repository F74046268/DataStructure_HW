#include <stdio.h>

int main(){

char input1[10],input2[10],input3[10];
for(int i=0;i<10;i++)
{
	input1[i]='\0';
	input2[i]='\0';
	input3[i]='\0';
}
input1[0]='\0';
int choice,number,front=0,rear=0,queue[4];
while(1){
	printf("Insert(1)delete(2):");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Insert number:");
		scanf("%d",&number);
		if(rear==3 && front==0){printf("Queue if full\n");printf("Queue:[][%s][%s][%s]\n",input1,input2,input3);continue;}
		else if(rear==3 && front==1){--front;--rear;sprintf(input1,"%s",input2);sprintf(input2,"%s",input3);queue[1]=queue[2];queue[2]=queue[3];}
		else if(rear==3 && front==2){front=front-2;rear=rear-2;sprintf(input1,"%s",input3);sprintf(input3,"%s",input2);queue[1]=queue[3];}
		++rear;
		switch(rear)
		{
			case 1:
				queue[rear]=number;
				sprintf(input1,"%d",queue[1]);
				printf("Front=%d,Rear=%d \n",front,rear);
				printf("Queue:[][%s][][]\n",input1);
				break;
			case 2:
				queue[rear]=number;
				sprintf(input2,"%d",queue[2]);
				printf("Front=%d,Rear=%d \n",front,rear);
				printf("Queue:[][%s][%s][]\n",input1,input2);
				break;
			case 3:
				queue[rear]=number;	
				sprintf(input3,"%d",queue[3]);
				printf("Front=%d,Rear=%d \n",front,rear);
				printf("Queue:[][%s][%s][%s]\n",input1,input2,input3);
		}
	}
	else if(choice==2)
	{
		if(front == rear){printf("Queue is empty\n");continue;}
		++front;
		switch(front)
		{
			case 1:
				printf("delete:%d\n",queue[1]);
				printf("Queue:[][][%s][%s]\n",input2,input3);
				for(int i=0;i<10;i++)
				{
					input1[i]='\0';
				}
				break;
			case 2:
				printf("delete:%d\n",queue[2]);
				printf("Queue:[][][][%s]\n",input3);
				for(int i=0;i<10;i++)
				{
					input2[i]='\0';
				}
				break;
			case 3:
				printf("delete:%d\n",queue[3]);
				printf("Queue:[][][][]\n");
				for(int i=0;i<10;i++)
				{
					input1[i]='\0';
					input2[i]='\0';
					input3[i]='\0';
				}
				front=0;
				rear=0;

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


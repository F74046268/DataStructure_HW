#include <stdio.h>
#include <stdlib.h>

int recursive(int a);

int main(){

while(1)
{
int a,b,c=1;

printf("Please enter a number bigger than 0.enter '-1' to end program.\n");
scanf("%d",&a);
b=a;

if(a==-1){return 0;}  


a=recursive(a);               //recursive
printf("Recursive:%d\n",a);

for(;b>0;--b){				  //iterative
	c=c*b;
}
printf("Iterative:%d\n",c);

}
}

int recursive (int a){

if(a==0)             //if a is 0, stop the recursive funcion,and return
	return 1;


return a*recursive(a-1);
}

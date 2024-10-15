#include<stdio.h>
//#define N 10
//int stack[N];
int top=-1;

void push(int*stack,int N){
       int x;
       printf("Enter integer to push:");
       scanf("%d",&x);
       if(top==N-1){
        printf("overflow\n");
       }
       else{
        top++;
        stack[top]=x;
       }}
void pop(int*stack){
       int item;
       if (top==-1){
        printf("underflow\n");
       }
       else{
        item=stack[top];
        top--;
        printf("%d\n",item);
       }
       }
void display(int *stack){
       for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
       }}
void peek(int* stack){
       if (top==-1){
        printf("stack is empty\n");
       }else{
       printf("%d\n",stack[top]);
       }}
void main(){
    int n;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int stack[n];
    int choice;
     printf("THIS IS AN INTEGER STACK \n");
        printf("1.PUSH AN ELEMENT\n");
        printf( "2.POP AN ELEMENT\n");
        printf( "3.DISPLAY THE STACK\n");
        printf("4.DISPLAY PEEK\n");
        printf("0.EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
            while(choice!=0){

                if(choice==1){
                    push(stack,n);

                }
                else if(choice==2){
                    pop(stack);}
                   // break;}
                else if(choice==3){
                    display(stack);
                    //break;
                }
                else if(choice==4){
                    peek(stack);
                    //break;
                }
                else{
                    printf("invalid\n");
                    //break;
                }
                printf("Enter your choice:");

                scanf("%d",&choice);
                }
       }


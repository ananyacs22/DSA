#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
int stack[MAX];
void push();
void pop();
void dispaly();
void push(){
        if(top>=MAX-1){
            printf("STACK OVERFLOW!\n");
        }
        else {
            int value;
            printf("Enter a value to push into the stack:");
            scanf("%d",&value);
            top++;
            stack[top]=value;
            printf("%d has been pushed to the stack\n",value);
        }
}
void pop(){
        if(top==-1){
            printf("STACK UNDERFLOW!\n");
        }
        else{
            printf("%d has been popped out of the stack\n",stack[top]);
            top--;
        }
}
void display(){
    if(top==-1){
            printf("STACK IS EMPTY!.NOTHING TO DISPLAY!\n");
        }
    else{
        printf("Stack Elements Are:\n");
        for(int i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
    }
}
int main(){
    while(1){
        printf("\t\tSTACK MENU\n1.PUSH\n2.POP\n3.DISPALY\n4.EXIT\n");
        int choice;
        printf("Enter your choice(1-4):");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("EXITING THE PROGRAM!!\n");
            exit(0);
        default:
            printf("INVALID CHOICE!\n");
        }
    }
    return 0
}

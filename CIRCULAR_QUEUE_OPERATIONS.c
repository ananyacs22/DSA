#include<stdio.h>
#include<stdlib.h>
#define max 5
int front=-1;
int rear=-1;
int queue[max];
void enqueue(){
    if (front==0&&rear==max-1||front==rear+1){
        printf("QUEUE OVERFLOW!!\n");
    }
    else{
        if(front==-1&&rear==-1){
            front=0;
            rear=0;
        }
        else if(front!=0&&rear==max-1)
            rear=0;
        else
            rear++;
        int val;
        printf("Enter a value to insert:");
        scanf("%d",&val);
        queue[rear]=val;
    }
}
void dequeue(){
        if(front==-1){
            printf("QUEUE UNDERFLOW!!..\n");
        }
        printf("%d is deleted from the queue\n",queue[front]);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(front==max-1)
            front=0;
        else
            front++;
}
void display(){
    if(front==-1&&rear==-1){
        printf("QUEUE EMPTY NOTHING TO DISPLAY!!.\n");
    }
    else{
        for(int i=front;;i++){
            printf("%d\t",queue[i]);
            if(i==rear){
                break;
            }
        }
    }
}
int main(){
    while(1){
        int choice;
        printf("\nQUEUE MENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPALY\n4.EXIT\n");
        printf("enter your choice(1-4):");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
                printf("EXITING PROPGRAM!");
                exit(0);

        }
    }
}

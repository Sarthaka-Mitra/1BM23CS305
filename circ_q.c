#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int rear = -1, front = -1;

int isFull(){
    if (front == 0 && rear == MAX - 1)
        return 1;
    else if ((rear+1)%MAX==front)
        return 1;
    else   
        return 0;
    
}

int isEmpty(){
    return((rear==-1 && front==-1)?1:0);
}

void enq(int x){
    if (isFull())
        {printf("Queue is full\n"); return;}
    else if (isEmpty())
        {front=0;rear=0;}
    else
        rear=(rear+1)%MAX;
    queue[rear]=x;
    //printf("front = %d\nrear = %d", front, rear);
}

void deq(){
    if (isEmpty())
        {printf("Queue is empty\n");return;}
    else if (front==rear)
        {front=-1;rear=-1;}
    else
        front=(front+1)%MAX;
}

void display(){
    for(int i=front;i!=rear;i=(i+1)%MAX)
        printf("%d\t", queue[i]);
    printf("%d\n", queue[rear]);
}

int main(){
    int elem, choice, flag=1;
    while(flag){
        printf("\nChoose the operation from the given menu:");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter the choice:\t");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value:");
                scanf("%d", &elem);
                enq(elem);
                break;
            case 2:
                deq();
                printf("\nElement removed from queue");
                break;
            case 3:
                display();printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
                break;
        }
    }
    return 0;
}

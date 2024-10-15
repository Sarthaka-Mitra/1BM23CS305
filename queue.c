#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int rear = -1, front = -1;

int isFull(){
    return((rear==(MAX-1)?1:0));
}

int isEmpty(){
    return((rear==-1 && front==-1)?1:0);
}

void enq(int x){
    if (isFull())
        printf("Queue is full");
    else if (isEmpty())
        {front=0;rear=0;}
    else
        rear++;
    queue[rear]=x;
}

void deq(){
    if (isEmpty())
        printf("Queue is empty");
    else if (front==rear)
        {front=-1;rear=-1;}
    else
        front++;
}

void display(){
    for(int i=front;i<=rear;i++)
        printf("%d\t", queue[i]);
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
        }
    }
    return 0;
}
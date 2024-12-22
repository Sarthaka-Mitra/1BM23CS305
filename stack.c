#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty(){
    return (top == -1);
}

int isFull(){
    return (top == MAX - 1);
}

int pop(){
    return stack[top--];
}

void insert(int elem){
    stack[++top]=elem;
}

void display(){
    for(int i = 0; i<top+1; i++)
        printf("%d\t", stack[i]);
    printf("\n");
}

int main(){
    int choice, elem, key,flag=1;
    printf("Enter your choice:\n");
    while(flag){
        printf("\n1.Push\n2.Display\n3.Pop\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value to insert:");
            scanf("%d", &elem);
            insert(elem);
            break;
        case 2:
            printf("\nStack:\n");
            display();
            printf("\n");
            break;
        case 3:
            elem=pop();
            printf("\nElement popped = %d", elem);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
            printf("\n");
            break;
        }
    }
    return 0;
}
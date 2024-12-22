#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* Node;

struct label{
    Node front;
    Node rear;
};

Node create(int x){
    Node new = (Node)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    return new;
}

struct label enq(struct label head, int x){
    Node new = create(x);
    if(head.front == NULL)
        head.front = head.rear = new;
    else{
        head.rear->next = new;
        head.rear = new;
    }
    return head;
}

struct label deq(struct label head){
    if(head.front == NULL && head.rear == NULL)
        printf("\nQueue empty");
    else if(head.front == head.rear){
        free(head.front);
        head.front = head.rear = NULL;
    }
    else{
        Node temp = head.front;
        head.front=head.front->next;
        free(temp);
    }
    return head;
}

void disp(struct label head) {
    Node temp = head.front;
    if(temp==NULL)
        printf("\nList empty");
    else
    {
        while(temp!=NULL) {
            printf("%d\t", temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    struct label head;
    head.front = head.rear = NULL;
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
                head = enq(head, elem);
                break;
            case 2:
                head = deq(head);
                printf("\nElement removed from queue");
                break;
            case 3:
                disp(head);
                printf("\n");
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
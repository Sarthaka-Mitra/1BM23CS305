#include <stdio.h>
#include <stdlib.h>

 struct node
{
    int data;
    struct node *next;
    
};
typedef struct node* Node;
Node push (Node head, int x) {
    Node new = (Node)malloc(sizeof(struct node));

    if (head == NULL) {
        new->data=x;
        new->next=NULL;
        head = new;
    }
    else {
        new->data=x;
        new->next=head;
        head = new;
    }
    return head;
}

Node pushb(Node head, int x) {
    Node newb=(Node)malloc(sizeof(struct node));
    
    if (head == NULL)
        head=push(head, x);
    
    newb->data=x;
    newb->next=head;
    head=newb;
    return head;
}

Node pushL(Node head, int x) {
    Node temp = head;
    if(head == NULL)
        head=push(head, x);
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        Node newL = (Node)malloc(sizeof(struct node));
        temp->next=newL;
        newL->data=x;
        newL->next=NULL;
    }
    return head;
}

void disp(Node head) {
    Node temp = head;
    if(temp==NULL)
        printf("\nlist empty");
    else
    {
        while(temp!=NULL) {
            printf("%d\t", temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    int choice, elem, flag=1;
    Node head=NULL;
    printf("Enter your choice:\n");
    while(flag){
        printf("\n1. Push\n2.Push at beginning\n3.Push at end\n4.Display \n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value to insert:");
            scanf("%d", &elem);
            head=push(head, elem);
            break;
        case 2:
            printf("\nEnter value to insert at beginning:");
            scanf("%d", &elem);
            head= pushb(head, elem);
            break;
        case 3:
            printf("\nEnter value to insert at end:");
            scanf("%d", &elem);
            head= pushL(head, elem);
            break;
        case 4:
            disp(head);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice");
            break;
        }
    }
    return 0;
}

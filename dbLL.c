#include <stdio.h>
#include <stdlib.h>

 struct node
{
    int data;
    struct node *prev;
    struct node *next;
    
};
typedef struct node* Node;

Node create(int ele) {
    Node new = (Node)malloc(sizeof(struct node));
    new->data=ele;
    new->prev=NULL;
    new->next=NULL;
    return new;
}

Node insE(Node head, int x) {
   Node new=create(x);
    if (head != NULL){
        head->next=new;
        new->prev=head;
    }
    return new;
}

Node insB(Node head, int x){
    Node new = create(x);
    Node temp;
    for(temp=head;temp->prev!=NULL;temp=temp->prev);
    temp->prev=new;
    new->next=temp;
    return head;
}

Node insK(Node head, int x){
    Node temp = head;
    int elem;
    printf("\nAt which element to insert:");
    scanf("%d", &elem);
    for(;temp->prev->data==elem && temp != NULL;temp=temp->prev);
    printf("%d\n", temp->data);

    Node new = create(x);

    new->next=temp;
    new->prev=temp->prev;

    temp->prev=new;
    new->prev->next=new;

    return head;

}

void disp(Node head) {
    Node temp = head;
    if(temp==NULL)
        printf("\nList empty");
    else
    {
        while(temp!=NULL) {
            printf("%d\t", temp->data);
            temp=temp->prev;
        }
    }
}


int main(){
    int choice, elem, key,flag=1;
    Node head=NULL;
    printf("Enter your choice:\n");
    while(flag){
        printf("\n1.Insert at end\n2.Insert at beginning\n3.Insert at key\n4.Display\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value to insert:");
            scanf("%d", &elem);
            head = insE(head, elem);
            break;
        case 2:
            printf("\nEnter value to insert:");
            scanf("%d", &elem);
            head = insB(head, elem);
            break;
        case 3:
            printf("\nEnter value to insert:");
            scanf("%d", &elem);
            head = insK(head, elem);
            break;
        case 4:
            disp(head);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice");
            printf("\n");
            break;
        }
    }
    return 0;
}

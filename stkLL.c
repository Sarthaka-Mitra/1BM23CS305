#include <stdio.h>
#include <stdlib.h>

 struct node
{
    int data;
    struct node *next;
    
};
typedef struct node* Node;

Node create(int ele) {
    Node new = (Node)malloc(sizeof(struct node));
    new->data=ele;
    new->next=NULL;
    return new;
}
Node push (Node head, int x) {
   Node new=create(x);
    if (head != NULL)
        new->next=head;
    return new;
}

Node pop(Node head){
    int val;
    Node temp=head;
    head=head->next;
    val=temp->data;
    printf("\nValue popped is = %d", val);
    free(temp);
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
            temp=temp->next;
        }
    }
}


int main(){
    int choice, elem, flag=1;
    Node head=NULL;
    printf("Enter your choice:\n");
    while(flag){
        printf("\n1.Push\n2.Display\n3.Pop\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value to insert:");
            scanf("%d", &elem);
            head=push(head, elem);
            break;
        case 2:
            printf("\nStack:\n");
            disp(head);
            printf("\n");
            break;
        case 3:
            head=pop(head);
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

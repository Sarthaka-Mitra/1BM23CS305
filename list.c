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
    new->data=x;
    new->next=NULL;
    if (head != NULL)
        new->next=head;
    return new;
}

Node push_e(Node head, int x) {
    Node temp = head;

    if (head==NULL){
        printf("\nList empty");
        head = push(head, x);
    }
    else {
        while(temp->next!=NULL)
            temp=temp->next;

        Node new = (Node)malloc(sizeof(struct node));
        
        temp->next=new;
        new->data=x;
        new->next=NULL;
    }

    return head;
}

Node push_B(Node head, int x) {
    Node new = (Node)malloc(sizeof(struct node));

    if (head==NULL) {
        printf("\nList empty");
        head = push(head, x);
    }
    else {
        new->data=x;
        new->next=head;
        head = new;
    }
    
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

Node del_b(Node head){
    Node temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node del_e(Node head){
    Node i,j;

    i = head;
    j=head->next;

    while(j->next!=NULL){
        i=j;
        j=j->next;
    }

    i->next=NULL;
    free(j);
    return head;
}

Node del_key(Node head, int key) {
    Node temp = head;

    while(temp->data != key && temp!=NULL)
        temp=temp->next;

    if(temp!=NULL) {
        if (temp == head) {
            head = head->next;
            free(temp);
        }

        else {
            Node i = head;
            while(i->next!=temp)
                i=i->next;

            i->next=temp->next;
            free(temp);
        }
    }
    else {
        printf("\nError in deletion: Element not found");
    }
    return head;
}
int main(){
    int choice, elem, key,flag=1;
    Node head=NULL;

    printf("Enter your choice:\n");
    

    while(flag){
        printf("\n1.Push\n2.Push at beginning\n3.Push at end\n4.Display\n5.Delete at beginning\n6.Delete at end\n7.Deletion of key\n8.Exit");
        printf("\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value to push:");
            scanf("%d", &elem);
            head=push(head, elem);
            break;
        case 2:
            printf("\nPush at beginning");
            scanf("%d", &elem);
            head = push_B(head, elem);
            break;
        case 3:
            printf("\nPush at end:");
            scanf("%d", &elem);
            head = push_e(head, elem);
            break;
        case 4:
            disp(head);
            break;
        case 5:
            if(head == NULL)
                printf("\nList Empty");
            else {
                printf("\nDeletion at beginning");
                head = del_b(head);
            }
            break;
        case 6:
            if(head == NULL)
                printf("\nList Empty");
            else {
                printf("\nDeletion at end");
                head = del_e(head);
            }
            break;
        case 7:
            printf("\nEnter element to be deleted:");
            scanf("%d", &elem);
            head = del_key(head, elem);
            break;
        case 8:
            exit(0);
        default:
            printf("\nInvalid choice");
            break;
        }
    }
    return 0;
}

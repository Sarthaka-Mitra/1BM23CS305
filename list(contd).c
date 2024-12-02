#include <stdio.h>
#include <stdlib.h>
int stk[100], top = -1;


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

Node reverse(Node head){
    int n;
    Node p1;
    
    for(p1=head;p1!=NULL;p1=p1->next, n++);

    p1=head;

    for(int i=0;i<n;i++){
        stk[++top]=p1->data;
        p1=p1->next;
    }

    p1 = head;

    for(int i=0;i<n;i++){
        p1->data=stk[top--];
        p1=p1->next;
    }
    disp(head);
    return head;


}


Node concat(Node h1, Node h2){
    Node p1;

    for(p1=h1;p1->next!=NULL;p1=p1->next);

    p1->next=h2;

    disp(h1);
    return h1;
}

Node sort(Node head){
	struct node *curr = head, *index;
	while(curr){
		index = curr->next;
		while(index){
			if(curr->data > index->data){
				int temp = curr->data;
				curr->data = index->data;
				index->data = temp;
			}
			index = index->next;
		}
		curr = curr->next;
	}
	disp(head);
	return(head);
}


int main(){
    int choice, elem, key,flag=1;
    Node head=NULL, h2 = NULL;
    printf("Enter your choice:\n");
    while(flag){
        printf("\n1.Push\n2.Display\n3.Sort\n4.Reverse\n5.Concatenation\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value to insert:");
            scanf("%d", &elem);
            head=push(head, elem);
            h2 = push(h2, rand()%100);
            break;
        case 2:
            printf("\nLinked list 1:\n");
            disp(head);
            printf("\nLinked list 2:\n");
            disp(h2);
            printf("\n");
            break;
        case 3:
            head=sort(head);
            printf("\nLinked list 1 sorted\n");
            h2=sort(h2);
            printf("\nLinked list 2 sorted\n");
            break;
        case 4:
            printf("\nLinked list 1 reversed\n");
            head = reverse(head);
            printf("\nLinked list 2 reversed\n");
            h2=reverse(h2);
            printf("\n");
            break;
        case 5:
            printf("\nLinked list 1 and 2 concatenated\n");
            head=concat(head, h2);
            printf("\n");
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid choice");
            printf("\n");
            break;
        }
    }
    return 0;
}

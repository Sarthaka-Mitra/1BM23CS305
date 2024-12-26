#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* L;
    struct node* R;
    int val;
};

typedef struct node* Node;

Node create(int x){
    Node new = (Node)malloc(sizeof(struct node));
    new->val = x;
    new->L = new->R = NULL;

    return new;
}

Node insert(Node root, int x){
    Node new = create(x), temp = root, cur;

    if(root==NULL)
        root = new;
    else{
        while(temp!=NULL){
            cur = temp;

            temp = (x < temp->val)?temp->L:temp->R;
        }

        if(x < cur->val)
            cur->L = new;
        else
            cur->R = new;
    }
    return root;
}

void inorder(Node root){
    if(root!=NULL){
        inorder(root->L);
        printf("%d\t", root->val);
        inorder(root->R);
    }
}

void postorder(Node root){
    if(root!=NULL){
        postorder(root->L);
        postorder(root->R);
        printf("%d\t", root->val);
    }
}

void preorder(Node root){
    if(root!=NULL){
        printf("%d\t", root->val);
        preorder(root->L);
        preorder(root->R);
    }
}




void main(){
    Node root = NULL;
    int x;
    root = insert(root, 50);
    for(int i = 0; i < 10; i++){
        x=rand()%100;
        printf("%d\t",x);
        root = insert(root,x);
    }
    printf("\nInorder of the tree: \n");
    inorder(root);
    printf("\nPreorder of the tree: \n");
    preorder(root);
    printf("\nPostorder of the tree: \n");
    postorder(root);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char stack[MAX], infix[MAX], postfix[MAX];
int top=-1;

int assoc(char c){
    return ((c=='^')?1:0);
}

int prec(char c){
    switch (c)
    {
        case '^': return 3;
        case '/': return 2;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}

void ifxpfx(){
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    //printf("%d\n", prec(infix[0]));
    int counter = 0;
    for (int i=0; i<strlen(infix);i++){
        
        if(infix[i]=='(')
        {
            stack[++top]=infix[i];
        }
        else if(prec(infix[i])==0){
            postfix[counter++]=infix[i];
            printf("%s", postfix);
        }
        else if (infix[i]==')'){
            while (top>=0 && stack[top]!='(')
                postfix[counter++]=stack[top--];
            top--;
        }
        else {
            while (top>=0 && (prec(infix[i])<=prec(stack[top])))
                postfix[counter++]=stack[top--];
            stack[++top]=infix[i];
        }
    }
        while(top>=0)
            postfix[counter++]=stack[top--];
        
        postfix[counter]='\0';
        printf("\n%s\n", postfix);
}


int main(){
    ifxpfx();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct stack
{
    node *top;
}stack;


stack *create_stack(){
    stack *new_stack=(stack *)malloc(sizeof(stack));
     new_stack->top=NULL;
     return new_stack;
}

node *create_node(int data){
    node *new_node=(node *)malloc(sizeof(node));
    if (new_node==NULL)
    {
        return NULL;
    }
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void push(stack *S,int data){
    node *new_node=create_node(data);
    if (new_node==NULL)
    {
        printf("memory not alloted");
        return;
    }
    new_node->next=S->top;
    S->top=new_node;
    printf("the value : %d is pushed on : %p in next it store : %p\n",data,S->top,new_node->next);
}

int isempty(stack *S){
    if(S->top==NULL)return 1;
    return 0;
}

int pop(stack *S){
    if (isempty(S))
    {
        return -1;
    }
    int data=S->top->data;
    node *temp=S->top;
    S->top=S->top->next;
    free(temp);
    return data;
    
}

int peek(stack *S){
    if (isempty(S))
    {
        return -1;
    }
    return S->top->data;
}

void free_space(stack *S) {
    node *temp;
    while (S->top != NULL) {
        temp = (*S).top;
        S->top = S->top->next;
        free(temp);
    printf(":-)\t");
    }
    free(S);
}


int main(){
    stack *S1;
    S1=create_stack();
    printf("%p\n",S1->top);

    push(S1, 10);
    push(S1, 20);
    push(S1, 30);
    push(S1, 40);
    push(S1, 50); 
    printf("top node add: %p\n",S1->top); 

    printf("the poped value is : %d\n",pop(S1)); 
    printf("the poped value is : %d\n",pop(S1)); 
        printf("top node add: %p\n",S1->top); 

    printf("the peeked element is : %d\n",peek(S1));

    push(S1,100);
    printf("the peeked element is : %d\n",peek(S1));


    free_space(S1);
    printf("ended!");
    return 0; 
}
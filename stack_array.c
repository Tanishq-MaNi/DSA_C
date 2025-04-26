#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

stack *create_stack(int size)
{
    stack *new_stack = (stack *)malloc(sizeof(stack));
    new_stack->arr = (int *)malloc(size * (sizeof(int)));
    new_stack->size = size;
    new_stack->top = -1;
    return new_stack;
}

int isempty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isfull(stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(stack *s, int value)
{
    if (isfull(s)){
        printf("cant push %d the stack is full!\n",value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("the value: %d is pushed on index: %d\n", value, s->top);
}

int pop(stack *s){
    if (isempty(s))
    {
        return -1;
    }
    
    int temp;
    temp=s->arr[s->top];
    s->top=s->top-1;
    return temp;
}

void free_stack(stack *s){
    if(s){
        free(s->arr);
        free(s);
    }
}
int main()
{

    stack *S1;
    S1 = create_stack(7);

    push(S1, 10);
    push(S1, 20);
    push(S1, 30);
    push(S1, 40);
    push(S1, 50);
    push(S1, 60);
    push(S1, 70);
    push(S1, 80);
    
    printf("the poped element is : %d\n",pop(S1));
    
    printf("the top value is: %d\n",S1->top);
    free_stack(S1);
    return 0;
}
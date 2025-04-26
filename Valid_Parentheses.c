#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} stack;

stack *create_stack(int size){
    stack *new_stack=(stack *)malloc(sizeof(stack));
    new_stack->arr=(char *)malloc(size*sizeof(char));
    new_stack->size=size;
    new_stack->top=-1;
    return new_stack;
}

int isempty(stack *s){
    return s->top==-1;
}

int isfull(stack *s){
    return s->top==s->size-1;
}

void push(stack *s,char c){
    s->arr[++(s->top)]=c;
    printf("%c is pushed in stack\n",s->arr[s->top]);
}

void pop(stack *s){
    printf("%c is poped from stack\n",s->arr[s->top]);
    s->top=s->top-1;

}

int checkMatch(char c1, char c2){
    if (c1 == '(' && c2 == ')') return 1;
    if (c1 == '[' && c2 == ']') return 1;
    if (c1 == '{' && c2 == '}') return 1;
    return 0;
}

int isbalanced(stack *s,char e[]){
    for (int i = 0; i < s->size; i++)
    {
        if (e[i]=='{'||e[i]=='['||e[i]=='(')
        {
            push(s,e[i]);
            continue;
        }
        if (e[i]=='}'||e[i]==']'||e[i]==')')
        {
            if (isempty(s)) return 0;
            if (checkMatch(s->arr[s->top],e[i])) pop(s);
            else return 0;
        }
    } 
    return isempty(s);
}

int main(){
    // {[()]}
    char e[]="[ 4 + { 3 × ( − 2 ) } ] − [ { ( 4 × 6 ) + ( 14 ÷ 7 ) } − ( − 3 ) ] ";
    printf("%d\n",strlen(e)); //  \0 at the end of string
    stack *S1=create_stack(strlen(e));
    isbalanced(S1,e)?printf("Is Balanced"):printf("Not Balanced");
    free(S1);
}
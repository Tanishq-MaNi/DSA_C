#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    int size;
    char *arr;
} stack;

stack *create_stack(int size)
{
    stack *new_stack = (stack *)malloc(sizeof(stack));
    new_stack->arr = (char *)malloc(size * sizeof(char));
    new_stack->size = size;
    new_stack->top = -1;
    return new_stack;
}

void push(stack *s, char c)
{
    s->arr[++(s->top)] = c;
    printf("%c is pushed in stack\n", s->arr[s->top]);
}

int isempty(stack *s)
{
    return s->top == -1;
}

char pop(stack *s)
{
    printf("%c is poped from stack\n", s->arr[s->top]);
    char temp = s->arr[s->top];
    s->top = s->top - 1;
    return temp;
}
int isoperator(char c)
{
    return (c == '/' || c == '*' || c == '+' || c == '-');
}

int precedence(char c)
{
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

char *intopos(char *infix)
{
    stack *new_stack = create_stack(strlen(infix) + 1);
    char *postfix = (char *)malloc(new_stack->size * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]) && infix[i] != ' ')
        {
            postfix[j] = infix[i];
            i++;
            j++;
            continue;
        }
        else if (isoperator(infix[i]))
        {
             if (precedence(infix[i]) > precedence(new_stack->arr[new_stack->top]))
            {
                push(new_stack, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(new_stack);
                j++;
            }
            continue;
        }
        i++;
    }
    while (!isempty(new_stack))
    {
        postfix[j] = pop(new_stack);
        j++;
    }
    postfix[j] = '\0';
    free(new_stack->arr);
    free(new_stack);
    return postfix;
}

int main()
{
    char infix[] = "a + b - c * d";
    printf("the lenght of given infix expression:%d\n", strlen(infix));
    char *postfix = intopos(infix);
    printf("%s", postfix);
    free(postfix);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void traversal(node *ptr)
{
    printf("%d\n", ptr->data);
    if (ptr->next != NULL)
    {
        traversal(ptr->next);
    }
}

int main()
{
    node *head, *second, *third;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));

    head->data = 45;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 21;
    third->next = NULL;

    traversal(head);
    free(third);
    free(second);
    free(head);

    return 0;
}
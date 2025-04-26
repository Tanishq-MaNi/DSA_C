#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node *insert_beginning(node *head, int data)
{
    node *newNode = create_node(data);
    newNode->next = head;
    return newNode;
}

node *deletion(node *head,int value){
    node *node;
    if (head->data==value)
    {
        node=head->next;
        free(head);
        return node;
    }
    node=head;
    while (node->data!=value)
    {
        node=node->next;
    }
    
    free(node);
    

    
}

void traversal(node *ptr)
{
    printf("%d\n", ptr->data);
    if (ptr->next != NULL)
    {
        traversal(ptr->next);
    }
}

void free_space(node *head){
    node *temp;
    while (head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    
}
int main()
{
    node *head=create_node(10);
    head=insert_beginning(head,20);
    head=insert_beginning(head,30);
    head=insert_beginning(head,40);

    traversal(head);

    head=deletion(head,);

    return 0;
}
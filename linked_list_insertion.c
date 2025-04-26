#include <stdio.h>
#include<stdlib.h>

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

void insert_end(node *head, int data)
{
    node *newNode = create_node(data);
    node *current_node = head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = newNode;
}

void insert_after_node(node *head,int data, int index){
        node *newNode = create_node(data);
    node *current_node=head,*temp;
    for (int i = 0; i < index; i++)
    {
        temp=current_node;
        current_node = current_node->next;
    }
    newNode->next=current_node;
    temp->next=newNode;
}

void display(node *head){
    printf("data:%d\n",head->data);
    if(head->next!=NULL){
    display(head->next);
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
    insert_end(head,50);
    insert_after_node(head,100,3);
    insert_end(head,120);
    head=insert_beginning(head,70);

    display(head);
    free_space(head);


    return 0;
}
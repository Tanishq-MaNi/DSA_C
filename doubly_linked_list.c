#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create_node(int data);

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

node *get_nth_node(node *head, int index)
{
    if (head == NULL)
        return NULL;
    if (index == 1)
        return head;
    return get_nth_node(head->next, index - 1);
}

node *insert_beginning(node *head, int data)
{
    node *new_node = create_node(data);

    new_node->next = head;
    head->prev = new_node;
    return new_node;
}

void insert_end(node *head, int data)
{
    node *new_node = create_node(data);
    node *current_node = head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->prev = current_node;
}

void insert_nth(node *nth_node,int data){
    node *new_node=create_node(data);
    new_node->prev=nth_node->prev;
    new_node->next=nth_node;
    nth_node->prev->next=new_node;
    nth_node->prev=new_node;
}


void display(node *head)
{
    printf("data:%d\n", head->data);
    if (head->next != NULL)
    {
        display(head->next);
    }
}

void free_space(node *head)
{
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    node *nth_node, *head;
    int place;

    head = create_node(90);
    head = insert_beginning(head, 80);
    head = insert_beginning(head, 70);
    head = insert_beginning(head, 60);

    insert_end(head, 100);
    insert_end(head, 110);

    printf("enter the nth node place which data and pointer you want:-");
    scanf("%d", &place);
    nth_node = get_nth_node(head, place);
    (nth_node == NULL) ? printf("out of range index!!\n\n") : printf("data:%d  & pointer:%p\n\n", nth_node->data, nth_node);

    printf("enter the place at which you want to insert node:");
    scanf("%d", &place);
    nth_node = get_nth_node(head, place);
    (place==1)?head = insert_beginning(head, 1245):insert_nth(nth_node,1245);
    printf("data:%d  & pointer:%p\n\n", nth_node->data, nth_node);


    display(head);
    free_space(head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next;
    int value;
};

struct linked_list {
    struct node* head;
    struct node* tail;
    int size;
};

void insert_node (struct linked_list *list,int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = val;
    newNode->next = NULL;
    if (list->size==0)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void print_list(struct linked_list* list)
{
    if (list->size)
    {
        struct node* newNode= list->head;
        while (newNode!=NULL)
        {
            printf("%d ",newNode->value);
            newNode=newNode->next;
        } 
        printf("\n");
    }
}

void delete_node (struct linked_list* list,int index)
{
    if (index >= list->size)
    {
        printf("Index Out Of Bounds.\n");
        return;
    }
    list->size--;
    if (index==0)
    {
        list->head=list->head->next;
        return;
    }

    struct node* newNode= list->head;
    for (int i=1;i<index;i++)
    {
        newNode= newNode->next;
    }
    newNode->next= newNode->next->next;
}

int main()
{
    struct linked_list list;
    list.size=0;
    insert_node(&list,5);
    print_list(&list);
    insert_node(&list,6);
    print_list(&list);
    insert_node(&list,7);
    print_list(&list);
    insert_node(&list,2);
    print_list(&list);
    insert_node(&list,6);
    print_list(&list);
    delete_node(&list,2);
    print_list(&list);
    delete_node(&list,0);
    print_list(&list);
    delete_node(&list,list.size-1);
    print_list(&list);
    delete_node(&list,list.size);
    print_list(&list);
    return 0;
}
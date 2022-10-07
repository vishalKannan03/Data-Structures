#include <stdio.h>
#include <stdlib.h>
typedef struct LinkedList
{
    int val;
    struct LinkedList *next;
} list;

void insert(list **super, int val)
{
    if (*super == NULL)
    {
        printf("inserting %d\n", val);
        (*super) = (list *)malloc(sizeof(list));
        (*super)->val = val;
        (*super)->next = NULL;
    }
    else
    {
        printf("inserting %d\n", val);
        list *temp = (list *)malloc(sizeof(list));
        temp->val = val;
        temp->next = NULL;
        list *trav = *super;
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = temp;
    }
}

void delete (list **super)
{
}

void traverse(list **super)
{
    list *trav = *super;
    while (trav != NULL)
    {
        printf("%d ", trav->val);
        trav = trav->next;
    }
}

int main()
{
    list *head = NULL;
    for (int i = 0; i <= 7; i++)
    {
        insert(&head, i);
    }
    traverse(&head);
    return 0;
}
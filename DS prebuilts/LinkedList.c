#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int val;
    struct LinkedList *next;
} list;

void insertNode(list **super, int val, char loc)
{
    if (*super == NULL)
    { // if list is empty
        (*super) = (list *)malloc(sizeof(list));
        (*super)->val = val;
        (*super)->next = NULL;
        return;
    }
    list *temp = (list *)malloc(sizeof(list));
    if (loc == 'e')
    { // inserting at end
        temp->val = val;
        temp->next = NULL;
        list *trav = *super;
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = temp;
        return;
    }
    else if (loc == 's')
    { // inserting at start
        temp->val = val;
        temp->next = *super;
        *super = temp;
        return;
    }
    else if (loc == 'm')
    { // inserting in the middle
        temp->val = val;
        printf("Enter location ");
        int n;
        scanf("%d", &n);
        int c = 0;
        list *trav = *super;
        while (c != n)
        {
            if (trav->next != NULL)
                trav = trav->next;
            c++;
        }
        temp->next = trav->next;
        trav->next = temp;
        return;
    }
}

void deleteNode(list **super, char loc)
{
    if (*super == NULL) // if list is empty
        return;
    list *temp = (list *)malloc(sizeof(list));
    if (loc == 's')
    { // deleting from start
        temp = *super;
        *super = (*super)->next;
        free(temp);
    }
    else if (loc == 'e')
    { // deleting from end
        list *trav = *super;
        while (trav->next->next != NULL)
        {
            trav = trav->next;
        }
        temp = trav->next;
        trav->next = NULL;
        free(temp);
    }
    else if (loc == 'm')
    { // deleting from middle
        printf("Enter location ");
        int n;
        scanf("%d", &n);
        int c = 0;
        list *trav = *super;
        while (c != n)
        {
            if (trav->next != NULL)
                trav = trav->next;
            c++;
        }
        temp = trav->next;
        trav->next = trav->next->next;
        free(temp);
    }
}

void traverse(list **super)
{
    list *trav = *super;
    do
    {
        printf("%d ", trav->val);
        trav = trav->next;
    } while (trav != NULL);
}

int main()
{
    list *head = NULL;
    for (int i = 0; i <= 7; i++)
    {
        insertNode(&head, i, 'e');
    }
    traverse(&head);
    return 0;
}
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
    list *temp = (list *)malloc(sizeof(list)); // stores current node
    temp->val = val;
    if (loc == 'e')
    { // inserting at end
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
        temp->next = *super;
        *super = temp;
        return;
    }
    else if (loc == 'm')
    { // inserting in the middle
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
    list *temp = (list *)malloc(sizeof(list)); // temp pointer to be freed
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
    list *head = NULL; // initial pointer
    for (int i = 0; i <= 7; i++)
    {
        insertNode(&head, i, 'e'); // double pointer
    }
    traverse(&head); // double pointer
    return 0;
}
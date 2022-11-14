#include <stdlib.h>
#include <stdio.h>
typedef struct BinarySearchTree
{
    int key;
    struct BinarySearchTree *left, *right;
} node;
int count = 0;
void insert(node **n, int key)
{
    if (*n == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->key = key;
        temp->left = NULL;
        temp->right = NULL;
        *n = temp;
    }
    if (key < (*n)->key)
    {
        insert(&((*n)->left), key);
    }
    else if (key > (*n)->key)
    {
        insert((&(*n)->right), key);
    }
}

int check(node *root, int *prev, int y, int k)
{
    if (root != NULL)
    {
        check(root->left, prev, y, k);
        count++;
        if (y > *prev && y < root->key)
        {
            if (y - *prev >= k && root->key - y >= k)
            {
                return 1;
            }
        }
        *prev = root->key;
        check(root->right, prev, y, k);
    }
}

int main()
{
    node *root = NULL;
    int prev = 0;
    int n;
    scanf("%d", &n);
    int j;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &j);
        insert(&root, j);
    }
    int y, k;
    scanf("%d", &y);
    scanf("%d", &k);
    int c = 0;
    c = check(root, &prev, y, k);
    printf("%d\n", count);
    if (c)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}
// work in progress
//#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct BinarySearchTree
{
    int key;
    struct BinarySearchTree *left, *right;
} node;

node *insert(node *n, int key)
{
    if (n == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->key = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
    }

    return n;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int search(node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->key == key)
    {
        return 1;
    }
    else if (key < root->key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int height(node *n)
{
    if (n == NULL)
        return -1;
    else
    {
        int lheight = height(n->left);
        int rheight = height(n->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

node *minValueNode(node *n)
{
    node *current = n;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("%d\n", search(root, 90));
    printf("%d \n", height(root));
    inorder(root);
}
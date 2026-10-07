#include "bst.h"

BST *makeNode(int data)
{
    BST *t = (BST *)malloc(sizeof(BST));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void inOrder(BST *t)
{
    if (t)
    {
        inOrder(t->left);
        printf("%5d", t->data);
        inOrder(t->right);
    }
}

void preOrder(BST *t)
{
    if (t)
    {
        printf("%5d", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void postOrder(BST *t)
{
    if (t)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%5d", t->data);
    }
}

int findMin(BST *t)
{
    if (!t->left)
    {
        return t->data;
    }
    return findMin(t->left);
}

BST *insert(BST *t, int data)
{
    if (!t)
    {
        return makeNode(data);
    }
    if (t->data > data)
    {
        t->left = insert(t->left, data);
    }
    if (t->data < data)
    {
        t->right = insert(t->right, data);
    }
    return t;
}

BOOL search(BST *t, int data)
{
    if (!t)
    {
        return FALSE;
    }
    if (t->data == data)
    {
        return TRUE;
    }
    if (t->data > data)
    {
        return search(t->left, data);
    }
    return search(t->right, data);
}

BST *deleteNode(BST *t, int data)
{
    if (!t)
    {
        return NULL;
    }
    if (t->data == data)
    {
        if (!t->left && !t->right)
        {
            return NULL;
        }
        if (!t->left)
        {
            return t->right;
        }
        if (!t->right)
        {
            return t->left;
        }
        t->data = findMin(t->right);
        t->right = deleteNode(t->right, t->data);
        return t;
    }
    if (t->data > data)
    {
        t->left = deleteNode(t->left, data);
    }
    else
    {
        t->right = deleteNode(t->right, data);
    }
    return t;
}

int count(BST *t)
{
    if (!t)
    {
        return 0;
    }
    return 1 + count(t->left) + count(t->right);
}

int height(BST *t)
{
    if (!t)
    {
        return 0;
    }
    int leftHeight = height(t->left);
    int rightHeight = height(t->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

BOOL isEquals(BST *p, BST *q)
{
    if (!p && !q)
    {
        return TRUE;
    }
    if (!p || !q)
    {
        return FALSE;
    }
    if (p->data != q->data)
    {
        return FALSE;
    }
    return isEquals(p->left, q->left) && isEquals(p->right, q->right);
}


#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int height(Node *n)
{
    return n ? n->height : 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

Node *createNode(int key)
{
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
        return NULL;

    n->data = key;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}

int balanceFactor(Node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balanceFactor(root);

    if (b > 1 && key < root->left->data)
        return rightRotate(root);

    if (b < -1 && key > root->right->data)
        return leftRotate(root);

    if (b > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *minValueNode(Node *root)
{
    Node *p = root;
    while (p && p->left)
        p = p->left;
    return p;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balanceFactor(root);

    if (b > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (b > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (b < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *search(Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(Node *root)
{
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

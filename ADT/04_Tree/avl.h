
#ifndef AVL_H
#define AVL_H

typedef struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int key);
Node *deleteNode(Node *root, int key);
Node *search(Node *root, int key);

void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);

#endif

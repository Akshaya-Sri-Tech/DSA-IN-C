/* Write a C program to implement searching in a sorted array, unsorted array, singly linked list, Binary Search Tree (BST), and AVL tree.
Insert 4000 randomly generated integers (0–9999) into each data structure.
Perform 50000 searches using randomly generated search keys.
Count the number of comparisons performed by each search operation and calculate the average comparisons per search.
Display and compare the average search comparisons for all five data structures.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000
#define SIZE 4000
#define MAX2 50000
typedef enum { FALSE, TRUE } BOOL;
int randNo(){ return rand() % MAX; }

typedef struct
{
    int s_arr[SIZE];
    int size;
} SARR;

int searchSarr(SARR *a, int val)
{
    int low = 0;
    int high = a->size - 1;
    int count = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        count++;
        if (a->s_arr[mid] == val)
            return count;
        if (val < a->s_arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return count;
}

void insertSarr(SARR *a, int val)
{
    if (a->size >= SIZE)
        return;

    int i = a->size - 1;

    while (i >= 0 && a->s_arr[i] > val)
    {
        a->s_arr[i + 1] = a->s_arr[i];
        i--;
    }

    a->s_arr[i + 1] = val;
    a->size++;
}

typedef struct
{
    int arr[SIZE];
    int size;
} ARRAY;

int searchA(ARRAY *a, int val)
{
    int count = 0;

    for (int i = 0; i < a->size; i++)
    {
        count++;

        if (a->arr[i] == val)
            return count;
    }

    return count;
}

void insertA(ARRAY *a, int val)
{
    if (a->size < SIZE)
    {
        a->arr[a->size] = val;
        a->size++;
    }
}

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *makeNode(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    if (temp == NULL)
        exit(1);

    temp->data = data;
    temp->next = NULL;

    return temp;
}

int searchLL(NODE *head, int val)
{
    int count = 0;

    while (head != NULL)
    {
        count++;

        if (head->data == val)
            return count;

        head = head->next;
    }

    return count;
}

NODE *insertTail(NODE *head, int val)
{
    NODE *newNode = makeNode(val);

    if (head == NULL)
        return newNode;

    NODE *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} BST;

BST *makeBSTNode(int data)
{
    BST *temp = (BST *)malloc(sizeof(BST));

    if (temp == NULL)
        exit(1);

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int searchBST(BST *root, int val)
{
    int count = 0;

    while (root != NULL)
    {
        count++;

        if (root->data == val)
            return count;

        if (val < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return count;
}

BST *insertBST(BST *root, int val)
{
    if (root == NULL)
        return makeBSTNode(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);

    return root;
}

typedef struct nodE
{
    int data;
    int height;
    struct nodE *left;
    struct nodE *right;
} AVL;

int height(AVL *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

AVL *makeAVLNode(int data)
{
    AVL *temp = (AVL *)malloc(sizeof(AVL));

    if (temp == NULL)
        exit(1);

    temp->data = data;
    temp->height = 1;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int balance(AVL *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

AVL *rightRotate(AVL *y)
{
    AVL *x = y->left;
    AVL *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

AVL *leftRotate(AVL *x)
{
    AVL *y = x->right;
    AVL *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

int searchAVL(AVL *root, int val)
{
    int count = 0;

    while (root != NULL)
    {
        count++;

        if (root->data == val)
            return count;

        if (val < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return count;
}

AVL *insertAVL(AVL *root, int val)
{
    if (root == NULL)
        return makeAVLNode(val);

    if (val < root->data)
        root->left = insertAVL(root->left, val);
    else if (val > root->data)
        root->right = insertAVL(root->right, val);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balance(root);

    if (b > 1 && val < root->left->data)
        return rightRotate(root);

    if (b < -1 && val > root->right->data)
        return leftRotate(root);

    if (b > 1 && val > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && val < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    SARR a1;
    ARRAY a2;
    NODE *L1 = NULL;
    BST *bstRoot = NULL;
    AVL *avlRoot = NULL;

    int val;
    int resSarr = 0;
    int resArray = 0;
    int resLL = 0;
    int resBST = 0;
    int resAVL = 0;

    a1.size = 0;
    a2.size = 0;

    while (a1.size < SIZE)
    {
        val = randNo();
        insertSarr(&a1, val);
        insertA(&a2, val);
        L1 = insertTail(L1, val);
        bstRoot = insertBST(bstRoot, val);
        avlRoot = insertAVL(avlRoot, val);
    }

    for (int i = 0; i < MAX2; i++)
    {
        val = randNo();
        resSarr += searchSarr(&a1, val);
        resArray += searchA(&a2, val);
        resLL += searchLL(L1, val);
        resBST += searchBST(bstRoot, val);
        resAVL += searchAVL(avlRoot, val);
    }

    printf("Sorted Array : %d\n", resSarr / MAX2);
    printf("Array        : %d\n", resArray / MAX2);
    printf("Linked List  : %d\n", resLL / MAX2);
    printf("BST          : %d\n", resBST / MAX2);
    printf("AVL          : %d\n", resAVL / MAX2);

    return 0;
}

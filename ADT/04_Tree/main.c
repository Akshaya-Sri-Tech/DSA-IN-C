
#include <stdio.h>
#include "avl.h"

int main(void)
{
    Node *root = NULL;
    int values[] = {30, 20, 10, 25, 40, 50};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nSearch 25: ");
    printf("%s", search(root, 25) ? "Found" : "Not found");

    root = deleteNode(root, 25);

    printf("\nAfter deleting 25: ");
    inorder(root);

    printf("\n");
    return 0;
}

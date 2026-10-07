#include "../ADT/00_Tree/bst.h"

int main(void)
{
    BST *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int count = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < count; i++)
    {
        root = insert(root, values[i]);
    }

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Search 40: %s\n", search(root, 40) ? "Found" : "Not Found");
    printf("Search 15: %s\n", search(root, 15) ? "Found" : "Not Found");

    root = deleteNode(root, 30);
    printf("After deleting 30: ");
    inOrder(root);
    printf("\n");

    return 0;
}

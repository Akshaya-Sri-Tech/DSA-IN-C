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

void BFS(BST* root) {
    if (root == NULL) return;
    BST* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        BST* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

BOOL mirror(BST* left, BST* right)
{
    if (!left && !right) return TRUE;
    if (!left || !right) return FALSE;
    if (left->data != right->data) return FALSE;

    return mirror(left->left, right->right) &&
           mirror(left->right, right->left);
}

BOOL isSymmetric(BST* root)
{
    if (!root) return TRUE;
    return mirror(root->left, root->right);
}

int numTrees(int n)
{
    int* dp = (int*)calloc(n + 1, sizeof(int));
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;

    for (int nodes = 2; nodes <= n; nodes++)
    {
        for (int root = 1; root <= nodes; root++)
        {
            int left = root - 1;
            int right = nodes - root;
            dp[nodes] += dp[left] * dp[right];
        }
    }

    int ans = dp[n];
    free(dp);
    return ans;
}

BOOL validate(BST* root, BST* min, BST* max)
{
    if (!root) return TRUE;
    if (min && root->data <= min->data) return FALSE;
    if (max && root->data >= max->data) return FALSE;

    return validate(root->left, min, root) &&
           validate(root->right, root, max);
}

BOOL isValidBST(BST* root)
{
    return validate(root, NULL, NULL);
}

BST* buildSorted(int nums[], int l, int r)
{
    if (l > r) return NULL;

    int mid = l + (r - l) / 2;
    BST* root = createNode(nums[mid]);

    root->left = buildSorted(nums, l, mid - 1);
    root->right = buildSorted(nums, mid + 1, r);

    return root;
}

BST* sortedArrayToBST(int nums[], int n)
{
    return buildSorted(nums, 0, n - 1);
}

BST* buildPreIn(int pre[], int in[], int* p, int l, int r)
{
    if (l > r) return NULL;

    BST* root = createNode(pre[(*p)++]);
    int i = l;

    while (in[i] != root->data) i++;

    root->left = buildPreIn(pre, in, p, l, i - 1);
    root->right = buildPreIn(pre, in, p, i + 1, r);

    return root;
}

BST* buildTreePreIn(int preorder[], int inorder[], int n)
{
    int p = 0;
    return buildPreIn(preorder, inorder, &p, 0, n - 1);
}

BST* buildInPost(int in[], int post[], int* p, int l, int r)
{
    if (l > r) return NULL;

    BST* root = createNode(post[(*p)--]);
    int i = l;

    while (in[i] != root->data) i++;

    root->right = buildInPost(in, post, p, i + 1, r);
    root->left = buildInPost(in, post, p, l, i - 1);

    return root;
}

BST* buildTreeInPost(int inorder[], int postorder[], int n)
{
    int p = n - 1;
    return buildInPost(inorder, postorder, &p, 0, n - 1);
}

int heightBalanced(BST* root)
{
    if (!root) return 0;

    int l = heightBalanced(root->left);
    int r = heightBalanced(root->right);

    return 1 + (l > r ? l : r);
}

BOOL isBalanced(BST* root)
{
    if (!root) return TRUE;

    if (abs(heightBalanced(root->left) -
            heightBalanced(root->right)) > 1)
        return FALSE;

    return isBalanced(root->left) && isBalanced(root->right);
}

BOOL hasPathSum(BST* root, int targetSum)
{
    if (!root) return FALSE;

    if (!root->left && !root->right)
        return targetSum == root->data ? TRUE : FALSE;

    return hasPathSum(root->left, targetSum - root->data) ||
           hasPathSum(root->right, targetSum - root->data);
}

BST* invertTree(BST* root)
{
    if (!root) return NULL;

    BST* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int diameterAnswer;

int heightDiameter(BST* root)
{
    if (!root) return 0;

    int l = heightDiameter(root->left);
    int r = heightDiameter(root->right);

    if (l + r > diameterAnswer)
        diameterAnswer = l + r;

    return 1 + (l > r ? l : r);
}

int diameterOfBinaryTree(BST* root)
{
    diameterAnswer = 0;
    heightDiameter(root);
    return diameterAnswer;
}

int rangeSumBST(BST* root, int low, int high)
{
    if (!root) return 0;

    if (root->data < low)
        return rangeSumBST(root->right, low, high);

    if (root->data > high)
        return rangeSumBST(root->left, low, high);

    return root->data +
           rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
}
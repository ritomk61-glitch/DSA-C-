#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

struct Node* rightRotate(struct Node* y)
{
    struct Node* x = y->left;
    struct Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* leftRotate(struct Node* x)
{
    struct Node* y = x->right;
    struct Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

int getBalance(struct Node* node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

struct Node* insert(struct Node* node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);

    else if (data > node->data)
        node->right = insert(node->right, data);

    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}
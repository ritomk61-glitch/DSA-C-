#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

struct Node* minValueNode(struct Node* root)
{
    struct Node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder: ");
    inorder(root);

    printf("\nEnter value to search: ");
    scanf("%d", &key);

    if (search(root, key) != NULL)
        printf("Value found\n");
    else
        printf("Value not found\n");

    printf("Enter value to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("After deletion: ");
    inorder(root);

    return 0;
}
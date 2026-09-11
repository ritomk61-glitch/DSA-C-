// *write a program to implement preorder and inorder and postorder travasal in binary tree using c
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node * createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
};

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node * root){
    if(root != NULL){
        inorder(root -> left);
        printf("%d",root -> data);
        preorder(root -> right);
    }
}
void postorder(struct Node * root){
    if(root != NULL){
        postorder(root -> left);
        preorder(root -> right);
        printf("%d",root -> data);
        
    }
}

int main(){
    struct  Node * root = createNode(1);
    root -> left = createNode(2);
    root -> right = createNode(3);


    root->left->left =createNode(4);
    root->right->right=createNode(5);

    printf("preorder:");
    preorder(root);

    printf("\npostorder:");
    postorder(root);

    printf("\ninorder:");
    inorder(root );
    return 0;
}






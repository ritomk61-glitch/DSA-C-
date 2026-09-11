#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode ->data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

int main(){
    struct Node * root = createNode(1);
    root->left = createNode(2);
    root -> right = createNode(3);

    root -> left -> left = createNode(3);
    root -> right -> right = createNode(4);
  
    return 0;

}
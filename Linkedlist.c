#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push Operation
void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack\n", value);
}

// Pop Operation
void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("%d popped from stack\n", top->data);

    top = top->next;
    free(temp);
}

// Display Operation
void display()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements:\n");

    temp = top;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
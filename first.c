#include<stdio.h>

#define MAX 5

int arr
[MAX];
int top = -1;

// !push method

void push(){
     int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter element to push: ");
    scanf("%d", &value);

    top++;
    arr[top] = value;

    printf("%d inserted successfully.\n", value);


}
// ?pop method

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return;
    }

    printf("%d deleted successfully.\n", arr[top]);
    top--;
}

// ?disply method

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty.\n");
        return;
    }

    printf("\nStack Elements are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n**** STACK MENU ****");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Program Terminated.\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
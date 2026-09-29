#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void insert(int value)
{
    if (top == SIZE - 1)
    {
        printf("your stack is empty\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
};

void pop()
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("%d delete from the stack\n", stack[top]);
        top--;
    }
};

void display()
{
    if (top == -1)
    {
        printf("stack is empty.please try again\n");
    }
    else{
        for(int i = top ; i >=0 ; i--){
            printf("value in the stack is %d \n",stack[i]);
        }
    }
};

int main(){
    insert(12);
    insert(22);
    insert(32);

    display();
}
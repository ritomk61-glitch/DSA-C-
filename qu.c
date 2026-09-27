#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;
// insert part
void enqueuee(int value)
{
    if (rear == SIZE - 1)
    {
        printf("your queue is full.\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
            rear++;
            queue[rear] = value;

            // printf("value insert in the queue %d", value);
    }

};

// delete

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("%d deleted from queue\n", queue[front]);
        front++;
    }
}
    // display part

    void display(){
        if (front == -1 || front > rear) {
        printf("queue is emplty\n");
        }
        else {
            printf("queue");
            
            for( int i = front ; i<=rear ; i++){
                printf("inserted value is %d \n",queue[i]);
            }
        }
    }

int main()
{
    enqueuee(44);
    enqueuee(48);
    enqueuee(94);
    enqueuee(64);
    enqueuee(74);
    display();

    dequeue();
    display();

    return 0;
}

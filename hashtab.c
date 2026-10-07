#include <stdio.h>

#define TABLE_SIZE 11

typedef enum { EMPTY, OCCUPIED, DELETED } State;

typedef struct
{
    State state;
    int key;
} HashEntry;

HashEntry table[TABLE_SIZE];

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void initialize(void)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i].state = EMPTY;
        table[i].key = -1;
    }
}

void insert(int key)
{
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int pos = (index + i) % TABLE_SIZE;

        if (table[pos].state == EMPTY ||
            table[pos].state == DELETED)
        {
            table[pos].key = key;
            table[pos].state = OCCUPIED;

            printf("Inserted %d at index %d\n", key, pos);
            return;
        }
    }

    printf("Hash table is full\n");
}

void deleteKey(int key)
{
    int index = hashFunction(key);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int pos = (index + i) % TABLE_SIZE;

        if (table[pos].state == EMPTY)
        {
            printf("%d not found\n", key);
            return;
        }

        if (table[pos].state == OCCUPIED &&
            table[pos].key == key)
        {
            table[pos].state = DELETED;
            printf("Deleted %d from index %d\n", key, pos);
            return; 
        }
    }

    printf("%d not found\n", key);
}

void display(void)
{
    printf("\nHash Table:\n");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i].state == OCCUPIED)
            printf("%d : %d\n", i, table[i].key);
        else if (table[i].state == DELETED)
            printf("%d : DELETED\n", i);
        else
            printf("%d : EMPTY\n", i);
    }
}

int main(void)
{
    initialize();

    insert(25);
    insert(36);
    insert(47);
    insert(18);
    insert(29);

    display();

    deleteKey(36);

    display();

    return 0;
}
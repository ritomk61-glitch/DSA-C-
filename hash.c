#include <stdio.h>

int main()
{
    int hash[10];
    int n, key, index;

    for(int i = 0; i < 10; i++)
    {
        hash[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &key);

        index = key % 10;

        while(hash[index] != -1)
        {
            index = (index + 1) % 10;
        }

        hash[index] = key;
    }

    printf("\nHash Table:\n");

    for(int i = 0; i < 10; i++)
    {
        printf("%d -----> %d\n", i, hash[i]);
    }

    return 0;
}
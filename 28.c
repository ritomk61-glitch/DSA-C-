#include <stdio.h>

int main()
{
    int n, j, i, k;
    int cost[10][10];

    printf("Enter no of routes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    printf("\nDistance vector table:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", cost[i][j]);
        }

        printf("\n");
    }

    return 0;
}
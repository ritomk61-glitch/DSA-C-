// piority queue

#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[10], priority[10], p[10];
    int wt[10], tat[10];
    int temp, time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;

        printf("Enter Burst Time for P%d: ", p[i]);
        scanf("%d", &bt[i]);

        printf("Enter Priority for P%d: ", p[i]);
        scanf("%d", &priority[i]);
    }

    /* Sort according to priority */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(priority[i] > priority[j])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nPriority Scheduling\n");
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        wt[i] = time;
        tat[i] = wt[i] + bt[i];

        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i], bt[i], priority[i], wt[i], tat[i]);

        time = time + bt[i];
    }

    return 0;
}
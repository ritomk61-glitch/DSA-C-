#include <stdio.h>

int main()
{
    int bucket, out, n, packet, i;

    printf("Enter bucket size: ");
    scanf("%d", &bucket);

    printf("Enter output rate: ");
    scanf("%d", &out);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("\nEnter packet size %d: ", i);
        scanf("%d", &packet);

        if(packet > bucket)
        {
            printf("Packet dropped! Bucket overflow.\n");
        }
        else
        {
            printf("Packet accepted: %d\n", packet);

            while(packet > 0)
            {
                if(packet >= out)
                {
                    packet = packet - out;
                    printf("Transmitted: %d\n", out);
                }
                else
                {
                    printf("Transmitted: %d\n", packet);
                    packet = 0;
                }
            }
        }
    }

    return 0;
}

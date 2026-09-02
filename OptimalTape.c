#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int length[100];
    int total = 0;
    int retrieval = 0;
    float average;

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter length of each file:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &length[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (length[i] > length[j])
            {
                temp = length[i];
                length[i] = length[j];
                length[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        retrieval = retrieval + length[i];
        total = total + retrieval;
    }

    average = (float)total / n;

    printf("\nOptimal order: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", length[i]);
    }

    printf("\nTotal Retrieval Time: %d", total);
    printf("\nAverage Retrieval Time: %.2f\n", average);

    return 0;
}
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initialize()
{
    int i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
            printf("Index %d --> %d\n", i, hashTable[i]);
        else
            printf("Index %d --> Empty\n", i);
    }
}

int main()
{
    int n, key, i;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
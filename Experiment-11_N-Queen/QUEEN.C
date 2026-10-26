#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];
int N;
int solutionCount = 0;

int isSafe(int row, int col)
{
    int i;

    for (i = 1; i < row; i++)
    {
        if (board[i] == col)
            return 0;

        if (abs(board[i] - col) == abs(i - row))
            return 0;
    }

    return 1;
}

void printBoard()
{
    int i, j;

    solutionCount++;

    printf("\nSolution %d:\n", solutionCount);

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void NQueen(int row)
{
    int col;

    if (row > N)
    {
        printBoard();
        return;
    }

    for (col = 1; col <= N; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            NQueen(row + 1);
            board[row] = 0;
        }
    }
}

int main()
{
    printf("Enter number of queens (1-%d): ", MAX - 1);
    scanf("%d", &N);

    if (N < 1 || N >= MAX)
    {
        printf("Invalid number of queens.\n");
        return 1;
    }

    NQueen(1);

    if (solutionCount == 0)
        printf("No solution exists.\n");
    else
        printf("\nTotal solutions: %d\n", solutionCount);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_sol(int *board, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", board[i]);
    printf("\n");
}

int abso(int n)
{
    if (n < 0)
        return -n;
    return n;
}

int is_safe(int *board, int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        if (board[i] == row)
            return 0;
//
//DIESE CONDITION AUSWENDIG LERNEN!!
// für diagonal
        if (abso(board[i] - row) == col - i)
            return 0;
    }
    return 1;
}

void solve(int *board, int n, int col)
{
    int row = 0;
    if (col == n)
    {
        print_sol(board, n);
        return ;
    }
    while (row < n)
    {
        if (is_safe(board, col, row))
        {
            board[col] = row;
            solve(board, n, col+1);
        }
        row++;
    }
}

int main(int ac, char **av)
{
    int n = atoi(av[1]);
    int *board = malloc(4 * n);
    solve(board, n, 0);
}
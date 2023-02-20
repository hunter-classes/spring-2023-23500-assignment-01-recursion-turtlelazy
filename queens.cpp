#include <iostream>
#include <string>
#include "queens.h"
/*
int **array;
array = new int *[10];
for(int i = 0; i <10; i++)
    array[i] = new int[10];
void passFunc(int **a)
{
    // ...
}
passFunc(array);
*/

bool addQueen(int r, int c, int **board, int size){
    if (board[r][c] == 0)
    {
        //adding to rook zones
        for (int i = 0; i < size; i++)
        {
            board[i][c]++;
            board[r][i]++;
        }

        for (int i = 0; i < size; i++)
        {
            int y1 = i - c + r;
            int y2 = -i + c + r;

            if (y1 < size && y1 > -1)
            {
                board[y1][i]++;
            }

            if (y2 < size && y2 > -1)
            {
                board[y2][i]++;
            }
        }

        board[r][c] = -1;
        return true;
    }

    return false;
}

void removeQueen(int r, int c, int **board, int size)
{
    if (board[r][c] != -1)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        board[i][c]--;
        board[r][i]--;
    }
    for (int i = 0; i < size; i++)
    {
        int y1 = i - c + r;
        int y2 = -i + c + r;

        if (y1 < size && y1 > -1)
        {
            board[y1][i]--;
        }

        if (y2 < size && y2 > -1)
        {
            board[y2][i]--;
        }
    }
    board[r][c] = 0;
}



bool solve(int **board, int size, int col)
{
    if (col == size)
    {
        return true;
    }

    for (int i = 0; i < size; i++)
    {
        bool currentSolveIter;
        if (addQueen(i, col, board, size))
        {
            currentSolveIter = solve(board, size, col + 1);
            if (currentSolveIter)
            {
                return true;
            }
            else
            {
                removeQueen(i, col, board, size);
            }
        }
    }
    return false;
}

bool solve(int **board, int size)
{

    return solve(board, size, 0);
}

std::string toString(int **board, int size)
{
    std::string return_string = "";
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            //std::cout << board[r][c] << " ";

            if(board[r][c] != -1){
                return_string += ".";
            }
            else{
                return_string += "Q";
            }
        }
        //std::cout << "\n";
        return_string += "\n";
    }



    return return_string;
}

std::string solve_queens(int queens){
    int **board;
    board = new int *[queens];
    for (int i = 0; i < queens; i++)
        board[i] = new int[queens];

    solve(board,queens);

    return toString(board,queens);
}
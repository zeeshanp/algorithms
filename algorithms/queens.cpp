//Verifies that a board is a solution to the N-queens problem

#include <iostream>
using namespace std;

bool duplicates(int* row, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (row[i] == row[j])
                return true;
        }
    }
    return false;
}

bool isBoardValid(char **board, int n)
{
    //row list, which row everyone is in (from column 1 to n)
    //rows[5] = 7 means in the 5th column, it is in row 7 
    int rows[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            if (board[i][j] == '*')
            {
                if (count == 0)
                {
                    rows[i] = j;
                    count++;
                }
                else
                    return false;
            }
        }
    }
    
    if (duplicates(int* row, int n)
    {
        return false;
    }

    //check diagonals
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if ( (rows[j] - rows[i]) == (j - i) )
                return false; 
        }
    }

    return true;

}


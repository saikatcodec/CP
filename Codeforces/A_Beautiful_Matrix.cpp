#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int mat[5][5];
    int row, col;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                row = i;
                col = j;
            }
        }
    }

    int minPos = abs(row - 2) + abs(col - 2);
    cout << minPos << endl;

    return 0;
}
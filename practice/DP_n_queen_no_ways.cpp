#include <bits/stdc++.h>
using namespace std;

bool safePos(int board[][20], int n, int i, int j) {
    for (int k = i - 1; k >= 0; k--) {
        if (board[k][j] == 1) {
            return false;
        }
    }

    int x = i - 1, y = j - 1;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--, y--;
    }

    x = i - 1, y = j + 1;
    while (x >= 0 && y < n) {
        if (board[x][y] == 1) {
            return false;
        }
        x--, y++;
    }

    return true;
}

int solveNQueen(int board[][20], int n, int i) {
    // Base Case
    if (i == n) {
        return 1;
    }

    // Recursive Case
    int ways = 0;
    for (int j = 0; j < n; j++) {
        if (safePos(board, n, i, j)) {
            board[i][j] = 1;
            ways += solveNQueen(board, n, i + 1);
            board[i][j] = 0;
        }
    }
    return ways;
}

int main() {
    int board[20][20] = {0};
    int n;
    cin >> n;

    cout << "No. Ways: " << solveNQueen(board, n, 0) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void printBoard(int board[][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

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

bool solveNQueen(int board[][20], int n, int i) {
    // Base Case
    if (i == n) {
        printBoard(board, n);
        return true;
    }

    // Recursive Case
    for (int j = 0; j < n; j++) {
        if (safePos(board, n, i, j)) {
            board[i][j] = 1;
            bool success = solveNQueen(board, n, i + 1);
            if (success) {
                return true;
            }

            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int board[20][20] = {0};
    int n;
    cin >> n;

    solveNQueen(board, n, 0);

    return 0;
}
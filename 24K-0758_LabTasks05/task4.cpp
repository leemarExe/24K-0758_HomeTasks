#include <iostream>
using namespace std;

int solutionCount = 0;

void printBoard(int board[20][20], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[20][20], int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueens(int board[20][20], int row, int N, bool firstSolutionPrinted) {
    if (row == N) {
        solutionCount++;
        if (!firstSolutionPrinted) {
            cout << "One valid solution:\n";
            printBoard(board, N);
            firstSolutionPrinted = true;
        }
        return firstSolutionPrinted;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            firstSolutionPrinted = solveNQueens(board, row + 1, N, firstSolutionPrinted);
            board[row][col] = 0;
        }
    }
    return firstSolutionPrinted;
}

int main() {
    int N;
    cout << "Enter the size of the ChessBoard.\n";
    cin >> N;
    int board[20][20] = {0};
    bool firstPrinted = solveNQueens(board, 0, N, false);
    cout << "Total number of distinct solutions: " << solutionCount << endl;
    return 0;
}

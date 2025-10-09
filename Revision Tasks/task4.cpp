/* If no safe route exists, the recursive function keeps returning false up the call chain.
The line that makes backtracking possible is:
arr[x][y] = 0; return false;
The final output (after calling print(arr)) will show all zeros, since no path was found.*/

#include<iostream>
using namespace std;

#define N 4

int grid [N][N] = {{1, 1, 0, 1}, 
                   {0, 1, 1, 0},
                   {1, 1, 0, 1},
                   {0, 1, 1, 1}};

bool isSafe(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 1);
}
bool move(int x, int y, int arr[N][N]){
    if(x == N - 1 && y == N - 1){
        arr[x][y] = 1;
        return true;
    }

    if(isSafe(x, y)){
        arr[x][y] = 1;
        if(move(x + 1, y, arr)){
            return true;
        }
        if(move(x, y + 1, arr)){
            return true;
        }
        arr[x][y] = 0;
        return false;
    }
    return false;
}

void print(int arr[N][N]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int arr[N][N] = {0};
    move(0,0, arr);
    print(arr);
}
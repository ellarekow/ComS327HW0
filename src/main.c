#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int solver(int x, int y, int index, int sol[SIZE][SIZE], int moveX[], int moveY[]);

//Checks valid indexes
bool safe(int row, int col, int board[SIZE][SIZE]){
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == -1)
        return true;

    else
        return false;
} 

void print(int sol[SIZE][SIZE]){
    for(int row = 0; row < SIZE; row++){
        for(int column = 0; column < SIZE; column++){
            printf(" %2d ", sol[row][column]);
        }
        printf("\n");
    }
}

bool solve(){
    int sol[SIZE][SIZE];

    for(int row = 0; row < SIZE; row++){
        for(int column = 0; column < SIZE; column++){
            sol[row][column] = -1;
        }
    }

    int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    sol[0][0] = 0;

    if(solver(0, 0, 1, sol, x, y) == 0){
        printf("Solution does not exsist \n");
        return false;
    }

    else
        print(sol);

    return true;
}

int solver(int x, int y, int index, int sol[SIZE][SIZE], int moveX[8], int moveY[8]){
    int nextX;
    int nextY;

    if(index == SIZE * SIZE){
        return 1;
    }

    for(int i = 0; i < SIZE; i++){
        nextX = x + moveX[i];
        nextY = y + moveX[i];

        if(safe(nextX, nextY, sol)){
            sol[nextX][nextY] = index;

            if(solver(nextX, nextY, index + 1, sol, moveX, moveY) == 1)
                return 1;

            else
                sol[nextX][nextY] = -1;
        }
    }

    return 0;
}


int main(){

    solve();

    return 0;
}
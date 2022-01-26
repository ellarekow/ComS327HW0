#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

FILE *fileprinter;

int solver(int x, int y, int index, int sol[SIZE][SIZE], int moveX[8], int moveY[8], int solOrder[SIZE * SIZE]);

//Checks valid indexes
bool safe(int row, int col, int board[SIZE][SIZE]){
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == -1);
} 

void printBoard(int sol[SIZE][SIZE]){
    for(int row = 0; row < SIZE; row++){
        for(int column = 0; column < SIZE; column++){
            printf(" %2d ", sol[row][column]);
        }
        printf("\n");
    }
}

void printSolution(int sol[SIZE * SIZE]){
    fprintf(fileprinter, "%d", sol[0]);
    int i;
    for(i = 1; i < (SIZE * SIZE); i++){
        fprintf(fileprinter, ",%d", sol[i]);
    }
    fprintf(fileprinter, "\n");
}

bool solve(){
    int sol[SIZE][SIZE];
    int solOrder[SIZE * SIZE];

    int row, row1;
    int column, column1; 


    int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for(row = 0; row < SIZE; row++){
        for(column = 0; column < SIZE; column++){
            for(row1 = 0; row1 < SIZE; row1++){
                for(column1 = 0; column1 < SIZE; column1++){
                    sol[row1][column1] = -1;
                }
            }
            solOrder[0] = (row * SIZE) + column;
            sol[row][column] = 0;

            solver(row, column, 1, sol, x, y, solOrder);
        }
    }

    return true;
}

int solver(int x, int y, int index, int sol[SIZE][SIZE], int moveX[8], int moveY[8], int solOrder[SIZE * SIZE]){
    int nextX;
    int nextY;
    

    if(index == SIZE * SIZE){
        printSolution(solOrder);
        return 1;
    }

    int i;
    for(i = 0; i < 8; i++){
        nextX = x + moveX[i];
        nextY = y + moveY[i];

        if(safe(nextX, nextY, sol)){
            sol[nextX][nextY] = index;
            solOrder[index] = (nextY * SIZE) + 1 + nextX;

            solver(nextX, nextY, index + 1, sol, moveX, moveY, solOrder);
            sol[nextX][nextY] = -1;
        }
    }

    return 0;
}


int main(){
    fileprinter = fopen("outputs.txt", "w");

    if(fileprinter == NULL){
        printf("COULDN'T OPEN FILE");
        return 1;
    }
    solve();

    fclose(fileprinter);

    return 0;
}
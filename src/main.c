#include <stdio.h>

#define SIZE 5
int BOARD[SIZE][SIZE];

void boardGenerator(){
    int i = 1;
    for(int row = 0; row < SIZE; row++){
        for(int column = 0; column < SIZE; column++){
            BOARD[row][column] = i;
            i++;
        }
    }
}

int main(){
    boardGenerator();

    for(int row = 0; row < SIZE; row++){
        for(int column = 0; column < SIZE; column++){
            printf("%d ", BOARD[row][column]);
        }
        printf("\n");
    }

    return 0;
}
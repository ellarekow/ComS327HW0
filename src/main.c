#include <stdio.h>

#define SIZE 5
int BOARD[SIZE][SIZE];

void boardGenerator(){
    int i = 0;
    for(int row = 0; row < SIZE; row++){
        for(int column = 0; column < SIZE; row++){
            BOARD[row][column] = i;
            i++;
        }
    }
}

void main(){
    for(int row = 0; row < SIZE; row++){
        for(int column = 0; column < SIZE; row++){
            printf("%d ", BOARD[row][column]);
        }
        printf("\n");
    }
}
#include<stdio.h>
#include<stdbool.h>

#include "../include/board.h"

int main()
{
    extern struct msboard msb[BOARDSIZE][BOARDSIZE];
    int ue=0;
    initializeboard(&ue);
    ue = BOARDSIZE*BOARDSIZE - ue;
    int x,y;
    char action;
    while(1)
    {
        displayboard();
        printf("Enter row number, column number and action ('O' to open, 'F' to flag) : ");
        scanf("%d %d %c",&x,&y,&action);
        changeboard(x-1,y-1,action, &ue);
    }
}

#include<stdio.h>
#include<stdlib.h>
#include"../include/board.h"
#include<time.h>

#define MODVALUE 3
#define MODNO BOARDSIZE/2

void opensurrounding(int, int, int, int*);

void changeboard(int x, int y, char action, int *ue){
    extern struct msboard msb[BOARDSIZE][BOARDSIZE];

    srand(time(NULL));
    int rkey = rand() % MODVALUE;
    int bopens, openno;

    if(action=='O'){
        if(msb[x][y].status == 'O')
            printf("Already opened/flagged. Choose again. \n");
        else if(msb[x][y].status == 'F'){
            printf("Toggled");
            msb[x][y].status = 'O';
        }
        else{
            if(msb[x][y].bomb){
                printf("Oh! You stepped on a bomb. Game over. Sorry.");
                exit(0);
            }
            else{
                msb[x][y].status = 'O';
                bopens = rand() % MODVALUE;
                if(bopens == rkey){
                    openno = rand() % MODNO;
                    opensurrounding(x,y,openno, ue);
                }
                *ue -= 1;
            }
        }
    }
    else if(action=='F'){
        if(msb[x][y].status == 'F')
            printf("Already flagged/opened. Choose again. \n");
        else{
            msb[x][y].status='F';
            *ue -= 1;
        }
    }
    if(*ue <= 0){
        printf("You won !");
        exit(0);
    }
}

void opensurrounding(int x, int y, int openno, int* ue){
    printf("Opening a few more ! \n");
    int k, hmov, vmov;
    srand(time(NULL));
    for(k=0;k<openno;k++){
        hmov = (rand() % 3) - 1;
        vmov = (rand() % 3) - 1;
        x += hmov;
        y += vmov;

        if(x < BOARDSIZE && x >= 0){
            if(y < BOARDSIZE && y >= 0){
                if(msb[x][y].status == 'C'){
                    msb[x][y].status = 'O';
                    *ue -= 1;
                }
            }
            else{
            y -= hmov;
            }
        }
        else{
            x -= hmov;
        }
    }
}

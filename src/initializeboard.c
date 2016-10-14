#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

#include"../include/board.h"

int maxi(int, int);
int mini(int, int);

void initializeboard(int *ue){
    extern struct msboard msb[BOARDSIZE][BOARDSIZE];
    int i,j,k,l;
    srand(time(NULL));
    for(i=0;i<BOARDSIZE;i++){
        for(j=0;j<BOARDSIZE;j++){
            msb[i][j].status = 'C';
            msb[i][j].no = 0;
        }
    }

    for(i=0;i<BOARDSIZE;i++){
        for(j=0;j<BOARDSIZE;j++){
            msb[i][j].bomb = (rand()%7 == 1);

            if(msb[i][j].bomb){
                *ue += 1;
                for(k=maxi(0,i-1);k<=mini(BOARDSIZE-1,i+1);k++){
                    for(l=maxi(0,j-1);l<=mini(BOARDSIZE-1,j+1);l++){
                        if(i!=k || j!=l)
                            msb[k][l].no += 1;
                    }
                }
            }

        }
    }
}

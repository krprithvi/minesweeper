#include<stdio.h>
#include<stdlib.h>
#include"../include/board.h"

void displayboard(){
    extern struct msboard msb[BOARDSIZE][BOARDSIZE];
    int i,j;
    // Creating a dashed line
    int hds = BOARDSIZE*4 + 1;
    char *horizontaldash = (char *) malloc(sizeof(char)*hds);
    for(i=0;i<hds;i++)
        horizontaldash[i]='-';

    for(i=0;i<BOARDSIZE;i++){
        printf("%s\n", horizontaldash);
        for(j=0;j<BOARDSIZE;j++){
            if(msb[i][j].status == 'C')
                printf("| ? ");
            else if(msb[i][j].status == 'O')
                if(msb[i][j].bomb)
                    printf("| * ");
                else
                    printf("| %d ", msb[i][j].no);
            else
                printf("| F ");
        }
        printf("|\n");
    }
    printf("%s\n", horizontaldash);
}

#include<stdbool.h>
#define BOARDSIZE 5

struct msboard {
    char status;
    unsigned int bomb:1;
    int no;
};

struct msboard msb[BOARDSIZE][BOARDSIZE];

void initializeboard(int*);
void displayboard();
void changeboard(int, int, char, int*);

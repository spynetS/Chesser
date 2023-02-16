#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "render.h"

char* fen = "rnbqkbnr/pppppppp/8/8/8/5z2/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
/* char* fen = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"; */
int hover = 0;
int selected = 0;
int* cursor = &hover;

int main(int argc, char** argv){
    if(argc > 1){
        render(argv[1], *cursor, selected);
    }
    else{
        while(1){
            msleep(50);
            system("clear");
            if(kbhit()){
                char c = getchar();
                if(c == 'd' ) (*cursor)++;
                if(c == 'a' ) (*cursor)--;
                if(c == 's' ) (*cursor)+=9;
                if(c == 'w' ) (*cursor)-=9;
                if(c == '\n') selected = *cursor;
            }
            render(fen, *cursor, selected);
            printf("\n");
        }
    }

    return 0;
}


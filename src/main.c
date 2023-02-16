#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "render.h"
#include "msc.h"

char* fen = "rnbqkbnr/pppppppp/00000000/00000000/00000000/00000z00/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
/* char* fen = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"; */

int hover = 0;
int selected = 0;
int* cursor = &hover;
int validMoves[10];

char* parseFen(char* fen){
    char* newFen = malloc(sizeof(char)*80);
    int nfeni = 0;
    for(int i = 0; i < strlen(fen); i++){
        char c = fen[i];
        int a = (int)c - '0';
        if(a > 0 && a < 9){
            for(int j = 0;j < a; j++){
                newFen[nfeni] = '0';
                nfeni++;
            }
            continue;
        }
        else{
            newFen[nfeni] = fen[i];
        }
        nfeni++;
    }
    return newFen;
}

int main(int argc, char** argv){
    validMoves[0] = 20;
    if(argc > 1){
        fen = parseFen(argv[1]);
        render(fen, *cursor, selected);
    }
    else{
        while(1){
            msleep(50);
            system("clear");
            if(kbhit()){
                char c = getchar();
                if(c == 'd' ) (*cursor)++;
                if(c == 'a' ) (*cursor)--;
                if(c == 's' ) (*cursor)+=8;
                if(c == 'w' ) (*cursor)-=8;
                if(c == '\n') {

                    selected = *cursor;
                }
            }
            render(fen, *cursor, selected);
            printf("\n");
        }
    }

    free(fen);
    return 0;
}


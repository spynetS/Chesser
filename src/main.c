#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "render.h"

/* char* fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"; */
char* fen = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";

struct piece{
    int pos;
    char t;
};


int main(int argc, char** argv){
    if(argc > 1){
        render(argv[1]);
    }
    else{
        render(fen);
    }

    return 0;
}


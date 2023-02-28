#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "render.h"
#include "msc.h"
#include "flagser.h"
#include "board.h"

int timew = 1000;
int timeb = 1000;

void makeMove(){
    for(int i = 0; i < strlen(fen); i++){
        if(!isWhite(getPiece(i))){

            setValidMoves(i);

            if(pieceInValid(i+9)){
                move(i,i+9);
                clearValidMoves();
                break;
            }
            clearValidMoves();
        }
    }
}

void renderFen(int argc, char** args){
    render(parseFen(args[1]),0,0,validMoves, timew, timeb);
}

void runChess(){
    while(1){
        msleep(100);
        // decrease time
        if(getTurn() == 'w'){
            timew --;
        }else{
            timeb --;
        }

        if(timew <= 0){
            system("clear");
            printf("Black won on time");
            break;
        }
        if(timeb <= 0){
            system("clear");
            printf("White won on time");
            break;
        }

        system("clear");
        if(kbhit()){
            char c = getchar();
            if(c == 'd' ) (hover)++;
            if(c == 'a' ) (hover)--;
            if(c == 's' ) (hover)+=9;
            if(c == 'w' ) (hover)-=9;
            if(c == '\n') {
                if(selected == 100 && getColor(hover) == getTurn()){
                    selected = hover;
                    setValidMoves(selected);
                }
                //move selected piece
                else if (pieceInValid(hover)){
                    move(selected, hover);
                }
                else if(getColor(hover) == getTurn()){
                    clearValidMoves();
                    selected = hover;
                    setValidMoves(selected);
                }
            }
            if(c == 'q'){
                system("clear");
                printf("%s\n",fen);
                printf("%s\n",getFen(fen));
                break;
            }
        }
        render(fen, hover, selected, validMoves, timew, timeb);
        printf("\n");
    }
}

int main(int argc, char** argv){
    clearValidMoves();
    addFlag("-r", "--render", "will render a fen", renderFen);
    addHelp();

    int flagsFound = parse(argc, argv);
    if(flagsFound == 0) runChess();

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "render.h"
#include "msc.h"
#include "flagser.h"
#include "board.h"

int hover = 66;
int selected = 100;
int* cursor = &hover;

int timew = 1000;
int timeb = 1000;

// calculates the moves that are legal and add them to the calidMoves array
void setValidMoves(int index){
    char p = getPiece(index);
    for(int i = 0; i < strlen(fen); i++){
        if(p == 'p'){
            if(index+9  == i && getPiece(i) == '0') addValidMove(i);
            // and that pos is not empty and it is not our color
            if(index+8  == i && getPiece(i) != '0' && isWhite(i)) addValidMove(i);
            if(index+10 == i && getPiece(i) != '0' && isWhite(i)) addValidMove(i);
        }
        if(p == 'P'){
            if(index-9  == i && getPiece(i) == '0') addValidMove(i);
            if(index-8  == i && getPiece(i) != '0' && !isWhite(i)) addValidMove(i);
            if(index-10 == i && getPiece(i) != '0' && !isWhite(i)) addValidMove(i);
        }
        if(p == 'Q'){
            if(i == index){
                for(int j = 1; j < 10 ; j++){
                    int pos = i-(9*j);
                    if(getPiece(pos) != '0'){
                        break;
                    }
                    addValidMove(pos);
                }
                for(int j = 1; j < 10 ; j++){
                    int pos = i+(9*j);
                    addValidMove(pos);
                    if(getPiece(pos) != '0'){
                        break;
                    }
                }
            }
        }
    }
}

void renderFen(int argc, char** args){
    render(parseFen(args[1]),0,0,validMoves, timew, timeb);
}

void runChess(){
    while(1){
        msleep(50);
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
            if(c == 'd' ) (*cursor)++;
            if(c == 'a' ) (*cursor)--;
            if(c == 's' ) (*cursor)+=9;
            if(c == 'w' ) (*cursor)-=9;
            if(c == '\n') {
                if(selected == 100 && getColor(*cursor) == getTurn()){
                    selected = *cursor;
                    setValidMoves(selected);
                }
                //move selected piece
                else if (pieceInValid(*cursor)){
                    setPiece(*cursor,getPiece(selected));

                    setPiece(selected,'0');
                    selected = 100;

                    clearValidMoves();

                    // mv cursor to oponents side
                    if(getTurn()=='w')
                        hover = 12;
                    else
                        hover = 57;

                    changeTurn();
                }
                else if(getColor(*cursor) == getTurn()){
                    clearValidMoves();
                    selected = *cursor;
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
        render(fen, *cursor, selected, validMoves, timew, timeb);
        printf("\n");
    }
}

int main(int argc, char** argv){
    addFlag("-r", "--render", "will render a fen", renderFen);
    addHelp();

    int flagsFound = parse(argc, argv);
    if(flagsFound == 0) runChess();

    return 0;
}


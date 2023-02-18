#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include<ctype.h>


char fen[] = "rnbqkbnr/pppppppp/00000000/00000000/00000000/00000000/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
int validMoves[100];
int validMoveIndex = 0;

char getTurn(){
    for(int i = 0; i < strlen(fen); i++){
        char c = fen[i];
        if(c == ' '){
            return fen[i+1];
        }
    }
    return 'w';
}
void changeTurn(){
    for(int i = 0; i < strlen(fen); i++){
        char c = fen[i];
        if(c == ' '){
            if(fen[i+1] == 'w'){
                fen[i+1] = 'b';
            }
            else if(fen[i+1] == 'b'){
                fen[i+1] = 'w';
            }
            break;
        }
    }
}

int isWhite(int index){
    return isupper(getPiece(index));
}
char getColor(int index){
    if(isWhite(index)) return 'w';
    return 'b';
}
void addValidMove(int index){
    validMoves[validMoveIndex] = index;
    validMoveIndex++;
}
void clearValidMoves(){
    for(int i = 0; i < validMoveIndex; i++){
        validMoves[i] = 100;
    }
    validMoveIndex = 0;
}
//returns 1 if the argument index is inside the valid moves list
int pieceInValid(int index){
    for(int i = 0; i < 100; i++){
        if(index == validMoves[i]){
            return 1;
        }
    }
    return 0;
}

void setPiece(int index, char v){
    fen[index] = v;
}
char getPiece(int index){
    return fen[index];
}


// returns a long fen from a fen
char* parseFen(char* fen){
    // allocats new fen string
    char* newFen = malloc(sizeof(char)*80);

    int nfeni = 0; // index fornew string
    for(int i = 0; i < strlen(fen); i++){
        char c = fen[i];
        // if a is a number etween 0-9 we add a 0
        int a = (int)c - '0';
        if(a > 0 && a < 9){
            for(int j = 0;j < a; j++){
                newFen[nfeni] = '0';
                nfeni++;
            }
            continue;
        }
        // else we just add the piece
        else{
            newFen[nfeni] = fen[i];
        }
        nfeni++;
    }
    return newFen;
}
//retuns normal fen from long fen
char* getFen(char* longfen){
    // new fen string
    char* newFen = malloc(sizeof(char)*80);
    // new fen string index
    int nfeni = 0;
    // keep track of how many empty
    int index = 0;
    for(int i = 0; i < strlen(longfen); i++){
        char c = longfen[i];
        // if we encounter empty string we start counting
        if(c == '0'){
            index++;
            continue;
        }
        // if the char is not empty and the index is > 0
        // we add the index and go back a step
        else{
            if(index > 0){
                newFen[nfeni] = index+'0';
                index=0;
                i--;
            }
            else{
                newFen[nfeni] = fen[i];
            }
        }
        nfeni++;
    }
    return newFen;
}


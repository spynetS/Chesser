#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "render.h"
#include "msc.h"

// a long fen is a fen with all the positions occupues (empy place is 0)

char fen[] = "rnbqkbnr/pppppppp/00000000/00000000/00000000/00000000/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

int hover = 0;
int selected = 100;
int* cursor = &hover;
int validMoves[100];

//returns 1 if the argument index is inside the valid moves list
int pieceInValid(int index){
    for(int i = 0; i < 100; i++){
        if(validMoves[i] !=NULL && index == validMoves[i]){
            return 1;
        }
    }
    return 0;
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

void setPiece(int index, char v){
    fen[index] = v;
}
char getPiece(int index){
    return fen[index];
}
// calculates the moves that are legal and add them to the calidMoves array
void setValidMoves(int index){
    char p = getPiece(index);
    for(int i = 0; i < strlen(fen); i++){
        if(p == 'p'){
            if(index+9 == i) validMoves[0] = i;
        }
        if(p == 'P'){
            if(index-9 == i && getPiece(i)!='p') validMoves[0] = i;
        }
    }
}

int main(int argc, char** argv){
    if(argc > 1){
        printf("%s\n", argv[1]);
        strcpy(fen, parseFen(argv[1]));
        printf("%s\n", fen);
        printf("%s\n", getFen(fen));
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
                if(c == '\n') {
                    if(selected == 100){
                        selected = *cursor;
                        setValidMoves(selected);
                    }
                    else if (pieceInValid(*cursor)){
                        setPiece(*cursor,getPiece(selected));
                        validMoves[0] = NULL;
                        setPiece(selected,'0');
                        selected = 100;
                    }
                    else{
                        selected = *cursor;
                        setValidMoves(selected);
                    }
                }
                if(c == 'q'){
                    system("clear");
                    printf("%s\n",fen);
                    printf("%s\n",getFen(fen));
                    return 0;
                }
            }
            render(fen, *cursor, selected, validMoves);
            printf("\n");
        }
    }
    
    return 0;
}


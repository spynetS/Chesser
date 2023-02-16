#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "render.h"
#include "msc.h"

char fen[] = "rnbqkbnr/pppppppp/00000000/00000000/00000000/00000000/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

int hover = 0;
int selected = 100;
int* cursor = &hover;

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

char* getFen(char* longfen){
    char* newFen = malloc(sizeof(char)*80);
    int nfeni = 0;
    int index = 0;
    for(int i = 0; i < strlen(longfen); i++){
        char c = longfen[i];
        if(c == '0'){
            index++;
            continue;
        }
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
    int ii = 0;
    for(int i = 0; i < strlen(fen); i++){
        if(index == ii) fen[i] = v;
        ii++;
    }
}
char getPiece(int index){
    int ii = 0;
    for(int i = 0; i < strlen(fen); i++){
        if(index == ii) return fen[i];
        ii++;
    }
    return '0';
}

void setValidMoves(int index){
    for(int i = 0; i < strlen(fen); i++){
        if(index+9 == i) fen[i] = 'z'; 
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
                    else if (getPiece(*cursor)=='z'){
                        setPiece(*cursor,getPiece(selected));
                        setPiece(selected,'0');
                        selected = 100;
                    }
                }
                if(c == 'q'){
                    system("clear");
                    printf("%s\n",fen);
                    printf("%s\n",getFen(fen));
                    return 0;
                }
            }
            render(fen, *cursor, selected);
            printf("\n");
        }
    }
    
    return 0;
}


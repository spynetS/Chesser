#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

#define BLACK    "\x1b[30m"
#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW   "\x1b[33m"
#define BLUE     "\x1b[34m"
#define MAGENTA  "\x1b[35m"
#define CYAN     "\x1b[36m"
#define WHITE    "\x1b[37m"
#define RESET    "\x1b[0m"
#define SELECTED "\x1b[44m"
#define VALID    "\x1b[43m"
#define BOLD     "\033[1m"

//prints the right char from the long fen
int printP(char c, int i, int pos){
    printf(BLACK);
    if(c == 'r'){
        printf("♜");
        return 1;
    }
    else if(c == 'n'){
        printf("♞");
        return 1;
    }
    else if(c == 'b'){
        printf("♝");
        return 1;
    }
    else if(c == 'q'){
        printf("♛");
        return 1;
    }
    else if(c == 'k'){
        printf("♚");
        return 1;
    }
    else if(c == 'p'){
        printf("♟︎");
        return 1;
    }
    else if(c == 'P'){
        printf("♙");
        return 1;
    }
    else if(c == 'R'){
        printf("♖");
        return 1;
    }
    else if(c == 'N'){
        printf("♘");
        return 1;
    }
    else if(c == 'B'){
        printf("♗");
        return 1;
    }
    else if(c == 'Q'){
        printf("♕");
        return 1;
    }
    else if(c == 'K'){
        printf("♔");
        return 1;
    }
    else if(c == 'z'){
        printf("#");
        return 1;
    }
    else if(c == '0'){
        printf("  "); 
        return 0;
    }
    else return 0;
        
}
void drawBg(int i){
    //draws the black and white board 
    if(i % 2 != 0){
        printf("\x1b[42m");
    }
    else{
        printf("\x1b[47m");
    }
}
void render(char* fen, int pos, int selected, int* validMoves){
    for(int i = 0; i < strlen(fen); i++){
        char c = fen[i];

        printf(BOLD);
        drawBg(i);
        // render valid moves 
        for(int j = 0; j < 100; j ++){
            if(validMoves[j] == i){
                printf(VALID);
            }
        }
        // draws the cursor and the selected piece
        if(i == pos) printf(SELECTED);
        if(i == selected) printf(YELLOW);

        // we break the render loop when we fins w and ' ' and b in the next char
        if(fen[i+1] == 'w' | (c == ' ' && fen[i+1] == 'b')) break;
        // render pieces
        if(!printP(c,i, pos)){
            if(c == '/') {
                if(i == 8)
                    printf("%cs turn",getTurn());
                if(i == 17)
                    printf("Whites time: %d",10);
                if(i == 26)
                    printf("Blacks time: %d",10);

                printf("\n");
            }
        }
        else{
            // to make the chars squares 
            printf(" ");
        }
        printf(RESET);
    }
        printf(RESET);
}

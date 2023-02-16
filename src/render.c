#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK   "\x1b[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define RESET   "\x1b[0m"
#define SELECTED   "\x1b[44m"
#define VALID   "\x1b[43m"

//prints the right char from the long fen
int printP(char c, int i, int pos){
    printf(RED);
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
        printf(" "); 
        return 0;
    }
    else return 0;
        
}

void render(char* fen, int pos, int selected, int* validMoves){

    for(int i = 0; i < strlen(fen); i++){
        char c = fen[i];
        //draws the black and white board 
        if(i % 2 == 0){
            printf("\x1b[40m");
        }
        else{
            printf("\x1b[47m");
        }
        // draws the cursor and the selected piece
        if(i == pos) printf(SELECTED);
        if(i == selected) printf(YELLOW);
        // render valid moves 
        for(int j = 0; j < sizeof(int)*100; j ++){
            if(validMoves[j]!=NULL && validMoves[j] == i){
                printf(VALID);
            }
        }

        // we break the render loop when we fins w and ' ' and b in the next char
        if(fen[i+1] == 'w' | (c == ' ' && fen[i+1] == 'b')) break;
        // render pieces
        if(!printP(c,i, pos)){
            if(c == '/') {
                printf("\n");
            }
        }
        printf(RESET);
    }
        printf(RESET);
}

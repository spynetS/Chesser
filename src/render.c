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

int printP(char c){
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
    else return 0;
        
}
int printEmpty(char c,int* prev, int pos, int selected){
    int len = (int)c - '0'; 
    for(int i = 0; i < len;i++){
        printf(".");
    }
    return len;
}
void render(char* fen, int pos, int selected){
    for(int i = 0; i < strlen(fen); i++){
        char c = fen[i];

        if(i == pos) printf(RED);
        if(i == selected) printf(YELLOW);

        if(fen[i+1] == 'w' | (c == ' ' && fen[i+1] == 'b')) break;
        if(!printP(c)){
            if(c == '/') printf("\n");
            else {
                printEmpty(c ,&i ,pos ,selected);
            }
        }
        printf("%s", "\x1b[0m");
    }
}

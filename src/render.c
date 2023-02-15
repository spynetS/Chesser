#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    else return 0;
        
}
void printEmpty(char c){
    int len = (int)c - '0'; 
    for(int i = 0; i<len;i++){
        printf(" ");
    }
}
void render(char* fen){
    for(int i = 0; i < strlen(fen); i++){
        char c = fen[i];
        if(fen[i+1] == 'w' | (c == ' ' && fen[i+1] == 'b')) break;
        if(!printP(c)){
            if(c == '/') printf("\n");
            else printEmpty(c);
        }
    }
        
}

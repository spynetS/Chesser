
extern char fen[100];//= "rnbqkbnr/pppppppp/00000000/00000000/00000000/00000000/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

extern int validMoves[100];

char getTurn();

void addValidMove(int index);

void clearValidMoves();
//returns 1 if the argument index is inside the valid moves list
int pieceInValid(int index);
// returns a long fen from a fen
char* parseFen(char* fen);
//retuns normal fen from long fen
char* getFen(char* longfen);

void setPiece(int index, char v);

char getPiece(int index);

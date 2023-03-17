
extern char fen[100];//= "rnbqkbnr/pppppppp/00000000/00000000/00000000/00000000/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

extern int validMoves[100];

extern int hover;
extern int selected;

void setValidMoves(int index);
void setSelected(int index);
void move(int from, int to);
void checkHor(int index);
void checkVert(int index);
void checkDiagonaly(int index);

int isSameColor(int index, int index2);
char getTurn();

char getColor(int index);

int isWhite(int index);

void setFen(char* newFen);

void changeTurn();

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

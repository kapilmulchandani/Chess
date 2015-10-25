typedef enum
{
	empty,
	white,
	black
}
colour;

typedef enum
{
	false,
	true
}
condition;

typedef enum 
{
	none,
	pawn,
	rook,
	knight,
	bishop,
	king,
	queen
}
piece;

typedef struct
{
	piece Piece;	
	colour Colour;
	
}
piecol;

typedef struct
{
	int X;
	int Y;
}
Coordinates;

typedef struct
{
	Coordinates From;
	Coordinates To;
}
Move;

typedef struct
{
	condition CastleLeft;
	condition CastleRight;
}
Castling;

typedef struct
{
	Castling White;
	Castling Black;
	Coordinates LastMove;
	colour Turn;
}
GameData;


extern GameData Gamestate;
void DrawBoard(piecol*[8][8]);
Move GetMove(piecol*[8][8]);
Coordinates GetInput();
Coordinates GetToCoords(piecol*[8][8]);
Coordinates GetFromCoords(piecol*[8][8]);
int ConvertLetterToNumber(char);
int ValidCoords(char, int);
void SetupBoard(piecol*[8][8]);
void CreateBoard(piecol*[8][8]);
void MovePiece(Move*, piecol*[8][8]);
void TakeTurn(piecol*[8][8]);
void NextTurn();
int KnightMove(Move*);

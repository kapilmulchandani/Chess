#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chess.h"

GameData Gamestate;

void TakeTurn(piecol *Board[8][8])
{
	GetMove(Board);
	NextTurn();
}

void NextTurn()
{

	if (Gamestate.Turn == white)
	{
		Gamestate.Turn = black;
	}
	else
	{
		Gamestate.Turn = white;
	}
}


void CreateBoard(piecol *Board[8][8])
{
	Gamestate.White.CastleLeft	=
	Gamestate.White.CastleRight	=
	Gamestate.Black.CastleLeft	=
	Gamestate.Black.CastleRight	= false;
	Gamestate.Turn = white;
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			Board[i][j] = malloc(sizeof(piecol));
		}
	}
}


void SetupBoard(piecol *Board[8][8])
{
	int x, y;

	for (y = 0; y < 8; y++)
	{
		for (x = 0; x < 8; x++)
		{
			switch (y)
			{
				case 1	: Board[x][y]->Piece = pawn;
				case 0	: Board[x][y]->Colour = white;
					  break;
				case 6	: Board[x][y]->Piece = pawn;
				case 7	: Board[x][y]->Colour = black;
					  break;
			}

			if (y == 0 || y == 7)
			{
				switch (x)
				{
					case 0	:
					case 7	: Board[x][y]->Piece = rook;
						  break;
					case 1	:
					case 6	: Board[x][y]->Piece = knight;
						  break;
					case 2	:
					case 5	: Board[x][y]->Piece = bishop;
						  break;
					case 3	: Board[x][y]->Piece = queen;
						  break;
					case 4	: Board[x][y]->Piece = king;
						  break;
				}
			}
		}
	}
}



Move GetMove(piecol *Board[8][8])
{
	Move move;
	Coordinates FromCoords = GetFromCoords(Board);
	Coordinates ToCoords= GetToCoords(Board);
	move.To = ToCoords;
	move.From = FromCoords;
	MovePiece(&move, Board);
				
}

Coordinates GetFromCoords(piecol *Board[8][8])
{
	Coordinates Coords;
	DrawBoard(Board);
	printf("Move which piece?\n");
	Coords = GetInput();

	while (!ValidCoords(Coords.X, Coords.Y))
	{
		DrawBoard(Board);
		printf("Invalid Coordinates! Select a piece to move:\n");
		Coords = GetInput();
	}

	return Coords;

}

Coordinates GetToCoords(piecol *Board[8][8])
{

	Coordinates Coords;
	DrawBoard(Board);
	printf("Move piece to where?\n");
	Coords = GetInput();
	while (!ValidCoords(Coords.X, Coords.Y))
	{
		DrawBoard(Board);
		printf("Invalid Coordinates! move piece where?\n");
		Coords = GetInput();
	}

	return Coords;

}

int ConvertLetterToNumber(char ch)
{
	int i = (int)ch;
	if (i > 90)
	{
		i -= 97;
	}
	else
	{
		i -= 65;
	}
	return i;
}

void skipgarb()
{
	while (getchar() != '\n')
	{
	}
}

int ValidCoords(char x, int y)
{
	return ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7));
}

Coordinates GetInput()
{
	char temp;
	Coordinates Coords;
	scanf("%c%d", &temp, &Coords.Y);
	skipgarb();
	Coords.X = ConvertLetterToNumber(temp);
	Coords.Y--;
	return Coords;
}

int CheckFriendlyPiece(Coordinates Coords, piecol *Board[8][8])
{
	return (Board[Coords.X][Coords.Y]->Colour == Gamestate.Turn);
}

void MovePiece(Move *move, piecol *Board[8][8])
{
	Board[move->To.X][move->To.Y]->Piece = Board[move->From.X][move->From.Y]->Piece;
	Board[move->To.X][move->To.Y]->Colour = Board[move->From.X][move->From.Y]->Colour;
	Board[move->From.X][move->From.Y]->Colour = empty;
	Board[move->From.X][move->From.Y]->Piece = none;
}



main()
{
	piecol *Board[8][8];
	CreateBoard(Board);
	SetupBoard(Board);
	while (1)
	{
		TakeTurn(Board);
	}
}

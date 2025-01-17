/*****************************************************************************
 * Copyright (C) Kapil Mulchandani kapilmulchandani2012@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
		printf("Black's turn");
		Gamestate.Turn = black;
	}
	else
	{
		printf("White's Turn");
		Gamestate.Turn = white;
	}
}


void CreateBoard(piecol *Board[8][8])      /* Creates the 8x8 Board */
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


void SetupBoard(piecol *Board[8][8])		/* Sets up Chess Board */
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
	int x, y;
	Coordinates Coords;
	Coordinates FromCoords = GetFromCoords(Board);
	Coordinates ToCoords = GetToCoords(Board);
	move.From = FromCoords;
	move.To = ToCoords;
	if(Board[FromCoords.X][FromCoords.Y]->Piece == pawn)
	pawnmove(&move, Board, FromCoords, ToCoords);
	if(Board[FromCoords.X][FromCoords.Y]->Piece == rook)
	rookmove(&move, Board, FromCoords, ToCoords);
	if(Board[FromCoords.X][FromCoords.Y]->Piece == queen)
	queenmove(&move, Board, FromCoords, ToCoords);
	if(Board[FromCoords.X][FromCoords.Y]->Piece == king)
	kingmove(&move, Board, FromCoords, ToCoords);
	if(Board[FromCoords.X][FromCoords.Y]->Piece == bishop)
	bishopmove(&move, Board, FromCoords, ToCoords);
	
	MovePiece(&move, Board);
	
				
}

Coordinates GetFromCoords(piecol *Board[8][8])
{
	int X, Y;	
	Coordinates Coords;
	DrawBoard(Board);
	printf("Move which piece?\n");
	Coords = GetInput();

	while(!CheckFriendlyPiece(Coords, Board)) {
		
		DrawBoard(Board);
		printf("Invalid Coordinates! Select a piece to move:\n");
		Coords = GetInput();
		break;
	}
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

	while(CheckFriendlyPiece(Coords, Board)) {
		
		DrawBoard(Board);
		printf("Invalid Coordinates! move piece where?\n");
		Coords = GetInput();
		break;
	}
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


int ValidCoords(char x, int y)		/*Valid Coordinates i.e inside the board */
{
	return ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7));
}

Coordinates GetInput()
{
	char temp;
	Coordinates Coords;
	scanf("%c%d", &temp, &Coords.Y);
	while (getchar() != '\n') {
	}
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
	

float getDistance (Coordinates a, Coordinates b) {
	float distance;
	char temp;
	temp = a.X;
	a.X = ConvertLetterToNumber(temp);
	distance = sqrt((a.X - b.X) * (a.X- b.X) + (a.Y - b.Y) * (a.Y - b.Y));
	return distance;
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

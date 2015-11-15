#include <stdio.h>
#include "chess.h"
Coordinates GetToCoordsforpawn(piecol *Board[8][8])
{

	Coordinates Tocoords, FromCoords;
	DrawBoard(Board);
	while (!ValidCoordsforpawn(FromCoords, ToCoords, Board)
	{
		DrawBoard(Board);
		printf("Invalid Coordinates for a pawn! move piece where?\n");
		ToCoords = GetInput();
	}
	
	return ToCoords;

}

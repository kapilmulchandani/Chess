#include<stdio.h>
#include "chess.h"

void pawnmove (Move move, piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {
	int x,y;	
	Coordinates Coords;
	
		if((Board[FromCoords.X][FromCoords.Y]->Piece == pawn) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
					
			ToCoords.X = FromCoords.X;			
				while(!(ValidCoordsforpawn(FromCoords, ToCoords, Board))) {
					DrawBoard(Board);
					printf("Invalid move for white Pawn..Move piece to where?: \n");
					ToCoords = GetInput();
					move.To = ToCoords;
				}
		

			 
		 }
		if((Board[FromCoords.X][FromCoords.Y]->Piece == pawn) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) {
			ToCoords.X = FromCoords.X;
			
			while(!(ValidCoordsforpawn(FromCoords, ToCoords, Board))) {
					DrawBoard(Board);
					printf("Invalid move for black Pawn.. Move piece to where? :\n");
					ToCoords = GetInput();
				}
		move.To = ToCoords;
		 
		}
	
		
	
	
}

void rookmove (piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {
	int x, y;
	Coordinates Coords;
		if((Board[FromCoords.X][FromCoords.Y]->Piece == rook) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) 
			while (InValidCoordsforrook(FromCoords, ToCoords, Board)) {
				DrawBoard(Board);
				printf("Invalid Coordinates for White Rook.. Move piece to where? :\n");
				ToCoords = GetInput();
			}
		if((Board[FromCoords.X][FromCoords.Y]->Piece == rook) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) 
			while (InValidCoordsforrook(FromCoords, ToCoords, Board)) {
				DrawBoard(Board);
				printf("Invalid Coordinates for Black Rook.. Move piece to where? :\n");
				ToCoords = GetInput();
			}
			
}



void kingmove (piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {
	
	
	if((Board[FromCoords.X][FromCoords.Y]->Piece == king) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
		if (getDistance(FromCoords, ToCoords) != 1) {
			printf("Invalid move for King");
		}
	}
}


void bishopmove (piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {
	int x, y;
	Coordinates Coords;
	if((Board[FromCoords.X][FromCoords.Y]->Piece == bishop) && (Board[FromCoords.X][FromCoords.Y]->Colour == white))
		while(!(ValidCoordsforbishop(FromCoords, ToCoords, Board))) {
					DrawBoard(Board);
					printf("Invalid move for white Bishop.. Move piece to where? :\n");
					ToCoords = GetInput();
				}
	if((Board[FromCoords.X][FromCoords.Y]->Piece == bishop) && (Board[FromCoords.X][FromCoords.Y]->Colour == black))
		while(!(ValidCoordsforbishop(FromCoords, ToCoords, Board))) {
					DrawBoard(Board);
					printf("Invalid move for black Bishop.. Move piece to where? :\n");
					ToCoords = GetInput();
				}
}

void queenmove (piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {
	int x, y;
	Coordinates Coords;
	if((Board[FromCoords.X][FromCoords.Y]->Piece == queen) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) 
		while ((!(ValidCoordsforbishop(FromCoords, ToCoords, Board)) && (InValidCoordsforrook(FromCoords, ToCoords, Board)))) {
			DrawBoard(Board);
			printf("Invalid move for white Queen.. Move piece to where? :\n");
			ToCoords = GetInput();
		}
		
	if((Board[FromCoords.X][FromCoords.Y]->Piece == queen) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) 
		while ((!(ValidCoordsforbishop(FromCoords, ToCoords, Board)) && (InValidCoordsforrook(FromCoords, ToCoords, Board)))){
			DrawBoard(Board);
			printf("Invalid move for Black Queen.. Move piece to where? :\n");
			ToCoords = GetInput();
		}	

} 

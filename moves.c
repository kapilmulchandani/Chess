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

#include<stdio.h>
#include "chess.h"
Coordinates pawnmove (Move *move, piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {		/*rules for pawn */
	int x,y;	
	
	Coordinates Coords;
	
		if((Board[FromCoords.X][FromCoords.Y]->Piece == pawn) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
						
				while(!(ValidCoordsforpawn(FromCoords, ToCoords, Board))) {
					DrawBoard(Board);
					printf("Invalid move for white Pawn..Move piece to where?: \n");
					ToCoords = GetInput();
					
				}
			move->To = ToCoords;
			
			
		 }
		if((Board[FromCoords.X][FromCoords.Y]->Piece == pawn) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) {
			
			
			while(!(ValidCoordsforpawn(FromCoords, ToCoords, Board))) {
					DrawBoard(Board);
					printf("Invalid move for black Pawn.. Move piece to where? :\n");
					ToCoords = GetInput();
					
				}
			move->To = ToCoords;
		}
	
		
	return move->To;
	
}

Coordinates rookmove (Move *move, piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {      /*rules for rook */
	int x, y;
	Coordinates Coords;
		if((Board[FromCoords.X][FromCoords.Y]->Piece == rook) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
			while (InValidCoordsforrook(FromCoords, ToCoords, Board)) {
				DrawBoard(Board);
				printf("Invalid Coordinates for White Rook.. Move piece to where? :\n");
				ToCoords = GetInput();
			}
			move->To = ToCoords;
		}
		if((Board[FromCoords.X][FromCoords.Y]->Piece == rook) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) {
			while (InValidCoordsforrook(FromCoords, ToCoords, Board)) {
				DrawBoard(Board);
				printf("Invalid Coordinates for Black Rook.. Move piece to where? :\n");
				ToCoords = GetInput();
			}
			move->To = ToCoords;
		}
			
	return move->To;			
}



Coordinates kingmove (piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {	/*rules for king */
	
	
	if((Board[FromCoords.X][FromCoords.Y]->Piece == king) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
		if (getDistance(FromCoords, ToCoords) != 1) {
			printf("Invalid move for White King");
	}}
	if((Board[FromCoords.X][FromCoords.Y]->Piece == king) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) {
		if (getDistance(FromCoords, ToCoords) != 1) {
			printf("Invalid move for black King");
		}
	}
}


Coordinates bishopmove (Move *move, piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {  /* Rules for bishop*/
	int x, y;
	Coordinates Coords;
	if((Board[FromCoords.X][FromCoords.Y]->Piece == bishop) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
		while(!(ValidCoordsforbishop(FromCoords, ToCoords, Board))) {
					DrawBoard(Board);
					printf("Invalid move for white Bishop.. Move piece to where? :\n");
					ToCoords = GetInput();
				}
		move->To = ToCoords;
	}
	if((Board[FromCoords.X][FromCoords.Y]->Piece == bishop) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) {
		while(!(ValidCoordsforbishop(FromCoords, ToCoords, Board))) {
					DrawBoard(Board);
					printf("Invalid move for black Bishop.. Move piece to where? :\n");
					ToCoords = GetInput();
				}
		move->To = ToCoords;
	}
	return move->To;
}

Coordinates queenmove (Move *move, piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {	/*rules for queen */
	int x, y;
	Coordinates Coords;
	if((Board[FromCoords.X][FromCoords.Y]->Piece == queen) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
		while ((!(ValidCoordsforbishop(FromCoords, ToCoords, Board)) && (InValidCoordsforrook(FromCoords, ToCoords, Board)))) {
			DrawBoard(Board);
			printf("Invalid move for white Queen.. Move piece to where? :\n");
			ToCoords = GetInput();
		}
		move->To = ToCoords;
	}
		
	if((Board[FromCoords.X][FromCoords.Y]->Piece == queen) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) {
		while ((!(ValidCoordsforbishop(FromCoords, ToCoords, Board)) && (InValidCoordsforrook(FromCoords, ToCoords, Board)))){
			DrawBoard(Board);
			printf("Invalid move for Black Queen.. Move piece to where? :\n");
			ToCoords = GetInput();
		}
		move->To = ToCoords;
	}
	return move->To;	
}

Coordinates knightmove (Move *move, piecol *Board[8][8], Coordinates FromCoords, Coordinates ToCoords) {
	int x, y;
	Coordinates Coords;
	if((Board[FromCoords.X][FromCoords.Y]->Piece == knight) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
		while (!ValidCoordsforknight(FromCoords, ToCoords, Board)) {
			DrawBoard(Board);
			printf("Invalid move for white knight.. Move piece to where? :\n");
			ToCoords = GetInput();
		}
		move->To = ToCoords;
	}
	if((Board[FromCoords.X][FromCoords.Y]->Piece == knight) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) {
		while (!ValidCoordsforknight(FromCoords, ToCoords, Board)) {
			DrawBoard(Board);
			printf("Invalid move for black knight.. Move piece to where? :\n");
			ToCoords = GetInput();
		}
		move->To = ToCoords;
	}
	return move->To;
}

/* ***** CODE FOR CHECK ***** */

/*
int checkbyrook(Coordinates FromCoords, Coordinates ToCoords, piecol *Board[8][8]) {
	Coordinates Coords,
	int x = 0, y = 0;
	for(y = FromCoords.Y; y < ToCoords.Y; y++) 
	
		for (x = FromCoords.X; x < ToCoords.X; x++)
		
			if((Board[x][y]->Piece == king) && (Board[x][y]->Colour == black))
				return 0;
*/


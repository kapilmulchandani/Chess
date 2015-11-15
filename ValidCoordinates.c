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
#include "chess.h"
int ValidCoordsforpawn(Coordinates FromCoords, Coordinates ToCoords, piecol *Board[8][8]) {
	int x, y;
	if(FromCoords.Y == ToCoords.Y)
		return 0;
	if((Board[FromCoords.X][FromCoords.Y]->Piece == pawn) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) 
		if((FromCoords.Y > ToCoords.Y))
			return 0;
	if((Board[FromCoords.X][FromCoords.Y]->Piece == pawn) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) 
		if((FromCoords.Y < ToCoords.Y))
			return 0;
	
	if((FromCoords.Y == 1) || (FromCoords.Y == 6)){
		if(Gamestate.Turn == white)
			
			if((ToCoords.Y != 3) && (ToCoords.Y != 2))
				return 0;
		if(Gamestate.Turn == black)
			if((ToCoords.Y != 4) && (ToCoords.Y != 5))
				return 0;	
	}
	if((FromCoords.Y != 2) || (FromCoords.Y != 3) || (FromCoords.Y != 4) || (FromCoords.Y != 5)) {
				
		if(getDistance(FromCoords, ToCoords) != 0)
			return 1;
	}
}

int ValidCoordsforking(Coordinates FromCoords, Coordinates ToCoords, piecol *Board[8][8]) {
	}

int ValidCoordsforbishop(Coordinates FromCoords, Coordinates ToCoords, piecol *Board[8][8]) {
	if((FromCoords.X == ToCoords.X) || (FromCoords.Y == ToCoords.Y))
		return 0;
	
}

int InValidCoordsforrook(Coordinates FromCoords, Coordinates ToCoords, piecol *Board[8][8]) {
	if((FromCoords.X == ToCoords.X) || (FromCoords.Y == ToCoords.Y))
		return 0;
}

int ValidCoordsforknight(Coordinates FromCoords, Coordinates ToCoords, piecol *Board[8][8]) {
	if((Board[FromCoords.X][FromCoords.Y]->Piece == knight) && (Board[FromCoords.X][FromCoords.Y]->Colour == white)) {
		if((FromCoords.Y == 0) && (ToCoords.Y == 2))
			return 1;
		else
			return 0;
		if((FromCoords.X == 1) || (FromCoords.X == 6))
			if((ToCoords.X != 0) || (ToCoords.X != 2) || (ToCoords.X != 5) || (ToCoords.X != 7))
				return 0;
	}

	if((Board[FromCoords.X][FromCoords.Y]->Piece == knight) && (Board[FromCoords.X][FromCoords.Y]->Colour == black)) {
		if((FromCoords.Y == 7) && (ToCoords.Y == 5))
			return 1;
		else
			return 0;
		if((FromCoords.X == 1) || (FromCoords.X == 6))
			if((ToCoords.X != 0) || (ToCoords.X != 2) || (ToCoords.X != 5) || (ToCoords.X != 7))
				return 0;
	}
}

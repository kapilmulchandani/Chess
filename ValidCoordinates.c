#include <stdio.h>
#include "chess.h"
int ValidCoordsforpawn(Coordinates FromCoords, Coordinates ToCoords, piecol *Board[8][8]) {
	if((FromCoords.X != ToCoords.X) || (FromCoords.Y == ToCoords.Y))
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



	

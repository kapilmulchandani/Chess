#include "chess.h"
Rookmove {
	if (adjascent same colour)
		cannot move;
	else	
		can move in a vertical or horizontal line
		unless the other block is occupied by white
}

Pawnmove {
	if (adjascent same colour || infront black)
		cannot move;
	else
		if(at start)
			if		
				can move 2 blocks in front;
		else
			can move 1 block in front;
	if (diagonal not empty)
		can mmove diagonal 1 block;
} 

Kingmove {
	if (adjascent same colour)
		cannot move;
	else
		can move 1 block anywhere;
}

Bishopmove {
	if (adjascent same colour)
		cannot move;
	else
		can move diagonally only
		unless encounters same colour piece;
}

Queenmove {
	if(adjascent same colour)
		cannot move;
	else
		can move anywhere 
		unless encouters piece of same colour
}

Knightmove {
	

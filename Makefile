project: chess.c output.c moves.c ValidCoordinates.c 
	 cc -c chess.c
	 cc -c output.c
	 cc -c moves.c
	 cc -c ValidCoordinates.c
	
	 cc chess.o output.o moves.o ValidCoordinates.o GetToCoords.o -o project -lm



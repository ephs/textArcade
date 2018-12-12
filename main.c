#include <stdio.h>
#include <stdlib.h>

//game c files
#include "numberGuesser.c"

char *gameNames[] = {"Number Guesser - by Avery"};
int numGames = sizeof(gameNames) / sizeof(gameNames[0]);
int MAXINPUT = 1000;

int main() {

	char input[MAXINPUT];
	int i;

	//printf("%d\n", atoi(input));

	printf("\n\nWelcome to the Text Arcade!\nThis is a computer program that was written in C by members of the Programming Club at EPHS\n");
	
start:
	do {
		printf("\n\nSelect a game to play from the following list:\n");

		for (i = 0; i < numGames; i++) {
			printf("[%d]\t%s\n", i+1, gameNames[i]);

		}
		scanf("%s", input);
	} while (atoi(input) <= 0 || atoi(input) > (0 + numGames));

	//run game function
	switch (atoi(input)) {
		case 1:
			//printf("Number guesser selected\n");
			numberGuesser();
			break;
		case 2:
			//printf("Tic Tac Toe selected\n");
			break;
	}
	goto start;


	return 0;
}

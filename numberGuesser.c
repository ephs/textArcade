#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void numberGuesser();
int playerNumGuess();

static int RANDMAX = 100; 
static int MAXGUESSLEN = 1000;
static int STARTINGLIVES = 6;

void numberGuesser() {

	printf("%d\n", atoi("asdfasdfa"));

	srand(time(NULL));
	int randNum, lives, numGuess;
	char guess[MAXGUESSLEN], c;

	//restart point
start:

	randNum = rand() % RANDMAX + 1;
	lives = STARTINGLIVES;
	printf("\n\nI'm thinking of a number from 1 to %d\n", RANDMAX);
	//printf("%d is the number\n", randNum);

	numGuess = playerNumGuess();

	while (numGuess != randNum) {

		//check for bad guess
		if (numGuess < 1 || numGuess > RANDMAX) {
			printf("Bad guess. Range is from 1 to %d\n", RANDMAX);
			continue;
		}

		//give hint
		if (numGuess > randNum) {
			printf("Too high\n\n");
		}
		else {
			printf("Too low\n\n");
		}

		lives --;
		if (lives < 1)
			break;

			numGuess = playerNumGuess();
	}//end while

	if (lives >= 1)
		printf("You Win!\n");
	else {
		printf("You Lose! The correct number was %d. Would you like to try again? (y/n)\n", randNum);
		while ((c = getchar()) != 'y' && c != 'n')
			//printf("(y/n)\n");
		if (c == 'y') {
			goto start;
		}

	}

}//end numberGuesser()

int playerNumGuess() {

	char guess[MAXGUESSLEN];
	int intGuess;
	do {
		//printf("in playerNumGuess do-while");
		scanf("%s", guess);
		intGuess = atoi(guess);

	} while (intGuess < 1 || intGuess > RANDMAX);
	
	return intGuess;
}

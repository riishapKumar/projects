#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_game_end(int counter);
int check_guess(int counter, int target, int guess);
int prompt_guess();
int get_random_int();


int main(int argc, char **argv) {
	int counter = 0;
	int guess = 0;
	int target = get_random_int();


	while (check_game_end(counter) == 0) {
		guess = prompt_guess();
		counter++;

		if (check_guess(counter, target, guess) == 1) {
			break;
		}

	}
}

/**
 * Returns a random number between 1 and 100 both numbers inclusive.
 */
int get_random_int() {
	int number = 0;
	srand(0);
	number = rand() % 100+1;

	return number;
}

/**
 */

int prompt_guess() {
	int guess = 0;
	
	while (guess <= 0 || guess >= 100) {
		printf("What is your guess?\n");

		if (scanf("%d", &guess) == 1) {
			if (guess <= 0 || guess > 100) {
				printf("Guess out of bounds, try again.\n");
			} else {
				return guess;
			}

		} else {
			while (getchar() != '\n')
				;
		}
	}
	return 0; // but will never be reached
}

/**
 */
int check_guess(int counter, int target, int guess) {
	if (guess == target) {
		printf("You guessed correctly in %d tries!\n", counter);
		return 1;
	}
	if (guess < target) {
		printf("Your guess is too small! ");
	} else {
		printf("Your guess is too big! ");
	}

	printf("(%d tries left)\n", 10 - counter);
	return 0;
}
/**
 */
int check_game_end(int counter) {
	if (counter == 10) {
		printf("You lose!\n");
		return 1;
	}
	return 0;
}


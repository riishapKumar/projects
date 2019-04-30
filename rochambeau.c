#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_cpu_move(void);
int get_player_move(void);
void print_winner(int player_move, int cpu_move);
int main (void)
{




}
int get_cpu_move(void)
{
	int computerMove = rand()%3;
	return comp_choice;
}
int get_player_move(void)
{
	int userMove;
	char input;
	printf("[Rr]ock, [Pp]aper or [Ss]cissors? (or [Qq]uit)\n");
	scanf("%c", input);
	while (input != "R" || input != "r" || input != "P" || input != "p" || input != "S" || input != "s")
		printf("Invalid move, try again!\n")
		printf(("[Rr]ock, [Pp]aper or [Ss]cissors? (or [Qq]uit)\n");
}
	switch (input) {
		case "R":
		case "r":
			 userMove = 1;
			break;
		case "P":
		case "p":
			 userMove = 2;
			break;
		case "S":
		case "s":
			 userMove = 3;
		return userMove
}
	
}
void print_winner(int userMove, int computerMove)
{
if ((userMove==1)&&(computerMove==1))

{

printf("Rock versus Rock... Tie!\n");

}

else if ((userMove==1)&&(computerMove==2))

{ printf("Rock versus Paper... You lose!\n");

}

else if ((userMove==1)&&(computerMove==3))

{ printf("Rock versus Sicssors... You win!\n");

}

else if((userMove==2)&&(computerMove==1))

{ printf("Paper versus Rock... You win!\n");

}

else if((userMove==2)&&(computerMove==2))

{ printf("Paper versus Paper... Tie!\n");

}

else if((userMove==2)&&(computerMove==3))

{ printf("Paper versus Scissors... You lose!\n");

}

else if((userMove==3)&&(computerMove==1))

{ printf("Scissors versus Rock... You lose!\n");

}

else if((userMove==3)&&(computerMove==2))

{ printf("Scissors versus Paper... You Win!\n");

}

else if((userMove==3)&&(computerMove==3))

{ printf("Scissors versus Scissors... Tie!\n");

}	

}
	

	

/*
 * File: matrix_transpose.c
 * Desc: this program  enables two players to play tic-tac-toe interactively
 * Author: Rishap kumar and Thanapol Makjumroen
 */
#include <stdio.h>

char grid[9] = {};

void init_grid(void)
{/* empty the grid (ie, fills it out with spaces)*/
	for(int i = 0;i<9;i++)
		grid[i] = ' ';
}
int is_horizontal_winner(char player)
{/*checks if the player represented by the specified character has filled out a horizontal line */
	if((grid[0]==player && grid[0]==grid[1] && grid[0]==grid[2]) 
		|| (grid[3]==player && grid[3]==grid[4] && grid[3]==grid[5])
		|| (grid[6]==player && grid[6]==grid[7] && grid[6]==grid[8])
		)
		return 1;
	return 0;
}
int is_vertical_winner(char player)
{/*checks if the player represented by the specified character has filled out a vertical line */
	if((grid[0]==player && grid[0]==grid[3] && grid[0]==grid[6]) 
		|| (grid[1]==player && grid[1]==grid[4] && grid[1]==grid[7])
		|| (grid[2]==player && grid[2]==grid[5] && grid[2]==grid[8])
		)
		return 1;
	return 0;
}
int is_diag_winner(char player)
{
/* checks if the player represented by the specified character has filled out one of the two diagonal lines */
	if((grid[0]==player && grid[0]==grid[4] && grid[0]==grid[8]) 
		|| (grid[2]==player && grid[2]==grid[4] && grid[2]==grid[6]))
		return 1;
	return 0;
}
int is_win(char player)
{

	return (is_horizontal_winner(player) || is_vertical_winner(player) || is_diag_winner(player));
}


int is_tie(void)
{
	for(int i = 0;i<9;i++)
	{
		if(!(grid[i]=='X' || grid[i]=='O'))
			return 0;
	}
	return 1;
}

int play(char player, int pos)
{
/* tries playing the player represented by the specified character at the given position */
	if(pos>=9 || pos<=-1)
	{
		printf("Invalid Cell\n");
		return 0;
	}
	if (player == 'X' )
		grid[pos] = 'X';
	else
		grid[pos] = 'O';
	return 1;	
}

void display_grid(void)
{
/*display the grid */
	printf("-------\n");
	for(int i=0;i<9;i++)
	{
		printf("|%c",grid[i]);
		if (i == 2 || i== 5 || i==8)
			printf("|\n-------\n");
	}
}

int main()
{
/* ties all the fuctions and runs them all */
	char player1 = 'X', player2 ='O';
	
	int pos, result = 0;
	init_grid();
	display_grid();	

	while(1)
	{
		do{
			printf("Enter cell for Player 1\n");
			scanf("%d",&pos);
		}
		while(!play( player1, pos));
		display_grid();

		result = is_win(player1);

		if (result == 1 )
		{	
			printf("Player 1 wins!\n");
			break;
		}
		else if (is_tie())
		{	

			break;
		}

		do{
			printf("Enter cell for Player 2\n");
			scanf("%d",&pos);
		}
		while(!play( player2, pos));
		display_grid();
		
		result =is_win(player2);	
		if (result == 1 )
		{	
			printf("Player 2 wins!\n");
			break;
		}
	}
	return 0;
}

#include <stdlib.h>
#include <time.h>
#include "game_logic.h"

void create_seed()
{
	srand(time(NULL));
}

void generate_colors(int secret_colors[], int color_count)
	/*
	Func accepts pointer to an array of type int
	and number of colors (nums) to be randomly
	generated.
	
	Before calling the func, an array has to be 
	initialized of type int and passed to the func 
	with enough memory allocated.
	*/
{
	int _max_iter = 4;

	for (int i = 0; i < _max_iter; i++)
	{
		secret_colors[i] = rand() % color_count + 1;
	}
}

void eval_guess(int secret_colors[], int player_guess[],
	int* black_pins, int* white_pins)
{
	int _max_iter = 4;

	*black_pins = 0;
	*white_pins = 0;

	int secret_copy[4];
	int guess_copy[4];

	for (int i = 0; i < _max_iter; i++)
	{
		secret_copy[i] = secret_colors[i];
		guess_copy[i] = player_guess[i];
	}

	for (int i = 0; i < _max_iter; i++)
	{
		if (secret_colors[i] == player_guess[i])
		{
			(*black_pins)++;
			secret_copy[i] = -1;
			guess_copy[i] = -1;
		}
	}

	for (int i = 0; i < _max_iter; i++)
	{
		for (int j = 0; j < _max_iter; j++)
		{
			/*	check only if guess_copy is not - 1, otherwise
				white_pins would be incremented when in reality
				it is a black_pin
			*/
			if (guess_copy[i] != -1 && guess_copy[i] == secret_copy[j])
			{
				(*white_pins)++;
				guess_copy[i] = -1;
				secret_copy[j] = -1;
				break;
			}
		}
	}
}

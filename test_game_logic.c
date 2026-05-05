#include "test_game_logic.h"
#include "game_logic.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void test_generate_colors(int debug)

{
	int count = 4;
	int* arr = malloc(sizeof(int) * count);
	generate_colors(arr, count);

	if (debug)
	{
		for (int i = 0; i < count; i++)
		{
			printf("\n%d", arr[i]);
		}
	}

}

void test_eval_guess()
{
	int count = 4;
	int* secret_colors = malloc(sizeof(int) * count);
	generate_colors(secret_colors, count);

	int* player_guess = malloc(sizeof(int) * count);
	
	for (int i = 0; i < count; i++)
	{
		*(player_guess + i) = i + 1;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%d ", secret_colors[i]);
	}

	printf("\n");

	for (int i = 0; i < count; i++)
	{
		printf("%d ", player_guess[i]);
	}

	printf("\n");

	int* black_pins = malloc(4);
	int* white_pins = malloc(4);
	eval_guess(secret_colors, player_guess, black_pins, white_pins);

	printf("Black pins: %d, White pins: %d", *black_pins, *white_pins);
}
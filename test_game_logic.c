#include "test_game_logic.h"
#include "game_logic.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void test_generate_colors()

{
	int count = 4;
	int* arr = malloc(sizeof(int) * count);
	generate_colors(arr, count);

	for (int i = 0; i < count; i++)
	{
		printf("\n%d", arr[i]);
	}
}
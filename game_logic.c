#include <stdlib.h>
#include <time.h>
#include "game_logic.h"

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
	srand(time(NULL));

	for (int i = 0; i < color_count; i++)
	{
		*(secret_colors + i) = rand() % color_count + 1;
	}
}
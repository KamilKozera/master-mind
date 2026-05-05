#pragma once

void generate_colors(int secret_colors[], int color_count);
void eval_guess(int secret_colors[], int player_guess[],
	unsigned int* black_pins, unsigned int* white_pins);
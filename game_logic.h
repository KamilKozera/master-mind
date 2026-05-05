#pragma once

void create_seed();
void generate_colors(int secret_colors[], int color_count);
void eval_guess(int secret_colors[], int player_guess[],
	int* black_pins, int* white_pins);
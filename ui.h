#pragma once

#define CODE_LENGTH 4
#define MAX_ATTEMPTS 10

void clear_screen();
int get_difficulty();
void get_player_guess(int guess[], int color_count);
void display_board(int history[][4], int results[][2], int attempts);
void display_final_result(int won, int secret_code[]);
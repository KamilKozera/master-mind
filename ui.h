#pragma once

#define CODE_LENGTH 4
#define MAX_ATTEMPTS 12

void clear_screen();
int get_difficulty();
void get_player_guess(int guess[], int color_count);
void display_board(int history[][4], int results[][2], int attempts);
void display_final_result(int won, int secret_code[]);
int ask_to_play_again();
int get_attempts_limit();
void print_colored_digit(int digit);
void display_instructions();

//colors
// ui.h
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_BRIGHT_YELLOW "\x1b[93m"
#define ANSI_COLOR_RESET   "\x1b[0m"
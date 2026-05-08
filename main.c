#include <stdio.h>
#include "game_logic.h"
#include "ui.h"

int main() {
  
    create_seed();
    clear_screen();

    printf("===== MASTERMIND GAME =====\n\n");

    // set up difficulty and generate secret code
    int color_count = get_difficulty();
    int secret_code[4];
    generate_colors(secret_code, color_count);

    int board_history[10][4];
    int results_history[10][2];
    int won = 0;

    clear_screen();
    printf("Code generated! You have 10 attempts.\n");

    // main game loop
    for (int i = 0; i < 10; i++) {
        int current_guess[4];
        
        get_player_guess(current_guess, color_count);

        int black = 0;
        int white = 0;

        eval_guess(secret_code, current_guess, &black, &white);
  
        for (int j = 0; j < 4; j++) {
            board_history[i][j] = current_guess[j];
        }
        results_history[i][0] = black;
        results_history[i][1] = white;

     
        clear_screen();
        display_board(board_history, results_history, i + 1);

        // check if all pins are black
        if (black == 4) {
            won = 1;
            break;
        }
    }

    display_final_result(won, secret_code);

    return 0;
}
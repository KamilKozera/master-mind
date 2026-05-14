#include <stdio.h>
#include "game_logic.h"
#include "ui.h"

int main() {
    create_seed(); 

    do {
        clear_screen();
        printf("===== MASTERMIND GAME =====\n\n");

        display_instructions();

        int color_count = get_difficulty();
        int max_attempts = get_attempts_limit();
        int secret_code[4];
        generate_colors(secret_code, color_count);

        
        int board_history[MAX_ATTEMPTS][4];
        int results_history[MAX_ATTEMPTS][2];
        int won = 0;

        clear_screen();
        printf("Code generated! You have %d attempts.\n", max_attempts);

        
        for (int i = 0; i < max_attempts; i++) {
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

          
            if (black == 4) {
                won = 1;
                break;
            }
        }

        display_final_result(won, secret_code);

    } while (ask_to_play_again()); 

    return 0;
}
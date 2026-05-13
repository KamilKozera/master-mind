#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void clear_screen() {
    system("cls");
}

int get_difficulty() {
    int choice;
  do {
    printf("Choose the difficulty level:\n");
    printf("1. Easy (1-4)\n");
    printf("2. Medium (1-6)\n");
    printf("3. Hard (Be careful!) (1-8)\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    while (getchar() != '\n'); // clear buffer

    if (choice < 1 || choice > 3) {
        printf("Invalid choice. Please choose 1, 2, or 3.\n");
    }

} while (choice < 1 || choice > 3);
    if (choice == 1) return 4;
    if (choice == 2) return 6;
    return 8;
}

void get_player_guess(int guess[], int color_count) {
    
    char input_buffer[100];    // Line-buffered input for robust validation and stream synchronization.

    while (1) {
        printf("Enter 4 digits (1-%d) separated by spaces: ", color_count);

        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) continue;

        int items_read = sscanf(input_buffer, "%d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3]);

        if (items_read == 4 &&
            guess[0] >= 1 && guess[0] <= color_count &&
            guess[1] >= 1 && guess[1] <= color_count &&
            guess[2] >= 1 && guess[2] <= color_count &&
            guess[3] >= 1 && guess[3] <= color_count) {
            break;
        }

        printf("Prosze porzadnie przeczytac polecenie...\n");
    }
}


void display_board(int history[][4], int results[][2], int attempts) {
    printf("\n Mastermind Board\n");
    for (int i = 0; i < attempts; i++) {
        printf("Attempt %d: [ ", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%d ", history[i][j]);
        }
        printf("] | Black: %d | White: %d\n", results[i][0], results[i][1]);
    }
    printf("--------------------------\n");
}


void display_final_result(int won, int secret_code[]) {
    if (won == 1) {
        printf("\n Gratulacje Graczu, zwyciezyles...\n");
    } else {
        printf("\n Gorycz porazki unosi sie w powietrzu... nie tym razem graczu \n");
        printf("Oto szyfr ktory cie pokonal: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", secret_code[i]);
        }
        printf("\n");
    }
}
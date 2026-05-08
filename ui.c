#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void clear_screen() {
    system("cls");
}

int get_difficulty() {
    int choice;
    printf("Choose the difficulty level:\n");
    printf("1. Easy (1-4)\n");
    printf("2. Medium (1-6)\n");
    printf("3. Hard (Be careful!) (1-8)\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) return 4;
    if (choice == 2) return 6;
    return 8;
}

void get_player_guess(int guess[], int color_count) {
    printf("Enter 4 digits (1-%d) separated by spaces: ", color_count);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &guess[i]);
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
        printf("\n Gorycz porazki unosi się w powietrzu... nie tym razem graczu \n");
        printf("Oto szyfr który cie pokonał: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", secret_code[i]);
        }
        printf("\n");
    }
}
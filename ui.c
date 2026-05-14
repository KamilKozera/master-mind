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
    printf("Wybierz poziom swojej mocy:\n");
    printf("1. Adept - Latwy (1-4)\n");
    printf("2. Mag - Sredni (1-6)\n");
    printf("3. Arcymag - Trudny (1-8)\n");
    printf("Twoj wybor: ");
    scanf("%d", &choice);

    while (getchar() != '\n'); // clear buffer

    if (choice < 1 || choice > 3) {
        printf("Niewlasciwy wybor! Wybierz sciezke 1, 2 lub 3.\n\n");
    }

} while (choice < 1 || choice > 3);
    if (choice == 1) return 4;
    if (choice == 2) return 6;
    return 8;
}

void get_player_guess(int guess[], int color_count) {
    
    char input_buffer[100];    // Line-buffered input for robust validation and stream synchronization.

    while (1) {
        printf("Uloz rzad 4 klejnotow (cyfry 1-%d oddzielone spacjami): ", color_count);

        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) continue;

        int items_read = sscanf(input_buffer, "%d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3]);

        if (items_read == 4 &&
            guess[0] >= 1 && guess[0] <= color_count &&
            guess[1] >= 1 && guess[1] <= color_count &&
            guess[2] >= 1 && guess[2] <= color_count &&
            guess[3] >= 1 && guess[3] <= color_count) {
            break;
        }

        printf("Zaklecie nieudane! Prosze porzadnie przeczytac ksiege...\n\n");
    }
}

void display_board(int history[][4], int results[][2], int attempts) {
    printf("\n--- TABLICA RYTUALU ---\n");
    for (int i = 0; i < attempts; i++) {
        printf("Kolejka %d: [ ", i + 1);
        for (int j = 0; j < 4; j++) {
            print_colored_digit(history[i][j]);
        }
        printf("] | Czarne Runy: %d | Biale Runy: %d\n", results[i][0], results[i][1]);
    }
    printf("--------------------------\n");
}


void display_final_result(int won, int secret_code[]) {
    if (won == 1) {
        printf("\n " ANSI_COLOR_GREEN "Brama stoi otworem! Skarbiec jest Twoj, Mistrzu Szyfrow!" ANSI_COLOR_RESET "\n");
    }
    else {
        printf("\n " ANSI_COLOR_RED "Ciemnosc Cie pochlania... Twoja magia byla zbyt slaba." ANSI_COLOR_RESET "\n");
        printf("Oto prawdziwy kod, ktorego nie udalo Ci sie zlamac: ");
        for (int i = 0; i < 4; i++) {
            print_colored_digit(secret_code[i]);
        }
        printf("\n");
    }
}

int ask_to_play_again() {
    int choice;
    printf("\n \"Sukces nie jest ostateczny, porazka nie jest fatalna : liczy sie odwaga, by kontynuowac  — Winston Churchill\"\n");
    printf("Czy podejmiesz kolejna probe? (1 - Tak, 0 - Nie): ");
    (void)scanf("%d", &choice);

    while (getchar() != '\n');

    return (choice == 1);
}

int get_attempts_limit() {
    int attempts;
    do {
        printf("Na ile prob starczy Ci many? (Wybierz 8, 10 lub 12 prob): ");
        (void)scanf("%d", &attempts);
        while (getchar() != '\n');

        if (attempts != 8 && attempts != 10 && attempts != 12) {
            printf("Twoja wola musi byc konkretna: 8, 10 lub 12.\n");
        }
    } while (attempts != 8 && attempts != 10 && attempts != 12);
    return attempts;
}


//colors
void print_colored_digit(int digit) {
    switch (digit) {
    case 1: printf(ANSI_COLOR_RED "%d " ANSI_COLOR_RESET, digit); break;
    case 2: printf(ANSI_COLOR_GREEN "%d " ANSI_COLOR_RESET, digit); break;
    case 3: printf(ANSI_COLOR_YELLOW "%d " ANSI_COLOR_RESET, digit); break;
    case 4: printf(ANSI_COLOR_BLUE "%d " ANSI_COLOR_RESET, digit); break;
    case 5: printf(ANSI_COLOR_MAGENTA "%d " ANSI_COLOR_RESET, digit); break;
    case 6: printf(ANSI_COLOR_CYAN "%d " ANSI_COLOR_RESET, digit); break;
    case 7: printf(ANSI_COLOR_WHITE "%d " ANSI_COLOR_RESET, digit); break;
    case 8: printf(ANSI_COLOR_BRIGHT_YELLOW "%d " ANSI_COLOR_RESET, digit); break;
    default: printf("%d ", digit);
    }
}

void display_instructions() {
    printf("--------------------------------------------------\n");
    printf("--- RYTUAL MASTERMIND ---\n");
    printf("Zlam kod 4 klejnotow ukrytych przez przeznaczenie.\n\n");

    printf("LEGENDA KAMIENI:\n");
    printf("1-" ANSI_COLOR_RED "Rubin " ANSI_COLOR_RESET "2-" ANSI_COLOR_GREEN "Szmaragd " ANSI_COLOR_RESET "3-" ANSI_COLOR_YELLOW "Topaz " ANSI_COLOR_RESET "4-" ANSI_COLOR_BLUE "Szafir " ANSI_COLOR_RESET);
    printf("5-" ANSI_COLOR_MAGENTA "Ametyst " ANSI_COLOR_RESET "6-" ANSI_COLOR_CYAN "Turkus " ANSI_COLOR_RESET "7-" ANSI_COLOR_WHITE "Diament " ANSI_COLOR_RESET "8-" ANSI_COLOR_BRIGHT_YELLOW "Bursztyn" ANSI_COLOR_RESET "\n\n");

    printf("Czarne Runy: Klejnot jest wlasciwy i na dobrym miejscu.\n");
    printf("Biale Runy: Klejnot jest wlasciwy, lecz w zlym gniezdzie.\n");
    printf("--------------------------------------------------\n\n");
}
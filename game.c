#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *getInstructions() {
    // Using a character array

    return "You always start as the X, therefore they are the first\n\
to play. Each cell is reprensented by a number. To place your X simply\n\
put input the number of the cell. Then it is the computer's turn.\n\n\n\
Usual grid layout:\n\n\
[1][2][3]     [X][2][3]\n\
[4][5][6]     [4][5][6]\n\
[7][8][9]     [7][O][9]";
}
void flushConsole(){
    
        printf("\033[2J\033[H");
}

void demande() {
    printf("1. Play\n");
    printf("2. How to play\n");
    printf("3. Quit\n");

    // Variable used to store the user choice
    int choice;

    // Get and save the number the user types
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("You chose to play!\n");
        break;
    case 2:
        // printf("\033[2J\033[H");
        flushConsole();
        printf("You chose the instructions menu!\n\n");
        const char *instructions = getInstructions();
        // Here i print the instructions
        // printf("\033[2J\033[H");
        flushConsole();

        printf("%s\n", instructions);
        printf("1. Back\n");
        int choice2;
        scanf("%d", &choice2);
        if (choice2 == 1) {
            // printf("\033[2J\033[H");
        flushConsole();
            demande();
        }
        else {
            while (getchar() != '\n');
            // printf("\033[2J\033[H");
        flushConsole();
            // demande();
            demande();
        }
        break;
    case 3:
        printf("You chose to quit the game!\n");
        exit(0);
        break;

    default:
        while (getchar() != '\n');
        printf("wrong value\n");
        demande();
        break;
    }
}

int main() {

    /*
    This is the game of tic-tac-toe played in the terminal/console


    It is a project to learn C in a fun way
    */

    printf("Hello and welcome to Tic Tac Toe made by Love-Fromage!\n\n");
    demande();

    return 0;
}

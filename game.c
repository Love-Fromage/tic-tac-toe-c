#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

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

/*
int board[25] = {
    :,:,:,:,:,
    :,O,-,X,:,
    :,X,-,-,:,
    :,-,-,-,:,
    :,:,:,:,:,
}
*/


// const int CERCLE = 1;
// const int X = 2;
// const int BORDER =3;
// const int EMPTY = 0;
enum { CERCLE, X, BORDER, EMPTY };
enum { HUMANWIN, COMPWIN, DRAW };


const int ConvertTo25[9]={
    6,7,8,
    11,12,13,
    16,17,18
};

void InitialiseBoard(int *board){
    int index = 0;
   for(index = 0; index<25; index++) {
        board[index] = BORDER;
   }
   for(index = 0; index < 9; index++){
        board[ConvertTo25[index]] = EMPTY;
   }
    
}

void PrintBoard(const int *board){
    int index = 0;
    char pceChars[] = "OX|-";
    printf("\n\nBoard\n\n");
    for(index = 0; index < 9; index++){
        if(index!=0 && index%3==0){
            printf("\n\n");
        }
        printf("%4c", pceChars[board[ConvertTo25[index]]]);
    }
    printf("\n");
}

int getComputerMove(const int *board){
    int index = 0;
    int numFree = 0;
    int availableMoves[9];
    int randMove = 0;

    /* 2,4,8
        availableMoves[0] = 2
        availableMoves[1] = 4
        availableMoves[2] = 8
    
    */
}

int GetHumanMove(const int *board){
    char userInput[4];

    int moveOK = 0;
    int move = -1;

    while(moveOK == 0){
        printf("Please enter a move from 1 to 9:");
        fgets(userInput, 3, stdin);
        fflush(stdin);

        if(strlen(userInput) !=2){
            printf("Invalid strlen()\n");
            continue;
        }

        if(sscanf(userInput, "%d", &move) != 1){
            move = -1;
            printf("Invalid sscanf()\n");
            continue;
        }

        if(move < 1 || move > 9){
            move = -1;
            printf("Invalid range\n");
            continue;
        }

        move--; // Zero indexing

        if(board[ConvertTo25[move]]!=EMPTY){
            move = -1;
            printf("Square is not available!\n");
            continue;
        }
        moveOK = 1;
    }
    printf("Making Move...%d\n", (move+1));
    return ConvertTo25[move];
}

int HasEmpty(const int *board){
    int index = 0;
    for(index=0; index < 9; index++){
        if( board[ConvertTo25[index]] == EMPTY) return 1;
    }
    return 0;
}

void MakeMove(int *board, const int sq, const int side){
    board[sq] = side;
}


void Start(){
    
    int GameOver = 0;
    int Side = CERCLE;
    int LastMoveMade = 0;
    int board[25];

    InitialiseBoard(&board[0]);
    PrintBoard(&board[0]);


    while(!GameOver){
        if(Side == CERCLE){
            GetHumanMove(&board[0]);
            // get move from human, make move on board, change side
        } else {
            // get move from computer, make move on board, change side
            PrintBoard(&board[0]);
        }

        // if three in a row exists Game is over

        // if no more moves, game is a draw
        GameOver =1; // Remove ME !!
    }
}


void demande() {
    printf("1. Play\n");
    printf("2. How to play\n");
    printf("3. Quit\n");

    // Variable used to store the user choice
    int choice;

    // Get and save the number the user types
    scanf("%d", &choice);
    while (getchar() != '\n');

    switch (choice) {
    case 1:
        printf("You chose to play!\n\n\n");
        Start(); 
        break;
    case 2:
        flushConsole();
        printf("You chose the instructions menu!\n\n");
        const char *instructions = getInstructions();
        flushConsole();

        printf("%s\n", instructions);
        printf("1. Back\n");
        int choice2;
        scanf("%d", &choice2);
        if (choice2 == 1) {
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
    srand(time(NULL));

    printf("Hello and welcome to Tic Tac Toe made by Love-Fromage!\n\n");
    demande();

    return 0;
}

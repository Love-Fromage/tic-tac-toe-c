#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


const char* getInstructions(){
    // Using a character array
    
    return "You always start as the X, therefore they are the first\n\
to play. Each cell is reprensented by a number. To place your X simply\n\
put input the number of the cell. Then it is the computer's turn.\n";
}

void demande(){
   printf("1. Play\n");
   printf("2. How to play\n");
   printf("3. Quit\n");

   // Variable used to store the user choice
   int choice;

   // Get and save the number the user types
   scanf("%d", &choice);


    switch (choice)
    {
    case 1:
        printf("You chose to play!\n");
        break;
    case 2:
        printf("You chose the instructions menu!\n\n");
        const char* instructions = getInstructions();
        // Here i print the instructions
        printf("%s\n", instructions);
        printf("1. Back\n");
        int choice2;
        scanf("%d", &choice2);
        if(choice2 == 1){
            demande();
        }
        break;
    case 3:
        printf("You chose to quit the game!\n");
        exit(0);
        break;
    
    default:
    printf("wrong value");
    demande();
        break;
    }
   

}


int main(){

    /*
    This is the game of tic-tac-toe played in the terminal/console 


    It is a project to learn C in a fun way
    */    


   printf("Hello and welcome to Tic Tac Toe made by Love-Fromage!\n\n");
   demande();
   

    return 0;
}

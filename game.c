#include <stdio.h>
#include <stdlib.h>


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
        printf("You chose the instructions menu!\n");
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

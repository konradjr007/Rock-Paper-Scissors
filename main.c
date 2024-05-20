//Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
 
// Function to implement the game
int game(char you, char computer) {
    if (you == computer) {                        // If both the user and computer has choose the same thing
        return 2;
    } else if (you == 's' && computer == 'p') {   // If user's choice is stone and computer's choice is paper
        return -1;
    } else if (you == 's' && computer == 'z') {   // If user's choice is stone and computer's choice is scissor
        return 1;
    } else if (you == 'p' && computer == 's') {   // If user's choice is paper and computer's choice is stone
        return 1;
    } else if (you == 'p' && computer == 'z') {   // If user's choice is paper and computer's choice is scissor
        return -1;
    } else if (you == 'z' && computer == 's') {   // If user's choice is scissor and computer's choice is stone
        return -1;
    } else if (you == 'z' && computer == 'p') {   // If user's choice is scissor and computer's choice is paper
        return 1;
    }
}

// Driver Code
int main() {
    // Stores the random number
    int n;
    char you, computer, result;
     // Chooses the random number
    // every time
    srand(time(NULL));
    // Make the random number less
    // than 100, divided it by 100
    n = rand() % 100;
    // Using simple probability 100 is
    // roughly divided among stone,
    // paper, and scissor
    if (n < 33) {
        computer = 's'; // s is denoting Stone
    } else if (n > 33 && n < 66) {
        computer = 'p'; // p is denoting Paper
    }     // z is denoting Scissor
    else {
        computer = 'z';
    }
    do {
        printf("\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");
        // input from the user
        scanf(" %c", &you);
        // Function Call to play the game
        result = game(you, computer);
        if (result == 1) {
            system("cls");
            printf("\n\n\t\t\t\tWow! You have won the game!\n");
        }
        else if (result == -1) {
            system("cls");
            printf("\n\n\t\t\t\tOh! You have lost the game!\n");
        } else if (result == 2) {
            system("cls"); 
            printf("\n\n\t\t\t\tOh! Draw! Play Again...\n");
        }
        printf("\t\t\t\tYou choose : %c and Computer choose : %c\n",you, computer);
    } while (result==2);
    
    printf("\n\n\n\t\t\tPress Enter to continue...\t");
    getchar();getchar();
    return 0;
}
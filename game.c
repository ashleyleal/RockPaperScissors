/** game.c
 * 
 * play rock paper scissors
 *
 * 02/22/23      
 * Ashley Leal
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// returns either 'r', 'p', or 's' for rock, paper or scissors
char getComputersChoice() {
    // generate random number based on time (seeded)
    srand(time(NULL));

    int randomNumber = (rand() % 3) + 1;
    char computersChoice;

    switch (randomNumber) {
        case 1:
            computersChoice = 'r';
            break;
        case 2:
            computersChoice = 'p';
            break;
        case 3:
            computersChoice = 's';
            break;
    }

    return computersChoice;
}

// function to get user input
char getUserInput() {
    char userInput;

    printf("Enter your choice\n(r for rock, p for paper, s for scissors): ");
    scanf(" %c", &userInput);

    userInput = tolower(userInput);

    return userInput;
}

// return either 'w', 'l' or 'd' for win, loss and draw
char getResult(char userPick, char computerPick) {
    // condition for user to draw
    if (computerPick == userPick) {
        return 'd';
    }

    // all winning conditions
    else if (userPick == 'p' && computerPick == 'r') {
        return 'w';
    } else if (userPick == 'r' && computerPick == 's') {
        return 'w';
    } else if (userPick == 's' && computerPick == 'p') {
        return 'w';
    }

    // all other conditions result in user losing
    else {
        return 'l';
    }
}

int main() {
    
    // game status
    bool playing = true;
    char playAgain;

        do {
        // generate computer's choice
        char computerPick = getComputersChoice();

        // get input until user enters valid input - 'r', 'p', 's'
        char userPick;
        while (true) {
            userPick = getUserInput();
            if (userPick == 'r' || userPick == 'p' || userPick == 's') {
                break;
            }
        }

        char result = getResult(userPick, computerPick);

        // print result
        switch (result) {
            case 'w':
                printf("Computer's pick: %c\n", computerPick);
                printf("Your pick: %c\n", userPick);
                printf("You won\n");
                break;
            case 'l':
                printf("Computer's pick: %c\n", computerPick);
                printf("Your pick: %c\n", userPick);
                printf("You lose\n");
                break;
            case 'd':
                printf("Computer's pick: %c\n", computerPick);
                printf("Your pick: %c\n", userPick);
                printf("Draw\n");
                break;
        }

        printf("Play again?\n(y for yes, n for no):");
        scanf(" %c", &playAgain);

        switch (playAgain) {
            case 'y':
                continue;
            case 'n':
                printf("Thanks for playing");
                playing = false;
        }
    }
    while (playing);

    return 0;
}

/*** end of file ***/
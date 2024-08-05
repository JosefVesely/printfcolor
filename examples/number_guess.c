#include "../printfcolor.h"

#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int number = rand() % 100 + 1; // Random number between 1 and 100

    printfc_bg(BLUE, "Guess the number game\n\n");

    while (true) {
        printfc_fg(CYAN, "Your guess: ");

        int guess;
        scanf("%i", &guess);

        if (guess < number) {
            printfc_fg(GREEN, "^^^ Higher ^^^\n");
        }
        else if (guess > number) {
            printfc_fg(RED, "vvv Lower vvv\n");
        }
        else {
            printfc(GRAY, YELLOW, "Congratulations! You guessed the number.\n"); 

            printfc_fg(YELLOW, "The number is %i\n", number);
            break;
        }
        printf("\n");
    }
}
// Simple Stone Paper Scissor game
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game function
int game(char you, char computer)
{
    // Same choice
    if (you == computer)
        return -1;

    // Stone vs Paper
    if (you == 's' && computer == 'p')
        return 0;
    else if (you == 'p' && computer == 's')
        return 1;

    // Stone vs Scissor
    if (you == 's' && computer == 'z')
        return 1;
    else if (you == 'z' && computer == 's')
        return 0;

    // Paper vs Scissor
    if (you == 'p' && computer == 'z')
        return 0;
    else if (you == 'z' && computer == 'p')
        return 1;
}

// Main function
int main()
{
    int n;
    char you, computer, result;

    // Random number setup
    srand(time(NULL));
    n = rand() % 100;

    // Computer choice
    if (n < 33)
        computer = 's';
    else if (n > 33 && n < 66)
        computer = 'p';
    else
        computer = 'z';

    printf("\nEnter s for STONE, p for PAPER and z for SCISSOR\n");

    // User input
    scanf("%c", &you);

    // Play game
    result = game(you, computer);

    if (result == -1)
        printf("Game Draw!\n");
    else if (result == 1)
        printf("You won the game!\n");
    else
        printf("You lost the game!\n");

    printf("You choose : %c and Computer choose : %c\n", you, computer);

    return 0;
}

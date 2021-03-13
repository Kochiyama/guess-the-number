#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declarar uma constante
#define ATTEMPTS_NUMBER 5

int main() {
  int secretNumber, playerGuess, bigger, attempt;
  double points, lostpoints;

  printf("***************************\n");
  printf("* GUESS THE SECRET NUMBER *\n");
  printf("***************************\n");

  int secondsPastTimeStamp = time(0);

  // set the seed for pseudo random number generation
  srand(secondsPastTimeStamp);

  // Generate random number (not so random right now)
  secretNumber = rand() % 100;
  attempt = 0;
  points = 1000;

  while (playerGuess != secretNumber) {

    attempt++;

    // Show player attempt
    printf("Attempt %d\n", attempt);
    
    // Store player guess
    printf("Wich is the secret number? ");
    scanf("%d", &playerGuess);

    if (playerGuess == secretNumber) {
      printf("Congratulations! You hit! You used %d atempts.\n ", attempt);
      printf("You did %.2f points.", points);
      break;
    }

    // Ensure player guess is not an negative number
    if (playerGuess < 0) {
      printf("Negative numbers are not accepted!");
      attempt--;

      continue;
    }
    
    bigger = (playerGuess < secretNumber);

    // Player miss the guess
    printf("Oops! You missed. ");

    if (bigger) {
      printf("The secret number is bigger than that! \n");
    } 
    else {
      printf("The secret number is lower than that! \n");
    }

    points -= abs((double)(playerGuess - secretNumber) / (double)2);

    printf("******************************************************\n");
  }
}



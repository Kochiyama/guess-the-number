#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declarar uma constante
#define ATTEMPTS_NUMBER 5

int main() {
  printf("***************************\n");
  printf("* GUESS THE SECRET NUMBER *\n");
  printf("***************************\n");

  int secretNumber, playerGuess, bigger, attempt, attemptLimits, difficulty;
  double points, lostpoints;

  // set the seed for pseudo random number generation
  srand(time(0));

  // Generate random number
  secretNumber = rand() % 100;
  points = 1000;

  printf("Selecione o nível de dificuldade\n");
  printf("(1) Fácil | (2) Médio | (3) Difícil\n\n");
  printf("Escolha: ");
  scanf("%d", &difficulty);

  switch (difficulty)
  {
  case 1:
    attemptLimits = 20;
    break;

  case 2:
    attemptLimits = 15;
    break;

  case 3:
    attemptLimits = 6;
    break;

  default:
    printf("Escolha inválida! Utilizando dificuldade médio.\n");
    attemptLimits = 15;
    break;
  }

  for (int attempt = 1; attempt <= attemptLimits; attempt++)
  {
    // Show player attempt
    printf("Attempt %d\n", attempt);
    
    // Store player guess
    printf("Wich is the secret number? ");
    scanf("%d", &playerGuess);

    // Ensure player guess is not an negative number
    if (playerGuess < 0) {
      printf("Negative numbers are not accepted!");
      attempt--;

      continue;
    }

    if (playerGuess == secretNumber) {
      printf("Congratulations! You hit! You used %d atempts.\n ", attempt);
      printf("You did %.2f points.", points);
      break;
    } 

    // Player miss the guess
    printf("Oops! You missed. ");

    if (playerGuess < secretNumber) {
      printf("The secret number is bigger than that! \n");
    } 
    else {
      printf("The secret number is lower than that! \n");
    }

    points -= abs((double)(playerGuess - secretNumber) / (double)2);

    printf("******************************************************\n");
  }
}



#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int checkGuess();

int main(int argc, char *argv[]) {
  srand(time(NULL)); // need to seed time at every exec

  int guess;
  int randomNumber = (rand() % 10) + 1;

  printf("Welcome the the guessing game!\n");
  printf("Pick a number 1-10\n"); 

  scanf("%d", &guess);

  while (checkGuess(guess, randomNumber) != 0) {
    if (checkGuess(guess, randomNumber) == 1) {
      printf("Oh! Too small! ");
    } 
    if (checkGuess(guess, randomNumber) == 2) {
      printf("Oh! Too big! ");
    } 
    printf("You've guessed: %d\nBetter try again!\n", guess);
    scanf("%d", &guess);
  }

  printf("Good job! You've guessed: %d\n", guess);
  printf("Random number is: %d\n", randomNumber);

  return 0;
}

int checkGuess(int guess, int rando) {
  if (guess == rando) {
    return 0;
  } else if (guess < rando) {
    return 1;
  } else {
    return 2;
  }
}

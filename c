#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int checkGuess();
void generate();
void play();


int main(int argc, char *argv[]) {
  int c;
  int gflag = 0;

  srand(time(NULL)); // need to seed time at every exec
  int randomNumber = (rand() % 10) + 1;

  opterr = 0;

  while ((c = getopt(argc, argv, "g")) != -1) {
    switch(c) {
      case 'g':
        gflag = 1;
        break;
      case '?': 
        fprintf (stderr, 
                 "Unknown option `-%c'.\n", 
                 optopt);
        return 1;
      default:
        abort();
      }
  }

  if (gflag == 1)
    play(randomNumber);
  else 
    generate(randomNumber);

  return 0;
}


void play(int randomNumber) {
  int guess;

  printf("Welcome the the guessing game!\n");
  printf("Pick a number 1-10\n"); 

  scanf("%d", &guess);

  while (checkGuess(guess, randomNumber) != 0) {
    if (checkGuess(guess, randomNumber) == -1) {
      printf("Pick a number between 1-10! ");
    } 
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
  return;
}


int checkGuess(int guess, int rando) {
  if (guess < 1 || guess > 10) {
    return -1;
  } else if (guess == rando) {
    return 0;
  } else if (guess < rando) {
    return 1;
  } else {
    return 2;
  }
}

void generate(int rando) {
  printf("Here is your random number: %d\nInput -g flag for some fun\n", 
         rando);
  return;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome();
void chose_mode();
void solo_mode();
void duo_mode();
void bye();
// Define the clear command based on the operating system
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else // Assume POSIX (Linux, macOS, etc.)
#define CLEAR_SCREEN "clear"
#endif

int main() {
  welcome();
  chose_mode();

  bye();
}

void welcome() { printf("Welcome to the pendu game \n"); };
void chose_mode() {
  static int mode = 1; // 1 = Solo ; // 2 = Duo
  printf("Choose your mode \n1. Solo \n2. Duo \n");
  scanf("%d", &mode);

  if (mode == 1) {
    solo_mode();
  } else {
    duo_mode();
  }
}
void solo_mode() {
  unsigned int random, guess, attempts = 0;
  srand(time(NULL));

  random = (rand() % 10000) + 1;

  do {
    printf("Guess the number(1-10000) \n");
    scanf("%d", &guess);

    attempts++;

    if (guess < random)
      printf("Too low \n");
    if (guess > random)
      printf("Too high \n");
    if (guess == random) {
      printf("Perfect!! You guess it in %d attempts \n", attempts);
    }

  } while (guess != random);
}

void duo_mode() {
  unsigned int guessing_number, guess, attempts = 0;

  printf("PLAYER 1: Enter the guessing number: ");
  scanf("%d", &guessing_number);

  system(CLEAR_SCREEN);

  do {
    printf("PLAYER 2: Guess the number :");
    scanf("%d", &guess);

    attempts++;

    if (guess < guessing_number)
      printf("Too low \n");
    if (guess > guessing_number)
      printf("Too high \n");
    if (guess == guessing_number) {
      printf("Perfect!! You guess it in %d attempts \n", attempts);
    }

  } while (guess != guessing_number);
}

void bye() {
  printf("\n\nBye Bye \n");
  printf("Developped by Epoundor\n");
}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcome();

int main() {
  int isFinished = 0;

  int progress_bar_width = 100;
  int steps = 100;
  int current_step = 0;

  while (isFinished == 0) {
    float random = 0;
    srand(time(NULL));

    system("clear");
    welcome();
    printf("[PROCESS 1]: [");

    random = ((rand() * 1.0) / RAND_MAX);

    char c = '=';
    int no_repetitions = round((current_step * progress_bar_width) / steps);
    for (int i = 0; i < no_repetitions; i++) {
      printf("%c", c);
    }

    for (int i = 0; i < progress_bar_width - no_repetitions; i++) {
      printf(" ");
    }
    printf("] %d/%d \n", current_step, steps);

    char command[50];
    sprintf(command, "sleep %f", random);
    system(command);

    current_step += rand() % 10;

    if (current_step >= steps) {
      isFinished = 1;
    }
  }
}

void welcome() {
  printf("\n\n---------------------------------------------- \n");

  printf("Welcome to progress bar \n\n");
};

#include <stdio.h>

void welcome();
void print_menu();
void bye();

int main() {
  int operation;
  double first, second, result;

  while (1) {
    welcome();
    print_menu();
    scanf("%d", &operation);

    if (operation == 0) {
      break;
    }

    printf("Please, enter the first number : ");
    scanf("%lf", &first);

    printf("Please, enter the second number : ");
    scanf("%lf", &second);

    switch (operation) {
    case 1:
      result = first + second;
      break;
    case 2:
      result = first - second;
      break;
    case 3:
      result = first * second;
      break;
    }

    printf("The result id %lf", result);
    break;
  }

  bye();
}

void welcome() {
  printf("\n\n---------------------------------------------- \n");

  printf("Welcome to simple calculator \n");
};

void print_menu() {
  printf("0. Exit\n1. Add\n2. Substract\n3. Multiply \n");
  printf("Choose on of the following operation : ");
}

void bye() {
  printf("\n\nBye Bye \n");
  printf("Developped by Epoundor\n");
}
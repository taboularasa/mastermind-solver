#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"

size_t guess_size = 5;

void prompt(char *result, char *current_guess)
{
  printf("Next guess: %s\n", current_guess);
  puts("Enter results: ");

  int bytes_read;
  bytes_read = getline(&result, &guess_size, stdin);

  if (bytes_read == -1)
  {
    exit(EXIT_FAILURE);
  }
}

void input_loop() {
  char *current_guess = "1122";
  char *my_string;
  my_string = (char *)malloc(guess_size + 1);
  while (1)
  {
    prompt(my_string, current_guess);
    if (strcmp(my_string, "WWWB\n") == 0)
    {
      puts("The results were: ");
      puts(my_string);
    }
  }
}

int main()
{
  input_loop();
}

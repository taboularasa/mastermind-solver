#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"

size_t guess_size = 5;

void test_build_guesses()
{
  Guess *n = build_guesses();
  while (n != NULL)
  {
    printf("%s\n", n->data);
    n = n->next;
  }
}

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

//
//void prune_s(char *result, char *current_guess, Guess *S)
//{
//  // use current_guess as code to evaluate the rest of S against
//  // remove any potential guesses that get the same score as result
//}

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

void test_evaluate() {
  evaluation_pair w1b0 = {.code = {3, 4, 3, 1}, .guess = {1, 1, 2, 2}};
  puts("should be: w_score == 1, b_score == 0");
  evaluate(w1b0);

  evaluation_pair w0b4 = {.code = {3, 4, 3, 1}, .guess = {3, 4, 3, 1}};
  puts("should be: w_score == 0, b_score == 4");
  evaluate(w0b4);

  evaluation_pair w4b0 = {.code = {3, 4, 2, 1}, .guess = {1, 3, 4, 2}};
  puts("should be: w_score == 4, b_score == 0");
  evaluate(w4b0);
}

int main()
{
  // test_build_guesses();

  test_evaluate();

  // input_loop();
}

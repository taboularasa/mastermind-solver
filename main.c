#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Guess
{
  char data[5];
  struct Guess *next;
};

size_t guess_size = 5;

struct Guess* build_guesses()
{
  struct Guess *guess_list = (struct Guess *)malloc(sizeof(struct Guess));
  struct Guess *prev = (struct Guess *)malloc(sizeof(struct Guess));
  strcpy(guess_list->data, "1122");
  guess_list->next = prev;

  for (int i = 1; i < 7; i++)
  {
    for (int j = 1; j < 7; j++)
    {
      for (int k = 1; k < 7; k++)
      {
        for (int l = 1; l < 7; l++)
        {
          char buf[5];
          sprintf(buf, "%d%d%d%d", i, j, k, l);
          strcpy(prev->data, buf);
          struct Guess *next = (struct Guess *)malloc(sizeof(struct Guess));
          next->next = NULL;
          prev->next = next;
          prev = next;
        }
      }
    }
  }

  return guess_list;
}

void test_build_guesses()
{
  struct Guess *n = build_guesses();
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

int main()
{
  test_build_guesses();

  char *my_string;
  my_string = (char *)malloc(guess_size + 1);
  char *current_guess = "1122";
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

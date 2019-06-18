#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Guesses
{
  char all[1296][5];
  char reduced[1296][5];
};

size_t guess_size = 5;

struct Guesses build_guesses()
{
  struct Guesses guesses;
  int index = 0;
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
          strcpy(guesses.all[index], buf);
          index++;
        }
      }
    }
  }

  return guesses;
}

void test_build_guesses()
{
  struct Guesses guesses = build_guesses();

  for (int i = 0; i < 1296; i++)
  {
    puts(guesses.all[i]);
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

void reduce_guesses(struct Guesses guesses)
{

}

int main()
{
  // test_build_guesses();
  struct Guesses guesses = build_guesses();

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

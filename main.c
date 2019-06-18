#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Guesses
{
  char all[1296][5];
};

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

void prompt()
{
  int bytes_read;
  size_t nbytes = 5;
  char *my_string;
  my_string = (char *)malloc(nbytes + 1);

  puts("Next guess: RGBB");
  puts("Enter results: ");

  bytes_read = getline(&my_string, &nbytes, stdin);

  if (bytes_read == -1)
  {
    puts("ERROR!");
  }
  else if (strcmp(my_string, "WWWB\n") == 0)
  {
    puts("The results were: ");
    puts(my_string);
  }
  else
  {
    puts("fail");
    exit(EXIT_FAILURE);
  }

}

int main()
{
  // test_build_guesses();
  struct Guesses guesses = build_guesses();
  prompt();
}

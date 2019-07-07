#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "solver.h"

Guess *build_guesses()
{
  Guess *guess_list = (Guess *)malloc(sizeof(Guess));
  Guess *prev = (Guess *)malloc(sizeof(Guess));
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
          Guess *next = (Guess *)malloc(sizeof(Guess));
          next->next = NULL;
          prev->next = next;
          prev = next;
        }
      }
    }
  }

  return guess_list;
}

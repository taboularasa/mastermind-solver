#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "solver.h"

Guess* build_guesses()
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
          sprintf(prev->data, "%d%d%d%d", i, j, k, l);
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



void evaluate(evaluation_pair p)
{
  int code_length = sizeof(p.code) / sizeof(p.code[0]);
  if (code_length != 4)
  {
    printf("code not correct length");
    exit(EXIT_FAILURE);
  }
  int guess_length = sizeof(p.guess) / sizeof(p.guess[0]);
  if (code_length != guess_length) {
    printf("guess not correct length");
    exit(EXIT_FAILURE);
  }

  int w_score = 0;
  int b_score = 0;
  int code_counts[6] = {0, 0, 0, 0, 0, 0};
  int guess_counts[6] = {0, 0, 0, 0, 0, 0};

  for (int i = 0; i < code_length; i++)
  {
    char code_letter = p.code[i];
    char guess_letter = p.guess[i];
    if (code_letter == guess_letter)
    {
      b_score++;
    }

    code_counts[p.code[i]]++;
    guess_counts[p.guess[i]]++;
  }

  for (int i = 0; i < 6; i++)
  {
    if (guess_counts[i] < code_counts[i]) {
      w_score += guess_counts[i];
    } else {
      w_score += code_counts[i];
    }
  }

  w_score = w_score - b_score;

  printf("w_score == %d\n", w_score);
  printf("b_score == %d\n", b_score);
}

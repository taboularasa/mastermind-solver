#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "solver.h"

Guess* build_guesses()
{
  Guess *prev = (Guess *)malloc(sizeof(Guess));
  Guess *head = prev;
  int count = 0;
  for (int i = 1; i < 7; i++)
  {
    for (int j = 1; j < 7; j++)
    {
      for (int k = 1; k < 7; k++)
      {
        for (int l = 1; l < 7; l++)
        {
          count++;
          prev->data[0] = i;
          prev->data[1] = j;
          prev->data[2] = k;
          prev->data[3] = l;
          if (count < 1296) {
            Guess *next = (Guess *)malloc(sizeof(Guess));
            next->next = NULL;
            prev->next = next;
            prev = next;
          } else {
            prev->next = NULL;
          }
        }
      }
    }
  }

  return head;
}

Score evaluate(EvaluationPair p)
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

  Score score = {.white = 0, .black = 0};
  int code_counts[6] = {0, 0, 0, 0, 0, 0};
  int guess_counts[6] = {0, 0, 0, 0, 0, 0};

  for (int i = 0; i < code_length; i++)
  {
    char code_letter = p.code[i];
    char guess_letter = p.guess[i];
    if (code_letter == guess_letter)
    {
      score.black++;
    }

    code_counts[p.code[i]]++;
    guess_counts[p.guess[i]]++;
  }

  for (int i = 0; i < 6; i++)
  {
    if (guess_counts[i] < code_counts[i]) {
      score.white += guess_counts[i];
    } else {
      score.white += code_counts[i];
    }
  }

  score.white = score.white - score.black;

  return score;
}

// void eliminate(Guess *guesses, Guess guess, Score score)
// {
//   Guess *n = &guesses;
//   while (n != NULL)
//   {
//     Guess *next = n->next;

//   }
// }

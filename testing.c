#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "solver.h"

void test_build_guesses()
{
  Guess *n = build_guesses();
  int count = 0;
  while (n != NULL)
  {
    count++;
    n = n->next;
  }
  assert(count == 1296);
  puts("build_guesses tested successfully");
}

void test_evaluate()
{
  EvaluationPair w1b0 = {.code = {3, 4, 3, 1}, .guess = {1, 1, 2, 2}};
  Score score = evaluate(w1b0);
  assert(score.white == 1);
  assert(score.black == 0);
  printf("code %d, %d, %d, %d\n", w1b0.code[0], w1b0.code[1], w1b0.code[2], w1b0.code[3]);
  printf("guess %d, %d, %d, %d\n", w1b0.guess[0], w1b0.guess[1], w1b0.guess[2], w1b0.guess[3]);
  printf("score.white %d\n", score.white);
  printf("score.black %d\n", score.black);

  EvaluationPair w0b4 = {.code = {3, 4, 3, 1}, .guess = {3, 4, 3, 1}};
  score = evaluate(w0b4);
  assert(score.white == 0);
  assert(score.black == 4);

  EvaluationPair w4b0 = {.code = {3, 4, 2, 1}, .guess = {1, 3, 4, 2}};
  score = evaluate(w4b0);
  assert(score.white == 4);
  assert(score.black == 0);

  puts("evaluate tested successfully");
}

int main()
{
  test_build_guesses();

  test_evaluate();
}

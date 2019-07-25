#ifndef SOLVER_H
#define SOLVER_H

typedef struct Guess
{
  char data[5];
  struct Guess *next;
} Guess;

typedef struct evaluation_pair
{
  int code[4];
  int guess[4];
} evaluation_pair;

    Guess *
    build_guesses();

void evaluate(evaluation_pair p);

#endif // SOLVER_H

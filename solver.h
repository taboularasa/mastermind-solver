#ifndef SOLVER_H
#define SOLVER_H

typedef struct Guess
{
  char data[5];
  struct Guess *next;
} Guess;

Guess *build_guesses();

#endif // SOLVER_H

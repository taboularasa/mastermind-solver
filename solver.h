#ifndef SOLVER_H
#define SOLVER_H

typedef struct Guess
{
  int data[4];
  struct Guess *next;
} Guess;

typedef struct EvaluationPair
{
  int code[4];
  int guess[4];
} EvaluationPair;

typedef struct Score
{
  int black;
  int white;
} Score;

Guess * build_guesses();
Score evaluate(EvaluationPair p);
// void eliminate(Guess *guesses, Guess guess);

#endif // SOLVER_H

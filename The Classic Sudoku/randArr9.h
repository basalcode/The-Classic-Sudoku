#ifndef RAND_ARR9_H
#define RAND_ARR9_H

typedef enum _START
{
	NUM_0to8 = 0,
	NUM_1to9
} START;

int randArr9_randomNumber(START num);
int* randArr9_randomNumberArr(START num);

#endif

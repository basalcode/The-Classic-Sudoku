#ifndef SET_MATRIX_H
#define SET_MATRIX_H

#include <stdbool.h>

#include "setDataStructure.h"

bool setMatrix_setAnswerMatrix(int** matrix, int majorNum, int minorNum);
void setMatrix_setQuestionMatrix(int** answerMatrix, int** questionMatrix, PDATA data);
void setMatrix_setRandomMatrixLocation(int* arr, int max_i, int max_j);
void setMatrix_freeMatrixArr(int** matrix);

#endif 

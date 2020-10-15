#ifndef GET_MATRIX_H
#define GET_MATRIX_H

int** getMatrix_allocInitMatrixArr();
int** getMatrix_copy2DMatrix(int** matrix);
int* getMatrix_getColNumber(int** matrix, int col, int row);
int* getMatrix_getRowNumber(int** matrix, int col, int row);
int* getMatrix_getSectNumber(int** matrix, int col, int row);
int* getMatrix_getPossibleArr(int** matrix, int col, int row);

int** getMatrix_allocInitMatrixLocationArr(int difficult);
int** getMatrix_randomLocationType(int difficulty);
int** getMatrix_symmetryTypeA(int difficulty);
int** getMatrix_symmetryTypeB(int difficulty);
int** getMatrix_symmetryTypeC(int difficulty);
int** getMatrix_symmetryTypeD(int difficulty);

#endif 

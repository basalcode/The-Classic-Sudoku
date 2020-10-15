#ifndef GET_MATRIX_TEXT_NODE_H
#define GET_MATRIX_TEXT_NODE_H

#include "setMatrixTextNode.h"

typedef enum _BorL
{
	BLANK = 0,
	LINE
} BorL;

char* getMatrixTextNode_allocInitArr();
PMATRIX_NODE getMatrixTextNode_allocInitMatrixStruct();
char* getMatrixTextNode_topNode(PDATA data);
char* getMatrixTextNode_middleNode(BorL blankOrLine, PDATA data);
char* getMatrixTextNode_bottomNode(PDATA data);
char* getMatrixTextNode_arrToString(int* matrix, PDATA data);

#endif

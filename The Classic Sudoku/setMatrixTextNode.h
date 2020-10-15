#ifndef SET_MATRIX_TEXT_NODE_H
#define SET_MATRIX_TEXT_NODE_H

#include "setDataStructure.h"

typedef struct _MATRIX_NODE
{
	struct _MATRIX_NODE *nextNode;
	char* str;
} MATRIX_NODE, *PMATRIX_NODE;

void setMatrixTextNode_setLinkedList(PMATRIX_NODE list, int** matrix, PDATA data);
void setMatrixTextNode_addNodeToEnd(PMATRIX_NODE list, char* str);
void setMatrixTextNode_addNodeToStart(PMATRIX_NODE list, char* str);
void setMatrixTextNode_freeNodes(PMATRIX_NODE list);

#endif

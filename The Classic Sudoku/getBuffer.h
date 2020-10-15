#ifndef GET_BUFFER_H
#define GET_BUFFER_H

#include "setTextNode.h"
#include "setMatrixTextNode.h"

char** getBuffer_textNode(PSTR_NODE list, int height, int width);
char** getBuffer_completedTextNode(PSTR_NODE list, int boxWidthSize);
char** getBuffer_matrixTextNode(PMATRIX_NODE list);

#endif
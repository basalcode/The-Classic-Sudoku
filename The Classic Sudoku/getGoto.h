#ifndef GET_GOTO_H
#define GET_GOTO_H

#include "setTextNode.h"

int** getGoto_cursorLocation(char** buffer, int choiseNum);
int** getGoto_cursorLocation_Node(PSTR_NODE list, int choiseNum, int start_i, int start_j);
int** getGoto_cursorLocation_playScreen();

#endif
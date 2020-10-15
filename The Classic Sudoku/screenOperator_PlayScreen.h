#ifndef SCREEN_OPERATOR_PLAY_SCREEN_H
#define SCREEN_OPERATOR_PLAY_SCREEN_H

#include "setDataStructure.h"
#include "setTextNode.h"

int screenOperator_driectionKeyboard_playScreen(int** move, int max, int pos, int keyBoard);
void screenOperator_PlayScreen(PDATA data);
char** buffer_screenTextToBuffer_PlayScreen(int** answerMatrix, int** questionMatrix, PDATA data);

#endif

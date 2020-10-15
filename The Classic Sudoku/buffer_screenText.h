#ifndef BUFFER_SCREEN_TEXT_H
#define BUFFER_SCREEN_TEXT_H

#include "setTextNode.h"
#include "setDataStructure.h"

char** buffer_screenTextToBuffer(void (*fp)(PSTR_NODE));
char** buffer_screenTextToBuffer_rate(void(*fp)(PSTR_NODE, PDATA), PDATA data);
char** buffer_screenTextToBuffer_PlayScreen(int** answerMatrix, int** questionMatrix, PDATA data);

#endif

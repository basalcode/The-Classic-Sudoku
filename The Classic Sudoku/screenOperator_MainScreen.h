#ifndef SCREEN_OPERATOR__MAIN_SCREEN_H
#define SCREEN_OPERATOR__MAIN_SCREEN_H

#include "getDataStructure.h"
#include "setDataStructure.h"

int screenOperator_driectionKeyboard(int** move, int moveMax, int keyBoard, int pos);
int screenOperator_driectionKeyboard_notRemove(int** move, int moveMax, int keyBoard, int pos);
void screenOperator_MainScreen(PDATA data);

#endif
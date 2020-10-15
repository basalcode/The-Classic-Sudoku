#ifndef SCREEN_TEXT__MAIN_SCREEN__CHECK_RATE_H
#define SCREEN_TEXT__MAIN_SCREEN__CHECK_RATE_H

#include "setTextNode.h"
#include "setDataStructure.h"

void screenText_MainScreen_CheckRate_Page1(PSTR_NODE list, PDATA data);
void screenText_MainScreen_CheckRate_Page2(PSTR_NODE list, PDATA data);
void screenText_MainScreen_CheckRate_Page3(PSTR_NODE list, PDATA data);

PSTR_NODE screenText_MainScreen_CheckRate_BoxedSumRate(PDATA data);
PSTR_NODE screenText_MainScreen_CheckRate_ShowLevel(PDATA data);

char* screenText_MainScreen_CheckRate_LevelBarTop(PDATA data);
char* screenText_MainScreen_CheckRate_LevelBarMiddle(PDATA data);
char* screenText_MainScreen_CheckRate_LevelBarBottom(PDATA data);

#endif

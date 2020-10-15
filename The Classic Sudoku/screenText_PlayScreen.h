#ifndef SCREEN_TEXT__PLAY_SCREEN_H
#define SCREEN_TEXT__PLAY_SCREEN_H

#include "setTextNode.h"
#include "setMatrixTextNode.h"
#include "setDataStructure.h"

#define DIRECTION_KEY_COMMON(key) (key == 0 || key == 0xE0 || key == -32)

typedef enum _KEYBOARD
{
	UP_ = 72,
	DOWN_ = 80,
	LEFT_ = 75,
	RIGHT_ = 77,
	ENTER_ = 13,
	ESCAPE_ = 27,
	OPTION_ = 111,
	ERASE_ = 8,
	DELETE_ = 83
} KEYBOARD;

void screenText_PlayScreen_Matrix(int** answerMatrix, int** questionMatrix, PMATRIX_NODE list, PDATA data);
void screenText_PlayScreen_ControlScreen(PSTR_NODE list);

void screenText_PlayScreen_StateScreen(PSTR_NODE list, PDATA data);
void screenText_PlayScreen_StateScreenScript_print(PSTR_NODE list);
void screenText_PlayScreen_StateScreenScript_Input(PSTR_NODE list, bool numberExist, int i, int j, int matrix);
void screenText_PlayScreen_StateScreenScript_Remove(PSTR_NODE list, bool initNumber, bool numberExist, int i, int j, int matrix);
void screenText_PlayScreen_StateScreenScript_ExtraKey(PSTR_NODE list, int keyBoard, int max);
void screenText_PlayScreen_StateScreenScript_ExtraKey_Out(PSTR_NODE list, int index);

void screenText_PlayScreen_HintsScreen(PSTR_NODE list, PDATA data);
void screenText_PlayScreen_HintScreenScript(int* hintArr, PDATA data, int i, int j, bool generate);

void screenText_PlayScreen_OptionScreen(PDATA data);
int screenText_PlayScreen_OptionScreen_move(int** move, int moveMax, int pos, int keyBoard);

bool screenText_PlayScreen_EnterScreen_Win(PDATA data, int start_i, int start_j);
bool screenText_PlayScreen_EnterScreen_Lost(int max, int level, int start_i, int start_j);
bool screenText_PlayScreen_EnterScreen_GameOver(int level, int start_i, int start_j);
bool screenText_PlayScreen_EscapeScreen(int level, int start_i, int start_j);

#endif

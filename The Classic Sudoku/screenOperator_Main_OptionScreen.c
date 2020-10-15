// screenOperator_Main_OptionScreen.c ��Ʈ��

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>
#include <conio.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

#include "screenOperator_Main_OptionScreen.h"

#include "buffer_screenText.h"
#include "setBuffer.h"
#include "getBuffer.h"
#include "getTextNode.h"
#include "printBuffer.h"
#include "screenOperator_MainScreen.h"
#include "ScreenText_MainScreen_Option.h"

#include "getDataStructure.h"
#include "setDataStructure.h"

#include "getGoto.h"
#include "setGoto.h"

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 77

#define DIRECTION_KEY_COMMON(key) (key == 0 || key == 0xE0 || key == -32)

#define ENTER_KEY 13
#define ESCAPE_KEY 27

#define MOVE_SET (setGoto_setCursor(move[pos][I], move[pos][J]))
#define I 0
#define J 1


#define DIRECTORY_NAME "C:\\Users\\SEC\\Desktop\\TestFolder"


void screenOperator_MainScreen_Option_Main(PDATA data)
{
	int max = 4;

	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_Main);
	int** move = getGoto_cursorLocation(buffer, max);

	char keyBoard;
	int pos = 0;
BACK:
	// ȭ�� ���.
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);

	MOVE_SET;
	printf("V");

	setDataStructure_saveStructure(data);

	while (1)
	{
		keyBoard = _getch();
		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard(move, max, keyBoard, pos);
		}
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			case 0: // 1. ���̵� ����
			{
				screenOperator_MainScreen_Option_Difficulty_Page1(data);
				goto BACK;
			}
			case 1: // 2. �⺻�� ����
			{
				screenOperator_MainScreen_Option_NumberSetting_Page1(data);
				goto BACK;
			}
			case 2: // 3. ������ ����
			{
				screenOperator_MainScreen_Option_SaveSheet(data);
				goto BACK;
			}
			case 3: // 4. ���� & ������
			{
				screenOperator_MainScreen_Option_MusicDesigne_Page1(data);
				goto BACK;
			}
			}
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	setGoto_freeCursorLocationArr(move, max);

	return;
}

// 1. ���̵� ���� page 1
void screenOperator_MainScreen_Option_Difficulty_Page1(PDATA data)
{
	int max = 6;

	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_Difficulty_Page1);
	int** move = getGoto_cursorLocation(buffer, max);

	char keyBoard;
	int pos = 0;
	int temp = 0;
BACK:
	// ȭ�� ���.
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	temp = pos;

	if (data->gameData->difficulty_tier < 5)
	{
		pos = data->gameData->difficulty_tier;
		MOVE_SET;
		printf("V");
	}
	pos = temp;
	MOVE_SET;

	while (1)
	{
		keyBoard = _getch();
		
		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard_notRemove(move, max, keyBoard, pos);
		}
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			case 0: // 1. �����
			{
				data->gameData->difficulty_tier = pos;
				goto BACK;
			}
			case 1: // 2. �ǹ�
			{
				if (data->gameData->rate_myTier < pos) // ���� Ƽ�� ���ý�
				{
					screenOperator_MainScreen_Option_WARNING_wrongTier(data);
					Sleep(2000);
					goto BACK;
				}
				else // ���� Ƽ�� ���ý�
				{
					data->gameData->difficulty_tier = pos;
					goto BACK;
				}
			}
			case 2: // 3. ���
			{
				if (data->gameData->rate_myTier < pos) // ���� Ƽ�� ���ý�
				{
					screenOperator_MainScreen_Option_WARNING_wrongTier(data);
					Sleep(2000);
					goto BACK;
				}
				else // ���� Ƽ�� ���ý�
				{
					data->gameData->difficulty_tier = pos;
					goto BACK;
				}
			}
			case 3: // 4. �÷�Ƽ��
			{
				if (data->gameData->rate_myTier < pos) // ���� Ƽ�� ���ý�
				{
					screenOperator_MainScreen_Option_WARNING_wrongTier(data);
					Sleep(2000);
					goto BACK;
				}
				else // ���� Ƽ�� ���ý�
				{
					data->gameData->difficulty_tier = pos;
					goto BACK;
				}
			}
			case 4: // 5. ���̾Ƹ��
			{
				if (data->gameData->rate_myTier < pos) // ���� Ƽ�� ���ý�
				{
					screenOperator_MainScreen_Option_WARNING_wrongTier(data);
					Sleep(2000);
					goto BACK;
				}
				else // ���� Ƽ�� ���ý�
				{
					data->gameData->difficulty_tier = pos;
					goto BACK;
				}
			}
			case 5: // ���� ������
			{
				screenOperator_MainScreen_Option_Difficulty_Page2(data);
				goto BACK;
			}
			}
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	setGoto_freeCursorLocationArr(move, max);

	return;
}

// 1. ���̵� ���� page 2
void screenOperator_MainScreen_Option_Difficulty_Page2(PDATA data)
{
	int max = 4;

	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_Difficulty_Page2);
	int** move = getGoto_cursorLocation(buffer, max);

	char keyBoard;
	int pos = 0;
	int temp = 0;
BACK:
	// ȭ�� ���.
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	temp = pos;

	if (data->gameData->difficulty_tier >= 5)
	{
		pos = data->gameData->difficulty_tier - 5;
		MOVE_SET;
		printf("V");
	}
	if (data->gameData->difficulty_hintArr_OnOff == true)
	{
		pos = 2;
		MOVE_SET;
		printf("V");
	}
	else
	{
		pos = 3;
		MOVE_SET;
		printf("V");
	}

	pos = temp;
	MOVE_SET;

	while (1)
	{
		keyBoard = _getch();

		if (DIRECTION_KEY_COMMON(keyBoard))
		{

			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard_notRemove(move, max, keyBoard, pos);
		}
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			case 0: // 6. ������
			{
				if (data->gameData->rate_myTier < pos + 5) // ���� Ƽ�� ���ý�
				{
					screenOperator_MainScreen_Option_WARNING_wrongTier(data);
					Sleep(2000);
					goto BACK;
				}
				else // ���� Ƽ�� ���ý�
				{
					data->gameData->difficulty_tier = pos + 5;
					goto BACK;
				}
			}
			case 1: // 7. �׷��� ������
			{
				if (data->gameData->rate_myTier < pos + 5) // ���� Ƽ�� ���ý�
				{
					screenOperator_MainScreen_Option_WARNING_wrongTier(data);
					Sleep(2000);
					goto BACK;
				}
				else // ���� Ƽ�� ���ý�
				{
					data->gameData->difficulty_tier = pos + 5;
					goto BACK;
				}
			}
			case 2: // ��Ʈ ON
			{
				data->gameData->difficulty_hintArr_OnOff = true;
				goto BACK;
			}
			case 3: // ��Ʈ OFF
			{
				data->gameData->difficulty_hintArr_OnOff = false;
				goto BACK;
			}
			}
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	setGoto_freeCursorLocationArr(move, max);

	return;
}

// 2. �⺻�� ���� page 1
void screenOperator_MainScreen_Option_NumberSetting_Page1(PDATA data)
{
	int max = 8;

	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_NumberSetting_Page1);
	int** move = getGoto_cursorLocation(buffer, max);

	char keyBoard;
	int pos = 0;
	int temp = 0;
BACK:
	// ȭ�� ���.
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	temp = pos;
	
	if (data->gameData->numberSetting_random_OnOff == true)
	{
		pos = 0;
		MOVE_SET;
		printf("V");
	}
	else
	{
		pos = 1;
		MOVE_SET;
		printf("V");
	}

	pos = 2 + data->gameData->numberSetting_symmetryType;
	MOVE_SET;
	printf("V");

	pos = temp;
	MOVE_SET;

	while (1)
	{
		keyBoard = _getch();

		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard_notRemove(move, max, keyBoard, pos);
		}
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			case 0: // 1. �������� ��ġ
			{
				data->gameData->numberSetting_random_OnOff = true;
				goto BACK;
			}
			case 1: // 2. ��Ī���� ��ġ
			{
				data->gameData->numberSetting_random_OnOff = false;
				goto BACK;
			}
			case 2: // A TYPE
			{
				data->gameData->numberSetting_symmetryType = COMPLETE;
				goto BACK;
			}
			case 3: // B TYPE
			{
				data->gameData->numberSetting_symmetryType = WINDMILL;
				goto BACK;
			}
			case 4: // C TYPE
			{
				data->gameData->numberSetting_symmetryType = LEFT_RIGHT;
				goto BACK;
			}
			case 5: // D TYPE
			{
				data->gameData->numberSetting_symmetryType = UP_DOWN;
				goto BACK;
			}
			case 6: // RANDOM TYPE
			{
				data->gameData->numberSetting_symmetryType = RANDOM;
				goto BACK;
			}
			case 7: // ����
			{
				screenOperator_MainScreen_Option_NumberSetting_Page2();
				goto BACK;
			}
			}
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	setGoto_freeCursorLocationArr(move, max);

	return;
}


// 2. �⺻�� ���� page 2
void screenOperator_MainScreen_Option_NumberSetting_Page2()
{
	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_NumberSetting_Page2);
	char keyBoard;

	// ȭ�� ���.
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);

	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	return;
}


// 3. ������ / ����� ���� ����.
void screenOperator_MainScreen_Option_SaveSheet(PDATA data)
{
	int max = 4;

	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_SaveSheet);
	int** move = getGoto_cursorLocation(buffer, max);

	char keyBoard;
	int pos = 0;
	int temp = 0;
BACK:
	// ȭ�� ���.
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	temp = pos;

	if (data->gameData->saveSheet_OnOff == false) // ���� OFF
	{
		pos = 0;
		MOVE_SET;
		printf("V");
	}
	else // ���� ON
	{
		pos = 1;
		MOVE_SET;
		printf("V");
	}

	pos = 2 + data->gameData->saveSheet_saveType;
	MOVE_SET;
	printf("V");

	pos = temp;
	MOVE_SET;

	while (1)
	{
		keyBoard = _getch();

		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard_notRemove(move, max, keyBoard, pos);
		}
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			case 0: // 1. ������ / ����� ���� OFF
			{
				data->gameData->saveSheet_OnOff = false;
				goto BACK;
			}
			case 1: // 2. ������ / ����� ���� ON
			{
				data->gameData->saveSheet_OnOff = true;
				goto BACK;
			}
			case 2: // �������� ����.
			{
				data->gameData->saveSheet_saveType = QUESTION;
				goto BACK;
			}
			case 3: // ������ + ����� ����.
			{
				data->gameData->saveSheet_saveType = QUESTION_ANSWER;
				goto BACK;
			}
			}
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	setGoto_freeCursorLocationArr(move, max);

	return;
}

// 4. ���� & ������ ���� page 1
#define DRECTORY_SIZE 200
#define K_POP_PATH "\\Sound\\k_pop.wav"
#define POP_SONG_PATH "\\Sound\\pop_song.wav"
#define BGM_PATH "\\Sound\\bgm.wav"
void screenOperator_MainScreen_Option_MusicDesigne_Page1(PDATA data)
{
	int max = 6;

	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_MusicDesigne_Page1);
	int** move = getGoto_cursorLocation(buffer, max);

	char keyBoard;
	int pos = 0;
	int temp = 0;
	bool music = data->gameData->music_OnOff;
BACK:
	// ȭ�� ���.
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	temp = pos;

	
	if (data->gameData->music_OnOff == false) // ���� OFF
	{
		pos = 0;
		MOVE_SET;
		printf("V");
		PlaySound(NULL, 0, 0);
		music = false;
	}
	else // ���� ON
	{
		pos = 1;
		MOVE_SET;
		printf("V");
		
		char* directory = screenOperator_MainScreen_Option_Music(data);

		if (music == false)
		{
			PlaySound(TEXT(directory), NULL, SND_ASYNC | SND_LOOP);
			music = true;
		}
		free(directory);
	}

	pos = 2 + data->gameData->music_playList;
	MOVE_SET;
	printf("V");

	pos = temp;
	MOVE_SET;

	while (1)
	{
		keyBoard = _getch();

		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard_notRemove(move, max, keyBoard, pos);
		}
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			case 0: // 1. ���� OFF
			{
				data->gameData->music_OnOff = false;
				goto BACK;
			}
			case 1: // 2. ���� ON
			{
				data->gameData->music_OnOff = true;
				goto BACK;
			}
			case 2: // ���� ���
			{
				if (data->gameData->music_playList != K_POP)
				{
					data->gameData->music_playList = K_POP;
					music = false;
				}
				goto BACK;
			}
			case 3: // �˼� ���
			{
				if (data->gameData->music_playList != POP_SONG)
				{
					data->gameData->music_playList = POP_SONG;
					music = false;
				}
				goto BACK;
			}
			case 4: // BGM ���
			{
				if (data->gameData->music_playList != BGM)
				{
					data->gameData->music_playList = BGM;
					music = false;
				}
				goto BACK;
			}
			case 5: // ���� ������
			{
				screenOperator_MainScreen_Option_MusicDesigne_Page2(data);
				goto BACK;
			}
			}
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	setGoto_freeCursorLocationArr(move, max);

	return;
}

// 4. ���� & ������ ���� page 2
void screenOperator_MainScreen_Option_MusicDesigne_Page2(PDATA data)
{
	int max = 7;

	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_MusicDesigne_Page2);
	int** move = getGoto_cursorLocation(buffer, max);

	char keyBoard;
	int pos = 0;
	int temp = 0;
BACK:
	// ȭ�� ���.
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	temp = pos;

	if (data->gameData->designe_initValueMark_OnOff == true) // �ʱ갪 '*'ǥ ON
	{
		pos = 0;
		MOVE_SET;
		printf("V");
	}
	else // �ʱ갪 '*'ǥ OFF
	{
		pos = 1;
		MOVE_SET;
		printf("V");
	}

	pos = 2 + data->gameData->designe_boundaryType;
	MOVE_SET;
	printf("V");

	pos = temp;
	MOVE_SET;

	while (1)
	{
		keyBoard = _getch();

		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard_notRemove(move, max, keyBoard, pos);
		}
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			case 0: // 1. ��� ǥ�� ON
			{
				data->gameData->designe_initValueMark_OnOff = true;
				goto BACK;
			}
			case 1: // 2. ��� ǥ�� OFF
			{
				data->gameData->designe_initValueMark_OnOff = false;
				goto BACK;
			}
			case 2: // ��輱 : �⺻ ��
			{
				data->gameData->designe_boundaryType = DEFAULT;
				goto BACK;
			}
			case 3: // ��輱 : �� ��
			{
				data->gameData->designe_boundaryType = DOTED_LINE;
				goto BACK;
			}
			case 4: // ��輱 : ��� �� ǥ��
			{
				data->gameData->designe_boundaryType = EVERY_LINE;
				goto BACK;
			}
			case 5:
			{
				data->gameData->designe_boundaryType = REMOVE_LINE;
				goto BACK;
			}
			case 6: // ���� ������
			{
				screenOperator_MainScreen_Option_MusicDesigne_Page3();
				goto BACK;
			}
			}
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	setGoto_freeCursorLocationArr(move, max);

	return;
}

// 4. ���� & ������ ���� page 3
void screenOperator_MainScreen_Option_MusicDesigne_Page3()
{
	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_MusicDesigne_Page3);
	char keyBoard;

BACK:
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	int pos = 0;

	// Ű ����
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == ENTER_KEY)
		{
			screenOperator_MainScreen_Option_MusicDesigne_Page4();
			goto BACK;
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);

	return;
}

// 4. ���� & ������ ���� page 4
void screenOperator_MainScreen_Option_MusicDesigne_Page4()
{
	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_MusicDesigne_Page4);
	char keyBoard;

BACK:
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	int pos = 0;

	// Ű ����
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == ENTER_KEY)
		{
			screenOperator_MainScreen_Option_MusicDesigne_Page5();
			goto BACK;
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);

	return;
}

// 4. ���� & ������ ���� page 5
void screenOperator_MainScreen_Option_MusicDesigne_Page5()
{
	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Option_MusicDesigne_Page5);
	char keyBoard;

	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	int pos = 0;

	// Ű ����
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);

	return;
}


// ��� : �߸��� Ƽ��
#define WARNING_HEIGHT 8
void screenOperator_MainScreen_Option_WARNING_wrongTier(PDATA data)
{
	
	PSTR_NODE list = getTextNode_allocInitHeader();
	screenText_MainScreen_Option_WARNING_wrongTier(list, data);
	char** buffer = getBuffer_completedTextNode(list, 47);

	for (int i = 0; i < WARNING_HEIGHT + 2; i++)
	{
		setGoto_setCursor(8 + i, 15);
		printf("%s\n", buffer[i]);
	}

	setTextNode_freeNodes(list);
	setBuffer_freeChar2DBuffer(buffer, WARNING_HEIGHT);

	return;
}


// ���� �ش� ���ϰ�� ����
char* screenOperator_MainScreen_Option_Music(PDATA data)
{
	char directory[DRECTORY_SIZE] = { 0, };
	_getcwd(directory, DRECTORY_SIZE); // ���� �۾���� ���

	switch (data->gameData->music_playList)
	{
	case K_POP:
	{
		strcat(directory, K_POP_PATH);
		break;
	}
	case POP_SONG:
	{
		strcat(directory, POP_SONG_PATH);
		break;
	}
	case BGM:
	{
		strcat(directory, BGM_PATH);
		break;
	}
	}

	int size = strlen(directory);
	char* str = malloc(sizeof(char) * size + 1);
	memset(str, 0, sizeof(char) * size + 1);

	strcpy(str, directory);

	return str;
}
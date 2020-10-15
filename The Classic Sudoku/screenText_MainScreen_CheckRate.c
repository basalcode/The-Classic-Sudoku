// screenText_MainScreen_CheckRate.c 파일은 전적확인 페이지 관련 텍스트 함수 파일.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screenText_MainScreen_CheckRate.h"

#include "setTextNode.h"
#include "getTextNode.h"
#include "setDataStructure.h"
#include "setBoxedNode.h"

// 전적 확인 Page 1
#define BOXED_RATE_HEIGTH 7
#define TEMP_SIZE 100
void screenText_MainScreen_CheckRate_Page1(PSTR_NODE list, PDATA data)
{
	PSTR_NODE boxedText = screenText_MainScreen_CheckRate_BoxedSumRate(data);
	PSTR_NODE curr = boxedText->nextNode;

	char levelStr[100];
	memset(levelStr, 0, sizeof(char) * 100);

	int tier = (data->gameData->rate_level - 1) / 5;
	switch (tier)
	{
	case 0:
	{
		sprintf(levelStr, "  2. 현재 나의 Level : %2d    [ 브론즈 : BRONZE ]", data->gameData->rate_level);
		break;
	}
	case 1:
	{
		sprintf(levelStr, "  2. 현재 나의 Level : %2d    [ 실버 : SILVER ]", data->gameData->rate_level);
		break;
	}
	case 2:
	{
		sprintf(levelStr, "  2. 현재 나의 Level : %2d    [ 골드 : GOLD ]", data->gameData->rate_level);
		break;
	}
	case 3:
	{
		sprintf(levelStr, "  2. 현재 나의 Level : %2d    [ 플래티넘 : PLATINUM ]", data->gameData->rate_level);
		break;
	}
	case 4:
	{
		sprintf(levelStr, "  2. 현재 나의 Level : %2d    [ 다이아몬드 : DIAMOND ]", data->gameData->rate_level);
		break;
	}
	case 5:
	{
		sprintf(levelStr, "  2. 현재 나의 Level : %2d    [ 마스터 : MASTER ]", data->gameData->rate_level);
		break;
	}
	case 6:
	{
		sprintf(levelStr, "  2. 현재 나의 Level : %2d    [ 그랜드 마스터 : GRAND MASTER ]", data->gameData->rate_level);
		break;
	}
	}
	

	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ C H E C K _ R A T E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 전체 전적", LEFT);
	
	while (curr != NULL)
	{
		setTextNode_addNodeToEnd(list, curr->str, LEFT);

		curr = curr->nextNode;
	}
	
	PSTR_NODE levelBox = screenText_MainScreen_CheckRate_ShowLevel(data);
	curr = levelBox->nextNode;

	setTextNode_addNodeToEnd(list, "", LEFT);

	setTextNode_addNodeToEnd(list, levelStr, LEFT);

	while (curr != NULL)
	{
		setTextNode_addNodeToEnd(list, curr->str, LEFT);

		curr = curr->nextNode;
	}

	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    1 / 3                    [ ENTER - 다음 ]", MIDDLE);

	setTextNode_freeNodes(boxedText);
	free(boxedText);

	return;
}

// 전적 확인 Page 2
void screenText_MainScreen_CheckRate_Page2(PSTR_NODE list, PDATA data)
{
	char total_rate[TEMP_SIZE];
	char win_lost[TEMP_SIZE];

	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ C H E C K _ R A T E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  3. 티어별 전적", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (1) 브론즈          [ BRONZE ]", LEFT);

	memset(total_rate, 0, sizeof(char) * TEMP_SIZE);
	memset(win_lost, 0, sizeof(char) * TEMP_SIZE);
	sprintf(total_rate, "    [ 게임 ] : %3d            [ 승률 ] : %3d%%", data->gameData->rate.bronze[0], data->gameData->rate.bronze[3]);
	sprintf(win_lost, "    [ 승리 ] : %3d            [ 패배 ] : %3d", data->gameData->rate.bronze[1], data->gameData->rate.bronze[2]);

	setTextNode_addNodeToEnd(list, total_rate, LEFT);
	setTextNode_addNodeToEnd(list, win_lost, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (2) 실버            [ SILVER ]", LEFT);

	memset(total_rate, 0, sizeof(char) * TEMP_SIZE);
	memset(win_lost, 0, sizeof(char) * TEMP_SIZE);
	sprintf(total_rate, "    [ 게임 ] : %3d            [ 승률 ] : %3d%%", data->gameData->rate.silver[0], data->gameData->rate.silver[3]);
	sprintf(win_lost, "    [ 승리 ] : %3d            [ 패배 ] : %3d", data->gameData->rate.silver[1], data->gameData->rate.silver[2]);

	setTextNode_addNodeToEnd(list, total_rate, LEFT);
	setTextNode_addNodeToEnd(list, win_lost, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (3) 골드            [ GOLD ]", LEFT);

	memset(total_rate, 0, sizeof(char) * TEMP_SIZE);
	memset(win_lost, 0, sizeof(char) * TEMP_SIZE);
	sprintf(total_rate, "    [ 게임 ] : %3d            [ 승률 ] : %3d%%", data->gameData->rate.gold[0], data->gameData->rate.gold[3]);
	sprintf(win_lost, "    [ 승리 ] : %3d            [ 패배 ] : %3d", data->gameData->rate.gold[1], data->gameData->rate.gold[2]);

	setTextNode_addNodeToEnd(list, total_rate, LEFT);
	setTextNode_addNodeToEnd(list, win_lost, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (4) 플래티넘        [ PLATINUM ]", LEFT);

	memset(total_rate, 0, sizeof(char) * TEMP_SIZE);
	memset(win_lost, 0, sizeof(char) * TEMP_SIZE);
	sprintf(total_rate, "    [ 게임 ] : %3d            [ 승률 ] : %3d%%", data->gameData->rate.platinum[0], data->gameData->rate.platinum[3]);
	sprintf(win_lost, "    [ 승리 ] : %3d            [ 패배 ] : %3d", data->gameData->rate.platinum[1], data->gameData->rate.platinum[2]);

	setTextNode_addNodeToEnd(list, total_rate, LEFT);
	setTextNode_addNodeToEnd(list, win_lost, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    2 / 3                    [ ENTER - 다음 ]", MIDDLE);

	return;
}

// 전적 확인 Page 3
void screenText_MainScreen_CheckRate_Page3(PSTR_NODE list, PDATA data)
{
	char total_rate[TEMP_SIZE];
	char win_lost[TEMP_SIZE];

	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ C H E C K _ R A T E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  3. 티어별 전적", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (5) 다이아몬드      [ DIAMOND ]", LEFT);

	memset(total_rate, 0, sizeof(char) * TEMP_SIZE);
	memset(win_lost, 0, sizeof(char) * TEMP_SIZE);
	sprintf(total_rate, "    [ 게임 ] : %3d            [ 승률 ] : %3d%%", data->gameData->rate.diamond[0], data->gameData->rate.diamond[3]);
	sprintf(win_lost, "    [ 승리 ] : %3d            [ 패배 ] : %3d", data->gameData->rate.diamond[1], data->gameData->rate.diamond[2]);
	

	setTextNode_addNodeToEnd(list, total_rate, LEFT);
	setTextNode_addNodeToEnd(list, win_lost, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (6) 마스터          [ MASTER ]", LEFT);

	memset(total_rate, 0, sizeof(char) * TEMP_SIZE);
	memset(win_lost, 0, sizeof(char) * TEMP_SIZE);
	sprintf(total_rate, "    [ 게임 ] : %3d            [ 승률 ] : %3d%%", data->gameData->rate.master[0], data->gameData->rate.master[3]);
	sprintf(win_lost, "    [ 승리 ] : %3d            [ 패배 ] : %3d", data->gameData->rate.master[1], data->gameData->rate.master[2]);

	setTextNode_addNodeToEnd(list, total_rate, LEFT);
	setTextNode_addNodeToEnd(list, win_lost, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (7) 그랜드 마스터   [ GRAND MASTER ]", LEFT);

	memset(total_rate, 0, sizeof(char) * TEMP_SIZE);
	memset(win_lost, 0, sizeof(char) * TEMP_SIZE);
	sprintf(total_rate, "    [ 게임 ] : %3d            [ 승률 ] : %3d%%", data->gameData->rate.grandMaster[0], data->gameData->rate.grandMaster[3]);
	sprintf(win_lost, "    [ 승리 ] : %3d            [ 패배 ] : %3d", data->gameData->rate.grandMaster[1], data->gameData->rate.grandMaster[2]);

	setTextNode_addNodeToEnd(list, total_rate, LEFT);
	setTextNode_addNodeToEnd(list, win_lost, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    3 / 3                                    ", MIDDLE);

	return;
}

// boxing 되어있는 텍스트
#define TIER_MAX 7
#define BOXED_RATE_LENGTH 30
PSTR_NODE screenText_MainScreen_CheckRate_BoxedSumRate(PDATA data)
{
	PSTR_NODE list = malloc(sizeof(STR_NODE));
	memset(list, 0, sizeof(STR_NODE));
	
	char strTotal_Rate[TEMP_SIZE];
	char strWin_Lost[TEMP_SIZE];
	memset(strTotal_Rate, 0, sizeof(char) * TEMP_SIZE);
	memset(strWin_Lost, 0, sizeof(char) * TEMP_SIZE);

	sprintf(strTotal_Rate, "   [ 전체 게임 ] : %3d 게임            [ 전체 승률 ] : %3d%% 승률    ", data->gameData->rate.total[0], data->gameData->rate.total[3]);
	sprintf(strWin_Lost, "   [ 전체 승리 ] : %3d 승리            [ 전체 패배 ] : %3d 패배    ", data->gameData->rate.total[1], data->gameData->rate.total[2]);

	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, strTotal_Rate, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, strWin_Lost, LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);

	setBoxedNode_addBoxNode(list, BOXED_RATE_LENGTH);

	return list;
}

// levelBar 만들어주는함수.
#define LEVEL_BAR_LENGTH 60

// levelBar를 표시해주는 텍스트
PSTR_NODE screenText_MainScreen_CheckRate_ShowLevel(PDATA data)
{
	PSTR_NODE list = malloc(sizeof(STR_NODE));
	memset(list, 0, sizeof(STR_NODE));
	char* levelBar;
	char levelInfo[LEVEL_BAR_LENGTH + 3];
	memset(levelInfo, 0, sizeof(char) * LEVEL_BAR_LENGTH + 3);

	// 레벨바 상단
	int myExp = data->gameData->rate_exp;
	int myLevel = data->gameData->rate_level;

	sprintf(levelInfo, "%2d LEVEL                                         %2d LEVEL", myLevel, myLevel + 1);
	setTextNode_addNodeToEnd(list, levelInfo, MIDDLE);

	// 레벨 바 만들기.
	levelBar = screenText_MainScreen_CheckRate_LevelBarTop(data);
	setTextNode_addNodeToEnd(list, levelBar, MIDDLE);
	free(levelBar);
	
	levelBar = screenText_MainScreen_CheckRate_LevelBarMiddle(data);
	setTextNode_addNodeToEnd(list, levelBar, MIDDLE);
	free(levelBar);

	levelBar = screenText_MainScreen_CheckRate_LevelBarBottom(data);
	setTextNode_addNodeToEnd(list, levelBar, MIDDLE);
	free(levelBar);

	// 레벨바 하단
	int minExp = (myLevel - 1) * 40;
	int maxExp = myLevel * 40;

	memset(levelInfo, 0, sizeof(char) * LEVEL_BAR_LENGTH + 3);
	sprintf(levelInfo, "%4d EXP             [ 현재 : %4d EXP ]             %4d EXP", minExp, myExp, maxExp);

	setTextNode_addNodeToEnd(list, levelInfo, MIDDLE);
	
	setBoxedNode_addBoxNode(list, BOXED_RATE_LENGTH);

	return list;
}

// levelBar Top
char* screenText_MainScreen_CheckRate_LevelBarTop(PDATA data)
{
	char* arr = malloc(sizeof(char) * LEVEL_BAR_LENGTH + 3);
	memset(arr, 0, sizeof(char) * LEVEL_BAR_LENGTH + 3);

	int myExp = data->gameData->rate_exp;
	int levelParameter = (myExp % 40) * LEVEL_BAR_LENGTH / 40;

	arr[0] = 1;

	for (int i = 1; i < LEVEL_BAR_LENGTH - 2; i++)
	{
		if (i < levelParameter)
		{
			arr[i] = 22;
		}
		else
		{
			arr[i] = 6;
		}
	}

	arr[LEVEL_BAR_LENGTH - 2] = 2;

	return arr;
}

// levelBar Middle
char* screenText_MainScreen_CheckRate_LevelBarMiddle(PDATA data)
{
	char* arr = malloc(sizeof(char) * LEVEL_BAR_LENGTH + 3);
	memset(arr, 0, sizeof(char) * LEVEL_BAR_LENGTH + 3);

	int myExp = data->gameData->rate_exp;
	int levelParameter = (myExp % 40) * LEVEL_BAR_LENGTH / 40;

	arr[0] = 5;

	for (int i = 1; i < LEVEL_BAR_LENGTH - 2; i++)
	{
		if (i < levelParameter)
		{
			arr[i] = 5;
		}
		else
		{
			arr[i] = ' ';
		}
	}

	arr[LEVEL_BAR_LENGTH - 2] = 5;

	return arr;
}

// levelBar Bottom
char* screenText_MainScreen_CheckRate_LevelBarBottom(PDATA data)
{
	char* arr = malloc(sizeof(char) * LEVEL_BAR_LENGTH + 3);
	memset(arr, 0, sizeof(char) * LEVEL_BAR_LENGTH + 3);

	int myExp = data->gameData->rate_exp;
	int levelParameter = (myExp % 40) * LEVEL_BAR_LENGTH / 40;

	arr[0] = 25;

	for (int i = 1; i < LEVEL_BAR_LENGTH - 2; i++)
	{
		if (i < levelParameter)
		{
			if (i == (LEVEL_BAR_LENGTH - 1) / 2)
			{
				arr[i] = 16;
				continue;
			}
			arr[i] = 21;
		}
		else
		{
			if (i == (LEVEL_BAR_LENGTH - 1) / 2)
			{
				arr[i] = 22;
				continue;
			}
			arr[i] = 6;
		}
	}

	arr[LEVEL_BAR_LENGTH - 2] = 23;

	return arr;
}


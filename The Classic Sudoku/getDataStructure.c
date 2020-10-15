// getDataStructure.c 파일은 option과 관련된 값을 리턴해주는 함수 파일.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>

#include "getDataStructure.h"
#include "setDataStructure.h"

// option 구조체를 메모리에 할당 / 초기화 해주는 함수.
PGAME_DATA getDataStructure_allocInitStruct()
{
	PGAME_DATA data = malloc(sizeof(GAME_DATA));
	memset(data, 0, sizeof(GAME_DATA));
	
	data->difficulty_tier = BRONZE;
	data->difficulty_hintArr_OnOff = true;

	data->numberSetting_random_OnOff = false;
	data->numberSetting_symmetryType = WINDMILL;

	data->saveSheet_OnOff = false;
	data->saveSheet_saveType = QUESTION_ANSWER;

	data->music_OnOff = false;
	data->music_playList = K_POP;

	data->designe_initValueMark_OnOff = true;
	data->designe_boundaryType = DEFAULT;

	memset(&data->rate, 0, sizeof(RATE_DATA));
	data->rate_myTier = BRONZE;
	data->rate_level = 1;
	data->rate_exp = 0;

	return data;
}

// 할당과 기본 초기화만 해줌.
PGAME_DATA getDataStructure_allocStruct()
{
	PGAME_DATA data = malloc(sizeof(GAME_DATA));
	memset(data, 0, sizeof(GAME_DATA));

	return data;
}

#define DRECTORY_SIZE 200
#define FILE_NAME "gameData.bin"
#define README "설명서(readme).txt"

// 폴더 생성 및 파일 초기화
PDATA getDataStructure_initFolderAndFile()
{

	char directory[DRECTORY_SIZE] = { 0, };
	char sudokuDir[DRECTORY_SIZE] = { 0, };
	char soundDir[DRECTORY_SIZE] = { 0, };
	char saveDir[DRECTORY_SIZE] = { 0, };

	_getcwd(directory, DRECTORY_SIZE); // 현재 작업경로 

	/* sudoku 폴더 */
	strcpy(sudokuDir, directory);
	strcat(sudokuDir, "\\The Classic Sudoku");
	_mkdir(sudokuDir); // 디렉토리 생성

	_chdir(sudokuDir); // 작업장소 변경.

	/* Sound 폴더 */
	strcpy(soundDir, sudokuDir);
	strcat(soundDir, "\\Sound");
	_mkdir(soundDir);

	/* Saves 폴더 */
	strcpy(saveDir, sudokuDir);
	strcat(saveDir, "\\Saves");
	_mkdir(saveDir);

	PDATA data = malloc(sizeof(DATA));
	memset(data, 0, sizeof(DATA));
	
	FILE* fp = fopen(FILE_NAME, "rb");
	if (fp == NULL)
	{
		fp = fopen(FILE_NAME, "wb");
		if (fp == NULL)
		{
			printf("setInitGame_file() 함수 애러 : 파일을 생성할 수 없습니다.\n");
		}

		data->gameData = getDataStructure_allocInitStruct();

		if (fwrite(data->gameData, sizeof(GAME_DATA), 1, fp) < 0)
		{
			printf("setInitGame_file() 함수 애러 : 게임 데이터 쓰기 실패.\n");
		}

		fseek(fp, 0, SEEK_SET);
		
		free(data->gameData);
		fclose(fp);

		fp = fopen(FILE_NAME, "rb");
	}

	/* 파일 읽기 성공시, Data 구조체 할당해주기. */
	data->gameData = getDataStructure_allocStruct();

	data->fp = fp;

	if (fread(data->gameData, sizeof(GAME_DATA), 1, fp) < 0)
	{
		printf("setInitGame_file() 함수 애러 : 게임 데이터 읽기 실패.\n");
	}
	fclose(fp);

	fp = fopen(README, "r");
	if (fp == NULL)
	{
		fp = fopen(README, "w");
		if (fp == NULL)
		{
			printf("setInitGame_file() 함수 애러 : %s 파일 생성 실패.\n", README);
		}

		char* str = "/* 설명서 (readme) */\n[ 해당 문서는 The Classic Sudoku에 관련된 파일 및 폴더에 대한 설명을\n\
  포함합니다. ]\n\n\n";
		fwrite(str, strlen(str), 1, fp);

		str = "1. 문제지 / 답안지 저장 관련 (Saves 폴더)\n\n\
* The Classic Sudoku 폴더의 Save폴더(이하 폴더)에 내가 풀었던 \n\
  문제지와 답안지를 저장하는 기능이 있습니다.\n\n\
* 게임 내부의 설정으로 게임에서 나왔던, 문제지와 답안지의 저장 \n\
  여부를 설정할 수 있습니다.\n\
  ( 게임설정 > 문제지 저장 > 문제지 저장 ON 항목 )\n\n\
* 저장된 게임은 .txt(텍스트) 확장자 형식으로 저장됩니다.\n\n\
* 저장된 문제지(혹은 문제지 + 답안지)는 저장 순서대로 번호가 \n\
  매겨져서 저장됩니다.\n\n\n";
		fwrite(str, strlen(str), 1, fp);

		str = "2. 음악 재생 관련 (Sound 폴더)\n\n\
* The Classic Sudoku 폴더의 Sound폴더(이하 폴더) 안에 아무런 파일이\n\
  없을시엔 게임 설정을 하더라도 음악이 재생되지 않습니다.\n\
  ( 음악 파일이 없는데 재생설정을 하게되면, 경고음이 반복적으로\n\
    출력됩니다. )\n\n\
* 폴더내부에 들어가야 하는 파일 이름은 다음 3가지와 같습니다.\n\
  ( k_pop.wav / pop_song.wav / bgm.wav ) \n\
  이외의 파일이 들어가도 무관하나, 설정의 적용을 받지 못합니다.\n\n\
* 만약 음악 플레이리스트를 바꾸고 싶다면, 음악 파일의 이름을 \n\
  위 3가지 형식에 맞추어 바꾼 후, 넣어주면 됩니다.\n\
  ( 단, 음악 파일 확장자는 반드시 .wav 여야만 합니다. mp3확장자나\n\
    기타 확장자는 .wav로 인코딩후 넣어줘야 적용이 가능합니다. )\n\n\n";
		fwrite(str, strlen(str), 1, fp);

		str = "3. 게임 데이터 관련 (gameData.bin 파일)\n\n\
* The Classic Sudoku 폴더내부에 생성되는 gameData.bin 파일은 \n\
  게임에서 사용되었던 데이터를 저장하는 파일입니다.\n\n\
* 게임 내부의 데이터 ( 전적, 레벨, 티어, 기타 옵션 등)을 초기화\n\
  하고 싶다면 gameData.bin을 삭제를 해주시면 됩니다.\n\n\
* gameData.bin 파일은 삭제가 되어도 프로그램 시작시 기본 값으로\n\
  재생성됩니다.\n\n\n";
		fwrite(str, strlen(str), 1, fp);

		fclose(fp);
		
		fp = fopen(README, "r");
	}

	fclose(fp);
	return data;
}
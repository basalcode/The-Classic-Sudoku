// getDataStructure.c ������ option�� ���õ� ���� �������ִ� �Լ� ����.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>

#include "getDataStructure.h"
#include "setDataStructure.h"

// option ����ü�� �޸𸮿� �Ҵ� / �ʱ�ȭ ���ִ� �Լ�.
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

// �Ҵ�� �⺻ �ʱ�ȭ�� ����.
PGAME_DATA getDataStructure_allocStruct()
{
	PGAME_DATA data = malloc(sizeof(GAME_DATA));
	memset(data, 0, sizeof(GAME_DATA));

	return data;
}

#define DRECTORY_SIZE 200
#define FILE_NAME "gameData.bin"
#define README "����(readme).txt"

// ���� ���� �� ���� �ʱ�ȭ
PDATA getDataStructure_initFolderAndFile()
{

	char directory[DRECTORY_SIZE] = { 0, };
	char sudokuDir[DRECTORY_SIZE] = { 0, };
	char soundDir[DRECTORY_SIZE] = { 0, };
	char saveDir[DRECTORY_SIZE] = { 0, };

	_getcwd(directory, DRECTORY_SIZE); // ���� �۾���� 

	/* sudoku ���� */
	strcpy(sudokuDir, directory);
	strcat(sudokuDir, "\\The Classic Sudoku");
	_mkdir(sudokuDir); // ���丮 ����

	_chdir(sudokuDir); // �۾���� ����.

	/* Sound ���� */
	strcpy(soundDir, sudokuDir);
	strcat(soundDir, "\\Sound");
	_mkdir(soundDir);

	/* Saves ���� */
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
			printf("setInitGame_file() �Լ� �ַ� : ������ ������ �� �����ϴ�.\n");
		}

		data->gameData = getDataStructure_allocInitStruct();

		if (fwrite(data->gameData, sizeof(GAME_DATA), 1, fp) < 0)
		{
			printf("setInitGame_file() �Լ� �ַ� : ���� ������ ���� ����.\n");
		}

		fseek(fp, 0, SEEK_SET);
		
		free(data->gameData);
		fclose(fp);

		fp = fopen(FILE_NAME, "rb");
	}

	/* ���� �б� ������, Data ����ü �Ҵ����ֱ�. */
	data->gameData = getDataStructure_allocStruct();

	data->fp = fp;

	if (fread(data->gameData, sizeof(GAME_DATA), 1, fp) < 0)
	{
		printf("setInitGame_file() �Լ� �ַ� : ���� ������ �б� ����.\n");
	}
	fclose(fp);

	fp = fopen(README, "r");
	if (fp == NULL)
	{
		fp = fopen(README, "w");
		if (fp == NULL)
		{
			printf("setInitGame_file() �Լ� �ַ� : %s ���� ���� ����.\n", README);
		}

		char* str = "/* ���� (readme) */\n[ �ش� ������ The Classic Sudoku�� ���õ� ���� �� ������ ���� ������\n\
  �����մϴ�. ]\n\n\n";
		fwrite(str, strlen(str), 1, fp);

		str = "1. ������ / ����� ���� ���� (Saves ����)\n\n\
* The Classic Sudoku ������ Save����(���� ����)�� ���� Ǯ���� \n\
  �������� ������� �����ϴ� ����� �ֽ��ϴ�.\n\n\
* ���� ������ �������� ���ӿ��� ���Դ�, �������� ������� ���� \n\
  ���θ� ������ �� �ֽ��ϴ�.\n\
  ( ���Ӽ��� > ������ ���� > ������ ���� ON �׸� )\n\n\
* ����� ������ .txt(�ؽ�Ʈ) Ȯ���� �������� ����˴ϴ�.\n\n\
* ����� ������(Ȥ�� ������ + �����)�� ���� ������� ��ȣ�� \n\
  �Ű����� ����˴ϴ�.\n\n\n";
		fwrite(str, strlen(str), 1, fp);

		str = "2. ���� ��� ���� (Sound ����)\n\n\
* The Classic Sudoku ������ Sound����(���� ����) �ȿ� �ƹ��� ������\n\
  �����ÿ� ���� ������ �ϴ��� ������ ������� �ʽ��ϴ�.\n\
  ( ���� ������ ���µ� ��������� �ϰԵǸ�, ������� �ݺ�������\n\
    ��µ˴ϴ�. )\n\n\
* �������ο� ���� �ϴ� ���� �̸��� ���� 3������ �����ϴ�.\n\
  ( k_pop.wav / pop_song.wav / bgm.wav ) \n\
  �̿��� ������ ���� �����ϳ�, ������ ������ ���� ���մϴ�.\n\n\
* ���� ���� �÷��̸���Ʈ�� �ٲٰ� �ʹٸ�, ���� ������ �̸��� \n\
  �� 3���� ���Ŀ� ���߾� �ٲ� ��, �־��ָ� �˴ϴ�.\n\
  ( ��, ���� ���� Ȯ���ڴ� �ݵ�� .wav ���߸� �մϴ�. mp3Ȯ���ڳ�\n\
    ��Ÿ Ȯ���ڴ� .wav�� ���ڵ��� �־���� ������ �����մϴ�. )\n\n\n";
		fwrite(str, strlen(str), 1, fp);

		str = "3. ���� ������ ���� (gameData.bin ����)\n\n\
* The Classic Sudoku �������ο� �����Ǵ� gameData.bin ������ \n\
  ���ӿ��� ���Ǿ��� �����͸� �����ϴ� �����Դϴ�.\n\n\
* ���� ������ ������ ( ����, ����, Ƽ��, ��Ÿ �ɼ� ��)�� �ʱ�ȭ\n\
  �ϰ� �ʹٸ� gameData.bin�� ������ ���ֽø� �˴ϴ�.\n\n\
* gameData.bin ������ ������ �Ǿ ���α׷� ���۽� �⺻ ������\n\
  ������˴ϴ�.\n\n\n";
		fwrite(str, strlen(str), 1, fp);

		fclose(fp);
		
		fp = fopen(README, "r");
	}

	fclose(fp);
	return data;
}
// main.c �ִ��� �Լ�������� ���α׷� ������.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

#include "getDataStructure.h"
#include "screenOperator_MainScreen.h"
#include "screenOperator_Main_OptionScreen.h"

#define DRECTORY_SIZE 200
#define K_POP_PATH "\\sound\\k_pop.wav"
#define POP_SONG_PATH "\\sound\\pop_song.wav"
#define BGM_PATH "\\sound\\bgm.wav"


#include "printMatrix.h"
int main()
{
	/* �ܼ� ȭ�� ũ�� ����*/
	system("mode con cols=80 lines=25");

	PDATA data = getDataStructure_initFolderAndFile(); // ���丮, data���� ����. �� �ʱ�ȭ.

	/* ���� ������ ���� ON OFF*/
	char* directory = screenOperator_MainScreen_Option_Music(data);
	if (data->gameData->music_OnOff)
	{
		PlaySound(TEXT(directory), 0, SND_ASYNC | SND_LOOP);
	}
	free(directory);

	/* ���� ȭ�� ���� */
	screenOperator_MainScreen(data);

	/* �Ҵ� ���� */
	free(data->gameData);
	fclose(data->fp);
	free(data);

	return 0;
}
// main.c 최대한 함수사용으로 프로그램 돌리기.

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
	/* 콘솔 화면 크기 설정*/
	system("mode con cols=80 lines=25");

	PDATA data = getDataStructure_initFolderAndFile(); // 디렉토리, data파일 생성. 및 초기화.

	/* 음악 설정에 따라 ON OFF*/
	char* directory = screenOperator_MainScreen_Option_Music(data);
	if (data->gameData->music_OnOff)
	{
		PlaySound(TEXT(directory), 0, SND_ASYNC | SND_LOOP);
	}
	free(directory);

	/* 메인 화면 조작 */
	screenOperator_MainScreen(data);

	/* 할당 해제 */
	free(data->gameData);
	fclose(data->fp);
	free(data);

	return 0;
}
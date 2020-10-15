// setOption.c 파일은 옵션과 관련된 내용을 option구조체 혹은 특정 변수에 저장 시켜주는 함수 파일.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setDataStructure.h"

#include "getDataStructure.h"

#define DRECTORY_SIZE 200
#define FILE_NAME "gameData.bin"

// 구조체에 저장된 내용을 파일에 씌운후 다시 파일에서 구조체로 내용을 불러옴
void setDataStructure_saveStructure(PDATA data)
{
	fseek(data->fp, 0, SEEK_SET);
	fclose(data->fp);

	data->fp = fopen(FILE_NAME, "wb");
	fwrite(data->gameData, sizeof(GAME_DATA), 1, data->fp); //쓰고
	free(data->gameData); // 할당해제 해주고
	fclose(data->fp);

	// 새로 할당
	PGAME_DATA gameData = malloc(sizeof(GAME_DATA));
	memset(gameData, 0, sizeof(GAME_DATA));	

	data->gameData = gameData;
	data->fp = fopen(FILE_NAME, "rb");

	fread(data->gameData, sizeof(GAME_DATA), 1, data->fp); // 읽고



	return;
}
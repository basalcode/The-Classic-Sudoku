// setOption.c ������ �ɼǰ� ���õ� ������ option����ü Ȥ�� Ư�� ������ ���� �����ִ� �Լ� ����.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setDataStructure.h"

#include "getDataStructure.h"

#define DRECTORY_SIZE 200
#define FILE_NAME "gameData.bin"

// ����ü�� ����� ������ ���Ͽ� ������ �ٽ� ���Ͽ��� ����ü�� ������ �ҷ���
void setDataStructure_saveStructure(PDATA data)
{
	fseek(data->fp, 0, SEEK_SET);
	fclose(data->fp);

	data->fp = fopen(FILE_NAME, "wb");
	fwrite(data->gameData, sizeof(GAME_DATA), 1, data->fp); //����
	free(data->gameData); // �Ҵ����� ���ְ�
	fclose(data->fp);

	// ���� �Ҵ�
	PGAME_DATA gameData = malloc(sizeof(GAME_DATA));
	memset(gameData, 0, sizeof(GAME_DATA));	

	data->gameData = gameData;
	data->fp = fopen(FILE_NAME, "rb");

	fread(data->gameData, sizeof(GAME_DATA), 1, data->fp); // �а�



	return;
}
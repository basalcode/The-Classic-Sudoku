#ifndef SET_DATA_STRUCTURE_H
#define SET_DATA_STRUCTURE_H

#include <stdio.h>
#include <stdbool.h>

typedef enum _TYPE_DIFFICULTY // ���̵� (Ƽ��)
{
	BRONZE = 0,
	SILVER,
	GOLD,
	PLATINUM,
	DIAMOND,
	MASTER,
	GRAND_MASTER
} TYPE_DIFFICULTY;

typedef enum _TYPE_SYMMETRY // ���ڼ��� ��Ī
{
	COMPLETE = 0,
	WINDMILL,
	LEFT_RIGHT,
	UP_DOWN,
	RANDOM
} TYPE_SYMMETRY;

typedef enum _TYPE_SAVE_SHEET // ������ ���� ���.
{
	QUESTION = 0,
	QUESTION_ANSWER
} TYPE_SAVE_SHEET;

typedef enum _TYPE_MUSIC // ���� ��� type
{
	K_POP = 0,
	POP_SONG,
	BGM
} TYPE_MUSIC;

typedef enum _TYPE_BOUNDARY // ��輱 ������
{
	DEFAULT = 0,
	DOTED_LINE,
	EVERY_LINE,
	REMOVE_LINE
} TYPE_BOUNDARY;

#pragma pack (push, 1)

typedef struct _RATE_DATA // 0 : ��, 1: ��, 2 : ��, 3 : �·�
{
	int total[4];
	int bronze[4];
	int silver[4];
	int gold[4];
	int platinum[4];
	int diamond[4];
	int master[4];
	int grandMaster[4];
} RATE_DATA, *PRATE_DATA;

typedef struct _GAME_DATA
{
	// Difficulty
	TYPE_DIFFICULTY difficulty_tier; // ���̵� (Ƽ��)
	bool difficulty_hintArr_OnOff; // ��Ʈ ON / OFF

	// Number Setting 
	bool numberSetting_random_OnOff; // ������ ON / OFF
	TYPE_SYMMETRY numberSetting_symmetryType; // ��Ī type

	// Save Sheet
	bool saveSheet_OnOff;
	TYPE_SAVE_SHEET saveSheet_saveType;
	
	// Music & Designe
	bool music_OnOff;
	TYPE_MUSIC music_playList;
	bool designe_initValueMark_OnOff;
	TYPE_BOUNDARY designe_boundaryType;

	// rate
	RATE_DATA rate;
	TYPE_DIFFICULTY rate_myTier;
	int rate_level;
	int rate_exp;
} GAME_DATA, *PGAME_DATA;

#pragma pack (pop)

typedef struct _DATA
{
	FILE* fp;
	PGAME_DATA gameData;
} DATA, *PDATA;

void setDataStructure_saveStructure(PDATA data);

#endif
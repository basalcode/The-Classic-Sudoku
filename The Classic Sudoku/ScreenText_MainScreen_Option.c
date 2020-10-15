// screenText_MainScreen_Option.c ������ ���� �ɼǰ��� �ؽ�Ʈ�� ���ִ� �Լ� ����.

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>

#include "screenText_MainScreen_Option.h"

#include "setTextNode.h"
#include "getDataStructure.h"
#include "setDataStructure.h"

// ���� ���� ����ȭ��
void screenText_MainScreen_Option_Main(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ G A M E _ O P T I O N ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. ���̵�  ����   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : ������ ���� ���̵�(Ƽ��)�� �����մϴ�.          ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. �⺻ �� ����   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : ������ �ܼ��� �Ǵ� �⺻���� ��ġ�� �����մϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  3. ������  ����   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : ������, ����� ���� ������ �����մϴ�.          ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  4. ���� & ������  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : ���� ������, ��Ÿ �����ε��� �����մϴ�.      ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                                                             ", MIDDLE);

	return;
}

// ���̵� ���� �� page1
void screenText_MainScreen_Option_Difficulty_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ D I F F I C U L T Y ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. ���̵�(Ƽ��) ����", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) �����          [ 54%  ���� ]       BRONZE", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 1 - 5)     [ 43�� �ܼ� ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) �ǹ�            [ 46%  ���� ]       SILVER", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 6 - 10)    [ 37�� �ܼ� ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (3) ���            [ 39%  ���� ]         GOLD", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 11 - 15)   [ 31�� �ܼ� ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (4) �÷�Ƽ��        [ 33%  ���� ]     PLATINUM", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 16 - 20)   [ 26�� �ܼ� ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (5) ���̾Ƹ��      [ 28%  ���� ]      DIAMOND", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 21 - 25)   [ 22�� �ܼ� ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    1 / 2                      [ [ ] - ���� ]", MIDDLE);
	
	return;
}

// ���̵� ���� �� page2
void screenText_MainScreen_Option_Difficulty_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ D I F F I C U L T Y ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. Ƽ�� ����", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (6) ������          [ 24%  ���� ]       MASTER",LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 26 - 30)   [ 19�� �ܼ� ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (7) �׷��� ������   [ 21%  ���� ] GRAND MASTER", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 31 - 35)   [ 17�� �ܼ� ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. ��Ʈ ����", LEFT);
	setTextNode_addNodeToEnd(list, "    * ��Ʈ�� ��ġ�� �ʴ� ���ڵ��� �迭�� �����ݴϴ�. (����, ����, 3x3)", LEFT);
	setTextNode_addNodeToEnd(list, "    * ���� �÷��� ȭ�� ���� �ϴܿ� ��Ʈ�� ǥ�õ˴ϴ�.", MIDDLE);
	setTextNode_addNodeToEnd(list, "    * ��Ʈ ���� [ OFF ] ������, ����ġ�� 2��� ����˴ϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) ��Ʈ ���� [ O N ]    [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) ��Ʈ ���� [ OFF ]    [ ] ", LEFT);	
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    2 / 2                                    ", MIDDLE);

	return;
}

// �⺻ �� ����. Page 1
void screenText_MainScreen_Option_NumberSetting_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ N U M B E R _ S E T T I N G ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  * ������ Ǯ�̿� �־����� �⺻ ���� ��ġ�� ���� �����մϴ�.*", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. �������� ��ġ      [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. ��Ī���� ��ġ      [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * ��Ī�� ���� ������ ������������ �ֽ��ϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) ������ ��Ī           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) ǳ���� ��Ī (�⺻��)  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (3) ������ ��Ī           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (4) �𷡽ð��� ��Ī       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (5) ���� ����             [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    1 / 2                      [ [ ] - ���� ]", MIDDLE);

	return;
}

// �ʱⰪ ��Ī Type
void screenText_MainScreen_Option_NumberSetting_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ N U M B E R _ S E T T I N G ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. ��Ī���� ��ġ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  (1) ������ ��Ī                      (2) ǳ���� ��Ī", LEFT);
	setTextNode_addNodeToEnd(list, "    ��  ��  ��  ��                       ��������    ��", LEFT);
	setTextNode_addNodeToEnd(list, "      ��  ��  ��                             ����  ����", LEFT);
	setTextNode_addNodeToEnd(list, "    ��  ��  ��  ��                       ��������������", LEFT);
	setTextNode_addNodeToEnd(list, "      ��  ��  ��                         ����  ����    ", LEFT);
	setTextNode_addNodeToEnd(list, "    ��  ��  ��  ��                       ��    ��������", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  (3) ������ ��Ī (�¿�)           (4) �𷡽ð��� ��Ī (����)", LEFT);
	setTextNode_addNodeToEnd(list, "    ����      ����                       ��������������", LEFT);
	setTextNode_addNodeToEnd(list, "    ������  ������                         ����������  ", LEFT);
	setTextNode_addNodeToEnd(list, "    ��������������                           ������    ", LEFT);
	setTextNode_addNodeToEnd(list, "    ������  ������                         ����������  ", LEFT);
	setTextNode_addNodeToEnd(list, "    ����      ����                       ��������������", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    1 / 2                                    ", MIDDLE);

	return;
}

// ����� ���� ON / OFF.
void screenText_MainScreen_Option_SaveSheet(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ S A V E _ S H E E T ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. ������ ���� [ OFF ]     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * �÷����� �������� �������� �ʽ��ϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. ������ ���� [ O N ]     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * �÷����� �������� �����մϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "    * �������� �������ϰ� ���� ī�װ��� ����˴ϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) �������� ����       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) ������ + ���� ����  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                                                             ", MIDDLE);

	return;
}

// ���� & ������ Page 1
void screenText_MainScreen_Option_MusicDesigne_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. ���� ���", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) ���� ��� [ OFF ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) ���� ��� [ O N ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "     * ���� ����� �ð��� 2������ �ҿ� �ɼ� �ֽ��ϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "     * ��� ����� ���������� �ֽ��ϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [1] ���� ���       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [2] �˼� ���       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [3] BGM  ���       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    1 / 5                      [ [ ] - ���� ]", MIDDLE);

	return;
}

// ���� & ������ Page 2
void screenText_MainScreen_Option_MusicDesigne_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. �⺻ �� ' ǥ��", LEFT);
	setTextNode_addNodeToEnd(list, "    * �ʱ⿡ �־����� �⺻ ���� ���� ��������ǥ(') ǥ�ø� �մϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (1) �⺻�� ' ǥ�� [ O N ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (2) �⺻�� ' ǥ�� [ OFF ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  3. ��輱 ������", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (1) �⺻ ��         [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (2) �� ��           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (3) ��� �� ǥ��    [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (4) ��輱 ����     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    2 / 5                      [ [ ] - ���� ]", MIDDLE);

	return;
}

// ���� ����Ʈ
void screenText_MainScreen_Option_MusicDesigne_Page3(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (1) ���� ��� ���", LEFT);
	setTextNode_addNodeToEnd(list, "        [01] ���ĵ� �ֱ� - ������", LEFT);
	setTextNode_addNodeToEnd(list, "        [02] ������ - dream all day", LEFT);
	setTextNode_addNodeToEnd(list, "        [03] ������ - ����뷡���� �̺��뷡", LEFT);
	setTextNode_addNodeToEnd(list, "        [04] 40 - �������", LEFT);
	setTextNode_addNodeToEnd(list, "        [05] ��Ŵ - ��", LEFT);
	setTextNode_addNodeToEnd(list, "        [06] �� - �Ѿ��", LEFT);
	setTextNode_addNodeToEnd(list, "        [07] �迹�� - rain", LEFT);
	setTextNode_addNodeToEnd(list, "        [08] �ѵ��� - �״��� ��ġ", LEFT);
	setTextNode_addNodeToEnd(list, "        [09] �鿹�� - ����", LEFT);
	setTextNode_addNodeToEnd(list, "        [10] ����� - �̾���", LEFT);
	setTextNode_addNodeToEnd(list, "        [11] ���� - Love Story", LEFT);
	setTextNode_addNodeToEnd(list, "        [12] ���� - ������ ���", LEFT);
	setTextNode_addNodeToEnd(list, "        [13] ������ - ��", LEFT);
	setTextNode_addNodeToEnd(list, "        [14] �����ī�� - ���� �׸���", LEFT);
	setTextNode_addNodeToEnd(list, "        [15] ��ϳ� �̹߼� - ���� ������ ����", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    3 / 5                    [ ENTER - ���� ]", MIDDLE);

	return;
}

// �˼� ����Ʈ
void screenText_MainScreen_Option_MusicDesigne_Page4(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (2) �˼� ��� ���", LEFT);
	setTextNode_addNodeToEnd(list, "        [01] Camila Cabello - Havana", LEFT);
	setTextNode_addNodeToEnd(list, "        [02] Justin Bieber - Love Yourself", LEFT);
	setTextNode_addNodeToEnd(list, "        [03] Sam smith - I'm Not The Only One", LEFT);
	setTextNode_addNodeToEnd(list, "        [04] Ed Sheeran - Shape Of You", LEFT);
	setTextNode_addNodeToEnd(list, "        [05] Mike Perry - The Ocean", LEFT);
	setTextNode_addNodeToEnd(list, "        [06] Clean Bandit - Symphony", LEFT);
	setTextNode_addNodeToEnd(list, "        [07] Sia - Chandelier", LEFT);
	setTextNode_addNodeToEnd(list, "        [08] Pharrell Williams - Happy", LEFT);
	setTextNode_addNodeToEnd(list, "        [09] Sting - Shape Of My Heart", LEFT);
	setTextNode_addNodeToEnd(list, "        [10] Ariana Grande - Dangerous Woman", LEFT);
	setTextNode_addNodeToEnd(list, "        [11] Jeff Bernat - Call You Mine", LEFT);
	setTextNode_addNodeToEnd(list, "        [12] Adele - Hello", LEFT);
	setTextNode_addNodeToEnd(list, "        [13] Calvin Harris - Feels", LEFT);
	setTextNode_addNodeToEnd(list, "        [14] Imagine Dragons - Believer", LEFT);
	setTextNode_addNodeToEnd(list, "        [15] Dua Lipa - New Rules	", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    4 / 5                    [ ENTER - ���� ]", MIDDLE);

	return;
}

// BGM ����Ʈ
void screenText_MainScreen_Option_MusicDesigne_Page5(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (3) BGM ��� ���", LEFT);
	setTextNode_addNodeToEnd(list, "        [01] E's Jammy Jams - Jolly Old St Nicholas (Instrumental)", LEFT);
	setTextNode_addNodeToEnd(list, "        [02] Defqwop - Heart Afire", LEFT);
	setTextNode_addNodeToEnd(list, "        [03] Tobu - Higher", LEFT);
	setTextNode_addNodeToEnd(list, "        [04] Zaza - Be Together ", LEFT);
	setTextNode_addNodeToEnd(list, "        [05] Jim Yosef - Firefly", LEFT);
	setTextNode_addNodeToEnd(list, "        [06] Tobu & Marcus Mouya - Running Away", LEFT);
	setTextNode_addNodeToEnd(list, "        [07] Tobu - Roots", LEFT);
	setTextNode_addNodeToEnd(list, "        [08] Dj Okawari - Midnight Train ", LEFT);
	setTextNode_addNodeToEnd(list, "        [09] Elektronomia - Sky High", LEFT);
	setTextNode_addNodeToEnd(list, "        [10] Alan Walker - Fade", LEFT);
	setTextNode_addNodeToEnd(list, "        [11] ", LEFT);
	setTextNode_addNodeToEnd(list, "        [12]", LEFT);
	setTextNode_addNodeToEnd(list, "        [13]", LEFT);
	setTextNode_addNodeToEnd(list, "        [14]", LEFT);
	setTextNode_addNodeToEnd(list, "        [15]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    5 / 5                                    ", MIDDLE);

	return;
}

// ��� �߸��� Ƽ� �������� ���.
void screenText_MainScreen_Option_WARNING_wrongTier(PSTR_NODE list, PDATA data)
{
	char* tierStr = malloc(sizeof(char) * 100);
	char* levelStr = malloc(sizeof(char) * 100);
	memset(tierStr, 0, sizeof(char) * 100);
	memset(levelStr, 0, sizeof(char) * 100);

	switch (data->gameData->rate_myTier)
	{
	case 0:
	{
		sprintf(tierStr, ": ���� ����� [ ����� : BRONZE ] �Դϴ�.");
		sprintf(levelStr, ": ���� ������ [ %2d Level ] �Դϴ�.", data->gameData->rate_level);
		break;
	}
	case 1:
	{
		sprintf(tierStr, ": ���� ����� [ �ǹ� : SILVER ] �Դϴ�.");
		sprintf(levelStr, ": ���� ������ [ %2d Level ] �Դϴ�.", data->gameData->rate_level);
		break;
	}
	case 2:
	{
		sprintf(tierStr, ": ���� ����� [ ��� : GOLD ] �Դϴ�.");
		sprintf(levelStr, ": ���� ������ [ %2d Level ] �Դϴ�.", data->gameData->rate_level);
		break;
	}
	case 3:
	{
		sprintf(tierStr, ": ���� ����� [ �÷�Ƽ�� : PLATINUM ] �Դϴ�.");
		sprintf(levelStr, ": ���� ������ [ %2d Level ] �Դϴ�.", data->gameData->rate_level);
		break;
	}
	case 4:
	{
		sprintf(tierStr, ": ���� ����� [ ���̾Ƹ�� : DIAMOND ] �Դϴ�.");
		sprintf(levelStr, ": ���� ������ [ %2d Level ] �Դϴ�.", data->gameData->rate_level);
		break;
	}
	case 5:
	{
		sprintf(tierStr, ": ���� ����� [ ������ : MASTER ] �Դϴ�.");
		sprintf(levelStr, ": ���� ������ [ %2d Level ] �Դϴ�.", data->gameData->rate_level);
		break;
	}
	case 6:
	{
		sprintf(tierStr, ": ���� ����� [ �׷��� ������ : GRAND MASTER ] �Դϴ�.");
		sprintf(levelStr, ": ���� ������ [ %2d Level ] �Դϴ�.", data->gameData->rate_level);
		break;
	}
	}
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " = = W A R N I N G S", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "* �߸��� Ƽ� �����Ͽ����ϴ�. *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* �ڽ��� ��޿� �´� ���̵��� �����ؾ� �մϴ�. *", MIDDLE);
	setTextNode_addNodeToEnd(list, tierStr, MIDDLE);
	setTextNode_addNodeToEnd(list, levelStr, MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
}

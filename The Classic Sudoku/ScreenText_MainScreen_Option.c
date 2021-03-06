// screenText_MainScreen_Option.c 督析精 惟績 辛芝淫恵 努什闘亜 乞食赤澗 敗呪 督析.

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>

#include "screenText_MainScreen_Option.h"

#include "setTextNode.h"
#include "getDataStructure.h"
#include "setDataStructure.h"

// 惟績 竺舛 五昔鉢檎
void screenText_MainScreen_Option_Main(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ G A M E _ O P T I O N ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 貝戚亀  竺舛   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : 傾婚拭 魚献 貝戚亀(銅嬢)研 竺舛杯艦陥.          ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 奄沙 葵 竺舛   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : 什亀庭拭 舘辞亜 鞠澗 奄沙葵税 壕帖研 竺舛杯艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  3. 庚薦走  煽舌   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : 庚薦走, 岩照走 煽舌 政巷研 竺舛杯艦陥.          ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  4. 製焦 & 巨切昔  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : 製焦 仙持鯉系, 奄展 巨切昔級聖 竺舛杯艦陥.      ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                                                             ", MIDDLE);

	return;
}

// 貝戚亀 竺舛 吐 page1
void screenText_MainScreen_Option_Difficulty_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ D I F F I C U L T Y ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 貝戚亀(銅嬢) 竺舛", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 崎経綜          [ 54%  因鯵 ]       BRONZE", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 1 - 5)     [ 43鯵 舘辞 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 叔獄            [ 46%  因鯵 ]       SILVER", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 6 - 10)    [ 37鯵 舘辞 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (3) 茨球            [ 39%  因鯵 ]         GOLD", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 11 - 15)   [ 31鯵 舘辞 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (4) 巴掘銅角        [ 33%  因鯵 ]     PLATINUM", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 16 - 20)   [ 26鯵 舘辞 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (5) 陥戚焼佼球      [ 28%  因鯵 ]      DIAMOND", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 21 - 25)   [ 22鯵 舘辞 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    1 / 2                      [ [ ] - 陥製 ]", MIDDLE);
	
	return;
}

// 貝戚亀 竺舛 吐 page2
void screenText_MainScreen_Option_Difficulty_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ D I F F I C U L T Y ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 銅嬢 竺舛", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (6) 原什斗          [ 24%  因鯵 ]       MASTER",LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 26 - 30)   [ 19鯵 舘辞 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (7) 益沓球 原什斗   [ 21%  因鯵 ] GRAND MASTER", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 31 - 35)   [ 17鯵 舘辞 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 微闘 左奄", LEFT);
	setTextNode_addNodeToEnd(list, "    * 微闘澗 違帖走 省澗 収切級税 壕伸聖 左食掃艦陥. (亜稽, 室稽, 3x3)", LEFT);
	setTextNode_addNodeToEnd(list, "    * 惟績 巴傾戚 鉢檎 酔著 馬舘拭 微闘亜 妊獣桔艦陥.", MIDDLE);
	setTextNode_addNodeToEnd(list, "    * 微闘 左奄 [ OFF ] 竺舛獣, 井蝿帖亜 2壕稽 旋遂桔艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 微闘 左奄 [ O N ]    [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 微闘 左奄 [ OFF ]    [ ] ", LEFT);	
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    2 / 2                                    ", MIDDLE);

	return;
}

// 奄沙 葵 竺舛. Page 1
void screenText_MainScreen_Option_NumberSetting_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ N U M B E R _ S E T T I N G ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  * 什亀庭 熱戚拭 爽嬢走澗 奄沙 葵税 壕帖拭 企背 竺舛杯艦陥.*", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 巷拙是稽 壕帖      [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 企暢生稽 壕帖      [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * 企暢拭 企廃 竺誤精 陥製凪戚走拭 赤柔艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 刃穿莫 企暢           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 燃託莫 企暢 (奄沙葵)  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (3) 蟹搾莫 企暢           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (4) 乞掘獣域莫 企暢       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (5) 沓棋 識澱             [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    1 / 2                      [ [ ] - 陥製 ]", MIDDLE);

	return;
}

// 段奄葵 企暢 Type
void screenText_MainScreen_Option_NumberSetting_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ N U M B E R _ S E T T I N G ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 企暢生稽 壕帖", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  (1) 刃穿莫 企暢                      (2) 燃託莫 企暢", LEFT);
	setTextNode_addNodeToEnd(list, "    け  け  け  け                       けけけけ    け", LEFT);
	setTextNode_addNodeToEnd(list, "      け  け  け                             けけ  けけ", LEFT);
	setTextNode_addNodeToEnd(list, "    け  け  け  け                       けけけけけけけ", LEFT);
	setTextNode_addNodeToEnd(list, "      け  け  け                         けけ  けけ    ", LEFT);
	setTextNode_addNodeToEnd(list, "    け  け  け  け                       け    けけけけ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  (3) 蟹搾莫 企暢 (疎酔)           (4) 乞掘獣域莫 企暢 (呪送)", LEFT);
	setTextNode_addNodeToEnd(list, "    けけ      けけ                       けけけけけけけ", LEFT);
	setTextNode_addNodeToEnd(list, "    けけけ  けけけ                         けけけけけ  ", LEFT);
	setTextNode_addNodeToEnd(list, "    けけけけけけけ                           けけけ    ", LEFT);
	setTextNode_addNodeToEnd(list, "    けけけ  けけけ                         けけけけけ  ", LEFT);
	setTextNode_addNodeToEnd(list, "    けけ      けけ                       けけけけけけけ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    1 / 2                                    ", MIDDLE);

	return;
}

// 岩照走 煽舌 ON / OFF.
void screenText_MainScreen_Option_SaveSheet(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ S A V E _ S H E E T ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 庚薦走 煽舌 [ OFF ]     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * 巴傾戚廃 庚薦走研 煽舌馬走 省柔艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 庚薦走 煽舌 [ O N ]     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * 巴傾戚廃 庚薦走研 煽舌杯艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "    * 庚薦走澗 叔楳督析引 旭精 朝砺壱軒拭 煽舌桔艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 庚薦走幻 煽舌       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 庚薦走 + 岩走 煽舌  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                                                             ", MIDDLE);

	return;
}

// 製焦 & 巨切昔 Page 1
void screenText_MainScreen_Option_MusicDesigne_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 製焦 仙持", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 製焦 仙持 [ OFF ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 製焦 仙持 [ O N ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "     * 製焦 仙持獣 獣娃戚 2段舛亀 社推 吃呪 赤柔艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "     * 仙持 鯉系精 急凪戚走拭 赤柔艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [1] 亜推 仙持       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [2] 橡勺 仙持       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [3] BGM  仙持       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    1 / 5                      [ [ ] - 陥製 ]", MIDDLE);

	return;
}

// 製焦 & 巨切昔 Page 2
void screenText_MainScreen_Option_MusicDesigne_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 奄沙 葵 ' 妊獣", LEFT);
	setTextNode_addNodeToEnd(list, "    * 段奄拭 爽嬢走澗 奄沙 収切 新拭 拙精魚身妊(') 妊獣研 杯艦陥.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (1) 奄沙葵 ' 妊獣 [ O N ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (2) 奄沙葵 ' 妊獣 [ OFF ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  3. 井域識 巨切昔", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (1) 奄沙 葵         [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (2) 繊 識           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (3) 乞窮 識 妊獣    [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (4) 井域識 薦暗     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    2 / 5                      [ [ ] - 陥製 ]", MIDDLE);

	return;
}

// 亜推 軒什闘
void screenText_MainScreen_Option_MusicDesigne_Page3(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (1) 亜推 仙持 鯉系", LEFT);
	setTextNode_addNodeToEnd(list, "        [01] 什田漁 蕉益 - 巷走鯵", LEFT);
	setTextNode_addNodeToEnd(list, "        [02] 沿走呪 - dream all day", LEFT);
	setTextNode_addNodeToEnd(list, "        [03] 嬢庭欠崎 - 紫櫛葛掘旭精 戚紺葛掘", LEFT);
	setTextNode_addNodeToEnd(list, "        [04] 40 - 笈澗畷走", LEFT);
	setTextNode_addNodeToEnd(list, "        [05] 虹鉄 - 搾", LEFT);
	setTextNode_addNodeToEnd(list, "        [06] 拠 - 角嬢人", LEFT);
	setTextNode_addNodeToEnd(list, "        [07] 沿森顕 - rain", LEFT);
	setTextNode_addNodeToEnd(list, "        [08] 廃疑悦 - 益企虞澗 紫帖", LEFT);
	setTextNode_addNodeToEnd(list, "        [09] 拷森鍵 - 亜懐", LEFT);
	setTextNode_addNodeToEnd(list, "        [10] 丞陥析 - 耕照背", LEFT);
	setTextNode_addNodeToEnd(list, "        [11] 呪空 - Love Story", LEFT);
	setTextNode_addNodeToEnd(list, "        [12] 走坪 - 神幻引 畷胃", LEFT);
	setTextNode_addNodeToEnd(list, "        [13] 映遭焼 - 魁", LEFT);
	setTextNode_addNodeToEnd(list, "        [14] 嬢鋼切朝督 - 砂聖 益軒陥", LEFT);
	setTextNode_addNodeToEnd(list, "        [15] 情艦革 戚降社 - 亜舌 左搭税 糎仙", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    3 / 5                    [ ENTER - 陥製 ]", MIDDLE);

	return;
}

// 橡勺 軒什闘
void screenText_MainScreen_Option_MusicDesigne_Page4(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (2) 橡勺 仙持 鯉系", LEFT);
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
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    4 / 5                    [ ENTER - 陥製 ]", MIDDLE);

	return;
}

// BGM 軒什闘
void screenText_MainScreen_Option_MusicDesigne_Page5(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (3) BGM 仙持 鯉系", LEFT);
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
	setTextNode_addNodeToEnd(list, "[ ESC - 及稽 ]                    5 / 5                                    ", MIDDLE);

	return;
}

// 井壱庚 設公吉 銅嬢研 識澱梅聖 井酔.
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
		sprintf(tierStr, ": 薄仙 去厭精 [ 崎経綜 : BRONZE ] 脊艦陥.");
		sprintf(levelStr, ": 薄仙 傾婚精 [ %2d Level ] 脊艦陥.", data->gameData->rate_level);
		break;
	}
	case 1:
	{
		sprintf(tierStr, ": 薄仙 去厭精 [ 叔獄 : SILVER ] 脊艦陥.");
		sprintf(levelStr, ": 薄仙 傾婚精 [ %2d Level ] 脊艦陥.", data->gameData->rate_level);
		break;
	}
	case 2:
	{
		sprintf(tierStr, ": 薄仙 去厭精 [ 茨球 : GOLD ] 脊艦陥.");
		sprintf(levelStr, ": 薄仙 傾婚精 [ %2d Level ] 脊艦陥.", data->gameData->rate_level);
		break;
	}
	case 3:
	{
		sprintf(tierStr, ": 薄仙 去厭精 [ 巴掘銅角 : PLATINUM ] 脊艦陥.");
		sprintf(levelStr, ": 薄仙 傾婚精 [ %2d Level ] 脊艦陥.", data->gameData->rate_level);
		break;
	}
	case 4:
	{
		sprintf(tierStr, ": 薄仙 去厭精 [ 陥戚焼佼球 : DIAMOND ] 脊艦陥.");
		sprintf(levelStr, ": 薄仙 傾婚精 [ %2d Level ] 脊艦陥.", data->gameData->rate_level);
		break;
	}
	case 5:
	{
		sprintf(tierStr, ": 薄仙 去厭精 [ 原什斗 : MASTER ] 脊艦陥.");
		sprintf(levelStr, ": 薄仙 傾婚精 [ %2d Level ] 脊艦陥.", data->gameData->rate_level);
		break;
	}
	case 6:
	{
		sprintf(tierStr, ": 薄仙 去厭精 [ 益沓球 原什斗 : GRAND MASTER ] 脊艦陥.");
		sprintf(levelStr, ": 薄仙 傾婚精 [ %2d Level ] 脊艦陥.", data->gameData->rate_level);
		break;
	}
	}
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " = = W A R N I N G S", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 設公吉 銅嬢研 識澱馬心柔艦陥. *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 切重税 去厭拭 限澗 貝戚亀研 識澱背醤 杯艦陥. *", MIDDLE);
	setTextNode_addNodeToEnd(list, tierStr, MIDDLE);
	setTextNode_addNodeToEnd(list, levelStr, MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
}

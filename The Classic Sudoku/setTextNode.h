#ifndef SET_TEXT_NODE_H
#define SET_TEXT_NODE_H

typedef enum _ARRANGEMENT
{
	ELSE = 0,
	LEFT,
	MIDDLE,
	RIGHT
} ARRANGEMENT;

typedef struct _STR_NODE
{
	struct _STR_NODE *nextNode;
	char* str;
	int strLnegth;
	int nodeNumber;
	ARRANGEMENT arrange;
} STR_NODE, *PSTR_NODE;


void setTextNode_addNodeToEnd(PSTR_NODE list, char* str, ARRANGEMENT arrange);
void setTextNode_addNodeToStart(PSTR_NODE list, char* str, ARRANGEMENT arrange);
void setTextNode_eraseNodeToStart(PSTR_NODE list);
void setTextNode_freeNodes(PSTR_NODE list);

#endif

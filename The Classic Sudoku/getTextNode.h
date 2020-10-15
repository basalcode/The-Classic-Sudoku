#ifndef GET_TEXT_NODE_H
#define GET_TEXT_NODE_H

#include "setTextNode.h"

PSTR_NODE getTextNode_allocInitHeader();
int getTextNode_getNodeMax(PSTR_NODE list);
int getTextNode_getStringLengthMax(PSTR_NODE list);

#endif

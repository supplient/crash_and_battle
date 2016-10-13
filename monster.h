#pragma once//°¡£¬ÎÒ»¹Ð´¸öÆ¨ifndef°¡¡­¡­

#include "animal.h"

class monster:public animal
{
public:
	monster(elementSignChar _signChar = MONSTER_CHAR, elementSignColor _signColor = MONSTER_COLOR, elementType _type = MONSTER)
		:animal(_signChar, _signColor, _type)
	{
	}

	virtual ~monster()
	{
	}

	//virtual timerEvent* AIThinking();

private:

};

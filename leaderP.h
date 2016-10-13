#pragma once

#include "person.h"

class leaderP:public person
{
public:
	leaderP(elementSignChar _signChar = LEADER_P_CHAR, elementSignColor _signColor = LEADER_P_COLOR, elementType _type = LEADER_P)
		:person(_signChar, _signColor, _type)
	{
	}

	virtual ~leaderP()
	{
	}

	//virtual timerEvent* AIThinking();

private:

};

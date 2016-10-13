#pragma once

#include "person.h"

class followerP:public person
{
public:
	followerP(elementSignChar _signChar = FOLLOWER_P_CHAR, elementSignColor _signColor = FOLLOWER_P_COLOR, elementType _type = FOLLOWER_P)
		:person(_signChar, _signColor, _type)
	{
	}

	virtual ~followerP()
	{
	}

	//virtual timeEvent* AIThinking();

private:

};

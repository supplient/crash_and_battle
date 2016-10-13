#pragma once

#include "person.h"

class player:public person
{
public:
	player(elementSignChar _signChar = PLAYER_CHAR, elementSignColor _signColor = PLAYER_COLOR, elementType _type = PLAYER)
		:person(_signChar, _signColor, _type)
	{
	}

	virtual ~player()
	{
	}

private:

};

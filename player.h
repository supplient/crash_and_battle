#pragma once

#include "person.h"

class player:public person
{
public:
	virtual ~player()
	{
	}

	static player* getInstance()
	{
		if (onlyInstance)
			return onlyInstance;
		onlyInstance = new player;
		return onlyInstance;
	}

private:
	static player* onlyInstance;

	player(elementSignChar _signChar = PLAYER_CHAR, elementSignColor _signColor = PLAYER_COLOR, elementType _type = PLAYER)
		:person(_signChar, _signColor, _type)
	{
	}
};

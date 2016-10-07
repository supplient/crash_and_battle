#pragma once

#include "macro.h"

struct pos
{
	int x;
	int y;
	pos(int _x = 0, int _y = 0)
	{
		if (_x < 0)
			x = 0;
		else if (_x >= MAP_SIZE)
			x = MAP_SIZE;
		else
			x = _x;

		if (_y < 0)
			y = 0;
		else if (_y >= MAP_SIZE)
			y = MAP_SIZE;
		else
			y = _y;
	}
};

bool isValid(const pos & p);

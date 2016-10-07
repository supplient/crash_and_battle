#include "pos.h"

bool isValid(const pos & p)
{
	if (p.x < 0 || p.x >= MAP_SIZE || p.y < 0 || p.y >= MAP_SIZE)
		return false;
	return true;
}
#pragma once

enum elementSignChar
{
	OBJECT_CHAR = 'O',
		ANIMAL_CHAR = 'A',
			PERSON_CHAR = 'P',
				FOLLOWER_P_CHAR = PERSON_CHAR,
				LEADER_P_CHAR = PERSON_CHAR,
				PLAYER_CHAR = '@',
			MONSTER_CHAR = 'M'
};

struct elementSignColor
{
	int red;
	int green;
	int blue;
	elementSignColor(int r, int g, int b) :red(r), green(g), blue(b)
	{
	}
};

const elementSignColor OBJECT_COLOR(255, 0, 0);
const elementSignColor ANIMAL_COLOR(255, 0, 0);
const elementSignColor PERSON_COLOR(255, 0, 0);
const elementSignColor MONSTER_COLOR(255, 0, 0);
const elementSignColor PLAYER_COLOR(255, 0, 0);
const elementSignColor LEADER_P_COLOR(255, 0, 0);
const elementSignColor FOLLOWER_P_COLOR(255, 0, 0);
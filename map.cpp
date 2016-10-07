#include <random>
#include "map.h"
#include "pos.h"
#include "macro.h"

vector<object*> map::search(int x, int y, int view)
{
	vector<object*> res;
	view = (view + 1) / 2;
	int left = x - view > 0 ? x - view : 0;
	int right = x + view < MAP_SIZE ? x + view + 1 : MAP_SIZE;
	int top = y - view > 0 ? y - view : 0;
	int bottom = y + view < MAP_SIZE ? y + view + 1 : MAP_SIZE;

	for (int x = left; x < right; x++)
	{
		for (int y = top; y < bottom; y++)
		{
			object * n;
			if (n = table[x][y].getContent())
				res.push_back(n);
		}
	}

	return res;
}

bool map::remove(int x, int y, object * t)
{
	if (!isValid(pos(x, y)))
		return false;

	if (!table[x][y].getContent())
		return false;
	if (t)
		if (table[x][y].getContent() != t)
			return false;
	table[x][y].setContent(nullptr);
	return true;
}

bool map::put(int x, int y, object * t)
{
	if (!isValid(pos(x, y)))
		return false;

	if (table[x][y].getContent())
		return false;
	if (!t)
		return false;
	table[x][y].setContent(t);
	return true;
}

char ** map::getPaintingMap()
{
	char** res = new char*[MAP_SIZE];

	for (int i = 0; i < MAP_SIZE; i++)
		res[i] = new char[MAP_SIZE];
	for (int x=0;x<MAP_SIZE;x++)
		for (int y = 0; y < MAP_SIZE; y++)
		{
			if (table[x][y].getContent())
				res[x][y] = table[x][y].getContent()->signChar;
			else
				res[x][y] = MAP_BLANK;
		}

	return res;
}

bool map::random_generate()
{
	table.resize(MAP_SIZE);
	for (auto& row : table)
		row.resize(MAP_SIZE);

	std::default_random_engine gen;
	std::uniform_int_distribution<int> dis(0, MAP_SIZE-1);

	for (int n = 0; n < MONSTER_NUM; n++)
	{
		monster* m = new monster;

		int exc_count = 0;
		while (true)
		{
			int x = dis(gen);
			int y = dis(gen);
			bool flag = table[x][y].setContent(m);
			if (flag)
			{
				m->setPos(pos(x, y));
				break;
			}
			exc_count++;
			if (exc_count > 100)
				throw "ERROR!In map generating!";
		}
	}

	for (int n = 0; n < PERSON_NUM; n++)
	{
		person* p = new person;

		int exc_count = 0;
		while (true)
		{
			int x = dis(gen);
			int y = dis(gen);
			bool flag = table[x][y].setContent(p);
			if (flag)
			{
				p->setPos(pos(x, y));
				break;
			}
			exc_count++;
			if (exc_count > MAP_SIZE*MAP_SIZE)
				throw "ERROR!In map generating!";
		}
	}

	const int middle = MAP_SIZE / 2;
	player* p = new player;
	int exc_count = 0;
	bool flag = false;
	for (int offset = 0; offset < middle; offset++)
	{
		for (int x = middle - offset; x <= middle + offset; x++)
		{
			for (int y = middle - offset; y <= middle + offset; y++)
			{
				bool flag = table[x][y].setContent(p);
				if (flag)
				{
					p->setPos(pos(x, y));
					break;
				}
				exc_count++;
				if (exc_count > MAP_SIZE *MAP_SIZE * 2)
					throw "ERROR!In player putting!";
			}
			if (flag)
				break;
		}
		if (flag)
			break;
	}

	return true;
}

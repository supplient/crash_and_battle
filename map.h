#pragma once

#include <vector>
#include "mapNode.h"
#include "elements.h"

#define MAP_BLANK '+'

class map
{
public:
	map()
	{
		if (!random_generate())
			throw "ERROR!In map generating!";
	}

	~map()
	{
	}

	vector<object*> search(int x, int y, int view);
	bool remove(pos p, object* t = nullptr) { return remove(p.x, p.y, t); }
	bool remove(int x, int y, object* t=nullptr);
	bool put(pos p, object*t) { return put(p.x, p.y, t); }
	bool put(int x, int y, object* t);

	char** getPaintingMap();

private:
	 std::vector<vector<mapNode>> table;

	 bool random_generate();
};

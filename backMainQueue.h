#pragma once

#include <queue>
#include "mainEvent.h"

using std::queue;

class backMainQueue
{
public:
	backMainQueue()
	{
	}

	~backMainQueue()
	{
	}

	mainEvent* pop();
	void push(mainEvent*);
	int size() { return wheel.size(); }

private:
	queue<mainEvent*> wheel;
};
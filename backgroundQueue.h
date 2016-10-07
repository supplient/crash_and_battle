#pragma once

#include <queue>
#include "backgroundEvent.h"

using std::queue;

class backgroundQueue
{
public:
	backgroundQueue()
	{
	}

	~backgroundQueue()
	{
	}

	backgroundEvent* pop();
	void push(backgroundEvent*);
	int size() { return wheel.size(); }

private:
	queue<backgroundEvent*> wheel;
};
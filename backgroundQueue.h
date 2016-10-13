#pragma once

#include <queue>
#include "backgroundEvent.h"

using std::queue;

class backgroundQueue
{
public:
	~backgroundQueue()
	{
	}

	backgroundEvent* pop();
	void push(backgroundEvent*);
	int size() { return wheel.size(); }

	static backgroundQueue* getInstance();

private:
	queue<backgroundEvent*> wheel;

	static backgroundQueue* onlyInstance;

	backgroundQueue()
	{
	}
};
#pragma once

#include <queue>
#include <vector>
#include "timerEvent.h"

using std::priority_queue;
using std::vector;

struct cmp
{
	bool operator() (timerEvent* a, timerEvent* b)
	{
		if (a->getTime() > b->getTime())
			return true;
		return false;
	}
};

class backTimerQueue
{
public:
	~backTimerQueue() {}

	bool push(timerEvent*);
	timerEvent* pop();
	timerEvent* top();
	int size() { return wheel.size(); }

	bool countdown();

	static backTimerQueue* getInstance();

private:
	priority_queue<timerEvent*, vector<timerEvent*>, cmp> wheel;

	static backTimerQueue* onlyInstance;

	backTimerQueue() {}
};
#include "backMainQueue.h"

mainEvent * backMainQueue::pop()
{
	if (wheel.size() == 0)
		return nullptr;
	mainEvent* res = wheel.front();
	wheel.pop();
	return res;
}

void backMainQueue::push(mainEvent * p)
{
	if (!p)
		return;
	wheel.push(p);
}

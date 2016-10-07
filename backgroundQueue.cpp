#include "backgroundQueue.h"

backgroundEvent * backgroundQueue::pop()
{
	if (wheel.size() == 0)
		return nullptr;
	backgroundEvent* res = wheel.front();
	wheel.pop();
	return res;
}

void backgroundQueue::push(backgroundEvent * p)
{
	if (!p)
		return;
	wheel.push(p);
}

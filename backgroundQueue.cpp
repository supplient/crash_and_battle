#include "backgroundQueue.h"

backgroundQueue* backgroundQueue::onlyInstance = backgroundQueue::onlyInstance ? backgroundQueue::onlyInstance : nullptr;

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

backgroundQueue * backgroundQueue::getInstance()
{
	if (onlyInstance)
		return onlyInstance;
	onlyInstance = new backgroundQueue;
	return onlyInstance;
}

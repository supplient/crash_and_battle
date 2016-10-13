#include "backMainQueue.h"

backMainQueue* backMainQueue::onlyInstance = new backMainQueue;

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

backMainQueue * backMainQueue::getInstance()
{
	if (onlyInstance)
		return onlyInstance;
	onlyInstance = new backMainQueue;
	return onlyInstance;
}

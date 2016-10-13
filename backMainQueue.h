#pragma once

#include <queue>
#include "mainEvent.h"

using std::queue;

class backMainQueue
{
public:
	

	~backMainQueue()
	{
	}

	mainEvent* pop();
	void push(mainEvent*);
	int size() { return wheel.size(); }

	static backMainQueue* getInstance();

private:
	queue<mainEvent*> wheel;

	static backMainQueue* onlyInstance;

	backMainQueue()
	{
	}
};
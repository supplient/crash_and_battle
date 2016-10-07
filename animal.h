#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#include "object.h"
#include "timerEvent.h"
#include <vector>

using std::vector;

class animal :public object
{
public:
	animal():object()
	{
	}

	virtual ~animal()
	{
	}

	//virtual timerEvent* AIThinking();

	virtual int getView() { return view; }
	virtual animal* getLeader() { return leader; }
	virtual bool setLeader(animal*);
	virtual const vector<animal*> & getFollower() { return follower; }
	virtual bool addFollower(animal* p) { follower.push_back(p); return true; }
	virtual bool removeFollower(animal* p);

private:
	int view;
	animal* leader;
	vector<animal*> follower;
	
};
#endif // !ANIMAL_H

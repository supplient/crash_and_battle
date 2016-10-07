#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "animal.h"

class person:public animal
{
public:
	person() :animal()
	{
	}

	virtual ~person()
	{
	}

	//virtual timerEvent* AIThinking();

	int getFame() { return fame; }
	void changeFame(int delta) { fame += delta; }


private:
	int fame;
};


#endif // !PERSON_H

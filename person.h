#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "animal.h"

class person:public animal
{
public:
	person(elementSignChar _signChar = PERSON_CHAR, elementSignColor _signColor = PERSON_COLOR, elementType _type = PERSON)
		:animal(_signChar, _signColor, _type)
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

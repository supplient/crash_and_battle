#pragma once

#include "eventType.h"

class mainEvent
{
public:
	mainEvent(eventType _type=MAIN_EVENT):type(_type)
	{
	}

	virtual ~mainEvent()
	{
	}

	eventType type;
	virtual eventType getType() { return type; }

private:

};

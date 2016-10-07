#pragma once

#include "eventType.h"

class backgroundEvent
{
public:
	backgroundEvent(eventType _type=BACKGROUND_EVENT):type(_type)
	{
	}

	virtual ~backgroundEvent()
	{
	}

	eventType type;
	virtual eventType getType() { return type; }

private:

};

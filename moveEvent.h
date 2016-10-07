#pragma once

#include "mainEvent.h"
#include "elements.h"
#include "pos.h"

class moveEvent:public mainEvent
{
public:
	moveEvent(object* _target, pos _to, eventType _type = MOVE_EVENT) :mainEvent(_type), target(_target), to(_to)
	{
	}

	virtual ~moveEvent()
	{
	}

	object* getTarget() { return target; }
	pos getTo() { return to; }

	virtual eventType getType() { return mainEvent::getType(); }

private:
	object* target;
	pos to;
};

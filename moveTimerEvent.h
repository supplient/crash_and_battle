#pragma once

#include "timerEvent.h"
#include "moveEvent.h"

class moveTimerEvent:public timerEvent , public moveEvent
{
public:
	moveTimerEvent(int _leftTime, object* _target, pos _to, eventType _type = MOVE_TIMER_EVENT)
		:timerEvent(_leftTime, _type), moveEvent(_target, _to, _type)
	{
	}

	virtual ~moveTimerEvent()
	{
	}

	virtual mainEvent* turnToMainEvent();

	virtual eventType getType() { return timerEvent::getType(); }

private:
	
};

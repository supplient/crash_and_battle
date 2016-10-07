#pragma once
#ifndef TIMER_EVENT_H
#define TIMER_EVENT_H

#include "mainEvent.h"


class timerEvent
{
public:
	timerEvent(int _leftTime, eventType _type = TIMER_EVENT) :leftTime(_leftTime), type(_type)
	{
	}

	virtual ~timerEvent()
	{
	}

	int getTime() { return leftTime; }

	/**
	@brief	count down the timer event.

	@return true	still count downing.
	@return false	there is no left time.
	*/
	virtual bool countdown();
	virtual mainEvent* turnToMainEvent();

	virtual eventType getType() { return type; }

protected:
	eventType type;

private:
	int leftTime;
};

#endif // !TIMER_EVENT_H

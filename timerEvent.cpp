#include "timerEvent.h"

bool timerEvent::countdown()
{
	if (leftTime <= 0)
		return false;
	leftTime--;
	return true;
}

mainEvent * timerEvent::turnToMainEvent()
{
	mainEvent* p = new mainEvent();
	return p;
}

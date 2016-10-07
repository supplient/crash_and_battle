#include "moveTimerEvent.h"

mainEvent * moveTimerEvent::turnToMainEvent()
{
	moveEvent* np = new moveEvent(this->getTarget(), this->getTo());
	return np;
}

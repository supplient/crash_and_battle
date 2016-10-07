#pragma once

#include "backgroundEvent.h"

/**
@brief	player's keyboard input back event
@init	char _key
@func	
char getKey()
void setKey(char)
*/
class keyboardEvent:public backgroundEvent
{
public:
	keyboardEvent(char _key, eventType _type = KEYBOARD_EVENT) :key(_key), backgroundEvent(_type)
	{
	}

	virtual ~keyboardEvent()
	{
	}

	char getKey() { return key; }
	void setKey(char _key) { key = _key; }

	virtual eventType getType() { return backgroundEvent::getType(); }

private:
	char key;
};

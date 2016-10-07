#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include "elementType.h"
#include "elementSign.h"
#include "pos.h"

class object
{
public:
	object(elementSignChar _signChar=OBJECT_CHAR,elementSignColor _signColor=OBJECT_COLOR,elementType _type=OBJECT)
		:signChar(_signChar),signColor(_signColor),type(_type)
	{
	}

	virtual ~object()
	{
	}

	const elementSignChar signChar;
	const elementSignColor signColor;
	const elementType type;

	pos getPos() { return position; }
	void setPos(pos np) { position = np; }

private:
	pos position;
};

#endif // !OBJECT_H

#pragma once

#include "object.h"

class mapNode
{
public:
	mapNode(object*_content=nullptr):content(_content)
	{
	}

	~mapNode()
	{
		if (content)
			delete content;
	}

	bool setContent(object*);
	object* getContent();

private:
	object* content;
};

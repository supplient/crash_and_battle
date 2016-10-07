#include "mapNode.h"

bool mapNode::setContent(object * _content)
{
	if (content)
		return false;
	content = _content;
	return true;
}

object * mapNode::getContent()
{
	return content;
}

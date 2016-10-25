#include "mapNode.h"

bool mapNode::setContent(object * _content)
{
	content = _content;
	return true;
}

object * mapNode::getContent()
{
	return content;
}

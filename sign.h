#pragma once

enum elementSignChar
{
	OBJECT_CHAR='O'
};

struct elementSignColor
{
	char red;
	char green;
	char blue;
	elementSignColor(char r, char g, char b) :red(r), green(g), blue(b)
	{
	}
};

const elementSignColor OBJECT_COLOR(static_cast<char>(255), static_cast<char>(0), static_cast<char>(0));
#pragma once
#include "Element.h"
#include "Coockies.h"

class Wall :public Element
{
public:

	void mark(char *M[], Coockies &c);
	void draw(char *M[]);

	Wall(int x, int y, int width, int high)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->high = high;
	}

private:
	int x;
	int y;
	int width;
	int high;
};

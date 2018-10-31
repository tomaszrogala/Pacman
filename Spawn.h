#pragma once
#include "Element.h"
#include "Coockies.h"

class Spawn :public Element
{
public:
	void mark(char *M[], Coockies &c);
	void draw(char *M[]);

	Spawn(int width = 10, int high = 4,int x = 12, int y = 6)
	{
		this->width = width;
		this->high = high;
		this->x = x;
		this->y = y;
	}

private:
	int x;
	int y;
	int width;
	int high;
};
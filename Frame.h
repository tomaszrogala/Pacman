#pragma once
#include "Element.h"
#include "Coockies.h"

class Frame :public Element
{
public:

	void mark(char *M[], Coockies &c);
	void draw(char *M[]);

	Frame(int width = 16, int high = 11)
	{
		this->width = width;
		this->high = high;
	}

private:
	int width;
	int high;
};

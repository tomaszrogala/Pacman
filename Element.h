#pragma once
#include "Header.h"


class Element
{
public:
	virtual void mark(char *M[], Coockies &c) = 0;
	virtual void draw(char *M[]) = 0;

protected:

	int width;
	int high;

};
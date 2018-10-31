#pragma once
#include "Element.h"

class Coockies: public Element
{

public:

	friend class Pacman;
	friend class Ghost;

	int number;
	void mark(char *M[], Coockies &c);
	void draw(char *M[]);
	Coockies(int width = 34, int high = 16)
	{
		number = 0;
		this->width = width;
		this->high = high;

		C = new bool *[width + 1];
		
		for (int j = 0; j < width; j++)
		{
			C[j] = new bool[high+1];
		}

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < high; j++)
			{
				C[i][j] = false;
			}
		}
	}
	
	~Coockies()
	{
		for (int j = 0; j < width; j++)
		{
			delete[] C[j];
		}
		delete[] C;
		
	}
	
	bool **C;
protected:
	int width;
	int high;
	int x;
	int y;
};
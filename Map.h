#pragma once
#include "Header.h"
#include "Creation.h"
#include "Element.h"

class Map 
{
public:

	friend class Creation;
	friend class Ghost;
	friend class Pacman;
	friend class Element;
	friend class Frame;
	friend class Wall;
	friend class Coockies;

	int spread; int high;
	Creation *creat[30];
	Element *element[22];
	char **M;
	
	Map(int width, int high)
	{
		this->spread = width;
		this->high = high;
		M = new char*[width +1];

		for (int i = 0; i < width +1; i++)
		{
			M[i] = new char[high+1];
		}

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < high; j++)
			{
				M[i][j] = 'f';
			}
		}
	}

	~Map()
	{
		for (int i = 0; i < spread + 1; i++)
		{
			delete[] M[i];
		}
		delete[] M;
	}
};
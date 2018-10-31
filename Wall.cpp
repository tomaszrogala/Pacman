#include "Wall.h"
#include "Map.h"

void Wall::draw(char *M[])
{
	text_color_red();
	
	for (int i = x; i < (width + x); i++){
		for (int j = y; j < (high+y); j++){
			gotoxy(i, j);
			std::cout << '|';
		}
	}

	color_standard();
}

void Wall::mark(char *M[], Coockies &c)
{
	for (int i = x; i < (width+x); i++){
		for (int j = y; j < (high+y); j++){
			c.C[i][j] = false;
			M[i][j] = '|';
		}
	}
}
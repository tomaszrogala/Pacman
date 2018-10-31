#include "Spawn.h"


void Spawn::draw(char *M[])
{
	color_standard();

	for (int i = x; i < width+x; i++){
		if (M[i][y] == '.'){
			gotoxy(i, y);
			std::cout << '-';
		}	
	}

	for (int i = y; i < high+y; i++){
		if (M[x][i] == '.'){
			gotoxy(x, i);
			std::cout << '-';
		}
	}

	for (int i = x; i < width + x; i++){
		if (M[i][y + high-1] == '.'){
			gotoxy(i, y+high-1);
			std::cout << '-';
		}
	}

	for (int i = y; i < high +y; i++){
		if (M[x + width - 1][i] == '.'){
			gotoxy(x + width-1, i);
			std::cout << '-';
		}
	}

	for (int i = x+1; i < width + x-1; i++) {
		for (int j = y+1; j < high + y-1; j++) {
			if (M[i][j] == '-') {
				gotoxy(i, j);
				std::cout << ' ';
			}
		}
	}
	color_standard();
}

void Spawn::mark(char *M[], Coockies &c)
{
	for (int i = x; i < width + x; i++) {
		for (int j = y; j < high + y; j++) {
			if (j == y || i == x|| j ==(high+y -1)|| i== width+x-1){
				if (M[i][j] != '|'){
					c.C[i][j] = false;
					c.number--;
					M[i][j] = '.';
				}
			}
			else if (M[i][j] != '|'){
				c.C[i][j] = false;
				c.number--;
				M[i][j] = '-';
			}
		}
	}
}
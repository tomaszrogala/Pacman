#include "Coockies.h"

void Coockies::mark(char *M[], Coockies &c)
{
	M[1][1] = 'O';
	M[width - 2][high - 2] = 'O';
	M[1][high - 2] = 'O';
	M[width - 2][1] = 'O';

	for (int i = 0; i < width; i++){
		for (int j = 0; j < high; j++){
			if (M[i][j] == 'f'){
				C[i][j] = true;
				M[i][j] = 'o';
				number++;
			}
		}
	}
}

void Coockies::draw(char *M[])
{
	for (int i = 0; i < width; i++)	{
		for (int j = 0; j < high; j++){
			if (M[i][j] == 'o'){
				text_color_gold();
				gotoxy(i, j);
				std::cout << '*';
				color_standard();
			}
			else if (M[i][j] == 'O'){
				text_color_gold();
				gotoxy(i, j);
				std::cout << 'O';
				color_standard();
			}
		}
	}

	color_standard();
}
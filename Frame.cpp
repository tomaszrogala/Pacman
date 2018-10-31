#include "Frame.h"

void Frame::draw(char *M[])
{
	text_color_red();

	for (int i = 0; i < width; i++){
		gotoxy(i, 0);
		std::cout << '|';
	}

	for (int i = 0; i < high; i++){
		gotoxy(0, i);
		std::cout << '|';
	}

	for (int i = 0; i < width; i++){
		gotoxy(i, high-1);
		std::cout << '|';
	}

	for (int i = 0; i < high; i++){
		gotoxy(width-1, i);
		std::cout << '|';
	}

	color_standard();
}

void Frame::mark(char *M[], Coockies &c)
{
	for (int i = 0; i < width; i++){
		c.C[i][0]=false;
		M[i][0] = '*';
	}

	for (int i = 0; i < high; i++){
		c.C[0][i]=false;
		M[0][i] = '*';
	}

	for (int i = 0; i < width; i++){
		c.C[i][high - 1] = false;
		M[i][high-1] = '*';
	}

	for (int i = 0; i < high; i++){
		c.C[width - 1][i] = false;
		M[width-1][i] = '*';
	}
}


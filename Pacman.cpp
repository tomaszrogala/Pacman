#include "Pacman.h"

void Pacman::view()
{
	text_color_aquamarine();
	std::cout << sign;
	color_standard();
}

void Pacman::erase(bool *C[])
{
	std::cout << ' ';
}

void Pacman::change(bool &flag, char*M[])
{
	if (flag){
		this->sign = 'Q';
		flag = false;
		return;
	}
	else{
		this->sign = 'P';
		flag = true;
		return;
	}
}

void Pacman::set_start_possition(char *M[])
{
	do{
		x = rand() % 15;
		y = rand() % 15;
		gotoxy(x, y);

	} while (M[x][y] != 'f' && M[x][y] != 'o'&& M[x][y] != 'O');

	M[x][y] = sign;
}

void Pacman::set_possition(char *M[], char &button, int &ghost_number, bool &ghost_death, int &x, int &y, bool flag)
{
	gotoxy(this->x, this->y);
	x = this->x;
	y = this->y;
	if (M[this->x][this->y] == 'A')
		game_over(button);
	if (M[this->x][this->y] == 'V')
		ghost_death = true;

	M[this->x][this->y] = sign;
}

void Pacman::move(char &button,char *M[], bool &flag, int p_x, int p_y, int &c_numb, bool *C[])
{
	M[x][y] = 'f';
	if (C[x][y] == true)
		c_numb--;
	C[x][y] = false;

	switch (button)
	{
	case 72:
		if (M[x][y - 1] == 'f' || M[x][y - 1] == 'A' || M[x][y - 1] == 'o' || M[x][y - 1] == 'O' || M[x][y - 1] == 'V'){
			if (M[x][y - 1] == 'O'){
				if (sign == 'P'){
					change(flag, M);
				}
				else
					break;
			}
			y--;
		}
		break;

	case 80:
		if (M[x][y + 1] == 'f' || M[x][y + 1] == 'A' || M[x][y + 1] == 'o' || M[x][y + 1] == 'O' || M[x][y + 1] == 'V'){
			if (M[x][y + 1] == 'O'){
				if (sign == 'P'){
					change(flag, M);
				}
				else
					break;
			}
			y++;
		}
		break;

	case 75: 
		if (M[x-1][y] == 'f' || M[x - 1][y] == 'A' || M[x-1][y] == 'o' || M[x - 1][y] == 'O' || M[x - 1][y] == 'V'){
			if (M[x-1][y] == 'O'){
				if (sign == 'P'){
					change(flag, M);
				}
				else
					break;
			}
			x--;
		}
		break;
	case 77:
		if (M[x+1][y] == 'f' || M[x + 1][y] == 'A' || M[x+1][y] == 'o' || M[x + 1][y] == 'O' || M[x + 1][y] == 'V'){
			if (M[x + 1][y] == 'O'){
				if (sign == 'P'){
					change(flag, M);
				}
				else
					break;
			}
			x++;
		}
		break;
	}
}

bool Pacman::die(char *M[], int x, int y, bool ghost_death)
{
	return false;
}
#pragma once
#include "Creation.h"
#include "Coockies.h"

class Pacman :public Creation
{
public: 

	void view();
	void erase(bool *C[]);
	void change(bool &flag, char*M[]);
	void set_possition(char *M[], char &button, int &ghost_number, bool &ghost_death, int &x, int &y, bool flag);
	void set_start_possition(char *M[]);
	void move(char &button, char *M[], bool &flag, int p_x, int p_y, int &c_numb, bool *C[]);
	bool die(char *M[], int x, int y, bool ghost_death);

	Pacman(char sign)
	{
		this->sign = sign;
	}

private:
	char sign;
	int x;
	int y;
};
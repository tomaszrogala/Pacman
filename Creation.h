#pragma once
#include "Header.h"

class Creation
{
public:

	virtual void set_start_possition(char *M[]) = 0;
	virtual void set_possition(char *M[], char &button, int &ghost_number, bool &ghost_death, int &x, int &y, bool flag) = 0;
	virtual void change(bool &flag, char*M[]) = 0;
	virtual void view() = 0; 
	virtual void erase(bool *C[]) = 0;
	virtual void move(char &button, char *M[], bool &change, int p_x, int p_y, int &c_numb, bool *C[], bool &next) = 0;
	virtual bool die(char *M[], int x, int y, bool ghost_death) = 0;

protected:
	char sign;
	int x;
	int y;

};

#pragma once
#include "Creation.h"
#include "Coockies.h"

class Ghost :virtual public Creation, public Coockies
{
public:

	virtual void set_start_possition(char *M[]) = 0;
	virtual void set_possition(char *M[], char &button, int &ghost_number, bool &ghost_death, int &x, int &y, bool flag) = 0;
	virtual void view() = 0;
	virtual void erase(bool *C[]) = 0;
	virtual void change(bool &flag, char*M[]) = 0;
	virtual void move(char &button, char *M[], bool &change, int p_x, int p_y, int &c_numb, bool *C[], bool &next) = 0;
	virtual void search_path(char *M[], bool &change, int x, int y) = 0;
	virtual void creat_path(char *M[]) = 0; 
	virtual bool die(char *M[], int x, int y, bool ghost_death) = 0;

protected:
	int **Graph;
	Vertex *Dijkstra;
	int width;
	int high;
	char sign;
	int x;
	int y;
	bool ghost_death;
	int end_index;
	int begin_index;
};

#pragma once
#include "Ghost.h"
#include "Coockies.h"

class Ghost1 : public Ghost, public Coockies
{

public:

	void set_start_possition(char *M[]);
	void set_possition(char *M[], char &button, int &ghost_number, bool &ghost_death, int &x, int &y, bool flag);
	void view();
	void erase(bool *C[]);
	void change(bool &flag, char*M[]);
	void move(char &button, char *M[], bool &change, int p_x, int p_y, int &c_numb, bool *C[], bool &next);

	void search_path(char *M[], bool &change, int p_x, int p_y);
	void creat_path(char *M[]); 
	bool die(char *M[], int x, int y, bool ghost_death);

	Ghost1(char sign = 'A', int width = 34, int high = 16, int x = 18, int y = 7)  
	{
		spawn_frame = true;
		this->sign = sign;
		this->width = width;
		this->high = high;
		this->x = x;
		this->y = y;
		start_point = x*high + y;

		Dijkstra = new Vertex[width*high];
		Graph = new int*[width*high + 1];

		for (int i = 0; i < width*high; i++)
		{
			Graph[i] = new int[width*high + 1];
		}

		for (int i = 0; i < width*high; i++)
		{
			for (int j = 0; j < width*high; j++)
			{
				if (i == j)
				{
					Graph[i][j] = 0;
				}
				else
				{
					Graph[i][j] = INT_MAX;
				}
			}
		}
	}

	~Ghost1()
	{
		delete[] Dijkstra;
		for (int i = 0; i < width*high; i++)
		{
			delete[] Graph[i];
		}
		delete[] Graph;
	}
	
private:
	int start_point;
	int buffor;
	bool spawn_frame;

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

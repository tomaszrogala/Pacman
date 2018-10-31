#include "Ghost1.h"

void Ghost1::creat_path(char *M[])
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < high; j++) {
			if (M[i][j] == 'f' || M[i][j] == 'o' || M[i][j] == '-' || M[i][j] == '.') {
				if (j < high) {
					if (M[i][j + 1] == 'f' || M[i][j + 1] == 'o' || M[i][j+1] == '-' || M[i][j + 1] == '.')
						Graph[i*high + j][i*high + (j + 1)] = 1;
					else
						Graph[i*high + j][i*high + (j + 1)] = INT_MAX;
				}
				if (i < width){
					if (M[i + 1][j] == 'f' || M[i + 1][j] == 'o' || M[i+1][j] == '-' || M[i + 1][j] == '.')
						Graph[i*high + j][(i + 1)*high + j] = 1;
					else
						Graph[i*high + j][(i + 1)*high + j] = INT_MAX;
				}

				if (j > 0){
					if (M[i][j - 1] == 'f' || M[i][j - 1] == 'o' || M[i][j-1] == '-' || M[i][j - 1] == '.')
						Graph[i*high + j][i*high + (j - 1)] = 1;
					else
						Graph[i*high + j][i*high + (j - 1)] = INT_MAX;
				}
				if (i > 0){
					if (M[i - 1][j] == 'f' || M[i - 1][j] == 'o' || M[i-1][j] == '-' || M[i - 1][j] == '.')
						Graph[i*high + j][(i - 1)*high + j] = 1;
					else
						Graph[i*high + j][(i - 1)*high + j] = INT_MAX;
				}
			}
		}
	}
}

void Ghost1::search_path(char *M[], bool &change, int p_x, int p_y)
{
	if (!change) {
		begin_index = start_point;
	}
	else {
		begin_index = p_x*high + p_y;
	}
	
	end_index = this->x*high + this->y;
	
	int min = INT_MAX;
	buffor = begin_index;

	for (int i = 0; i < width*high; i++) {
		Dijkstra[i].edge = INT_MAX;
		Dijkstra[i].open = true;
	}

	while (end_index != begin_index){
		for (int i = 0; i < width*high; i++){
			if (Dijkstra[i].open == true){
				if (Graph[begin_index][i] != INT_MAX){
					if (Dijkstra[begin_index].edge == INT_MAX){
						Dijkstra[i].prev_index = begin_index;
						Dijkstra[i].edge = Graph[begin_index][i];
					}
					else{
						if (Dijkstra[i].edge > Graph[begin_index][i] + Dijkstra[begin_index].edge){
							Dijkstra[i].prev_index = begin_index;
							Dijkstra[i].edge = Graph[begin_index][i] + Dijkstra[begin_index].edge;
						}
					}
				}
			}
		}

		Dijkstra[begin_index].open = false;

		//search for the smallest value:

		for (int i = 0; i < width*high; i++){
			if (Dijkstra[i].edge < min && Dijkstra[i].open == true && Dijkstra[i].edge != 0)
			{
				min = Dijkstra[i].edge; 
				begin_index = i;
			}
		}
		if (min == INT_MAX){
			this->x = 16;
			this->y = 7;
			end_index = start_point;
			buffor = end_index;
			begin_index = start_point;
			break;
		}
		min = INT_MAX;
	}

	begin_index = buffor;
	buffor = end_index;
	Dijkstra[end_index].x = this->x;
	Dijkstra[end_index].y = this->y;

	
	while (end_index != begin_index) {
		Dijkstra[Dijkstra[end_index].prev_index].next_index = end_index;

		if (Dijkstra[end_index].prev_index - end_index > 1 || Dijkstra[end_index].prev_index - end_index < -1) {
			Dijkstra[Dijkstra[end_index].prev_index].y = Dijkstra[end_index].y;
			Dijkstra[Dijkstra[end_index].prev_index].x = (Dijkstra[end_index].prev_index - Dijkstra[end_index].y) / high;
		}
		else{
			Dijkstra[Dijkstra[end_index].prev_index].x = Dijkstra[end_index].x;
			Dijkstra[Dijkstra[end_index].prev_index].y = Dijkstra[end_index].prev_index - (Dijkstra[end_index].x * high);
		}

		end_index = Dijkstra[end_index].prev_index;
	}
	end_index = buffor;

}

bool Ghost1::die(char *M[], int x, int y, bool ghost_death)
{
	if (this->x == x && this->y == y && ghost_death == true){
		M[x][y] = 'f';
		gotoxy(this->x, this->y);
		std::cout << ' ';
		return true;
	}
	else{
		return false;
	}
}

void Ghost1::change(bool &flag, char*M[])
{
	if (flag) {
		sign = 'A';
	}
	else {
		sign = 'V';
		}

}

void Ghost1::set_start_possition(char *M[])
{
	do{
		x--;
		start_point = start_point - high;
	} while (M[x][y] != 'f' && M[x][y] != 'o'&& M[x][y] != 'O' && M[x][y] != '-');

	gotoxy(x, y);
	if (M[this->x][this->y] == '.')
		spawn_frame = true;
	else if (M[this->x][this->y] != sign)
		spawn_frame = false;

	if (M[this->x][this->y] != '-') {
		M[this->x][this->y] = sign;
	}
}

void Ghost1::set_possition(char *M[], char &button, int &ghost_number, bool &ghost_death, int &x, int &y, bool flag)
{
	gotoxy(this->x, this->y);
	
	if (M[this->x][this->y] == 'P')
	{
		game_over(button);
		return;
	}
	if (M[this->x][this->y] == '.')
		spawn_frame = true;
	else if (M[this->x][this->y] != sign)
		spawn_frame = false;

	if (M[this->x][this->y] != '-'&& M[this->x][this->y] != '.') {
		if (flag)
		{
			M[this->x][this->y] = sign;
		}
	}
}

void Ghost1::view()
{
	text_color_blue();
	std::cout << sign;
	color_standard();
}

void Ghost1::erase(bool *C[])
{
	if (spawn_frame) {
		color_standard();
		std::cout << '-';
		color_standard();
		return;
	}
	if (C[this->x][this->y]){
		text_color_gold();
		std::cout << '*';
		color_standard();
	}
	else if (!spawn_frame)
		std::cout << ' ';
}

void Ghost1::move(char &button, char *M[], bool &change, int p_x, int p_y, int &c_numb, bool *C[])
{	
	if (C[x][y] == true && M[x][y] != '-'&& M[x][y] != '.'){
		M[x][y] = 'o';
	}
	else if(M[x][y] != '-'&& M[x][y] != '.'&& M[x][y] != 'o'){
		if (!C[x][y])
			M[x][y] = 'f';
	}

	search_path(M, change, p_x, p_y);

	if (M[Dijkstra[Dijkstra[buffor].prev_index].x][Dijkstra[Dijkstra[buffor].prev_index].y] != 'A' && M[Dijkstra[Dijkstra[buffor].prev_index].x][Dijkstra[Dijkstra[buffor].prev_index].y] != 'V'){
		this->x = Dijkstra[Dijkstra[buffor].prev_index].x;
		this->y = Dijkstra[Dijkstra[buffor].prev_index].y;
		buffor = Dijkstra[buffor].prev_index;
		return;
	}
	else {
		this->x = 18;
		this->y = 7;
		return;
	}
}

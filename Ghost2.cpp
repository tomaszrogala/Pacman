#include "Ghost2.h"

void Ghost2::creat_path(char *M[])
{
	for (int i = 0; i < width; i++){
		for (int j = 0; j < high; j++){
			if (M[i][j] == 'f' || M[i][j] == 'o' || M[i][j] == '-' || M[i][j] == '.'){
				if (j < high){
					if (M[i][j + 1] == 'f' || M[i][j + 1] == 'o' || M[i][j + 1] == '-' || M[i][j + 1] == '.')
						Graph[i*high + j][i*high + (j + 1)] = 1;
					else
						Graph[i*high + j][i*high + (j + 1)] = INT_MAX;
				}

				if (i < width){
					if (M[i + 1][j] == 'f' || M[i + 1][j] == 'o' || M[i + 1][j] == '-' || M[i + 1][j] == '.')
						Graph[i*high + j][(i + 1)*high + j] = 1;
					else
						Graph[i*high + j][(i + 1)*high + j] = INT_MAX;
				}

				if (j > 0){
					if (M[i][j - 1] == 'f' || M[i][j - 1] == 'o' || M[i][j - 1] == '-' || M[i][j - 1] == '.')
						Graph[i*high + j][i*high + (j - 1)] = 1;
					else
						Graph[i*high + j][i*high + (j - 1)] = INT_MAX;
				}

				if (i > 0){
					if (M[i - 1][j] == 'f' || M[i - 1][j] == 'o' || M[i - 1][j] == '-' || M[i - 1][j] == '.')
						Graph[i*high + j][(i - 1)*high + j] = 1;
					else
						Graph[i*high + j][(i - 1)*high + j] = INT_MAX;
				}
			}
		}
	}
}

void Ghost2::search_path(char *M[], bool &change, int p_x, int p_y)
{
	if (!change) {
		begin_index = start_point;
	}

	end_index = this->x*high + this->y;

	int min = INT_MAX;
	buffor = begin_index;

	for (int i = 0; i < width*high; i++){
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

		for (int i = 0; i < width*high; i++){													
			if (Dijkstra[i].edge < min && Dijkstra[i].open == true && Dijkstra[i].edge != 0){
				min = Dijkstra[i].edge;
				begin_index = i;
			}
		}
		if (min == INT_MAX){
			this->x = 17;
			this->y = 8;
			end_index = start_point;
			buffor = end_index;
			begin_index = start_point;
			gotoxy(0, 16);
			break;
		}
		min = INT_MAX;
	}

	begin_index = buffor;
	buffor = end_index;
	Dijkstra[end_index].x = this->x;
	Dijkstra[end_index].y = this->y;

	while (end_index != begin_index){
		Dijkstra[Dijkstra[end_index].prev_index].next_index = end_index;

		if (Dijkstra[end_index].prev_index - end_index > 1 || Dijkstra[end_index].prev_index - end_index < -1) {
			Dijkstra[Dijkstra[end_index].prev_index].y = Dijkstra[end_index].y;
			Dijkstra[Dijkstra[end_index].prev_index].x = (Dijkstra[end_index].prev_index - Dijkstra[end_index].y) / high;
		}
		else{
			Dijkstra[Dijkstra[end_index].prev_index].x = Dijkstra[end_index].x;
			if (Dijkstra[end_index].prev_index > (Dijkstra[end_index].x * high)) {
				Dijkstra[Dijkstra[end_index].prev_index].y = Dijkstra[end_index].prev_index - (Dijkstra[end_index].x * high);
			}
			else {
				//Dijkstra[Dijkstra[end_index].prev_index].y = 8;
				//Dijkstra[Dijkstra[end_index].prev_index].x = 15;
				Dijkstra[Dijkstra[end_index].prev_index].y = Dijkstra[end_index].prev_index - (Dijkstra[end_index].x * high); 
				Dijkstra[Dijkstra[end_index].prev_index].y = Dijkstra[Dijkstra[end_index].prev_index].y * -1;
			}
		}

		end_index = Dijkstra[end_index].prev_index;
	}

	end_index = buffor;
}

bool Ghost2::die(char *M[], int x, int y, bool ghost_death)
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

void Ghost2::change(bool &flag, char*M[])
{
	if (flag){
		sign = 'A';			
	}
	else{
		sign = 'V';			
	}
}

void Ghost2::set_start_possition(char *M[])
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
	
	if (M[this->x][this->y] != '-'&& M[this->x][this->y] != '.') {
		M[this->x][this->y] = sign;
	}
}

void Ghost2::set_possition(char *M[], char &button, int &ghost_number, bool &ghost_death, int &x, int &y, bool flag)
{
	gotoxy(this->x, this->y);
	if (M[this->x][this->y] == 'P'){
		game_over(button);
		return;
	}
	if (M[this->x][this->y] == 'Q') {
		ghost_death = true;
	}
	if (M[this->x][this->y] == '.')
		spawn_frame = true;
	else if (M[this->x][this->y] != sign)
		spawn_frame = false;

	if (M[this->x][this->y] != '-' && M[this->x][this->y] != '.'){
		if (flag)
		{
			M[this->x][this->y] = sign;
		}
	}
}

void Ghost2::view()
{
	text_color_green();
	std::cout << sign;
	color_standard();
}

void Ghost2::erase(bool *C[])
{
	if (spawn_frame) {
		color_standard();
		std::cout << '-';
		color_standard();
		return;
	}
	if (C[this->x][this->y]) {
		text_color_gold();
		std::cout << '*';
		color_standard();
	}
	else if(!spawn_frame&& !C[this->x][this->y])
		std::cout << ' ';
}

void Ghost2::move(char &button, char *M[], bool &change, int p_x, int p_y, int &c_numb, bool *C[], bool &next)
{
	if (C[x][y] == true && M[x][y] != '-' && M[x][y] != '.') {
		M[x][y] = 'o';
	}
	else if (M[x][y] != '-'&& M[x][y] != '.'&& M[x][y] != 'o') {
		if (!C[x][y])
			M[x][y] = 'f';
	}

	search_path(M, change, p_x, p_y);

	if (!change) {
		if (M[Dijkstra[Dijkstra[buffor].prev_index].x][Dijkstra[Dijkstra[buffor].prev_index].y] != 'V') {
			this->x = Dijkstra[Dijkstra[buffor].prev_index].x;
			this->y = Dijkstra[Dijkstra[buffor].prev_index].y;
			buffor = Dijkstra[buffor].prev_index;
			return;
		}
		else {

			if (M[x - 1][y] == 'f' || M[x - 1][y] == 'P' || M[x - 1][y] == 'o' || M[x - 1][y] == 'Q' || M[x - 1][y] == '-' || M[x - 1][y] == '.') {
				x--;
				return;
			}
			else if (M[x + 1][y] == 'f' || M[x + 1][y] == 'P' || M[x + 1][y] == 'o' || M[x + 1][y] == 'Q' || M[x + 1][y] == '-' || M[x + 1][y] == '.') {
				x++;
				return;
			}
			else if (M[x][y - 1] == 'f' || M[x][y - 1] == 'P' || M[x][y - 1] == 'o' || M[x][y - 1] == 'Q' || M[x][y - 1] == '-' || M[x][y - 1] == '.') {
				y--;
				return;
			}
			else if (M[x][y + 1] == 'f' || M[x][y + 1] == 'P' || M[x][y + 1] == 'o' || M[x][y + 1] == 'Q'  || M[x][y + 1] == '-' || M[x][y - 1] == '.') {
				y++;
				return;
			}
			else {
				this->x = 17;
				this->y = 8;
				return;
				
			}
		}
	}
	else {
		if (buffor == begin_index){
			int r;
			int a;
			int b;
			r = rand() % 30;

			if (r >= 5 && r<10){
				a = x;
				while (M[a - 1][y] == 'f' || M[a - 1][y] == 'P' || M[a - 1][y] == 'o' || M[a - 1][y] == 'Q'  || M[a - 1][y] == '-' || M[a - 1][y] == '.')
					a--;
				begin_index = a*high + y;
			}

			if (r<5){
				a = x;
				while (M[a + 1][y] == 'f' || M[a + 1][y] == 'P' || M[a + 1][y] == 'o' || M[a + 1][y] == 'Q'  || M[a + 1][y] == '-' || M[a + 1][y] == '.')
					a++;
				begin_index = a*high + y;
			}

			if (r >= 10){
				a = y;
				while (M[x][a - 1] == 'f' || M[x][a - 1] == 'P' || M[x][a - 1] == 'o' || M[x][a - 1] == 'Q' || M[x][a-1] == '-' || M[x][a - 1] == '.')
					a--;
				begin_index = x*high + a;
			}

			if (r >= 15 && r < 20){
				a = y;
				while (M[x][a+1] == 'f' || M[x][a + 1] == 'P' || M[x][a + 1] == 'o' || M[x][a + 1] == 'Q'  || M[x][a+1] == '-' || M[x][a + 1] == '.')
					a++;
				begin_index = x*high + a;
			}

			if (r >= 20) {
				do{
					a = rand() % 34;
					b = rand() % 16;
				} while (M[a][b] != 'f' && M[a][b] != 'o');

				begin_index = a*high + b;
			}

			if (M[Dijkstra[Dijkstra[buffor].prev_index].x][Dijkstra[Dijkstra[buffor].prev_index].y] != 'A') {
				this->x = Dijkstra[Dijkstra[buffor].prev_index].x;
				this->y = Dijkstra[Dijkstra[buffor].prev_index].y;
				buffor = Dijkstra[buffor].prev_index;
				return;
			}
			else {

				if (M[x - 1][y] == 'f' || M[x - 1][y] == 'P' || M[x - 1][y] == 'o' || M[x - 1][y] == 'Q' || M[x - 1][y] == '-' || M[x - 1][y] == '.') {
					x--;
					return;
				}
				else if (M[x + 1][y] == 'f' || M[x + 1][y] == 'P' || M[x + 1][y] == 'o' || M[x + 1][y] == 'Q'  || M[x + 1][y] == '-' || M[x + 1][y] == '.') {
					x++;
					return;
				}
				else if (M[x][y - 1] == 'f' || M[x][y - 1] == 'P' || M[x][y - 1] == 'o' || M[x][y - 1] == 'Q'  || M[x][y - 1] == '-' || M[x][y - 1] == '.') {
					y--;
					return;
				}
				else if (M[x][y + 1] == 'f' || M[x][y + 1] == 'P' || M[x][y + 1] == 'o' || M[x][y + 1] == 'Q'  || M[x][y + 1] == '-' || M[x][y - 1] == '.') {
					y++;
					return;
				}
				else {
					this->x = 17;
					this->y = 8;
					return;
				}
			}
		}
		else {

			if (M[Dijkstra[Dijkstra[buffor].prev_index].x][Dijkstra[Dijkstra[buffor].prev_index].y] != 'A') {
				this->x = Dijkstra[Dijkstra[buffor].prev_index].x;
				this->y = Dijkstra[Dijkstra[buffor].prev_index].y;
				buffor = Dijkstra[buffor].prev_index;
			}
			else {

				if (M[x - 1][y] == 'f' || M[x - 1][y] == 'P' || M[x - 1][y] == 'o' || M[x - 1][y] == 'Q' || M[x - 1][y] == '-' || M[x - 1][y] == '.') {
					x--;
					return;
				}
				else if (M[x + 1][y] == 'f' || M[x + 1][y] == 'P' || M[x + 1][y] == 'o' || M[x + 1][y] == 'Q' || M[x + 1][y] == '-' || M[x + 1][y] == '.') {
					x++;
					return;
				}
				else if (M[x][y - 1] == 'f' || M[x][y - 1] == 'P' || M[x][y - 1] == 'o' || M[x][y - 1] == 'Q' || M[x][y - 1] == '-' || M[x][y - 1] == '.') {
					y--;
					return;
				}
				else if (M[x][y + 1] == 'f' || M[x][y + 1] == 'P' || M[x][y + 1] == 'o' || M[x][y + 1] == 'Q' || M[x][y + 1] == '-' || M[x][y - 1] == '.') {
					y++;
					return;
				}
				else {
					this->x = 17;
					this->y = 8;
					return;

				}
			}
		}
	}
}		


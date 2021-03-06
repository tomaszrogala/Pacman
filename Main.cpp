#include "Header.h"
#include "Creation.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Ghost1.h"
#include "Ghost2.h"
#include "Map.h"
#include "Element.h"
#include "Frame.h"
#include "Wall.h"
#include "Coockies.h"
#include <conio.h>
#include "Spawn.h"

void creation_move(Map &m, char &button, int &ghost_number, bool &ghost_death, int &pacman_x, int &pacman_y, bool &flag, bool &change, Coockies &coockies, int i, bool &next) //int number, *C[]
{
	m.creat[i]->set_possition(m.M, button, ghost_number, ghost_death, pacman_x, pacman_y, flag);
	m.creat[i]->erase(coockies.C);
	m.creat[i]->move(button, m.M, change, pacman_x, pacman_y, coockies.number, coockies.C, next);
	m.creat[i]->set_possition(m.M, button, ghost_number, ghost_death, pacman_x, pacman_y, flag);
	m.creat[i]->view();
}

void check_ghost_death(int &pacman_x, int &pacman_y, bool &ghost_death, int &ghost_number, Map &m, Ghost *ghost[], Ghost *buffor_g[], int i)
{
	if (m.creat[i]->die(m.M, pacman_x, pacman_y, ghost_death) == true) {
		for (int j = 1; j <= ghost_number; j++) {
			buffor_g[j] = ghost[j];
		}

		ghost_number--;

		for (int j = ghost_number; j >= i; j--) {
			if (j == 0) {
				break;
			}

			ghost[j] = buffor_g[j + 1];
		}

		for (int j = 1; j <= ghost_number; j++) {
			m.creat[j] = ghost[j];
		}
	}
}

int main()
{
	srand(time(NULL));

	int width = 34; int high = 16; char button = 1; int ghost_number = 6; 
	bool change = true; int change_time = 100; bool ghost_death = false; bool flag = true;
	int pacman_x; int pacman_y; bool next = true;

	Pacman p('P'); Ghost1 g_1a; Ghost2 g_1b; Ghost2 g_2a; Ghost2 g_2b; Ghost2 g_2c; Ghost2 g_3a; Ghost1 g;
	Ghost *ghost[7] = { &g,&g_1a,&g_1b,&g_2a,&g_2b,&g_2c,&g_3a };
	Ghost *buffor_g[7];  Creation *buffor_c; int buffor;
	Frame frame(width, high); Coockies coockies(width, high);

	//width:
	Wall w1(4, 2, 16, 1); Wall w2(24, 2, 6, 1); Wall w3(8, 4, 18, 1); Wall w4(10, 6, 6, 1); Wall w5(20, 6, 2, 1);
	Wall w6(8, 11, 10, 1); Wall w7(20, 11, 4, 1); Wall w8(4, 13, 24, 1); Wall w9(18, 9, 2, 1);
	//high:
	Wall w10(20, 1, 2, 2); Wall w11(3, 2, 2, 10); Wall w12(28, 3, 2, 11); Wall w13(24, 5, 2, 7);
	Wall w14(7, 4, 2, 3); Wall w15(7, 9, 2, 3); Wall w16(12, 7, 2, 3); Wall w17(20, 7, 2, 3);
	Wall ww(0, 0, 0, 0);

	Wall walls[18] = { ww, w1,w2,w3 ,w4 ,w5 ,w6 ,w7,w8 ,w9 ,w10 ,w11 ,w12 ,w13 ,w14 ,w15 ,w16, w17 };

	Spawn sp;
	Map m(width, high);

	//Elements of Map:
	m.element[0] = &frame;
	for (int i = 1; i < 18; i++)
		m.element[i] = &walls[i];
	m.element[18] = &coockies;
	m.element[19] = &sp;

	for (int i = 0; i <= 19; i++) {
		m.element[i]->mark(m.M, coockies);
		m.element[i]->draw(m.M);
	}

	for (int i = 1; i <= ghost_number; i++) {
		ghost[i]->creat_path(m.M);
	}

	//Creatures:
	m.creat[0] = &p;
	for (int i = 1; i <= ghost_number; i++)
		m.creat[i] = ghost[i];

	for (int i = 0; i <= ghost_number; i++) {
		m.creat[i]->set_start_possition(m.M);
		m.creat[i]->view();
	}

	//Game loop:
	HideCursor();
	buffor = change_time;

	do {
		//PACMAN MOVE:
		button = _getch();

		while (_kbhit()) {
			button = _getch();
		}
		
		do {

			if (change == false) {
				creation_move(m, button, ghost_number, ghost_death, pacman_x, pacman_y, flag, change, coockies, 0, next);
				creation_move(m, button, ghost_number, ghost_death, pacman_x, pacman_y, flag, change, coockies, 0, next);
			}
			else {
				creation_move(m, button, ghost_number, ghost_death, pacman_x, pacman_y, flag, change, coockies, 0, next);
			}
		
		for (int i = 1; i <= ghost_number; i++){
			check_ghost_death(pacman_x, pacman_y, ghost_death, ghost_number, m, ghost, buffor_g, i);
		}
		
	//	while (_kbhit() == false) {
			if (change == false) {
				if (buffor == change_time) {
					flag = false;
					for (int i = 1; i <= ghost_number; i++) {
						m.creat[i]->change(change, m.M);
						creation_move(m, button, ghost_number, ghost_death, pacman_x, pacman_y, flag, change, coockies, i, next);
					}
					flag = true;
				}
				change_time--;
				if (change_time == 0) {
					change_time = buffor;
					p.change(change, m.M);
					for (int i = 1; i <= ghost_number; i++) {
						m.creat[i]->change(change, m.M);
					}
				}
			}

			Sleep(150);

			//GHOST MOVE:
			for (int i = 1; i <= ghost_number; i++) {
				creation_move(m, button, ghost_number, ghost_death, pacman_x, pacman_y, flag, change, coockies, i, next);
				if (button == 0)
					break;
				check_ghost_death(pacman_x, pacman_y, ghost_death, ghost_number, m, ghost, buffor_g, i);

			}
				//SHOW THE MAP MARK:
				/*
				gotoxy(0, 16);

				for (int i = 0; i < high; i++) {
					for (int j = 0; j < width; j++) 
						std::cout << m.M[j][i];
						std::cout << ' ';
					}
							std::cout << '\n';
				}*/
	//		}
		} while (next == true && _kbhit() == false);
		while (next == false && _kbhit() == false)
		{
			Sleep(150);
			for (int i = 1; i <= ghost_number; i++) {
				creation_move(m, button, ghost_number, ghost_death, pacman_x, pacman_y, flag, change, coockies, i, next);
				if (button == 0)
					break;
				check_ghost_death(pacman_x, pacman_y, ghost_death, ghost_number, m, ghost, buffor_g, i);

			}
		}
			if ((coockies.number) == 0) {
				win(button);
			}

		} while (button != 0);

		std::cout << '\n';
		system("pause");

		return 0;
}

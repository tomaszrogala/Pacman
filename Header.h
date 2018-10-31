#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stack>

class Creation;
class Ghost;
class Pacman;
class Map;
class Element;
class Coockies;
class Wall;
class Frame;

struct Vertex
{
	int edge;
	bool open;
	int prev_index;
	int next_index;
	int x;
	int y;

	Vertex()
	{
		open = true;
	}
};

void color_standard();
void background_color_red();
void background_color_blue();
void background_color_green();
void text_color_red();
void text_color_blue();
void text_color_green();
void text_color_gold();
void text_color_silver();
void text_color_violet();
void text_color_aquamarine();

void HideCursor();
void gotoxy(int x, int y);
void ShowCursor();
void game_over(char &button);
void win(char &button);



#include "Header.h"

void game_over(char &button)
{
	system("cls");
	gotoxy(54, 13);
	std::cout << "GAME OVER";
	button = 0;
}

void win(char &button)
{
	system("cls");
	gotoxy(54, 13);
	std::cout << "Good Job!!!" ;
	button = 0;
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

void ShowCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = TRUE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

void color_standard()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

void background_color_red()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, BACKGROUND_RED);
}
void background_color_blue()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
}
void background_color_green()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
}

void text_color_red()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, FOREGROUND_RED);
}

void text_color_blue()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
}

void text_color_green()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
}

void text_color_gold()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void text_color_silver()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void text_color_violet()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
}
void text_color_aquamarine()
{
	::HANDLE hOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
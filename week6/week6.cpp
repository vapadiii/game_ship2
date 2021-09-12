#define _CRT_SECURE_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<conio.h>

int main() {
	setcursor(0);
	char ch = ' ';
	char chc = ' ';
	int x = 38, y = 20;
	int cannonballst1 = 0;
	int cannonballst2 = 0;
	int cannonballst3 = 0;
	int cannonballst4 = 0;
	int cannonballst5 = 0;
	int cbx1, cbx2, cbx3, cbx4, cbx5; //cbx=cannonballx
	int cby1, cby2, cby3, cby4, cby5; //cby=cannonbally
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();

			if (ch == ' ' && cannonballst1 == 0) {  //st=status
				cannonballst1 = 1;
				cbx1 = x + 2;
				cby1 = y;
				cannonball(cbx1, --cby1);
			}
			else if (ch == ' ' && cannonballst2 == 0) {
				cannonballst2 = 1;
				cbx2 = x + 2;
				cby2 = y;
				cannonball(cbx2, --cby2);
			}
			else if (ch == ' ' && cannonballst3 == 0) {
				cannonballst3 = 1;
				cbx3 = x + 2;
				cby3 = y;
				cannonball(cbx3, --cby3);
			}
			else if (ch == ' ' && cannonballst4 == 0) {
				cannonballst4 = 1;
				cbx4 = x + 2;
				cby4 = y;
				cannonball(cbx4, --cby4);
			}
			else if (ch == ' ' && cannonballst5 == 0) {
				cannonballst5 = 1;
				cbx5 = x + 2;
				cby5 = y;
				cannonball(cbx5, --cby5);
			}
			if (ch == ' ') {
				ch = chc;
			}
		}

		if (ch == 'a' && x > 0) {
			chc = 'a';
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (ch == 'd' && x < 75)
		{
			chc = 'd';
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (ch == 'w') {
			erase_ship(x, y);
			draw_ship(x, --y);
		}
		if (ch == 's') {
			erase_ship(x, y);
			draw_ship(x, y);
		}
		if (cannonballst1 == 1) {
			erase_bullet(cbx1, cby1);
			if (cby1 == 0) cannonballst1 = 0;
			if (cby1 >= 1) {
				cannonball(cbx1, --cby1);
			}
		}
		if (cannonballst2 == 1) {
			erase_bullet(cbx2, cby2);
			if (cby2 == 0) cannonballst2 = 0;
			if (cby2 >= 1) {
				cannonball(cbx2, --cby2);
			}
		}
		if (cannonballst3 == 1) {
			erase_bullet(cbx3, cby3);
			if (cby3 == 0) cannonballst3 = 0;
			if (cby3 >= 1) {
				cannonball(cbx3, --cby3);
			}
		}
		if (cannonballst4 == 1) {
			erase_bullet(cbx4, cby4);
			if (cby4 == 0) cannonballst4 = 0;
			if (cby4 >= 1) {
				cannonball(cbx4, --cby4);
			}
		}
		if (cannonballst5 == 1) {
			erase_bullet(cbx5, cby5);
			if (cby5 == 0) cannonballst5 = 0;
			if (cby5 >= 1) {
				cannonball(cbx5, --cby5);
			}
		}
		fflush(stdin);
		Sleep(100);
	} while (ch != 'x');

	return 0;
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf("<-0->");
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf("     ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void cannonball(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf("|");
}
void erase_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(7, 0);
	printf(" ");
}

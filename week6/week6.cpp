#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define getch() _getch()

void setcursor(bool visible) {
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

void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(2, 4);
	printf("<-0->");
}

void erase_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(2, 0);
	printf("     ");
}

void draw_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(2, 0);
	printf("|");
}

void erase_bullet(int x, int y) {
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");
}


int main() {
	char ch = ' ';
	int x = 38, y = 20;

	int n=0;
	int n_bullet[5];
	int x_bullet[5];
	int y_bullet[5];
	bool bullet_status[5] = { false,false,false,false,false};

	char move = ' ';

	setcursor(0);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {
				move = 'L';
			}
			if (ch == 'd') {
				move = 'R';
			}
			if (ch == 's') {
				move = ' ';
			}
			if (ch == ' ') {
				
				if (bullet_status[n] == false) {
					bullet_status[n] = true;
					x_bullet[n] = x + 2;
					y_bullet[n] = y - 1;
				}
				n++;
			}

			fflush(stdin);
		}
		if (move == 'L') {
			if (x > 0) {
				erase_ship(x, y);
				x--;
				draw_ship(x, y);
			}
		}
		if (move == 'R') {
			if (x < 75) {
				erase_ship(x, y);
				x++;
				draw_ship(x, y);
			}
		}

		for (int i = 0; i < n; i++) {
			if (bullet_status[i] == true) {
				erase_bullet(x_bullet[i], y_bullet[i]);

				if (y_bullet[i] > 0) {
					y_bullet[i]--;
					draw_bullet(x_bullet[i], y_bullet[i]);
				}
				else {
					bullet_status[i] = false;
					if (i == 4 && bullet_status[i] == false) {
						n = 0;
					}
				}
			}
		}


		Sleep(100);
	} while (ch != 'x');
	return 0;
}

#include "stdafx.h"
#pragma warning(disable:4996)
int Sleepcount; // 슬립한 시간을 체크.
int X=0,Y; // X = 초, Y = 입력한 문자
char inputchar;
void gotoxy(int x, int y) // 커서 이동 함수
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int main()
{
	while (1) {
		if (Sleepcount % 1000 == 0) {
			gotoxy((X)*2, 0);
			if (X % 2 == 0)
				printf("★");
			else
				printf("☆");
			X++;
			gotoxy(0, 1);
			printf("%d 초", X);
		}
		if (kbhit()) {
			inputchar = getch();
			gotoxy(Y++, 2);
			printf("%c", inputchar);
		}
		Sleep(1);
		Sleepcount++;
	}
}


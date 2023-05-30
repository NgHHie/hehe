#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

struct maybay {
	char s[50];
	int x, y;
};

struct dan {
	char dan = 248;
	int x, y;
};

struct vatcan {
	char vc = 254;
	int x, y;
};

//dich chuyen con tro chuot den toa do (x, y)
void gotoXY(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x,y};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//an con tro chuot
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

int main () {
	Nocursortype();
	
	maybay A;
	A.s[0] = 170;
	A.s[1] = 254;
	A.s[2] = 186;
	A.s[3] = 254;
	A.s[4] = 169;
	A.x = 58;
	A.y = 25;
	
	dan a;
	a.y = A.y - 1;
	a.x = A.x + 2;
	
	srand((int)time(0));
	vatcan b[10];
	for (int i=1; i<=10; i++) {
		b[i].x = random (3, 117);
	}
	for (int j=1; j<=10; j++) {
		b[j].y = random (0, 19);
	}
	
	while (1) {
		system("cls");
		//chuong ngai vat
		for (int n=1; n<=10; n++) {
			gotoXY(b[n].x, b[n].y);
			printf ("%c", b[n].vc);
		}
		
		//Tau vu tru
		gotoXY (A.x, A.y);
		printf ("%s", A.s);		
		if (kbhit()) {
			char key = getch();
			if (key == 'a') {
				if (A.x == 0) A.x *= 1;
				if (A.x == 1) A.x--;
				if (A.x > 1) A.x -= 2;
			}
			if (key == 'd') {
				if (A.x == 115) A.x *= 1;
				if (A.x == 114) A.x++;
				if (A.x < 114) A.x += 2;
			}	
			if (key == 'w') {
				if (A.y == 20) A.y *= 1;
				if (A.y > 20) A.y--;
			}
			if (key == 's') {
				if (A.y == 29) A.y *= 1;
				if (A.y < 29) A.y++;
			}
			if (key == '1') {
				if (A.x == 0) A.x *= 1;
				if (A.x >= 1) A.x--;				
			}
			if (key == '2') {
				if (A.x == 115) A.x *= 1;
				if (A.x <= 114) A.x++;				
			}
			
			//An enter de ket thuc tro choi
			if (key == 13) {
				system("cls");
				break;			    
			}
		}
		
		//Ban dan
		gotoXY (a.x, a.y);		
		printf ("%c", a.dan);	
		if (a.y >= 0) a.y -= 2;		
		if (a.y == -1 || a.y == -2) {
			a.dan = 248;
			a.y = A.y - 1;
			a.x = A.x + 2;
		}
		
		//Xu li va cham giua dan va chuong ngai vat
		for (int m = 1; m <= 10; m++) {
			if (a.x == b[m].x) {
				if (a.y - b[m].y == 1 || a.y == b[m].y) {
					b[m].vc = '\0';
					b[m].x = b[m].y = 0;
					a.dan = 248;
					a.y = A.y - 1;
					a.x = A.x + 2;
				}
			}
		}
				
		Sleep(50);
	}	
}
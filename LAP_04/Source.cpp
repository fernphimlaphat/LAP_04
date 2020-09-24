#include<stdio.h>
#include<windows.h>
#include<conio.h>

void draw(int x, int y) {

	COORD xy = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	printf(" <-0-> ");
}

void deleteXY(int x, int y) {
	COORD xy = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	printf("       ");

}

void move(int x,int y,int m)
{
	do
	{
	if((x>= 0 && x <=80) && (y>=0 && y<=80))
	{
		if ((x>0 && x<80) && (y>0 && y<80))
		{
			if (_kbhit())
			{
				m = _getch();
				if (m == 'a') { draw(--x, y); }
				if (m == 'd') { draw(++x, y); }
				if (m == 'w') { draw(x, --y); deleteXY(x, y + 1); }
				if (m == 's') { draw(x, ++y); deleteXY(x, y - 1); }

			}
		}
		else if(x==0 || y==0)
		{
			if (x == 0)
			{
				if (_kbhit())
				{
					m = _getch();
					if (m == 'd') { draw(++x, y); }
					if (m == 'w') { draw(x, --y); deleteXY(x, y + 1); }
					if (m == 's') { draw(x, ++y); deleteXY(x, y - 1); }


				}
			}
			else if (y == 0)
			{
				if (_kbhit())
				{
					deleteXY(x + 7, 1);

					m = _getch();
					if (m == 'a') { draw(--x, y); }
					if (m == 'd') { draw(++x, y); }
					if (m == 's') { draw(x, ++y); deleteXY(x, y - 1); }





				}
			}
		}
		else if ((x == 80) || (y == 80))
		{
			if (x == 80)
			{
				if (_kbhit())
				{
					m = _getch();
					if (m == 'w') { draw(x, --y); deleteXY(x, y + 1); }
					if (m == 's') { draw(x, ++y); deleteXY(x, y - 1); }
					if (m == 'a') { draw(--x, y); }
				}
			}
			else if (y == 80)
			{
				if (_kbhit())
				{
					m = _getch();
					if (m == 'a') { draw(--x, y); }
					if (m == 'd') { draw(++x, y); }
					if (m == 'w') { draw(x, --y); deleteXY(x, y + 1); }
				}
			}
		}
		
	}
	else
	{
		if (x >= 81)
		{
			draw(80,y);
			m = _getch();
			if (m == 'w') { draw(x, --y); deleteXY(x, y + 1); }
			if (m == 's') { draw(x, ++y); deleteXY(x, y - 1); }
			if (m == 'a') { draw(--x, y); }
		}
		if (y >= 81)
		{
			draw(x, 80);
			deleteXY(x, 81);
			m = _getch();
			if (m == 'a') { draw(--x, y); }
			if (m == 'd') { draw(++x, y); }
			if (m == 'w') { draw(x, --y); deleteXY(x, y + 1); }
		}
		if (y == -1)
		{
		draw(x, 0);
			deleteXY(x+7,1);
			
			m = _getch();
			if (x>=0&&x<=50)
			{
				if (m == 'd') { draw(++x, y); deleteXY(x + 14, 1); }
				if (m == 's') { draw(x, ++y); deleteXY(x, y - 1); }

			}
			if (x > 50 && x <= 70)
			{	

				if (m == 'd') {  draw(++x, y);  }
				deleteXY(x + 14, 1);
				deleteXY(x + 28, 1);
				deleteXY(x - 1, 0);
				deleteXY(x + 10, 1);

				if (m == 'w') { draw(x, --y); deleteXY(x, y + 1); }
				if (m == 'a') { draw(--x, y); }
				deleteXY(x + 17, 1);
				deleteXY(x + 19, 1);
				deleteXY(80,y);



			}
			else
			{
				if (x>70 && x<=80)
				{
					m = _getch();
					if (m == 'a') { draw(--x, y); }
					if (m == 'w') { draw(x, --y); deleteXY(x, y + 1); }
					if (m == 's') { draw(x, ++y); deleteXY(x, y - 1); }

				}
			}
		}
	
	}
	//Sleep(500);
	 
	} while (m != 'x');

}

int main()
{
	char m = ' ';
	int x = 20, y = 2;
	draw(x, y);
	move(x,y,m);

}
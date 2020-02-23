#include<conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <windows.h>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include "myconsole.h"
#include "myconsole.cpp"
#include <iostream>
using namespace std;

char shapes[19][4][4] = { { { 'O','O',' ',' ' },{ ' ','O','O',' ' },{ ' ',' ',' ',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ','O',' ' },{ ' ','O','O',' ' },{ ' ','O',' ',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ',' ',' ' },{ ' ','O','O',' ' },{ 'O','O',' ',' ' },{ ' ',' ',' ',' ' } },{ { ' ','O',' ',' ' },{ ' ','O','O',' ' },{ ' ',' ','O',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ',' ',' ' },{ ' ',' ',' ',' ' },{ 'O','O','O','O' },{ ' ',' ',' ',' ' } },{ { ' ',' ','O',' ' },{ ' ',' ','O',' ' },{ ' ',' ','O',' ' },{ ' ',' ','O',' ' } },{ { ' ',' ','O',' ' },{ 'O','O','O',' ' },{ ' ',' ',' ',' ' },{ ' ',' ',' ',' ' } },{ { ' ','O',' ',' ' },{ ' ','O',' ',' ' },{ ' ','O','O',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ',' ',' ' },{ ' ','O','O','O' },{ ' ','O',' ',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ',' ',' ' },{ ' ','O','O',' ' },{ ' ',' ','O',' ' },{ ' ',' ','O',' ' } },{ { ' ',' ',' ',' ' },{ ' ','O',' ',' ' },{ ' ','O','O','O' },{ ' ',' ',' ',' ' } },{ { ' ',' ','O',' ' },{ ' ',' ','O',' ' },{ ' ','O','O',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ',' ',' ' },{ 'O','O','O',' ' },{ ' ',' ','O',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ',' ',' ' },{ ' ','O','O',' ' },{ ' ','O',' ',' ' },{ ' ','O',' ',' ' } },{ { ' ',' ','O',' ' },{ ' ','O','O','O' },{ ' ',' ',' ',' ' },{ ' ',' ',' ',' ' } },{ { ' ','O',' ',' ' },{ ' ','O','O',' ' },{ ' ','O',' ',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ','O',' ' },{ ' ','O','O',' ' },{ ' ',' ','O',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ',' ',' ' },{ ' ','O','O','O' },{ ' ',' ','O',' ' },{ ' ',' ',' ',' ' } },{ { ' ',' ',' ',' ' },{ ' ','O','O',' ' },{ ' ','O','O',' ' },{ ' ',' ',' ',' ' } } };
char array[40][25];

class shape{
private:
	int x;
	int y;
	int r;


public:
	void ShapeOnTop(char shape[4][4], char arr[40][25]);
	void ShapeChange(char arr[40][25], char shape[4][4], int x, int y, int r);
};
class movement{
private:
	int x, y;
	shape s;

public:
	int GetCharacter();
	void DropDown(char shape[4][4], char arr[40][25], int& x, int& y);
	void Timer(char sh[19][4][4], char arr[40][25]);
	void MoveRight(char arr[40][25], char shape[4][4], int &x, int &y);
	void MoveLeft(char arr[40][25], char shape[4][4], int &x, int &y);

};
class display{
public:
	int t;
	int x;
	int y;
	shape s;
	movement m;
public:
	void Display(char arr[40][25], char sh[4][4], int t);
	int score(char arr[40][25]);
	void gotoxy(short x, short y);
	int LastRow(char shape[4][4]);
	int LeftCol(char shape[4][4]);
	int RightCol(char shape[4][4]);
	int MaxRow(char arr[40][25]);
	bool EndCheck(int y, char shape[4][4]);
	bool BlockCheck(char arr[40][25], char shape[4][4], int x, int y);

};










int main()
{
    char a;
    int b;





    ifstream myfile("score1.txt",ios::in);
    while(!myfile.eof())
    {
        myfile.get(a);
        cout<<a;
    }
    myfile.close();
    cout<<endl;
    cin>>b;

    if(b==1)
    {
        ClearScreen();
        shape s;
	movement m;
	display d;


	for (int var1=0;var1<40;var1++)
	{
		for (int var2=0;var2<25;var2++)
		{
			array[var1][var2]=' ';
		}
	}
	m.Timer(shapes,array);
	cout<<endl<<endl;
	for (int var1=0;var1<40;var1++)
	{
		for (int var2=0;var2<25;var2++)
		{
			array[var1][var2]=' ';
		}
	}
	d.gotoxy(0, 0);

	cout<<"                                         ";
	for (int var=0;var<=50;var++)
		cout<<"~";
	cout<<endl;
	for (int var1=0;var1<40;var1++)
	{
		cout<<"                                         (";
		for (int var2=0;var2<25;var2++)
		{
			cout<<array[var1][var2]<<" ";
			Sleep(3);
		}
		cout<<")                                            "<<endl;
	}
	cout<<"                                         ";
	for (int var=0;var<=50;var++)
		cout<<"_";
	cout<<endl;
	d.gotoxy(60, 18);
	cout<<"**** GAME END ****";
	Sleep(3000);
	d.gotoxy(0,41);
    }
    if(b==2)
    {

        cout<<"Game End";
    }
}

void shape::ShapeOnTop(char shape[4][4], char arr[40][25])
{
	for (int var1=0;var1<4;var1++)
	{
		for (int var2=10;var2<14;var2++)
		{
			arr[var1][var2]=shape[var1][var2-10];
		}
	}
}

void display::Display(char arr[40][25], char sh[4][4], int t)
{
	cout<<"                                         ";
	for (int var=0;var<=50;var++)
		cout<<"~";
	cout<<endl;
	for (int var1=0;var1<40;var1++)
	{
		if (var1==10)
			cout<<"            TETRIS GAME                  (";
		else if (var1==15 && t<=5)
			cout<<"         PLAY WITH PATIENCE              (";
		else
			cout<<"                                         (";
		for (int var2=0;var2<25;var2++)
		{
			cout<<arr[var1][var2]<<" ";
		}
		cout<<")";
		if (var1==15)
			cout<<"             LINES COMPLETED = "<<score(arr);
		if (var1==20)
			cout<<"             NEXT SHAPE : ";
		if (var1==23 || var1==24 || var1==25 ||var1==26)
		{
			cout<<"                 ";
			for (int a=0;a<4;a++)
			{
				cout<<sh[var1-23][a]<<" ";
			}
		}
		if (var1==10)
			cout<<"             Press 'q' to Quit";
		cout<<endl;
	}
	cout<<"                                         ";
	for (int var=0;var<=50;var++)
		cout<<"-";
	cout<<endl;

}

void movement::Timer(char sh[19][4][4], char arr[40][25])
{
	shape a;
	display d;
	movement m;

	clock_t start;
    double duration;
    start = clock();
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
	int r=abs((rand()*9999)%19);
	int r1=abs((rand()*999999)%19);

temp:
	r=r1;
	r1=abs((rand()*999999)%19);
	a.ShapeOnTop(sh[r],arr);
	int X=10;
	int Y=0;
	int c=0;
	int k=0;
	while (1)
	{
		if (fmod(1000000*duration,5000)==0)
		{
			c=0;
			k=_kbhit();
			if (k)
			{
				k=0;
				c=GetCharacter();
			}
			if (c==77)
				MoveRight(arr,sh[r],X,Y);
			else if (c==75)
				MoveLeft(arr,sh[r],X,Y);
			else if (c==80)
			{
				if (Y<32)
				{
					DropDown(sh[r],arr,X,Y);
					DropDown(sh[r],arr,X,Y);
				}
			}
			else if (c==32)
				s.ShapeChange(arr,sh[r],X,Y,r);
			else if (c==113)
				goto end;
			m.DropDown(sh[r],arr,X,Y);
			d.Display(arr,sh[r1], int(duration));
			if (d.EndCheck(Y,sh[r]) || d.BlockCheck(arr,sh[r],X,Y))
			{
				if (d.MaxRow(arr)<=2)
					goto end;
				system("CLS");
				goto temp;

			}
			Sleep(5);
			d.gotoxy(0,0);
		}
		duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
	}
	cout<<" ";
	end:;
}

void movement::DropDown(char shape[4][4], char arr[40][25],int& x, int& y)
{
	y+=1;
	for (int var1=y-1;var1<y+3;var1++)
	{
		for (int var2=x;var2<x+4;var2++)
		{
			if (shape[var1-y+1][var2-x]=='O')
				arr[var1][var2]=' ';
		}
	}
	for (int var1=y;var1<y+4;var1++)
	{
		for (int var2=x;var2<x+4;var2++)
		{
			if (arr[var1][var2]==' ')
				arr[var1][var2]=shape[var1-y][var2-x];
		}
	}
}

bool display::EndCheck(int y, char shape[4][4])
{
	int count=0;
	bool check=true;
	for (int var=3; var>=0 && check; var--)
	{
		for (int var1=0;var1<4;var1++)
		{
			if (shape[var][var1]=='O')
				check=false;
		}
		if (check)
			count+=1;
	}
	if (y+4-count==40)
		return true;
	else
		return false;
}

bool display::BlockCheck(char arr[40][25], char shape[4][4],int x, int y)
{
	bool check=false;
	for (int var=x; var<x+4; var++)
	{
		if (arr[y+1+LastRow(shape)][var]=='O' && shape[LastRow(shape)][var-x]=='O')
		{
			check=true;
		}
	}
	for (int var=x; var<x+4; var++)
	{
		{
			if ((arr[y+LastRow(shape)][var]=='O' && shape[LastRow(shape)][var-x]==' ' && shape[LastRow(shape)-1][var-x]=='O'))
				check=true;
		}
	}
	for (int var=x; var<x+4; var++)
	{
		{
			if ((arr[y+LastRow(shape)-1][var]=='O' && shape[LastRow(shape)-1][var-x]==' ' && shape[LastRow(shape)-2][var-x]=='O'))
				check=true;
		}
	}
	return check;
}
int display::LastRow(char shape[4][4])
{
	int count=0;
	bool check=true;
	for (int var=3; var>=0 && check; var--)
	{
		for (int var1=0;var1<4;var1++)
		{
			if (shape[var][var1]=='O')
				check=false;
		}
		if (check)
			count+=1;
	}
	return (3-count);
}
void movement::MoveRight(char arr[40][25], char shape[4][4],int &x, int &y)
{
    display d;
	if (x<21+d.RightCol(shape))
		x+=1;
	for (int var1=y;var1<y+4;var1++)
	{
		for (int var2=x-1;var2<x+3;var2++)
		{
			if (shape[var1-y][var2-x+1]=='O')
			arr[var1][var2]=' ';
		}
	}
	for (int var1=y;var1<y+4;var1++)
	{
		for (int var2=x;var2<x+4;var2++)
		{
			if (arr[var1][var2]==' ')
				arr[var1][var2]=shape[var1-y][var2-x];
		}
	}
}

void movement::MoveLeft(char arr[40][25], char shape[4][4],int &x, int &y)
{
    display d;
	if (x>0-d.LeftCol(shape))
		x-=1;
	for (int var1=y;var1<y+4;var1++)
	{
		for (int var2=x+1;var2<x+5;var2++)
		{
			if (shape[var1-y][var2-x-1]=='O')
			arr[var1][var2]=' ';
		}
	}
	for (int var1=y;var1<y+4;var1++)
	{
		for (int var2=x;var2<x+4;var2++)
		{
			if (arr[var1][var2]==' ')
				arr[var1][var2]=shape[var1-y][var2-x];
		}
	}
}
int movement::GetCharacter()
{

	char key;
	key=_getch();
	int asciivalue=key;
	return asciivalue;

}

int display::LeftCol(char shape[4][4])
{
	bool check=true;
	int count=0;
	for (int var1=0;var1<4;var1++)
	{
		for (int var2=0;var2<4;var2++)
		{
			if (shape[var2][var1]=='O')
				check=false;
		}
		if(check)
			count+=1;
	}
	return count;
}

int display::RightCol(char shape[4][4])
{
	bool check=true;
	int count=0;
	for (int var1=3;var1>=0;var1--)
	{
		for (int var2=0;var2<4;var2++)
		{
			if (shape[var2][var1]=='O')
				check=false;
		}
		if(check)
			count+=1;
	}
	return count;
}

void shape::ShapeChange(char arr[40][25],char shape[4][4], int x, int y, int r)
{
	bool check=true;
	for (int var1=y ;var1<y+4; var1++)
	{
		for(int var2=x; var2<x+4; var2++)
		{
			if (arr[var1][var2]=='O' && shape[var1-y][var2-x]!='O')
				check=false;
		}
	}
	if (check)
	{
		for (int var1=x ;var1<x+4; var1++)
		{
			for(int var2=y; var2<y+4; var2++)
			{
				arr[var2][var1]=' ';
			}
		}
		char temp[4][4];
		for (int var1=0 ;var1<4; var1++)
		{
			for(int var2=0; var2<4; var2++)
			{
				temp[var1][var2]=shape[var2][var1];
			}
		}
		for (int var1=0 ;var1<4; var1++)
		{
			for(int var2=0; var2<4; var2++)
			{
				shape[var1][var2]=temp[var1][var2];
			}
		}
	}

}

void display::gotoxy(short x, short y)
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int display::MaxRow(char arr[40][25])
{
	for (int var1=0;var1<40;var1++)
	{
		for (int var2=0;var2<25;var2++)
		{
			if (arr[var1][var2]=='O')
				return var1;
		}
	}
}

int display::score(char arr[40][25])
{
	int count=0;
	for (int var1=0;var1<40;var1++)
	{
		bool check=true;
		for(int var2=0;var2<25;var2++)
		{
			if (arr[var1][var2]==' ')
				check=false;
		}
		if (check)
			count+=1;
	}
	return count;
}

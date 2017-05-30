// SHOOP-DA-WHOOP!.cpp : main project file.
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>


using namespace std;
void gotoxy(int x, int y);
void title();


HWND hWnd;

int main(int argc, char **argv)
{
    int color;
	int i;
	char key;
	int winner=0;
	int p1counter=0;
	int p2counter=0;
    COORD xy;
    xy.X = 2;
    xy.Y = 2;

    HANDLE Console;
    Console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	title();



	//this is the left side player
	color = 15;
    SetConsoleTextAttribute(Console, color);
    gotoxy(0,0);
	cout << "@ @\n\n";

	color = 12;
	SetConsoleTextAttribute(Console, color);
    gotoxy(0,1);
	cout << "[_]\n\n";

	//this is the right side player
	color = 15;
    SetConsoleTextAttribute(Console, color);
    gotoxy(77,0);
	cout << "@ @\n\n";

	color = 12;
	SetConsoleTextAttribute(Console, color);
    gotoxy(77,1);
	cout << "[_]\n\n";
	//this is text
	color = 7;
	SetConsoleTextAttribute(Console, color);
    gotoxy(29,1);
	cout << "IMMA CHARGIN' MAH LAZER\n\n";

	do 
	{// laser
		key=_getch();

		//key for p1
		if (key == 'a')
		{	
			p1counter++;//couter to charge the hits to charge the laser
			if (p1counter==29)//if it is charged will shoot
			{
				winner=1;//set p1 as winner
				for(i=3;i<77;i++)//makes the laser goes over the screen
				{
					color=14;
					SetConsoleTextAttribute(Console, color);
					gotoxy(i,1);
					cout<<"=";
					Sleep(5);//speed of laser bean in miliseconds(bigger is slower)
				}
				cout<<"*";//hit char
				break;
			}
		}
	
		if (key=='l')
		{
			p2counter++;//couter to charge the hits to charge the laser
			if (p2counter==29)//if it is charged will shoot
			{
				winner=2;//set p2 as winner
				for(i=76;i>2;i--)//makes the laser goes over the screen
				{
					color=14;
					SetConsoleTextAttribute(Console, color);
					gotoxy(i,1);
					cout<<"=";
					Sleep(5);//speed of laser bean in miliseconds(bigger is slower)
				}
				gotoxy(i,1);
				cout<<"*";//hit char
				break;
			}
			
		}
	}while(key!=27);

	if(winner==1)
	{
		color = 12;
		SetConsoleTextAttribute(Console, color);
		cout<<""<<endl;
		cout<<"                   SHOOP! BLAAAAAAAH! Player 2, you got PWN'D."<<endl;
		color = 7;
		SetConsoleTextAttribute(Console, color);
		cout<<"                      Player 1, you win 9,001 internets!"<<endl;
	}
	if(winner==2)
	{
		color = 12;
		SetConsoleTextAttribute(Console, color);
		cout<<""<<endl;
		cout<<"                   SHOOP! BLAAAAAAAH! Player 1, you got PWN'D."<<endl;
		color = 7;
		SetConsoleTextAttribute(Console, color);
		cout<<"                      Player 2, you win 9,001 internets!"<<endl;
	}


    
    system ("pause");
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void title()
	{
		int color;

		HANDLE Console;
		Console = GetStdHandle(STD_OUTPUT_HANDLE);

		color = 10;
		SetConsoleTextAttribute(Console, color);
		cout<<"This is SHOOP-DA-WHOOP!"<<endl;
		cout<<""<<endl;
		color = 11;
		SetConsoleTextAttribute(Console, color);
		cout<<"You and your opponent are chargin' lazerz."<<endl;
		cout<<"Don't be a N00B.  Charge first and OWN that sucker."<<endl;
		cout<<""<<endl;
		color = 12;
		SetConsoleTextAttribute(Console, color);
		cout<<"To charge press A(Left Player) or L(Right Player)."<<endl;
		cout<<""<<endl;
		system("pause");
		system("cls");
	}

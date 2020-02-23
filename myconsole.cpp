#include <windows.h> 
#include <stdio.h>
#include<iostream>
#include "myconsole.h"

using namespace std;

//this function outputs a string str at position (x,y) of the screen 
void OutputString(int x,int y,char *str)
{    
    COORD c;
    c.X = x;
    c.Y = y;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
    cout << *str;
    cout.flush();

}

//this function will clear the screen
void ClearScreen()
{
	CONSOLE_SCREEN_BUFFER_INFO info;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&info);
	system("cls");
	SetConsoleCursorPosition(h,info.dwCursorPosition);
	
}
//this function will place the cursor at a certain position on the screen
void PlaceCursor(int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}

void SetWindowSize(int width,int height)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool bAbs = true;
	SMALL_RECT r;

	r.Left = 0;
	r.Top  = 0;
	r.Right = width;
	r.Bottom = height;

	SetConsoleWindowInfo(h,bAbs,&r);
}

//this function checks if a key is pressed and if a key is pressed
//then it returns the ascii code of the key pressed
//the parameter waitTime specifies how long we have to wait for an input
//the default value is 20 millisecond.  If within the wait time no key is pressed
//the function returns zero.
int CheckKeyPressed(int waitTime)

{
	HANDLE h= GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD r;
	DWORD w = 1;
	DWORD eventss;
	DWORD waitResult=0;
	int keypressed = false;
	int toReturn = 0;

	waitResult = WaitForSingleObject(h,waitTime);

	if (waitResult == WAIT_OBJECT_0)
	{
		keypressed = ReadConsoleInput(h,&r,1,&eventss);
		if (keypressed && r.EventType==KEY_EVENT)
			toReturn = r.Event.KeyEvent.wVirtualKeyCode;
		FlushConsoleInputBuffer(h);
	}
	return toReturn;
}




//changes the color of a certain co-ordinate
//color can be BACKGROUND_GREEN, BACKGROUND_BLUE,BACKGROUND_RED or a combination of these using | operator
bool SetColorAtPoint(int x,int y,int color)
{
    COORD c,size;
    c.X = x;
    c.Y = y;
	size.X = 1;
	size.Y = 1;


    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	WORD w = color;
	unsigned long written = 0;

	WriteConsoleOutputAttribute(h,&w,1,c,&written);

	if (written)
		return true;

	return false;
}

/*
// the hoop ...
HWND GetConsoleWndHandle1(void)
{
	HWND hConWnd;
	OSVERSIONINFO os;
	char szTempTitle[64], szClassName[128], szOriginalTitle[1024];

  //os.dwOSVersionInfoSize = sizeof( OSVERSIONINFO )
//  GetVersionEx( &os );
  // may not work on WIN9x
  if ( os.dwPlatformId == VER_PLATFORM_WIN32s ) 
	  return 0;

  GetConsoleTitle( szOriginalTitle, sizeof( szOriginalTitle ) );
  sprintf( szTempTitle,"%u - %u", GetTickCount(), GetCurrentProcessId() );
  SetConsoleTitle( szTempTitle );
  Sleep( 40 );
  // handle for NT
  hConWnd = FindWindow( NULL, szTempTitle );
  SetConsoleTitle( szOriginalTitle );

  // may not work on WIN9x
  if ( os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )
  {
    hConWnd = GetWindow( hConWnd, GW_CHILD );
    if ( hConWnd == NULL )  return 0;
    GetClassName( hConWnd, szClassName, sizeof ( szClassName ) );
    while ( strcmp( szClassName, "ttyGrab" ) != 0 )
    {
      hConWnd = GetNextWindow( hConWnd, GW_HWNDNEXT );
      if ( hConWnd == NULL )  return 0;
      GetClassName( hConWnd, szClassName, sizeof( szClassName ) );
    }
  }
  return hConWnd;
}*/


//changes the color at a certain pixel
//x and y are the coordinates of that pixel
//we have to remember that pixel is a very small dot on the screet
//you can speficy here the combination of red, green and blue shades (range 0-255) to make any shade of color
/*void changePixelColor(int x,int y,unsigned char red,unsigned char green,unsigned char blue)
{
	HWND hConWnd = GetConsoleWndHandle1();
	HDC dc = GetDC(hConWnd);
	COLORREF w RGB(red,green,blue);

	SetPixel(dc,x,y,w);

}*/
//this function outputs a string str at position (x,y) of the screen 
void OutputString(int x,int y,char *str);

//this function will clear the screen
void ClearScreen();



//this function will place the cursor at a certain position on the screen
void PlaceCursor(int x,int y);


//this will change the window size to width and height as specified in the function
void SetWindowSize(int width,int height);


//this function checks if a key is pressed and if a key is pressed
//then it returns the ascii code of the key pressed
//the parameter waitTime specifies how long we have to wait for an input
//the default value is 20 millisecond.  If within the wait time no key is pressed
//the function returns zero.
int CheckKeyPressed(int waitTime);


//changes the color of a certain co-ordinate
//changes the color of a certain co-ordinate
//color can be BACKGROUND_GREEN, BACKGROUND_BLUE,BACKGROUND_RED or a combination of these using | operator
//e.g. you can send as parameter BACKGROUND_GREEN|BACKGROUND_BLUE
//the following combinations are possible:
//FOREGROUND_BLUE	Text color contains blue.
//FOREGROUND_GREEN	Text color contains green.
//FOREGROUND_RED	Text color contains red.
//FOREGROUND_INTENSITY	Text color is intensified.
//BACKGROUND_BLUE	Background color contains blue.
//BACKGROUND_GREEN	Background color contains green.
//BACKGROUND_RED	Background color contains red.
//BACKGROUND_INTENSITY	Background color is intensified.
bool SetColorAtPoint(int x,int y,int color);

//changes the color at a certain pixel
//x and y are the coordinates of that pixel
//we have to remember that pixel is a very small dot on the screet
//you can speficy here the combination of red, green and blue shades (range 0-255) to make any shade of color
void changePixelColor(int x,int y,unsigned char red,unsigned char green,unsigned char blue);

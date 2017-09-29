/*
    John Nguyen
*/

#include <iostream>
using namespace std;

const int ROWS = 30;
const int COLS = 30;

struct Rect
{
    int locX;
    int locY;
    int width;
    int height;
    char icon;
    
};

//prototypes
//user input checks
int checkWidth(int); // user enter correct width - Works
int checkHeight(int); //user enter correct height - Works
int numOfRect(); // check correct input number of rectangles - works
int checklocX(); // check locX is valid - works
int checklocY(); // check locY is valid -works
char symbol();
int nLocX(int);
int nLocY(int);

//Maybe
int checknWidth(int);
int checknHeight(int);

Rect *createArray(int); // create an allocated array - works
Rect *inputRect(Rect *&, int); //input rect struct into array - Works
void resetCanvas(char t[ROWS][COLS]); //reset - works
void displayCanvas(char t[ROWS][COLS]); // print out canvas - works
void printOnCanvas(char can[ROWS][COLS], int, int, int, int, char); // works : just print
void assign(Rect *, char can[ROWS][COLS], int); // assign one by one and print - works
int whichNum(int);
void translate(Rect *&, int); //Shift the rectangle over - works
void resize(Rect *&, int); //Resize the rectangle - works

//My menu and its checks
int getMenu();
void displayMenu();



int main()
{
    
    char canvas[ROWS][COLS]; // 30x30 canvas
    resetCanvas(canvas);     // Overwrite the canvas with 30x30 of space
    
    int num = numOfRect();
    //Create dynamic allocated array of rectangle struct
    Rect *rec = createArray(num);
    rec = inputRect(rec, num);      // Insert the struct into the array
    assign(rec, canvas, num);       // Print the rectangles retrieved from the array of struct into a separate canvas
    displayCanvas(canvas);          // Print the canvas onto the console
    
    
    int decision = 0;
    do
    {
        displayMenu();
        decision = getMenu();
        switch (decision)
        {
            case 1:
            {
                int wNum = whichNum(num);
                translate(rec, wNum);
                
                // This is for efficiently so it should not be included in translate.
                // Just in case I may need to use a the function translate in the future
                resetCanvas(canvas);
                assign(rec, canvas, num);
                displayCanvas(canvas);
                
                break;
            }
            case 2:
            {
                int wNum = whichNum(num);
                resize(rec, wNum);
                
                resetCanvas(canvas);
                assign(rec, canvas, num);
                displayCanvas(canvas);
                
                break;
            }
            case 3:
            {
                cout << "Quitting... " << endl;
                break;
            }
                
            default:
            {
                break;
            }
                
        }
        
    }while(decision !=3);
    

}


/*
    Resize the rectangle
    @parem the dynamic array of struct rectangle
    @parem the rectangle that was asked to be change
*/
void resize(Rect *& t, int wNum)
{
    //Pointer get wNum locX
    int *locX = &t[wNum].locX;
    int *locY = &t[wNum].locY;
    
    //Get new user input that is valid through the check functions
    cout << "Enter the new width: " << endl;
    int nWidth = checkWidth(*locX);
    cout << "Enter the new height: " << endl;
    int nHeight = checkHeight(*locY);
    
    //pointer to new width and height
    int *x = &nWidth;
    int *y = &nHeight;
    
    //assign new width/ height
    t[wNum].width = *x;
    t[wNum].height = *y;
}

/*
    Translate the rectangle
    @parem the dynamic array of struct rectangle
    @parem the rectangle that was asked to be change
 */
void translate(Rect *& t, int wNum)
{
    //Note
    //int *x = &t[wNum].locX; same as t[wNum].locX;
    
    //Get the width of the specific rectangle
    int *width =&t[wNum].width;
    int *height = &t[wNum].height;
    //Using the width and height get the new x and y axis
    cout << "Enter the new X to shift over to: " << endl;
    int xAxis = nLocX(*width);
    cout << "Enter the new Y to shift over to: " << endl;
    int yAxis = nLocY(*height);
    
    
    // point to the value of loc
    int *x = &t[wNum].locY;
    *x += yAxis;
    int *y = &t[wNum].locX;
    *y += xAxis;
    
    // assign new locX and locY
    t[wNum].locY = *x;
    t[wNum].locX = *y;
    

}

/*
    Reset the canvas
    @parem the canvas
 */
void resetCanvas(char t[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j <COLS; j++)
        {
            t[i][j] = ' '; //space
        }
    }
}


/*
    Display the canvas
    @parem the canvas
 */
void displayCanvas(char t[ROWS][COLS])
{
    cout << endl;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j <COLS; j++)
        {
            cout << t[i][j];
        }
        cout << endl;
    }

}

/*
    Assign the struct in the array to a variable and print it out
    @parem the dynamic array
    @parem the canvas
    @parem How many rectangles there are
 */
void assign(Rect * t, char can[ROWS][COLS], int num) //print on the canvas
{
    for(int i = 0; i < num; i++)
    {
        //Extract the data from the struct array
        int locX = t[i].locX;
        int locY = t[i].locY;
        int width = t[i].width;
        int height = t[i].height;
        char icon = t[i].icon;
        
        
        printOnCanvas(can, locX, locY, width, height, icon);
    }
    
}

/*
    Print the canvas
    @parem the canvas
    @parem the locx of the rectangle
    @parem the locy of the rectangle
    @parem the width of the rectangle
    @parem the height of the rectangle
    @parem icon requested from the user for the icon
 */
void printOnCanvas(char can[ROWS][COLS], int locx, int locy, int width, int height, char symbol)
{
    
    for(int i = locy; i <= height+locy; i++)
    {
        for(int j = locx; j <= width+locx; j++)
        {
            can[i][j] = symbol;
        }
        
    }
}


/*
 Create a dynamic array
 @parem capacity of the array
 @return cynamic memory array
 */
Rect *createArray(int num)
{
    Rect *arrPtr = new Rect[num]; //dynamic memory
    return arrPtr;
}

/*
    Get the array of Rect 
    @parem the dynamic array
    @parem how many rectangles in there
 */
Rect *inputRect(Rect * &array, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the Location X of R" << i+1 << endl;
        int locX = checklocX();
        cout << "Enter the Location Y of R" << i+1 << endl;
        int locY = checklocY();
        
        cout << "Enter the width of R" << i+1 << endl;
        int width = checkWidth(locX);
        cout << "Enter the height of R" << i+1<< endl;
        int height = checkHeight(locY);
        
        cout << "Enter an icon for R" << i+1 << endl;
        char icon = symbol();
        
        Rect rec = {locX, locY, width, height, icon}; //Just one rectangle
        array[i] = rec;  // Allocated array equals that one rectangle, first slot
    }
    return array;
}

/*
    Request users how many rectangles they want
    @return valid number of rectangle
 */
int numOfRect()
{
    cout << "Enter Number of Rectangles (1-5): " << endl;
    int num = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> num)
        {
            if (num >=1 && num <= 5) //
            {
                loop = false;
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return num; //Return the valid month input
}


/*
    Check if the width entered was valid
    @parem the locX
    @return the valid width
 */
int checkWidth(int locX)
{
    int width = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> width)
        {
            if (width >=1 && width < 31) //
            {
                if(locX + width >= 31)
                {
                    cout << "Try again\n" << endl;
                }
                else
                {
                    loop = false;
                }
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    //Minus 1 because of computer counting from 0, so must take in consideration of user input
    return width - 1; //Return the valid width input
}

/*
    Check if the height entered was valid
    @parem the locY
    @return the valid height
 */
int checkHeight(int locY)
{
    int height = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> height)
        {
            if (height >=1 && height < 31) //
            {
                if(locY + height >= 31)
                {
                    cout << "Try again\n" << endl;
                }
                else
                {
                    loop = false;
                }
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    //Minus 1 because of computer counting from 0, so must take in consideration of user input
    return height - 1; //Return the valid height input
}

/*
    Check if the users locX is valid
    @return the valid locX
 */
int checklocX()
{
    int locX = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> locX)
        {
            if (locX >=1 && locX <= 30) //
            {
                loop = false;
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return locX - 1; //Return the valid locX input
}

/*
    Check if the users locY is valid
    @return the valid locY
 */
int checklocY()
{
    int locY = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> locY)
        {
            if (locY >=1 && locY <= 30) //
            {
                loop = false;
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return locY - 1; //Return the valid locX input
}

/*
    As the user for the icon to be use
    @return the icon
 */
char symbol()
{
    char icon;
    cin >> icon;
    return icon;
}

/*
    Ask the users for which rectangle they would like to use
    @parem the total number of rectangle
    @return the rectangle that is being requested
 */
int whichNum(int num)
{
    cout << "Which rectangle (1-" << num << ")? " << endl;
    int whichNum = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> whichNum)
        {
            if (whichNum >=1 && whichNum <= num) //
            {
                loop = false;
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    //Minus 1 because computer counts by 0. So the first element in the array starts at 0
    return whichNum - 1; //Return the valid locX input
}

/*
    Ask the user for the new locX
    @parem the width
    @return valid new locX
 */
int nLocX(int width)
{
    int nlocX = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> nlocX)
        {
            if (nlocX <= 30 && nlocX >= 1) //
            {
                if(width + nlocX >=30 || width + nlocX < -1)
                {
                    cout << "Try again\n" << endl;
                }
                else
                {
                    loop = false;
                }
                
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return nlocX; //Return the valid locX input

}

/*
    Ask the user for the new locY
    @parem the height
    @return valid new locY
 */
int nLocY(int height)
{
    int nlocY = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> nlocY)
        {
            if (nlocY <= 30 && nlocY >= 1) //
            {
                if(height + nlocY >=30 || height + nlocY < -1)
                {
                    cout << "Try again\n" << endl;
                }
                else
                {
                    loop = false;
                }
                
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return nlocY; //Return the valid locX input
    
}


//Menu - Not New Codes

/*
    Get the correct menu input
    @return the valid menu input
 */
int getMenu()
{
    int menu = 0;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu >=1 && menu <= 3) //
            {
                loop = false;
            }
            else
            {
                cout << "Try again\n" << endl;
            }
        }
        else
        {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Try Again\n" << endl;
        }
    }
    return menu; //Return the valid menu input
}

/*
    Display menu options
 */
void displayMenu()
{
    cout << "\nOptions: " << endl;
    cout << "1. Translate Rectangle" << endl;
    cout << "2. Resize Rectangle" << endl;
    cout << "3. Quit" << endl;
}





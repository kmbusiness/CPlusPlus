/*
	John Nguyen
 */

#include <iostream>
#include<ctime>
#include<string>
using namespace std;

const int ROWS = 5;
const int COLS = 5;


//prototypes
void displayBoard(char[ROWS][COLS]); //	Display the board
void resetBoard(char [ROWS][COLS]);	// Reset the board
void displayMenu();					//Display the Menu
int getMenuInput();					//Get vailid menu input
int getRow();						//Get valid row from the user
int getColumn();					//Get valid column from the user
void fireShot(char[ROWS][COLS], char[ROWS][COLS], int, int, int&);			//Attack according to the row x column

//Extra functions that I made
int convertLetter(char);			//Convert the letter typed by the user into number for the column input
void setShip(char[ROWS][COLS]);						//set the 2x2 ship





int main()
{
    srand(time(NULL));			//seed random
    char tab[ROWS][COLS]; // real board that has the ship
    char hideShip[ROWS][COLS]; //fake board that doesn't display the ship
    int HitCount = 0; // How many time the ship been hit
    resetBoard(hideShip); // set up board for the board that is seen by the user
    resetBoard(tab); // set up the board for the real board with the ship
    setShip(tab); // set the ship for tab which holds the real board
    displayBoard(hideShip); //Display the board that does not have the ship
    
    int decision = 0;
    
    //		Do while loop
    do
    {
        displayMenu();				//Display Menu
        decision = getMenuInput();	//get the valid menu option
        
        
        switch (decision)
        {
            case 1:				//Attack
            {
                int r;
                int c;
                cout << "Enter a Row Number: " << endl;
                r = getRow();
                cout << "Enter a Column Number: " << endl;
                c = getColumn();
                fireShot(tab, hideShip, r, c, HitCount);		//call function fireShot
                displayBoard(hideShip);
                
                // Indicate that the user has won and restart the game
                if (HitCount == 4) //Ship hit is a counter
                {
                    cout << "\nYou Won!" << endl;
                    resetBoard(hideShip); // set up board for the board that is seen by the user
                    resetBoard(tab); // set up the board for the real board with the ship
                    setShip(tab); // reset ship
                    HitCount = 0; // reset when win
                    cout << "\n===NewBoard====\n" << endl;
                    displayBoard(hideShip);
                    break;
                }
                
                break;
            }
                
            case 2: //Show solution
            {
                displayBoard(tab);
                resetBoard(hideShip); // set up board for the board that is seen by the user
                resetBoard(tab); // set up the board for the real board with the ship
                setShip(tab); // set the ship for tab which holds the real board
                cout << "\n===NewBoard====\n" << endl;
                displayBoard(hideShip);
                break;
            }
            case 3: // Quit
                
            {
                cout << "Farewell" << endl;
                break;
            }
                
                
        }
        
        
        
    } while (decision != 3);
    
    /*
    //VS only
    system("pause");
    //cin.get();
    return 0;
     */
}



/*
	Returns the converted letter into number for the column input
 
	@param ch Char that the user input
	@return the correlated number from the letter
 
 */
int convertLetter(char ch)
{
    int convertedNum;
    if (ch == 'A' || ch == 'a')
    {
        convertedNum = 0;
    }
    else if (ch == 'B' || ch == 'b')
    {
        convertedNum = 1;
    }
    else if (ch == 'C' || ch == 'c')
    {
        convertedNum = 2;
    }
    else if (ch == 'D' || ch == 'd')
    {
        convertedNum = 3;
    }
    else
    {
        convertedNum = 4;
    }
    
    return convertedNum;
}

/*
	Returns the validated row
 
	@returns the valid row
 */
int getRow()
{
    int rw;
    bool loop = true;
    while (loop)
    {
        if (cin >> rw)
        {
            if (rw <= 5 && rw >=1) // 1 - 5
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
    return rw - 1; //Return the valid row
    // Minus one because array starts counting from 0
}

/*
 Returns the validated column
 
 @returns the valid column
 */
int getColumn()
{
    char letter;
    int col;
    bool loop = true;
    while (loop)
    {
        
        if (cin >> letter)
        {
            col = convertLetter(letter);
            if (letter == 'A' || letter == 'a'||
                letter == 'B' || letter == 'b'||
                letter == 'C' || letter == 'c'||
                letter == 'D' || letter == 'd'||
                letter == 'E' || letter == 'e')
                //only certain char will pass
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
    return col; //Return the valid row
    // Plus one because array starts counting from 0
}


/*
	Void method returns nothing but takes in coordinate to be use
 
	@param row, col which are the row and the column that is designated by the user.
    @parem an two arrays one that has the ship and another that does not, so the one that does not can be use by users
    @parem Hit counter to be used as incremenent
 */
void fireShot(char tab[ROWS][COLS], char hideShip[ROWS][COLS], int row, int col, int &HitCount)
{
    
    if (tab[row][col] == 'S') //Remember when compare there are two '=='
    {
        hideShip[row][col] = '*';
        tab[row][col] = '*';
        HitCount++;
    }
    else
    {
        hideShip[row][col] = 'X';
        tab[row][col] = 'X';
    }
    
}


/*
	Void method that set the ship in a 2x2 manner
 
    @parem an array to be used
 */
void setShip(char tab[ROWS][COLS])
{
    int xZero = rand() % 5; // 0 - 4
    int yZero = rand() % 5; // 0 - 4
    
    //These were testing variables
    //int xZero = 0;
    //int yZero = 0;
    
    int xOne;
    int xTwo;
    int xThree;
    //col
    int yOne;
    int yTwo;
    int yThree;
    
    
    if (xZero == 4 && yZero == 4) //takes care of row 4 x col 4
    {
        xOne = xZero;
        yOne = yZero - 1;
        xTwo = xZero - 1;
        yTwo = yZero;
        xThree = xZero - 1;
        yThree = yZero - 1;
    }
    else if (yZero == 4) // takes care of anything within the col 4
    {
        xOne = xZero;
        yOne = yZero - 1;
        
        xTwo = xZero + 1;
        yTwo = yZero - 1;
        
        xThree = xZero + 1;
        yThree = yZero;
        
    }
    else if (xZero == 4) // takes care of anything that is in row 4
    {
        xOne = xZero - 1;
        yOne = yZero;
        
        xTwo = xZero - 1;
        yTwo = yZero + 1;
        
        
        xThree = xZero;
        yThree = yZero + 1;
    }
    else // Takes care of everything else
    {
        xOne = xZero;
        yOne = yZero + 1;
        xTwo = xZero + 1;
        yTwo = yZero;
        xThree = xZero + 1;
        yThree = yZero + 1;
        
    }
    
    //set Ship
    tab[xZero][yZero] = 'S';
    tab[xOne][yOne] = 'S';
    tab[xTwo][yTwo] = 'S';
    tab[xThree][yThree] = 'S';
}


/*
	Is a void method that creates new board for warship
 
    @parem an array to be used
 */
void resetBoard(char array[ROWS][COLS])
{
    char sign = '-';
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            array[i][j] = sign;
        }
    }
    
    
}

/*
	Is a void method that display the board
 
    @parem an array to be used
 */
void displayBoard(char array[ROWS][COLS])
{
    cout << "  A B C D E" << endl;
    
    for (int i = 0; i < ROWS; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < COLS; j++)
        {
            cout << array[i][j] << " ";
        }
        
        cout << endl;
    }
}

/*
	Is a void function that display the menu options
 */
void displayMenu()
{
    cout << "\nMenu:" << endl;
    cout << "1: Fire Shot" << endl;
    cout << "2: Show Solution / Give Up" << endl;
    cout << "3: Quit" << endl;
}

/*
 Is an int function that validate the user input
 @return the valid menu input
 */
int getMenuInput()
{
    int menu;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu == 1 || menu == 2 || menu == 3) //only 3 options allowed
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


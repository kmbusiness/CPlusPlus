#include<iostream>
#include <fstream>
#include <string>
using namespace std;

const int ROWS = 10;
const int COLS = 15;

//prototypes
void readMaze(int, string, char a[ROWS][COLS]);                 // Read text file and store into array
void displayMaze(char array[ROWS][COLS]);                       // Display maze
int getMenu();                                                  // Check menu input
void searchStart();                                             // Search where the start is
void displayMenu();                                             // Display menu
void displayDirect();                                           // Direction options
void move(char loc[ROWS][COLS], char, int&, int&);              // Move
bool checkSpace(char temp[ROWS][COLS], int curRow, int curCol); // User direction correct or not
bool checkFinish(char array[ROWS][COLS]);                       // Check whether the user finish
string getTxt(int);                                             // Based on the user menu input, string will be return of the file name
void searchStart(char array[ROWS][COLS], int&, int&);           // Search for start
char validateDirect(char a[ROWS][COLS], int, int);                      //Valid direction input

int main()
{
    char array[ROWS][COLS];                  //10 rows x 15 columns

    int decision = 0;
    int curRow;
    int curCol;
    do
    {
        displayMenu();                          //display menu
        decision = getMenu();                   //get valid menu option
        
        
        
        

        if(decision ==1 || decision == 2||decision == 3)
        {string txt = getTxt(decision);          //get the text file
                readMaze(decision, txt, array);
                cout << "New Map" <<endl;
                displayMaze(array);
                cout <<"\nStarting position = *" << endl;
                searchStart(array, curRow, curCol);                    // Assign starting position
                displayMaze(array);

                bool notFinish = checkFinish(array);
                //start game
                char direct;
                
                while(notFinish)
                {
                    
                
                displayDirect();
                direct = validateDirect(array, curRow, curCol);

                move(array,direct, curRow, curCol);
                notFinish = checkFinish(array);
                displayMaze(array);
                    
                    if(direct == 'q')
                    {
                        cout <<"\n"<< endl;
                        break;
                    }
                
                }
                
                if(notFinish == false)
                {
                    cout << "\nYou won!\n" << endl;
                }
            
            }
                
 

        
            else
            {
                cout << "Quit..." << endl;
                
            }
    }while(decision != 4);


    
    
}



/*
    Move around the maze
    @parem 2D array
    @parem chosen direction
    @parem saved current row
    @parem saved current column
 */
void move(char temp[ROWS][COLS], char direct, int &curRow, int &curCol)
{
    //char temp[ROWS][COLS];



            if(direct == 'w')
            {
                temp[curRow][curCol] = 'o';
                curRow-=1;
                temp[curRow][curCol] = '+';
                //displayMaze(temp);
            }
            
            else if(direct == 'a')
            {
                temp[curRow][curCol] = 'o';
                curCol-=1;
                temp[curRow][curCol] = '+';
                //displayMaze(temp);
            }
            
            else if(direct == 's')
            {
                temp[curRow][curCol] = 'o';
                curRow+=1;
                temp[curRow][curCol] = '+';
                //displayMaze(temp);
            }
    
            else if(direct == 'd')
            {
                temp[curRow][curCol] = 'o';
                curCol+=1;
                temp[curRow][curCol] = '+';
                //displayMaze(temp);
            }
            
            else if(direct == 'q') // d
            {
                direct = 'q';
                
            }
    

}

/*
 Check for finish
 @parem the array
 @return true if the location is finishline, else false
 */
bool checkFinish(char array[ROWS][COLS])
{
    bool finish = false;
    for (int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j <COLS; j++)
        {
            if(array[i][j] == 'f')
            {
                finish = true;
            }

            
        }
        
    }
    return finish;
}


/*
    Check for space
    @parem the array
    @parem saved current row
    @parem saved current column

    @return true if the location is empty, else false
 */
bool checkSpace(char temp[ROWS][COLS], int curRow, int curCol)
{
    bool empty = false;
            if(temp[curRow][curCol] == ' ' || temp[curRow][curCol] == 'f' || temp[curRow][curCol] == 'o')
            {
                empty = true;
            }
 
    return empty;
}

/*
 Display direction menu options
 */
void displayDirect()
{
    cout << "Press: " << endl;
    cout << "<w> --> North" << endl;
    cout << "<a> --> West" << endl;
    cout << "<s> --> South" << endl;
    cout << "<d> --> East" << endl;
    cout << "<q> --> Quit" << endl;
}

/*
    validate the chosen direction is valid
    @parem the array
    @parem saved current row
    @parem saved current column
    @return the validated move
 */
char validateDirect(char temp[ROWS][COLS], int curRow, int curCol)
{
    char direct;
    bool loop = true;
    while (loop)
    {
        if (cin >> direct)
        {
            if (direct == 'w' || direct == 'a' || direct == 's' || direct == 'd' || direct == 'q') //choices
            {
                
                if(direct == 'w')
                {
                    //
                    if(checkSpace(temp, curRow-1, curCol))
                    {
                        curRow-=1;      //Looking back at my code, I have no clue why this was included
                        direct = 'w';
                        loop = false;
                    }
                    else
                    {
                        cout << "Invalid\n" << endl;
                    }
                    
                }
                
                else if(direct == 'a')
                {
                    
                    
                    if(checkSpace(temp, curRow, curCol-1))
                    {
                        curCol-=1;
                        direct = 'a';
                        loop = false;
                    }
                    else
                    {
                        cout << "Invalid\n" << endl;
                    }

                }
                
                else if(direct == 's')
                {
                    
                    
                    if(checkSpace(temp, curRow+1, curCol))
                    {
                        curRow+=1;
                        direct = 's';
                        loop = false;
                    }
                    else
                    {
                        cout << "Invalid\n" << endl;
                    }

                }
                
                else if (direct == 'd')
                {
                    
                    
                    if(checkSpace(temp, curRow, curCol+1))
                    {
                        curCol+=1;
                        direct = 'd';
                        loop = false;
                    }
                    else
                    {
                        cout << "Invalid\n" << endl;
                    }

                    
                }

                else if(direct == 'q')
                {
                    cout << "Quit..\n " << endl;
                    loop = false;
                }
                
                
                }
            
            else
            {
                cout << "Try Again\n" << endl;
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
    return direct; //Return the valid menu input
}


/*
    Search for the start
    @parem the array
    @parem saved current row
    @parem saved current column
 */
void searchStart(char array[ROWS][COLS], int &currRow, int &currCol)
{
    for (int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j <COLS; j++)
        {
            if(array[i][j] == 's')
            {
                array[i][j] = '+';
                currRow = i;
                currCol = j;
            }
            
        }
        
    }

}


/*
    Display the maze
    @parem the array
 */
void displayMaze(char array[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j <COLS; j++)
        {
            cout << array[i][j];
            
        }
        cout << endl;
    }
}


/*
    Read the maze from the txt file
    @parem menu selection
    @parem text selected
    @parem array
 */
void readMaze(int pick, string txt, char array[ROWS][COLS])
{
    //char array[ROWS][COLS];
    fstream file;
    char input;
    file.open(txt.c_str(), ios::in);    // Assign to maze 1 if pick equals 1
    if(file)
    {
        
        for (int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j <COLS+1; j++)
            {
                file.get(input);
                array[i][j] = input;
            }
        }
        file.close();
        // cout << input[1] << endl;
        
    }
    else
    {
        cout << "Cout Not Open File." << endl;
    }

}

/*
 Get the correct menu input
 @return the valid menu input
 */
int getMenu()
{
    int menu;
    bool loop = true;
    while (loop)
    {
        if (cin >> menu)
        {
            if (menu >=1 && menu <= 4) //
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
 Based on the pick of the user return the txt file
 @parem maze pick chosen by the user
 @return string of the maze file name;
 */
string getTxt(int pick)
{
    string txt;
    if(pick == 1)
    {
        txt = "Maze1.txt";
    }
    else if(pick == 2)
    {
        txt = "Maze2.txt";
    }
    else
    {
        txt = "Maze3.txt";
    }
    return txt;
}




/*
 Display menu options
 */
void displayMenu()
{
    cout << "1. Maze #1" << endl;
    cout << "2. Maze #2" << endl;
    cout << "3. Maze #3" << endl;
    cout << "4. Quit" << endl;
}

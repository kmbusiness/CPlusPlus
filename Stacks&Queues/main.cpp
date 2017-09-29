#include "Point.h"
#include <stack>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

//Prototypes
string getTxt(int);
int getTextPick();
void readMaze(int, string, char a[5][5]);
void displayMaze(int row, int col, char **arr);
void getPoint(int row, int col, char **arr, Point &p);      //Get the starting Point (Finds the start point)
void solveMazeDFS(Point &p, char **maze, int row, int col);
void solveMazeBFS(Point &p, char **maze, int row, int col);
int getMenu2();

//Extra Credit
bool move(char **maze,Point &currLoc, char d, int row, int col); //User move
char validateDirect(char **maze, Point p);    //Valid direction input
bool checkSpace(char **maze, Point p);
void displayDirect();

int main()
{
    int row;
    int col;
    Point currLoc; //   Point to access the starting location and for future current location
    
    bool loop = true;
    while(loop)
    {
        fstream file;
        int pick = getTextPick();
        if(pick == 5)
        {
            cout << "Quiting..." << endl;
            loop = false;
        }
        else
        {
        string txt = getTxt(pick);
        file.open(txt.c_str(), ios::in);
        
        //Get the row and col
        file >> row;
        file >> col;
        
        // Create dynamic 2D array
        char** maze = new char*[row];
        for(int i = 0; i < col; ++i)
        {
            maze[i] = new char[col];
        }
        
        char input;
        if(file)
        {
            
            for (int i = 0; i < row; i++)
            {
                for(int j = 0; j <col + 1; j++)
                {
                    file.get(input);
                    maze[i][j] = input;
                }
            }
            file.close();
        }
        else
        {
            cout << "Cout Not Open File." << endl;
        }

                int pick2 = getMenu2();
                if(pick2 == 1)
                {
                    //Using DFS(Stack)
                    getPoint(row, col, maze, currLoc); // Get starting location
                    cout << "DFS";
                    solveMazeDFS(currLoc, maze, row, col);
                }
                else if(pick2 == 2)
                {
                    //Using BFS(Queue)
                    getPoint(row, col, maze, currLoc); // Get starting location
                    cout << "BFS";
                    solveMazeBFS(currLoc, maze, row, col);
                }
            else if(pick2 == 3)
            {
                getPoint(row, col, maze, currLoc); // Get starting location
                displayMaze(row, col, maze);
                bool loop2 = true;
                while(loop2)
                {
                    char d = validateDirect(maze, currLoc);
                    loop2 = move(maze, currLoc, d, row, col);
                    
                    // Quit and let the DFS solve
                    if (d == 'q')
                    {
                        currLoc = Point(currLoc.getX(), currLoc.getY());
                        solveMazeDFS(currLoc, maze, row, col);
                        loop2 = false;
                    }
                    
                }
                
            }
            
            // Delete the allocated array
            delete [] maze;
            maze = NULL;

    }
    
    }

}

/*
    Solve maze by DFS (using stack)
    @parem Point that holds the starting location
    @parem Maze 2D array
    @parem row
    @parem col
 */
void solveMazeDFS(Point &currLoc, char **maze ,int row, int col)
{
    stack <Point> dfs;  //Using Stack
    
    // Push into stack/ dfs
    dfs.push(currLoc);
    
    //Check to see if this point is the finish
    bool notFound = true;
    while(notFound)
    {
        int tempX = dfs.top().getX();
        int tempY = dfs.top().getY();
        dfs.pop(); // pop point
        if(maze[tempX][tempY] == 'f')
        {
            notFound = false;
        }
        else if (maze[tempX][tempY] == ' ' || maze[tempX][tempY] == 's')
        {
            
            maze[tempX][tempY] = '.'; //Leaves trail mark
            
            //Up
            if(maze[tempX - 1][tempY] != '*' )
            {
                currLoc = Point(tempX - 1, tempY); //new location to be push in
                dfs.push(currLoc); //Push in new currLoc
            }
            
            //Down
            if(maze[tempX + 1][tempY] != '*')
            {
                currLoc = Point(tempX + 1, tempY);
                dfs.push(currLoc); //Push in new currLoc
            }
            
            // Left
            if(maze[tempX][tempY - 1] != '*')
            {
                currLoc = Point(tempX, tempY - 1);
                dfs.push(currLoc); //Push in new currLoc
            }
            
            // Right
            if(maze[tempX][tempY +1] != '*')
            {
                currLoc = Point(tempX, tempY + 1);
                dfs.push(currLoc); //Push in new currLoc
            }
        }
        
    }   //end while loop
    
    displayMaze(row, col, maze);

}

/*
 Solve maze by BFS (using queue)
 @parem Point that holds the starting location
 @parem Maze 2D array
 @parem row
 @parem col
 */
void solveMazeBFS(Point &currLoc, char **maze ,int row, int col)
{
    queue<Point> bfs; // Using Queue
    
    // Push into queue / bfs
    bfs.push(currLoc);
    
    //Check to see if this point is the finish
    bool notFound = true;
    while(notFound)
    {
        int tempX = bfs.front().getX();
        int tempY = bfs.front().getY();
        bfs.pop(); // pop point
        
        if(maze[tempX][tempY] == 'f')
        {
            notFound = false;
        }
        else if (maze[tempX][tempY] == ' ' || maze[tempX][tempY] == 's')
        {
            
            maze[tempX][tempY] = '.'; //Leaves trail mark
            
            //Up
            if(maze[tempX - 1][tempY] != '*' )
            {
                currLoc = Point(tempX - 1, tempY); //new location to be push in
                bfs.push(currLoc); //Push in new currLoc
            }
            
            //Down
            if(maze[tempX + 1][tempY] != '*')
            {
                currLoc = Point(tempX + 1, tempY);
                bfs.push(currLoc); //Push in new currLoc
            }
            
            // Left
            if(maze[tempX][tempY - 1] != '*')
            {
                currLoc = Point(tempX, tempY - 1);
                bfs.push(currLoc); //Push in new currLoc
            }
            
            // Right
            if(maze[tempX][tempY +1] != '*')
            {
                currLoc = Point(tempX, tempY + 1);
                bfs.push(currLoc); //Push in new currLoc
            }
        }
        
    }   //end while loop
    
    displayMaze(row, col, maze);
    
}



/*
    Find the starting Point and set the Point p
    @parem row
    @parem col
    @parem allocated 2d array
    @parem Point p
 */
void getPoint(int row, int col, char **arr, Point &p)
{
    for (int i = 0; i < row; i++)
            {
                for(int j = 0; j <col; j++)
                {
                    if(arr[i][j] == 's')
                    {
                        p = Point(i,j);
                    }
                    
                }
                
            }
}


/*
 Display the maze
 @parem the array
 */
void displayMaze(int row, int col, char **arr)
{
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j <col + 1; j++)
        {
            cout << arr[i][j];
            
        }
    }
    cout << endl;
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
    else if(pick == 3)
    {
        txt = "Maze3.txt";
    }
    else if (pick == 4)
    {
        txt = "Maze4.txt";
    }
    return txt;
}

/*
 Get the correct text pick input
 @return the valid pick input
 */
int getTextPick()
{
    cout << "Which Maze file would you like to use?" << endl;
    cout << "1) Maze1.txt" << endl;
    cout << "2) Maze2.txt" << endl;
    cout << "3) Maze3.txt" << endl;
    cout << "4) Maze4.txt" << endl;
    cout << "5) Quit" << endl;
    int pick;
    bool loop = true;
    while (loop)
    {
        if (cin >> pick)
        {
            if (pick >=1 && pick <= 5) //
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
    return pick;
}

/*
 Get the correct input
 @return the valid input
 */
int getMenu2()
{
    cout << "1) Use DFS(Stack) to solve" << endl;
    cout << "2) Use BFS(Queue) to solve" << endl;
    cout << "3) Solve it yourself" << endl;
    int pick;
    bool loop = true;
    while (loop)
    {
        if (cin >> pick)
        {
            if (pick >=1 && pick <= 3) //
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
    return pick;
}

//Extra Credit
/*
 Move around the maze
 @parem 2D array
 @parem chosen direction
 @parem saved row
 @parem saved col
 */
bool move(char **maze,Point &currLoc, char d, int row, int col)
{
    bool win = true; //To stop the while loop in the main for winning
            //Up
            if(d == 'w')
            {
                maze[currLoc.getX()][currLoc.getY()] = '.';
                int tempX = currLoc.getX() - 1;
                int tempY = currLoc.getY();
                
                if(maze[tempX][tempY] == 'f')
                {
                    cout << "You Win" << endl;
                    win = false;
                }
                
                maze[tempX][tempY] = 'o'; //Current Location
                currLoc = Point(tempX, tempY); // New currLoc
            }
            //Down
            else if(d == 's')
            {
                maze[currLoc.getX()][currLoc.getY()] = '.';
                int tempX = currLoc.getX() + 1;
                int tempY = currLoc.getY();
                
                if(maze[tempX][tempY] == 'f')
                {
                    cout << "You Win" << endl;
                    win = false;
                }
                
                maze[tempX][tempY] = 'o';
                currLoc = Point(tempX, tempY); // New currLoc
            }

            
            // Left
            else if(d == 'a')
            {
                maze[currLoc.getX()][currLoc.getY()] = '.';
                int tempX = currLoc.getX();
                int tempY = currLoc.getY() - 1;
                
                if(maze[tempX][tempY] == 'f')
                {
                    cout << "You Win" << endl;
                    win = false;
                }
                
                maze[tempX][tempY] = 'o';
                currLoc = Point(tempX, tempY); // New currLoc
            }
            
            // Right
            else if(d == 'd')
            {
                maze[currLoc.getX()][currLoc.getY()] = '.';
                int tempX = currLoc.getX();
                int tempY = currLoc.getY() + 1;
                
                if(maze[tempX][tempY] == 'f')
                {
                    cout << "You Win" << endl;
                    win = false;
                }
                
                maze[tempX][tempY] = 'o';
                currLoc = Point(tempX, tempY); // New currLoc
            }

    displayMaze(row, col, maze);
    return win;
}

/*
 Check for space
 @parem 2D array
 @parem Point that holds the current location
 
 @return true if the location is empty, else false
 */
bool checkSpace(char **maze, Point p)
{
    bool empty = false;
    if(maze[p.getX()][p.getY()] == ' ' || maze[p.getX()][p.getY()] == 'f' || maze[p.getX()][p.getY()] == '.')
    {
        empty = true;
    }
    
    return empty;
}

/*
 validate the chosen direction is valid
 @parem 2D array
 @parem Point that holds the current location
 @return the validated move
 */
char validateDirect(char **maze, Point p)
{
    displayDirect();
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
                    p = Point(p.getX() -1, p.getY());
                    if(checkSpace(maze, p))
                    {
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
                    
                    p = Point(p.getX(), p.getY() -1);
                    if(checkSpace(maze, p))
                    {
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
                    
                    p = Point(p.getX() +1, p.getY());
                    if(checkSpace(maze, p))
                    {
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
                    
                    p = Point(p.getX(), p.getY() +1);
                    if(checkSpace(maze, p))
                    {
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
 Display direction menu options
 */
void displayDirect()
{
    cout << "Press: " << endl;
    cout << "<w> --> North" << endl;
    cout << "<a> --> West" << endl;
    cout << "<s> --> South" << endl;
    cout << "<d> --> East" << endl;
    cout << "<q> --> Quit (Solve by DFS)" << endl;
}


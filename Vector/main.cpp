#include <iostream>
#include<vector>
using namespace std;

//prototypes
void displayMenu();                                 // Display the menu options
int getMenuInput();                                 // Check if the menu input is valid
int sizeOfVector();                                 // Check if the given vector size is valid
vector<int> populateVector(int);                    // Populate Vector
void printVec(vector<int>, int);                    // Print Vector
void sortVec(vector<int> &);                        // Sort Vector
vector<int> createCopy(vector<int> &);              // Copy vector
int sumVec(const vector<int> &);                    // Sum of vector
int maxVec(const vector<int> &, int);               // Maximum value of the vector
int minVec(const vector<int> &);                    // Minimum value of the vector
double findMedian(const vector<int> &);             // Find the median
void average(int, int);                           // Find the average
int search(const vector <int> &, int);              // Find matching number
void searchResponse(int, int);                      // Print out the search result
int findWhat();                                     // Check if the user input the correct number range of the number to be find. Anything number greater than 0
vector<int> mode(const vector<int> &);                              // Find mode
void modeResponse(const vector<int> & ,const vector<int> &);        // Response for the mode

int main()
{
    srand(time(NULL)); //seed random

    cout << "Enter the size of the vector" << endl;
    int numVec = sizeOfVector();

    //displayMenu();                                      //display menu
    vector<int> firstVec = populateVector(numVec);      //orginial vector
    vector<int> unsorted = createCopy(firstVec);        //copied for unsorted
    sortVec(firstVec);                                  //sort the orginial
    int sum = sumVec(firstVec);                         // Need the sum here because I used the value sum to find the average
    

    
    int decision = 0;
    
    do
    {
          displayMenu();                                      //display menu

        
        decision = getMenuInput();                          //Get valid menu input
        
        switch(decision)
        {
            case 1: // unsorted
            {
                printVec(unsorted, numVec);
                break;
            }
                
            case 2: // sorted
            {
                printVec(firstVec, numVec);
                break;
            }
                
            case 3: // sum
            {
                cout <<"Sum: " << sum << endl;
                break;
            }
                
            case 4: // average
            {
                average(sum, numVec);
                break;
            }
                
            case 5: // maximum value
            {
                int max = maxVec(firstVec, numVec);
                cout << "\nMax: " << max;
                break;
            }
                
            case 6: // minimum value
            {
                int min = minVec(firstVec);
                cout << "\nMin: " << min;
                break;
            }
                
            case 7: // median
            {
                double median = findMedian(firstVec);
                cout << "\nMedian: " << median;
                break;
            }
                
            case 8: //mode
            {
               vector<int> mde = mode(firstVec);
                modeResponse(mde, firstVec);
                break;
            }
                
            case 9:
            {
                cout <<"\nWhat number to find? " <<endl;
                int find = findWhat();
                int serch = search(firstVec, find);
                cout <<"\n";
                searchResponse(serch, find);
                break;
            }
                
            case 10:
            {
                cout << "Quitting..." <<endl;
                break;
            }
        }
        
    } while (decision != 10);


    return 0;
    
}



/*
    Response according to the the mode found
    @parem the vector that was used in the function mode and the firstVec
 
 */


void modeResponse(const vector<int> &vec, const vector<int> &b)
{
        if(vec[0] != vec[1] && vec.size() == b.size()) // No mode
        {
            cout << "There are no mode" << endl;
    
        }
        else if (vec.size() == 1) //If only one mode
        {
            cout << "The mode is: " << vec[0] << endl;
        }
        else //If more than one mode
        {
            cout << "The modes are: " << vec[0];
            for (int i = 1; i < vec.size(); i++)
            {
                cout << ", " << vec[i];
            }
            cout << endl;
        }
    
}


/*
    Find the mode
    @parem a vector
 */
vector<int> mode (const vector<int> &v)
{
    vector<int> number;         //Vector to store each unique number
    vector<int> numberCount;    //Vector to store the number of occurance
    
    for (int i = 0; i < v.size(); i++)
    {
        if (number.size() == 0)     // If there were no number in the vector
        {
            number.push_back(v[i]);     // Push first number into vector
            numberCount.push_back(1);   //Start the count vector
        }
        else                            //There are number in the vector
        {
            if (number[number.size() - 1] == v[i])  //If there is this number
            {
                numberCount[number.size() - 1] += 1; //Add 1 to the NumberCount
            }
            else //If this number has not been added to the vector already
            {
                number.push_back(v[i]); //Add to vector
                numberCount.push_back(1); //start count
            }
        }
    }
    
    int max = 0; // Store the highest number
    for (int i = 0; i < numberCount.size(); i++)
    {
        if (numberCount[i] > max) // If numberCount is higher than max
        {
            max = numberCount[i]; // Update max
        }
    }
    
    
    for (int i = numberCount.size() - 1; i >= 0; i--)   // Remove number that isn't in the max range
    {
        if (numberCount[i] < max) //If number less than max
        {
            number.erase(number.begin() + i);           //remove
            numberCount.erase(numberCount.begin() + i);
        }
    }
    
    return number;
    
}

/*
    Function that make sure the user input the correct range for find
    @return the correct, valid find
 */
int findWhat()
{
    int find;
    bool loop = true;
    while (loop)
    {
        if (cin >> find)
        {
            if (find >=1) //only positve number
            {
                loop = false;
            }
            else
            {
                cout << "Try again. Enter number that is greater than 0.\n" << endl;
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
    return find; //Return the valid find input
}



/*
    Function that response accordingly to the search result
    @parem the number that was requested to be found
    @parem the outcome of the search result
 
 */
void searchResponse(int match, int find)
{

    if(match != -1)
    {
        cout << "Bingo!!! Your number " << find << " was found!!!!" <<endl;
    }
    
    else
    {
        cout << "That number " << find << " was not found." << endl;
    }
}


/*
    Function that search for the number requested by the user
    @parem the number that need to be find
    @parem the vector
    @return -1 if the value is not found
 */
int search(const vector<int> &v, int find)
{
    int low = 0;
    int high = v.size() - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(v[mid] == find)
        {
            return mid;
        }
        else if (v[mid] < find)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


/*
    Function that determines the average
    @parem the sum that was returned by the sum function
    @parem the size of the vector declared by the user
    @return the average of the vector
 */
void average(int sum, int num)
{
    double size = num + 1; // Add one because when I returned num from the function sizeOfVector I subtract 1 because computer counts from 0
                           // Therefore when I add one it gets back the user input of the size initiated
    double avg = sum / size;
    cout << "Average: " << avg << endl;
}


/*
    Function that find the median value of a sorted vector
    @parem A constant vector with numbers so the vector does not get change
    @return the median value of the vector
 */
double findMedian(const vector<int> &v)
{
    double median = 0;
    //int size = v.size();
    
    if(v.size() % 2 == 0)
    {
        median = (v[v.size() / 2 - 1] + v[v.size() / 2]) / (double)2; //type casted into double for remainder
    }
    else
    {
        median = v[v.size() /(double) 2]; //type casted into double for remainder
    }
    //cout << "Median: " << median <<endl;
    return median;
}



/*
    Function that find the minium value of a sorted vector
    @parem A constant vector with numbers so the vector does not get change
    @return the min value of the vector
 */
int minVec(const vector<int> &v)
{
    int min = v[0]; //The first element in the vector
    //cout <<"Minimum: " << min << endl;
    return min;
}


/*
    Function that find the max value of a sorted vector
    @parem A constant vector with numbers so the vector does not get change
    @parem the size of the vector
    @return the max value of the vector
 */
int maxVec(const vector<int> &v, int num)
{
    int max = v[num]; //The last element in the vector
    //cout << "Maximum: " << max << endl;
    return max;
    
}



/*
    A function that takes the sum of all the element in the vector
    @parem an int vector that is a constant so the value does not get affected when referenced
    @return the total sum of the vector
 */
int sumVec(const vector<int> &v)
{
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}


/*
    A sort function that uses the implementation of bubble sort
    @parem an int vector
 */
void sortVec(vector<int> &vec)
{
    bool swapped = false;
    do
    {
        swapped = false;
        for(int i = 0; i < vec.size() - 1; i++)
        {
            if(vec[i] > vec[i + 1])
            {
                int swap = vec[i];
                vec[i] = vec[i+1];
                vec[i + 1] = swap;
                swapped = true;
            }
        }
    } while(swapped);
    
    
}





/*
    Is a function that create a copy of the original vector
    @parem the original vector
    @return the copied vector
 */
vector<int> createCopy(vector<int> &v) //pass by reference
{
    vector<int> copy;
    for(int i = 0; i < v.size(); i++)
    {
        copy.push_back(v[i]);
    }
    return copy;
}

/*
    Is a function that prints the vector
    @parem the vector
    @parem the size of vector declared by the user input
 
 */
void printVec(vector<int> v, int num)
{
    for (int i = 0; i <= num; i++)
    {
        cout << v[i] << " "; // print vec out
        
        if ((i % 10) == 9) //10 numbers per line (9 % 10 = 9 so new line)
        {
            cout << "\n";
        }
        
        

        
    }
}

/*
    Is a function that populate a vector
    @parem the size of vector declared by the user input
    @return vector with randomized number from 1 -100
 
 */
vector<int> populateVector(int num)
{
    vector<int> vec;
    for (int i = 0; i <= num; i++)
    {
        int x = rand() % (100 - 1) + 1; // (max-min)+min = range from min - max (1-100)
        vec.push_back(x); //insert random generated number into vec
    }
    return vec;
}

/*
    Function that display the menu options
 */
void displayMenu()
{
    cout << "\n\nMenu Options:" << endl;
    cout << "1: Display unsorted list" << endl;
    cout << "2: Display sorted list" << endl;
    cout << "3: Display sum" << endl;
    cout << "4: Display average" << endl;
    cout << "5: Display maximum value" << endl;
    cout << "6: Display minimum value" << endl;
    cout << "7: Display median value" << endl;
    cout << "8: Display mode values" << endl;
    cout << "9: Find matching value" << endl;
    cout << "10: Quit" << endl;
}

/*
	Is an int function that validate the user input of the size of the vector
	@return the valid menu input
 */
int sizeOfVector()
{
    int num;
    bool loop = true;
    while (loop)
    {
        if (cin >> num)
        {
            if (num >=1) //only 1 or greater number of size of the vector
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
    return num - 1; //Return the valid size input
                    //minus 1 because computer counts from 0
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
            if (menu >=1 && menu <= 10) //only 10 options allowed
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

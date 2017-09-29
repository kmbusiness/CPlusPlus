#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("file.txt", ios::in);

    string input;
    
    //Create stack and read file into stack
    stack <string> values;
    while  (file >> input)
    {
        values.push(input);
    }
    file.close();
   /////////////////////////////////////////////////
    
    
    
    file.open("reverse.txt", ios::out | ios::app);
    
    // Print out into reverse.txt
    if(file)
    {
        
        while(!values.empty())
        {
            file << values.top() << endl;
            values.pop();
        }
        file.close();
    }
    else
    {
        cout << "Error Opening File" << endl;
    }
    
    return 0;
    
}

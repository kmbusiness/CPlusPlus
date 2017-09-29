#include <iostream>
#include <list>
using namespace std;

int main()
{
    int x, y, z, a, b, c;
    list<int> variables; // list
    list<int>:: iterator it; // iterator
    
    cout << "X " << endl;
    cin >> x;
    cout << "Y " << endl;
    cin >> y;
    
    cout << "A " << endl;
    cin >> a;
    cout << "B " << endl;
    cin >> b;
    
    cout << x << " + " << y << endl;
    cout << a << " + " << b << endl;
    
    z = x + y;
    c = a + b;
    
    variables.push_back(z);
    variables.push_back(c);
    //variables.push_front(100);
    
    it = variables.begin();
    int num;
    do
    {
        cout << "1) " << x << " + " << y << endl;
        cout << "2) " << a << " + " << b << endl;
        cout << "3) Quit" << endl;
        cin >> num;
        
        if (num  == 1)
        {
            cout << *it << endl;
            it = variables.begin();
        }
        else if (num == 2)
        {
            advance(it, 1); // it += doesn't work so this will do
            cout << *it << endl;
            it = variables.begin();
        }
    }while (num != 3);
    
}

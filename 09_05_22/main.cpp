#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main() 
{
    double area, length, width;
    string myStr = "My name is Angela.";

    cout << setprecision(2) << fixed << showpoint;
    
    //setting length and width

    length = 7;
    width = 5;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << endl;

    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << endl;

    area = length * width;
    cout << area << endl;


    int x = 5;
    int y = 2;
    
    int z = static_cast<double>(x) / y;

    cout << "z = "<< z << endl;


    cout << "Enter something: ";
    getline(cin >> ws, myStr);
    
    cout << endl;

    cout << "You entered: " << myStr << endl;
    return 0;
}
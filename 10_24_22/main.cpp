#include <iostream>
#include <cmath>
#include <cctype>
#include <climits>
#include <string>
#include <fstream>

using namespace std;

double getDoubleGreaterThan0(string prompt);
char getUnits();
long calcualteBytes(double memSize, char unit);
int secret(int);
double secret(double);
void readStudentFromFile(ifstream&, int&, char&);


int main()
{
    int mar;
    double memorySize = getDoubleGreaterThan0("Enter the memory size: ");
    char unit = getUnits();
    long bytes = calcualteBytes(memorySize, unit);

    cout << "The minimum MAR size for " << bytes << " bytes of memory is " << ceil(log2(bytes)) << " bits." << endl;

    bytes = calcualteBytes(3, 'K');
    cout << secret(4) << endl;
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin >> ws,sentence);
    cout << sentence << endl;

    ifstream infile;
    infile.open("grades.txt");
    int studentNum;
    char grade;
    while (!infile.eof())
    {
        readStudentFromFile(infile, studentNum, grade);
        if(!infile)
            break;
        cout << studentNum << " - " << grade << endl;
    }

    

    return 0;

}

double getDoubleGreaterThan0(string prompt)
{
    double x;

    cout << prompt;
    cin >> x;
    cout << endl;
    while (!cin || x <= 0)
    {
        if (!cin)
        {
            cout << "You entered something that is not a number." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else
        {
            cout << "You entered a number that is less than or equal to 0." << endl;
        }
        cout << prompt;
        cin >> x;
        cout << endl;
    }
    return x;
}


char getUnits()
{
    char unit;
    cout << "Enter the units (B = Bytes, K = KB, M = MB, G = GB, T = TB): ";
    cin >> unit;
    cout << endl;
    unit = toupper(unit);
    while (unit != 'B' && unit != 'K' && unit != 'M' && unit != 'G' && unit != 'T')
    {
        cout << "That is not valid units." << endl;
        cout << "Enter the units (B = Bytes, K = KB, M = MB, G = GB, T = TB): ";
        cin >> unit;
        cout << endl;
        unit = toupper(unit);
    }
    return unit;
}

long calcualteBytes(double memSize, char unit)
{
    long bytes;
    if (unit == 'B')
    {
        bytes = ceil(memSize);
    }
    else if (unit == 'K')
    {
        bytes = ceil(memSize * pow(2, 10));
    }
    else if (unit == 'M')
    {
        bytes = ceil(memSize * pow(2, 20));
    }
    else if (unit == 'G')
    {
        bytes = ceil((memSize * pow(2, 30)));
    }
    else if (unit == 'T')
    {
        bytes = ceil(memSize * pow(2, 40));
    }
    return bytes;
}
int secret(int x)
{
    if (x > 5)
        return 2 * x;
    
    return x;
}


void readStudentFromFile(ifstream& in, int& x, char& ch)
{
    in >> x >> ch;
}

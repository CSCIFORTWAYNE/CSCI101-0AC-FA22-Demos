#include <iostream>
#include <string>
#include <climits>
#include <iomanip>

using namespace std;

void inputValidation(int&, string);
void initialize(int[], int);
void inputArray(int[], int);
void outputArray(int[], int);
void calculateSumAndAverage(int[], int, int&, double&);
void findLargest(int[], int, int&);
const int ARRAY_SIZE = 100;

void twoDArray(int table[5][7], int rowCount, int colCount);

int main()
{
    cout << setprecision(2) << showpoint << fixed;
    int num[ARRAY_SIZE];
    num[5] = 7; // sixth item in the array in position 5
    int table[5][7];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            table[i][j] = 0;
        }
    }
    
    initialize(num, 10);
    inputArray(num, 10);
    outputArray(num, 10);
    int sum = 0;
    double average;
    calculateSumAndAverage(num, 10, sum, average);

    
    cout << "The sum of the numbers is " << sum << endl;
    cout << "The average of the numbers is " << average << endl;
    int largestPos;
    findLargest(num, 10, largestPos);
    
    cout << "The largest element is " << num[largestPos] << " at position " << largestPos <<endl;
    

    return 0;
}

void inputValidation(int& x, string prompt)
{
    while(!cin)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "You entered something that is not a number." << endl;
        cout << prompt;
        cin >> x;
    }
}

void initialize(int list[], int size)
{
    for(int i = 0; i < size; i++) //i = i + 1
    {
        list[i] = 0;
        
    }
}

void inputArray(int list[], int size)
{
for(int i = 0; i < size; i++)
    {
        cout << "Enter a number (" << i << "): ";
        cin >> list[i];
        cout << endl;
        inputValidation(list[i], "Enter a number (" + to_string(i) + "): ");

    }
}

void outputArray(int list[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << list[i] << endl;
    }
}

void calculateSumAndAverage(int list[], int size, int& sum, double& avg)
{
    sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += list[i];
    }
    avg = static_cast<double>(sum) / size;
}

void findLargest(int list[], int size, int& lg)
{
    lg = 0;
    for(int i = 1; i < size; i++)
    {
        if(list[lg] < list[i])
        {
            lg = i;
        }
    }
}
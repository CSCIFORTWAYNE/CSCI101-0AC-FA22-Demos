#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <climits>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("grades.txt");
    int studentNum;
    char grade;

    int count = 0;
    
    while (!infile.eof())
    {
        
        infile >> studentNum >> grade;
        
        if(!infile)
        {
            break;
        }

        if (grade <= 'C')
        {
            cout << studentNum << " has earned a passing grade of " << grade << endl;
        }
        else
        {
            cout << studentNum << " needs to improve their grade. It is currently " << grade << endl;
        }
        count++; // count = count + 1;
    }
    char play = 'Y';
    int winning = 75;
    int user;

    while (play != 'N')
    {
        cout << "Enter a number between 1 and 1000: ";
        cin >> user;
        cout << endl;

        while (!cin || user < 1 || user > 1000)
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "You did not enter a number. Please try again." << endl;
            }
            else
            {
                cout << "You entered a number out of range." << endl;
            }
            cout << "Enter a number between 1 and 1000: ";
            cin >> user;
            cout << endl;
        }

        if (user < winning)
        {
            cout << "I win!!" << endl;
            cout << "I'm the best!" << endl;
            
        }
        else
        {
            cout << "I didn't win :(" << endl;
        }

        cout << "Would you like to play again? (Y or N) ";
        cin >> play;
        cout << endl;
        play = toupper(play);
        while (play != 'Y' && play != 'N')
        {
            cout << "You did not enter a Y or N. Please try again." << endl;
            cout << "Would you like to play again? (Y or N) ";
            cin >> play;
            cout << endl;
            play = toupper(play);
        }

        winning = rand() % 1000 + 1;
    }

    cout << "Thank you for playing." << endl;
    cout << "Goodbye" << endl;

    return 0;
}
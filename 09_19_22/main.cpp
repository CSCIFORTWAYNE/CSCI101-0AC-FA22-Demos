#include <iostream>
#include <fstream>


using namespace std;


int main()
{
    /*
    int winning = 75;
    int user;
    char day;

    cout << "Enter a number: ";
    cin >> user;
    cout << endl;

    cout << "Enter a character for the day: ";
    cin >> day;
    cout << endl;

    if(user < winning || day == 'M')
    {
        cout << "I win!!" << endl;
        cout << "I'm the best!" << endl;
    }
    else
    {
        cout << "I didn't win :(" << endl;
    }

    
    cout << "Thank you for playing." << endl;
    cout << "Goodbye" << endl;

    */
   /*
   ifstream infile;
   infile.open("grades.txt");

   int studentNum;
   char grade;

   infile >> studentNum >> grade; //reading first student from the file
   if(grade <= 'C')
   {
        cout << studentNum << " has earned a passing grade of " << grade << endl;
   }
   else 
   {
    cout << studentNum << " needs to improve their grade. It is currently " << grade << endl;
   }

    infile >> studentNum >> grade; //reading second student from file
   if(grade <= 'C')
   {
        cout << studentNum << " has earned a passing grade of " << grade << endl;
   }
   else 
   {
    cout << studentNum << " needs to improve their grade. It is currently " << grade << endl;
   }

       infile >> studentNum >> grade; //reading third student from file
   if(grade <= 'C')
   {
        cout << studentNum << " has earned a passing grade of " << grade << endl;
   }
   else 
   {
    cout << studentNum << " needs to improve their grade. It is currently " << grade << endl;
   }
*/

    int num;
    cout << "Enter an integer: ";

    cin >> num;
    cout << endl;
    if(!cin)
    {
        cout << "You have entered something that is not a number." << endl;
        return 0;
    } 
    else if (num <= 0)
    {
        cout << "Please enter a positive number." << endl;
        return 0;
    }
    if (0 <= num && num <= 10)
    {
        cout << num << " is within 0 and 10." << endl;
    }
    else 
    {
        cout << num << " is not within 0 and 10." << endl;
    }


    return 0;
}
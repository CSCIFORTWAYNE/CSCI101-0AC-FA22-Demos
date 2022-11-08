#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

//using namespace std;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::setfill;
using std::left;

enum productType
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H
};
/*const int A = 0;
const int B = 1;
const int C = 2;
const int D = 3;
const int E = 4;
const int F = 5;
const int G = 6;
const int H = 7;*/
const double TAX_RATE = .17;
const double SHIPPING = 14.95;

productType getProduct(char);
double calculateLineTotal(productType, int);
std::string printProduct(productType);
void printLowerTableRow(std::string, double);
string toLowerCase(string);

int main()
{
    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    ifstream infile;
    infile.open("order1.txt");
    productType prod;
    int quantity;
    char prodCode;
    double lineTotal;
    double subTotal = 0;
    double tax;

    cout << "Thank You! Your order is summarized below:" << endl;
	cout << setw(52) << setfill('-') << "-" << endl;
	cout << setfill(' ');
	cout << "| " << setw(15) << left << "Product" << "| " << setw(15) << "Quantity" << "| " << setw(15) << "Line Total" << "|"<< endl; 
	cout << setw(52) << setfill('-') << "-" << endl;
	cout << setfill(' ');
    
    while (!infile.eof())
    {
        infile >> prodCode >> quantity;
        prod = getProduct(prodCode);
        lineTotal = calculateLineTotal(prod, quantity);
        cout << "| " << setw(15) << left << printProduct(prod) << "| " << setw(15) << quantity 
             << "| $" << setw(15) << lineTotal << "|"<< endl; 
	    cout << setw(52) << setfill('-') << "-" << endl;
	    cout << setfill(' ');
        subTotal += lineTotal; //subtotal = subtotal + lineTotal;
    }

    printLowerTableRow("Subtotal", subTotal);

    tax = subTotal * TAX_RATE;

    printLowerTableRow("Tax", tax);
    printLowerTableRow("Shipping", SHIPPING);
    printLowerTableRow("Grand Total", subTotal + tax + SHIPPING);
    
    string str = "Have a good day!";
    str[0] = 'D'; //access first char of the string
    return 0;
}

productType getProduct(char p)
{
    switch (p)
    {
    case 'A':
        return A;
    case 'B':
        return B;
    case 'C':
        return C;
    case 'D':
        return D;
    case 'E':
        return E;
    case 'F':
        return F;
    case 'G':
        return G;
    case 'H':
        return H;
    default:
        return A;
    }
}

double calculateLineTotal(productType p, int q)
{
    double line;
    switch (p)
    {
    case A:
        line = q * 17.46;
        break;
    case B:
        line = q * 10.13;
        break;
    case C:
        line = q * 2.11;
        break;
    case D:
        line = q * 23.13;
        break;
    case E:
        line = q * 74.56;
        break;
    case F:
        line = q * 1.11;
        break;
    case G:
        line = q * 9.34;
        break;
    case H:
        line = q * 3.45;
        break;
    default:
        line = 0;
    }
    return line;
}

string printProduct(productType p)
{
    switch (p)
    {
    case A:
        return "A";
        break;
    case B:
        return "B";
        break;
    case C:
        return "C";
        break;
    case D:
        return "D";
        break;
    case E:
        return "E";
        break;
    case F:
        return "F";
        break;
    case G:
        return "G";
        break;
    case H:
        return "H";
        break;
    default:
        return "Unknown Product";
        
    }
}

void printLowerTableRow(string label, double amount)
{
    cout << "| " << setw(15) << left << label << "| " << setw(15) << " " 
         << "| $" << setw(15) << amount << "|"<< endl; 
	cout << setw(52) << setfill('-') << "-" << endl;
	cout << setfill(' ');

}

string toLowerCase(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = std::tolower(s[i]);
    }
}
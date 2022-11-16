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

const int NUM_PRODUCTS = 8;
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

const char productCodes[NUM_PRODUCTS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G','H'};
const productType products[NUM_PRODUCTS] = {A, B, C, D, E, F, G, H};
const double productPrice[NUM_PRODUCTS] = {17.46, 10.13, 2.11, 23.13, 74.56, 1.11, 9.34, 3.45};

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
    infile.open("order3.txt");
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
        cout << "| " << setw(15) << left << productCodes[prod] << "| " << setw(15) << quantity 
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
    for(int i = 0; i < NUM_PRODUCTS; i++)
    {
        if(p == productCodes[i])
            return products[i];
    }
    return products[0];
}

double calculateLineTotal(productType p, int q)
{
    double line;
   
    line = q * productPrice[p];
       
    return line;
}

/*string printProduct(productType p)
{
    return productCodes[p];
}*/

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
    return s;
}
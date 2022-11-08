#include <iostream>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#endif

const std::string corazon = "\xe2\x99\xa5";
const char diamante[] = "\xe2\x99\xa6";
const char pica[] = "\xe2\x99\xa4";
const char trebol[] = "\xe2\x99\xa7";


int main()
{
    std::string x = "♥";
    std::cout << x << std::endl;
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
}
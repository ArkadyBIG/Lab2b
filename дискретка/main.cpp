#include <iostream>
#include <conio.h>
//using namespace std;
#define suka  std::cout
#define blat  std::endl
#include "CALCULATE.h"
#include "EQUATION.h"
#include "JEGALKIN.h"
//#include cout std::cout


int main()
{
    string E=")";
    while(1)
    {
        system("cls");
        suka<<"Available symbols: \n'^' - AND\n'@' - OR\n'=' - if x==y returns 1\n '!' - if 0 returns 1 \n '(' ')' - brackets\n'+' - mod(2) \nExample: (x+y)^z@x=1\n";

    getline(cin,E);

    equation(E);
    suka<<"DDNF:\n"<<DDNF(E)<<endl;

    suka<<"POLINOM JEGALKINA:\n"<<polinom_jegalkina(E)<<endl;
    _getch();
    }
    return 0;
}

#include <iostream>
#include <conio.h>
//using namespace std;


#include "CALCULATE.h"
#include "EQUATION.h"
#include "JEGALKIN.h"
//#include cout std::cout
// 

int main()
{
    string E=")";
    while(1)
    {
        system("cls");
        cout<<"Available symbols: \n'^' - AND\n'@' - OR\n'=' - if x==y returns 1\n '!' - if 0 returns 1 \n '(' ')' - brackets\n'+' - mod(2) \nExample: (x+y)^z@x=1\n";

    getline(cin,E);

    equation(E);
    cout<<"DDNF:\n"<<DDNF(E)<<endl;

    cout<<"POLINOM JEGALKINA:\n"<<polinom_jegalkina(E)<<endl;
    _getch();
    }
    return 0;
}

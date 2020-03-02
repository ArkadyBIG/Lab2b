#include <iostream>
#include <windows.h>
using namespace std;
/*
~ equal
^ *

*/
bool calculate(string equation)
{
    //cout<<"E: "<<equation<<ends<<equation.size()<<endl;
    if(equation.size()==1)
    {
        if(equation=="1") return 1;
        if(equation=="0") return 0;
        cout<<"MISTAKE OCURED! "<<equation<<endl;
        exit(0);
    }
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='(')
    {
       string in_brackets;
       equation.erase(i,1);
       for(int b=0;;)
       {
           if(equation[i] != ')' || b>0)
           {
               if(equation[i]=='(')
               b++;
               if(b>0 && equation[i] == ')')
               b--;
               in_brackets+=equation[i];
               equation.erase(i,1);
           }
           else
               break;
       }

       equation[i]=(char)calculate(in_brackets) + 48;

    }
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='!')
    {
        equation.erase(i,1);
        if(equation[i]=='1') equation[i]='0';
        else if(equation[i]=='0') equation[i]='1';
        else cout<<"MISTAKE OCURED!!"<<endl;
      //  cout<<equation<<endl;
    }
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='^')
    {
        if(equation[i-1]=='0' || equation[i+1]=='0') equation[i-1]='0';
        else equation[i-1]='1';
        equation.erase(i,2);
        i--;
      //  cout<<equation<<endl;
    }
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='>')
    {

        if(equation[i-1]=='0')
        {
            equation[i-1]='1';
            equation.erase(i,2);

        }
        else if(equation[i+1]=='1')
        {
            equation[i-1]='1';
            equation.erase(i,2);

        }
        else
        {
            equation[i-1]='0';
            equation.erase(i--,2);

        }
        i--;
      //  cout<<equation<<endl;
    }
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='@')
    {
        if(equation[i-1]=='1' || equation[i+1]=='1') equation[i-1]='1';
        else equation[i-1]='0';
        equation.erase(i,2);
        i--;
        // cout<<"& "<<equation<<endl;
    }
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='+')
    {
        if(equation[i-1]==equation[i+1]) equation[i-1]='0';
        else equation[i-1]='1';
        equation.erase(i,2);
        i--;
        // cout<<"& "<<equation<<endl;
    }
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='=')
    {
        if(equation[i-1]==equation[i+1]) equation[i-1]='1';
        else equation[i-1]='0';
        equation.erase(i,2);
        i--;
        // cout<<"& "<<equation<<endl;
    }
    return calculate(equation);
}

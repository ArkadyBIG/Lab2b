
#include <iostream>
#include <vector>
#include <string>

#include "CALCULATE.h"
using namespace std;
struct Varible
{
    char name;
    bool value;
};
vector<Varible> var(0);
bool add()
{
    for(int i=0;i<var.size();++i)
        if(var[i].value=(!var[i].value))
        return 1;
    return 0;
}
bool equation(string eq)
{
    var.clear();
    //cout<<eq<<endl;
    for(int i=0;i<eq.size();++i)
        if(eq[i]>=97 && eq[i] <=122)
        {
         bool is=0;
         for(int j=0;j<var.size();++j)
            if(var[j].name==eq[i])
            is=1;
         if(!is)
         var.push_back({eq[i],0});
    }

    for(int i=0;i<var.size();++i)
    {
        cout<<var[i].name<<"   ";
    }
    cout<<"F()"<<endl;
    do
    {
        for(int i=0;i<var.size();++i)
        cout<<var[i].value<<"   ";
        string to_help;
        for(char c : eq)
        {
            if(c>=97 && c<=122)
            {
                for(int j=0;j<var.size();++j)
                    if(var[j].name==c){
                    to_help+=to_string(var[j].value);
                break;}

            }
            else to_help+=c;
        }
        cout<<calculate(to_help)<<endl;
    }while (add());
}
string DDNF(string eq)
{
    string ddnf;
    for(int i=0;i<eq.size();++i)
        if(eq[i]>=97 && eq[i] <=122)
        {
         bool is=0;
         for(int j=0;j<var.size();++j)
            if(var[j].name==eq[i])
            is=1;
         if(!is)
         var.push_back({eq[i],0});
    }



    do
    {


        string to_help;
        for(char c : eq)
        {
            if(c>=97 && c<=122)
            {
                for(int j=0;j<var.size();++j)
                    if(var[j].name==c){
                    to_help+=to_string(var[j].value);
                break;}

            }
            else to_help+=c;
        }
        if(calculate(to_help))
        {
            for(int i=0;i<var.size();++i)
                if(var[i].value){
                ddnf.push_back(var[i].name);
                ddnf+="^";}
                else
                {
                      ddnf+="!";
                      ddnf.push_back(var[i].name);
                      ddnf+="^";}
            ddnf[ddnf.size()-1]='@';
        }
    }while (add());
    return ddnf.erase(ddnf.size()-1);
}

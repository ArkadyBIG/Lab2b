#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "EQUATION.h"
using namespace std;
void TO_JEGALKIN(string &jeg)
{
    if(jeg.size()==2)
    {
        jeg.erase(0,1);
        jeg+="+1";
        return;
    }
    string out;
    int one=0;
    for(int i=0;i<jeg.size();++i)
        {
            if(jeg[i]=='!' ){
                for(int j=i+1;j<jeg.size();++j)
                    out+=jeg[j];
                break;
            }
            out+=jeg[i];
        }
        out+='+';
        one=0;
    for(int i=0;i<jeg.size();++i)
    {
        if(jeg[i]=='!' ){
                for(int j=3+i;j<jeg.size();++j)
                    out+=jeg[j];
                break;
            }
            out+=jeg[i];
    }
    if(out[out.size()-1]=='^') out.erase(out.size()-1,1);
    jeg=out;

}
void clear_repets(string &equation)
{

    /*int counter=0;
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='1')
            counter++;
    counter/=2;
    counter*=2;

    if(counter)
        for(int i=0;i<equation.size() && counter;++i)
            if(equation[i]=='1')
        {
            equation.erase(i-1,2);
            counter--;
            i=0;
        }*/
        vector<string> elements(1);
        for(int i=0;i<equation.size();++i)
        {
            if(equation[i]=='+')
            {
                elements.push_back("");
                continue;
            }

            elements[elements.size()-1]+=equation[i];

        }
       /* for(string s : elements)
            cout<<s<<endl;*/
        for(int i=0;i<elements.size()-1;++i)
            for(int j=i+1;j<elements.size();++j)
            if(elements[i]==elements[j])
        {
            elements.erase(elements.begin()+i);
            elements.erase(elements.begin()+j-1);
            i=-1;
            break;
        }
        equation="";
        for(string s : elements)
        equation+=s+"+";
        equation.erase(equation.size()-1);




}
string polinom_jegalkina(string equation)
{
    equation=DDNF(equation);
    //cout<<equation<<endl;
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='@') equation[i]='+';
    for(int i=0;i<equation.size();++i)
        if(equation[i]=='!')
    {
        //cout<<"i: "<<i<<endl;
        if(i>0){
        for(i;i>=0;--i)
            if(equation[i]=='+')
                break;
        ++i;}

        //cout<<"i: "<<i<<endl;
        string to_jeg;
        for(int j= i ;j<equation.size() && equation[j]!='+';++j)
            to_jeg+=equation[j];
        equation.erase(i,to_jeg.size());
        //cout<<to_jeg<<endl;
        TO_JEGALKIN(to_jeg);
        equation.insert(i,to_jeg);
       // cout<<to_jeg<<endl;


    }
    clear_repets(equation);
   return equation;
}

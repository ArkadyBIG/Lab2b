#include <iostream>
#include <vector>
#include <conio.h>

#include "Queue_class.h"
#include "choose_a_choise.h"
using namespace std;

Queue Q;
void new_task()
{
    Features f;
    cout<<"Enter the task:\n";
    cin>>f.task;
    cout<<"Enter the priority\n";
    cin>>f.priority;
    cout<<"Hours it will take:\n";
    cin>>f.time.hour;
    cout<<"Minutes it will take:\n";
    cin>>f.time.minutes;

    Q.push(f);
}
int less_time()
{
    int ind=0;
    for(int i=0;i<Q.size_();++i)
    {
        if(Q[ind]->features.time.hour>Q[i]->features.time.hour)
            ind=i;
        else if(Q[ind]->features.time.hour==Q[i]->features.time.hour && Q[ind]->features.time.minutes>Q[i]->features.time.minutes)
            ind=i;
    }
    return ind;
}
int most_priority()
{
    int ind=0;
    for(int i=0;i<Q.size_();++i)
    {
        if(Q[ind]->features.priority>Q[i]->features.priority)
            ind=i;

    }
    return ind;
}
int main()
{
    //new_task();
    //new_task();
    int ind=-1;
    while(1)
    {
        system("cls");
        if(Q.size_()==0)
        {
            cout<<"Your queue is empty.Lets create a new Task!\n";
            new_task();
        }

        cout << "What task to do first?\n";
        switch(choose({"Task with less time","Priority","Create a new task","Show all tasks","EXIT"}))
        {
        case 0:
            {


            bool task_is_done=0;
            while(!task_is_done)
            {
                system("cls");
                ind = less_time();
                cout<<"You are doing:\n";
                Q.show(Q[ind]);
                switch(choose({"Mark it as done","Create a new task"}))
                {
                case 0:
                    Q.erase(ind);
                    task_is_done=1;
                    break;
                case 1:

                    new_task();
                    break;

                }

            }

        }break;
        case 1:
            {

            bool task_is_done=0;
            while(!task_is_done)
            {
                system("cls");
                ind = most_priority();
                cout<<"You are doing:\n";
                Q.show(Q[ind]);
                switch(choose({"Mark it as done","Create a new task"}))
                {
                case 0:
                    Q.erase(ind);
                    task_is_done=1;
                    break;
                case 1:
                    new_task();
                    break;
                }
            }
            break;
        }
        case 2:
            {


            new_task();
            break;
            }
        case 3:
            Q.show();
            getche();
            break;
        case 4:
            return 1;
        }
        system("cls");

    }

    return 0;
}

#ifndef QUEUE_CLASS_H_INCLUDED
#define QUEUE_CLASS_H_INCLUDED

#include <iostream>
#include <windows.h>
using namespace std;

struct Time
{
    int hour;
    int minutes;
};
struct Features{
    string task;
    Time time;
    unsigned int priority;
    };
void print(Features f)
{
        cout<<"Task: "<<f.task<<endl;
        cout<<"Priority: "<<f.priority<<endl;
        cout<<"Time it takes: "<<f.time.hour<<" hour "<<f.time.minutes<<" minutes "<<endl;
}
struct Node
{
    Features features;

    Node *next;
};
class Queue
{
private:
    size_t size;
    Node *first;
public:
    Queue();
    size_t size_()
    {
        return size;
    }
    void show();
    void show(Node* );
    void push(Features);
    void erase(int );
    Node* operator [](int ind)
    {
        if(ind>=size) {
                cout<<"Index is out of range. EROR 404.";
                exit(0);}
        Node *n=first;
        for(int i=0;i<ind;++i)
            n=n->next;

        return n;
    }

};
void Queue::erase(int ind)
{
    if(ind>=size) {
            cout<<"Index is out of range. EROR 403.";
            exit(0);
            }
    size--;
    Node *prev=first;
    if(ind==0)
    {
        first=first->next;
        delete prev;
        return;
    }
        for(int i=0;i<ind-1;++i)
            prev=prev->next;
    Node *to_erase=prev->next;
    prev->next=to_erase->next;
    delete to_erase;

}
void Queue::show(Node *node)
{
    print(node->features);
}
void Queue::push(Features F)
{

    if(size++ == 0) //If Queue was empty
    {
        Node *new_node=new Node;
        new_node->features=F;
        new_node->next=0;
        first=new_node;
        return;
    }

    Node *node=first;
    Node *new_node=new Node;
    new_node->features=F;
    new_node->next=nullptr;


    while(node->next!=nullptr) node=node->next;
    //cout<<node->features.task<<endl;
    node->next=new_node;
    new_node->next=0;
}

void Queue::show()
{
    if(size==0)
    {
        cout<<"Queue is empty!\n";
        return;
    }
    Node *node=first;
    //print(node->features);
    do
    {
        print(node->features);
    }while(node=node->next);
}
Queue::Queue()
{
    size=0;
    first=0;
}
#endif // QUEUE_CLASS_H_INCLUDED

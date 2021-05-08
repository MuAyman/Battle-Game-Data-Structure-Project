#pragma once
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct n // node declaration
{
    int priority;
    int info;
    struct n* next;
};
class Priority_Queue
{
private:
    n* f;

public:
    Priority_Queue()
    {

        f = NULL;
    }
    void insert(int i, int p)
    {
        n* t, * q;
        t = new n;
        t->info = i;
        t->priority = p;
        if (f == NULL || p < f->priority)
        {
            t->next = f;
            f = t;
        }
        else
        {
            q = f;
            while (q->next != NULL && q->next->priority <= p)
                q = q->next;
            t->next = q->next;
            q->next = t;
        }
    }
    void delet()
    {
        n* t;
        if (f == NULL) //if queue is null
            cout << "Queue Underflow\n";
        else
        {
            t = f;
            cout << "Deleted item is: " << t->info << endl;
            f = f->next;
            free(t);
        }
    }
    void show() //print queue {
    {
        n* ptr;
        ptr = f;
        if (f == NULL)
            cout << "Queue is empty\n";
        else
        {
            cout << "Queue is :\n";
            cout << "Priority Item\n";
            while (ptr != NULL)
            {
                cout << ptr->priority << " " << ptr->info << endl;
                ptr = ptr->next;
            }
        }
    }
};


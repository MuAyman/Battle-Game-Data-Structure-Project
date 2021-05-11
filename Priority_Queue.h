#pragma once
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

template <class T>
struct n // node declaration
{
    T priority;
    T info;
    struct n * next;
};

template <class T>
class Priority_Queue
{
private:
    n<T>* f;
    int count;
public:
    Priority_Queue()
    {
        f = NULL;
    }
    void insert(T i, T p)
    {
        count++;

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
        count--;

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

    int GetCount() const
    {
        return count;
    }

    const T* toArray(int& count)
    {

        //IMPORTANT:
        //toArray function to be used ONLY when drawing the queue items

        count = 0;

        if (!f)
            return nullptr;
        //counting the no. of items in the Queue
        n* p;
        p = f;
        while (p)
        {
            count++;
            p = p->getNext();
        }


        T* Arr = new T[count];
        p = f;
        for (int i = 0; i < count; i++)
        {
            Arr[i] = p->getItem();
            p = p->getNext();
        }
        return Arr;
        //IMPORTANT:
        //toArray function to be used ONLY when drawing the queue items

    }

};

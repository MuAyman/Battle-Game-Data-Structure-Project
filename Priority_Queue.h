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
    int priority;
    T info;
    n<T> * next;
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
        f = nullptr;
        count = 0;
    }
    void insert(T i, int p)
    {
        count++;

        n<T>* t, * q;
        t = new n<T>;
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

    void insert_Stack(T i, int p)
    {
        count++;

        n<T>* t, * q;
        t = new n<T>;
        t->info = i;
        t->priority = p;
        if (f == NULL || p > f->priority)
        {
            t->next = f;
            f = t;
        }
        else
        {
            q = f;
            while (q->next != NULL && q->next->priority >= p)
                q = q->next;
            t->next = q->next;
            q->next = t;
        }
    }

    void delet()
    {
        count--;

        n<T>* t;
        if (f == NULL) return; //if queue is null, return
        else
        {
            t = f;
            f = f->next;
            free(t);
        }
    }

    bool isEmpty() const
    {
        if (f == nullptr)
            return true;
        else
            return false;
    }

    bool dequeue(T& frntEntry) 
    {
        count--;

        if (isEmpty())
            return false;

        n<T>* nodeToDeletePtr = f;
        frntEntry = f->info;
        f = f->next;
       
        // Free memory reserved by the dequeued node
        delete nodeToDeletePtr;
        return true;
    }

    void show() //print queue
    {
       n<T>* ptr;
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
        n<T>* p = f;
        while (p)
        {
            count++;
            p = p->next;
        }


        T* Arr = new T[count];
        p = f;
        for (int i = 0; i < count; i++)
        {
            Arr[i] = p->info;
            p = p->next;
        }
        return Arr;
        //IMPORTANT:
        //toArray function to be used ONLY when drawing the queue items

    }

};


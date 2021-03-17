#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
enum  SortOrder
{
    ASC,    //по возрастанию
    DESC    //по убыванию
};
void swapElements(int& element1, int& element2)
{
    int tempVar = element1;
    element1 = element2;
    element2 = tempVar;
}
bool isElementsSorted(int a, int b, SortOrder sortOrder)
{
    if (sortOrder == ASC)
    {
        return a <= b;
    }
    else
    {
        return a >= b;
    }

}
bool isArraySorted(int* arr, int n, SortOrder sortOrder)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (!isElementsSorted(arr[i], arr[i + 1], sortOrder))
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            return false;
        }
    }


    return true;
}
int* shuffleElements(int* arr, int n)
{
    while (n > 1)
    {
        int r = rand() % n;
        n -= 1;
        swapElements(arr[r], arr[n]);
    }

    return arr;
}
int* bogoSort(int* arr, int n, SortOrder sortOrder)
{
    while (!isArraySorted(arr, n, sortOrder))
    {
        arr = shuffleElements(arr, n);
    }

    return arr;
}
int* fillArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {

        arr[i] = rand() % 100;
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return arr;
}
void printArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int* SelectionSort()
{
    return 0;
}

#ifndef _STOP_WATCH_HPP_
#define _STOP_WATCH_HPP_
#include <cassert> 
#include <chrono>
#include "windows.h"
using namespace std;
class stop_watch {
    std::chrono::high_resolution_clock::time_point last_time_point;
    std::chrono::duration<double> time_duration;
    bool is_running;
public:
    stop_watch() :
        last_time_point{ std::chrono::high_resolution_clock::now() },
        time_duration{ std::chrono::duration<double>::zero() },
        is_running{ false }
    {}
    void start() {
        assert(!is_running); // stop watch is already running
        last_time_point = std::chrono::high_resolution_clock::now();
        time_duration = std::chrono::duration<double>::zero();
        is_running = true;
    }
    void stop() {
        assert(is_running); // stop watch is not running
        auto n = std::chrono::high_resolution_clock::now();
        time_duration = n - last_time_point;
        last_time_point = n;
        is_running = false;
    }
    double hours() {
        return std::chrono::duration_cast<std::chrono::hours>(
            time_duration).count();
    }
    friend std::ostream& operator<<(std::ostream& out, stop_watch sw) {
        std::chrono::hours h = std::chrono::duration_cast<
            std::chrono::hours>(sw.time_duration);
        if (h.count()) { out << h.count() << "h "; sw.time_duration -= h; }
        std::chrono::minutes m = std::chrono::duration_cast<
            std::chrono::minutes>(sw.time_duration);
        if (m.count()) { out << m.count() << "min "; sw.time_duration -= m; }
        std::chrono::seconds s = std::chrono::duration_cast<
            std::chrono::seconds>(sw.time_duration);
        if (s.count()) { out << s.count() << "s "; sw.time_duration -= s; }
        std::chrono::milliseconds ms = std::chrono::duration_cast<
            std::chrono::milliseconds>(sw.time_duration);
        if (ms.count()) { out << ms.count() << "ms "; sw.time_duration -= ms; }
        std::chrono::microseconds us = std::chrono::duration_cast<
            std::chrono::microseconds>(sw.time_duration);
        if (us.count()) { out << us.count() << "us "; sw.time_duration -= us; }
        std::chrono::nanoseconds ns = std::chrono::duration_cast<
            std::chrono::nanoseconds>(sw.time_duration);
        if (ns.count()) { out << ns.count() << "ns "; sw.time_duration -= ns; }
        return out;
    }
};

#endif

int main()
{
    int y = 0;
    while (y == 0)
    {
        srand(time(NULL));
        int yy = 0;
        int sort_order;
        int* arr;
        int size, type_S;
        cout << "Print the size of array (random values in cells)" << endl << "n = ";
        cin >> size;
        arr = new int[size];
        arr = fillArray(arr, size);
        stop_watch sw;
        cout << "Select type of sort:" << endl << "1) Bogosort" << endl << "0) EXIT" << endl;
        cin >> type_S;
        switch (type_S)
        {
        case 1:
        {
            cout << "select the sort order: 1)ascending 2) descending" << endl;

            while (yy == 0)
            {
                cin >> sort_order;            
               
                sw.start();
                if (sort_order == 1)
                {

                    arr = bogoSort(arr, size, ASC);
                    yy = 1;
                }
                else if (sort_order == 2)
                {

                    arr = bogoSort(arr, size, DESC);
                    yy = 1;
                }
            }
            printArray(arr, size);
            sw.stop();
            cout <<endl<< "It took " << sw << endl;
            delete arr;
            cout << endl;
            break;
        }
        case 2:
        {

            break;

        }
        case 0:
            y = 1;
        default:
        {
            cout << endl << "Wrong variant" << endl;
        }
        }
    }
}

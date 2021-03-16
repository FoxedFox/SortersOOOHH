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

}

int main(int argc, char** argv)
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

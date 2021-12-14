#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    printf("[");
    for (i = 0; i < size; i++)
        cout << arr[i] << (i < size - 1 ? "," : "");
    printf("]\n");
}

void insert(int arr[], int position, int value, int size)
{
    if (position < size)
        arr[position] = value;
    else
    {
        cout << "Position out of range\n";
    }
}

int linearsearch(int arr[], int n, int value)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

void deletion(int arr[], int &size, int value)
{
    int pos = linearsearch(arr, size, value);
    if (pos == -1)
    {
        cout << "Element not found";
    }
    int i;
    for (i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size -= 1;
}

int main()
{
    int arr[5] = {21, 5, 96, 33, 12};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "\nOld -> ";
    printArray(arr, length);
    insert(arr, 2, 3, length);
    deletion(arr, length, 21);
    printArray(arr, length);
}
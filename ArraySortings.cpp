#include <iostream>
using namespace std;
int order = 1;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size)
{
    int i;
    printf("[");
    for (i = 0; i < size; i++)
        cout << arr[i] << (i < size - 1 ? "," : "");
    printf("]\n");
}

int linearsearch(int arr[], int n, int value)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (order == 2)
            {
                if (arr[j] < arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
            else
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    int arrarar[5] = {21, 5, 96, 33, 12};
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (order == 2)
            {
                if (arr[j] > arr[min_idx])
                {
                    min_idx = j;
                }
            }
            else
            {
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }
        swap(&arr[min_idx], &arr[i]);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    { // If current element is smaller than the pivot
        if (order == 2)
        {
            if (arr[j] > pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        else
        {
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
        printArray(arr, 5);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        if (order == 2)
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

int main()
{
    int arr[5] = {21, 5, 96, 33, 12};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "\nOld -> ";
    printArray(arr, length);

    cout << "Enter (1) for Ascending or (2) for Descending: ";
    cin >> order;
    cout << (order == 2 ? "\nDescending -> " : "\nAscending -> ");
    
    int find = linearsearch(arr,length,96);
    // bubbleSort(arr,length);
    // selectionSort(arr,length);
    // insertionSort(arr, length);
    // quickSort(arr, 0, length - 1);
    printArray(arr, length);

    return 0;
}

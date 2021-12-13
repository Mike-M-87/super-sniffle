#include <iostream>
#include <stdlib.h>

using namespace std;

class Array
{
private:
    size_t size;
    int *arr;

public:
    void init();
    void add_values();
    void display();
    bool empty();
    int find(int value);
    void insert(int pos, int num);
    void replace(int pos, int num);
    void pop();
    void pop_back();
    int top();
    int back();
    void push(int num);
    void push_back(int num);
    void remove(int pos);
    int length();
    void erase();
};

void Array::init()
{
    cout << "Enter array size: ";
    cin >> size;
    arr = (int *)malloc(size * sizeof(int));
}

void Array::add_values()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void Array::display()
{
    cout << "Printing Array of size " << size << " ";
    cout << "[";
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
        {
            cout << ",";
        }
    }
    cout << "]\n";
}

bool Array::empty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Array::find(int value)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void Array::insert(int pos, int num)
{
    if (pos < size)
    {
        size += 1;
        arr = (int *)realloc(arr, size * sizeof(int));
        for (size_t i = size - 1; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = num;
        printf("Successfully inserted %d at index %d\n", num, pos);
    }
    else
    {
        printf(">>> Insertion Index arguement out of range!\n");
    }
}

void Array::replace(int pos, int num)
{
    if (pos < size)
    {
        arr[pos] = num;
        printf("Successfully replaced %d at index %d\n", num, pos);
    }
    else
    {
        printf(">>> Replacement Index arguement out of range!\n");
    }
}

void Array::pop()
{
    for (size_t i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size -= 1;
    arr = (int *)realloc(arr, size * sizeof(int));
}

void Array::pop_back()
{
    size -= 1;
    arr = (int *)realloc(arr, size * sizeof(int));
}

int Array::top()
{
    return arr[0];
}

int Array::back()
{
    return arr[size - 1];
}

void Array::push(int num)
{
    size += 1;
    arr = (int *)realloc(arr, size * sizeof(int));
    for (size_t i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = num;
}

void Array::push_back(int num)
{
    size += 1;
    arr = (int *)realloc(arr, size * sizeof(int));
    arr[size - 1] = num;
}

void Array::remove(int pos)
{
    if (pos < size)
    {
        for (size_t i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        printf("Successfully deleted index %d\n", pos);
        size -= 1;
        arr = (int *)realloc(arr, size * sizeof(int));
    }
    else
    {
        printf(">>> Deletion Index arguement out of range!\n");
    }
}

int Array::length()
{
    return size;
}

void Array::erase(){
    size = 0;
    arr = (int*)malloc(0);
    cout << "Array destroyed\n";
}

int main(int argc, char const *argv[])
{
    Array k;
    k.init();
    k.add_values();
    k.display();
    cout << "Size = " << k.length() << endl;
    k.erase();
    k.display();
    printf("\n");
    return 0;
}

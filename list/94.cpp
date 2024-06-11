#include <iostream>
#include <cstring> 

using namespace std;

class DynamicArray
{
private:
    int *arr; 
    int size; 

public:
    DynamicArray(size_t size) : size(size)
    {
        arr = new int[size];
    }

    DynamicArray(const DynamicArray &other) : size(other.size)
    {
        arr = new int[other.size];
        memcpy(arr, other.arr, other.size * sizeof(int));
    }

    ~DynamicArray()
    {
        delete[] arr;
    }
};
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
        for (size_t i = 0; i < other.size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }

    ~DynamicArray()
    {
        delete[] arr;
    }
};
#include <iostream>
using namespace std;

class ArrayHeap
{
private:
    int *arr;
    int length = 0;

public:
    ArrayHeap(int *arr, int len)
    {
        this->arr = arr;
        this->length = len;
    }

private:
    int getParentIndex(int child)
    {
        return (child - 1) / 2;
    }

private:
    int getLeftChildIndex(int parent)
    {
        return 2 * parent + 1;
    }

private:
    void swap(int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
private:
    void adjustHeap(int i, int len)
    {
        int left, right, j;
        left = getLeftChildIndex(i);
        while (left <= len)
        {
            right = left + 1;
            j = left;
            if (j < len && arr[left] < arr[right])
            {
                j++;
            }
            if (arr[i] < arr[j])
            {
                swap(i, j);
                i = j;
                left = getLeftChildIndex(i);
            }
            else
            {
                break;
            }
        }
    }
public:
    void sort()
    {
        int last = length - 1;
        for (int i = getParentIndex(last); i >= 0; --i)
        {
            adjustHeap(i, last);
        }
        while (last >= 0)
        {
            swap(0, last--);
            adjustHeap(0, last);
        }
    }
};

int main(void)
{
    int arr[5] = {2, 3, 5, 1, 0};
    ArrayHeap A(arr, 5);
    A.sort();
    for (int i = 0; i < 5; i++)
        cout << arr[i] << ' ';
    return 0;
}
#include <iostream>
using namespace std;

void bubble_sort(int *arr, int len);
void select_sort(int *arr, int len);
void insert_sort(int *arr, int len);
void merge_sort(int *arr, int *temp, int s, int e);
void merge(int *source, int *temp, int s, int mid, int e);
void swap(int &a, int &b);
int main(void)
{
    int arr[5] = {2, 3, 5, 1, 0};
    // bubble_sort(arr, 5);
    // select_sort(arr, 5);
    // insert_sort(arr, 5);
    // int temp[5];
    // merge_sort(arr, temp, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << ' ';
    return 0;
}

void bubble_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] <= arr[j])
                swap(arr[i], arr[j]);
        }
    return;
}

void select_sort(int *arr, int len)
{
    int dex = 0;
    for (int i = 0; i < len; i++)
    {
        dex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[dex] <= arr[j])
                dex = j;
        }
        swap(arr[i], arr[dex]);
    }
    return;
}

void insert_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int value = arr[i];
        int position = i;
        while (position > 0 && arr[position - 1] < value)
        {
            arr[position] = arr[position - 1]; // 所有元素后移一位
            position--;
        }
        arr[position] = value;
    }
}

void merge_sort(int *arr, int *temp, int s, int e)
{
    if (e <= s)
        return;
    int mid = (e + s) >> 1;
    merge_sort(arr, temp, s, mid);
    merge_sort(arr, temp, mid+1, e);
    merge(arr, temp, s, mid, e);
}

void merge(int *source, int *temp, int s, int mid, int e)
{
    int i = s, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= e)
    {
        if (source[i] >= source[j])
            temp[k++] = source[i++];
        else
            temp[k++] = source[j++];
    }
    while (i <= mid)
        temp[k++] = source[i++];
    while (j <= e)
        temp[k++] = source[j++];
    for (int i = s, j = 0; i <= e; i++, j++)
        source[i] = temp[j];
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
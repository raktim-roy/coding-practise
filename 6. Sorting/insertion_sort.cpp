#include <bits/stdc++.h>
using namespace std;

/* When no of elements to be sorted become smaller then
insertion sort is used; otherwise for quickness merge sort
or quick sort is used for larger arrays*/


void InsertionSort(int arr[],int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j]>key; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }

}

void PrintArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {20, 4, 8, 97, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    InsertionSort(arr, size);

    PrintArray(arr, size);
}
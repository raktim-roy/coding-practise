 #include <bits/stdc++.h>

 using namespace std;

 void swap(int *a, int *b)
 {
     int t = *a;
     *a = *b;
     *b = t;
 }

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];      /* pivot */
    int i = (low - 1);          /* Index of smaller element */

    for (int j =  low; j <= high - 1; j++)
    {
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
 void QuickSort(int arr[], int left, int right)
 {
     if(left < right)
     {
         int p = partition(arr, left, right);
         QuickSort(arr, left, p-1);
         QuickSort(arr, p+1, right);

     }
 }
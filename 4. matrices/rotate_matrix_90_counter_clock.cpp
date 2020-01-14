#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

/* After transpose we swap the elements of column
one by one for finding left rotation of the matrix
by 90 degree */

void reverseColumns(int arr[R][C])
{
    for(int i = 0; i < C; i++)
    {
        for(int j = 0, k = C - 1; j <k; j++, k--)
        {
            swap(arr[j][i], arr[k][i]);
        }
    }
}

/* Transpose of a matrix */
void transpose(int arr[R][C])
{
    for(int i = 0; i < R; i++)
        for(int j = i; j < C; j++)
            swap(arr[i][j], arr[j][i]);
}

/* Function to print matrix */
void printMatrix(int arr[R][C])
{
    for (int i = 0; i <R; i++){
        for (int j = 0; j <C; j++)
            cout << arr[i][j] <<" ";
        cout << endl;
    }
}

/* Function to rotate matrix anticlockwise
by 90 degrees */
void rotate90(int arr[R][C])
{
    transpose(arr);
    reverseColumns(arr);
}

/* Driver code */
int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16} };

    rotate90(arr);
    printMatrix(arr);
    return 0;
}
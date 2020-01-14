#include <bits/stdc++.h>

using namespace std;
#define R 3
#define C 3

void transpose(int matrix[R][C])
{
    for(int i =0; i < R; i++)
    {
        for(int j = i+1; j <C; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
}

int main()
{
    int a[R][C]={{1, 2, 3},{4,5,6}, {7,8,9}};
    transpose(a);
    for (int i = 0; i < R; i++) 
    { 
        for (int j = 0; j < C; j++) 
           printf("%d ", a[i][j]); 
        printf("\n"); 
    }

}
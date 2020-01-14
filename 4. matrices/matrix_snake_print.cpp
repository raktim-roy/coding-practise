#include <bits/stdc++.h>
#define R 3
#define C 6
using namespace std;

void print_array_snake(int arr[R][C])
{
    for(int i = 0; i < R; i++)
    {
        if (i%2 == 0)
        {
            for(int j = 0; j < C; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for(int j = C-1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
        }

        cout << endl;
        
    }

}

int main()
{
    int a[R][C] = { { 1, 2, 3, 4, 5, 6 }, 
					{ 7, 8, 9, 10, 11, 12 }, 
					{ 13, 14, 15, 16, 17, 18 } };
    print_array_snake(a);
    return 0;
}



/* Equilibrium point means the sum preceding the point
equals to the sum following the point */
#include <bits/stdc++.h>

using namespace std;

int Eqpoint(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int l_sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(l_sum == sum - arr[i]) return i;
        l_sum += arr[i];
        sum -= arr[i]; /* sum is now right sum for index i */
    }

    return -1;

}

int main()
{
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout << "First equilibrium index is " << Eqpoint(arr, arr_size);
    return 0;
}
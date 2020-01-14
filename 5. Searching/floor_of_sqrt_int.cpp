#include <bits/stdc++.h>

using namespace std;

int floorSqrt(int x)
{
    /* Base cases */
    if ( x == 0 || x == 1)
        return x;
    
    /* Do binary search for floor(sqrt(x)) */
    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = ( start + end ) / 2;

        /* If x is perfect square */
        if ( mid * mid == x)
            return mid;
        // Since we need floor, we update answer when mid*mid is 
		// smaller than x, and move closer to sqrt(x)
        if (mid * mid <x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
        
        return ans;
    }

    
}

// Driver program 
int main() 
{	 
	int x = 11; 
	cout << floorSqrt(x) << endl; 
	return 0; 
} 
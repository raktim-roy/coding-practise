#include <iostream>

using namespace std;

/* tail recursive has less stack overload, hence faster execution*/
/* tail means after the recursive call there is nothing else */

#define tail_recursive_optimized
#ifdef unoptimized
void fun(int n)
{
    if (n == 0) return;
    fun(n-1);
    cout << n << " ";
}

#endif

#ifdef tail_recursive_optimized
void fun(int n, int k = 1)
{
    if (n == 0) return;
    cout << k << " ";
    fun(n-1, k+1);
}

#endif

int main()
{
    fun(5);
}
/* problem: Find sum of digits of a n digit number */


#include <iostream>

using namespace std;

int fun(int n)
{
    if ( n < 10) return n;

    return fun(n/10) + n %10;
}



int main()
{
    int ans = fun(253);
    cout <<  ans << endl;
}
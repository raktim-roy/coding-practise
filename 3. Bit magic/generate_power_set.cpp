#include <bits/stdc++.h>
using namespace std;

void PrintPowerSet(char* set, int set_size)
{
    /* set size of power set of a set with size
    n is equal to (2**n - 1) */
    uint32_t pow_set_size = pow(2, set_size);
    int counter, j;

    /*Run counter from 0000...0 to 1111...1 */
    for(counter = 0; counter < pow_set_size; counter++)
    {
        for(j = 0; j < set_size; j++)
        {
            /* check if jth bit in the counter is set
            if set then print the jth element from set */
            if(counter & (1 <<j))
                cout << set[j];
        }

        cout << endl;
    } 
}

int main()
{
    char set[] = {'a', 'b', 'c'};
    PrintPowerSet(set, 3);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// The difference gives the result that how many variables of type of x can be stored in that amount of memory which will obviously be 1 for the type x (for incrementing it with 1 and taking the difference is what we’ve done). Typecasting it into char* and taking the difference will tell us how many variables of type char can be stored in the given memory space (the difference). Since each char requires the only 1B of memory, therefore (amount of memory)/1 will give the number of bytes between two successive memory locations of the type of the variable passed on to the macro and hence the amount of memory that the variable of type x requires.
#define MY_SIZE_OF(x)   (size_t)(((char *)(&x+1)) - ((char *)(&x)))

int main()
{
    char var[] = "test_str";
    cout << "size of variable using sizeof operator " << sizeof(var) << endl;
    cout << "size of variable using mysizeof operator " << MY_SIZE_OF(var) << endl;
    return 0;
}

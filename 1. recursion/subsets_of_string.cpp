#include <bits/stdc++.h>

using namespace std;
/* str: stores input string
curr: stores current subset
index: index in current subset, curr */

void powerSet(string str, int index = 0, string curr = " ")
{
    int n = str.length();

    /*base case */
    if (index == n)
    {
        cout << curr << endl;
        return;
    }

    // Two cases for every character 
    // (i) We consider the character 
    // as part of current subset 
    // (ii) We do not consider current 
    // character as part of current 
    // subset

    powerSet(str, index + 1, curr + str[index]); 
    powerSet(str, index + 1, curr); 
} 

int main() 
{ 
    string str = "abc"; 
    powerSet(str); 
    return 0; 
}
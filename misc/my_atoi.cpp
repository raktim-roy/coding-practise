#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int myAtoi_simple(char* str) {
    int res = 0, i = 0, sign = 1;
    
    while(str[i] == ' ') {
        i++;
    }
    
    while(str[i] != '\0') {
        
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        
        res = res * 10 + (str[i++] - '0');
    }
    return res * sign;
}


int myAtoi_boundary_check(char *str) {
    int res = 0, i = 0, sign = 1;
    
    while(str[i] == ' ') {
        i++;
    }
    
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    
    
    while(str[i] >= '0' && str[i] <= '9') {
        
        // The check value is 7 because INT_MAX: 2147483647
	// INT_MAX/10 = 214748364. Multiplying by 10 will give 2147483640.
	// Now if str[i] = '8' then '8'-'0' = 8 which will be greater than 2147483647
        if(res > INT_MAX/10 || (res == INT_MAX/10 && str[i] - '0' > 7)) {
            if (sign == 1) 
                return INT_MAX;
            else
                return INT_MIN;
        }
        res = res * 10 + (str[i++] - '0');
    }
    return res * sign;
}



int main()
{
    char str1[] = "-123";
    
    int val = atoi(str1);
    
    cout << "String value: " << str1 << endl;
    cout << "Integer value: " << val << endl;
    
    int val2 = myAtoi_simple(str1);
    cout << "my atoi Integer value: " << val2 << endl;

    return 0;
}

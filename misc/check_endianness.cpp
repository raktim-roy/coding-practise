#include <iostream>
using namespace std;

int main()
{
    uint16_t x = 0x1;
    
    char *ptr = (char *) &x;
    
    // cout << "First Byte " << hex << (int)(unsigned char)*ptr << endl;
    if (*ptr == 0x1 ) {
        cout<< "little endian" << endl;
    } else {
        cout << "big endian" << endl;
    }

    return 0;
}

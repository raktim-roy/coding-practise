#include <bits/stdc++.h>
#include <arpa/inet.h>


int main()
{
    uint32_t num = 0x1234abcd;
    
    uint32_t converted = 0;
    
    converted |= (num & 0x000000ff) << 24;
    converted |= (num & (0x000000ff << 8)) << 8;
    converted |= (num & (0x000000ff << 16)) >> 8;
    converted |= (num & (0x000000ff << 24)) >> 24;
    std::cout << std::hex << converted << std::endl;
    std::cout << std::hex << htonl(num) << std::endl;
    return 0;
}

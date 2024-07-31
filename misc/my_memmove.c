#include <stdio.h>
#include <stdint.h>
#include <string.h>

void* my_memmove(void *dst, const void *src, size_t n) {
    uint8_t* to = (uint8_t*)src;
    uint8_t* from = (uint8_t*)dst;
    
    if (to == from || n == 0) return dst;
    
    if ((to > from) && (to - from) < (int)n) {
        /* to overlaps with from */
	/*  <from......>         */
	/*         <to........>  */
	/* copy in reverse, to avoid overwriting from */
        for (int i = n-1; i >=0; i--) {
            to[i] = from[i];
        }
        
        return dst;
    }
    
    if ((from > to) && (from - to) < (int)n) {
        /* to overlaps with from */
	/*        <from......>   */
	/*  <to........>         */
	/* copy forwards, to avoid overwriting from */
        for (int i = 0; i < n; i++) {
            to[i] = from[i];
        }
        return dst;
    }
    
    memcpy(dst, src, n);
    
    return dst;
}

int main()
{
    unsigned char str1[] = "raktim is";
    unsigned char str2[] = "bad";
    
    memmove(str1, str2, sizeof(str2));
    printf("%s\n", str1);
    
    strncpy(str1, "stupid", 7);
     printf("%s\n", str1);
    my_memmove(str1, str2, sizeof(str2));
    printf("%s\n", str1);
    
    return 0;
}

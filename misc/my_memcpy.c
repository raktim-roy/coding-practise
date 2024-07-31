#include <stdio.h>
#include <string.h>
#include <stdint.h>

void *my_memcpy(void * dst, const void * src, size_t n) {
    
    if (dst == NULL || src == NULL) return NULL;
    
    uint8_t *dst_ptr = (uint8_t *)dst;
    uint8_t *src_ptr = (uint8_t *)src;
    
    for (int i = 0; i < n; i++) {
        *(dst_ptr + i) = (src_ptr + i)
    }
    return dst_ptr;
}


int main() {
	
	char src[] = "stupid";
	char dst[] = "raktim is";
	memcpy(dst, src, sizeof(dst));

	printf("%s\n", dst);
	
	char *res = (char *)my_memcpy(destination, src, sizeof(src));
    	printf("%s\n", res)
	return 0;
}

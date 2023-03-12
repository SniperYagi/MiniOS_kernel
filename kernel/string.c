#include <stdint.h>
#include <string.h>


int strlen(const char *str) {
    uint32_t length = 0;

    while(*str) {
        length++;
    }

    return length;
}

char *strcpy(char *dst, const char *str) {
    char *ptr = dst;
    
    while(*str) {
        *ptr++ = *str++;
    }

    return dst;
}

char *strcat(char *dst, const char *str) {
    char *ptr = dst;
    uint32_t length = strlen(str);

    strcpy(ptr, str);
    ptr[length + 1] = '\0';

    return dst;
}

void memcpy(void *dst, void *src, uint32_t length) {
    char *ptr = dst;
    char *_src = src;
    uint32_t copy = 0;

    while(copy < length) {
        *ptr++ = *_src++;
        copy++;
    }
}

void memset(void *dst, uint32_t bit, uint32_t length) {
    char *ptr = dst;
    uint32_t copy = 0;

    while(copy < length) {
        *ptr++ = bit;
        copy++;
    }
}
#include <stdint.h>


int strlen(const char *str);
char *strcpy(char *dst, const char *str);
char *strcat(char *dst, const char *str);

void memcpy(void *dst, void *src, uint32_t length);
void memset(void *dst, uint32_t bit, uint32_t length);
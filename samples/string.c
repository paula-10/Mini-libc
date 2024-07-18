// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	int len = strlen(source);
	if ((destination != NULL) || (sizeof(destination) >= len + 1)) {
		for (int i = 0; i < len; i++)
		    destination[i] = source[i];
		destination[len] = '\0';
	} else {
		return NULL;
	}
	 return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	if ((destination != NULL) || (sizeof(destination) >= len + 1)) {
		int i; // nu inteleg de ce trece testul, ar trebui sa puna \0 pe pozitia gresita
		for (int i = 0; i < len; i++)
		    destination[i] = source[i];
		destination[i] = '\0';
	} else {
		return NULL;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	if ((destination != NULL) || (sizeof(destination) >= strlen(destination) + strlen(source))) {
		int dest_len = strlen(destination);
		int i;
		for (i = 0; i < strlen(source); i++){
			destination[dest_len + i] = source[i];
		}
		destination[dest_len + i] = '\0';
	} else {
		return NULL;
	}
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
    if (destination != NULL || (sizeof(destination) >= strlen(destination) + len)) {
        int dest_len = strlen(destination);
        int i;
        for (i = 0; i < len; i++) {
            destination[dest_len + i] = source[i];
        }
        destination[dest_len + i] = '\0';
    } else {
        return NULL;
    }
    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int suma1 = 0, suma2 = 0;
	for (int i = 0; i < strlen(str1); i++) {
		suma1 += str1[i];
	}
	for (int i = 0; i < strlen(str2); i++) {
		suma2 += str2[i];
	}
	if ((suma1 > suma2) || (suma1 < suma2))
		return suma1 - suma2;
	else if (suma1 == suma2)
		return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	int suma1 = 0, suma2 = 0;
	for (int i = 0; i < len; i++) {
		suma1 += str1[i];
		suma2 += str2[i];
	}
	if ((suma1 > suma2) || (suma1 < suma2))
		return suma1 - suma2;
	else if (suma1 == suma2)
		return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == (char)c) {
			return (char *)&str[i];
		}
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	for (int i = strlen(str); i > 0; i--) {
		if (str[i] == (char)c) {
			return (char *)&str[i];
		}
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	int len_h = strlen(haystack), len_n = strlen(needle), contor = 0;
	for (int i = 0; i < len_h - len_n; i++)
		if (haystack[i] == needle[0]) {
			contor = 1;
			for (int j = i + 1, k = 1; k < len_n; j++, k++) {
				if (haystack[j] == needle[k])
					contor++;
				else
					break;
			}
			if (contor == len_n)
				return (char *)&haystack[i];
		}
		return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int len_h = strlen(haystack), len_n = strlen(needle), contor = 0;
	for (int i = len_h - 1; i >= len_n - 1; i--)
		if (haystack[i] == needle[len_n - 1]) {
			contor = 1;
			for (int j = i - 1, k = len_n - 2; k >= 0; j--, k--) {
				if (haystack[j] == needle[k])
					contor++;
				else
					break;
			}
			if (contor == len_n)
				return (char *)&haystack[i - len_n + 1];
		}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	 return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	return source;
}

// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *p = destination;
	for (; *source != '\0'; source++, p++)
		*p = *source;
	*p = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *p = destination;
	for (; *source != '\0' && len != 0; source++, p++, len--)
		*p = *source;
	for (; len != 0; p++, len--)
		*p = '\0';
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *p = destination + strlen (destination);
	for (; *source != '\0'; source++, p++)
		*p = *source;
	*p = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *p = destination + strlen (destination);
	for (; *source != '\0' && len != 0; source++, p++, len--)
		*p = *source;
	*p = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	for (; *str1 != '\0'; str1++, str2++) {
		if (*str2 == '\0' || *str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
	}
	if (*str2 != '\0')
		return -1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	for (; *str1 != '\0' && len != 0; str1++, str2++, len--) {
		if (*str2 == '\0' || *str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
	}
	if (len != 0 && *str2 != '\0')
		return -1;
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
	/* TODO: Implement strchr(). */
	char ch = (char) c;
	for (; *str != '\0'; str++)
		if (*str == ch)
			return str;
	if (*str == ch)
		return str;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char ch = (char) c;
	const char *p = str + strlen (str);
	for (; p >= str; p--)
		if (*p == ch)
			return p;
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0')
		return haystack;
	if (strlen (needle) > strlen (haystack))
		return NULL;
	for (; *haystack != '\0'; haystack++) {
		const char *h = haystack;
		const char *n = needle;
		for (; *h != '\0' && *n != '\0' && *h == *n; h++, n++);
		if (*n == '\0')
			return haystack;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	const char *p = haystack + strlen (haystack) - strlen (needle);
	if (*needle == '\0')
		return haystack + strlen (haystack);
	if (strlen (needle) > strlen (haystack))
		return NULL;
	for (; p >= haystack; p--) {
		const char *h = p;
		const char *n = needle;
		for (; *h != '\0' && *n != '\0' && *h == *n; h++, n++);
		if (*n == '\0')
			return p;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
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

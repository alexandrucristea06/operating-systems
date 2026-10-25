// SPDX-License-Identifier: BSD-3-Clause
#define _GNU_SOURCE

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0)
		return NULL;
	void *p = mmap (NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (p == MAP_FAILED)
		return NULL;
	if (mem_list_add (p, size) < 0) {
		munmap (p, size);
		return NULL;
	}
	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return NULL;
	void *p = malloc (total);
	if (p != NULL)
		memset (p, 0, total);
	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL)
		return;
	struct mem_list *block = mem_list_find (ptr);
	if (block == NULL)
		return;
	munmap (block->start, block->len);
	mem_list_del (ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL)
		return malloc (size);
	if (size == 0) {
		free (ptr);
		return NULL;
	}
	struct mem_list *block = mem_list_find (ptr);
	if (block == NULL)
		return NULL;
	void *p = malloc (size);
	if (p == NULL)
		return NULL;
	size_t copy = block->len < size ? block->len : size;
	memcpy (p, ptr, copy);
	free (ptr);
	return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return NULL;
	return realloc (ptr, total);
}

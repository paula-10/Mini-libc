// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
	int ret = mem_list_add(ptr, size);
    if (ret == -1) {
        munmap(ptr, size);
        return NULL;
    }
    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);
    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }
    return ptr;
}

void free(void *ptr)
{
	if (ptr == NULL)
		return;
	struct mem_list *item = mem_list_find(ptr);
	size_t len_item = item->len;
    if (item != NULL) {
		mem_list_del(item->start);
		munmap(ptr, len_item);
    }
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
		return malloc(size);
	} else if (size == 0) {
        free(ptr);
        return NULL;
    }
    void *new = malloc(size);
    if (new == NULL) {
        return NULL;
    }
	struct mem_list *item = mem_list_find(ptr);
	size_t len = item->len;
	size_t new_size;
	if (size <= len) {
		new_size = size;
    } else {
		new_size = len;
    }
    memcpy(new, ptr, new_size);
    free(ptr);
    return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
	if (ptr == NULL) {
		return malloc(total_size);
	} else if (total_size == 0) {
        free(ptr);
        return NULL;
    }

	void *new = malloc(total_size);
    if (new == NULL) {
        return NULL;
    }
	struct mem_list *item = mem_list_find(ptr);
	size_t len = item->len;
	size_t new_size;
	if (size <= len) {
		new_size = size;
    } else {
		new_size = len;
    }
    memcpy(new, ptr, new_size);
    free(ptr);

	return new;
}

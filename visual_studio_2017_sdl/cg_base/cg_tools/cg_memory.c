#include "cg_memory.h"
#include <malloc.h>

void* cg_malloc(uint32_t size)
{
	return malloc(size);
}

void cg_free(void* point)
{
	free(point);
}

#ifndef _CG_MEMORY_H_
#define _CG_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

void* cg_malloc(uint32_t size);
void  cg_free(void* point);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_MEMORY_H_

#ifndef _CG_ERROR_H_
#define _CG_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include <stdint.h>


/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef int32_t cg_error_t;

typedef enum {
        cg_err_success = 0x00,
        cg_err_fial = 0x01,
}cg_error_generic;

typedef enum {
        cg_err_area_exist = 0x10,
        cg_err_area_not_exist = 0x11,
        cg_err_area_intersect = 0x12,
}cg_error_area;



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _CG_ERROR_H_

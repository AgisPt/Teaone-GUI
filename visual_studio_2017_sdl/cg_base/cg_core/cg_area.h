#ifndef _CG_AREA_H_
#define _CG_AREA_H_

/************************************************************************/
/* Include                                                              */
/************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include "../cg_log/cg_error.h"
#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* typedef                                                              */
/************************************************************************/
typedef int16_t cg_ruler_t;
typedef int32_t cg_addr_t;

typedef struct _cg_point
{
        cg_ruler_t x;
        cg_ruler_t y;
}cg_point_t;

typedef struct _cg_area
{
        cg_ruler_t    x;
        cg_ruler_t    y;
        cg_ruler_t    x_width;
        cg_ruler_t    y_width;
}cg_area_t;



/************************************************************************/
/* static inline functions                                              */
/************************************************************************/
static inline cg_ruler_t cg_area_get_width(cg_area_t* area)
{
        return area->x_width;
}

static inline cg_error_t cg_area_isexist(cg_area_t* area)
{
        if (area->x_width <= 1 || area->y_width <= 1)
        {
                return cg_err_area_not_exist;
        }
        return cg_err_area_exist;
}
/************************************************************************/
/* global functions                                                     */
/************************************************************************/
bool  cg_area_intersect(cg_area_t* rest, cg_area_t* a1, cg_area_t* a2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _CG_AREA_H_

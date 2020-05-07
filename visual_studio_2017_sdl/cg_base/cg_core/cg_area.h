#ifndef _CG_AREA_H_
#define _CG_AREA_H_

/************************************************************************/
/* Include                                                              */
/************************************************************************/
#include <stdbool.h>
#include <stdint.h>

#include "../cg_log/cg_error.h"
#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* typedef                                                              */
/************************************************************************/
typedef int16_t cg_ruler_t;
typedef int32_t cg_addr_t;

typedef struct cg_point_s cg_point_t;
typedef struct cg_rect_s  cg_rect_t;

/************************************************************************/
/* struct                                                               */
/************************************************************************/
struct cg_point_s
{
	cg_ruler_t x, y;
};

struct cg_rect_s
{
	cg_ruler_t x0, y0, x1, y1;
};

/************************************************************************/
/* static inline functions                                              */
/************************************************************************/
static inline cg_ruler_t cg_area_rect_get_width(cg_rect_t* rect)
{
	return rect->x1 - rect->x0;
}

static inline cg_error_t cg_area_isexist(cg_rect_t* rect)
{
	if (CG_MATH_ABS(rect->x0 - rect->x1) <= 1 ||
	    CG_MATH_ABS(rect->y0 - rect->y1) <= 1) {
		return cg_err_area_not_exist;
	}
	return cg_err_area_exist;
}
/************************************************************************/
/* global functions                                                     */
/************************************************************************/
bool cg_area_intersect(cg_rect_t* rest, cg_rect_t* rect1, cg_rect_t* rect2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_AREA_H_

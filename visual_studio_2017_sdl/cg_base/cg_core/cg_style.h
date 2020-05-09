#ifndef _CG_STYLE_H_
#define _CG_STYLE_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "cg_area.h"
#include "cg_color.h"
#include <stdbool.h>

/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef bool              cg_bool_t;
typedef struct cg_style_s cg_style_t;

/************************************************************************/
/* struct                                                               */
/************************************************************************/
struct cg_style_s
{
	cg_color_t color;
	cg_ruler_t radius;
	cg_ruler_t wdith;
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_STYLE_H_

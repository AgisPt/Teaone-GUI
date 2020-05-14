#ifndef _CG_DRAW_POINT_H_
#define _CG_DRAW_POINT_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../cg_core/cg_style.h"
#include "../cg_log/cg_error_t.h"

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_error_t cg_draw__point(cg_point_t* point,
                          cg_rect_t*  mask,
                          cg_style_t* style,
                          cg_opa_t    opa);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_DRAW_POINT_H_

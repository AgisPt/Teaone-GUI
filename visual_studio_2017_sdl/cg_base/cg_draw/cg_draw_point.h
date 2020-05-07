#ifndef _CG_DRAW_POINT_H_
#define _CG_DRAW_POINT_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../cg_base/cg_core/cg_style.h"

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_error_t cg_draw_ground_point(cg_point_t* point,
                                cg_rect_t*  mask,
                                cg_style_t* style,
                                cg_alpha_t  alpha);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_DRAW_POINT_H_

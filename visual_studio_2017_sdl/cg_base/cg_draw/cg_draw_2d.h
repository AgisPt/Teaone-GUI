#ifndef _CG_DRAW_2D_H_
#define _CG_DRAW_2D_H_

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
cg_error_t cg_draw__fill_rect(cg_rect_t*  rect,
                              cg_rect_t*  mask,
                              cg_style_t* style,
                              cg_opa_t    opa);

cg_error_t cg_draw__rect(cg_rect_t*  rect,
                         cg_rect_t*  mask,
                         cg_style_t* style,
                         cg_opa_t    opa);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_DRAW_2D_H_

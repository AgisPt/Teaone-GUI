#ifndef _CG_DRAW_H_
#define _CG_DRAW_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../cg_core/cg_style.h"
#include "cg_draw_drv.h"

extern cg_error_t (*const set_pixel)(cg_ruler_t x,
                                     cg_ruler_t y,
                                     cg_rect_t* mask,
                                     cg_color_t color,
                                     cg_opa_t   opa);

extern cg_error_t (*const fill_pixel)(cg_rect_t* area,
                                      cg_rect_t* mask,
                                      cg_color_t color,
                                      cg_opa_t   opa);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_DRAW_H_

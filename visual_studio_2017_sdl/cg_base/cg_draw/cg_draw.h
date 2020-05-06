#ifndef _CG_DRAW_H_
#define _CG_DRAW_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../cg_core/cg_style.h"
#include "cg_draw_drv.h"

extern void (* const set_pixel)(cg_ruler_t x, cg_ruler_t y, cg_area_t* mask, cg_color_t color, cg_alpha_t alpha);
extern void (* const fill_pixel)(cg_area_t* area, cg_area_t* mask, cg_color_t color, cg_alpha_t alpha);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _CG_DRAW_H_

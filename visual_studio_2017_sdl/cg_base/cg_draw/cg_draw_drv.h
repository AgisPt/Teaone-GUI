#ifndef _CG_DRAW_DRV_H_
#define _CG_DRAW_DRV_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../../cg_base/cg_core/cg_style.h"
#include "../../cg_drivers/display/cg_hal_display.h"

//************************************
// Method:    cg_draw_vpx
// FullName:  cg_draw_vpx
// Access:    public
// Returns:   void
// Parameter: cg_ruler_t x - Absolute coordinate x
// Parameter: cg_ruler_t y - Absolute coordinate y
// Parameter: cg_area_t mask - Displayable area
// Parameter: cg_color_t color - Draw color
// Parameter: cg_alpha_t alpha - Display transparency
//************************************
cg_error_t cg_draw_drv_vpx(cg_ruler_t x,
                           cg_ruler_t y,
                           cg_rect_t* mask,
                           cg_color_t color,
                           cg_alpha_t alpha);

cg_error_t cg_draw_drv_vfill(cg_rect_t* rect,
                             cg_rect_t* mask,
                             cg_color_t color,
                             cg_alpha_t alpha);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_DRAW_DRV_H_

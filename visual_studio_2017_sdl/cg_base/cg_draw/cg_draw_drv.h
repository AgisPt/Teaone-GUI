#ifndef _CG_DRAW_DRV_H_
#define _CG_DRAW_DRV_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../../cg_drivers/display/cg_hal_display.h"
#include "../../cg_base/cg_core/cg_style.h"

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
void cg_draw_drv_vpx(cg_ruler_t x, cg_ruler_t y, cg_area_t* mask, cg_color_t color, cg_alpha_t alpha);
void cg_draw_drv_vfill(cg_area_t *aims, cg_area_t *mask, cg_color_t color, cg_alpha_t alpha);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _CG_DRAW_DRV_H_

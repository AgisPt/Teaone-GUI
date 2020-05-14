#ifndef _CG_HAL_DISPLAY_H_
#define _CG_HAL_DISPLAY_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../../cg_base/cg_core/cg_area.h"
#include "../../cg_base/cg_core/cg_color.h"
#include "../../cg_base/cg_log/cg_error_t.h"
/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef struct display_driver_s cg_disp_drv_t;
typedef struct display_s        cg_disp_t;

typedef cg_error_t (*disp_drv_refresh)(cg_rect_t* area, cg_color_t* frame_p);
typedef cg_error_t (*disp_drv_fill)(cg_rect_t* area, cg_color_t color);

struct display_driver_s
{
	disp_drv_refresh disp_refresh;
	disp_drv_fill    disp_fill;
};

struct display_s
{
	cg_disp_drv_t    dirver;
	struct _display* next;
};

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
void cg_hal_disp_get_default(cg_disp_drv_t* driver);

cg_disp_t* cg_hal_disp_create_handle(cg_disp_drv_t* reg);

cg_error_t cg_hal_disp_refresh(cg_rect_t* area, cg_color_t* frame_p);

cg_error_t cg_hal_disp_fill(cg_rect_t* area, cg_color_t color);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_HAL_DISPLAY_H_

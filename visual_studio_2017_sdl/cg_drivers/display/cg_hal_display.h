#ifndef _CG_HAL_DISPLAY_H_
#define _CG_HAL_DISPLAY_H_


#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../../cg_base/cg_core/cg_color.h"

/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef struct _display_driver
{
    void(*disp_refresh)(int32_t x1, int32_t y1, int32_t x2, int32_t y2, cg_color_t* frame_p);
    void(*disp_fill)(int32_t x1, int32_t y1, int32_t x2, int32_t y2, cg_color_t color);
}cg_disp_drv_t;

typedef struct _display 
{
    cg_disp_drv_t dirver;
    struct _display* next;
}cg_disp_t;



/************************************************************************/
/* global functions                                                     */
/************************************************************************/
void cg_hal_disp_get_default(cg_disp_drv_t* driver);

cg_disp_t* cg_hal_disp_create_handle(cg_disp_drv_t* reg);

void cg_hal_disp_refresh(int32_t x1, int32_t y1, int32_t x2, int32_t y2, cg_color_t* frame_p);

void cg_hal_disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, cg_color_t color);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _CG_HAL_DISPLAY_H_

/************************************************************************/
/* Include                                                              */
/************************************************************************/
#include <stdbool.h>

#include "cg_vfb.h"
#include "cg_conf.h"

#include "../cg_log/cg_log.h"
#include "../../cg_drivers/display/cg_hal_display.h"
/************************************************************************/
/* Define                                                               */
/************************************************************************/
#if CG_MULTI_BUFFER_ENABLE == 0
static uint8_t  vfb[CG_VRAM_SIZE_BYTES];
static cg_vfb_t cg_vfb = {.frame_p = (cg_color_t *)vfb};
#elif CG_MULTI_BUFFER_ENABLE == 1
#   if CG_MULTI_BUFFER == 2
static uint8_t  vfb[2][CG_VRAM_SIZE_BYTES];
static cg_vfb_t cg_vfb[2] = {{.frame_p = (cg_color_t*)vfb[0]},
                             {.frame_p = (cg_color_t*)vfb[1]}};
#   elif CG_MULTI_BUFFER == 3
static uint8_t  vfb[3][CG_VRAM_SIZE_BYTES];
static cg_vfb_t cg_vfb[3] = {{.frame_p = (cg_color_t*)vfb[0]},
                             {.frame_p = (cg_color_t*)vfb[1]},
                             {.frame_p = (cg_color_t*)vfb[2]}};
#   else
    #error Invalid CG_MULTI_BUFFER in cg_conf.h, Can only be set to 1, 2, 3.
#   endif // CG_MULTI_BUFFER == 2
#endif // CG_MULTI_BUFFER_ENABLE == 0

/************************************************************************/
/* Static variables                                                     */
/************************************************************************/
static char vfb_active = 0;
static bool vfb_refreshing = false;

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_vfb_t* cg_vfb_get(void)
{
#if CG_MULTI_BUFFER_ENABLE == 0
    while (vfb_refreshing);
    return &cg_vfb;
#else
    return &cg_vfb[vfb_active];
#endif // CG_MULTI_BUFFER_ENABLE == 0
}

cg_vfb_t* cg_vfb_get_active(void)
{
#if CG_MULTI_BUFFER_ENABLE == 0
    return &cg_vfb;
#else
    return &cg_vfb[vfb_active];
#endif // CG_MULTI_BUFFER_ENABLE == 0
}

void cg_vfb_refresh(void)
{
    cg_vfb_t* active = cg_vfb_get();
    if (NULL == active)
    {
        CG_LOG_ERROR("Pointer is empty!");
        return;
    }
#if CG_MULTI_BUFFER_ENABLE == 0
    /* 需要修改的部分进行刷新 */
    cg_hal_disp_refresh(active->area.x1, active->area.y, active->area.x2, active->area.y_width, active->frame_p);
#else

#endif // CG_MULTI_BUFFER_ENABLE == 0
}





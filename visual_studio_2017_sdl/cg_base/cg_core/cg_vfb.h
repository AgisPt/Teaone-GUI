#ifndef _CG_VFB_H_
#define _CG_VFB_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* Include                                                              */
/************************************************************************/
#include "cg_area.h"
#include "cg_color.h"
#include "../../cg_drivers/display/cg_hal_display.h"
/************************************************************************/
/* Define                                                               */
/************************************************************************/
#define CG_VRAM_SIZE_BYTES  ((CG_HOR_PX) * (CG_VER_PX) * (CG_COLOR_DEPTH))

/************************************************************************/
/* Typedef                                                              */
/************************************************************************/
typedef struct _cg_vfb
{
    cg_area_t area;
    cg_color_t* frame_p;
}cg_vfb_t;

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_vfb_t* cg_vfb_get(void);

cg_vfb_t* cg_vfb_get_active(void);

void cg_vfb_refresh(void);




#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _CG_VFB_H_

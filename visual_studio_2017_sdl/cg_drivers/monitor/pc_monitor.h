#ifndef _PC_MONITOR_H_
#define _PC_MONITOR_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../../cg_base/cg_core/cg_color.h"
#include "../../cg_base/cg_core/cg_area.h"



/************************************************************************/
/* global functions                                                     */
/************************************************************************/
void pc_monitor_init(void);
void pc_monitor_refresh(cg_area_t* area, cg_color_t* frame_p);
void pc_monitor_fill(cg_area_t* area, cg_color_t color)
;
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _PC_MONITOR_H_

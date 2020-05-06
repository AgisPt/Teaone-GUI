#ifndef _CG_DRAW_LINE_H_
#define _CG_DRAW_LINE_H_

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
void cg_draw_ground_line(cg_point_t* point1, cg_point_t* point2, cg_area_t* mask, cg_style_t* style, cg_alpha_t alpha);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _CG_DRAW_LINE_H_

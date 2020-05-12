#ifndef _CG_H_
#define _CG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <SDL.h>
#include <stdio.h>

#include "cg_init.h"

#include "cg_base/cg_draw/cg_draw_2d.h"
#include "cg_base/cg_draw/cg_draw_line.h"
#include "cg_base/cg_draw/cg_draw_point.h"

#include "cg_base/cg_core/cg_vfb.h"

extern void cg_gui_main(void);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_H_

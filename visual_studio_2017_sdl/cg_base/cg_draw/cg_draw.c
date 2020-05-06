#include "cg_draw.h"


void (* const set_pixel)(cg_ruler_t x, cg_ruler_t y, cg_area_t* mask, cg_color_t color, cg_alpha_t alpha) = cg_draw_drv_vpx;
void (* const fill_pixel)(cg_area_t* area, cg_area_t* mask, cg_color_t color, cg_alpha_t alpha) = cg_draw_drv_vfill;


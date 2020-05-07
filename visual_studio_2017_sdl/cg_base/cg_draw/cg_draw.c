#include "cg_draw.h"

cg_error_t (*const set_pixel)(cg_ruler_t x,
                              cg_ruler_t y,
                              cg_rect_t* mask,
                              cg_color_t color,
                              cg_alpha_t alpha) = cg_draw_drv_vpx;

cg_error_t (*const fill_pixel)(cg_rect_t* area,
                               cg_rect_t* mask,
                               cg_color_t color,
                               cg_alpha_t alpha) = cg_draw_drv_vfill;

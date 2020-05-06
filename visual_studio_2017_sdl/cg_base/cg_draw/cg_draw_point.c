#include "cg_draw_point.h"
#include "cg_draw.h"
#include "../cg_core/cg_vfb.h"

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
void cg_draw_ground_point(cg_point_t* point, cg_area_t* mask, cg_style_t* style, cg_alpha_t alpha)
{
    cg_ruler_t  radius;
    radius = style->point.radius;
    if(0 == radius)return;
    
    cg_area_t   area;

    if (radius < 2)
    {
        area.x = point->x;
        area.y = point->y;
        area.x_width = 1;
        area.y_width = 1;
        fill_pixel(&area, mask, style->point.color, alpha);
    }
    else
    {
        area.x = point->x - radius;
        area.y = point->y - radius;
        area.x_width = radius;
        area.y_width = radius;
        fill_pixel(&area, mask,style->point.color, alpha);
    }
}




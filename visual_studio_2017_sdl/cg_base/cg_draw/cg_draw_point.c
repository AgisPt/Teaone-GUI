#include "cg_draw_point.h"
#include "../cg_core/cg_vfb.h"
#include "cg_draw.h"

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_error_t cg_draw_ground_point(cg_point_t* point,
                          cg_rect_t* mask,
                          cg_style_t* style,
                          cg_alpha_t alpha)
{
	cg_rect_t area;

	cg_ruler_t radius = style->point.radius;
	if (0 == radius)
		return cg_err_graphical_point_not_exist;

	if (radius < 2) {
		set_pixel(point->x, point->y, mask, style->point.color, alpha);
	}
	else {
		area.x0 = point->x - radius;
		area.y0 = point->y - radius;
		area.x1 = radius;
		area.y1 = radius;
		fill_pixel(&area, mask, style->point.color, alpha);
	}
	return cg_err_success;
}

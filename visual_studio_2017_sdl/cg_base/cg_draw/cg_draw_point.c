#include "cg_draw_point.h"
#include "../cg_core/cg_vfb.h"
#include "cg_draw.h"

/************************************************************************/
/* static variables                                                     */
/************************************************************************/
static void draw_point(cg_point_t* point,
                       cg_rect_t*  mask,
                       cg_ruler_t  radius,
                       cg_color_t  color,
                       cg_opa_t    opa);

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_error_t cg_draw__point(cg_point_t* point,
                          cg_rect_t*  mask,
                          cg_style_t* style,
                          cg_opa_t    opa)
{
	cg_ruler_t radius = style->radius;
	if (0 == radius)
		return cg_err_graphical_point_not_exist;

	draw_point(point, mask, radius, style->color, opa);
	return cg_err_success;
}

/************************************************************************/
/* static functions                                                     */
/************************************************************************/
static void draw_point(cg_point_t* point,
                       cg_rect_t*  mask,
                       cg_ruler_t  radius,
                       cg_color_t  color,
                       cg_opa_t    opa)
{
	cg_rect_t area;

	if (radius < 2) {
		set_pixel(point->x, point->y, mask, color, opa);
	}
	else {
		area.x0 = point->x - radius;
		area.y0 = point->y - radius;
		area.x1 = point->x + radius;
		area.y1 = point->y + radius;
		fill_pixel(&area, mask, color, opa);
	}
	cg_vfb_refresh();
}
#include "cg_draw_line.h"
#include "../../cg_base/cg_misc/cg_math.h"
#include "../cg_core/cg_vfb.h"
#include "cg_draw.h"

/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef struct
{
	cg_point_t p0, p1;
} draw_line_t;

/************************************************************************/
/* static functions                                                     */
/************************************************************************/
static void draw_line_bresenham(cg_point_t* ps,
                                cg_point_t* pe,
                                cg_rect_t*  mask,
                                cg_style_t* style,
                                cg_opa_t    alpha);

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_error_t cg_draw_line(cg_ruler_t x0,
                        cg_ruler_t y0,
                        cg_ruler_t x1,
                        cg_ruler_t y1,
                        cg_color_t color)
{

}

cg_error_t cg_draw__line(cg_point_t* point1,
                         cg_point_t* point2,
                         cg_rect_t*  mask,
                         cg_style_t* style,
                         cg_opa_t    opa)
{
	if (0 == style->line.wdith)
		return cg_err_graphical_line_not_exist;
	if (point1->x == point2->x && point1->y == point2->y)
		return cg_err_graphical_line_not_exist;

	draw_line_bresenham(point1, point2, mask, style, opa);
	return cg_err_success;
}

/************************************************************************/
/* static functions                                                     */
/************************************************************************/
static void draw_line_bresenham(cg_point_t* ps,
                                cg_point_t* pe,
                                cg_rect_t*  mask,
                                cg_style_t* style,
                                cg_opa_t    opa)
{
	cg_ruler_t dx, dy, eps, ux, uy, abs_x, abs_y;
	cg_ruler_t x, y;

	dx  = pe->x - ps->x;
	dy  = pe->y - ps->y;
	eps = 0;

	if (dx == 0) {
		ux = 0;
	}
	else {
		ux = ((dx > 0) << 1) - 1;
	}
	if (dy == 0) {
		uy = 0;
	}
	else {
		uy = ((dy > 0) << 1) - 1;
	}

	x     = ps->x;
	y     = ps->y;
	abs_x = CG_MATH_ABS(dx);
	abs_y = CG_MATH_ABS(dy);
	if (abs_x > abs_y) {
		for (; x != pe->x; x += ux) {
			set_pixel(x, y, mask, style->line.color, opa);
			eps += abs_y;
			if ((eps << 1) >= dx) {
				eps -= abs_x;
				y += uy;
			}
		}
	}
	else {
		for (; y != pe->y; y += uy) {
			set_pixel(x, y, mask, style->line.color, opa);
			eps += abs_x;
			if ((eps << 1) >= dy) {
				eps -= abs_y;
				x += ux;
			}
		}
	}
	cg_vfb_refresh();
}
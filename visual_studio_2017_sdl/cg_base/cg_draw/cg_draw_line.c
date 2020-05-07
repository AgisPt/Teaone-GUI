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
static void line_transform(draw_line_t* line, cg_point_t* p1, cg_point_t* p2);
static void draw_line_hor(draw_line_t* line,
                          cg_rect_t*   mask,
                          cg_style_t*  style,
                          cg_alpha_t   alpha);
static void draw_line_ver(draw_line_t* line,
                          cg_rect_t*   mask,
                          cg_style_t*  style,
                          cg_alpha_t   alpha);
static void draw_line_slash(draw_line_t* line, cg_style_t* style);
static void draw_line_bresenham(cg_point_t* ps,
                                cg_point_t* pe,
                                cg_rect_t*  mask,
                                cg_style_t* style,
                                cg_alpha_t  alpha);

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_error_t cg_draw_ground_line(cg_point_t* point1,
                               cg_point_t* point2,
                               cg_rect_t*  mask,
                               cg_style_t* style,
                               cg_alpha_t  alpha)
{
	if (0 == style->line.wdith)
		return;
	if (point1->x == point2->x && point1->y == point2->y)
		return;

	draw_line_bresenham(point1, point2, mask, style, alpha);
	///*Draw a vertical line*/
	// if (line.p1.x == line.p2.x)
	//{
	//    draw_line_ver(&line, mask, style, alpha);
	//}
	///*Draw a horizontal line*/
	// else if (line.p1.y == line.p2.y)
	//{
	//    draw_line_hor(&line, mask, style, alpha);
	//}
	///*Draw other skew line*/
	// else
	//{
	//    draw_line_slash(&line, style);
	//}
}

/************************************************************************/
/* static functions                                                     */
/************************************************************************/
// void line_transform(draw_line_t *line, cg_point_t* p1, cg_point_t* p2)
//{
//    cg_ruler_t dx, dy;
//
//    dx = CG_MATH_ABS(p1->x - p2->x);
//    dy = CG_MATH_ABS(p1->y - p2->y);
//    if (dx > dy)
//    {
//        if (p1->x > p2->x)
//        {
//            line->p1.x = p2->x;
//            line->p1.y = p2->y;
//            line->p2.x = p1->x;
//            line->p2.y = p1->y;
//        }
//        else
//        {
//            line->p1.x = p1->x;
//            line->p1.y = p1->y;
//            line->p2.x = p2->x;
//            line->p2.y = p2->y;
//        }
//    }
//    else
//    {
//        if (p1->y > p2->y)
//        {
//            line->p1.x = p2->x;
//            line->p1.y = p2->y;
//            line->p2.x = p1->x;
//            line->p2.y = p1->y;
//        }
//        else
//        {
//            line->p1.x = p1->x;
//            line->p1.y = p1->y;
//            line->p2.x = p2->x;
//            line->p2.y = p2->y;
//        }
//    }
//}

// void draw_line_ver(draw_line_t* line, cg_area_t* mask, cg_style_t* style,
// cg_alpha_t alpha)
//{
//    cg_ruler_t  width_half = style->line.wdith >> 1;
//    cg_ruler_t  width_last = style->line.wdith & 0b1;
//
//    cg_area_t   area;
//    area.x1 = line->p1.x - width_half;
//    area.x2 = line->p1.x + width_half + width_last;
//    area.y = line->p1.y;
//    area.y_width = line->p2.y;
//
//    fill_pixel(&area, mask, style->line.color, alpha);
//}
//
// void draw_line_hor(draw_line_t* line, cg_area_t* mask, cg_style_t* style,
// cg_alpha_t alpha)
//{
//    cg_ruler_t  width_half = style->line.wdith >> 1;
//    cg_ruler_t  width_last = style->line.wdith & 0b1;
//
//    cg_area_t   area;
//    area.x = line->p1.x;
//    area.y = line->p1.y - width_half;
//    area.x_width = line->p2.x;
//    area.y_width = line->p1.y + width_half + width_last;
//
//    fill_pixel(&area, mask, style->line.color, alpha);
//}
//
// static void draw_line_slash(draw_line_t* line, cg_area_t* mask, cg_style_t*
// style, cg_alpha_t alpha)
//{
//    double dx, dy, f;
//    dx = (double)line->p1.x - line->p2.x;
//    dy = (double)line->p1.y - line->p2.y;
//    f = dx / dy;
//}

static void draw_line_bresenham(cg_point_t* ps,
                                cg_point_t* pe,
                                cg_rect_t*  mask,
                                cg_style_t* style,
                                cg_alpha_t  alpha)
{
	cg_ruler_t dx, dy, eps, ux, uy;
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

	x = ps->x;
	y = ps->y;

	if (CG_MATH_ABS(dx) > CG_MATH_ABS(dy)) {
		for (; x != pe->x; x += ux) {
			set_pixel(x, y, mask, style->line.color, alpha);
			eps += dy;
			if ((eps << 1) >= dx) {
				eps -= dx;
				y += uy;
			}
		}
	}
	else {
		for (; y != pe->y; y += uy) {
			set_pixel(x, y, mask, style->line.color, alpha);
			eps += dx;
			if ((eps << 1) >= dy) {
				eps -= dy;
				x += ux;
			}
		}
	}
	cg_vfb_refresh();
}
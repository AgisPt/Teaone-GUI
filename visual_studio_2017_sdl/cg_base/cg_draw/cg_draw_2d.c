#include "cg_draw_2d.h"
#include "../cg_base/cg_misc/cg_math.h"
#include "../cg_core/cg_vfb.h"
#include "cg_draw_line.h"

void cg_draw_ground_rect(cg_rect_t*  area,
                         cg_rect_t*  mask,
                         cg_style_t* style,
                         cg_alpha_t  alpha)
{
	/*Exclude line*/
	if (CG_MATH_ABS(area->x1 - area->x2) <= 1 ||
	    CG_MATH_ABS(area->y - area->y_width) <= 1)
		return;

	cg_point_t p1, p2, p3, p4;

	if (style->graph.fill) {
		cg_hal_disp_fill(area->x1, area->y, area->x2, area->y_width,
		                 style->graph.color);
	}
	else {
		p1.x = CG_MATH_MIN(area->x1, area->x2);
		p1.y = CG_MATH_MIN(area->y, area->y_width);

		p2.x = CG_MATH_MAX(area->x1, area->x2);
		p2.y = CG_MATH_MIN(area->y, area->y_width);

		p3.x = CG_MATH_MIN(area->x1, area->x2);
		p3.y = CG_MATH_MAX(area->y, area->y_width);

		p4.x = CG_MATH_MAX(area->x1, area->x2);
		p4.y = CG_MATH_MAX(area->y, area->y_width);

		cg_draw_ground_line(&p1, &p2, mask, style, alpha);
		cg_draw_ground_line(&p1, &p3, mask, style, alpha);
		cg_draw_ground_line(&p4, &p2, mask, style, alpha);
		cg_draw_ground_line(&p4, &p3, mask, style, alpha);
	}
}

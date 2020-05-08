#include "cg_area.h"

bool cg_area_isintersect(cg_rect_t* rest, cg_rect_t* rect1, cg_rect_t* rect2)
{
	rest->x0 = CG_MATH_MAX(rect1->x0, rect2->x0);
	rest->y0 = CG_MATH_MAX(rect1->y0, rect2->y0);
	rest->x1 = CG_MATH_MIN(rect1->x1, rect2->x1);
	rest->y1 = CG_MATH_MIN(rect1->y1, rect2->y1);

	if ((rest->x0 >= rest->x1) || (rest->y0 >= rest->y1)) {
		return false;
	}
	return true;
}
#include "cg_draw_2d.h"
#include "../cg_base/cg_core/cg_vfb.h"
#include "../cg_base/cg_misc/cg_math.h"
#include "../cg_core/cg_vfb.h"
#include "cg_draw.h"
#include "cg_draw_line.h"

cg_error_t cg_draw__rect(cg_rect_t*  rect,
                         cg_rect_t*  mask,
                         cg_style_t* style,
                         cg_opa_t  opa)
{
	cg_error_t err = cg_err_success;
	if (true != cg_area_isexist(rect)) {
		err = cg_err_graphical_rect_not_exist;
		return err;
	}
	cg_rect_t area = cg_area_rect_arrange_coordinate(rect);

	cg_point_t p1, p2, p3, p4;
	p1.x = area.x0;
	p1.y = area.y0;

	p2.x = area.x1;
	p2.y = area.y0;

	p3.x = area.x1;
	p3.y = area.y1;

	p4.x = area.x0;
	p4.y = area.y1;

	cg_draw__line(&p1, &p2, mask, style, opa);
	cg_draw__line(&p2, &p3, mask, style, opa);
	cg_draw__line(&p3, &p4, mask, style, opa);
	cg_draw__line(&p4, &p1, mask, style, opa);
	return err;

}

cg_error_t cg_draw__fill_rect(cg_rect_t*  rect,
                              cg_rect_t*  mask,
                              cg_style_t* style,
                              cg_opa_t    opa)
{
	cg_error_t err = cg_err_success;
	if (true != cg_area_isexist(rect)) {
		err = cg_err_graphical_rect_not_exist;
		return err;
	}
	/*Make sure that the input rectangular coordinate conform to the
	GUI specifications,and calculate the coordinate of the input point.
	This should be the object's own business.Yeah, I haven't object*/
	cg_rect_t area = cg_area_rect_arrange_coordinate(rect);

	fill_pixel(&area, mask, style->color, opa);
	cg_vfb_refresh();
	return err;
}

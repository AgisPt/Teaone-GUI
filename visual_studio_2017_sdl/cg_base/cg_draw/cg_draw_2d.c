#include "cg_draw_2d.h"
#include "../cg_base/cg_misc/cg_math.h"
#include "../cg_core/cg_vfb.h"
#include "cg_draw_line.h"
#include "cg_draw.h"
#include "../cg_base/cg_core/cg_vfb.h"

cg_error_t cg_draw__fill_rect(cg_rect_t* rect,
                         cg_rect_t* mask,
                         cg_style_t* style,
                         cg_opa_t opa)
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

	fill_pixel(&area, mask, style->graph.color, opa);
	cg_vfb_refresh();
	return err;
}

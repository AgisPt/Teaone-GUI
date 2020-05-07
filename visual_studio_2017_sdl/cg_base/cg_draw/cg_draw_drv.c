#include "../cg_base/cg_core/cg_vfb.h"
#include "../cg_base/cg_log/cg_log.h"

cg_error_t cg_draw_drv_vpx(cg_ruler_t x,
                           cg_ruler_t y,
                           cg_rect_t* mask,
                           cg_color_t color,
                           cg_alpha_t alpha)
{
	if (x > mask->x1 || x < mask->x0 || y > mask->y1 || y < mask->y0)
		return;
	if (alpha > CG_ALPHA_MAX)
		return;
	if (alpha < CG_ALPHA_MIN)
		alpha = CG_ALPHA_COVER;

	cg_vfb_t* vfb = cg_vfb_get();
	if (NULL == vfb) {
		CG_LOG_ERROR("Invalid vfb point!");
		/*Vfb not found, will not continue, return error message.*/
		return cg_err_vfb_invalid;
	}

	/*Calculate position relative vfb and get the offset address
	 * information*/
	x -= vfb->area.x0;
	y -= vfb->area.y0;
	cg_ruler_t  width = cg_area_rect_get_width(&vfb->area);
	cg_color_t* vfb_t = vfb->frame_p + cg_math_multi_over_dec(y, width) + x;

	/*Draw directly on vfb*/
	if (CG_ALPHA_COVER == alpha) {
		*vfb_t = color;
	}
	else {
		*vfb_t = cg_color_mix(color, *vfb_t, alpha);
	}
	return cg_err_success;
}

cg_error_t cg_draw_drv_vfill(cg_rect_t* rect,
                             cg_rect_t* mask,
                             cg_color_t color,
                             cg_alpha_t alpha)
{
	if (alpha < CG_ALPHA_MIN)
		return;
	if (alpha > CG_ALPHA_MAX)
		alpha = CG_ALPHA_MAX;

	cg_rect_t overlap;
	cg_rect_t area;

	cg_vfb_t* vfb = cg_vfb_get();
	if (NULL == vfb) {
		CG_LOG_ERROR("Invalid vfb point!");
		/*Vfb not found, will not continue, return error message.*/
		return cg_err_vfb_invalid;
	}

	if (true != cg_area_intersect(&overlap, rect, mask))
		return cg_err_area_not_exist;

	area.x0 = overlap.x0 - vfb->area.x0;
	area.y0 = overlap.y0 - vfb->area.y0;
	area.x1 = overlap.x1 - vfb->area.x0;
	area.y1 = overlap.y1 - vfb->area.y0;
	return cg_hal_disp_fill(area.x0, area.y0, area.x1, area.y1, color);
}
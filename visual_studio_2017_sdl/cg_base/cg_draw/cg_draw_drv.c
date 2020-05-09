#include "../cg_base/cg_core/cg_vfb.h"
#include "../cg_base/cg_log/cg_log.h"

/************************************************************************/
/* static variables                                                     */
/************************************************************************/
static void vfb_fill_color_sw(cg_vfb_t*  vfb,
                              cg_rect_t* rect,
                              cg_color_t color,
                              cg_opa_t   opa);

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_error_t cg_draw_drv_vpx(cg_ruler_t x,
                           cg_ruler_t y,
                           cg_rect_t* mask,
                           cg_color_t color,
                           cg_opa_t   opa)
{
	if (x > mask->x1 || x < mask->x0 || y > mask->y1 || y < mask->y0)
		return cg_err_area_not_inmask;
	if (opa > CG_OPA_MAX)
		/*Ops reaches the maximum value, its content will not change
		 * VRAM*/
		return cg_err_opa_max;
	if (opa < CG_OPA_MIN)
		opa = CG_OPA_COVER;

	cg_vfb_t* vfb = cg_vfb_get();
	if (NULL == vfb) {
		CG_LOG_ERROR("Invalid vfb point!");
		/*Vfb not found, will not continue, return error message.*/
		return cg_err_vfb_invalid;
	}

	/*Because the draw object is vfb, you need to calculate the coordinates
	 *relative to vfb */
	x -= vfb->area.x0;
	y -= vfb->area.y0;
	/*Calculate the width of vfb, used to calculate offset address*/
	cg_ruler_t  width = cg_area_rect_get_width(&vfb->area);
	cg_color_t* frame = vfb->frame_p + cg_math_multi_over_dec(y, width) + x;

	if (CG_OPA_COVER == opa) {
		*frame = color;
	}
	else {
		/*When the displayed content has transparency requirements, the
		displayed content will be mixed with the background color
		according to the transparency value*/
		*frame = cg_color_mix(color, *frame, opa);
	}
	return cg_err_success;
}

cg_error_t cg_draw_drv_vfill(cg_rect_t* rect,
                             cg_rect_t* mask,
                             cg_color_t color,
                             cg_opa_t   opa)
{
	if (opa > CG_OPA_MAX)
		/*Ops reaches the maximum value, its content will not change
		 * VRAM*/
		return cg_err_opa_max;
	if (opa < CG_OPA_MIN)
		opa = CG_OPA_COVER;

	cg_rect_t overlap;
	if (true != cg_area_isintersect(&overlap, rect, mask))
		return cg_err_area_not_exist;

	cg_vfb_t* vfb = cg_vfb_get();
	if (NULL == vfb) {
		CG_LOG_ERROR("Invalid vfb point!");
		/*Vfb not found, will not continue, return error message.*/
		return cg_err_vfb_invalid;
	}

	/*Filling vfb with software*/
	vfb_fill_color_sw(vfb, &overlap, color, opa);
	return cg_err_success;
}

/************************************************************************/
/* static functions                                                     */
/************************************************************************/
static void vfb_fill_color_sw(cg_vfb_t*  vfb,
                              cg_rect_t* rect,
                              cg_color_t color,
                              cg_opa_t   opa)
{
	cg_rect_t area;
	/*Because the draw object is vfb, you need to calculate the coordinates
	 *relative to vfb */
	area.x0 = rect->x0 - vfb->area.x0;
	area.y0 = rect->y0 - vfb->area.y0;
	area.x1 = rect->x1 - vfb->area.x0;
	area.y1 = rect->y1 - vfb->area.y0;

	/*Calculate the width of vfb, used to calculate offset address*/
	cg_ruler_t  width = cg_area_rect_get_width(&vfb->area);
	cg_color_t* frame = NULL;

	int x, y;
	if (CG_OPA_COVER == opa) {
		for (y = area.y0; y <= area.y1; y++) {
			frame = vfb->frame_p +
			        cg_math_multi_over_dec(width, y) + area.x0;
			for (x = area.x0; x < area.x1; x++) {
				*frame = color;
				frame++;
			}
		}
	}
	else {
		for (y = area.y0; y <= area.y1; y++) {
			frame = vfb->frame_p +
			        cg_math_multi_over_dec(width, y) + area.x0;
			for (x = area.x0; x < area.x1; x++) {
				*frame = cg_color_mix(color, *frame, opa);
				frame++;
			}
		}
	}
}

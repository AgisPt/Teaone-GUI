#include "cg.h"

void cg_gui_main()
{
	cg_point_t point1 = {
	        .x = 200,
	        .y = 300,
	};
	cg_point_t point2 = {
	        .x = 100,
	        .y = 450,
	};

	cg_rect_t area = {
	        .x0 = 200,
	        .y0 = 200,
	        .x1 = 0,
	        .y1 = 500,
	};
	cg_rect_t mask = {
	        .x0 = 0,
	        .y0 = 0,
	        .x1 = 800,
	        .y1 = 480,
	};
	cg_style_t style = {.radius = 100, .wdith = 10};

	cg_vfb_t* cg_active = cg_vfb_get();
	cg_active->area.x0  = 0;
	cg_active->area.y0  = 0;
	cg_active->area.x1  = 800;
	cg_active->area.y1  = 480;

	style.color.green = 0xffff;
	style.color.red   = 0xFF;
	cg_draw__line(&point2, &point1, &mask, &style, 0);
	cg_draw__point(&point1, &mask, &style, 0);
	cg_draw__rect(&area, &mask, &style, 0);
}

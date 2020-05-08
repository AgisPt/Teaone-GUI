/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include <SDL.h>
#include <stdio.h>

#include "cg_init.h"

#include "cg_base/cg_draw/cg_draw_2d.h"
#include "cg_base/cg_draw/cg_draw_line.h"
#include "cg_base/cg_draw/cg_draw_point.h"

#include "cg_base/cg_core/cg_vfb.h"
/************************************************************************/
/* function                                                             */
/************************************************************************/
int main(int argc, char** argv)
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
	        .y1 = 0,
	};
	cg_rect_t mask = {
	        .x0 = 0,
	        .y0 = 0,
	        .x1 = 800,
	        .y1 = 480,
	};
	cg_style_t style = {.point.radius = 100, .line.wdith = 3};

	cg_init();
	cg_vfb_t* cg_active = cg_vfb_get();
	cg_active->area.x0  = 0;
	cg_active->area.y0  = 0;
	cg_active->area.x1  = 800;
	cg_active->area.y1  = 480;

	style.point.color.green = 0xffff;
	style.line.color.red    = 0xFF;
	style.graph.color.full  = 0xFFFF;
	cg_draw__line(&point2, &point1, &mask, &style, 0);
	cg_draw__point(&point1, &mask, &style, 0);
	cg_draw__fill_rect(&area, &mask, &style, 0);
	while (1) {
		;
	}
}

/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include <SDL.h>
#include <stdio.h>

#include "cg_init.h"

#include "cg_base/cg_draw/cg_draw_point.h"
#include "cg_base/cg_draw/cg_draw_line.h"
#include "cg_base/cg_draw/cg_draw_2d.h"

#include "cg_base/cg_core/cg_vfb.h"
/************************************************************************/
/* function                                                             */
/************************************************************************/
int main(int argc, char** argv)
{
    cg_point_t point1 = {
        .x = 0,
        .y = 100,
    };
    cg_point_t point2 = {
        .x = 100,
        .y = 100,
    };

    cg_area_t area = {
        .x = 10,
        .y = 10,
        .x_width = 100,
        .y_width = 100,
    };
    cg_area_t mask = {
        .x = 0,
        .y = 0,
        .x_width = 200, 
        .y_width = 200,
    };
    cg_style_t style = {
        .point.radius = 10,
        .line.wdith = 3
    };

    cg_init();
    cg_vfb_t *cg_active = cg_vfb_get();
    cg_active->area.x = 0;
    cg_active->area.y = 0;
    cg_active->area.x_width = 800;
    cg_active->area.y_width = 480;


    style.point.color.full = 0xffff;
    style.line.color.full = 0xFF;
    style.graph.color.full = 0xFF00;
    cg_draw_ground_line(&point1, &point2, &mask, &style, 0);
    //cg_draw_ground_point(&point1, &mask, &style, 0);
    //cg_draw_ground_rect(&area, &mask, &style, 0);
    while (1)
    {
        
    }
}


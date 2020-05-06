#include "../cg_base/cg_core/cg_vfb.h"
#include "../cg_base/cg_log/cg_log.h"


void cg_draw_drv_vpx(cg_ruler_t x, cg_ruler_t y, cg_area_t* mask, cg_color_t color, cg_alpha_t alpha)
{
    
    if (x > mask->x2 || x < mask->x1 || y > mask->y_width || y < mask->y) return;
    if (alpha < CG_ALPHA_MIN) alpha = CG_ALPHA_COVER;
    if (alpha > CG_ALPHA_MAX) return;

    cg_vfb_t* vfb;

    vfb = cg_vfb_get();

    if (NULL == vfb)
    {
        CG_LOG_ERROR("Invalid vfb point!");
        return;
    }

    /*Calculate position relative VFB*/
    x -= vfb->area.x1;
    y -= vfb->area.y;

    cg_ruler_t width = cg_area_get_width(&vfb->area);

    
    cg_color_t *vfb_t = vfb->frame_p + cg_math_multi_over_dec(y , width) + x;

    if (CG_ALPHA_COVER == alpha)
    {
        *vfb_t = color;
    } 
    else
    {
        *vfb_t = cg_color_mix(color, *vfb_t, alpha);
    }
}

void cg_draw_drv_vfill(cg_area_t *aims, cg_area_t *mask, cg_color_t color, cg_alpha_t alpha)
{
    if (alpha < CG_ALPHA_MIN) return;
    if (alpha > CG_ALPHA_MAX) alpha = CG_ALPHA_MAX;

    cg_area_t rest;
    bool ret;
    cg_vfb_t *vfb;
    
    vfb = cg_vfb_get();
    
    if (NULL == vfb)
    {
        CG_LOG_ERROR("Invalid vfb point!");
        return;
    }

    ret = cg_area_intersect(&rest, aims, mask);
    if (false == ret)
    {
        return;
    }

    cg_area_t _rest;

    _rest.x = rest.x - vfb->area.x;
    _rest.y = rest.y - vfb->area.y;
    _rest.x_width = rest.x_width;
    _rest.y_width = rest.y_width;
    cg_hal_disp_fill(_rest.x1, _rest.y, _rest.x2, _rest.y_width, color);
}
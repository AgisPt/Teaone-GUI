/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "cg_hal_display.h"
#include "../monitor/pc_monitor.h"

#include "../../cg_base/cg_tools/cg_memory.h"
#include "../../cg_base/cg_log/cg_log.h"

/************************************************************************/
/*                                                                      */
/************************************************************************/
static cg_disp_t* cg_handle;



/************************************************************************/
/* global functions                                                     */
/************************************************************************/
void cg_hal_disp_get_default(cg_disp_drv_t* driver)
{
    driver->disp_refresh = NULL;
    driver->disp_fill = NULL;
}


cg_disp_t* cg_hal_disp_create_handle(cg_disp_drv_t* driver)
{
    cg_disp_t* handle;

    handle = cg_malloc(sizeof(cg_disp_t));

    if(NULL == handle)return;

    memcpy(&(handle->dirver), driver, sizeof(cg_disp_drv_t));
    handle->next = NULL;

    cg_handle = handle;
    return handle;
}

void cg_hal_disp_refresh(int32_t x1, int32_t y1, int32_t x2, int32_t y2, cg_color_t* frame_p)
{
    if (NULL == cg_handle)return;
    if (NULL != cg_handle->dirver.disp_refresh)
    {
        cg_handle->dirver.disp_refresh(x1, y1, x2, y2, frame_p);
    }
    else
    {
        CG_LOG_ERROR("display refresh function unregistered!");
    }
}

void cg_hal_disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, cg_color_t color)
{
    if (NULL == cg_handle)return;
    if (NULL != cg_handle->dirver.disp_fill)
    {
        cg_handle->dirver.disp_fill(x1, y1, x2, y2, color);
    }
    else
    {
        CG_LOG_ERROR("display fill function unregistered!");
    }
}

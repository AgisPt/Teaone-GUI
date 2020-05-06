#include "cg_drivers/display/cg_hal_display.h"
#include "cg_drivers/display/cg_hal_win_driver.h"
#include "cg_drivers/monitor/pc_monitor.h"

void cg_init(void)
{
    cg_disp_drv_t cg_disp_drv;
    
    pc_monitor_init();
    cg_hal_drv_binding(&cg_disp_drv);
    cg_hal_disp_create_handle(&cg_disp_drv);

}
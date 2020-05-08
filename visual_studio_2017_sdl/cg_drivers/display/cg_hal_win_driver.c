#include "cg_hal_win_driver.h"
#include "../monitor/pc_monitor.h"

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
void cg_hal_drv_binding(cg_disp_drv_t* cg_disp_drv)
{
	if (NULL == cg_disp_drv)
		return;

	cg_disp_drv->disp_refresh = pc_monitor_refresh;
	cg_disp_drv->disp_fill    = pc_monitor_fill;
}

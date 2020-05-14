#include "../../cg_base/cg_log/cg_error_t.h"
#include "cg_window.h"
#include <stdint.h>

/************************************************************************/
/* static variables                                                     */
/************************************************************************/
static void cg_presenter_get_default(cg_presenter_handle_t* handle);

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_presenter_handle_t cg_presenser_create(void)
{
	cg_presenter_handle_t presenter;
	cg_presenter_get_default(&presenter);
	return presenter;
}

cg_error_t cg_presenter_binding(cg_win_handle_t*       window,
                                cg_presenter_handle_t* presenter)
{
	window->presenter = *presenter;
	presenter->window = window;
}

/************************************************************************/
/* static functions                                                     */
/************************************************************************/
static void cg_presenter_get_default(cg_presenter_handle_t* handle)
{
	handle->window = NULL;
}
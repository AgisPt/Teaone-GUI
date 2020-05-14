#include "../../cg_base/cg_log/cg_error_t.h"
#include "cg_window.h"
#include <stdint.h>

/************************************************************************/
/* static variables                                                     */
/************************************************************************/
static void cg_view_get_default(cg_view_handle_t* handle);

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_view_handle_t cg_view_create(cg_view_draw draw_callback)
{
	cg_view_handle_t view;
	cg_view_get_default(&view);
	view.draw = draw_callback;
	return view;
}

cg_error_t cg_view_binding(cg_win_handle_t* window, cg_view_handle_t* view)
{
	window->view = *view;
	view->window = window;
}

/************************************************************************/
/* static functions                                                     */
/************************************************************************/
static void cg_view_get_default(cg_view_handle_t* handle)
{
	handle->window = NULL;
}
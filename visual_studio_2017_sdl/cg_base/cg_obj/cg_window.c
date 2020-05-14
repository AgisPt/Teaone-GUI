#include "cg_window.h"

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_win_handle_t cg_window_create(cg_rect_t* rect)
{
	cg_win_handle_t handle;
	handle.rect = *rect;

	return handle;
}

cg_error_t cg_window_handle_regsiter(cg_win_handle_t*       handle,
                                     cg_model_handle_t*     model,
                                     cg_view_handle_t*      view,
                                     cg_presenter_handle_t* presenter)
{
	model->window     = handle;
	view->window      = handle;
	presenter->window = handle;


	handle->model     = *model;
	handle->view      = *view;
	handle->presenter = *presenter;


}
#include "cg_window.h"

cg_win_handle_t cg_window_create(cg_rect_t* rect)
{
	cg_win_handle_t handle;
	handle.rect = *rect;

	return handle;
}

cg_error_t cg_window_binding_handle(cg_win_handle_t*       handle,
                                    cg_model_handle_t*     model,
                                    cg_view_handle_t*      view,
                                    cg_presenter_handle_t* presenter)
{
	handle->model     = model;
	handle->view      = view;
	handle->presenter = presenter;
}
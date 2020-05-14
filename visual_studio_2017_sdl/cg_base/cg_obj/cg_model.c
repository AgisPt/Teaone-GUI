#include <stdint.h>
#include "cg_window.h"
#include "../../cg_base/cg_log/cg_error_t.h"

/************************************************************************/
/* static variables                                                     */
/************************************************************************/
static void cg_model_get_default(cg_model_handle_t* handle);



/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_model_handle_t cg_model_create(void)
{
	cg_model_handle_t model;
	cg_model_get_default(&model);
	return model;
}

cg_error_t cg_model_binding(cg_win_handle_t* window, cg_model_handle_t* model)
{
	window->model = *model;
	model->window = window;
}

/************************************************************************/
/* static functions                                                     */
/************************************************************************/
static void cg_model_get_default(cg_model_handle_t* handle)
{
	handle->window = NULL;
}

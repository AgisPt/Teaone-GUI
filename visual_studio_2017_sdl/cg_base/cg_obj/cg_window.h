#ifndef _CG_WINDOW_H_
#define _CG_WINDOW_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include <stdint.h>

#include "cg_model.h"
#include "cg_presenter.h"
#include "cg_view.h"

#include "../cg_core/cg_area.h"
#include "../cg_log/cg_error_t.h"
/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef struct cg_win_handle_s cg_win_handle_t;

struct cg_win_handle_s
{
	cg_rect_t             rect;
	cg_model_handle_t     model;
	cg_view_handle_t      view;
	cg_presenter_handle_t presenter;
};

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_win_handle_t cg_window_create(cg_rect_t* rect);

cg_error_t cg_window_handle_regsiter(cg_win_handle_t*       handle,
                                     cg_model_handle_t*     model,
                                     cg_view_handle_t*      view,
                                     cg_presenter_handle_t* presenter);

cg_error_t cg_model_binding(cg_win_handle_t* window, cg_model_handle_t* model);
cg_error_t cg_view_binding(cg_win_handle_t* window, cg_view_handle_t* view);
cg_error_t cg_presenter_binding(cg_win_handle_t*       window,
                                cg_presenter_handle_t* presenter);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_WINDOW_H_

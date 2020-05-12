#ifndef _CG_WINDOW_H_
#define _CG_WINDOW_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../cg_core/cg_area.h"
#include <stdint.h>

#include "cg_model.h"
#include "cg_presenter.h"
#include "cg_view.h"

/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef struct cg_win_handle_s cg_win_handle_t;

struct cg_win_handle_s
{
	cg_rect_t              rect;
	cg_model_handle_t*     model;
	cg_view_handle_t*      view;
	cg_presenter_handle_t* presenter;
};
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_WINDOW_H_

#ifndef _CG_VIEW_H_
#define _CG_VIEW_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../cg_message/cg_message.h"

/************************************************************************/
/* extern                                                               */
/************************************************************************/
extern struct cg_win_handle_s;

/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef struct cg_view_handle_s cg_view_handle_t;

typedef const void (*cg_view_draw)(cg_message_t* cg_message);

/************************************************************************/
/* struct                                                               */
/************************************************************************/
struct cg_view_handle_s
{
	struct cg_win_handle_s* window;
	cg_view_draw            draw;
};

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_view_handle_t cg_view_create(cg_view_draw draw_callback);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_VIEW_H_

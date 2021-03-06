#ifndef _CG_PRESENTER_H_
#define _CG_PRESENTER_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* extern                                                               */
/************************************************************************/
extern struct cg_win_handle_s;

/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef struct cg_presenter_handle_s cg_presenter_handle_t;

/************************************************************************/
/* struct                                                               */
/************************************************************************/
struct cg_presenter_handle_s
{
	struct cg_win_handle_s* window;
};

/************************************************************************/
/* global functions                                                     */
/************************************************************************/
cg_presenter_handle_t cg_presenser_create(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_PRESENTER_H_

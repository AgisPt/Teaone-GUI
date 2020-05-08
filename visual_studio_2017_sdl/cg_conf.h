#ifndef _CTA_CONF_H_
#define _CTA_CONF_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* Size                                                                 */
/************************************************************************/
#define CG_HOR_PX (800)
#define CG_VER_PX (480)

/************************************************************************/
/* Depth                                                                */
/************************************************************************/
#define CG_COLOR_BPP (16)
#define CG_COLOR_DEPTH CG_COLOR_BPP

/************************************************************************/
/* Multi Buffer                                                         */
/************************************************************************/
#define CG_MULTI_BUFFER_ENABLE 0

#if CG_MULTI_BUFFER_ENABLE == 1
#	define CG_MULTI_BUFFER 2
#else
#	define CG_MULTI_BUFFER 1
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CTA_CONF_H_
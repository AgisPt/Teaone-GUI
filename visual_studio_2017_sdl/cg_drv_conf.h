#ifndef _CTA_DRV_CONF_H_
#define _CTA_DRV_CONF_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "cg_conf.h"

/************************************************************************/
/* Monitor for PC                                                       */
/************************************************************************/
#define USE_MONITOR     1

#ifndef USE_MONITOR
#   define USE_MONITOR  0
#endif

#if USE_MONITOR
#   define MONITOR_HOR_PX   CG_HOR_PX 
#   define MONITOR_VER_PX   CG_VER_PX
/* Scale window by this factor */
#   define MONITOR_ZOOM       1
#endif


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _CTA_DRV_CONF_H_

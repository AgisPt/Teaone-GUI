#ifndef _CG_MATH_H_
#define _CG_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include <stdint.h>

/************************************************************************/
/* defines                                                              */
/************************************************************************/

#define CG_MATH_ABS(x) ((x) > 0 ? (x) : (-(x)))
#define CG_MATH_MIN(a, b) (a < b ? a : b)
#define CG_MATH_MAX(a, b) (a > b ? a : b)

#define CG_MATH_GETINT(x) (int(x + 0.5))

/************************************************************************/
/* global functions                                                     */
/************************************************************************/

int32_t cg_math_multi_over_dec(int16_t value1, int16_t value2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_MATH_H_

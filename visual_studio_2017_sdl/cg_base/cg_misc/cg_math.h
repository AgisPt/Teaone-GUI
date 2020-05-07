#ifndef _CG_MATH_H_
#define _CG_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "../cg_core/cg_area.h"

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

//************************************
// Multiplication overflow detection
// Method:    cg_math_multi_over_dec
// FullName:  cg_math_multi_over_dec
// Access:    public
// Returns:   cg_ruler_t
// Parameter: cg_ruler_t value1
// Parameter: cg_ruler_t value2
//************************************
cg_addr_t cg_math_multi_over_dec(cg_ruler_t value1, cg_ruler_t value2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_MATH_H_

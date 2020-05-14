#ifndef _CG_ERROR_H_
#define _CG_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif
/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include <stdint.h>

/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef int32_t cg_error_t;

typedef enum {
	cg_err_success                = 0x00,
	cg_err_fial                   = 0x01,
	cg_err_handle_invalid         = 0x02,
	cg_err_handle_refresh_invalid = 0x03,
	cg_err_handle_fill_invalid    = 0x04,
	cg_err_opa_max                = 0x05,
} cg_error_generic_type;

typedef enum {
	cg_err_vfb_invalid = 0x11,
} cg_error_vfb_type;

typedef enum {
	cg_err_area_exist      = 0x20,
	cg_err_area_not_exist  = 0x21,
	cg_err_area_intersect  = 0x22,
	cg_err_area_not_inlcd  = 0x23,
	cg_err_area_not_inmask = 0x24,
} cg_error_area_type;

typedef enum {
	cg_err_graphical_point_not_exist = 0x31,
	cg_err_graphical_line_not_exist  = 0x32,
	cg_err_graphical_rect_not_exist  = 0x32,
} cg_error_graphical_type;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_ERROR_H_

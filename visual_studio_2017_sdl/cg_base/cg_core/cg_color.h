#ifndef _CG_COLOR_H_
#define _CG_COLOR_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* includes                                                             */
/************************************************************************/
#include "cg_conf.h"
#include <stdint.h>

/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef union
{
	struct
	{
		uint16_t blue : 5;
		uint16_t green : 6;
		uint16_t red : 5;
	};
	/* MSB         LSB */
	/* [R:5][G:6][B:5] */
	uint16_t full;
} cg_color16_t;

typedef union
{
	struct
	{
		uint8_t blue;
		uint8_t green;
		uint8_t red;
		uint8_t alpha;
	};
	/* MSB              LSB */
	/* [A:8][R:8][G:8][B:8] */
	uint32_t full;
} cg_color32_t;

typedef uint8_t cg_alpha_t;

/************************************************************************/
/* Define                                                               */
/************************************************************************/

/************************************************************************/
/* Color depth                                                          */
/************************************************************************/
#if CG_COLOR_DEPTH == 1
typedef cg_color1_t cg_color_t;
#elif CG_COLOR_DEPTH == 8
typedef cg_color8_t cg_color_t;
#elif CG_COLOR_DEPTH == 16
typedef cg_color16_t cg_color_t;
#elif CG_COLOR_DEPTH == 32
typedef cg_color32_t cg_color_t;
#endif  // CG_COLOR_DEPTH == 1

/************************************************************************/
/* Alpha                                                                */
/************************************************************************/
#define CG_ALPHA_MIN 10
#define CG_ALPHA_MAX 254

enum { CG_ALPHA_COVER  = 0,
       CG_ALPHA_0      = 0,
       CG_ALPHA_10     = 25,
       CG_ALPHA_20     = 51,
       CG_ALPHA_30     = 76,
       CG_ALPHA_40     = 102,
       CG_ALPHA_50     = 127,
       CG_ALPHA_60     = 153,
       CG_ALPHA_70     = 178,
       CG_ALPHA_80     = 204,
       CG_ALPHA_90     = 229,
       CG_ALPHA_100    = 255,
       CG_ALPHA_TRANSP = 255,
};

/************************************************************************/
/* static inline functions                                              */
/************************************************************************/
static inline uint32_t cg_color_to32(cg_color_t color)
{
#if CG_COLOR_DEPTH == 1
	if (color.full) {
		return 0xFFFFFFFF;
	}
	else {
		return 0;
	}
#elif CG_COLOR_DEPTH == 8
	cg_color_t ret;
#elif CG_COLOR_DEPTH == 16
	cg_color32_t ret;
	ret.red   = color.red << 3;
	ret.green = color.green << 2;
	ret.blue  = color.blue << 3;
	ret.alpha = 0xFF;
	return ret.full;
#elif CG_COLOR_DEPTH == 32
	return cg_color_t.full;
#endif  // CG_COLOR_DEPTH == 1
}

static inline cg_color_t
cg_color_mix(cg_color_t foreground, cg_color_t background, cg_alpha_t mix)
{
	cg_color_t ret;
#if CG_COLOR_DEPTH != 1
	ret.red = ((uint16_t)foreground.red * (255 - mix) +
	           (background.red * mix)) >> 8;
	ret.green = ((uint16_t)foreground.green * (255 - mix) +
	             (background.green * mix)) >> 8;
	ret.blue = ((uint16_t)foreground.blue * (255 - mix) +
	            (background.blue * mix)) >> 8;
#	if CG_COLOR_DEPTH == 32
	ret.alpha = mix
#	endif
	        return ret;
#endif  // CG_COLOR_DEPTH != 1
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // _CG_COLOR_H_

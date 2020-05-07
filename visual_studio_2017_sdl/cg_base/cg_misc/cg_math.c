#include "cg_math.h"

cg_addr_t cg_math_multi_over_dec(cg_ruler_t value1, cg_ruler_t value2)
{
	cg_addr_t ret;

	ret = value1 * value2;
	return ret;
}

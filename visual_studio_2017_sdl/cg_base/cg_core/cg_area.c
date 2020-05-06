#include "cg_area.h"
#include "../cg_misc/cg_math.h"

bool  cg_area_intersect(cg_area_t* rest, cg_area_t* a1, cg_area_t* a2)
{
        bool ret;
        rest->x1 = CG_MATH_MAX(a1->x1, a2->x1);
        rest->x2 = CG_MATH_MIN(a1->x2, a2->x2);
        rest->y = CG_MATH_MAX(a1->y, a2->y);
        rest->y_width = CG_MATH_MIN(a1->y_width, a2->y_width);

        ret = true;
        if ((rest->x1 >= rest->x2) || (rest->y >= rest->y_width))
        {
                ret = false;
        }
        return ret;
}
/*
 * Support for tty settings using termios
 *
 * (c) 2019 Kamil Rytarowski <n54@gmx.com>
 *
 */

#include "jim.h"
#include "jim-floats.h"

#include <stdlib.h>
#include <math.h>

int jim_float_isnan( jim_float f )
{
    return isnan(f);
}

int jim_float_isinf( jim_float f )
{
    return isinf(f);
}

jim_float jim_float_sin( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return sin(f);
#else
    abort();
#endif
}

jim_float jim_float_sin( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return sin(f);
#else
    abort();
#endif
}

jim_float jim_float_cos( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return cos(f);
#else
    abort();
#endif
}

jim_float jim_float_tan( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return tan(f);
#else
    abort();
#endif
}

jim_float jim_float_asin( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return asin(f);
#else
    abort();
#endif
}

jim_float jim_float_acos( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return acos(f);
#else
    abort();
#endif
}

jim_float jim_float_atan( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return atan(f);
#else
    abort();
#endif
}

jim_float jim_float_atan2( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return atan2(f);
#else
    abort();
#endif
}

jim_float jim_float_sinh( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return sinh(f);
#else
    abort();
#endif
}

jim_float jim_float_cosh( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return cosh(f);
#else
    abort();
#endif
}

jim_float jim_float_tanh( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return tanh(f);
#else
    abort();
#endif
}

jim_float jim_float_ceil( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return ceil(f);
#else
    abort();
#endif
}

jim_float jim_float_floor( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return floor(f);
#else
    abort();
#endif
}

jim_float jim_float_exp( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return exp(f);
#else
    abort();
#endif
}

jim_float jim_float_log( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return log(f);
#else
    abort();
#endif
}

jim_float jim_float_log10( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return log10(f);
#else
    abort();
#endif
}

jim_float jim_float_sqrt( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return sqrt(f);
#else
    abort();
#endif
}

jim_float jim_float_pow( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return pow(f);
#else
    abort();
#endif
}

jim_float jim_float_hypot( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return hypot(f);
#else
    abort();
#endif
}

jim_float jim_float_fmod( jim_float f )
{
#ifdef JIM_MATH_FUNCTIONS
    return fmod(f);
#else
    abort();
#endif
}

jim_float jim_strtof( const char *nptr, char **endptr )
{
    return strtof(nptr, endptr);
}

#define MAXLEN_CHARS_IN_FLOAT 16
#define MAXLEN_CHARS_IN_DOUBLE 24

int jim_stof( jim_float f, char *str, unsigned int len )
{
    return snprintf(str, len, "%g", f);
}

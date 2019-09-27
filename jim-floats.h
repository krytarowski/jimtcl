#ifndef JIM_FLOATS_H
#define JIM_FLOATS_H

#include <jim.h>

#ifndef HAVE_SOFTFLOAT

/*----------------------------------------------------------------------------
| jimtcl float/double
*----------------------------------------------------------------------------*/
typedef float jim_float;
typedef double jim_double;

/*----------------------------------------------------------------------------
| Integer-to-floating-point conversion routines.
*----------------------------------------------------------------------------*/
static inline jim_float jim_wide_to_float( jim_wide w )
{
    return (jim_float)w;
}
static inline jim_double jim_wide_to_double( jim_wide w )
{
    return (jim_double)w;
}

/*----------------------------------------------------------------------------
| 32-bit (single-precision) floating-point operations.
*----------------------------------------------------------------------------*/
static inline jim_wide jim_float_to_wide( jim_float f )
{
    return (jim_wide)f;
}
static inline jim_double jim_float_to_double( jim_float f )
{
    return (jim_double)f;
}

static inline jim_float jim_float_add( jim_float f1, jim_float f2 )
{
    return f1 + f2;
}
static inline jim_float jim_float_sub( jim_float f1, jim_float f2 )
{
    return f1 - f2;
}
static inline jim_float jim_float_mul( jim_float f1, jim_float f2 )
{
    return f1 * f2;
}
static inline jim_float jim_float_div( jim_float f1, jim_float f2 )
{
    return f1 / f2;
}

static inline int jim_float_eq( jim_float f1, jim_float f2 )
{
    return f1 == f2;
}
static inline int jim_float_le( jim_float f1, jim_float f2 )
{
    return f1 <= f2;
}
static inline int jim_float_lt( jim_float f1, jim_float f2 )
{
    return f1 < f2;
}
static inline int jim_float_neq( jim_float f1, jim_float f2 )
{
    return f1 != f2;
}
static inline int jim_float_ge( jim_float f1, jim_float f2 )
{
    return f1 >= f2;
}
static inline int jim_float_gt( jim_float f1, jim_float f2 )
{
    return f1 > f2;
}

int jim_float_isnan( jim_float );
int jim_float_isinf( jim_float );

jim_float jim_float_sin( jim_float );
jim_float jim_float_cos( jim_float );
jim_float jim_float_tan( jim_float );
jim_float jim_float_asin( jim_float );
jim_float jim_float_acos( jim_float );
jim_float jim_float_atan( jim_float );
jim_float jim_float_atan2( jim_float );
jim_float jim_float_sinh( jim_float );
jim_float jim_float_cosh( jim_float );
jim_float jim_float_tanh( jim_float );
jim_float jim_float_ceil( jim_float );
jim_float jim_float_floor( jim_float );
jim_float jim_float_exp( jim_float );
jim_float jim_float_log( jim_float );
jim_float jim_float_log10( jim_float );
jim_float jim_float_sqrt( jim_float );
jim_float jim_float_pow( jim_float );
jim_float jim_float_hypot( jim_float );
jim_float jim_float_fmod( jim_float );

jim_float jim_strtof( const char *, char ** );
int jim_stof( jim_float, const char *, char *, unsigned int );

/*----------------------------------------------------------------------------
| 64-bit (double-precision) floating-point operations.
*----------------------------------------------------------------------------*/
static inline jim_wide jim_double_to_wide( jim_double f )
{
    return (jim_wide)f;
}
static inline jim_float jim_double_to_float( jim_double f )
{
    return (jim_float)f;
}

static inline jim_double jim_double_add( jim_double f1, jim_double f2 )
{
    return f1 + f2;
}
static inline jim_double jim_double_sub( jim_double f1, jim_double f2 )
{
    return f1 - f2;
}
static inline jim_double jim_double_mul( jim_double f1, jim_double f2 )
{
    return f1 * f2;
}
static inline jim_double jim_double_div( jim_double f1, jim_double f2 )
{
    return f1 / f2;
}

static inline int jim_double_eq( jim_double f1, jim_double f2 )
{
    return f1 == f2;
}
static inline int jim_double_le( jim_double f1, jim_double f2 )
{
    return f1 <= f2;
}
static inline int jim_double_lt( jim_double f1, jim_double f2 )
{
    return f1 < f2;
}
static inline int jim_double_neq( jim_double f1, jim_double f2 )
{
    return f1 != f2;
}
static inline int jim_double_ge( jim_double f1, jim_double f2 )
{
    return f1 >= f2;
}
static inline int jim_double_gt( jim_double f1, jim_double f2 )
{
    return f1 > f2;
}

int jim_double_isnan( jim_double );
int jim_double_isinf( jim_double );

jim_double jim_double_sin( jim_double );
jim_double jim_double_cos( jim_double );
jim_double jim_double_tan( jim_double );
jim_double jim_double_asin( jim_double );
jim_double jim_double_acos( jim_double );
jim_double jim_double_atan( jim_double );
jim_double jim_double_atan2( jim_double );
jim_double jim_double_sinh( jim_double );
jim_double jim_double_cosh( jim_double );
jim_double jim_double_tanh( jim_double );
jim_double jim_double_ceil( jim_double );
jim_double jim_double_floor( jim_double );
jim_double jim_double_exp( jim_double );
jim_double jim_double_log( jim_double );
jim_double jim_double_log10( jim_double );
jim_double jim_double_sqrt( jim_double );
jim_double jim_double_pow( jim_double );
jim_double jim_double_hypot( jim_double );
jim_double jim_double_fmod( jim_double );

jim_double jim_strtod( const char *, char ** );
int jim_stod( jim_double, const char *, char *, unsigned int );

/*----------------------------------------------------------------------------
| jimtcl soft float/double commonly used constants
*----------------------------------------------------------------------------*/

#define JIM_DOUBLE_ZERO 0.0
#define JIM_DOUBLE_ONE 1.0
#define JIM_DOUBLE_MINUSONE -1.0
#define JIM_DOUBLE_HALF 0.5
#define JIM_DOUBLE_THOUSAND 1e3
#define JIM_DOUBLE_MILLION 1e6

#else
#include <jim-softfloat.h>
#endif

#endif

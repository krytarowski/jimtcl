
/*============================================================================

This C header file is part of the SoftFloat IEEE Floating-Point Arithmetic
Package, Release 3e, by John R. Hauser.

Copyright 2011, 2012, 2013, 2014, 2015, 2016, 2017 The Regents of the
University of California.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions, and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions, and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the University nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/

#ifndef JIM_SOFTFLOAT_H
#define JIM_SOFTFLOAT_H

#include <jim.h>

#ifdef HAVE_SOFTFLOAT

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------
| Auxiliary types.
*----------------------------------------------------------------------------*/

typedef unsigned char jim_uint8_t;
typedef unsigned short jim_uint16_t;
typedef unsigned int jim_uint32_t;
typedef unsigned long long jim_uint64_t;

typedef signed char jim_int8_t;
typedef signed short jim_int16_t;
typedef signed int jim_int32_t;
typedef signed long long jim_int64_t;

JIM_CTASSERT(sizeof(jim_uint8_t) == 1);
JIM_CTASSERT(sizeof(jim_uint16_t) == 2);
JIM_CTASSERT(sizeof(jim_uint32_t) == 4);
JIM_CTASSERT(sizeof(jim_uint64_t) == 8);

JIM_CTASSERT(sizeof(jim_int8_t) == 1);
JIM_CTASSERT(sizeof(jim_int16_t) == 2);
JIM_CTASSERT(sizeof(jim_int32_t) == 4);
JIM_CTASSERT(sizeof(jim_int64_t) == 8);

/*----------------------------------------------------------------------------
| jimtcl soft float/double
*----------------------------------------------------------------------------*/

typedef struct { jim_uint32_t v; } jim_float;
typedef struct { jim_uint64_t v; } jim_double;

JIM_CTASSERT(sizeof(jim_uint32_t) == sizeof(jim_float));
JIM_CTASSERT(sizeof(jim_uint64_t) == sizeof(jim_double));

/*----------------------------------------------------------------------------
| Software floating-point underflow tininess-detection mode.
*----------------------------------------------------------------------------*/
extern jim_uint8_t jim_softfloat_detectTininess;
enum {
    jim_softfloat_tininess_beforeRounding = 0,
    jim_softfloat_tininess_afterRounding  = 1
};

/*----------------------------------------------------------------------------
| Software floating-point rounding mode.  (Mode "odd" is supported only if
| SoftFloat is compiled with macro 'SOFTFLOAT_ROUND_ODD' defined.)
*----------------------------------------------------------------------------*/
extern jim_uint8_t softfloat_roundingMode;
enum {
    jim_softfloat_round_near_even   = 0,
    jim_softfloat_round_minMag      = 1,
    jim_softfloat_round_min         = 2,
    jim_softfloat_round_max         = 3,
    jim_softfloat_round_near_maxMag = 4,
    jim_softfloat_round_odd         = 6
};

/*----------------------------------------------------------------------------
| Software floating-point exception flags.
*----------------------------------------------------------------------------*/
extern jim_uint8_t softfloat_exceptionFlags;
enum {
    jim_softfloat_flag_inexact   =  1,
    jim_softfloat_flag_underflow =  2,
    jim_softfloat_flag_overflow  =  4,
    jim_softfloat_flag_infinite  =  8,
    jim_softfloat_flag_invalid   = 16
};

/*----------------------------------------------------------------------------
| Routine to raise any or all of the software floating-point exception flags.
*----------------------------------------------------------------------------*/
void jim_softfloat_raiseFlags( jim_uint8_t );

/*----------------------------------------------------------------------------
| Integer-to-floating-point conversion routines.
*----------------------------------------------------------------------------*/
jim_float jim_ui32_to_f32( jim_uint32_t );
jim_double jim_ui32_to_f64( jim_uint32_t );
jim_float jim_ui64_to_f32( jim_uint64_t );
jim_double jim_ui64_to_f64( jim_uint64_t );
jim_float jim_i32_to_f32( jim_int32_t );
jim_double jim_i32_to_f64( jim_int32_t );
jim_float jim_i64_to_f32( jim_int64_t );
jim_double jim_i64_to_f64( jim_int64_t );

/*----------------------------------------------------------------------------
| 32-bit (single-precision) floating-point operations.
*----------------------------------------------------------------------------*/
jim_uint32_t jim_f32_to_ui32( jim_float, jim_uint8_t, int );
jim_uint64_t jim_f32_to_ui64( jim_float, jim_uint8_t, int );
jim_int32_t jim_f32_to_i32( jim_float, jim_uint8_t, int );
jim_int64_t jim_f32_to_i64( jim_float, jim_uint8_t, int );
jim_uint32_t jim_f32_to_ui32_r_minMag( jim_float, int );
jim_uint64_t jim_f32_to_ui64_r_minMag( jim_float, int );
jim_int32_t jim_f32_to_i32_r_minMag( jim_float, int );
jim_int64_t jim_f32_to_i64_r_minMag( jim_float, int );
jim_double jim_f32_to_f64( jim_float );
jim_float jim_f32_roundToInt( jim_float, jim_uint8_t, int );
jim_float jim_f32_add( jim_float, jim_float );
jim_float jim_f32_sub( jim_float, jim_float );
jim_float jim_f32_mul( jim_float, jim_float );
jim_float jim_f32_mulAdd( jim_float, jim_float, jim_float );
jim_float jim_f32_div( jim_float, jim_float );
jim_float jim_f32_rem( jim_float, jim_float );
jim_float jim_f32_sqrt( jim_float );
int jim_f32_eq( jim_float, jim_float );
int jim_f32_le( jim_float, jim_float );
int jim_f32_lt( jim_float, jim_float );
int jim_f32_eq_signaling( jim_float, jim_float );
int jim_f32_le_quiet( jim_float, jim_float );
int jim_f32_lt_quiet( jim_float, jim_float );
int jim_f32_isSignalingNaN( jim_float );

/*----------------------------------------------------------------------------
| 64-bit (double-precision) floating-point operations.
*----------------------------------------------------------------------------*/
jim_uint32_t jim_f64_to_ui32( jim_double, jim_uint8_t, int );
jim_uint64_t jim_f64_to_ui64( jim_double, jim_uint8_t, int );
jim_int32_t jim_f64_to_i32( jim_double, jim_uint8_t, int );
jim_int64_t jim_f64_to_i64( jim_double, jim_uint8_t, int );
jim_uint32_t jim_f64_to_ui32_r_minMag( jim_double, int );
jim_uint64_t jim_f64_to_ui64_r_minMag( jim_double, int );
jim_int32_t jim_f64_to_i32_r_minMag( jim_double, int );
jim_int64_t jim_f64_to_i64_r_minMag( jim_double, int );
jim_float jim_f64_to_f32( jim_double );
jim_double jim_f64_roundToInt( jim_double, jim_uint8_t, int );
jim_double jim_f64_add( jim_double, jim_double );
jim_double jim_f64_sub( jim_double, jim_double );
jim_double jim_f64_mul( jim_double, jim_double );
jim_double jim_f64_mulAdd( jim_double, jim_double, jim_double );
jim_double jim_f64_div( jim_double, jim_double );
jim_double jim_f64_rem( jim_double, jim_double );
jim_double jim_f64_sqrt( jim_double );
int jim_f64_eq( jim_double, jim_double );
int jim_f64_le( jim_double, jim_double );
int jim_f64_lt( jim_double, jim_double );
int jim_f64_eq_signaling( jim_double, jim_double );
int jim_f64_le_quiet( jim_double, jim_double );
int jim_f64_lt_quiet( jim_double, jim_double );
int jim_f64_isSignalingNaN( jim_double );

#ifdef __cplusplus
}
#endif

#endif

#endif

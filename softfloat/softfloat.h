
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

#ifndef softfloat_h
#define softfloat_h 1

#include <stdbool.h>
#include <stdint.h>
#include "softfloat_types.h"

/*----------------------------------------------------------------------------
| Software floating-point underflow tininess-detection mode.
*----------------------------------------------------------------------------*/
extern  uint_fast8_t softfloat_detectTininess;
enum {
    softfloat_tininess_beforeRounding = 0,
    softfloat_tininess_afterRounding  = 1
};

/*----------------------------------------------------------------------------
| Software floating-point rounding mode.  (Mode "odd" is supported only if
| SoftFloat is compiled with macro 'SOFTFLOAT_ROUND_ODD' defined.)
*----------------------------------------------------------------------------*/
extern  uint_fast8_t softfloat_roundingMode;
enum {
    softfloat_round_near_even   = 0,
    softfloat_round_minMag      = 1,
    softfloat_round_min         = 2,
    softfloat_round_max         = 3,
    softfloat_round_near_maxMag = 4,
    softfloat_round_odd         = 6
};

/*----------------------------------------------------------------------------
| Software floating-point exception flags.
*----------------------------------------------------------------------------*/
extern  uint_fast8_t softfloat_exceptionFlags;
enum {
    softfloat_flag_inexact   =  1,
    softfloat_flag_underflow =  2,
    softfloat_flag_overflow  =  4,
    softfloat_flag_infinite  =  8,
    softfloat_flag_invalid   = 16
};

/*----------------------------------------------------------------------------
| Routine to raise any or all of the software floating-point exception flags.
*----------------------------------------------------------------------------*/
void softfloat_raiseFlags( uint_fast8_t );

/*----------------------------------------------------------------------------
| Integer-to-floating-point conversion routines.
*----------------------------------------------------------------------------*/
jim_float ui32_to_f32( uint32_t );
jim_double ui32_to_f64( uint32_t );
jim_float ui64_to_f32( uint64_t );
jim_double ui64_to_f64( uint64_t );
jim_float i32_to_f32( int32_t );
jim_double i32_to_f64( int32_t );
jim_float i64_to_f32( int64_t );
jim_double i64_to_f64( int64_t );

/*----------------------------------------------------------------------------
| 32-bit (single-precision) floating-point operations.
*----------------------------------------------------------------------------*/
uint_fast32_t f32_to_ui32( jim_float, uint_fast8_t, bool );
uint_fast64_t f32_to_ui64( jim_float, uint_fast8_t, bool );
int_fast32_t f32_to_i32( jim_float, uint_fast8_t, bool );
int_fast64_t f32_to_i64( jim_float, uint_fast8_t, bool );
uint_fast32_t f32_to_ui32_r_minMag( jim_float, bool );
uint_fast64_t f32_to_ui64_r_minMag( jim_float, bool );
int_fast32_t f32_to_i32_r_minMag( jim_float, bool );
int_fast64_t f32_to_i64_r_minMag( jim_float, bool );
jim_double f32_to_f64( jim_float );
jim_float f32_roundToInt( jim_float, uint_fast8_t, bool );
jim_float f32_add( jim_float, jim_float );
jim_float f32_sub( jim_float, jim_float );
jim_float f32_mul( jim_float, jim_float );
jim_float f32_mulAdd( jim_float, jim_float, jim_float );
jim_float f32_div( jim_float, jim_float );
jim_float f32_rem( jim_float, jim_float );
jim_float f32_sqrt( jim_float );
bool f32_eq( jim_float, jim_float );
bool f32_le( jim_float, jim_float );
bool f32_lt( jim_float, jim_float );
bool f32_eq_signaling( jim_float, jim_float );
bool f32_le_quiet( jim_float, jim_float );
bool f32_lt_quiet( jim_float, jim_float );
bool f32_isSignalingNaN( jim_float );

/*----------------------------------------------------------------------------
| 64-bit (double-precision) floating-point operations.
*----------------------------------------------------------------------------*/
uint_fast32_t jim_f64_to_ui32( jim_double, uint_fast8_t, bool );
uint_fast64_t jim_f64_to_ui64( jim_double, uint_fast8_t, bool );
int_fast32_t jim_f64_to_i32( jim_double, uint_fast8_t, bool );
int_fast64_t jim_f64_to_i64( jim_double, uint_fast8_t, bool );
uint_fast32_t jim_f64_to_ui32_r_minMag( jim_double, bool );
uint_fast64_t jim_f64_to_ui64_r_minMag( jim_double, bool );
int_fast32_t jim_f64_to_i32_r_minMag( jim_double, bool );
int_fast64_t jim_f64_to_i64_r_minMag( jim_double, bool );
jim_float jim_f64_to_f32( jim_double );
jim_double f64_roundToInt( jim_double, uint_fast8_t, bool );
jim_double f64_add( jim_double, jim_double );
jim_double f64_sub( jim_double, jim_double );
jim_double f64_mul( jim_double, jim_double );
jim_double f64_mulAdd( jim_double, jim_double, jim_double );
jim_double f64_div( jim_double, jim_double );
jim_double f64_rem( jim_double, jim_double );
jim_double f64_sqrt( jim_double );
bool f64_eq( jim_double, jim_double );
bool f64_le( jim_double, jim_double );
bool f64_lt( jim_double, jim_double );
bool f64_eq_signaling( jim_double, jim_double );
bool f64_le_quiet( jim_double, jim_double );
bool f64_lt_quiet( jim_double, jim_double );
bool f64_isSignalingNaN( jim_double );

#endif

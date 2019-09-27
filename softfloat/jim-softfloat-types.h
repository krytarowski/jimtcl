
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

#ifndef JIM_SOFTFLOAT_TYPES_H
#define JIM_SOFTFLOAT_TYPES_H

#include "jim.h"

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
| Compat types
*----------------------------------------------------------------------------*/

typedef unsigned char jim_uint_fast8_t;
typedef unsigned short jim_uint_fast16_t;
typedef unsigned int jim_uint_fast32_t;
typedef unsigned long long jim_uint_fast64_t;

typedef signed char jim_int_fast8_t;
typedef signed short jim_int_fast16_t;
typedef signed int jim_int_fast32_t;
typedef signed long long jim_int_fast64_t;

typedef int jim_bool;

typedef jim_float jim_float32_t;
typedef jim_double jim_float64_t;

#endif

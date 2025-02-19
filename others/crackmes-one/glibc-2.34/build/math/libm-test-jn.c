/* Test jn.
   Copyright (C) 1997-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include "libm-test-driver.c"

static const struct test_if_f_data jn_test_data[] =
  {
    /* jn is the Bessel function of the first kind of order n.  */
    /* jn (0, x) == j0 (x)  */
    { "0, qNaN", 0, qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, -qNaN", 0, -qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "0, sNaN", 0, snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "0, -sNaN", 0, -snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "0, inf", 0, plus_infty, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },
    { "0, -inf", 0, minus_infty, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },

    /* jn (1, x) == j1 (x)  */
    { "1, qNaN", 1, qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1, -qNaN", 1, -qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "1, sNaN", 1, snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "1, -sNaN", 1, -snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "1, inf", 1, plus_infty, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },
    { "1, -inf", 1, minus_infty, { minus_zero, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { minus_zero, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { minus_zero, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { minus_zero, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },

    /* jn (3, x)  */
    { "3, qNaN", 3, qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "3, -qNaN", 3, -qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "3, sNaN", 3, snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "3, -sNaN", 3, -snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "3, inf", 3, plus_infty, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },
    { "3, -inf", 3, minus_infty, { minus_zero, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { minus_zero, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { minus_zero, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { minus_zero, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },

    /*  jn (10, x)  */
    { "10, qNaN", 10, qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10, -qNaN", 10, -qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "10, sNaN", 10, snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "10, -sNaN", 10, -snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "10, inf", 10, plus_infty, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },
    { "10, -inf", 10, minus_infty, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN }, { 0, ERRNO_UNCHANGED|IGNORE_ZERO_INF_SIGN } },

#if (TEST_COND_binary128)
    { "-1, -0x1p+0", -1, LIT (-0x1p+0), { LIT (0x7.0a727ba5c31b14d8b9e34019007p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e340190074p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e34019007p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e340190074p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-1, 0x1p+0", -1, LIT (0x1p+0), { LIT (-0x7.0a727ba5c31b14d8b9e340190074p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e340190074p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019007p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019007p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-2, -0x1p+0", -2, LIT (-0x1p+0), { LIT (0x1.d6a5095fa9be67e2592e1f1c667cp-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c667dp-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c667cp-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c667dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-2, 0x1p+0", -2, LIT (0x1p+0), { LIT (0x1.d6a5095fa9be67e2592e1f1c667cp-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c667dp-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c667cp-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c667dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-3, -0x1p+0", -3, LIT (-0x1p+0), { LIT (0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c589981p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-3, 0x1p+0", -3, LIT (0x1p+0), { LIT (-0x5.021a9d8e3de8ab0aad53c589981p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-4, -0x1p+0", -4, LIT (-0x1p+0), { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af7328808p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-4, 0x1p+0", -4, LIT (0x1p+0), { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af7328808p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0", 0, LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x1p+0", 0, LIT (-0x1p+0), { LIT (0xc.3e3fedebdc77c1cf1a9861159a6p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159a68p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159a6p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159a68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x2p-16384", 0, LIT (-0x2p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x4p+0", 0, LIT (-0x4p+0), { LIT (-0x6.5ab9c24fa53e5cd1657dfde87d9cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87d9cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87d98p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87d98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x4p-1024", 0, LIT (-0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x4p-1076", 0, LIT (-0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x4p-128", 0, LIT (-0x4p-128), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x4p-16384", 0, LIT (-0x4p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x4p-16448", 0, LIT (-0x4p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x4p-16496", 0, LIT (-0x4p-16496), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x8p-152", 0, LIT (-0x8p-152), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x8p-16448", 0, LIT (-0x8p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, -0x8p-972", 0, LIT (-0x8p-972), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, +0", 0, LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x1.8p+0", 0, LIT (0x1.8p+0), { LIT (0x8.30723674b28d6ea4efdbfbb4b748p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6ea4efdbfbb4b75p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6ea4efdbfbb4b748p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6ea4efdbfbb4b75p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x1p+0", 0, LIT (0x1p+0), { LIT (0xc.3e3fedebdc77c1cf1a9861159a6p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159a68p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159a6p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159a68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x2p+0", 0, LIT (0x2p+0), { LIT (0x3.950e7f6499def91adac0afbc5d8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91adac0afbc5d8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91adac0afbc5d8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91adac0afbc5d8ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x2p-16384", 0, LIT (0x2p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x2p-4", 0, LIT (0x2p-4), { LIT (0xf.f003ff8e3fffb730abe3bbf5da78p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb730abe3bbf5da78p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb730abe3bbf5da78p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb730abe3bbf5da8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x4p+0", 0, LIT (0x4p+0), { LIT (-0x6.5ab9c24fa53e5cd1657dfde87d9cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87d9cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87d98p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87d98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x4p-1024", 0, LIT (0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x4p-1076", 0, LIT (0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x4p-128", 0, LIT (0x4p-128), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x4p-16384", 0, LIT (0x4p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x4p-16448", 0, LIT (0x4p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x4p-16496", 0, LIT (0x4p-16496), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x8p+0", 0, LIT (0x8p+0), { LIT (0x2.bf14eaafce04a587ded211e82082p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a587ded211e82084p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a587ded211e82082p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a587ded211e82084p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x8p-152", 0, LIT (0x8p-152), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x8p-16448", 0, LIT (0x8p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0x8p-972", 0, LIT (0x8p-972), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0xap+0", 0, LIT (0xap+0), { LIT (-0x3.ef5a5713c3ca70644304d7022888p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca70644304d7022886p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca70644304d7022886p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca70644304d7022886p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0, 0xcp-4", 0, LIT (0xcp-4), { LIT (0xd.d3efb53a950c68ecf70068c9937p-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68ecf70068c9937p-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68ecf70068c9937p-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68ecf70068c99378p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, -0", 1, LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x1p+0", 1, LIT (-0x1p+0), { LIT (-0x7.0a727ba5c31b14d8b9e340190074p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e340190074p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019007p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019007p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x2p-16384", 1, LIT (-0x2p-16384), { LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0xf.ffffffffffffffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (-0xf.ffffffffffffffffffffffffffcp-16388), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x4p-1024", 1, LIT (-0x4p-1024), { LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (-0x1.ffffffffffffffffffffffffffffp-1024), ERRNO_UNCHANGED }, { LIT (-0x1.ffffffffffffffffffffffffffffp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x4p-1076", 1, LIT (-0x4p-1076), { LIT (-0x2p-1076), ERRNO_UNCHANGED }, { LIT (-0x2p-1076), ERRNO_UNCHANGED }, { LIT (-0x1.ffffffffffffffffffffffffffffp-1076), ERRNO_UNCHANGED }, { LIT (-0x1.ffffffffffffffffffffffffffffp-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x4p-128", 1, LIT (-0x4p-128), { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x1.ffffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (-0x1.ffffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x4p-16384", 1, LIT (-0x4p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x4p-16448", 1, LIT (-0x4p-16448), { LIT (-0x2p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffcp-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x4p-16496", 1, LIT (-0x4p-16496), { LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x8p-152", 1, LIT (-0x8p-152), { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x8p-16448", 1, LIT (-0x8p-16448), { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, -0x8p-972", 1, LIT (-0x8p-972), { LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, +0", 1, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x1.8p+0", 1, LIT (0x1.8p+0), { LIT (0x8.ed4ed4eb7e408aa88a07549300b8p-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408aa88a07549300cp-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408aa88a07549300b8p-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408aa88a07549300cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x1p+0", 1, LIT (0x1p+0), { LIT (0x7.0a727ba5c31b14d8b9e34019007p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e340190074p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e34019007p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e340190074p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x2p+0", 1, LIT (0x2p+0), { LIT (0x9.3a43cac1b8f7ed7b828f5f282b5p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed7b828f5f282b5p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed7b828f5f282b5p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed7b828f5f282b58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x2p-16384", 1, LIT (0x2p-16384), { LIT (0xf.ffffffffffffffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x2p-4", 1, LIT (0x2p-4), { LIT (0xf.f8015538e4fa43825ff72a8a0bdp-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa43825ff72a8a0bdp-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa43825ff72a8a0bdp-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa43825ff72a8a0bd8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x4p-1024", 1, LIT (0x4p-1024), { LIT (0x1.ffffffffffffffffffffffffffffp-1024), ERRNO_UNCHANGED }, { LIT (0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-1024), ERRNO_UNCHANGED }, { LIT (0x2p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x4p-1076", 1, LIT (0x4p-1076), { LIT (0x1.ffffffffffffffffffffffffffffp-1076), ERRNO_UNCHANGED }, { LIT (0x2p-1076), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-1076), ERRNO_UNCHANGED }, { LIT (0x2p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x4p-128", 1, LIT (0x4p-128), { LIT (0x1.ffffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x4p-16384", 1, LIT (0x4p-16384), { LIT (0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x4p-16448", 1, LIT (0x4p-16448), { LIT (0x1.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x4p-16496", 1, LIT (0x4p-16496), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x8p+0", 1, LIT (0x8p+0), { LIT (0x3.c1120ac30c305a93c61d86d25d24p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a93c61d86d25d24p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a93c61d86d25d24p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a93c61d86d25d26p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x8p-152", 1, LIT (0x8p-152), { LIT (0x3.fffffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x8p-16448", 1, LIT (0x8p-16448), { LIT (0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "1, 0x8p-972", 1, LIT (0x8p-972), { LIT (0x3.fffffffffffffffffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x4p-972), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0xap+0", 1, LIT (0xap+0), { LIT (0xb.2107a710048861578f0a8f4f2bf8p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a710048861578f0a8f4f2bf8p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a710048861578f0a8f4f2bf8p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a710048861578f0a8f4f2cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "1, 0xcp-4", 1, LIT (0xcp-4), { LIT (0x5.9680759ada2f1ddd24ac845bcc0cp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1ddd24ac845bcc0cp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1ddd24ac845bcc0cp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1ddd24ac845bcc1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x1p+0", 10, LIT (-0x1p+0), { LIT (0x1.213d3baa4f2958d9d02fd1c84b77p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b77p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b77p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b78p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x2p-16384", 10, LIT (-0x2p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x4p-1024", 10, LIT (-0x4p-1024), { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-10252), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x4p-1076", 10, LIT (-0x4p-1076), { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-10772), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x4p-128", 10, LIT (-0x4p-128), { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-1292), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x4p-16384", 10, LIT (-0x4p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x4p-16448", 10, LIT (-0x4p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x4p-16496", 10, LIT (-0x4p-16496), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x8p-152", 10, LIT (-0x8p-152), { LIT (0x4.9f93edde27d71cbbc05b4fa999ep-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999e4p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999ep-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999e4p-1524), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x8p-16448", 10, LIT (-0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, -0x8p-972", 10, LIT (-0x8p-972), { LIT (0x4.9f93edde27d71cbbc05b4fa999ep-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999e4p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999ep-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999e4p-9724), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, +0", 10, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x1p+0", 10, LIT (0x1p+0), { LIT (0x1.213d3baa4f2958d9d02fd1c84b77p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b77p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b77p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b78p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x2p+0", 10, LIT (0x2p+0), { LIT (0x4.3859a588db86b2abf118b634e7d8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2abf118b634e7d8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2abf118b634e7d8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2abf118b634e7dcp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x2p-16384", 10, LIT (0x2p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x2p-4", 10, LIT (0x2p-4), { LIT (0x4.9f28594420d0db24be7085a75f2cp-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db24be7085a75f3p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db24be7085a75f2cp-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db24be7085a75f3p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x4p-1024", 10, LIT (0x4p-1024), { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-10252), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x4p-1076", 10, LIT (0x4p-1076), { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-10772), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x4p-128", 10, LIT (0x4p-128), { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6678p-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ef016d3ea6679p-1292), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x4p-16384", 10, LIT (0x4p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x4p-16448", 10, LIT (0x4p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x4p-16496", 10, LIT (0x4p-16496), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x8p-152", 10, LIT (0x8p-152), { LIT (0x4.9f93edde27d71cbbc05b4fa999ep-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999e4p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999ep-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999e4p-1524), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x8p-16448", 10, LIT (0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "10, 0x8p-972", 10, LIT (0x8p-972), { LIT (0x4.9f93edde27d71cbbc05b4fa999ep-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999e4p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999ep-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cbbc05b4fa999e4p-9724), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0xap+0", 10, LIT (0xap+0), { LIT (0x3.51dcf3a5d595f32918e1e89dda18p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f32918e1e89dda18p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f32918e1e89dda18p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f32918e1e89dda1ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "10, 0xcp-4", 10, LIT (0xcp-4), { LIT (0x1.0737a10f99b90732aa4c2ac32d5p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732aa4c2ac32d51p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732aa4c2ac32d5p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732aa4c2ac32d51p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a4p+0", 2, LIT (0x2.67a2a4p+0), { LIT (0x6.e877b5d4dc1402af1a88bb1c2edcp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402af1a88bb1c2edcp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402af1a88bb1c2edcp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402af1a88bb1c2eep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a5d2e36800fce3e16f10ca66p+0", 2, LIT (0x2.67a2a5d2e36800fce3e16f10ca66p+0), { LIT (0x6.e877ba80a524fcee5679bdeb0ec4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0ec8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0ec4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0ec8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a5d2e36800fce3e16f10ca68p+0", 2, LIT (0x2.67a2a5d2e36800fce3e16f10ca68p+0), { LIT (0x6.e877ba80a524fcee5679bdeb0eccp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0eccp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0eccp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0edp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a5d2e36800fce3e16f10cap+0", 2, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x6.e877ba80a524fcee5679bdeb0dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0dc4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0dc4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 2, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x6.e877ba80a524fcee5679bdeb105p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb105p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb105p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb1054p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a5d2e36800fcp+0", 2, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x6.e877ba80a524fcec0ed507b6f79cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcec0ed507b6f79cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcec0ed507b6f79cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcec0ed507b6f7ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a5d2e36801p+0", 2, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x6.e877ba80a524fcf64d7b315ea6c4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf64d7b315ea6c4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf64d7b315ea6c4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf64d7b315ea6c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a5d2e3682p+0", 2, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.e877ba80a5254c5bd53e04ec11a8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c5bd53e04ec11acp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c5bd53e04ec11a8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c5bd53e04ec11acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a5d2e368p+0", 2, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.e877ba80a524fa66a3f0c772dcecp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa66a3f0c772dcecp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa66a3f0c772dcecp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa66a3f0c772dcfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x2.67a2a8p+0", 2, LIT (0x2.67a2a8p+0), { LIT (0x6.e877c013823b69d4ce163ac993b4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d4ce163ac993b4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d4ce163ac993b4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d4ce163ac993b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x8p+1020", 2, LIT (0x8p+1020), { LIT (0x3.5c4f847797f2fb0411a8a82ca028p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb0411a8a82ca028p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb0411a8a82ca028p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb0411a8a82ca02ap-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x8p+124", 2, LIT (0x8p+124), { LIT (-0x1.1f0b5f972511213d156ea4060903p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213d156ea4060903p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213d156ea4060902p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213d156ea4060902p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0x8p+16380", 2, LIT (0x8p+16380), { LIT (-0x1.0bab81cdff9208215a7577214c4ap-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff9208215a7577214c49p-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff9208215a7577214c49p-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff9208215a7577214c49p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0xf.fffb1p+96", 2, LIT (0xf.fffb1p+96), { LIT (-0x1.ffbc8bdea325a0a6acac69a1ecf9p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6acac69a1ecf9p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6acac69a1ecf8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6acac69a1ecf8p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0xf.ffffffffffff8p+1020", 2, LIT (0xf.ffffffffffff8p+1020), { LIT (0x8.fb6ce7294f33633a6933acbe27p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33633a6933acbe27p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33633a6933acbe27p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33633a6933acbe2708p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0xf.ffffffffffffbffffffffffffcp+1020", 2, LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.a80d0ee91ce259a722e1f0190238p-516), ERRNO_UNCHANGED }, { LIT (0xb.a80d0ee91ce259a722e1f0190238p-516), ERRNO_UNCHANGED }, { LIT (0xb.a80d0ee91ce259a722e1f0190238p-516), ERRNO_UNCHANGED }, { LIT (0xb.a80d0ee91ce259a722e1f019024p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "2, 0xf.fffffp+124", 2, LIT (0xf.fffffp+124), { LIT (-0x2.fd3fa9dee0899291bc853ffc5616p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee0899291bc853ffc5614p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee0899291bc853ffc5614p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee0899291bc853ffc5614p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, -0x1p+0", 3, LIT (-0x1p+0), { LIT (-0x5.021a9d8e3de8ab0aad53c589981p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, +0", 3, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x1p+0", 3, LIT (0x1p+0), { LIT (0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c589980cp-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c589981p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a4p+0", 3, LIT (0x2.67a2a4p+0), { LIT (0x3.2f1a80fbe12c0d39ed8c1d8cce62p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d39ed8c1d8cce62p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d39ed8c1d8cce62p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d39ed8c1d8cce64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a5d2e36800fce3e16f10ca66p+0", 3, LIT (0x2.67a2a5d2e36800fce3e16f10ca66p+0), { LIT (0x3.2f1a8656b1ac6923b62403c2607ap-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c2607cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c2607ap-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c2607cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a5d2e36800fce3e16f10ca68p+0", 3, LIT (0x2.67a2a5d2e36800fce3e16f10ca68p+0), { LIT (0x3.2f1a8656b1ac6923b62403c2608p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c2608p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c2608p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c26082p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a5d2e36800fce3e16f10cap+0", 3, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x3.2f1a8656b1ac6923b62403c25f4ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c25f5p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c25f4ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c25f5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 3, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x3.2f1a8656b1ac6923b62403c2623ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c2624p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c2623ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c2624p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a5d2e36800fcp+0", 3, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x3.2f1a8656b1ac692119118273112cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692119118273112cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692119118273112cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692119118273112ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a5d2e36801p+0", 3, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x3.2f1a8656b1ac692cd7995dbdf3a2p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cd7995dbdf3a4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cd7995dbdf3a2p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cd7995dbdf3a4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a5d2e3682p+0", 3, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x3.2f1a8656b1acc431747ce21909d4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc431747ce21909d6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc431747ce21909d4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc431747ce21909d6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a5d2e368p+0", 3, LIT (0x2.67a2a5d2e368p+0), { LIT (0x3.2f1a8656b1ac663d35a28b05560cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663d35a28b05560ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663d35a28b05560cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663d35a28b05560ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2.67a2a8p+0", 3, LIT (0x2.67a2a8p+0), { LIT (0x3.2f1a8cba6907bb6218bedbdc8ee4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb6218bedbdc8ee6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb6218bedbdc8ee4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb6218bedbdc8ee6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2p+0", 3, LIT (0x2p+0), { LIT (0x2.1026cbf88539fb45cd0dffaf7038p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb45cd0dffaf703ap-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb45cd0dffaf7038p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb45cd0dffaf703ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0x2p-4", 3, LIT (0x2p-4), { LIT (0x2.aa0011101e5fe5c6e5fdd8a1ee1ep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c6e5fdd8a1ee1ep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c6e5fdd8a1ee1ep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c6e5fdd8a1ee2p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0xap+0", 3, LIT (0xap+0), { LIT (0xe.f1f374e06602c7ac005cf0b07eb8p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7ac005cf0b07eb8p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7ac005cf0b07eb8p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7ac005cf0b07ecp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "3, 0xcp-4", 3, LIT (0xcp-4), { LIT (0x2.2c085554665b098a31fc3a7224dp-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098a31fc3a7224dp-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098a31fc3a7224dp-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098a31fc3a7224d2p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a4p+0", 4, LIT (0x2.67a2a4p+0), { LIT (0x1.0933ca3121ef34ed2012c04120bcp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34ed2012c04120bdp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34ed2012c04120bcp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34ed2012c04120bdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a5d2e36800fce3e16f10ca66p+0", 4, LIT (0x2.67a2a5d2e36800fce3e16f10ca66p+0), { LIT (0x1.0933ccdb33e9d0fac17bf7b397aep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b397aep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b397aep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b397afp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a5d2e36800fce3e16f10ca68p+0", 4, LIT (0x2.67a2a5d2e36800fce3e16f10ca68p+0), { LIT (0x1.0933ccdb33e9d0fac17bf7b397b1p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b397b1p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b397b1p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b397b2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a5d2e36800fce3e16f10cap+0", 4, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x1.0933ccdb33e9d0fac17bf7b39719p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b39719p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b39719p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b3971ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 4, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x1.0933ccdb33e9d0fac17bf7b3988fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b3988fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b3988fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b3989p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a5d2e36800fcp+0", 4, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x1.0933ccdb33e9d0f97493ab0ed3b3p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0f97493ab0ed3b4p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0f97493ab0ed3b3p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0f97493ab0ed3b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a5d2e36801p+0", 4, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x1.0933ccdb33e9d0ff4c85fbc9f2ccp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0ff4c85fbc9f2cdp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0ff4c85fbc9f2ccp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0ff4c85fbc9f2cdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a5d2e3682p+0", 4, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x1.0933ccdb33e9fe48e277a5faf45cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48e277a5faf45cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48e277a5faf45cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48e277a5faf45dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a5d2e368p+0", 4, LIT (0x2.67a2a5d2e368p+0), { LIT (0x1.0933ccdb33e9cf894ff1cd022ca1p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf894ff1cd022ca2p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf894ff1cd022ca1p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf894ff1cd022ca2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "4, 0x2.67a2a8p+0", 4, LIT (0x2.67a2a8p+0), { LIT (0x1.0933d0091440ccac79775018468cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccac79775018468dp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccac79775018468cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccac79775018468dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a4p+0", 5, LIT (0x2.67a2a4p+0), { LIT (0x4.3215d1403d64260fb600f2449d74p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64260fb600f2449d78p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64260fb600f2449d74p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64260fb600f2449d78p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a5d2e36800fce3e16f10ca66p+0", 5, LIT (0x2.67a2a5d2e36800fce3e16f10ca66p+0), { LIT (0x4.3215df92220122e7748f1e2e7858p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7858p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7858p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e785cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a5d2e36800fce3e16f10ca68p+0", 5, LIT (0x2.67a2a5d2e36800fce3e16f10ca68p+0), { LIT (0x4.3215df92220122e7748f1e2e7868p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7868p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7868p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e786cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a5d2e36800fce3e16f10cap+0", 5, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x4.3215df92220122e7748f1e2e7538p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7538p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7538p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e753cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 5, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x4.3215df92220122e7748f1e2e7d1p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7d14p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7d1p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7d14p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a5d2e36800fcp+0", 5, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x4.3215df92220122e0774bcacdde54p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e0774bcacdde58p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e0774bcacdde54p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e0774bcacdde58p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a5d2e36801p+0", 5, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x4.3215df92220122ffdf7ea63b6f78p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ffdf7ea63b6f78p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ffdf7ea63b6f78p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ffdf7ea63b6f7cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a5d2e3682p+0", 5, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x4.3215df922202166769a33760502p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202166769a33760502p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202166769a33760502p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202166769a337605024p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a5d2e368p+0", 5, LIT (0x2.67a2a5d2e368p+0), { LIT (0x4.3215df9222011b25d2c7cad726dp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b25d2c7cad726d4p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b25d2c7cad726dp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b25d2c7cad726d4p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "5, 0x2.67a2a8p+0", 5, LIT (0x2.67a2a8p+0), { LIT (0x4.3215f0a870471a307b29df5ec01cp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a307b29df5ec02p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a307b29df5ec01cp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a307b29df5ec02p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a4p+0", 6, LIT (0x2.67a2a4p+0), { LIT (0xd.f235c4ce9085834528296300188p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce90858345282963001888p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce9085834528296300188p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce90858345282963001888p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a5d2e36800fce3e16f10ca66p+0", 6, LIT (0x2.67a2a5d2e36800fce3e16f10ca66p+0), { LIT (0xd.f235ffc760bbb64cc948621e243p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e2438p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e243p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e2438p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a5d2e36800fce3e16f10ca68p+0", 6, LIT (0x2.67a2a5d2e36800fce3e16f10ca68p+0), { LIT (0xd.f235ffc760bbb64cc948621e247p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e2478p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e247p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e2478p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a5d2e36800fce3e16f10cap+0", 6, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0xd.f235ffc760bbb64cc948621e175p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e175p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e175p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e1758p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 6, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0xd.f235ffc760bbb64cc948621e37a8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e37a8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e37a8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e37bp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a5d2e36800fcp+0", 6, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0xd.f235ffc760bbb63000c5c66e6a78p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63000c5c66e6a8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63000c5c66e6a78p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63000c5c66e6a8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a5d2e36801p+0", 6, LIT (0x2.67a2a5d2e36801p+0), { LIT (0xd.f235ffc760bbb6b157c59c59493p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6b157c59c59493p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6b157c59c59493p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6b157c59c594938p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a5d2e3682p+0", 6, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.f235ffc760bfa113967f78979b68p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa113967f78979b68p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa113967f78979b68p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa113967f78979b7p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a5d2e368p+0", 6, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.f235ffc760bb965b97d021a19cdp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb965b97d021a19cd8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb965b97d021a19cdp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb965b97d021a19cd8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "6, 0x2.67a2a8p+0", 6, LIT (0x2.67a2a8p+0), { LIT (0xd.f2364625908550a2021a5c597718p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550a2021a5c59772p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550a2021a5c597718p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550a2021a5c59772p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a4p+0", 7, LIT (0x2.67a2a4p+0), { LIT (0x2.75de01cd2ca964d00a4c077dfab4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964d00a4c077dfab4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964d00a4c077dfab4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964d00a4c077dfab6p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a5d2e36800fce3e16f10ca66p+0", 7, LIT (0x2.67a2a5d2e36800fce3e16f10ca66p+0), { LIT (0x2.75de0e2cb0b93d5bd132aa3aa1acp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa1aep-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa1acp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa1aep-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a5d2e36800fce3e16f10ca68p+0", 7, LIT (0x2.67a2a5d2e36800fce3e16f10ca68p+0), { LIT (0x2.75de0e2cb0b93d5bd132aa3aa1bap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa1bcp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa1bap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa1bcp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a5d2e36800fce3e16f10cap+0", 7, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x2.75de0e2cb0b93d5bd132aa3a9ef8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3a9efap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3a9ef8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3a9efap-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 7, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x2.75de0e2cb0b93d5bd132aa3aa5c2p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa5c2p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa5c2p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa5c4p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a5d2e36800fcp+0", 7, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x2.75de0e2cb0b93d55c72f45899032p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d55c72f45899032p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d55c72f45899032p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d55c72f45899034p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a5d2e36801p+0", 7, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x2.75de0e2cb0b93d70ea5223d304a8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d70ea5223d304aap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d70ea5223d304a8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d70ea5223d304aap-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a5d2e3682p+0", 7, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x2.75de0e2cb0ba0fc1388cdd19bf64p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fc1388cdd19bf66p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fc1388cdd19bf64p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fc1388cdd19bf66p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a5d2e368p+0", 7, LIT (0x2.67a2a5d2e368p+0), { LIT (0x2.75de0e2cb0b936a8219a9175e6d6p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8219a9175e6d6p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8219a9175e6d6p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8219a9175e6d8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "7, 0x2.67a2a8p+0", 7, LIT (0x2.67a2a8p+0), { LIT (0x2.75de1cf04f92a6f52a473bb1a996p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f52a473bb1a996p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f52a473bb1a996p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f52a473bb1a998p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a4p+0", 8, LIT (0x2.67a2a4p+0), { LIT (0x6.0a48e703faf914b831a31c6280ccp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b831a31c6280ccp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b831a31c6280ccp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b831a31c6280dp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a5d2e36800fce3e16f10ca66p+0", 8, LIT (0x2.67a2a5d2e36800fce3e16f10ca66p+0), { LIT (0x6.0a490a2a68000affa6e9591725ap-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e9591725ap-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e9591725ap-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e9591725a4p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a5d2e36800fce3e16f10ca68p+0", 8, LIT (0x2.67a2a5d2e36800fce3e16f10ca68p+0), { LIT (0x6.0a490a2a68000affa6e9591725c4p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e9591725c8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e9591725c4p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e9591725c8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a5d2e36800fce3e16f10cap+0", 8, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x6.0a490a2a68000affa6e959171dfp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959171df4p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959171dfp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959171df4p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 8, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x6.0a490a2a68000affa6e959173138p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959173138p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959173138p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e95917313cp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a5d2e36800fcp+0", 8, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x6.0a490a2a68000aee7eece044dc3p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000aee7eece044dc3p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000aee7eece044dc3p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000aee7eece044dc34p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a5d2e36801p+0", 8, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x6.0a490a2a68000b3b96ac1be0f1f4p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b3b96ac1be0f1f8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b3b96ac1be0f1f4p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b3b96ac1be0f1f8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a5d2e3682p+0", 8, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.0a490a2a680260b3a0ba158a1ef4p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260b3a0ba158a1ef8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260b3a0ba158a1ef4p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260b3a0ba158a1ef8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a5d2e368p+0", 8, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.0a490a2a67fff7f5a6dd34db8034p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f5a6dd34db8034p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f5a6dd34db8034p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f5a6dd34db8038p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "8, 0x2.67a2a8p+0", 8, LIT (0x2.67a2a8p+0), { LIT (0x6.0a49341bba59e67ed8dd8194c32cp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e67ed8dd8194c33p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e67ed8dd8194c32cp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e67ed8dd8194c33p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a4p+0", 9, LIT (0x2.67a2a4p+0), { LIT (0xd.2013f924ba500bb0e7f429c0cbdp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bb0e7f429c0cbdp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bb0e7f429c0cbdp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bb0e7f429c0cbd8p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a5d2e36800fce3e16f10ca66p+0", 9, LIT (0x2.67a2a5d2e36800fce3e16f10ca66p+0), { LIT (0xd.20144fd00b01a7f534e9c14b57f8p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b57f8p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b57f8p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b58p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a5d2e36800fce3e16f10ca68p+0", 9, LIT (0x2.67a2a5d2e36800fce3e16f10ca68p+0), { LIT (0xd.20144fd00b01a7f534e9c14b5858p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b5858p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b5858p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b586p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a5d2e36800fce3e16f10cap+0", 9, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0xd.20144fd00b01a7f534e9c14b4508p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b451p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b4508p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b451p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 9, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0xd.20144fd00b01a7f534e9c14b749p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b749p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b749p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b7498p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a5d2e36800fcp+0", 9, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0xd.20144fd00b01a7cae7a4981cbc78p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7cae7a4981cbc8p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7cae7a4981cbc78p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7cae7a4981cbc8p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a5d2e36801p+0", 9, LIT (0x2.67a2a5d2e36801p+0), { LIT (0xd.20144fd00b01a888fdd9366ed3b8p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a888fdd9366ed3cp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a888fdd9366ed3b8p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a888fdd9366ed3cp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a5d2e3682p+0", 9, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.20144fd00b0769b515a432a40fdp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769b515a432a40fdp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769b515a432a40fdp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769b515a432a40fd8p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a5d2e368p+0", 9, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.20144fd00b01790370b1a1e9048p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01790370b1a1e90488p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01790370b1a1e9048p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01790370b1a1e90488p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "9, 0x2.67a2a8p+0", 9, LIT (0x2.67a2a8p+0), { LIT (0xd.2014b73aef58c3f33c7316090878p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3f33c731609088p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3f33c7316090878p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3f33c731609088p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-1, -0x1p+0", -1, LIT (-0x1p+0), { LIT (0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a728p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-1, 0x1p+0", -1, LIT (0x1p+0), { LIT (-0x7.0a728p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a7278p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-2, -0x1p+0", -2, LIT (-0x1p+0), { LIT (0x1.d6a508p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a50ap-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a508p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a50ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-2, 0x1p+0", -2, LIT (0x1p+0), { LIT (0x1.d6a508p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a50ap-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a508p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a50ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-3, -0x1p+0", -3, LIT (-0x1p+0), { LIT (0x5.021a98p-8), ERRNO_UNCHANGED }, { LIT (0x5.021aap-8), ERRNO_UNCHANGED }, { LIT (0x5.021a98p-8), ERRNO_UNCHANGED }, { LIT (0x5.021aap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-3, 0x1p+0", -3, LIT (0x1p+0), { LIT (-0x5.021aap-8), ERRNO_UNCHANGED }, { LIT (-0x5.021aap-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a98p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a98p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-4, -0x1p+0", -4, LIT (-0x1p+0), { LIT (0xa.24f1bp-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1bp-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1bp-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-4, 0x1p+0", -4, LIT (0x1p+0), { LIT (0xa.24f1bp-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1bp-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1bp-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, -0", 0, LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, -0x1p+0", 0, LIT (-0x1p+0), { LIT (0xc.3e3fep-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3ffp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fep-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, -0x4p+0", 0, LIT (-0x4p+0), { LIT (-0x6.5ab9c8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, -0x4p-128", 0, LIT (-0x4p-128), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, -0x8p-152", 0, LIT (-0x8p-152), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, +0", 0, LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0x1.8p+0", 0, LIT (0x1.8p+0), { LIT (0x8.30723p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723p-4), ERRNO_UNCHANGED }, { LIT (0x8.30724p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0x1p+0", 0, LIT (0x1p+0), { LIT (0xc.3e3fep-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3ffp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fep-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0x2p+0", 0, LIT (0x2p+0), { LIT (0x3.950e7cp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e8p-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7cp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0x2p-4", 0, LIT (0x2p-4), { LIT (0xf.f003fp-4), ERRNO_UNCHANGED }, { LIT (0xf.f004p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003fp-4), ERRNO_UNCHANGED }, { LIT (0xf.f004p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0x4p+0", 0, LIT (0x4p+0), { LIT (-0x6.5ab9c8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0x4p-128", 0, LIT (0x4p-128), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0x8p+0", 0, LIT (0x8p+0), { LIT (0x2.bf14e8p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14ecp-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14e8p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0x8p-152", 0, LIT (0x8p-152), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0xap+0", 0, LIT (0xap+0), { LIT (-0x3.ef5a58p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a58p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a54p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a54p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0, 0xcp-4", 0, LIT (0xcp-4), { LIT (0xd.d3efbp-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efbp-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efbp-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, -0", 1, LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, -0x1p+0", 1, LIT (-0x1p+0), { LIT (-0x7.0a728p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a7278p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, -0x4p-128", 1, LIT (-0x4p-128), { LIT (-0x2p-128), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-128), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffff8p-128), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffff8p-128), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "1, -0x8p-152", 1, LIT (-0x8p-152), { LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary32)
    { "1, +0", 1, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, 0x1.8p+0", 1, LIT (0x1.8p+0), { LIT (0x8.ed4edp-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4edp-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4edp-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4eep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, 0x1p+0", 1, LIT (0x1p+0), { LIT (0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a7278p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a728p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, 0x2p+0", 1, LIT (0x2p+0), { LIT (0x9.3a43cp-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43dp-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cp-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, 0x2p-4", 1, LIT (0x2p-4), { LIT (0xf.f8015p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8016p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, 0x4p-128", 1, LIT (0x4p-128), { LIT (0x1.fffff8p-128), UNDERFLOW_EXCEPTION }, { LIT (0x2p-128), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffff8p-128), UNDERFLOW_EXCEPTION }, { LIT (0x2p-128), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "1, 0x8p+0", 1, LIT (0x8p+0), { LIT (0x3.c11208p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120cp-4), ERRNO_UNCHANGED }, { LIT (0x3.c11208p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, 0x8p-152", 1, LIT (0x8p-152), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "1, 0xap+0", 1, LIT (0xap+0), { LIT (0xb.2107ap-8), ERRNO_UNCHANGED }, { LIT (0xb.2107ap-8), ERRNO_UNCHANGED }, { LIT (0xb.2107ap-8), ERRNO_UNCHANGED }, { LIT (0xb.2107bp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "1, 0xcp-4", 1, LIT (0xcp-4), { LIT (0x5.96807p-4), ERRNO_UNCHANGED }, { LIT (0x5.968078p-4), ERRNO_UNCHANGED }, { LIT (0x5.96807p-4), ERRNO_UNCHANGED }, { LIT (0x5.968078p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "10, -0x1p+0", 10, LIT (-0x1p+0), { LIT (0x1.213d3ap-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3cp-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3ap-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3cp-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "10, -0x4p-128", 10, LIT (-0x4p-128), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "10, -0x8p-152", 10, LIT (-0x8p-152), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "10, +0", 10, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "10, 0x1p+0", 10, LIT (0x1p+0), { LIT (0x1.213d3ap-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3cp-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3ap-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3cp-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "10, 0x2p+0", 10, LIT (0x2p+0), { LIT (0x4.3859ap-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859ap-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "10, 0x2p-4", 10, LIT (0x2p-4), { LIT (0x4.9f2858p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f2858p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f2858p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f286p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "10, 0x4p-128", 10, LIT (0x4p-128), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "10, 0x8p-152", 10, LIT (0x8p-152), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "10, 0xap+0", 10, LIT (0xap+0), { LIT (0x3.51dcfp-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf4p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcfp-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "10, 0xcp-4", 10, LIT (0xcp-4), { LIT (0x1.0737ap-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a2p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737ap-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a2p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "2, 0x2.67a2a4p+0", 2, LIT (0x2.67a2a4p+0), { LIT (0x6.e877bp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877bp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "2, 0x2.67a2a8p+0", 2, LIT (0x2.67a2a8p+0), { LIT (0x6.e877cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "2, 0x8p+124", 2, LIT (0x8p+124), { LIT (-0x1.1f0b6p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b6p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5ep-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5ep-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "2, 0xf.fffb1p+96", 2, LIT (0xf.fffb1p+96), { LIT (-0x1.ffbc8cp-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8cp-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8ap-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8ap-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "2, 0xf.fffffp+124", 2, LIT (0xf.fffffp+124), { LIT (-0x2.fd3facp-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa8p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa8p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa8p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, -0x1p+0", 3, LIT (-0x1p+0), { LIT (-0x5.021aap-8), ERRNO_UNCHANGED }, { LIT (-0x5.021aap-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a98p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a98p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, +0", 3, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, 0x1p+0", 3, LIT (0x1p+0), { LIT (0x5.021a98p-8), ERRNO_UNCHANGED }, { LIT (0x5.021aap-8), ERRNO_UNCHANGED }, { LIT (0x5.021a98p-8), ERRNO_UNCHANGED }, { LIT (0x5.021aap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, 0x2.67a2a4p+0", 3, LIT (0x2.67a2a4p+0), { LIT (0x3.2f1a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, 0x2.67a2a8p+0", 3, LIT (0x2.67a2a8p+0), { LIT (0x3.2f1a8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, 0x2p+0", 3, LIT (0x2p+0), { LIT (0x2.1026c8p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026ccp-4), ERRNO_UNCHANGED }, { LIT (0x2.1026c8p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, 0x2p-4", 3, LIT (0x2p-4), { LIT (0x2.aa001p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa001p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa001p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0014p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, 0xap+0", 3, LIT (0xap+0), { LIT (0xe.f1f37p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f37p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f37p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f38p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "3, 0xcp-4", 3, LIT (0xcp-4), { LIT (0x2.2c0854p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c0854p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c0854p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c0858p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "4, 0x2.67a2a4p+0", 4, LIT (0x2.67a2a4p+0), { LIT (0x1.0933cap-4), ERRNO_UNCHANGED }, { LIT (0x1.0933cap-4), ERRNO_UNCHANGED }, { LIT (0x1.0933cap-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "4, 0x2.67a2a8p+0", 4, LIT (0x2.67a2a8p+0), { LIT (0x1.0933dp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933dp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933dp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "5, 0x2.67a2a4p+0", 5, LIT (0x2.67a2a4p+0), { LIT (0x4.3215dp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215dp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215dp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "5, 0x2.67a2a8p+0", 5, LIT (0x2.67a2a8p+0), { LIT (0x4.3215fp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215fp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215fp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "6, 0x2.67a2a4p+0", 6, LIT (0x2.67a2a4p+0), { LIT (0xd.f235cp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235cp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235cp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235dp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "6, 0x2.67a2a8p+0", 6, LIT (0x2.67a2a8p+0), { LIT (0xd.f2364p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2365p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "7, 0x2.67a2a4p+0", 7, LIT (0x2.67a2a4p+0), { LIT (0x2.75dep-12), ERRNO_UNCHANGED }, { LIT (0x2.75dep-12), ERRNO_UNCHANGED }, { LIT (0x2.75dep-12), ERRNO_UNCHANGED }, { LIT (0x2.75de04p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "7, 0x2.67a2a8p+0", 7, LIT (0x2.67a2a8p+0), { LIT (0x2.75de1cp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de2p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "8, 0x2.67a2a4p+0", 8, LIT (0x2.67a2a4p+0), { LIT (0x6.0a48ep-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48ep-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "8, 0x2.67a2a8p+0", 8, LIT (0x2.67a2a8p+0), { LIT (0x6.0a493p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a4938p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a493p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a4938p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "9, 0x2.67a2a4p+0", 9, LIT (0x2.67a2a4p+0), { LIT (0xd.2013fp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014p-20), ERRNO_UNCHANGED }, { LIT (0xd.2013fp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "9, 0x2.67a2a8p+0", 9, LIT (0x2.67a2a8p+0), { LIT (0xd.2014bp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014bp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014bp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014cp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-1, -0x1p+0", -1, LIT (-0x1p+0), { LIT (0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-1, 0x1p+0", -1, LIT (0x1p+0), { LIT (-0x7.0a727ba5c31b4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-2, -0x1p+0", -2, LIT (-0x1p+0), { LIT (0x1.d6a5095fa9be6p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be6p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be6p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-2, 0x1p+0", -2, LIT (0x1p+0), { LIT (0x1.d6a5095fa9be6p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be6p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be6p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-3, -0x1p+0", -3, LIT (-0x1p+0), { LIT (0x5.021a9d8e3de88p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8cp-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de88p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-3, 0x1p+0", -3, LIT (0x1p+0), { LIT (-0x5.021a9d8e3de8cp-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8cp-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de88p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de88p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-4, -0x1p+0", -4, LIT (-0x1p+0), { LIT (0xa.24f1b5ad78d8p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d88p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d8p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d88p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-4, 0x1p+0", -4, LIT (0x1p+0), { LIT (0xa.24f1b5ad78d8p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d88p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d8p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d88p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, -0", 0, LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, -0x1p+0", 0, LIT (-0x1p+0), { LIT (0xc.3e3fedebdc778p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc78p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc778p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, -0x4p+0", 0, LIT (-0x4p+0), { LIT (-0x6.5ab9c24fa53e8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e4p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e4p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, -0x4p-1024", 0, LIT (-0x4p-1024), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, -0x4p-1076", 0, LIT (-0x4p-1076), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, -0x4p-128", 0, LIT (-0x4p-128), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, -0x8p-152", 0, LIT (-0x8p-152), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, -0x8p-972", 0, LIT (-0x8p-972), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, +0", 0, LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x1.8p+0", 0, LIT (0x1.8p+0), { LIT (0x8.30723674b28dp-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d8p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28dp-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x1p+0", 0, LIT (0x1p+0), { LIT (0xc.3e3fedebdc778p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc78p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc778p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x2p+0", 0, LIT (0x2p+0), { LIT (0x3.950e7f6499deep-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499dfp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499deep-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499dfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x2p-4", 0, LIT (0x2p-4), { LIT (0xf.f003ff8e3fff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x4p+0", 0, LIT (0x4p+0), { LIT (-0x6.5ab9c24fa53e8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e4p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e4p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x4p-1024", 0, LIT (0x4p-1024), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x4p-1076", 0, LIT (0x4p-1076), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x4p-128", 0, LIT (0x4p-128), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x8p+0", 0, LIT (0x8p+0), { LIT (0x2.bf14eaafce04ap-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04ap-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04ap-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x8p-152", 0, LIT (0x8p-152), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0x8p-972", 0, LIT (0x8p-972), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0xap+0", 0, LIT (0xap+0), { LIT (-0x3.ef5a5713c3ca8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca6p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0, 0xcp-4", 0, LIT (0xcp-4), { LIT (0xd.d3efb53a950cp-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c8p-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950cp-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, -0", 1, LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, -0x1p+0", 1, LIT (-0x1p+0), { LIT (-0x7.0a727ba5c31b4p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, -0x4p-1024", 1, LIT (-0x4p-1024), { LIT (-0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "1, -0x4p-1076", 1, LIT (-0x4p-1076), { LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_binary64)
    { "1, -0x4p-128", 1, LIT (-0x4p-128), { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, -0x8p-152", 1, LIT (-0x8p-152), { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, -0x8p-972", 1, LIT (-0x8p-972), { LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, +0", 1, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x1.8p+0", 1, LIT (0x1.8p+0), { LIT (0x8.ed4ed4eb7e408p-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408p-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408p-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e41p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x1p+0", 1, LIT (0x1p+0), { LIT (0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31bp-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x2p+0", 1, LIT (0x2p+0), { LIT (0x9.3a43cac1b8f78p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f8p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f78p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x2p-4", 1, LIT (0x2p-4), { LIT (0xf.f8015538e4fap-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fap-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x4p-1024", 1, LIT (0x4p-1024), { LIT (0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x4p-1076", 1, LIT (0x4p-1076), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x4p-128", 1, LIT (0x4p-128), { LIT (0x1.fffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x8p+0", 1, LIT (0x8p+0), { LIT (0x3.c1120ac30c304p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c306p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c304p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c306p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x8p-152", 1, LIT (0x8p-152), { LIT (0x3.ffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0x8p-972", 1, LIT (0x8p-972), { LIT (0x3.ffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x4p-972), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0xap+0", 1, LIT (0xap+0), { LIT (0xb.2107a7100488p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a71004888p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a7100488p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a71004888p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "1, 0xcp-4", 1, LIT (0xcp-4), { LIT (0x5.9680759ada2fp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2fp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2fp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "10, -0x1p+0", 10, LIT (-0x1p+0), { LIT (0x1.213d3baa4f295p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f296p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f295p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f296p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "10, -0x4p-1024", 10, LIT (-0x4p-1024), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, -0x4p-1076", 10, LIT (-0x4p-1076), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, -0x4p-128", 10, LIT (-0x4p-128), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, -0x8p-152", 10, LIT (-0x8p-152), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, -0x8p-972", 10, LIT (-0x8p-972), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, +0", 10, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "10, 0x1p+0", 10, LIT (0x1p+0), { LIT (0x1.213d3baa4f295p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f296p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f295p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f296p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "10, 0x2p+0", 10, LIT (0x2p+0), { LIT (0x4.3859a588db868p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86cp-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db868p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86cp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "10, 0x2p-4", 10, LIT (0x2p-4), { LIT (0x4.9f28594420d0cp-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0cp-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0cp-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d1p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "10, 0x4p-1024", 10, LIT (0x4p-1024), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, 0x4p-1076", 10, LIT (0x4p-1076), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, 0x4p-128", 10, LIT (0x4p-128), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, 0x8p-152", 10, LIT (0x8p-152), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, 0x8p-972", 10, LIT (0x8p-972), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "10, 0xap+0", 10, LIT (0xap+0), { LIT (0x3.51dcf3a5d595ep-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d596p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595ep-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d596p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "10, 0xcp-4", 10, LIT (0xcp-4), { LIT (0x1.0737a10f99b9p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b9p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b9p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b91p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0x2.67a2a4p+0", 2, LIT (0x2.67a2a4p+0), { LIT (0x6.e877b5d4dc14p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc14p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc14p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc144p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0x2.67a2a5d2e3682p+0", 2, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.e877ba80a5254p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5258p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0x2.67a2a5d2e368p+0", 2, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.e877ba80a524cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a525p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a525p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0x2.67a2a8p+0", 2, LIT (0x2.67a2a8p+0), { LIT (0x6.e877c013823b4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b4p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0x8p+1020", 2, LIT (0x8p+1020), { LIT (0x3.5c4f847797f2ep-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f3p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2ep-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f3p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0x8p+124", 2, LIT (0x8p+124), { LIT (-0x1.1f0b5f9725113p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f9725112p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f9725112p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f9725112p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0xf.fffb1p+96", 2, LIT (0xf.fffb1p+96), { LIT (-0x1.ffbc8bdea325bp-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325ap-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325ap-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325ap-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0xf.ffffffffffff8p+1020", 2, LIT (0xf.ffffffffffff8p+1020), { LIT (0x8.fb6ce7294f33p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f338p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f338p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "2, 0xf.fffffp+124", 2, LIT (0xf.fffffp+124), { LIT (-0x2.fd3fa9dee089ap-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee089ap-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee0898p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee0898p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, -0x1p+0", 3, LIT (-0x1p+0), { LIT (-0x5.021a9d8e3de8cp-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8cp-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de88p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de88p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, +0", 3, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0x1p+0", 3, LIT (0x1p+0), { LIT (0x5.021a9d8e3de88p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8cp-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de88p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0x2.67a2a4p+0", 3, LIT (0x2.67a2a4p+0), { LIT (0x3.2f1a80fbe12cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0x2.67a2a5d2e3682p+0", 3, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x3.2f1a8656b1accp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1accp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1accp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0x2.67a2a5d2e368p+0", 3, LIT (0x2.67a2a5d2e368p+0), { LIT (0x3.2f1a8656b1ac6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0x2.67a2a8p+0", 3, LIT (0x2.67a2a8p+0), { LIT (0x3.2f1a8cba6907ap-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907ap-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0x2p+0", 3, LIT (0x2p+0), { LIT (0x2.1026cbf88539ep-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf8853ap-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539ep-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf8853ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0x2p-4", 3, LIT (0x2p-4), { LIT (0x2.aa0011101e5fep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e6p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0xap+0", 3, LIT (0xap+0), { LIT (0xe.f1f374e066028p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06603p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e066028p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06603p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "3, 0xcp-4", 3, LIT (0xcp-4), { LIT (0x2.2c085554665bp-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665bp-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665bp-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b2p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "4, 0x2.67a2a4p+0", 4, LIT (0x2.67a2a4p+0), { LIT (0x1.0933ca3121ef3p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef3p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef3p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "4, 0x2.67a2a5d2e3682p+0", 4, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x1.0933ccdb33e9fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33eap-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33eap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "4, 0x2.67a2a5d2e368p+0", 4, LIT (0x2.67a2a5d2e368p+0), { LIT (0x1.0933ccdb33e9cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9dp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "4, 0x2.67a2a8p+0", 4, LIT (0x2.67a2a8p+0), { LIT (0x1.0933d0091440cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440dp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440cp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "5, 0x2.67a2a4p+0", 5, LIT (0x2.67a2a4p+0), { LIT (0x4.3215d1403d64p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d644p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d644p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "5, 0x2.67a2a5d2e3682p+0", 5, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x4.3215df922202p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222024p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "5, 0x2.67a2a5d2e368p+0", 5, LIT (0x2.67a2a5d2e368p+0), { LIT (0x4.3215df922201p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922201p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922201p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222014p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "5, 0x2.67a2a8p+0", 5, LIT (0x2.67a2a8p+0), { LIT (0x4.3215f0a87047p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a87047p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a87047p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870474p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "6, 0x2.67a2a4p+0", 6, LIT (0x2.67a2a4p+0), { LIT (0xd.f235c4ce90858p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce90858p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce90858p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce9086p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "6, 0x2.67a2a5d2e3682p+0", 6, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.f235ffc760bf8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bf8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bf8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "6, 0x2.67a2a5d2e368p+0", 6, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.f235ffc760bb8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb8p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bcp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "6, 0x2.67a2a8p+0", 6, LIT (0x2.67a2a8p+0), { LIT (0xd.f23646259085p-12), ERRNO_UNCHANGED }, { LIT (0xd.f236462590858p-12), ERRNO_UNCHANGED }, { LIT (0xd.f23646259085p-12), ERRNO_UNCHANGED }, { LIT (0xd.f236462590858p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "7, 0x2.67a2a4p+0", 7, LIT (0x2.67a2a4p+0), { LIT (0x2.75de01cd2ca96p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca96p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca96p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca98p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "7, 0x2.67a2a5d2e3682p+0", 7, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x2.75de0e2cb0bap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0bap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0bap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba2p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "7, 0x2.67a2a5d2e368p+0", 7, LIT (0x2.67a2a5d2e368p+0), { LIT (0x2.75de0e2cb0b92p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b94p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b92p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b94p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "7, 0x2.67a2a8p+0", 7, LIT (0x2.67a2a8p+0), { LIT (0x2.75de1cf04f92ap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92ap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92ap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "8, 0x2.67a2a4p+0", 8, LIT (0x2.67a2a4p+0), { LIT (0x6.0a48e703faf9p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf9p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf9p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf94p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "8, 0x2.67a2a5d2e3682p+0", 8, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.0a490a2a68024p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68028p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68024p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68028p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "8, 0x2.67a2a5d2e368p+0", 8, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.0a490a2a67ffcp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67ffcp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "8, 0x2.67a2a8p+0", 8, LIT (0x2.67a2a8p+0), { LIT (0x6.0a49341bba59cp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba5ap-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59cp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba5ap-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "9, 0x2.67a2a4p+0", 9, LIT (0x2.67a2a4p+0), { LIT (0xd.2013f924ba5p-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba5p-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba5p-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba508p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "9, 0x2.67a2a5d2e3682p+0", 9, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.20144fd00b07p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b078p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b07p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b078p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "9, 0x2.67a2a5d2e368p+0", 9, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.20144fd00b01p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b018p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b018p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "9, 0x2.67a2a8p+0", 9, LIT (0x2.67a2a8p+0), { LIT (0xd.2014b73aef588p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef59p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef588p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef59p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-1, -0x1p+0", -1, LIT (-0x1p+0), { LIT (0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e3401902p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-1, 0x1p+0", -1, LIT (0x1p+0), { LIT (-0x7.0a727ba5c31b14d8b9e3401902p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-2, -0x1p+0", -2, LIT (-0x1p+0), { LIT (0x1.d6a5095fa9be67e2592e1f1c66p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c668p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c66p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c668p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-2, 0x1p+0", -2, LIT (0x1p+0), { LIT (0x1.d6a5095fa9be67e2592e1f1c66p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c668p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c66p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2592e1f1c668p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-3, -0x1p+0", -3, LIT (-0x1p+0), { LIT (0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c5899ap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-3, 0x1p+0", -3, LIT (0x1p+0), { LIT (-0x5.021a9d8e3de8ab0aad53c5899ap-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-4, -0x1p+0", -4, LIT (-0x1p+0), { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af7328cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-4, 0x1p+0", -4, LIT (0x1p+0), { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af73288p-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841a7d14af7328cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, -0", 0, LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, -0x1p+0", 0, LIT (-0x1p+0), { LIT (0xc.3e3fedebdc77c1cf1a98611598p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a98611598p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, -0x4p+0", 0, LIT (-0x4p+0), { LIT (-0x6.5ab9c24fa53e5cd1657dfde87ep-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87ep-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, -0x4p-1024", 0, LIT (-0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, -0x4p-1076", 0, LIT (-0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, -0x4p-128", 0, LIT (-0x4p-128), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, -0x8p-152", 0, LIT (-0x8p-152), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, -0x8p-972", 0, LIT (-0x8p-972), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, +0", 0, LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x1.8p+0", 0, LIT (0x1.8p+0), { LIT (0x8.30723674b28d6ea4efdbfbb4b4p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6ea4efdbfbb4b8p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6ea4efdbfbb4b4p-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6ea4efdbfbb4b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x1p+0", 0, LIT (0x1p+0), { LIT (0xc.3e3fedebdc77c1cf1a98611598p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a98611598p-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cf1a9861159cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x2p+0", 0, LIT (0x2p+0), { LIT (0x3.950e7f6499def91adac0afbc5dp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91adac0afbc5ep-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91adac0afbc5dp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91adac0afbc5ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x2p-4", 0, LIT (0x2p-4), { LIT (0xf.f003ff8e3fffb730abe3bbf5d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb730abe3bbf5dcp-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb730abe3bbf5d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb730abe3bbf5dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x4p+0", 0, LIT (0x4p+0), { LIT (-0x6.5ab9c24fa53e5cd1657dfde87ep-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87ep-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cd1657dfde87cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x4p-1024", 0, LIT (0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x4p-1076", 0, LIT (0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x4p-128", 0, LIT (0x4p-128), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x8p+0", 0, LIT (0x8p+0), { LIT (0x2.bf14eaafce04a587ded211e82p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a587ded211e821p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a587ded211e82p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a587ded211e821p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x8p-152", 0, LIT (0x8p-152), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0x8p-972", 0, LIT (0x8p-972), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0xap+0", 0, LIT (0xap+0), { LIT (-0x3.ef5a5713c3ca70644304d70229p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca70644304d70229p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca70644304d70228p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca70644304d70228p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0, 0xcp-4", 0, LIT (0xcp-4), { LIT (0xd.d3efb53a950c68ecf70068c99p-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68ecf70068c994p-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68ecf70068c99p-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68ecf70068c994p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, -0", 1, LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, -0x1p+0", 1, LIT (-0x1p+0), { LIT (-0x7.0a727ba5c31b14d8b9e3401902p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, -0x4p-1024", 1, LIT (-0x4p-1024), { LIT (-0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "1, -0x4p-1076", 1, LIT (-0x4p-1076), { LIT (-0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_ibm128)
    { "1, -0x4p-128", 1, LIT (-0x4p-128), { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x1.ffffffffffffffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (-0x1.ffffffffffffffffffffffffff8p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, -0x8p-152", 1, LIT (-0x8p-152), { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffffffffffffffffp-152), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffffffffffffffffp-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, -0x8p-972", 1, LIT (-0x8p-972), { LIT (-0x4p-972), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-972), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "1, +0", 1, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x1.8p+0", 1, LIT (0x1.8p+0), { LIT (0x8.ed4ed4eb7e408aa88a075493p-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408aa88a075493p-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408aa88a075493p-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408aa88a07549304p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x1p+0", 1, LIT (0x1p+0), { LIT (0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e34019p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8b9e3401902p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x2p+0", 1, LIT (0x2p+0), { LIT (0x9.3a43cac1b8f7ed7b828f5f2828p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed7b828f5f282cp-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed7b828f5f2828p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed7b828f5f282cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x2p-4", 1, LIT (0x2p-4), { LIT (0xf.f8015538e4fa43825ff72a8a08p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa43825ff72a8a0cp-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa43825ff72a8a08p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa43825ff72a8a0cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x4p-1024", 1, LIT (0x4p-1024), { LIT (0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x4p-1076", 1, LIT (0x4p-1076), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x4p-128", 1, LIT (0x4p-128), { LIT (0x1.ffffffffffffffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x8p+0", 1, LIT (0x8p+0), { LIT (0x3.c1120ac30c305a93c61d86d25dp-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a93c61d86d25dp-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a93c61d86d25dp-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a93c61d86d25ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x8p-152", 1, LIT (0x8p-152), { LIT (0x3.ffffffffffffffffffffffffffp-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffffp-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0x8p-972", 1, LIT (0x8p-972), { LIT (0x3.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION }, { LIT (0x4p-972), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION }, { LIT (0x4p-972), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0xap+0", 1, LIT (0xap+0), { LIT (0xb.2107a710048861578f0a8f4f28p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a710048861578f0a8f4f2cp-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a710048861578f0a8f4f28p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a710048861578f0a8f4f2cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "1, 0xcp-4", 1, LIT (0xcp-4), { LIT (0x5.9680759ada2f1ddd24ac845bccp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1ddd24ac845bccp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1ddd24ac845bccp-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1ddd24ac845bcep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "10, -0x1p+0", 10, LIT (-0x1p+0), { LIT (0x1.213d3baa4f2958d9d02fd1c84bp-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84bp-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b8p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "10, -0x4p-1024", 10, LIT (-0x4p-1024), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, -0x4p-1076", 10, LIT (-0x4p-1076), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, -0x4p-128", 10, LIT (-0x4p-128), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, -0x8p-152", 10, LIT (-0x8p-152), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, -0x8p-972", 10, LIT (-0x8p-972), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, +0", 10, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0x1p+0", 10, LIT (0x1p+0), { LIT (0x1.213d3baa4f2958d9d02fd1c84bp-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84bp-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d9d02fd1c84b8p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0x2p+0", 10, LIT (0x2p+0), { LIT (0x4.3859a588db86b2abf118b634e6p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2abf118b634e8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2abf118b634e6p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2abf118b634e8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0x2p-4", 10, LIT (0x2p-4), { LIT (0x4.9f28594420d0db24be7085a75ep-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db24be7085a76p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db24be7085a75ep-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db24be7085a76p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0x4p-1024", 10, LIT (0x4p-1024), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0x4p-1076", 10, LIT (0x4p-1076), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0x4p-128", 10, LIT (0x4p-128), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0x8p-152", 10, LIT (0x8p-152), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0x8p-972", 10, LIT (0x8p-972), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0xap+0", 10, LIT (0xap+0), { LIT (0x3.51dcf3a5d595f32918e1e89ddap-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f32918e1e89ddap-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f32918e1e89ddap-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f32918e1e89ddbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "10, 0xcp-4", 10, LIT (0xcp-4), { LIT (0x1.0737a10f99b90732aa4c2ac32dp-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732aa4c2ac32d8p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732aa4c2ac32dp-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732aa4c2ac32d8p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x2.67a2a4p+0", 2, LIT (0x2.67a2a4p+0), { LIT (0x6.e877b5d4dc1402af1a88bb1c2ep-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402af1a88bb1c2ep-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402af1a88bb1c2ep-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402af1a88bb1c3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x2.67a2a5d2e36800fce3e16f10cap+0", 2, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x6.e877ba80a524fcee5679bdeb0cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0ep-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0cp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb0ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 2, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x6.e877ba80a524fcee5679bdeb1p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb1p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb1p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcee5679bdeb12p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x2.67a2a5d2e36800fcp+0", 2, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x6.e877ba80a524fcec0ed507b6f6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcec0ed507b6f8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcec0ed507b6f6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcec0ed507b6f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x2.67a2a5d2e36801p+0", 2, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x6.e877ba80a524fcf64d7b315ea6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf64d7b315ea6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf64d7b315ea6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf64d7b315ea8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x2.67a2a5d2e3682p+0", 2, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.e877ba80a5254c5bd53e04ec1p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c5bd53e04ec12p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c5bd53e04ec1p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c5bd53e04ec12p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x2.67a2a5d2e368p+0", 2, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.e877ba80a524fa66a3f0c772dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa66a3f0c772dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa66a3f0c772dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa66a3f0c772dep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x2.67a2a8p+0", 2, LIT (0x2.67a2a8p+0), { LIT (0x6.e877c013823b69d4ce163ac992p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d4ce163ac994p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d4ce163ac992p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d4ce163ac994p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x8p+1020", 2, LIT (0x8p+1020), { LIT (0x3.5c4f847797f2fb0411a8a82cap-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb0411a8a82cap-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb0411a8a82cap-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb0411a8a82ca1p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0x8p+124", 2, LIT (0x8p+124), { LIT (-0x1.1f0b5f972511213d156ea406098p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213d156ea40609p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213d156ea40609p-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213d156ea40609p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0xf.fffb1p+96", 2, LIT (0xf.fffb1p+96), { LIT (-0x1.ffbc8bdea325a0a6acac69a1edp-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6acac69a1edp-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6acac69a1ec8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6acac69a1ec8p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0xf.ffffffffffff8p+1020", 2, LIT (0xf.ffffffffffff8p+1020), { LIT (0x8.fb6ce7294f33633a6933acbe24p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33633a6933acbe28p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33633a6933acbe24p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33633a6933acbe28p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0xf.ffffffffffffbffffffffffffcp+1020", 2, LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.a80d0ee91ce259a722e1f019p-516), ERRNO_UNCHANGED }, { LIT (0xb.a80d0ee91ce259a722e1f01904p-516), ERRNO_UNCHANGED }, { LIT (0xb.a80d0ee91ce259a722e1f019p-516), ERRNO_UNCHANGED }, { LIT (0xb.a80d0ee91ce259a722e1f01904p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "2, 0xf.fffffp+124", 2, LIT (0xf.fffffp+124), { LIT (-0x2.fd3fa9dee0899291bc853ffc57p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee0899291bc853ffc56p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee0899291bc853ffc56p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee0899291bc853ffc56p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, -0x1p+0", 3, LIT (-0x1p+0), { LIT (-0x5.021a9d8e3de8ab0aad53c5899ap-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, +0", 3, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x1p+0", 3, LIT (0x1p+0), { LIT (0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c58998p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab0aad53c5899ap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2.67a2a4p+0", 3, LIT (0x2.67a2a4p+0), { LIT (0x3.2f1a80fbe12c0d39ed8c1d8ccep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d39ed8c1d8ccep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d39ed8c1d8ccep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d39ed8c1d8ccfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2.67a2a5d2e36800fce3e16f10cap+0", 3, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x3.2f1a8656b1ac6923b62403c25fp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c25fp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c25fp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c26p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 3, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x3.2f1a8656b1ac6923b62403c262p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c262p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c262p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6923b62403c263p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2.67a2a5d2e36800fcp+0", 3, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x3.2f1a8656b1ac69211911827311p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac69211911827311p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac69211911827311p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac69211911827312p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2.67a2a5d2e36801p+0", 3, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x3.2f1a8656b1ac692cd7995dbdf3p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cd7995dbdf4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cd7995dbdf3p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cd7995dbdf4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2.67a2a5d2e3682p+0", 3, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x3.2f1a8656b1acc431747ce21909p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc431747ce2190ap-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc431747ce21909p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc431747ce2190ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2.67a2a5d2e368p+0", 3, LIT (0x2.67a2a5d2e368p+0), { LIT (0x3.2f1a8656b1ac663d35a28b0556p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663d35a28b0556p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663d35a28b0556p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663d35a28b0557p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2.67a2a8p+0", 3, LIT (0x2.67a2a8p+0), { LIT (0x3.2f1a8cba6907bb6218bedbdc8ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb6218bedbdc8fp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb6218bedbdc8ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb6218bedbdc8fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2p+0", 3, LIT (0x2p+0), { LIT (0x2.1026cbf88539fb45cd0dffaf7p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb45cd0dffaf7p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb45cd0dffaf7p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb45cd0dffaf71p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0x2p-4", 3, LIT (0x2p-4), { LIT (0x2.aa0011101e5fe5c6e5fdd8a1eep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c6e5fdd8a1eep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c6e5fdd8a1eep-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c6e5fdd8a1efp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0xap+0", 3, LIT (0xap+0), { LIT (0xe.f1f374e06602c7ac005cf0b07cp-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7ac005cf0b08p-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7ac005cf0b07cp-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7ac005cf0b08p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "3, 0xcp-4", 3, LIT (0xcp-4), { LIT (0x2.2c085554665b098a31fc3a7224p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098a31fc3a7225p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098a31fc3a7224p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098a31fc3a7225p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "4, 0x2.67a2a4p+0", 4, LIT (0x2.67a2a4p+0), { LIT (0x1.0933ca3121ef34ed2012c041208p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34ed2012c041208p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34ed2012c041208p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34ed2012c04121p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "4, 0x2.67a2a5d2e36800fce3e16f10cap+0", 4, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x1.0933ccdb33e9d0fac17bf7b397p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b397p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b397p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b3978p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "4, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 4, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x1.0933ccdb33e9d0fac17bf7b3988p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b3988p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b3988p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fac17bf7b399p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "4, 0x2.67a2a5d2e36800fcp+0", 4, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x1.0933ccdb33e9d0f97493ab0ed38p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0f97493ab0ed38p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0f97493ab0ed38p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0f97493ab0ed4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "4, 0x2.67a2a5d2e36801p+0", 4, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x1.0933ccdb33e9d0ff4c85fbc9f28p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0ff4c85fbc9f3p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0ff4c85fbc9f28p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0ff4c85fbc9f3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "4, 0x2.67a2a5d2e3682p+0", 4, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x1.0933ccdb33e9fe48e277a5faf4p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48e277a5faf48p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48e277a5faf4p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48e277a5faf48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "4, 0x2.67a2a5d2e368p+0", 4, LIT (0x2.67a2a5d2e368p+0), { LIT (0x1.0933ccdb33e9cf894ff1cd022c8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf894ff1cd022c8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf894ff1cd022c8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf894ff1cd022dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "4, 0x2.67a2a8p+0", 4, LIT (0x2.67a2a8p+0), { LIT (0x1.0933d0091440ccac79775018468p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccac79775018468p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccac79775018468p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccac7977501847p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "5, 0x2.67a2a4p+0", 5, LIT (0x2.67a2a4p+0), { LIT (0x4.3215d1403d64260fb600f2449cp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64260fb600f2449ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64260fb600f2449cp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64260fb600f2449ep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "5, 0x2.67a2a5d2e36800fce3e16f10cap+0", 5, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x4.3215df92220122e7748f1e2e74p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e76p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e74p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e76p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "5, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 5, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x4.3215df92220122e7748f1e2e7cp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7cp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e7748f1e2e7ep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "5, 0x2.67a2a5d2e36800fcp+0", 5, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x4.3215df92220122e0774bcacddep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e0774bcacddep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e0774bcacddep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e0774bcacdep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "5, 0x2.67a2a5d2e36801p+0", 5, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x4.3215df92220122ffdf7ea63b6ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ffdf7ea63b7p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ffdf7ea63b6ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ffdf7ea63b7p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "5, 0x2.67a2a5d2e3682p+0", 5, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x4.3215df922202166769a337605p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202166769a337605p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202166769a337605p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202166769a3376052p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "5, 0x2.67a2a5d2e368p+0", 5, LIT (0x2.67a2a5d2e368p+0), { LIT (0x4.3215df9222011b25d2c7cad726p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b25d2c7cad726p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b25d2c7cad726p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b25d2c7cad728p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "5, 0x2.67a2a8p+0", 5, LIT (0x2.67a2a8p+0), { LIT (0x4.3215f0a870471a307b29df5ecp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a307b29df5ecp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a307b29df5ecp-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a307b29df5ec2p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "6, 0x2.67a2a4p+0", 6, LIT (0x2.67a2a4p+0), { LIT (0xd.f235c4ce908583452829630018p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce908583452829630018p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce908583452829630018p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce90858345282963001cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "6, 0x2.67a2a5d2e36800fce3e16f10cap+0", 6, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0xd.f235ffc760bbb64cc948621e14p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e18p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e14p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e18p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "6, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 6, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0xd.f235ffc760bbb64cc948621e34p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e38p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e34p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64cc948621e38p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "6, 0x2.67a2a5d2e36800fcp+0", 6, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0xd.f235ffc760bbb63000c5c66e68p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63000c5c66e6cp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63000c5c66e68p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63000c5c66e6cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "6, 0x2.67a2a5d2e36801p+0", 6, LIT (0x2.67a2a5d2e36801p+0), { LIT (0xd.f235ffc760bbb6b157c59c5948p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6b157c59c5948p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6b157c59c5948p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6b157c59c594cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "6, 0x2.67a2a5d2e3682p+0", 6, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.f235ffc760bfa113967f789798p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa113967f78979cp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa113967f789798p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa113967f78979cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "6, 0x2.67a2a5d2e368p+0", 6, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.f235ffc760bb965b97d021a19cp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb965b97d021a19cp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb965b97d021a19cp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb965b97d021a1ap-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "6, 0x2.67a2a8p+0", 6, LIT (0x2.67a2a8p+0), { LIT (0xd.f2364625908550a2021a5c5974p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550a2021a5c5978p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550a2021a5c5974p-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550a2021a5c5978p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "7, 0x2.67a2a4p+0", 7, LIT (0x2.67a2a4p+0), { LIT (0x2.75de01cd2ca964d00a4c077dfap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964d00a4c077dfbp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964d00a4c077dfap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964d00a4c077dfbp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "7, 0x2.67a2a5d2e36800fce3e16f10cap+0", 7, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x2.75de0e2cb0b93d5bd132aa3a9ep-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3a9fp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3a9ep-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3a9fp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "7, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 7, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x2.75de0e2cb0b93d5bd132aa3aa5p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa6p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa5p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d5bd132aa3aa6p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "7, 0x2.67a2a5d2e36800fcp+0", 7, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x2.75de0e2cb0b93d55c72f45899p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d55c72f45899p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d55c72f45899p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d55c72f458991p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "7, 0x2.67a2a5d2e36801p+0", 7, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x2.75de0e2cb0b93d70ea5223d304p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d70ea5223d305p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d70ea5223d304p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d70ea5223d305p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "7, 0x2.67a2a5d2e3682p+0", 7, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x2.75de0e2cb0ba0fc1388cdd19bfp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fc1388cdd19bfp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fc1388cdd19bfp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fc1388cdd19cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "7, 0x2.67a2a5d2e368p+0", 7, LIT (0x2.67a2a5d2e368p+0), { LIT (0x2.75de0e2cb0b936a8219a9175e6p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8219a9175e7p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8219a9175e6p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8219a9175e7p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "7, 0x2.67a2a8p+0", 7, LIT (0x2.67a2a8p+0), { LIT (0x2.75de1cf04f92a6f52a473bb1a9p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f52a473bb1aap-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f52a473bb1a9p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f52a473bb1aap-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "8, 0x2.67a2a4p+0", 8, LIT (0x2.67a2a4p+0), { LIT (0x6.0a48e703faf914b831a31c628p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b831a31c628p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b831a31c628p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b831a31c6282p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "8, 0x2.67a2a5d2e36800fce3e16f10cap+0", 8, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0x6.0a490a2a68000affa6e959171cp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959171ep-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959171cp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959171ep-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "8, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 8, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0x6.0a490a2a68000affa6e959173p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e9591732p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e959173p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000affa6e9591732p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "8, 0x2.67a2a5d2e36800fcp+0", 8, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x6.0a490a2a68000aee7eece044dcp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000aee7eece044dcp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000aee7eece044dcp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000aee7eece044dep-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "8, 0x2.67a2a5d2e36801p+0", 8, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x6.0a490a2a68000b3b96ac1be0fp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b3b96ac1be0f2p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b3b96ac1be0fp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b3b96ac1be0f2p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "8, 0x2.67a2a5d2e3682p+0", 8, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.0a490a2a680260b3a0ba158a1ep-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260b3a0ba158a1ep-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260b3a0ba158a1ep-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260b3a0ba158a2p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "8, 0x2.67a2a5d2e368p+0", 8, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.0a490a2a67fff7f5a6dd34db8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f5a6dd34db8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f5a6dd34db8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f5a6dd34db82p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "8, 0x2.67a2a8p+0", 8, LIT (0x2.67a2a8p+0), { LIT (0x6.0a49341bba59e67ed8dd8194c2p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e67ed8dd8194c4p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e67ed8dd8194c2p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e67ed8dd8194c4p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "9, 0x2.67a2a4p+0", 9, LIT (0x2.67a2a4p+0), { LIT (0xd.2013f924ba500bb0e7f429c0c8p-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bb0e7f429c0ccp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bb0e7f429c0c8p-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bb0e7f429c0ccp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "9, 0x2.67a2a5d2e36800fce3e16f10cap+0", 9, LIT (0x2.67a2a5d2e36800fce3e16f10cap+0), { LIT (0xd.20144fd00b01a7f534e9c14b44p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b44p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b44p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b48p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "9, 0x2.67a2a5d2e36800fce3e16f10cbp+0", 9, LIT (0x2.67a2a5d2e36800fce3e16f10cbp+0), { LIT (0xd.20144fd00b01a7f534e9c14b74p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b74p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b74p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7f534e9c14b78p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "9, 0x2.67a2a5d2e36800fcp+0", 9, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0xd.20144fd00b01a7cae7a4981cbcp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7cae7a4981cbcp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7cae7a4981cbcp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7cae7a4981ccp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "9, 0x2.67a2a5d2e36801p+0", 9, LIT (0x2.67a2a5d2e36801p+0), { LIT (0xd.20144fd00b01a888fdd9366edp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a888fdd9366ed4p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a888fdd9366edp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a888fdd9366ed4p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "9, 0x2.67a2a5d2e3682p+0", 9, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.20144fd00b0769b515a432a40cp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769b515a432a41p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769b515a432a40cp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769b515a432a41p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "9, 0x2.67a2a5d2e368p+0", 9, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.20144fd00b01790370b1a1e904p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01790370b1a1e904p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01790370b1a1e904p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01790370b1a1e908p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "9, 0x2.67a2a8p+0", 9, LIT (0x2.67a2a8p+0), { LIT (0xd.2014b73aef58c3f33c73160908p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3f33c73160908p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3f33c73160908p-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3f33c7316090cp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-1, -0x1p+0", -1, LIT (-0x1p+0), { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-1, 0x1p+0", -1, LIT (0x1p+0), { LIT (-0x7.0a727ba5c31b14ep-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-2, -0x1p+0", -2, LIT (-0x1p+0), { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-2, 0x1p+0", -2, LIT (0x1p+0), { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-3, -0x1p+0", -3, LIT (-0x1p+0), { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-3, 0x1p+0", -3, LIT (0x1p+0), { LIT (-0x5.021a9d8e3de8ab1p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-4, -0x1p+0", -4, LIT (-0x1p+0), { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841bp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-4, 0x1p+0", -4, LIT (0x1p+0), { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841bp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0", 0, LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x1p+0", 0, LIT (-0x1p+0), { LIT (0xc.3e3fedebdc77c1cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1dp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x2p-16384", 0, LIT (-0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x4p+0", 0, LIT (-0x4p+0), { LIT (-0x6.5ab9c24fa53e5cd8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x4p-1024", 0, LIT (-0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x4p-1076", 0, LIT (-0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x4p-128", 0, LIT (-0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x4p-16384", 0, LIT (-0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x8p-152", 0, LIT (-0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x8p-16448", 0, LIT (-0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, -0x8p-972", 0, LIT (-0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, +0", 0, LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x1.8p+0", 0, LIT (0x1.8p+0), { LIT (0x8.30723674b28d6eap-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6eap-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6eap-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6ebp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x1p+0", 0, LIT (0x1p+0), { LIT (0xc.3e3fedebdc77c1cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1dp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x2p+0", 0, LIT (0x2p+0), { LIT (0x3.950e7f6499def918p-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91cp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def918p-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x2p-16384", 0, LIT (0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x2p-4", 0, LIT (0x2p-4), { LIT (0xf.f003ff8e3fffb73p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb73p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb73p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x4p+0", 0, LIT (0x4p+0), { LIT (-0x6.5ab9c24fa53e5cd8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x4p-1024", 0, LIT (0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x4p-1076", 0, LIT (0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x4p-128", 0, LIT (0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x4p-16384", 0, LIT (0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x8p+0", 0, LIT (0x8p+0), { LIT (0x2.bf14eaafce04a584p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a588p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a584p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a588p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x8p-152", 0, LIT (0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x8p-16448", 0, LIT (0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0x8p-972", 0, LIT (0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0xap+0", 0, LIT (0xap+0), { LIT (-0x3.ef5a5713c3ca7068p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca7064p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca7064p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca7064p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0, 0xcp-4", 0, LIT (0xcp-4), { LIT (0xd.d3efb53a950c68ep-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68fp-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68ep-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, -0", 1, LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x1p+0", 1, LIT (-0x1p+0), { LIT (-0x7.0a727ba5c31b14ep-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x2p-16384", 1, LIT (-0x2p-16384), { LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0xf.ffffffffffffff8p-16388), UNDERFLOW_EXCEPTION }, { LIT (-0xf.ffffffffffffff8p-16388), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x4p-1024", 1, LIT (-0x4p-1024), { LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x4p-1076", 1, LIT (-0x4p-1076), { LIT (-0x2p-1076), ERRNO_UNCHANGED }, { LIT (-0x2p-1076), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x4p-128", 1, LIT (-0x4p-128), { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x4p-16384", 1, LIT (-0x4p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x8p-152", 1, LIT (-0x8p-152), { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x8p-16448", 1, LIT (-0x8p-16448), { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_intel96)
    { "1, -0x8p-972", 1, LIT (-0x8p-972), { LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, +0", 1, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x1.8p+0", 1, LIT (0x1.8p+0), { LIT (0x8.ed4ed4eb7e408aap-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408abp-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408aap-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408abp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x1p+0", 1, LIT (0x1p+0), { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x2p+0", 1, LIT (0x2p+0), { LIT (0x9.3a43cac1b8f7ed7p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed8p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed7p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x2p-16384", 1, LIT (0x2p-16384), { LIT (0xf.ffffffffffffff8p-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffff8p-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x2p-4", 1, LIT (0x2p-4), { LIT (0xf.f8015538e4fa438p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa438p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa438p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa439p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x4p-1024", 1, LIT (0x4p-1024), { LIT (0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x2p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x4p-1076", 1, LIT (0x4p-1076), { LIT (0x1.fffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (0x2p-1076), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (0x2p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x4p-128", 1, LIT (0x4p-128), { LIT (0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x4p-16384", 1, LIT (0x4p-16384), { LIT (0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x8p+0", 1, LIT (0x8p+0), { LIT (0x3.c1120ac30c305a9p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a94p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a9p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x8p-152", 1, LIT (0x8p-152), { LIT (0x3.fffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x8p-16448", 1, LIT (0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "1, 0x8p-972", 1, LIT (0x8p-972), { LIT (0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x4p-972), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0xap+0", 1, LIT (0xap+0), { LIT (0xb.2107a7100488615p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a7100488615p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a7100488615p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a7100488616p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "1, 0xcp-4", 1, LIT (0xcp-4), { LIT (0x5.9680759ada2f1dd8p-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1dep-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1dd8p-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1dep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x1p+0", 10, LIT (-0x1p+0), { LIT (0x1.213d3baa4f2958d8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958dap-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958dap-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x2p-16384", 10, LIT (-0x2p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x4p-1024", 10, LIT (-0x4p-1024), { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-10252), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x4p-1076", 10, LIT (-0x4p-1076), { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-10772), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x4p-128", 10, LIT (-0x4p-128), { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-1292), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x4p-16384", 10, LIT (-0x4p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x8p-152", 10, LIT (-0x8p-152), { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71ccp-1524), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x8p-16448", 10, LIT (-0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "10, -0x8p-972", 10, LIT (-0x8p-972), { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71ccp-9724), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, +0", 10, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x1p+0", 10, LIT (0x1p+0), { LIT (0x1.213d3baa4f2958d8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958dap-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958dap-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x2p+0", 10, LIT (0x2p+0), { LIT (0x4.3859a588db86b2a8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2a8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2a8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2bp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x2p-16384", 10, LIT (0x2p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x2p-4", 10, LIT (0x2p-4), { LIT (0x4.9f28594420d0db2p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db28p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db2p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db28p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x4p-1024", 10, LIT (0x4p-1024), { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-10252), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x4p-1076", 10, LIT (0x4p-1076), { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-10772), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x4p-128", 10, LIT (0x4p-128), { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-1292), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x4p-16384", 10, LIT (0x4p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x8p-152", 10, LIT (0x8p-152), { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71ccp-1524), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x8p-16448", 10, LIT (0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "10, 0x8p-972", 10, LIT (0x8p-972), { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71ccp-9724), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0xap+0", 10, LIT (0xap+0), { LIT (0x3.51dcf3a5d595f328p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f328p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f328p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f32cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "10, 0xcp-4", 10, LIT (0xcp-4), { LIT (0x1.0737a10f99b90732p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90734p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x2.67a2a4p+0", 2, LIT (0x2.67a2a4p+0), { LIT (0x6.e877b5d4dc1402a8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402bp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402a8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x2.67a2a5d2e36800fcp+0", 2, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x6.e877ba80a524fce8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcfp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fce8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x2.67a2a5d2e36801p+0", 2, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x6.e877ba80a524fcfp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcfp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x2.67a2a5d2e3682p+0", 2, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.e877ba80a5254c58p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c58p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c58p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x2.67a2a5d2e368p+0", 2, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.e877ba80a524fa6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa68p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x2.67a2a8p+0", 2, LIT (0x2.67a2a8p+0), { LIT (0x6.e877c013823b69dp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69dp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x8p+1020", 2, LIT (0x8p+1020), { LIT (0x3.5c4f847797f2fb04p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb04p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb04p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb08p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x8p+124", 2, LIT (0x8p+124), { LIT (-0x1.1f0b5f972511213ep-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213ep-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213cp-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213cp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0x8p+16380", 2, LIT (0x8p+16380), { LIT (-0x1.0bab81cdff920822p-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff920822p-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff92082p-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff92082p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0xf.fffb1p+96", 2, LIT (0xf.fffb1p+96), { LIT (-0x1.ffbc8bdea325a0a8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0xf.ffffffffffff8p+1020", 2, LIT (0xf.ffffffffffff8p+1020), { LIT (0x8.fb6ce7294f33633p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33634p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33633p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33634p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "2, 0xf.fffffp+124", 2, LIT (0xf.fffffp+124), { LIT (-0x2.fd3fa9dee0899294p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee089929p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee089929p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee089929p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, -0x1p+0", 3, LIT (-0x1p+0), { LIT (-0x5.021a9d8e3de8ab1p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, +0", 3, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x1p+0", 3, LIT (0x1p+0), { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x2.67a2a4p+0", 3, LIT (0x2.67a2a4p+0), { LIT (0x3.2f1a80fbe12c0d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d3cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x2.67a2a5d2e36800fcp+0", 3, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x3.2f1a8656b1ac692p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6924p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x2.67a2a5d2e36801p+0", 3, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x3.2f1a8656b1ac692cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac693p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x2.67a2a5d2e3682p+0", 3, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x3.2f1a8656b1acc43p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc43p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc43p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc434p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x2.67a2a5d2e368p+0", 3, LIT (0x2.67a2a5d2e368p+0), { LIT (0x3.2f1a8656b1ac663cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac664p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x2.67a2a8p+0", 3, LIT (0x2.67a2a8p+0), { LIT (0x3.2f1a8cba6907bb6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb64p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x2p+0", 3, LIT (0x2p+0), { LIT (0x2.1026cbf88539fb44p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb44p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb44p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0x2p-4", 3, LIT (0x2p-4), { LIT (0x2.aa0011101e5fe5c4p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c8p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c4p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0xap+0", 3, LIT (0xap+0), { LIT (0xe.f1f374e06602c7ap-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7bp-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7ap-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7bp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "3, 0xcp-4", 3, LIT (0xcp-4), { LIT (0x2.2c085554665b0988p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098cp-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b0988p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "4, 0x2.67a2a4p+0", 4, LIT (0x2.67a2a4p+0), { LIT (0x1.0933ca3121ef34ecp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34eep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34ecp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34eep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "4, 0x2.67a2a5d2e36800fcp+0", 4, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x1.0933ccdb33e9d0f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fap-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "4, 0x2.67a2a5d2e36801p+0", 4, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x1.0933ccdb33e9d0fep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d1p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "4, 0x2.67a2a5d2e3682p+0", 4, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x1.0933ccdb33e9fe48p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe4ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "4, 0x2.67a2a5d2e368p+0", 4, LIT (0x2.67a2a5d2e368p+0), { LIT (0x1.0933ccdb33e9cf88p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf8ap-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf88p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf8ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "4, 0x2.67a2a8p+0", 4, LIT (0x2.67a2a8p+0), { LIT (0x1.0933d0091440ccacp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccacp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccacp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccaep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "5, 0x2.67a2a4p+0", 5, LIT (0x2.67a2a4p+0), { LIT (0x4.3215d1403d642608p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64261p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d642608p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64261p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "5, 0x2.67a2a5d2e36800fcp+0", 5, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x4.3215df92220122ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "5, 0x2.67a2a5d2e36801p+0", 5, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x4.3215df92220122f8p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220123p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122f8p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220123p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "5, 0x2.67a2a5d2e3682p+0", 5, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x4.3215df922202166p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222021668p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202166p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222021668p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "5, 0x2.67a2a5d2e368p+0", 5, LIT (0x2.67a2a5d2e368p+0), { LIT (0x4.3215df9222011b2p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b28p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b2p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b28p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "5, 0x2.67a2a8p+0", 5, LIT (0x2.67a2a8p+0), { LIT (0x4.3215f0a870471a3p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a3p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a3p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a38p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "6, 0x2.67a2a4p+0", 6, LIT (0x2.67a2a4p+0), { LIT (0xd.f235c4ce9085834p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce9085834p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce9085834p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce9085835p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "6, 0x2.67a2a5d2e36800fcp+0", 6, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0xd.f235ffc760bbb63p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "6, 0x2.67a2a5d2e36801p+0", 6, LIT (0x2.67a2a5d2e36801p+0), { LIT (0xd.f235ffc760bbb6bp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6bp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6bp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "6, 0x2.67a2a5d2e3682p+0", 6, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.f235ffc760bfa11p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa11p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa11p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa12p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "6, 0x2.67a2a5d2e368p+0", 6, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.f235ffc760bb965p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb966p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb965p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb966p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "6, 0x2.67a2a8p+0", 6, LIT (0x2.67a2a8p+0), { LIT (0xd.f2364625908550ap-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550ap-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550ap-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550bp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "7, 0x2.67a2a4p+0", 7, LIT (0x2.67a2a4p+0), { LIT (0x2.75de01cd2ca964dp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964dp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964dp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964d4p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "7, 0x2.67a2a5d2e36800fcp+0", 7, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x2.75de0e2cb0b93d54p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d54p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d54p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d58p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "7, 0x2.67a2a5d2e36801p+0", 7, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x2.75de0e2cb0b93d7p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d7p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d7p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d74p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "7, 0x2.67a2a5d2e3682p+0", 7, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x2.75de0e2cb0ba0fcp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fcp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fcp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fc4p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "7, 0x2.67a2a5d2e368p+0", 7, LIT (0x2.67a2a5d2e368p+0), { LIT (0x2.75de0e2cb0b936a8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936acp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "7, 0x2.67a2a8p+0", 7, LIT (0x2.67a2a8p+0), { LIT (0x2.75de1cf04f92a6f4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "8, 0x2.67a2a4p+0", 8, LIT (0x2.67a2a4p+0), { LIT (0x6.0a48e703faf914b8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914cp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "8, 0x2.67a2a5d2e36800fcp+0", 8, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x6.0a490a2a68000ae8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000afp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000ae8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000afp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "8, 0x2.67a2a5d2e36801p+0", 8, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x6.0a490a2a68000b38p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b38p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b38p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b4p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "8, 0x2.67a2a5d2e3682p+0", 8, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.0a490a2a680260bp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260bp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260bp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260b8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "8, 0x2.67a2a5d2e368p+0", 8, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.0a490a2a67fff7fp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7fp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "8, 0x2.67a2a8p+0", 8, LIT (0x2.67a2a8p+0), { LIT (0x6.0a49341bba59e678p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e68p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e678p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e68p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "9, 0x2.67a2a4p+0", 9, LIT (0x2.67a2a4p+0), { LIT (0xd.2013f924ba500bbp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bbp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bbp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bcp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "9, 0x2.67a2a5d2e36800fcp+0", 9, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0xd.20144fd00b01a7cp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7dp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7cp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7dp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "9, 0x2.67a2a5d2e36801p+0", 9, LIT (0x2.67a2a5d2e36801p+0), { LIT (0xd.20144fd00b01a88p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a89p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a88p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a89p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "9, 0x2.67a2a5d2e3682p+0", 9, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.20144fd00b0769bp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769bp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769bp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769cp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "9, 0x2.67a2a5d2e368p+0", 9, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.20144fd00b0179p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0179p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0179p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01791p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "9, 0x2.67a2a8p+0", 9, LIT (0x2.67a2a8p+0), { LIT (0xd.2014b73aef58c3fp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3fp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3fp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c4p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-1, -0x1p+0", -1, LIT (-0x1p+0), { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-1, 0x1p+0", -1, LIT (0x1p+0), { LIT (-0x7.0a727ba5c31b14ep-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-2, -0x1p+0", -2, LIT (-0x1p+0), { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-2, 0x1p+0", -2, LIT (0x1p+0), { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.d6a5095fa9be67e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-3, -0x1p+0", -3, LIT (-0x1p+0), { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-3, 0x1p+0", -3, LIT (0x1p+0), { LIT (-0x5.021a9d8e3de8ab1p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-4, -0x1p+0", -4, LIT (-0x1p+0), { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841bp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-4, 0x1p+0", -4, LIT (0x1p+0), { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841ap-12), ERRNO_UNCHANGED }, { LIT (0xa.24f1b5ad78d841bp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0", 0, LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x1p+0", 0, LIT (-0x1p+0), { LIT (0xc.3e3fedebdc77c1cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1dp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x2p-16384", 0, LIT (-0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x4p+0", 0, LIT (-0x4p+0), { LIT (-0x6.5ab9c24fa53e5cd8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x4p-1024", 0, LIT (-0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x4p-1076", 0, LIT (-0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x4p-128", 0, LIT (-0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x4p-16384", 0, LIT (-0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x4p-16448", 0, LIT (-0x4p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x8p-152", 0, LIT (-0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x8p-16448", 0, LIT (-0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, -0x8p-972", 0, LIT (-0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, +0", 0, LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x1.8p+0", 0, LIT (0x1.8p+0), { LIT (0x8.30723674b28d6eap-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6eap-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6eap-4), ERRNO_UNCHANGED }, { LIT (0x8.30723674b28d6ebp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x1p+0", 0, LIT (0x1p+0), { LIT (0xc.3e3fedebdc77c1cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1dp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1cp-4), ERRNO_UNCHANGED }, { LIT (0xc.3e3fedebdc77c1dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x2p+0", 0, LIT (0x2p+0), { LIT (0x3.950e7f6499def918p-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91cp-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def918p-4), ERRNO_UNCHANGED }, { LIT (0x3.950e7f6499def91cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x2p-16384", 0, LIT (0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x2p-4", 0, LIT (0x2p-4), { LIT (0xf.f003ff8e3fffb73p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb73p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb73p-4), ERRNO_UNCHANGED }, { LIT (0xf.f003ff8e3fffb74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x4p+0", 0, LIT (0x4p+0), { LIT (-0x6.5ab9c24fa53e5cd8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED }, { LIT (-0x6.5ab9c24fa53e5cdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x4p-1024", 0, LIT (0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x4p-1076", 0, LIT (0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x4p-128", 0, LIT (0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x4p-16384", 0, LIT (0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x4p-16448", 0, LIT (0x4p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x8p+0", 0, LIT (0x8p+0), { LIT (0x2.bf14eaafce04a584p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a588p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a584p-4), ERRNO_UNCHANGED }, { LIT (0x2.bf14eaafce04a588p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x8p-152", 0, LIT (0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x8p-16448", 0, LIT (0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0x8p-972", 0, LIT (0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0xap+0", 0, LIT (0xap+0), { LIT (-0x3.ef5a5713c3ca7068p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca7064p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca7064p-4), ERRNO_UNCHANGED }, { LIT (-0x3.ef5a5713c3ca7064p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0, 0xcp-4", 0, LIT (0xcp-4), { LIT (0xd.d3efb53a950c68ep-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68fp-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68ep-4), ERRNO_UNCHANGED }, { LIT (0xd.d3efb53a950c68fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0", 1, LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x1p+0", 1, LIT (-0x1p+0), { LIT (-0x7.0a727ba5c31b14ep-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x2p-16384", 1, LIT (-0x2p-16384), { LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0xf.ffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (-0xf.ffffffffffffffcp-16388), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x4p-1024", 1, LIT (-0x4p-1024), { LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x4p-1076", 1, LIT (-0x4p-1076), { LIT (-0x2p-1076), ERRNO_UNCHANGED }, { LIT (-0x2p-1076), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x4p-128", 1, LIT (-0x4p-128), { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (-0x1.fffffffffffffffep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x4p-16384", 1, LIT (-0x4p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x4p-16448", 1, LIT (-0x4p-16448), { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x8p-152", 1, LIT (-0x8p-152), { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x4p-152), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x8p-16448", 1, LIT (-0x8p-16448), { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "1, -0x8p-972", 1, LIT (-0x8p-972), { LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, +0", 1, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x1.8p+0", 1, LIT (0x1.8p+0), { LIT (0x8.ed4ed4eb7e408aap-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408abp-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408aap-4), ERRNO_UNCHANGED }, { LIT (0x8.ed4ed4eb7e408abp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x1p+0", 1, LIT (0x1p+0), { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14d8p-4), ERRNO_UNCHANGED }, { LIT (0x7.0a727ba5c31b14ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x2p+0", 1, LIT (0x2p+0), { LIT (0x9.3a43cac1b8f7ed7p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed8p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed7p-4), ERRNO_UNCHANGED }, { LIT (0x9.3a43cac1b8f7ed8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x2p-16384", 1, LIT (0x2p-16384), { LIT (0xf.ffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x2p-4", 1, LIT (0x2p-4), { LIT (0xf.f8015538e4fa438p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa438p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa438p-8), ERRNO_UNCHANGED }, { LIT (0xf.f8015538e4fa439p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x4p-1024", 1, LIT (0x4p-1024), { LIT (0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x2p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x4p-1076", 1, LIT (0x4p-1076), { LIT (0x1.fffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (0x2p-1076), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (0x2p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x4p-128", 1, LIT (0x4p-128), { LIT (0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x4p-16384", 1, LIT (0x4p-16384), { LIT (0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x4p-16448", 1, LIT (0x4p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x8p+0", 1, LIT (0x8p+0), { LIT (0x3.c1120ac30c305a9p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a94p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a9p-4), ERRNO_UNCHANGED }, { LIT (0x3.c1120ac30c305a94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x8p-152", 1, LIT (0x8p-152), { LIT (0x3.fffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x4p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x8p-16448", 1, LIT (0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0x8p-972", 1, LIT (0x8p-972), { LIT (0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x4p-972), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0xap+0", 1, LIT (0xap+0), { LIT (0xb.2107a7100488615p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a7100488615p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a7100488615p-8), ERRNO_UNCHANGED }, { LIT (0xb.2107a7100488616p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "1, 0xcp-4", 1, LIT (0xcp-4), { LIT (0x5.9680759ada2f1dd8p-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1dep-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1dd8p-4), ERRNO_UNCHANGED }, { LIT (0x5.9680759ada2f1dep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x1p+0", 10, LIT (-0x1p+0), { LIT (0x1.213d3baa4f2958d8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958dap-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958dap-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x2p-16384", 10, LIT (-0x2p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x4p-1024", 10, LIT (-0x4p-1024), { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-10252), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x4p-1076", 10, LIT (-0x4p-1076), { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-10772), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x4p-128", 10, LIT (-0x4p-128), { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-1292), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x4p-16384", 10, LIT (-0x4p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x4p-16448", 10, LIT (-0x4p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x8p-152", 10, LIT (-0x8p-152), { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71ccp-1524), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x8p-16448", 10, LIT (-0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "10, -0x8p-972", 10, LIT (-0x8p-972), { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71ccp-9724), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, +0", 10, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x1p+0", 10, LIT (0x1p+0), { LIT (0x1.213d3baa4f2958d8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958dap-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958d8p-32), ERRNO_UNCHANGED }, { LIT (0x1.213d3baa4f2958dap-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x2p+0", 10, LIT (0x2p+0), { LIT (0x4.3859a588db86b2a8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2a8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2a8p-24), ERRNO_UNCHANGED }, { LIT (0x4.3859a588db86b2bp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x2p-16384", 10, LIT (0x2p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x2p-4", 10, LIT (0x2p-4), { LIT (0x4.9f28594420d0db2p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db28p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db2p-64), ERRNO_UNCHANGED }, { LIT (0x4.9f28594420d0db28p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x4p-1024", 10, LIT (0x4p-1024), { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10252), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-10252), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x4p-1076", 10, LIT (0x4p-1076), { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-10772), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-10772), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x4p-128", 10, LIT (0x4p-128), { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c72ep-1292), ERRNO_UNCHANGED }, { LIT (0x1.27e4fb7789f5c73p-1292), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x4p-16384", 10, LIT (0x4p-16384), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x4p-16448", 10, LIT (0x4p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x8p-152", 10, LIT (0x8p-152), { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-1524), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71ccp-1524), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x8p-16448", 10, LIT (0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0x8p-972", 10, LIT (0x8p-972), { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71cb8p-9724), ERRNO_UNCHANGED }, { LIT (0x4.9f93edde27d71ccp-9724), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0xap+0", 10, LIT (0xap+0), { LIT (0x3.51dcf3a5d595f328p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f328p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f328p-4), ERRNO_UNCHANGED }, { LIT (0x3.51dcf3a5d595f32cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "10, 0xcp-4", 10, LIT (0xcp-4), { LIT (0x1.0737a10f99b90732p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90732p-36), ERRNO_UNCHANGED }, { LIT (0x1.0737a10f99b90734p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x2.67a2a4p+0", 2, LIT (0x2.67a2a4p+0), { LIT (0x6.e877b5d4dc1402a8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402bp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402a8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877b5d4dc1402bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x2.67a2a5d2e36800fcp+0", 2, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x6.e877ba80a524fce8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcfp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fce8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x2.67a2a5d2e36801p+0", 2, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x6.e877ba80a524fcfp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcfp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fcf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x2.67a2a5d2e3682p+0", 2, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.e877ba80a5254c58p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c58p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c58p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a5254c6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x2.67a2a5d2e368p+0", 2, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.e877ba80a524fa6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa68p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa6p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877ba80a524fa68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x2.67a2a8p+0", 2, LIT (0x2.67a2a8p+0), { LIT (0x6.e877c013823b69dp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d8p-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69dp-4), ERRNO_UNCHANGED }, { LIT (0x6.e877c013823b69d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x8p+1020", 2, LIT (0x8p+1020), { LIT (0x3.5c4f847797f2fb04p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb04p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb04p-516), ERRNO_UNCHANGED }, { LIT (0x3.5c4f847797f2fb08p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x8p+124", 2, LIT (0x8p+124), { LIT (-0x1.1f0b5f972511213ep-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213ep-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213cp-64), ERRNO_UNCHANGED }, { LIT (-0x1.1f0b5f972511213cp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0x8p+16380", 2, LIT (0x8p+16380), { LIT (-0x1.0bab81cdff920822p-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff920822p-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff92082p-8192), ERRNO_UNCHANGED }, { LIT (-0x1.0bab81cdff92082p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0xf.fffb1p+96", 2, LIT (0xf.fffb1p+96), { LIT (-0x1.ffbc8bdea325a0a8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6p-52), ERRNO_UNCHANGED }, { LIT (-0x1.ffbc8bdea325a0a6p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0xf.ffffffffffff8p+1020", 2, LIT (0xf.ffffffffffff8p+1020), { LIT (0x8.fb6ce7294f33633p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33634p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33633p-516), ERRNO_UNCHANGED }, { LIT (0x8.fb6ce7294f33634p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "2, 0xf.fffffp+124", 2, LIT (0xf.fffffp+124), { LIT (-0x2.fd3fa9dee0899294p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee089929p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee089929p-68), ERRNO_UNCHANGED }, { LIT (-0x2.fd3fa9dee089929p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, -0x1p+0", 3, LIT (-0x1p+0), { LIT (-0x5.021a9d8e3de8ab1p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (-0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, +0", 3, LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x1p+0", 3, LIT (0x1p+0), { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab08p-8), ERRNO_UNCHANGED }, { LIT (0x5.021a9d8e3de8ab1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x2.67a2a4p+0", 3, LIT (0x2.67a2a4p+0), { LIT (0x3.2f1a80fbe12c0d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a80fbe12c0d3cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x2.67a2a5d2e36800fcp+0", 3, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x3.2f1a8656b1ac692p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac6924p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x2.67a2a5d2e36801p+0", 3, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x3.2f1a8656b1ac692cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac692cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac693p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x2.67a2a5d2e3682p+0", 3, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x3.2f1a8656b1acc43p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc43p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc43p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1acc434p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x2.67a2a5d2e368p+0", 3, LIT (0x2.67a2a5d2e368p+0), { LIT (0x3.2f1a8656b1ac663cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac663cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8656b1ac664p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x2.67a2a8p+0", 3, LIT (0x2.67a2a8p+0), { LIT (0x3.2f1a8cba6907bb6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb64p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb6p-4), ERRNO_UNCHANGED }, { LIT (0x3.2f1a8cba6907bb64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x2p+0", 3, LIT (0x2p+0), { LIT (0x2.1026cbf88539fb44p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb44p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb44p-4), ERRNO_UNCHANGED }, { LIT (0x2.1026cbf88539fb48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0x2p-4", 3, LIT (0x2p-4), { LIT (0x2.aa0011101e5fe5c4p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c8p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c4p-16), ERRNO_UNCHANGED }, { LIT (0x2.aa0011101e5fe5c8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0xap+0", 3, LIT (0xap+0), { LIT (0xe.f1f374e06602c7ap-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7bp-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7ap-8), ERRNO_UNCHANGED }, { LIT (0xe.f1f374e06602c7bp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "3, 0xcp-4", 3, LIT (0xcp-4), { LIT (0x2.2c085554665b0988p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098cp-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b0988p-8), ERRNO_UNCHANGED }, { LIT (0x2.2c085554665b098cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "4, 0x2.67a2a4p+0", 4, LIT (0x2.67a2a4p+0), { LIT (0x1.0933ca3121ef34ecp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34eep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34ecp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ca3121ef34eep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "4, 0x2.67a2a5d2e36800fcp+0", 4, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x1.0933ccdb33e9d0f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fap-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "4, 0x2.67a2a5d2e36801p+0", 4, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x1.0933ccdb33e9d0fep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d1p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d0fep-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9d1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "4, 0x2.67a2a5d2e3682p+0", 4, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x1.0933ccdb33e9fe48p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe48p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9fe4ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "4, 0x2.67a2a5d2e368p+0", 4, LIT (0x2.67a2a5d2e368p+0), { LIT (0x1.0933ccdb33e9cf88p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf8ap-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf88p-4), ERRNO_UNCHANGED }, { LIT (0x1.0933ccdb33e9cf8ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "4, 0x2.67a2a8p+0", 4, LIT (0x2.67a2a8p+0), { LIT (0x1.0933d0091440ccacp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccacp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccacp-4), ERRNO_UNCHANGED }, { LIT (0x1.0933d0091440ccaep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "5, 0x2.67a2a4p+0", 5, LIT (0x2.67a2a4p+0), { LIT (0x4.3215d1403d642608p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64261p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d642608p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215d1403d64261p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "5, 0x2.67a2a5d2e36800fcp+0", 5, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x4.3215df92220122ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122ep-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122e8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "5, 0x2.67a2a5d2e36801p+0", 5, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x4.3215df92220122f8p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220123p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220122f8p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df92220123p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "5, 0x2.67a2a5d2e3682p+0", 5, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x4.3215df922202166p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222021668p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df922202166p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222021668p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "5, 0x2.67a2a5d2e368p+0", 5, LIT (0x2.67a2a5d2e368p+0), { LIT (0x4.3215df9222011b2p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b28p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b2p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215df9222011b28p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "5, 0x2.67a2a8p+0", 5, LIT (0x2.67a2a8p+0), { LIT (0x4.3215f0a870471a3p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a3p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a3p-8), ERRNO_UNCHANGED }, { LIT (0x4.3215f0a870471a38p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "6, 0x2.67a2a4p+0", 6, LIT (0x2.67a2a4p+0), { LIT (0xd.f235c4ce9085834p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce9085834p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce9085834p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235c4ce9085835p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "6, 0x2.67a2a5d2e36800fcp+0", 6, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0xd.f235ffc760bbb63p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb63p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb64p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "6, 0x2.67a2a5d2e36801p+0", 6, LIT (0x2.67a2a5d2e36801p+0), { LIT (0xd.f235ffc760bbb6bp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6bp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6bp-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bbb6cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "6, 0x2.67a2a5d2e3682p+0", 6, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.f235ffc760bfa11p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa11p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa11p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bfa12p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "6, 0x2.67a2a5d2e368p+0", 6, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.f235ffc760bb965p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb966p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb965p-12), ERRNO_UNCHANGED }, { LIT (0xd.f235ffc760bb966p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "6, 0x2.67a2a8p+0", 6, LIT (0x2.67a2a8p+0), { LIT (0xd.f2364625908550ap-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550ap-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550ap-12), ERRNO_UNCHANGED }, { LIT (0xd.f2364625908550bp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "7, 0x2.67a2a4p+0", 7, LIT (0x2.67a2a4p+0), { LIT (0x2.75de01cd2ca964dp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964dp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964dp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de01cd2ca964d4p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "7, 0x2.67a2a5d2e36800fcp+0", 7, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x2.75de0e2cb0b93d54p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d54p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d54p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d58p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "7, 0x2.67a2a5d2e36801p+0", 7, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x2.75de0e2cb0b93d7p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d7p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d7p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b93d74p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "7, 0x2.67a2a5d2e3682p+0", 7, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x2.75de0e2cb0ba0fcp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fcp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fcp-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0ba0fc4p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "7, 0x2.67a2a5d2e368p+0", 7, LIT (0x2.67a2a5d2e368p+0), { LIT (0x2.75de0e2cb0b936a8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936a8p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de0e2cb0b936acp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "7, 0x2.67a2a8p+0", 7, LIT (0x2.67a2a8p+0), { LIT (0x2.75de1cf04f92a6f4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f4p-12), ERRNO_UNCHANGED }, { LIT (0x2.75de1cf04f92a6f8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "8, 0x2.67a2a4p+0", 8, LIT (0x2.67a2a4p+0), { LIT (0x6.0a48e703faf914b8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914b8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a48e703faf914cp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "8, 0x2.67a2a5d2e36800fcp+0", 8, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0x6.0a490a2a68000ae8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000afp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000ae8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000afp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "8, 0x2.67a2a5d2e36801p+0", 8, LIT (0x2.67a2a5d2e36801p+0), { LIT (0x6.0a490a2a68000b38p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b38p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b38p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a68000b4p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "8, 0x2.67a2a5d2e3682p+0", 8, LIT (0x2.67a2a5d2e3682p+0), { LIT (0x6.0a490a2a680260bp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260bp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260bp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a680260b8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "8, 0x2.67a2a5d2e368p+0", 8, LIT (0x2.67a2a5d2e368p+0), { LIT (0x6.0a490a2a67fff7fp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f8p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7fp-16), ERRNO_UNCHANGED }, { LIT (0x6.0a490a2a67fff7f8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "8, 0x2.67a2a8p+0", 8, LIT (0x2.67a2a8p+0), { LIT (0x6.0a49341bba59e678p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e68p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e678p-16), ERRNO_UNCHANGED }, { LIT (0x6.0a49341bba59e68p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "9, 0x2.67a2a4p+0", 9, LIT (0x2.67a2a4p+0), { LIT (0xd.2013f924ba500bbp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bbp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bbp-20), ERRNO_UNCHANGED }, { LIT (0xd.2013f924ba500bcp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "9, 0x2.67a2a5d2e36800fcp+0", 9, LIT (0x2.67a2a5d2e36800fcp+0), { LIT (0xd.20144fd00b01a7cp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7dp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7cp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a7dp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "9, 0x2.67a2a5d2e36801p+0", 9, LIT (0x2.67a2a5d2e36801p+0), { LIT (0xd.20144fd00b01a88p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a89p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a88p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01a89p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "9, 0x2.67a2a5d2e3682p+0", 9, LIT (0x2.67a2a5d2e3682p+0), { LIT (0xd.20144fd00b0769bp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769bp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769bp-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0769cp-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "9, 0x2.67a2a5d2e368p+0", 9, LIT (0x2.67a2a5d2e368p+0), { LIT (0xd.20144fd00b0179p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0179p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b0179p-20), ERRNO_UNCHANGED }, { LIT (0xd.20144fd00b01791p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "9, 0x2.67a2a8p+0", 9, LIT (0x2.67a2a8p+0), { LIT (0xd.2014b73aef58c3fp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3fp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c3fp-20), ERRNO_UNCHANGED }, { LIT (0xd.2014b73aef58c4p-20), ERRNO_UNCHANGED } },
#endif
  };

static void
jn_test (void)
{
  ALL_RM_TEST (jn, 0, jn_test_data, RUN_TEST_LOOP_if_f, END);
}

static void
do_test (void)
{
  jn_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

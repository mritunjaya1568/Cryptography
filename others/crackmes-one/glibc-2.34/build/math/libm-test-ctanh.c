/* Test ctanh.
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

static const struct test_c_c_data ctanh_test_data[] =
  {
    { "inf + 0 i", plus_infty, 0, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf + 1 i", plus_infty, 1, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf + 2 i", plus_infty, 2, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf + 3 i", plus_infty, 3, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf + 4 i", plus_infty, 4, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf + min_value i", plus_infty, min_value, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf + min_subnorm_value i", plus_infty, min_subnorm_value, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf + 0x1p127 i", plus_infty, LIT (0x1p127), { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf + 0x1.11p127 i", plus_infty, LIT (0x1.11p127), { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
#if !TEST_COND_binary32
    { "inf + 0x1p1023 i", plus_infty, LIT (0x1p1023), { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf + 0x1.5p1023 i", plus_infty, LIT (0x1.5p1023), { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
#endif
#if MAX_EXP >= 16384
    { "inf + 0x1p16383 i", plus_infty, LIT (0x1p16383), { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf + 0x1.2p16383 i", plus_infty, LIT (0x1.2p16383), { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
#endif
    { "inf - 0 i", plus_infty, minus_zero, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf - 1 i", plus_infty, -1, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf - 2 i", plus_infty, -2, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf - 3 i", plus_infty, -3, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf - 4 i", plus_infty, -4, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf - min_value i", plus_infty, -min_value, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf - min_subnorm_value i", plus_infty, -min_subnorm_value, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf - 0x1p127 i", plus_infty, LIT (-0x1p127), { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf - 0x1.11p127 i", plus_infty, LIT (-0x1.11p127), { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
#if !TEST_COND_binary32
    { "inf - 0x1p1023 i", plus_infty, LIT (-0x1p1023), { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
    { "inf - 0x1.5p1023 i", plus_infty, LIT (-0x1.5p1023), { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
#endif
#if MAX_EXP >= 16384
    { "inf - 0x1p16383 i", plus_infty, LIT (-0x1p16383), { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 }, { LIT (1.0), minus_zero, 0 } },
    { "inf - 0x1.2p16383 i", plus_infty, LIT (-0x1.2p16383), { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 }, { LIT (1.0), LIT (0.0), 0 } },
#endif
    { "-inf + 0 i", minus_infty, 0, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf + 1 i", minus_infty, 1, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf + 2 i", minus_infty, 2, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf + 3 i", minus_infty, 3, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf + 4 i", minus_infty, 4, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf + min_value i", minus_infty, min_value, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf + min_subnorm_value i", minus_infty, min_subnorm_value, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf + 0x1p127 i", minus_infty, LIT (0x1p127), { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf + 0x1.11p127 i", minus_infty, LIT (0x1.11p127), { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
#if !TEST_COND_binary32
    { "-inf + 0x1p1023 i", minus_infty, LIT (0x1p1023), { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf + 0x1.5p1023 i", minus_infty, LIT (0x1.5p1023), { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
#endif
#if MAX_EXP >= 16384
    { "-inf + 0x1p16383 i", minus_infty, LIT (0x1p16383), { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf + 0x1.2p16383 i", minus_infty, LIT (0x1.2p16383), { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
#endif
    { "-inf - 0 i", minus_infty, minus_zero, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf - 1 i", minus_infty, -1, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf - 2 i", minus_infty, -2, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf - 3 i", minus_infty, -3, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf - 4 i", minus_infty, -4, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf - min_value i", minus_infty, -min_value, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf - min_subnorm_value i", minus_infty, -min_subnorm_value, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf - 0x1p127 i", minus_infty, LIT (-0x1p127), { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf - 0x1.11p127 i", minus_infty, LIT (-0x1.11p127), { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
#if !TEST_COND_binary32
    { "-inf - 0x1p1023 i", minus_infty, LIT (-0x1p1023), { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
    { "-inf - 0x1.5p1023 i", minus_infty, LIT (-0x1.5p1023), { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
#endif
#if MAX_EXP >= 16384
    { "-inf - 0x1p16383 i", minus_infty, LIT (-0x1p16383), { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 }, { LIT (-1.0), minus_zero, 0 } },
    { "-inf - 0x1.2p16383 i", minus_infty, LIT (-0x1.2p16383), { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 }, { LIT (-1.0), LIT (0.0), 0 } },
#endif

    { "0 + inf i", 0, plus_infty, { 0, qnan_value, INVALID_EXCEPTION }, { 0, qnan_value, INVALID_EXCEPTION }, { 0, qnan_value, INVALID_EXCEPTION }, { 0, qnan_value, INVALID_EXCEPTION } },
    { "2 + inf i", 2, plus_infty, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION } },
    { "0 - inf i", 0, minus_infty, { 0, qnan_value, INVALID_EXCEPTION }, { 0, qnan_value, INVALID_EXCEPTION }, { 0, qnan_value, INVALID_EXCEPTION }, { 0, qnan_value, INVALID_EXCEPTION } },
    { "2 - inf i", 2, minus_infty, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION } },
    { "-0 + inf i", minus_zero, plus_infty, { minus_zero, qnan_value, INVALID_EXCEPTION }, { minus_zero, qnan_value, INVALID_EXCEPTION }, { minus_zero, qnan_value, INVALID_EXCEPTION }, { minus_zero, qnan_value, INVALID_EXCEPTION } },
    { "-2 + inf i", -2, plus_infty, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION } },
    { "-0 - inf i", minus_zero, minus_infty, { minus_zero, qnan_value, INVALID_EXCEPTION }, { minus_zero, qnan_value, INVALID_EXCEPTION }, { minus_zero, qnan_value, INVALID_EXCEPTION }, { minus_zero, qnan_value, INVALID_EXCEPTION } },
    { "-2 - inf i", -2, minus_infty, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION }, { qnan_value, qnan_value, INVALID_EXCEPTION } },

    { "inf + qNaN i", plus_infty, qnan_value, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN } },
    { "inf + inf i", plus_infty, plus_infty, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN } },
    { "inf - inf i", plus_infty, minus_infty, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN } },
    { "-inf + qNaN i", minus_infty, qnan_value, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN } },
    { "-inf + inf i", minus_infty, plus_infty, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN } },
    { "-inf - inf i", minus_infty, minus_infty, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN }, { LIT (-1.0), LIT (0.0), IGNORE_ZERO_INF_SIGN } },

    { "qNaN + 0 i", qnan_value, 0, { qnan_value, LIT (0.0), 0 }, { qnan_value, LIT (0.0), 0 }, { qnan_value, LIT (0.0), 0 }, { qnan_value, LIT (0.0), 0 } },
    { "qNaN - 0 i", qnan_value, minus_zero, { qnan_value, minus_zero, 0 }, { qnan_value, minus_zero, 0 }, { qnan_value, minus_zero, 0 }, { qnan_value, minus_zero, 0 } },

    { "qNaN + 0.5 i", qnan_value, LIT (0.5), { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },
    { "qNaN - 4.5 i", qnan_value, LIT (-4.5), { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },

    { "0 + qNaN i", 0, qnan_value, { 0, qnan_value, 0 }, { 0, qnan_value, 0 }, { 0, qnan_value, 0 }, { 0, qnan_value, 0 } },
    { "5 + qNaN i", 5, qnan_value, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },
    { "-0 + qNaN i", minus_zero, qnan_value, { minus_zero, qnan_value, 0 }, { minus_zero, qnan_value, 0 }, { minus_zero, qnan_value, 0 }, { minus_zero, qnan_value, 0 } },
    { "-0.25 + qNaN i", LIT (-0.25), qnan_value, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },

    { "qNaN + qNaN i", qnan_value, qnan_value, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 } },

#if (TEST_COND_binary128)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (-0xf.723876a6b9717849ff07dfd98898p-4), LIT (0x2.87c84b87ef36a32deb7b60c8a6d4p-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b9717849ff07dfd9889p-4), LIT (0x2.87c84b87ef36a32deb7b60c8a6d6p-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b9717849ff07dfd9889p-4), LIT (0x2.87c84b87ef36a32deb7b60c8a6d4p-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b9717849ff07dfd9889p-4), LIT (0x2.87c84b87ef36a32deb7b60c8a6d6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p-16384 + +0 i", LIT (-0x2p-16384), LIT (0x0p+0), { LIT (-0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1024 + +0 i", LIT (-0x4p-1024), LIT (0x0p+0), { LIT (-0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1024), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076 + +0 i", LIT (-0x4p-1076), LIT (0x0p+0), { LIT (-0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1076), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-128 + +0 i", LIT (-0x4p-128), LIT (0x0p+0), { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384 + +0 i", LIT (-0x4p-16384), LIT (0x0p+0), { LIT (-0x4p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16448 + +0 i", LIT (-0x4p-16448), LIT (0x0p+0), { LIT (-0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffcp-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffcp-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16496 + +0 i", LIT (-0x4p-16496), LIT (0x0p+0), { LIT (-0x4p-16496), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16496), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 + +0 i", LIT (-0x8p-152), LIT (0x0p+0), { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-16448 + +0 i", LIT (-0x8p-16448), LIT (0x0p+0), { LIT (-0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x7.fffffffffffcp-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x7.fffffffffffcp-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-972 + +0 i", LIT (-0x8p-972), LIT (0x0p+0), { LIT (-0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-972), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xc.35p+12 - 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (-0xc.35p+12), { LIT (-0x1.0000000000000000000000000001p+0), LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0xc.35p+12 + 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (0xc.35p+12), { LIT (-0x1.0000000000000000000000000001p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x2p-16384 i", LIT (0x0p+0), LIT (-0x2p-16384), { LIT (0x0p+0), LIT (-0x2.0000000000000000000000000004p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x4p-1024 i", LIT (0x0p+0), LIT (-0x4p-1024), { LIT (0x0p+0), LIT (-0x4.0000000000000000000000000004p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x4p-1076 i", LIT (0x0p+0), LIT (-0x4p-1076), { LIT (0x0p+0), LIT (-0x4.0000000000000000000000000004p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x4p-128 i", LIT (0x0p+0), LIT (-0x4p-128), { LIT (0x0p+0), LIT (-0x4.0000000000000000000000000004p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x4p-16384 i", LIT (0x0p+0), LIT (-0x4p-16384), { LIT (0x0p+0), LIT (-0x4.0000000000000000000000000004p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x4p-16448 i", LIT (0x0p+0), LIT (-0x4p-16448), { LIT (0x0p+0), LIT (-0x4.000000000004p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x4p-16496 i", LIT (0x0p+0), LIT (-0x4p-16496), { LIT (0x0p+0), LIT (-0x8p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x0p+0), LIT (-0x8.0000000000000000000000000008p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x8p-16448 i", LIT (0x0p+0), LIT (-0x8p-16448), { LIT (0x0p+0), LIT (-0x8.000000000004p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x8p-972 i", LIT (0x0p+0), LIT (-0x8p-972), { LIT (0x0p+0), LIT (-0x8.0000000000000000000000000008p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x1.921fb4p+0 i", LIT (0x0p+0), LIT (0x1.921fb4p+0), { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cd91404ccd8cbp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x1.921fb54442d1846ap+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d1846ap+0), { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7b3b807fb349bcp+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x1.921fb54442d18p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d18p+0), { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1871a036cababep+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x1.921fb54442d19p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d19p+0), { LIT (0x0p+0), LIT (-0x1.617a15494767a04882c320317f3fp+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x1.921fb6p+0 i", LIT (0x0p+0), LIT (0x1.921fb6p+0), { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6421a55284fe1p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x2p-16384 i", LIT (0x0p+0), LIT (0x2p-16384), { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x2.0000000000000000000000000004p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-1024 i", LIT (0x0p+0), LIT (0x4p-1024), { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000000000000000004p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000000000000000004p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-128 i", LIT (0x0p+0), LIT (0x4p-128), { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000000000000000004p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-16384 i", LIT (0x0p+0), LIT (0x4p-16384), { LIT (0x0p+0), LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4.0000000000000000000000000004p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-16448 i", LIT (0x0p+0), LIT (0x4p-16448), { LIT (0x0p+0), LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4.000000000004p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-16496 i", LIT (0x0p+0), LIT (0x4p-16496), { LIT (0x0p+0), LIT (0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.0000000000000000000000000008p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p-16448 i", LIT (0x0p+0), LIT (0x8p-16448), { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8.000000000004p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p-972 i", LIT (0x0p+0), LIT (0x8p-972), { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.0000000000000000000000000008p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdaa22168c234c4c6628b80cp-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234c4c6628b80cp-4), { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffc78p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffc8p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffc78p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdaa22168c234c4c6628b80dc8p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234c4c6628b80dc8p-4), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdaa22168c234c4c6628b80dcp-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234c4c6628b80dcp-4), { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdaa22168c234c4c6628b81p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234c4c6628b81p-4), { LIT (0x0p+0), LIT (0x1.0000000000000000000000000047p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000000000000000048p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000000000000000047p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000000000000000048p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdaa22168c234p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234p-4), { LIT (0x0p+0), LIT (0xf.ffffffffffffffe76733ae8fe478p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffe76733ae8fe48p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffe76733ae8fe478p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffe76733ae8fe48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdaa22168c235p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c235p-4), { LIT (0x0p+0), LIT (0x1.000000000000000076733ae8fe47p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000000000000076733ae8fe48p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000000000000076733ae8fe47p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000000000000076733ae8fe48p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdaa22168c8p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c8p-4), { LIT (0x0p+0), LIT (0x1.0000000000000b9676733ae8fe8ap+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b9676733ae8fe8bp+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b9676733ae8fe8ap+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b9676733ae8fe8bp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdaa22168cp-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168cp-4), { LIT (0x0p+0), LIT (0xf.ffffffffffffb9676733ae8fe518p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb9676733ae8fe518p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb9676733ae8fe518p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb9676733ae8fe52p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdap-4 i", LIT (0x0p+0), LIT (0xc.90fdap-4), { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f30fa9c07dc0468p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f30fa9c07dc0468p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f30fa9c07dc0468p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f30fa9c07dc047p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xc.90fdbp-4 i", LIT (0x0p+0), LIT (0xc.90fdbp-4), { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06d6d6fff3655a3p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06d6d6fff3655a3p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06d6d6fff3655a3p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06d6d6fff3655a4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.63ap+12 + 0x1p+0 i", LIT (0x1.63ap+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x7.f673ecc6b39aff738e4p-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x7.f673ecc6b39aff738e8p-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x7.f673ecc6b39aff738e4p-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x7.f673ecc6b39aff738e8p-16420), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x1.63p+12 + 0x1p+0 i", LIT (0x1.63p+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0xe.6442e59c9ba29e34d4429f85ccp-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xe.6442e59c9ba29e34d4429f85ccp-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xe.6442e59c9ba29e34d4429f85ccp-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0xe.6442e59c9ba29e34d4429f85dp-16392), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x1.63p+8 + 0x1p+0 i", LIT (0x1.63p+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fc921d45c1e929p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fc921d45c1e929p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fc921d45c1e929p-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x1.76a2c6f034b4a7fc921d45c1e92ap-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.6dp+8 + 0x1p+0 i", LIT (0x1.6dp+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0xc.f47f20686b62b7024c3d69ff0358p-1056), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xc.f47f20686b62b7024c3d69ff0358p-1056), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xc.f47f20686b62b7024c3d69ff0358p-1056), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0xc.f47f20686b62b7024c3d69ff036p-1056), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0x8p+1020 i", LIT (0x1p+0), LIT (0x8p+1020), { LIT (0xe.0ec57df9e9489b83c566cd1868b8p-4), LIT (-0x3.9b7edf84053dda473c3ba3e75288p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b83c566cd1868b8p-4), LIT (-0x3.9b7edf84053dda473c3ba3e75286p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b83c566cd1868b8p-4), LIT (-0x3.9b7edf84053dda473c3ba3e75286p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b83c566cd1868cp-4), LIT (-0x3.9b7edf84053dda473c3ba3e75286p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0x8p+124 i", LIT (0x1p+0), LIT (0x8p+124), { LIT (0xe.8fe80b8795b6ed2c28e53930ce48p-4), LIT (0x3.ea075fdf18c8a74bfc7e25465e78p-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed2c28e53930ce48p-4), LIT (0x3.ea075fdf18c8a74bfc7e25465e78p-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed2c28e53930ce48p-4), LIT (0x3.ea075fdf18c8a74bfc7e25465e78p-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed2c28e53930ce5p-4), LIT (0x3.ea075fdf18c8a74bfc7e25465e7ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0x8p+16380 i", LIT (0x1p+0), LIT (0x8p+16380), { LIT (0xd.039cb06618c08bfe358cf75c6128p-4), LIT (0x2.92e1ce9b08cb660c9a8081990afap-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08bfe358cf75c6128p-4), LIT (0x2.92e1ce9b08cb660c9a8081990afcp-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08bfe358cf75c6128p-4), LIT (0x2.92e1ce9b08cb660c9a8081990afap-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08bfe358cf75c613p-4), LIT (0x2.92e1ce9b08cb660c9a8081990afcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x1p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xc.2f859c7fb3531523e975e1dad058p-4), LIT (-0x8.891dda2c06577145af81f4f5604p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb3531523e975e1dad058p-4), LIT (-0x8.891dda2c06577145af81f4f5604p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb3531523e975e1dad058p-4), LIT (-0x8.891dda2c06577145af81f4f56038p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb3531523e975e1dad06p-4), LIT (-0x8.891dda2c06577145af81f4f56038p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x1p+0), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x1.33b2569c333811735902f282a0fp+0), LIT (0x3.89f37a0888a0e05652b04c0aa334p-4), ERRNO_UNCHANGED }, { LIT (0x1.33b2569c333811735902f282a0fp+0), LIT (0x3.89f37a0888a0e05652b04c0aa334p-4), ERRNO_UNCHANGED }, { LIT (0x1.33b2569c333811735902f282a0fp+0), LIT (0x3.89f37a0888a0e05652b04c0aa334p-4), ERRNO_UNCHANGED }, { LIT (0x1.33b2569c333811735902f282a0f1p+0), LIT (0x3.89f37a0888a0e05652b04c0aa336p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0xf.fffffp+124 i", LIT (0x1p+0), LIT (0xf.fffffp+124), { LIT (0xd.c26353c068203bf3a2f7a9b94db8p-4), LIT (-0x3.60b2616c1339906858c23a90d004p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bf3a2f7a9b94dcp-4), LIT (-0x3.60b2616c1339906858c23a90d002p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bf3a2f7a9b94db8p-4), LIT (-0x3.60b2616c1339906858c23a90d002p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bf3a2f7a9b94dcp-4), LIT (-0x3.60b2616c1339906858c23a90d002p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.dp+4 + 0x1p+0 i", LIT (0x2.dp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x8.1cfa783d16f462a5a6cd1741d1a8p-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f462a5a6cd1741d1bp-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f462a5a6cd1741d1a8p-132), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x8.1cfa783d16f462a5a6cd1741d1bp-132), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.fp+4 + 0x1p+0 i", LIT (0x2.fp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241555288ba7825782p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241555288ba7825782p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241555288ba7825782p-136), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x2.60a8b2f7f5241555288ba7825784p-136), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16384 + +0 i", LIT (0x2p-16384), LIT (0x0p+0), { LIT (0x1.fffffffffffffffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1024 + +0 i", LIT (0x4p-1024), LIT (0x0p+0), { LIT (0x3.fffffffffffffffffffffffffffep-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x3.fffffffffffffffffffffffffffep-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x1.921fb4p+0 i", LIT (0x4p-1076), LIT (0x1.921fb4p+0), { LIT (0x2.7e3fd9c32f99fb414e4dcf68264ap-1028), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb414e4dcf68264cp-1028), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb414e4dcf68264ap-1028), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb414e4dcf68264cp-1028), LIT (0xc.a1bd99b5b58623cd91404ccd8cbp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x1.921fb54442d1846ap+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d1846ap+0), { LIT (0x1.2af1800dc70a09fe7b8c9b12f9bcp-944), LIT (-0x2.29478136aaf68d7b3b807fb349bcp+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fe7b8c9b12f9bdp-944), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fe7b8c9b12f9bcp-944), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fe7b8c9b12f9bdp-944), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x1.921fb54442d18p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d18p+0), { LIT (0x3.49961ed5af28cf18c004073f8964p-968), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18c004073f8964p-968), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18c004073f8964p-968), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18c004073f8966p-968), LIT (0x3.a052cf8639b69c1871a036cababep+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x1.921fb54442d19p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d19p+0), { LIT (0x7.a047a3b18a23c5f62c2ad1b17b8cp-972), LIT (-0x1.617a15494767a04882c320317f3fp+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5f62c2ad1b17b9p-972), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5f62c2ad1b17b8cp-972), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5f62c2ad1b17b9p-972), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x1.921fb6p+0 i", LIT (0x4p-1076), LIT (0x1.921fb6p+0), { LIT (0x7.7004796b7ae1a3831eb56826f958p-1028), LIT (-0x1.5d14946dc98975d6421a55284fe1p+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a3831eb56826f958p-1028), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a3831eb56826f958p-1028), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a3831eb56826f95cp-1028), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-128 + +0 i", LIT (0x4p-128), LIT (0x0p+0), { LIT (0x3.fffffffffffffffffffffffffffep-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384 + +0 i", LIT (0x4p-16384), LIT (0x0p+0), { LIT (0x3.fffffffffffffffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.fffffffffffffffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + +0 i", LIT (0x4p-16448), LIT (0x0p+0), { LIT (0x3.fffffffffffcp-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffcp-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + +0 i", LIT (0x4p-16496), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16496), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16496), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x7.fffffffffffffffffffffffffffcp-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x1.921fb4p+0 i", LIT (0x8p-152), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fb3865f33f6829c9b9ed04c94p-104), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f6829c9b9ed04c98p-104), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f6829c9b9ed04c94p-104), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f6829c9b9ed04c98p-104), LIT (0xc.a1bd99b5b58623cd91404ccd8cbp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x1.921fb54442d1846ap+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d1846ap+0), { LIT (0x2.55e3001b8e1413fcf7193625f378p-20), LIT (-0x2.29478136aaf68d7b3b807fb349bcp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f37ap-20), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f378p-20), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f37ap-20), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x1.921fb54442d18p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d18p+0), { LIT (0x6.932c3dab5e519e3180080e7f12c8p-44), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f12c8p-44), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f12c8p-44), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f12ccp-44), LIT (0x3.a052cf8639b69c1871a036cababep+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x1.921fb54442d19p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d19p+0), { LIT (0xf.408f476314478bec5855a362f718p-48), LIT (-0x1.617a15494767a04882c320317f3fp+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f72p-48), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f718p-48), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f72p-48), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x1.921fb6p+0 i", LIT (0x8p-152), LIT (0x1.921fb6p+0), { LIT (0xe.e008f2d6f5c347063d6ad04df2bp-104), LIT (-0x1.5d14946dc98975d6421a55284fe1p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347063d6ad04df2bp-104), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347063d6ad04df2bp-104), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347063d6ad04df2b8p-104), LIT (-0x1.5d14946dc98975d6421a55284fep+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + +0 i", LIT (0x8p-16448), LIT (0x0p+0), { LIT (0x7.fffffffffffcp-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x7.fffffffffffcp-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x1.921fb4p+0 i", LIT (0x8p-16448), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fb3865f33f6829c9b9edp-16400), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f33f6829c9b9edp-16400), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f33f6829c9b9edp-16400), LIT (0xc.a1bd99b5b58623cd91404ccd8ca8p+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f33f6829c9b9ed4p-16400), LIT (0xc.a1bd99b5b58623cd91404ccd8cbp+20), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x1.921fb54442d1846ap+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d1846ap+0), { LIT (0x2.55e3001b8e1413fcf7193625f378p-16316), LIT (-0x2.29478136aaf68d7b3b807fb349bcp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f37ap-16316), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f378p-16316), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f37ap-16316), LIT (-0x2.29478136aaf68d7b3b807fb349bap+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x1.921fb54442d18p+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d18p+0), { LIT (0x6.932c3dab5e519e3180080e7f12c8p-16340), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f12c8p-16340), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f12c8p-16340), LIT (0x3.a052cf8639b69c1871a036cababcp+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f12ccp-16340), LIT (0x3.a052cf8639b69c1871a036cababep+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x1.921fb54442d19p+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d19p+0), { LIT (0xf.408f476314478bec5855a362f718p-16344), LIT (-0x1.617a15494767a04882c320317f3fp+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f72p-16344), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f718p-16344), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f72p-16344), LIT (-0x1.617a15494767a04882c320317f3ep+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x1.921fb6p+0 i", LIT (0x8p-16448), LIT (0x1.921fb6p+0), { LIT (0xe.e008f2d6f5c347063d6ad04cp-16400), LIT (-0x1.5d14946dc98975d6421a55284fe1p+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5c347063d6ad04cp-16400), LIT (-0x1.5d14946dc98975d6421a55284fep+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5c347063d6ad04cp-16400), LIT (-0x1.5d14946dc98975d6421a55284fep+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5c347063d6ad05p-16400), LIT (-0x1.5d14946dc98975d6421a55284fep+24), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-972 + +0 i", LIT (0x8p-972), LIT (0x0p+0), { LIT (0x7.fffffffffffffffffffffffffffcp-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.35p+12 - 0xc.35p+12 i", LIT (0xc.35p+12), LIT (-0xc.35p+12), { LIT (0x1p+0), LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000000000000000001p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xc.35p+12 + 0xc.35p+12 i", LIT (0xc.35p+12), LIT (0xc.35p+12), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.5f6335b1af42bd62464d7689818cp+0), LIT (0x6.2c386076356ea000be129c14b8c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62464d7689818cp+0), LIT (0x6.2c386076356ea000be129c14b8c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62464d7689818cp+0), LIT (0x6.2c386076356ea000be129c14b8c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62464d7689818dp+0), LIT (0x6.2c386076356ea000be129c14b8c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (-0xf.72388p-4), LIT (0x2.87c848p-8), ERRNO_UNCHANGED }, { LIT (-0xf.72387p-4), LIT (0x2.87c84cp-8), ERRNO_UNCHANGED }, { LIT (-0xf.72387p-4), LIT (0x2.87c848p-8), ERRNO_UNCHANGED }, { LIT (-0xf.72387p-4), LIT (0x2.87c84cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-128 + +0 i", LIT (-0x4p-128), LIT (0x0p+0), { LIT (-0x4p-128), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-128), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffff8p-128), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffff8p-128), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152 + +0 i", LIT (-0x8p-152), LIT (0x0p+0), { LIT (-0x8p-152), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-152), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0xc.35p+12 - 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (-0xc.35p+12), { LIT (-0x1.000002p+0), LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0xc.35p+12 + 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (0xc.35p+12), { LIT (-0x1.000002p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 - 0x4p-128 i", LIT (0x0p+0), LIT (-0x4p-128), { LIT (0x0p+0), LIT (-0x4.000008p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x0p+0), LIT (-0x1p-148), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0x1.921fb4p+0 i", LIT (0x0p+0), LIT (0x1.921fb4p+0), { LIT (0x0p+0), LIT (0xc.a1bd9p+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bdap+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd9p+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bdap+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0x1.921fb6p+0 i", LIT (0x0p+0), LIT (0x1.921fb6p+0), { LIT (0x0p+0), LIT (-0x1.5d1496p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d1494p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d1494p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d1494p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0x4p-128 i", LIT (0x0p+0), LIT (0x4p-128), { LIT (0x0p+0), LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4.000008p-128), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x0p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x1p-148), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0xc.90fdap-4 i", LIT (0x0p+0), LIT (0xc.90fdap-4), { LIT (0x0p+0), LIT (0xf.ffffep-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffep-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0xc.90fdbp-4 i", LIT (0x0p+0), LIT (0xc.90fdbp-4), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.63ap+12 + 0x1p+0 i", LIT (0x1.63ap+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.63p+12 + 0x1p+0 i", LIT (0x1.63p+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.63p+8 + 0x1p+0 i", LIT (0x1.63p+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.6dp+8 + 0x1p+0 i", LIT (0x1.6dp+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0 + 0x8p+124 i", LIT (0x1p+0), LIT (0x8p+124), { LIT (0xe.8fe8p-4), LIT (0x3.ea075cp-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe81p-4), LIT (0x3.ea076p-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe8p-4), LIT (0x3.ea075cp-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe81p-4), LIT (0x3.ea076p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0 + 0xf.fffffp+124 i", LIT (0x1p+0), LIT (0xf.fffffp+124), { LIT (0xd.c2635p-4), LIT (-0x3.60b264p-4), ERRNO_UNCHANGED }, { LIT (0xd.c2635p-4), LIT (-0x3.60b26p-4), ERRNO_UNCHANGED }, { LIT (0xd.c2635p-4), LIT (-0x3.60b26p-4), ERRNO_UNCHANGED }, { LIT (0xd.c2636p-4), LIT (-0x3.60b26p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.dp+4 + 0x1p+0 i", LIT (0x2.dp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x8.1cfap-132), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x8.1cfa8p-132), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x8.1cfap-132), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (0x8.1cfa8p-132), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x2.fp+4 + 0x1p+0 i", LIT (0x2.fp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x2.60a8p-136), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x2.60a8p-136), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x2.60a8p-136), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (0x2.60bp-136), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-128 + +0 i", LIT (0x4p-128), LIT (0x0p+0), { LIT (0x3.fffff8p-128), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-128), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.fffff8p-128), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-128), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + 0x1.921fb4p+0 i", LIT (0x8p-152), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fbp-104), LIT (0xc.a1bd9p+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fbp-104), LIT (0xc.a1bdap+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fbp-104), LIT (0xc.a1bd9p+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb8p-104), LIT (0xc.a1bdap+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + 0x1.921fb6p+0 i", LIT (0x8p-152), LIT (0x1.921fb6p+0), { LIT (0xe.e008fp-104), LIT (-0x1.5d1496p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008fp-104), LIT (-0x1.5d1494p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008fp-104), LIT (-0x1.5d1494p+24), ERRNO_UNCHANGED }, { LIT (0xe.e009p-104), LIT (-0x1.5d1494p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xc.35p+12 - 0xc.35p+12 i", LIT (0xc.35p+12), LIT (-0xc.35p+12), { LIT (0x1p+0), LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0xc.35p+12 + 0xc.35p+12 i", LIT (0xc.35p+12), LIT (0xc.35p+12), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.5f6334p+0), LIT (0x6.2c386p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6336p+0), LIT (0x6.2c386p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6334p+0), LIT (0x6.2c386p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6336p+0), LIT (0x6.2c3868p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (-0xf.723876a6b9718p-4), LIT (0x2.87c84b87ef36ap-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b9718p-4), LIT (0x2.87c84b87ef36ap-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b971p-4), LIT (0x2.87c84b87ef36ap-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b971p-4), LIT (0x2.87c84b87ef36cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1024 + +0 i", LIT (-0x4p-1024), LIT (0x0p+0), { LIT (-0x4p-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.ffffffffffffcp-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.ffffffffffffcp-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076 + +0 i", LIT (-0x4p-1076), LIT (0x0p+0), { LIT (-0x4p-1076), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1076), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-128 + +0 i", LIT (-0x4p-128), LIT (0x0p+0), { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152 + +0 i", LIT (-0x8p-152), LIT (0x0p+0), { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-972 + +0 i", LIT (-0x8p-972), LIT (0x0p+0), { LIT (-0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-972), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xc.35p+12 - 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (-0xc.35p+12), { LIT (-0x1.0000000000001p+0), LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0xc.35p+12 + 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (0xc.35p+12), { LIT (-0x1.0000000000001p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0x4p-1024 i", LIT (0x0p+0), LIT (-0x4p-1024), { LIT (0x0p+0), LIT (-0x4.0000000000004p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-1024), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0x4p-1076 i", LIT (0x0p+0), LIT (-0x4p-1076), { LIT (0x0p+0), LIT (-0x8p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0x4p-128 i", LIT (0x0p+0), LIT (-0x4p-128), { LIT (0x0p+0), LIT (-0x4.0000000000004p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x0p+0), LIT (-0x8.0000000000008p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0x8p-972 i", LIT (0x0p+0), LIT (-0x8p-972), { LIT (0x0p+0), LIT (-0x8.0000000000008p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x1.921fb4p+0 i", LIT (0x0p+0), LIT (0x1.921fb4p+0), { LIT (0x0p+0), LIT (0xc.a1bd99b5b586p+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b586p+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b586p+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b5868p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x1.921fb54442d18p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d18p+0), { LIT (0x0p+0), LIT (0x3.a052cf8639b68p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b6ap+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b68p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b6ap+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x1.921fb54442d19p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d19p+0), { LIT (0x0p+0), LIT (-0x1.617a15494767bp+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x1.921fb6p+0 i", LIT (0x0p+0), LIT (0x1.921fb6p+0), { LIT (0x0p+0), LIT (-0x1.5d14946dc9898p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc9897p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc9897p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc9897p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x4p-1024 i", LIT (0x0p+0), LIT (0x4p-1024), { LIT (0x0p+0), LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4.0000000000004p-1024), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x4p-128 i", LIT (0x0p+0), LIT (0x4p-128), { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000004p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.0000000000008p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x8p-972 i", LIT (0x0p+0), LIT (0x8p-972), { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.0000000000008p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0xc.90fdaa22168c8p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c8p-4), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0xc.90fdaa22168cp-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168cp-4), { LIT (0x0p+0), LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0xc.90fdap-4 i", LIT (0x0p+0), LIT (0xc.90fdap-4), { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0xc.90fdbp-4 i", LIT (0x0p+0), LIT (0xc.90fdbp-4), { LIT (0x0p+0), LIT (0x1.000000bbbd2ecp+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ecp+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ecp+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2edp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.63ap+12 + 0x1p+0 i", LIT (0x1.63ap+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000001p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1.63p+12 + 0x1p+0 i", LIT (0x1.63p+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000001p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1.63p+8 + 0x1p+0 i", LIT (0x1.63p+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x1.76a2c6f034b48p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b4cp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b48p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000001p+0), LIT (0x1.76a2c6f034b4cp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1.6dp+8 + 0x1p+0 i", LIT (0x1.6dp+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0xc.f47fp-1056), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xc.f47f4p-1056), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xc.f47fp-1056), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000001p+0), LIT (0xc.f47f4p-1056), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 + 0x8p+1020 i", LIT (0x1p+0), LIT (0x8p+1020), { LIT (0xe.0ec57df9e9488p-4), LIT (-0x3.9b7edf84053dep-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9488p-4), LIT (-0x3.9b7edf84053dep-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9488p-4), LIT (-0x3.9b7edf84053dcp-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e949p-4), LIT (-0x3.9b7edf84053dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 + 0x8p+124 i", LIT (0x1p+0), LIT (0x8p+124), { LIT (0xe.8fe80b8795b68p-4), LIT (0x3.ea075fdf18c8ap-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b7p-4), LIT (0x3.ea075fdf18c8ap-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b68p-4), LIT (0x3.ea075fdf18c8ap-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b7p-4), LIT (0x3.ea075fdf18c8cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x1p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xc.2f859c7fb353p-4), LIT (-0x8.891dda2c06578p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb353p-4), LIT (-0x8.891dda2c06578p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb353p-4), LIT (-0x8.891dda2c0657p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb3538p-4), LIT (-0x8.891dda2c0657p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 + 0xf.fffffp+124 i", LIT (0x1p+0), LIT (0xf.fffffp+124), { LIT (0xd.c26353c0682p-4), LIT (-0x3.60b2616c1339ap-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c0682p-4), LIT (-0x3.60b2616c1339ap-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c0682p-4), LIT (-0x3.60b2616c13398p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068208p-4), LIT (-0x3.60b2616c13398p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.dp+4 + 0x1p+0 i", LIT (0x2.dp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x8.1cfa783d16f4p-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f48p-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f4p-132), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), LIT (0x8.1cfa783d16f48p-132), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.fp+4 + 0x1p+0 i", LIT (0x2.fp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x2.60a8b2f7f524p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5242p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f524p-136), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), LIT (0x2.60a8b2f7f5242p-136), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1024 + +0 i", LIT (0x4p-1024), LIT (0x0p+0), { LIT (0x3.ffffffffffffcp-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.ffffffffffffcp-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x1.921fb4p+0 i", LIT (0x4p-1076), LIT (0x1.921fb4p+0), { LIT (0x2.7e3fd9c32f98p-1028), LIT (0xc.a1bd99b5b586p+20), UNDERFLOW_EXCEPTION }, { LIT (0x2.7e3fd9c32f98p-1028), LIT (0xc.a1bd99b5b586p+20), UNDERFLOW_EXCEPTION }, { LIT (0x2.7e3fd9c32f98p-1028), LIT (0xc.a1bd99b5b586p+20), UNDERFLOW_EXCEPTION }, { LIT (0x2.7e3fd9c32f9cp-1028), LIT (0xc.a1bd99b5b5868p+20), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x1.921fb54442d18p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d18p+0), { LIT (0x3.49961ed5af28cp-968), LIT (0x3.a052cf8639b68p+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cp-968), LIT (0x3.a052cf8639b6ap+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cp-968), LIT (0x3.a052cf8639b68p+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28ep-968), LIT (0x3.a052cf8639b6ap+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x1.921fb54442d19p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d19p+0), { LIT (0x7.a047a3b18a23cp-972), LIT (-0x1.617a15494767bp+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23cp-972), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23cp-972), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a24p-972), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x1.921fb6p+0 i", LIT (0x4p-1076), LIT (0x1.921fb6p+0), { LIT (0x7.7004796b7aep-1028), LIT (-0x1.5d14946dc9898p+24), UNDERFLOW_EXCEPTION }, { LIT (0x7.7004796b7aep-1028), LIT (-0x1.5d14946dc9897p+24), UNDERFLOW_EXCEPTION }, { LIT (0x7.7004796b7aep-1028), LIT (-0x1.5d14946dc9897p+24), UNDERFLOW_EXCEPTION }, { LIT (0x7.7004796b7ae4p-1028), LIT (-0x1.5d14946dc9897p+24), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-128 + +0 i", LIT (0x4p-128), LIT (0x0p+0), { LIT (0x3.ffffffffffffep-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x7.ffffffffffffcp-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x1.921fb4p+0 i", LIT (0x8p-152), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fb3865f33cp-104), LIT (0xc.a1bd99b5b586p+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f34p-104), LIT (0xc.a1bd99b5b586p+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33cp-104), LIT (0xc.a1bd99b5b586p+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f34p-104), LIT (0xc.a1bd99b5b5868p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x1.921fb54442d18p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d18p+0), { LIT (0x6.932c3dab5e518p-44), LIT (0x3.a052cf8639b68p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e518p-44), LIT (0x3.a052cf8639b6ap+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e518p-44), LIT (0x3.a052cf8639b68p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e51cp-44), LIT (0x3.a052cf8639b6ap+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x1.921fb54442d19p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d19p+0), { LIT (0xf.408f476314478p-48), LIT (-0x1.617a15494767bp+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478p-48), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478p-48), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED }, { LIT (0xf.408f47631448p-48), LIT (-0x1.617a15494767ap+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x1.921fb6p+0 i", LIT (0x8p-152), LIT (0x1.921fb6p+0), { LIT (0xe.e008f2d6f5c3p-104), LIT (-0x1.5d14946dc9898p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c38p-104), LIT (-0x1.5d14946dc9897p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c3p-104), LIT (-0x1.5d14946dc9897p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c38p-104), LIT (-0x1.5d14946dc9897p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-972 + +0 i", LIT (0x8p-972), LIT (0x0p+0), { LIT (0x7.ffffffffffffcp-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.35p+12 - 0xc.35p+12 i", LIT (0xc.35p+12), LIT (-0xc.35p+12), { LIT (0x1p+0), LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000001p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0xc.35p+12 + 0xc.35p+12 i", LIT (0xc.35p+12), LIT (0xc.35p+12), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000001p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.5f6335b1af42bp+0), LIT (0x6.2c386076356e8p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42cp+0), LIT (0x6.2c386076356ecp-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bp+0), LIT (0x6.2c386076356e8p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42cp+0), LIT (0x6.2c386076356ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (-0xf.723876a6b9717849ff07dfd98cp-4), LIT (0x2.87c84b87ef36a32deb7b60c8a6p-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b9717849ff07dfd988p-4), LIT (0x2.87c84b87ef36a32deb7b60c8a7p-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b9717849ff07dfd988p-4), LIT (0x2.87c84b87ef36a32deb7b60c8a6p-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b9717849ff07dfd988p-4), LIT (0x2.87c84b87ef36a32deb7b60c8a7p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1024 + +0 i", LIT (-0x4p-1024), LIT (0x0p+0), { LIT (-0x4p-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x3.ffffffffffffcp-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x3.ffffffffffffcp-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076 + +0 i", LIT (-0x4p-1076), LIT (0x0p+0), { LIT (-0x4p-1076), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1076), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-128 + +0 i", LIT (-0x4p-128), LIT (0x0p+0), { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffffffffffffffffp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffffffffffffffffp-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152 + +0 i", LIT (-0x8p-152), LIT (0x0p+0), { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffep-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffep-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-972 + +0 i", LIT (-0x8p-972), LIT (0x0p+0), { LIT (-0x8p-972), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x8p-972), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x7.fffffffffffffffffffffffffcp-972), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x7.fffffffffffffffffffffffffcp-972), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "-0xc.35p+12 - 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (-0xc.35p+12), { LIT (-0x1.000000000000000000000000008p+0), LIT (-0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0xc.35p+12 + 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (0xc.35p+12), { LIT (-0x1.000000000000000000000000008p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0x4p-1024 i", LIT (0x0p+0), LIT (-0x4p-1024), { LIT (0x0p+0), LIT (-0x4.0000000000004p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0x4p-1076 i", LIT (0x0p+0), LIT (-0x4p-1076), { LIT (0x0p+0), LIT (-0x8p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0x4p-128 i", LIT (0x0p+0), LIT (-0x4p-128), { LIT (0x0p+0), LIT (-0x4.00000000000000000000000002p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x0p+0), LIT (-0x8.00000000000000000000000004p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0x8p-972 i", LIT (0x0p+0), LIT (-0x8p-972), { LIT (0x0p+0), LIT (-0x8.00000000000000000000000004p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x1.921fb4p+0 i", LIT (0x0p+0), LIT (0x1.921fb4p+0), { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cd91404ccd9p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x1.921fb54442d1846ap+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d1846ap+0), { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7b3b807fb34ap+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7b3b807fb34ap+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7b3b807fb349p+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7b3b807fb349p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x1.921fb54442d18p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d18p+0), { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1871a036cabap+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1871a036cabbp+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1871a036cabap+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1871a036cabbp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x1.921fb54442d19p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d19p+0), { LIT (0x0p+0), LIT (-0x1.617a15494767a04882c320317f8p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a04882c320317fp+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a04882c320317fp+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a04882c320317fp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x1.921fb6p+0 i", LIT (0x0p+0), LIT (0x1.921fb6p+0), { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6421a55285p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6421a55285p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6421a55284f8p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6421a55284f8p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x4p-1024 i", LIT (0x0p+0), LIT (0x4p-1024), { LIT (0x0p+0), LIT (0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4.0000000000004p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x4p-128 i", LIT (0x0p+0), LIT (0x4p-128), { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.00000000000000000000000002p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.00000000000000000000000004p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x8p-972 i", LIT (0x0p+0), LIT (0x8p-972), { LIT (0x0p+0), LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x8.00000000000000000000000004p-972), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xc.90fdaa22168c234c4c6628b80cp-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234c4c6628b80cp-4), { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xc.90fdaa22168c234c4c6628b81p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234c4c6628b81p-4), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xc.90fdaa22168c234p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234p-4), { LIT (0x0p+0), LIT (0xf.ffffffffffffffe76733ae8fe4p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffe76733ae8fe4p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffe76733ae8fe4p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffe76733ae8fe8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xc.90fdaa22168c235p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c235p-4), { LIT (0x0p+0), LIT (0x1.000000000000000076733ae8fep+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000000000000076733ae8fe8p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000000000000076733ae8fep+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000000000000076733ae8fe8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xc.90fdaa22168c8p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c8p-4), { LIT (0x0p+0), LIT (0x1.0000000000000b9676733ae8fe8p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b9676733ae8fe8p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b9676733ae8fe8p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b9676733ae8ffp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xc.90fdaa22168cp-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168cp-4), { LIT (0x0p+0), LIT (0xf.ffffffffffffb9676733ae8fe4p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb9676733ae8fe4p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb9676733ae8fe4p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb9676733ae8fe8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xc.90fdap-4 i", LIT (0x0p+0), LIT (0xc.90fdap-4), { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f30fa9c07dc04p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f30fa9c07dc04p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f30fa9c07dc04p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f30fa9c07dc08p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xc.90fdbp-4 i", LIT (0x0p+0), LIT (0xc.90fdbp-4), { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06d6d6fff36558p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06d6d6fff36558p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06d6d6fff36558p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06d6d6fff3656p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.63ap+12 + 0x1p+0 i", LIT (0x1.63ap+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.63p+12 + 0x1p+0 i", LIT (0x1.63p+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.63p+8 + 0x1p+0 i", LIT (0x1.63p+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x1.76a2c6f034b48p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b4cp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b48p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x1.76a2c6f034b4cp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.6dp+8 + 0x1p+0 i", LIT (0x1.6dp+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0xc.f47fp-1056), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xc.f47f4p-1056), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xc.f47fp-1056), UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (0xc.f47f4p-1056), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + 0x8p+1020 i", LIT (0x1p+0), LIT (0x8p+1020), { LIT (0xe.0ec57df9e9489b83c566cd1868p-4), LIT (-0x3.9b7edf84053dda473c3ba3e753p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b83c566cd1868p-4), LIT (-0x3.9b7edf84053dda473c3ba3e753p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b83c566cd1868p-4), LIT (-0x3.9b7edf84053dda473c3ba3e752p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b83c566cd186cp-4), LIT (-0x3.9b7edf84053dda473c3ba3e752p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + 0x8p+124 i", LIT (0x1p+0), LIT (0x8p+124), { LIT (0xe.8fe80b8795b6ed2c28e53930ccp-4), LIT (0x3.ea075fdf18c8a74bfc7e25465ep-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed2c28e53930dp-4), LIT (0x3.ea075fdf18c8a74bfc7e25465ep-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed2c28e53930ccp-4), LIT (0x3.ea075fdf18c8a74bfc7e25465ep-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed2c28e53930dp-4), LIT (0x3.ea075fdf18c8a74bfc7e25465fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x1p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xc.2f859c7fb3531523e975e1dadp-4), LIT (-0x8.891dda2c06577145af81f4f564p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb3531523e975e1dadp-4), LIT (-0x8.891dda2c06577145af81f4f56p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb3531523e975e1dadp-4), LIT (-0x8.891dda2c06577145af81f4f56p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb3531523e975e1dad4p-4), LIT (-0x8.891dda2c06577145af81f4f56p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x1p+0), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x1.33b2569c333811735902f282a08p+0), LIT (0x3.89f37a0888a0e05652b04c0aa3p-4), ERRNO_UNCHANGED }, { LIT (0x1.33b2569c333811735902f282a1p+0), LIT (0x3.89f37a0888a0e05652b04c0aa3p-4), ERRNO_UNCHANGED }, { LIT (0x1.33b2569c333811735902f282a08p+0), LIT (0x3.89f37a0888a0e05652b04c0aa3p-4), ERRNO_UNCHANGED }, { LIT (0x1.33b2569c333811735902f282a1p+0), LIT (0x3.89f37a0888a0e05652b04c0aa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + 0xf.fffffp+124 i", LIT (0x1p+0), LIT (0xf.fffffp+124), { LIT (0xd.c26353c068203bf3a2f7a9b94cp-4), LIT (-0x3.60b2616c1339906858c23a90d1p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bf3a2f7a9b94cp-4), LIT (-0x3.60b2616c1339906858c23a90dp-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bf3a2f7a9b94cp-4), LIT (-0x3.60b2616c1339906858c23a90dp-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bf3a2f7a9b95p-4), LIT (-0x3.60b2616c1339906858c23a90dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.dp+4 + 0x1p+0 i", LIT (0x2.dp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x8.1cfa783d16f462a5a6cd1741dp-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f462a5a6cd1741dp-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f462a5a6cd1741dp-132), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x8.1cfa783d16f462a5a6cd1741d4p-132), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.fp+4 + 0x1p+0 i", LIT (0x2.fp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241555288ba78257p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241555288ba78258p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241555288ba78257p-136), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x2.60a8b2f7f5241555288ba78258p-136), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1024 + +0 i", LIT (0x4p-1024), LIT (0x0p+0), { LIT (0x3.ffffffffffffcp-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffffffffffffcp-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1024), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x1.921fb4p+0 i", LIT (0x4p-1076), LIT (0x1.921fb4p+0), { LIT (0x2.7e3fd9c32f98p-1028), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), UNDERFLOW_EXCEPTION }, { LIT (0x2.7e3fd9c32f98p-1028), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), UNDERFLOW_EXCEPTION }, { LIT (0x2.7e3fd9c32f98p-1028), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), UNDERFLOW_EXCEPTION }, { LIT (0x2.7e3fd9c32f9cp-1028), LIT (0xc.a1bd99b5b58623cd91404ccd9p+20), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x1.921fb54442d1846ap+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d1846ap+0), { LIT (0x1.2af1800dc70a09fe7b8c9b12f98p-944), LIT (-0x2.29478136aaf68d7b3b807fb34ap+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fe7b8c9b12f98p-944), LIT (-0x2.29478136aaf68d7b3b807fb34ap+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fe7b8c9b12f98p-944), LIT (-0x2.29478136aaf68d7b3b807fb349p+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fe7b8c9b12fap-944), LIT (-0x2.29478136aaf68d7b3b807fb349p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x1.921fb54442d18p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d18p+0), { LIT (0x3.49961ed5af28cf18c004073f89p-968), LIT (0x3.a052cf8639b69c1871a036cabap+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18c004073f89p-968), LIT (0x3.a052cf8639b69c1871a036cabbp+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18c004073f89p-968), LIT (0x3.a052cf8639b69c1871a036cabap+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18c004073f8ap-968), LIT (0x3.a052cf8639b69c1871a036cabbp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x1.921fb54442d19p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d19p+0), { LIT (0x7.a047a3b18a23c5f62c2ad1b178p-972), LIT (-0x1.617a15494767a04882c320317f8p+52), UNDERFLOW_EXCEPTION }, { LIT (0x7.a047a3b18a23c5f62c2ad1b17cp-972), LIT (-0x1.617a15494767a04882c320317fp+52), UNDERFLOW_EXCEPTION }, { LIT (0x7.a047a3b18a23c5f62c2ad1b178p-972), LIT (-0x1.617a15494767a04882c320317fp+52), UNDERFLOW_EXCEPTION }, { LIT (0x7.a047a3b18a23c5f62c2ad1b17cp-972), LIT (-0x1.617a15494767a04882c320317fp+52), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x1.921fb6p+0 i", LIT (0x4p-1076), LIT (0x1.921fb6p+0), { LIT (0x7.7004796b7aep-1028), LIT (-0x1.5d14946dc98975d6421a55285p+24), UNDERFLOW_EXCEPTION }, { LIT (0x7.7004796b7aep-1028), LIT (-0x1.5d14946dc98975d6421a55285p+24), UNDERFLOW_EXCEPTION }, { LIT (0x7.7004796b7aep-1028), LIT (-0x1.5d14946dc98975d6421a55284f8p+24), UNDERFLOW_EXCEPTION }, { LIT (0x7.7004796b7ae4p-1028), LIT (-0x1.5d14946dc98975d6421a55284f8p+24), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-128 + +0 i", LIT (0x4p-128), LIT (0x0p+0), { LIT (0x3.ffffffffffffffffffffffffffp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffffp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x7.fffffffffffffffffffffffffep-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x1.921fb4p+0 i", LIT (0x8p-152), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fb3865f33f6829c9b9ed04cp-104), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f6829c9b9ed04cp-104), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f6829c9b9ed04cp-104), LIT (0xc.a1bd99b5b58623cd91404ccd8cp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f6829c9b9ed04ep-104), LIT (0xc.a1bd99b5b58623cd91404ccd9p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x1.921fb54442d1846ap+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d1846ap+0), { LIT (0x2.55e3001b8e1413fcf7193625f3p-20), LIT (-0x2.29478136aaf68d7b3b807fb34ap+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f3p-20), LIT (-0x2.29478136aaf68d7b3b807fb34ap+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f3p-20), LIT (-0x2.29478136aaf68d7b3b807fb349p+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcf7193625f4p-20), LIT (-0x2.29478136aaf68d7b3b807fb349p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x1.921fb54442d18p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d18p+0), { LIT (0x6.932c3dab5e519e3180080e7f12p-44), LIT (0x3.a052cf8639b69c1871a036cabap+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f12p-44), LIT (0x3.a052cf8639b69c1871a036cabbp+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f12p-44), LIT (0x3.a052cf8639b69c1871a036cabap+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3180080e7f14p-44), LIT (0x3.a052cf8639b69c1871a036cabbp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x1.921fb54442d19p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d19p+0), { LIT (0xf.408f476314478bec5855a362f4p-48), LIT (-0x1.617a15494767a04882c320317f8p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f8p-48), LIT (-0x1.617a15494767a04882c320317fp+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f4p-48), LIT (-0x1.617a15494767a04882c320317fp+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bec5855a362f8p-48), LIT (-0x1.617a15494767a04882c320317fp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x1.921fb6p+0 i", LIT (0x8p-152), LIT (0x1.921fb6p+0), { LIT (0xe.e008f2d6f5c347063d6ad04dfp-104), LIT (-0x1.5d14946dc98975d6421a55285p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347063d6ad04df4p-104), LIT (-0x1.5d14946dc98975d6421a55285p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347063d6ad04dfp-104), LIT (-0x1.5d14946dc98975d6421a55284f8p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347063d6ad04df4p-104), LIT (-0x1.5d14946dc98975d6421a55284f8p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-972 + +0 i", LIT (0x8p-972), LIT (0x0p+0), { LIT (0x7.fffffffffffffffffffffffffcp-972), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8p-972), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x7.fffffffffffffffffffffffffcp-972), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8p-972), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.35p+12 - 0xc.35p+12 i", LIT (0xc.35p+12), LIT (-0xc.35p+12), { LIT (0x1p+0), LIT (-0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.35p+12 + 0xc.35p+12 i", LIT (0xc.35p+12), LIT (0xc.35p+12), { LIT (0x1p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.5f6335b1af42bd62464d7689818p+0), LIT (0x6.2c386076356ea000be129c14b8p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62464d7689818p+0), LIT (0x6.2c386076356ea000be129c14b8p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62464d7689818p+0), LIT (0x6.2c386076356ea000be129c14b8p-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62464d768982p+0), LIT (0x6.2c386076356ea000be129c14bap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (-0xf.723876a6b971785p-4), LIT (0x2.87c84b87ef36a32cp-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b971785p-4), LIT (0x2.87c84b87ef36a32cp-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b971784p-4), LIT (0x2.87c84b87ef36a32cp-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b971784p-4), LIT (0x2.87c84b87ef36a33p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p-16384 + +0 i", LIT (-0x2p-16384), LIT (0x0p+0), { LIT (-0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1024 + +0 i", LIT (-0x4p-1024), LIT (0x0p+0), { LIT (-0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076 + +0 i", LIT (-0x4p-1076), LIT (0x0p+0), { LIT (-0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-128 + +0 i", LIT (-0x4p-128), LIT (0x0p+0), { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384 + +0 i", LIT (-0x4p-16384), LIT (0x0p+0), { LIT (-0x4p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffff8p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffff8p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 + +0 i", LIT (-0x8p-152), LIT (0x0p+0), { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-16448 + +0 i", LIT (-0x8p-16448), LIT (0x0p+0), { LIT (-0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-972 + +0 i", LIT (-0x8p-972), LIT (0x0p+0), { LIT (-0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xc.35p+12 - 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (-0xc.35p+12), { LIT (-0x1.0000000000000002p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0xc.35p+12 + 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (0xc.35p+12), { LIT (-0x1.0000000000000002p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x2p-16384 i", LIT (0x0p+0), LIT (-0x2p-16384), { LIT (0x0p+0), LIT (-0x2.0000000000000008p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x4p-1024 i", LIT (0x0p+0), LIT (-0x4p-1024), { LIT (0x0p+0), LIT (-0x4.0000000000000008p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x4p-1076 i", LIT (0x0p+0), LIT (-0x4p-1076), { LIT (0x0p+0), LIT (-0x4.0000000000000008p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x4p-128 i", LIT (0x0p+0), LIT (-0x4p-128), { LIT (0x0p+0), LIT (-0x4.0000000000000008p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x4p-16384 i", LIT (0x0p+0), LIT (-0x4p-16384), { LIT (0x0p+0), LIT (-0x4.0000000000000008p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x0p+0), LIT (-0x8.000000000000001p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x8p-16448 i", LIT (0x0p+0), LIT (-0x8p-16448), { LIT (0x0p+0), LIT (-0x1p-16444), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x8p-972 i", LIT (0x0p+0), LIT (-0x8p-972), { LIT (0x0p+0), LIT (-0x8.000000000000001p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x1.921fb4p+0 i", LIT (0x0p+0), LIT (0x1.921fb4p+0), { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x1.921fb54442d1846ap+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d1846ap+0), { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x1.921fb54442d18p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d18p+0), { LIT (0x0p+0), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x1.921fb54442d19p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d19p+0), { LIT (0x0p+0), LIT (-0x1.617a15494767a04ap+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x1.921fb6p+0 i", LIT (0x0p+0), LIT (0x1.921fb6p+0), { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d8p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x2p-16384 i", LIT (0x0p+0), LIT (0x2p-16384), { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x2.0000000000000008p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4p-1024 i", LIT (0x0p+0), LIT (0x4p-1024), { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000008p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000008p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4p-128 i", LIT (0x0p+0), LIT (0x4p-128), { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000008p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4p-16384 i", LIT (0x0p+0), LIT (0x4p-16384), { LIT (0x0p+0), LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x4.0000000000000008p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.000000000000001p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p-16448 i", LIT (0x0p+0), LIT (0x8p-16448), { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x1p-16444), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p-972 i", LIT (0x0p+0), LIT (0x8p-972), { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.000000000000001p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0xc.90fdaa22168c234p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234p-4), { LIT (0x0p+0), LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0xc.90fdaa22168c235p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c235p-4), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0xc.90fdaa22168c8p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c8p-4), { LIT (0x0p+0), LIT (0x1.0000000000000b96p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b96p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b96p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b98p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0xc.90fdaa22168cp-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168cp-4), { LIT (0x0p+0), LIT (0xf.ffffffffffffb96p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb96p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb96p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb97p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0xc.90fdap-4 i", LIT (0x0p+0), LIT (0xc.90fdap-4), { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f3p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f3p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f3p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0xc.90fdbp-4 i", LIT (0x0p+0), LIT (0xc.90fdbp-4), { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06cp+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06ep+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06cp+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.63ap+12 + 0x1p+0 i", LIT (0x1.63ap+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x7.f673ec8p-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x7.f673edp-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x7.f673ec8p-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0x7.f673edp-16420), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x1.63p+12 + 0x1p+0 i", LIT (0x1.63p+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0xe.6442e59c9ba298p-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xe.6442e59c9ba2ap-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xe.6442e59c9ba298p-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0xe.6442e59c9ba2ap-16392), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x1.63p+8 + 0x1p+0 i", LIT (0x1.63p+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fcp-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fcp-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fcp-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x1.76a2c6f034b4a7fep-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.6dp+8 + 0x1p+0 i", LIT (0x1.6dp+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0xc.f47f20686b62b7p-1056), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xc.f47f20686b62b7p-1056), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xc.f47f20686b62b7p-1056), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0xc.f47f20686b62b71p-1056), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0x8p+1020 i", LIT (0x1p+0), LIT (0x8p+1020), { LIT (0xe.0ec57df9e9489b8p-4), LIT (-0x3.9b7edf84053dda48p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b8p-4), LIT (-0x3.9b7edf84053dda48p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b8p-4), LIT (-0x3.9b7edf84053dda44p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b9p-4), LIT (-0x3.9b7edf84053dda44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0x8p+124 i", LIT (0x1p+0), LIT (0x8p+124), { LIT (0xe.8fe80b8795b6ed2p-4), LIT (0x3.ea075fdf18c8a748p-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed3p-4), LIT (0x3.ea075fdf18c8a74cp-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed2p-4), LIT (0x3.ea075fdf18c8a748p-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed3p-4), LIT (0x3.ea075fdf18c8a74cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0x8p+16380 i", LIT (0x1p+0), LIT (0x8p+16380), { LIT (0xd.039cb06618c08bfp-4), LIT (0x2.92e1ce9b08cb660cp-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08cp-4), LIT (0x2.92e1ce9b08cb660cp-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08bfp-4), LIT (0x2.92e1ce9b08cb660cp-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08cp-4), LIT (0x2.92e1ce9b08cb661p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x1p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xc.2f859c7fb353152p-4), LIT (-0x8.891dda2c0657715p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb353152p-4), LIT (-0x8.891dda2c0657714p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb353152p-4), LIT (-0x8.891dda2c0657714p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb353153p-4), LIT (-0x8.891dda2c0657714p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0xf.fffffp+124 i", LIT (0x1p+0), LIT (0xf.fffffp+124), { LIT (0xd.c26353c068203bfp-4), LIT (-0x3.60b2616c1339906cp-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bfp-4), LIT (-0x3.60b2616c13399068p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bfp-4), LIT (-0x3.60b2616c13399068p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203cp-4), LIT (-0x3.60b2616c13399068p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.dp+4 + 0x1p+0 i", LIT (0x2.dp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x8.1cfa783d16f462ap-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f462ap-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f462ap-132), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x8.1cfa783d16f462bp-132), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.fp+4 + 0x1p+0 i", LIT (0x2.fp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241554p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241554p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241554p-136), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x2.60a8b2f7f5241558p-136), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16384 + +0 i", LIT (0x2p-16384), LIT (0x0p+0), { LIT (0x1.fffffffffffffff8p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffff8p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1024 + +0 i", LIT (0x4p-1024), LIT (0x0p+0), { LIT (0x3.fffffffffffffffcp-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x3.fffffffffffffffcp-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x1.921fb4p+0 i", LIT (0x4p-1076), LIT (0x1.921fb4p+0), { LIT (0x2.7e3fd9c32f99fb4p-1028), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb4p-1028), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb4p-1028), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb44p-1028), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x1.921fb54442d1846ap+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d1846ap+0), { LIT (0x1.2af1800dc70a09fep-944), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fep-944), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fep-944), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a0ap-944), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x1.921fb54442d18p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d18p+0), { LIT (0x3.49961ed5af28cf18p-968), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18p-968), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18p-968), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf1cp-968), LIT (0x3.a052cf8639b69c1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x1.921fb54442d19p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d19p+0), { LIT (0x7.a047a3b18a23c5fp-972), LIT (-0x1.617a15494767a04ap+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5f8p-972), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5fp-972), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5f8p-972), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x1.921fb6p+0 i", LIT (0x4p-1076), LIT (0x1.921fb6p+0), { LIT (0x7.7004796b7ae1a38p-1028), LIT (-0x1.5d14946dc98975d8p+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a38p-1028), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a38p-1028), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a388p-1028), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-128 + +0 i", LIT (0x4p-128), LIT (0x0p+0), { LIT (0x3.fffffffffffffffcp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384 + +0 i", LIT (0x4p-16384), LIT (0x0p+0), { LIT (0x3.fffffffffffffff8p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.fffffffffffffff8p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x7.fffffffffffffff8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x1.921fb4p+0 i", LIT (0x8p-152), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fb3865f33f68p-104), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f68p-104), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f68p-104), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f688p-104), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x1.921fb54442d1846ap+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d1846ap+0), { LIT (0x2.55e3001b8e1413fcp-20), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcp-20), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcp-20), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1414p-20), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x1.921fb54442d18p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d18p+0), { LIT (0x6.932c3dab5e519e3p-44), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3p-44), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3p-44), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e38p-44), LIT (0x3.a052cf8639b69c1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x1.921fb54442d19p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d19p+0), { LIT (0xf.408f476314478bep-48), LIT (-0x1.617a15494767a04ap+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bfp-48), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bep-48), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bfp-48), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x1.921fb6p+0 i", LIT (0x8p-152), LIT (0x1.921fb6p+0), { LIT (0xe.e008f2d6f5c347p-104), LIT (-0x1.5d14946dc98975d8p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347p-104), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347p-104), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c3471p-104), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + +0 i", LIT (0x8p-16448), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x1.921fb4p+0 i", LIT (0x8p-16448), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fb3865f3p-16400), LIT (0xc.a1bd99b5b58623cp+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f3p-16400), LIT (0xc.a1bd99b5b58623dp+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f3p-16400), LIT (0xc.a1bd99b5b58623cp+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f38p-16400), LIT (0xc.a1bd99b5b58623dp+20), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x1.921fb54442d1846ap+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d1846ap+0), { LIT (0x2.55e3001b8e1413fcp-16316), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcp-16316), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcp-16316), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1414p-16316), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x1.921fb54442d18p+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d18p+0), { LIT (0x6.932c3dab5e519e3p-16340), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3p-16340), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3p-16340), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e38p-16340), LIT (0x3.a052cf8639b69c1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x1.921fb54442d19p+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d19p+0), { LIT (0xf.408f476314478bep-16344), LIT (-0x1.617a15494767a04ap+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bfp-16344), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bep-16344), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bfp-16344), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x1.921fb6p+0 i", LIT (0x8p-16448), LIT (0x1.921fb6p+0), { LIT (0xe.e008f2d6f5cp-16400), LIT (-0x1.5d14946dc98975d8p+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5cp-16400), LIT (-0x1.5d14946dc98975d6p+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5cp-16400), LIT (-0x1.5d14946dc98975d6p+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5c8p-16400), LIT (-0x1.5d14946dc98975d6p+24), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-972 + +0 i", LIT (0x8p-972), LIT (0x0p+0), { LIT (0x7.fffffffffffffff8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.35p+12 - 0xc.35p+12 i", LIT (0xc.35p+12), LIT (-0xc.35p+12), { LIT (0x1p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0xc.35p+12 + 0xc.35p+12 i", LIT (0xc.35p+12), LIT (0xc.35p+12), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.5f6335b1af42bd62p+0), LIT (0x6.2c386076356eap-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62p+0), LIT (0x6.2c386076356eap-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62p+0), LIT (0x6.2c386076356eap-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd64p+0), LIT (0x6.2c386076356ea008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (-0xf.723876a6b971785p-4), LIT (0x2.87c84b87ef36a32cp-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b971785p-4), LIT (0x2.87c84b87ef36a32cp-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b971784p-4), LIT (0x2.87c84b87ef36a32cp-8), ERRNO_UNCHANGED }, { LIT (-0xf.723876a6b971784p-4), LIT (0x2.87c84b87ef36a33p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p-16384 + +0 i", LIT (-0x2p-16384), LIT (0x0p+0), { LIT (-0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1024 + +0 i", LIT (-0x4p-1024), LIT (0x0p+0), { LIT (-0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076 + +0 i", LIT (-0x4p-1076), LIT (0x0p+0), { LIT (-0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-128 + +0 i", LIT (-0x4p-128), LIT (0x0p+0), { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384 + +0 i", LIT (-0x4p-16384), LIT (0x0p+0), { LIT (-0x4p-16384), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x4p-16384), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-16384), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-16384), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16448 + +0 i", LIT (-0x4p-16448), LIT (0x0p+0), { LIT (-0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 + +0 i", LIT (-0x8p-152), LIT (0x0p+0), { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-16448 + +0 i", LIT (-0x8p-16448), LIT (0x0p+0), { LIT (-0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-972 + +0 i", LIT (-0x8p-972), LIT (0x0p+0), { LIT (-0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xc.35p+12 - 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (-0xc.35p+12), { LIT (-0x1.0000000000000002p+0), LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0xc.35p+12 + 0xc.35p+12 i", LIT (-0xc.35p+12), LIT (0xc.35p+12), { LIT (-0x1.0000000000000002p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x1p+0), LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x2p-16384 i", LIT (0x0p+0), LIT (-0x2p-16384), { LIT (0x0p+0), LIT (-0x2.0000000000000004p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x4p-1024 i", LIT (0x0p+0), LIT (-0x4p-1024), { LIT (0x0p+0), LIT (-0x4.0000000000000008p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x4p-1076 i", LIT (0x0p+0), LIT (-0x4p-1076), { LIT (0x0p+0), LIT (-0x4.0000000000000008p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x4p-128 i", LIT (0x0p+0), LIT (-0x4p-128), { LIT (0x0p+0), LIT (-0x4.0000000000000008p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x4p-16384 i", LIT (0x0p+0), LIT (-0x4p-16384), { LIT (0x0p+0), LIT (-0x4.0000000000000008p-16384), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x4p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x4p-16448 i", LIT (0x0p+0), LIT (-0x4p-16448), { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x0p+0), LIT (-0x8.000000000000001p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x8p-16448 i", LIT (0x0p+0), LIT (-0x8p-16448), { LIT (0x0p+0), LIT (-0xcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x8p-972 i", LIT (0x0p+0), LIT (-0x8p-972), { LIT (0x0p+0), LIT (-0x8.000000000000001p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x1.921fb4p+0 i", LIT (0x0p+0), LIT (0x1.921fb4p+0), { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x1.921fb54442d1846ap+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d1846ap+0), { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x1.921fb54442d18p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d18p+0), { LIT (0x0p+0), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x3.a052cf8639b69c1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x1.921fb54442d19p+0 i", LIT (0x0p+0), LIT (0x1.921fb54442d19p+0), { LIT (0x0p+0), LIT (-0x1.617a15494767a04ap+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x1.921fb6p+0 i", LIT (0x0p+0), LIT (0x1.921fb6p+0), { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d8p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x2p-16384 i", LIT (0x0p+0), LIT (0x2p-16384), { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x0p+0), LIT (0x2.0000000000000004p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4p-1024 i", LIT (0x0p+0), LIT (0x4p-1024), { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000008p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000008p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4p-128 i", LIT (0x0p+0), LIT (0x4p-128), { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000008p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4p-16384 i", LIT (0x0p+0), LIT (0x4p-16384), { LIT (0x0p+0), LIT (0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x4.0000000000000008p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4p-16448 i", LIT (0x0p+0), LIT (0x4p-16448), { LIT (0x0p+0), LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.000000000000001p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p-16448 i", LIT (0x0p+0), LIT (0x8p-16448), { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xcp-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p-972 i", LIT (0x0p+0), LIT (0x8p-972), { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x8.000000000000001p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0xc.90fdaa22168c234p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c234p-4), { LIT (0x0p+0), LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0xc.90fdaa22168c235p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c235p-4), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0xc.90fdaa22168c8p-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168c8p-4), { LIT (0x0p+0), LIT (0x1.0000000000000b96p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b96p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b96p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.0000000000000b98p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0xc.90fdaa22168cp-4 i", LIT (0x0p+0), LIT (0xc.90fdaa22168cp-4), { LIT (0x0p+0), LIT (0xf.ffffffffffffb96p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb96p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb96p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffb97p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0xc.90fdap-4 i", LIT (0x0p+0), LIT (0xc.90fdap-4), { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f3p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f3p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f3p-4), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffebbbd2f48f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0xc.90fdbp-4 i", LIT (0x0p+0), LIT (0xc.90fdbp-4), { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06cp+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06ep+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06cp+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1.000000bbbd2ec06ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.63ap+12 + 0x1p+0 i", LIT (0x1.63ap+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x7.f673eccp-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x7.f673eccp-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x7.f673eccp-16420), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0x7.f673edp-16420), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.63p+12 + 0x1p+0 i", LIT (0x1.63p+12), LIT (0x1p+0), { LIT (0x1p+0), LIT (0xe.6442e59c9ba29cp-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xe.6442e59c9ba2ap-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xe.6442e59c9ba29cp-16392), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0xe.6442e59c9ba2ap-16392), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.63p+8 + 0x1p+0 i", LIT (0x1.63p+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fcp-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fcp-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.76a2c6f034b4a7fcp-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x1.76a2c6f034b4a7fep-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.6dp+8 + 0x1p+0 i", LIT (0x1.6dp+8), LIT (0x1p+0), { LIT (0x1p+0), LIT (0xc.f47f20686b62b7p-1056), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xc.f47f20686b62b7p-1056), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xc.f47f20686b62b7p-1056), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0xc.f47f20686b62b71p-1056), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0x8p+1020 i", LIT (0x1p+0), LIT (0x8p+1020), { LIT (0xe.0ec57df9e9489b8p-4), LIT (-0x3.9b7edf84053dda48p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b8p-4), LIT (-0x3.9b7edf84053dda48p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b8p-4), LIT (-0x3.9b7edf84053dda44p-4), ERRNO_UNCHANGED }, { LIT (0xe.0ec57df9e9489b9p-4), LIT (-0x3.9b7edf84053dda44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0x8p+124 i", LIT (0x1p+0), LIT (0x8p+124), { LIT (0xe.8fe80b8795b6ed2p-4), LIT (0x3.ea075fdf18c8a748p-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed3p-4), LIT (0x3.ea075fdf18c8a74cp-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed2p-4), LIT (0x3.ea075fdf18c8a748p-4), ERRNO_UNCHANGED }, { LIT (0xe.8fe80b8795b6ed3p-4), LIT (0x3.ea075fdf18c8a74cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0x8p+16380 i", LIT (0x1p+0), LIT (0x8p+16380), { LIT (0xd.039cb06618c08bfp-4), LIT (0x2.92e1ce9b08cb660cp-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08cp-4), LIT (0x2.92e1ce9b08cb660cp-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08bfp-4), LIT (0x2.92e1ce9b08cb660cp-4), ERRNO_UNCHANGED }, { LIT (0xd.039cb06618c08cp-4), LIT (0x2.92e1ce9b08cb661p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x1p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xc.2f859c7fb353152p-4), LIT (-0x8.891dda2c0657715p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb353152p-4), LIT (-0x8.891dda2c0657714p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb353152p-4), LIT (-0x8.891dda2c0657714p-12), ERRNO_UNCHANGED }, { LIT (0xc.2f859c7fb353153p-4), LIT (-0x8.891dda2c0657714p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0xf.fffffp+124 i", LIT (0x1p+0), LIT (0xf.fffffp+124), { LIT (0xd.c26353c068203bfp-4), LIT (-0x3.60b2616c1339906cp-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bfp-4), LIT (-0x3.60b2616c13399068p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203bfp-4), LIT (-0x3.60b2616c13399068p-4), ERRNO_UNCHANGED }, { LIT (0xd.c26353c068203cp-4), LIT (-0x3.60b2616c13399068p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.dp+4 + 0x1p+0 i", LIT (0x2.dp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x8.1cfa783d16f462ap-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f462ap-132), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.1cfa783d16f462ap-132), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x8.1cfa783d16f462bp-132), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.fp+4 + 0x1p+0 i", LIT (0x2.fp+4), LIT (0x1p+0), { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241554p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241554p-136), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.60a8b2f7f5241554p-136), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x2.60a8b2f7f5241558p-136), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16384 + +0 i", LIT (0x2p-16384), LIT (0x0p+0), { LIT (0x1.fffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1.fffffffffffffffcp-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), LIT (0x0p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1024 + +0 i", LIT (0x4p-1024), LIT (0x0p+0), { LIT (0x3.fffffffffffffffcp-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1024), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1024), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x3.fffffffffffffffcp-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1076), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-1076), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x1.921fb4p+0 i", LIT (0x4p-1076), LIT (0x1.921fb4p+0), { LIT (0x2.7e3fd9c32f99fb4p-1028), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb4p-1028), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb4p-1028), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x2.7e3fd9c32f99fb44p-1028), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x1.921fb54442d1846ap+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d1846ap+0), { LIT (0x1.2af1800dc70a09fep-944), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fep-944), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a09fep-944), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED }, { LIT (0x1.2af1800dc70a0ap-944), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x1.921fb54442d18p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d18p+0), { LIT (0x3.49961ed5af28cf18p-968), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18p-968), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf18p-968), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x3.49961ed5af28cf1cp-968), LIT (0x3.a052cf8639b69c1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x1.921fb54442d19p+0 i", LIT (0x4p-1076), LIT (0x1.921fb54442d19p+0), { LIT (0x7.a047a3b18a23c5fp-972), LIT (-0x1.617a15494767a04ap+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5f8p-972), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5fp-972), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0x7.a047a3b18a23c5f8p-972), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x1.921fb6p+0 i", LIT (0x4p-1076), LIT (0x1.921fb6p+0), { LIT (0x7.7004796b7ae1a38p-1028), LIT (-0x1.5d14946dc98975d8p+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a38p-1028), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a38p-1028), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0x7.7004796b7ae1a388p-1028), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-128 + +0 i", LIT (0x4p-128), LIT (0x0p+0), { LIT (0x3.fffffffffffffffcp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-128), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-128), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384 + +0 i", LIT (0x4p-16384), LIT (0x0p+0), { LIT (0x3.fffffffffffffffcp-16384), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-16384), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-16384), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-16384), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + +0 i", LIT (0x4p-16448), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x7.fffffffffffffff8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-152), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-152), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x1.921fb4p+0 i", LIT (0x8p-152), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fb3865f33f68p-104), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f68p-104), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f68p-104), LIT (0xc.a1bd99b5b58623cp+20), ERRNO_UNCHANGED }, { LIT (0x4.fc7fb3865f33f688p-104), LIT (0xc.a1bd99b5b58623dp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x1.921fb54442d1846ap+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d1846ap+0), { LIT (0x2.55e3001b8e1413fcp-20), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcp-20), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcp-20), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1414p-20), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x1.921fb54442d18p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d18p+0), { LIT (0x6.932c3dab5e519e3p-44), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3p-44), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3p-44), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e38p-44), LIT (0x3.a052cf8639b69c1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x1.921fb54442d19p+0 i", LIT (0x8p-152), LIT (0x1.921fb54442d19p+0), { LIT (0xf.408f476314478bep-48), LIT (-0x1.617a15494767a04ap+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bfp-48), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bep-48), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bfp-48), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x1.921fb6p+0 i", LIT (0x8p-152), LIT (0x1.921fb6p+0), { LIT (0xe.e008f2d6f5c347p-104), LIT (-0x1.5d14946dc98975d8p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347p-104), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c347p-104), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED }, { LIT (0xe.e008f2d6f5c3471p-104), LIT (-0x1.5d14946dc98975d6p+24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + +0 i", LIT (0x8p-16448), LIT (0x0p+0), { LIT (0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), LIT (0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x1.921fb4p+0 i", LIT (0x8p-16448), LIT (0x1.921fb4p+0), { LIT (0x4.fc7fb3865f3p-16400), LIT (0xc.a1bd99b5b58623cp+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f34p-16400), LIT (0xc.a1bd99b5b58623dp+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f3p-16400), LIT (0xc.a1bd99b5b58623cp+20), UNDERFLOW_EXCEPTION }, { LIT (0x4.fc7fb3865f34p-16400), LIT (0xc.a1bd99b5b58623dp+20), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x1.921fb54442d1846ap+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d1846ap+0), { LIT (0x2.55e3001b8e1413fcp-16316), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcp-16316), LIT (-0x2.29478136aaf68d7cp+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1413fcp-16316), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED }, { LIT (0x2.55e3001b8e1414p-16316), LIT (-0x2.29478136aaf68d78p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x1.921fb54442d18p+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d18p+0), { LIT (0x6.932c3dab5e519e3p-16340), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3p-16340), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e3p-16340), LIT (0x3.a052cf8639b69c18p+52), ERRNO_UNCHANGED }, { LIT (0x6.932c3dab5e519e38p-16340), LIT (0x3.a052cf8639b69c1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x1.921fb54442d19p+0 i", LIT (0x8p-16448), LIT (0x1.921fb54442d19p+0), { LIT (0xf.408f476314478bep-16344), LIT (-0x1.617a15494767a04ap+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bfp-16344), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bep-16344), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED }, { LIT (0xf.408f476314478bfp-16344), LIT (-0x1.617a15494767a048p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x1.921fb6p+0 i", LIT (0x8p-16448), LIT (0x1.921fb6p+0), { LIT (0xe.e008f2d6f5cp-16400), LIT (-0x1.5d14946dc98975d8p+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5c4p-16400), LIT (-0x1.5d14946dc98975d6p+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5cp-16400), LIT (-0x1.5d14946dc98975d6p+24), UNDERFLOW_EXCEPTION }, { LIT (0xe.e008f2d6f5c4p-16400), LIT (-0x1.5d14946dc98975d6p+24), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-972 + +0 i", LIT (0x8p-972), LIT (0x0p+0), { LIT (0x7.fffffffffffffff8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-972), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-972), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.35p+12 - 0xc.35p+12 i", LIT (0xc.35p+12), LIT (-0xc.35p+12), { LIT (0x1p+0), LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.35p+12 + 0xc.35p+12 i", LIT (0xc.35p+12), LIT (0xc.35p+12), { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.5f6335b1af42bd62p+0), LIT (0x6.2c386076356eap-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62p+0), LIT (0x6.2c386076356eap-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd62p+0), LIT (0x6.2c386076356eap-4), ERRNO_UNCHANGED }, { LIT (0x1.5f6335b1af42bd64p+0), LIT (0x6.2c386076356ea008p-4), ERRNO_UNCHANGED } },
#endif
  };

static void
ctanh_test (void)
{
  ALL_RM_TEST (ctanh, 0, ctanh_test_data, RUN_TEST_LOOP_c_c, END_COMPLEX);
}

static void
do_test (void)
{
  ctanh_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

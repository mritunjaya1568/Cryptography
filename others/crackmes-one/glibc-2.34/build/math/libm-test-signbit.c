/* Test signbit.
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

static const struct test_f_i_data signbit_test_data[] =
  {
    { "0", 0, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-0", minus_zero, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "inf", plus_infty, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-inf", minus_infty, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "qNaN", qnan_value, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { 0, TEST_SNAN|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, TEST_SNAN|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, TEST_SNAN|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, TEST_SNAN|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-sNaN", -snan_value, { 1, TEST_SNAN|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, TEST_SNAN|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, TEST_SNAN|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, TEST_SNAN|NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

    /* signbit (x) != 0 for x < 0.  */
    { "-1", -1, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-min_value", -min_value, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-min_subnorm_value", -min_subnorm_value, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-max_value", -max_value, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 1, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    /* signbit (x) == 0 for x >= 0.  */
    { "1", 1, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "min_value", min_value, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "min_subnorm_value", min_subnorm_value, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "max_value", max_value, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { 0, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
  };

static void
signbit_test (void)
{
  ALL_RM_TEST (signbit, 1, signbit_test_data, RUN_TEST_LOOP_f_b_tg, END);
}

static void
do_test (void)
{
  signbit_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

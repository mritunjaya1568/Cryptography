/* Test csqrt.
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

static const struct test_c_c_data csqrt_test_data[] =
  {
    { "-inf + 0 i", minus_infty, 0, { LIT (0.0), plus_infty, 0 }, { LIT (0.0), plus_infty, 0 }, { LIT (0.0), plus_infty, 0 }, { LIT (0.0), plus_infty, 0 } },
    { "-inf + 6 i", minus_infty, 6, { LIT (0.0), plus_infty, 0 }, { LIT (0.0), plus_infty, 0 }, { LIT (0.0), plus_infty, 0 }, { LIT (0.0), plus_infty, 0 } },
    { "-inf - 0 i", minus_infty, minus_zero, { LIT (0.0), minus_infty, 0 }, { LIT (0.0), minus_infty, 0 }, { LIT (0.0), minus_infty, 0 }, { LIT (0.0), minus_infty, 0 } },
    { "-inf - 6 i", minus_infty, -6, { LIT (0.0), minus_infty, 0 }, { LIT (0.0), minus_infty, 0 }, { LIT (0.0), minus_infty, 0 }, { LIT (0.0), minus_infty, 0 } },

    { "inf + 0 i", plus_infty, 0, { plus_infty, LIT (0.0), 0 }, { plus_infty, LIT (0.0), 0 }, { plus_infty, LIT (0.0), 0 }, { plus_infty, LIT (0.0), 0 } },
    { "inf + 6 i", plus_infty, 6, { plus_infty, LIT (0.0), 0 }, { plus_infty, LIT (0.0), 0 }, { plus_infty, LIT (0.0), 0 }, { plus_infty, LIT (0.0), 0 } },
    { "inf - 0 i", plus_infty, minus_zero, { plus_infty, minus_zero, 0 }, { plus_infty, minus_zero, 0 }, { plus_infty, minus_zero, 0 }, { plus_infty, minus_zero, 0 } },
    { "inf - 6 i", plus_infty, -6, { plus_infty, minus_zero, 0 }, { plus_infty, minus_zero, 0 }, { plus_infty, minus_zero, 0 }, { plus_infty, minus_zero, 0 } },

    { "0 + inf i", 0, plus_infty, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 } },
    { "4 + inf i", 4, plus_infty, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 } },
    { "inf + inf i", plus_infty, plus_infty, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 } },
    { "-0 + inf i", minus_zero, plus_infty, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 } },
    { "-4 + inf i", -4, plus_infty, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 } },
    { "-inf + inf i", minus_infty, plus_infty, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 }, { plus_infty, plus_infty, 0 } },
    { "0 - inf i", 0, minus_infty, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 } },
    { "4 - inf i", 4, minus_infty, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 } },
    { "inf - inf i", plus_infty, minus_infty, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 } },
    { "-0 - inf i", minus_zero, minus_infty, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 } },
    { "-4 - inf i", -4, minus_infty, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 } },
    { "-inf - inf i", minus_infty, minus_infty, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 }, { plus_infty, minus_infty, 0 } },

    { "-inf + qNaN i", minus_infty, qnan_value, { qnan_value, plus_infty, IGNORE_ZERO_INF_SIGN }, { qnan_value, plus_infty, IGNORE_ZERO_INF_SIGN }, { qnan_value, plus_infty, IGNORE_ZERO_INF_SIGN }, { qnan_value, plus_infty, IGNORE_ZERO_INF_SIGN } },

    { "inf + qNaN i", plus_infty, qnan_value, { plus_infty, qnan_value, 0 }, { plus_infty, qnan_value, 0 }, { plus_infty, qnan_value, 0 }, { plus_infty, qnan_value, 0 } },

    { "0 + qNaN i", 0, qnan_value, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },
    { "1 + qNaN i", 1, qnan_value, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },
    { "-0 + qNaN i", minus_zero, qnan_value, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },
    { "-1 + qNaN i", -1, qnan_value, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },

    { "qNaN + 0 i", qnan_value, 0, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },
    { "qNaN + 8 i", qnan_value, 8, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },
    { "qNaN - 0 i", qnan_value, minus_zero, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },
    { "qNaN - 8 i", qnan_value, -8, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK }, { qnan_value, qnan_value, INVALID_EXCEPTION_OK } },

    { "qNaN + qNaN i", qnan_value, qnan_value, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 } },

#if (TEST_COND_binary128)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 - 0x4.0000000000000000000000000004p-16384 i", LIT (-0x0p+0), LIT (-0x4.0000000000000000000000000004p-16384), { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (-0x1.6a09e667f3bcc908b2fb1366ea97p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (-0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (-0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (-0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 - 0x4.0000000000000008p-16384 i", LIT (-0x0p+0), LIT (-0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (-0x1.6a09e667f3bcc90a1d04f9cede53p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (-0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (-0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (-0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 - 0x4.0000000000004p-1024 i", LIT (-0x0p+0), LIT (-0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcd459022e5304d0bp-512), LIT (-0x1.6a09e667f3bcd459022e5304d0b1p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d0b1p-512), LIT (-0x1.6a09e667f3bcd459022e5304d0b1p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d0bp-512), LIT (-0x1.6a09e667f3bcd459022e5304d0bp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d0b1p-512), LIT (-0x1.6a09e667f3bcd459022e5304d0bp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 - 0x4p-1076 i", LIT (-0x0p+0), LIT (-0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 - 0x4p-16384 i", LIT (-0x0p+0), LIT (-0x4p-16384), { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), LIT (-0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), LIT (-0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), LIT (-0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (-0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 - 0x8p-152 i", LIT (-0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0 + 0x8p-152 i", LIT (-0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.65c7ac7c97a25p-176 - 0x8p-152 i", LIT (-0x1.65c7ac7c97a25p-176), LIT (-0x8p-152), { LIT (0x1.ffffffd3470a72611238fcca077bp-76), LIT (-0x2.0000002cb8f59186facca56fa4bp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a72611238fcca077bp-76), LIT (-0x2.0000002cb8f59186facca56fa4aep-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a72611238fcca077bp-76), LIT (-0x2.0000002cb8f59186facca56fa4aep-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a72611238fcca077cp-76), LIT (-0x2.0000002cb8f59186facca56fa4aep-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.9edb24c83e22cp-172 - 0x8p-152 i", LIT (-0x1.9edb24c83e22cp-172), LIT (-0x8p-152), { LIT (0x1.fffffcc249b90fcd4551133a1e3cp-76), LIT (-0x2.0000033db64c30c5c7ce266be91ep-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcd4551133a1e3dp-76), LIT (-0x2.0000033db64c30c5c7ce266be91cp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcd4551133a1e3cp-76), LIT (-0x2.0000033db64c30c5c7ce266be91cp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcd4551133a1e3dp-76), LIT (-0x2.0000033db64c30c5c7ce266be91cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 - 0x2p-16384 i", LIT (-0x1p+0), LIT (-0x2p-16384), { LIT (0xf.ffffffffffffffffffffffffffcp-16388), LIT (-0x1.0000000000000000000000000001p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffffffffffffffffcp-16388), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 - 0x4p-1024 i", LIT (-0x1p+0), LIT (-0x4p-1024), { LIT (0x1.ffffffffffffffffffffffffffffp-1024), LIT (-0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-1024), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 - 0x4p-128 i", LIT (-0x1p+0), LIT (-0x4p-128), { LIT (0x1.ffffffffffffffffffffffffffffp-128), LIT (-0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 - 0x4p-16384 i", LIT (-0x1p+0), LIT (-0x4p-16384), { LIT (0x1.fffffffffffffffffffffffffffcp-16384), LIT (-0x1.0000000000000000000000000001p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffffffffffffffffcp-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 - 0x8p-972 i", LIT (-0x1p+0), LIT (-0x8p-972), { LIT (0x3.fffffffffffffffffffffffffffep-972), LIT (-0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-972), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 + +0 i", LIT (-0x1p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 + 0x2p-16384 i", LIT (-0x1p+0), LIT (0x2p-16384), { LIT (0xf.ffffffffffffffffffffffffffcp-16388), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffffffffffffffffcp-16388), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (0x1.0000000000000000000000000001p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 + 0x4p-1024 i", LIT (-0x1p+0), LIT (0x4p-1024), { LIT (0x1.ffffffffffffffffffffffffffffp-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 + 0x4p-128 i", LIT (-0x1p+0), LIT (0x4p-128), { LIT (0x1.ffffffffffffffffffffffffffffp-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 + 0x4p-16384 i", LIT (-0x1p+0), LIT (0x4p-16384), { LIT (0x1.fffffffffffffffffffffffffffcp-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffffffffffffffffcp-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (0x1.0000000000000000000000000001p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0 + 0x8p-972 i", LIT (-0x1p+0), LIT (0x8p-972), { LIT (0x3.fffffffffffffffffffffffffffep-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.927275f6febb6p-184 + 0x8p-152 i", LIT (-0x2.927275f6febb6p-184), LIT (0x8p-152), { LIT (0x1.ffffffffadb1b14126c62499980cp-76), LIT (0x2.00000000524e4ebee674fc9995eap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b14126c62499980cp-76), LIT (0x2.00000000524e4ebee674fc9995ecp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b14126c62499980cp-76), LIT (0x2.00000000524e4ebee674fc9995eap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b14126c62499980dp-76), LIT (0x2.00000000524e4ebee674fc9995ecp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (0xe.55ec7a5ee26873fa30d7c5f6e6a8p-4), LIT (-0x1.ac950b37094a5a94aab4a9642dc9p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e6bp-4), LIT (-0x1.ac950b37094a5a94aab4a9642dc9p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e6a8p-4), LIT (-0x1.ac950b37094a5a94aab4a9642dc8p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e6bp-4), LIT (-0x1.ac950b37094a5a94aab4a9642dc8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p+0 + 0x3p+0 i", LIT (-0x2p+0), LIT (0x3p+0), { LIT (0xe.55ec7a5ee26873fa30d7c5f6e6a8p-4), LIT (0x1.ac950b37094a5a94aab4a9642dc8p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e6bp-4), LIT (0x1.ac950b37094a5a94aab4a9642dc9p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e6a8p-4), LIT (0x1.ac950b37094a5a94aab4a9642dc8p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e6bp-4), LIT (0x1.ac950b37094a5a94aab4a9642dc9p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000000000000000004p-16384 - 0 i", LIT (-0x4.0000000000000000000000000004p-16384), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000000000000000000002p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000000000000000004p-16384 - 0x4.0000000000000000000000000004p-16384 i", LIT (-0x4.0000000000000000000000000004p-16384), LIT (-0x4.0000000000000000000000000004p-16384), { LIT (0xe.90189c7b6414133be637803acbfp-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d8p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbf8p-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d8p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbfp-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbf8p-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000000000000000004p-16384 - 0x4.0000000000000008p-16384 i", LIT (-0x4.0000000000000000000000000004p-16384), LIT (-0x4.0000000000000008p-16384), { LIT (0xe.90189c7b64141354c279997827e8p-8196), LIT (-0x2.3286b95ff53f16afaed19f01d956p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b64141354c279997827fp-8196), LIT (-0x2.3286b95ff53f16afaed19f01d956p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b64141354c279997827e8p-8196), LIT (-0x2.3286b95ff53f16afaed19f01d954p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b64141354c279997827fp-8196), LIT (-0x2.3286b95ff53f16afaed19f01d954p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000000000000000004p-16384 - 0x4p-1076 i", LIT (-0x4.0000000000000000000000000004p-16384), LIT (-0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000000000000000004p-16384 - 0x4p-16384 i", LIT (-0x4.0000000000000000000000000004p-16384), LIT (-0x4p-16384), { LIT (0xe.90189c7b6414133be637803acbe8p-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d8p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbe8p-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbe8p-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbfp-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000000000000000004p-16384 - 0x8p-152 i", LIT (-0x4.0000000000000000000000000004p-16384), LIT (-0x8p-152), { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2.0000000000000000000000000002p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000008p-16384 - 0 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000000002p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000002p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000001fffffffffffep-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000001fffffffffffep-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000008p-16384 - 0x4.0000000000000000000000000004p-16384 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4.0000000000000000000000000004p-16384), { LIT (0xe.90189c7b641413319a0e0378d408p-8196), LIT (-0x2.3286b95ff53f16b097d328c98f98p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641413319a0e0378d41p-8196), LIT (-0x2.3286b95ff53f16b097d328c98f96p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641413319a0e0378d408p-8196), LIT (-0x2.3286b95ff53f16b097d328c98f96p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641413319a0e0378d41p-8196), LIT (-0x2.3286b95ff53f16b097d328c98f96p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000008p-16384 - 0x4.0000000000000008p-16384 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4.0000000000000008p-16384), { LIT (0xe.90189c7b6414134a76501cb63p-8196), LIT (-0x2.3286b95ff53f16b13c95c095af16p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134a76501cb63008p-8196), LIT (-0x2.3286b95ff53f16b13c95c095af14p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134a76501cb63p-8196), LIT (-0x2.3286b95ff53f16b13c95c095af14p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134a76501cb63008p-8196), LIT (-0x2.3286b95ff53f16b13c95c095af14p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000008p-16384 - 0x4p-1076 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000008p-16384 - 0x4p-16384 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4p-16384), { LIT (0xe.90189c7b641413319a0e0378d4p-8196), LIT (-0x2.3286b95ff53f16b097d328c98f98p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641413319a0e0378d4p-8196), LIT (-0x2.3286b95ff53f16b097d328c98f96p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641413319a0e0378d4p-8196), LIT (-0x2.3286b95ff53f16b097d328c98f96p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641413319a0e0378d408p-8196), LIT (-0x2.3286b95ff53f16b097d328c98f96p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000000008p-16384 - 0x8p-152 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x8p-152), { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2.0000000000000000000000000002p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000004p-1024 - 0 i", LIT (-0x4.0000000000004p-1024), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000000fffffffffffffc2p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000fffffffffffffcp-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000fffffffffffffcp-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000fffffffffffffcp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000004p-1024 - 0x4.0000000000004p-1024 i", LIT (-0x4.0000000000004p-1024), LIT (-0x4.0000000000004p-1024), { LIT (0xe.90189c7b641487bcab1b5b5b6abp-516), LIT (-0x2.3286b95ff53f28433fda06dfb246p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487bcab1b5b5b6ab8p-516), LIT (-0x2.3286b95ff53f28433fda06dfb246p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487bcab1b5b5b6abp-516), LIT (-0x2.3286b95ff53f28433fda06dfb244p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487bcab1b5b5b6ab8p-516), LIT (-0x2.3286b95ff53f28433fda06dfb244p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.0000000000004p-1024 - 0x8p-152 i", LIT (-0x4.0000000000004p-1024), LIT (-0x8p-152), { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2.0000000000000000000000000002p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.000008p-128 - 0x4.000008p-128 i", LIT (-0x4.000008p-128), LIT (-0x4.000008p-128), { LIT (0xe.9018ab0b7ca94693b355165c1d7p-68), LIT (-0x2.3286bb927bf75d60ed8efefb8deep-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca94693b355165c1d78p-68), LIT (-0x2.3286bb927bf75d60ed8efefb8decp-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca94693b355165c1d7p-68), LIT (-0x2.3286bb927bf75d60ed8efefb8decp-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca94693b355165c1d78p-68), LIT (-0x2.3286bb927bf75d60ed8efefb8decp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.15ca1p+0 - 0x8p-152 i", LIT (-0x4.15ca1p+0), LIT (-0x8p-152), { LIT (0x1.faa35a1b5eb2277c5b81a0bc8121p-152), LIT (-0x2.056b2cd84231ea6b3b0807c89a7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277c5b81a0bc8121p-152), LIT (-0x2.056b2cd84231ea6b3b0807c89a7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277c5b81a0bc8121p-152), LIT (-0x2.056b2cd84231ea6b3b0807c89a78p+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277c5b81a0bc8122p-152), LIT (-0x2.056b2cd84231ea6b3b0807c89a78p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.827738p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.827738p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee6cd64cbb62e158cabbd8c28p-4), LIT (-0x1.02a876fc905207cb814e2eb3845fp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb62e158cabbd8c28p-4), LIT (-0x1.02a876fc905207cb814e2eb3845ep+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb62e158cabbd8c28p-4), LIT (-0x1.02a876fc905207cb814e2eb3845ep+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb62e158cabbd8c3p-4), LIT (-0x1.02a876fc905207cb814e2eb3845ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.82773b736291p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82773b736291p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee5f5a36814cd75037a9130dp-4), LIT (-0x1.02a8770c69a38eb8ab6efd78eb6fp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814cd75037a9130dp-4), LIT (-0x1.02a8770c69a38eb8ab6efd78eb6fp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814cd75037a9130dp-4), LIT (-0x1.02a8770c69a38eb8ab6efd78eb6ep+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814cd75037a9130d8p-4), LIT (-0x1.02a8770c69a38eb8ab6efd78eb6ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.82774p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82774p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee4d93232a2420fb5a5de7ee8p-4), LIT (-0x1.02a877214e9fe4ccddb4bf40a2f4p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a2420fb5a5de7efp-4), LIT (-0x1.02a877214e9fe4ccddb4bf40a2f4p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a2420fb5a5de7ee8p-4), LIT (-0x1.02a877214e9fe4ccddb4bf40a2f3p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a2420fb5a5de7efp-4), LIT (-0x1.02a877214e9fe4ccddb4bf40a2f3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.d0144005d7af4p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144005d7af4p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2657d0a0370ad2744a13bdp+0), LIT (-0x2.0201143f4f66d95db989bd24497ep+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a0370ad2744a13bdp+0), LIT (-0x2.0201143f4f66d95db989bd24497cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a0370ad2744a13bdp+0), LIT (-0x2.0201143f4f66d95db989bd24497cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a0370ad2744a13bd1p+0), LIT (-0x2.0201143f4f66d95db989bd24497cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.d01448p-4 - 0x7.c19148p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2559bb4b70c158cd5697a1cp+0), LIT (-0x2.0201144fd174462bdbd12437e774p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70c158cd5697a1cp+0), LIT (-0x2.0201144fd174462bdbd12437e772p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70c158cd5697a1cp+0), LIT (-0x2.0201144fd174462bdbd12437e772p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70c158cd5697a1dp+0), LIT (-0x2.0201144fd174462bdbd12437e772p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.d01448p-4 - 0x7.c1915p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c1915p+0), { LIT (0x1.ee74d35e7dfe1b3cee8924cd502ep+0), LIT (-0x2.0201154ea0e0412a465d9337568cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cee8924cd502ep+0), LIT (-0x2.0201154ea0e0412a465d9337568ap+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cee8924cd502ep+0), LIT (-0x2.0201154ea0e0412a465d9337568ap+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cee8924cd502fp+0), LIT (-0x2.0201154ea0e0412a465d9337568ap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4.d0144p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d26588ab7af21eeb8d76b494p+0), LIT (-0x2.0201143f434fabbbd9085f85cb74p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af21eeb8d76b495p+0), LIT (-0x2.0201143f434fabbbd9085f85cb74p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af21eeb8d76b494p+0), LIT (-0x2.0201143f434fabbbd9085f85cb72p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af21eeb8d76b495p+0), LIT (-0x2.0201143f434fabbbd9085f85cb72p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076 - 0 i", LIT (-0x4p-1076), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076 - 0x4.0000000000000000000000000004p-16384 i", LIT (-0x4p-1076), LIT (-0x4.0000000000000000000000000004p-16384), { LIT (0x4p-15848), LIT (-0x8.0000000000000000000000000008p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000000004p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000000004p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076 - 0x4.0000000000000008p-16384 i", LIT (-0x4p-1076), LIT (-0x4.0000000000000008p-16384), { LIT (0x4.0000000000000007fffffffffffcp-15848), LIT (-0x8.0000000000000000000000000008p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000007fffffffffffcp-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076 - 0x4p-1076 i", LIT (-0x4p-1076), LIT (-0x4p-1076), { LIT (0x3.a406271ed90504cef98de00eb2fcp-540), LIT (-0x8.ca1ae57fd4fc5abc283c1cd6e758p-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504cef98de00eb2fcp-540), LIT (-0x8.ca1ae57fd4fc5abc283c1cd6e758p-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504cef98de00eb2fcp-540), LIT (-0x8.ca1ae57fd4fc5abc283c1cd6e75p-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504cef98de00eb2fep-540), LIT (-0x8.ca1ae57fd4fc5abc283c1cd6e75p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076 - 0x4p-16384 i", LIT (-0x4p-1076), LIT (-0x4p-16384), { LIT (0x3.fffffffffffffffffffffffffffep-15848), LIT (-0x8.0000000000000000000000000008p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076 - 0x8p-152 i", LIT (-0x4p-1076), LIT (-0x8p-152), { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2.0000000000000000000000000002p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384 - 0 i", LIT (-0x4p-16384), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384 - 0x4.0000000000000000000000000004p-16384 i", LIT (-0x4p-16384), LIT (-0x4.0000000000000000000000000004p-16384), { LIT (0xe.90189c7b6414133be637803acbf8p-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d8p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803accp-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbf8p-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803accp-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384 - 0x4.0000000000000008p-16384 i", LIT (-0x4p-16384), LIT (-0x4.0000000000000008p-16384), { LIT (0xe.90189c7b64141354c279997827fp-8196), LIT (-0x2.3286b95ff53f16afaed19f01d956p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b64141354c279997827fp-8196), LIT (-0x2.3286b95ff53f16afaed19f01d954p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b64141354c279997827fp-8196), LIT (-0x2.3286b95ff53f16afaed19f01d954p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b64141354c279997827f8p-8196), LIT (-0x2.3286b95ff53f16afaed19f01d954p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384 - 0x4p-1076 i", LIT (-0x4p-16384), LIT (-0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (-0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384 - 0x4p-16384 i", LIT (-0x4p-16384), LIT (-0x4p-16384), { LIT (0xe.90189c7b6414133be637803acbfp-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbfp-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d6p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbfp-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d4p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133be637803acbf8p-8196), LIT (-0x2.3286b95ff53f16af0a0f0735b9d4p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384 - 0x8p-152 i", LIT (-0x4p-16384), LIT (-0x8p-152), { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2.0000000000000000000000000002p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.31291c9fdae04p-160 - 0x8p-152 i", LIT (-0x7.31291c9fdae04p-160), LIT (-0x8p-152), { LIT (0x1.ff1a0ead4f6b13d04d5d6ea54babp-76), LIT (-0x2.00e658c5f71cca99e9ffb790e274p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13d04d5d6ea54babp-76), LIT (-0x2.00e658c5f71cca99e9ffb790e272p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13d04d5d6ea54babp-76), LIT (-0x2.00e658c5f71cca99e9ffb790e272p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13d04d5d6ea54bacp-76), LIT (-0x2.00e658c5f71cca99e9ffb790e272p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.915fa8p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fa8p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c32571e2b8ea0a1d4283bbdba8ap-4), LIT (-0x1.3392ad649c5855af7b9a4bcfd00cp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a1d4283bbdba8a8p-4), LIT (-0x1.3392ad649c5855af7b9a4bcfd00bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a1d4283bbdba8ap-4), LIT (-0x1.3392ad649c5855af7b9a4bcfd00bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a1d4283bbdba8a8p-4), LIT (-0x1.3392ad649c5855af7b9a4bcfd00bp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.915fafbe9f588p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fafbe9f588p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c325704e2c61d1a1062699dc5a58p-4), LIT (-0x1.3392ad837265580fa41acfac146cp+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1a1062699dc5a58p-4), LIT (-0x1.3392ad837265580fa41acfac146bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1a1062699dc5a58p-4), LIT (-0x1.3392ad837265580fa41acfac146bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1a1062699dc5a6p-4), LIT (-0x1.3392ad837265580fa41acfac146bp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.915fbp-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fbp-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c3257040d54fb3c85fce59f48f9p-4), LIT (-0x1.3392ad8476b45afedefba40152dfp+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3c85fce59f48f98p-4), LIT (-0x1.3392ad8476b45afedefba40152dep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3c85fce59f48f9p-4), LIT (-0x1.3392ad8476b45afedefba40152dep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3c85fce59f48f98p-4), LIT (-0x1.3392ad8476b45afedefba40152dep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.ec8932bf5603p-172 + 0x8p-152 i", LIT (-0x8.ec8932bf5603p-172), LIT (0x8p-152), { LIT (0x1.ffffee26edea24772bbb75f81e72p-76), LIT (0x2.000011d912b521c9aa5f4f56724ap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea24772bbb75f81e73p-76), LIT (0x2.000011d912b521c9aa5f4f56724cp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea24772bbb75f81e72p-76), LIT (0x2.000011d912b521c9aa5f4f56724ap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea24772bbb75f81e73p-76), LIT (0x2.000011d912b521c9aa5f4f56724cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0 i", LIT (-0x8p-152), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.d413cccfe779921165f626cdd52cp-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0x1.818bccp+0 i", LIT (-0x8p-152), LIT (-0x1.818bccp+0), { LIT (0xd.e25fb98f8390a020c51dc0c93e1p-4), LIT (-0xd.e25fb98f8390a020c51dc0c93e18p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a020c51dc0c93e18p-4), LIT (-0xd.e25fb98f8390a020c51dc0c93e18p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a020c51dc0c93e1p-4), LIT (-0xd.e25fb98f8390a020c51dc0c93e1p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a020c51dc0c93e18p-4), LIT (-0xd.e25fb98f8390a020c51dc0c93e1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0x2.c832ff5b163af0dcp-2444 i", LIT (-0x8p-152), LIT (-0x2.c832ff5b163af0dcp-2444), { LIT (0x7.de674fc19752a2cf61b69684f858p-2372), LIT (-0x2.d413cccfe779921165f626cdd52cp-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2cf61b69684f858p-2372), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2cf61b69684f858p-2372), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2cf61b69684f85cp-2372), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0x4.0000000000000000000000000004p-16384 i", LIT (-0x8p-152), LIT (-0x4.0000000000000000000000000004p-16384), { LIT (0xb.504f333f9de6484597d89b3754bp-16312), LIT (-0x2.d413cccfe779921165f626cdd52cp-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754b8p-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754b8p-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0x4.0000000000000008p-16384 i", LIT (-0x8p-152), LIT (-0x4.0000000000000008p-16384), { LIT (0xb.504f333f9de6485c387701b69078p-16312), LIT (-0x2.d413cccfe779921165f626cdd52cp-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485c387701b69078p-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485c387701b69078p-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485c387701b6908p-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0x4.0000000000004p-1024 i", LIT (-0x8p-152), LIT (-0x4.0000000000004p-1024), { LIT (0xb.504f333f9de6fd4a8b0c9515b93p-952), LIT (-0x2.d413cccfe779921165f626cdd52cp-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd4a8b0c9515b93p-952), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd4a8b0c9515b93p-952), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd4a8b0c9515b938p-952), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0x4p-1076 i", LIT (-0x8p-152), LIT (-0x4p-1076), { LIT (0xb.504f333f9de6484597d89b3754a8p-1004), LIT (-0x2.d413cccfe779921165f626cdd52cp-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p-1004), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p-1004), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp-1004), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0x4p-16384 i", LIT (-0x8p-152), LIT (-0x4p-16384), { LIT (0xb.504f333f9de6484597d89b3754a8p-16312), LIT (-0x2.d413cccfe779921165f626cdd52cp-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp-16312), LIT (-0x2.d413cccfe779921165f626cdd52ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 - 0x8p-152 i", LIT (-0x8p-152), LIT (-0x8p-152), { LIT (0x1.49852f983efdd57b4bab8f320d16p-76), LIT (-0x3.1b884327ab8057e2c8727f396696p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320d17p-76), LIT (-0x3.1b884327ab8057e2c8727f396694p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320d16p-76), LIT (-0x3.1b884327ab8057e2c8727f396694p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320d17p-76), LIT (-0x3.1b884327ab8057e2c8727f396694p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152 + 0x8p-152 i", LIT (-0x8p-152), LIT (0x8p-152), { LIT (0x1.49852f983efdd57b4bab8f320d16p-76), LIT (0x3.1b884327ab8057e2c8727f396694p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320d17p-76), LIT (0x3.1b884327ab8057e2c8727f396694p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320d16p-76), LIT (0x3.1b884327ab8057e2c8727f396694p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320d17p-76), LIT (0x3.1b884327ab8057e2c8727f396696p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x9.0a61a7b482d28p-168 - 0x8p-152 i", LIT (-0x9.0a61a7b482d28p-168), LIT (-0x8p-152), { LIT (0x1.fffedeb41cc4e764fc7b2f071b95p-76), LIT (-0x2.0001214c86b1abbcd9ec0a3a2a94p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764fc7b2f071b96p-76), LIT (-0x2.0001214c86b1abbcd9ec0a3a2a94p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764fc7b2f071b95p-76), LIT (-0x2.0001214c86b1abbcd9ec0a3a2a92p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764fc7b2f071b96p-76), LIT (-0x2.0001214c86b1abbcd9ec0a3a2a92p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xb.e2bc1cd6eaa7p-180 + 0x8p-152 i", LIT (-0xb.e2bc1cd6eaa7p-180), LIT (0x8p-152), { LIT (0x1.ffffffe83a87c6df6fad2e2d150fp-76), LIT (0x2.00000017c5783a3b1a49210eea1p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6df6fad2e2d151p-76), LIT (0x2.00000017c5783a3b1a49210eea12p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6df6fad2e2d150fp-76), LIT (0x2.00000017c5783a3b1a49210eea1p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6df6fad2e2d151p-76), LIT (0x2.00000017c5783a3b1a49210eea12p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xd.e1d5fp-4 - 0x1.054226p+4 i", LIT (-0xd.e1d5fp-4), LIT (-0x1.054226p+4), { LIT (0x2.c84e99e2df484b121a43f676e3eap+0), LIT (-0x2.ef2930261e97de8eea66b38cb58p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b121a43f676e3eap+0), LIT (-0x2.ef2930261e97de8eea66b38cb58p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b121a43f676e3eap+0), LIT (-0x2.ef2930261e97de8eea66b38cb57ep+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b121a43f676e3ecp+0), LIT (-0x2.ef2930261e97de8eea66b38cb57ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xe.6432ap-4 + 0xe.8175p-4 i", LIT (-0xe.6432ap-4), LIT (0xe.8175p-4), { LIT (0x6.f3d482a6e0b03b9722cd5561f2ep-4), LIT (0x1.0b0f83813dfbbb8ddfefa6ce47fcp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b9722cd5561f2ep-4), LIT (0x1.0b0f83813dfbbb8ddfefa6ce47fcp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b9722cd5561f2ep-4), LIT (0x1.0b0f83813dfbbb8ddfefa6ce47fcp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b9722cd5561f2e4p-4), LIT (0x1.0b0f83813dfbbb8ddfefa6ce47fdp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xe.735dbp+0 - 0x5.26cb98p+40 i", LIT (-0xe.735dbp+0), LIT (-0x5.26cb98p+40), { LIT (0x1.9adc1d93b4e9b398b22875bb9f3cp+20), LIT (-0x1.9adc1d93b96a35664dffa77bdd62p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398b22875bb9f3cp+20), LIT (-0x1.9adc1d93b96a35664dffa77bdd62p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398b22875bb9f3cp+20), LIT (-0x1.9adc1d93b96a35664dffa77bdd61p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398b22875bb9f3dp+20), LIT (-0x1.9adc1d93b96a35664dffa77bdd61p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020 + +0 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.ffffffffffffbfffffffffffff78p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffbfffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffbfffffffffffff78p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffbfffffffffffff8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0x2.000000000000080000000000003p-1588), LIT (0xf.ffffffffffffbfffffffffffff78p+508), ERRNO_UNCHANGED }, { LIT (0x2.000000000000080000000000003p-1588), LIT (0xf.ffffffffffffbfffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x2.000000000000080000000000003p-1588), LIT (0xf.ffffffffffffbfffffffffffff78p+508), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000800000000000032p-1588), LIT (0xf.ffffffffffffbfffffffffffff8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020 + 0x8.8p-8192 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x8.8p-8192), { LIT (0x4.4000000000001100000000000064p-8704), LIT (0xf.ffffffffffffbfffffffffffff78p+508), ERRNO_UNCHANGED }, { LIT (0x4.4000000000001100000000000068p-8704), LIT (0xf.ffffffffffffbfffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x4.4000000000001100000000000064p-8704), LIT (0xf.ffffffffffffbfffffffffffff78p+508), ERRNO_UNCHANGED }, { LIT (0x4.4000000000001100000000000068p-8704), LIT (0xf.ffffffffffffbfffffffffffff8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0x4.000000000000100000000000006p-664), LIT (0xf.ffffffffffffbfffffffffffff78p+508), ERRNO_UNCHANGED }, { LIT (0x4.000000000000100000000000006p-664), LIT (0xf.ffffffffffffbfffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x4.000000000000100000000000006p-664), LIT (0xf.ffffffffffffbfffffffffffff78p+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001000000000000064p-664), LIT (0xf.ffffffffffffbfffffffffffff8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020 + +0 i", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffdd8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffdep+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffdd8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffdep+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020 + 0x4p-1076 i", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x4p-1076), { LIT (0x2.000000000000040000000000004cp-1588), LIT (0xf.ffffffffffffdffffffffffffdd8p+508), ERRNO_UNCHANGED }, { LIT (0x2.000000000000040000000000004cp-1588), LIT (0xf.ffffffffffffdffffffffffffdep+508), ERRNO_UNCHANGED }, { LIT (0x2.000000000000040000000000004cp-1588), LIT (0xf.ffffffffffffdffffffffffffdd8p+508), ERRNO_UNCHANGED }, { LIT (0x2.000000000000040000000000004ep-1588), LIT (0xf.ffffffffffffdffffffffffffdep+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020 + 0x8.8p-8192 i", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x8.8p-8192), { LIT (0x4.40000000000008800000000000ap-8704), LIT (0xf.ffffffffffffdffffffffffffdd8p+508), ERRNO_UNCHANGED }, { LIT (0x4.40000000000008800000000000ap-8704), LIT (0xf.ffffffffffffdffffffffffffdep+508), ERRNO_UNCHANGED }, { LIT (0x4.40000000000008800000000000ap-8704), LIT (0xf.ffffffffffffdffffffffffffdd8p+508), ERRNO_UNCHANGED }, { LIT (0x4.40000000000008800000000000a4p-8704), LIT (0xf.ffffffffffffdffffffffffffdep+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020 + 0x8p-152 i", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x8p-152), { LIT (0x4.0000000000000800000000000098p-664), LIT (0xf.ffffffffffffdffffffffffffdd8p+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000800000000000098p-664), LIT (0xf.ffffffffffffdffffffffffffdep+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000800000000000098p-664), LIT (0xf.ffffffffffffdffffffffffffdd8p+508), ERRNO_UNCHANGED }, { LIT (0x4.000000000000080000000000009cp-664), LIT (0xf.ffffffffffffdffffffffffffdep+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124 + +0 i", LIT (-0xf.fffffp+124), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124 + 0x4p-1076 i", LIT (-0xf.fffffp+124), LIT (0x4p-1076), { LIT (0x2.000001000000c00000a000008cp-1140), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000c00000a000008cp-1140), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000c00000a000008cp-1140), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000c00000a000008c02p-1140), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124 + 0x8.8p-512 i", LIT (-0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0x4.400002200001980001540001298p-576), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x4.400002200001980001540001298p-576), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED }, { LIT (0x4.400002200001980001540001298p-576), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000019800015400012984p-576), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124 + 0x8.8p-8192 i", LIT (-0xf.fffffp+124), LIT (0x8.8p-8192), { LIT (0x4.400002200001980001540001298p-8256), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x4.400002200001980001540001298p-8256), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED }, { LIT (0x4.400002200001980001540001298p-8256), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000019800015400012984p-8256), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124 + 0x8p-152 i", LIT (-0xf.fffffp+124), LIT (0x8p-152), { LIT (0x4.00000200000180000140000118p-216), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x4.00000200000180000140000118p-216), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED }, { LIT (0x4.00000200000180000140000118p-216), LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018000014000011804p-216), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fp+1020 + +0 i", LIT (-0xf.fp+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fp+1020 + 0x8.8p-512 i", LIT (-0xf.fp+1020), LIT (0x8.8p-512), { LIT (0x4.422199552a8cb654be740b2b7d1cp-1024), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d2p-1024), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d1cp-1024), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d2p-1024), LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fp+1020 + 0x8p-152 i", LIT (-0xf.fp+1020), LIT (0x8p-152), { LIT (0x4.0201814118fce7d749d6a119df28p-664), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119df2cp-664), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119df28p-664), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119df2cp-664), LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fp+124 + 0x8.8p-64 i", LIT (-0xf.fp+124), LIT (0x8.8p-64), { LIT (0x4.422199552a8cb654be740b2b7d1cp-128), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d2p-128), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d1cp-128), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d2p-128), LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fp+16380 + +0 i", LIT (-0xf.fp+16380), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fp+16380 + 0x4p-1076 i", LIT (-0xf.fp+16380), LIT (0x4p-1076), { LIT (0x2.0100c0a08c7e73eba4eb508cef94p-9268), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73eba4eb508cef96p-9268), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73eba4eb508cef94p-9268), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73eba4eb508cef96p-9268), LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fp+16380 + 0x8.8p-8192 i", LIT (-0xf.fp+16380), LIT (0x8.8p-8192), { LIT (0x4.422199552a8cb654be740b2b7d1cp-16384), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d2p-16384), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d1cp-16384), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7d2p-16384), LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fp+16380 + 0x8p-152 i", LIT (-0xf.fp+16380), LIT (0x8p-152), { LIT (0x4.0201814118fce7d749d6a119df28p-8344), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119df2cp-8344), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119df28p-8344), LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119df2cp-8344), LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x1p+0 i", LIT (0x0p+0), LIT (-0x1p+0), { LIT (0xb.504f333f9de6484597d89b3754a8p-4), LIT (-0xb.504f333f9de6484597d89b3754bp-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p-4), LIT (-0xb.504f333f9de6484597d89b3754a8p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p-4), LIT (-0xb.504f333f9de6484597d89b3754a8p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp-4), LIT (-0xb.504f333f9de6484597d89b3754a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x2p+0 i", LIT (0x0p+0), LIT (0x2p+0), { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x0p+0), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4.0000000000000000000000000008p-16384 i", LIT (0x0p+0), LIT (0x4.0000000000000000000000000008p-16384), { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4.0000000000000008p-16384 i", LIT (0x0p+0), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4.000000000000001p-16384 i", LIT (0x0p+0), LIT (0x4.000000000000001p-16384), { LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90b870ee036d21p-8192), LIT (0x1.6a09e667f3bcc90b870ee036d21p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4.0000000000004p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcd459022e5304d0bp-512), LIT (0x1.6a09e667f3bcd459022e5304d0bp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d0b1p-512), LIT (0x1.6a09e667f3bcd459022e5304d0b1p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d0bp-512), LIT (0x1.6a09e667f3bcd459022e5304d0bp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d0b1p-512), LIT (0x1.6a09e667f3bcd459022e5304d0b1p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4.0000000000008p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bcdfa9516192a2b671p-512), LIT (0x1.6a09e667f3bcdfa9516192a2b671p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b671p-512), LIT (0x1.6a09e667f3bcdfa9516192a2b671p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b671p-512), LIT (0x1.6a09e667f3bcdfa9516192a2b671p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b672p-512), LIT (0x1.6a09e667f3bcdfa9516192a2b672p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-16384 i", LIT (0x0p+0), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-16448 i", LIT (0x0p+0), LIT (0x4p-16448), { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8224), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8224), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8224), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8224), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8224), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8224), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8224), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x4p-16496 i", LIT (0x0p+0), LIT (0x4p-16496), { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8248), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8248), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8248), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8248), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8248), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8248), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8248), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8248), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p+1020 i", LIT (0x0p+0), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p+16380 i", LIT (0x0p+0), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p-1076 i", LIT (0x0p+0), LIT (0x8p-1076), { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p-16444 i", LIT (0x0p+0), LIT (0x8p-16444), { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0x8p-16448 i", LIT (0x0p+0), LIT (0x8p-16448), { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x0p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x0p+0), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb86ap+508), LIT (0xb.504f333f9de631a4f9721bfb86ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0 + 0xf.fffffp+124 i", LIT (0x0p+0), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0221e29d5a3cdp-188 - 0x8p-152 i", LIT (0x1.0221e29d5a3cdp-188), LIT (-0x8p-152), { LIT (0x2.00000000020443c53ab57de8514p-76), LIT (-0x1.fffffffffdfbbc3ac54c8aa85142p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c53ab57de85142p-76), LIT (-0x1.fffffffffdfbbc3ac54c8aa85141p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c53ab57de8514p-76), LIT (-0x1.fffffffffdfbbc3ac54c8aa85141p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c53ab57de85142p-76), LIT (-0x1.fffffffffdfbbc3ac54c8aa85141p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.d60caep+0 + 0x7.a7d468p+0 i", LIT (0x1.d60caep+0), LIT (0x7.a7d468p+0), { LIT (0x2.3409baa805bc952b162589badcdp+0), LIT (0x1.bcc10b50fddb6aeab8ce2e2a597ap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952b162589badcd2p+0), LIT (0x1.bcc10b50fddb6aeab8ce2e2a597ap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952b162589badcdp+0), LIT (0x1.bcc10b50fddb6aeab8ce2e2a597ap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952b162589badcd2p+0), LIT (0x1.bcc10b50fddb6aeab8ce2e2a597bp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.f9610ap+4 + 0x9.87716p+4 i", LIT (0x1.f9610ap+4), LIT (0x9.87716p+4), { LIT (0x9.ad5033142bab31612e9054dcdf2p+0), LIT (0x7.e0b144c043868be3519cfa06806cp+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab31612e9054dcdf2p+0), LIT (0x7.e0b144c043868be3519cfa06807p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab31612e9054dcdf2p+0), LIT (0x7.e0b144c043868be3519cfa06806cp+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab31612e9054dcdf28p+0), LIT (0x7.e0b144c043868be3519cfa06807p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 - 0x2p-16384 i", LIT (0x1p+0), LIT (-0x2p-16384), { LIT (0x1p+0), LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0xf.ffffffffffffffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000000000000000001p+0), LIT (-0xf.ffffffffffffffffffffffffffcp-16388), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 - 0x4p-1024 i", LIT (0x1p+0), LIT (-0x4p-1024), { LIT (0x1p+0), LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.ffffffffffffffffffffffffffffp-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (-0x1.ffffffffffffffffffffffffffffp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 - 0x4p-128 i", LIT (0x1p+0), LIT (-0x4p-128), { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.ffffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (-0x1.ffffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 - 0x4p-16384 i", LIT (0x1p+0), LIT (-0x4p-16384), { LIT (0x1p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000000000000000001p+0), LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 - 0x8p-972 i", LIT (0x1p+0), LIT (-0x8p-972), { LIT (0x1p+0), LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.fffffffffffffffffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (-0x3.fffffffffffffffffffffffffffep-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0x2p-16384 i", LIT (0x1p+0), LIT (0x2p-16384), { LIT (0x1p+0), LIT (0xf.ffffffffffffffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xf.ffffffffffffffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x1p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0x4p-1024 i", LIT (0x1p+0), LIT (0x4p-1024), { LIT (0x1p+0), LIT (0x1.ffffffffffffffffffffffffffffp-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.ffffffffffffffffffffffffffffp-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x2p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0x4p-128 i", LIT (0x1p+0), LIT (0x4p-128), { LIT (0x1p+0), LIT (0x1.ffffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.ffffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0x4p-16384 i", LIT (0x1p+0), LIT (0x4p-16384), { LIT (0x1p+0), LIT (0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0 + 0x8p-972 i", LIT (0x1p+0), LIT (0x8p-972), { LIT (0x1p+0), LIT (0x3.fffffffffffffffffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.fffffffffffffffffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), LIT (0x4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+4 - 0x1.ep+4 i", LIT (0x1p+4), LIT (-0x1.ep+4), { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-16440 + +0 i", LIT (0x1p-16440), LIT (0x0p+0), { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-16440 + 0x4p-1076 i", LIT (0x1p-16440), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-16440 + 0x8p-152 i", LIT (0x1p-16440), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-16440 + 0x8p-16444 i", LIT (0x1p-16440), LIT (0x8p-16444), { LIT (0x1.077225f1da571bac72dad8647708p-8220), LIT (0x3.e30ee78adee42e5e26a28ada7bc2p-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571bac72dad8647709p-8220), LIT (0x3.e30ee78adee42e5e26a28ada7bc4p-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571bac72dad8647708p-8220), LIT (0x3.e30ee78adee42e5e26a28ada7bc2p-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571bac72dad8647709p-8220), LIT (0x3.e30ee78adee42e5e26a28ada7bc4p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-500 + +0 i", LIT (0x1p-500), LIT (0x0p+0), { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-500 + 0x4p-1076 i", LIT (0x1p-500), LIT (0x4p-1076), { LIT (0x4p-252), LIT (0x7.fffffffffffffffffffffffffffcp-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x8p-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x7.fffffffffffffffffffffffffffcp-828), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000000004p-252), LIT (0x8p-828), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-500 + 0x8p-152 i", LIT (0x1p-500), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-5000 + +0 i", LIT (0x1p-5000), LIT (0x0p+0), { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-5000 + 0x4p-1076 i", LIT (0x1p-5000), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-5000 + 0x4p-16448 i", LIT (0x1p-5000), LIT (0x4p-16448), { LIT (0x1p-2500), LIT (0x1.ffffffffffffffffffffffffffffp-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x2p-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x1.ffffffffffffffffffffffffffffp-13948), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p-2500), LIT (0x2p-13948), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-5000 + 0x4p-16496 i", LIT (0x1p-5000), LIT (0x4p-16496), { LIT (0x1p-2500), LIT (0x1.ffffffffffffffffffffffffffffp-13996), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x2p-13996), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x1.ffffffffffffffffffffffffffffp-13996), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p-2500), LIT (0x2p-13996), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-5000 + 0x8p-152 i", LIT (0x1p-5000), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-5000 + 0x8p-16448 i", LIT (0x1p-5000), LIT (0x8p-16448), { LIT (0x1p-2500), LIT (0x3.fffffffffffffffffffffffffffep-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x4p-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x3.fffffffffffffffffffffffffffep-13948), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p-2500), LIT (0x4p-13948), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-148 + 0x2p-148 i", LIT (0x2p-148), LIT (0x2p-148), { LIT (0x6.3710864f5700afc590e4fe72cd28p-76), LIT (0x2.930a5f307dfbaaf697571e641a2cp-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc590e4fe72cd28p-76), LIT (0x2.930a5f307dfbaaf697571e641a2ep-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc590e4fe72cd28p-76), LIT (0x2.930a5f307dfbaaf697571e641a2cp-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc590e4fe72cd2cp-76), LIT (0x2.930a5f307dfbaaf697571e641a2ep-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db1f30939cea7c0dd70ad3dbp+0), LIT (0xf.3d9236b503fee60e243767b55b28p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939cea7c0dd70ad3dcp+0), LIT (0xf.3d9236b503fee60e243767b55b3p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939cea7c0dd70ad3dbp+0), LIT (0xf.3d9236b503fee60e243767b55b28p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939cea7c0dd70ad3dcp+0), LIT (0xf.3d9236b503fee60e243767b55b3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db809771dda17a04e5a9cfb1p+0), LIT (0xf.3d923d93816780f8baebea446848p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda17a04e5a9cfb2p+0), LIT (0xf.3d923d93816780f8baebea44685p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda17a04e5a9cfb1p+0), LIT (0xf.3d923d93816780f8baebea446848p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda17a04e5a9cfb2p+0), LIT (0xf.3d923d93816780f8baebea44685p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc0ba4f2875145978e811eep+0), LIT (0xf.3d924761f5b5cfe64009bf6f0bfp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f2875145978e811eep+0), LIT (0xf.3d924761f5b5cfe64009bf6f0bf8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f2875145978e811eep+0), LIT (0xf.3d924761f5b5cfe64009bf6f0bfp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f2875145978e811ee1p+0), LIT (0xf.3d924761f5b5cfe64009bf6f0bf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f0dc684de4c436bp+0), LIT (0xf.3d92365a334569e0a428358b7d1p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0dc684de4c436bp+0), LIT (0xf.3d92365a334569e0a428358b7d1p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0dc684de4c436bp+0), LIT (0xf.3d92365a334569e0a428358b7d1p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0dc684de4c436cp+0), LIT (0xf.3d92365a334569e0a428358b7d18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05acf4d936a88802d7p+0), LIT (0xf.3d923d38b0ae23e2d94a11eaec9p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4d936a88802d8p+0), LIT (0xf.3d923d38b0ae23e2d94a11eaec98p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4d936a88802d7p+0), LIT (0xf.3d923d38b0ae23e2d94a11eaec9p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4d936a88802d8p+0), LIT (0xf.3d923d38b0ae23e2d94a11eaec98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c8652a0df9525e4c6fbp+0), LIT (0xf.3d92470724fc9f33acc4c0d701dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652a0df9525e4c6fcp+0), LIT (0xf.3d92470724fc9f33acc4c0d701d8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652a0df9525e4c6fbp+0), LIT (0xf.3d92470724fc9f33acc4c0d701dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652a0df9525e4c6fcp+0), LIT (0xf.3d92470724fc9f33acc4c0d701d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f8c99d77e46e964p+0), LIT (0xf.3d92365a334562da4b179d650968p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8c99d77e46e965p+0), LIT (0xf.3d92365a334562da4b179d65097p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8c99d77e46e964p+0), LIT (0xf.3d92365a334562da4b179d650968p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8c99d77e46e965p+0), LIT (0xf.3d92365a334562da4b179d65097p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ad73ac8910d2a482p+0), LIT (0xf.3d923d38b0ae1cdc803be176d67p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad73ac8910d2a482p+0), LIT (0xf.3d923d38b0ae1cdc803be176d67p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad73ac8910d2a482p+0), LIT (0xf.3d923d38b0ae1cdc803be176d67p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad73ac8910d2a483p+0), LIT (0xf.3d923d38b0ae1cdc803be176d678p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c86531fb2e73eaf3e4dp+0), LIT (0xf.3d92470724fc982d53b9ff5df3e8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86531fb2e73eaf3e4ep+0), LIT (0xf.3d92470724fc982d53b9ff5df3fp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86531fb2e73eaf3e4dp+0), LIT (0xf.3d92470724fc982d53b9ff5df3e8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86531fb2e73eaf3e4ep+0), LIT (0xf.3d92470724fc982d53b9ff5df3fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f932e12df109811p+0), LIT (0xf.3d92365a3345627d012e06d767ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f932e12df109811p+0), LIT (0xf.3d92365a3345627d012e06d767ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f932e12df109811p+0), LIT (0xf.3d92365a3345627d012e06d767ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f932e12df109812p+0), LIT (0xf.3d92365a3345627d012e06d767e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ad7a40c46eb8cc73p+0), LIT (0xf.3d923d38b0ae1c7f36526ad99bdp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7a40c46eb8cc73p+0), LIT (0xf.3d923d38b0ae1c7f36526ad99bd8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7a40c46eb8cc73p+0), LIT (0xf.3d923d38b0ae1c7f36526ad99bdp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7a40c46eb8cc74p+0), LIT (0xf.3d923d38b0ae1c7f36526ad99bd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c86532647229875a329p+0), LIT (0xf.3d92470724fc97d009d0b659839p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532647229875a32ap+0), LIT (0xf.3d92470724fc97d009d0b6598398p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532647229875a329p+0), LIT (0xf.3d92470724fc97d009d0b659839p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532647229875a32ap+0), LIT (0xf.3d92470724fc97d009d0b6598398p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f8p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2fdd855d19cf1f5e8bfbd3p+0), LIT (0xf.3d9235c88f9fa24728a26688b1ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d19cf1f5e8bfbd3p+0), LIT (0xf.3d9235c88f9fa24728a26688b1ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d19cf1f5e8bfbd3p+0), LIT (0xf.3d9235c88f9fa24728a26688b1ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d19cf1f5e8bfbd4p+0), LIT (0xf.3d9235c88f9fa24728a26688b1e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f8p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db914463967e5bb4fceaa5ap+0), LIT (0xf.3d923ca70d088e2617e22ff8c15p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967e5bb4fceaa5ap+0), LIT (0xf.3d923ca70d088e2617e22ff8c15p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967e5bb4fceaa5ap+0), LIT (0xf.3d923ca70d088e2617e22ff8c15p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967e5bb4fceaa5a1p+0), LIT (0xf.3d923ca70d088e2617e22ff8c158p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.f768f8p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc1c51e435ba2999d1f3426ap+0), LIT (0xf.3d924675815750a6174c42a76aap-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435ba2999d1f3426bp+0), LIT (0xf.3d924675815750a6174c42a76aa8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435ba2999d1f3426ap+0), LIT (0xf.3d924675815750a6174c42a76aap-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435ba2999d1f3426bp+0), LIT (0xf.3d924675815750a6174c42a76aa8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000000000000000004p-16384 + +0 i", LIT (0x4.0000000000000000000000000004p-16384), LIT (0x0p+0), { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-8192), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000000000000000004p-16384 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x4.0000000000000000000000000004p-16384), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbfp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d8p-8192), LIT (0xe.90189c7b6414133be637803acbf8p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbfp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d8p-8192), LIT (0xe.90189c7b6414133be637803acbf8p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000000000000000004p-16384 + 0x4.0000000000000008p-16384 i", LIT (0x4.0000000000000000000000000004p-16384), LIT (0x4.0000000000000008p-16384), { LIT (0x2.3286b95ff53f16afaed19f01d954p-8192), LIT (0xe.90189c7b64141354c279997827e8p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16afaed19f01d956p-8192), LIT (0xe.90189c7b64141354c279997827fp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16afaed19f01d954p-8192), LIT (0xe.90189c7b64141354c279997827e8p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16afaed19f01d956p-8192), LIT (0xe.90189c7b64141354c279997827fp-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000000000000000004p-16384 + 0x4p-1076 i", LIT (0x4.0000000000000000000000000004p-16384), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000000000000000004p-16384 + 0x4p-16384 i", LIT (0x4.0000000000000000000000000004p-16384), LIT (0x4p-16384), { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbe8p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbe8p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbe8p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d8p-8192), LIT (0xe.90189c7b6414133be637803acbfp-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000000000000000004p-16384 + 0x8p-152 i", LIT (0x4.0000000000000000000000000004p-16384), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000008p-16384 + +0 i", LIT (0x4.0000000000000008p-16384), LIT (0x0p+0), { LIT (0x2.0000000000000001fffffffffffep-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000002p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000001fffffffffffep-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000002p-8192), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000008p-16384 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x4.0000000000000008p-16384), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x2.3286b95ff53f16b097d328c98f96p-8192), LIT (0xe.90189c7b641413319a0e0378d408p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b097d328c98f96p-8192), LIT (0xe.90189c7b641413319a0e0378d41p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b097d328c98f96p-8192), LIT (0xe.90189c7b641413319a0e0378d408p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b097d328c98f98p-8192), LIT (0xe.90189c7b641413319a0e0378d41p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000008p-16384 + 0x4.0000000000000008p-16384 i", LIT (0x4.0000000000000008p-16384), LIT (0x4.0000000000000008p-16384), { LIT (0x2.3286b95ff53f16b13c95c095af14p-8192), LIT (0xe.90189c7b6414134a76501cb63p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b13c95c095af14p-8192), LIT (0xe.90189c7b6414134a76501cb63008p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b13c95c095af14p-8192), LIT (0xe.90189c7b6414134a76501cb63p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b13c95c095af16p-8192), LIT (0xe.90189c7b6414134a76501cb63008p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000008p-16384 + 0x4p-1076 i", LIT (0x4.0000000000000008p-16384), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000008p-16384 + 0x4p-16384 i", LIT (0x4.0000000000000008p-16384), LIT (0x4p-16384), { LIT (0x2.3286b95ff53f16b097d328c98f96p-8192), LIT (0xe.90189c7b641413319a0e0378d4p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b097d328c98f96p-8192), LIT (0xe.90189c7b641413319a0e0378d4p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b097d328c98f96p-8192), LIT (0xe.90189c7b641413319a0e0378d4p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b097d328c98f98p-8192), LIT (0xe.90189c7b641413319a0e0378d408p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000000008p-16384 + 0x8p-152 i", LIT (0x4.0000000000000008p-16384), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000004p-1024 + +0 i", LIT (0x4.0000000000004p-1024), LIT (0x0p+0), { LIT (0x2.0000000000000fffffffffffffcp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000fffffffffffffcp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000fffffffffffffcp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000fffffffffffffc2p-512), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000004p-1024 + 0x4.0000000000004p-1024 i", LIT (0x4.0000000000004p-1024), LIT (0x4.0000000000004p-1024), { LIT (0x2.3286b95ff53f28433fda06dfb244p-512), LIT (0xe.90189c7b641487bcab1b5b5b6abp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f28433fda06dfb246p-512), LIT (0xe.90189c7b641487bcab1b5b5b6ab8p-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f28433fda06dfb244p-512), LIT (0xe.90189c7b641487bcab1b5b5b6abp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f28433fda06dfb246p-512), LIT (0xe.90189c7b641487bcab1b5b5b6ab8p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.0000000000004p-1024 + 0x8p-152 i", LIT (0x4.0000000000004p-1024), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.000008p-128 + 0x4.000008p-128 i", LIT (0x4.000008p-128), LIT (0x4.000008p-128), { LIT (0x2.3286bb927bf75d60ed8efefb8decp-64), LIT (0xe.9018ab0b7ca94693b355165c1d7p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d60ed8efefb8decp-64), LIT (0xe.9018ab0b7ca94693b355165c1d78p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d60ed8efefb8decp-64), LIT (0xe.9018ab0b7ca94693b355165c1d7p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d60ed8efefb8deep-64), LIT (0xe.9018ab0b7ca94693b355165c1d78p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x4p-1076), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000000000000000004p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x4.0000000000000000000000000004p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4.0000000000000000000000000008p-16384 i", LIT (0x4p-1076), LIT (0x4.0000000000000000000000000008p-16384), { LIT (0x8p-540), LIT (0x4.0000000000000000000000000004p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000000000000000008p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000000000000000004p-15848), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x4.0000000000000000000000000008p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4.0000000000000008p-16384 i", LIT (0x4p-1076), LIT (0x4.0000000000000008p-16384), { LIT (0x8p-540), LIT (0x4.0000000000000007fffffffffffcp-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000007fffffffffffcp-15848), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4.000000000000001p-16384 i", LIT (0x4p-1076), LIT (0x4.000000000000001p-16384), { LIT (0x8p-540), LIT (0x4.000000000000000ffffffffffffcp-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.000000000000001p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.000000000000000ffffffffffffcp-15848), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x4.000000000000001p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4.0000000000004p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcdfa9516192a2b6cbp-512), LIT (0x1.6a09e667f3bcc908b2fb1366eaefp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b6ccp-512), LIT (0x1.6a09e667f3bcc908b2fb1366eafp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b6cbp-512), LIT (0x1.6a09e667f3bcc908b2fb1366eaefp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b6ccp-512), LIT (0x1.6a09e667f3bcc908b2fb1366eafp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4.0000000000008p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bceaf9a094d2409c31p-512), LIT (0x1.6a09e667f3bcd459022e5304d10bp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceaf9a094d2409c32p-512), LIT (0x1.6a09e667f3bcd459022e5304d10bp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceaf9a094d2409c31p-512), LIT (0x1.6a09e667f3bcd459022e5304d10bp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceaf9a094d2409c32p-512), LIT (0x1.6a09e667f3bcd459022e5304d10cp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4p-1076 i", LIT (0x4p-1076), LIT (0x4p-1076), { LIT (0x8.ca1ae57fd4fc5abc283c1cd6e75p-540), LIT (0x3.a406271ed90504cef98de00eb2fcp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5abc283c1cd6e758p-540), LIT (0x3.a406271ed90504cef98de00eb2fcp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5abc283c1cd6e75p-540), LIT (0x3.a406271ed90504cef98de00eb2fcp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5abc283c1cd6e758p-540), LIT (0x3.a406271ed90504cef98de00eb2fep-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4p-16384 i", LIT (0x4p-1076), LIT (0x4p-16384), { LIT (0x8p-540), LIT (0x3.fffffffffffffffffffffffffffep-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x3.fffffffffffffffffffffffffffep-15848), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x4p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4p-16448 i", LIT (0x4p-1076), LIT (0x4p-16448), { LIT (0x8p-540), LIT (0x3.fffffffffffffffffffffffffffep-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x3.fffffffffffffffffffffffffffep-15912), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x4p-15912), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x4p-16496 i", LIT (0x4p-1076), LIT (0x4p-16496), { LIT (0x8p-540), LIT (0x3.fffffffffffffffffffffffffffep-15960), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15960), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x3.fffffffffffffffffffffffffffep-15960), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x4p-15960), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x8p+1020 i", LIT (0x4p-1076), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x8p+16380 i", LIT (0x4p-1076), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x8p-152 i", LIT (0x4p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x8p-16444 i", LIT (0x4p-1076), LIT (0x8p-16444), { LIT (0x8p-540), LIT (0x7.fffffffffffffffffffffffffffcp-15908), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-15908), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x7.fffffffffffffffffffffffffffcp-15908), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x8p-15908), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0x8p-16448 i", LIT (0x4p-1076), LIT (0x8p-16448), { LIT (0x8p-540), LIT (0x7.fffffffffffffffffffffffffffcp-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x7.fffffffffffffffffffffffffffcp-15912), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-540), LIT (0x8p-15912), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0xf.ffffffffffff8p+1020 i", LIT (0x4p-1076), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x4p-1076), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb86ap+508), LIT (0xb.504f333f9de631a4f9721bfb86ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076 + 0xf.fffffp+124 i", LIT (0x4p-1076), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384 + +0 i", LIT (0x4p-16384), LIT (0x0p+0), { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x4p-16384), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbf8p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803accp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbf8p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d8p-8192), LIT (0xe.90189c7b6414133be637803accp-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384 + 0x4.0000000000000008p-16384 i", LIT (0x4p-16384), LIT (0x4.0000000000000008p-16384), { LIT (0x2.3286b95ff53f16afaed19f01d954p-8192), LIT (0xe.90189c7b64141354c279997827fp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16afaed19f01d954p-8192), LIT (0xe.90189c7b64141354c279997827fp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16afaed19f01d954p-8192), LIT (0xe.90189c7b64141354c279997827fp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16afaed19f01d956p-8192), LIT (0xe.90189c7b64141354c279997827f8p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384 + 0x4p-1076 i", LIT (0x4p-16384), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384 + 0x4p-16384 i", LIT (0x4p-16384), LIT (0x4p-16384), { LIT (0x2.3286b95ff53f16af0a0f0735b9d4p-8192), LIT (0xe.90189c7b6414133be637803acbfp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbfp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d4p-8192), LIT (0xe.90189c7b6414133be637803acbfp-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16af0a0f0735b9d6p-8192), LIT (0xe.90189c7b6414133be637803acbf8p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384 + 0x8p-152 i", LIT (0x4p-16384), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + +0 i", LIT (0x4p-16448), LIT (0x0p+0), { LIT (0x2p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x4p-16448), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x1.6a09e667f3bcc9096800069ae474p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b7p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae475p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b8p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae474p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b7p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae475p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b8p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0x4.0000000000000000000000000008p-16384 i", LIT (0x4p-16448), LIT (0x4.0000000000000000000000000008p-16384), { LIT (0x1.6a09e667f3bcc9096800069ae475p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b8p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae475p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b9p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae475p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b8p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae476p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b9p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0x4.0000000000000008p-16384 i", LIT (0x4p-16448), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90ad209ed02d83p-8192), LIT (0x1.6a09e667f3bcc9096800069ae473p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ad209ed02d831p-8192), LIT (0x1.6a09e667f3bcc9096800069ae474p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ad209ed02d83p-8192), LIT (0x1.6a09e667f3bcc9096800069ae473p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ad209ed02d831p-8192), LIT (0x1.6a09e667f3bcc9096800069ae474p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0x4p-1076 i", LIT (0x4p-16448), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0x4p-16384 i", LIT (0x4p-16448), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc9096800069ae473p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b7p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae474p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b7p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae473p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b7p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc9096800069ae474p-8192), LIT (0x1.6a09e667f3bcc907fdf62032f0b8p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0x8p+16380 i", LIT (0x4p-16448), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0x8p-152 i", LIT (0x4p-16448), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0xf.ffffffffffff8p+1020 i", LIT (0x4p-16448), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x4p-16448), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb86ap+508), LIT (0xb.504f333f9de631a4f9721bfb86ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448 + 0xf.fffffp+124 i", LIT (0x4p-16448), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + +0 i", LIT (0x4p-16496), LIT (0x0p+0), { LIT (0x2p-8248), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8248), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8248), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8248), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x4p-16496), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0x4.0000000000000000000000000008p-16384 i", LIT (0x4p-16496), LIT (0x4.0000000000000000000000000008p-16384), { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea98p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea98p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0x4.0000000000000008p-16384 i", LIT (0x4p-16496), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede51p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede51p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0x4p-1076 i", LIT (0x4p-16496), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0x4p-16384 i", LIT (0x4p-16496), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea94p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea94p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908b2fb1366ea97p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0x8p+16380 i", LIT (0x4p-16496), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0x8p-152 i", LIT (0x4p-16496), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0xf.ffffffffffff8p+1020 i", LIT (0x4p-16496), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x4p-16496), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb86ap+508), LIT (0xb.504f333f9de631a4f9721bfb86ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496 + 0xf.fffffp+124 i", LIT (0x4p-16496), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-52 + 0x8p-152 i", LIT (0x4p-52), LIT (0x8p-152), { LIT (0x8p-28), LIT (0x7.fffffffffffffffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x7.fffffffffffffffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-28), LIT (0x8p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.39e238p+0 - 0x4.576278p-4 i", LIT (0x5.39e238p+0), LIT (-0x4.576278p-4), { LIT (0x2.496e354be8ff297cdb78cd2981bcp+0), LIT (-0xf.2fef5df67620a002c8298862676p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cdb78cd2981bep+0), LIT (-0xf.2fef5df67620a002c82988626758p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cdb78cd2981bcp+0), LIT (-0xf.2fef5df67620a002c82988626758p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cdb78cd2981bep+0), LIT (-0xf.2fef5df67620a002c82988626758p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.9cc21p-4 - 0x1.fb1ec8p+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec8p+0), { LIT (0x1.163c67724ff4a226cf087765a16dp+0), LIT (-0xe.94bd3c203679a4cf7915a8cb6268p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226cf087765a16ep+0), LIT (-0xe.94bd3c203679a4cf7915a8cb6268p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226cf087765a16dp+0), LIT (-0xe.94bd3c203679a4cf7915a8cb626p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226cf087765a16ep+0), LIT (-0xe.94bd3c203679a4cf7915a8cb626p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.9cc21p-4 - 0x1.fb1ec91b40dcdp+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec91b40dcdp+0), { LIT (0x1.163c67b277e8b48129b48dbf9ad4p+0), LIT (-0xe.94bd40e8718fd24951a429be2918p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b48129b48dbf9ad5p+0), LIT (-0xe.94bd40e8718fd24951a429be291p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b48129b48dbf9ad4p+0), LIT (-0xe.94bd40e8718fd24951a429be291p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b48129b48dbf9ad5p+0), LIT (-0xe.94bd40e8718fd24951a429be291p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.9cc21p-4 - 0x1.fb1ecap+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ecap+0), { LIT (0x1.163c67e6476248ee6aa067fa3f86p+0), LIT (-0xe.94bd44c5182a0d43dafb53336b08p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248ee6aa067fa3f86p+0), LIT (-0xe.94bd44c5182a0d43dafb53336bp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248ee6aa067fa3f86p+0), LIT (-0xe.94bd44c5182a0d43dafb53336bp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248ee6aa067fa3f87p+0), LIT (-0xe.94bd44c5182a0d43dafb53336bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.b1a2e79e9c9acp-164 + 0x8p-152 i", LIT (0x6.b1a2e79e9c9acp-164), LIT (0x8p-152), { LIT (0x2.000d63729cf6c5d96fbd4c72f68p-76), LIT (0x1.fff29ce700d43550653bb310cafep-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d96fbd4c72f68p-76), LIT (0x1.fff29ce700d43550653bb310caffp-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d96fbd4c72f68p-76), LIT (0x1.fff29ce700d43550653bb310cafep-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d96fbd4c72f682p-76), LIT (0x1.fff29ce700d43550653bb310caffp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.7p+4 + 0x7.8p+4 i", LIT (0x7.7p+4), LIT (0x7.8p+4), { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+1020 + +0 i", LIT (0x8p+1020), LIT (0x0p+0), { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+1020 + 0x4p-1076 i", LIT (0x8p+1020), LIT (0x4p-1076), { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x2.d413cccfe779921165f626cdd52ap-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x2.d413cccfe779921165f626cdd52ap-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x2.d413cccfe779921165f626cdd52ap-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp+508), LIT (0x2.d413cccfe779921165f626cdd52cp-1588), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+1020 + 0x8p-152 i", LIT (0x8p+1020), LIT (0x8p-152), { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x5.a827999fcef32422cbec4d9baa54p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x5.a827999fcef32422cbec4d9baa54p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+508), LIT (0x5.a827999fcef32422cbec4d9baa54p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp+508), LIT (0x5.a827999fcef32422cbec4d9baa58p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+124 + 0x8p-152 i", LIT (0x8p+124), LIT (0x8p-152), { LIT (0xb.504f333f9de6484597d89b3754a8p+60), LIT (0x5.a827999fcef32422cbec4d9baa54p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+60), LIT (0x5.a827999fcef32422cbec4d9baa54p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+60), LIT (0x5.a827999fcef32422cbec4d9baa54p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp+60), LIT (0x5.a827999fcef32422cbec4d9baa58p-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380 + +0 i", LIT (0x8p+16380), LIT (0x0p+0), { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp+8188), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380 + 0x4p-1076 i", LIT (0x8p+16380), LIT (0x4p-1076), { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x2.d413cccfe779921165f626cdd52ap-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x2.d413cccfe779921165f626cdd52ap-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x2.d413cccfe779921165f626cdd52ap-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp+8188), LIT (0x2.d413cccfe779921165f626cdd52cp-9268), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380 + 0x4p-16448 i", LIT (0x8p+16380), LIT (0x4p-16448), { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754bp+8188), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380 + 0x4p-16496 i", LIT (0x8p+16380), LIT (0x4p-16496), { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754bp+8188), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380 + 0x8p-152 i", LIT (0x8p+16380), LIT (0x8p-152), { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x5.a827999fcef32422cbec4d9baa54p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x5.a827999fcef32422cbec4d9baa54p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x5.a827999fcef32422cbec4d9baa54p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp+8188), LIT (0x5.a827999fcef32422cbec4d9baa58p-8344), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380 + 0x8p-16448 i", LIT (0x8p+16380), LIT (0x8p-16448), { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754a8p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754bp+8188), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-1076 + +0 i", LIT (0x8p-1076), LIT (0x0p+0), { LIT (0xb.504f333f9de6484597d89b3754a8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754a8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754bp-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-1076 + 0x8p-1076 i", LIT (0x8p-1076), LIT (0x8p-1076), { LIT (0xc.6e210c9eae015f8b21c9fce59a5p-540), LIT (0x5.2614be60fbf755ed2eae3cc83458p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f8b21c9fce59a5p-540), LIT (0x5.2614be60fbf755ed2eae3cc8345cp-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f8b21c9fce59a5p-540), LIT (0x5.2614be60fbf755ed2eae3cc83458p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f8b21c9fce59a58p-540), LIT (0x5.2614be60fbf755ed2eae3cc8345cp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-1076 + 0x8p-152 i", LIT (0x8p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 - 0x8p-152 i", LIT (0x8p-152), LIT (-0x8p-152), { LIT (0x3.1b884327ab8057e2c8727f396694p-76), LIT (-0x1.49852f983efdd57b4bab8f320d17p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f396694p-76), LIT (-0x1.49852f983efdd57b4bab8f320d17p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f396694p-76), LIT (-0x1.49852f983efdd57b4bab8f320d16p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f396696p-76), LIT (-0x1.49852f983efdd57b4bab8f320d16p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x8p-152), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754bp-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754b8p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754bp-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de6484597d89b3754b8p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4.0000000000000000000000000008p-16384 i", LIT (0x8p-152), LIT (0x4.0000000000000000000000000008p-16384), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754cp-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754cp-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754cp-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de6484597d89b3754c8p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4.0000000000000008p-16384 i", LIT (0x8p-152), LIT (0x4.0000000000000008p-16384), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6485c387701b69078p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6485c387701b69078p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6485c387701b69078p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de6485c387701b6908p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4.000000000000001p-16384 i", LIT (0x8p-152), LIT (0x4.000000000000001p-16384), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de64872d9156835cc4p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de64872d9156835cc48p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de64872d9156835cc4p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de64872d9156835cc48p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4.0000000000004p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000004p-1024), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6fd4a8b0c9515b93p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6fd4a8b0c9515b93p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6fd4a8b0c9515b93p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de6fd4a8b0c9515b938p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4.0000000000008p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000008p-1024), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de7b24f7e408ef41dbp-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de7b24f7e408ef41db8p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de7b24f7e408ef41dbp-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de7b24f7e408ef41db8p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4.000008p-128 i", LIT (0x8p-152), LIT (0x4.000008p-128), { LIT (0x1.6a09e93c07882ee646253113a0ccp-64), LIT (0x1.6a09e667f3be3312968ef35a6ccfp-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee646253113a0ccp-64), LIT (0x1.6a09e667f3be3312968ef35a6ccfp-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee646253113a0ccp-64), LIT (0x1.6a09e667f3be3312968ef35a6ccfp-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee646253113a0cdp-64), LIT (0x1.6a09e667f3be3312968ef35a6cdp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4.00001p-128 i", LIT (0x8p-152), LIT (0x4.00001p-128), { LIT (0x1.6a09eaa6116b0dc14c1b98b5b938p-64), LIT (0x1.6a09e7d1fda3e6015c9ae986dce3p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc14c1b98b5b938p-64), LIT (0x1.6a09e7d1fda3e6015c9ae986dce4p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc14c1b98b5b938p-64), LIT (0x1.6a09e7d1fda3e6015c9ae986dce3p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc14c1b98b5b939p-64), LIT (0x1.6a09e7d1fda3e6015c9ae986dce4p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4p-1076 i", LIT (0x8p-152), LIT (0x4p-1076), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de6484597d89b3754bp-1004), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4p-16384 i", LIT (0x8p-152), LIT (0x4p-16384), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de6484597d89b3754bp-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4p-16448 i", LIT (0x8p-152), LIT (0x4p-16448), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-16376), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-16376), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484597d89b3754a8p-16376), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de6484597d89b3754bp-16376), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x4p-16496 i", LIT (0x8p-152), LIT (0x4p-16496), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484594p-16424), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484598p-16424), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0xb.504f333f9de6484594p-16424), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0xb.504f333f9de6484598p-16424), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x7.8p-148 i", LIT (0x8p-152), LIT (0x7.8p-148), { LIT (0x8.02213e8d55a4ec309c4e474cd598p-76), LIT (0x7.7e015d4e23f441ba1dff5c60a22cp-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec309c4e474cd598p-76), LIT (0x7.7e015d4e23f441ba1dff5c60a22cp-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec309c4e474cd598p-76), LIT (0x7.7e015d4e23f441ba1dff5c60a22cp-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec309c4e474cd5ap-76), LIT (0x7.7e015d4e23f441ba1dff5c60a23p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x8p+1020 i", LIT (0x8p-152), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x8p+124 i", LIT (0x8p-152), LIT (0x8p+124), { LIT (0x8p+60), LIT (0x7.fffffffffffffffffffffffffffcp+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x7.fffffffffffffffffffffffffffcp+60), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+60), LIT (0x8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x8p+16380 i", LIT (0x8p-152), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x8p-1076 i", LIT (0x8p-152), LIT (0x8p-1076), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-1000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x8p-152 i", LIT (0x8p-152), LIT (0x8p-152), { LIT (0x3.1b884327ab8057e2c8727f396694p-76), LIT (0x1.49852f983efdd57b4bab8f320d16p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f396694p-76), LIT (0x1.49852f983efdd57b4bab8f320d17p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f396694p-76), LIT (0x1.49852f983efdd57b4bab8f320d16p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f396696p-76), LIT (0x1.49852f983efdd57b4bab8f320d17p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x8p-16444 i", LIT (0x8p-152), LIT (0x8p-16444), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-16368), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0x8p-16448 i", LIT (0x8p-152), LIT (0x8p-16448), { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-76), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-16372), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0xf.ffffffffffff8p+1020 i", LIT (0x8p-152), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x8p-152), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb86ap+508), LIT (0xb.504f333f9de631a4f9721bfb86ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152 + 0xf.fffffp+124 i", LIT (0x8p-152), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + +0 i", LIT (0x8p-16448), LIT (0x0p+0), { LIT (0x2.d413cccfe779921165f626cdd52ap-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52ap-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd52cp-8224), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x4.0000000000000000000000000004p-16384 i", LIT (0x8p-16448), LIT (0x4.0000000000000000000000000004p-16384), { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6d9p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6d9p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6d9p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6dap-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x4.0000000000000000000000000008p-16384 i", LIT (0x8p-16448), LIT (0x4.0000000000000000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6dap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede54p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6dap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6dap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede54p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6dbp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x4.0000000000000008p-16384 i", LIT (0x8p-16448), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90b870ee036d20fp-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea95p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90b870ee036d21p-8192), LIT (0x1.6a09e667f3bcc908b2fb1366ea96p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x4.000000000000001p-16384 i", LIT (0x8p-16448), LIT (0x4.000000000000001p-16384), { LIT (0x1.6a09e667f3bcc90cf118c69ec5cbp-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cf118c69ec5ccp-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cf118c69ec5cbp-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cf118c69ec5ccp-8192), LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x4p-1076 i", LIT (0x8p-16448), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa54p-540), LIT (0x5.a827999fcef32422cbec4d9baa54p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baa58p-540), LIT (0x5.a827999fcef32422cbec4d9baa58p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x4p-16384 i", LIT (0x8p-16448), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6d8p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6d9p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede52p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6d8p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90a1d04f9cede53p-8192), LIT (0x1.6a09e667f3bcc90748f12cfef6d9p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x8p+16380 i", LIT (0x8p-16448), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0x8p-152 i", LIT (0x8p-16448), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000000000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0xf.ffffffffffff8p+1020 i", LIT (0x8p-16448), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x8p-16448), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb86ap+508), LIT (0xb.504f333f9de631a4f9721bfb86ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448 + 0xf.fffffp+124 i", LIT (0x8p-16448), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa38p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), LIT (0xb.504f2d97764b3e6cbd977fbafa4p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.0cf78272ed4f605dfff3fea6159ap+0), LIT (0x9.84953b9e67deb2fe57ac37bf9148p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605dfff3fea6159bp+0), LIT (0x9.84953b9e67deb2fe57ac37bf915p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605dfff3fea6159ap+0), LIT (0x9.84953b9e67deb2fe57ac37bf9148p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605dfff3fea6159bp+0), LIT (0x9.84953b9e67deb2fe57ac37bf915p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xd.25d559ac5baap-168 + 0x8p-152 i", LIT (0xd.25d559ac5baap-168), LIT (0x8p-152), { LIT (0x2.0001a4bb58123fe162db7d9d6d2ep-76), LIT (0x1.fffe5b4601a8450ff04752f0ab62p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fe162db7d9d6d3p-76), LIT (0x1.fffe5b4601a8450ff04752f0ab63p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fe162db7d9d6d2ep-76), LIT (0x1.fffe5b4601a8450ff04752f0ab62p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fe162db7d9d6d3p-76), LIT (0x1.fffe5b4601a8450ff04752f0ab63p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.229827fe17d08p-4 + 0xd.849ecp-4 i", LIT (0xe.229827fe17d08p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00ac53515a8be28bdca1157b7p+0), LIT (0x6.96423e0f6402721c81ccafa98ea4p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8be28bdca1157b8p+0), LIT (0x6.96423e0f6402721c81ccafa98ea8p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8be28bdca1157b7p+0), LIT (0x6.96423e0f6402721c81ccafa98ea4p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8be28bdca1157b8p+0), LIT (0x6.96423e0f6402721c81ccafa98ea8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.22982p-4 + 0xd.849ecp-4 i", LIT (0xe.22982p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00a8f88c3be402c8f8b728c2bp+0), LIT (0x6.96423f67ee9c453f21bd8b8025e8p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be402c8f8b728c2cp+0), LIT (0x6.96423f67ee9c453f21bd8b8025e8p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be402c8f8b728c2bp+0), LIT (0x6.96423f67ee9c453f21bd8b8025e8p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be402c8f8b728c2cp+0), LIT (0x6.96423f67ee9c453f21bd8b8025ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.22983p-4 + 0xd.849ecp-4 i", LIT (0xe.22983p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00afafb0445adfa106798f19fp+0), LIT (0x6.96423cb6350011fc8758aa4813bcp-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445adfa106798f1ap+0), LIT (0x6.96423cb6350011fc8758aa4813bcp-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445adfa106798f19fp+0), LIT (0x6.96423cb6350011fc8758aa4813bcp-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445adfa106798f1ap+0), LIT (0x6.96423cb6350011fc8758aa4813cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.8p+16380 + 0x8p+16380 i", LIT (0xf.8p+16380), LIT (0x8p+16380), { LIT (0x1.03be61de0c283c976f29f999f187p+8192), LIT (0x3.f13db93133426b29a4cf68a47928p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c976f29f999f187p+8192), LIT (0x3.f13db93133426b29a4cf68a47928p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c976f29f999f187p+8192), LIT (0x3.f13db93133426b29a4cf68a47928p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c976f29f999f188p+8192), LIT (0x3.f13db93133426b29a4cf68a4792ap+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.8p+16380 + 0xf.8p+16380 i", LIT (0xf.8p+16380), LIT (0xf.8p+16380), { LIT (0x1.14d561462f72313b41a3e8922092p+8192), LIT (0x7.2ab0eef99eed6b1f39b7abe3349p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313b41a3e8922093p+8192), LIT (0x7.2ab0eef99eed6b1f39b7abe3349p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313b41a3e8922092p+8192), LIT (0x7.2ab0eef99eed6b1f39b7abe3349p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313b41a3e8922093p+8192), LIT (0x7.2ab0eef99eed6b1f39b7abe33494p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.8p+16380 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.8p+16380), LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c524036f3e2ab6820fa2aa9b9p-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c524036f3e2ab6820fa2aa9b98p-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c524036f3e2ab6820fa2aa9b9p-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d5p+8188), LIT (0x8.20c524036f3e2ab6820fa2aa9b98p-7172), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.8p+16380 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0xf.8p+16380), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c524036f3e4b39969fb0679338p-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c524036f3e4b39969fb067934p-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c524036f3e4b39969fb0679338p-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d5p+8188), LIT (0x8.20c524036f3e4b39969fb067934p-7172), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.8p+16380 + 0xf.fffffp+124 i", LIT (0xf.8p+16380), LIT (0xf.fffffp+124), { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c51be2aa1a684d6cc401795f3p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c51be2aa1a684d6cc401795f38p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d4f8p+8188), LIT (0x8.20c51be2aa1a684d6cc401795f3p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bd8bac8066d5p+8188), LIT (0x8.20c51be2aa1a684d6cc401795f38p-8068), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.a24adp+28 + 0x8.0f148p+36 i", LIT (0xf.a24adp+28), LIT (0x8.0f148p+36), { LIT (0x8.0f544aab1480595cbd4e8ac1935p+16), LIT (0x7.ffc0aea89479a12a5f913347d51cp+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480595cbd4e8ac1935p+16), LIT (0x7.ffc0aea89479a12a5f913347d51cp+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480595cbd4e8ac1935p+16), LIT (0x7.ffc0aea89479a12a5f913347d51cp+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480595cbd4e8ac19358p+16), LIT (0x7.ffc0aea89479a12a5f913347d52p+16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + +0 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x2.000000000000080000000000003p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x2.000000000000080000000000003p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x2.000000000000080000000000003p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x2.0000000000000800000000000032p-1588), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0x4p-16448 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x4p-16448), { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0x4p-16496 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x4p-16496), { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0x8.8p-8192 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8.8p-8192), { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x4.4000000000001100000000000064p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x4.4000000000001100000000000068p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x4.4000000000001100000000000064p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x4.4000000000001100000000000068p-8704), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0x8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p+1020), { LIT (0x1.077225f1da5717fdea7d77c6afd9p+512), LIT (0x3.e30ee78adee43c462def644d249ep+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fdea7d77c6afd9p+512), LIT (0x3.e30ee78adee43c462def644d249ep+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fdea7d77c6afd9p+512), LIT (0x3.e30ee78adee43c462def644d249ep+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fdea7d77c6afdap+512), LIT (0x3.e30ee78adee43c462def644d24ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0x8p+16380 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x4.000000000000100000000000006p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x4.000000000000100000000000006p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x4.000000000000100000000000006p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x4.0000000000001000000000000064p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0x8p-16448 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p-16448), { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0xf.8p+16380 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.8p+16380), { LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.19435caffa9f86f27794c3b05eb4p+512), LIT (0x7.480c4e3db209ec7dc1e2c9553d94p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f27794c3b05eb5p+512), LIT (0x7.480c4e3db209ec7dc1e2c9553d98p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f27794c3b05eb4p+512), LIT (0x7.480c4e3db209ec7dc1e2c9553d94p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f27794c3b05eb5p+512), LIT (0x7.480c4e3db209ec7dc1e2c9553d98p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x1.19435caffa9f87973a2c8fcfdd98p+512), LIT (0x7.480c4e3db20a055a03fc06b13f18p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f87973a2c8fcfdd98p+512), LIT (0x7.480c4e3db20a055a03fc06b13f1cp+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f87973a2c8fcfdd98p+512), LIT (0x7.480c4e3db20a055a03fc06b13f18p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f87973a2c8fcfdd99p+512), LIT (0x7.480c4e3db20a055a03fc06b13f1cp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020 + 0xf.fffffp+124 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x7.fffff80000001fffffe0000000bcp-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x7.fffff80000001fffffe0000000cp-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff78p+508), LIT (0x7.fffff80000001fffffe0000000bcp-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbfffffffffffff8p+508), LIT (0x7.fffff80000001fffffe0000000cp-388), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + +0 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x0p+0), { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x4p-1076 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x4p-1076), { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x2.000000000000040000000000004cp-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x2.000000000000040000000000004cp-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x2.000000000000040000000000004cp-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x2.000000000000040000000000004ep-1588), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x4p-16448 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x4p-16448), { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x4p-16496 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x4p-16496), { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x8.8p-8192 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x8.8p-8192), { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x4.40000000000008800000000000ap-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x4.40000000000008800000000000ap-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x4.40000000000008800000000000ap-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x4.40000000000008800000000000a4p-8704), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x8p+16380 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x8p-152 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x8p-152), { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x4.0000000000000800000000000098p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x4.0000000000000800000000000098p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x4.0000000000000800000000000098p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x4.000000000000080000000000009cp-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x8p-16448 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x8p-16448), { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0xf.8p+16380 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0xf.8p+16380), { LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.19435caffa9f88803bb657861ecdp+512), LIT (0x7.480c4e3db209e2319866075d4f78p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f88803bb657861ecep+512), LIT (0x7.480c4e3db209e2319866075d4f78p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f88803bb657861ecdp+512), LIT (0x7.480c4e3db209e2319866075d4f78p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f88803bb657861ecep+512), LIT (0x7.480c4e3db209e2319866075d4f7cp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x1.19435caffa9f8924fe4e23a59daep+512), LIT (0x7.480c4e3db209fb0dda7f44b950ecp+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f8924fe4e23a59dafp+512), LIT (0x7.480c4e3db209fb0dda7f44b950ecp+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f8924fe4e23a59daep+512), LIT (0x7.480c4e3db209fb0dda7f44b950ecp+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f8924fe4e23a59dafp+512), LIT (0x7.480c4e3db209fb0dda7f44b950fp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0xf.fffffp+124 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x7.fffff80000000ffffff00000012cp-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x7.fffff80000000ffffff00000013p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdd8p+508), LIT (0x7.fffff80000000ffffff00000012cp-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffdep+508), LIT (0x7.fffff80000000ffffff00000013p-388), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + +0 i", LIT (0xf.fffffp+124), LIT (0x0p+0), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x1p+0 i", LIT (0xf.fffffp+124), LIT (0x1p+0), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x8.0000040000030000028000023p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x8.0000040000030000028000023p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x8.0000040000030000028000023p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x8.0000040000030000028000023008p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x4p-1076 i", LIT (0xf.fffffp+124), LIT (0x4p-1076), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x2.000001000000c00000a000008cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x2.000001000000c00000a000008cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x2.000001000000c00000a000008cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x2.000001000000c00000a000008c02p-1140), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x4p-16448 i", LIT (0xf.fffffp+124), LIT (0x4p-16448), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x4p-16496 i", LIT (0xf.fffffp+124), LIT (0x4p-16496), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x8.8p-512 i", LIT (0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x4.400002200001980001540001298p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.400002200001980001540001298p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x4.400002200001980001540001298p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.4000022000019800015400012984p-576), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x8.8p-8192 i", LIT (0xf.fffffp+124), LIT (0x8.8p-8192), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x4.400002200001980001540001298p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.400002200001980001540001298p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x4.400002200001980001540001298p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.4000022000019800015400012984p-8256), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x8p+1020 i", LIT (0xf.fffffp+124), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x8p+16380 i", LIT (0xf.fffffp+124), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffffffffffffffffcp+8188), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x8p-152 i", LIT (0xf.fffffp+124), LIT (0x8p-152), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x4.00000200000180000140000118p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.00000200000180000140000118p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x4.00000200000180000140000118p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.0000020000018000014000011804p-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0x8p-16448 i", LIT (0xf.fffffp+124), LIT (0x8p-16448), { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff5ff8p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0xe.7e0c2p+116 i", LIT (0xf.fffffp+124), LIT (0xe.7e0c2p+116), { LIT (0x1.000019c0e5da25586e536f88f332p+64), LIT (0x7.3f055562b51cd3bfc904f1d6ae18p+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da25586e536f88f332p+64), LIT (0x7.3f055562b51cd3bfc904f1d6ae1cp+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da25586e536f88f332p+64), LIT (0x7.3f055562b51cd3bfc904f1d6ae18p+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da25586e536f88f333p+64), LIT (0x7.3f055562b51cd3bfc904f1d6ae1cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0xf.8p+16380 i", LIT (0xf.fffffp+124), LIT (0xf.8p+16380), { LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e04p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), LIT (0xb.22b202b460e1ba2ef0fc9912e048p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.fffffp+124), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb3p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), LIT (0xb.504f333f9de61b045b0b9cbfbb38p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0xf.fffffp+124), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb8698p+508), LIT (0xb.504f333f9de631a4f9721bfb8698p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb86ap+508), LIT (0xb.504f333f9de631a4f9721bfb86ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124 + 0xf.fffffp+124 i", LIT (0xf.fffffp+124), LIT (0xf.fffffp+124), { LIT (0x1.19435c2358f11031c99a444e91c1p+64), LIT (0x7.480c4a99abe201c363daba1d6a38p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11031c99a444e91c2p+64), LIT (0x7.480c4a99abe201c363daba1d6a38p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11031c99a444e91c1p+64), LIT (0x7.480c4a99abe201c363daba1d6a38p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11031c99a444e91c2p+64), LIT (0x7.480c4a99abe201c363daba1d6a3cp+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fp+1020 + +0 i", LIT (0xf.fp+1020), LIT (0x0p+0), { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fp+1020 + 0x8.8p-512 i", LIT (0xf.fp+1020), LIT (0x8.8p-512), { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x4.422199552a8cb654be740b2b7d1cp-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x4.422199552a8cb654be740b2b7d2p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x4.422199552a8cb654be740b2b7d1cp-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+508), LIT (0x4.422199552a8cb654be740b2b7d2p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fp+1020 + 0x8p-152 i", LIT (0xf.fp+1020), LIT (0x8p-152), { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x4.0201814118fce7d749d6a119df28p-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x4.0201814118fce7d749d6a119df2cp-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+508), LIT (0x4.0201814118fce7d749d6a119df28p-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+508), LIT (0x4.0201814118fce7d749d6a119df2cp-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fp+124 + 0x8.8p-64 i", LIT (0xf.fp+124), LIT (0x8.8p-64), { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+60), LIT (0x4.422199552a8cb654be740b2b7d1cp-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+60), LIT (0x4.422199552a8cb654be740b2b7d2p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+60), LIT (0x4.422199552a8cb654be740b2b7d1cp-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+60), LIT (0x4.422199552a8cb654be740b2b7d2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fp+16380 + +0 i", LIT (0xf.fp+16380), LIT (0x0p+0), { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+8188), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fp+16380 + 0x4p-1076 i", LIT (0xf.fp+16380), LIT (0x4p-1076), { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x2.0100c0a08c7e73eba4eb508cef94p-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x2.0100c0a08c7e73eba4eb508cef96p-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x2.0100c0a08c7e73eba4eb508cef94p-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+8188), LIT (0x2.0100c0a08c7e73eba4eb508cef96p-9268), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fp+16380 + 0x8.8p-8192 i", LIT (0xf.fp+16380), LIT (0x8.8p-8192), { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x4.422199552a8cb654be740b2b7d1cp-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x4.422199552a8cb654be740b2b7d2p-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x4.422199552a8cb654be740b2b7d1cp-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+8188), LIT (0x4.422199552a8cb654be740b2b7d2p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fp+16380 + 0x8p-152 i", LIT (0xf.fp+16380), LIT (0x8p-152), { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x4.0201814118fce7d749d6a119df28p-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x4.0201814118fce7d749d6a119df2cp-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e3153p+8188), LIT (0x4.0201814118fce7d749d6a119df28p-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e31538p+8188), LIT (0x4.0201814118fce7d749d6a119df2cp-8344), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0 - 0x8p-152 i", LIT (-0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0 + 0x8p-152 i", LIT (-0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p+0 - 0x4p-128 i", LIT (-0x1p+0), LIT (-0x4p-128), { LIT (0x1.fffff8p-128), LIT (-0x1.000002p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-128), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffff8p-128), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-128), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p+0 + +0 i", LIT (-0x1p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p+0 + 0x4p-128 i", LIT (-0x1p+0), LIT (0x4p-128), { LIT (0x1.fffff8p-128), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-128), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffff8p-128), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-128), LIT (0x1.000002p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (0xe.55ec7p-4), LIT (-0x1.ac950cp+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec8p-4), LIT (-0x1.ac950cp+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7p-4), LIT (-0x1.ac950ap+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec8p-4), LIT (-0x1.ac950ap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p+0 + 0x3p+0 i", LIT (-0x2p+0), LIT (0x3p+0), { LIT (0xe.55ec7p-4), LIT (0x1.ac950ap+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec8p-4), LIT (0x1.ac950cp+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7p-4), LIT (0x1.ac950ap+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec8p-4), LIT (0x1.ac950cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.000008p-128 - 0x4.000008p-128 i", LIT (-0x4.000008p-128), LIT (-0x4.000008p-128), { LIT (0xe.9018ap-68), LIT (-0x2.3286bcp-64), ERRNO_UNCHANGED }, { LIT (0xe.9018bp-68), LIT (-0x2.3286bcp-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ap-68), LIT (-0x2.3286b8p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018bp-68), LIT (-0x2.3286b8p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.15ca1p+0 - 0x8p-152 i", LIT (-0x4.15ca1p+0), LIT (-0x8p-152), { LIT (0x0p+0), LIT (-0x2.056b3p+0), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x2.056b2cp+0), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (-0x2.056b2cp+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), LIT (-0x2.056b2cp+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.827738p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.827738p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12eep-4), LIT (-0x1.02a878p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12eep-4), LIT (-0x1.02a876p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12eep-4), LIT (-0x1.02a876p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12efp-4), LIT (-0x1.02a876p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.82774p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82774p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12eep-4), LIT (-0x1.02a878p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12eep-4), LIT (-0x1.02a878p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12eep-4), LIT (-0x1.02a876p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12efp-4), LIT (-0x1.02a876p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.d01448p-4 - 0x7.c19148p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2p+0), LIT (-0x2.020118p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d4p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.d01448p-4 - 0x7.c1915p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c1915p+0), { LIT (0x1.ee74d2p+0), LIT (-0x2.020118p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d4p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d4p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4.d0144p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2p+0), LIT (-0x2.020118p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d4p+0), LIT (-0x2.020114p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x7.915fa8p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fa8p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c3257p-4), LIT (-0x1.3392aep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257p-4), LIT (-0x1.3392aep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257p-4), LIT (-0x1.3392acp+0), ERRNO_UNCHANGED }, { LIT (0xf.c3258p-4), LIT (-0x1.3392acp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x7.915fbp-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fbp-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c3257p-4), LIT (-0x1.3392aep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257p-4), LIT (-0x1.3392aep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257p-4), LIT (-0x1.3392acp+0), ERRNO_UNCHANGED }, { LIT (0xf.c3258p-4), LIT (-0x1.3392acp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152 - 0 i", LIT (-0x8p-152), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.d413dp-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413ccp-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413ccp-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413ccp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152 - 0x1.818bccp+0 i", LIT (-0x8p-152), LIT (-0x1.818bccp+0), { LIT (0xd.e25fbp-4), LIT (-0xd.e25fcp-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fcp-4), LIT (-0xd.e25fcp-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fbp-4), LIT (-0xd.e25fbp-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fcp-4), LIT (-0xd.e25fbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152 - 0x8p-152 i", LIT (-0x8p-152), LIT (-0x8p-152), { LIT (0x1.49852ep-76), LIT (-0x3.1b8844p-76), ERRNO_UNCHANGED }, { LIT (0x1.49853p-76), LIT (-0x3.1b8844p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852ep-76), LIT (-0x3.1b884p-76), ERRNO_UNCHANGED }, { LIT (0x1.49853p-76), LIT (-0x3.1b884p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152 + 0x8p-152 i", LIT (-0x8p-152), LIT (0x8p-152), { LIT (0x1.49852ep-76), LIT (0x3.1b884p-76), ERRNO_UNCHANGED }, { LIT (0x1.49853p-76), LIT (0x3.1b8844p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852ep-76), LIT (0x3.1b884p-76), ERRNO_UNCHANGED }, { LIT (0x1.49853p-76), LIT (0x3.1b8844p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xd.e1d5fp-4 - 0x1.054226p+4 i", LIT (-0xd.e1d5fp-4), LIT (-0x1.054226p+4), { LIT (0x2.c84e98p+0), LIT (-0x2.ef2934p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e98p+0), LIT (-0x2.ef293p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e98p+0), LIT (-0x2.ef293p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e9cp+0), LIT (-0x2.ef293p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xe.6432ap-4 + 0xe.8175p-4 i", LIT (-0xe.6432ap-4), LIT (0xe.8175p-4), { LIT (0x6.f3d48p-4), LIT (0x1.0b0f82p+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d48p-4), LIT (0x1.0b0f84p+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d48p-4), LIT (0x1.0b0f82p+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d488p-4), LIT (0x1.0b0f84p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xe.735dbp+0 - 0x5.26cb98p+40 i", LIT (-0xe.735dbp+0), LIT (-0x5.26cb98p+40), { LIT (0x1.9adc1cp+20), LIT (-0x1.9adc1ep+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1ep+20), LIT (-0x1.9adc1ep+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1cp+20), LIT (-0x1.9adc1cp+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1ep+20), LIT (-0x1.9adc1cp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fffffp+124 + +0 i", LIT (-0xf.fffffp+124), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.fffffp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffffp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fffffp+124 + 0x8p-152 i", LIT (-0xf.fffffp+124), LIT (0x8p-152), { LIT (0x0p+0), LIT (0xf.fffffp+60), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.fffffp+60), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.fffffp+60), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), LIT (0x1p+64), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fp+124 + 0x8.8p-64 i", LIT (-0xf.fp+124), LIT (0x8.8p-64), { LIT (0x4.422198p-128), LIT (0xf.f7fdfp+60), ERRNO_UNCHANGED }, { LIT (0x4.422198p-128), LIT (0xf.f7fep+60), ERRNO_UNCHANGED }, { LIT (0x4.422198p-128), LIT (0xf.f7fdfp+60), ERRNO_UNCHANGED }, { LIT (0x4.4221ap-128), LIT (0xf.f7fep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 - 0x1p+0 i", LIT (0x0p+0), LIT (-0x1p+0), { LIT (0xb.504f3p-4), LIT (-0xb.504f4p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f3p-4), LIT (-0xb.504f3p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f3p-4), LIT (-0xb.504f3p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f4p-4), LIT (-0xb.504f3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0x2p+0 i", LIT (0x0p+0), LIT (0x2p+0), { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0 + 0xf.fffffp+124 i", LIT (0x0p+0), LIT (0xf.fffffp+124), { LIT (0xb.504f2p+60), LIT (0xb.504f2p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f3p+60), LIT (0xb.504f3p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2p+60), LIT (0xb.504f2p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f3p+60), LIT (0xb.504f3p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.d60caep+0 + 0x7.a7d468p+0 i", LIT (0x1.d60caep+0), LIT (0x7.a7d468p+0), { LIT (0x2.3409b8p+0), LIT (0x1.bcc10ap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409bcp+0), LIT (0x1.bcc10cp+0), ERRNO_UNCHANGED }, { LIT (0x2.3409b8p+0), LIT (0x1.bcc10ap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409bcp+0), LIT (0x1.bcc10cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.f9610ap+4 + 0x9.87716p+4 i", LIT (0x1.f9610ap+4), LIT (0x9.87716p+4), { LIT (0x9.ad503p+0), LIT (0x7.e0b14p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad503p+0), LIT (0x7.e0b148p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad503p+0), LIT (0x7.e0b14p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad504p+0), LIT (0x7.e0b148p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0 - 0x4p-128 i", LIT (0x1p+0), LIT (-0x4p-128), { LIT (0x1p+0), LIT (-0x2p-128), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x2p-128), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x1.fffff8p-128), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (-0x1.fffff8p-128), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0 + 0x4p-128 i", LIT (0x1p+0), LIT (0x4p-128), { LIT (0x1p+0), LIT (0x1.fffff8p-128), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x2p-128), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.fffff8p-128), UNDERFLOW_EXCEPTION }, { LIT (0x1.000002p+0), LIT (0x2p-128), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+4 - 0x1.ep+4 i", LIT (0x1p+4), LIT (-0x1.ep+4), { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-148 + 0x2p-148 i", LIT (0x2p-148), LIT (0x2p-148), { LIT (0x6.37108p-76), LIT (0x2.930a5cp-76), ERRNO_UNCHANGED }, { LIT (0x6.371088p-76), LIT (0x2.930a6p-76), ERRNO_UNCHANGED }, { LIT (0x6.37108p-76), LIT (0x2.930a5cp-76), ERRNO_UNCHANGED }, { LIT (0x6.371088p-76), LIT (0x2.930a6p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.f768f4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326dap+0), LIT (0xf.3d923p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dcp+0), LIT (0xf.3d923p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dap+0), LIT (0xf.3d923p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dcp+0), LIT (0xf.3d924p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.f768f4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dcp+0), LIT (0xf.3d924p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dcp+0), LIT (0xf.3d924p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dcp+0), LIT (0xf.3d924p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dep+0), LIT (0xf.3d925p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.f768f8p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326dap+0), LIT (0xf.3d923p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dcp+0), LIT (0xf.3d923p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dap+0), LIT (0xf.3d923p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dcp+0), LIT (0xf.3d924p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.f768f8p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dcp+0), LIT (0xf.3d924p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dcp+0), LIT (0xf.3d924p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dcp+0), LIT (0xf.3d924p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dep+0), LIT (0xf.3d925p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.000008p-128 + 0x4.000008p-128 i", LIT (0x4.000008p-128), LIT (0x4.000008p-128), { LIT (0x2.3286b8p-64), LIT (0xe.9018ap-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bcp-64), LIT (0xe.9018bp-68), ERRNO_UNCHANGED }, { LIT (0x2.3286b8p-64), LIT (0xe.9018ap-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bcp-64), LIT (0xe.9018bp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-52 + 0x8p-152 i", LIT (0x4p-52), LIT (0x8p-152), { LIT (0x8p-28), LIT (0x7.fffff8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x7.fffff8p-128), ERRNO_UNCHANGED }, { LIT (0x8.00001p-28), LIT (0x8p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.39e238p+0 - 0x4.576278p-4 i", LIT (0x5.39e238p+0), LIT (-0x4.576278p-4), { LIT (0x2.496e34p+0), LIT (-0xf.2fef6p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e34p+0), LIT (-0xf.2fef6p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e34p+0), LIT (-0xf.2fef5p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e38p+0), LIT (-0xf.2fef5p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.9cc21p-4 - 0x1.fb1ec8p+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec8p+0), { LIT (0x1.163c66p+0), LIT (-0xe.94bd4p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c68p+0), LIT (-0xe.94bd4p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c66p+0), LIT (-0xe.94bd3p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c68p+0), LIT (-0xe.94bd3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.9cc21p-4 - 0x1.fb1ecap+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ecap+0), { LIT (0x1.163c66p+0), LIT (-0xe.94bd5p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c68p+0), LIT (-0xe.94bd4p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c66p+0), LIT (-0xe.94bd4p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c68p+0), LIT (-0xe.94bd4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7.7p+4 + 0x7.8p+4 i", LIT (0x7.7p+4), LIT (0x7.8p+4), { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p+124 + 0x8p-152 i", LIT (0x8p+124), LIT (0x8p-152), { LIT (0xb.504f3p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f3p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f3p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f4p+60), LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 - 0x8p-152 i", LIT (0x8p-152), LIT (-0x8p-152), { LIT (0x3.1b884p-76), LIT (-0x1.49853p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b8844p-76), LIT (-0x1.49853p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884p-76), LIT (-0x1.49852ep-76), ERRNO_UNCHANGED }, { LIT (0x3.1b8844p-76), LIT (-0x1.49852ep-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x2.d413ccp-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413ccp-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413ccp-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413dp-76), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + 0x4.000008p-128 i", LIT (0x8p-152), LIT (0x4.000008p-128), { LIT (0x1.6a09e8p-64), LIT (0x1.6a09e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eap-64), LIT (0x1.6a09e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e8p-64), LIT (0x1.6a09e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eap-64), LIT (0x1.6a09e8p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + 0x4.00001p-128 i", LIT (0x8p-152), LIT (0x4.00001p-128), { LIT (0x1.6a09eap-64), LIT (0x1.6a09e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eap-64), LIT (0x1.6a09e8p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eap-64), LIT (0x1.6a09e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09ecp-64), LIT (0x1.6a09e8p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + 0x7.8p-148 i", LIT (0x8p-152), LIT (0x7.8p-148), { LIT (0x8.02213p-76), LIT (0x7.7e0158p-76), ERRNO_UNCHANGED }, { LIT (0x8.02214p-76), LIT (0x7.7e016p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213p-76), LIT (0x7.7e0158p-76), ERRNO_UNCHANGED }, { LIT (0x8.02214p-76), LIT (0x7.7e016p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + 0x8p+124 i", LIT (0x8p-152), LIT (0x8p+124), { LIT (0x8p+60), LIT (0x7.fffff8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x7.fffff8p+60), ERRNO_UNCHANGED }, { LIT (0x8.00001p+60), LIT (0x8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + 0x8p-152 i", LIT (0x8p-152), LIT (0x8p-152), { LIT (0x3.1b884p-76), LIT (0x1.49852ep-76), ERRNO_UNCHANGED }, { LIT (0x3.1b8844p-76), LIT (0x1.49853p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884p-76), LIT (0x1.49852ep-76), ERRNO_UNCHANGED }, { LIT (0x3.1b8844p-76), LIT (0x1.49853p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152 + 0xf.fffffp+124 i", LIT (0x8p-152), LIT (0xf.fffffp+124), { LIT (0xb.504f2p+60), LIT (0xb.504f2p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f3p+60), LIT (0xb.504f3p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2p+60), LIT (0xb.504f2p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f3p+60), LIT (0xb.504f3p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.0cf782p+0), LIT (0x9.84953p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf782p+0), LIT (0x9.84954p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf782p+0), LIT (0x9.84953p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf784p+0), LIT (0x9.84954p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.22982p-4 + 0xd.849ecp-4 i", LIT (0xe.22982p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00ap+0), LIT (0x6.964238p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ap+0), LIT (0x6.96424p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ap+0), LIT (0x6.964238p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00cp+0), LIT (0x6.96424p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.22983p-4 + 0xd.849ecp-4 i", LIT (0xe.22983p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00ap+0), LIT (0x6.964238p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ap+0), LIT (0x6.96424p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ap+0), LIT (0x6.964238p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00cp+0), LIT (0x6.96424p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.a24adp+28 + 0x8.0f148p+36 i", LIT (0xf.a24adp+28), LIT (0x8.0f148p+36), { LIT (0x8.0f544p+16), LIT (0x7.ffc0a8p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f545p+16), LIT (0x7.ffc0bp+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544p+16), LIT (0x7.ffc0a8p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f545p+16), LIT (0x7.ffc0bp+16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124 + +0 i", LIT (0xf.fffffp+124), LIT (0x0p+0), { LIT (0xf.fffffp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p+64), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124 + 0x1p+0 i", LIT (0xf.fffffp+124), LIT (0x1p+0), { LIT (0xf.fffffp+60), LIT (0x8p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffffp+60), LIT (0x8p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffffp+60), LIT (0x8p-68), ERRNO_UNCHANGED }, { LIT (0x1p+64), LIT (0x8.00001p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124 + 0x8p-152 i", LIT (0xf.fffffp+124), LIT (0x8p-152), { LIT (0xf.fffffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+64), LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124 + 0xe.7e0c2p+116 i", LIT (0xf.fffffp+124), LIT (0xe.7e0c2p+116), { LIT (0x1.000018p+64), LIT (0x7.3f055p+52), ERRNO_UNCHANGED }, { LIT (0x1.00001ap+64), LIT (0x7.3f0558p+52), ERRNO_UNCHANGED }, { LIT (0x1.000018p+64), LIT (0x7.3f055p+52), ERRNO_UNCHANGED }, { LIT (0x1.00001ap+64), LIT (0x7.3f0558p+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124 + 0xf.fffffp+124 i", LIT (0xf.fffffp+124), LIT (0xf.fffffp+124), { LIT (0x1.19435cp+64), LIT (0x7.480c48p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435cp+64), LIT (0x7.480c48p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435cp+64), LIT (0x7.480c48p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435ep+64), LIT (0x7.480c5p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fp+124 + 0x8.8p-64 i", LIT (0xf.fp+124), LIT (0x8.8p-64), { LIT (0xf.f7fdfp+60), LIT (0x4.422198p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fep+60), LIT (0x4.422198p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfp+60), LIT (0x4.422198p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fep+60), LIT (0x4.4221ap-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0 - 0x4.0000000000004p-1024 i", LIT (-0x0p+0), LIT (-0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcdp-512), LIT (-0x1.6a09e667f3bcep-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdp-512), LIT (-0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdp-512), LIT (-0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcep-512), LIT (-0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0 - 0x4p-1076 i", LIT (-0x0p+0), LIT (-0x4p-1076), { LIT (0x5.a827999fcef3p-540), LIT (-0x5.a827999fcef34p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef34p-540), LIT (-0x5.a827999fcef34p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3p-540), LIT (-0x5.a827999fcef3p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef34p-540), LIT (-0x5.a827999fcef3p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0 - 0x8p-152 i", LIT (-0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0 + 0x8p-152 i", LIT (-0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.65c7ac7c97a25p-176 - 0x8p-152 i", LIT (-0x1.65c7ac7c97a25p-176), LIT (-0x8p-152), { LIT (0x1.ffffffd3470a7p-76), LIT (-0x2.0000002cb8f5ap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a7p-76), LIT (-0x2.0000002cb8f5ap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a7p-76), LIT (-0x2.0000002cb8f58p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a8p-76), LIT (-0x2.0000002cb8f58p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.9edb24c83e22cp-172 - 0x8p-152 i", LIT (-0x1.9edb24c83e22cp-172), LIT (-0x8p-152), { LIT (0x1.fffffcc249b9p-76), LIT (-0x2.0000033db64c4p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b91p-76), LIT (-0x2.0000033db64c4p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b9p-76), LIT (-0x2.0000033db64c2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b91p-76), LIT (-0x2.0000033db64c2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0 - 0x4p-1024 i", LIT (-0x1p+0), LIT (-0x4p-1024), { LIT (0x1.ffffffffffffcp-1024), LIT (-0x1.0000000000001p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffffcp-1024), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0 - 0x4p-128 i", LIT (-0x1p+0), LIT (-0x4p-128), { LIT (0x1.fffffffffffffp-128), LIT (-0x1.0000000000001p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0 - 0x8p-972 i", LIT (-0x1p+0), LIT (-0x8p-972), { LIT (0x3.ffffffffffffep-972), LIT (-0x1.0000000000001p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-972), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0 + +0 i", LIT (-0x1p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0 + 0x4p-1024 i", LIT (-0x1p+0), LIT (0x4p-1024), { LIT (0x1.ffffffffffffcp-1024), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffffcp-1024), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), LIT (0x1.0000000000001p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0 + 0x4p-128 i", LIT (-0x1p+0), LIT (0x4p-128), { LIT (0x1.fffffffffffffp-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0 + 0x8p-972 i", LIT (-0x1p+0), LIT (0x8p-972), { LIT (0x3.ffffffffffffep-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.927275f6febb6p-184 + 0x8p-152 i", LIT (-0x2.927275f6febb6p-184), LIT (0x8p-152), { LIT (0x1.ffffffffadb1bp-76), LIT (0x2.00000000524e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1bp-76), LIT (0x2.00000000524e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1bp-76), LIT (0x2.00000000524e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1cp-76), LIT (0x2.00000000524e6p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (0xe.55ec7a5ee268p-4), LIT (-0x1.ac950b37094a6p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee2688p-4), LIT (-0x1.ac950b37094a6p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee268p-4), LIT (-0x1.ac950b37094a5p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee2688p-4), LIT (-0x1.ac950b37094a5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p+0 + 0x3p+0 i", LIT (-0x2p+0), LIT (0x3p+0), { LIT (0xe.55ec7a5ee268p-4), LIT (0x1.ac950b37094a5p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee2688p-4), LIT (0x1.ac950b37094a6p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee268p-4), LIT (0x1.ac950b37094a5p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee2688p-4), LIT (0x1.ac950b37094a6p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.0000000000004p-1024 - 0 i", LIT (-0x4.0000000000004p-1024), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000002p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.0000000000004p-1024 - 0x4.0000000000004p-1024 i", LIT (-0x4.0000000000004p-1024), LIT (-0x4.0000000000004p-1024), { LIT (0xe.90189c7b64148p-516), LIT (-0x2.3286b95ff53f4p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b64148p-516), LIT (-0x2.3286b95ff53f2p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b64148p-516), LIT (-0x2.3286b95ff53f2p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6415p-516), LIT (-0x2.3286b95ff53f2p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.0000000000004p-1024 - 0x8p-152 i", LIT (-0x4.0000000000004p-1024), LIT (-0x8p-152), { LIT (0x1.fffffffffffffp-76), LIT (-0x2.0000000000002p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.000008p-128 - 0x4.000008p-128 i", LIT (-0x4.000008p-128), LIT (-0x4.000008p-128), { LIT (0xe.9018ab0b7ca9p-68), LIT (-0x2.3286bb927bf76p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca98p-68), LIT (-0x2.3286bb927bf76p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca9p-68), LIT (-0x2.3286bb927bf74p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca98p-68), LIT (-0x2.3286bb927bf74p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.15ca1p+0 - 0x8p-152 i", LIT (-0x4.15ca1p+0), LIT (-0x8p-152), { LIT (0x1.faa35a1b5eb22p-152), LIT (-0x2.056b2cd84232p+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb22p-152), LIT (-0x2.056b2cd84231ep+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb22p-152), LIT (-0x2.056b2cd84231ep+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb23p-152), LIT (-0x2.056b2cd84231ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.827738p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.827738p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee6cd64cb8p-4), LIT (-0x1.02a876fc90521p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cb8p-4), LIT (-0x1.02a876fc9052p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cb8p-4), LIT (-0x1.02a876fc9052p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64ccp-4), LIT (-0x1.02a876fc9052p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.82773b736291p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82773b736291p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee5f5a368p-4), LIT (-0x1.02a8770c69a39p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a368p-4), LIT (-0x1.02a8770c69a39p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a368p-4), LIT (-0x1.02a8770c69a38p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a3688p-4), LIT (-0x1.02a8770c69a38p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.82774p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82774p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee4d932328p-4), LIT (-0x1.02a877214e9ffp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d932328p-4), LIT (-0x1.02a877214e9fep+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d932328p-4), LIT (-0x1.02a877214e9fep+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93233p-4), LIT (-0x1.02a877214e9fep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.d0144005d7af4p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144005d7af4p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2657d0ap+0), LIT (-0x2.0201143f4f66ep+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0ap+0), LIT (-0x2.0201143f4f66ep+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0ap+0), LIT (-0x2.0201143f4f66cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a1p+0), LIT (-0x2.0201143f4f66cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.d01448p-4 - 0x7.c19148p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2559bb4bp+0), LIT (-0x2.0201144fd1746p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4bp+0), LIT (-0x2.0201144fd1744p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4bp+0), LIT (-0x2.0201144fd1744p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4cp+0), LIT (-0x2.0201144fd1744p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.d01448p-4 - 0x7.c1915p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c1915p+0), { LIT (0x1.ee74d35e7dfe1p+0), LIT (-0x2.0201154ea0e06p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe2p+0), LIT (-0x2.0201154ea0e04p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1p+0), LIT (-0x2.0201154ea0e04p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe2p+0), LIT (-0x2.0201154ea0e04p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4.d0144p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d26588ab7p+0), LIT (-0x2.0201143f434fcp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab8p+0), LIT (-0x2.0201143f434fap+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7p+0), LIT (-0x2.0201143f434fap+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab8p+0), LIT (-0x2.0201143f434fap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076 - 0 i", LIT (-0x4p-1076), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076 - 0x4p-1076 i", LIT (-0x4p-1076), LIT (-0x4p-1076), { LIT (0x3.a406271ed905p-540), LIT (-0x8.ca1ae57fd4fc8p-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed905p-540), LIT (-0x8.ca1ae57fd4fc8p-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed905p-540), LIT (-0x8.ca1ae57fd4fcp-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed9052p-540), LIT (-0x8.ca1ae57fd4fcp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076 - 0x8p-152 i", LIT (-0x4p-1076), LIT (-0x8p-152), { LIT (0x1.fffffffffffffp-76), LIT (-0x2.0000000000002p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.31291c9fdae04p-160 - 0x8p-152 i", LIT (-0x7.31291c9fdae04p-160), LIT (-0x8p-152), { LIT (0x1.ff1a0ead4f6b1p-76), LIT (-0x2.00e658c5f71cep-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b1p-76), LIT (-0x2.00e658c5f71ccp-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b1p-76), LIT (-0x2.00e658c5f71ccp-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b2p-76), LIT (-0x2.00e658c5f71ccp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.915fa8p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fa8p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c32571e2b8eap-4), LIT (-0x1.3392ad649c586p+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8eap-4), LIT (-0x1.3392ad649c585p+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8eap-4), LIT (-0x1.3392ad649c585p+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea8p-4), LIT (-0x1.3392ad649c585p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.915fafbe9f588p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fafbe9f588p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c325704e2c618p-4), LIT (-0x1.3392ad8372656p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c62p-4), LIT (-0x1.3392ad8372656p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c618p-4), LIT (-0x1.3392ad8372655p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c62p-4), LIT (-0x1.3392ad8372655p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.915fbp-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fbp-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c3257040d54f8p-4), LIT (-0x1.3392ad8476b46p+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54f8p-4), LIT (-0x1.3392ad8476b46p+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54f8p-4), LIT (-0x1.3392ad8476b45p+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d55p-4), LIT (-0x1.3392ad8476b45p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8.ec8932bf5603p-172 + 0x8p-152 i", LIT (-0x8.ec8932bf5603p-172), LIT (0x8p-152), { LIT (0x1.ffffee26edea2p-76), LIT (0x2.000011d912b52p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea2p-76), LIT (0x2.000011d912b52p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea2p-76), LIT (0x2.000011d912b52p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea3p-76), LIT (0x2.000011d912b54p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152 - 0 i", LIT (-0x8p-152), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.d413cccfe779ap-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779ap-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe7798p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe7798p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152 - 0x1.818bccp+0 i", LIT (-0x8p-152), LIT (-0x1.818bccp+0), { LIT (0xd.e25fb98f83908p-4), LIT (-0xd.e25fb98f8391p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f83908p-4), LIT (-0xd.e25fb98f83908p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f83908p-4), LIT (-0xd.e25fb98f83908p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8391p-4), LIT (-0xd.e25fb98f83908p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152 - 0x4.0000000000004p-1024 i", LIT (-0x8p-152), LIT (-0x4.0000000000004p-1024), { LIT (0xb.504f333f9de68p-952), LIT (-0x2.d413cccfe779ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de7p-952), LIT (-0x2.d413cccfe779ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p-952), LIT (-0x2.d413cccfe7798p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de7p-952), LIT (-0x2.d413cccfe7798p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152 - 0x4p-1076 i", LIT (-0x8p-152), LIT (-0x4p-1076), { LIT (0xb.504f333f9de6p-1004), LIT (-0x2.d413cccfe779ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p-1004), LIT (-0x2.d413cccfe779ap-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p-1004), LIT (-0x2.d413cccfe7798p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p-1004), LIT (-0x2.d413cccfe7798p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152 - 0x8p-152 i", LIT (-0x8p-152), LIT (-0x8p-152), { LIT (0x1.49852f983efddp-76), LIT (-0x3.1b884327ab806p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efddp-76), LIT (-0x3.1b884327ab806p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efddp-76), LIT (-0x3.1b884327ab804p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdep-76), LIT (-0x3.1b884327ab804p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152 + 0x8p-152 i", LIT (-0x8p-152), LIT (0x8p-152), { LIT (0x1.49852f983efddp-76), LIT (0x3.1b884327ab804p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efddp-76), LIT (0x3.1b884327ab806p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efddp-76), LIT (0x3.1b884327ab804p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdep-76), LIT (0x3.1b884327ab806p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x9.0a61a7b482d28p-168 - 0x8p-152 i", LIT (-0x9.0a61a7b482d28p-168), LIT (-0x8p-152), { LIT (0x1.fffedeb41cc4ep-76), LIT (-0x2.0001214c86b1cp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4ep-76), LIT (-0x2.0001214c86b1ap-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4ep-76), LIT (-0x2.0001214c86b1ap-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4fp-76), LIT (-0x2.0001214c86b1ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xb.e2bc1cd6eaa7p-180 + 0x8p-152 i", LIT (-0xb.e2bc1cd6eaa7p-180), LIT (0x8p-152), { LIT (0x1.ffffffe83a87cp-76), LIT (0x2.00000017c5782p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87cp-76), LIT (0x2.00000017c5784p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87cp-76), LIT (0x2.00000017c5782p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87dp-76), LIT (0x2.00000017c5784p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xd.e1d5fp-4 - 0x1.054226p+4 i", LIT (-0xd.e1d5fp-4), LIT (-0x1.054226p+4), { LIT (0x2.c84e99e2df484p+0), LIT (-0x2.ef2930261e97ep+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484p+0), LIT (-0x2.ef2930261e97ep+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484p+0), LIT (-0x2.ef2930261e97cp+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df486p+0), LIT (-0x2.ef2930261e97cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xe.6432ap-4 + 0xe.8175p-4 i", LIT (-0xe.6432ap-4), LIT (0xe.8175p-4), { LIT (0x6.f3d482a6e0bp-4), LIT (0x1.0b0f83813dfbbp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b04p-4), LIT (0x1.0b0f83813dfbcp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0bp-4), LIT (0x1.0b0f83813dfbbp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b04p-4), LIT (0x1.0b0f83813dfbcp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xe.735dbp+0 - 0x5.26cb98p+40 i", LIT (-0xe.735dbp+0), LIT (-0x5.26cb98p+40), { LIT (0x1.9adc1d93b4e9bp+20), LIT (-0x1.9adc1d93b96a4p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9bp+20), LIT (-0x1.9adc1d93b96a3p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9bp+20), LIT (-0x1.9adc1d93b96a3p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9cp+20), LIT (-0x1.9adc1d93b96a3p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020 + +0 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.ffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0xf.ffffffffffff8p+508), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.ffffffffffff8p+508), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.ffffffffffff8p+508), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0x1p+512), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0x4p-664), LIT (0xf.ffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x4p-664), LIT (0xf.ffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x4p-664), LIT (0xf.ffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000004p-664), LIT (0x1p+512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124 + +0 i", LIT (-0xf.fffffp+124), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.fffff7fffffd8p+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffd8p+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124 + 0x4p-1076 i", LIT (-0xf.fffffp+124), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0xf.fffff7fffffd8p+60), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.fffff7fffffep+60), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.fffff7fffffd8p+60), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0xf.fffff7fffffep+60), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124 + 0x8.8p-512 i", LIT (-0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0x4.4000022000018p-576), LIT (0xf.fffff7fffffd8p+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000018p-576), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000018p-576), LIT (0xf.fffff7fffffd8p+60), ERRNO_UNCHANGED }, { LIT (0x4.400002200001cp-576), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124 + 0x8p-152 i", LIT (-0xf.fffffp+124), LIT (0x8p-152), { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffd8p+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffd8p+60), ERRNO_UNCHANGED }, { LIT (0x4.000002000001cp-216), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fp+1020 + +0 i", LIT (-0xf.fp+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f9p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fp+1020 + 0x8.8p-512 i", LIT (-0xf.fp+1020), LIT (0x8.8p-512), { LIT (0x4.422199552a8c8p-1024), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8ccp-1024), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8c8p-1024), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8ccp-1024), LIT (0xf.f7fdfeff5f9p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fp+1020 + 0x8p-152 i", LIT (-0xf.fp+1020), LIT (0x8p-152), { LIT (0x4.0201814118fccp-664), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fdp-664), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fccp-664), LIT (0xf.f7fdfeff5f8f8p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fdp-664), LIT (0xf.f7fdfeff5f9p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fp+124 + 0x8.8p-64 i", LIT (-0xf.fp+124), LIT (0x8.8p-64), { LIT (0x4.422199552a8c8p-128), LIT (0xf.f7fdfeff5f8f8p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8ccp-128), LIT (0xf.f7fdfeff5f8f8p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8c8p-128), LIT (0xf.f7fdfeff5f8f8p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8ccp-128), LIT (0xf.f7fdfeff5f9p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0x1p+0 i", LIT (0x0p+0), LIT (-0x1p+0), { LIT (0xb.504f333f9de6p-4), LIT (-0xb.504f333f9de68p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p-4), LIT (-0xb.504f333f9de68p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p-4), LIT (-0xb.504f333f9de6p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p-4), LIT (-0xb.504f333f9de6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x2p+0 i", LIT (0x0p+0), LIT (0x2p+0), { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x4.0000000000004p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcdp-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdp-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdp-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcep-512), LIT (0x1.6a09e667f3bcep-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x4.0000000000008p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bcdp-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcep-512), LIT (0x1.6a09e667f3bcep-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdp-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcep-512), LIT (0x1.6a09e667f3bcep-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x5.a827999fcef3p-540), LIT (0x5.a827999fcef3p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef34p-540), LIT (0x5.a827999fcef34p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3p-540), LIT (0x5.a827999fcef3p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef34p-540), LIT (0x5.a827999fcef34p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x8p+1020 i", LIT (0x0p+0), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x8p-1076 i", LIT (0x0p+0), LIT (0x8p-1076), { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x0p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+508), LIT (0xb.504f333f9de68p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0 + 0xf.fffffp+124 i", LIT (0x0p+0), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b8p+60), LIT (0xb.504f2d97764b8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0221e29d5a3cdp-188 - 0x8p-152 i", LIT (0x1.0221e29d5a3cdp-188), LIT (-0x8p-152), { LIT (0x2.0000000002044p-76), LIT (-0x1.fffffffffdfbcp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000002044p-76), LIT (-0x1.fffffffffdfbcp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000002044p-76), LIT (-0x1.fffffffffdfbbp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000002046p-76), LIT (-0x1.fffffffffdfbbp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.d60caep+0 + 0x7.a7d468p+0 i", LIT (0x1.d60caep+0), LIT (0x7.a7d468p+0), { LIT (0x2.3409baa805bc8p+0), LIT (0x1.bcc10b50fddb6p+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bcap+0), LIT (0x1.bcc10b50fddb7p+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc8p+0), LIT (0x1.bcc10b50fddb6p+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bcap+0), LIT (0x1.bcc10b50fddb7p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.f9610ap+4 + 0x9.87716p+4 i", LIT (0x1.f9610ap+4), LIT (0x9.87716p+4), { LIT (0x9.ad5033142babp+0), LIT (0x7.e0b144c043868p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142babp+0), LIT (0x7.e0b144c043868p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142babp+0), LIT (0x7.e0b144c043868p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab8p+0), LIT (0x7.e0b144c04386cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 - 0x4p-1024 i", LIT (0x1p+0), LIT (-0x4p-1024), { LIT (0x1p+0), LIT (-0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000001p+0), LIT (-0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 - 0x4p-128 i", LIT (0x1p+0), LIT (-0x4p-128), { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.fffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), LIT (-0x1.fffffffffffffp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 - 0x8p-972 i", LIT (0x1p+0), LIT (-0x8p-972), { LIT (0x1p+0), LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.ffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), LIT (-0x3.ffffffffffffep-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 + 0x4p-1024 i", LIT (0x1p+0), LIT (0x4p-1024), { LIT (0x1p+0), LIT (0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000001p+0), LIT (0x2p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 + 0x4p-128 i", LIT (0x1p+0), LIT (0x4p-128), { LIT (0x1p+0), LIT (0x1.fffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.fffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 + 0x8p-972 i", LIT (0x1p+0), LIT (0x8p-972), { LIT (0x1p+0), LIT (0x3.ffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.ffffffffffffep-972), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), LIT (0x4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+4 - 0x1.ep+4 i", LIT (0x1p+4), LIT (-0x1.ep+4), { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-500 + +0 i", LIT (0x1p-500), LIT (0x0p+0), { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-500 + 0x4p-1076 i", LIT (0x1p-500), LIT (0x4p-1076), { LIT (0x4p-252), LIT (0x7.ffffffffffffcp-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x8p-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x7.ffffffffffffcp-828), ERRNO_UNCHANGED }, { LIT (0x4.0000000000004p-252), LIT (0x8p-828), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-500 + 0x8p-152 i", LIT (0x1p-500), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-148 + 0x2p-148 i", LIT (0x2p-148), LIT (0x2p-148), { LIT (0x6.3710864f57008p-76), LIT (0x2.930a5f307dfbap-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700cp-76), LIT (0x2.930a5f307dfbap-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f57008p-76), LIT (0x2.930a5f307dfbap-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700cp-76), LIT (0x2.930a5f307dfbcp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db1f30939p+0), LIT (0xf.3d9236b503fe8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f3093ap+0), LIT (0xf.3d9236b503ffp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939p+0), LIT (0xf.3d9236b503fe8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f3093ap+0), LIT (0xf.3d9236b503ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db809771dp+0), LIT (0xf.3d923d9381678p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771ep+0), LIT (0xf.3d923d9381678p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dp+0), LIT (0xf.3d923d9381678p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771ep+0), LIT (0xf.3d923d938168p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc0ba4f28p+0), LIT (0xf.3d924761f5b58p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f28p+0), LIT (0xf.3d924761f5b6p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f28p+0), LIT (0xf.3d924761f5b58p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f29p+0), LIT (0xf.3d924761f5b6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276p+0), LIT (0xf.3d92365a3345p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598277p+0), LIT (0xf.3d92365a33458p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276p+0), LIT (0xf.3d92365a3345p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598277p+0), LIT (0xf.3d92365a33458p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ap+0), LIT (0xf.3d923d38b0aep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05bp+0), LIT (0xf.3d923d38b0aep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ap+0), LIT (0xf.3d923d38b0aep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05bp+0), LIT (0xf.3d923d38b0ae8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c865p+0), LIT (0xf.3d92470724fc8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865p+0), LIT (0xf.3d92470724fc8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865p+0), LIT (0xf.3d92470724fc8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c866p+0), LIT (0xf.3d92470724fdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276p+0), LIT (0xf.3d92365a3345p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598277p+0), LIT (0xf.3d92365a33458p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276p+0), LIT (0xf.3d92365a3345p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598277p+0), LIT (0xf.3d92365a33458p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ap+0), LIT (0xf.3d923d38b0aep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05bp+0), LIT (0xf.3d923d38b0aep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ap+0), LIT (0xf.3d923d38b0aep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05bp+0), LIT (0xf.3d923d38b0ae8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c865p+0), LIT (0xf.3d92470724fc8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865p+0), LIT (0xf.3d92470724fc8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865p+0), LIT (0xf.3d92470724fc8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c866p+0), LIT (0xf.3d92470724fdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f8p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2fdd855p+0), LIT (0xf.3d9235c88f9f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd856p+0), LIT (0xf.3d9235c88f9f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855p+0), LIT (0xf.3d9235c88f9f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd856p+0), LIT (0xf.3d9235c88fap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f8p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db9144639p+0), LIT (0xf.3d923ca70d088p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db9144639p+0), LIT (0xf.3d923ca70d088p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db9144639p+0), LIT (0xf.3d923ca70d088p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463ap+0), LIT (0xf.3d923ca70d09p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.f768f8p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc1c51e43p+0), LIT (0xf.3d9246758157p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e43p+0), LIT (0xf.3d92467581578p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e43p+0), LIT (0xf.3d9246758157p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e44p+0), LIT (0xf.3d92467581578p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.0000000000004p-1024 + +0 i", LIT (0x4.0000000000004p-1024), LIT (0x0p+0), { LIT (0x2p-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000002p-512), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.0000000000004p-1024 + 0x4.0000000000004p-1024 i", LIT (0x4.0000000000004p-1024), LIT (0x4.0000000000004p-1024), { LIT (0x2.3286b95ff53f2p-512), LIT (0xe.90189c7b64148p-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f2p-512), LIT (0xe.90189c7b64148p-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f2p-512), LIT (0xe.90189c7b64148p-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f4p-512), LIT (0xe.90189c7b6415p-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.0000000000004p-1024 + 0x8p-152 i", LIT (0x4.0000000000004p-1024), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.000008p-128 + 0x4.000008p-128 i", LIT (0x4.000008p-128), LIT (0x4.000008p-128), { LIT (0x2.3286bb927bf74p-64), LIT (0xe.9018ab0b7ca9p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf76p-64), LIT (0xe.9018ab0b7ca98p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf74p-64), LIT (0xe.9018ab0b7ca9p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf76p-64), LIT (0xe.9018ab0b7ca98p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x4.0000000000004p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcdp-512), LIT (0x1.6a09e667f3bccp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcep-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdp-512), LIT (0x1.6a09e667f3bccp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcep-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x4.0000000000008p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bcep-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcfp-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcep-512), LIT (0x1.6a09e667f3bcdp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcfp-512), LIT (0x1.6a09e667f3bcep-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x4p-1076 i", LIT (0x4p-1076), LIT (0x4p-1076), { LIT (0x8.ca1ae57fd4fcp-540), LIT (0x3.a406271ed905p-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc8p-540), LIT (0x3.a406271ed905p-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fcp-540), LIT (0x3.a406271ed905p-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc8p-540), LIT (0x3.a406271ed9052p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x8p+1020 i", LIT (0x4p-1076), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0x8p-152 i", LIT (0x4p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0xf.ffffffffffff8p+1020 i", LIT (0x4p-1076), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+508), LIT (0xb.504f333f9de68p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076 + 0xf.fffffp+124 i", LIT (0x4p-1076), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b8p+60), LIT (0xb.504f2d97764b8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-52 + 0x8p-152 i", LIT (0x4p-52), LIT (0x8p-152), { LIT (0x8p-28), LIT (0x7.ffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x7.ffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p-28), LIT (0x8p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.39e238p+0 - 0x4.576278p-4 i", LIT (0x5.39e238p+0), LIT (-0x4.576278p-4), { LIT (0x2.496e354be8ff2p+0), LIT (-0xf.2fef5df67621p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff2p+0), LIT (-0xf.2fef5df676208p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff2p+0), LIT (-0xf.2fef5df676208p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff4p+0), LIT (-0xf.2fef5df676208p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.9cc21p-4 - 0x1.fb1ec8p+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec8p+0), { LIT (0x1.163c67724ff4ap+0), LIT (-0xe.94bd3c20367ap-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4ap+0), LIT (-0xe.94bd3c2036798p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4ap+0), LIT (-0xe.94bd3c2036798p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4bp+0), LIT (-0xe.94bd3c2036798p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.9cc21p-4 - 0x1.fb1ec91b40dcdp+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec91b40dcdp+0), { LIT (0x1.163c67b277e8bp+0), LIT (-0xe.94bd40e8719p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8bp+0), LIT (-0xe.94bd40e8719p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8bp+0), LIT (-0xe.94bd40e8718f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8cp+0), LIT (-0xe.94bd40e8718f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.9cc21p-4 - 0x1.fb1ecap+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ecap+0), { LIT (0x1.163c67e647624p+0), LIT (-0xe.94bd44c5182a8p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e647625p+0), LIT (-0xe.94bd44c5182ap-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e647624p+0), LIT (-0xe.94bd44c5182ap-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e647625p+0), LIT (-0xe.94bd44c5182ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.b1a2e79e9c9acp-164 + 0x8p-152 i", LIT (0x6.b1a2e79e9c9acp-164), LIT (0x8p-152), { LIT (0x2.000d63729cf6cp-76), LIT (0x1.fff29ce700d43p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6cp-76), LIT (0x1.fff29ce700d43p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6cp-76), LIT (0x1.fff29ce700d43p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6ep-76), LIT (0x1.fff29ce700d44p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.7p+4 + 0x7.8p+4 i", LIT (0x7.7p+4), LIT (0x7.8p+4), { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+1020 + +0 i", LIT (0x8p+1020), LIT (0x0p+0), { LIT (0xb.504f333f9de6p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+1020 + 0x4p-1076 i", LIT (0x8p+1020), LIT (0x4p-1076), { LIT (0xb.504f333f9de6p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de68p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de68p+508), LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+1020 + 0x8p-152 i", LIT (0x8p+1020), LIT (0x8p-152), { LIT (0xb.504f333f9de6p+508), LIT (0x5.a827999fcef3p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+508), LIT (0x5.a827999fcef34p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0x5.a827999fcef3p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+508), LIT (0x5.a827999fcef34p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+124 + 0x8p-152 i", LIT (0x8p+124), LIT (0x8p-152), { LIT (0xb.504f333f9de6p+60), LIT (0x5.a827999fcef3p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+60), LIT (0x5.a827999fcef34p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+60), LIT (0x5.a827999fcef3p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+60), LIT (0x5.a827999fcef34p-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-1076 + +0 i", LIT (0x8p-1076), LIT (0x0p+0), { LIT (0xb.504f333f9de6p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-1076 + 0x8p-1076 i", LIT (0x8p-1076), LIT (0x8p-1076), { LIT (0xc.6e210c9eae01p-540), LIT (0x5.2614be60fbf74p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae018p-540), LIT (0x5.2614be60fbf74p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae01p-540), LIT (0x5.2614be60fbf74p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae018p-540), LIT (0x5.2614be60fbf78p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-1076 + 0x8p-152 i", LIT (0x8p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffp-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000002p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 - 0x8p-152 i", LIT (0x8p-152), LIT (-0x8p-152), { LIT (0x3.1b884327ab804p-76), LIT (-0x1.49852f983efdep-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab806p-76), LIT (-0x1.49852f983efddp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab804p-76), LIT (-0x1.49852f983efddp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab806p-76), LIT (-0x1.49852f983efddp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x2.d413cccfe7798p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7798p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x4.0000000000004p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000004p-1024), { LIT (0x2.d413cccfe7798p-76), LIT (0xb.504f333f9de68p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0xb.504f333f9de7p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7798p-76), LIT (0xb.504f333f9de68p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0xb.504f333f9de7p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x4.0000000000008p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000008p-1024), { LIT (0x2.d413cccfe7798p-76), LIT (0xb.504f333f9de78p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0xb.504f333f9de78p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7798p-76), LIT (0xb.504f333f9de78p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0xb.504f333f9de8p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x4.000008p-128 i", LIT (0x8p-152), LIT (0x4.000008p-128), { LIT (0x1.6a09e93c07882p-64), LIT (0x1.6a09e667f3be3p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07883p-64), LIT (0x1.6a09e667f3be3p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882p-64), LIT (0x1.6a09e667f3be3p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07883p-64), LIT (0x1.6a09e667f3be4p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x4.00001p-128 i", LIT (0x8p-152), LIT (0x4.00001p-128), { LIT (0x1.6a09eaa6116bp-64), LIT (0x1.6a09e7d1fda3ep-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b1p-64), LIT (0x1.6a09e7d1fda3ep-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116bp-64), LIT (0x1.6a09e7d1fda3ep-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b1p-64), LIT (0x1.6a09e7d1fda3fp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x4p-1076 i", LIT (0x8p-152), LIT (0x4p-1076), { LIT (0x2.d413cccfe7798p-76), LIT (0xb.504f333f9de6p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0xb.504f333f9de68p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7798p-76), LIT (0xb.504f333f9de6p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0xb.504f333f9de68p-1004), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x7.8p-148 i", LIT (0x8p-152), LIT (0x7.8p-148), { LIT (0x8.02213e8d55a48p-76), LIT (0x7.7e015d4e23f44p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a5p-76), LIT (0x7.7e015d4e23f44p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a48p-76), LIT (0x7.7e015d4e23f44p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a5p-76), LIT (0x7.7e015d4e23f48p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x8p+1020 i", LIT (0x8p-152), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x8p+124 i", LIT (0x8p-152), LIT (0x8p+124), { LIT (0x8p+60), LIT (0x7.ffffffffffffcp+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x7.ffffffffffffcp+60), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p+60), LIT (0x8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x8p-1076 i", LIT (0x8p-152), LIT (0x8p-1076), { LIT (0x2.d413cccfe7798p-76), LIT (0x1.6a09e667f3bccp-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0x1.6a09e667f3bcdp-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7798p-76), LIT (0x1.6a09e667f3bccp-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779ap-76), LIT (0x1.6a09e667f3bcdp-1000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0x8p-152 i", LIT (0x8p-152), LIT (0x8p-152), { LIT (0x3.1b884327ab804p-76), LIT (0x1.49852f983efddp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab806p-76), LIT (0x1.49852f983efddp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab804p-76), LIT (0x1.49852f983efddp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab806p-76), LIT (0x1.49852f983efdep-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0xf.ffffffffffff8p+1020 i", LIT (0x8p-152), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+508), LIT (0xb.504f333f9de68p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152 + 0xf.fffffp+124 i", LIT (0x8p-152), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764bp+60), LIT (0xb.504f2d97764bp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b8p+60), LIT (0xb.504f2d97764b8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.0cf78272ed4f6p+0), LIT (0x9.84953b9e67de8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f6p+0), LIT (0x9.84953b9e67de8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f6p+0), LIT (0x9.84953b9e67de8p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f7p+0), LIT (0x9.84953b9e67dfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xd.25d559ac5baap-168 + 0x8p-152 i", LIT (0xd.25d559ac5baap-168), LIT (0x8p-152), { LIT (0x2.0001a4bb58122p-76), LIT (0x1.fffe5b4601a84p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58124p-76), LIT (0x1.fffe5b4601a84p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58122p-76), LIT (0x1.fffe5b4601a84p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58124p-76), LIT (0x1.fffe5b4601a85p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.229827fe17d08p-4 + 0xd.849ecp-4 i", LIT (0xe.229827fe17d08p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00ac53515ap+0), LIT (0x6.96423e0f64024p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515bp+0), LIT (0x6.96423e0f64028p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515ap+0), LIT (0x6.96423e0f64024p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515bp+0), LIT (0x6.96423e0f64028p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.22982p-4 + 0xd.849ecp-4 i", LIT (0xe.22982p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00a8f88c3bp+0), LIT (0x6.96423f67ee9c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3cp+0), LIT (0x6.96423f67ee9c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3bp+0), LIT (0x6.96423f67ee9c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3cp+0), LIT (0x6.96423f67ee9c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.22983p-4 + 0xd.849ecp-4 i", LIT (0xe.22983p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00afafb044p+0), LIT (0x6.96423cb635p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb044p+0), LIT (0x6.96423cb635p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb044p+0), LIT (0x6.96423cb635p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb045p+0), LIT (0x6.96423cb635004p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.a24adp+28 + 0x8.0f148p+36 i", LIT (0xf.a24adp+28), LIT (0x8.0f148p+36), { LIT (0x8.0f544aab148p+16), LIT (0x7.ffc0aea894798p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab14808p+16), LIT (0x7.ffc0aea89479cp+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab148p+16), LIT (0x7.ffc0aea894798p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab14808p+16), LIT (0x7.ffc0aea89479cp+16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020 + +0 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0xf.ffffffffffff8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p+512), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0xf.ffffffffffff8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffff8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffff8p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p+512), LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020 + 0x8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p+1020), { LIT (0x1.077225f1da571p+512), LIT (0x3.e30ee78adee42p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571p+512), LIT (0x3.e30ee78adee44p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571p+512), LIT (0x3.e30ee78adee42p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da572p+512), LIT (0x3.e30ee78adee44p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0xf.ffffffffffff8p+508), LIT (0x4p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p+508), LIT (0x4p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p+508), LIT (0x4p-664), ERRNO_UNCHANGED }, { LIT (0x1p+512), LIT (0x4.0000000000004p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.19435caffa9f8p+512), LIT (0x7.480c4e3db209cp+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f8p+512), LIT (0x7.480c4e3db20ap+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f8p+512), LIT (0x7.480c4e3db209cp+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f9p+512), LIT (0x7.480c4e3db20ap+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020 + 0xf.fffffp+124 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffff8p+508), LIT (0x7.fffff8p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p+508), LIT (0x7.fffff8p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p+508), LIT (0x7.fffff8p-388), ERRNO_UNCHANGED }, { LIT (0x1p+512), LIT (0x7.fffff80000004p-388), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + +0 i", LIT (0xf.fffffp+124), LIT (0x0p+0), { LIT (0xf.fffff7fffffd8p+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffd8p+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + 0x1p+0 i", LIT (0xf.fffffp+124), LIT (0x1p+0), { LIT (0xf.fffff7fffffd8p+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffd8p+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x8.0000040000038p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + 0x4p-1076 i", LIT (0xf.fffffp+124), LIT (0x4p-1076), { LIT (0xf.fffff7fffffd8p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffd8p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffep+60), LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + 0x8.8p-512 i", LIT (0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0xf.fffff7fffffd8p+60), LIT (0x4.4000022000018p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.4000022000018p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffd8p+60), LIT (0x4.4000022000018p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.400002200001cp-576), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + 0x8p+1020 i", LIT (0xf.fffffp+124), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + 0x8p-152 i", LIT (0xf.fffffp+124), LIT (0x8p-152), { LIT (0xf.fffff7fffffd8p+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffd8p+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.000002000001cp-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + 0xe.7e0c2p+116 i", LIT (0xf.fffffp+124), LIT (0xe.7e0c2p+116), { LIT (0x1.000019c0e5da2p+64), LIT (0x7.3f055562b51ccp+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da2p+64), LIT (0x7.3f055562b51ccp+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da2p+64), LIT (0x7.3f055562b51ccp+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da3p+64), LIT (0x7.3f055562b51dp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.fffffp+124), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6p+508), LIT (0xb.504f333f9de6p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de68p+508), LIT (0xb.504f333f9de68p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124 + 0xf.fffffp+124 i", LIT (0xf.fffffp+124), LIT (0xf.fffffp+124), { LIT (0x1.19435c2358f11p+64), LIT (0x7.480c4a99abe2p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11p+64), LIT (0x7.480c4a99abe2p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11p+64), LIT (0x7.480c4a99abe2p+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f12p+64), LIT (0x7.480c4a99abe24p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fp+1020 + +0 i", LIT (0xf.fp+1020), LIT (0x0p+0), { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f9p+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fp+1020 + 0x8.8p-512 i", LIT (0xf.fp+1020), LIT (0x8.8p-512), { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x4.422199552a8c8p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x4.422199552a8ccp-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x4.422199552a8c8p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f9p+508), LIT (0x4.422199552a8ccp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fp+1020 + 0x8p-152 i", LIT (0xf.fp+1020), LIT (0x8p-152), { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x4.0201814118fccp-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x4.0201814118fdp-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8f8p+508), LIT (0x4.0201814118fccp-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f9p+508), LIT (0x4.0201814118fdp-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fp+124 + 0x8.8p-64 i", LIT (0xf.fp+124), LIT (0x8.8p-64), { LIT (0xf.f7fdfeff5f8f8p+60), LIT (0x4.422199552a8c8p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8f8p+60), LIT (0x4.422199552a8ccp-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8f8p+60), LIT (0x4.422199552a8c8p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f9p+60), LIT (0x4.422199552a8ccp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0 - 0x4.0000000000004p-1024 i", LIT (-0x0p+0), LIT (-0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcd459022e5304d08p-512), LIT (-0x1.6a09e667f3bcd459022e5304d1p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d08p-512), LIT (-0x1.6a09e667f3bcd459022e5304d08p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d08p-512), LIT (-0x1.6a09e667f3bcd459022e5304d08p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d1p-512), LIT (-0x1.6a09e667f3bcd459022e5304d08p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0 - 0x4p-1076 i", LIT (-0x0p+0), LIT (-0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baap-540), LIT (-0x5.a827999fcef32422cbec4d9bacp-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baap-540), LIT (-0x5.a827999fcef32422cbec4d9baap-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baap-540), LIT (-0x5.a827999fcef32422cbec4d9baap-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9bacp-540), LIT (-0x5.a827999fcef32422cbec4d9baap-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0 - 0x8p-152 i", LIT (-0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0 + 0x8p-152 i", LIT (-0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.65c7ac7c97a25p-176 - 0x8p-152 i", LIT (-0x1.65c7ac7c97a25p-176), LIT (-0x8p-152), { LIT (0x1.ffffffd3470a72611238fcca07p-76), LIT (-0x2.0000002cb8f59186facca56fa5p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a72611238fcca078p-76), LIT (-0x2.0000002cb8f59186facca56fa5p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a72611238fcca07p-76), LIT (-0x2.0000002cb8f59186facca56fa4p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a72611238fcca078p-76), LIT (-0x2.0000002cb8f59186facca56fa4p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.9edb24c83e22cp-172 - 0x8p-152 i", LIT (-0x1.9edb24c83e22cp-172), LIT (-0x8p-152), { LIT (0x1.fffffcc249b90fcd4551133a1ep-76), LIT (-0x2.0000033db64c30c5c7ce266beap-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcd4551133a1ep-76), LIT (-0x2.0000033db64c30c5c7ce266be9p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcd4551133a1ep-76), LIT (-0x2.0000033db64c30c5c7ce266be9p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcd4551133a1e8p-76), LIT (-0x2.0000033db64c30c5c7ce266be9p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0 - 0x4p-1024 i", LIT (-0x1p+0), LIT (-0x4p-1024), { LIT (0x1.ffffffffffffcp-1024), LIT (-0x1.000000000000000000000000008p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffffcp-1024), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0 - 0x4p-128 i", LIT (-0x1p+0), LIT (-0x4p-128), { LIT (0x1.ffffffffffffffffffffffffff8p-128), LIT (-0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0 - 0x8p-972 i", LIT (-0x1p+0), LIT (-0x8p-972), { LIT (0x3.fffffffffffffffffffffffffcp-972), LIT (-0x1.000000000000000000000000008p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-972), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffffffffffffffffcp-972), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-972), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0 + +0 i", LIT (-0x1p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0 + 0x4p-1024 i", LIT (-0x1p+0), LIT (0x4p-1024), { LIT (0x1.ffffffffffffcp-1024), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffffcp-1024), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-1024), LIT (0x1.000000000000000000000000008p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0 + 0x4p-128 i", LIT (-0x1p+0), LIT (0x4p-128), { LIT (0x1.ffffffffffffffffffffffffff8p-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0 + 0x8p-972 i", LIT (-0x1p+0), LIT (0x8p-972), { LIT (0x3.fffffffffffffffffffffffffcp-972), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-972), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffffffffffffffffcp-972), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-972), LIT (0x1.000000000000000000000000008p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.927275f6febb6p-184 + 0x8p-152 i", LIT (-0x2.927275f6febb6p-184), LIT (0x8p-152), { LIT (0x1.ffffffffadb1b14126c6249998p-76), LIT (0x2.00000000524e4ebee674fc9995p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b14126c6249998p-76), LIT (0x2.00000000524e4ebee674fc9996p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b14126c6249998p-76), LIT (0x2.00000000524e4ebee674fc9995p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b14126c62499988p-76), LIT (0x2.00000000524e4ebee674fc9996p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (0xe.55ec7a5ee26873fa30d7c5f6e4p-4), LIT (-0x1.ac950b37094a5a94aab4a9642ep+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e8p-4), LIT (-0x1.ac950b37094a5a94aab4a9642ep+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e4p-4), LIT (-0x1.ac950b37094a5a94aab4a9642d8p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e8p-4), LIT (-0x1.ac950b37094a5a94aab4a9642d8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p+0 + 0x3p+0 i", LIT (-0x2p+0), LIT (0x3p+0), { LIT (0xe.55ec7a5ee26873fa30d7c5f6e4p-4), LIT (0x1.ac950b37094a5a94aab4a9642d8p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e8p-4), LIT (0x1.ac950b37094a5a94aab4a9642ep+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e4p-4), LIT (0x1.ac950b37094a5a94aab4a9642d8p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fa30d7c5f6e8p-4), LIT (0x1.ac950b37094a5a94aab4a9642ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.0000000000004p-1024 - 0 i", LIT (-0x4.0000000000004p-1024), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000001p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000001p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000fffffffffffffp-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000fffffffffffffp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.0000000000004p-1024 - 0x4.0000000000004p-1024 i", LIT (-0x4.0000000000004p-1024), LIT (-0x4.0000000000004p-1024), { LIT (0xe.90189c7b641487bcab1b5b5b68p-516), LIT (-0x2.3286b95ff53f28433fda06dfb3p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487bcab1b5b5b6cp-516), LIT (-0x2.3286b95ff53f28433fda06dfb2p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487bcab1b5b5b68p-516), LIT (-0x2.3286b95ff53f28433fda06dfb2p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487bcab1b5b5b6cp-516), LIT (-0x2.3286b95ff53f28433fda06dfb2p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.0000000000004p-1024 - 0x8p-152 i", LIT (-0x4.0000000000004p-1024), LIT (-0x8p-152), { LIT (0x1.ffffffffffffffffffffffffff8p-76), LIT (-0x2.00000000000000000000000001p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.000008p-128 - 0x4.000008p-128 i", LIT (-0x4.000008p-128), LIT (-0x4.000008p-128), { LIT (0xe.9018ab0b7ca94693b355165c1cp-68), LIT (-0x2.3286bb927bf75d60ed8efefb8ep-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca94693b355165c1cp-68), LIT (-0x2.3286bb927bf75d60ed8efefb8ep-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca94693b355165c1cp-68), LIT (-0x2.3286bb927bf75d60ed8efefb8dp-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca94693b355165c2p-68), LIT (-0x2.3286bb927bf75d60ed8efefb8dp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.15ca1p+0 - 0x8p-152 i", LIT (-0x4.15ca1p+0), LIT (-0x8p-152), { LIT (0x1.faa35a1b5eb2277c5b81a0bc81p-152), LIT (-0x2.056b2cd84231ea6b3b0807c89bp+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277c5b81a0bc81p-152), LIT (-0x2.056b2cd84231ea6b3b0807c89ap+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277c5b81a0bc81p-152), LIT (-0x2.056b2cd84231ea6b3b0807c89ap+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277c5b81a0bc818p-152), LIT (-0x2.056b2cd84231ea6b3b0807c89ap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.827738p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.827738p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee6cd64cbb62e158cabbd8cp-4), LIT (-0x1.02a876fc905207cb814e2eb3848p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb62e158cabbd8cp-4), LIT (-0x1.02a876fc905207cb814e2eb3848p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb62e158cabbd8cp-4), LIT (-0x1.02a876fc905207cb814e2eb384p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb62e158cabbd9p-4), LIT (-0x1.02a876fc905207cb814e2eb384p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.82773b736291p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82773b736291p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee5f5a36814cd75037a913p-4), LIT (-0x1.02a8770c69a38eb8ab6efd78eb8p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814cd75037a913p-4), LIT (-0x1.02a8770c69a38eb8ab6efd78eb8p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814cd75037a913p-4), LIT (-0x1.02a8770c69a38eb8ab6efd78ebp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814cd75037a9134p-4), LIT (-0x1.02a8770c69a38eb8ab6efd78ebp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.82774p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82774p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee4d93232a2420fb5a5de7cp-4), LIT (-0x1.02a877214e9fe4ccddb4bf40a3p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a2420fb5a5de8p-4), LIT (-0x1.02a877214e9fe4ccddb4bf40a3p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a2420fb5a5de7cp-4), LIT (-0x1.02a877214e9fe4ccddb4bf40a28p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a2420fb5a5de8p-4), LIT (-0x1.02a877214e9fe4ccddb4bf40a28p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.d0144005d7af4p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144005d7af4p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2657d0a0370ad2744a13b8p+0), LIT (-0x2.0201143f4f66d95db989bd244ap+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a0370ad2744a13cp+0), LIT (-0x2.0201143f4f66d95db989bd2449p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a0370ad2744a13b8p+0), LIT (-0x2.0201143f4f66d95db989bd2449p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a0370ad2744a13cp+0), LIT (-0x2.0201143f4f66d95db989bd2449p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.d01448p-4 - 0x7.c19148p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2559bb4b70c158cd5697ap+0), LIT (-0x2.0201144fd174462bdbd12437e8p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70c158cd5697ap+0), LIT (-0x2.0201144fd174462bdbd12437e7p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70c158cd5697ap+0), LIT (-0x2.0201144fd174462bdbd12437e7p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70c158cd5697a8p+0), LIT (-0x2.0201144fd174462bdbd12437e7p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.d01448p-4 - 0x7.c1915p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c1915p+0), { LIT (0x1.ee74d35e7dfe1b3cee8924cd5p+0), LIT (-0x2.0201154ea0e0412a465d933757p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cee8924cd5p+0), LIT (-0x2.0201154ea0e0412a465d933757p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cee8924cd5p+0), LIT (-0x2.0201154ea0e0412a465d933756p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cee8924cd508p+0), LIT (-0x2.0201154ea0e0412a465d933756p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4.d0144p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d26588ab7af21eeb8d76b48p+0), LIT (-0x2.0201143f434fabbbd9085f85ccp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af21eeb8d76b48p+0), LIT (-0x2.0201143f434fabbbd9085f85cbp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af21eeb8d76b48p+0), LIT (-0x2.0201143f434fabbbd9085f85cbp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af21eeb8d76b5p+0), LIT (-0x2.0201143f434fabbbd9085f85cbp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076 - 0 i", LIT (-0x4p-1076), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076 - 0x4p-1076 i", LIT (-0x4p-1076), LIT (-0x4p-1076), { LIT (0x3.a406271ed90504cef98de00eb2p-540), LIT (-0x8.ca1ae57fd4fc5abc283c1cd6e8p-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504cef98de00eb3p-540), LIT (-0x8.ca1ae57fd4fc5abc283c1cd6e8p-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504cef98de00eb2p-540), LIT (-0x8.ca1ae57fd4fc5abc283c1cd6e4p-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504cef98de00eb3p-540), LIT (-0x8.ca1ae57fd4fc5abc283c1cd6e4p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076 - 0x8p-152 i", LIT (-0x4p-1076), LIT (-0x8p-152), { LIT (0x1.ffffffffffffffffffffffffff8p-76), LIT (-0x2.00000000000000000000000001p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.31291c9fdae04p-160 - 0x8p-152 i", LIT (-0x7.31291c9fdae04p-160), LIT (-0x8p-152), { LIT (0x1.ff1a0ead4f6b13d04d5d6ea54b8p-76), LIT (-0x2.00e658c5f71cca99e9ffb790e3p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13d04d5d6ea54b8p-76), LIT (-0x2.00e658c5f71cca99e9ffb790e2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13d04d5d6ea54b8p-76), LIT (-0x2.00e658c5f71cca99e9ffb790e2p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13d04d5d6ea54cp-76), LIT (-0x2.00e658c5f71cca99e9ffb790e2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.915fa8p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fa8p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c32571e2b8ea0a1d4283bbdba8p-4), LIT (-0x1.3392ad649c5855af7b9a4bcfd08p+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a1d4283bbdba8p-4), LIT (-0x1.3392ad649c5855af7b9a4bcfdp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a1d4283bbdba8p-4), LIT (-0x1.3392ad649c5855af7b9a4bcfdp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a1d4283bbdbacp-4), LIT (-0x1.3392ad649c5855af7b9a4bcfdp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.915fafbe9f588p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fafbe9f588p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c325704e2c61d1a1062699dc58p-4), LIT (-0x1.3392ad837265580fa41acfac148p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1a1062699dc5cp-4), LIT (-0x1.3392ad837265580fa41acfac148p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1a1062699dc58p-4), LIT (-0x1.3392ad837265580fa41acfac14p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1a1062699dc5cp-4), LIT (-0x1.3392ad837265580fa41acfac14p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.915fbp-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fbp-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c3257040d54fb3c85fce59f48cp-4), LIT (-0x1.3392ad8476b45afedefba40153p+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3c85fce59f49p-4), LIT (-0x1.3392ad8476b45afedefba40153p+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3c85fce59f48cp-4), LIT (-0x1.3392ad8476b45afedefba401528p+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3c85fce59f49p-4), LIT (-0x1.3392ad8476b45afedefba401528p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.ec8932bf5603p-172 + 0x8p-152 i", LIT (-0x8.ec8932bf5603p-172), LIT (0x8p-152), { LIT (0x1.ffffee26edea24772bbb75f81ep-76), LIT (0x2.000011d912b521c9aa5f4f5672p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea24772bbb75f81e8p-76), LIT (0x2.000011d912b521c9aa5f4f5672p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea24772bbb75f81ep-76), LIT (0x2.000011d912b521c9aa5f4f5672p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea24772bbb75f81e8p-76), LIT (0x2.000011d912b521c9aa5f4f5673p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152 - 0 i", LIT (-0x8p-152), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.d413cccfe779921165f626cdd6p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921165f626cdd5p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921165f626cdd5p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921165f626cdd5p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152 - 0x1.818bccp+0 i", LIT (-0x8p-152), LIT (-0x1.818bccp+0), { LIT (0xd.e25fb98f8390a020c51dc0c93cp-4), LIT (-0xd.e25fb98f8390a020c51dc0c94p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a020c51dc0c94p-4), LIT (-0xd.e25fb98f8390a020c51dc0c94p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a020c51dc0c93cp-4), LIT (-0xd.e25fb98f8390a020c51dc0c93cp-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a020c51dc0c94p-4), LIT (-0xd.e25fb98f8390a020c51dc0c93cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152 - 0x4.0000000000004p-1024 i", LIT (-0x8p-152), LIT (-0x4.0000000000004p-1024), { LIT (0xb.504f333f9de6fd4a8b0c9515b8p-952), LIT (-0x2.d413cccfe779921165f626cdd6p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd4a8b0c9515b8p-952), LIT (-0x2.d413cccfe779921165f626cdd5p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd4a8b0c9515b8p-952), LIT (-0x2.d413cccfe779921165f626cdd5p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd4a8b0c9515bcp-952), LIT (-0x2.d413cccfe779921165f626cdd5p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152 - 0x4p-1076 i", LIT (-0x8p-152), LIT (-0x4p-1076), { LIT (0xb.504f333f9de6484594p-1004), LIT (-0x2.d413cccfe779921165f626cdd6p-76), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484598p-1004), LIT (-0x2.d413cccfe779921165f626cdd5p-76), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484594p-1004), LIT (-0x2.d413cccfe779921165f626cdd5p-76), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484598p-1004), LIT (-0x2.d413cccfe779921165f626cdd5p-76), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152 - 0x8p-152 i", LIT (-0x8p-152), LIT (-0x8p-152), { LIT (0x1.49852f983efdd57b4bab8f320dp-76), LIT (-0x3.1b884327ab8057e2c8727f3967p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320dp-76), LIT (-0x3.1b884327ab8057e2c8727f3967p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320dp-76), LIT (-0x3.1b884327ab8057e2c8727f3966p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320d8p-76), LIT (-0x3.1b884327ab8057e2c8727f3966p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152 + 0x8p-152 i", LIT (-0x8p-152), LIT (0x8p-152), { LIT (0x1.49852f983efdd57b4bab8f320dp-76), LIT (0x3.1b884327ab8057e2c8727f3966p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320dp-76), LIT (0x3.1b884327ab8057e2c8727f3967p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320dp-76), LIT (0x3.1b884327ab8057e2c8727f3966p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57b4bab8f320d8p-76), LIT (0x3.1b884327ab8057e2c8727f3967p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x9.0a61a7b482d28p-168 - 0x8p-152 i", LIT (-0x9.0a61a7b482d28p-168), LIT (-0x8p-152), { LIT (0x1.fffedeb41cc4e764fc7b2f071b8p-76), LIT (-0x2.0001214c86b1abbcd9ec0a3a2bp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764fc7b2f071b8p-76), LIT (-0x2.0001214c86b1abbcd9ec0a3a2bp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764fc7b2f071b8p-76), LIT (-0x2.0001214c86b1abbcd9ec0a3a2ap-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764fc7b2f071cp-76), LIT (-0x2.0001214c86b1abbcd9ec0a3a2ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xb.e2bc1cd6eaa7p-180 + 0x8p-152 i", LIT (-0xb.e2bc1cd6eaa7p-180), LIT (0x8p-152), { LIT (0x1.ffffffe83a87c6df6fad2e2d15p-76), LIT (0x2.00000017c5783a3b1a49210eeap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6df6fad2e2d15p-76), LIT (0x2.00000017c5783a3b1a49210eeap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6df6fad2e2d15p-76), LIT (0x2.00000017c5783a3b1a49210eeap-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6df6fad2e2d158p-76), LIT (0x2.00000017c5783a3b1a49210eebp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xd.e1d5fp-4 - 0x1.054226p+4 i", LIT (-0xd.e1d5fp-4), LIT (-0x1.054226p+4), { LIT (0x2.c84e99e2df484b121a43f676e3p+0), LIT (-0x2.ef2930261e97de8eea66b38cb6p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b121a43f676e4p+0), LIT (-0x2.ef2930261e97de8eea66b38cb5p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b121a43f676e3p+0), LIT (-0x2.ef2930261e97de8eea66b38cb5p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b121a43f676e4p+0), LIT (-0x2.ef2930261e97de8eea66b38cb5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xe.6432ap-4 + 0xe.8175p-4 i", LIT (-0xe.6432ap-4), LIT (0xe.8175p-4), { LIT (0x6.f3d482a6e0b03b9722cd5561f2p-4), LIT (0x1.0b0f83813dfbbb8ddfefa6ce478p+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b9722cd5561f2p-4), LIT (0x1.0b0f83813dfbbb8ddfefa6ce48p+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b9722cd5561f2p-4), LIT (0x1.0b0f83813dfbbb8ddfefa6ce478p+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b9722cd5561f4p-4), LIT (0x1.0b0f83813dfbbb8ddfefa6ce48p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xe.735dbp+0 - 0x5.26cb98p+40 i", LIT (-0xe.735dbp+0), LIT (-0x5.26cb98p+40), { LIT (0x1.9adc1d93b4e9b398b22875bb9fp+20), LIT (-0x1.9adc1d93b96a35664dffa77bdd8p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398b22875bb9fp+20), LIT (-0x1.9adc1d93b96a35664dffa77bdd8p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398b22875bb9fp+20), LIT (-0x1.9adc1d93b96a35664dffa77bddp+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398b22875bb9f8p+20), LIT (-0x1.9adc1d93b96a35664dffa77bddp+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020 + +0 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.ffffffffffffbffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffbffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0xf.ffffffffffffbffffffffffffcp+508), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.ffffffffffffcp+508), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.ffffffffffffbffffffffffffcp+508), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0xf.ffffffffffffcp+508), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffbffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffbffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.00000000000010000000000002p-664), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020 + +0 i", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffep+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020 + 0x4p-1076 i", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffcp+508), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffcp+508), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.ffffffffffffdffffffffffffcp+508), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0xf.ffffffffffffep+508), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020 + 0x8p-152 i", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x8p-152), { LIT (0x4.00000000000008p-664), LIT (0xf.ffffffffffffdffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.00000000000008p-664), LIT (0xf.ffffffffffffdffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.00000000000008p-664), LIT (0xf.ffffffffffffdffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.00000000000008000000000002p-664), LIT (0xf.ffffffffffffep+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124 + +0 i", LIT (-0xf.fffffp+124), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff5cp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff5cp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124 + 0x4p-1076 i", LIT (-0xf.fffffp+124), LIT (0x4p-1076), { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff5cp+60), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff6p+60), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffffeffffff5cp+60), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124 + 0x8.8p-512 i", LIT (-0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0x4.40000220000198000154000128p-576), LIT (0xf.fffff7fffffdfffffeffffff5cp+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000019800015400012ap-576), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198000154000128p-576), LIT (0xf.fffff7fffffdfffffeffffff5cp+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000019800015400012ap-576), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124 + 0x8p-152 i", LIT (-0xf.fffffp+124), LIT (0x8p-152), { LIT (0x4.00000200000180000140000118p-216), LIT (0xf.fffff7fffffdfffffeffffff5cp+60), ERRNO_UNCHANGED }, { LIT (0x4.00000200000180000140000118p-216), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED }, { LIT (0x4.00000200000180000140000118p-216), LIT (0xf.fffff7fffffdfffffeffffff5cp+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018000014000011ap-216), LIT (0xf.fffff7fffffdfffffeffffff6p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fp+1020 + +0 i", LIT (-0xf.fp+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbdca3329e318p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fp+1020 + 0x8.8p-512 i", LIT (-0xf.fp+1020), LIT (0x8.8p-512), { LIT (0x4.422199552a8c8p-1024), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), UNDERFLOW_EXCEPTION }, { LIT (0x4.422199552a8ccp-1024), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), UNDERFLOW_EXCEPTION }, { LIT (0x4.422199552a8c8p-1024), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), UNDERFLOW_EXCEPTION }, { LIT (0x4.422199552a8ccp-1024), LIT (0xf.f7fdfeff5f8fabbdca3329e318p+508), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fp+1020 + 0x8p-152 i", LIT (-0xf.fp+1020), LIT (0x8p-152), { LIT (0x4.0201814118fce7d749d6a119dep-664), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119ep-664), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119dep-664), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d749d6a119ep-664), LIT (0xf.f7fdfeff5f8fabbdca3329e318p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fp+124 + 0x8.8p-64 i", LIT (-0xf.fp+124), LIT (0x8.8p-64), { LIT (0x4.422199552a8cb654be740b2b7cp-128), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7ep-128), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7cp-128), LIT (0xf.f7fdfeff5f8fabbdca3329e314p+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb654be740b2b7ep-128), LIT (0xf.f7fdfeff5f8fabbdca3329e318p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0x1p+0 i", LIT (0x0p+0), LIT (-0x1p+0), { LIT (0xb.504f333f9de6484597d89b3754p-4), LIT (-0xb.504f333f9de6484597d89b3758p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p-4), LIT (-0xb.504f333f9de6484597d89b3754p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p-4), LIT (-0xb.504f333f9de6484597d89b3754p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3758p-4), LIT (-0xb.504f333f9de6484597d89b3754p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x2p+0 i", LIT (0x0p+0), LIT (0x2p+0), { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x4.0000000000004p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcd459022e5304d08p-512), LIT (0x1.6a09e667f3bcd459022e5304d08p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d08p-512), LIT (0x1.6a09e667f3bcd459022e5304d08p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d08p-512), LIT (0x1.6a09e667f3bcd459022e5304d08p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd459022e5304d1p-512), LIT (0x1.6a09e667f3bcd459022e5304d1p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x4.0000000000008p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bcdfa9516192a2b6p-512), LIT (0x1.6a09e667f3bcdfa9516192a2b6p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b68p-512), LIT (0x1.6a09e667f3bcdfa9516192a2b68p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b6p-512), LIT (0x1.6a09e667f3bcdfa9516192a2b6p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b68p-512), LIT (0x1.6a09e667f3bcdfa9516192a2b68p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x5.a827999fcef32422cbec4d9baap-540), LIT (0x5.a827999fcef32422cbec4d9baap-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baap-540), LIT (0x5.a827999fcef32422cbec4d9baap-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9baap-540), LIT (0x5.a827999fcef32422cbec4d9baap-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32422cbec4d9bacp-540), LIT (0x5.a827999fcef32422cbec4d9bacp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x8p+1020 i", LIT (0x0p+0), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x8p-1076 i", LIT (0x0p+0), LIT (0x8p-1076), { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x0p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x0p+0), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb84p+508), LIT (0xb.504f333f9de631a4f9721bfb84p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb88p+508), LIT (0xb.504f333f9de631a4f9721bfb88p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb84p+508), LIT (0xb.504f333f9de631a4f9721bfb84p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb88p+508), LIT (0xb.504f333f9de631a4f9721bfb88p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0 + 0xf.fffffp+124 i", LIT (0x0p+0), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0221e29d5a3cdp-188 - 0x8p-152 i", LIT (0x1.0221e29d5a3cdp-188), LIT (-0x8p-152), { LIT (0x2.00000000020443c53ab57de851p-76), LIT (-0x1.fffffffffdfbbc3ac54c8aa8518p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c53ab57de851p-76), LIT (-0x1.fffffffffdfbbc3ac54c8aa8518p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c53ab57de851p-76), LIT (-0x1.fffffffffdfbbc3ac54c8aa851p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c53ab57de852p-76), LIT (-0x1.fffffffffdfbbc3ac54c8aa851p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.d60caep+0 + 0x7.a7d468p+0 i", LIT (0x1.d60caep+0), LIT (0x7.a7d468p+0), { LIT (0x2.3409baa805bc952b162589badcp+0), LIT (0x1.bcc10b50fddb6aeab8ce2e2a59p+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952b162589baddp+0), LIT (0x1.bcc10b50fddb6aeab8ce2e2a598p+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952b162589badcp+0), LIT (0x1.bcc10b50fddb6aeab8ce2e2a59p+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952b162589baddp+0), LIT (0x1.bcc10b50fddb6aeab8ce2e2a598p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.f9610ap+4 + 0x9.87716p+4 i", LIT (0x1.f9610ap+4), LIT (0x9.87716p+4), { LIT (0x9.ad5033142bab31612e9054dcdcp+0), LIT (0x7.e0b144c043868be3519cfa068p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab31612e9054dcep+0), LIT (0x7.e0b144c043868be3519cfa068p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab31612e9054dcdcp+0), LIT (0x7.e0b144c043868be3519cfa068p+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab31612e9054dcep+0), LIT (0x7.e0b144c043868be3519cfa0682p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 - 0x4p-1024 i", LIT (0x1p+0), LIT (-0x4p-1024), { LIT (0x1p+0), LIT (-0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (-0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 - 0x4p-128 i", LIT (0x1p+0), LIT (-0x4p-128), { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.ffffffffffffffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), LIT (-0x1.ffffffffffffffffffffffffff8p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 - 0x8p-972 i", LIT (0x1p+0), LIT (-0x8p-972), { LIT (0x1p+0), LIT (-0x4p-972), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x4p-972), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x3.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (-0x3.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + 0x4p-1024 i", LIT (0x1p+0), LIT (0x4p-1024), { LIT (0x1p+0), LIT (0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x2p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x2p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + 0x4p-128 i", LIT (0x1p+0), LIT (0x4p-128), { LIT (0x1p+0), LIT (0x1.ffffffffffffffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.ffffffffffffffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + 0x8p-972 i", LIT (0x1p+0), LIT (0x8p-972), { LIT (0x1p+0), LIT (0x3.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x4p-972), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x3.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION }, { LIT (0x1.000000000000000000000000008p+0), LIT (0x4p-972), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+4 - 0x1.ep+4 i", LIT (0x1p+4), LIT (-0x1.ep+4), { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-500 + +0 i", LIT (0x1p-500), LIT (0x0p+0), { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-500 + 0x4p-1076 i", LIT (0x1p-500), LIT (0x4p-1076), { LIT (0x4p-252), LIT (0x7.fffffffffffffffffffffffffep-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x8p-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x7.fffffffffffffffffffffffffep-828), ERRNO_UNCHANGED }, { LIT (0x4.00000000000000000000000002p-252), LIT (0x8p-828), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-500 + 0x8p-152 i", LIT (0x1p-500), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffff8p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffff8p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000000000000000000001p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-148 + 0x2p-148 i", LIT (0x2p-148), LIT (0x2p-148), { LIT (0x6.3710864f5700afc590e4fe72ccp-76), LIT (0x2.930a5f307dfbaaf697571e641ap-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc590e4fe72cep-76), LIT (0x2.930a5f307dfbaaf697571e641ap-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc590e4fe72ccp-76), LIT (0x2.930a5f307dfbaaf697571e641ap-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc590e4fe72cep-76), LIT (0x2.930a5f307dfbaaf697571e641bp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db1f30939cea7c0dd70ad38p+0), LIT (0xf.3d9236b503fee60e243767b558p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939cea7c0dd70ad4p+0), LIT (0xf.3d9236b503fee60e243767b55cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939cea7c0dd70ad38p+0), LIT (0xf.3d9236b503fee60e243767b558p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939cea7c0dd70ad4p+0), LIT (0xf.3d9236b503fee60e243767b55cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db809771dda17a04e5a9cf8p+0), LIT (0xf.3d923d93816780f8baebea4468p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda17a04e5a9cf8p+0), LIT (0xf.3d923d93816780f8baebea4468p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda17a04e5a9cf8p+0), LIT (0xf.3d923d93816780f8baebea4468p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda17a04e5a9dp+0), LIT (0xf.3d923d93816780f8baebea446cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc0ba4f2875145978e811e8p+0), LIT (0xf.3d924761f5b5cfe64009bf6f08p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f2875145978e811fp+0), LIT (0xf.3d924761f5b5cfe64009bf6f0cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f2875145978e811e8p+0), LIT (0xf.3d924761f5b5cfe64009bf6f08p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f2875145978e811fp+0), LIT (0xf.3d924761f5b5cfe64009bf6f0cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f0dc684de4c43p+0), LIT (0xf.3d92365a334569e0a428358b7cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0dc684de4c438p+0), LIT (0xf.3d92365a334569e0a428358b7cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0dc684de4c43p+0), LIT (0xf.3d92365a334569e0a428358b7cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0dc684de4c438p+0), LIT (0xf.3d92365a334569e0a428358b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05acf4d936a888028p+0), LIT (0xf.3d923d38b0ae23e2d94a11eaecp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4d936a88803p+0), LIT (0xf.3d923d38b0ae23e2d94a11eaecp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4d936a888028p+0), LIT (0xf.3d923d38b0ae23e2d94a11eaecp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4d936a88803p+0), LIT (0xf.3d923d38b0ae23e2d94a11eafp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c8652a0df9525e4c68p+0), LIT (0xf.3d92470724fc9f33acc4c0d7p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652a0df9525e4c7p+0), LIT (0xf.3d92470724fc9f33acc4c0d7p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652a0df9525e4c68p+0), LIT (0xf.3d92470724fc9f33acc4c0d7p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652a0df9525e4c7p+0), LIT (0xf.3d92470724fc9f33acc4c0d704p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f8c99d77e46e9p+0), LIT (0xf.3d92365a334562da4b179d6508p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8c99d77e46e98p+0), LIT (0xf.3d92365a334562da4b179d6508p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8c99d77e46e9p+0), LIT (0xf.3d92365a334562da4b179d6508p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8c99d77e46e98p+0), LIT (0xf.3d92365a334562da4b179d650cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ad73ac8910d2a48p+0), LIT (0xf.3d923d38b0ae1cdc803be176d4p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad73ac8910d2a48p+0), LIT (0xf.3d923d38b0ae1cdc803be176d8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad73ac8910d2a48p+0), LIT (0xf.3d923d38b0ae1cdc803be176d4p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad73ac8910d2a5p+0), LIT (0xf.3d923d38b0ae1cdc803be176d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c86531fb2e73eaf3ep+0), LIT (0xf.3d92470724fc982d53b9ff5dfp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86531fb2e73eaf3e8p+0), LIT (0xf.3d92470724fc982d53b9ff5df4p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86531fb2e73eaf3ep+0), LIT (0xf.3d92470724fc982d53b9ff5dfp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86531fb2e73eaf3e8p+0), LIT (0xf.3d92470724fc982d53b9ff5df4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f932e12df1098p+0), LIT (0xf.3d92365a3345627d012e06d764p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f932e12df1098p+0), LIT (0xf.3d92365a3345627d012e06d768p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f932e12df1098p+0), LIT (0xf.3d92365a3345627d012e06d764p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f932e12df10988p+0), LIT (0xf.3d92365a3345627d012e06d768p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ad7a40c46eb8ccp+0), LIT (0xf.3d923d38b0ae1c7f36526ad998p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7a40c46eb8cc8p+0), LIT (0xf.3d923d38b0ae1c7f36526ad99cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7a40c46eb8ccp+0), LIT (0xf.3d923d38b0ae1c7f36526ad998p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7a40c46eb8cc8p+0), LIT (0xf.3d923d38b0ae1c7f36526ad99cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c86532647229875a3p+0), LIT (0xf.3d92470724fc97d009d0b6598p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532647229875a3p+0), LIT (0xf.3d92470724fc97d009d0b65984p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532647229875a3p+0), LIT (0xf.3d92470724fc97d009d0b6598p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532647229875a38p+0), LIT (0xf.3d92470724fc97d009d0b65984p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f8p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2fdd855d19cf1f5e8bfb8p+0), LIT (0xf.3d9235c88f9fa24728a26688bp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d19cf1f5e8bfcp+0), LIT (0xf.3d9235c88f9fa24728a26688bp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d19cf1f5e8bfb8p+0), LIT (0xf.3d9235c88f9fa24728a26688bp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d19cf1f5e8bfcp+0), LIT (0xf.3d9235c88f9fa24728a26688b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f8p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db914463967e5bb4fceaa58p+0), LIT (0xf.3d923ca70d088e2617e22ff8cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967e5bb4fceaa58p+0), LIT (0xf.3d923ca70d088e2617e22ff8cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967e5bb4fceaa58p+0), LIT (0xf.3d923ca70d088e2617e22ff8cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967e5bb4fceaa6p+0), LIT (0xf.3d923ca70d088e2617e22ff8c4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.f768f8p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc1c51e435ba2999d1f342p+0), LIT (0xf.3d924675815750a6174c42a768p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435ba2999d1f3428p+0), LIT (0xf.3d924675815750a6174c42a76cp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435ba2999d1f342p+0), LIT (0xf.3d924675815750a6174c42a768p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435ba2999d1f3428p+0), LIT (0xf.3d924675815750a6174c42a76cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.0000000000004p-1024 + +0 i", LIT (0x4.0000000000004p-1024), LIT (0x0p+0), { LIT (0x2.0000000000000fffffffffffffp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001p-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000fffffffffffffp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001p-512), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.0000000000004p-1024 + 0x4.0000000000004p-1024 i", LIT (0x4.0000000000004p-1024), LIT (0x4.0000000000004p-1024), { LIT (0x2.3286b95ff53f28433fda06dfb2p-512), LIT (0xe.90189c7b641487bcab1b5b5b68p-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f28433fda06dfb2p-512), LIT (0xe.90189c7b641487bcab1b5b5b6cp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f28433fda06dfb2p-512), LIT (0xe.90189c7b641487bcab1b5b5b68p-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f28433fda06dfb3p-512), LIT (0xe.90189c7b641487bcab1b5b5b6cp-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.0000000000004p-1024 + 0x8p-152 i", LIT (0x4.0000000000004p-1024), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffff8p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffff8p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000000000000000000001p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.000008p-128 + 0x4.000008p-128 i", LIT (0x4.000008p-128), LIT (0x4.000008p-128), { LIT (0x2.3286bb927bf75d60ed8efefb8dp-64), LIT (0xe.9018ab0b7ca94693b355165c1cp-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d60ed8efefb8ep-64), LIT (0xe.9018ab0b7ca94693b355165c1cp-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d60ed8efefb8dp-64), LIT (0xe.9018ab0b7ca94693b355165c1cp-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d60ed8efefb8ep-64), LIT (0xe.9018ab0b7ca94693b355165c2p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x4.0000000000004p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcdfa9516192a2b68p-512), LIT (0x1.6a09e667f3bcc908b2fb1366ea8p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b7p-512), LIT (0x1.6a09e667f3bcc908b2fb1366ebp-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b68p-512), LIT (0x1.6a09e667f3bcc908b2fb1366ea8p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa9516192a2b7p-512), LIT (0x1.6a09e667f3bcc908b2fb1366ebp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x4.0000000000008p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bceaf9a094d2409cp-512), LIT (0x1.6a09e667f3bcd459022e5304d1p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceaf9a094d2409cp-512), LIT (0x1.6a09e667f3bcd459022e5304d1p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceaf9a094d2409cp-512), LIT (0x1.6a09e667f3bcd459022e5304d1p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceaf9a094d2409c8p-512), LIT (0x1.6a09e667f3bcd459022e5304d18p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x4p-1076 i", LIT (0x4p-1076), LIT (0x4p-1076), { LIT (0x8.ca1ae57fd4fc5abc283c1cd6e4p-540), LIT (0x3.a406271ed90504cef98de00eb2p-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5abc283c1cd6e8p-540), LIT (0x3.a406271ed90504cef98de00eb3p-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5abc283c1cd6e4p-540), LIT (0x3.a406271ed90504cef98de00eb2p-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5abc283c1cd6e8p-540), LIT (0x3.a406271ed90504cef98de00eb3p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x8p+1020 i", LIT (0x4p-1076), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffep+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffep+508), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000004p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0x8p-152 i", LIT (0x4p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffff8p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffff8p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000000000000000000001p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0xf.ffffffffffff8p+1020 i", LIT (0x4p-1076), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x4p-1076), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb84p+508), LIT (0xb.504f333f9de631a4f9721bfb84p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb88p+508), LIT (0xb.504f333f9de631a4f9721bfb88p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb84p+508), LIT (0xb.504f333f9de631a4f9721bfb84p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb88p+508), LIT (0xb.504f333f9de631a4f9721bfb88p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076 + 0xf.fffffp+124 i", LIT (0x4p-1076), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-52 + 0x8p-152 i", LIT (0x4p-52), LIT (0x8p-152), { LIT (0x8p-28), LIT (0x7.fffffffffffffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x7.fffffffffffffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000004p-28), LIT (0x8p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.39e238p+0 - 0x4.576278p-4 i", LIT (0x5.39e238p+0), LIT (-0x4.576278p-4), { LIT (0x2.496e354be8ff297cdb78cd2981p+0), LIT (-0xf.2fef5df67620a002c829886268p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cdb78cd2982p+0), LIT (-0xf.2fef5df67620a002c829886268p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cdb78cd2981p+0), LIT (-0xf.2fef5df67620a002c829886264p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cdb78cd2982p+0), LIT (-0xf.2fef5df67620a002c829886264p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.9cc21p-4 - 0x1.fb1ec8p+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec8p+0), { LIT (0x1.163c67724ff4a226cf087765a1p+0), LIT (-0xe.94bd3c203679a4cf7915a8cb64p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226cf087765a18p+0), LIT (-0xe.94bd3c203679a4cf7915a8cb64p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226cf087765a1p+0), LIT (-0xe.94bd3c203679a4cf7915a8cb6p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226cf087765a18p+0), LIT (-0xe.94bd3c203679a4cf7915a8cb6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.9cc21p-4 - 0x1.fb1ec91b40dcdp+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec91b40dcdp+0), { LIT (0x1.163c67b277e8b48129b48dbf9a8p+0), LIT (-0xe.94bd40e8718fd24951a429be2cp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b48129b48dbf9bp+0), LIT (-0xe.94bd40e8718fd24951a429be28p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b48129b48dbf9a8p+0), LIT (-0xe.94bd40e8718fd24951a429be28p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b48129b48dbf9bp+0), LIT (-0xe.94bd40e8718fd24951a429be28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.9cc21p-4 - 0x1.fb1ecap+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ecap+0), { LIT (0x1.163c67e6476248ee6aa067fa3f8p+0), LIT (-0xe.94bd44c5182a0d43dafb53336cp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248ee6aa067fa3f8p+0), LIT (-0xe.94bd44c5182a0d43dafb53336cp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248ee6aa067fa3f8p+0), LIT (-0xe.94bd44c5182a0d43dafb533368p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248ee6aa067fa4p+0), LIT (-0xe.94bd44c5182a0d43dafb533368p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.b1a2e79e9c9acp-164 + 0x8p-152 i", LIT (0x6.b1a2e79e9c9acp-164), LIT (0x8p-152), { LIT (0x2.000d63729cf6c5d96fbd4c72f6p-76), LIT (0x1.fff29ce700d43550653bb310ca8p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d96fbd4c72f7p-76), LIT (0x1.fff29ce700d43550653bb310cbp-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d96fbd4c72f6p-76), LIT (0x1.fff29ce700d43550653bb310ca8p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d96fbd4c72f7p-76), LIT (0x1.fff29ce700d43550653bb310cbp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.7p+4 + 0x7.8p+4 i", LIT (0x7.7p+4), LIT (0x7.8p+4), { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+1020 + +0 i", LIT (0x8p+1020), LIT (0x0p+0), { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3758p+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+1020 + 0x4p-1076 i", LIT (0x8p+1020), LIT (0x4p-1076), { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484597d89b3758p+508), LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+1020 + 0x8p-152 i", LIT (0x8p+1020), LIT (0x8p-152), { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x5.a827999fcef32422cbec4d9baap-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x5.a827999fcef32422cbec4d9baap-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p+508), LIT (0x5.a827999fcef32422cbec4d9baap-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3758p+508), LIT (0x5.a827999fcef32422cbec4d9bacp-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+124 + 0x8p-152 i", LIT (0x8p+124), LIT (0x8p-152), { LIT (0xb.504f333f9de6484597d89b3754p+60), LIT (0x5.a827999fcef32422cbec4d9baap-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p+60), LIT (0x5.a827999fcef32422cbec4d9baap-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p+60), LIT (0x5.a827999fcef32422cbec4d9baap-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3758p+60), LIT (0x5.a827999fcef32422cbec4d9bacp-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-1076 + +0 i", LIT (0x8p-1076), LIT (0x0p+0), { LIT (0xb.504f333f9de6484597d89b3754p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3754p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484597d89b3758p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-1076 + 0x8p-1076 i", LIT (0x8p-1076), LIT (0x8p-1076), { LIT (0xc.6e210c9eae015f8b21c9fce598p-540), LIT (0x5.2614be60fbf755ed2eae3cc834p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f8b21c9fce59cp-540), LIT (0x5.2614be60fbf755ed2eae3cc834p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f8b21c9fce598p-540), LIT (0x5.2614be60fbf755ed2eae3cc834p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f8b21c9fce59cp-540), LIT (0x5.2614be60fbf755ed2eae3cc836p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-1076 + 0x8p-152 i", LIT (0x8p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffff8p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.ffffffffffffffffffffffffff8p-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000000000000000000001p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 - 0x8p-152 i", LIT (0x8p-152), LIT (-0x8p-152), { LIT (0x3.1b884327ab8057e2c8727f3966p-76), LIT (-0x1.49852f983efdd57b4bab8f320d8p-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f3967p-76), LIT (-0x1.49852f983efdd57b4bab8f320dp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f3966p-76), LIT (-0x1.49852f983efdd57b4bab8f320dp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f3967p-76), LIT (-0x1.49852f983efdd57b4bab8f320dp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd6p-76), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x4.0000000000004p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000004p-1024), { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de6fd4a8b0c9515b8p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de6fd4a8b0c9515b8p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de6fd4a8b0c9515b8p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd6p-76), LIT (0xb.504f333f9de6fd4a8b0c9515bcp-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x4.0000000000008p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000008p-1024), { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de7b24f7e408ef41cp-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de7b24f7e408ef41cp-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de7b24f7e408ef41cp-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921165f626cdd6p-76), LIT (0xb.504f333f9de7b24f7e408ef42p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x4.000008p-128 i", LIT (0x8p-152), LIT (0x4.000008p-128), { LIT (0x1.6a09e93c07882ee646253113a08p-64), LIT (0x1.6a09e667f3be3312968ef35a6c8p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee646253113a1p-64), LIT (0x1.6a09e667f3be3312968ef35a6dp-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee646253113a08p-64), LIT (0x1.6a09e667f3be3312968ef35a6c8p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee646253113a1p-64), LIT (0x1.6a09e667f3be3312968ef35a6dp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x4.00001p-128 i", LIT (0x8p-152), LIT (0x4.00001p-128), { LIT (0x1.6a09eaa6116b0dc14c1b98b5b9p-64), LIT (0x1.6a09e7d1fda3e6015c9ae986dc8p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc14c1b98b5b9p-64), LIT (0x1.6a09e7d1fda3e6015c9ae986ddp-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc14c1b98b5b9p-64), LIT (0x1.6a09e7d1fda3e6015c9ae986dc8p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc14c1b98b5b98p-64), LIT (0x1.6a09e7d1fda3e6015c9ae986ddp-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x4p-1076 i", LIT (0x8p-152), LIT (0x4p-1076), { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de6484594p-1004), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de6484598p-1004), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0xb.504f333f9de6484594p-1004), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd6p-76), LIT (0xb.504f333f9de6484598p-1004), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x7.8p-148 i", LIT (0x8p-152), LIT (0x7.8p-148), { LIT (0x8.02213e8d55a4ec309c4e474cd4p-76), LIT (0x7.7e015d4e23f441ba1dff5c60a2p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec309c4e474cd4p-76), LIT (0x7.7e015d4e23f441ba1dff5c60a2p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec309c4e474cd4p-76), LIT (0x7.7e015d4e23f441ba1dff5c60a2p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec309c4e474cd8p-76), LIT (0x7.7e015d4e23f441ba1dff5c60a4p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x8p+1020 i", LIT (0x8p-152), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffep+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffep+508), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000004p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x8p+124 i", LIT (0x8p-152), LIT (0x8p+124), { LIT (0x8p+60), LIT (0x7.fffffffffffffffffffffffffep+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x7.fffffffffffffffffffffffffep+60), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000004p+60), LIT (0x8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x8p-1076 i", LIT (0x8p-152), LIT (0x8p-1076), { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0x1.6a09e667f3bcc908b2cp-1000), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0x1.6a09e667f3bcc908b3p-1000), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd5p-76), LIT (0x1.6a09e667f3bcc908b2cp-1000), UNDERFLOW_EXCEPTION }, { LIT (0x2.d413cccfe779921165f626cdd6p-76), LIT (0x1.6a09e667f3bcc908b3p-1000), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0x8p-152 i", LIT (0x8p-152), LIT (0x8p-152), { LIT (0x3.1b884327ab8057e2c8727f3966p-76), LIT (0x1.49852f983efdd57b4bab8f320dp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f3967p-76), LIT (0x1.49852f983efdd57b4bab8f320dp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f3966p-76), LIT (0x1.49852f983efdd57b4bab8f320dp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e2c8727f3967p-76), LIT (0x1.49852f983efdd57b4bab8f320d8p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0xf.ffffffffffff8p+1020 i", LIT (0x8p-152), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0x8p-152), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb84p+508), LIT (0xb.504f333f9de631a4f9721bfb84p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb88p+508), LIT (0xb.504f333f9de631a4f9721bfb88p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb84p+508), LIT (0xb.504f333f9de631a4f9721bfb84p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb88p+508), LIT (0xb.504f333f9de631a4f9721bfb88p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152 + 0xf.fffffp+124 i", LIT (0x8p-152), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), LIT (0xb.504f2d97764b3e6cbd977fbaf8p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), LIT (0xb.504f2d97764b3e6cbd977fbafcp+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.0cf78272ed4f605dfff3fea6158p+0), LIT (0x9.84953b9e67deb2fe57ac37bf9p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605dfff3fea6158p+0), LIT (0x9.84953b9e67deb2fe57ac37bf9p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605dfff3fea6158p+0), LIT (0x9.84953b9e67deb2fe57ac37bf9p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605dfff3fea616p+0), LIT (0x9.84953b9e67deb2fe57ac37bf94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xd.25d559ac5baap-168 + 0x8p-152 i", LIT (0xd.25d559ac5baap-168), LIT (0x8p-152), { LIT (0x2.0001a4bb58123fe162db7d9d6dp-76), LIT (0x1.fffe5b4601a8450ff04752f0abp-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fe162db7d9d6dp-76), LIT (0x1.fffe5b4601a8450ff04752f0ab8p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fe162db7d9d6dp-76), LIT (0x1.fffe5b4601a8450ff04752f0abp-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fe162db7d9d6ep-76), LIT (0x1.fffe5b4601a8450ff04752f0ab8p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.229827fe17d08p-4 + 0xd.849ecp-4 i", LIT (0xe.229827fe17d08p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00ac53515a8be28bdca11578p+0), LIT (0x6.96423e0f6402721c81ccafa98ep-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8be28bdca11578p+0), LIT (0x6.96423e0f6402721c81ccafa98ep-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8be28bdca11578p+0), LIT (0x6.96423e0f6402721c81ccafa98ep-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8be28bdca1158p+0), LIT (0x6.96423e0f6402721c81ccafa99p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.22982p-4 + 0xd.849ecp-4 i", LIT (0xe.22982p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00a8f88c3be402c8f8b728cp+0), LIT (0x6.96423f67ee9c453f21bd8b8024p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be402c8f8b728cp+0), LIT (0x6.96423f67ee9c453f21bd8b8026p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be402c8f8b728cp+0), LIT (0x6.96423f67ee9c453f21bd8b8024p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be402c8f8b728c8p+0), LIT (0x6.96423f67ee9c453f21bd8b8026p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.22983p-4 + 0xd.849ecp-4 i", LIT (0xe.22983p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00afafb0445adfa106798f18p+0), LIT (0x6.96423cb6350011fc8758aa4812p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445adfa106798f18p+0), LIT (0x6.96423cb6350011fc8758aa4814p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445adfa106798f18p+0), LIT (0x6.96423cb6350011fc8758aa4812p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445adfa106798f2p+0), LIT (0x6.96423cb6350011fc8758aa4814p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.a24adp+28 + 0x8.0f148p+36 i", LIT (0xf.a24adp+28), LIT (0x8.0f148p+36), { LIT (0x8.0f544aab1480595cbd4e8ac19p+16), LIT (0x7.ffc0aea89479a12a5f913347d4p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480595cbd4e8ac194p+16), LIT (0x7.ffc0aea89479a12a5f913347d6p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480595cbd4e8ac19p+16), LIT (0x7.ffc0aea89479a12a5f913347d4p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480595cbd4e8ac194p+16), LIT (0x7.ffc0aea89479a12a5f913347d6p+16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020 + +0 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0xf.ffffffffffffbffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0xf.ffffffffffffbffffffffffffcp+508), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbffffffffffffcp+508), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020 + 0x8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p+1020), { LIT (0x1.077225f1da5717fdea7d77c6af8p+512), LIT (0x3.e30ee78adee43c462def644d24p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fdea7d77c6bp+512), LIT (0x3.e30ee78adee43c462def644d25p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fdea7d77c6af8p+512), LIT (0x3.e30ee78adee43c462def644d24p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fdea7d77c6bp+512), LIT (0x3.e30ee78adee43c462def644d25p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0xf.ffffffffffffbffffffffffffcp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffffffffffffcp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.00000000000010000000000002p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.19435caffa9f86f27794c3b05e8p+512), LIT (0x7.480c4e3db209ec7dc1e2c9553cp+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f27794c3b05e8p+512), LIT (0x7.480c4e3db209ec7dc1e2c9553ep+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f27794c3b05e8p+512), LIT (0x7.480c4e3db209ec7dc1e2c9553cp+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f27794c3b05fp+512), LIT (0x7.480c4e3db209ec7dc1e2c9553ep+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x1.19435caffa9f87973a2c8fcfdd8p+512), LIT (0x7.480c4e3db20a055a03fc06b13ep+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f87973a2c8fcfdd8p+512), LIT (0x7.480c4e3db20a055a03fc06b14p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f87973a2c8fcfdd8p+512), LIT (0x7.480c4e3db20a055a03fc06b13ep+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f87973a2c8fcfdep+512), LIT (0x7.480c4e3db20a055a03fc06b14p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020 + 0xf.fffffp+124 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffffbffffffffffffcp+508), LIT (0x7.fffff80000001fffffep-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x7.fffff80000001fffffep-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffffffffffffcp+508), LIT (0x7.fffff80000001fffffep-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x7.fffff80000001fffffe0000002p-388), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + +0 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x0p+0), { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffep+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x4p-1076 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x4p-1076), { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffep+508), LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0x8p-152 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0x8p-152), { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x4.00000000000008p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x4.00000000000008p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x4.00000000000008p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffep+508), LIT (0x4.00000000000008000000000002p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.19435caffa9f88803bb657861e8p+512), LIT (0x7.480c4e3db209e2319866075d4ep+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f88803bb657861fp+512), LIT (0x7.480c4e3db209e2319866075d5p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f88803bb657861e8p+512), LIT (0x7.480c4e3db209e2319866075d4ep+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f88803bb657861fp+512), LIT (0x7.480c4e3db209e2319866075d5p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x1.19435caffa9f8924fe4e23a59d8p+512), LIT (0x7.480c4e3db209fb0dda7f44b95p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f8924fe4e23a59d8p+512), LIT (0x7.480c4e3db209fb0dda7f44b95p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f8924fe4e23a59d8p+512), LIT (0x7.480c4e3db209fb0dda7f44b95p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f8924fe4e23a59ep+512), LIT (0x7.480c4e3db209fb0dda7f44b952p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020 + 0xf.fffffp+124 i", LIT (0xf.ffffffffffffbffffffffffffcp+1020), LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x7.fffff80000000ffffffp-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x7.fffff80000000ffffff0000002p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdffffffffffffcp+508), LIT (0x7.fffff80000000ffffffp-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffep+508), LIT (0x7.fffff80000000ffffff0000002p-388), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + +0 i", LIT (0xf.fffffp+124), LIT (0x0p+0), { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0x1p+0 i", LIT (0xf.fffffp+124), LIT (0x1p+0), { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x8.0000040000030000028000023p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x8.0000040000030000028000023p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x8.0000040000030000028000023p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x8.00000400000300000280000234p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0x4p-1076 i", LIT (0xf.fffffp+124), LIT (0x4p-1076), { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0x8.8p-512 i", LIT (0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x4.40000220000198000154000128p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.4000022000019800015400012ap-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x4.40000220000198000154000128p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.4000022000019800015400012ap-576), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0x8p+1020 i", LIT (0xf.fffffp+124), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffep+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffffffffffffffep+508), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000004p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0x8p-152 i", LIT (0xf.fffffp+124), LIT (0x8p-152), { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x4.00000200000180000140000118p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.00000200000180000140000118p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff5cp+60), LIT (0x4.00000200000180000140000118p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffffeffffff6p+60), LIT (0x4.0000020000018000014000011ap-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0xe.7e0c2p+116 i", LIT (0xf.fffffp+124), LIT (0xe.7e0c2p+116), { LIT (0x1.000019c0e5da25586e536f88f3p+64), LIT (0x7.3f055562b51cd3bfc904f1d6aep+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da25586e536f88f3p+64), LIT (0x7.3f055562b51cd3bfc904f1d6aep+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da25586e536f88f3p+64), LIT (0x7.3f055562b51cd3bfc904f1d6aep+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da25586e536f88f38p+64), LIT (0x7.3f055562b51cd3bfc904f1d6bp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.fffffp+124), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), LIT (0xb.504f333f9de61b045b0b9cbfb8p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), LIT (0xb.504f333f9de61b045b0b9cbfbcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0xf.ffffffffffffbffffffffffffcp+1020 i", LIT (0xf.fffffp+124), LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xb.504f333f9de631a4f9721bfb84p+508), LIT (0xb.504f333f9de631a4f9721bfb84p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb88p+508), LIT (0xb.504f333f9de631a4f9721bfb88p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb84p+508), LIT (0xb.504f333f9de631a4f9721bfb84p+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de631a4f9721bfb88p+508), LIT (0xb.504f333f9de631a4f9721bfb88p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124 + 0xf.fffffp+124 i", LIT (0xf.fffffp+124), LIT (0xf.fffffp+124), { LIT (0x1.19435c2358f11031c99a444e918p+64), LIT (0x7.480c4a99abe201c363daba1d6ap+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11031c99a444e92p+64), LIT (0x7.480c4a99abe201c363daba1d6ap+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11031c99a444e918p+64), LIT (0x7.480c4a99abe201c363daba1d6ap+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11031c99a444e92p+64), LIT (0x7.480c4a99abe201c363daba1d6cp+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fp+1020 + +0 i", LIT (0xf.fp+1020), LIT (0x0p+0), { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e318p+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fp+1020 + 0x8.8p-512 i", LIT (0xf.fp+1020), LIT (0x8.8p-512), { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x4.422199552a8c8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x4.422199552a8ccp-1024), UNDERFLOW_EXCEPTION }, { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x4.422199552a8c8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0xf.f7fdfeff5f8fabbdca3329e318p+508), LIT (0x4.422199552a8ccp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fp+1020 + 0x8p-152 i", LIT (0xf.fp+1020), LIT (0x8p-152), { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x4.0201814118fce7d749d6a119dep-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x4.0201814118fce7d749d6a119ep-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+508), LIT (0x4.0201814118fce7d749d6a119dep-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e318p+508), LIT (0x4.0201814118fce7d749d6a119ep-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fp+124 + 0x8.8p-64 i", LIT (0xf.fp+124), LIT (0x8.8p-64), { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+60), LIT (0x4.422199552a8cb654be740b2b7cp-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+60), LIT (0x4.422199552a8cb654be740b2b7ep-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e314p+60), LIT (0x4.422199552a8cb654be740b2b7cp-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbdca3329e318p+60), LIT (0x4.422199552a8cb654be740b2b7ep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 - 0x4.0000000000000008p-16384 i", LIT (-0x0p+0), LIT (-0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (-0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (-0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (-0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (-0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 - 0x4.0000000000004p-1024 i", LIT (-0x0p+0), LIT (-0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcd458p-512), LIT (-0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd45ap-512), LIT (-0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd458p-512), LIT (-0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd45ap-512), LIT (-0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 - 0x4p-1076 i", LIT (-0x0p+0), LIT (-0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef32428p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 - 0x4p-16384 i", LIT (-0x0p+0), LIT (-0x4p-16384), { LIT (0x1.6a09e667f3bcc908p-8192), LIT (-0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (-0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (-0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (-0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 - 0x8p-152 i", LIT (-0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0 + 0x8p-152 i", LIT (-0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.65c7ac7c97a25p-176 - 0x8p-152 i", LIT (-0x1.65c7ac7c97a25p-176), LIT (-0x8p-152), { LIT (0x1.ffffffd3470a726p-76), LIT (-0x2.0000002cb8f59188p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a7262p-76), LIT (-0x2.0000002cb8f59188p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a726p-76), LIT (-0x2.0000002cb8f59184p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a7262p-76), LIT (-0x2.0000002cb8f59184p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.9edb24c83e22cp-172 - 0x8p-152 i", LIT (-0x1.9edb24c83e22cp-172), LIT (-0x8p-152), { LIT (0x1.fffffcc249b90fccp-76), LIT (-0x2.0000033db64c30c8p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcep-76), LIT (-0x2.0000033db64c30c4p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fccp-76), LIT (-0x2.0000033db64c30c4p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcep-76), LIT (-0x2.0000033db64c30c4p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 - 0x2p-16384 i", LIT (-0x1p+0), LIT (-0x2p-16384), { LIT (0xf.ffffffffffffff8p-16388), LIT (-0x1.0000000000000002p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffff8p-16388), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 - 0x4p-1024 i", LIT (-0x1p+0), LIT (-0x4p-1024), { LIT (0x1.fffffffffffffffep-1024), LIT (-0x1.0000000000000002p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-1024), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 - 0x4p-128 i", LIT (-0x1p+0), LIT (-0x4p-128), { LIT (0x1.fffffffffffffffep-128), LIT (-0x1.0000000000000002p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 - 0x4p-16384 i", LIT (-0x1p+0), LIT (-0x4p-16384), { LIT (0x1.fffffffffffffff8p-16384), LIT (-0x1.0000000000000002p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffff8p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 - 0x8p-972 i", LIT (-0x1p+0), LIT (-0x8p-972), { LIT (0x3.fffffffffffffffcp-972), LIT (-0x1.0000000000000002p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-972), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 + +0 i", LIT (-0x1p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 + 0x2p-16384 i", LIT (-0x1p+0), LIT (0x2p-16384), { LIT (0xf.ffffffffffffff8p-16388), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffff8p-16388), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (0x1.0000000000000002p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 + 0x4p-1024 i", LIT (-0x1p+0), LIT (0x4p-1024), { LIT (0x1.fffffffffffffffep-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 + 0x4p-128 i", LIT (-0x1p+0), LIT (0x4p-128), { LIT (0x1.fffffffffffffffep-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 + 0x4p-16384 i", LIT (-0x1p+0), LIT (0x4p-16384), { LIT (0x1.fffffffffffffff8p-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffff8p-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), LIT (0x1.0000000000000002p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0 + 0x8p-972 i", LIT (-0x1p+0), LIT (0x8p-972), { LIT (0x3.fffffffffffffffcp-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.927275f6febb6p-184 + 0x8p-152 i", LIT (-0x2.927275f6febb6p-184), LIT (0x8p-152), { LIT (0x1.ffffffffadb1b14p-76), LIT (0x2.00000000524e4ebcp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b142p-76), LIT (0x2.00000000524e4ecp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b14p-76), LIT (0x2.00000000524e4ebcp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b142p-76), LIT (0x2.00000000524e4ecp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (0xe.55ec7a5ee26873fp-4), LIT (-0x1.ac950b37094a5a96p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26874p-4), LIT (-0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fp-4), LIT (-0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26874p-4), LIT (-0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p+0 + 0x3p+0 i", LIT (-0x2p+0), LIT (0x3p+0), { LIT (0xe.55ec7a5ee26873fp-4), LIT (0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26874p-4), LIT (0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fp-4), LIT (0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26874p-4), LIT (0x1.ac950b37094a5a96p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.0000000000000008p-16384 - 0 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000000004p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.0000000000000008p-16384 - 0x4.0000000000000008p-16384 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4.0000000000000008p-16384), { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16b4p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.0000000000000008p-16384 - 0x4p-1076 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef32428p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.0000000000000008p-16384 - 0x4p-16384 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4p-16384), { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16b4p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.0000000000000008p-16384 - 0x8p-152 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x8p-152), { LIT (0x1.fffffffffffffffep-76), LIT (-0x2.0000000000000004p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.0000000000004p-1024 - 0 i", LIT (-0x4.0000000000004p-1024), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000001p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000001p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000ffcp-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000ffcp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.0000000000004p-1024 - 0x4.0000000000004p-1024 i", LIT (-0x4.0000000000004p-1024), LIT (-0x4.0000000000004p-1024), { LIT (0xe.90189c7b641487bp-516), LIT (-0x2.3286b95ff53f2844p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487cp-516), LIT (-0x2.3286b95ff53f2844p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487bp-516), LIT (-0x2.3286b95ff53f284p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487cp-516), LIT (-0x2.3286b95ff53f284p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.0000000000004p-1024 - 0x8p-152 i", LIT (-0x4.0000000000004p-1024), LIT (-0x8p-152), { LIT (0x1.fffffffffffffffep-76), LIT (-0x2.0000000000000004p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.000008p-128 - 0x4.000008p-128 i", LIT (-0x4.000008p-128), LIT (-0x4.000008p-128), { LIT (0xe.9018ab0b7ca9469p-68), LIT (-0x2.3286bb927bf75d64p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca9469p-68), LIT (-0x2.3286bb927bf75d6p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca9469p-68), LIT (-0x2.3286bb927bf75d6p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca946ap-68), LIT (-0x2.3286bb927bf75d6p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.15ca1p+0 - 0x8p-152 i", LIT (-0x4.15ca1p+0), LIT (-0x8p-152), { LIT (0x1.faa35a1b5eb2277cp-152), LIT (-0x2.056b2cd84231ea6cp+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277cp-152), LIT (-0x2.056b2cd84231ea6cp+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277cp-152), LIT (-0x2.056b2cd84231ea68p+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277ep-152), LIT (-0x2.056b2cd84231ea68p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.827738p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.827738p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee6cd64cbb62p-4), LIT (-0x1.02a876fc905207ccp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb63p-4), LIT (-0x1.02a876fc905207ccp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb62p-4), LIT (-0x1.02a876fc905207cap+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb63p-4), LIT (-0x1.02a876fc905207cap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.82773b736291p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82773b736291p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee5f5a36814cp-4), LIT (-0x1.02a8770c69a38ebap+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814dp-4), LIT (-0x1.02a8770c69a38eb8p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814cp-4), LIT (-0x1.02a8770c69a38eb8p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814dp-4), LIT (-0x1.02a8770c69a38eb8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.82774p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82774p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee4d93232a24p-4), LIT (-0x1.02a877214e9fe4cep+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a24p-4), LIT (-0x1.02a877214e9fe4ccp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a24p-4), LIT (-0x1.02a877214e9fe4ccp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a25p-4), LIT (-0x1.02a877214e9fe4ccp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.d0144005d7af4p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144005d7af4p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2657d0a037p+0), LIT (-0x2.0201143f4f66d96p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a037p+0), LIT (-0x2.0201143f4f66d95cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a037p+0), LIT (-0x2.0201143f4f66d95cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a0372p+0), LIT (-0x2.0201143f4f66d95cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.d01448p-4 - 0x7.c19148p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2559bb4b70cp+0), LIT (-0x2.0201144fd174462cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70cp+0), LIT (-0x2.0201144fd174462cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70cp+0), LIT (-0x2.0201144fd1744628p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70ep+0), LIT (-0x2.0201144fd1744628p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.d01448p-4 - 0x7.c1915p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c1915p+0), { LIT (0x1.ee74d35e7dfe1b3cp+0), LIT (-0x2.0201154ea0e0412cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cp+0), LIT (-0x2.0201154ea0e0412cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cp+0), LIT (-0x2.0201154ea0e04128p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3ep+0), LIT (-0x2.0201154ea0e04128p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4.d0144p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d26588ab7af2p+0), LIT (-0x2.0201143f434fabbcp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af2p+0), LIT (-0x2.0201143f434fabbcp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af2p+0), LIT (-0x2.0201143f434fabb8p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af4p+0), LIT (-0x2.0201143f434fabb8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076 - 0 i", LIT (-0x4p-1076), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076 - 0x4.0000000000000008p-16384 i", LIT (-0x4p-1076), LIT (-0x4.0000000000000008p-16384), { LIT (0x4p-15848), LIT (-0x8.000000000000001p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076 - 0x4p-1076 i", LIT (-0x4p-1076), LIT (-0x4p-1076), { LIT (0x3.a406271ed90504ccp-540), LIT (-0x8.ca1ae57fd4fc5acp-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504dp-540), LIT (-0x8.ca1ae57fd4fc5acp-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504ccp-540), LIT (-0x8.ca1ae57fd4fc5abp-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504dp-540), LIT (-0x8.ca1ae57fd4fc5abp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076 - 0x4p-16384 i", LIT (-0x4p-1076), LIT (-0x4p-16384), { LIT (0x3.fffffffffffffffcp-15848), LIT (-0x8.000000000000001p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076 - 0x8p-152 i", LIT (-0x4p-1076), LIT (-0x8p-152), { LIT (0x1.fffffffffffffffep-76), LIT (-0x2.0000000000000004p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384 - 0 i", LIT (-0x4p-16384), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384 - 0x4.0000000000000008p-16384 i", LIT (-0x4p-16384), LIT (-0x4.0000000000000008p-16384), { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16acp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414136p-8196), LIT (-0x2.3286b95ff53f16acp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384 - 0x4p-1076 i", LIT (-0x4p-16384), LIT (-0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef32428p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384 - 0x4p-16384 i", LIT (-0x4p-16384), LIT (-0x4p-16384), { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16acp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16acp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384 - 0x8p-152 i", LIT (-0x4p-16384), LIT (-0x8p-152), { LIT (0x1.fffffffffffffffep-76), LIT (-0x2.0000000000000004p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.31291c9fdae04p-160 - 0x8p-152 i", LIT (-0x7.31291c9fdae04p-160), LIT (-0x8p-152), { LIT (0x1.ff1a0ead4f6b13dp-76), LIT (-0x2.00e658c5f71cca9cp-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13dp-76), LIT (-0x2.00e658c5f71cca98p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13dp-76), LIT (-0x2.00e658c5f71cca98p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13d2p-76), LIT (-0x2.00e658c5f71cca98p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.915fa8p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fa8p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c32571e2b8ea0a1p-4), LIT (-0x1.3392ad649c5855bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a2p-4), LIT (-0x1.3392ad649c5855bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a1p-4), LIT (-0x1.3392ad649c5855aep+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a2p-4), LIT (-0x1.3392ad649c5855aep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.915fafbe9f588p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fafbe9f588p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c325704e2c61d1ap-4), LIT (-0x1.3392ad837265581p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1ap-4), LIT (-0x1.3392ad837265581p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1ap-4), LIT (-0x1.3392ad837265580ep+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1bp-4), LIT (-0x1.3392ad837265580ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.915fbp-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fbp-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c3257040d54fb3cp-4), LIT (-0x1.3392ad8476b45bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3dp-4), LIT (-0x1.3392ad8476b45afep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3cp-4), LIT (-0x1.3392ad8476b45afep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3dp-4), LIT (-0x1.3392ad8476b45afep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8.ec8932bf5603p-172 + 0x8p-152 i", LIT (-0x8.ec8932bf5603p-172), LIT (0x8p-152), { LIT (0x1.ffffee26edea2476p-76), LIT (0x2.000011d912b521c8p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea2478p-76), LIT (0x2.000011d912b521c8p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea2476p-76), LIT (0x2.000011d912b521c8p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea2478p-76), LIT (0x2.000011d912b521ccp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 - 0 i", LIT (-0x8p-152), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 - 0x1.818bccp+0 i", LIT (-0x8p-152), LIT (-0x1.818bccp+0), { LIT (0xd.e25fb98f8390a02p-4), LIT (-0xd.e25fb98f8390a03p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a02p-4), LIT (-0xd.e25fb98f8390a02p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a02p-4), LIT (-0xd.e25fb98f8390a02p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a03p-4), LIT (-0xd.e25fb98f8390a02p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 - 0x2.c832ff5b163af0dcp-2444 i", LIT (-0x8p-152), LIT (-0x2.c832ff5b163af0dcp-2444), { LIT (0x7.de674fc19752a2c8p-2372), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2dp-2372), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2c8p-2372), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2dp-2372), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 - 0x4.0000000000000008p-16384 i", LIT (-0x8p-152), LIT (-0x4.0000000000000008p-16384), { LIT (0xb.504f333f9de6485p-16312), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6486p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6486p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 - 0x4.0000000000004p-1024 i", LIT (-0x8p-152), LIT (-0x4.0000000000004p-1024), { LIT (0xb.504f333f9de6fd4p-952), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd5p-952), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd4p-952), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd5p-952), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 - 0x4p-1076 i", LIT (-0x8p-152), LIT (-0x4p-1076), { LIT (0xb.504f333f9de6484p-1004), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-1004), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-1004), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-1004), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 - 0x4p-16384 i", LIT (-0x8p-152), LIT (-0x4p-16384), { LIT (0xb.504f333f9de6484p-16312), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 - 0x8p-152 i", LIT (-0x8p-152), LIT (-0x8p-152), { LIT (0x1.49852f983efdd57ap-76), LIT (-0x3.1b884327ab8057e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57cp-76), LIT (-0x3.1b884327ab8057e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57ap-76), LIT (-0x3.1b884327ab8057ep-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57cp-76), LIT (-0x3.1b884327ab8057ep-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152 + 0x8p-152 i", LIT (-0x8p-152), LIT (0x8p-152), { LIT (0x1.49852f983efdd57ap-76), LIT (0x3.1b884327ab8057ep-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57cp-76), LIT (0x3.1b884327ab8057e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57ap-76), LIT (0x3.1b884327ab8057ep-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57cp-76), LIT (0x3.1b884327ab8057e4p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x9.0a61a7b482d28p-168 - 0x8p-152 i", LIT (-0x9.0a61a7b482d28p-168), LIT (-0x8p-152), { LIT (0x1.fffedeb41cc4e764p-76), LIT (-0x2.0001214c86b1abcp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764p-76), LIT (-0x2.0001214c86b1abbcp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764p-76), LIT (-0x2.0001214c86b1abbcp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e766p-76), LIT (-0x2.0001214c86b1abbcp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xb.e2bc1cd6eaa7p-180 + 0x8p-152 i", LIT (-0xb.e2bc1cd6eaa7p-180), LIT (0x8p-152), { LIT (0x1.ffffffe83a87c6dep-76), LIT (0x2.00000017c5783a38p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6ep-76), LIT (0x2.00000017c5783a3cp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6dep-76), LIT (0x2.00000017c5783a38p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6ep-76), LIT (0x2.00000017c5783a3cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xd.e1d5fp-4 - 0x1.054226p+4 i", LIT (-0xd.e1d5fp-4), LIT (-0x1.054226p+4), { LIT (0x2.c84e99e2df484b1p+0), LIT (-0x2.ef2930261e97de9p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b14p+0), LIT (-0x2.ef2930261e97de9p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b1p+0), LIT (-0x2.ef2930261e97de8cp+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b14p+0), LIT (-0x2.ef2930261e97de8cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xe.6432ap-4 + 0xe.8175p-4 i", LIT (-0xe.6432ap-4), LIT (0xe.8175p-4), { LIT (0x6.f3d482a6e0b03b9p-4), LIT (0x1.0b0f83813dfbbb8cp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b98p-4), LIT (0x1.0b0f83813dfbbb8ep+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b9p-4), LIT (0x1.0b0f83813dfbbb8cp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b98p-4), LIT (0x1.0b0f83813dfbbb8ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xe.735dbp+0 - 0x5.26cb98p+40 i", LIT (-0xe.735dbp+0), LIT (-0x5.26cb98p+40), { LIT (0x1.9adc1d93b4e9b398p+20), LIT (-0x1.9adc1d93b96a3568p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398p+20), LIT (-0x1.9adc1d93b96a3566p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398p+20), LIT (-0x1.9adc1d93b96a3566p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b39ap+20), LIT (-0x1.9adc1d93b96a3566p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020 + +0 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0x2.00000000000008p-1588), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x2.00000000000008p-1588), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x2.00000000000008p-1588), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000804p-1588), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020 + 0x8.8p-8192 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x8.8p-8192), { LIT (0x4.40000000000011p-8704), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x4.40000000000011p-8704), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.40000000000011p-8704), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x4.4000000000001108p-8704), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001008p-664), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124 + +0 i", LIT (-0xf.fffffp+124), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124 + 0x4p-1076 i", LIT (-0xf.fffffp+124), LIT (0x4p-1076), { LIT (0x2.000001000000cp-1140), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000cp-1140), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000cp-1140), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000c004p-1140), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124 + 0x8.8p-512 i", LIT (-0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0x4.40000220000198p-576), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198p-576), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198p-576), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000019808p-576), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124 + 0x8.8p-8192 i", LIT (-0xf.fffffp+124), LIT (0x8.8p-8192), { LIT (0x4.40000220000198p-8256), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198p-8256), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198p-8256), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000019808p-8256), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124 + 0x8p-152 i", LIT (-0xf.fffffp+124), LIT (0x8p-152), { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018008p-216), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fp+1020 + +0 i", LIT (-0xf.fp+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fp+1020 + 0x8.8p-512 i", LIT (-0xf.fp+1020), LIT (0x8.8p-512), { LIT (0x4.422199552a8cb65p-1024), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-1024), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb65p-1024), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-1024), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fp+1020 + 0x8p-152 i", LIT (-0xf.fp+1020), LIT (0x8p-152), { LIT (0x4.0201814118fce7dp-664), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d8p-664), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7dp-664), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d8p-664), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fp+124 + 0x8.8p-64 i", LIT (-0xf.fp+124), LIT (0x8.8p-64), { LIT (0x4.422199552a8cb65p-128), LIT (0xf.f7fdfeff5f8fabbp+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-128), LIT (0xf.f7fdfeff5f8fabcp+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb65p-128), LIT (0xf.f7fdfeff5f8fabbp+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-128), LIT (0xf.f7fdfeff5f8fabcp+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fp+16380 + +0 i", LIT (-0xf.fp+16380), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fp+16380 + 0x4p-1076 i", LIT (-0xf.fp+16380), LIT (0x4p-1076), { LIT (0x2.0100c0a08c7e73e8p-9268), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73ecp-9268), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73e8p-9268), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73ecp-9268), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fp+16380 + 0x8.8p-8192 i", LIT (-0xf.fp+16380), LIT (0x8.8p-8192), { LIT (0x4.422199552a8cb65p-16384), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-16384), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb65p-16384), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-16384), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fp+16380 + 0x8p-152 i", LIT (-0xf.fp+16380), LIT (0x8p-152), { LIT (0x4.0201814118fce7dp-8344), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d8p-8344), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7dp-8344), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d8p-8344), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x1p+0 i", LIT (0x0p+0), LIT (-0x1p+0), { LIT (0xb.504f333f9de6484p-4), LIT (-0xb.504f333f9de6485p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-4), LIT (-0xb.504f333f9de6484p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-4), LIT (-0xb.504f333f9de6484p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-4), LIT (-0xb.504f333f9de6484p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x2p+0 i", LIT (0x0p+0), LIT (0x2p+0), { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4.0000000000000008p-16384 i", LIT (0x0p+0), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4.000000000000001p-16384 i", LIT (0x0p+0), LIT (0x4.000000000000001p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4.0000000000004p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcd458p-512), LIT (0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd45ap-512), LIT (0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd458p-512), LIT (0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd45ap-512), LIT (0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4.0000000000008p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bcdfa8p-512), LIT (0x1.6a09e667f3bcdfa8p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfaap-512), LIT (0x1.6a09e667f3bcdfaap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa8p-512), LIT (0x1.6a09e667f3bcdfa8p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfaap-512), LIT (0x1.6a09e667f3bcdfaap-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x4p-16384 i", LIT (0x0p+0), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc908p-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p+1020 i", LIT (0x0p+0), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p+16380 i", LIT (0x0p+0), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p-1076 i", LIT (0x0p+0), LIT (0x8p-1076), { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p-16444 i", LIT (0x0p+0), LIT (0x8p-16444), { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0x8p-16448 i", LIT (0x0p+0), LIT (0x8p-16448), { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x0p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0 + 0xf.fffffp+124 i", LIT (0x0p+0), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0221e29d5a3cdp-188 - 0x8p-152 i", LIT (0x1.0221e29d5a3cdp-188), LIT (-0x8p-152), { LIT (0x2.00000000020443c4p-76), LIT (-0x1.fffffffffdfbbc3cp-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c4p-76), LIT (-0x1.fffffffffdfbbc3ap-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c4p-76), LIT (-0x1.fffffffffdfbbc3ap-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c8p-76), LIT (-0x1.fffffffffdfbbc3ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.d60caep+0 + 0x7.a7d468p+0 i", LIT (0x1.d60caep+0), LIT (0x7.a7d468p+0), { LIT (0x2.3409baa805bc9528p+0), LIT (0x1.bcc10b50fddb6aeap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952cp+0), LIT (0x1.bcc10b50fddb6aeap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc9528p+0), LIT (0x1.bcc10b50fddb6aeap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952cp+0), LIT (0x1.bcc10b50fddb6aecp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.f9610ap+4 + 0x9.87716p+4 i", LIT (0x1.f9610ap+4), LIT (0x9.87716p+4), { LIT (0x9.ad5033142bab316p+0), LIT (0x7.e0b144c043868bep+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab316p+0), LIT (0x7.e0b144c043868bep+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab316p+0), LIT (0x7.e0b144c043868bep+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab317p+0), LIT (0x7.e0b144c043868be8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 - 0x2p-16384 i", LIT (0x1p+0), LIT (-0x2p-16384), { LIT (0x1p+0), LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0xf.ffffffffffffff8p-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (-0xf.ffffffffffffff8p-16388), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 - 0x4p-1024 i", LIT (0x1p+0), LIT (-0x4p-1024), { LIT (0x1p+0), LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (-0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 - 0x4p-128 i", LIT (0x1p+0), LIT (-0x4p-128), { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (-0x1.fffffffffffffffep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 - 0x4p-16384 i", LIT (0x1p+0), LIT (-0x4p-16384), { LIT (0x1p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 - 0x8p-972 i", LIT (0x1p+0), LIT (-0x8p-972), { LIT (0x1p+0), LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (-0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0x2p-16384 i", LIT (0x1p+0), LIT (0x2p-16384), { LIT (0x1p+0), LIT (0xf.ffffffffffffff8p-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xf.ffffffffffffff8p-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0x1p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0x4p-1024 i", LIT (0x1p+0), LIT (0x4p-1024), { LIT (0x1p+0), LIT (0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x2p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0x4p-128 i", LIT (0x1p+0), LIT (0x4p-128), { LIT (0x1p+0), LIT (0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0x4p-16384 i", LIT (0x1p+0), LIT (0x4p-16384), { LIT (0x1p+0), LIT (0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + 0x8p-972 i", LIT (0x1p+0), LIT (0x8p-972), { LIT (0x1p+0), LIT (0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+4 - 0x1.ep+4 i", LIT (0x1p+4), LIT (-0x1.ep+4), { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-16440 + +0 i", LIT (0x1p-16440), LIT (0x0p+0), { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-16440 + 0x4p-1076 i", LIT (0x1p-16440), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-16440 + 0x8p-152 i", LIT (0x1p-16440), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-16440 + 0x8p-16444 i", LIT (0x1p-16440), LIT (0x8p-16444), { LIT (0x1.077225f1da571bacp-8220), LIT (0x3.e30ee78adee42e5cp-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571bacp-8220), LIT (0x3.e30ee78adee42e6p-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571bacp-8220), LIT (0x3.e30ee78adee42e5cp-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571baep-8220), LIT (0x3.e30ee78adee42e6p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-500 + +0 i", LIT (0x1p-500), LIT (0x0p+0), { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-500 + 0x4p-1076 i", LIT (0x1p-500), LIT (0x4p-1076), { LIT (0x4p-252), LIT (0x7.fffffffffffffff8p-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x8p-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x7.fffffffffffffff8p-828), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-252), LIT (0x8p-828), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-500 + 0x8p-152 i", LIT (0x1p-500), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-5000 + +0 i", LIT (0x1p-5000), LIT (0x0p+0), { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-5000 + 0x4p-1076 i", LIT (0x1p-5000), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-5000 + 0x8p-152 i", LIT (0x1p-5000), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-5000 + 0x8p-16448 i", LIT (0x1p-5000), LIT (0x8p-16448), { LIT (0x1p-2500), LIT (0x3.fffffffffffffffcp-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x4p-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x3.fffffffffffffffcp-13948), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-2500), LIT (0x4p-13948), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-148 + 0x2p-148 i", LIT (0x2p-148), LIT (0x2p-148), { LIT (0x6.3710864f5700afcp-76), LIT (0x2.930a5f307dfbaaf4p-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc8p-76), LIT (0x2.930a5f307dfbaaf8p-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afcp-76), LIT (0x2.930a5f307dfbaaf4p-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc8p-76), LIT (0x2.930a5f307dfbaaf8p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db1f30939ceap+0), LIT (0xf.3d9236b503fee6p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939ceap+0), LIT (0xf.3d9236b503fee61p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939ceap+0), LIT (0xf.3d9236b503fee6p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939cecp+0), LIT (0xf.3d9236b503fee61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db809771ddap+0), LIT (0xf.3d923d93816780fp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda2p+0), LIT (0xf.3d923d93816781p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771ddap+0), LIT (0xf.3d923d93816780fp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda2p+0), LIT (0xf.3d923d93816781p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc0ba4f2875p+0), LIT (0xf.3d924761f5b5cfep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f28752p+0), LIT (0xf.3d924761f5b5cfep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f2875p+0), LIT (0xf.3d924761f5b5cfep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f28752p+0), LIT (0xf.3d924761f5b5cffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f0cp+0), LIT (0xf.3d92365a334569ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0ep+0), LIT (0xf.3d92365a334569ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0cp+0), LIT (0xf.3d92365a334569ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0ep+0), LIT (0xf.3d92365a334569fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05acf4p+0), LIT (0xf.3d923d38b0ae23ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4p+0), LIT (0xf.3d923d38b0ae23ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4p+0), LIT (0xf.3d923d38b0ae23ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf6p+0), LIT (0xf.3d923d38b0ae23fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c8652ap+0), LIT (0xf.3d92470724fc9f3p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652ap+0), LIT (0xf.3d92470724fc9f3p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652ap+0), LIT (0xf.3d92470724fc9f3p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652a2p+0), LIT (0xf.3d92470724fc9f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f8cp+0), LIT (0xf.3d92365a334562dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8cp+0), LIT (0xf.3d92365a334562ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8cp+0), LIT (0xf.3d92365a334562dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8ep+0), LIT (0xf.3d92365a334562ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ad72p+0), LIT (0xf.3d923d38b0ae1cdp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad74p+0), LIT (0xf.3d923d38b0ae1cep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad72p+0), LIT (0xf.3d923d38b0ae1cdp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad74p+0), LIT (0xf.3d923d38b0ae1cep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c86531ep+0), LIT (0xf.3d92470724fc982p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532p+0), LIT (0xf.3d92470724fc983p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86531ep+0), LIT (0xf.3d92470724fc982p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532p+0), LIT (0xf.3d92470724fc983p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f92p+0), LIT (0xf.3d92365a3345627p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f94p+0), LIT (0xf.3d92365a3345628p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f92p+0), LIT (0xf.3d92365a3345627p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f94p+0), LIT (0xf.3d92365a3345628p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ad7ap+0), LIT (0xf.3d923d38b0ae1c7p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7ap+0), LIT (0xf.3d923d38b0ae1c8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7ap+0), LIT (0xf.3d923d38b0ae1c7p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7cp+0), LIT (0xf.3d923d38b0ae1c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c865326p+0), LIT (0xf.3d92470724fc97dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865326p+0), LIT (0xf.3d92470724fc97dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865326p+0), LIT (0xf.3d92470724fc97dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865328p+0), LIT (0xf.3d92470724fc97ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f8p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2fdd855d18p+0), LIT (0xf.3d9235c88f9fa24p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d1ap+0), LIT (0xf.3d9235c88f9fa24p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d18p+0), LIT (0xf.3d9235c88f9fa24p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d1ap+0), LIT (0xf.3d9235c88f9fa25p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f8p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db914463967ep+0), LIT (0xf.3d923ca70d088e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967ep+0), LIT (0xf.3d923ca70d088e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967ep+0), LIT (0xf.3d923ca70d088e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463968p+0), LIT (0xf.3d923ca70d088e3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.f768f8p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc1c51e435bap+0), LIT (0xf.3d924675815750ap-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435bap+0), LIT (0xf.3d924675815750ap-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435bap+0), LIT (0xf.3d924675815750ap-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435bcp+0), LIT (0xf.3d924675815750bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000000008p-16384 + +0 i", LIT (0x4.0000000000000008p-16384), LIT (0x0p+0), { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-8192), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000000008p-16384 + 0x4.0000000000000008p-16384 i", LIT (0x4.0000000000000008p-16384), LIT (0x4.0000000000000008p-16384), { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b4p-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000000008p-16384 + 0x4p-1076 i", LIT (0x4.0000000000000008p-16384), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000000008p-16384 + 0x4p-16384 i", LIT (0x4.0000000000000008p-16384), LIT (0x4p-16384), { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b4p-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000000008p-16384 + 0x8p-152 i", LIT (0x4.0000000000000008p-16384), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000004p-1024 + +0 i", LIT (0x4.0000000000004p-1024), LIT (0x0p+0), { LIT (0x2.0000000000000ffcp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001p-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000ffcp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001p-512), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000004p-1024 + 0x4.0000000000004p-1024 i", LIT (0x4.0000000000004p-1024), LIT (0x4.0000000000004p-1024), { LIT (0x2.3286b95ff53f284p-512), LIT (0xe.90189c7b641487bp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f2844p-512), LIT (0xe.90189c7b641487cp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f284p-512), LIT (0xe.90189c7b641487bp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f2844p-512), LIT (0xe.90189c7b641487cp-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.0000000000004p-1024 + 0x8p-152 i", LIT (0x4.0000000000004p-1024), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.000008p-128 + 0x4.000008p-128 i", LIT (0x4.000008p-128), LIT (0x4.000008p-128), { LIT (0x2.3286bb927bf75d6p-64), LIT (0xe.9018ab0b7ca9469p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d6p-64), LIT (0xe.9018ab0b7ca9469p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d6p-64), LIT (0xe.9018ab0b7ca9469p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d64p-64), LIT (0xe.9018ab0b7ca946ap-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x4.0000000000000008p-16384 i", LIT (0x4p-1076), LIT (0x4.0000000000000008p-16384), { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x4.000000000000001p-16384 i", LIT (0x4p-1076), LIT (0x4.000000000000001p-16384), { LIT (0x8p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.000000000000001p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x4.000000000000001p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x4.0000000000004p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcdfa8p-512), LIT (0x1.6a09e667f3bcc908p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfaap-512), LIT (0x1.6a09e667f3bcc908p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa8p-512), LIT (0x1.6a09e667f3bcc908p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfaap-512), LIT (0x1.6a09e667f3bcc90ap-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x4.0000000000008p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bceaf8p-512), LIT (0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceafap-512), LIT (0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceaf8p-512), LIT (0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceafap-512), LIT (0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x4p-1076 i", LIT (0x4p-1076), LIT (0x4p-1076), { LIT (0x8.ca1ae57fd4fc5abp-540), LIT (0x3.a406271ed90504ccp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5acp-540), LIT (0x3.a406271ed90504dp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5abp-540), LIT (0x3.a406271ed90504ccp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5acp-540), LIT (0x3.a406271ed90504dp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x4p-16384 i", LIT (0x4p-1076), LIT (0x4p-16384), { LIT (0x8p-540), LIT (0x3.fffffffffffffffcp-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x3.fffffffffffffffcp-15848), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x4p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x8p+1020 i", LIT (0x4p-1076), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x8p+16380 i", LIT (0x4p-1076), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x8p-152 i", LIT (0x4p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x8p-16444 i", LIT (0x4p-1076), LIT (0x8p-16444), { LIT (0x8p-540), LIT (0x7.fffffffffffffff8p-15908), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-15908), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x7.fffffffffffffff8p-15908), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x8p-15908), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0x8p-16448 i", LIT (0x4p-1076), LIT (0x8p-16448), { LIT (0x8p-540), LIT (0x7.fffffffffffffff8p-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x7.fffffffffffffff8p-15912), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x8p-15912), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0xf.ffffffffffff8p+1020 i", LIT (0x4p-1076), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076 + 0xf.fffffp+124 i", LIT (0x4p-1076), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384 + +0 i", LIT (0x4p-16384), LIT (0x0p+0), { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384 + 0x4.0000000000000008p-16384 i", LIT (0x4p-16384), LIT (0x4.0000000000000008p-16384), { LIT (0x2.3286b95ff53f16acp-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16acp-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414136p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384 + 0x4p-1076 i", LIT (0x4p-16384), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384 + 0x4p-16384 i", LIT (0x4p-16384), LIT (0x4p-16384), { LIT (0x2.3286b95ff53f16acp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16acp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384 + 0x8p-152 i", LIT (0x4p-16384), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-52 + 0x8p-152 i", LIT (0x4p-52), LIT (0x8p-152), { LIT (0x8p-28), LIT (0x7.fffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x7.fffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-28), LIT (0x8p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.39e238p+0 - 0x4.576278p-4 i", LIT (0x5.39e238p+0), LIT (-0x4.576278p-4), { LIT (0x2.496e354be8ff297cp+0), LIT (-0xf.2fef5df67620a01p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cp+0), LIT (-0xf.2fef5df67620ap-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cp+0), LIT (-0xf.2fef5df67620ap-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff298p+0), LIT (-0xf.2fef5df67620ap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.9cc21p-4 - 0x1.fb1ec8p+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec8p+0), { LIT (0x1.163c67724ff4a226p+0), LIT (-0xe.94bd3c203679a4dp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226p+0), LIT (-0xe.94bd3c203679a4dp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226p+0), LIT (-0xe.94bd3c203679a4cp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a228p+0), LIT (-0xe.94bd3c203679a4cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.9cc21p-4 - 0x1.fb1ec91b40dcdp+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec91b40dcdp+0), { LIT (0x1.163c67b277e8b48p+0), LIT (-0xe.94bd40e8718fd25p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b482p+0), LIT (-0xe.94bd40e8718fd25p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b48p+0), LIT (-0xe.94bd40e8718fd24p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b482p+0), LIT (-0xe.94bd40e8718fd24p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.9cc21p-4 - 0x1.fb1ecap+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ecap+0), { LIT (0x1.163c67e6476248eep+0), LIT (-0xe.94bd44c5182a0d5p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248eep+0), LIT (-0xe.94bd44c5182a0d4p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248eep+0), LIT (-0xe.94bd44c5182a0d4p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248fp+0), LIT (-0xe.94bd44c5182a0d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.b1a2e79e9c9acp-164 + 0x8p-152 i", LIT (0x6.b1a2e79e9c9acp-164), LIT (0x8p-152), { LIT (0x2.000d63729cf6c5d8p-76), LIT (0x1.fff29ce700d4355p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d8p-76), LIT (0x1.fff29ce700d4355p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d8p-76), LIT (0x1.fff29ce700d4355p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5dcp-76), LIT (0x1.fff29ce700d43552p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.7p+4 + 0x7.8p+4 i", LIT (0x7.7p+4), LIT (0x7.8p+4), { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+1020 + +0 i", LIT (0x8p+1020), LIT (0x0p+0), { LIT (0xb.504f333f9de6484p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+1020 + 0x4p-1076 i", LIT (0x8p+1020), LIT (0x4p-1076), { LIT (0xb.504f333f9de6484p+508), LIT (0x2.d413cccfe779921p-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x2.d413cccfe779921p-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x2.d413cccfe779921p-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+508), LIT (0x2.d413cccfe7799214p-1588), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+1020 + 0x8p-152 i", LIT (0x8p+1020), LIT (0x8p-152), { LIT (0xb.504f333f9de6484p+508), LIT (0x5.a827999fcef3242p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x5.a827999fcef3242p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x5.a827999fcef3242p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+508), LIT (0x5.a827999fcef32428p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+124 + 0x8p-152 i", LIT (0x8p+124), LIT (0x8p-152), { LIT (0xb.504f333f9de6484p+60), LIT (0x5.a827999fcef3242p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+60), LIT (0x5.a827999fcef3242p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+60), LIT (0x5.a827999fcef3242p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+60), LIT (0x5.a827999fcef32428p-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+16380 + +0 i", LIT (0x8p+16380), LIT (0x0p+0), { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+16380 + 0x4p-1076 i", LIT (0x8p+16380), LIT (0x4p-1076), { LIT (0xb.504f333f9de6484p+8188), LIT (0x2.d413cccfe779921p-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x2.d413cccfe779921p-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x2.d413cccfe779921p-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x2.d413cccfe7799214p-9268), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+16380 + 0x8p-152 i", LIT (0x8p+16380), LIT (0x8p-152), { LIT (0xb.504f333f9de6484p+8188), LIT (0x5.a827999fcef3242p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x5.a827999fcef3242p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x5.a827999fcef3242p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x5.a827999fcef32428p-8344), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+16380 + 0x8p-16448 i", LIT (0x8p+16380), LIT (0x8p-16448), { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-1076 + +0 i", LIT (0x8p-1076), LIT (0x0p+0), { LIT (0xb.504f333f9de6484p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-1076 + 0x8p-1076 i", LIT (0x8p-1076), LIT (0x8p-1076), { LIT (0xc.6e210c9eae015f8p-540), LIT (0x5.2614be60fbf755e8p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f9p-540), LIT (0x5.2614be60fbf755fp-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f8p-540), LIT (0x5.2614be60fbf755e8p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f9p-540), LIT (0x5.2614be60fbf755fp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-1076 + 0x8p-152 i", LIT (0x8p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 - 0x8p-152 i", LIT (0x8p-152), LIT (-0x8p-152), { LIT (0x3.1b884327ab8057ep-76), LIT (-0x1.49852f983efdd57cp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e4p-76), LIT (-0x1.49852f983efdd57cp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057ep-76), LIT (-0x1.49852f983efdd57ap-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e4p-76), LIT (-0x1.49852f983efdd57ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x2.d413cccfe779921p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x4.0000000000000008p-16384 i", LIT (0x8p-152), LIT (0x4.0000000000000008p-16384), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6485p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6486p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6485p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6486p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x4.000000000000001p-16384 i", LIT (0x8p-152), LIT (0x4.000000000000001p-16384), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6487p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6487p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6487p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6488p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x4.0000000000004p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000004p-1024), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6fd4p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6fd5p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6fd4p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6fd5p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x4.0000000000008p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000008p-1024), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de7b24p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de7b25p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de7b24p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de7b25p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x4.000008p-128 i", LIT (0x8p-152), LIT (0x4.000008p-128), { LIT (0x1.6a09e93c07882ee6p-64), LIT (0x1.6a09e667f3be3312p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee6p-64), LIT (0x1.6a09e667f3be3312p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee6p-64), LIT (0x1.6a09e667f3be3312p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee8p-64), LIT (0x1.6a09e667f3be3314p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x4.00001p-128 i", LIT (0x8p-152), LIT (0x4.00001p-128), { LIT (0x1.6a09eaa6116b0dcp-64), LIT (0x1.6a09e7d1fda3e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc2p-64), LIT (0x1.6a09e7d1fda3e602p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dcp-64), LIT (0x1.6a09e7d1fda3e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc2p-64), LIT (0x1.6a09e7d1fda3e602p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x4p-1076 i", LIT (0x8p-152), LIT (0x4p-1076), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6485p-1004), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x4p-16384 i", LIT (0x8p-152), LIT (0x4p-16384), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6485p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x7.8p-148 i", LIT (0x8p-152), LIT (0x7.8p-148), { LIT (0x8.02213e8d55a4ec3p-76), LIT (0x7.7e015d4e23f441b8p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec3p-76), LIT (0x7.7e015d4e23f441b8p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec3p-76), LIT (0x7.7e015d4e23f441b8p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec4p-76), LIT (0x7.7e015d4e23f441cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x8p+1020 i", LIT (0x8p-152), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x8p+124 i", LIT (0x8p-152), LIT (0x8p+124), { LIT (0x8p+60), LIT (0x7.fffffffffffffff8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x7.fffffffffffffff8p+60), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+60), LIT (0x8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x8p+16380 i", LIT (0x8p-152), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x8p-1076 i", LIT (0x8p-152), LIT (0x8p-1076), { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0x1.6a09e667f3bcc90ap-1000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x8p-152 i", LIT (0x8p-152), LIT (0x8p-152), { LIT (0x3.1b884327ab8057ep-76), LIT (0x1.49852f983efdd57ap-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e4p-76), LIT (0x1.49852f983efdd57cp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057ep-76), LIT (0x1.49852f983efdd57ap-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e4p-76), LIT (0x1.49852f983efdd57cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x8p-16444 i", LIT (0x8p-152), LIT (0x8p-16444), { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0x1.6a09e667f3bcc90ap-16368), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0x8p-16448 i", LIT (0x8p-152), LIT (0x8p-16448), { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0x1.6a09e667f3bcc90ap-16372), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0xf.ffffffffffff8p+1020 i", LIT (0x8p-152), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152 + 0xf.fffffp+124 i", LIT (0x8p-152), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + +0 i", LIT (0x8p-16448), LIT (0x0p+0), { LIT (0x2.d413cccfe779921p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-8224), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x4.0000000000000008p-16384 i", LIT (0x8p-16448), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x4.000000000000001p-16384 i", LIT (0x8p-16448), LIT (0x4.000000000000001p-16384), { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ep-8192), LIT (0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x4p-1076 i", LIT (0x8p-16448), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x4p-16384 i", LIT (0x8p-16448), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc906p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc906p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x8p+16380 i", LIT (0x8p-16448), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0x8p-152 i", LIT (0x8p-16448), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0xf.ffffffffffff8p+1020 i", LIT (0x8p-16448), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448 + 0xf.fffffp+124 i", LIT (0x8p-16448), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.0cf78272ed4f605cp+0), LIT (0x9.84953b9e67deb2fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605ep+0), LIT (0x9.84953b9e67deb3p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605cp+0), LIT (0x9.84953b9e67deb2fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605ep+0), LIT (0x9.84953b9e67deb3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xd.25d559ac5baap-168 + 0x8p-152 i", LIT (0xd.25d559ac5baap-168), LIT (0x8p-152), { LIT (0x2.0001a4bb58123fep-76), LIT (0x1.fffe5b4601a8450ep-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fep-76), LIT (0x1.fffe5b4601a8451p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fep-76), LIT (0x1.fffe5b4601a8450ep-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fe4p-76), LIT (0x1.fffe5b4601a8451p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.229827fe17d08p-4 + 0xd.849ecp-4 i", LIT (0xe.229827fe17d08p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00ac53515a8bep+0), LIT (0x6.96423e0f64027218p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8bep+0), LIT (0x6.96423e0f6402722p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8bep+0), LIT (0x6.96423e0f64027218p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8cp+0), LIT (0x6.96423e0f6402722p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.22982p-4 + 0xd.849ecp-4 i", LIT (0xe.22982p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00a8f88c3be4p+0), LIT (0x6.96423f67ee9c4538p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be4p+0), LIT (0x6.96423f67ee9c454p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be4p+0), LIT (0x6.96423f67ee9c4538p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be42p+0), LIT (0x6.96423f67ee9c454p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.22983p-4 + 0xd.849ecp-4 i", LIT (0xe.22983p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00afafb0445acp+0), LIT (0x6.96423cb6350011f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445aep+0), LIT (0x6.96423cb6350012p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445acp+0), LIT (0x6.96423cb6350011f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445aep+0), LIT (0x6.96423cb6350012p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.8p+16380 + 0x8p+16380 i", LIT (0xf.8p+16380), LIT (0x8p+16380), { LIT (0x1.03be61de0c283c96p+8192), LIT (0x3.f13db93133426b28p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c98p+8192), LIT (0x3.f13db93133426b28p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c96p+8192), LIT (0x3.f13db93133426b28p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c98p+8192), LIT (0x3.f13db93133426b2cp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.8p+16380 + 0xf.8p+16380 i", LIT (0xf.8p+16380), LIT (0xf.8p+16380), { LIT (0x1.14d561462f72313ap+8192), LIT (0x7.2ab0eef99eed6b18p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313cp+8192), LIT (0x7.2ab0eef99eed6b2p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313ap+8192), LIT (0x7.2ab0eef99eed6b18p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313cp+8192), LIT (0x7.2ab0eef99eed6b2p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.8p+16380 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.8p+16380), LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.bf7df5c6a788f0bp+8188), LIT (0x8.20c524036f3e2abp-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0cp+8188), LIT (0x8.20c524036f3e2abp-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bp+8188), LIT (0x8.20c524036f3e2abp-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0cp+8188), LIT (0x8.20c524036f3e2acp-7172), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.8p+16380 + 0xf.fffffp+124 i", LIT (0xf.8p+16380), LIT (0xf.fffffp+124), { LIT (0xf.bf7df5c6a788f0bp+8188), LIT (0x8.20c51be2aa1a684p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0cp+8188), LIT (0x8.20c51be2aa1a685p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bp+8188), LIT (0x8.20c51be2aa1a684p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0cp+8188), LIT (0x8.20c51be2aa1a685p-8068), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.a24adp+28 + 0x8.0f148p+36 i", LIT (0xf.a24adp+28), LIT (0x8.0f148p+36), { LIT (0x8.0f544aab1480595p+16), LIT (0x7.ffc0aea89479a128p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480596p+16), LIT (0x7.ffc0aea89479a128p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480595p+16), LIT (0x7.ffc0aea89479a128p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480596p+16), LIT (0x7.ffc0aea89479a13p+16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + +0 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0xf.ffffffffffffbffp+508), LIT (0x2.00000000000008p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x2.00000000000008p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x2.00000000000008p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x2.0000000000000804p-1588), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0x8.8p-8192 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8.8p-8192), { LIT (0xf.ffffffffffffbffp+508), LIT (0x4.40000000000011p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.40000000000011p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x4.40000000000011p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.4000000000001108p-8704), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0x8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p+1020), { LIT (0x1.077225f1da5717fcp+512), LIT (0x3.e30ee78adee43c44p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fep+512), LIT (0x3.e30ee78adee43c48p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fcp+512), LIT (0x3.e30ee78adee43c44p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fep+512), LIT (0x3.e30ee78adee43c48p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0x8p+16380 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0xf.ffffffffffffbffp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.0000000000001008p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0x8p-16448 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p-16448), { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffcp+508), LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0xf.8p+16380 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.8p+16380), { LIT (0xb.22b202b460e1ba2p+8188), LIT (0xb.22b202b460e1ba2p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba3p+8188), LIT (0xb.22b202b460e1ba3p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2p+8188), LIT (0xb.22b202b460e1ba2p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba3p+8188), LIT (0xb.22b202b460e1ba3p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.19435caffa9f86f2p+512), LIT (0x7.480c4e3db209ec78p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f2p+512), LIT (0x7.480c4e3db209ec8p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f2p+512), LIT (0x7.480c4e3db209ec78p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f4p+512), LIT (0x7.480c4e3db209ec8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020 + 0xf.fffffp+124 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffffbffp+508), LIT (0x7.fffff80000001ff8p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x7.fffff80000002p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x7.fffff80000001ff8p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x7.fffff80000002p-388), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + +0 i", LIT (0xf.fffffp+124), LIT (0x0p+0), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0x1p+0 i", LIT (0xf.fffffp+124), LIT (0x1p+0), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x8.000004000003001p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0x4p-1076 i", LIT (0xf.fffffp+124), LIT (0x4p-1076), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x2.000001000000cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x2.000001000000cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x2.000001000000cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x2.000001000000c004p-1140), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0x8.8p-512 i", LIT (0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.40000220000198p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.40000220000198p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.40000220000198p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.4000022000019808p-576), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0x8.8p-8192 i", LIT (0xf.fffffp+124), LIT (0x8.8p-8192), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.40000220000198p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.40000220000198p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.40000220000198p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.4000022000019808p-8256), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0x8p+1020 i", LIT (0xf.fffffp+124), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0x8p+16380 i", LIT (0xf.fffffp+124), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0x8p-152 i", LIT (0xf.fffffp+124), LIT (0x8p-152), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.0000020000018008p-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0x8p-16448 i", LIT (0xf.fffffp+124), LIT (0x8p-16448), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffep+60), LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0xe.7e0c2p+116 i", LIT (0xf.fffffp+124), LIT (0xe.7e0c2p+116), { LIT (0x1.000019c0e5da2558p+64), LIT (0x7.3f055562b51cd3b8p+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da2558p+64), LIT (0x7.3f055562b51cd3cp+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da2558p+64), LIT (0x7.3f055562b51cd3b8p+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da255ap+64), LIT (0x7.3f055562b51cd3cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0xf.8p+16380 i", LIT (0xf.fffffp+124), LIT (0xf.8p+16380), { LIT (0xb.22b202b460e1ba2p+8188), LIT (0xb.22b202b460e1ba2p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba3p+8188), LIT (0xb.22b202b460e1ba3p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2p+8188), LIT (0xb.22b202b460e1ba2p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba3p+8188), LIT (0xb.22b202b460e1ba3p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.fffffp+124), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124 + 0xf.fffffp+124 i", LIT (0xf.fffffp+124), LIT (0xf.fffffp+124), { LIT (0x1.19435c2358f1103p+64), LIT (0x7.480c4a99abe201cp+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11032p+64), LIT (0x7.480c4a99abe201cp+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f1103p+64), LIT (0x7.480c4a99abe201cp+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11032p+64), LIT (0x7.480c4a99abe201c8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fp+1020 + +0 i", LIT (0xf.fp+1020), LIT (0x0p+0), { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fp+1020 + 0x8.8p-512 i", LIT (0xf.fp+1020), LIT (0x8.8p-512), { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x4.422199552a8cb65p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x4.422199552a8cb658p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x4.422199552a8cb65p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x4.422199552a8cb658p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fp+1020 + 0x8p-152 i", LIT (0xf.fp+1020), LIT (0x8p-152), { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x4.0201814118fce7dp-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x4.0201814118fce7d8p-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x4.0201814118fce7dp-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x4.0201814118fce7d8p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fp+124 + 0x8.8p-64 i", LIT (0xf.fp+124), LIT (0x8.8p-64), { LIT (0xf.f7fdfeff5f8fabbp+60), LIT (0x4.422199552a8cb65p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+60), LIT (0x4.422199552a8cb658p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+60), LIT (0x4.422199552a8cb65p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+60), LIT (0x4.422199552a8cb658p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fp+16380 + +0 i", LIT (0xf.fp+16380), LIT (0x0p+0), { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fp+16380 + 0x4p-1076 i", LIT (0xf.fp+16380), LIT (0x4p-1076), { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x2.0100c0a08c7e73e8p-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x2.0100c0a08c7e73ecp-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x2.0100c0a08c7e73e8p-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x2.0100c0a08c7e73ecp-9268), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fp+16380 + 0x8.8p-8192 i", LIT (0xf.fp+16380), LIT (0x8.8p-8192), { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x4.422199552a8cb65p-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x4.422199552a8cb658p-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x4.422199552a8cb65p-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x4.422199552a8cb658p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fp+16380 + 0x8p-152 i", LIT (0xf.fp+16380), LIT (0x8p-152), { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x4.0201814118fce7dp-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x4.0201814118fce7d8p-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x4.0201814118fce7dp-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x4.0201814118fce7d8p-8344), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 - 0 i", LIT (-0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 - 0x4.0000000000000008p-16384 i", LIT (-0x0p+0), LIT (-0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (-0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (-0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (-0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (-0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 - 0x4.0000000000004p-1024 i", LIT (-0x0p+0), LIT (-0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcd458p-512), LIT (-0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd45ap-512), LIT (-0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd458p-512), LIT (-0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd45ap-512), LIT (-0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 - 0x4p-1076 i", LIT (-0x0p+0), LIT (-0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef32428p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 - 0x4p-16384 i", LIT (-0x0p+0), LIT (-0x4p-16384), { LIT (0x1.6a09e667f3bcc908p-8192), LIT (-0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (-0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (-0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (-0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 - 0x8p-152 i", LIT (-0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 + +0 i", LIT (-0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0 + 0x8p-152 i", LIT (-0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.65c7ac7c97a25p-176 - 0x8p-152 i", LIT (-0x1.65c7ac7c97a25p-176), LIT (-0x8p-152), { LIT (0x1.ffffffd3470a726p-76), LIT (-0x2.0000002cb8f59188p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a7262p-76), LIT (-0x2.0000002cb8f59188p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a726p-76), LIT (-0x2.0000002cb8f59184p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffd3470a7262p-76), LIT (-0x2.0000002cb8f59184p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.9edb24c83e22cp-172 - 0x8p-152 i", LIT (-0x1.9edb24c83e22cp-172), LIT (-0x8p-152), { LIT (0x1.fffffcc249b90fccp-76), LIT (-0x2.0000033db64c30c8p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcep-76), LIT (-0x2.0000033db64c30c4p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fccp-76), LIT (-0x2.0000033db64c30c4p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffcc249b90fcep-76), LIT (-0x2.0000033db64c30c4p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 - 0x2p-16384 i", LIT (-0x1p+0), LIT (-0x2p-16384), { LIT (0xf.ffffffffffffffcp-16388), LIT (-0x1.0000000000000002p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffffcp-16388), LIT (-0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 - 0x4p-1024 i", LIT (-0x1p+0), LIT (-0x4p-1024), { LIT (0x1.fffffffffffffffep-1024), LIT (-0x1.0000000000000002p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-1024), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 - 0x4p-128 i", LIT (-0x1p+0), LIT (-0x4p-128), { LIT (0x1.fffffffffffffffep-128), LIT (-0x1.0000000000000002p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-128), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 - 0x4p-16384 i", LIT (-0x1p+0), LIT (-0x4p-16384), { LIT (0x1.fffffffffffffffcp-16384), LIT (-0x1.0000000000000002p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1.fffffffffffffffcp-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), LIT (-0x1p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 - 0x8p-972 i", LIT (-0x1p+0), LIT (-0x8p-972), { LIT (0x3.fffffffffffffffcp-972), LIT (-0x1.0000000000000002p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-972), LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 + +0 i", LIT (-0x1p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 + 0x2p-16384 i", LIT (-0x1p+0), LIT (0x2p-16384), { LIT (0xf.ffffffffffffffcp-16388), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffffcp-16388), LIT (0x1p+0), UNDERFLOW_EXCEPTION }, { LIT (0x1p-16384), LIT (0x1.0000000000000002p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 + 0x4p-1024 i", LIT (-0x1p+0), LIT (0x4p-1024), { LIT (0x1.fffffffffffffffep-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-1024), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-1024), LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 + 0x4p-128 i", LIT (-0x1p+0), LIT (0x4p-128), { LIT (0x1.fffffffffffffffep-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-128), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x2p-128), LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 + 0x4p-16384 i", LIT (-0x1p+0), LIT (0x4p-16384), { LIT (0x1.fffffffffffffffcp-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1.fffffffffffffffcp-16384), LIT (0x1p+0), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), LIT (0x1.0000000000000002p+0), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0 + 0x8p-972 i", LIT (-0x1p+0), LIT (0x8p-972), { LIT (0x3.fffffffffffffffcp-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-972), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x4p-972), LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.927275f6febb6p-184 + 0x8p-152 i", LIT (-0x2.927275f6febb6p-184), LIT (0x8p-152), { LIT (0x1.ffffffffadb1b14p-76), LIT (0x2.00000000524e4ebcp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b142p-76), LIT (0x2.00000000524e4ecp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b14p-76), LIT (0x2.00000000524e4ebcp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffadb1b142p-76), LIT (0x2.00000000524e4ecp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p+0 - 0x3p+0 i", LIT (-0x2p+0), LIT (-0x3p+0), { LIT (0xe.55ec7a5ee26873fp-4), LIT (-0x1.ac950b37094a5a96p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26874p-4), LIT (-0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fp-4), LIT (-0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26874p-4), LIT (-0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p+0 + 0x3p+0 i", LIT (-0x2p+0), LIT (0x3p+0), { LIT (0xe.55ec7a5ee26873fp-4), LIT (0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26874p-4), LIT (0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26873fp-4), LIT (0x1.ac950b37094a5a94p+0), ERRNO_UNCHANGED }, { LIT (0xe.55ec7a5ee26874p-4), LIT (0x1.ac950b37094a5a96p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.0000000000000008p-16384 - 0 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000000004p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.0000000000000008p-16384 - 0x4.0000000000000008p-16384 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4.0000000000000008p-16384), { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16b4p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.0000000000000008p-16384 - 0x4p-1076 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef32428p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.0000000000000008p-16384 - 0x4p-16384 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x4p-16384), { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16b4p-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.0000000000000008p-16384 - 0x8p-152 i", LIT (-0x4.0000000000000008p-16384), LIT (-0x8p-152), { LIT (0x1.fffffffffffffffep-76), LIT (-0x2.0000000000000004p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.0000000000004p-1024 - 0 i", LIT (-0x4.0000000000004p-1024), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.0000000000001p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000001p-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000ffcp-512), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.0000000000000ffcp-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.0000000000004p-1024 - 0x4.0000000000004p-1024 i", LIT (-0x4.0000000000004p-1024), LIT (-0x4.0000000000004p-1024), { LIT (0xe.90189c7b641487bp-516), LIT (-0x2.3286b95ff53f2844p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487cp-516), LIT (-0x2.3286b95ff53f2844p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487bp-516), LIT (-0x2.3286b95ff53f284p-512), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b641487cp-516), LIT (-0x2.3286b95ff53f284p-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.0000000000004p-1024 - 0x8p-152 i", LIT (-0x4.0000000000004p-1024), LIT (-0x8p-152), { LIT (0x1.fffffffffffffffep-76), LIT (-0x2.0000000000000004p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.000008p-128 - 0x4.000008p-128 i", LIT (-0x4.000008p-128), LIT (-0x4.000008p-128), { LIT (0xe.9018ab0b7ca9469p-68), LIT (-0x2.3286bb927bf75d64p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca9469p-68), LIT (-0x2.3286bb927bf75d6p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca9469p-68), LIT (-0x2.3286bb927bf75d6p-64), ERRNO_UNCHANGED }, { LIT (0xe.9018ab0b7ca946ap-68), LIT (-0x2.3286bb927bf75d6p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.15ca1p+0 - 0x8p-152 i", LIT (-0x4.15ca1p+0), LIT (-0x8p-152), { LIT (0x1.faa35a1b5eb2277cp-152), LIT (-0x2.056b2cd84231ea6cp+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277cp-152), LIT (-0x2.056b2cd84231ea6cp+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277cp-152), LIT (-0x2.056b2cd84231ea68p+0), ERRNO_UNCHANGED }, { LIT (0x1.faa35a1b5eb2277ep-152), LIT (-0x2.056b2cd84231ea68p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.827738p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.827738p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee6cd64cbb62p-4), LIT (-0x1.02a876fc905207ccp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb63p-4), LIT (-0x1.02a876fc905207ccp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb62p-4), LIT (-0x1.02a876fc905207cap+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee6cd64cbb63p-4), LIT (-0x1.02a876fc905207cap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.82773b736291p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82773b736291p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee5f5a36814cp-4), LIT (-0x1.02a8770c69a38ebap+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814dp-4), LIT (-0x1.02a8770c69a38eb8p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814cp-4), LIT (-0x1.02a8770c69a38eb8p+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee5f5a36814dp-4), LIT (-0x1.02a8770c69a38eb8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.82774p-4 - 0x1.bcb7cep+0 i", LIT (-0x4.82774p-4), LIT (-0x1.bcb7cep+0), { LIT (0xd.c12ee4d93232a24p-4), LIT (-0x1.02a877214e9fe4cep+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a24p-4), LIT (-0x1.02a877214e9fe4ccp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a24p-4), LIT (-0x1.02a877214e9fe4ccp+0), ERRNO_UNCHANGED }, { LIT (0xd.c12ee4d93232a25p-4), LIT (-0x1.02a877214e9fe4ccp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.d0144005d7af4p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144005d7af4p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2657d0a037p+0), LIT (-0x2.0201143f4f66d96p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a037p+0), LIT (-0x2.0201143f4f66d95cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a037p+0), LIT (-0x2.0201143f4f66d95cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2657d0a0372p+0), LIT (-0x2.0201143f4f66d95cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.d01448p-4 - 0x7.c19148p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d2559bb4b70cp+0), LIT (-0x2.0201144fd174462cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70cp+0), LIT (-0x2.0201144fd174462cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70cp+0), LIT (-0x2.0201144fd1744628p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d2559bb4b70ep+0), LIT (-0x2.0201144fd1744628p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.d01448p-4 - 0x7.c1915p+0 i", LIT (-0x4.d01448p-4), LIT (-0x7.c1915p+0), { LIT (0x1.ee74d35e7dfe1b3cp+0), LIT (-0x2.0201154ea0e0412cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cp+0), LIT (-0x2.0201154ea0e0412cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3cp+0), LIT (-0x2.0201154ea0e04128p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d35e7dfe1b3ep+0), LIT (-0x2.0201154ea0e04128p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4.d0144p-4 - 0x7.c19148p+0 i", LIT (-0x4.d0144p-4), LIT (-0x7.c19148p+0), { LIT (0x1.ee74d26588ab7af2p+0), LIT (-0x2.0201143f434fabbcp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af2p+0), LIT (-0x2.0201143f434fabbcp+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af2p+0), LIT (-0x2.0201143f434fabb8p+0), ERRNO_UNCHANGED }, { LIT (0x1.ee74d26588ab7af4p+0), LIT (-0x2.0201143f434fabb8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076 - 0 i", LIT (-0x4p-1076), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076 - 0x4.0000000000000008p-16384 i", LIT (-0x4p-1076), LIT (-0x4.0000000000000008p-16384), { LIT (0x4p-15848), LIT (-0x8.000000000000001p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076 - 0x4p-1076 i", LIT (-0x4p-1076), LIT (-0x4p-1076), { LIT (0x3.a406271ed90504ccp-540), LIT (-0x8.ca1ae57fd4fc5acp-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504dp-540), LIT (-0x8.ca1ae57fd4fc5acp-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504ccp-540), LIT (-0x8.ca1ae57fd4fc5abp-540), ERRNO_UNCHANGED }, { LIT (0x3.a406271ed90504dp-540), LIT (-0x8.ca1ae57fd4fc5abp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076 - 0x4p-16384 i", LIT (-0x4p-1076), LIT (-0x4p-16384), { LIT (0x3.fffffffffffffffcp-15848), LIT (-0x8.000000000000001p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-15848), LIT (-0x8p-540), ERRNO_UNCHANGED }, { LIT (0x4p-15848), LIT (-0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076 - 0x8p-152 i", LIT (-0x4p-1076), LIT (-0x8p-152), { LIT (0x1.fffffffffffffffep-76), LIT (-0x2.0000000000000004p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384 - 0 i", LIT (-0x4p-16384), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384 - 0x4.0000000000000008p-16384 i", LIT (-0x4p-16384), LIT (-0x4.0000000000000008p-16384), { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414135p-8196), LIT (-0x2.3286b95ff53f16acp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414136p-8196), LIT (-0x2.3286b95ff53f16acp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384 - 0x4p-1076 i", LIT (-0x4p-16384), LIT (-0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef32428p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (-0x5.a827999fcef3242p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384 - 0x4p-16384 i", LIT (-0x4p-16384), LIT (-0x4p-16384), { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16bp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414133p-8196), LIT (-0x2.3286b95ff53f16acp-8192), ERRNO_UNCHANGED }, { LIT (0xe.90189c7b6414134p-8196), LIT (-0x2.3286b95ff53f16acp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384 - 0x8p-152 i", LIT (-0x4p-16384), LIT (-0x8p-152), { LIT (0x1.fffffffffffffffep-76), LIT (-0x2.0000000000000004p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.31291c9fdae04p-160 - 0x8p-152 i", LIT (-0x7.31291c9fdae04p-160), LIT (-0x8p-152), { LIT (0x1.ff1a0ead4f6b13dp-76), LIT (-0x2.00e658c5f71cca9cp-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13dp-76), LIT (-0x2.00e658c5f71cca98p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13dp-76), LIT (-0x2.00e658c5f71cca98p-76), ERRNO_UNCHANGED }, { LIT (0x1.ff1a0ead4f6b13d2p-76), LIT (-0x2.00e658c5f71cca98p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.915fa8p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fa8p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c32571e2b8ea0a1p-4), LIT (-0x1.3392ad649c5855bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a2p-4), LIT (-0x1.3392ad649c5855bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a1p-4), LIT (-0x1.3392ad649c5855aep+0), ERRNO_UNCHANGED }, { LIT (0xf.c32571e2b8ea0a2p-4), LIT (-0x1.3392ad649c5855aep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.915fafbe9f588p-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fafbe9f588p-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c325704e2c61d1ap-4), LIT (-0x1.3392ad837265581p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1ap-4), LIT (-0x1.3392ad837265581p+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1ap-4), LIT (-0x1.3392ad837265580ep+0), ERRNO_UNCHANGED }, { LIT (0xf.c325704e2c61d1bp-4), LIT (-0x1.3392ad837265580ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.915fbp-4 - 0x2.5e01bcp+0 i", LIT (-0x7.915fbp-4), LIT (-0x2.5e01bcp+0), { LIT (0xf.c3257040d54fb3cp-4), LIT (-0x1.3392ad8476b45bp+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3dp-4), LIT (-0x1.3392ad8476b45afep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3cp-4), LIT (-0x1.3392ad8476b45afep+0), ERRNO_UNCHANGED }, { LIT (0xf.c3257040d54fb3dp-4), LIT (-0x1.3392ad8476b45afep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8.ec8932bf5603p-172 + 0x8p-152 i", LIT (-0x8.ec8932bf5603p-172), LIT (0x8p-152), { LIT (0x1.ffffee26edea2476p-76), LIT (0x2.000011d912b521c8p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea2478p-76), LIT (0x2.000011d912b521c8p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea2476p-76), LIT (0x2.000011d912b521c8p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffee26edea2478p-76), LIT (0x2.000011d912b521ccp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 - 0 i", LIT (-0x8p-152), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 - 0x1.818bccp+0 i", LIT (-0x8p-152), LIT (-0x1.818bccp+0), { LIT (0xd.e25fb98f8390a02p-4), LIT (-0xd.e25fb98f8390a03p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a02p-4), LIT (-0xd.e25fb98f8390a02p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a02p-4), LIT (-0xd.e25fb98f8390a02p-4), ERRNO_UNCHANGED }, { LIT (0xd.e25fb98f8390a03p-4), LIT (-0xd.e25fb98f8390a02p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 - 0x2.c832ff5b163af0dcp-2444 i", LIT (-0x8p-152), LIT (-0x2.c832ff5b163af0dcp-2444), { LIT (0x7.de674fc19752a2c8p-2372), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2dp-2372), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2c8p-2372), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0x7.de674fc19752a2dp-2372), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 - 0x4.0000000000000008p-16384 i", LIT (-0x8p-152), LIT (-0x4.0000000000000008p-16384), { LIT (0xb.504f333f9de6485p-16312), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6486p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6486p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 - 0x4.0000000000004p-1024 i", LIT (-0x8p-152), LIT (-0x4.0000000000004p-1024), { LIT (0xb.504f333f9de6fd4p-952), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd5p-952), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd4p-952), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6fd5p-952), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 - 0x4p-1076 i", LIT (-0x8p-152), LIT (-0x4p-1076), { LIT (0xb.504f333f9de6484p-1004), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-1004), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-1004), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-1004), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 - 0x4p-16384 i", LIT (-0x8p-152), LIT (-0x4p-16384), { LIT (0xb.504f333f9de6484p-16312), LIT (-0x2.d413cccfe7799214p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-16312), LIT (-0x2.d413cccfe779921p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 - 0x8p-152 i", LIT (-0x8p-152), LIT (-0x8p-152), { LIT (0x1.49852f983efdd57ap-76), LIT (-0x3.1b884327ab8057e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57cp-76), LIT (-0x3.1b884327ab8057e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57ap-76), LIT (-0x3.1b884327ab8057ep-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57cp-76), LIT (-0x3.1b884327ab8057ep-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152 + 0x8p-152 i", LIT (-0x8p-152), LIT (0x8p-152), { LIT (0x1.49852f983efdd57ap-76), LIT (0x3.1b884327ab8057ep-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57cp-76), LIT (0x3.1b884327ab8057e4p-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57ap-76), LIT (0x3.1b884327ab8057ep-76), ERRNO_UNCHANGED }, { LIT (0x1.49852f983efdd57cp-76), LIT (0x3.1b884327ab8057e4p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x9.0a61a7b482d28p-168 - 0x8p-152 i", LIT (-0x9.0a61a7b482d28p-168), LIT (-0x8p-152), { LIT (0x1.fffedeb41cc4e764p-76), LIT (-0x2.0001214c86b1abcp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764p-76), LIT (-0x2.0001214c86b1abbcp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e764p-76), LIT (-0x2.0001214c86b1abbcp-76), ERRNO_UNCHANGED }, { LIT (0x1.fffedeb41cc4e766p-76), LIT (-0x2.0001214c86b1abbcp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xb.e2bc1cd6eaa7p-180 + 0x8p-152 i", LIT (-0xb.e2bc1cd6eaa7p-180), LIT (0x8p-152), { LIT (0x1.ffffffe83a87c6dep-76), LIT (0x2.00000017c5783a38p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6ep-76), LIT (0x2.00000017c5783a3cp-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6dep-76), LIT (0x2.00000017c5783a38p-76), ERRNO_UNCHANGED }, { LIT (0x1.ffffffe83a87c6ep-76), LIT (0x2.00000017c5783a3cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xd.e1d5fp-4 - 0x1.054226p+4 i", LIT (-0xd.e1d5fp-4), LIT (-0x1.054226p+4), { LIT (0x2.c84e99e2df484b1p+0), LIT (-0x2.ef2930261e97de9p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b14p+0), LIT (-0x2.ef2930261e97de9p+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b1p+0), LIT (-0x2.ef2930261e97de8cp+0), ERRNO_UNCHANGED }, { LIT (0x2.c84e99e2df484b14p+0), LIT (-0x2.ef2930261e97de8cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xe.6432ap-4 + 0xe.8175p-4 i", LIT (-0xe.6432ap-4), LIT (0xe.8175p-4), { LIT (0x6.f3d482a6e0b03b9p-4), LIT (0x1.0b0f83813dfbbb8cp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b98p-4), LIT (0x1.0b0f83813dfbbb8ep+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b9p-4), LIT (0x1.0b0f83813dfbbb8cp+0), ERRNO_UNCHANGED }, { LIT (0x6.f3d482a6e0b03b98p-4), LIT (0x1.0b0f83813dfbbb8ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xe.735dbp+0 - 0x5.26cb98p+40 i", LIT (-0xe.735dbp+0), LIT (-0x5.26cb98p+40), { LIT (0x1.9adc1d93b4e9b398p+20), LIT (-0x1.9adc1d93b96a3568p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398p+20), LIT (-0x1.9adc1d93b96a3566p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b398p+20), LIT (-0x1.9adc1d93b96a3566p+20), ERRNO_UNCHANGED }, { LIT (0x1.9adc1d93b4e9b39ap+20), LIT (-0x1.9adc1d93b96a3566p+20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020 + +0 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0x2.00000000000008p-1588), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x2.00000000000008p-1588), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x2.00000000000008p-1588), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000804p-1588), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020 + 0x8.8p-8192 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x8.8p-8192), { LIT (0x4.40000000000011p-8704), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x4.40000000000011p-8704), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.40000000000011p-8704), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x4.4000000000001108p-8704), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (-0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001p-664), LIT (0xf.ffffffffffffbffp+508), ERRNO_UNCHANGED }, { LIT (0x4.0000000000001008p-664), LIT (0xf.ffffffffffffcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124 + +0 i", LIT (-0xf.fffffp+124), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124 + 0x4p-1076 i", LIT (-0xf.fffffp+124), LIT (0x4p-1076), { LIT (0x2.000001000000cp-1140), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000cp-1140), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000cp-1140), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x2.000001000000c004p-1140), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124 + 0x8.8p-512 i", LIT (-0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0x4.40000220000198p-576), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198p-576), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198p-576), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000019808p-576), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124 + 0x8.8p-8192 i", LIT (-0xf.fffffp+124), LIT (0x8.8p-8192), { LIT (0x4.40000220000198p-8256), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198p-8256), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x4.40000220000198p-8256), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.4000022000019808p-8256), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124 + 0x8p-152 i", LIT (-0xf.fffffp+124), LIT (0x8p-152), { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018p-216), LIT (0xf.fffff7fffffdfffp+60), ERRNO_UNCHANGED }, { LIT (0x4.0000020000018008p-216), LIT (0xf.fffff7fffffep+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fp+1020 + +0 i", LIT (-0xf.fp+1020), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fp+1020 + 0x8.8p-512 i", LIT (-0xf.fp+1020), LIT (0x8.8p-512), { LIT (0x4.422199552a8cb65p-1024), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-1024), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb65p-1024), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-1024), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fp+1020 + 0x8p-152 i", LIT (-0xf.fp+1020), LIT (0x8p-152), { LIT (0x4.0201814118fce7dp-664), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d8p-664), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7dp-664), LIT (0xf.f7fdfeff5f8fabbp+508), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d8p-664), LIT (0xf.f7fdfeff5f8fabcp+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fp+124 + 0x8.8p-64 i", LIT (-0xf.fp+124), LIT (0x8.8p-64), { LIT (0x4.422199552a8cb65p-128), LIT (0xf.f7fdfeff5f8fabbp+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-128), LIT (0xf.f7fdfeff5f8fabcp+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb65p-128), LIT (0xf.f7fdfeff5f8fabbp+60), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-128), LIT (0xf.f7fdfeff5f8fabcp+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fp+16380 + +0 i", LIT (-0xf.fp+16380), LIT (0x0p+0), { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fp+16380 + 0x4p-1076 i", LIT (-0xf.fp+16380), LIT (0x4p-1076), { LIT (0x2.0100c0a08c7e73e8p-9268), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73ecp-9268), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73e8p-9268), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x2.0100c0a08c7e73ecp-9268), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fp+16380 + 0x8.8p-8192 i", LIT (-0xf.fp+16380), LIT (0x8.8p-8192), { LIT (0x4.422199552a8cb65p-16384), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-16384), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb65p-16384), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x4.422199552a8cb658p-16384), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fp+16380 + 0x8p-152 i", LIT (-0xf.fp+16380), LIT (0x8p-152), { LIT (0x4.0201814118fce7dp-8344), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d8p-8344), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7dp-8344), LIT (0xf.f7fdfeff5f8fabbp+8188), ERRNO_UNCHANGED }, { LIT (0x4.0201814118fce7d8p-8344), LIT (0xf.f7fdfeff5f8fabcp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0 i", LIT (0x0p+0), LIT (-0x0p+0), { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x1p+0 i", LIT (0x0p+0), LIT (-0x1p+0), { LIT (0xb.504f333f9de6484p-4), LIT (-0xb.504f333f9de6485p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-4), LIT (-0xb.504f333f9de6484p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-4), LIT (-0xb.504f333f9de6484p-4), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-4), LIT (-0xb.504f333f9de6484p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 - 0x8p-152 i", LIT (0x0p+0), LIT (-0x8p-152), { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (-0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + +0 i", LIT (0x0p+0), LIT (0x0p+0), { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x2p+0 i", LIT (0x0p+0), LIT (0x2p+0), { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4.0000000000000008p-16384 i", LIT (0x0p+0), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4.000000000000001p-16384 i", LIT (0x0p+0), LIT (0x4.000000000000001p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4.0000000000004p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcd458p-512), LIT (0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd45ap-512), LIT (0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd458p-512), LIT (0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcd45ap-512), LIT (0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4.0000000000008p-1024 i", LIT (0x0p+0), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bcdfa8p-512), LIT (0x1.6a09e667f3bcdfa8p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfaap-512), LIT (0x1.6a09e667f3bcdfaap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa8p-512), LIT (0x1.6a09e667f3bcdfa8p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfaap-512), LIT (0x1.6a09e667f3bcdfaap-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4p-1076 i", LIT (0x0p+0), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4p-16384 i", LIT (0x0p+0), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc908p-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x4p-16448 i", LIT (0x0p+0), LIT (0x4p-16448), { LIT (0x1.6a09e667f3bcc908p-8224), LIT (0x1.6a09e667f3bcc908p-8224), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8224), LIT (0x1.6a09e667f3bcc908p-8224), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8224), LIT (0x1.6a09e667f3bcc908p-8224), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8224), LIT (0x1.6a09e667f3bcc90ap-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p+1020 i", LIT (0x0p+0), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p+16380 i", LIT (0x0p+0), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p-1076 i", LIT (0x0p+0), LIT (0x8p-1076), { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p-152 i", LIT (0x0p+0), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p-16444 i", LIT (0x0p+0), LIT (0x8p-16444), { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED }, { LIT (0x8p-8224), LIT (0x8p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0x8p-16448 i", LIT (0x0p+0), LIT (0x8p-16448), { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x2p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0xf.ffffffffffff8p+1020 i", LIT (0x0p+0), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0 + 0xf.fffffp+124 i", LIT (0x0p+0), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0221e29d5a3cdp-188 - 0x8p-152 i", LIT (0x1.0221e29d5a3cdp-188), LIT (-0x8p-152), { LIT (0x2.00000000020443c4p-76), LIT (-0x1.fffffffffdfbbc3cp-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c4p-76), LIT (-0x1.fffffffffdfbbc3ap-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c4p-76), LIT (-0x1.fffffffffdfbbc3ap-76), ERRNO_UNCHANGED }, { LIT (0x2.00000000020443c8p-76), LIT (-0x1.fffffffffdfbbc3ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.d60caep+0 + 0x7.a7d468p+0 i", LIT (0x1.d60caep+0), LIT (0x7.a7d468p+0), { LIT (0x2.3409baa805bc9528p+0), LIT (0x1.bcc10b50fddb6aeap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952cp+0), LIT (0x1.bcc10b50fddb6aeap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc9528p+0), LIT (0x1.bcc10b50fddb6aeap+0), ERRNO_UNCHANGED }, { LIT (0x2.3409baa805bc952cp+0), LIT (0x1.bcc10b50fddb6aecp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.f9610ap+4 + 0x9.87716p+4 i", LIT (0x1.f9610ap+4), LIT (0x9.87716p+4), { LIT (0x9.ad5033142bab316p+0), LIT (0x7.e0b144c043868bep+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab316p+0), LIT (0x7.e0b144c043868bep+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab316p+0), LIT (0x7.e0b144c043868bep+0), ERRNO_UNCHANGED }, { LIT (0x9.ad5033142bab317p+0), LIT (0x7.e0b144c043868be8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 - 0x2p-16384 i", LIT (0x1p+0), LIT (-0x2p-16384), { LIT (0x1p+0), LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (-0xf.ffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (-0xf.ffffffffffffffcp-16388), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 - 0x4p-1024 i", LIT (0x1p+0), LIT (-0x4p-1024), { LIT (0x1p+0), LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (-0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 - 0x4p-128 i", LIT (0x1p+0), LIT (-0x4p-128), { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (-0x1.fffffffffffffffep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 - 0x4p-16384 i", LIT (0x1p+0), LIT (-0x4p-16384), { LIT (0x1p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1p+0), LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1p+0), LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1.0000000000000002p+0), LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 - 0x8p-972 i", LIT (0x1p+0), LIT (-0x8p-972), { LIT (0x1p+0), LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (-0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0x2p-16384 i", LIT (0x1p+0), LIT (0x2p-16384), { LIT (0x1p+0), LIT (0xf.ffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0x1p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1p+0), LIT (0xf.ffffffffffffffcp-16388), UNDERFLOW_EXCEPTION }, { LIT (0x1.0000000000000002p+0), LIT (0x1p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0x4p-1024 i", LIT (0x1p+0), LIT (0x4p-1024), { LIT (0x1p+0), LIT (0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2p-1024), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.fffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x2p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0x4p-128 i", LIT (0x1p+0), LIT (0x4p-128), { LIT (0x1p+0), LIT (0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2p-128), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.fffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x2p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0x4p-16384 i", LIT (0x1p+0), LIT (0x4p-16384), { LIT (0x1p+0), LIT (0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1p+0), LIT (0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1.0000000000000002p+0), LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + 0x8p-972 i", LIT (0x1p+0), LIT (0x8p-972), { LIT (0x1p+0), LIT (0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4p-972), ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.fffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), LIT (0x4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+4 - 0x1.ep+4 i", LIT (0x1p+4), LIT (-0x1.ep+4), { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED }, { LIT (0x5p+0), LIT (-0x3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-16440 + +0 i", LIT (0x1p-16440), LIT (0x0p+0), { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-8220), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-16440 + 0x4p-1076 i", LIT (0x1p-16440), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-16440 + 0x8p-152 i", LIT (0x1p-16440), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-16440 + 0x8p-16444 i", LIT (0x1p-16440), LIT (0x8p-16444), { LIT (0x1.077225f1da571bacp-8220), LIT (0x3.e30ee78adee42e5cp-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571bacp-8220), LIT (0x3.e30ee78adee42e6p-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571bacp-8220), LIT (0x3.e30ee78adee42e5cp-8224), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da571baep-8220), LIT (0x3.e30ee78adee42e6p-8224), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-500 + +0 i", LIT (0x1p-500), LIT (0x0p+0), { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-500 + 0x4p-1076 i", LIT (0x1p-500), LIT (0x4p-1076), { LIT (0x4p-252), LIT (0x7.fffffffffffffff8p-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x8p-828), ERRNO_UNCHANGED }, { LIT (0x4p-252), LIT (0x7.fffffffffffffff8p-828), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000008p-252), LIT (0x8p-828), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-500 + 0x8p-152 i", LIT (0x1p-500), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-5000 + +0 i", LIT (0x1p-5000), LIT (0x0p+0), { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-5000 + 0x4p-1076 i", LIT (0x1p-5000), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-5000 + 0x4p-16448 i", LIT (0x1p-5000), LIT (0x4p-16448), { LIT (0x1p-2500), LIT (0x1.fffffffffffffffep-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x2p-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x1.fffffffffffffffep-13948), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-2500), LIT (0x2p-13948), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-5000 + 0x8p-152 i", LIT (0x1p-5000), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-5000 + 0x8p-16448 i", LIT (0x1p-5000), LIT (0x8p-16448), { LIT (0x1p-2500), LIT (0x3.fffffffffffffffcp-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x4p-13948), ERRNO_UNCHANGED }, { LIT (0x1p-2500), LIT (0x3.fffffffffffffffcp-13948), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p-2500), LIT (0x4p-13948), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-148 + 0x2p-148 i", LIT (0x2p-148), LIT (0x2p-148), { LIT (0x6.3710864f5700afcp-76), LIT (0x2.930a5f307dfbaaf4p-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc8p-76), LIT (0x2.930a5f307dfbaaf8p-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afcp-76), LIT (0x2.930a5f307dfbaaf4p-76), ERRNO_UNCHANGED }, { LIT (0x6.3710864f5700afc8p-76), LIT (0x2.930a5f307dfbaaf8p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db1f30939ceap+0), LIT (0xf.3d9236b503fee6p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939ceap+0), LIT (0xf.3d9236b503fee61p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939ceap+0), LIT (0xf.3d9236b503fee6p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db1f30939cecp+0), LIT (0xf.3d9236b503fee61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db809771ddap+0), LIT (0xf.3d923d93816780fp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda2p+0), LIT (0xf.3d923d93816781p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771ddap+0), LIT (0xf.3d923d93816780fp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db809771dda2p+0), LIT (0xf.3d923d93816781p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc0ba4f2875p+0), LIT (0xf.3d924761f5b5cfep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f28752p+0), LIT (0xf.3d924761f5b5cfep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f2875p+0), LIT (0xf.3d924761f5b5cfep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc0ba4f28752p+0), LIT (0xf.3d924761f5b5cffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f0cp+0), LIT (0xf.3d92365a334569ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0ep+0), LIT (0xf.3d92365a334569ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0cp+0), LIT (0xf.3d92365a334569ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f0ep+0), LIT (0xf.3d92365a334569fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05acf4p+0), LIT (0xf.3d923d38b0ae23ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4p+0), LIT (0xf.3d923d38b0ae23ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf4p+0), LIT (0xf.3d923d38b0ae23ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05acf6p+0), LIT (0xf.3d923d38b0ae23fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e3ep-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3ep-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c8652ap+0), LIT (0xf.3d92470724fc9f3p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652ap+0), LIT (0xf.3d92470724fc9f3p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652ap+0), LIT (0xf.3d92470724fc9f3p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c8652a2p+0), LIT (0xf.3d92470724fc9f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f8cp+0), LIT (0xf.3d92365a334562dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8cp+0), LIT (0xf.3d92365a334562ep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8cp+0), LIT (0xf.3d92365a334562dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f8ep+0), LIT (0xf.3d92365a334562ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ad72p+0), LIT (0xf.3d923d38b0ae1cdp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad74p+0), LIT (0xf.3d923d38b0ae1cep-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad72p+0), LIT (0xf.3d923d38b0ae1cdp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad74p+0), LIT (0xf.3d923d38b0ae1cep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e3fe6cp-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e3fe6cp-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c86531ep+0), LIT (0xf.3d92470724fc982p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532p+0), LIT (0xf.3d92470724fc983p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86531ep+0), LIT (0xf.3d92470724fc982p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c86532p+0), LIT (0xf.3d92470724fc983p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2598276f92p+0), LIT (0xf.3d92365a3345627p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f94p+0), LIT (0xf.3d92365a3345628p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f92p+0), LIT (0xf.3d92365a3345627p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2598276f94p+0), LIT (0xf.3d92365a3345628p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db86ff05ad7ap+0), LIT (0xf.3d923d38b0ae1c7p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7ap+0), LIT (0xf.3d923d38b0ae1c8p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7ap+0), LIT (0xf.3d923d38b0ae1c7p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db86ff05ad7cp+0), LIT (0xf.3d923d38b0ae1c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f58949e4p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f58949e4p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc120c865326p+0), LIT (0xf.3d92470724fc97dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865326p+0), LIT (0xf.3d92470724fc97dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865326p+0), LIT (0xf.3d92470724fc97dp-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc120c865328p+0), LIT (0xf.3d92470724fc97ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f8p-4 + 0x2.0c2e88p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e88p+0), { LIT (0x1.1326db2fdd855d18p+0), LIT (0xf.3d9235c88f9fa24p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d1ap+0), LIT (0xf.3d9235c88f9fa24p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d18p+0), LIT (0xf.3d9235c88f9fa24p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db2fdd855d1ap+0), LIT (0xf.3d9235c88f9fa25p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f8p-4 + 0x2.0c2e89a5cff98p+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e89a5cff98p+0), { LIT (0x1.1326db914463967ep+0), LIT (0xf.3d923ca70d088e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967ep+0), LIT (0xf.3d923ca70d088e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463967ep+0), LIT (0xf.3d923ca70d088e2p-4), ERRNO_UNCHANGED }, { LIT (0x1.1326db914463968p+0), LIT (0xf.3d923ca70d088e3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.f768f8p-4 + 0x2.0c2e8cp+0 i", LIT (0x3.f768f8p-4), LIT (0x2.0c2e8cp+0), { LIT (0x1.1326dc1c51e435bap+0), LIT (0xf.3d924675815750ap-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435bap+0), LIT (0xf.3d924675815750ap-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435bap+0), LIT (0xf.3d924675815750ap-4), ERRNO_UNCHANGED }, { LIT (0x1.1326dc1c51e435bcp+0), LIT (0xf.3d924675815750bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000000008p-16384 + +0 i", LIT (0x4.0000000000000008p-16384), LIT (0x0p+0), { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-8192), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000000008p-16384 + 0x4.0000000000000008p-16384 i", LIT (0x4.0000000000000008p-16384), LIT (0x4.0000000000000008p-16384), { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b4p-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000000008p-16384 + 0x4p-1076 i", LIT (0x4.0000000000000008p-16384), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000000008p-16384 + 0x4p-16384 i", LIT (0x4.0000000000000008p-16384), LIT (0x4p-16384), { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16b4p-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000000008p-16384 + 0x8p-152 i", LIT (0x4.0000000000000008p-16384), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000004p-1024 + +0 i", LIT (0x4.0000000000004p-1024), LIT (0x0p+0), { LIT (0x2.0000000000000ffcp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001p-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000ffcp-512), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001p-512), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000004p-1024 + 0x4.0000000000004p-1024 i", LIT (0x4.0000000000004p-1024), LIT (0x4.0000000000004p-1024), { LIT (0x2.3286b95ff53f284p-512), LIT (0xe.90189c7b641487bp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f2844p-512), LIT (0xe.90189c7b641487cp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f284p-512), LIT (0xe.90189c7b641487bp-516), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f2844p-512), LIT (0xe.90189c7b641487cp-516), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.0000000000004p-1024 + 0x8p-152 i", LIT (0x4.0000000000004p-1024), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.000008p-128 + 0x4.000008p-128 i", LIT (0x4.000008p-128), LIT (0x4.000008p-128), { LIT (0x2.3286bb927bf75d6p-64), LIT (0xe.9018ab0b7ca9469p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d6p-64), LIT (0xe.9018ab0b7ca9469p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d6p-64), LIT (0xe.9018ab0b7ca9469p-68), ERRNO_UNCHANGED }, { LIT (0x2.3286bb927bf75d64p-64), LIT (0xe.9018ab0b7ca946ap-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + +0 i", LIT (0x4p-1076), LIT (0x0p+0), { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x4.0000000000000008p-16384 i", LIT (0x4p-1076), LIT (0x4.0000000000000008p-16384), { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x4.000000000000001p-16384 i", LIT (0x4p-1076), LIT (0x4.000000000000001p-16384), { LIT (0x8p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.000000000000001p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4.0000000000000008p-15848), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x4.000000000000001p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x4.0000000000004p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000004p-1024), { LIT (0x1.6a09e667f3bcdfa8p-512), LIT (0x1.6a09e667f3bcc908p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfaap-512), LIT (0x1.6a09e667f3bcc908p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfa8p-512), LIT (0x1.6a09e667f3bcc908p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcdfaap-512), LIT (0x1.6a09e667f3bcc90ap-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x4.0000000000008p-1024 i", LIT (0x4p-1076), LIT (0x4.0000000000008p-1024), { LIT (0x1.6a09e667f3bceaf8p-512), LIT (0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceafap-512), LIT (0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceaf8p-512), LIT (0x1.6a09e667f3bcd458p-512), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bceafap-512), LIT (0x1.6a09e667f3bcd45ap-512), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x4p-1076 i", LIT (0x4p-1076), LIT (0x4p-1076), { LIT (0x8.ca1ae57fd4fc5abp-540), LIT (0x3.a406271ed90504ccp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5acp-540), LIT (0x3.a406271ed90504dp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5abp-540), LIT (0x3.a406271ed90504ccp-540), ERRNO_UNCHANGED }, { LIT (0x8.ca1ae57fd4fc5acp-540), LIT (0x3.a406271ed90504dp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x4p-16384 i", LIT (0x4p-1076), LIT (0x4p-16384), { LIT (0x8p-540), LIT (0x3.fffffffffffffffcp-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15848), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x3.fffffffffffffffcp-15848), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x4p-15848), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x4p-16448 i", LIT (0x4p-1076), LIT (0x4p-16448), { LIT (0x8p-540), LIT (0x3.fffffffffffffffcp-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x4p-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x3.fffffffffffffffcp-15912), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x4p-15912), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x8p+1020 i", LIT (0x4p-1076), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x8p+16380 i", LIT (0x4p-1076), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x8p-152 i", LIT (0x4p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x8p-16444 i", LIT (0x4p-1076), LIT (0x8p-16444), { LIT (0x8p-540), LIT (0x7.fffffffffffffff8p-15908), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-15908), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x7.fffffffffffffff8p-15908), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x8p-15908), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0x8p-16448 i", LIT (0x4p-1076), LIT (0x8p-16448), { LIT (0x8p-540), LIT (0x7.fffffffffffffff8p-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x8p-15912), ERRNO_UNCHANGED }, { LIT (0x8p-540), LIT (0x7.fffffffffffffff8p-15912), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-540), LIT (0x8p-15912), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0xf.ffffffffffff8p+1020 i", LIT (0x4p-1076), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076 + 0xf.fffffp+124 i", LIT (0x4p-1076), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384 + +0 i", LIT (0x4p-16384), LIT (0x0p+0), { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8192), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384 + 0x4.0000000000000008p-16384 i", LIT (0x4p-16384), LIT (0x4.0000000000000008p-16384), { LIT (0x2.3286b95ff53f16acp-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16acp-8192), LIT (0xe.90189c7b6414135p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414136p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384 + 0x4p-1076 i", LIT (0x4p-16384), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384 + 0x4p-16384 i", LIT (0x4p-16384), LIT (0x4p-16384), { LIT (0x2.3286b95ff53f16acp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16acp-8192), LIT (0xe.90189c7b6414133p-8196), ERRNO_UNCHANGED }, { LIT (0x2.3286b95ff53f16bp-8192), LIT (0xe.90189c7b6414134p-8196), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384 + 0x8p-152 i", LIT (0x4p-16384), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + +0 i", LIT (0x4p-16448), LIT (0x0p+0), { LIT (0x2p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2p-8224), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + 0x4.0000000000000008p-16384 i", LIT (0x4p-16448), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + 0x4p-1076 i", LIT (0x4p-16448), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + 0x4p-16384 i", LIT (0x4p-16448), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc908p-8192), LIT (0x1.6a09e667f3bcc906p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc908p-8192), LIT (0x1.6a09e667f3bcc906p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + 0x8p+16380 i", LIT (0x4p-16448), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + 0x8p-152 i", LIT (0x4p-16448), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + 0xf.ffffffffffff8p+1020 i", LIT (0x4p-16448), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448 + 0xf.fffffp+124 i", LIT (0x4p-16448), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-52 + 0x8p-152 i", LIT (0x4p-52), LIT (0x8p-152), { LIT (0x8p-28), LIT (0x7.fffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x8p-128), ERRNO_UNCHANGED }, { LIT (0x8p-28), LIT (0x7.fffffffffffffff8p-128), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-28), LIT (0x8p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.39e238p+0 - 0x4.576278p-4 i", LIT (0x5.39e238p+0), LIT (-0x4.576278p-4), { LIT (0x2.496e354be8ff297cp+0), LIT (-0xf.2fef5df67620a01p-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cp+0), LIT (-0xf.2fef5df67620ap-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff297cp+0), LIT (-0xf.2fef5df67620ap-8), ERRNO_UNCHANGED }, { LIT (0x2.496e354be8ff298p+0), LIT (-0xf.2fef5df67620ap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.9cc21p-4 - 0x1.fb1ec8p+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec8p+0), { LIT (0x1.163c67724ff4a226p+0), LIT (-0xe.94bd3c203679a4dp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226p+0), LIT (-0xe.94bd3c203679a4dp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a226p+0), LIT (-0xe.94bd3c203679a4cp-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67724ff4a228p+0), LIT (-0xe.94bd3c203679a4cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.9cc21p-4 - 0x1.fb1ec91b40dcdp+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ec91b40dcdp+0), { LIT (0x1.163c67b277e8b48p+0), LIT (-0xe.94bd40e8718fd25p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b482p+0), LIT (-0xe.94bd40e8718fd25p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b48p+0), LIT (-0xe.94bd40e8718fd24p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67b277e8b482p+0), LIT (-0xe.94bd40e8718fd24p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.9cc21p-4 - 0x1.fb1ecap+0 i", LIT (0x5.9cc21p-4), LIT (-0x1.fb1ecap+0), { LIT (0x1.163c67e6476248eep+0), LIT (-0xe.94bd44c5182a0d5p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248eep+0), LIT (-0xe.94bd44c5182a0d4p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248eep+0), LIT (-0xe.94bd44c5182a0d4p-4), ERRNO_UNCHANGED }, { LIT (0x1.163c67e6476248fp+0), LIT (-0xe.94bd44c5182a0d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.b1a2e79e9c9acp-164 + 0x8p-152 i", LIT (0x6.b1a2e79e9c9acp-164), LIT (0x8p-152), { LIT (0x2.000d63729cf6c5d8p-76), LIT (0x1.fff29ce700d4355p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d8p-76), LIT (0x1.fff29ce700d4355p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5d8p-76), LIT (0x1.fff29ce700d4355p-76), ERRNO_UNCHANGED }, { LIT (0x2.000d63729cf6c5dcp-76), LIT (0x1.fff29ce700d43552p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.7p+4 + 0x7.8p+4 i", LIT (0x7.7p+4), LIT (0x7.8p+4), { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED }, { LIT (0xcp+0), LIT (0x5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+1020 + +0 i", LIT (0x8p+1020), LIT (0x0p+0), { LIT (0xb.504f333f9de6484p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+1020 + 0x4p-1076 i", LIT (0x8p+1020), LIT (0x4p-1076), { LIT (0xb.504f333f9de6484p+508), LIT (0x2.d413cccfe779921p-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x2.d413cccfe779921p-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x2.d413cccfe779921p-1588), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+508), LIT (0x2.d413cccfe7799214p-1588), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+1020 + 0x8p-152 i", LIT (0x8p+1020), LIT (0x8p-152), { LIT (0xb.504f333f9de6484p+508), LIT (0x5.a827999fcef3242p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x5.a827999fcef3242p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+508), LIT (0x5.a827999fcef3242p-664), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+508), LIT (0x5.a827999fcef32428p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+124 + 0x8p-152 i", LIT (0x8p+124), LIT (0x8p-152), { LIT (0xb.504f333f9de6484p+60), LIT (0x5.a827999fcef3242p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+60), LIT (0x5.a827999fcef3242p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+60), LIT (0x5.a827999fcef3242p-216), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+60), LIT (0x5.a827999fcef32428p-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+16380 + +0 i", LIT (0x8p+16380), LIT (0x0p+0), { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+16380 + 0x4p-1076 i", LIT (0x8p+16380), LIT (0x4p-1076), { LIT (0xb.504f333f9de6484p+8188), LIT (0x2.d413cccfe779921p-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x2.d413cccfe779921p-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x2.d413cccfe779921p-9268), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x2.d413cccfe7799214p-9268), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+16380 + 0x4p-16448 i", LIT (0x8p+16380), LIT (0x4p-16448), { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+16380 + 0x8p-152 i", LIT (0x8p+16380), LIT (0x8p-152), { LIT (0xb.504f333f9de6484p+8188), LIT (0x5.a827999fcef3242p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x5.a827999fcef3242p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x5.a827999fcef3242p-8344), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x5.a827999fcef32428p-8344), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+16380 + 0x8p-16448 i", LIT (0x8p+16380), LIT (0x8p-16448), { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6484p+8188), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xb.504f333f9de6485p+8188), LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-1076 + +0 i", LIT (0x8p-1076), LIT (0x0p+0), { LIT (0xb.504f333f9de6484p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6484p-540), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de6485p-540), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-1076 + 0x8p-1076 i", LIT (0x8p-1076), LIT (0x8p-1076), { LIT (0xc.6e210c9eae015f8p-540), LIT (0x5.2614be60fbf755e8p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f9p-540), LIT (0x5.2614be60fbf755fp-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f8p-540), LIT (0x5.2614be60fbf755e8p-540), ERRNO_UNCHANGED }, { LIT (0xc.6e210c9eae015f9p-540), LIT (0x5.2614be60fbf755fp-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-1076 + 0x8p-152 i", LIT (0x8p-1076), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 - 0x8p-152 i", LIT (0x8p-152), LIT (-0x8p-152), { LIT (0x3.1b884327ab8057ep-76), LIT (-0x1.49852f983efdd57cp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e4p-76), LIT (-0x1.49852f983efdd57cp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057ep-76), LIT (-0x1.49852f983efdd57ap-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e4p-76), LIT (-0x1.49852f983efdd57ap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + +0 i", LIT (0x8p-152), LIT (0x0p+0), { LIT (0x2.d413cccfe779921p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4.0000000000000008p-16384 i", LIT (0x8p-152), LIT (0x4.0000000000000008p-16384), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6485p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6486p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6485p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6486p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4.000000000000001p-16384 i", LIT (0x8p-152), LIT (0x4.000000000000001p-16384), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6487p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6487p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6487p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6488p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4.0000000000004p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000004p-1024), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6fd4p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6fd5p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6fd4p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6fd5p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4.0000000000008p-1024 i", LIT (0x8p-152), LIT (0x4.0000000000008p-1024), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de7b24p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de7b25p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de7b24p-952), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de7b25p-952), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4.000008p-128 i", LIT (0x8p-152), LIT (0x4.000008p-128), { LIT (0x1.6a09e93c07882ee6p-64), LIT (0x1.6a09e667f3be3312p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee6p-64), LIT (0x1.6a09e667f3be3312p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee6p-64), LIT (0x1.6a09e667f3be3312p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09e93c07882ee8p-64), LIT (0x1.6a09e667f3be3314p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4.00001p-128 i", LIT (0x8p-152), LIT (0x4.00001p-128), { LIT (0x1.6a09eaa6116b0dcp-64), LIT (0x1.6a09e7d1fda3e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc2p-64), LIT (0x1.6a09e7d1fda3e602p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dcp-64), LIT (0x1.6a09e7d1fda3e6p-64), ERRNO_UNCHANGED }, { LIT (0x1.6a09eaa6116b0dc2p-64), LIT (0x1.6a09e7d1fda3e602p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4p-1076 i", LIT (0x8p-152), LIT (0x4p-1076), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-1004), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6485p-1004), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4p-16384 i", LIT (0x8p-152), LIT (0x4p-16384), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16312), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6485p-16312), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x4p-16448 i", LIT (0x8p-152), LIT (0x4p-16448), { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16376), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16376), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0xb.504f333f9de6484p-16376), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0xb.504f333f9de6485p-16376), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x7.8p-148 i", LIT (0x8p-152), LIT (0x7.8p-148), { LIT (0x8.02213e8d55a4ec3p-76), LIT (0x7.7e015d4e23f441b8p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec3p-76), LIT (0x7.7e015d4e23f441b8p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec3p-76), LIT (0x7.7e015d4e23f441b8p-76), ERRNO_UNCHANGED }, { LIT (0x8.02213e8d55a4ec4p-76), LIT (0x7.7e015d4e23f441cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x8p+1020 i", LIT (0x8p-152), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x8p+124 i", LIT (0x8p-152), LIT (0x8p+124), { LIT (0x8p+60), LIT (0x7.fffffffffffffff8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x8p+60), ERRNO_UNCHANGED }, { LIT (0x8p+60), LIT (0x7.fffffffffffffff8p+60), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+60), LIT (0x8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x8p+16380 i", LIT (0x8p-152), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x8p-1076 i", LIT (0x8p-152), LIT (0x8p-1076), { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-1000), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0x1.6a09e667f3bcc90ap-1000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x8p-152 i", LIT (0x8p-152), LIT (0x8p-152), { LIT (0x3.1b884327ab8057ep-76), LIT (0x1.49852f983efdd57ap-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e4p-76), LIT (0x1.49852f983efdd57cp-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057ep-76), LIT (0x1.49852f983efdd57ap-76), ERRNO_UNCHANGED }, { LIT (0x3.1b884327ab8057e4p-76), LIT (0x1.49852f983efdd57cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x8p-16444 i", LIT (0x8p-152), LIT (0x8p-16444), { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16368), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0x1.6a09e667f3bcc90ap-16368), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0x8p-16448 i", LIT (0x8p-152), LIT (0x8p-16448), { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-76), LIT (0x1.6a09e667f3bcc908p-16372), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-76), LIT (0x1.6a09e667f3bcc90ap-16372), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0xf.ffffffffffff8p+1020 i", LIT (0x8p-152), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152 + 0xf.fffffp+124 i", LIT (0x8p-152), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + +0 i", LIT (0x8p-16448), LIT (0x0p+0), { LIT (0x2.d413cccfe779921p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe779921p-8224), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x2.d413cccfe7799214p-8224), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x4.0000000000000008p-16384 i", LIT (0x8p-16448), LIT (0x4.0000000000000008p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x4.000000000000001p-16384 i", LIT (0x8p-16448), LIT (0x4.000000000000001p-16384), { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc90ap-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ep-8192), LIT (0x1.6a09e667f3bcc90cp-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x4p-1076 i", LIT (0x8p-16448), LIT (0x4p-1076), { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef3242p-540), LIT (0x5.a827999fcef3242p-540), ERRNO_UNCHANGED }, { LIT (0x5.a827999fcef32428p-540), LIT (0x5.a827999fcef32428p-540), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x4p-16384 i", LIT (0x8p-16448), LIT (0x4p-16384), { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc906p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90ap-8192), LIT (0x1.6a09e667f3bcc906p-8192), ERRNO_UNCHANGED }, { LIT (0x1.6a09e667f3bcc90cp-8192), LIT (0x1.6a09e667f3bcc908p-8192), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x8p+16380 i", LIT (0x8p-16448), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0x8p-152 i", LIT (0x8p-16448), LIT (0x8p-152), { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x2p-76), ERRNO_UNCHANGED }, { LIT (0x2p-76), LIT (0x1.fffffffffffffffep-76), ERRNO_UNCHANGED }, { LIT (0x2.0000000000000004p-76), LIT (0x2p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0xf.ffffffffffff8p+1020 i", LIT (0x8p-16448), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448 + 0xf.fffffp+124 i", LIT (0x8p-16448), LIT (0xf.fffffp+124), { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e6p+60), LIT (0xb.504f2d97764b3e6p+60), ERRNO_UNCHANGED }, { LIT (0xb.504f2d97764b3e7p+60), LIT (0xb.504f2d97764b3e7p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.0cf78272ed4f605cp+0), LIT (0x9.84953b9e67deb2fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605ep+0), LIT (0x9.84953b9e67deb3p-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605cp+0), LIT (0x9.84953b9e67deb2fp-4), ERRNO_UNCHANGED }, { LIT (0x1.0cf78272ed4f605ep+0), LIT (0x9.84953b9e67deb3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xd.25d559ac5baap-168 + 0x8p-152 i", LIT (0xd.25d559ac5baap-168), LIT (0x8p-152), { LIT (0x2.0001a4bb58123fep-76), LIT (0x1.fffe5b4601a8450ep-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fep-76), LIT (0x1.fffe5b4601a8451p-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fep-76), LIT (0x1.fffe5b4601a8450ep-76), ERRNO_UNCHANGED }, { LIT (0x2.0001a4bb58123fe4p-76), LIT (0x1.fffe5b4601a8451p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.229827fe17d08p-4 + 0xd.849ecp-4 i", LIT (0xe.229827fe17d08p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00ac53515a8bep+0), LIT (0x6.96423e0f64027218p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8bep+0), LIT (0x6.96423e0f6402722p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8bep+0), LIT (0x6.96423e0f64027218p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00ac53515a8cp+0), LIT (0x6.96423e0f6402722p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.22982p-4 + 0xd.849ecp-4 i", LIT (0xe.22982p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00a8f88c3be4p+0), LIT (0x6.96423f67ee9c4538p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be4p+0), LIT (0x6.96423f67ee9c454p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be4p+0), LIT (0x6.96423f67ee9c4538p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00a8f88c3be42p+0), LIT (0x6.96423f67ee9c454p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.22983p-4 + 0xd.849ecp-4 i", LIT (0xe.22983p-4), LIT (0xd.849ecp-4), { LIT (0x1.06b00afafb0445acp+0), LIT (0x6.96423cb6350011f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445aep+0), LIT (0x6.96423cb6350012p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445acp+0), LIT (0x6.96423cb6350011f8p-4), ERRNO_UNCHANGED }, { LIT (0x1.06b00afafb0445aep+0), LIT (0x6.96423cb6350012p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.8p+16380 + 0x8p+16380 i", LIT (0xf.8p+16380), LIT (0x8p+16380), { LIT (0x1.03be61de0c283c96p+8192), LIT (0x3.f13db93133426b28p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c98p+8192), LIT (0x3.f13db93133426b28p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c96p+8192), LIT (0x3.f13db93133426b28p+8188), ERRNO_UNCHANGED }, { LIT (0x1.03be61de0c283c98p+8192), LIT (0x3.f13db93133426b2cp+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.8p+16380 + 0xf.8p+16380 i", LIT (0xf.8p+16380), LIT (0xf.8p+16380), { LIT (0x1.14d561462f72313ap+8192), LIT (0x7.2ab0eef99eed6b18p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313cp+8192), LIT (0x7.2ab0eef99eed6b2p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313ap+8192), LIT (0x7.2ab0eef99eed6b18p+8188), ERRNO_UNCHANGED }, { LIT (0x1.14d561462f72313cp+8192), LIT (0x7.2ab0eef99eed6b2p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.8p+16380 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.8p+16380), LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.bf7df5c6a788f0bp+8188), LIT (0x8.20c524036f3e2abp-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0cp+8188), LIT (0x8.20c524036f3e2abp-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bp+8188), LIT (0x8.20c524036f3e2abp-7172), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0cp+8188), LIT (0x8.20c524036f3e2acp-7172), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.8p+16380 + 0xf.fffffp+124 i", LIT (0xf.8p+16380), LIT (0xf.fffffp+124), { LIT (0xf.bf7df5c6a788f0bp+8188), LIT (0x8.20c51be2aa1a684p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0cp+8188), LIT (0x8.20c51be2aa1a685p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0bp+8188), LIT (0x8.20c51be2aa1a684p-8068), ERRNO_UNCHANGED }, { LIT (0xf.bf7df5c6a788f0cp+8188), LIT (0x8.20c51be2aa1a685p-8068), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.a24adp+28 + 0x8.0f148p+36 i", LIT (0xf.a24adp+28), LIT (0x8.0f148p+36), { LIT (0x8.0f544aab1480595p+16), LIT (0x7.ffc0aea89479a128p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480596p+16), LIT (0x7.ffc0aea89479a128p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480595p+16), LIT (0x7.ffc0aea89479a128p+16), ERRNO_UNCHANGED }, { LIT (0x8.0f544aab1480596p+16), LIT (0x7.ffc0aea89479a13p+16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + +0 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x0p+0), { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0x4p-1076 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x4p-1076), { LIT (0xf.ffffffffffffbffp+508), LIT (0x2.00000000000008p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x2.00000000000008p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x2.00000000000008p-1588), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x2.0000000000000804p-1588), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0x4p-16448 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x4p-16448), { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0x8.8p-8192 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8.8p-8192), { LIT (0xf.ffffffffffffbffp+508), LIT (0x4.40000000000011p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.40000000000011p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x4.40000000000011p-8704), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.4000000000001108p-8704), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0x8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p+1020), { LIT (0x1.077225f1da5717fcp+512), LIT (0x3.e30ee78adee43c44p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fep+512), LIT (0x3.e30ee78adee43c48p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fcp+512), LIT (0x3.e30ee78adee43c44p+508), ERRNO_UNCHANGED }, { LIT (0x1.077225f1da5717fep+512), LIT (0x3.e30ee78adee43c48p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0x8p+16380 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0x8p-152 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p-152), { LIT (0xf.ffffffffffffbffp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x4.0000000000001p-664), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4.0000000000001008p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0x8p-16448 i", LIT (0xf.ffffffffffff8p+1020), LIT (0x8p-16448), { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffcp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.ffffffffffffcp+508), LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0xf.8p+16380 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.8p+16380), { LIT (0xb.22b202b460e1ba2p+8188), LIT (0xb.22b202b460e1ba2p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba3p+8188), LIT (0xb.22b202b460e1ba3p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2p+8188), LIT (0xb.22b202b460e1ba2p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba3p+8188), LIT (0xb.22b202b460e1ba3p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.19435caffa9f86f2p+512), LIT (0x7.480c4e3db209ec78p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f2p+512), LIT (0x7.480c4e3db209ec8p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f2p+512), LIT (0x7.480c4e3db209ec78p+508), ERRNO_UNCHANGED }, { LIT (0x1.19435caffa9f86f4p+512), LIT (0x7.480c4e3db209ec8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020 + 0xf.fffffp+124 i", LIT (0xf.ffffffffffff8p+1020), LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffffbffp+508), LIT (0x7.fffff80000001ff8p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x7.fffff80000002p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffbffp+508), LIT (0x7.fffff80000001ff8p-388), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffcp+508), LIT (0x7.fffff80000002p-388), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + +0 i", LIT (0xf.fffffp+124), LIT (0x0p+0), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x1p+0 i", LIT (0xf.fffffp+124), LIT (0x1p+0), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x8.000004000003p-68), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x8.000004000003001p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x4p-1076 i", LIT (0xf.fffffp+124), LIT (0x4p-1076), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x2.000001000000cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x2.000001000000cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x2.000001000000cp-1140), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x2.000001000000c004p-1140), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x4p-16448 i", LIT (0xf.fffffp+124), LIT (0x4p-16448), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffep+60), LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x8.8p-512 i", LIT (0xf.fffffp+124), LIT (0x8.8p-512), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.40000220000198p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.40000220000198p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.40000220000198p-576), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.4000022000019808p-576), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x8.8p-8192 i", LIT (0xf.fffffp+124), LIT (0x8.8p-8192), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.40000220000198p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.40000220000198p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.40000220000198p-8256), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.4000022000019808p-8256), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x8p+1020 i", LIT (0xf.fffffp+124), LIT (0x8p+1020), { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x8p+508), ERRNO_UNCHANGED }, { LIT (0x8p+508), LIT (0x7.fffffffffffffff8p+508), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+508), LIT (0x8p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x8p+16380 i", LIT (0xf.fffffp+124), LIT (0x8p+16380), { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED }, { LIT (0x8p+8188), LIT (0x7.fffffffffffffff8p+8188), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p+8188), LIT (0x8p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x8p-152 i", LIT (0xf.fffffp+124), LIT (0x8p-152), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x4.0000020000018p-216), ERRNO_UNCHANGED }, { LIT (0xf.fffff7fffffep+60), LIT (0x4.0000020000018008p-216), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0x8p-16448 i", LIT (0xf.fffffp+124), LIT (0x8p-16448), { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffep+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffdfffp+60), LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0xf.fffff7fffffep+60), LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0xe.7e0c2p+116 i", LIT (0xf.fffffp+124), LIT (0xe.7e0c2p+116), { LIT (0x1.000019c0e5da2558p+64), LIT (0x7.3f055562b51cd3b8p+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da2558p+64), LIT (0x7.3f055562b51cd3cp+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da2558p+64), LIT (0x7.3f055562b51cd3b8p+52), ERRNO_UNCHANGED }, { LIT (0x1.000019c0e5da255ap+64), LIT (0x7.3f055562b51cd3cp+52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0xf.8p+16380 i", LIT (0xf.fffffp+124), LIT (0xf.8p+16380), { LIT (0xb.22b202b460e1ba2p+8188), LIT (0xb.22b202b460e1ba2p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba3p+8188), LIT (0xb.22b202b460e1ba3p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba2p+8188), LIT (0xb.22b202b460e1ba2p+8188), ERRNO_UNCHANGED }, { LIT (0xb.22b202b460e1ba3p+8188), LIT (0xb.22b202b460e1ba3p+8188), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0xf.ffffffffffff8p+1020 i", LIT (0xf.fffffp+124), LIT (0xf.ffffffffffff8p+1020), { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61bp+508), LIT (0xb.504f333f9de61bp+508), ERRNO_UNCHANGED }, { LIT (0xb.504f333f9de61b1p+508), LIT (0xb.504f333f9de61b1p+508), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124 + 0xf.fffffp+124 i", LIT (0xf.fffffp+124), LIT (0xf.fffffp+124), { LIT (0x1.19435c2358f1103p+64), LIT (0x7.480c4a99abe201cp+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11032p+64), LIT (0x7.480c4a99abe201cp+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f1103p+64), LIT (0x7.480c4a99abe201cp+60), ERRNO_UNCHANGED }, { LIT (0x1.19435c2358f11032p+64), LIT (0x7.480c4a99abe201c8p+60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fp+1020 + +0 i", LIT (0xf.fp+1020), LIT (0x0p+0), { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fp+1020 + 0x8.8p-512 i", LIT (0xf.fp+1020), LIT (0x8.8p-512), { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x4.422199552a8cb65p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x4.422199552a8cb658p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x4.422199552a8cb65p-1024), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x4.422199552a8cb658p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fp+1020 + 0x8p-152 i", LIT (0xf.fp+1020), LIT (0x8p-152), { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x4.0201814118fce7dp-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x4.0201814118fce7d8p-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+508), LIT (0x4.0201814118fce7dp-664), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+508), LIT (0x4.0201814118fce7d8p-664), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fp+124 + 0x8.8p-64 i", LIT (0xf.fp+124), LIT (0x8.8p-64), { LIT (0xf.f7fdfeff5f8fabbp+60), LIT (0x4.422199552a8cb65p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+60), LIT (0x4.422199552a8cb658p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+60), LIT (0x4.422199552a8cb65p-128), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+60), LIT (0x4.422199552a8cb658p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fp+16380 + +0 i", LIT (0xf.fp+16380), LIT (0x0p+0), { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fp+16380 + 0x4p-1076 i", LIT (0xf.fp+16380), LIT (0x4p-1076), { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x2.0100c0a08c7e73e8p-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x2.0100c0a08c7e73ecp-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x2.0100c0a08c7e73e8p-9268), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x2.0100c0a08c7e73ecp-9268), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fp+16380 + 0x8.8p-8192 i", LIT (0xf.fp+16380), LIT (0x8.8p-8192), { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x4.422199552a8cb65p-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x4.422199552a8cb658p-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x4.422199552a8cb65p-16384), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x4.422199552a8cb658p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fp+16380 + 0x8p-152 i", LIT (0xf.fp+16380), LIT (0x8p-152), { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x4.0201814118fce7dp-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x4.0201814118fce7d8p-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabbp+8188), LIT (0x4.0201814118fce7dp-8344), ERRNO_UNCHANGED }, { LIT (0xf.f7fdfeff5f8fabcp+8188), LIT (0x4.0201814118fce7d8p-8344), ERRNO_UNCHANGED } },
#endif
  };

static void
csqrt_test (void)
{
  ALL_RM_TEST (csqrt, 0, csqrt_test_data, RUN_TEST_LOOP_c_c, END_COMPLEX);
}

static void
do_test (void)
{
  csqrt_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

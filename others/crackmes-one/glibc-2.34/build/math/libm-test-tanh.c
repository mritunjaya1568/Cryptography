/* Test tanh.
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

static const struct test_f_f_data tanh_test_data[] =
  {
    { "inf", plus_infty, { 1, ERRNO_UNCHANGED }, { 1, ERRNO_UNCHANGED }, { 1, ERRNO_UNCHANGED }, { 1, ERRNO_UNCHANGED } },
    { "-inf", minus_infty, { -1, ERRNO_UNCHANGED }, { -1, ERRNO_UNCHANGED }, { -1, ERRNO_UNCHANGED }, { -1, ERRNO_UNCHANGED } },
    { "qNaN", qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "-sNaN", -snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },

#if (TEST_COND_binary128)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.4p+4", LIT (-0x1.4p+4), { LIT (-0xf.fffffffffffff63436db3272edfp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63436db3272edfp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63436db3272ede8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63436db3272ede8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.6p+4", LIT (-0x1.6p+4), { LIT (-0xf.ffffffffffffffd2117c43d16e3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffd2117c43d16e28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffd2117c43d16e28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffd2117c43d16e28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.9p+4", LIT (-0x1.9p+4), { LIT (-0xf.ffffffffffffffffe2da82ab81f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffe2da82ab81f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffe2da82ab81fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffe2da82ab81fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.ep+4", LIT (-0x1.ep+4), { LIT (-0xf.ffffffffffffffffffffa9479b98p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffa9479b98p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffa9479b9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffa9479b9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (-0xc.2f7d5a8a79ca2ac3195f149e214p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2ac3195f149e2138p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2ac3195f149e2138p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2ac3195f149e2138p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.3p+4", LIT (-0x2.3p+4), { LIT (-0xf.fffffffffffffffffffffffefep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffefdf8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffefdf8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffefdf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.6082fp-4", LIT (-0x2.6082fp-4), { LIT (-0x2.5c12e9588a795db643b503e27bp-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db643b503e27bp-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db643b503e27afep-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db643b503e27afep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.8p+4", LIT (-0x2.8p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (-0xf.6ca82f0de1e9e99e2197e1f412bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99e2197e1f412bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99e2197e1f412a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99e2197e1f412a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.2f59p-4", LIT (-0x3.2f59p-4), { LIT (-0x3.24bf114777f8faf96902769a0d84p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf96902769a0d84p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf96902769a0d82p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf96902769a0d82p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.2p+4", LIT (-0x3.2p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.b60d7cp-4", LIT (-0x3.b60d7cp-4), { LIT (-0x3.a55fc883707aca21b3d3eb4c9496p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca21b3d3eb4c9496p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca21b3d3eb4c9494p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca21b3d3eb4c9494p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.c0d8b4p-4", LIT (-0x3.c0d8b4p-4), { LIT (-0x3.af99f04902f54a5e1438d014c592p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5e1438d014c59p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5e1438d014c59p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5e1438d014c59p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.c0d8b54c5a488p-4", LIT (-0x3.c0d8b54c5a488p-4), { LIT (-0x3.af99f183b9d71e966538c40d39p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e966538c40d38fep-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e966538c40d38fep-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e966538c40d38fep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.c0d8b8p-4", LIT (-0x3.c0d8b8p-4), { LIT (-0x3.af99f412aab73f59c1a2be2a32fp-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f59c1a2be2a32fp-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f59c1a2be2a32eep-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f59c1a2be2a32eep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (-0xf.ebbe888d057ff1057854585bfdbp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1057854585bfdbp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1057854585bfda8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1057854585bfda8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (-0xf.fd40b84505a10b42b92360cee308p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b42b92360cee308p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b42b92360cee3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b42b92360cee3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffffffffffffffep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16448", LIT (-0x4p-16448), { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16496", LIT (-0x4p-16496), { LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (-0xf.ffa0cb346f889a800b7186cb573p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a800b7186cb573p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a800b7186cb5728p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a800b7186cb5728p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (-0xf.fff31d5f129deedd313b5726566p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedd313b57265658p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedd313b57265658p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedd313b57265658p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (-0xf.fffe4193a878ed68e8057dafd2d8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed68e8057dafd2dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed68e8057dafd2dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed68e8057dafd2dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (-0xf.ffffc39548fc3487707369d6c578p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc3487707369d6c578p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc3487707369d6c57p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc3487707369d6c57p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x7.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x7.fffffffffffcp-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (-0xf.fffff7d2cebbe208a50ed05e717p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe208a50ed05e717p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe208a50ed05e7168p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe208a50ed05e7168p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.fffffee4b79aaa94a2b6168968ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa94a2b616896898p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa94a2b616896898p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa94a2b616896898p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xcp-4", LIT (-0xcp-4), { LIT (-0xa.2991f2a97914139d5832bf78fb18p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139d5832bf78fb1p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139d5832bf78fb1p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139d5832bf78fb1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xe.9e035p+0", LIT (-0xe.9e035p+0), { LIT (-0xf.fffffffff8ebbffbf5b020cd6ab8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffbf5b020cd6ab8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffbf5b020cd6abp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffbf5b020cd6abp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffffffffffffff8p+16380", LIT (-0xf.fffffffffffffffffffffffffff8p+16380), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xfp+0", LIT (-0xfp+0), { LIT (-0xf.fffffffffcb523e7aa70681dc27p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523e7aa70681dc27p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523e7aa70681dc268p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523e7aa70681dc268p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0xf.fffffffffffff63436db3272ede8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63436db3272edfp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63436db3272ede8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63436db3272edfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.6p+4", LIT (0x1.6p+4), { LIT (0xf.ffffffffffffffd2117c43d16e28p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffd2117c43d16e28p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffd2117c43d16e28p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffd2117c43d16e3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0xf.ffffffffffffffffe2da82ab81fp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffe2da82ab81f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffe2da82ab81fp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffe2da82ab81f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0xf.ffffffffffffffffffffa9479b9p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffa9479b98p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffa9479b9p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffa9479b98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xc.2f7d5a8a79ca2ac3195f149e2138p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2ac3195f149e2138p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2ac3195f149e2138p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2ac3195f149e214p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffffffffffffff8p-10004), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-10004), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffffaaaaaaaaaacccccccc8p-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaaaaaaacccccccdp-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaaaaaaacccccccc8p-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaaaaaaacccccccdp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffffffffffffffffaaaaaaaa8p-44), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffaaaaaaaa8p-44), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffaaaaaaaa8p-44), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffaaaaaaabp-44), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffffffffffffffff8p-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffffffffffffff8p-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.00f984p-4", LIT (0x2.00f984p-4), { LIT (0x1.fe4f391dbd3ecd714619cc709977p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd714619cc709978p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd714619cc709977p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd714619cc709978p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.00f9857616524p-4", LIT (0x2.00f9857616524p-4), { LIT (0x1.fe4f3a8e0515344ff794387d92d8p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515344ff794387d92d8p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515344ff794387d92d8p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515344ff794387d92d9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.00f988p-4", LIT (0x2.00f988p-4), { LIT (0x1.fe4f3d0dd83fadafe273ab28dd29p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadafe273ab28dd29p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadafe273ab28dd29p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadafe273ab28dd2ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0xf.fffffffffffffffffffffffefdf8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffefdf8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffefdf8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffefep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.dp+4", LIT (0x2.dp+4), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.e6f54cp-4", LIT (0x2.e6f54cp-4), { LIT (0x2.deea7ea48e5ed334e492b456066cp-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334e492b456066ep-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334e492b456066cp-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334e492b456066ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xf.6ca82f0de1e9e99e2197e1f412a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e99e2197e1f412bp-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e99e2197e1f412a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e99e2197e1f412bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16", LIT (0x2p-16), { LIT (0x1.fffffffd5555555999999992b12bp-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555999999992b12bp-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555999999992b12bp-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555999999992b12cp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-36", LIT (0x2p-36), { LIT (0x1.fffffffffffffffffd5555555555p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffd5555555555p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffd5555555555p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffd5555555556p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-56", LIT (0x2p-56), { LIT (0x1.fffffffffffffffffffffffffffdp-56), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffffffffffffdp-56), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffffffffffffdp-56), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffffffffffffep-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.397f2cp-4", LIT (0x3.397f2cp-4), { LIT (0x3.2e7fba1674b721d00a6064e53d74p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721d00a6064e53d74p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721d00a6064e53d74p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721d00a6064e53d76p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.397f2f50241d031p-4", LIT (0x3.397f2f50241d031p-4), { LIT (0x3.2e7fbd450f41bf76f8da4b4ea528p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf76f8da4b4ea52ap-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf76f8da4b4ea528p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf76f8da4b4ea52ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.397f2f50241d2p-4", LIT (0x3.397f2f50241d2p-4), { LIT (0x3.2e7fbd450f41db420b102ed5c87cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db420b102ed5c87cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db420b102ed5c87cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db420b102ed5c87ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.397f2f50241dp-4", LIT (0x3.397f2f50241dp-4), { LIT (0x3.2e7fbd450f41bc85f9231ae637dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc85f9231ae637dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc85f9231ae637dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc85f9231ae637d2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.397f3p-4", LIT (0x3.397f3p-4), { LIT (0x3.2e7fbdedf6f4e4677fd41531d3bp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e4677fd41531d3b2p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e4677fd41531d3bp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e4677fd41531d3b2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.b99798p-4", LIT (0x3.b99798p-4), { LIT (0x3.a8baac02f578491e7a245d926178p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578491e7a245d92617ap-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578491e7a245d926178p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578491e7a245d92617ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.b9979a543d0fap-4", LIT (0x3.b9979a543d0fap-4), { LIT (0x3.a8baae38037e12aaff36972c4886p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12aaff36972c4886p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12aaff36972c4886p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12aaff36972c4888p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.b9979a543d0fbfa8p-4", LIT (0x3.b9979a543d0fbfa8p-4), { LIT (0x3.a8baae38037e30ab26bdc37e7456p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30ab26bdc37e7458p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30ab26bdc37e7456p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30ab26bdc37e7458p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.b9979a543d0fcp-4", LIT (0x3.b9979a543d0fcp-4), { LIT (0x3.a8baae38037e30fe8c8253c51892p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30fe8c8253c51894p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30fe8c8253c51892p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30fe8c8253c51894p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.b9979cp-4", LIT (0x3.b9979cp-4), { LIT (0x3.a8baafcd6721c9d281b58b34a988p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d281b58b34a98ap-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d281b58b34a988p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d281b58b34a98ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.c80ea8p-4", LIT (0x3.c80ea8p-4), { LIT (0x3.b66d36fa7234778e14df5c18c678p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234778e14df5c18c67ap-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234778e14df5c18c678p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234778e14df5c18c67ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.c80eaa7adaa3p-4", LIT (0x3.c80eaa7adaa3p-4), { LIT (0x3.b66d39531e6043a85263d7aef20cp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a85263d7aef20ep-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a85263d7aef20cp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a85263d7aef20ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.c80eacp-4", LIT (0x3.c80eacp-4), { LIT (0x3.b66d3ac34ff934cf70cbc132d382p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934cf70cbc132d382p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934cf70cbc132d382p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934cf70cbc132d384p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3p+0", LIT (0x3p+0), { LIT (0xf.ebbe888d057ff1057854585bfda8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1057854585bfdbp-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1057854585bfda8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1057854585bfdbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p+0", LIT (0x4p+0), { LIT (0xf.fd40b84505a10b42b92360cee3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b42b92360cee308p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b42b92360cee3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b42b92360cee308p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.fffffffffffffffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x3.fffffffffffffffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x3.ffffeaaaab33332fbefc0623efe6p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33332fbefc0623efe6p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33332fbefc0623efe6p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33332fbefc0623efe8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.fffffffffffffffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0x3.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496", LIT (0x4p-16496), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-32", LIT (0x4p-32), { LIT (0x3.ffffffffffffffeaaaaaaaaaaaaap-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffeaaaaaaaaaaaaap-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffeaaaaaaaaaaaaap-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffeaaaaaaaaaaaacp-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x3.ffffffffffffffffffffffffeaaap-52), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffeaaap-52), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffeaaap-52), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffeaacp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5p+0", LIT (0x5p+0), { LIT (0xf.ffa0cb346f889a800b7186cb5728p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a800b7186cb573p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a800b7186cb5728p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a800b7186cb573p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.5821dp-4", LIT (0x6.5821dp-4), { LIT (0x6.080bf03812d804f456a4858a20dp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f456a4858a20dp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f456a4858a20dp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f456a4858a20d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.fff31d5f129deedd313b57265658p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deedd313b57265658p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deedd313b57265658p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deedd313b5726566p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.a18e8p-4", LIT (0x7.a18e8p-4), { LIT (0x7.19c5470dc5d6c0913805237beb4cp-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c0913805237beb5p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c0913805237beb4cp-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c0913805237beb5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.b9985p-4", LIT (0x7.b9985p-4), { LIT (0x7.2d06324738d23d4d4328c1a80f98p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d4d4328c1a80f9cp-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d4d4328c1a80f98p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d4d4328c1a80f9cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xf.fffe4193a878ed68e8057dafd2dp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed68e8057dafd2dp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed68e8057dafd2dp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed68e8057dafd2d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.4024a11b6610672b2982b852e8p-4", LIT (0x8.4024a11b6610672b2982b852e8p-4), { LIT (0x7.96e91a6be7d9af71106ffad34224p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af71106ffad34228p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af71106ffad34224p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af71106ffad34228p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.4024a11b6610672p-4", LIT (0x8.4024a11b6610672p-4), { LIT (0x7.96e91a6be7d9af6869df15f309e4p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af6869df15f309e4p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af6869df15f309e4p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af6869df15f309e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.4024a11b6610673p-4", LIT (0x8.4024a11b6610673p-4), { LIT (0x7.96e91a6be7d9af74d043bee12618p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af74d043bee12618p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af74d043bee12618p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af74d043bee1261cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.4024a11b66108p-4", LIT (0x8.4024a11b66108p-4), { LIT (0x7.96e91a6be7d9c2af9a5db822e298p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2af9a5db822e29cp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2af9a5db822e298p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2af9a5db822e29cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.4024a11b661p-4", LIT (0x8.4024a11b661p-4), { LIT (0x7.96e91a6be7d95f7c75164741421cp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f7c75164741422p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f7c75164741421cp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f7c75164741422p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.4024ap-4", LIT (0x8.4024ap-4), { LIT (0x7.96e9199045abc439fc0595df5b88p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc439fc0595df5b8cp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc439fc0595df5b88p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc439fc0595df5b8cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.4024bp-4", LIT (0x8.4024bp-4), { LIT (0x7.96e925f6aa4fa0f29663e3f79f08p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0f29663e3f79f08p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0f29663e3f79f08p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0f29663e3f79f0cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.7c9e5p-4", LIT (0x8.7c9e5p-4), { LIT (0x7.c57313d93519a7edb391a912d4e8p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7edb391a912d4e8p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7edb391a912d4e8p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7edb391a912d4ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.c259ep-4", LIT (0x8.c259ep-4), { LIT (0x7.fa4a1eea64fa283aa32d48b14b94p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa283aa32d48b14b94p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa283aa32d48b14b94p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa283aa32d48b14b98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.ffffc39548fc3487707369d6c57p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc3487707369d6c578p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc3487707369d6c57p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc3487707369d6c578p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.fffffffffffffffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x7.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x7.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-28", LIT (0x8p-28), { LIT (0x7.ffffffffffff5555555555556664p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff5555555555556668p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff5555555555556664p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff5555555555556668p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-48", LIT (0x8p-48), { LIT (0x7.ffffffffffffffffffffff555554p-48), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffff555554p-48), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffff555554p-48), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffff555558p-48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-60", LIT (0x8p-60), { LIT (0x7.fffffffffffffffffffffffffffcp-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-8", LIT (0x8p-8), { LIT (0x7.ff556664ac778a0c17f05ce08814p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a0c17f05ce08814p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a0c17f05ce08814p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a0c17f05ce08818p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.fffffffffffffffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x9p+0", LIT (0x9p+0), { LIT (0xf.fffff7d2cebbe208a50ed05e7168p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe208a50ed05e717p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe208a50ed05e7168p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe208a50ed05e717p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xap+0", LIT (0xap+0), { LIT (0xf.fffffee4b79aaa94a2b616896898p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa94a2b616896898p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa94a2b616896898p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa94a2b6168968ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.2991f2a97914139d5832bf78fb1p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914139d5832bf78fb1p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914139d5832bf78fb1p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914139d5832bf78fb18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.05031p-16", LIT (0xe.05031p-16), { LIT (0xe.05030c697d9e582f4a79c88f0198p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e582f4a79c88f0198p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e582f4a79c88f0198p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e582f4a79c88f01ap-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.6c659p-4", LIT (0xe.6c659p-4), { LIT (0xb.78df781e11d83e198e857e22169p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e198e857e22169p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e198e857e22169p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e198e857e221698p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffff8p+16380", LIT (0xf.fffffffffffffffffffffffffff8p+16380), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xfp+0", LIT (0xfp+0), { LIT (0xf.fffffffffcb523e7aa70681dc268p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523e7aa70681dc27p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523e7aa70681dc268p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523e7aa70681dc27p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.4p+4", LIT (-0x1.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.6p+4", LIT (-0x1.6p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.9p+4", LIT (-0x1.9p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.ep+4", LIT (-0x1.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (-0xc.2f7d6p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d6p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.3p+4", LIT (-0x2.3p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.6082fp-4", LIT (-0x2.6082fp-4), { LIT (-0x2.5c12ecp-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.8p+4", LIT (-0x2.8p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (-0xf.6ca83p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca83p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.2f59p-4", LIT (-0x3.2f59p-4), { LIT (-0x3.24bf14p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf1p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf1p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.2p+4", LIT (-0x3.2p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.b60d7cp-4", LIT (-0x3.b60d7cp-4), { LIT (-0x3.a55fccp-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.c0d8b4p-4", LIT (-0x3.c0d8b4p-4), { LIT (-0x3.af99f4p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99fp-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99fp-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.c0d8b8p-4", LIT (-0x3.c0d8b8p-4), { LIT (-0x3.af99f8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f4p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f4p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (-0xf.ebbe9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (-0xf.fd40cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (-0xf.ffa0dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (-0xf.fff32p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff32p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (-0xf.fffe5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (-0xf.ffffdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xcp-4", LIT (-0xcp-4), { LIT (-0xa.2992p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991fp-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991fp-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xe.9e035p+0", LIT (-0xe.9e035p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xfp+0", LIT (-0xfp+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.6p+4", LIT (0x1.6p+4), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xc.2f7d5p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d6p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffp-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffp-24), ERRNO_UNCHANGED }, { LIT (0x1p-20), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-24), ERRNO_UNCHANGED }, { LIT (0x1p-20), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffp-44), ERRNO_UNCHANGED }, { LIT (0x1p-40), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-44), ERRNO_UNCHANGED }, { LIT (0x1p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffp-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.00f984p-4", LIT (0x2.00f984p-4), { LIT (0x1.fe4f38p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3ap-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f38p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.00f988p-4", LIT (0x2.00f988p-4), { LIT (0x1.fe4f3cp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3ep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3cp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.dp+4", LIT (0x2.dp+4), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.e6f54cp-4", LIT (0x2.e6f54cp-4), { LIT (0x2.deea7cp-4), ERRNO_UNCHANGED }, { LIT (0x2.deea8p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7cp-4), ERRNO_UNCHANGED }, { LIT (0x2.deea8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xf.6ca82p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca83p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca83p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-16", LIT (0x2p-16), { LIT (0x1.fffffep-16), ERRNO_UNCHANGED }, { LIT (0x2p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffep-16), ERRNO_UNCHANGED }, { LIT (0x2p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-36", LIT (0x2p-36), { LIT (0x1.fffffep-36), ERRNO_UNCHANGED }, { LIT (0x2p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffep-36), ERRNO_UNCHANGED }, { LIT (0x2p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-56", LIT (0x2p-56), { LIT (0x1.fffffep-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED }, { LIT (0x1.fffffep-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.397f2cp-4", LIT (0x3.397f2cp-4), { LIT (0x3.2e7fb8p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbcp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fb8p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.397f3p-4", LIT (0x3.397f3p-4), { LIT (0x3.2e7fbcp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbcp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbcp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.b99798p-4", LIT (0x3.b99798p-4), { LIT (0x3.a8baacp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baacp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baacp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8babp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.b9979cp-4", LIT (0x3.b9979cp-4), { LIT (0x3.a8baacp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8babp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baacp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8babp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.c80ea8p-4", LIT (0x3.c80ea8p-4), { LIT (0x3.b66d34p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d34p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.c80eacp-4", LIT (0x3.c80eacp-4), { LIT (0x3.b66d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3cp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d38p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3p+0", LIT (0x3p+0), { LIT (0xf.ebbe8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe9p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p+0", LIT (0x4p+0), { LIT (0xf.fd40bp-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40cp-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40bp-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x3.ffffe8p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffecp-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffe8p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffecp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-32", LIT (0x4p-32), { LIT (0x3.fffffcp-32), ERRNO_UNCHANGED }, { LIT (0x4p-32), ERRNO_UNCHANGED }, { LIT (0x3.fffffcp-32), ERRNO_UNCHANGED }, { LIT (0x4p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x3.fffffcp-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED }, { LIT (0x3.fffffcp-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5p+0", LIT (0x5p+0), { LIT (0xf.ffa0cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0dp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.5821dp-4", LIT (0x6.5821dp-4), { LIT (0x6.080bfp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bfp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bfp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.fff31p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff32p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff32p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7.a18e8p-4", LIT (0x7.a18e8p-4), { LIT (0x7.19c54p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c548p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c54p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c548p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7.b9985p-4", LIT (0x7.b9985p-4), { LIT (0x7.2d063p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d063p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d063p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d0638p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xf.fffe4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8.4024ap-4", LIT (0x8.4024ap-4), { LIT (0x7.96e918p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e918p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e918p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e92p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8.4024bp-4", LIT (0x8.4024bp-4), { LIT (0x7.96e92p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e928p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e92p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e928p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8.7c9e5p-4", LIT (0x8.7c9e5p-4), { LIT (0x7.c5731p-4), ERRNO_UNCHANGED }, { LIT (0x7.c5731p-4), ERRNO_UNCHANGED }, { LIT (0x7.c5731p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57318p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8.c259ep-4", LIT (0x8.c259ep-4), { LIT (0x7.fa4a18p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a2p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a18p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.ffffcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-28", LIT (0x8p-28), { LIT (0x7.fffff8p-28), ERRNO_UNCHANGED }, { LIT (0x8p-28), ERRNO_UNCHANGED }, { LIT (0x7.fffff8p-28), ERRNO_UNCHANGED }, { LIT (0x8p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-48", LIT (0x8p-48), { LIT (0x7.fffff8p-48), ERRNO_UNCHANGED }, { LIT (0x8p-48), ERRNO_UNCHANGED }, { LIT (0x7.fffff8p-48), ERRNO_UNCHANGED }, { LIT (0x8p-48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-60", LIT (0x8p-60), { LIT (0x7.fffff8p-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED }, { LIT (0x7.fffff8p-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-8", LIT (0x8p-8), { LIT (0x7.ff556p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff5568p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff5568p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x9p+0", LIT (0x9p+0), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xap+0", LIT (0xap+0), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.2991fp-4), ERRNO_UNCHANGED }, { LIT (0xa.2991fp-4), ERRNO_UNCHANGED }, { LIT (0xa.2991fp-4), ERRNO_UNCHANGED }, { LIT (0xa.2992p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.05031p-16", LIT (0xe.05031p-16), { LIT (0xe.0503p-16), ERRNO_UNCHANGED }, { LIT (0xe.05031p-16), ERRNO_UNCHANGED }, { LIT (0xe.0503p-16), ERRNO_UNCHANGED }, { LIT (0xe.05031p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.6c659p-4", LIT (0xe.6c659p-4), { LIT (0xb.78df7p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df8p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df7p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xfp+0", LIT (0xfp+0), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.4p+4", LIT (-0x1.4p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.6p+4", LIT (-0x1.6p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.9p+4", LIT (-0x1.9p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.ep+4", LIT (-0x1.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (-0xc.2f7d5a8a79ca8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79cap-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79cap-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79cap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.3p+4", LIT (-0x2.3p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.6082fp-4", LIT (-0x2.6082fp-4), { LIT (-0x2.5c12e9588a796p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a796p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a794p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a794p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.8p+4", LIT (-0x2.8p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (-0xf.6ca82f0de1eap-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1eap-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e98p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.2f59p-4", LIT (-0x3.2f59p-4), { LIT (-0x3.24bf114777f9p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f9p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8ep-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.2p+4", LIT (-0x3.2p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.b60d7cp-4", LIT (-0x3.b60d7cp-4), { LIT (-0x3.a55fc883707aep-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707acp-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707acp-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.c0d8b4p-4", LIT (-0x3.c0d8b4p-4), { LIT (-0x3.af99f04902f56p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.c0d8b54c5a488p-4", LIT (-0x3.c0d8b54c5a488p-4), { LIT (-0x3.af99f183b9d72p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d72p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d7p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.c0d8b8p-4", LIT (-0x3.c0d8b8p-4), { LIT (-0x3.af99f412aab74p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab74p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab72p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab72p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (-0xf.ebbe888d058p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d058p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (-0xf.fd40b84505a18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (-0xf.ffa0cb346f89p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f888p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f888p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f888p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (-0xf.fff31d5f129ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129d8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (-0xf.fffe4193a879p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a879p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a8788p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a8788p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (-0xf.ffffc39548fc8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (-0xf.fffff7d2cebcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebb8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.fffffee4b79bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xcp-4", LIT (-0xcp-4), { LIT (-0xa.2991f2a979148p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xe.9e035p+0", LIT (-0xe.9e035p+0), { LIT (-0xf.fffffffff8ecp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8eb8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8eb8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8eb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xfp+0", LIT (-0xfp+0), { LIT (-0xf.fffffffffcb58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.6p+4", LIT (0x1.6p+4), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xc.2f7d5a8a79cap-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79cap-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79cap-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.ffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffffaaa8p-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaa8p-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaa8p-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaabp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.ffffffffffff8p-44), ERRNO_UNCHANGED }, { LIT (0x1p-40), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-44), ERRNO_UNCHANGED }, { LIT (0x1p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.ffffffffffff8p-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.ffffffffffff8p-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.00f984p-4", LIT (0x2.00f984p-4), { LIT (0x1.fe4f391dbd3ecp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3edp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3edp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.00f9857616524p-4", LIT (0x2.00f9857616524p-4), { LIT (0x1.fe4f3a8e05153p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e05153p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e05153p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e05154p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.00f988p-4", LIT (0x2.00f988p-4), { LIT (0x1.fe4f3d0dd83fap-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fbp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fap-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.dp+4", LIT (0x2.dp+4), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.e6f54cp-4", LIT (0x2.e6f54cp-4), { LIT (0x2.deea7ea48e5ecp-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5eep-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ecp-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5eep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xf.6ca82f0de1e98p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1eap-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e98p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1eap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-16", LIT (0x2p-16), { LIT (0x1.fffffffd55555p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd55555p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd55555p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd55556p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-36", LIT (0x2p-36), { LIT (0x1.fffffffffffffp-36), ERRNO_UNCHANGED }, { LIT (0x2p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp-36), ERRNO_UNCHANGED }, { LIT (0x2p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-56", LIT (0x2p-56), { LIT (0x1.fffffffffffffp-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.397f2cp-4", LIT (0x3.397f2cp-4), { LIT (0x3.2e7fba1674b72p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b72p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b72p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.397f2f50241d2p-4", LIT (0x3.397f2f50241d2p-4), { LIT (0x3.2e7fbd450f41cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.397f2f50241dp-4", LIT (0x3.397f2f50241dp-4), { LIT (0x3.2e7fbd450f41ap-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41cp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41ap-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.397f3p-4", LIT (0x3.397f3p-4), { LIT (0x3.2e7fbdedf6f4ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4ep-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.b99798p-4", LIT (0x3.b99798p-4), { LIT (0x3.a8baac02f5784p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f5784p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f5784p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f5786p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.b9979a543d0fap-4", LIT (0x3.b9979a543d0fap-4), { LIT (0x3.a8baae38037ep-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e2p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037ep-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.b9979a543d0fcp-4", LIT (0x3.b9979a543d0fcp-4), { LIT (0x3.a8baae38037e2p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e4p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e2p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.b9979cp-4", LIT (0x3.b9979cp-4), { LIT (0x3.a8baafcd6721cp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721cp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721cp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.c80ea8p-4", LIT (0x3.c80ea8p-4), { LIT (0x3.b66d36fa72346p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa72348p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa72346p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa72348p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.c80eaa7adaa3p-4", LIT (0x3.c80eaa7adaa3p-4), { LIT (0x3.b66d39531e604p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e604p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e604p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e606p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.c80eacp-4", LIT (0x3.c80eacp-4), { LIT (0x3.b66d3ac34ff92p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff94p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff92p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3p+0", LIT (0x3p+0), { LIT (0xf.ebbe888d057f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d058p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d058p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p+0", LIT (0x4p+0), { LIT (0xf.fd40b84505a1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x3.ffffeaaaab332p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab334p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab332p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab334p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.ffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-32", LIT (0x4p-32), { LIT (0x3.ffffffffffffep-32), ERRNO_UNCHANGED }, { LIT (0x4p-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-32), ERRNO_UNCHANGED }, { LIT (0x4p-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x3.ffffffffffffep-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5p+0", LIT (0x5p+0), { LIT (0xf.ffa0cb346f888p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f888p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f888p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f89p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.5821dp-4", LIT (0x6.5821dp-4), { LIT (0x6.080bf03812d8p-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d8p-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d8p-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.fff31d5f129d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129ep-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.a18e8p-4", LIT (0x7.a18e8p-4), { LIT (0x7.19c5470dc5d6cp-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6cp-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6cp-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.b9985p-4", LIT (0x7.b9985p-4), { LIT (0x7.2d06324738d2p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d24p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d2p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d24p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xf.fffe4193a8788p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a879p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a8788p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a879p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.4024a11b66108p-4", LIT (0x8.4024a11b66108p-4), { LIT (0x7.96e91a6be7d9cp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9cp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9cp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7dap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.4024a11b661p-4", LIT (0x8.4024a11b661p-4), { LIT (0x7.96e91a6be7d94p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d94p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d94p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.4024ap-4", LIT (0x8.4024ap-4), { LIT (0x7.96e9199045abcp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abcp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abcp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.4024bp-4", LIT (0x8.4024bp-4), { LIT (0x7.96e925f6aa4f8p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fcp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4f8p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.7c9e5p-4", LIT (0x8.7c9e5p-4), { LIT (0x7.c57313d935198p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519cp-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d935198p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.c259ep-4", LIT (0x8.c259ep-4), { LIT (0x7.fa4a1eea64fap-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa4p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fap-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.ffffc39548fcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.ffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-28", LIT (0x8p-28), { LIT (0x7.ffffffffffff4p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff4p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff4p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff8p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-48", LIT (0x8p-48), { LIT (0x7.ffffffffffffcp-48), ERRNO_UNCHANGED }, { LIT (0x8p-48), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-48), ERRNO_UNCHANGED }, { LIT (0x8p-48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-60", LIT (0x8p-60), { LIT (0x7.ffffffffffffcp-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-8", LIT (0x8p-8), { LIT (0x7.ff556664ac778p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac77cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.ffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x9p+0", LIT (0x9p+0), { LIT (0xf.fffff7d2cebb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xap+0", LIT (0xap+0), { LIT (0xf.fffffee4b79a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.2991f2a97914p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a979148p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.05031p-16", LIT (0xe.05031p-16), { LIT (0xe.05030c697d9ep-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e8p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9ep-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.6c659p-4", LIT (0xe.6c659p-4), { LIT (0xb.78df781e11d8p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d8p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d8p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d88p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xfp+0", LIT (0xfp+0), { LIT (0xf.fffffffffcb5p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb5p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb5p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.4p+4", LIT (-0x1.4p+4), { LIT (-0xf.fffffffffffff63436db3272fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63436db3272ecp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63436db3272ecp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63436db3272ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.6p+4", LIT (-0x1.6p+4), { LIT (-0xf.ffffffffffffffd2117c43d17p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffd2117c43d17p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffd2117c43d16cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffd2117c43d16cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.9p+4", LIT (-0x1.9p+4), { LIT (-0xf.ffffffffffffffffe2da82ab84p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffe2da82ab8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffe2da82ab8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffe2da82ab8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.ep+4", LIT (-0x1.ep+4), { LIT (-0xf.ffffffffffffffffffffa9479cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffa9479cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffa94798p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffa94798p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (-0xc.2f7d5a8a79ca2ac3195f149e24p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2ac3195f149e2p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2ac3195f149e2p-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2ac3195f149e2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.3p+4", LIT (-0x2.3p+4), { LIT (-0xf.ffffffffffffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffefcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffefcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffefcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.6082fp-4", LIT (-0x2.6082fp-4), { LIT (-0x2.5c12e9588a795db643b503e27bp-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db643b503e27bp-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db643b503e27ap-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db643b503e27ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.8p+4", LIT (-0x2.8p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (-0xf.6ca82f0de1e9e99e2197e1f414p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99e2197e1f414p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99e2197e1f41p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99e2197e1f41p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.2f59p-4", LIT (-0x3.2f59p-4), { LIT (-0x3.24bf114777f8faf96902769a0ep-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf96902769a0ep-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf96902769a0dp-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf96902769a0dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.2p+4", LIT (-0x3.2p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.b60d7cp-4", LIT (-0x3.b60d7cp-4), { LIT (-0x3.a55fc883707aca21b3d3eb4c95p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca21b3d3eb4c95p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca21b3d3eb4c94p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca21b3d3eb4c94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.c0d8b4p-4", LIT (-0x3.c0d8b4p-4), { LIT (-0x3.af99f04902f54a5e1438d014c6p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5e1438d014c6p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5e1438d014c5p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5e1438d014c5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.c0d8b54c5a488p-4", LIT (-0x3.c0d8b54c5a488p-4), { LIT (-0x3.af99f183b9d71e966538c40d39p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e966538c40d39p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e966538c40d38p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e966538c40d38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.c0d8b8p-4", LIT (-0x3.c0d8b8p-4), { LIT (-0x3.af99f412aab73f59c1a2be2a33p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f59c1a2be2a33p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f59c1a2be2a32p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f59c1a2be2a32p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (-0xf.ebbe888d057ff1057854585cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1057854585bfcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1057854585bfcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1057854585bfcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (-0xf.fd40b84505a10b42b92360cee4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b42b92360cee4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b42b92360ceep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b42b92360ceep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (-0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (-0x3.ffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (-0xf.ffa0cb346f889a800b7186cb58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a800b7186cb58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a800b7186cb54p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a800b7186cb54p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (-0xf.fff31d5f129deedd313b572658p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedd313b572658p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedd313b572654p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedd313b572654p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (-0xf.fffe4193a878ed68e8057dafd4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed68e8057dafd4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed68e8057dafdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed68e8057dafdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (-0xf.ffffc39548fc3487707369d6c8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc3487707369d6c4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc3487707369d6c4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc3487707369d6c4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (-0xf.fffff7d2cebbe208a50ed05e74p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe208a50ed05e7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe208a50ed05e7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe208a50ed05e7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.fffffee4b79aaa94a2b616896cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa94a2b6168968p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa94a2b6168968p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa94a2b6168968p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xcp-4", LIT (-0xcp-4), { LIT (-0xa.2991f2a97914139d5832bf78fcp-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139d5832bf78fcp-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139d5832bf78f8p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139d5832bf78f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xe.9e035p+0", LIT (-0xe.9e035p+0), { LIT (-0xf.fffffffff8ebbffbf5b020cd6cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffbf5b020cd6cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffbf5b020cd68p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffbf5b020cd68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xfp+0", LIT (-0xfp+0), { LIT (-0xf.fffffffffcb523e7aa70681dc4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523e7aa70681dc4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523e7aa70681dcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523e7aa70681dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0xf.fffffffffffff63436db3272ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63436db3272ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63436db3272ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63436db3272fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.6p+4", LIT (0x1.6p+4), { LIT (0xf.ffffffffffffffd2117c43d16cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffd2117c43d17p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffd2117c43d16cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffd2117c43d17p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0xf.ffffffffffffffffe2da82ab8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffe2da82ab8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffe2da82ab8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffe2da82ab84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0xf.ffffffffffffffffffffa94798p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffa9479cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffa94798p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffa9479cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xc.2f7d5a8a79ca2ac3195f149e2p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2ac3195f149e2p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2ac3195f149e2p-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2ac3195f149e24p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffffffffffffcp-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffffaaaaaaaaaacccccccp-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaaaaaaacccccccp-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaaaaaaacccccccp-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaaaaaaacccccdp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffffffffffffffffaaaaaa8p-44), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffaaaaaacp-44), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffaaaaaa8p-44), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffaaaaaacp-44), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffffffffffffffcp-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffffffffffffcp-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.00f984p-4", LIT (0x2.00f984p-4), { LIT (0x1.fe4f391dbd3ecd714619cc7099p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd714619cc70998p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd714619cc7099p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd714619cc70998p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.00f9857616524p-4", LIT (0x2.00f9857616524p-4), { LIT (0x1.fe4f3a8e0515344ff794387d928p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515344ff794387d93p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515344ff794387d928p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515344ff794387d93p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.00f988p-4", LIT (0x2.00f988p-4), { LIT (0x1.fe4f3d0dd83fadafe273ab28ddp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadafe273ab28ddp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadafe273ab28ddp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadafe273ab28dd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0xf.fffffffffffffffffffffffefcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffefcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffefcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.dp+4", LIT (0x2.dp+4), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.e6f54cp-4", LIT (0x2.e6f54cp-4), { LIT (0x2.deea7ea48e5ed334e492b45606p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334e492b45606p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334e492b45606p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334e492b45607p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xf.6ca82f0de1e9e99e2197e1f41p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e99e2197e1f414p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e99e2197e1f41p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e99e2197e1f414p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-16", LIT (0x2p-16), { LIT (0x1.fffffffd5555555999999992b1p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555999999992b1p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555999999992b1p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555999999992b18p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-36", LIT (0x2p-36), { LIT (0x1.fffffffffffffffffd55555555p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffd555555558p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffd55555555p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffffd555555558p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-56", LIT (0x2p-56), { LIT (0x1.ffffffffffffffffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.397f2cp-4", LIT (0x3.397f2cp-4), { LIT (0x3.2e7fba1674b721d00a6064e53dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721d00a6064e53dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721d00a6064e53dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721d00a6064e53ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.397f2f50241d031p-4", LIT (0x3.397f2f50241d031p-4), { LIT (0x3.2e7fbd450f41bf76f8da4b4ea5p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf76f8da4b4ea5p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf76f8da4b4ea5p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf76f8da4b4ea6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.397f2f50241d2p-4", LIT (0x3.397f2f50241d2p-4), { LIT (0x3.2e7fbd450f41db420b102ed5c8p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db420b102ed5c8p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db420b102ed5c8p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db420b102ed5c9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.397f2f50241dp-4", LIT (0x3.397f2f50241dp-4), { LIT (0x3.2e7fbd450f41bc85f9231ae637p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc85f9231ae638p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc85f9231ae637p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc85f9231ae638p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.397f3p-4", LIT (0x3.397f3p-4), { LIT (0x3.2e7fbdedf6f4e4677fd41531d3p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e4677fd41531d4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e4677fd41531d3p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e4677fd41531d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.b99798p-4", LIT (0x3.b99798p-4), { LIT (0x3.a8baac02f578491e7a245d9261p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578491e7a245d9261p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578491e7a245d9261p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578491e7a245d9262p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.b9979a543d0fap-4", LIT (0x3.b9979a543d0fap-4), { LIT (0x3.a8baae38037e12aaff36972c48p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12aaff36972c49p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12aaff36972c48p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12aaff36972c49p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.b9979a543d0fbfa8p-4", LIT (0x3.b9979a543d0fbfa8p-4), { LIT (0x3.a8baae38037e30ab26bdc37e74p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30ab26bdc37e74p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30ab26bdc37e74p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30ab26bdc37e75p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.b9979a543d0fcp-4", LIT (0x3.b9979a543d0fcp-4), { LIT (0x3.a8baae38037e30fe8c8253c518p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30fe8c8253c519p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30fe8c8253c518p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30fe8c8253c519p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.b9979cp-4", LIT (0x3.b9979cp-4), { LIT (0x3.a8baafcd6721c9d281b58b34a9p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d281b58b34aap-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d281b58b34a9p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d281b58b34aap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.c80ea8p-4", LIT (0x3.c80ea8p-4), { LIT (0x3.b66d36fa7234778e14df5c18c6p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234778e14df5c18c6p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234778e14df5c18c6p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234778e14df5c18c7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.c80eaa7adaa3p-4", LIT (0x3.c80eaa7adaa3p-4), { LIT (0x3.b66d39531e6043a85263d7aef2p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a85263d7aef2p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a85263d7aef2p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a85263d7aef3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.c80eacp-4", LIT (0x3.c80eacp-4), { LIT (0x3.b66d3ac34ff934cf70cbc132d3p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934cf70cbc132d4p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934cf70cbc132d3p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934cf70cbc132d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3p+0", LIT (0x3p+0), { LIT (0xf.ebbe888d057ff1057854585bfcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1057854585bfcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1057854585bfcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1057854585cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p+0", LIT (0x4p+0), { LIT (0xf.fd40b84505a10b42b92360ceep-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b42b92360cee4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b42b92360ceep-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b42b92360cee4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x3.ffffeaaaab33332fbefc0623efp-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33332fbefc0623fp-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33332fbefc0623efp-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33332fbefc0623fp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.ffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-32", LIT (0x4p-32), { LIT (0x3.ffffffffffffffeaaaaaaaaaaap-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffeaaaaaaaaaabp-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffeaaaaaaaaaaap-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffeaaaaaaaaaabp-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x3.ffffffffffffffffffffffffeap-52), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffebp-52), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffeap-52), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffebp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5p+0", LIT (0x5p+0), { LIT (0xf.ffa0cb346f889a800b7186cb54p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a800b7186cb58p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a800b7186cb54p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a800b7186cb58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.5821dp-4", LIT (0x6.5821dp-4), { LIT (0x6.080bf03812d804f456a4858a2p-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f456a4858a2p-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f456a4858a2p-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f456a4858a22p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.fff31d5f129deedd313b572654p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deedd313b572658p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deedd313b572654p-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deedd313b572658p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.a18e8p-4", LIT (0x7.a18e8p-4), { LIT (0x7.19c5470dc5d6c0913805237beap-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c0913805237becp-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c0913805237beap-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c0913805237becp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.b9985p-4", LIT (0x7.b9985p-4), { LIT (0x7.2d06324738d23d4d4328c1a80ep-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d4d4328c1a81p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d4d4328c1a80ep-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d4d4328c1a81p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xf.fffe4193a878ed68e8057dafdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed68e8057dafd4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed68e8057dafdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed68e8057dafd4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.4024a11b6610672b2982b852e8p-4", LIT (0x8.4024a11b6610672b2982b852e8p-4), { LIT (0x7.96e91a6be7d9af71106ffad342p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af71106ffad342p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af71106ffad342p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af71106ffad344p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.4024a11b6610672p-4", LIT (0x8.4024a11b6610672p-4), { LIT (0x7.96e91a6be7d9af6869df15f308p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af6869df15f30ap-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af6869df15f308p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af6869df15f30ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.4024a11b6610673p-4", LIT (0x8.4024a11b6610673p-4), { LIT (0x7.96e91a6be7d9af74d043bee126p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af74d043bee126p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af74d043bee126p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af74d043bee128p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.4024a11b66108p-4", LIT (0x8.4024a11b66108p-4), { LIT (0x7.96e91a6be7d9c2af9a5db822e2p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2af9a5db822e2p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2af9a5db822e2p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2af9a5db822e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.4024a11b661p-4", LIT (0x8.4024a11b661p-4), { LIT (0x7.96e91a6be7d95f7c7516474142p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f7c7516474142p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f7c7516474142p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f7c7516474144p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.4024ap-4", LIT (0x8.4024ap-4), { LIT (0x7.96e9199045abc439fc0595df5ap-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc439fc0595df5cp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc439fc0595df5ap-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc439fc0595df5cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.4024bp-4", LIT (0x8.4024bp-4), { LIT (0x7.96e925f6aa4fa0f29663e3f79ep-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0f29663e3f7ap-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0f29663e3f79ep-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0f29663e3f7ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.7c9e5p-4", LIT (0x8.7c9e5p-4), { LIT (0x7.c57313d93519a7edb391a912d4p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7edb391a912d4p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7edb391a912d4p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7edb391a912d6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.c259ep-4", LIT (0x8.c259ep-4), { LIT (0x7.fa4a1eea64fa283aa32d48b14ap-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa283aa32d48b14cp-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa283aa32d48b14ap-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa283aa32d48b14cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.ffffc39548fc3487707369d6c4p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc3487707369d6c4p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc3487707369d6c4p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc3487707369d6c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-28", LIT (0x8p-28), { LIT (0x7.ffffffffffff55555555555566p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff55555555555566p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff55555555555566p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff55555555555568p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-48", LIT (0x8p-48), { LIT (0x7.ffffffffffffffffffffff5554p-48), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffff5556p-48), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffff5554p-48), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffffffffffff5556p-48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-60", LIT (0x8p-60), { LIT (0x7.fffffffffffffffffffffffffep-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-8", LIT (0x8p-8), { LIT (0x7.ff556664ac778a0c17f05ce088p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a0c17f05ce088p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a0c17f05ce088p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a0c17f05ce08ap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "0x9p+0", LIT (0x9p+0), { LIT (0xf.fffff7d2cebbe208a50ed05e7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe208a50ed05e7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe208a50ed05e7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe208a50ed05e74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xap+0", LIT (0xap+0), { LIT (0xf.fffffee4b79aaa94a2b6168968p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa94a2b6168968p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa94a2b6168968p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa94a2b616896cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.2991f2a97914139d5832bf78f8p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914139d5832bf78fcp-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914139d5832bf78f8p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914139d5832bf78fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.05031p-16", LIT (0xe.05031p-16), { LIT (0xe.05030c697d9e582f4a79c88fp-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e582f4a79c88fp-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e582f4a79c88fp-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e582f4a79c88f04p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.6c659p-4", LIT (0xe.6c659p-4), { LIT (0xb.78df781e11d83e198e857e2214p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e198e857e2218p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e198e857e2214p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e198e857e2218p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xfp+0", LIT (0xfp+0), { LIT (0xf.fffffffffcb523e7aa70681dcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523e7aa70681dc4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523e7aa70681dcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523e7aa70681dc4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.4p+4", LIT (-0x1.4p+4), { LIT (-0xf.fffffffffffff64p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.6p+4", LIT (-0x1.6p+4), { LIT (-0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.9p+4", LIT (-0x1.9p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.ep+4", LIT (-0x1.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (-0xc.2f7d5a8a79ca2adp-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.3p+4", LIT (-0x2.3p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.6082fp-4", LIT (-0x2.6082fp-4), { LIT (-0x2.5c12e9588a795db8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db4p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.8p+4", LIT (-0x2.8p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (-0xf.6ca82f0de1e9e9ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e9ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.2f59p-4", LIT (-0x3.2f59p-4), { LIT (-0x3.24bf114777f8fafcp-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.2p+4", LIT (-0x3.2p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.b60d7cp-4", LIT (-0x3.b60d7cp-4), { LIT (-0x3.a55fc883707aca24p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca2p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca2p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.c0d8b4p-4", LIT (-0x3.c0d8b4p-4), { LIT (-0x3.af99f04902f54a6p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a6p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5cp-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.c0d8b54c5a488p-4", LIT (-0x3.c0d8b54c5a488p-4), { LIT (-0x3.af99f183b9d71e98p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e98p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e94p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.c0d8b8p-4", LIT (-0x3.c0d8b8p-4), { LIT (-0x3.af99f412aab73f5cp-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f58p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f58p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (-0xf.ebbe888d057ff11p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (-0xf.fd40b84505a10b5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (-0xf.ffa0cb346f889a9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (-0xf.fff31d5f129deeep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deeep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (-0xf.fffe4193a878ed7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (-0xf.ffffc39548fc349p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (-0xf.fffff7d2cebbe21p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe21p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.fffffee4b79aaaap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xcp-4", LIT (-0xcp-4), { LIT (-0xa.2991f2a9791413ap-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a9791413ap-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xe.9e035p+0", LIT (-0xe.9e035p+0), { LIT (-0xf.fffffffff8ebcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xfp+0", LIT (-0xfp+0), { LIT (-0xf.fffffffffcb523fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.6p+4", LIT (0x1.6p+4), { LIT (0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2adp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffp-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffp-10004), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-10004), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffffaaaaaap-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaabp-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaaap-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaabp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffffffffffffp-44), ERRNO_UNCHANGED }, { LIT (0x1p-40), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-44), ERRNO_UNCHANGED }, { LIT (0x1p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffffp-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffp-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.00f984p-4", LIT (0x2.00f984p-4), { LIT (0x1.fe4f391dbd3ecd7p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd72p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd7p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd72p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.00f9857616524p-4", LIT (0x2.00f9857616524p-4), { LIT (0x1.fe4f3a8e0515344ep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515345p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515344ep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515345p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.00f988p-4", LIT (0x2.00f988p-4), { LIT (0x1.fe4f3d0dd83fadaep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadbp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadaep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.dp+4", LIT (0x2.dp+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.e6f54cp-4", LIT (0x2.e6f54cp-4), { LIT (0x2.deea7ea48e5ed334p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed338p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xf.6ca82f0de1e9e99p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e9ap-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e99p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e9ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16", LIT (0x2p-16), { LIT (0x1.fffffffd55555558p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555ap-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd55555558p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555ap-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-36", LIT (0x2p-36), { LIT (0x1.fffffffffffffffep-36), ERRNO_UNCHANGED }, { LIT (0x2p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-36), ERRNO_UNCHANGED }, { LIT (0x2p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-56", LIT (0x2p-56), { LIT (0x1.fffffffffffffffep-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.397f2cp-4", LIT (0x3.397f2cp-4), { LIT (0x3.2e7fba1674b721dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.397f2f50241d031p-4", LIT (0x3.397f2f50241d031p-4), { LIT (0x3.2e7fbd450f41bf74p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf78p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf74p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.397f2f50241d2p-4", LIT (0x3.397f2f50241d2p-4), { LIT (0x3.2e7fbd450f41db4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db44p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.397f2f50241dp-4", LIT (0x3.397f2f50241dp-4), { LIT (0x3.2e7fbd450f41bc84p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc84p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc84p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc88p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.397f3p-4", LIT (0x3.397f3p-4), { LIT (0x3.2e7fbdedf6f4e464p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e468p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e464p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e468p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.b99798p-4", LIT (0x3.b99798p-4), { LIT (0x3.a8baac02f578491cp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578492p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578491cp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578492p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.b9979a543d0fap-4", LIT (0x3.b9979a543d0fap-4), { LIT (0x3.a8baae38037e12a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12acp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.b9979a543d0fbfa8p-4", LIT (0x3.b9979a543d0fbfa8p-4), { LIT (0x3.a8baae38037e30a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30acp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.b9979a543d0fcp-4", LIT (0x3.b9979a543d0fcp-4), { LIT (0x3.a8baae38037e30fcp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e31p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30fcp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e31p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.b9979cp-4", LIT (0x3.b9979cp-4), { LIT (0x3.a8baafcd6721c9dp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d4p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9dp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.c80ea8p-4", LIT (0x3.c80ea8p-4), { LIT (0x3.b66d36fa7234778cp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234779p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234778cp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234779p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.c80eaa7adaa3p-4", LIT (0x3.c80eaa7adaa3p-4), { LIT (0x3.b66d39531e6043a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.c80eacp-4", LIT (0x3.c80eacp-4), { LIT (0x3.b66d3ac34ff934ccp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934dp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934ccp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3p+0", LIT (0x3p+0), { LIT (0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff11p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p+0", LIT (0x4p+0), { LIT (0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x3.ffffeaaaab33332cp-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33333p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33332cp-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33333p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0x3.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-32", LIT (0x4p-32), { LIT (0x3.ffffffffffffffe8p-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffecp-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffe8p-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffecp-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x3.fffffffffffffffcp-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5p+0", LIT (0x5p+0), { LIT (0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.5821dp-4", LIT (0x6.5821dp-4), { LIT (0x6.080bf03812d804fp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f8p-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804fp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.fff31d5f129deedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deeep-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deeep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.a18e8p-4", LIT (0x7.a18e8p-4), { LIT (0x7.19c5470dc5d6c09p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c09p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c09p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c098p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.b9985p-4", LIT (0x7.b9985p-4), { LIT (0x7.2d06324738d23d48p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d5p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d48p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xf.fffe4193a878ed6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.4024a11b6610672p-4", LIT (0x8.4024a11b6610672p-4), { LIT (0x7.96e91a6be7d9af68p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af68p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af68p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.4024a11b6610673p-4", LIT (0x8.4024a11b6610673p-4), { LIT (0x7.96e91a6be7d9af7p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af78p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af7p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.4024a11b66108p-4", LIT (0x8.4024a11b66108p-4), { LIT (0x7.96e91a6be7d9c2a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2bp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.4024a11b661p-4", LIT (0x8.4024a11b661p-4), { LIT (0x7.96e91a6be7d95f78p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f8p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f78p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.4024ap-4", LIT (0x8.4024ap-4), { LIT (0x7.96e9199045abc438p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc438p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc438p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.4024bp-4", LIT (0x8.4024bp-4), { LIT (0x7.96e925f6aa4fa0fp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0fp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0fp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.7c9e5p-4", LIT (0x8.7c9e5p-4), { LIT (0x7.c57313d93519a7e8p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7fp-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7e8p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.c259ep-4", LIT (0x8.c259ep-4), { LIT (0x7.fa4a1eea64fa2838p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa2838p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa2838p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa284p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc349p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-28", LIT (0x8p-28), { LIT (0x7.ffffffffffff555p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff5558p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff555p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff5558p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-48", LIT (0x8p-48), { LIT (0x7.fffffffffffffff8p-48), ERRNO_UNCHANGED }, { LIT (0x8p-48), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-48), ERRNO_UNCHANGED }, { LIT (0x8p-48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-60", LIT (0x8p-60), { LIT (0x7.fffffffffffffff8p-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-8", LIT (0x8p-8), { LIT (0x7.ff556664ac778a08p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a1p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a08p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x9p+0", LIT (0x9p+0), { LIT (0xf.fffff7d2cebbe2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe21p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe21p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xap+0", LIT (0xap+0), { LIT (0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaaap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.2991f2a97914139p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a9791413ap-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914139p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a9791413ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.05031p-16", LIT (0xe.05031p-16), { LIT (0xe.05030c697d9e582p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e583p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e582p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e583p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.6c659p-4", LIT (0xe.6c659p-4), { LIT (0xb.78df781e11d83e1p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e2p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e1p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xfp+0", LIT (0xfp+0), { LIT (0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.4p+4", LIT (-0x1.4p+4), { LIT (-0xf.fffffffffffff64p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffff63p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.6p+4", LIT (-0x1.6p+4), { LIT (-0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.9p+4", LIT (-0x1.9p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.ep+4", LIT (-0x1.ep+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (-0xc.2f7d5a8a79ca2adp-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (-0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.3p+4", LIT (-0x2.3p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.6082fp-4", LIT (-0x2.6082fp-4), { LIT (-0x2.5c12e9588a795db8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db8p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db4p-4), ERRNO_UNCHANGED }, { LIT (-0x2.5c12e9588a795db4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.8p+4", LIT (-0x2.8p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2.dp+4", LIT (-0x2.dp+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (-0xf.6ca82f0de1e9e9ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e9ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99p-4), ERRNO_UNCHANGED }, { LIT (-0xf.6ca82f0de1e9e99p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.2f59p-4", LIT (-0x3.2f59p-4), { LIT (-0x3.24bf114777f8fafcp-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf8p-4), ERRNO_UNCHANGED }, { LIT (-0x3.24bf114777f8faf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.2p+4", LIT (-0x3.2p+4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.b60d7cp-4", LIT (-0x3.b60d7cp-4), { LIT (-0x3.a55fc883707aca24p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca2p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca2p-4), ERRNO_UNCHANGED }, { LIT (-0x3.a55fc883707aca2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.c0d8b4p-4", LIT (-0x3.c0d8b4p-4), { LIT (-0x3.af99f04902f54a6p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a6p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5cp-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f04902f54a5cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.c0d8b54c5a488p-4", LIT (-0x3.c0d8b54c5a488p-4), { LIT (-0x3.af99f183b9d71e98p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e98p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e94p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f183b9d71e94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.c0d8b8p-4", LIT (-0x3.c0d8b8p-4), { LIT (-0x3.af99f412aab73f5cp-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f58p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f58p-4), ERRNO_UNCHANGED }, { LIT (-0x3.af99f412aab73f58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (-0xf.ebbe888d057ff11p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (-0xf.fd40b84505a10b5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x4p-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x4p-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x4p-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (-0x4p-16384), ERRNO_UNCHANGED }, { LIT (-0x4p-16384), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-16384), ERRNO_UNCHANGED }, { LIT (-0x3.fffffffffffffffcp-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16448", LIT (-0x4p-16448), { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (-0xf.ffa0cb346f889a9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (-0xf.fff31d5f129deeep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deeep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fff31d5f129deedp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (-0xf.fffe4193a878ed7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffe4193a878ed6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (-0xf.ffffc39548fc349p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (-0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (-0xf.fffff7d2cebbe21p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe21p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff7d2cebbe2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xap+0", LIT (-0xap+0), { LIT (-0xf.fffffee4b79aaaap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xcp-4", LIT (-0xcp-4), { LIT (-0xa.2991f2a9791413ap-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a9791413ap-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139p-4), ERRNO_UNCHANGED }, { LIT (-0xa.2991f2a97914139p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xe.9e035p+0", LIT (-0xe.9e035p+0), { LIT (-0xf.fffffffff8ebcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffff8ebbffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xfp+0", LIT (-0xfp+0), { LIT (-0xf.fffffffffcb523fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.4p+4", LIT (0x1.4p+4), { LIT (0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff63p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffff64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.6p+4", LIT (0x1.6p+4), { LIT (0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffdp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.9p+4", LIT (0x1.9p+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.ep+4", LIT (0x1.ep+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2acp-4), ERRNO_UNCHANGED }, { LIT (0xc.2f7d5a8a79ca2adp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffp-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-104), ERRNO_UNCHANGED }, { LIT (0x1p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffp-10004), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-10004), ERRNO_UNCHANGED }, { LIT (0x1p-10000), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffffffffaaaaaap-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaabp-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaaap-24), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffaaaaabp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffffffffffffp-44), ERRNO_UNCHANGED }, { LIT (0x1p-40), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-44), ERRNO_UNCHANGED }, { LIT (0x1p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffffp-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-64), ERRNO_UNCHANGED }, { LIT (0x1p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffp-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-604), ERRNO_UNCHANGED }, { LIT (0x1p-600), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.00f984p-4", LIT (0x2.00f984p-4), { LIT (0x1.fe4f391dbd3ecd7p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd72p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd7p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f391dbd3ecd72p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.00f9857616524p-4", LIT (0x2.00f9857616524p-4), { LIT (0x1.fe4f3a8e0515344ep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515345p-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515344ep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3a8e0515345p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.00f988p-4", LIT (0x2.00f988p-4), { LIT (0x1.fe4f3d0dd83fadaep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadbp-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadaep-4), ERRNO_UNCHANGED }, { LIT (0x1.fe4f3d0dd83fadbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.3p+4", LIT (0x2.3p+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.8p+4", LIT (0x2.8p+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.dp+4", LIT (0x2.dp+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.e6f54cp-4", LIT (0x2.e6f54cp-4), { LIT (0x2.deea7ea48e5ed334p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed334p-4), ERRNO_UNCHANGED }, { LIT (0x2.deea7ea48e5ed338p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xf.6ca82f0de1e9e99p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e9ap-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e99p-4), ERRNO_UNCHANGED }, { LIT (0xf.6ca82f0de1e9e9ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16", LIT (0x2p-16), { LIT (0x1.fffffffd55555558p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555ap-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd55555558p-16), ERRNO_UNCHANGED }, { LIT (0x1.fffffffd5555555ap-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-36", LIT (0x2p-36), { LIT (0x1.fffffffffffffffep-36), ERRNO_UNCHANGED }, { LIT (0x2p-36), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-36), ERRNO_UNCHANGED }, { LIT (0x2p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-56", LIT (0x2p-56), { LIT (0x1.fffffffffffffffep-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-56), ERRNO_UNCHANGED }, { LIT (0x2p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.2p+4", LIT (0x3.2p+4), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.397f2cp-4", LIT (0x3.397f2cp-4), { LIT (0x3.2e7fba1674b721dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721dp-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fba1674b721d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.397f2f50241d031p-4", LIT (0x3.397f2f50241d031p-4), { LIT (0x3.2e7fbd450f41bf74p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf78p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf74p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bf78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.397f2f50241d2p-4", LIT (0x3.397f2f50241d2p-4), { LIT (0x3.2e7fbd450f41db4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db44p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db4p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41db44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.397f2f50241dp-4", LIT (0x3.397f2f50241dp-4), { LIT (0x3.2e7fbd450f41bc84p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc84p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc84p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbd450f41bc88p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.397f3p-4", LIT (0x3.397f3p-4), { LIT (0x3.2e7fbdedf6f4e464p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e468p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e464p-4), ERRNO_UNCHANGED }, { LIT (0x3.2e7fbdedf6f4e468p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.b99798p-4", LIT (0x3.b99798p-4), { LIT (0x3.a8baac02f578491cp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578492p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578491cp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baac02f578492p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.b9979a543d0fap-4", LIT (0x3.b9979a543d0fap-4), { LIT (0x3.a8baae38037e12a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12acp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e12acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.b9979a543d0fbfa8p-4", LIT (0x3.b9979a543d0fbfa8p-4), { LIT (0x3.a8baae38037e30a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30acp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.b9979a543d0fcp-4", LIT (0x3.b9979a543d0fcp-4), { LIT (0x3.a8baae38037e30fcp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e31p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e30fcp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baae38037e31p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.b9979cp-4", LIT (0x3.b9979cp-4), { LIT (0x3.a8baafcd6721c9dp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d4p-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9dp-4), ERRNO_UNCHANGED }, { LIT (0x3.a8baafcd6721c9d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.c80ea8p-4", LIT (0x3.c80ea8p-4), { LIT (0x3.b66d36fa7234778cp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234779p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234778cp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d36fa7234779p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.c80eaa7adaa3p-4", LIT (0x3.c80eaa7adaa3p-4), { LIT (0x3.b66d39531e6043a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d39531e6043acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.c80eacp-4", LIT (0x3.c80eacp-4), { LIT (0x3.b66d3ac34ff934ccp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934dp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934ccp-4), ERRNO_UNCHANGED }, { LIT (0x3.b66d3ac34ff934dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3p+0", LIT (0x3p+0), { LIT (0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff1p-4), ERRNO_UNCHANGED }, { LIT (0xf.ebbe888d057ff11p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p+0", LIT (0x4p+0), { LIT (0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fd40b84505a10b5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-12", LIT (0x4p-12), { LIT (0x3.ffffeaaaab33332cp-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33333p-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33332cp-12), ERRNO_UNCHANGED }, { LIT (0x3.ffffeaaaab33333p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0x3.fffffffffffffffcp-16384), ERRNO_UNCHANGED }, { LIT (0x4p-16384), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-16384), ERRNO_UNCHANGED }, { LIT (0x4p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-32", LIT (0x4p-32), { LIT (0x3.ffffffffffffffe8p-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffecp-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffe8p-32), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffecp-32), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-52", LIT (0x4p-52), { LIT (0x3.fffffffffffffffcp-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-52), ERRNO_UNCHANGED }, { LIT (0x4p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5p+0", LIT (0x5p+0), { LIT (0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffa0cb346f889a9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.5821dp-4", LIT (0x6.5821dp-4), { LIT (0x6.080bf03812d804fp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f8p-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804fp-4), ERRNO_UNCHANGED }, { LIT (0x6.080bf03812d804f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6p+0", LIT (0x6p+0), { LIT (0xf.fff31d5f129deedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deeep-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fff31d5f129deeep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.a18e8p-4", LIT (0x7.a18e8p-4), { LIT (0x7.19c5470dc5d6c09p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c09p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c09p-4), ERRNO_UNCHANGED }, { LIT (0x7.19c5470dc5d6c098p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.b9985p-4", LIT (0x7.b9985p-4), { LIT (0x7.2d06324738d23d48p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d5p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d48p-4), ERRNO_UNCHANGED }, { LIT (0x7.2d06324738d23d5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xf.fffe4193a878ed6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffe4193a878ed7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.4024a11b6610672p-4", LIT (0x8.4024a11b6610672p-4), { LIT (0x7.96e91a6be7d9af68p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af68p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af68p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.4024a11b6610673p-4", LIT (0x8.4024a11b6610673p-4), { LIT (0x7.96e91a6be7d9af7p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af78p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af7p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9af78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.4024a11b66108p-4", LIT (0x8.4024a11b66108p-4), { LIT (0x7.96e91a6be7d9c2a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2bp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d9c2bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.4024a11b661p-4", LIT (0x8.4024a11b661p-4), { LIT (0x7.96e91a6be7d95f78p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f8p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f78p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e91a6be7d95f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.4024ap-4", LIT (0x8.4024ap-4), { LIT (0x7.96e9199045abc438p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc438p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc438p-4), ERRNO_UNCHANGED }, { LIT (0x7.96e9199045abc44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.4024bp-4", LIT (0x8.4024bp-4), { LIT (0x7.96e925f6aa4fa0fp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0fp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0fp-4), ERRNO_UNCHANGED }, { LIT (0x7.96e925f6aa4fa0f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.7c9e5p-4", LIT (0x8.7c9e5p-4), { LIT (0x7.c57313d93519a7e8p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7fp-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7e8p-4), ERRNO_UNCHANGED }, { LIT (0x7.c57313d93519a7fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.c259ep-4", LIT (0x8.c259ep-4), { LIT (0x7.fa4a1eea64fa2838p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa2838p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa2838p-4), ERRNO_UNCHANGED }, { LIT (0x7.fa4a1eea64fa284p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc348p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffc39548fc349p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-28", LIT (0x8p-28), { LIT (0x7.ffffffffffff555p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff5558p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff555p-28), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffff5558p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-48", LIT (0x8p-48), { LIT (0x7.fffffffffffffff8p-48), ERRNO_UNCHANGED }, { LIT (0x8p-48), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-48), ERRNO_UNCHANGED }, { LIT (0x8p-48), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-60", LIT (0x8p-60), { LIT (0x7.fffffffffffffff8p-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-60), ERRNO_UNCHANGED }, { LIT (0x8p-60), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-8", LIT (0x8p-8), { LIT (0x7.ff556664ac778a08p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a1p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a08p-8), ERRNO_UNCHANGED }, { LIT (0x7.ff556664ac778a1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x9p+0", LIT (0x9p+0), { LIT (0xf.fffff7d2cebbe2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe21p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d2cebbe21p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xap+0", LIT (0xap+0), { LIT (0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaa9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffee4b79aaaap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.2991f2a97914139p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a9791413ap-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a97914139p-4), ERRNO_UNCHANGED }, { LIT (0xa.2991f2a9791413ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.05031p-16", LIT (0xe.05031p-16), { LIT (0xe.05030c697d9e582p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e583p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e582p-16), ERRNO_UNCHANGED }, { LIT (0xe.05030c697d9e583p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.6c659p-4", LIT (0xe.6c659p-4), { LIT (0xb.78df781e11d83e1p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e2p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e1p-4), ERRNO_UNCHANGED }, { LIT (0xb.78df781e11d83e2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xfp+0", LIT (0xfp+0), { LIT (0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523ep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffcb523fp-4), ERRNO_UNCHANGED } },
#endif
  };

static void
tanh_test (void)
{
  ALL_RM_TEST (tanh, 0, tanh_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  tanh_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

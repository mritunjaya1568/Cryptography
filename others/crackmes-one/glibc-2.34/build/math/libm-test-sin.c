/* Test sin.
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

static const struct test_f_f_data sin_test_data[] =
  {
    { "inf", plus_infty, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM } },
    { "-inf", minus_infty, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM } },
    { "qNaN", qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "-sNaN", -snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },

#if (TEST_COND_binary128)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (-0xd.8f691a7a95425ffcb89dc2b97cep-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffcb89dc2b97cep-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffcb89dc2b97cd8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffcb89dc2b97cd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb4p+0", LIT (-0x1.921fb4p+0), { LIT (-0xf.fffffffffff32a3661c108e136d8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3661c108e136d8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3661c108e136dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3661c108e136dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb54442d18468p+0", LIT (-0x1.921fb54442d18468p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb54442d18469898cc517018p+0", LIT (-0x1.921fb54442d18469898cc517018p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb54442d18469898cc51701b8p+0", LIT (-0x1.921fb54442d18469898cc51701b8p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb54442d18469898cc51701b9p+0", LIT (-0x1.921fb54442d18469898cc51701b9p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb54442d18469898cc51702p+0", LIT (-0x1.921fb54442d18469898cc51702p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb54442d1846ap+0", LIT (-0x1.921fb54442d1846ap+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb54442d18p+0", LIT (-0x1.921fb54442d18p+0), { LIT (-0xf.ffffffffffffffffffffffffff68p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffffff68p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffffff6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffffffffffffffff6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb54442d19p+0", LIT (-0x1.921fb54442d19p+0), { LIT (-0xf.fffffffffffffffffffffffffbdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffbdp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffbc8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffbc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.921fb6p+0", LIT (-0x1.921fb6p+0), { LIT (-0xf.fffffffffffbb290924e3a114988p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb290924e3a114988p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb290924e3a11498p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb290924e3a11498p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xc.143e153b0701e800f9b8a47b75bp-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e800f9b8a47b75b8p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e800f9b8a47b75bp-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e800f9b8a47b75b8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { LIT (-0x2.8885a308d31063e2b6c62b7f4d6cp-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063e2b6c62b7f4d6cp-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063e2b6c62b7f4d6ap-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063e2b6c62b7f4d6ap-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d313198a2e0372p+0", LIT (-0x3.243f6a8885a308d313198a2e0372p+0), { LIT (0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), ERRNO_UNCHANGED }, { LIT (0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), ERRNO_UNCHANGED }, { LIT (0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), ERRNO_UNCHANGED }, { LIT (0x1.8cbb5bf6c7ddd660ce2ff7d10568p-112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d313198a2e037p+0", LIT (-0x3.243f6a8885a308d313198a2e037p+0), { LIT (-0x7.344a4093822299f31d0082efa99p-116), ERRNO_UNCHANGED }, { LIT (-0x7.344a4093822299f31d0082efa99p-116), ERRNO_UNCHANGED }, { LIT (-0x7.344a4093822299f31d0082efa98cp-116), ERRNO_UNCHANGED }, { LIT (-0x7.344a4093822299f31d0082efa98cp-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d313198a2e03p+0", LIT (-0x3.243f6a8885a308d313198a2e03p+0), { LIT (-0x7.07344a4093822299f31d0082efacp-108), ERRNO_UNCHANGED }, { LIT (-0x7.07344a4093822299f31d0082efa8p-108), ERRNO_UNCHANGED }, { LIT (-0x7.07344a4093822299f31d0082efa8p-108), ERRNO_UNCHANGED }, { LIT (-0x7.07344a4093822299f31d0082efa8p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d313198a2e04p+0", LIT (-0x3.243f6a8885a308d313198a2e04p+0), { LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d105p-108), ERRNO_UNCHANGED }, { LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1058p-108), ERRNO_UNCHANGED }, { LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d105p-108), ERRNO_UNCHANGED }, { LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1058p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d4p+0", LIT (-0x3.243f6a8885a308d4p+0), { LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd6608p-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd661p-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd6608p-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd661p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308dp+0", LIT (-0x3.243f6a8885a308dp+0), { LIT (-0x3.13198a2e03707344a409382229ap-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344a409382229ap-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344a4093822299ep-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344a4093822299ep-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { LIT (0x1.72cece675d1fc8f8cbb5bf6c7d5bp-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8cbb5bf6c7d5cp-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8cbb5bf6c7d5bp-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8cbb5bf6c7d5cp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { LIT (-0x8.d313198a2e03707344a4093821b8p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707344a4093821b8p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707344a4093821bp-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707344a4093821bp-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { LIT (0x1.777a5cf72cec5fd61896cb4f40d1p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd61896cb4f40d2p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd61896cb4f40d1p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd61896cb4f40d2p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0xf.e00885042dd770c93962abdb61f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770c93962abdb61f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770c93962abdb61fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770c93962abdb61fp-4), ERRNO_UNCHANGED } },
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
    { "-0x6.e23688p+16", LIT (-0x6.e23688p+16), { LIT (-0x1.bf207c900d877cb73f555829e3f1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb73f555829e3f1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb73f555829e3fp-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb73f555829e3fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x6.e2368c006c018228p+16", LIT (-0x6.e2368c006c018228p+16), { LIT (-0x1.feb6a361c0bb501b009ef2c1f11ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501b009ef2c1f11ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501b009ef2c1f119p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501b009ef2c1f119p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x6.e2368c006c018p+16", LIT (-0x6.e2368c006c018p+16), { LIT (-0x1.feb6a3619e803c49fb3b778718d2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c49fb3b778718d1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c49fb3b778718d1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c49fb3b778718d1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x6.e2368c006c01cp+16", LIT (-0x6.e2368c006c01cp+16), { LIT (-0x1.feb6a365968288771150b6f6c52p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a365968288771150b6f6c51fp-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a365968288771150b6f6c51fp-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a365968288771150b6f6c51fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x6.e2369p+16", LIT (-0x6.e2369p+16), { LIT (-0x2.3e1f7a26f594336f9e583b26bbbep-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336f9e583b26bbbep-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336f9e583b26bbbcp-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336f9e583b26bbbcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91c16b9b28p-4", LIT (-0x8.60a91c16b9b28p-4), { LIT (-0x7.ffffffffffffc6ab95779c1eae0cp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6ab95779c1eae0cp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6ab95779c1eae08p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6ab95779c1eae08p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91c16b9b2c232dd99707ab3d8p-4", LIT (-0x8.60a91c16b9b2c232dd99707ab3d8p-4), { LIT (-0x8.0000000000000000000000000008p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91c16b9b2c232dd99707ab3dp-4", LIT (-0x8.60a91c16b9b2c232dd99707ab3dp-4), { LIT (-0x7.fffffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91c16b9b2c232dd99707ab4p-4", LIT (-0x8.60a91c16b9b2c232dd99707ab4p-4), { LIT (-0x8.0000000000000000000000000028p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000000000000002p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000000000000002p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000000000000002p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91c16b9b2c232dd99707abp-4", LIT (-0x8.60a91c16b9b2c232dd99707abp-4), { LIT (-0x7.fffffffffffffffffffffffffcbp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffcacp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffcacp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffcacp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91c16b9b2c23p-4", LIT (-0x8.60a91c16b9b2c23p-4), { LIT (-0x7.fffffffffffffffd84af2ec140ep-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffd84af2ec140dcp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffd84af2ec140dcp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffd84af2ec140dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91c16b9b2c24p-4", LIT (-0x8.60a91c16b9b2c24p-4), { LIT (-0x8.000000000000000b5feca2ed6738p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000b5feca2ed673p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000b5feca2ed673p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000b5feca2ed673p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91c16b9b3p-4", LIT (-0x8.60a91c16b9b3p-4), { LIT (-0x8.00000000000035858118fd5157e8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000035858118fd5157ep-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000035858118fd5157ep-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000035858118fd5157ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a91p-4", LIT (-0x8.60a91p-4), { LIT (-0x7.fffff587e3a050cf967fba7bc72cp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050cf967fba7bc728p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050cf967fba7bc728p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050cf967fba7bc728p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8.60a92p-4", LIT (-0x8.60a92p-4), { LIT (-0x8.0000036321168852c4130c64b4cp-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168852c4130c64b4cp-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168852c4130c64b4b8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168852c4130c64b4b8p-4), ERRNO_UNCHANGED } },
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
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1.452fc98b34e96b61139b09a7c84bp-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b61139b09a7c84ap-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b61139b09a7c84ap-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b61139b09a7c84ap-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xe.f1a3e1dc468a921dddb4e37fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xe.f1a3e1dc468a921dddb4e37fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xe.f1a3e1dc468a921dddb4e37fbe6p-4), ERRNO_UNCHANGED }, { LIT (0xe.f1a3e1dc468a921dddb4e37fbe68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffffffffffffff8p+16380", LIT (-0xf.fffffffffffffffffffffffffff8p+16380), { LIT (-0xf.3b0b11ed85b7fe43d110251580b8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.3b0b11ed85b7fe43d110251580b8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.3b0b11ed85b7fe43d110251580bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.3b0b11ed85b7fe43d110251580bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0xf.dfd9d4b6d0e5f7b9650cab0f544p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x8.599b32844aba906cee446be04998p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba906cee446be04998p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba906cee446be04998p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba906cee446be049ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.2001469775ce6p+32", LIT (0x1.2001469775ce6p+32), { LIT (-0x6.444fda50019f9f5ba3779ca70604p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f5ba3779ca706p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f5ba3779ca706p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f5ba3779ca706p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (0x4.220ff25f5cf02a464dbb3a679ccp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a464dbb3a679ccp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a464dbb3a679ccp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a464dbb3a679cc4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.200148p+32", LIT (0x1.200148p+32), { LIT (-0x5.595d7e536fe35edbe2ad0df9d944p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35edbe2ad0df9d94p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35edbe2ad0df9d94p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35edbe2ad0df9d94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xf.fa2adb8953ae26229c919ec8f6b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae26229c919ec8f6cp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae26229c919ec8f6b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae26229c919ec8f6cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xf.fa2adcf9ea83dbdd053ee455ea68p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbdd053ee455ea7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbdd053ee455ea68p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbdd053ee455ea7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xf.fa2add3e58948d10238cc27b5618p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d10238cc27b562p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d10238cc27b5618p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d10238cc27b562p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0xf.fffffffffff32a3661c108e136dp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3661c108e136d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3661c108e136dp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3661c108e136d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc517018p+0", LIT (0x1.921fb54442d18469898cc517018p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51701b8p+0", LIT (0x1.921fb54442d18469898cc51701b8p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51701b9p+0", LIT (0x1.921fb54442d18469898cc51701b9p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51702p+0", LIT (0x1.921fb54442d18469898cc51702p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0xf.ffffffffffffffffffffffffff6p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffff68p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffff6p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffff68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (0xf.fffffffffffffffffffffffffbc8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffbdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffbc8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffbdp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (0xf.fffffffffffbb290924e3a11498p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb290924e3a114988p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb290924e3a11498p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb290924e3a114988p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.d12ed2p-12", LIT (0x1.d12ed2p-12), { LIT (0x1.d12ed0fffffdfe0f0008c8b28232p-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe0f0008c8b28233p-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe0f0008c8b28232p-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe0f0008c8b28233p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xd.76aa47848677020c6e9e909c50fp-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677020c6e9e909c50fp-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677020c6e9e909c50fp-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677020c6e9e909c50f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+120", LIT (0x1p+120), { LIT (0x6.0b8d19579bf2db5e5f1aa933f37cp-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db5e5f1aa933f37cp-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db5e5f1aa933f37cp-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db5e5f1aa933f38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0xf.c777c6b36a750a5fdeb8807a1568p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5fdeb8807a156p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5fdeb8807a156p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5fdeb8807a156p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (-0xd.a29d5bb5f9cb87d14de41dc991fp-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87d14de41dc991fp-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87d14de41dc991e8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87d14de41dc991e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (-0x4.cd7e86c4077bf0debc87d70d196p-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0debc87d70d196p-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0debc87d70d195cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0debc87d70d195cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (-0xb.becc47ab1b8c70793712c4ff2bc8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c70793712c4ff2bcp-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c70793712c4ff2bcp-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c70793712c4ff2bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.553534p+0", LIT (0x2.553534p+0), { LIT (0xb.932584840806c6090aefd5f25048p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c6090aefd5f2505p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c6090aefd5f25048p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c6090aefd5f2505p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.5535376715b9ep+0", LIT (0x2.5535376715b9ep+0), { LIT (0xb.93255eeda103a17c97f0fb512518p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a17c97f0fb51252p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a17c97f0fb512518p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a17c97f0fb51252p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.5535376715b9fffcp+0", LIT (0x2.5535376715b9fffcp+0), { LIT (0xb.93255eeda102402c2f97f47dcf78p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102402c2f97f47dcf78p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102402c2f97f47dcf78p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102402c2f97f47dcf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.5535376715b9ffffffffffffff78p+0", LIT (0x2.5535376715b9ffffffffffffff78p+0), { LIT (0xb.93255eeda10240000004f6fd4ad8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd4ad8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd4ad8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd4aep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.5535376715b9ffffffffffffff7ap+0", LIT (0x2.5535376715b9ffffffffffffff7ap+0), { LIT (0xb.93255eeda10240000004f6fd4acp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd4acp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd4acp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd4ac8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.5535376715b9ffffffffffffffp+0", LIT (0x2.5535376715b9ffffffffffffffp+0), { LIT (0xb.93255eeda10240000004f6fd5p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd5008p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd5p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd5008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.5535376715bap+0", LIT (0x2.5535376715bap+0), { LIT (0xb.93255eeda10240000004f6fd44f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd44f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd44f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd45p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.553538p+0", LIT (0x2.553538p+0), { LIT (0xb.93255854754a36d261581d7c0da8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36d261581d7c0da8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36d261581d7c0da8p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36d261581d7c0dbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xe.8c7b7568da22efd5c240c4004e48p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efd5c240c4004e5p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efd5c240c4004e48p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efd5c240c4004e5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+64", LIT (0x2p+64), { LIT (-0xc.143e153b0701e800f9b8a47b75b8p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e800f9b8a47b75b8p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e800f9b8a47b75bp-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e800f9b8a47b75bp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffffffffffffffffcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (0x1.ffc6da9f1ffed895f9fa424ba91p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed895f9fa424ba91p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed895f9fa424ba91p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed895f9fa424ba911p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { LIT (0x2.8885a308d31063e2b6c62b7f4d6ap-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e2b6c62b7f4d6cp-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e2b6c62b7f4d6ap-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e2b6c62b7f4d6cp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d313198a2e0372p+0", LIT (0x3.243f6a8885a308d313198a2e0372p+0), { LIT (-0x1.8cbb5bf6c7ddd660ce2ff7d10568p-112), ERRNO_UNCHANGED }, { LIT (-0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), ERRNO_UNCHANGED }, { LIT (-0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), ERRNO_UNCHANGED }, { LIT (-0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d313198a2e037p+0", LIT (0x3.243f6a8885a308d313198a2e037p+0), { LIT (0x7.344a4093822299f31d0082efa98cp-116), ERRNO_UNCHANGED }, { LIT (0x7.344a4093822299f31d0082efa99p-116), ERRNO_UNCHANGED }, { LIT (0x7.344a4093822299f31d0082efa98cp-116), ERRNO_UNCHANGED }, { LIT (0x7.344a4093822299f31d0082efa99p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d313198a2e03p+0", LIT (0x3.243f6a8885a308d313198a2e03p+0), { LIT (0x7.07344a4093822299f31d0082efa8p-108), ERRNO_UNCHANGED }, { LIT (0x7.07344a4093822299f31d0082efa8p-108), ERRNO_UNCHANGED }, { LIT (0x7.07344a4093822299f31d0082efa8p-108), ERRNO_UNCHANGED }, { LIT (0x7.07344a4093822299f31d0082efacp-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d313198a2e04p+0", LIT (0x3.243f6a8885a308d313198a2e04p+0), { LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1058p-108), ERRNO_UNCHANGED }, { LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1058p-108), ERRNO_UNCHANGED }, { LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d105p-108), ERRNO_UNCHANGED }, { LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d105p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d4p+0", LIT (0x3.243f6a8885a308d4p+0), { LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd661p-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd661p-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd6608p-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd6608p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308dp+0", LIT (0x3.243f6a8885a308dp+0), { LIT (0x3.13198a2e03707344a4093822299ep-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344a409382229ap-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344a4093822299ep-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344a409382229ap-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d5cp-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d5cp-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d5bp-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d5bp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { LIT (0x8.d313198a2e03707344a4093821bp-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707344a4093821b8p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707344a4093821bp-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707344a4093821b8p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { LIT (-0x1.777a5cf72cec5fd61896cb4f40d2p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd61896cb4f40d2p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd61896cb4f40d1p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd61896cb4f40d1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.be735c19be9fep+0", LIT (0x3.be735c19be9fep+0), { LIT (-0x9.10bb11242ec81a1c3545a17906p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1c3545a17905f8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1c3545a17905f8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1c3545a17905f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.be735c19be9ffffcp+0", LIT (0x3.be735c19be9ffffcp+0), { LIT (-0x9.10bb11242ec9bfcb43893004c398p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcb43893004c39p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcb43893004c39p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcb43893004c39p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.be735c19be9fffffffffffffffe8p+0", LIT (0x3.be735c19be9fffffffffffffffe8p+0), { LIT (-0x9.10bb11242ec9c000000287a18768p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a18768p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a1876p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a1876p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.be735c19be9fffffffffffffffeap+0", LIT (0x3.be735c19be9fffffffffffffffeap+0), { LIT (-0x9.10bb11242ec9c000000287a1878p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a1878p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a18778p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a18778p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.be735c19be9fffffffffffffffp+0", LIT (0x3.be735c19be9fffffffffffffffp+0), { LIT (-0x9.10bb11242ec9c000000287a17b78p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a17b7p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a17b7p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a17b7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.be735c19beap+0", LIT (0x3.be735c19beap+0), { LIT (-0x9.10bb11242ec9c000000287a188a8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a188ap-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a188ap-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a188ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.be735cp+0", LIT (0x3.be735cp+0), { LIT (-0x9.10bb0fd0c39d59f8b7898e86413p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59f8b7898e86413p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59f8b7898e864128p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59f8b7898e864128p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.be736p+0", LIT (0x3.be736p+0), { LIT (-0x9.10bb448d3cb0166e220f3af793c8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166e220f3af793c8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166e220f3af793cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166e220f3af793cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ec2a0250032a0000000000000072p+0", LIT (0x3.ec2a0250032a0000000000000072p+0), { LIT (-0xb.4351eaad09833fffffff47a712e8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a712e8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a712ep-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a712ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ec2a0250032a000000000000007p+0", LIT (0x3.ec2a0250032a000000000000007p+0), { LIT (-0xb.4351eaad09833fffffff47a712d8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a712dp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a712dp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a712dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ec2a0250032a00000000000001p+0", LIT (0x3.ec2a0250032a00000000000001p+0), { LIT (-0xb.4351eaad09833fffffff47a71938p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a71938p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a7193p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a7193p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ec2a0250032a0004p+0", LIT (0x3.ec2a0250032a0004p+0), { LIT (-0xb.4351eaad0983402d74f5d3cb83fp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402d74f5d3cb83fp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402d74f5d3cb83e8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402d74f5d3cb83e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ec2a0250032a2p+0", LIT (0x3.ec2a0250032a2p+0), { LIT (-0xb.4351eaad0984aba7b4606b57ad68p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984aba7b4606b57ad68p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984aba7b4606b57ad6p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984aba7b4606b57ad6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ec2a0250032ap+0", LIT (0x3.ec2a0250032ap+0), { LIT (-0xb.4351eaad09833fffffff47a70dd8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a70dd8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a70ddp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a70ddp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ec2a04p+0", LIT (0x3.ec2a04p+0), { LIT (-0xb.4351fdda3d81513dedde4fd2cd28p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513dedde4fd2cd28p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513dedde4fd2cd2p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513dedde4fd2cd2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ec2ap+0", LIT (0x3.ec2ap+0), { LIT (-0xb.4351d06546e7181306453a5b2ec8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181306453a5b2ec8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181306453a5b2ecp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181306453a5b2ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x2.42070db6daab69e3902e8468315p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e3902e8468315p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e3902e8468315p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e3902e84683152p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093385688a2d1508p-4", LIT (0x4.093385688a2d1508p-4), { LIT (0x3.fe477dbdc795642fffb6d11d9862p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795642fffb6d11d9862p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795642fffb6d11d9862p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795642fffb6d11d9864p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093385688a2d150c00bf42a08e84p-4", LIT (0x4.093385688a2d150c00bf42a08e84p-4), { LIT (0x3.fe477dbdc7956433e0084536147ep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e0084536148p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e0084536147ep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e0084536148p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093385688a2d150c00bf42a08e8p-4", LIT (0x4.093385688a2d150c00bf42a08e8p-4), { LIT (0x3.fe477dbdc7956433e0084536147cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e0084536147cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e0084536147cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e0084536147ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093385688a2d150c00bf42a08ep-4", LIT (0x4.093385688a2d150c00bf42a08ep-4), { LIT (0x3.fe477dbdc7956433e008453614p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453614p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453614p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e00845361402p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093385688a2d150c00bf42a09p-4", LIT (0x4.093385688a2d150c00bf42a09p-4), { LIT (0x3.fe477dbdc7956433e008453615eep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453615fp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453615eep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453615fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093385688a2d151p-4", LIT (0x4.093385688a2d151p-4), { LIT (0x3.fe477dbdc7956437bee74ef98324p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956437bee74ef98326p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956437bee74ef98324p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956437bee74ef98326p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093385688a2d4p-4", LIT (0x4.093385688a2d4p-4), { LIT (0x3.fe477dbdc7958dcbe52ad14f88f2p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dcbe52ad14f88f2p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dcbe52ad14f88f2p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dcbe52ad14f88f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093385688a2dp-4", LIT (0x4.093385688a2dp-4), { LIT (0x3.fe477dbdc7954fd2613bf1f96c22p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd2613bf1f96c24p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd2613bf1f96c22p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd2613bf1f96c24p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.093388p-4", LIT (0x4.093388p-4), { LIT (0x3.fe4780403e8078ca89790118cb8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ca89790118cb8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ca89790118cb8cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ca89790118cb8ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.09338p-4", LIT (0x4.09338p-4), { LIT (0x3.fe4778810e026fe1e37f141da492p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fe1e37f141da492p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fe1e37f141da492p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fe1e37f141da494p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.1237e153f7080000000000000004p+0", LIT (0x4.1237e153f7080000000000000004p+0), { LIT (-0xc.d2635f3faf56bffffffb0fcac2a8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcac2a8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcac2ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcac2ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.1237e153f70800000000000002p+0", LIT (0x4.1237e153f70800000000000002p+0), { LIT (-0xc.d2635f3faf56bffffffb0fcad5a8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcad5ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcad5ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcad5ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.1237e153f7080008p+0", LIT (0x4.1237e153f7080008p+0), { LIT (-0xc.d2635f3faf56c04c91082c534dfp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04c91082c534dfp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04c91082c534de8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04c91082c534de8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.1237e153f7084p+0", LIT (0x4.1237e153f7084p+0), { LIT (-0xc.d2635f3faf59248868df5425cdap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248868df5425cd98p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248868df5425cd98p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248868df5425cd98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.1237e153f708p+0", LIT (0x4.1237e153f708p+0), { LIT (-0xc.d2635f3faf56bffffffb0fcac28p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcac28p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcac278p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcac278p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.1237e8p+0", LIT (0x4.1237e8p+0), { LIT (-0xc.d2639f1afc7f4698649bd4cf58dp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f4698649bd4cf58c8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f4698649bd4cf58c8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f4698649bd4cf58c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.1237ep+0", LIT (0x4.1237ep+0), { LIT (-0xc.d2635289f074d2b2df33331ddd4p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2b2df33331ddd4p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2b2df33331ddd38p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2b2df33331ddd38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0x1.ffb679ba994b76173f9040637ff9p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b76173f9040637ff9p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b76173f9040637ff8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b76173f9040637ff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.c92d08p+0", LIT (0x4.c92d08p+0), { LIT (-0xf.f4f4736648dc2a042045142724ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2a042045142724ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2a04204514272498p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2a04204514272498p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.c92d0ffa4bf00000000000000088p+0", LIT (0x4.c92d0ffa4bf00000000000000088p+0), { LIT (-0xf.f4f46a082f2840000005480a496p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a496p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a4958p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a4958p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.c92d0ffa4bf0000000000000008cp+0", LIT (0x4.c92d0ffa4bf0000000000000008cp+0), { LIT (-0xf.f4f46a082f2840000005480a496p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a4958p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a4958p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a4958p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.c92d0ffa4bf000000000000002p+0", LIT (0x4.c92d0ffa4bf000000000000002p+0), { LIT (-0xf.f4f46a082f2840000005480a47a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a47ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a47ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a47ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.c92d0ffa4bf00008p+0", LIT (0x4.c92d0ffa4bf00008p+0), { LIT (-0xf.f4f46a082f283ff69b37289dc1ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ff69b37289dc1ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ff69b37289dc198p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ff69b37289dc198p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.c92d0ffa4bf04p+0", LIT (0x4.c92d0ffa4bf04p+0), { LIT (-0xf.f4f46a082f27f4d98f09e3c6cf38p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4d98f09e3c6cf38p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4d98f09e3c6cf3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4d98f09e3c6cf3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.c92d0ffa4bfp+0", LIT (0x4.c92d0ffa4bfp+0), { LIT (-0xf.f4f46a082f2840000005480a4ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a4ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a49f8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a49f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.c92d1p+0", LIT (0x4.c92d1p+0), { LIT (-0xf.f4f46a017cb883f95b64a197e97p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883f95b64a197e97p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883f95b64a197e968p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883f95b64a197e968p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xc.1bdceeee0f5738674c02ad072288p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f5738674c02ad072288p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f5738674c02ad07228p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f5738674c02ad07228p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p+48", LIT (0x4p+48), { LIT (0x7.f13d78eabb76b8a986d98d6703e4p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a986d98d6703e8p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a986d98d6703e4p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a986d98d6703e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.fffffffffffffffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x3.fffffffffffffffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffffffffffffffep-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED } },
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
    { "0x5.6a5005df4363833413fa44f74ae8p+64", LIT (0x5.6a5005df4363833413fa44f74ae8p+64), { LIT (-0xf.fdc3052396dd47c564b32734cc28p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc3052396dd47c564b32734cc2p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc3052396dd47c564b32734cc2p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc3052396dd47c564b32734cc2p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.6a5005df4363833413fa44f74ap+64", LIT (0x5.6a5005df4363833413fa44f74ap+64), { LIT (-0xf.fdc305247e694b390edb67a7fa7p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305247e694b390edb67a7fa7p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305247e694b390edb67a7fa68p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305247e694b390edb67a7fa68p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.6a5005df4363833413fa44f74cp+64", LIT (0x5.6a5005df4363833413fa44f74cp+64), { LIT (-0xf.fdc305227f69439ae6b7b4254f8p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305227f69439ae6b7b4254f78p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305227f69439ae6b7b4254f78p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305227f69439ae6b7b4254f78p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.6a5005df43638338p+64", LIT (0x5.6a5005df43638338p+64), { LIT (-0xa.8640e82e7924ec0007c751797398p-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ec0007c75179739p-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ec0007c75179739p-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ec0007c75179739p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.6a5005df4363833p+64", LIT (0x5.6a5005df4363833p+64), { LIT (0xd.7457bd2255e689f0662a7ba8548p-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689f0662a7ba85488p-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689f0662a7ba8548p-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689f0662a7ba85488p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.6a5005df43638p+64", LIT (0x5.6a5005df43638p+64), { LIT (0x2.f0e32ed649b326445c86bd0d5a5cp-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b326445c86bd0d5a5ep-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b326445c86bd0d5a5cp-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b326445c86bd0d5a5ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.6a5005df4363cp+64", LIT (0x5.6a5005df4363cp+64), { LIT (0x6.5ea3351c9d9da321a84877b1bf9cp-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da321a84877b1bf9cp-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da321a84877b1bf9cp-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da321a84877b1bfap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.6a5008p+64", LIT (0x5.6a5008p+64), { LIT (-0x1.4550689b93bbe1406aee26103891p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe1406aee26103891p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe1406aee2610389p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe1406aee2610389p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.6a5p+64", LIT (0x5.6a5p+64), { LIT (-0x1.ee01db6bc8ef288c92dcf3ee915cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288c92dcf3ee915cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288c92dcf3ee915bp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288c92dcf3ee915bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fbec7477d4a80000000000000098p+0", LIT (0x5.fbec7477d4a80000000000000098p+0), { LIT (-0x4.b6f642a935a49fffffff9a1c73e8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c73e4p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c73e4p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c73e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fbec7477d4a8000000000000009cp+0", LIT (0x5.fbec7477d4a8000000000000009cp+0), { LIT (-0x4.b6f642a935a49fffffff9a1c73a8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c73a8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c73a4p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c73a4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fbec7477d4a800000000000002p+0", LIT (0x5.fbec7477d4a800000000000002p+0), { LIT (-0x4.b6f642a935a49fffffff9a1c5e68p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c5e64p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c5e64p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c5e64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fbec7477d4a80008p+0", LIT (0x5.fbec7477d4a80008p+0), { LIT (-0x4.b6f642a935a49f85aee98a979804p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f85aee98a9798p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f85aee98a9798p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f85aee98a9798p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fbec7477d4a84p+0", LIT (0x5.fbec7477d4a84p+0), { LIT (-0x4.b6f642a935a0cd774f8372f49334p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd774f8372f49334p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd774f8372f4933p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd774f8372f4933p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fbec7477d4a8p+0", LIT (0x5.fbec7477d4a8p+0), { LIT (-0x4.b6f642a935a49fffffff9a1c7cfcp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c7cf8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c7cf8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c7cf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fbec78p+0", LIT (0x5.fbec78p+0), { LIT (-0x4.b6f60ca8d4150bc1732b1580fc8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bc1732b1580fc8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bc1732b1580fc7cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bc1732b1580fc7cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.fbec7p+0", LIT (0x5.fbec7p+0), { LIT (-0x4.b6f686f9ea12e8ec702d198cbfa8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8ec702d198cbfa8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8ec702d198cbfa4p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8ec702d198cbfa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5p+0", LIT (0x5p+0), { LIT (-0xf.57c0faf04c999135789f2ab1de3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c999135789f2ab1de3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c999135789f2ab1de28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c999135789f2ab1de28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { LIT (-0x1.fecb772e1b86f8e74fbeae63ee4dp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e74fbeae63ee4cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e74fbeae63ee4cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e74fbeae63ee4cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cc8749212e72p+0", LIT (0x6.287cc8749212e72p+0), { LIT (-0x1.fecb772e1b848bca4e961470b22p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bca4e961470b22p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bca4e961470b21fp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bca4e961470b21fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { LIT (-0x1.fecb772e1b8300e5ab16d9008ea9p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e5ab16d9008ea9p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e5ab16d9008ea8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e5ab16d9008ea8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { LIT (-0x1.fecb7e68ad6e9c3f77c1915bc919p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3f77c1915bc919p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3f77c1915bc918p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3f77c1915bc918p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { LIT (-0x1.fecaff6878a10ce5d42fde40e7p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce5d42fde40e7p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce5d42fde40e6ffp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce5d42fde40e6ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6p+0", LIT (0x6p+0), { LIT (-0x4.787c62ac28b00e989105113d2888p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e989105113d2884p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e989105113d2884p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e989105113d2884p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xa.83046136850421dd444208fd7788p-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421dd444208fd7788p-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421dd444208fd7788p-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421dd444208fd779p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { LIT (0x7.ffffffffffffc6ab95779c1eae08p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6ab95779c1eae0cp-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6ab95779c1eae08p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6ab95779c1eae0cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c232dd99707ab3d8p-4", LIT (0x8.60a91c16b9b2c232dd99707ab3d8p-4), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c232dd99707ab3dp-4", LIT (0x8.60a91c16b9b2c232dd99707ab3dp-4), { LIT (0x7.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c232dd99707ab4p-4", LIT (0x8.60a91c16b9b2c232dd99707ab4p-4), { LIT (0x8.000000000000000000000000002p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000000000000002p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000000000000002p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000000028p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c232dd99707abp-4", LIT (0x8.60a91c16b9b2c232dd99707abp-4), { LIT (0x7.fffffffffffffffffffffffffcacp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffcacp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffcacp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffcbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c23p-4", LIT (0x8.60a91c16b9b2c23p-4), { LIT (0x7.fffffffffffffffd84af2ec140dcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffd84af2ec140dcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffd84af2ec140dcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffd84af2ec140ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c24p-4", LIT (0x8.60a91c16b9b2c24p-4), { LIT (0x8.000000000000000b5feca2ed673p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000b5feca2ed673p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000b5feca2ed673p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000b5feca2ed6738p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { LIT (0x8.00000000000035858118fd5157ep-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000035858118fd5157ep-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000035858118fd5157ep-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000035858118fd5157e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { LIT (0x7.fffff587e3a050cf967fba7bc728p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050cf967fba7bc728p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050cf967fba7bc728p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050cf967fba7bc72cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { LIT (0x8.0000036321168852c4130c64b4b8p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000036321168852c4130c64b4cp-4), ERRNO_UNCHANGED }, { LIT (0x8.0000036321168852c4130c64b4b8p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000036321168852c4130c64b4cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.d469501467bd74fb158538284668p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd74fb15853828467p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd74fb158538284668p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd74fb15853828467p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (0x9.0292465edbaff2d2e64a2845e55p-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2d2e64a2845e558p-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2d2e64a2845e55p-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2d2e64a2845e558p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+124", LIT (0x8p+124), { LIT (0x9.f963166f215eb89381836cafaa28p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89381836cafaa3p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89381836cafaa28p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89381836cafaa3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380", LIT (0x8p+16380), { LIT (0x6.3ad4b2136cc6881f0ca607c7946p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc6881f0ca607c7946p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc6881f0ca607c7946p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc6881f0ca607c79464p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.fffffffffffffffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x7.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x7.fffffffffffcp-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.fffffffffffffffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x6.98098d830be42487274a8291c678p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42487274a8291c67cp-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42487274a8291c678p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42487274a8291c67cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xap+0", LIT (0xap+0), { LIT (-0x8.b44f7af9a7a92ce7fb22be024e28p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92ce7fb22be024e2p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92ce7fb22be024e2p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92ce7fb22be024e2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xb.fa09ap+100", LIT (0xb.fa09ap+100), { LIT (-0x1.1e7cf9ec10916c247834e44dabf2p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c247834e44dabf1p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c247834e44dabf1p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c247834e44dabf1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a663c8p-4", LIT (0xc.d4966d92d17082980965c1a663c8p-4), { LIT (0xb.7fb5fe776978e732912810356318p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356318p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356318p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73291281035632p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a663cp-4", LIT (0xc.d4966d92d17082980965c1a663cp-4), { LIT (0xb.7fb5fe776978e73291281035631p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356318p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73291281035631p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356318p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a664p-4", LIT (0xc.d4966d92d17082980965c1a664p-4), { LIT (0xb.7fb5fe776978e73291281035634p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73291281035634p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73291281035634p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356348p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a66p-4", LIT (0xc.d4966d92d17082980965c1a66p-4), { LIT (0xb.7fb5fe776978e732912810356078p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356078p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356078p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73291281035608p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { LIT (0xb.7fb5fe776978e72cfa9001072848p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e72cfa9001072848p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e72cfa9001072848p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e72cfa900107285p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { LIT (0xb.7fb5fe776978e7381aae7a4c30dp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7381aae7a4c30dp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7381aae7a4c30dp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7381aae7a4c30d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.7fb5fe776978e564d5ae94f8cb08p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e564d5ae94f8cb08p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e564d5ae94f8cb08p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e564d5ae94f8cb1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.7fb5fe7769793e65c978bd3cef98p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e65c978bd3cef98p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e65c978bd3cef98p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e65c978bd3cefap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.7fb5f50739fa5f8acc8f4f3f1b3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f8acc8f4f3f1b3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f8acc8f4f3f1b3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f8acc8f4f3f1b38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.7fb600275877a60011766c8a3178p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a60011766c8a3178p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a60011766c8a3178p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a60011766c8a318p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.e7fe0b5fc786b2d966e1d6af1408p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2d966e1d6af1408p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2d966e1d6af1408p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2d966e1d6af141p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0xf.dfffd7bde0fb4ec139784e3b7988p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ec139784e3b799p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ec139784e3b7988p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ec139784e3b799p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0x7.76d600e031521b7cc3cd579a135p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b7cc3cd579a135p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b7cc3cd579a135p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b7cc3cd579a1354p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (0xc.773a2eac3000ddec0c69e7ddef68p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddec0c69e7ddef68p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddec0c69e7ddef68p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddec0c69e7ddef7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.ef3af1b5d8000000000000000138p-4", LIT (0xe.ef3af1b5d8000000000000000138p-4), { LIT (0xc.dbc19333ad3abffffffc0a0c4a1p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4a18p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4a1p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4a18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.ef3af1b5d800000000000000014p-4", LIT (0xe.ef3af1b5d800000000000000014p-4), { LIT (0xc.dbc19333ad3abffffffc0a0c4a18p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4a18p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4a18p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4a2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.ef3af1b5d80000000000000004p-4", LIT (0xe.ef3af1b5d80000000000000004p-4), { LIT (0xc.dbc19333ad3abffffffc0a0c4bb8p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4bcp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4bb8p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.ef3af1b5d800001p-4", LIT (0xe.ef3af1b5d800001p-4), { LIT (0xc.dbc19333ad3ac0098583fa6f614p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac0098583fa6f6148p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac0098583fa6f614p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac0098583fa6f6148p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.ef3af1b5d8008p-4", LIT (0xe.ef3af1b5d8008p-4), { LIT (0xc.dbc19333ad3b0c2c3f7f22cb9868p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c2c3f7f22cb9868p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c2c3f7f22cb9868p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c2c3f7f22cb987p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.ef3af1b5d8p-4", LIT (0xe.ef3af1b5d8p-4), { LIT (0xc.dbc19333ad3abffffffc0a0c4958p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c496p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4958p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c496p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.ef3afp-4", LIT (0xe.ef3afp-4), { LIT (0xc.dbc1922f1d9f2c71bb4e06826528p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c71bb4e0682653p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c71bb4e06826528p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c71bb4e0682653p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.ef3bp-4", LIT (0xe.ef3bp-4), { LIT (0xc.dbc19bb4a58a818888614bb13368p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a818888614bb1337p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a818888614bb13368p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a818888614bb1337p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0x8.3bee07bc9076424bef274717106p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424bef274717106p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424bef2747171058p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424bef2747171058p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xc.6fa5c5665984d8892761be1537b8p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d8892761be1537b8p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d8892761be1537b8p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d8892761be1537cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.452fc98b34e96b61139b09a7c84ap-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b61139b09a7c84ap-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b61139b09a7c84ap-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b61139b09a7c84bp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0xe.f1a3e1dc468a921dddb4e37fbe68p-4), ERRNO_UNCHANGED }, { LIT (-0xe.f1a3e1dc468a921dddb4e37fbe6p-4), ERRNO_UNCHANGED }, { LIT (-0xe.f1a3e1dc468a921dddb4e37fbe6p-4), ERRNO_UNCHANGED }, { LIT (-0xe.f1a3e1dc468a921dddb4e37fbe6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffff8p+16380", LIT (0xf.fffffffffffffffffffffffffff8p+16380), { LIT (0xf.3b0b11ed85b7fe43d110251580bp-4), ERRNO_UNCHANGED }, { LIT (0xf.3b0b11ed85b7fe43d110251580b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.3b0b11ed85b7fe43d110251580bp-4), ERRNO_UNCHANGED }, { LIT (0xf.3b0b11ed85b7fe43d110251580b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7b9650cab0f544p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (-0x8.599b32844aba906cee446be049ap-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906cee446be04998p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906cee446be04998p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906cee446be04998p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (-0xd.8f692p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f692p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.921fb4p+0", LIT (-0x1.921fb4p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.921fb6p+0", LIT (-0x1.921fb6p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xc.143e1p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e1p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e1p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e2p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { LIT (-0x2.8885a4p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a4p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885ap-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885ap-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { LIT (0x1.777a5cp-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cp-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cp-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "-0x6.e23688p+16", LIT (-0x6.e23688p+16), { LIT (-0x1.bf207ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x6.e2369p+16", LIT (-0x6.e2369p+16), { LIT (-0x2.3e1f7cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f78p-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8.60a91p-4", LIT (-0x8.60a91p-4), { LIT (-0x7.fffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8.60a92p-4", LIT (-0x8.60a92p-4), { LIT (-0x8.00001p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (-0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (-0x0p+0), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x8.599b3p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b3p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b3p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (0x4.220ffp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ffp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ffp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.200148p+32", LIT (0x1.200148p+32), { LIT (-0x5.595d8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d78p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xf.fa2adp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2aep-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2aep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xf.fa2adp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2aep-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2aep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.d12ed2p-12", LIT (0x1.d12ed2p-12), { LIT (0x1.d12edp-12), ERRNO_UNCHANGED }, { LIT (0x1.d12edp-12), ERRNO_UNCHANGED }, { LIT (0x1.d12edp-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed2p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xd.76aa4p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa4p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa4p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+120", LIT (0x1p+120), { LIT (0x6.0b8d18p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d18p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d18p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0xf.c777dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (-0x4.cd7e88p-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e88p-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (-0xb.becc5p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc4p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc4p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.553534p+0", LIT (0x2.553534p+0), { LIT (0xb.93258p-4), ERRNO_UNCHANGED }, { LIT (0xb.93258p-4), ERRNO_UNCHANGED }, { LIT (0xb.93258p-4), ERRNO_UNCHANGED }, { LIT (0xb.93259p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.553538p+0", LIT (0x2.553538p+0), { LIT (0xb.93255p-4), ERRNO_UNCHANGED }, { LIT (0xb.93256p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255p-4), ERRNO_UNCHANGED }, { LIT (0xb.93256p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xe.8c7b7p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+64", LIT (0x2p+64), { LIT (-0xc.143e2p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e1p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e1p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (0x1.ffc6dap-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6dap-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6dap-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { LIT (0x2.8885ap-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a4p-24), ERRNO_UNCHANGED }, { LIT (0x2.8885ap-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { LIT (-0x1.777a5ep-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cp-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cp-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.be735cp+0", LIT (0x3.be735cp+0), { LIT (-0x9.10bb1p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb1p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bbp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.be736p+0", LIT (0x3.be736p+0), { LIT (-0x9.10bb5p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb4p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb4p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.ec2a04p+0", LIT (0x3.ec2a04p+0), { LIT (-0xb.4352p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4352p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.ec2ap+0", LIT (0x3.ec2ap+0), { LIT (-0xb.4351ep-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351dp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351dp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x2.42070cp-4), ERRNO_UNCHANGED }, { LIT (0x2.42070cp-4), ERRNO_UNCHANGED }, { LIT (0x2.42070cp-4), ERRNO_UNCHANGED }, { LIT (0x2.42071p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.093388p-4", LIT (0x4.093388p-4), { LIT (0x3.fe478p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe478p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe478p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4784p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.09338p-4", LIT (0x4.09338p-4), { LIT (0x3.fe4778p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.1237e8p+0", LIT (0x4.1237e8p+0), { LIT (-0xc.d263ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d263ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.1237ep+0", LIT (0x4.1237ep+0), { LIT (-0xc.d2636p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0x1.ffb67ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb67ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb678p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb678p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.c92d08p+0", LIT (0x4.c92d08p+0), { LIT (-0xf.f4f48p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f47p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f47p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f47p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.c92d1p+0", LIT (0x4.c92d1p+0), { LIT (-0xf.f4f47p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f47p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xc.1bdcfp-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdcfp-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdcep-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdcep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p+48", LIT (0x4p+48), { LIT (0x7.f13d78p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.fffff8p-128), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-128), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary32)
    { "0x5.6a5008p+64", LIT (0x5.6a5008p+64), { LIT (-0x1.45506ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.455068p-4), ERRNO_UNCHANGED }, { LIT (-0x1.455068p-4), ERRNO_UNCHANGED }, { LIT (-0x1.455068p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.6a5p+64", LIT (0x5.6a5p+64), { LIT (-0x1.ee01dcp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01dcp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01dap-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01dap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.fbec78p+0", LIT (0x5.fbec78p+0), { LIT (-0x4.b6f61p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f61p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f608p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f608p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.fbec7p+0", LIT (0x5.fbec7p+0), { LIT (-0x4.b6f688p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f688p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f68p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5p+0", LIT (0x5p+0), { LIT (-0xf.57c1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { LIT (-0x1.fecb8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { LIT (-0x1.fecbp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecbp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecafep-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecafep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6p+0", LIT (0x6p+0), { LIT (-0x4.787c68p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c6p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c6p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xa.83046p-4), ERRNO_UNCHANGED }, { LIT (0xa.83046p-4), ERRNO_UNCHANGED }, { LIT (0xa.83046p-4), ERRNO_UNCHANGED }, { LIT (0xa.83047p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { LIT (0x7.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.00001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.d4695p-4), ERRNO_UNCHANGED }, { LIT (0xf.d4695p-4), ERRNO_UNCHANGED }, { LIT (0xf.d4695p-4), ERRNO_UNCHANGED }, { LIT (0xf.d4696p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p+124", LIT (0x8p+124), { LIT (0x9.f9631p-4), ERRNO_UNCHANGED }, { LIT (0x9.f9631p-4), ERRNO_UNCHANGED }, { LIT (0x9.f9631p-4), ERRNO_UNCHANGED }, { LIT (0x9.f9632p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x6.980988p-4), ERRNO_UNCHANGED }, { LIT (0x6.98099p-4), ERRNO_UNCHANGED }, { LIT (0x6.980988p-4), ERRNO_UNCHANGED }, { LIT (0x6.98099p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xap+0", LIT (0xap+0), { LIT (-0x8.b44f8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xb.fa09ap+100", LIT (0xb.fa09ap+100), { LIT (-0x1.1e7cfap-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cfap-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf8p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.7fb5fp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.7fb6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.e7fep-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe1p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fep-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0x7.76d6p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d6p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d6p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d608p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (0xc.773a2p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a3p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.ef3afp-4", LIT (0xe.ef3afp-4), { LIT (0xc.dbc19p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.ef3bp-4", LIT (0xe.ef3bp-4), { LIT (0xc.dbc19p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1ap-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0x8.3bee1p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3beep-4), ERRNO_UNCHANGED }, { LIT (-0x8.3beep-4), ERRNO_UNCHANGED }, { LIT (-0x8.3beep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xc.6fa5cp-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5cp-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5cp-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5dp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (-0x8.599b4p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b3p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b3p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (-0xd.8f691a7a95428p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95428p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a9542p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a9542p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.921fb4p+0", LIT (-0x1.921fb4p+0), { LIT (-0xf.fffffffffff38p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.921fb54442d18p+0", LIT (-0x1.921fb54442d18p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.921fb54442d19p+0", LIT (-0x1.921fb54442d19p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.921fb6p+0", LIT (-0x1.921fb6p+0), { LIT (-0xf.fffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xc.143e153b07018p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0702p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b07018p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0702p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { LIT (-0x2.8885a308d3108p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d3106p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d3106p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d3106p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { LIT (0x1.72cece675d1fcp-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fdp-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fcp-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fdp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { LIT (-0x8.d313198a2e038p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e038p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { LIT (0x1.777a5cf72cec5p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec6p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0xf.e00885042dd78p-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd78p-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd7p-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd7p-4), ERRNO_UNCHANGED } },
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
    { "-0x6.e23688p+16", LIT (-0x6.e23688p+16), { LIT (-0x1.bf207c900d878p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d878p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x6.e2368c006c018p+16", LIT (-0x6.e2368c006c018p+16), { LIT (-0x1.feb6a3619e804p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e804p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x6.e2368c006c01cp+16", LIT (-0x6.e2368c006c01cp+16), { LIT (-0x1.feb6a36596829p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596829p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596828p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596828p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x6.e2369p+16", LIT (-0x6.e2369p+16), { LIT (-0x2.3e1f7a26f5944p-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f5944p-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f5942p-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f5942p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8.60a91c16b9b28p-4", LIT (-0x8.60a91c16b9b28p-4), { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8.60a91c16b9b3p-4", LIT (-0x8.60a91c16b9b3p-4), { LIT (-0x8.0000000000008p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8.60a91p-4", LIT (-0x8.60a91p-4), { LIT (-0x7.fffff587e3a08p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a04p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a04p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a04p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8.60a92p-4", LIT (-0x8.60a92p-4), { LIT (-0x8.000003632117p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x8p-972), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffcp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1.452fc98b34e97p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e97p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x8.599b32844aba8p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba8p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba8p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844abbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.2001469775ce6p+32", LIT (0x1.2001469775ce6p+32), { LIT (-0x6.444fda50019fcp-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f8p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (0x4.220ff25f5cfp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf04p-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cfp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf04p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.200148p+32", LIT (0x1.200148p+32), { LIT (-0x5.595d7e536fe38p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe34p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe34p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe34p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xf.fa2adb8953aep-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953aep-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953aep-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xf.fa2adcf9ea838p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea84p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea838p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xf.fa2add3e58948p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e5895p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0xf.fffffffffff3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (0xf.fffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.d12ed2p-12", LIT (0x1.d12ed2p-12), { LIT (0x1.d12ed0fffffdfp-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffep-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfp-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffep-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xd.76aa47848677p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa478486778p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+120", LIT (0x1p+120), { LIT (0x6.0b8d19579bf2cp-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2cp-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2cp-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0xf.c777c6b36a758p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a75p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a75p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a75p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (-0xd.a29d5bb5f9ccp-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb8p-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (-0x4.cd7e86c4077cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bcp-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (-0xb.becc47ab1b8c8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8cp-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.553534p+0", LIT (0x2.553534p+0), { LIT (0xb.9325848408068p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840807p-4), ERRNO_UNCHANGED }, { LIT (0xb.9325848408068p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840807p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.5535376715b9ep+0", LIT (0x2.5535376715b9ep+0), { LIT (0xb.93255eeda1038p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda1038p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda1038p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda104p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.5535376715bap+0", LIT (0x2.5535376715bap+0), { LIT (0xb.93255eeda102p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda1028p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda1028p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.553538p+0", LIT (0x2.553538p+0), { LIT (0xb.93255854754ap-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754ap-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754ap-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xe.8c7b7568da228p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da23p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da228p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da23p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+64", LIT (0x2p+64), { LIT (-0xc.143e153b0702p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0702p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b07018p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b07018p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (0x1.ffc6da9f1ffedp-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffeep-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffedp-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffeep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { LIT (0x2.8885a308d3106p-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d3106p-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d3106p-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d3108p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { LIT (-0x1.72cece675d1fdp-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fdp-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fcp-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fcp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { LIT (0x8.d313198a2e03p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e038p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e038p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { LIT (-0x1.777a5cf72cec6p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec6p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.be735c19be9fep+0", LIT (0x3.be735c19be9fep+0), { LIT (-0x9.10bb11242ec88p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.be735c19beap+0", LIT (0x3.be735c19beap+0), { LIT (-0x9.10bb11242ecap-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ecap-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec98p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.be735cp+0", LIT (0x3.be735cp+0), { LIT (-0x9.10bb0fd0c39d8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d8p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39dp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.be736p+0", LIT (0x3.be736p+0), { LIT (-0x9.10bb448d3cb08p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cbp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cbp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.ec2a0250032a2p+0", LIT (0x3.ec2a0250032a2p+0), { LIT (-0xb.4351eaad0985p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09848p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09848p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09848p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.ec2a0250032ap+0", LIT (0x3.ec2a0250032ap+0), { LIT (-0xb.4351eaad09838p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.ec2a04p+0", LIT (0x3.ec2a04p+0), { LIT (-0xb.4351fdda3d818p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d818p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.ec2ap+0", LIT (0x3.ec2ap+0), { LIT (-0xb.4351d06546e78p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x2.42070db6daab6p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab6p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab6p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.093385688a2d4p-4", LIT (0x4.093385688a2d4p-4), { LIT (0x3.fe477dbdc7958p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.093385688a2dp-4", LIT (0x4.093385688a2dp-4), { LIT (0x3.fe477dbdc7954p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.093388p-4", LIT (0x4.093388p-4), { LIT (0x3.fe4780403e806p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e808p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e806p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e808p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.09338p-4", LIT (0x4.09338p-4), { LIT (0x3.fe4778810e026p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e028p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.1237e153f7084p+0", LIT (0x4.1237e153f7084p+0), { LIT (-0xc.d2635f3faf598p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.1237e153f708p+0", LIT (0x4.1237e153f708p+0), { LIT (-0xc.d2635f3faf57p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf568p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf568p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf568p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.1237e8p+0", LIT (0x4.1237e8p+0), { LIT (-0xc.d2639f1afc7f8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7fp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.1237ep+0", LIT (0x4.1237ep+0), { LIT (-0xc.d2635289f075p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f075p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f0748p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f0748p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0x1.ffb679ba994b8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.c92d08p+0", LIT (0x4.c92d08p+0), { LIT (-0xf.f4f4736648dc8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.c92d0ffa4bf04p+0", LIT (0x4.c92d0ffa4bf04p+0), { LIT (-0xf.f4f46a082f28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f278p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f278p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.c92d0ffa4bfp+0", LIT (0x4.c92d0ffa4bfp+0), { LIT (-0xf.f4f46a082f288p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f288p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.c92d1p+0", LIT (0x4.c92d1p+0), { LIT (-0xf.f4f46a017cb9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb88p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb88p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb88p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xc.1bdceeee0f578p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p+48", LIT (0x4p+48), { LIT (0x7.f13d78eabb768p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76cp-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb768p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.ffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffep-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.6a5005df43638p+64", LIT (0x5.6a5005df43638p+64), { LIT (0x2.f0e32ed649b32p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b32p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b32p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b34p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.6a5005df4363cp+64", LIT (0x5.6a5005df4363cp+64), { LIT (0x6.5ea3351c9d9d8p-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9d8p-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.6a5008p+64", LIT (0x5.6a5008p+64), { LIT (-0x1.4550689b93bbfp-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbep-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbep-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.6a5p+64", LIT (0x5.6a5p+64), { LIT (-0x1.ee01db6bc8ef3p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef3p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.fbec7477d4a84p+0", LIT (0x5.fbec7477d4a84p+0), { LIT (-0x4.b6f642a935a1p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.fbec7477d4a8p+0", LIT (0x5.fbec7477d4a8p+0), { LIT (-0x4.b6f642a935a4cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a48p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a48p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.fbec78p+0", LIT (0x5.fbec78p+0), { LIT (-0x4.b6f60ca8d4154p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d415p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d415p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d415p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.fbec7p+0", LIT (0x5.fbec7p+0), { LIT (-0x4.b6f686f9ea13p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea13p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5p+0", LIT (0x5p+0), { LIT (-0xf.57c0faf04c9ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c998p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c998p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c998p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { LIT (-0x1.fecb772e1b87p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b87p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86fp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { LIT (-0x1.fecb772e1b831p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b83p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b83p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b83p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { LIT (-0x1.fecb7e68ad6eap-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6eap-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { LIT (-0x1.fecaff6878a11p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a11p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6p+0", LIT (0x6p+0), { LIT (-0x4.787c62ac28b04p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28bp-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28bp-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xa.830461368504p-4), ERRNO_UNCHANGED }, { LIT (0xa.830461368504p-4), ERRNO_UNCHANGED }, { LIT (0xa.830461368504p-4), ERRNO_UNCHANGED }, { LIT (0xa.8304613685048p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { LIT (0x7.ffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000000000008p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { LIT (0x7.fffff587e3a04p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a04p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a04p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a08p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { LIT (0x8.0000036321168p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000036321168p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000036321168p-4), ERRNO_UNCHANGED }, { LIT (0x8.000003632117p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.d469501467bdp-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd8p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bdp-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (0x9.0292465edbaf8p-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbbp-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaf8p-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+124", LIT (0x8p+124), { LIT (0x9.f963166f215e8p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215e8p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215e8p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.ffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.ffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffcp-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x6.98098d830be4p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be44p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be4p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xap+0", LIT (0xap+0), { LIT (-0x8.b44f7af9a7a98p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a9p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a9p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xb.fa09ap+100", LIT (0xb.fa09ap+100), { LIT (-0x1.1e7cf9ec10917p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10917p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.7fb5fe7769788p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776979p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769788p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776979p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.7fb5fe776979p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776979p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776979p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769798p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.7fb5f50739fap-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa8p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fap-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.7fb6002758778p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb6002758778p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb6002758778p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275878p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.e7fe0b5fc7868p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc7868p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc7868p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc787p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0xf.dfffd7bde0fbp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fbp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0x7.76d600e03152p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e03152p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e03152p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031524p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (0xc.773a2eac30008p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3001p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac30008p-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.ef3af1b5d8008p-4", LIT (0xe.ef3af1b5d8008p-4), { LIT (0xc.dbc19333ad3bp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3bp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3bp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.ef3af1b5d8p-4", LIT (0xe.ef3af1b5d8p-4), { LIT (0xc.dbc19333ad3a8p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3a8p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3a8p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.ef3afp-4", LIT (0xe.ef3afp-4), { LIT (0xc.dbc1922f1d9fp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9fp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9fp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.ef3bp-4", LIT (0xe.ef3bp-4), { LIT (0xc.dbc19bb4a58a8p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a8p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a8p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0x8.3bee07bc90768p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc90768p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xc.6fa5c56659848p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665985p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c56659848p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665985p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.452fc98b34e96p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e97p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e97p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (-0x8.599b32844abbp-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (-0xd.8f691a7a95425ffcb89dc2b98p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffcb89dc2b97cp-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffcb89dc2b97cp-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffcb89dc2b97cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fb4p+0", LIT (-0x1.921fb4p+0), { LIT (-0xf.fffffffffff32a3661c108e138p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3661c108e138p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3661c108e134p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3661c108e134p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fb54442d18468p+0", LIT (-0x1.921fb54442d18468p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fb54442d18469898cc517018p+0", LIT (-0x1.921fb54442d18469898cc517018p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fb54442d18469898cc51702p+0", LIT (-0x1.921fb54442d18469898cc51702p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fb54442d1846ap+0", LIT (-0x1.921fb54442d1846ap+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fb54442d18p+0", LIT (-0x1.921fb54442d18p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fb54442d19p+0", LIT (-0x1.921fb54442d19p+0), { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.921fb6p+0", LIT (-0x1.921fb6p+0), { LIT (-0xf.fffffffffffbb290924e3a114cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb290924e3a1148p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb290924e3a1148p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb290924e3a1148p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xc.143e153b0701e800f9b8a47b74p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e800f9b8a47b74p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e800f9b8a47b74p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e800f9b8a47b78p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { LIT (-0x2.8885a308d31063e2b6c62b7f4ep-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063e2b6c62b7f4dp-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063e2b6c62b7f4dp-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063e2b6c62b7f4dp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a308d313198a2e03p+0", LIT (-0x3.243f6a8885a308d313198a2e03p+0), { LIT (-0x7.07344a4093822299f31d0082fp-108), ERRNO_UNCHANGED }, { LIT (-0x7.07344a4093822299f31d0082fp-108), ERRNO_UNCHANGED }, { LIT (-0x7.07344a4093822299f31d0082eep-108), ERRNO_UNCHANGED }, { LIT (-0x7.07344a4093822299f31d0082eep-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a308d313198a2e04p+0", LIT (-0x3.243f6a8885a308d313198a2e04p+0), { LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), ERRNO_UNCHANGED }, { LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), ERRNO_UNCHANGED }, { LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), ERRNO_UNCHANGED }, { LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d14p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a308d4p+0", LIT (-0x3.243f6a8885a308d4p+0), { LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd64p-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd68p-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd64p-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd68p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a308dp+0", LIT (-0x3.243f6a8885a308dp+0), { LIT (-0x3.13198a2e03707344a40938222ap-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344a40938222ap-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344a409382229p-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344a409382229p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { LIT (0x1.72cece675d1fc8f8cbb5bf6c7dp-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8cbb5bf6c7d8p-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8cbb5bf6c7dp-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8cbb5bf6c7d8p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { LIT (-0x8.d313198a2e03707344a4093824p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707344a409382p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707344a409382p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707344a409382p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { LIT (0x1.777a5cf72cec5fd61896cb4f408p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd61896cb4f41p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd61896cb4f408p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd61896cb4f41p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0xf.e00885042dd770c93962abdb64p-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770c93962abdb6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770c93962abdb6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770c93962abdb6p-4), ERRNO_UNCHANGED } },
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
    { "-0x6.e23688p+16", LIT (-0x6.e23688p+16), { LIT (-0x1.bf207c900d877cb73f555829e4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb73f555829e4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb73f555829e38p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb73f555829e38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x6.e2368c006c018228p+16", LIT (-0x6.e2368c006c018228p+16), { LIT (-0x1.feb6a361c0bb501b009ef2c1f18p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501b009ef2c1f1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501b009ef2c1f1p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501b009ef2c1f1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x6.e2368c006c018p+16", LIT (-0x6.e2368c006c018p+16), { LIT (-0x1.feb6a3619e803c49fb3b778719p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c49fb3b778719p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c49fb3b7787188p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c49fb3b7787188p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x6.e2368c006c01cp+16", LIT (-0x6.e2368c006c01cp+16), { LIT (-0x1.feb6a365968288771150b6f6c58p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a365968288771150b6f6c5p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a365968288771150b6f6c5p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a365968288771150b6f6c5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x6.e2369p+16", LIT (-0x6.e2369p+16), { LIT (-0x2.3e1f7a26f594336f9e583b26bcp-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336f9e583b26bcp-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336f9e583b26bbp-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336f9e583b26bbp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.60a91c16b9b28p-4", LIT (-0x8.60a91c16b9b28p-4), { LIT (-0x7.ffffffffffffc6ab95779c1ebp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6ab95779c1eaep-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6ab95779c1eaep-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6ab95779c1eaep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.60a91c16b9b2c232dd99707ab4p-4", LIT (-0x8.60a91c16b9b2c232dd99707ab4p-4), { LIT (-0x8.00000000000000000000000004p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.60a91c16b9b2c232dd99707abp-4", LIT (-0x8.60a91c16b9b2c232dd99707abp-4), { LIT (-0x7.fffffffffffffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.60a91c16b9b2c23p-4", LIT (-0x8.60a91c16b9b2c23p-4), { LIT (-0x7.fffffffffffffffd84af2ec142p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffd84af2ec14p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffd84af2ec14p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffd84af2ec14p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.60a91c16b9b2c24p-4", LIT (-0x8.60a91c16b9b2c24p-4), { LIT (-0x8.000000000000000b5feca2ed68p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000b5feca2ed68p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000b5feca2ed64p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000000b5feca2ed64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.60a91c16b9b3p-4", LIT (-0x8.60a91c16b9b3p-4), { LIT (-0x8.00000000000035858118fd5158p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000035858118fd5158p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000035858118fd5154p-4), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000035858118fd5154p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.60a91p-4", LIT (-0x8.60a91p-4), { LIT (-0x7.fffff587e3a050cf967fba7bc8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050cf967fba7bc8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050cf967fba7bc6p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050cf967fba7bc6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8.60a92p-4", LIT (-0x8.60a92p-4), { LIT (-0x8.0000036321168852c4130c64b8p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168852c4130c64b4p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168852c4130c64b4p-4), ERRNO_UNCHANGED }, { LIT (-0x8.0000036321168852c4130c64b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x8p-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1.452fc98b34e96b61139b09a7c88p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b61139b09a7c88p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b61139b09a7c8p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b61139b09a7c8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0xe.f1a3e1dc468a921dddb4e37fbcp-4), ERRNO_UNCHANGED }, { LIT (0xe.f1a3e1dc468a921dddb4e37fcp-4), ERRNO_UNCHANGED }, { LIT (0xe.f1a3e1dc468a921dddb4e37fbcp-4), ERRNO_UNCHANGED }, { LIT (0xe.f1a3e1dc468a921dddb4e37fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x8.599b32844aba906cee446be048p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba906cee446be048p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba906cee446be048p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba906cee446be04cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.2001469775ce6p+32", LIT (0x1.2001469775ce6p+32), { LIT (-0x6.444fda50019f9f5ba3779ca708p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f5ba3779ca706p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f5ba3779ca706p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f5ba3779ca706p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (0x4.220ff25f5cf02a464dbb3a679cp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a464dbb3a679cp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a464dbb3a679cp-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a464dbb3a679ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.200148p+32", LIT (0x1.200148p+32), { LIT (-0x5.595d7e536fe35edbe2ad0df9dap-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35edbe2ad0df9dap-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35edbe2ad0df9d8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35edbe2ad0df9d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xf.fa2adb8953ae26229c919ec8f4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae26229c919ec8f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae26229c919ec8f4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae26229c919ec8f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xf.fa2adcf9ea83dbdd053ee455e8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbdd053ee455ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbdd053ee455e8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbdd053ee455ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xf.fa2add3e58948d10238cc27b54p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d10238cc27b58p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d10238cc27b54p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d10238cc27b58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0xf.fffffffffff32a3661c108e134p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3661c108e138p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3661c108e134p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3661c108e138p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18469898cc517018p+0", LIT (0x1.921fb54442d18469898cc517018p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18469898cc51702p+0", LIT (0x1.921fb54442d18469898cc51702p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (0xf.fffffffffffbb290924e3a1148p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb290924e3a1148p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb290924e3a1148p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb290924e3a114cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.d12ed2p-12", LIT (0x1.d12ed2p-12), { LIT (0x1.d12ed0fffffdfe0f0008c8b282p-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe0f0008c8b282p-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe0f0008c8b282p-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe0f0008c8b2828p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xd.76aa47848677020c6e9e909c5p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677020c6e9e909c5p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677020c6e9e909c5p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677020c6e9e909c54p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+120", LIT (0x1p+120), { LIT (0x6.0b8d19579bf2db5e5f1aa933f2p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db5e5f1aa933f4p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db5e5f1aa933f2p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db5e5f1aa933f4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0xf.c777c6b36a750a5fdeb8807a18p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5fdeb8807a14p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5fdeb8807a14p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5fdeb8807a14p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (-0xd.a29d5bb5f9cb87d14de41dc994p-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87d14de41dc99p-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87d14de41dc99p-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87d14de41dc99p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (-0x4.cd7e86c4077bf0debc87d70d1ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0debc87d70d1ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0debc87d70d18p-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0debc87d70d18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (-0xb.becc47ab1b8c70793712c4ff2cp-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c70793712c4ff2cp-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c70793712c4ff28p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c70793712c4ff28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.553534p+0", LIT (0x2.553534p+0), { LIT (0xb.932584840806c6090aefd5f25p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c6090aefd5f25p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c6090aefd5f25p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c6090aefd5f254p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.5535376715b9ep+0", LIT (0x2.5535376715b9ep+0), { LIT (0xb.93255eeda103a17c97f0fb5124p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a17c97f0fb5124p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a17c97f0fb5124p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a17c97f0fb5128p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.5535376715b9fffcp+0", LIT (0x2.5535376715b9fffcp+0), { LIT (0xb.93255eeda102402c2f97f47dccp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102402c2f97f47ddp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102402c2f97f47dccp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102402c2f97f47ddp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.5535376715b9ffffffffffffffp+0", LIT (0x2.5535376715b9ffffffffffffffp+0), { LIT (0xb.93255eeda10240000004f6fd5p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd5p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd5p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd54p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.5535376715bap+0", LIT (0x2.5535376715bap+0), { LIT (0xb.93255eeda10240000004f6fd44p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd44p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd44p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda10240000004f6fd48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.553538p+0", LIT (0x2.553538p+0), { LIT (0xb.93255854754a36d261581d7c0cp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36d261581d7c0cp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36d261581d7c0cp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36d261581d7c1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xe.8c7b7568da22efd5c240c4004cp-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efd5c240c4005p-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efd5c240c4004cp-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efd5c240c4005p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+64", LIT (0x2p+64), { LIT (-0xc.143e153b0701e800f9b8a47b78p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e800f9b8a47b74p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e800f9b8a47b74p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e800f9b8a47b74p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (0x1.ffc6da9f1ffed895f9fa424ba9p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed895f9fa424ba9p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed895f9fa424ba9p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed895f9fa424ba98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { LIT (0x2.8885a308d31063e2b6c62b7f4dp-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e2b6c62b7f4dp-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e2b6c62b7f4dp-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e2b6c62b7f4ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a308d313198a2e03p+0", LIT (0x3.243f6a8885a308d313198a2e03p+0), { LIT (0x7.07344a4093822299f31d0082eep-108), ERRNO_UNCHANGED }, { LIT (0x7.07344a4093822299f31d0082fp-108), ERRNO_UNCHANGED }, { LIT (0x7.07344a4093822299f31d0082eep-108), ERRNO_UNCHANGED }, { LIT (0x7.07344a4093822299f31d0082fp-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a308d313198a2e04p+0", LIT (0x3.243f6a8885a308d313198a2e04p+0), { LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d14p-108), ERRNO_UNCHANGED }, { LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), ERRNO_UNCHANGED }, { LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), ERRNO_UNCHANGED }, { LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a308d4p+0", LIT (0x3.243f6a8885a308d4p+0), { LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd68p-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd68p-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd64p-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd64p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a308dp+0", LIT (0x3.243f6a8885a308dp+0), { LIT (0x3.13198a2e03707344a409382229p-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344a40938222ap-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344a409382229p-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344a40938222ap-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8cbb5bf6c7dp-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8cbb5bf6c7dp-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { LIT (0x8.d313198a2e03707344a409382p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707344a409382p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707344a409382p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707344a4093824p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { LIT (-0x1.777a5cf72cec5fd61896cb4f41p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd61896cb4f41p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd61896cb4f408p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd61896cb4f408p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.be735c19be9fep+0", LIT (0x3.be735c19be9fep+0), { LIT (-0x9.10bb11242ec81a1c3545a17908p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1c3545a17904p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1c3545a17904p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1c3545a17904p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.be735c19be9ffffcp+0", LIT (0x3.be735c19be9ffffcp+0), { LIT (-0x9.10bb11242ec9bfcb43893004c4p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcb43893004c4p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcb43893004cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcb43893004cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.be735c19be9fffffffffffffffp+0", LIT (0x3.be735c19be9fffffffffffffffp+0), { LIT (-0x9.10bb11242ec9c000000287a17cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a17cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a178p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a178p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.be735c19beap+0", LIT (0x3.be735c19beap+0), { LIT (-0x9.10bb11242ec9c000000287a18cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a188p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a188p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9c000000287a188p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.be735cp+0", LIT (0x3.be735cp+0), { LIT (-0x9.10bb0fd0c39d59f8b7898e8644p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59f8b7898e864p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59f8b7898e864p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59f8b7898e864p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.be736p+0", LIT (0x3.be736p+0), { LIT (-0x9.10bb448d3cb0166e220f3af794p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166e220f3af794p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166e220f3af79p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166e220f3af79p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.ec2a0250032a00000000000001p+0", LIT (0x3.ec2a0250032a00000000000001p+0), { LIT (-0xb.4351eaad09833fffffff47a71cp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a718p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a718p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a718p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.ec2a0250032a0004p+0", LIT (0x3.ec2a0250032a0004p+0), { LIT (-0xb.4351eaad0983402d74f5d3cb84p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402d74f5d3cb84p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402d74f5d3cb8p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402d74f5d3cb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.ec2a0250032a2p+0", LIT (0x3.ec2a0250032a2p+0), { LIT (-0xb.4351eaad0984aba7b4606b57bp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984aba7b4606b57acp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984aba7b4606b57acp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984aba7b4606b57acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.ec2a0250032ap+0", LIT (0x3.ec2a0250032ap+0), { LIT (-0xb.4351eaad09833fffffff47a71p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a70cp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a70cp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833fffffff47a70cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.ec2a04p+0", LIT (0x3.ec2a04p+0), { LIT (-0xb.4351fdda3d81513dedde4fd2dp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513dedde4fd2ccp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513dedde4fd2ccp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513dedde4fd2ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.ec2ap+0", LIT (0x3.ec2ap+0), { LIT (-0xb.4351d06546e7181306453a5b3p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181306453a5b3p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181306453a5b2cp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181306453a5b2cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x2.42070db6daab69e3902e846831p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e3902e846831p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e3902e846831p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e3902e846832p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.093385688a2d1508p-4", LIT (0x4.093385688a2d1508p-4), { LIT (0x3.fe477dbdc795642fffb6d11d98p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795642fffb6d11d98p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795642fffb6d11d98p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795642fffb6d11d99p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.093385688a2d150c00bf42a08ep-4", LIT (0x4.093385688a2d150c00bf42a08ep-4), { LIT (0x3.fe477dbdc7956433e008453614p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453614p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453614p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453615p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.093385688a2d150c00bf42a09p-4", LIT (0x4.093385688a2d150c00bf42a09p-4), { LIT (0x3.fe477dbdc7956433e008453615p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453616p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453615p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956433e008453616p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.093385688a2d151p-4", LIT (0x4.093385688a2d151p-4), { LIT (0x3.fe477dbdc7956437bee74ef983p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956437bee74ef983p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956437bee74ef983p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956437bee74ef984p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.093385688a2d4p-4", LIT (0x4.093385688a2d4p-4), { LIT (0x3.fe477dbdc7958dcbe52ad14f88p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dcbe52ad14f89p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dcbe52ad14f88p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dcbe52ad14f89p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.093385688a2dp-4", LIT (0x4.093385688a2dp-4), { LIT (0x3.fe477dbdc7954fd2613bf1f96cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd2613bf1f96cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd2613bf1f96cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd2613bf1f96dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.093388p-4", LIT (0x4.093388p-4), { LIT (0x3.fe4780403e8078ca89790118cbp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ca89790118ccp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ca89790118cbp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ca89790118ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.09338p-4", LIT (0x4.09338p-4), { LIT (0x3.fe4778810e026fe1e37f141da4p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fe1e37f141da5p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fe1e37f141da4p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fe1e37f141da5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.1237e153f70800000000000002p+0", LIT (0x4.1237e153f70800000000000002p+0), { LIT (-0xc.d2635f3faf56bffffffb0fcad8p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcad4p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcad4p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcad4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.1237e153f7080008p+0", LIT (0x4.1237e153f7080008p+0), { LIT (-0xc.d2635f3faf56c04c91082c535p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04c91082c534cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04c91082c534cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04c91082c534cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.1237e153f7084p+0", LIT (0x4.1237e153f7084p+0), { LIT (-0xc.d2635f3faf59248868df5425dp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248868df5425ccp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248868df5425ccp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248868df5425ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.1237e153f708p+0", LIT (0x4.1237e153f708p+0), { LIT (-0xc.d2635f3faf56bffffffb0fcac4p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcac4p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcacp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffffffb0fcacp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.1237e8p+0", LIT (0x4.1237e8p+0), { LIT (-0xc.d2639f1afc7f4698649bd4cf5cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f4698649bd4cf58p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f4698649bd4cf58p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f4698649bd4cf58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.1237ep+0", LIT (0x4.1237ep+0), { LIT (-0xc.d2635289f074d2b2df33331dep-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2b2df33331ddcp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2b2df33331ddcp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2b2df33331ddcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0x1.ffb679ba994b76173f9040638p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b76173f9040638p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b76173f9040637f8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b76173f9040637f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.c92d08p+0", LIT (0x4.c92d08p+0), { LIT (-0xf.f4f4736648dc2a042045142728p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2a042045142724p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2a042045142724p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2a042045142724p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.c92d0ffa4bf000000000000002p+0", LIT (0x4.c92d0ffa4bf000000000000002p+0), { LIT (-0xf.f4f46a082f2840000005480a48p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a48p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a44p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a44p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.c92d0ffa4bf00008p+0", LIT (0x4.c92d0ffa4bf00008p+0), { LIT (-0xf.f4f46a082f283ff69b37289dc4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ff69b37289dcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ff69b37289dcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ff69b37289dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.c92d0ffa4bf04p+0", LIT (0x4.c92d0ffa4bf04p+0), { LIT (-0xf.f4f46a082f27f4d98f09e3c6dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4d98f09e3c6dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4d98f09e3c6ccp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4d98f09e3c6ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.c92d0ffa4bfp+0", LIT (0x4.c92d0ffa4bfp+0), { LIT (-0xf.f4f46a082f2840000005480a4cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a48p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a48p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f2840000005480a48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.c92d1p+0", LIT (0x4.c92d1p+0), { LIT (-0xf.f4f46a017cb883f95b64a197ecp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883f95b64a197e8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883f95b64a197e8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883f95b64a197e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xc.1bdceeee0f5738674c02ad0724p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f5738674c02ad0724p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f5738674c02ad072p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f5738674c02ad072p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p+48", LIT (0x4p+48), { LIT (0x7.f13d78eabb76b8a986d98d6702p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a986d98d6704p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a986d98d6702p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a986d98d6704p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffffffffffffcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.ffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffffffffffffffffffffffffffp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.6a5005df4363833413fa44f74ap+64", LIT (0x5.6a5005df4363833413fa44f74ap+64), { LIT (-0xf.fdc305247e694b390edb67a7fcp-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305247e694b390edb67a7fcp-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305247e694b390edb67a7f8p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305247e694b390edb67a7f8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.6a5005df4363833413fa44f74cp+64", LIT (0x5.6a5005df4363833413fa44f74cp+64), { LIT (-0xf.fdc305227f69439ae6b7b4255p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305227f69439ae6b7b4255p-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305227f69439ae6b7b4254cp-8), ERRNO_UNCHANGED }, { LIT (-0xf.fdc305227f69439ae6b7b4254cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.6a5005df43638338p+64", LIT (0x5.6a5005df43638338p+64), { LIT (-0xa.8640e82e7924ec0007c7517974p-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ec0007c7517974p-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ec0007c751797p-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ec0007c751797p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.6a5005df4363833p+64", LIT (0x5.6a5005df4363833p+64), { LIT (0xd.7457bd2255e689f0662a7ba854p-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689f0662a7ba854p-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689f0662a7ba854p-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689f0662a7ba858p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.6a5005df43638p+64", LIT (0x5.6a5005df43638p+64), { LIT (0x2.f0e32ed649b326445c86bd0d5ap-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b326445c86bd0d5ap-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b326445c86bd0d5ap-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b326445c86bd0d5bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.6a5005df4363cp+64", LIT (0x5.6a5005df4363cp+64), { LIT (0x6.5ea3351c9d9da321a84877b1bep-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da321a84877b1cp-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da321a84877b1bep-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da321a84877b1cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.6a5008p+64", LIT (0x5.6a5008p+64), { LIT (-0x1.4550689b93bbe1406aee261039p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe1406aee2610388p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe1406aee2610388p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe1406aee2610388p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.6a5p+64", LIT (0x5.6a5p+64), { LIT (-0x1.ee01db6bc8ef288c92dcf3ee918p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288c92dcf3ee918p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288c92dcf3ee91p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288c92dcf3ee91p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fbec7477d4a800000000000002p+0", LIT (0x5.fbec7477d4a800000000000002p+0), { LIT (-0x4.b6f642a935a49fffffff9a1c6p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c5ep-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c5ep-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c5ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fbec7477d4a80008p+0", LIT (0x5.fbec7477d4a80008p+0), { LIT (-0x4.b6f642a935a49f85aee98a979ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f85aee98a9798p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f85aee98a9798p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f85aee98a9798p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fbec7477d4a84p+0", LIT (0x5.fbec7477d4a84p+0), { LIT (-0x4.b6f642a935a0cd774f8372f494p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd774f8372f494p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd774f8372f492p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd774f8372f492p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fbec7477d4a8p+0", LIT (0x5.fbec7477d4a8p+0), { LIT (-0x4.b6f642a935a49fffffff9a1c7ep-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c7cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c7cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49fffffff9a1c7cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fbec78p+0", LIT (0x5.fbec78p+0), { LIT (-0x4.b6f60ca8d4150bc1732b1580fep-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bc1732b1580fcp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bc1732b1580fcp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bc1732b1580fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.fbec7p+0", LIT (0x5.fbec7p+0), { LIT (-0x4.b6f686f9ea12e8ec702d198ccp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8ec702d198ccp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8ec702d198cbep-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8ec702d198cbep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5p+0", LIT (0x5p+0), { LIT (-0xf.57c0faf04c999135789f2ab1ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c999135789f2ab1ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c999135789f2ab1dcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c999135789f2ab1dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { LIT (-0x1.fecb772e1b86f8e74fbeae63ee8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e74fbeae63ee8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e74fbeae63eep-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e74fbeae63eep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cc8749212e72p+0", LIT (0x6.287cc8749212e72p+0), { LIT (-0x1.fecb772e1b848bca4e961470b28p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bca4e961470b2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bca4e961470b2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bca4e961470b2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { LIT (-0x1.fecb772e1b8300e5ab16d9008fp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e5ab16d9008e8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e5ab16d9008e8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e5ab16d9008e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { LIT (-0x1.fecb7e68ad6e9c3f77c1915bc98p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3f77c1915bc9p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3f77c1915bc9p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3f77c1915bc9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { LIT (-0x1.fecaff6878a10ce5d42fde40e7p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce5d42fde40e7p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce5d42fde40e68p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce5d42fde40e68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6p+0", LIT (0x6p+0), { LIT (-0x4.787c62ac28b00e989105113d2ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e989105113d28p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e989105113d28p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e989105113d28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xa.83046136850421dd444208fd74p-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421dd444208fd78p-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421dd444208fd74p-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421dd444208fd78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { LIT (0x7.ffffffffffffc6ab95779c1eaep-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6ab95779c1eaep-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6ab95779c1eaep-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6ab95779c1ebp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b2c232dd99707ab4p-4", LIT (0x8.60a91c16b9b2c232dd99707ab4p-4), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000000000000000004p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b2c232dd99707abp-4", LIT (0x8.60a91c16b9b2c232dd99707abp-4), { LIT (0x7.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b2c23p-4", LIT (0x8.60a91c16b9b2c23p-4), { LIT (0x7.fffffffffffffffd84af2ec14p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffd84af2ec14p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffd84af2ec14p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffd84af2ec142p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b2c24p-4", LIT (0x8.60a91c16b9b2c24p-4), { LIT (0x8.000000000000000b5feca2ed64p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000b5feca2ed68p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000b5feca2ed64p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000000b5feca2ed68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { LIT (0x8.00000000000035858118fd5154p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000035858118fd5158p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000035858118fd5154p-4), ERRNO_UNCHANGED }, { LIT (0x8.00000000000035858118fd5158p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { LIT (0x7.fffff587e3a050cf967fba7bc6p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050cf967fba7bc8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050cf967fba7bc6p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050cf967fba7bc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { LIT (0x8.0000036321168852c4130c64b4p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000036321168852c4130c64b4p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000036321168852c4130c64b4p-4), ERRNO_UNCHANGED }, { LIT (0x8.0000036321168852c4130c64b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.d469501467bd74fb1585382844p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd74fb1585382848p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd74fb1585382844p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd74fb1585382848p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (0x9.0292465edbaff2d2e64a2845e4p-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2d2e64a2845e4p-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2d2e64a2845e4p-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2d2e64a2845e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+124", LIT (0x8p+124), { LIT (0x9.f963166f215eb89381836cafa8p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89381836cafacp-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89381836cafa8p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89381836cafacp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x7.fffffffffffffffffffffffffcp-972), UNDERFLOW_EXCEPTION_OK }, { LIT (0x8p-972), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_ibm128)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x6.98098d830be42487274a8291c6p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42487274a8291c6p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42487274a8291c6p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42487274a8291c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xap+0", LIT (0xap+0), { LIT (-0x8.b44f7af9a7a92ce7fb22be025p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92ce7fb22be025p-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92ce7fb22be024cp-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92ce7fb22be024cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xb.fa09ap+100", LIT (0xb.fa09ap+100), { LIT (-0x1.1e7cf9ec10916c247834e44dacp-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c247834e44dacp-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c247834e44dab8p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c247834e44dab8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082980965c1a664p-4", LIT (0xc.d4966d92d17082980965c1a664p-4), { LIT (0xb.7fb5fe776978e732912810356p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7329128103564p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7329128103564p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082980965c1a66p-4", LIT (0xc.d4966d92d17082980965c1a66p-4), { LIT (0xb.7fb5fe776978e732912810356p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e732912810356p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7329128103564p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { LIT (0xb.7fb5fe776978e72cfa90010728p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e72cfa90010728p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e72cfa90010728p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e72cfa9001072cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { LIT (0xb.7fb5fe776978e7381aae7a4c3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7381aae7a4c3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7381aae7a4c3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e7381aae7a4c34p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.7fb5fe776978e564d5ae94f8c8p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e564d5ae94f8ccp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e564d5ae94f8c8p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e564d5ae94f8ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.7fb5fe7769793e65c978bd3cecp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e65c978bd3cfp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e65c978bd3cecp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e65c978bd3cfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.7fb5f50739fa5f8acc8f4f3f18p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f8acc8f4f3f1cp-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f8acc8f4f3f18p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f8acc8f4f3f1cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.7fb600275877a60011766c8a3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a60011766c8a3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a60011766c8a3p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a60011766c8a34p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.e7fe0b5fc786b2d966e1d6af14p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2d966e1d6af14p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2d966e1d6af14p-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2d966e1d6af18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0xf.dfffd7bde0fb4ec139784e3b78p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ec139784e3b78p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ec139784e3b78p-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ec139784e3b7cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0x7.76d600e031521b7cc3cd579a12p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b7cc3cd579a14p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b7cc3cd579a12p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b7cc3cd579a14p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (0xc.773a2eac3000ddec0c69e7ddecp-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddec0c69e7ddfp-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddec0c69e7ddecp-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddec0c69e7ddfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.ef3af1b5d80000000000000004p-4", LIT (0xe.ef3af1b5d80000000000000004p-4), { LIT (0xc.dbc19333ad3abffffffc0a0c48p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4cp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c48p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.ef3af1b5d800001p-4", LIT (0xe.ef3af1b5d800001p-4), { LIT (0xc.dbc19333ad3ac0098583fa6f6p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac0098583fa6f6p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac0098583fa6f6p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac0098583fa6f64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.ef3af1b5d8008p-4", LIT (0xe.ef3af1b5d8008p-4), { LIT (0xc.dbc19333ad3b0c2c3f7f22cb98p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c2c3f7f22cb98p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c2c3f7f22cb98p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c2c3f7f22cb9cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.ef3af1b5d8p-4", LIT (0xe.ef3af1b5d8p-4), { LIT (0xc.dbc19333ad3abffffffc0a0c48p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c48p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c48p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffffffc0a0c4cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.ef3afp-4", LIT (0xe.ef3afp-4), { LIT (0xc.dbc1922f1d9f2c71bb4e068264p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c71bb4e068264p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c71bb4e068264p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c71bb4e068268p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.ef3bp-4", LIT (0xe.ef3bp-4), { LIT (0xc.dbc19bb4a58a818888614bb13p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a818888614bb134p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a818888614bb13p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a818888614bb134p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0x8.3bee07bc9076424bef27471714p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424bef2747171p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424bef2747171p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424bef2747171p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xc.6fa5c5665984d8892761be1534p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d8892761be1538p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d8892761be1534p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d8892761be1538p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.452fc98b34e96b61139b09a7c8p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b61139b09a7c88p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b61139b09a7c8p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b61139b09a7c88p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (-0xe.f1a3e1dc468a921dddb4e37fcp-4), ERRNO_UNCHANGED }, { LIT (-0xe.f1a3e1dc468a921dddb4e37fcp-4), ERRNO_UNCHANGED }, { LIT (-0xe.f1a3e1dc468a921dddb4e37fbcp-4), ERRNO_UNCHANGED }, { LIT (-0xe.f1a3e1dc468a921dddb4e37fbcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (-0x8.599b32844aba906cee446be04cp-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906cee446be048p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906cee446be048p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906cee446be048p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (-0xd.8f691a7a95426p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95426p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffp-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fb4p+0", LIT (-0x1.921fb4p+0), { LIT (-0xf.fffffffffff32a4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fb54442d18468p+0", LIT (-0x1.921fb54442d18468p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fb54442d1846ap+0", LIT (-0x1.921fb54442d1846ap+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fb54442d18p+0", LIT (-0x1.921fb54442d18p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fb54442d19p+0", LIT (-0x1.921fb54442d19p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.921fb6p+0", LIT (-0x1.921fb6p+0), { LIT (-0xf.fffffffffffbb2ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e81p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (-0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { LIT (-0x2.8885a308d31063e4p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063e4p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063ep-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6a8885a308d4p+0", LIT (-0x3.243f6a8885a308d4p+0), { LIT (0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbcp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6a8885a308dp+0", LIT (-0x3.243f6a8885a308dp+0), { LIT (-0x3.13198a2e03707348p-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { LIT (0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8fap-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { LIT (-0x8.d313198a2e03708p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { LIT (0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0xf.e00885042dd770dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770cp-4), ERRNO_UNCHANGED } },
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
    { "-0x6.e23688p+16", LIT (-0x6.e23688p+16), { LIT (-0x1.bf207c900d877cb8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x6.e2368c006c018228p+16", LIT (-0x6.e2368c006c018228p+16), { LIT (-0x1.feb6a361c0bb501cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x6.e2368c006c018p+16", LIT (-0x6.e2368c006c018p+16), { LIT (-0x1.feb6a3619e803c4ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c4ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c48p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x6.e2368c006c01cp+16", LIT (-0x6.e2368c006c01cp+16), { LIT (-0x1.feb6a36596828878p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596828878p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596828876p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596828876p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x6.e2369p+16", LIT (-0x6.e2369p+16), { LIT (-0x2.3e1f7a26f594337p-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594337p-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8.60a91c16b9b28p-4", LIT (-0x8.60a91c16b9b28p-4), { LIT (-0x7.ffffffffffffc6bp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8.60a91c16b9b2c23p-4", LIT (-0x8.60a91c16b9b2c23p-4), { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8.60a91c16b9b2c24p-4", LIT (-0x8.60a91c16b9b2c24p-4), { LIT (-0x8.000000000000001p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000001p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8.60a91c16b9b3p-4", LIT (-0x8.60a91c16b9b3p-4), { LIT (-0x8.000000000000359p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000358p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8.60a91p-4", LIT (-0x8.60a91p-4), { LIT (-0x7.fffff587e3a050dp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050dp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050c8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8.60a92p-4", LIT (-0x8.60a92p-4), { LIT (-0x8.000003632116886p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000003632116885p-4), ERRNO_UNCHANGED } },
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
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1.452fc98b34e96b62p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b62p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b6p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0xf.dfd9d4b6d0e5f7cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x8.599b32844aba906p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba907p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba906p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba907p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.2001469775ce6p+32", LIT (0x1.2001469775ce6p+32), { LIT (-0x6.444fda50019f9f6p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f58p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f58p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (0x4.220ff25f5cf02a4p-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a48p-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a4p-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.200148p+32", LIT (0x1.200148p+32), { LIT (-0x5.595d7e536fe35eep-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35ed8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35ed8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35ed8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xf.fa2adb8953ae262p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae262p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae262p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae263p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xf.fa2adcf9ea83dbdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbep-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xf.fa2add3e58948d1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb2ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.d12ed2p-12", LIT (0x1.d12ed2p-12), { LIT (0x1.d12ed0fffffdfe0ep-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe1p-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe0ep-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe1p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xd.76aa4784867702p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677021p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa4784867702p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677021p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+120", LIT (0x1p+120), { LIT (0x6.0b8d19579bf2db58p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db6p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db58p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0xf.c777c6b36a750a6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (-0xd.a29d5bb5f9cb87ep-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87dp-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87dp-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (-0x4.cd7e86c4077bf0ep-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0ep-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0d8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (-0xb.becc47ab1b8c708p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c708p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c707p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c707p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.553534p+0", LIT (0x2.553534p+0), { LIT (0xb.932584840806c6p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c61p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c6p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.5535376715b9ep+0", LIT (0x2.5535376715b9ep+0), { LIT (0xb.93255eeda103a17p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a18p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a17p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.5535376715b9fffcp+0", LIT (0x2.5535376715b9fffcp+0), { LIT (0xb.93255eeda102402p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102403p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102402p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102403p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.5535376715bap+0", LIT (0x2.5535376715bap+0), { LIT (0xb.93255eeda1024p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda1024p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda1024p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102401p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.553538p+0", LIT (0x2.553538p+0), { LIT (0xb.93255854754a36dp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36dp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36dp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xe.8c7b7568da22efdp-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efdp-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efdp-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+64", LIT (0x2p+64), { LIT (-0xc.143e153b0701e81p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (0x1.ffc6da9f1ffed894p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed896p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed894p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed896p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { LIT (0x2.8885a308d31063ep-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e4p-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063ep-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6a8885a308d4p+0", LIT (0x3.243f6a8885a308d4p+0), { LIT (-0xe.ce675d1fc8f8cbcp-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6a8885a308dp+0", LIT (0x3.243f6a8885a308dp+0), { LIT (0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707348p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { LIT (-0x1.72cece675d1fc8fap-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { LIT (0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03708p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { LIT (-0x1.777a5cf72cec5fd8p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.be735c19be9fep+0", LIT (0x3.be735c19be9fep+0), { LIT (-0x9.10bb11242ec81a2p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a2p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.be735c19be9ffffcp+0", LIT (0x3.be735c19be9ffffcp+0), { LIT (-0x9.10bb11242ec9bfdp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfdp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.be735c19beap+0", LIT (0x3.be735c19beap+0), { LIT (-0x9.10bb11242ec9c01p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.be735cp+0", LIT (0x3.be735cp+0), { LIT (-0x9.10bb0fd0c39d5ap-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d5ap-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59fp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.be736p+0", LIT (0x3.be736p+0), { LIT (-0x9.10bb448d3cb0167p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0167p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.ec2a0250032a0004p+0", LIT (0x3.ec2a0250032a0004p+0), { LIT (-0xb.4351eaad0983403p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983403p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.ec2a0250032a2p+0", LIT (0x3.ec2a0250032a2p+0), { LIT (-0xb.4351eaad0984abbp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984abap-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984abap-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984abap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.ec2a0250032ap+0", LIT (0x3.ec2a0250032ap+0), { LIT (-0xb.4351eaad09834p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09834p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833ffp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.ec2a04p+0", LIT (0x3.ec2a04p+0), { LIT (-0xb.4351fdda3d81514p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81514p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.ec2ap+0", LIT (0x3.ec2ap+0), { LIT (-0xb.4351d06546e7182p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x2.42070db6daab69ep-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e4p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69ep-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.093385688a2d1508p-4", LIT (0x4.093385688a2d1508p-4), { LIT (0x3.fe477dbdc795642cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795643p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795642cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795643p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.093385688a2d151p-4", LIT (0x4.093385688a2d151p-4), { LIT (0x3.fe477dbdc7956434p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956438p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956434p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956438p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.093385688a2d4p-4", LIT (0x4.093385688a2d4p-4), { LIT (0x3.fe477dbdc7958dc8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dccp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dc8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.093385688a2dp-4", LIT (0x4.093385688a2dp-4), { LIT (0x3.fe477dbdc7954fdp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd4p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fdp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.093388p-4", LIT (0x4.093388p-4), { LIT (0x3.fe4780403e8078c8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ccp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078c8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.09338p-4", LIT (0x4.09338p-4), { LIT (0x3.fe4778810e026fep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fe4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.1237e153f7080008p+0", LIT (0x4.1237e153f7080008p+0), { LIT (-0xc.d2635f3faf56c05p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c05p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.1237e153f7084p+0", LIT (0x4.1237e153f7084p+0), { LIT (-0xc.d2635f3faf59249p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59249p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.1237e153f708p+0", LIT (0x4.1237e153f708p+0), { LIT (-0xc.d2635f3faf56cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.1237e8p+0", LIT (0x4.1237e8p+0), { LIT (-0xc.d2639f1afc7f46ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f46ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f469p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f469p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.1237ep+0", LIT (0x4.1237ep+0), { LIT (-0xc.d2635289f074d2cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2bp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2bp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0x1.ffb679ba994b7618p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7618p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7616p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7616p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.c92d08p+0", LIT (0x4.c92d08p+0), { LIT (-0xf.f4f4736648dc2a1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.c92d0ffa4bf00008p+0", LIT (0x4.c92d0ffa4bf00008p+0), { LIT (-0xf.f4f46a082f284p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.c92d0ffa4bf04p+0", LIT (0x4.c92d0ffa4bf04p+0), { LIT (-0xf.f4f46a082f27f4ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.c92d0ffa4bfp+0", LIT (0x4.c92d0ffa4bfp+0), { LIT (-0xf.f4f46a082f28401p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f284p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f284p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f284p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.c92d1p+0", LIT (0x4.c92d1p+0), { LIT (-0xf.f4f46a017cb884p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb884p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xc.1bdceeee0f57387p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57386p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57386p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57386p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p+48", LIT (0x4p+48), { LIT (0x7.f13d78eabb76b8a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-128), ERRNO_UNCHANGED }, { LIT (0x4p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0x3.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x3.fffffffffffffff8p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x4p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_intel96)
    { "0x5.6a5005df43638338p+64", LIT (0x5.6a5005df43638338p+64), { LIT (-0xa.8640e82e7924ec1p-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ecp-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ecp-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.6a5005df4363833p+64", LIT (0x5.6a5005df4363833p+64), { LIT (0xd.7457bd2255e689fp-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689fp-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689fp-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e68ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.6a5005df43638p+64", LIT (0x5.6a5005df43638p+64), { LIT (0x2.f0e32ed649b32644p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b32644p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b32644p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b32648p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.6a5005df4363cp+64", LIT (0x5.6a5005df4363cp+64), { LIT (0x6.5ea3351c9d9da32p-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da32p-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da32p-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da328p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.6a5008p+64", LIT (0x5.6a5008p+64), { LIT (-0x1.4550689b93bbe142p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe14p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe14p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe14p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.6a5p+64", LIT (0x5.6a5p+64), { LIT (-0x1.ee01db6bc8ef288ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.fbec7477d4a80008p+0", LIT (0x5.fbec7477d4a80008p+0), { LIT (-0x4.b6f642a935a49f88p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f88p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.fbec7477d4a84p+0", LIT (0x5.fbec7477d4a84p+0), { LIT (-0x4.b6f642a935a0cd78p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd78p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd7p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.fbec7477d4a8p+0", LIT (0x5.fbec7477d4a8p+0), { LIT (-0x4.b6f642a935a4ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a4ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49ff8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49ff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.fbec78p+0", LIT (0x5.fbec78p+0), { LIT (-0x4.b6f60ca8d4150bc8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bcp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bcp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.fbec7p+0", LIT (0x5.fbec7p+0), { LIT (-0x4.b6f686f9ea12e8fp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8fp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8e8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5p+0", LIT (0x5p+0), { LIT (-0xf.57c0faf04c99914p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c99913p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c99913p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c99913p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { LIT (-0x1.fecb772e1b86f8e8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cc8749212e72p+0", LIT (0x6.287cc8749212e72p+0), { LIT (-0x1.fecb772e1b848bccp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bcap-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bcap-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bcap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { LIT (-0x1.fecb772e1b8300e6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { LIT (-0x1.fecb7e68ad6e9c4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { LIT (-0x1.fecaff6878a10ce6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6p+0", LIT (0x6p+0), { LIT (-0x4.787c62ac28b00eap-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e98p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e98p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xa.83046136850421dp-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421ep-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421dp-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { LIT (0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91c16b9b2c23p-4", LIT (0x8.60a91c16b9b2c23p-4), { LIT (0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91c16b9b2c24p-4", LIT (0x8.60a91c16b9b2c24p-4), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { LIT (0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000359p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { LIT (0x7.fffff587e3a050c8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050dp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050c8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { LIT (0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (0x8.000003632116886p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.d469501467bd74fp-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd75p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd74fp-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd75p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (0x9.0292465edbaff2dp-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2dp-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2dp-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+124", LIT (0x8p+124), { LIT (0x9.f963166f215eb89p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb8ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+16380", LIT (0x8p+16380), { LIT (0x6.3ad4b2136cc68818p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc6882p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc68818p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc6882p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x6.98098d830be4248p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42488p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be4248p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42488p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xap+0", LIT (0xap+0), { LIT (-0x8.b44f7af9a7a92cfp-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92cep-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92cep-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92cep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xb.fa09ap+100", LIT (0xb.fa09ap+100), { LIT (-0x1.1e7cf9ec10916c26p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c24p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c24p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c24p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { LIT (0xb.7fb5fe776978e72p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e72p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { LIT (0xb.7fb5fe776978e73p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e74p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.7fb5fe776978e56p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e56p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e56p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e57p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.7fb5fe7769793e6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.7fb5f50739fa5f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f9p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.7fb600275877a6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.e7fe0b5fc786b2dp-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2ep-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2dp-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0xf.dfffd7bde0fb4ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4edp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0x7.76d600e031521b78p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b78p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (0xc.773a2eac3000ddep-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddfp-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddep-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.ef3af1b5d800001p-4", LIT (0xe.ef3af1b5d800001p-4), { LIT (0xc.dbc19333ad3acp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac01p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3acp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.ef3af1b5d8008p-4", LIT (0xe.ef3af1b5d8008p-4), { LIT (0xc.dbc19333ad3b0c2p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c3p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c2p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.ef3af1b5d8p-4", LIT (0xe.ef3af1b5d8p-4), { LIT (0xc.dbc19333ad3abffp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3acp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.ef3afp-4", LIT (0xe.ef3afp-4), { LIT (0xc.dbc1922f1d9f2c7p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c7p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c7p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.ef3bp-4", LIT (0xe.ef3bp-4), { LIT (0xc.dbc19bb4a58a818p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a819p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a818p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a819p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0x8.3bee07bc9076425p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076425p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xc.6fa5c5665984d88p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d89p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d88p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d89p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.452fc98b34e96b6p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b62p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b6p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b62p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.dfd9d4b6d0e5f7bp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7cp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7bp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (-0x8.599b32844aba907p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba907p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0", LIT (-0x0p+0), { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED }, { LIT (-0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { LIT (-0xd.8f691a7a95426p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95426p-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffp-4), ERRNO_UNCHANGED }, { LIT (-0xd.8f691a7a95425ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fb4p+0", LIT (-0x1.921fb4p+0), { LIT (-0xf.fffffffffff32a4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fb54442d18468p+0", LIT (-0x1.921fb54442d18468p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fb54442d1846ap+0", LIT (-0x1.921fb54442d1846ap+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fb54442d18p+0", LIT (-0x1.921fb54442d18p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fb54442d19p+0", LIT (-0x1.921fb54442d19p+0), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.921fb6p+0", LIT (-0x1.921fb6p+0), { LIT (-0xf.fffffffffffbb2ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p+64", LIT (-0x2p+64), { LIT (0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (0xc.143e153b0701e81p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (-0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { LIT (-0x2.8885a308d31063e4p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063e4p-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063ep-24), ERRNO_UNCHANGED }, { LIT (-0x2.8885a308d31063ep-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6a8885a308d4p+0", LIT (-0x3.243f6a8885a308d4p+0), { LIT (0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (0xe.ce675d1fc8f8cbcp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6a8885a308dp+0", LIT (-0x3.243f6a8885a308dp+0), { LIT (-0x3.13198a2e03707348p-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (-0x3.13198a2e03707344p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { LIT (0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (0x1.72cece675d1fc8fap-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { LIT (-0x8.d313198a2e03708p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (-0x8.d313198a2e03707p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { LIT (0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (0x1.777a5cf72cec5fd8p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { LIT (-0xf.e00885042dd770dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.e00885042dd770cp-4), ERRNO_UNCHANGED } },
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
    { "-0x6.e23688p+16", LIT (-0x6.e23688p+16), { LIT (-0x1.bf207c900d877cb8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.bf207c900d877cb6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x6.e2368c006c018228p+16", LIT (-0x6.e2368c006c018228p+16), { LIT (-0x1.feb6a361c0bb501cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a361c0bb501ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x6.e2368c006c018p+16", LIT (-0x6.e2368c006c018p+16), { LIT (-0x1.feb6a3619e803c4ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c4ap-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c48p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a3619e803c48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x6.e2368c006c01cp+16", LIT (-0x6.e2368c006c01cp+16), { LIT (-0x1.feb6a36596828878p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596828878p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596828876p-4), ERRNO_UNCHANGED }, { LIT (-0x1.feb6a36596828876p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x6.e2369p+16", LIT (-0x6.e2369p+16), { LIT (-0x2.3e1f7a26f594337p-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594337p-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336cp-4), ERRNO_UNCHANGED }, { LIT (-0x2.3e1f7a26f594336cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8.60a91c16b9b28p-4", LIT (-0x8.60a91c16b9b28p-4), { LIT (-0x7.ffffffffffffc6bp-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8.60a91c16b9b2c23p-4", LIT (-0x8.60a91c16b9b2c23p-4), { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8.60a91c16b9b2c24p-4", LIT (-0x8.60a91c16b9b2c24p-4), { LIT (-0x8.000000000000001p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000001p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED }, { LIT (-0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8.60a91c16b9b3p-4", LIT (-0x8.60a91c16b9b3p-4), { LIT (-0x8.000000000000359p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000000000000358p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8.60a91p-4", LIT (-0x8.60a91p-4), { LIT (-0x7.fffff587e3a050dp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050dp-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050c8p-4), ERRNO_UNCHANGED }, { LIT (-0x7.fffff587e3a050c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8.60a92p-4", LIT (-0x8.60a92p-4), { LIT (-0x8.000003632116886p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (-0x8.000003632116885p-4), ERRNO_UNCHANGED } },
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
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (-0x1.452fc98b34e96b62p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b62p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b6p-8), ERRNO_UNCHANGED }, { LIT (-0x1.452fc98b34e96b6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (-0xf.dfd9d4b6d0e5f7cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7bp-4), ERRNO_UNCHANGED }, { LIT (-0xf.dfd9d4b6d0e5f7bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x8.599b32844aba906p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba907p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba906p-4), ERRNO_UNCHANGED }, { LIT (0x8.599b32844aba907p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0", LIT (0x0p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.2001469775ce6p+32", LIT (0x1.2001469775ce6p+32), { LIT (-0x6.444fda50019f9f6p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f58p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f58p-4), ERRNO_UNCHANGED }, { LIT (-0x6.444fda50019f9f58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.200146p+32", LIT (0x1.200146p+32), { LIT (0x4.220ff25f5cf02a4p-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a48p-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a4p-4), ERRNO_UNCHANGED }, { LIT (0x4.220ff25f5cf02a48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.200148p+32", LIT (0x1.200148p+32), { LIT (-0x5.595d7e536fe35eep-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35ed8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35ed8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.595d7e536fe35ed8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { LIT (0xf.fa2adb8953ae262p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae262p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae262p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adb8953ae263p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { LIT (0xf.fa2adcf9ea83dbdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbep-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2adcf9ea83dbep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { LIT (0xf.fa2add3e58948d1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d1p-4), ERRNO_UNCHANGED }, { LIT (0xf.fa2add3e58948d2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { LIT (0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff32a4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { LIT (0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb29p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbb2ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.d12ed2p-12", LIT (0x1.d12ed2p-12), { LIT (0x1.d12ed0fffffdfe0ep-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe1p-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe0ep-12), ERRNO_UNCHANGED }, { LIT (0x1.d12ed0fffffdfe1p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0xd.76aa4784867702p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677021p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa4784867702p-4), ERRNO_UNCHANGED }, { LIT (0xd.76aa47848677021p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+120", LIT (0x1p+120), { LIT (0x6.0b8d19579bf2db58p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db6p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db58p-4), ERRNO_UNCHANGED }, { LIT (0x6.0b8d19579bf2db6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+28", LIT (0x1p+28), { LIT (-0xf.c777c6b36a750a6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a6p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.c777c6b36a750a5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { LIT (-0xd.a29d5bb5f9cb87ep-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87dp-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87dp-4), ERRNO_UNCHANGED }, { LIT (-0xd.a29d5bb5f9cb87dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { LIT (-0x4.cd7e86c4077bf0ep-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0ep-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0d8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.cd7e86c4077bf0d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { LIT (-0xb.becc47ab1b8c708p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c708p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c707p-4), ERRNO_UNCHANGED }, { LIT (-0xb.becc47ab1b8c707p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.553534p+0", LIT (0x2.553534p+0), { LIT (0xb.932584840806c6p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c61p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c6p-4), ERRNO_UNCHANGED }, { LIT (0xb.932584840806c61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.5535376715b9ep+0", LIT (0x2.5535376715b9ep+0), { LIT (0xb.93255eeda103a17p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a18p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a17p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda103a18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.5535376715b9fffcp+0", LIT (0x2.5535376715b9fffcp+0), { LIT (0xb.93255eeda102402p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102403p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102402p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102403p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.5535376715bap+0", LIT (0x2.5535376715bap+0), { LIT (0xb.93255eeda1024p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda1024p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda1024p-4), ERRNO_UNCHANGED }, { LIT (0xb.93255eeda102401p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.553538p+0", LIT (0x2.553538p+0), { LIT (0xb.93255854754a36dp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36dp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36dp-4), ERRNO_UNCHANGED }, { LIT (0xb.93255854754a36ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xe.8c7b7568da22efdp-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efdp-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efdp-4), ERRNO_UNCHANGED }, { LIT (0xe.8c7b7568da22efep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+64", LIT (0x2p+64), { LIT (-0xc.143e153b0701e81p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e8p-8), ERRNO_UNCHANGED }, { LIT (-0xc.143e153b0701e8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x1.fffffffffffffffcp-16384), UNDERFLOW_EXCEPTION_OK }, { LIT (0x2p-16384), UNDERFLOW_EXCEPTION_OK } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { LIT (0x1.ffc6da9f1ffed894p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed896p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed894p-4), ERRNO_UNCHANGED }, { LIT (0x1.ffc6da9f1ffed896p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { LIT (0x2.8885a308d31063ep-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e4p-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063ep-24), ERRNO_UNCHANGED }, { LIT (0x2.8885a308d31063e4p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6a8885a308d4p+0", LIT (0x3.243f6a8885a308d4p+0), { LIT (-0xe.ce675d1fc8f8cbcp-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED }, { LIT (-0xe.ce675d1fc8f8cbbp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6a8885a308dp+0", LIT (0x3.243f6a8885a308dp+0), { LIT (0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707344p-64), ERRNO_UNCHANGED }, { LIT (0x3.13198a2e03707348p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { LIT (-0x1.72cece675d1fc8fap-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED }, { LIT (-0x1.72cece675d1fc8f8p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { LIT (0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03707p-56), ERRNO_UNCHANGED }, { LIT (0x8.d313198a2e03708p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { LIT (-0x1.777a5cf72cec5fd8p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED }, { LIT (-0x1.777a5cf72cec5fd6p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.be735c19be9fep+0", LIT (0x3.be735c19be9fep+0), { LIT (-0x9.10bb11242ec81a2p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a2p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec81a1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.be735c19be9ffffcp+0", LIT (0x3.be735c19be9ffffcp+0), { LIT (-0x9.10bb11242ec9bfdp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfdp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9bfcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.be735c19beap+0", LIT (0x3.be735c19beap+0), { LIT (-0x9.10bb11242ec9c01p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9cp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb11242ec9cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.be735cp+0", LIT (0x3.be735cp+0), { LIT (-0x9.10bb0fd0c39d5ap-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d5ap-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59fp-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb0fd0c39d59fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.be736p+0", LIT (0x3.be736p+0), { LIT (-0x9.10bb448d3cb0167p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0167p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166p-4), ERRNO_UNCHANGED }, { LIT (-0x9.10bb448d3cb0166p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.ec2a0250032a0004p+0", LIT (0x3.ec2a0250032a0004p+0), { LIT (-0xb.4351eaad0983403p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983403p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0983402p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.ec2a0250032a2p+0", LIT (0x3.ec2a0250032a2p+0), { LIT (-0xb.4351eaad0984abbp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984abap-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984abap-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad0984abap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.ec2a0250032ap+0", LIT (0x3.ec2a0250032ap+0), { LIT (-0xb.4351eaad09834p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09834p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833ffp-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351eaad09833ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.ec2a04p+0", LIT (0x3.ec2a04p+0), { LIT (-0xb.4351fdda3d81514p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81514p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351fdda3d81513p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.ec2ap+0", LIT (0x3.ec2ap+0), { LIT (-0xb.4351d06546e7182p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181p-4), ERRNO_UNCHANGED }, { LIT (-0xb.4351d06546e7181p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x2.42070db6daab69ep-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e4p-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69ep-4), ERRNO_UNCHANGED }, { LIT (0x2.42070db6daab69e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.093385688a2d1508p-4", LIT (0x4.093385688a2d1508p-4), { LIT (0x3.fe477dbdc795642cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795643p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795642cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc795643p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.093385688a2d151p-4", LIT (0x4.093385688a2d151p-4), { LIT (0x3.fe477dbdc7956434p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956438p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956434p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7956438p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.093385688a2d4p-4", LIT (0x4.093385688a2d4p-4), { LIT (0x3.fe477dbdc7958dc8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dccp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dc8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7958dccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.093385688a2dp-4", LIT (0x4.093385688a2dp-4), { LIT (0x3.fe477dbdc7954fdp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd4p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fdp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe477dbdc7954fd4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.093388p-4", LIT (0x4.093388p-4), { LIT (0x3.fe4780403e8078c8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ccp-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078c8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4780403e8078ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.09338p-4", LIT (0x4.09338p-4), { LIT (0x3.fe4778810e026fep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fep-4), ERRNO_UNCHANGED }, { LIT (0x3.fe4778810e026fe4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.1237e153f7080008p+0", LIT (0x4.1237e153f7080008p+0), { LIT (-0xc.d2635f3faf56c05p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c05p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56c04p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.1237e153f7084p+0", LIT (0x4.1237e153f7084p+0), { LIT (-0xc.d2635f3faf59249p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59249p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf59248p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.1237e153f708p+0", LIT (0x4.1237e153f708p+0), { LIT (-0xc.d2635f3faf56cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635f3faf56bffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.1237e8p+0", LIT (0x4.1237e8p+0), { LIT (-0xc.d2639f1afc7f46ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f46ap-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f469p-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2639f1afc7f469p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.1237ep+0", LIT (0x4.1237ep+0), { LIT (-0xc.d2635289f074d2cp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2bp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2bp-4), ERRNO_UNCHANGED }, { LIT (-0xc.d2635289f074d2bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { LIT (-0x1.ffb679ba994b7618p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7618p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7616p-4), ERRNO_UNCHANGED }, { LIT (-0x1.ffb679ba994b7616p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.c92d08p+0", LIT (0x4.c92d08p+0), { LIT (-0xf.f4f4736648dc2a1p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2ap-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f4736648dc2ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.c92d0ffa4bf00008p+0", LIT (0x4.c92d0ffa4bf00008p+0), { LIT (-0xf.f4f46a082f284p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f283ffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.c92d0ffa4bf04p+0", LIT (0x4.c92d0ffa4bf04p+0), { LIT (-0xf.f4f46a082f27f4ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4ep-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4dp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f27f4dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.c92d0ffa4bfp+0", LIT (0x4.c92d0ffa4bfp+0), { LIT (-0xf.f4f46a082f28401p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f284p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f284p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a082f284p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.c92d1p+0", LIT (0x4.c92d1p+0), { LIT (-0xf.f4f46a017cb884p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb884p-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883fp-4), ERRNO_UNCHANGED }, { LIT (-0xf.f4f46a017cb883fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p+0", LIT (0x4p+0), { LIT (-0xc.1bdceeee0f57387p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57386p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57386p-4), ERRNO_UNCHANGED }, { LIT (-0xc.1bdceeee0f57386p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p+48", LIT (0x4p+48), { LIT (0x7.f13d78eabb76b8a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.f13d78eabb76b8bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1024), ERRNO_UNCHANGED }, { LIT (0x4p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffffffcp-1076), ERRNO_UNCHANGED }, { LIT (0x4p-1076), ERRNO_UNCHANGED } },
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
    { "0x5.6a5005df43638338p+64", LIT (0x5.6a5005df43638338p+64), { LIT (-0xa.8640e82e7924ec1p-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ecp-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ecp-4), ERRNO_UNCHANGED }, { LIT (-0xa.8640e82e7924ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.6a5005df4363833p+64", LIT (0x5.6a5005df4363833p+64), { LIT (0xd.7457bd2255e689fp-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689fp-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e689fp-4), ERRNO_UNCHANGED }, { LIT (0xd.7457bd2255e68ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.6a5005df43638p+64", LIT (0x5.6a5005df43638p+64), { LIT (0x2.f0e32ed649b32644p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b32644p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b32644p-4), ERRNO_UNCHANGED }, { LIT (0x2.f0e32ed649b32648p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.6a5005df4363cp+64", LIT (0x5.6a5005df4363cp+64), { LIT (0x6.5ea3351c9d9da32p-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da32p-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da32p-4), ERRNO_UNCHANGED }, { LIT (0x6.5ea3351c9d9da328p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.6a5008p+64", LIT (0x5.6a5008p+64), { LIT (-0x1.4550689b93bbe142p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe14p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe14p-4), ERRNO_UNCHANGED }, { LIT (-0x1.4550689b93bbe14p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.6a5p+64", LIT (0x5.6a5p+64), { LIT (-0x1.ee01db6bc8ef288ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.ee01db6bc8ef288cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.fbec7477d4a80008p+0", LIT (0x5.fbec7477d4a80008p+0), { LIT (-0x4.b6f642a935a49f88p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f88p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.fbec7477d4a84p+0", LIT (0x5.fbec7477d4a84p+0), { LIT (-0x4.b6f642a935a0cd78p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd78p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd7p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a0cd7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.fbec7477d4a8p+0", LIT (0x5.fbec7477d4a8p+0), { LIT (-0x4.b6f642a935a4ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a4ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49ff8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f642a935a49ff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.fbec78p+0", LIT (0x5.fbec78p+0), { LIT (-0x4.b6f60ca8d4150bc8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bcp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bcp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f60ca8d4150bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.fbec7p+0", LIT (0x5.fbec7p+0), { LIT (-0x4.b6f686f9ea12e8fp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8fp-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8e8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.b6f686f9ea12e8e8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5p+0", LIT (0x5p+0), { LIT (-0xf.57c0faf04c99914p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c99913p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c99913p-4), ERRNO_UNCHANGED }, { LIT (-0xf.57c0faf04c99913p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { LIT (-0x1.fecb772e1b86f8e8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b86f8e6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cc8749212e72p+0", LIT (0x6.287cc8749212e72p+0), { LIT (-0x1.fecb772e1b848bccp-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bcap-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bcap-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b848bcap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { LIT (-0x1.fecb772e1b8300e6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb772e1b8300e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { LIT (-0x1.fecb7e68ad6e9c4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecb7e68ad6e9c3ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { LIT (-0x1.fecaff6878a10ce6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.fecaff6878a10ce4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6p+0", LIT (0x6p+0), { LIT (-0x4.787c62ac28b00eap-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e98p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e98p-4), ERRNO_UNCHANGED }, { LIT (-0x4.787c62ac28b00e98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7p+0", LIT (0x7p+0), { LIT (0xa.83046136850421dp-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421ep-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421dp-4), ERRNO_UNCHANGED }, { LIT (0xa.83046136850421ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { LIT (0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6a8p-4), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffc6bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91c16b9b2c23p-4", LIT (0x8.60a91c16b9b2c23p-4), { LIT (0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91c16b9b2c24p-4", LIT (0x8.60a91c16b9b2c24p-4), { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-4), ERRNO_UNCHANGED }, { LIT (0x8p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000001p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { LIT (0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000358p-4), ERRNO_UNCHANGED }, { LIT (0x8.000000000000359p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { LIT (0x7.fffff587e3a050c8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050dp-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050c8p-4), ERRNO_UNCHANGED }, { LIT (0x7.fffff587e3a050dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { LIT (0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (0x8.000003632116885p-4), ERRNO_UNCHANGED }, { LIT (0x8.000003632116886p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xf.d469501467bd74fp-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd75p-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd74fp-4), ERRNO_UNCHANGED }, { LIT (0xf.d469501467bd75p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+1020", LIT (0x8p+1020), { LIT (0x9.0292465edbaff2dp-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2dp-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2dp-4), ERRNO_UNCHANGED }, { LIT (0x9.0292465edbaff2ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+124", LIT (0x8p+124), { LIT (0x9.f963166f215eb89p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb89p-4), ERRNO_UNCHANGED }, { LIT (0x9.f963166f215eb8ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+16380", LIT (0x8p+16380), { LIT (0x6.3ad4b2136cc68818p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc6882p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc68818p-4), ERRNO_UNCHANGED }, { LIT (0x6.3ad4b2136cc6882p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-152), ERRNO_UNCHANGED }, { LIT (0x8p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffff8p-972), ERRNO_UNCHANGED }, { LIT (0x8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x6.98098d830be4248p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42488p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be4248p-4), ERRNO_UNCHANGED }, { LIT (0x6.98098d830be42488p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xap+0", LIT (0xap+0), { LIT (-0x8.b44f7af9a7a92cfp-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92cep-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92cep-4), ERRNO_UNCHANGED }, { LIT (-0x8.b44f7af9a7a92cep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xb.fa09ap+100", LIT (0xb.fa09ap+100), { LIT (-0x1.1e7cf9ec10916c26p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c24p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c24p-24), ERRNO_UNCHANGED }, { LIT (-0x1.1e7cf9ec10916c24p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { LIT (0xb.7fb5fe776978e72p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e72p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { LIT (0xb.7fb5fe776978e73p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e74p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e73p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e74p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { LIT (0xb.7fb5fe776978e56p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e56p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e56p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe776978e57p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { LIT (0xb.7fb5fe7769793e6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5fe7769793e7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { LIT (0xb.7fb5f50739fa5f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f9p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f8p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb5f50739fa5f9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { LIT (0xb.7fb600275877a6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a6p-4), ERRNO_UNCHANGED }, { LIT (0xb.7fb600275877a61p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0xa.e7fe0b5fc786b2dp-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2ep-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2dp-4), ERRNO_UNCHANGED }, { LIT (0xa.e7fe0b5fc786b2ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { LIT (0xf.dfffd7bde0fb4ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4ecp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfffd7bde0fb4edp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { LIT (0x7.76d600e031521b78p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b8p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b78p-4), ERRNO_UNCHANGED }, { LIT (0x7.76d600e031521b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { LIT (0xc.773a2eac3000ddep-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddfp-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddep-4), ERRNO_UNCHANGED }, { LIT (0xc.773a2eac3000ddfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.ef3af1b5d800001p-4", LIT (0xe.ef3af1b5d800001p-4), { LIT (0xc.dbc19333ad3acp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac01p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3acp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3ac01p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.ef3af1b5d8008p-4", LIT (0xe.ef3af1b5d8008p-4), { LIT (0xc.dbc19333ad3b0c2p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c3p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c2p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3b0c3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.ef3af1b5d8p-4", LIT (0xe.ef3af1b5d8p-4), { LIT (0xc.dbc19333ad3abffp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3acp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3abffp-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19333ad3acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.ef3afp-4", LIT (0xe.ef3afp-4), { LIT (0xc.dbc1922f1d9f2c7p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c7p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c7p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc1922f1d9f2c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.ef3bp-4", LIT (0xe.ef3bp-4), { LIT (0xc.dbc19bb4a58a818p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a819p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a818p-4), ERRNO_UNCHANGED }, { LIT (0xc.dbc19bb4a58a819p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { LIT (-0x8.3bee07bc9076425p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076425p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424p-4), ERRNO_UNCHANGED }, { LIT (-0x8.3bee07bc9076424p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { LIT (0xc.6fa5c5665984d88p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d89p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d88p-8), ERRNO_UNCHANGED }, { LIT (0xc.6fa5c5665984d89p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x1.452fc98b34e96b6p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b62p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b6p-8), ERRNO_UNCHANGED }, { LIT (0x1.452fc98b34e96b62p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0xf.dfd9d4b6d0e5f7bp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7cp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7bp-4), ERRNO_UNCHANGED }, { LIT (0xf.dfd9d4b6d0e5f7cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (-0x8.599b32844aba907p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba907p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906p-4), ERRNO_UNCHANGED }, { LIT (-0x8.599b32844aba906p-4), ERRNO_UNCHANGED } },
#endif
  };

static void
sin_test (void)
{
  ALL_RM_TEST (sin, 0, sin_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  sin_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

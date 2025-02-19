/* Test sincos.
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

static const struct test_fFF_11_data sincos_test_data[] =
  {
    { "inf", plus_infty, { INVALID_EXCEPTION|ERRNO_EDOM, 1, qnan_value, 1, qnan_value }, { INVALID_EXCEPTION|ERRNO_EDOM, 1, qnan_value, 1, qnan_value }, { INVALID_EXCEPTION|ERRNO_EDOM, 1, qnan_value, 1, qnan_value }, { INVALID_EXCEPTION|ERRNO_EDOM, 1, qnan_value, 1, qnan_value } },
    { "-inf", minus_infty, { INVALID_EXCEPTION|ERRNO_EDOM, 1, qnan_value, 1, qnan_value }, { INVALID_EXCEPTION|ERRNO_EDOM, 1, qnan_value, 1, qnan_value }, { INVALID_EXCEPTION|ERRNO_EDOM, 1, qnan_value, 1, qnan_value }, { INVALID_EXCEPTION|ERRNO_EDOM, 1, qnan_value, 1, qnan_value } },
    { "qNaN", qnan_value, { NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, qnan_value, 1, qnan_value }, { NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, qnan_value, 1, qnan_value }, { NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, qnan_value, 1, qnan_value }, { NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, qnan_value, 1, qnan_value } },
    { "-qNaN", -qnan_value, { NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, qnan_value, 1, qnan_value }, { NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, qnan_value, 1, qnan_value }, { NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, qnan_value, 1, qnan_value }, { NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED, 1, qnan_value, 1, qnan_value } },
    { "sNaN", snan_value, { TEST_SNAN|INVALID_EXCEPTION, 1, qnan_value, 1, qnan_value }, { TEST_SNAN|INVALID_EXCEPTION, 1, qnan_value, 1, qnan_value }, { TEST_SNAN|INVALID_EXCEPTION, 1, qnan_value, 1, qnan_value }, { TEST_SNAN|INVALID_EXCEPTION, 1, qnan_value, 1, qnan_value } },
    { "-sNaN", -snan_value, { TEST_SNAN|INVALID_EXCEPTION, 1, qnan_value, 1, qnan_value }, { TEST_SNAN|INVALID_EXCEPTION, 1, qnan_value, 1, qnan_value }, { TEST_SNAN|INVALID_EXCEPTION, 1, qnan_value, 1, qnan_value }, { TEST_SNAN|INVALID_EXCEPTION, 1, qnan_value, 1, qnan_value } },

#if (TEST_COND_binary128)
    { "-0", LIT (-0x0p+0), { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffcb89dc2b97cep-4), 1, LIT (0x8.7e0ea4db2f488671c85df720896p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffcb89dc2b97cep-4), 1, LIT (0x8.7e0ea4db2f488671c85df7208968p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffcb89dc2b97cd8p-4), 1, LIT (0x8.7e0ea4db2f488671c85df720896p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffcb89dc2b97cd8p-4), 1, LIT (0x8.7e0ea4db2f488671c85df7208968p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p+64", LIT (-0x2p+64), { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e800f9b8a47b75bp-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc897p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e800f9b8a47b75b8p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc897p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e800f9b8a47b75bp-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc897p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e800f9b8a47b75b8p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc8978p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p-16384", LIT (-0x2p-16384), { UNDERFLOW_EXCEPTION, 1, LIT (-0x2p-16384), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x2p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x1.fffffffffffffffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x1.fffffffffffffffffffffffffffcp-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e2b6c62b7f4d6cp-24), 1, LIT (-0xf.ffffffffffcca8d9870423997308p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e2b6c62b7f4d6cp-24), 1, LIT (-0xf.ffffffffffcca8d9870423997308p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e2b6c62b7f4d6ap-24), 1, LIT (-0xf.ffffffffffcca8d98704239973p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e2b6c62b7f4d6ap-24), 1, LIT (-0xf.ffffffffffcca8d98704239973p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d313198a2e0372p+0", LIT (-0x3.243f6a8885a308d313198a2e0372p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.8cbb5bf6c7ddd660ce2ff7d10568p-112), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d313198a2e037p+0", LIT (-0x3.243f6a8885a308d313198a2e037p+0), { ERRNO_UNCHANGED, 1, LIT (-0x7.344a4093822299f31d0082efa99p-116), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.344a4093822299f31d0082efa99p-116), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.344a4093822299f31d0082efa98cp-116), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.344a4093822299f31d0082efa98cp-116), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d313198a2e03p+0", LIT (-0x3.243f6a8885a308d313198a2e03p+0), { ERRNO_UNCHANGED, 1, LIT (-0x7.07344a4093822299f31d0082efacp-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.07344a4093822299f31d0082efa8p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.07344a4093822299f31d0082efa8p-108), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.07344a4093822299f31d0082efa8p-108), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d313198a2e04p+0", LIT (-0x3.243f6a8885a308d313198a2e04p+0), { ERRNO_UNCHANGED, 1, LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d105p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1058p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d105p-108), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1058p-108), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308d4p+0", LIT (-0x3.243f6a8885a308d4p+0), { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd6608p-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd661p-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd6608p-68), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd661p-68), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a308dp+0", LIT (-0x3.243f6a8885a308dp+0), { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344a409382229ap-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344a409382229ap-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344a4093822299ep-64), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344a4093822299ep-64), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8cbb5bf6c7d5bp-52), 1, LIT (-0xf.ffffffffffffffffffffffffef38p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8cbb5bf6c7d5cp-52), 1, LIT (-0xf.ffffffffffffffffffffffffef38p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8cbb5bf6c7d5bp-52), 1, LIT (-0xf.ffffffffffffffffffffffffef3p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8cbb5bf6c7d5cp-52), 1, LIT (-0xf.ffffffffffffffffffffffffef3p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707344a4093821b8p-56), 1, LIT (-0xf.fffffffffffffffffffffffffd98p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707344a4093821b8p-56), 1, LIT (-0xf.fffffffffffffffffffffffffd9p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707344a4093821bp-56), 1, LIT (-0xf.fffffffffffffffffffffffffd9p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707344a4093821bp-56), 1, LIT (-0xf.fffffffffffffffffffffffffd9p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd61896cb4f40d1p-24), 1, LIT (-0xf.ffffffffffeeca424938e847768p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd61896cb4f40d2p-24), 1, LIT (-0xf.ffffffffffeeca424938e8477678p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd61896cb4f40d1p-24), 1, LIT (-0xf.ffffffffffeeca424938e8477678p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd61896cb4f40d2p-24), 1, LIT (-0xf.ffffffffffeeca424938e8477678p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770c93962abdb61f8p-4), 1, LIT (-0x1.febbf9949ecc133623bb8c8c5a28p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770c93962abdb61f8p-4), 1, LIT (-0x1.febbf9949ecc133623bb8c8c5a27p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770c93962abdb61fp-4), 1, LIT (-0x1.febbf9949ecc133623bb8c8c5a27p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770c93962abdb61fp-4), 1, LIT (-0x1.febbf9949ecc133623bb8c8c5a27p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1024", LIT (-0x4p-1024), { ERRNO_UNCHANGED, 1, LIT (-0x4p-1024), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-1024), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffffffffffffffep-1024), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffffffffffffffep-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076", LIT (-0x4p-1076), { ERRNO_UNCHANGED, 1, LIT (-0x4p-1076), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-1076), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffffffffffffffep-1076), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffffffffffffffep-1076), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-128", LIT (-0x4p-128), { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffffffffffffffep-128), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffffffffffffffep-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384", LIT (-0x4p-16384), { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x4p-16384), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x4p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x3.fffffffffffffffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x3.fffffffffffffffffffffffffffcp-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16448", LIT (-0x4p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-16448), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x3.fffffffffffcp-16448), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x3.fffffffffffcp-16448), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16496", LIT (-0x4p-16496), { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-16496), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-16496), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152", LIT (-0x8p-152), { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffffffffffffffffcp-152), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffffffffffffffffcp-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-16448", LIT (-0x8p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (-0x8p-16448), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x8p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x7.fffffffffffcp-16448), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x7.fffffffffffcp-16448), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-972", LIT (-0x8p-972), { ERRNO_UNCHANGED, 1, LIT (-0x8p-972), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-972), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffffffffffffffffcp-972), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffffffffffffffffcp-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b61139b09a7c84bp-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f138p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b61139b09a7c84ap-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f138p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b61139b09a7c84ap-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f13p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b61139b09a7c84ap-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f13p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { ERRNO_UNCHANGED, 1, LIT (0xe.f1a3e1dc468a921dddb4e37fbe6p-4), 1, LIT (-0x5.b773d971a848e75c230605526978p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.f1a3e1dc468a921dddb4e37fbe6p-4), 1, LIT (-0x5.b773d971a848e75c230605526978p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.f1a3e1dc468a921dddb4e37fbe6p-4), 1, LIT (-0x5.b773d971a848e75c230605526974p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.f1a3e1dc468a921dddb4e37fbe68p-4), 1, LIT (-0x5.b773d971a848e75c230605526974p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffffffffffffff8p+16380", LIT (-0xf.fffffffffffffffffffffffffff8p+16380), { ERRNO_UNCHANGED, 1, LIT (-0xf.3b0b11ed85b7fe43d110251580b8p-4), 1, LIT (-0x4.e6dc95fb529bc365f472e4fbc1f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.3b0b11ed85b7fe43d110251580b8p-4), 1, LIT (-0x4.e6dc95fb529bc365f472e4fbc1f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.3b0b11ed85b7fe43d110251580bp-4), 1, LIT (-0x4.e6dc95fb529bc365f472e4fbc1f4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.3b0b11ed85b7fe43d110251580bp-4), 1, LIT (-0x4.e6dc95fb529bc365f472e4fbc1f4p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7b9650cab0f544p-4), 1, LIT (-0x2.002ef4018753d50b7a7f6bc3f5bap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), 1, LIT (-0x2.002ef4018753d50b7a7f6bc3f5bap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), 1, LIT (-0x2.002ef4018753d50b7a7f6bc3f5b8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), 1, LIT (-0x2.002ef4018753d50b7a7f6bc3f5b8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906cee446be04998p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906cee446be04998p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906cee446be04998p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906cee446be049ap-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb2f8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "+0", LIT (0x0p+0), { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5be750863ea3d58p-4), 1, LIT (0x8.000014f038b1ab0e902f68119158p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5be750863ea3d58p-4), 1, LIT (0x8.000014f038b1ab0e902f6811916p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5be750863ea3d58p-4), 1, LIT (0x8.000014f038b1ab0e902f68119158p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5be750863ea3d6p-4), 1, LIT (0x8.000014f038b1ab0e902f6811916p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d73658465bb32e0f567ap+0", LIT (0x1.0c152382d73658465bb32e0f567ap+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5b8p-4), 1, LIT (0x8.0000000000000000000000000008p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5b8p-4), 1, LIT (0x8.0000000000000000000000000008p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5b8p-4), 1, LIT (0x8.0000000000000000000000000008p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4), 1, LIT (0x8.000000000000000000000000001p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d73658465bb32e0f567bp+0", LIT (0x1.0c152382d73658465bb32e0f567bp+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4), 1, LIT (0x7.fffffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4), 1, LIT (0x7.fffffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4), 1, LIT (0x7.fffffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5c8p-4), 1, LIT (0x8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d73658465bb32e0f568p+0", LIT (0x1.0c152382d73658465bb32e0f568p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5e8p-4), 1, LIT (0x7.ffffffffffffffffffffffffffb8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5e8p-4), 1, LIT (0x7.ffffffffffffffffffffffffffb8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5e8p-4), 1, LIT (0x7.ffffffffffffffffffffffffffb8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c5fp-4), 1, LIT (0x7.ffffffffffffffffffffffffffbcp-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d73658465bb32e0f56p+0", LIT (0x1.0c152382d73658465bb32e0f56p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c1e8p-4), 1, LIT (0x8.00000000000000000000000006ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c1e8p-4), 1, LIT (0x8.00000000000000000000000006a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c1e8p-4), 1, LIT (0x8.00000000000000000000000006ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c1fp-4), 1, LIT (0x8.00000000000000000000000006a8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d7365846p+0", LIT (0x1.0c152382d7365846p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d64e07fb0911e8p-4), 1, LIT (0x8.0000000000000004f6a1a27d7e4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d64e07fb0911e8p-4), 1, LIT (0x8.0000000000000004f6a1a27d7e48p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d64e07fb0911e8p-4), 1, LIT (0x8.0000000000000004f6a1a27d7e4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d64e07fb0911fp-4), 1, LIT (0x8.0000000000000004f6a1a27d7e48p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d7365848p+0", LIT (0x1.0c152382d7365848p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539e64e07fb0911e8p-4), 1, LIT (0x7.ffffffffffffffe94026ba253198p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539e64e07fb0911e8p-4), 1, LIT (0x7.ffffffffffffffe94026ba25319cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539e64e07fb0911e8p-4), 1, LIT (0x7.ffffffffffffffe94026ba253198p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539e64e07fb0911fp-4), 1, LIT (0x7.ffffffffffffffe94026ba25319cp-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7a64e07fb09101p-4), 1, LIT (0x8.00000000000072a8d510c7c2a248p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7a64e07fb09101p-4), 1, LIT (0x8.00000000000072a8d510c7c2a25p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7a64e07fb09101p-4), 1, LIT (0x8.00000000000072a8d510c7c2a248p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7a64e07fb091018p-4), 1, LIT (0x8.00000000000072a8d510c7c2a25p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577a64e07fb091048p-4), 1, LIT (0x7.ffffffffffff94f4fdce055d4ed4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577a64e07fb09105p-4), 1, LIT (0x7.ffffffffffff94f4fdce055d4ed4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577a64e07fb091048p-4), 1, LIT (0x7.ffffffffffff94f4fdce055d4ed4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577a64e07fb09105p-4), 1, LIT (0x7.ffffffffffff94f4fdce055d4ed8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfb4fd88fd27f7d8p-4), 1, LIT (0x7.fffff939bdd18035537d20fef1bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfb4fd88fd27f7ep-4), 1, LIT (0x7.fffff939bdd18035537d20fef1b4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfb4fd88fd27f7d8p-4), 1, LIT (0x7.fffff939bdd18035537d20fef1bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfb4fd88fd27f7ep-4), 1, LIT (0x7.fffff939bdd18035537d20fef1b4p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae26229c919ec8f6b8p-4), 1, LIT (0xd.a82832da19f9891d9762fa659ff8p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae26229c919ec8f6cp-4), 1, LIT (0xd.a82832da19f9891d9762fa659ff8p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae26229c919ec8f6b8p-4), 1, LIT (0xd.a82832da19f9891d9762fa659ff8p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae26229c919ec8f6cp-4), 1, LIT (0xd.a82832da19f9891d9762fa65ap-8) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdd053ee455ea68p-4), 1, LIT (0xd.a82683a33cbebfffffffa2966878p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdd053ee455ea7p-4), 1, LIT (0xd.a82683a33cbebfffffffa2966878p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdd053ee455ea68p-4), 1, LIT (0xd.a82683a33cbebfffffffa2966878p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdd053ee455ea7p-4), 1, LIT (0xd.a82683a33cbebfffffffa296688p-8) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d10238cc27b5618p-4), 1, LIT (0xd.a8263394be6d0e58c1c35a8a3bap-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d10238cc27b562p-4), 1, LIT (0xd.a8263394be6d0e58c1c35a8a3bap-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d10238cc27b5618p-4), 1, LIT (0xd.a8263394be6d0e58c1c35a8a3bap-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d10238cc27b562p-4), 1, LIT (0xd.a8263394be6d0e58c1c35a8a3ba8p-8) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3661c108e136dp-4), 1, LIT (0x1.4442d18469893610281a0f9b0e8dp-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3661c108e136d8p-4), 1, LIT (0x1.4442d18469893610281a0f9b0e8dp-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3661c108e136dp-4), 1, LIT (0x1.4442d18469893610281a0f9b0e8dp-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3661c108e136d8p-4), 1, LIT (0x1.4442d18469893610281a0f9b0e8ep-24) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (0x1.898cc51701b839a252049c1114cfp-64) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.898cc51701b839a252049c1114dp-64) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (0x1.898cc51701b839a252049c1114cfp-64) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.898cc51701b839a252049c1114dp-64) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc517018p+0", LIT (0x1.921fb54442d18469898cc517018p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (0x3.839a252049c1114cf98e804177d4p-108) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x3.839a252049c1114cf98e804177d4p-108) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (0x3.839a252049c1114cf98e804177d4p-108) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x3.839a252049c1114cf98e804177d6p-108) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51701b8p+0", LIT (0x1.921fb54442d18469898cc51701b8p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (0x3.9a252049c1114cf98e804177d4c6p-116) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x3.9a252049c1114cf98e804177d4c8p-116) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (0x3.9a252049c1114cf98e804177d4c6p-116) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x3.9a252049c1114cf98e804177d4c8p-116) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51701b9p+0", LIT (0x1.921fb54442d18469898cc51701b9p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (-0xc.65dadfb63eeeb306717fbe882b4p-116) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xc.65dadfb63eeeb306717fbe882b38p-116) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (-0xc.65dadfb63eeeb306717fbe882b38p-116) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xc.65dadfb63eeeb306717fbe882b38p-116) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18469898cc51702p+0", LIT (0x1.921fb54442d18469898cc51702p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (-0x4.7c65dadfb63eeeb306717fbe882cp-108) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x4.7c65dadfb63eeeb306717fbe882cp-108) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (-0x4.7c65dadfb63eeeb306717fbe8828p-108) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x4.7c65dadfb63eeeb306717fbe8828p-108) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (-0x7.6733ae8fe47c65dadfb63eeeb308p-68) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x7.6733ae8fe47c65dadfb63eeeb308p-68) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffff8p-4), 1, LIT (-0x7.6733ae8fe47c65dadfb63eeeb304p-68) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x7.6733ae8fe47c65dadfb63eeeb304p-68) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.ffffffffffffffffffffffffff6p-4), 1, LIT (0x4.69898cc51701b839a252049c1104p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.ffffffffffffffffffffffffff68p-4), 1, LIT (0x4.69898cc51701b839a252049c1108p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.ffffffffffffffffffffffffff6p-4), 1, LIT (0x4.69898cc51701b839a252049c1104p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.ffffffffffffffffffffffffff68p-4), 1, LIT (0x4.69898cc51701b839a252049c1108p-56) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffbc8p-4), 1, LIT (-0xb.9676733ae8fe47c65dadfb63ede8p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffbdp-4), 1, LIT (-0xb.9676733ae8fe47c65dadfb63ede8p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffbc8p-4), 1, LIT (-0xb.9676733ae8fe47c65dadfb63edep-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffbdp-4), 1, LIT (-0xb.9676733ae8fe47c65dadfb63edep-56) } },
#endif
#if (TEST_COND_binary128)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb290924e3a11498p-4), 1, LIT (-0xb.bbd2e7b96766266f1d18f3ead018p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb290924e3a114988p-4), 1, LIT (-0xb.bbd2e7b96766266f1d18f3ead01p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb290924e3a11498p-4), 1, LIT (-0xb.bbd2e7b96766266f1d18f3ead01p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb290924e3a114988p-4), 1, LIT (-0xb.bbd2e7b96766266f1d18f3ead01p-28) } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+120", LIT (0x1p+120), { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db5e5f1aa933f37cp-4), 1, LIT (-0xe.d06685b36c66c4cf35c11f6519p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db5e5f1aa933f37cp-4), 1, LIT (-0xe.d06685b36c66c4cf35c11f6519p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db5e5f1aa933f37cp-4), 1, LIT (-0xe.d06685b36c66c4cf35c11f6518f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db5e5f1aa933f38p-4), 1, LIT (-0xe.d06685b36c66c4cf35c11f6518f8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+28", LIT (0x1p+28), { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5fdeb8807a1568p-4), 1, LIT (-0x2.a62ba8824e5bcb065f5f3b8e4f58p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5fdeb8807a156p-4), 1, LIT (-0x2.a62ba8824e5bcb065f5f3b8e4f58p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5fdeb8807a156p-4), 1, LIT (-0x2.a62ba8824e5bcb065f5f3b8e4f56p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5fdeb8807a156p-4), 1, LIT (-0x2.a62ba8824e5bcb065f5f3b8e4f56p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87d14de41dc991fp-4), 1, LIT (0x8.5f167780e479c9a5c86ffce76148p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87d14de41dc991fp-4), 1, LIT (0x8.5f167780e479c9a5c86ffce7615p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87d14de41dc991e8p-4), 1, LIT (0x8.5f167780e479c9a5c86ffce76148p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87d14de41dc991e8p-4), 1, LIT (0x8.5f167780e479c9a5c86ffce7615p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0debc87d70d196p-4), 1, LIT (0xf.431dd7a36cf37de5c74544f6b438p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0debc87d70d196p-4), 1, LIT (0xf.431dd7a36cf37de5c74544f6b438p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0debc87d70d195cp-4), 1, LIT (0xf.431dd7a36cf37de5c74544f6b438p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0debc87d70d195cp-4), 1, LIT (0xf.431dd7a36cf37de5c74544f6b44p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c70793712c4ff2bc8p-4), 1, LIT (0xa.dd6f6bacd20654c1404f52cde16p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c70793712c4ff2bcp-4), 1, LIT (0xa.dd6f6bacd20654c1404f52cde16p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c70793712c4ff2bcp-4), 1, LIT (0xa.dd6f6bacd20654c1404f52cde16p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c70793712c4ff2bcp-4), 1, LIT (0xa.dd6f6bacd20654c1404f52cde168p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+64", LIT (0x2p+64), { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e800f9b8a47b75b8p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc897p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e800f9b8a47b75b8p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc897p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e800f9b8a47b75bp-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc897p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e800f9b8a47b75bp-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc8978p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16384", LIT (0x2p-16384), { UNDERFLOW_EXCEPTION, 1, LIT (0x1.fffffffffffffffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x2p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x1.fffffffffffffffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x2p-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed895f9fa424ba91p-4), 1, LIT (-0xf.dfe6f2169e24f276e8027d91ba9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed895f9fa424ba91p-4), 1, LIT (-0xf.dfe6f2169e24f276e8027d91ba9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed895f9fa424ba91p-4), 1, LIT (-0xf.dfe6f2169e24f276e8027d91ba88p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed895f9fa424ba911p-4), 1, LIT (-0xf.dfe6f2169e24f276e8027d91ba88p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e2b6c62b7f4d6ap-24), 1, LIT (-0xf.ffffffffffcca8d9870423997308p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e2b6c62b7f4d6cp-24), 1, LIT (-0xf.ffffffffffcca8d9870423997308p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e2b6c62b7f4d6ap-24), 1, LIT (-0xf.ffffffffffcca8d98704239973p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e2b6c62b7f4d6cp-24), 1, LIT (-0xf.ffffffffffcca8d98704239973p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d313198a2e0372p+0", LIT (0x3.243f6a8885a308d313198a2e0372p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.8cbb5bf6c7ddd660ce2ff7d10568p-112), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.8cbb5bf6c7ddd660ce2ff7d10567p-112), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d313198a2e037p+0", LIT (0x3.243f6a8885a308d313198a2e037p+0), { ERRNO_UNCHANGED, 1, LIT (0x7.344a4093822299f31d0082efa98cp-116), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.344a4093822299f31d0082efa99p-116), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.344a4093822299f31d0082efa98cp-116), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.344a4093822299f31d0082efa99p-116), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d313198a2e03p+0", LIT (0x3.243f6a8885a308d313198a2e03p+0), { ERRNO_UNCHANGED, 1, LIT (0x7.07344a4093822299f31d0082efa8p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.07344a4093822299f31d0082efa8p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.07344a4093822299f31d0082efa8p-108), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.07344a4093822299f31d0082efacp-108), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d313198a2e04p+0", LIT (0x3.243f6a8885a308d313198a2e04p+0), { ERRNO_UNCHANGED, 1, LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1058p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1058p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d105p-108), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d105p-108), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308d4p+0", LIT (0x3.243f6a8885a308d4p+0), { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd661p-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd661p-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd6608p-68), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd6608p-68), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a308dp+0", LIT (0x3.243f6a8885a308dp+0), { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344a4093822299ep-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344a409382229ap-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344a4093822299ep-64), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344a409382229ap-64), 1, LIT (-0xf.fffffffffffffffffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d5cp-52), 1, LIT (-0xf.ffffffffffffffffffffffffef38p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d5cp-52), 1, LIT (-0xf.ffffffffffffffffffffffffef38p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d5bp-52), 1, LIT (-0xf.ffffffffffffffffffffffffef3p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d5bp-52), 1, LIT (-0xf.ffffffffffffffffffffffffef3p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707344a4093821bp-56), 1, LIT (-0xf.fffffffffffffffffffffffffd98p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707344a4093821b8p-56), 1, LIT (-0xf.fffffffffffffffffffffffffd9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707344a4093821bp-56), 1, LIT (-0xf.fffffffffffffffffffffffffd9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707344a4093821b8p-56), 1, LIT (-0xf.fffffffffffffffffffffffffd9p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd61896cb4f40d2p-24), 1, LIT (-0xf.ffffffffffeeca424938e847768p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd61896cb4f40d2p-24), 1, LIT (-0xf.ffffffffffeeca424938e8477678p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd61896cb4f40d1p-24), 1, LIT (-0xf.ffffffffffeeca424938e8477678p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd61896cb4f40d1p-24), 1, LIT (-0xf.ffffffffffeeca424938e8477678p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b76173f9040637ff9p-4), 1, LIT (-0xf.dfe902135fc1c18492e869a3f8bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b76173f9040637ff9p-4), 1, LIT (-0xf.dfe902135fc1c18492e869a3f8a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b76173f9040637ff8p-4), 1, LIT (-0xf.dfe902135fc1c18492e869a3f8a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b76173f9040637ff8p-4), 1, LIT (-0xf.dfe902135fc1c18492e869a3f8a8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x4p+48", LIT (0x4p+48), { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a986d98d6703e4p-4), 1, LIT (0xd.e3b88804f00552d6baba709471d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a986d98d6703e8p-4), 1, LIT (0xd.e3b88804f00552d6baba709471d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a986d98d6703e4p-4), 1, LIT (0xd.e3b88804f00552d6baba709471d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a986d98d6703e8p-4), 1, LIT (0xd.e3b88804f00552d6baba709471ep-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1024", LIT (0x4p-1024), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffffffffffffffep-1024), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffffffffffffffep-1024), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076", LIT (0x4p-1076), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffffffffffffffep-1076), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffffffffffffffep-1076), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-128", LIT (0x4p-128), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffffffffffffffep-128), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffffffffffffffep-128), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384", LIT (0x4p-16384), { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x3.fffffffffffffffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x4p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x3.fffffffffffffffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x4p-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448", LIT (0x4p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (0x3.fffffffffffcp-16448), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x3.fffffffffffcp-16448), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-16448), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496", LIT (0x4p-16496), { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-16496), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-16496), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e74fbeae63ee4dp-4), 1, LIT (0xf.e006929f558d3eb50074ea600e58p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e74fbeae63ee4cp-4), 1, LIT (0xf.e006929f558d3eb50074ea600e6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e74fbeae63ee4cp-4), 1, LIT (0xf.e006929f558d3eb50074ea600e58p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e74fbeae63ee4cp-4), 1, LIT (0xf.e006929f558d3eb50074ea600e6p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cc8749212e72p+0", LIT (0x6.287cc8749212e72p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bca4e961470b22p-4), 1, LIT (0xf.e006929f558d8cc5d90bd654dfbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bca4e961470b22p-4), 1, LIT (0xf.e006929f558d8cc5d90bd654dfbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bca4e961470b21fp-4), 1, LIT (0xf.e006929f558d8cc5d90bd654dfbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bca4e961470b21fp-4), 1, LIT (0xf.e006929f558d8cc5d90bd654dfb8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e5ab16d9008ea9p-4), 1, LIT (0xf.e006929f558dbe67de4071414d98p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e5ab16d9008ea9p-4), 1, LIT (0xf.e006929f558dbe67de4071414d98p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e5ab16d9008ea8p-4), 1, LIT (0xf.e006929f558dbe67de4071414d98p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e5ab16d9008ea8p-4), 1, LIT (0xf.e006929f558dbe67de4071414dap-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3f77c1915bc919p-4), 1, LIT (0xf.e00691b6bde4251c3b197736a7p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3f77c1915bc919p-4), 1, LIT (0xf.e00691b6bde4251c3b197736a7p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3f77c1915bc918p-4), 1, LIT (0xf.e00691b6bde4251c3b197736a7p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3f77c1915bc918p-4), 1, LIT (0xf.e00691b6bde4251c3b197736a708p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce5d42fde40e7p-4), 1, LIT (0xf.e006a1ad17db69b4cedfec37da9p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce5d42fde40e7p-4), 1, LIT (0xf.e006a1ad17db69b4cedfec37da98p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce5d42fde40e6ffp-4), 1, LIT (0xf.e006a1ad17db69b4cedfec37da9p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce5d42fde40e6ffp-4), 1, LIT (0xf.e006a1ad17db69b4cedfec37da98p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6ab95779c1eae08p-4), 1, LIT (0xd.db3d742c26555af29a6e23c11f3p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6ab95779c1eae0cp-4), 1, LIT (0xd.db3d742c26555af29a6e23c11f38p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6ab95779c1eae08p-4), 1, LIT (0xd.db3d742c26555af29a6e23c11f3p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6ab95779c1eae0cp-4), 1, LIT (0xd.db3d742c26555af29a6e23c11f38p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c232dd99707ab3d8p-4", LIT (0x8.60a91c16b9b2c232dd99707ab3d8p-4), { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000000000000000000000000008p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5c8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c232dd99707ab3dp-4", LIT (0x8.60a91c16b9b2c232dd99707ab3dp-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffff8p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffffcp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5c8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffff8p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffffcp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5c8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c232dd99707ab4p-4", LIT (0x8.60a91c16b9b2c232dd99707ab4p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000000000000002p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000000000000002p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000000000000002p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000000000000000000000000028p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c5bp-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c232dd99707abp-4", LIT (0x8.60a91c16b9b2c232dd99707abp-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffcacp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c7a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffcacp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c7bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffcacp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c7a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffcbp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c7bp-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c23p-4", LIT (0x8.60a91c16b9b2c23p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffd84af2ec140dcp-4), 1, LIT (0xd.db3d742c265539da9a6e23c11fa8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffd84af2ec140dcp-4), 1, LIT (0xd.db3d742c265539da9a6e23c11fbp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffd84af2ec140dcp-4), 1, LIT (0xd.db3d742c265539da9a6e23c11fa8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffd84af2ec140ep-4), 1, LIT (0xd.db3d742c265539da9a6e23c11fbp-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b2c24p-4", LIT (0x8.60a91c16b9b2c24p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000b5feca2ed673p-4), 1, LIT (0xd.db3d742c265539d29a6e23c11fa8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000b5feca2ed673p-4), 1, LIT (0xd.db3d742c265539d29a6e23c11fbp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000b5feca2ed673p-4), 1, LIT (0xd.db3d742c265539d29a6e23c11fa8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000b5feca2ed6738p-4), 1, LIT (0xd.db3d742c265539d29a6e23c11fbp-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000035858118fd5157ep-4), 1, LIT (0xd.db3d742c26551af29a6e23c11f4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000035858118fd5157ep-4), 1, LIT (0xd.db3d742c26551af29a6e23c11f48p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000035858118fd5157ep-4), 1, LIT (0xd.db3d742c26551af29a6e23c11f4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000035858118fd5157e8p-4), 1, LIT (0xd.db3d742c26551af29a6e23c11f48p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050cf967fba7bc728p-4), 1, LIT (0xd.db3d7a37832aa678a274956dfd28p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050cf967fba7bc728p-4), 1, LIT (0xd.db3d7a37832aa678a274956dfd3p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050cf967fba7bc728p-4), 1, LIT (0xd.db3d7a37832aa678a274956dfd28p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050cf967fba7bc72cp-4), 1, LIT (0xd.db3d7a37832aa678a274956dfd3p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168852c4130c64b4b8p-4), 1, LIT (0xd.db3d7237832e30f6465d599654a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168852c4130c64b4cp-4), 1, LIT (0xd.db3d7237832e30f6465d599654a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168852c4130c64b4b8p-4), 1, LIT (0xd.db3d7237832e30f6465d599654a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168852c4130c64b4cp-4), 1, LIT (0xd.db3d7237832e30f6465d599654bp-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+1020", LIT (0x8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2d2e64a2845e55p-4), 1, LIT (-0xd.38cf9361195f50b10fac29dd9038p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2d2e64a2845e558p-4), 1, LIT (-0xd.38cf9361195f50b10fac29dd9038p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2d2e64a2845e55p-4), 1, LIT (-0xd.38cf9361195f50b10fac29dd903p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2d2e64a2845e558p-4), 1, LIT (-0xd.38cf9361195f50b10fac29dd903p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+124", LIT (0x8p+124), { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89381836cafaa28p-4), 1, LIT (0xc.82b8ec98b5e62fcf0b09fd10eb28p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89381836cafaa3p-4), 1, LIT (0xc.82b8ec98b5e62fcf0b09fd10eb3p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89381836cafaa28p-4), 1, LIT (0xc.82b8ec98b5e62fcf0b09fd10eb28p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89381836cafaa3p-4), 1, LIT (0xc.82b8ec98b5e62fcf0b09fd10eb3p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+16380", LIT (0x8p+16380), { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc6881f0ca607c7946p-4), 1, LIT (0xe.bcc2fc82ae39ebf8da5d687bf358p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc6881f0ca607c7946p-4), 1, LIT (0xe.bcc2fc82ae39ebf8da5d687bf36p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc6881f0ca607c7946p-4), 1, LIT (0xe.bcc2fc82ae39ebf8da5d687bf358p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc6881f0ca607c79464p-4), 1, LIT (0xe.bcc2fc82ae39ebf8da5d687bf36p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152", LIT (0x8p-152), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffffcp-152), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffffcp-152), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448", LIT (0x8p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (0x7.fffffffffffcp-16448), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x8p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x7.fffffffffffcp-16448), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x8p-16448), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-972", LIT (0x8p-972), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffffcp-972), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-972), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffffcp-972), 1, LIT (0xf.fffffffffffffffffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a663c8p-4", LIT (0xc.d4966d92d17082980965c1a663c8p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356318p-4), 1, LIT (0xb.201e79450884be22c53e47ed16d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356318p-4), 1, LIT (0xb.201e79450884be22c53e47ed16d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356318p-4), 1, LIT (0xb.201e79450884be22c53e47ed16d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73291281035632p-4), 1, LIT (0xb.201e79450884be22c53e47ed16ep-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a663cp-4", LIT (0xc.d4966d92d17082980965c1a663cp-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73291281035631p-4), 1, LIT (0xb.201e79450884be22c53e47ed16ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356318p-4), 1, LIT (0xb.201e79450884be22c53e47ed16ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73291281035631p-4), 1, LIT (0xb.201e79450884be22c53e47ed16ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356318p-4), 1, LIT (0xb.201e79450884be22c53e47ed16e8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a664p-4", LIT (0xc.d4966d92d17082980965c1a664p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73291281035634p-4), 1, LIT (0xb.201e79450884be22c53e47ed16bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73291281035634p-4), 1, LIT (0xb.201e79450884be22c53e47ed16bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73291281035634p-4), 1, LIT (0xb.201e79450884be22c53e47ed16bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356348p-4), 1, LIT (0xb.201e79450884be22c53e47ed16b8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082980965c1a66p-4", LIT (0xc.d4966d92d17082980965c1a66p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356078p-4), 1, LIT (0xb.201e79450884be22c53e47ed199p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356078p-4), 1, LIT (0xb.201e79450884be22c53e47ed199p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356078p-4), 1, LIT (0xb.201e79450884be22c53e47ed199p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73291281035608p-4), 1, LIT (0xb.201e79450884be22c53e47ed1998p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72cfa9001072848p-4), 1, LIT (0xb.201e79450884be288bda3ee0dd18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72cfa9001072848p-4), 1, LIT (0xb.201e79450884be288bda3ee0dd18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72cfa9001072848p-4), 1, LIT (0xb.201e79450884be288bda3ee0dd18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72cfa900107285p-4), 1, LIT (0xb.201e79450884be288bda3ee0dd2p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7381aae7a4c30dp-4), 1, LIT (0xb.201e79450884be1d0c24406973ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7381aae7a4c30dp-4), 1, LIT (0xb.201e79450884be1d0c24406973ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7381aae7a4c30dp-4), 1, LIT (0xb.201e79450884be1d0c24406973ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7381aae7a4c30d8p-4), 1, LIT (0xb.201e79450884be1d0c24406973a8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e564d5ae94f8cb08p-4), 1, LIT (0xb.201e79450884c00000000000c17p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e564d5ae94f8cb08p-4), 1, LIT (0xb.201e79450884c00000000000c178p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e564d5ae94f8cb08p-4), 1, LIT (0xb.201e79450884c00000000000c17p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e564d5ae94f8cb1p-4), 1, LIT (0xb.201e79450884c00000000000c178p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e65c978bd3cef98p-4), 1, LIT (0xb.201e794508846402500c44b4f8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e65c978bd3cef98p-4), 1, LIT (0xb.201e794508846402500c44b4f8e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e65c978bd3cef98p-4), 1, LIT (0xb.201e794508846402500c44b4f8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e65c978bd3cefap-4), 1, LIT (0xb.201e794508846402500c44b4f8e8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8acc8f4f3f1b3p-4), 1, LIT (0xb.201e83065041456a084c70f5a12p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8acc8f4f3f1b3p-4), 1, LIT (0xb.201e83065041456a084c70f5a128p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8acc8f4f3f1b3p-4), 1, LIT (0xb.201e83065041456a084c70f5a12p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8acc8f4f3f1b38p-4), 1, LIT (0xb.201e83065041456a084c70f5a128p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a60011766c8a3178p-4), 1, LIT (0xb.201e77869a46ae20ce545c5c67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a60011766c8a3178p-4), 1, LIT (0xb.201e77869a46ae20ce545c5c67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a60011766c8a3178p-4), 1, LIT (0xb.201e77869a46ae20ce545c5c67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a60011766c8a318p-4), 1, LIT (0xb.201e77869a46ae20ce545c5c6708p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4", LIT (0xcp-4), { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2d966e1d6af1408p-4), 1, LIT (0xb.b4ff632a908f73ec151839cb9d98p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2d966e1d6af1408p-4), 1, LIT (0xb.b4ff632a908f73ec151839cb9d98p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2d966e1d6af1408p-4), 1, LIT (0xb.b4ff632a908f73ec151839cb9d98p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2d966e1d6af141p-4), 1, LIT (0xb.b4ff632a908f73ec151839cb9dap-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ec139784e3b7988p-4), 1, LIT (0x1.ff01000c9ae73630add558c936b4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ec139784e3b799p-4), 1, LIT (0x1.ff01000c9ae73630add558c936b5p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ec139784e3b7988p-4), 1, LIT (0x1.ff01000c9ae73630add558c936b4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ec139784e3b799p-4), 1, LIT (0x1.ff01000c9ae73630add558c936b5p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b7cc3cd579a135p-4), 1, LIT (0xe.26f8af8333f9270e9c3e9f64f938p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b7cc3cd579a135p-4), 1, LIT (0xe.26f8af8333f9270e9c3e9f64f94p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b7cc3cd579a135p-4), 1, LIT (0xe.26f8af8333f9270e9c3e9f64f938p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b7cc3cd579a1354p-4), 1, LIT (0xe.26f8af8333f9270e9c3e9f64f94p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddec0c69e7ddef68p-4), 1, LIT (-0xa.07bd3ab53ab9710f3445538de8fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddec0c69e7ddef68p-4), 1, LIT (-0xa.07bd3ab53ab9710f3445538de8fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddec0c69e7ddef68p-4), 1, LIT (-0xa.07bd3ab53ab9710f3445538de8e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddec0c69e7ddef7p-4), 1, LIT (-0xa.07bd3ab53ab9710f3445538de8e8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424bef274717106p-4), 1, LIT (-0xd.b7f5359babdb66be8d0cd3e293fp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424bef274717106p-4), 1, LIT (-0xd.b7f5359babdb66be8d0cd3e293e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424bef2747171058p-4), 1, LIT (-0xd.b7f5359babdb66be8d0cd3e293e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424bef2747171058p-4), 1, LIT (-0xd.b7f5359babdb66be8d0cd3e293e8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d8892761be1537b8p-8), 1, LIT (0xf.fb2a030c5ae20bdfe29fda198eap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d8892761be1537b8p-8), 1, LIT (0xf.fb2a030c5ae20bdfe29fda198eap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d8892761be1537b8p-8), 1, LIT (0xf.fb2a030c5ae20bdfe29fda198eap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d8892761be1537cp-8), 1, LIT (0xf.fb2a030c5ae20bdfe29fda198ea8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b61139b09a7c84ap-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f138p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b61139b09a7c84ap-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f138p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b61139b09a7c84ap-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f13p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b61139b09a7c84bp-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f13p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { ERRNO_UNCHANGED, 1, LIT (-0xe.f1a3e1dc468a921dddb4e37fbe68p-4), 1, LIT (-0x5.b773d971a848e75c230605526978p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.f1a3e1dc468a921dddb4e37fbe6p-4), 1, LIT (-0x5.b773d971a848e75c230605526978p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.f1a3e1dc468a921dddb4e37fbe6p-4), 1, LIT (-0x5.b773d971a848e75c230605526974p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.f1a3e1dc468a921dddb4e37fbe6p-4), 1, LIT (-0x5.b773d971a848e75c230605526974p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffff8p+16380", LIT (0xf.fffffffffffffffffffffffffff8p+16380), { ERRNO_UNCHANGED, 1, LIT (0xf.3b0b11ed85b7fe43d110251580bp-4), 1, LIT (-0x4.e6dc95fb529bc365f472e4fbc1f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.3b0b11ed85b7fe43d110251580b8p-4), 1, LIT (-0x4.e6dc95fb529bc365f472e4fbc1f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.3b0b11ed85b7fe43d110251580bp-4), 1, LIT (-0x4.e6dc95fb529bc365f472e4fbc1f4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.3b0b11ed85b7fe43d110251580b8p-4), 1, LIT (-0x4.e6dc95fb529bc365f472e4fbc1f4p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), 1, LIT (-0x2.002ef4018753d50b7a7f6bc3f5bap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), 1, LIT (-0x2.002ef4018753d50b7a7f6bc3f5bap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7b9650cab0f5438p-4), 1, LIT (-0x2.002ef4018753d50b7a7f6bc3f5b8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7b9650cab0f544p-4), 1, LIT (-0x2.002ef4018753d50b7a7f6bc3f5b8p-4) } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906cee446be049ap-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906cee446be04998p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906cee446be04998p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb2fp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906cee446be04998p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb2f8p-4) } },
#endif
#if (TEST_COND_binary32)
    { "-0", LIT (-0x0p+0), { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary32)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { ERRNO_UNCHANGED, 1, LIT (-0xd.8f692p-4), 1, LIT (0x8.7e0eap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f692p-4), 1, LIT (0x8.7e0eap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691p-4), 1, LIT (0x8.7e0eap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691p-4), 1, LIT (0x8.7e0ebp-4) } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p+64", LIT (-0x2p+64), { ERRNO_UNCHANGED, 1, LIT (0xc.143e1p-8), 1, LIT (0xf.fb701p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e1p-8), 1, LIT (0xf.fb702p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e1p-8), 1, LIT (0xf.fb701p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e2p-8), 1, LIT (0xf.fb702p-4) } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a4p-24), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a4p-24), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885ap-24), 1, LIT (-0xf.fffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885ap-24), 1, LIT (-0xf.fffffp-4) } },
#endif
#if (TEST_COND_binary32)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cp-24), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cp-24), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cp-24), 1, LIT (-0xf.fffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5ep-24), 1, LIT (-0xf.fffffp-4) } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-128", LIT (-0x4p-128), { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x4p-128), 1, LIT (0xf.fffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x4p-128), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x3.fffff8p-128), 1, LIT (0xf.fffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x3.fffff8p-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152", LIT (-0x8p-152), { UNDERFLOW_EXCEPTION, 1, LIT (-0x8p-152), 1, LIT (0xf.fffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x8p-152), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0xf.fffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (0x8.599b3p-4), 1, LIT (0xd.a5f96p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b3p-4), 1, LIT (0xd.a5f96p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b3p-4), 1, LIT (0xd.a5f96p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b4p-4), 1, LIT (0xd.a5f97p-4) } },
#endif
#if (TEST_COND_binary32)
    { "+0", LIT (0x0p+0), { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary32)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d6p-4), 1, LIT (0x8.00001p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d7p-4), 1, LIT (0x8.00001p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d6p-4), 1, LIT (0x8.00001p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d7p-4), 1, LIT (0x8.00002p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d7p-4), 1, LIT (0x7.fffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d8p-4), 1, LIT (0x7.fffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d7p-4), 1, LIT (0x7.fffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d8p-4), 1, LIT (0x8p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adp-4), 1, LIT (0xd.a8283p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2aep-4), 1, LIT (0xd.a8283p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adp-4), 1, LIT (0xd.a8283p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2aep-4), 1, LIT (0xd.a8284p-8) } },
#endif
#if (TEST_COND_binary32)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adp-4), 1, LIT (0xd.a8263p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2aep-4), 1, LIT (0xd.a8263p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adp-4), 1, LIT (0xd.a8263p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2aep-4), 1, LIT (0xd.a8264p-8) } },
#endif
#if (TEST_COND_binary32)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffp-4), 1, LIT (0x1.4442dp-24) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.4442d2p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffp-4), 1, LIT (0x1.4442dp-24) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.4442d2p-24) } },
#endif
#if (TEST_COND_binary32)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffp-4), 1, LIT (-0xb.bbd2fp-28) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xb.bbd2ep-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffp-4), 1, LIT (-0xb.bbd2ep-28) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xb.bbd2ep-28) } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+120", LIT (0x1p+120), { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d18p-4), 1, LIT (-0xe.d0669p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d18p-4), 1, LIT (-0xe.d0668p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d18p-4), 1, LIT (-0xe.d0668p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d2p-4), 1, LIT (-0xe.d0668p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+28", LIT (0x1p+28), { ERRNO_UNCHANGED, 1, LIT (-0xf.c777dp-4), 1, LIT (-0x2.a62bacp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777cp-4), 1, LIT (-0x2.a62ba8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777cp-4), 1, LIT (-0x2.a62ba8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777cp-4), 1, LIT (-0x2.a62ba8p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e88p-4), 1, LIT (0xf.431ddp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e88p-4), 1, LIT (0xf.431ddp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e8p-4), 1, LIT (0xf.431ddp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e8p-4), 1, LIT (0xf.431dep-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { ERRNO_UNCHANGED, 1, LIT (-0xb.becc5p-4), 1, LIT (0xa.dd6f6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc4p-4), 1, LIT (0xa.dd6f7p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc4p-4), 1, LIT (0xa.dd6f6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc4p-4), 1, LIT (0xa.dd6f7p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+64", LIT (0x2p+64), { ERRNO_UNCHANGED, 1, LIT (-0xc.143e2p-8), 1, LIT (0xf.fb701p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e1p-8), 1, LIT (0xf.fb702p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e1p-8), 1, LIT (0xf.fb701p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e1p-8), 1, LIT (0xf.fb702p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6dap-4), 1, LIT (-0xf.dfe7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6dap-4), 1, LIT (-0xf.dfe6fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6dap-4), 1, LIT (-0xf.dfe6fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6dcp-4), 1, LIT (-0xf.dfe6fp-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (0x2.8885ap-24), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a4p-24), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885ap-24), 1, LIT (-0xf.fffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a4p-24), 1, LIT (-0xf.fffffp-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5ep-24), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cp-24), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cp-24), 1, LIT (-0xf.fffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cp-24), 1, LIT (-0xf.fffffp-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb67ap-4), 1, LIT (-0xf.dfe91p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb67ap-4), 1, LIT (-0xf.dfe9p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb678p-4), 1, LIT (-0xf.dfe9p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb678p-4), 1, LIT (-0xf.dfe9p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x4p+48", LIT (0x4p+48), { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78p-4), 1, LIT (0xd.e3b88p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78p-4), 1, LIT (0xd.e3b89p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78p-4), 1, LIT (0xd.e3b88p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d8p-4), 1, LIT (0xd.e3b89p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-128", LIT (0x4p-128), { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x3.fffff8p-128), 1, LIT (0xf.fffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x4p-128), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x3.fffff8p-128), 1, LIT (0xf.fffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x4p-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary32)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb8p-4), 1, LIT (0xf.e0069p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7ep-4), 1, LIT (0xf.e0069p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7ep-4), 1, LIT (0xf.e0069p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7ep-4), 1, LIT (0xf.e006ap-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecbp-4), 1, LIT (0xf.e006ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecbp-4), 1, LIT (0xf.e006ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecafep-4), 1, LIT (0xf.e006ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecafep-4), 1, LIT (0xf.e006bp-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffp-4), 1, LIT (0xd.db3d7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff8p-4), 1, LIT (0xd.db3d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffp-4), 1, LIT (0xd.db3d7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff8p-4), 1, LIT (0xd.db3d8p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.00001p-4), 1, LIT (0xd.db3d8p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x8p+124", LIT (0x8p+124), { ERRNO_UNCHANGED, 1, LIT (0x9.f9631p-4), 1, LIT (0xc.82b8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f9631p-4), 1, LIT (0xc.82b8fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f9631p-4), 1, LIT (0xc.82b8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f9632p-4), 1, LIT (0xc.82b8fp-4) } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152", LIT (0x8p-152), { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x8p-152), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x8p-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary32)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fp-4), 1, LIT (0xb.201e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fp-4), 1, LIT (0xb.201e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fp-4), 1, LIT (0xb.201e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb6p-4), 1, LIT (0xb.201e9p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb6p-4), 1, LIT (0xb.201e7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb6p-4), 1, LIT (0xb.201e7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb6p-4), 1, LIT (0xb.201e7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb61p-4), 1, LIT (0xb.201e8p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4", LIT (0xcp-4), { ERRNO_UNCHANGED, 1, LIT (0xa.e7fep-4), 1, LIT (0xb.b4ff6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe1p-4), 1, LIT (0xb.b4ff6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fep-4), 1, LIT (0xb.b4ff6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe1p-4), 1, LIT (0xb.b4ff7p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { ERRNO_UNCHANGED, 1, LIT (0x7.76d6p-4), 1, LIT (0xe.26f8ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d6p-4), 1, LIT (0xe.26f8bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d6p-4), 1, LIT (0xe.26f8ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d608p-4), 1, LIT (0xe.26f8bp-4) } },
#endif
#if (TEST_COND_binary32)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { ERRNO_UNCHANGED, 1, LIT (0xc.773a2p-4), 1, LIT (-0xa.07bd4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a3p-4), 1, LIT (-0xa.07bd4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2p-4), 1, LIT (-0xa.07bd3p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a3p-4), 1, LIT (-0xa.07bd3p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee1p-4), 1, LIT (-0xd.b7f54p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3beep-4), 1, LIT (-0xd.b7f53p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3beep-4), 1, LIT (-0xd.b7f53p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3beep-4), 1, LIT (-0xd.b7f53p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5cp-8), 1, LIT (0xf.fb2ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5cp-8), 1, LIT (0xf.fb2ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5cp-8), 1, LIT (0xf.fb2ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5dp-8), 1, LIT (0xf.fb2a1p-4) } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (-0x8.599b4p-4), 1, LIT (0xd.a5f96p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b3p-4), 1, LIT (0xd.a5f96p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b3p-4), 1, LIT (0xd.a5f96p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b3p-4), 1, LIT (0xd.a5f97p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0", LIT (-0x0p+0), { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95428p-4), 1, LIT (0x8.7e0ea4db2f488p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95428p-4), 1, LIT (0x8.7e0ea4db2f488p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a9542p-4), 1, LIT (0x8.7e0ea4db2f488p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a9542p-4), 1, LIT (0x8.7e0ea4db2f49p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p+64", LIT (-0x2p+64), { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b07018p-8), 1, LIT (0xf.fb701e22987f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0702p-8), 1, LIT (0xf.fb701e22987f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b07018p-8), 1, LIT (0xf.fb701e22987f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0702p-8), 1, LIT (0xf.fb701e22988p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d3108p-24), 1, LIT (-0xf.ffffffffffcdp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d3106p-24), 1, LIT (-0xf.ffffffffffcc8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d3106p-24), 1, LIT (-0xf.ffffffffffcc8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d3106p-24), 1, LIT (-0xf.ffffffffffcc8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fcp-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fdp-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fcp-52), 1, LIT (-0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fdp-52), 1, LIT (-0xf.ffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e038p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e038p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03p-56), 1, LIT (-0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03p-56), 1, LIT (-0xf.ffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5p-24), 1, LIT (-0xf.ffffffffffefp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec6p-24), 1, LIT (-0xf.ffffffffffefp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5p-24), 1, LIT (-0xf.ffffffffffee8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec6p-24), 1, LIT (-0xf.ffffffffffee8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd78p-4), 1, LIT (-0x1.febbf9949ecc2p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd78p-4), 1, LIT (-0x1.febbf9949ecc1p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd7p-4), 1, LIT (-0x1.febbf9949ecc1p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd7p-4), 1, LIT (-0x1.febbf9949ecc1p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1024", LIT (-0x4p-1024), { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x4p-1024), 1, LIT (0xf.ffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x4p-1024), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x3.ffffffffffffcp-1024), 1, LIT (0xf.ffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x3.ffffffffffffcp-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076", LIT (-0x4p-1076), { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-1076), 1, LIT (0xf.ffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-1076), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0xf.ffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-128", LIT (-0x4p-128), { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.ffffffffffffep-128), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.ffffffffffffep-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152", LIT (-0x8p-152), { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.ffffffffffffcp-152), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.ffffffffffffcp-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-972", LIT (-0x8p-972), { ERRNO_UNCHANGED, 1, LIT (-0x8p-972), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-972), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.ffffffffffffcp-972), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.ffffffffffffcp-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e97p-8), 1, LIT (-0xf.fff31767d5bbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e97p-8), 1, LIT (-0xf.fff31767d5ba8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96p-8), 1, LIT (-0xf.fff31767d5ba8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96p-8), 1, LIT (-0xf.fff31767d5ba8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba8p-4), 1, LIT (0xd.a5f963cdefe68p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba8p-4), 1, LIT (0xd.a5f963cdefe7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba8p-4), 1, LIT (0xd.a5f963cdefe68p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844abbp-4), 1, LIT (0xd.a5f963cdefe7p-4) } },
#endif
#if (TEST_COND_binary64)
    { "+0", LIT (0x0p+0), { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c928p-4), 1, LIT (0x8.000014f038b18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c928p-4), 1, LIT (0x8.000014f038b18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c928p-4), 1, LIT (0x8.000014f038b18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c93p-4), 1, LIT (0x8.000014f038b2p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c26548p-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2655p-4), 1, LIT (0x8.0000000000008p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c26548p-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2655p-4), 1, LIT (0x8.0000000000008p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2655p-4), 1, LIT (0x7.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c26558p-4), 1, LIT (0x7.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2655p-4), 1, LIT (0x7.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c26558p-4), 1, LIT (0x7.ffffffffffffcp-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca08p-4), 1, LIT (0x7.fffff939bdd18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca1p-4), 1, LIT (0x7.fffff939bdd18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca08p-4), 1, LIT (0x7.fffff939bdd18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca1p-4), 1, LIT (0x7.fffff939bdd1cp-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953aep-4), 1, LIT (0xd.a82832da19f98p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953aep-4), 1, LIT (0xd.a82832da19f98p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953aep-4), 1, LIT (0xd.a82832da19f98p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae8p-4), 1, LIT (0xd.a82832da19fap-8) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea838p-4), 1, LIT (0xd.a82683a33cbe8p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea84p-4), 1, LIT (0xd.a82683a33cbe8p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea838p-4), 1, LIT (0xd.a82683a33cbe8p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea84p-4), 1, LIT (0xd.a82683a33cbfp-8) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948p-4), 1, LIT (0xd.a8263394be6dp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948p-4), 1, LIT (0xd.a8263394be6dp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948p-4), 1, LIT (0xd.a8263394be6dp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e5895p-4), 1, LIT (0xd.a8263394be6d8p-8) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff3p-4), 1, LIT (0x1.4442d18469893p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff3p-4), 1, LIT (0x1.4442d18469893p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff3p-4), 1, LIT (0x1.4442d18469893p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff38p-4), 1, LIT (0x1.4442d18469894p-24) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.ffffffffffff8p-4), 1, LIT (0x4.69898cc517018p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x4.69898cc51701cp-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.ffffffffffff8p-4), 1, LIT (0x4.69898cc517018p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x4.69898cc51701cp-56) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.ffffffffffff8p-4), 1, LIT (-0xb.9676733ae8fe8p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xb.9676733ae8fe8p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.ffffffffffff8p-4), 1, LIT (-0xb.9676733ae8fep-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xb.9676733ae8fep-56) } },
#endif
#if (TEST_COND_binary64)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffb8p-4), 1, LIT (-0xb.bbd2e7b967668p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffb8p-4), 1, LIT (-0xb.bbd2e7b96766p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffb8p-4), 1, LIT (-0xb.bbd2e7b96766p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffcp-4), 1, LIT (-0xb.bbd2e7b96766p-28) } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+120", LIT (0x1p+120), { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2cp-4), 1, LIT (-0xe.d06685b36c67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2cp-4), 1, LIT (-0xe.d06685b36c67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2cp-4), 1, LIT (-0xe.d06685b36c668p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf3p-4), 1, LIT (-0xe.d06685b36c668p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+28", LIT (0x1p+28), { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a758p-4), 1, LIT (-0x2.a62ba8824e5bep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a75p-4), 1, LIT (-0x2.a62ba8824e5bcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a75p-4), 1, LIT (-0x2.a62ba8824e5bcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a75p-4), 1, LIT (-0x2.a62ba8824e5bcp-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9ccp-4), 1, LIT (0x8.5f167780e4798p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb8p-4), 1, LIT (0x8.5f167780e47ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb8p-4), 1, LIT (0x8.5f167780e4798p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb8p-4), 1, LIT (0x8.5f167780e47ap-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077cp-4), 1, LIT (0xf.431dd7a36cf3p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077cp-4), 1, LIT (0xf.431dd7a36cf38p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bcp-4), 1, LIT (0xf.431dd7a36cf3p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bcp-4), 1, LIT (0xf.431dd7a36cf38p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c8p-4), 1, LIT (0xa.dd6f6bacd206p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c8p-4), 1, LIT (0xa.dd6f6bacd2068p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8cp-4), 1, LIT (0xa.dd6f6bacd206p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8cp-4), 1, LIT (0xa.dd6f6bacd2068p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+64", LIT (0x2p+64), { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0702p-8), 1, LIT (0xf.fb701e22987f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0702p-8), 1, LIT (0xf.fb701e22987f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b07018p-8), 1, LIT (0xf.fb701e22987f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b07018p-8), 1, LIT (0xf.fb701e22988p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffedp-4), 1, LIT (-0xf.dfe6f2169e25p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffeep-4), 1, LIT (-0xf.dfe6f2169e25p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffedp-4), 1, LIT (-0xf.dfe6f2169e248p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffeep-4), 1, LIT (-0xf.dfe6f2169e248p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d3106p-24), 1, LIT (-0xf.ffffffffffcdp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d3106p-24), 1, LIT (-0xf.ffffffffffcc8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d3106p-24), 1, LIT (-0xf.ffffffffffcc8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d3108p-24), 1, LIT (-0xf.ffffffffffcc8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fdp-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fdp-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fcp-52), 1, LIT (-0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fcp-52), 1, LIT (-0xf.ffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e038p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03p-56), 1, LIT (-0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e038p-56), 1, LIT (-0xf.ffffffffffff8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec6p-24), 1, LIT (-0xf.ffffffffffefp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec6p-24), 1, LIT (-0xf.ffffffffffefp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5p-24), 1, LIT (-0xf.ffffffffffee8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5p-24), 1, LIT (-0xf.ffffffffffee8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b8p-4), 1, LIT (-0xf.dfe902135fc2p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7p-4), 1, LIT (-0xf.dfe902135fc2p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7p-4), 1, LIT (-0xf.dfe902135fc18p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7p-4), 1, LIT (-0xf.dfe902135fc18p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x4p+48", LIT (0x4p+48), { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb768p-4), 1, LIT (0xd.e3b88804f005p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76cp-4), 1, LIT (0xd.e3b88804f0058p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb768p-4), 1, LIT (0xd.e3b88804f005p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76cp-4), 1, LIT (0xd.e3b88804f0058p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1024", LIT (0x4p-1024), { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x3.ffffffffffffcp-1024), 1, LIT (0xf.ffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x3.ffffffffffffcp-1024), 1, LIT (0xf.ffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076", LIT (0x4p-1076), { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.ffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.ffffffffffff8p-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-128", LIT (0x4p-128), { ERRNO_UNCHANGED, 1, LIT (0x3.ffffffffffffep-128), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.ffffffffffffep-128), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b87p-4), 1, LIT (0xf.e006929f558dp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b87p-4), 1, LIT (0xf.e006929f558dp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86fp-4), 1, LIT (0xf.e006929f558dp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86fp-4), 1, LIT (0xf.e006929f558d8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b831p-4), 1, LIT (0xf.e006929f558d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b83p-4), 1, LIT (0xf.e006929f558d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b83p-4), 1, LIT (0xf.e006929f558d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b83p-4), 1, LIT (0xf.e006929f558ep-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6eap-4), 1, LIT (0xf.e00691b6bde4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6eap-4), 1, LIT (0xf.e00691b6bde4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9p-4), 1, LIT (0xf.e00691b6bde4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9p-4), 1, LIT (0xf.e00691b6bde48p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a11p-4), 1, LIT (0xf.e006a1ad17dbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a11p-4), 1, LIT (0xf.e006a1ad17db8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a1p-4), 1, LIT (0xf.e006a1ad17dbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a1p-4), 1, LIT (0xf.e006a1ad17db8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffcp-4), 1, LIT (0xd.db3d742c2655p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffcp-4), 1, LIT (0xd.db3d742c26558p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffcp-4), 1, LIT (0xd.db3d742c2655p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c26558p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c2655p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c2655p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c2655p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000000000008p-4), 1, LIT (0xd.db3d742c26558p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a04p-4), 1, LIT (0xd.db3d7a37832a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a04p-4), 1, LIT (0xd.db3d7a37832a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a04p-4), 1, LIT (0xd.db3d7a37832a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a08p-4), 1, LIT (0xd.db3d7a37832bp-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168p-4), 1, LIT (0xd.db3d7237832ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168p-4), 1, LIT (0xd.db3d7237832ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168p-4), 1, LIT (0xd.db3d7237832ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000003632117p-4), 1, LIT (0xd.db3d7237832e8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+1020", LIT (0x8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaf8p-4), 1, LIT (-0xd.38cf9361195f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbbp-4), 1, LIT (-0xd.38cf9361195f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaf8p-4), 1, LIT (-0xd.38cf9361195fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbbp-4), 1, LIT (-0xd.38cf9361195fp-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+124", LIT (0x8p+124), { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215e8p-4), 1, LIT (0xc.82b8ec98b5e6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215e8p-4), 1, LIT (0xc.82b8ec98b5e6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215e8p-4), 1, LIT (0xc.82b8ec98b5e6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215fp-4), 1, LIT (0xc.82b8ec98b5e68p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152", LIT (0x8p-152), { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffcp-152), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffcp-152), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-972", LIT (0x8p-972), { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffcp-972), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-972), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffcp-972), 1, LIT (0xf.ffffffffffff8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769788p-4), 1, LIT (0xb.201e794508848p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776979p-4), 1, LIT (0xb.201e79450885p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769788p-4), 1, LIT (0xb.201e794508848p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776979p-4), 1, LIT (0xb.201e79450885p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776979p-4), 1, LIT (0xb.201e79450884p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776979p-4), 1, LIT (0xb.201e794508848p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776979p-4), 1, LIT (0xb.201e79450884p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769798p-4), 1, LIT (0xb.201e794508848p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fap-4), 1, LIT (0xb.201e83065041p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa8p-4), 1, LIT (0xb.201e830650418p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fap-4), 1, LIT (0xb.201e83065041p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa8p-4), 1, LIT (0xb.201e830650418p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb6002758778p-4), 1, LIT (0xb.201e77869a468p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb6002758778p-4), 1, LIT (0xb.201e77869a468p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb6002758778p-4), 1, LIT (0xb.201e77869a468p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275878p-4), 1, LIT (0xb.201e77869a47p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4", LIT (0xcp-4), { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc7868p-4), 1, LIT (0xb.b4ff632a908fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc7868p-4), 1, LIT (0xb.b4ff632a908f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc7868p-4), 1, LIT (0xb.b4ff632a908fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc787p-4), 1, LIT (0xb.b4ff632a908f8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fbp-4), 1, LIT (0x1.ff01000c9ae73p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb8p-4), 1, LIT (0x1.ff01000c9ae73p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fbp-4), 1, LIT (0x1.ff01000c9ae73p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb8p-4), 1, LIT (0x1.ff01000c9ae74p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e03152p-4), 1, LIT (0xe.26f8af8333f9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e03152p-4), 1, LIT (0xe.26f8af8333f9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e03152p-4), 1, LIT (0xe.26f8af8333f9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031524p-4), 1, LIT (0xe.26f8af8333f98p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac30008p-4), 1, LIT (-0xa.07bd3ab53ab98p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3001p-4), 1, LIT (-0xa.07bd3ab53ab98p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac30008p-4), 1, LIT (-0xa.07bd3ab53ab9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3001p-4), 1, LIT (-0xa.07bd3ab53ab9p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc90768p-4), 1, LIT (-0xd.b7f5359babdb8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc90768p-4), 1, LIT (-0xd.b7f5359babdb8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076p-4), 1, LIT (-0xd.b7f5359babdbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076p-4), 1, LIT (-0xd.b7f5359babdbp-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c56659848p-8), 1, LIT (0xf.fb2a030c5ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665985p-8), 1, LIT (0xf.fb2a030c5ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c56659848p-8), 1, LIT (0xf.fb2a030c5ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665985p-8), 1, LIT (0xf.fb2a030c5ae28p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96p-8), 1, LIT (-0xf.fff31767d5bbp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e97p-8), 1, LIT (-0xf.fff31767d5ba8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96p-8), 1, LIT (-0xf.fff31767d5ba8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e97p-8), 1, LIT (-0xf.fff31767d5ba8p-4) } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844abbp-4), 1, LIT (0xd.a5f963cdefe68p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba8p-4), 1, LIT (0xd.a5f963cdefe7p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba8p-4), 1, LIT (0xd.a5f963cdefe68p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba8p-4), 1, LIT (0xd.a5f963cdefe7p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0", LIT (-0x0p+0), { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffcb89dc2b98p-4), 1, LIT (0x8.7e0ea4db2f488671c85df72088p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffcb89dc2b97cp-4), 1, LIT (0x8.7e0ea4db2f488671c85df72088p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffcb89dc2b97cp-4), 1, LIT (0x8.7e0ea4db2f488671c85df72088p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffcb89dc2b97cp-4), 1, LIT (0x8.7e0ea4db2f488671c85df7208cp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p+64", LIT (-0x2p+64), { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e800f9b8a47b74p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc88p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e800f9b8a47b74p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc88p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e800f9b8a47b74p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc88p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e800f9b8a47b78p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc8cp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e2b6c62b7f4ep-24), 1, LIT (-0xf.ffffffffffcca8d98704239974p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e2b6c62b7f4dp-24), 1, LIT (-0xf.ffffffffffcca8d98704239974p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e2b6c62b7f4dp-24), 1, LIT (-0xf.ffffffffffcca8d9870423997p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e2b6c62b7f4dp-24), 1, LIT (-0xf.ffffffffffcca8d9870423997p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a308d313198a2e03p+0", LIT (-0x3.243f6a8885a308d313198a2e03p+0), { ERRNO_UNCHANGED, 1, LIT (-0x7.07344a4093822299f31d0082fp-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.07344a4093822299f31d0082fp-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.07344a4093822299f31d0082eep-108), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.07344a4093822299f31d0082eep-108), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a308d313198a2e04p+0", LIT (-0x3.243f6a8885a308d313198a2e04p+0), { ERRNO_UNCHANGED, 1, LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.f8cbb5bf6c7ddd660ce2ff7d14p-108), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a308d4p+0", LIT (-0x3.243f6a8885a308d4p+0), { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd64p-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd68p-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd64p-68), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbb5bf6c7ddd68p-68), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a308dp+0", LIT (-0x3.243f6a8885a308dp+0), { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344a40938222ap-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344a40938222ap-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344a409382229p-64), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344a409382229p-64), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8cbb5bf6c7dp-52), 1, LIT (-0xf.fffffffffffffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8cbb5bf6c7d8p-52), 1, LIT (-0xf.fffffffffffffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8cbb5bf6c7dp-52), 1, LIT (-0xf.ffffffffffffffffffffffffecp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8cbb5bf6c7d8p-52), 1, LIT (-0xf.ffffffffffffffffffffffffecp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707344a4093824p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707344a409382p-56), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707344a409382p-56), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707344a409382p-56), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd61896cb4f408p-24), 1, LIT (-0xf.ffffffffffeeca424938e84778p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd61896cb4f41p-24), 1, LIT (-0xf.ffffffffffeeca424938e84778p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd61896cb4f408p-24), 1, LIT (-0xf.ffffffffffeeca424938e84774p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd61896cb4f41p-24), 1, LIT (-0xf.ffffffffffeeca424938e84774p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770c93962abdb64p-4), 1, LIT (-0x1.febbf9949ecc133623bb8c8c5a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770c93962abdb6p-4), 1, LIT (-0x1.febbf9949ecc133623bb8c8c5ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770c93962abdb6p-4), 1, LIT (-0x1.febbf9949ecc133623bb8c8c5ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770c93962abdb6p-4), 1, LIT (-0x1.febbf9949ecc133623bb8c8c5ap-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1024", LIT (-0x4p-1024), { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-1024), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-1024), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x3.ffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x3.ffffffffffffcp-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076", LIT (-0x4p-1076), { ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-1076), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-1076), 1, LIT (0x1p+0) }, { ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-128", LIT (-0x4p-128), { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.ffffffffffffffffffffffffffp-128), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.ffffffffffffffffffffffffffp-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152", LIT (-0x8p-152), { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffffffffffffffep-152), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffffffffffffffep-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-972", LIT (-0x8p-972), { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x8p-972), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x8p-972), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x7.fffffffffffffffffffffffffcp-972), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x7.fffffffffffffffffffffffffcp-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b61139b09a7c88p-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b61139b09a7c88p-8), 1, LIT (-0xf.fff31767d5ba9e038d934070fp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b61139b09a7c8p-8), 1, LIT (-0xf.fff31767d5ba9e038d934070fp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b61139b09a7c8p-8), 1, LIT (-0xf.fff31767d5ba9e038d934070fp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { ERRNO_UNCHANGED, 1, LIT (0xe.f1a3e1dc468a921dddb4e37fbcp-4), 1, LIT (-0x5.b773d971a848e75c230605526ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.f1a3e1dc468a921dddb4e37fcp-4), 1, LIT (-0x5.b773d971a848e75c230605526ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.f1a3e1dc468a921dddb4e37fbcp-4), 1, LIT (-0x5.b773d971a848e75c2306055268p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.f1a3e1dc468a921dddb4e37fcp-4), 1, LIT (-0x5.b773d971a848e75c2306055268p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906cee446be048p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fbp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906cee446be048p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906cee446be048p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fbp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906cee446be04cp-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb4p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "+0", LIT (0x0p+0), { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5be750863ea3cp-4), 1, LIT (0x8.000014f038b1ab0e902f68119p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5be750863ea3cp-4), 1, LIT (0x8.000014f038b1ab0e902f68119p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5be750863ea3cp-4), 1, LIT (0x8.000014f038b1ab0e902f68119p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5be750863ea4p-4), 1, LIT (0x8.000014f038b1ab0e902f681194p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d73658465bb32e0f568p+0", LIT (0x1.0c152382d73658465bb32e0f568p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4), 1, LIT (0x7.fffffffffffffffffffffffffep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4), 1, LIT (0x7.fffffffffffffffffffffffffep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c8p-4), 1, LIT (0x8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d73658465bb32e0f56p+0", LIT (0x1.0c152382d73658465bb32e0f56p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83cp-4), 1, LIT (0x8.00000000000000000000000004p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83cp-4), 1, LIT (0x8.00000000000000000000000008p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83cp-4), 1, LIT (0x8.00000000000000000000000004p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4), 1, LIT (0x8.00000000000000000000000008p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d7365846p+0", LIT (0x1.0c152382d7365846p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d64e07fb091p-4), 1, LIT (0x8.0000000000000004f6a1a27d7cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d64e07fb091p-4), 1, LIT (0x8.0000000000000004f6a1a27d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d64e07fb091p-4), 1, LIT (0x8.0000000000000004f6a1a27d7cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539d64e07fb0914p-4), 1, LIT (0x8.0000000000000004f6a1a27d8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d7365848p+0", LIT (0x1.0c152382d7365848p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539e64e07fb091p-4), 1, LIT (0x7.ffffffffffffffe94026ba253p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539e64e07fb091p-4), 1, LIT (0x7.ffffffffffffffe94026ba2532p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539e64e07fb091p-4), 1, LIT (0x7.ffffffffffffffe94026ba253p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539e64e07fb0914p-4), 1, LIT (0x7.ffffffffffffffe94026ba2532p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7a64e07fb091p-4), 1, LIT (0x8.00000000000072a8d510c7c2ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7a64e07fb091p-4), 1, LIT (0x8.00000000000072a8d510c7c2a4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7a64e07fb091p-4), 1, LIT (0x8.00000000000072a8d510c7c2ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7a64e07fb0914p-4), 1, LIT (0x8.00000000000072a8d510c7c2a4p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577a64e07fb091p-4), 1, LIT (0x7.ffffffffffff94f4fdce055d4ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577a64e07fb091p-4), 1, LIT (0x7.ffffffffffff94f4fdce055d4ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577a64e07fb091p-4), 1, LIT (0x7.ffffffffffff94f4fdce055d4ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577a64e07fb0914p-4), 1, LIT (0x7.ffffffffffff94f4fdce055d5p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfb4fd88fd27f4p-4), 1, LIT (0x7.fffff939bdd18035537d20fefp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfb4fd88fd27f8p-4), 1, LIT (0x7.fffff939bdd18035537d20fef2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfb4fd88fd27f4p-4), 1, LIT (0x7.fffff939bdd18035537d20fefp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfb4fd88fd27f8p-4), 1, LIT (0x7.fffff939bdd18035537d20fef2p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae26229c919ec8f4p-4), 1, LIT (0xd.a82832da19f9891d9762fa659cp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae26229c919ec8f8p-4), 1, LIT (0xd.a82832da19f9891d9762fa65ap-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae26229c919ec8f4p-4), 1, LIT (0xd.a82832da19f9891d9762fa659cp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae26229c919ec8f8p-4), 1, LIT (0xd.a82832da19f9891d9762fa65ap-8) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdd053ee455e8p-4), 1, LIT (0xd.a82683a33cbebfffffffa29668p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdd053ee455ecp-4), 1, LIT (0xd.a82683a33cbebfffffffa29668p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdd053ee455e8p-4), 1, LIT (0xd.a82683a33cbebfffffffa29668p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdd053ee455ecp-4), 1, LIT (0xd.a82683a33cbebfffffffa2966cp-8) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d10238cc27b54p-4), 1, LIT (0xd.a8263394be6d0e58c1c35a8a38p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d10238cc27b58p-4), 1, LIT (0xd.a8263394be6d0e58c1c35a8a3cp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d10238cc27b54p-4), 1, LIT (0xd.a8263394be6d0e58c1c35a8a38p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d10238cc27b58p-4), 1, LIT (0xd.a8263394be6d0e58c1c35a8a3cp-8) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3661c108e134p-4), 1, LIT (0x1.4442d18469893610281a0f9b0e8p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3661c108e138p-4), 1, LIT (0x1.4442d18469893610281a0f9b0e8p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3661c108e134p-4), 1, LIT (0x1.4442d18469893610281a0f9b0e8p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3661c108e138p-4), 1, LIT (0x1.4442d18469893610281a0f9b0fp-24) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (0x1.898cc51701b839a252049c11148p-64) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.898cc51701b839a252049c1115p-64) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (0x1.898cc51701b839a252049c11148p-64) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.898cc51701b839a252049c1115p-64) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18469898cc517018p+0", LIT (0x1.921fb54442d18469898cc517018p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (0x3.839a252049c1114cf98e804177p-108) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x3.839a252049c1114cf98e804178p-108) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (0x3.839a252049c1114cf98e804177p-108) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x3.839a252049c1114cf98e804178p-108) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18469898cc51702p+0", LIT (0x1.921fb54442d18469898cc51702p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (-0x4.7c65dadfb63eeeb306717fbe8ap-108) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x4.7c65dadfb63eeeb306717fbe88p-108) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (-0x4.7c65dadfb63eeeb306717fbe88p-108) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x4.7c65dadfb63eeeb306717fbe88p-108) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (-0x7.6733ae8fe47c65dadfb63eeeb4p-68) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x7.6733ae8fe47c65dadfb63eeeb4p-68) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (-0x7.6733ae8fe47c65dadfb63eeeb2p-68) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x7.6733ae8fe47c65dadfb63eeeb2p-68) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (0x4.69898cc51701b839a252049c1p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x4.69898cc51701b839a252049c12p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (0x4.69898cc51701b839a252049c1p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x4.69898cc51701b839a252049c12p-56) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffff8p-4), 1, LIT (-0xb.9676733ae8fe47c65dadfb63fp-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (-0xb.9676733ae8fe47c65dadfb63ecp-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffff8p-4), 1, LIT (-0xb.9676733ae8fe47c65dadfb63ecp-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffffffffffffcp-4), 1, LIT (-0xb.9676733ae8fe47c65dadfb63ecp-56) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb290924e3a1148p-4), 1, LIT (-0xb.bbd2e7b96766266f1d18f3ead4p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb290924e3a1148p-4), 1, LIT (-0xb.bbd2e7b96766266f1d18f3eadp-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb290924e3a1148p-4), 1, LIT (-0xb.bbd2e7b96766266f1d18f3eadp-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb290924e3a114cp-4), 1, LIT (-0xb.bbd2e7b96766266f1d18f3eadp-28) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+120", LIT (0x1p+120), { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db5e5f1aa933f2p-4), 1, LIT (-0xe.d06685b36c66c4cf35c11f651cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db5e5f1aa933f4p-4), 1, LIT (-0xe.d06685b36c66c4cf35c11f6518p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db5e5f1aa933f2p-4), 1, LIT (-0xe.d06685b36c66c4cf35c11f6518p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db5e5f1aa933f4p-4), 1, LIT (-0xe.d06685b36c66c4cf35c11f6518p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+28", LIT (0x1p+28), { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5fdeb8807a18p-4), 1, LIT (-0x2.a62ba8824e5bcb065f5f3b8e5p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5fdeb8807a14p-4), 1, LIT (-0x2.a62ba8824e5bcb065f5f3b8e4fp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5fdeb8807a14p-4), 1, LIT (-0x2.a62ba8824e5bcb065f5f3b8e4fp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5fdeb8807a14p-4), 1, LIT (-0x2.a62ba8824e5bcb065f5f3b8e4fp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87d14de41dc994p-4), 1, LIT (0x8.5f167780e479c9a5c86ffce76p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87d14de41dc99p-4), 1, LIT (0x8.5f167780e479c9a5c86ffce76p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87d14de41dc99p-4), 1, LIT (0x8.5f167780e479c9a5c86ffce76p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87d14de41dc99p-4), 1, LIT (0x8.5f167780e479c9a5c86ffce764p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0debc87d70d1ap-4), 1, LIT (0xf.431dd7a36cf37de5c74544f6b4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0debc87d70d1ap-4), 1, LIT (0xf.431dd7a36cf37de5c74544f6b4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0debc87d70d18p-4), 1, LIT (0xf.431dd7a36cf37de5c74544f6b4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0debc87d70d18p-4), 1, LIT (0xf.431dd7a36cf37de5c74544f6b8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c70793712c4ff2cp-4), 1, LIT (0xa.dd6f6bacd20654c1404f52cdep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c70793712c4ff2cp-4), 1, LIT (0xa.dd6f6bacd20654c1404f52cdep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c70793712c4ff28p-4), 1, LIT (0xa.dd6f6bacd20654c1404f52cdep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c70793712c4ff28p-4), 1, LIT (0xa.dd6f6bacd20654c1404f52cde4p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+64", LIT (0x2p+64), { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e800f9b8a47b78p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc88p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e800f9b8a47b74p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc88p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e800f9b8a47b74p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc88p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e800f9b8a47b74p-8), 1, LIT (0xf.fb701e22987fbe68852ee2bc8cp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed895f9fa424ba9p-4), 1, LIT (-0xf.dfe6f2169e24f276e8027d91bcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed895f9fa424ba9p-4), 1, LIT (-0xf.dfe6f2169e24f276e8027d91bcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed895f9fa424ba9p-4), 1, LIT (-0xf.dfe6f2169e24f276e8027d91b8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed895f9fa424ba98p-4), 1, LIT (-0xf.dfe6f2169e24f276e8027d91b8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e2b6c62b7f4dp-24), 1, LIT (-0xf.ffffffffffcca8d98704239974p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e2b6c62b7f4dp-24), 1, LIT (-0xf.ffffffffffcca8d98704239974p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e2b6c62b7f4dp-24), 1, LIT (-0xf.ffffffffffcca8d9870423997p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e2b6c62b7f4ep-24), 1, LIT (-0xf.ffffffffffcca8d9870423997p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a308d313198a2e03p+0", LIT (0x3.243f6a8885a308d313198a2e03p+0), { ERRNO_UNCHANGED, 1, LIT (0x7.07344a4093822299f31d0082eep-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.07344a4093822299f31d0082fp-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.07344a4093822299f31d0082eep-108), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.07344a4093822299f31d0082fp-108), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a308d313198a2e04p+0", LIT (0x3.243f6a8885a308d313198a2e04p+0), { ERRNO_UNCHANGED, 1, LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d14p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.f8cbb5bf6c7ddd660ce2ff7d1p-108), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a308d4p+0", LIT (0x3.243f6a8885a308d4p+0), { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd68p-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd68p-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd64p-68), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbb5bf6c7ddd64p-68), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a308dp+0", LIT (0x3.243f6a8885a308dp+0), { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344a409382229p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344a40938222ap-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344a409382229p-64), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344a40938222ap-64), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d8p-52), 1, LIT (-0xf.fffffffffffffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8cbb5bf6c7d8p-52), 1, LIT (-0xf.fffffffffffffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8cbb5bf6c7dp-52), 1, LIT (-0xf.ffffffffffffffffffffffffecp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8cbb5bf6c7dp-52), 1, LIT (-0xf.ffffffffffffffffffffffffecp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707344a409382p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707344a409382p-56), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707344a409382p-56), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707344a4093824p-56), 1, LIT (-0xf.fffffffffffffffffffffffffcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd61896cb4f41p-24), 1, LIT (-0xf.ffffffffffeeca424938e84778p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd61896cb4f41p-24), 1, LIT (-0xf.ffffffffffeeca424938e84778p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd61896cb4f408p-24), 1, LIT (-0xf.ffffffffffeeca424938e84774p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd61896cb4f408p-24), 1, LIT (-0xf.ffffffffffeeca424938e84774p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b76173f9040638p-4), 1, LIT (-0xf.dfe902135fc1c18492e869a3fcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b76173f9040638p-4), 1, LIT (-0xf.dfe902135fc1c18492e869a3f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b76173f9040637f8p-4), 1, LIT (-0xf.dfe902135fc1c18492e869a3f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b76173f9040637f8p-4), 1, LIT (-0xf.dfe902135fc1c18492e869a3f8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p+48", LIT (0x4p+48), { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a986d98d6702p-4), 1, LIT (0xd.e3b88804f00552d6baba70947p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a986d98d6704p-4), 1, LIT (0xd.e3b88804f00552d6baba70947p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a986d98d6702p-4), 1, LIT (0xd.e3b88804f00552d6baba70947p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a986d98d6704p-4), 1, LIT (0xd.e3b88804f00552d6baba709474p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1024", LIT (0x4p-1024), { UNDERFLOW_EXCEPTION, 1, LIT (0x3.ffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x3.ffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076", LIT (0x4p-1076), { ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) }, { ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-128", LIT (0x4p-128), { ERRNO_UNCHANGED, 1, LIT (0x3.ffffffffffffffffffffffffffp-128), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.ffffffffffffffffffffffffffp-128), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e74fbeae63ee8p-4), 1, LIT (0xf.e006929f558d3eb50074ea600cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e74fbeae63ee8p-4), 1, LIT (0xf.e006929f558d3eb50074ea601p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e74fbeae63eep-4), 1, LIT (0xf.e006929f558d3eb50074ea600cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e74fbeae63eep-4), 1, LIT (0xf.e006929f558d3eb50074ea601p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cc8749212e72p+0", LIT (0x6.287cc8749212e72p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bca4e961470b28p-4), 1, LIT (0xf.e006929f558d8cc5d90bd654dcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bca4e961470b2p-4), 1, LIT (0xf.e006929f558d8cc5d90bd654ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bca4e961470b2p-4), 1, LIT (0xf.e006929f558d8cc5d90bd654dcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bca4e961470b2p-4), 1, LIT (0xf.e006929f558d8cc5d90bd654ep-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e5ab16d9008fp-4), 1, LIT (0xf.e006929f558dbe67de4071414cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e5ab16d9008e8p-4), 1, LIT (0xf.e006929f558dbe67de4071414cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e5ab16d9008e8p-4), 1, LIT (0xf.e006929f558dbe67de4071414cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e5ab16d9008e8p-4), 1, LIT (0xf.e006929f558dbe67de4071415p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3f77c1915bc98p-4), 1, LIT (0xf.e00691b6bde4251c3b197736a4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3f77c1915bc9p-4), 1, LIT (0xf.e00691b6bde4251c3b197736a8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3f77c1915bc9p-4), 1, LIT (0xf.e00691b6bde4251c3b197736a4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3f77c1915bc9p-4), 1, LIT (0xf.e00691b6bde4251c3b197736a8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce5d42fde40e7p-4), 1, LIT (0xf.e006a1ad17db69b4cedfec37d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce5d42fde40e7p-4), 1, LIT (0xf.e006a1ad17db69b4cedfec37dcp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce5d42fde40e68p-4), 1, LIT (0xf.e006a1ad17db69b4cedfec37d8p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce5d42fde40e68p-4), 1, LIT (0xf.e006a1ad17db69b4cedfec37dcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6ab95779c1eaep-4), 1, LIT (0xd.db3d742c26555af29a6e23c11cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6ab95779c1eaep-4), 1, LIT (0xd.db3d742c26555af29a6e23c12p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6ab95779c1eaep-4), 1, LIT (0xd.db3d742c26555af29a6e23c11cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6ab95779c1ebp-4), 1, LIT (0xd.db3d742c26555af29a6e23c12p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b2c232dd99707ab4p-4", LIT (0x8.60a91c16b9b2c232dd99707ab4p-4), { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000000000000000004p-4), 1, LIT (0xd.db3d742c265539d92ba16b83c8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b2c232dd99707abp-4", LIT (0x8.60a91c16b9b2c232dd99707abp-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffcp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffcp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffcp-4), 1, LIT (0xd.db3d742c265539d92ba16b83c4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffep-4), 1, LIT (0xd.db3d742c265539d92ba16b83c8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b2c23p-4", LIT (0x8.60a91c16b9b2c23p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffd84af2ec14p-4), 1, LIT (0xd.db3d742c265539da9a6e23c11cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffd84af2ec14p-4), 1, LIT (0xd.db3d742c265539da9a6e23c12p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffd84af2ec14p-4), 1, LIT (0xd.db3d742c265539da9a6e23c11cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffd84af2ec142p-4), 1, LIT (0xd.db3d742c265539da9a6e23c12p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b2c24p-4", LIT (0x8.60a91c16b9b2c24p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000b5feca2ed64p-4), 1, LIT (0xd.db3d742c265539d29a6e23c11cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000b5feca2ed68p-4), 1, LIT (0xd.db3d742c265539d29a6e23c12p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000b5feca2ed64p-4), 1, LIT (0xd.db3d742c265539d29a6e23c11cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000000b5feca2ed68p-4), 1, LIT (0xd.db3d742c265539d29a6e23c12p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000035858118fd5154p-4), 1, LIT (0xd.db3d742c26551af29a6e23c11cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000035858118fd5158p-4), 1, LIT (0xd.db3d742c26551af29a6e23c12p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000035858118fd5154p-4), 1, LIT (0xd.db3d742c26551af29a6e23c11cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.00000000000035858118fd5158p-4), 1, LIT (0xd.db3d742c26551af29a6e23c12p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050cf967fba7bc6p-4), 1, LIT (0xd.db3d7a37832aa678a274956dfcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050cf967fba7bc8p-4), 1, LIT (0xd.db3d7a37832aa678a274956dfcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050cf967fba7bc6p-4), 1, LIT (0xd.db3d7a37832aa678a274956dfcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050cf967fba7bc8p-4), 1, LIT (0xd.db3d7a37832aa678a274956ep-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168852c4130c64b4p-4), 1, LIT (0xd.db3d7237832e30f6465d599654p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168852c4130c64b4p-4), 1, LIT (0xd.db3d7237832e30f6465d599654p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168852c4130c64b4p-4), 1, LIT (0xd.db3d7237832e30f6465d599654p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.0000036321168852c4130c64b8p-4), 1, LIT (0xd.db3d7237832e30f6465d599658p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+1020", LIT (0x8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2d2e64a2845e4p-4), 1, LIT (-0xd.38cf9361195f50b10fac29dd94p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2d2e64a2845e4p-4), 1, LIT (-0xd.38cf9361195f50b10fac29dd9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2d2e64a2845e4p-4), 1, LIT (-0xd.38cf9361195f50b10fac29dd9p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2d2e64a2845e8p-4), 1, LIT (-0xd.38cf9361195f50b10fac29dd9p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+124", LIT (0x8p+124), { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89381836cafa8p-4), 1, LIT (0xc.82b8ec98b5e62fcf0b09fd10e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89381836cafacp-4), 1, LIT (0xc.82b8ec98b5e62fcf0b09fd10ecp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89381836cafa8p-4), 1, LIT (0xc.82b8ec98b5e62fcf0b09fd10e8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89381836cafacp-4), 1, LIT (0xc.82b8ec98b5e62fcf0b09fd10ecp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152", LIT (0x8p-152), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffep-152), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffffffffffffffep-152), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-972", LIT (0x8p-972), { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x7.fffffffffffffffffffffffffcp-972), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x8p-972), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x7.fffffffffffffffffffffffffcp-972), 1, LIT (0xf.fffffffffffffffffffffffffcp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x8p-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082980965c1a664p-4", LIT (0xc.d4966d92d17082980965c1a664p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356p-4), 1, LIT (0xb.201e79450884be22c53e47ed14p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7329128103564p-4), 1, LIT (0xb.201e79450884be22c53e47ed18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356p-4), 1, LIT (0xb.201e79450884be22c53e47ed14p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7329128103564p-4), 1, LIT (0xb.201e79450884be22c53e47ed18p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082980965c1a66p-4", LIT (0xc.d4966d92d17082980965c1a66p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356p-4), 1, LIT (0xb.201e79450884be22c53e47ed18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356p-4), 1, LIT (0xb.201e79450884be22c53e47ed18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e732912810356p-4), 1, LIT (0xb.201e79450884be22c53e47ed18p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7329128103564p-4), 1, LIT (0xb.201e79450884be22c53e47ed1cp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72cfa90010728p-4), 1, LIT (0xb.201e79450884be288bda3ee0dcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72cfa90010728p-4), 1, LIT (0xb.201e79450884be288bda3ee0dcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72cfa90010728p-4), 1, LIT (0xb.201e79450884be288bda3ee0dcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72cfa9001072cp-4), 1, LIT (0xb.201e79450884be288bda3ee0ep-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7381aae7a4c3p-4), 1, LIT (0xb.201e79450884be1d0c2440697p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7381aae7a4c3p-4), 1, LIT (0xb.201e79450884be1d0c24406974p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7381aae7a4c3p-4), 1, LIT (0xb.201e79450884be1d0c2440697p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e7381aae7a4c34p-4), 1, LIT (0xb.201e79450884be1d0c24406974p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e564d5ae94f8c8p-4), 1, LIT (0xb.201e79450884c00000000000cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e564d5ae94f8ccp-4), 1, LIT (0xb.201e79450884c00000000000cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e564d5ae94f8c8p-4), 1, LIT (0xb.201e79450884c00000000000cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e564d5ae94f8ccp-4), 1, LIT (0xb.201e79450884c00000000000c4p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e65c978bd3cecp-4), 1, LIT (0xb.201e794508846402500c44b4f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e65c978bd3cfp-4), 1, LIT (0xb.201e794508846402500c44b4f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e65c978bd3cecp-4), 1, LIT (0xb.201e794508846402500c44b4f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e65c978bd3cfp-4), 1, LIT (0xb.201e794508846402500c44b4fcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8acc8f4f3f18p-4), 1, LIT (0xb.201e83065041456a084c70f5ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8acc8f4f3f1cp-4), 1, LIT (0xb.201e83065041456a084c70f5ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8acc8f4f3f18p-4), 1, LIT (0xb.201e83065041456a084c70f5ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8acc8f4f3f1cp-4), 1, LIT (0xb.201e83065041456a084c70f5a4p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a60011766c8a3p-4), 1, LIT (0xb.201e77869a46ae20ce545c5c64p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a60011766c8a3p-4), 1, LIT (0xb.201e77869a46ae20ce545c5c68p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a60011766c8a3p-4), 1, LIT (0xb.201e77869a46ae20ce545c5c64p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a60011766c8a34p-4), 1, LIT (0xb.201e77869a46ae20ce545c5c68p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4", LIT (0xcp-4), { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2d966e1d6af14p-4), 1, LIT (0xb.b4ff632a908f73ec151839cb9cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2d966e1d6af14p-4), 1, LIT (0xb.b4ff632a908f73ec151839cb9cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2d966e1d6af14p-4), 1, LIT (0xb.b4ff632a908f73ec151839cb9cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2d966e1d6af18p-4), 1, LIT (0xb.b4ff632a908f73ec151839cbap-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ec139784e3b78p-4), 1, LIT (0x1.ff01000c9ae73630add558c9368p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ec139784e3b78p-4), 1, LIT (0x1.ff01000c9ae73630add558c9368p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ec139784e3b78p-4), 1, LIT (0x1.ff01000c9ae73630add558c9368p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ec139784e3b7cp-4), 1, LIT (0x1.ff01000c9ae73630add558c937p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b7cc3cd579a12p-4), 1, LIT (0xe.26f8af8333f9270e9c3e9f64f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b7cc3cd579a14p-4), 1, LIT (0xe.26f8af8333f9270e9c3e9f64f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b7cc3cd579a12p-4), 1, LIT (0xe.26f8af8333f9270e9c3e9f64f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b7cc3cd579a14p-4), 1, LIT (0xe.26f8af8333f9270e9c3e9f64fcp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddec0c69e7ddecp-4), 1, LIT (-0xa.07bd3ab53ab9710f3445538decp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddec0c69e7ddfp-4), 1, LIT (-0xa.07bd3ab53ab9710f3445538de8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddec0c69e7ddecp-4), 1, LIT (-0xa.07bd3ab53ab9710f3445538de8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddec0c69e7ddfp-4), 1, LIT (-0xa.07bd3ab53ab9710f3445538de8p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424bef27471714p-4), 1, LIT (-0xd.b7f5359babdb66be8d0cd3e294p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424bef2747171p-4), 1, LIT (-0xd.b7f5359babdb66be8d0cd3e294p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424bef2747171p-4), 1, LIT (-0xd.b7f5359babdb66be8d0cd3e29p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424bef2747171p-4), 1, LIT (-0xd.b7f5359babdb66be8d0cd3e29p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d8892761be1534p-8), 1, LIT (0xf.fb2a030c5ae20bdfe29fda198cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d8892761be1538p-8), 1, LIT (0xf.fb2a030c5ae20bdfe29fda199p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d8892761be1534p-8), 1, LIT (0xf.fb2a030c5ae20bdfe29fda198cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d8892761be1538p-8), 1, LIT (0xf.fb2a030c5ae20bdfe29fda199p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b61139b09a7c8p-8), 1, LIT (-0xf.fff31767d5ba9e038d934070f4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b61139b09a7c88p-8), 1, LIT (-0xf.fff31767d5ba9e038d934070fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b61139b09a7c8p-8), 1, LIT (-0xf.fff31767d5ba9e038d934070fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b61139b09a7c88p-8), 1, LIT (-0xf.fff31767d5ba9e038d934070fp-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { ERRNO_UNCHANGED, 1, LIT (-0xe.f1a3e1dc468a921dddb4e37fcp-4), 1, LIT (-0x5.b773d971a848e75c230605526ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.f1a3e1dc468a921dddb4e37fcp-4), 1, LIT (-0x5.b773d971a848e75c230605526ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.f1a3e1dc468a921dddb4e37fbcp-4), 1, LIT (-0x5.b773d971a848e75c2306055268p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.f1a3e1dc468a921dddb4e37fbcp-4), 1, LIT (-0x5.b773d971a848e75c2306055268p-4) } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906cee446be04cp-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906cee446be048p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906cee446be048p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fbp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906cee446be048p-4), 1, LIT (0xd.a5f963cdefe6d529f6b6009fb4p-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0", LIT (-0x0p+0), { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95426p-4), 1, LIT (0x8.7e0ea4db2f48867p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95426p-4), 1, LIT (0x8.7e0ea4db2f48867p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffp-4), 1, LIT (0x8.7e0ea4db2f48867p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffp-4), 1, LIT (0x8.7e0ea4db2f48868p-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p+64", LIT (-0x2p+64), { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e81p-8), 1, LIT (0xf.fb701e22987fbe7p-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p-16384", LIT (-0x2p-16384), { UNDERFLOW_EXCEPTION, 1, LIT (-0x2p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x2p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x1.fffffffffffffff8p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x1.fffffffffffffff8p-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e4p-24), 1, LIT (-0xf.ffffffffffcca8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e4p-24), 1, LIT (-0xf.ffffffffffcca8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063ep-24), 1, LIT (-0xf.ffffffffffcca8dp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063ep-24), 1, LIT (-0xf.ffffffffffcca8dp-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6a8885a308d4p+0", LIT (-0x3.243f6a8885a308d4p+0), { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbcp-68), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6a8885a308dp+0", LIT (-0x3.243f6a8885a308dp+0), { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707348p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344p-64), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344p-64), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8p-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8p-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8p-52), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8fap-52), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03708p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707p-56), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707p-56), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca5p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd8p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770dp-4), 1, LIT (-0x1.febbf9949ecc1338p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770dp-4), 1, LIT (-0x1.febbf9949ecc1336p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770cp-4), 1, LIT (-0x1.febbf9949ecc1336p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770cp-4), 1, LIT (-0x1.febbf9949ecc1336p-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1024", LIT (-0x4p-1024), { ERRNO_UNCHANGED, 1, LIT (-0x4p-1024), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-1024), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076", LIT (-0x4p-1076), { ERRNO_UNCHANGED, 1, LIT (-0x4p-1076), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-1076), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-1076), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-1076), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-128", LIT (-0x4p-128), { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-128), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384", LIT (-0x4p-16384), { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x4p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x4p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x3.fffffffffffffff8p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x3.fffffffffffffff8p-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152", LIT (-0x8p-152), { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffff8p-152), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffff8p-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-16448", LIT (-0x8p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (-0x8p-16448), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x8p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-972", LIT (-0x8p-972), { ERRNO_UNCHANGED, 1, LIT (-0x8p-972), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-972), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffff8p-972), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffff8p-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b62p-8), 1, LIT (-0xf.fff31767d5ba9e1p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b62p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b6p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b6p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7cp-4), 1, LIT (-0x2.002ef4018753d50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7cp-4), 1, LIT (-0x2.002ef4018753d50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7bp-4), 1, LIT (-0x2.002ef4018753d508p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7bp-4), 1, LIT (-0x2.002ef4018753d508p-4) } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906p-4), 1, LIT (0xd.a5f963cdefe6d52p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba907p-4), 1, LIT (0xd.a5f963cdefe6d53p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906p-4), 1, LIT (0xd.a5f963cdefe6d52p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba907p-4), 1, LIT (0xd.a5f963cdefe6d53p-4) } },
#endif
#if (TEST_COND_intel96)
    { "+0", LIT (0x0p+0), { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5bp-4), 1, LIT (0x8.000014f038b1abp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5cp-4), 1, LIT (0x8.000014f038b1ab1p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5bp-4), 1, LIT (0x8.000014f038b1abp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5cp-4), 1, LIT (0x8.000014f038b1ab1p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c152382d7365846p+0", LIT (0x1.0c152382d7365846p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539dp-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539dp-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539dp-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539ep-4), 1, LIT (0x8.000000000000001p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c152382d7365848p+0", LIT (0x1.0c152382d7365848p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539ep-4), 1, LIT (0x7.ffffffffffffffe8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539ep-4), 1, LIT (0x7.ffffffffffffffe8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539ep-4), 1, LIT (0x7.ffffffffffffffe8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539fp-4), 1, LIT (0x7.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7ap-4), 1, LIT (0x8.00000000000072ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7ap-4), 1, LIT (0x8.00000000000072bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7ap-4), 1, LIT (0x8.00000000000072ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7bp-4), 1, LIT (0x8.00000000000072bp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577ap-4), 1, LIT (0x7.ffffffffffff94fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577ap-4), 1, LIT (0x7.ffffffffffff94f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577ap-4), 1, LIT (0x7.ffffffffffff94fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577bp-4), 1, LIT (0x7.ffffffffffff94f8p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfbp-4), 1, LIT (0x7.fffff939bdd1803p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfbp-4), 1, LIT (0x7.fffff939bdd18038p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfbp-4), 1, LIT (0x7.fffff939bdd1803p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfcp-4), 1, LIT (0x7.fffff939bdd18038p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae262p-4), 1, LIT (0xd.a82832da19f9891p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae262p-4), 1, LIT (0xd.a82832da19f9892p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae262p-4), 1, LIT (0xd.a82832da19f9891p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae263p-4), 1, LIT (0xd.a82832da19f9892p-8) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdp-4), 1, LIT (0xd.a82683a33cbebffp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbep-4), 1, LIT (0xd.a82683a33cbecp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdp-4), 1, LIT (0xd.a82683a33cbebffp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbep-4), 1, LIT (0xd.a82683a33cbecp-8) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d1p-4), 1, LIT (0xd.a8263394be6d0e5p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d1p-4), 1, LIT (0xd.a8263394be6d0e6p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d1p-4), 1, LIT (0xd.a8263394be6d0e5p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d2p-4), 1, LIT (0xd.a8263394be6d0e6p-8) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3p-4), 1, LIT (0x1.4442d1846989361p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3p-4), 1, LIT (0x1.4442d1846989361p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3p-4), 1, LIT (0x1.4442d1846989361p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a4p-4), 1, LIT (0x1.4442d18469893612p-24) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (0x1.898cc51701b839a2p-64) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.898cc51701b839a2p-64) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (0x1.898cc51701b839a2p-64) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.898cc51701b839a4p-64) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (-0x7.6733ae8fe47c65ep-68) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x7.6733ae8fe47c65d8p-68) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (-0x7.6733ae8fe47c65d8p-68) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x7.6733ae8fe47c65d8p-68) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (0x4.69898cc51701b838p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x4.69898cc51701b838p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (0x4.69898cc51701b838p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x4.69898cc51701b84p-56) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (-0xb.9676733ae8fe47dp-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xb.9676733ae8fe47cp-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (-0xb.9676733ae8fe47cp-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xb.9676733ae8fe47cp-56) } },
#endif
#if (TEST_COND_intel96)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb29p-4), 1, LIT (-0xb.bbd2e7b96766267p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb29p-4), 1, LIT (-0xb.bbd2e7b96766267p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb29p-4), 1, LIT (-0xb.bbd2e7b96766266p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb2ap-4), 1, LIT (-0xb.bbd2e7b96766266p-28) } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+120", LIT (0x1p+120), { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db58p-4), 1, LIT (-0xe.d06685b36c66c4dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db6p-4), 1, LIT (-0xe.d06685b36c66c4dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db58p-4), 1, LIT (-0xe.d06685b36c66c4cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db6p-4), 1, LIT (-0xe.d06685b36c66c4cp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+28", LIT (0x1p+28), { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a6p-4), 1, LIT (-0x2.a62ba8824e5bcb08p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a6p-4), 1, LIT (-0x2.a62ba8824e5bcb08p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5p-4), 1, LIT (-0x2.a62ba8824e5bcb04p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5p-4), 1, LIT (-0x2.a62ba8824e5bcb04p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87ep-4), 1, LIT (0x8.5f167780e479c9ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87dp-4), 1, LIT (0x8.5f167780e479c9ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87dp-4), 1, LIT (0x8.5f167780e479c9ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87dp-4), 1, LIT (0x8.5f167780e479c9bp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0ep-4), 1, LIT (0xf.431dd7a36cf37dep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0ep-4), 1, LIT (0xf.431dd7a36cf37dep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0d8p-4), 1, LIT (0xf.431dd7a36cf37dep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0d8p-4), 1, LIT (0xf.431dd7a36cf37dfp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c708p-4), 1, LIT (0xa.dd6f6bacd20654cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c708p-4), 1, LIT (0xa.dd6f6bacd20654cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c707p-4), 1, LIT (0xa.dd6f6bacd20654cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c707p-4), 1, LIT (0xa.dd6f6bacd20654dp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+64", LIT (0x2p+64), { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e81p-8), 1, LIT (0xf.fb701e22987fbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe7p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe7p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16384", LIT (0x2p-16384), { UNDERFLOW_EXCEPTION, 1, LIT (0x1.fffffffffffffff8p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x2p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x1.fffffffffffffff8p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x2p-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed894p-4), 1, LIT (-0xf.dfe6f2169e24f28p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed896p-4), 1, LIT (-0xf.dfe6f2169e24f27p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed894p-4), 1, LIT (-0xf.dfe6f2169e24f27p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed896p-4), 1, LIT (-0xf.dfe6f2169e24f27p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063ep-24), 1, LIT (-0xf.ffffffffffcca8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e4p-24), 1, LIT (-0xf.ffffffffffcca8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063ep-24), 1, LIT (-0xf.ffffffffffcca8dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e4p-24), 1, LIT (-0xf.ffffffffffcca8dp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6a8885a308d4p+0", LIT (0x3.243f6a8885a308d4p+0), { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbcp-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6a8885a308dp+0", LIT (0x3.243f6a8885a308dp+0), { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344p-64), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707348p-64), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8fap-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8p-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8p-52), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8p-52), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707p-56), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03708p-56), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd8p-24), 1, LIT (-0xf.ffffffffffeeca5p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7618p-4), 1, LIT (-0xf.dfe902135fc1c19p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7618p-4), 1, LIT (-0xf.dfe902135fc1c18p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7616p-4), 1, LIT (-0xf.dfe902135fc1c18p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7616p-4), 1, LIT (-0xf.dfe902135fc1c18p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x4p+48", LIT (0x4p+48), { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a8p-4), 1, LIT (0xd.e3b88804f00552dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a8p-4), 1, LIT (0xd.e3b88804f00552dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a8p-4), 1, LIT (0xd.e3b88804f00552dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8bp-4), 1, LIT (0xd.e3b88804f00552ep-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1024", LIT (0x4p-1024), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076", LIT (0x4p-1076), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-1076), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-1076), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-128", LIT (0x4p-128), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-128), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-128), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384", LIT (0x4p-16384), { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x3.fffffffffffffff8p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x4p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x3.fffffffffffffff8p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x4p-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e8p-4), 1, LIT (0xf.e006929f558d3ebp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e8p-4), 1, LIT (0xf.e006929f558d3ebp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e6p-4), 1, LIT (0xf.e006929f558d3ebp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e6p-4), 1, LIT (0xf.e006929f558d3ecp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cc8749212e72p+0", LIT (0x6.287cc8749212e72p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bccp-4), 1, LIT (0xf.e006929f558d8ccp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bcap-4), 1, LIT (0xf.e006929f558d8ccp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bcap-4), 1, LIT (0xf.e006929f558d8ccp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bcap-4), 1, LIT (0xf.e006929f558d8cdp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e6p-4), 1, LIT (0xf.e006929f558dbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e6p-4), 1, LIT (0xf.e006929f558dbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e4p-4), 1, LIT (0xf.e006929f558dbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e4p-4), 1, LIT (0xf.e006929f558dbe7p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c4p-4), 1, LIT (0xf.e00691b6bde4251p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c4p-4), 1, LIT (0xf.e00691b6bde4252p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3ep-4), 1, LIT (0xf.e00691b6bde4251p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3ep-4), 1, LIT (0xf.e00691b6bde4252p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce6p-4), 1, LIT (0xf.e006a1ad17db69bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce6p-4), 1, LIT (0xf.e006a1ad17db69bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce4p-4), 1, LIT (0xf.e006a1ad17db69bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce4p-4), 1, LIT (0xf.e006a1ad17db69cp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6a8p-4), 1, LIT (0xd.db3d742c26555afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6a8p-4), 1, LIT (0xd.db3d742c26555afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6a8p-4), 1, LIT (0xd.db3d742c26555afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6bp-4), 1, LIT (0xd.db3d742c26555bp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91c16b9b2c23p-4", LIT (0x8.60a91c16b9b2c23p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539ep-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91c16b9b2c24p-4", LIT (0x8.60a91c16b9b2c24p-4), { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000001p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000001p-4), 1, LIT (0xd.db3d742c265539ep-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000358p-4), 1, LIT (0xd.db3d742c26551afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000358p-4), 1, LIT (0xd.db3d742c26551afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000358p-4), 1, LIT (0xd.db3d742c26551afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000359p-4), 1, LIT (0xd.db3d742c26551bp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050c8p-4), 1, LIT (0xd.db3d7a37832aa67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050dp-4), 1, LIT (0xd.db3d7a37832aa68p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050c8p-4), 1, LIT (0xd.db3d7a37832aa67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050dp-4), 1, LIT (0xd.db3d7a37832aa68p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.000003632116885p-4), 1, LIT (0xd.db3d7237832e30fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000003632116885p-4), 1, LIT (0xd.db3d7237832e30fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000003632116885p-4), 1, LIT (0xd.db3d7237832e30fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000003632116886p-4), 1, LIT (0xd.db3d7237832e31p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+1020", LIT (0x8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2dp-4), 1, LIT (-0xd.38cf9361195f50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2dp-4), 1, LIT (-0xd.38cf9361195f50bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2dp-4), 1, LIT (-0xd.38cf9361195f50bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2ep-4), 1, LIT (-0xd.38cf9361195f50bp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+124", LIT (0x8p+124), { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89p-4), 1, LIT (0xc.82b8ec98b5e62fcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89p-4), 1, LIT (0xc.82b8ec98b5e62fdp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89p-4), 1, LIT (0xc.82b8ec98b5e62fcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb8ap-4), 1, LIT (0xc.82b8ec98b5e62fdp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+16380", LIT (0x8p+16380), { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc68818p-4), 1, LIT (0xe.bcc2fc82ae39ebfp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc6882p-4), 1, LIT (0xe.bcc2fc82ae39ecp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc68818p-4), 1, LIT (0xe.bcc2fc82ae39ebfp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc6882p-4), 1, LIT (0xe.bcc2fc82ae39ecp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152", LIT (0x8p-152), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-152), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-152), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448", LIT (0x8p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x8p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x8p-16448), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-972", LIT (0x8p-972), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-972), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-972), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-972), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72p-4), 1, LIT (0xb.201e79450884be2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73p-4), 1, LIT (0xb.201e79450884be3p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72p-4), 1, LIT (0xb.201e79450884be2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73p-4), 1, LIT (0xb.201e79450884be3p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73p-4), 1, LIT (0xb.201e79450884be1p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e74p-4), 1, LIT (0xb.201e79450884be2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73p-4), 1, LIT (0xb.201e79450884be1p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e74p-4), 1, LIT (0xb.201e79450884be2p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e56p-4), 1, LIT (0xb.201e79450884cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e56p-4), 1, LIT (0xb.201e79450884cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e56p-4), 1, LIT (0xb.201e79450884cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e57p-4), 1, LIT (0xb.201e79450884c01p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e6p-4), 1, LIT (0xb.201e7945088464p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e6p-4), 1, LIT (0xb.201e7945088464p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e6p-4), 1, LIT (0xb.201e7945088464p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e7p-4), 1, LIT (0xb.201e79450884641p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8p-4), 1, LIT (0xb.201e83065041456p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f9p-4), 1, LIT (0xb.201e83065041457p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8p-4), 1, LIT (0xb.201e83065041456p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f9p-4), 1, LIT (0xb.201e83065041457p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a6p-4), 1, LIT (0xb.201e77869a46ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a6p-4), 1, LIT (0xb.201e77869a46ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a6p-4), 1, LIT (0xb.201e77869a46ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a61p-4), 1, LIT (0xb.201e77869a46ae3p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4", LIT (0xcp-4), { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2dp-4), 1, LIT (0xb.b4ff632a908f73ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2ep-4), 1, LIT (0xb.b4ff632a908f73fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2dp-4), 1, LIT (0xb.b4ff632a908f73ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2ep-4), 1, LIT (0xb.b4ff632a908f73fp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ecp-4), 1, LIT (0x1.ff01000c9ae7363p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ecp-4), 1, LIT (0x1.ff01000c9ae7363p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ecp-4), 1, LIT (0x1.ff01000c9ae7363p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4edp-4), 1, LIT (0x1.ff01000c9ae73632p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b78p-4), 1, LIT (0xe.26f8af8333f927p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b8p-4), 1, LIT (0xe.26f8af8333f9271p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b78p-4), 1, LIT (0xe.26f8af8333f927p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b8p-4), 1, LIT (0xe.26f8af8333f9271p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddep-4), 1, LIT (-0xa.07bd3ab53ab9711p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddfp-4), 1, LIT (-0xa.07bd3ab53ab9711p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddep-4), 1, LIT (-0xa.07bd3ab53ab971p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddfp-4), 1, LIT (-0xa.07bd3ab53ab971p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076425p-4), 1, LIT (-0xd.b7f5359babdb66cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076425p-4), 1, LIT (-0xd.b7f5359babdb66cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424p-4), 1, LIT (-0xd.b7f5359babdb66bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424p-4), 1, LIT (-0xd.b7f5359babdb66bp-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d88p-8), 1, LIT (0xf.fb2a030c5ae20bdp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d89p-8), 1, LIT (0xf.fb2a030c5ae20bep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d88p-8), 1, LIT (0xf.fb2a030c5ae20bdp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d89p-8), 1, LIT (0xf.fb2a030c5ae20bep-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b6p-8), 1, LIT (-0xf.fff31767d5ba9e1p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b62p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b6p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b62p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7bp-4), 1, LIT (-0x2.002ef4018753d50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7cp-4), 1, LIT (-0x2.002ef4018753d50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7bp-4), 1, LIT (-0x2.002ef4018753d508p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7cp-4), 1, LIT (-0x2.002ef4018753d508p-4) } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba907p-4), 1, LIT (0xd.a5f963cdefe6d52p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba907p-4), 1, LIT (0xd.a5f963cdefe6d53p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906p-4), 1, LIT (0xd.a5f963cdefe6d52p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906p-4), 1, LIT (0xd.a5f963cdefe6d53p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0", LIT (-0x0p+0), { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1.02e34cp+0", LIT (-0x1.02e34cp+0), { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95426p-4), 1, LIT (0x8.7e0ea4db2f48867p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95426p-4), 1, LIT (0x8.7e0ea4db2f48867p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffp-4), 1, LIT (0x8.7e0ea4db2f48867p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.8f691a7a95425ffp-4), 1, LIT (0x8.7e0ea4db2f48868p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p+64", LIT (-0x2p+64), { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe7p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.143e153b0701e81p-8), 1, LIT (0xf.fb701e22987fbe7p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p-16384", LIT (-0x2p-16384), { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x2p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x2p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x1.fffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (-0x1.fffffffffffffffcp-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f68p+0", LIT (-0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e4p-24), 1, LIT (-0xf.ffffffffffcca8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063e4p-24), 1, LIT (-0xf.ffffffffffcca8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063ep-24), 1, LIT (-0xf.ffffffffffcca8dp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x2.8885a308d31063ep-24), 1, LIT (-0xf.ffffffffffcca8dp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6a8885a308d4p+0", LIT (-0x3.243f6a8885a308d4p+0), { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xe.ce675d1fc8f8cbcp-68), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6a8885a308dp+0", LIT (-0x3.243f6a8885a308dp+0), { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707348p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344p-64), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.13198a2e03707344p-64), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6a8885a32p+0", LIT (-0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8p-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8p-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8f8p-52), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.72cece675d1fc8fap-52), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6a8885a3p+0", LIT (-0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03708p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707p-56), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.d313198a2e03707p-56), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.243f6cp+0", LIT (-0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca5p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.777a5cf72cec5fd8p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3.3de320f6be87ep+1020", LIT (-0x3.3de320f6be87ep+1020), { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770dp-4), 1, LIT (-0x1.febbf9949ecc1338p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770dp-4), 1, LIT (-0x1.febbf9949ecc1336p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770cp-4), 1, LIT (-0x1.febbf9949ecc1336p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.e00885042dd770cp-4), 1, LIT (-0x1.febbf9949ecc1336p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1024", LIT (-0x4p-1024), { ERRNO_UNCHANGED, 1, LIT (-0x4p-1024), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-1024), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076", LIT (-0x4p-1076), { ERRNO_UNCHANGED, 1, LIT (-0x4p-1076), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-1076), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-1076), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-1076), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-128", LIT (-0x4p-128), { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-128), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384", LIT (-0x4p-16384), { ERRNO_UNCHANGED, 1, LIT (-0x4p-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4p-16384), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x3.fffffffffffffffcp-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16448", LIT (-0x4p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-16448), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152", LIT (-0x8p-152), { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffff8p-152), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffff8p-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-16448", LIT (-0x8p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (-0x8p-16448), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x8p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-16448), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (-0x4p-16448), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-972", LIT (-0x8p-972), { ERRNO_UNCHANGED, 1, LIT (-0x8p-972), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8p-972), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffff8p-972), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x7.fffffffffffffff8p-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b62p-8), 1, LIT (-0xf.fff31767d5ba9e1p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b62p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b6p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.452fc98b34e96b6p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7cp-4), 1, LIT (-0x2.002ef4018753d50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7cp-4), 1, LIT (-0x2.002ef4018753d50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7bp-4), 1, LIT (-0x2.002ef4018753d508p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.dfd9d4b6d0e5f7bp-4), 1, LIT (-0x2.002ef4018753d508p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906p-4), 1, LIT (0xd.a5f963cdefe6d52p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba907p-4), 1, LIT (0xd.a5f963cdefe6d53p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba906p-4), 1, LIT (0xd.a5f963cdefe6d52p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.599b32844aba907p-4), 1, LIT (0xd.a5f963cdefe6d53p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "+0", LIT (0x0p+0), { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x0p+0), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c1522p+0", LIT (0x1.0c1522p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5bp-4), 1, LIT (0x8.000014f038b1abp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5cp-4), 1, LIT (0x8.000014f038b1ab1p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5bp-4), 1, LIT (0x8.000014f038b1abp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d68156c92a5cp-4), 1, LIT (0x8.000014f038b1ab1p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c152382d7365846p+0", LIT (0x1.0c152382d7365846p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539dp-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539dp-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539dp-4), 1, LIT (0x8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539ep-4), 1, LIT (0x8.000000000000001p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c152382d7365848p+0", LIT (0x1.0c152382d7365848p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539ep-4), 1, LIT (0x7.ffffffffffffffe8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539ep-4), 1, LIT (0x7.ffffffffffffffe8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539ep-4), 1, LIT (0x7.ffffffffffffffe8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265539fp-4), 1, LIT (0x7.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c152382d7365p+0", LIT (0x1.0c152382d7365p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7ap-4), 1, LIT (0x8.00000000000072ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7ap-4), 1, LIT (0x8.00000000000072bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7ap-4), 1, LIT (0x8.00000000000072ap-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c2654f7bp-4), 1, LIT (0x8.00000000000072bp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c152382d7366p+0", LIT (0x1.0c152382d7366p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577ap-4), 1, LIT (0x7.ffffffffffff94fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577ap-4), 1, LIT (0x7.ffffffffffff94f8p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577ap-4), 1, LIT (0x7.ffffffffffff94fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d742c265577bp-4), 1, LIT (0x7.ffffffffffff94f8p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0c1524p+0", LIT (0x1.0c1524p+0), { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfbp-4), 1, LIT (0x7.fffff939bdd1803p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfbp-4), 1, LIT (0x7.fffff939bdd18038p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfbp-4), 1, LIT (0x7.fffff939bdd1803p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xd.db3d78156ca0cfcp-4), 1, LIT (0x7.fffff939bdd18038p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e4p+0", LIT (0x1.8475e4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae262p-4), 1, LIT (0xd.a82832da19f9891p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae262p-4), 1, LIT (0xd.a82832da19f9892p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae262p-4), 1, LIT (0xd.a82832da19f9891p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adb8953ae263p-4), 1, LIT (0xd.a82832da19f9892p-8) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e5afd4481p+0", LIT (0x1.8475e5afd4481p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdp-4), 1, LIT (0xd.a82683a33cbebffp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbep-4), 1, LIT (0xd.a82683a33cbecp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbdp-4), 1, LIT (0xd.a82683a33cbebffp-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2adcf9ea83dbep-4), 1, LIT (0xd.a82683a33cbecp-8) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8475e6p+0", LIT (0x1.8475e6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d1p-4), 1, LIT (0xd.a8263394be6d0e5p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d1p-4), 1, LIT (0xd.a8263394be6d0e6p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d1p-4), 1, LIT (0xd.a8263394be6d0e5p-8) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fa2add3e58948d2p-4), 1, LIT (0xd.a8263394be6d0e6p-8) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb4p+0", LIT (0x1.921fb4p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3p-4), 1, LIT (0x1.4442d1846989361p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3p-4), 1, LIT (0x1.4442d1846989361p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a3p-4), 1, LIT (0x1.4442d1846989361p-24) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffff32a4p-4), 1, LIT (0x1.4442d18469893612p-24) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d18468p+0", LIT (0x1.921fb54442d18468p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (0x1.898cc51701b839a2p-64) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.898cc51701b839a2p-64) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (0x1.898cc51701b839a2p-64) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x1.898cc51701b839a4p-64) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d1846ap+0", LIT (0x1.921fb54442d1846ap+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (-0x7.6733ae8fe47c65ep-68) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x7.6733ae8fe47c65d8p-68) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (-0x7.6733ae8fe47c65d8p-68) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0x7.6733ae8fe47c65d8p-68) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d18p+0", LIT (0x1.921fb54442d18p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (0x4.69898cc51701b838p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x4.69898cc51701b838p-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (0x4.69898cc51701b838p-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (0x4.69898cc51701b84p-56) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb54442d19p+0", LIT (0x1.921fb54442d19p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (-0xb.9676733ae8fe47dp-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xb.9676733ae8fe47cp-56) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffffffp-4), 1, LIT (-0xb.9676733ae8fe47cp-56) }, { ERRNO_UNCHANGED, 1, LIT (0x1p+0), 1, LIT (-0xb.9676733ae8fe47cp-56) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.921fb6p+0", LIT (0x1.921fb6p+0), { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb29p-4), 1, LIT (-0xb.bbd2e7b96766267p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb29p-4), 1, LIT (-0xb.bbd2e7b96766267p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb29p-4), 1, LIT (-0xb.bbd2e7b96766266p-28) }, { ERRNO_UNCHANGED, 1, LIT (0xf.fffffffffffbb2ap-4), 1, LIT (-0xb.bbd2e7b96766266p-28) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+120", LIT (0x1p+120), { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db58p-4), 1, LIT (-0xe.d06685b36c66c4dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db6p-4), 1, LIT (-0xe.d06685b36c66c4dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db58p-4), 1, LIT (-0xe.d06685b36c66c4cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.0b8d19579bf2db6p-4), 1, LIT (-0xe.d06685b36c66c4cp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+28", LIT (0x1p+28), { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a6p-4), 1, LIT (-0x2.a62ba8824e5bcb08p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a6p-4), 1, LIT (-0x2.a62ba8824e5bcb08p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5p-4), 1, LIT (-0x2.a62ba8824e5bcb04p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xf.c777c6b36a750a5p-4), 1, LIT (-0x2.a62ba8824e5bcb04p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19e0c9bab24p+72", LIT (0x2.1e19e0c9bab24p+72), { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87ep-4), 1, LIT (0x8.5f167780e479c9ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87dp-4), 1, LIT (0x8.5f167780e479c9ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87dp-4), 1, LIT (0x8.5f167780e479c9ap-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xd.a29d5bb5f9cb87dp-4), 1, LIT (0x8.5f167780e479c9bp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19e4p+72", LIT (0x2.1e19e4p+72), { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0ep-4), 1, LIT (0xf.431dd7a36cf37dep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0ep-4), 1, LIT (0xf.431dd7a36cf37dep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0d8p-4), 1, LIT (0xf.431dd7a36cf37dep-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x4.cd7e86c4077bf0d8p-4), 1, LIT (0xf.431dd7a36cf37dfp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1e19ep+72", LIT (0x2.1e19ep+72), { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c708p-4), 1, LIT (0xa.dd6f6bacd20654cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c708p-4), 1, LIT (0xa.dd6f6bacd20654cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c707p-4), 1, LIT (0xa.dd6f6bacd20654cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xb.becc47ab1b8c707p-4), 1, LIT (0xa.dd6f6bacd20654dp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+64", LIT (0x2p+64), { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e81p-8), 1, LIT (0xf.fb701e22987fbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe7p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xc.143e153b0701e8p-8), 1, LIT (0xf.fb701e22987fbe7p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16384", LIT (0x2p-16384), { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x1.fffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x2p-16384), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x1.fffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION_OK, 1, LIT (0x2p-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.042d88p+0", LIT (0x3.042d88p+0), { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed894p-4), 1, LIT (-0xf.dfe6f2169e24f28p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed896p-4), 1, LIT (-0xf.dfe6f2169e24f27p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed894p-4), 1, LIT (-0xf.dfe6f2169e24f27p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.ffc6da9f1ffed896p-4), 1, LIT (-0xf.dfe6f2169e24f27p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f68p+0", LIT (0x3.243f68p+0), { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063ep-24), 1, LIT (-0xf.ffffffffffcca8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e4p-24), 1, LIT (-0xf.ffffffffffcca8ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063ep-24), 1, LIT (-0xf.ffffffffffcca8dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x2.8885a308d31063e4p-24), 1, LIT (-0xf.ffffffffffcca8dp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6a8885a308d4p+0", LIT (0x3.243f6a8885a308d4p+0), { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbcp-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0xe.ce675d1fc8f8cbbp-68), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6a8885a308dp+0", LIT (0x3.243f6a8885a308dp+0), { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344p-64), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707344p-64), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x3.13198a2e03707348p-64), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6a8885a32p+0", LIT (0x3.243f6a8885a32p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8fap-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8p-52), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8p-52), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.72cece675d1fc8f8p-52), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6a8885a3p+0", LIT (0x3.243f6a8885a3p+0), { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707p-56), 1, LIT (-0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03707p-56), 1, LIT (-0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.d313198a2e03708p-56), 1, LIT (-0xf.fffffffffffffffp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.243f6cp+0", LIT (0x3.243f6cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd8p-24), 1, LIT (-0xf.ffffffffffeeca5p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.777a5cf72cec5fd6p-24), 1, LIT (-0xf.ffffffffffeeca4p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.7857dp+68", LIT (0x4.7857dp+68), { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7618p-4), 1, LIT (-0xf.dfe902135fc1c19p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7618p-4), 1, LIT (-0xf.dfe902135fc1c18p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7616p-4), 1, LIT (-0xf.dfe902135fc1c18p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.ffb679ba994b7616p-4), 1, LIT (-0xf.dfe902135fc1c18p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p+48", LIT (0x4p+48), { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a8p-4), 1, LIT (0xd.e3b88804f00552dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a8p-4), 1, LIT (0xd.e3b88804f00552dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8a8p-4), 1, LIT (0xd.e3b88804f00552dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.f13d78eabb76b8bp-4), 1, LIT (0xd.e3b88804f00552ep-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1024", LIT (0x4p-1024), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-1024), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1024), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076", LIT (0x4p-1076), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-1076), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-1076), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-1076), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-128", LIT (0x4p-128), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-128), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-128), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-128), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384", LIT (0x4p-16384), { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-16384), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x3.fffffffffffffffcp-16384), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x4p-16384), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448", LIT (0x4p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x0p+0), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-16448), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cc8749212cp+0", LIT (0x6.287cc8749212cp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e8p-4), 1, LIT (0xf.e006929f558d3ebp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e8p-4), 1, LIT (0xf.e006929f558d3ebp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e6p-4), 1, LIT (0xf.e006929f558d3ebp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b86f8e6p-4), 1, LIT (0xf.e006929f558d3ecp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cc8749212e72p+0", LIT (0x6.287cc8749212e72p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bccp-4), 1, LIT (0xf.e006929f558d8ccp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bcap-4), 1, LIT (0xf.e006929f558d8ccp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bcap-4), 1, LIT (0xf.e006929f558d8ccp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b848bcap-4), 1, LIT (0xf.e006929f558d8cdp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cc8749213p+0", LIT (0x6.287cc8749213p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e6p-4), 1, LIT (0xf.e006929f558dbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e6p-4), 1, LIT (0xf.e006929f558dbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e4p-4), 1, LIT (0xf.e006929f558dbe6p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb772e1b8300e4p-4), 1, LIT (0xf.e006929f558dbe7p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cc8p+0", LIT (0x6.287cc8p+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c4p-4), 1, LIT (0xf.e00691b6bde4251p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c4p-4), 1, LIT (0xf.e00691b6bde4252p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3ep-4), 1, LIT (0xf.e00691b6bde4251p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecb7e68ad6e9c3ep-4), 1, LIT (0xf.e00691b6bde4252p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.287cdp+0", LIT (0x6.287cdp+0), { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce6p-4), 1, LIT (0xf.e006a1ad17db69bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce6p-4), 1, LIT (0xf.e006a1ad17db69bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce4p-4), 1, LIT (0xf.e006a1ad17db69bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x1.fecaff6878a10ce4p-4), 1, LIT (0xf.e006a1ad17db69cp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91c16b9b28p-4", LIT (0x8.60a91c16b9b28p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6a8p-4), 1, LIT (0xd.db3d742c26555afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6a8p-4), 1, LIT (0xd.db3d742c26555afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6a8p-4), 1, LIT (0xd.db3d742c26555afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.ffffffffffffc6bp-4), 1, LIT (0xd.db3d742c26555bp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91c16b9b2c23p-4", LIT (0x8.60a91c16b9b2c23p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539ep-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91c16b9b2c24p-4", LIT (0x8.60a91c16b9b2c24p-4), { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000001p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-4), 1, LIT (0xd.db3d742c265539dp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000001p-4), 1, LIT (0xd.db3d742c265539ep-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91c16b9b3p-4", LIT (0x8.60a91c16b9b3p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000358p-4), 1, LIT (0xd.db3d742c26551afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000358p-4), 1, LIT (0xd.db3d742c26551afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000358p-4), 1, LIT (0xd.db3d742c26551afp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000000000000359p-4), 1, LIT (0xd.db3d742c26551bp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a91p-4", LIT (0x8.60a91p-4), { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050c8p-4), 1, LIT (0xd.db3d7a37832aa67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050dp-4), 1, LIT (0xd.db3d7a37832aa68p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050c8p-4), 1, LIT (0xd.db3d7a37832aa67p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffff587e3a050dp-4), 1, LIT (0xd.db3d7a37832aa68p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.60a92p-4", LIT (0x8.60a92p-4), { ERRNO_UNCHANGED, 1, LIT (0x8.000003632116885p-4), 1, LIT (0xd.db3d7237832e30fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000003632116885p-4), 1, LIT (0xd.db3d7237832e30fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000003632116885p-4), 1, LIT (0xd.db3d7237832e30fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8.000003632116886p-4), 1, LIT (0xd.db3d7237832e31p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+1020", LIT (0x8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2dp-4), 1, LIT (-0xd.38cf9361195f50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2dp-4), 1, LIT (-0xd.38cf9361195f50bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2dp-4), 1, LIT (-0xd.38cf9361195f50bp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.0292465edbaff2ep-4), 1, LIT (-0xd.38cf9361195f50bp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+124", LIT (0x8p+124), { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89p-4), 1, LIT (0xc.82b8ec98b5e62fcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89p-4), 1, LIT (0xc.82b8ec98b5e62fdp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb89p-4), 1, LIT (0xc.82b8ec98b5e62fcp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x9.f963166f215eb8ap-4), 1, LIT (0xc.82b8ec98b5e62fdp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+16380", LIT (0x8p+16380), { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc68818p-4), 1, LIT (0xe.bcc2fc82ae39ebfp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc6882p-4), 1, LIT (0xe.bcc2fc82ae39ecp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc68818p-4), 1, LIT (0xe.bcc2fc82ae39ebfp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x6.3ad4b2136cc6882p-4), 1, LIT (0xe.bcc2fc82ae39ecp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152", LIT (0x8p-152), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-152), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-152), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-152), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448", LIT (0x8p-16448), { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-16448), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x8p-16448), 1, LIT (0x1p+0) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x4p-16448), 1, LIT (0xf.fffffffffffffffp-4) }, { UNDERFLOW_EXCEPTION, 1, LIT (0x8p-16448), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-972", LIT (0x8p-972), { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-972), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-972), 1, LIT (0x1p+0) }, { ERRNO_UNCHANGED, 1, LIT (0x7.fffffffffffffff8p-972), 1, LIT (0xf.fffffffffffffffp-4) }, { ERRNO_UNCHANGED, 1, LIT (0x8p-972), 1, LIT (0x1p+0) } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d170829p-4", LIT (0xc.d4966d92d170829p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72p-4), 1, LIT (0xb.201e79450884be2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73p-4), 1, LIT (0xb.201e79450884be3p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e72p-4), 1, LIT (0xb.201e79450884be2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73p-4), 1, LIT (0xb.201e79450884be3p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d17082ap-4", LIT (0xc.d4966d92d17082ap-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73p-4), 1, LIT (0xb.201e79450884be1p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e74p-4), 1, LIT (0xb.201e79450884be2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e73p-4), 1, LIT (0xb.201e79450884be1p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e74p-4), 1, LIT (0xb.201e79450884be2p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d1708p-4", LIT (0xc.d4966d92d1708p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e56p-4), 1, LIT (0xb.201e79450884cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e56p-4), 1, LIT (0xb.201e79450884cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e56p-4), 1, LIT (0xb.201e79450884cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe776978e57p-4), 1, LIT (0xb.201e79450884c01p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966d92d171p-4", LIT (0xc.d4966d92d171p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e6p-4), 1, LIT (0xb.201e7945088464p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e6p-4), 1, LIT (0xb.201e7945088464p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e6p-4), 1, LIT (0xb.201e7945088464p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5fe7769793e7p-4), 1, LIT (0xb.201e79450884641p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4966p-4", LIT (0xc.d4966p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8p-4), 1, LIT (0xb.201e83065041456p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f9p-4), 1, LIT (0xb.201e83065041457p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f8p-4), 1, LIT (0xb.201e83065041456p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb5f50739fa5f9p-4), 1, LIT (0xb.201e83065041457p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xc.d4967p-4", LIT (0xc.d4967p-4), { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a6p-4), 1, LIT (0xb.201e77869a46ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a6p-4), 1, LIT (0xb.201e77869a46ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a6p-4), 1, LIT (0xb.201e77869a46ae2p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xb.7fb600275877a61p-4), 1, LIT (0xb.201e77869a46ae3p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4", LIT (0xcp-4), { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2dp-4), 1, LIT (0xb.b4ff632a908f73ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2ep-4), 1, LIT (0xb.b4ff632a908f73fp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2dp-4), 1, LIT (0xb.b4ff632a908f73ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xa.e7fe0b5fc786b2ep-4), 1, LIT (0xb.b4ff632a908f73fp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e5bc3bb88p+112", LIT (0xe.9f1e5bc3bb88p+112), { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ecp-4), 1, LIT (0x1.ff01000c9ae7363p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ecp-4), 1, LIT (0x1.ff01000c9ae7363p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4ecp-4), 1, LIT (0x1.ff01000c9ae7363p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfffd7bde0fb4edp-4), 1, LIT (0x1.ff01000c9ae73632p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e5p+112", LIT (0xe.9f1e5p+112), { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b78p-4), 1, LIT (0xe.26f8af8333f927p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b8p-4), 1, LIT (0xe.26f8af8333f9271p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b78p-4), 1, LIT (0xe.26f8af8333f927p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x7.76d600e031521b8p-4), 1, LIT (0xe.26f8af8333f9271p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.9f1e6p+112", LIT (0xe.9f1e6p+112), { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddep-4), 1, LIT (-0xa.07bd3ab53ab9711p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddfp-4), 1, LIT (-0xa.07bd3ab53ab9711p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddep-4), 1, LIT (-0xa.07bd3ab53ab971p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.773a2eac3000ddfp-4), 1, LIT (-0xa.07bd3ab53ab971p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.f0274p+4", LIT (0xf.f0274p+4), { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076425p-4), 1, LIT (-0xd.b7f5359babdb66cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076425p-4), 1, LIT (-0xd.b7f5359babdb66cp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424p-4), 1, LIT (-0xd.b7f5359babdb66bp-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.3bee07bc9076424p-4), 1, LIT (-0xd.b7f5359babdb66bp-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffcp+124", LIT (0xf.ffffcp+124), { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d88p-8), 1, LIT (0xf.fb2a030c5ae20bdp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d89p-8), 1, LIT (0xf.fb2a030c5ae20bep-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d88p-8), 1, LIT (0xf.fb2a030c5ae20bdp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xc.6fa5c5665984d89p-8), 1, LIT (0xf.fb2a030c5ae20bep-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b6p-8), 1, LIT (-0xf.fff31767d5ba9e1p-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b62p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b6p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) }, { ERRNO_UNCHANGED, 1, LIT (0x1.452fc98b34e96b62p-8), 1, LIT (-0xf.fff31767d5ba9ep-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7bp-4), 1, LIT (-0x2.002ef4018753d50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7cp-4), 1, LIT (-0x2.002ef4018753d50cp-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7bp-4), 1, LIT (-0x2.002ef4018753d508p-4) }, { ERRNO_UNCHANGED, 1, LIT (0xf.dfd9d4b6d0e5f7cp-4), 1, LIT (-0x2.002ef4018753d508p-4) } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba907p-4), 1, LIT (0xd.a5f963cdefe6d52p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba907p-4), 1, LIT (0xd.a5f963cdefe6d53p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906p-4), 1, LIT (0xd.a5f963cdefe6d52p-4) }, { ERRNO_UNCHANGED, 1, LIT (-0x8.599b32844aba906p-4), 1, LIT (0xd.a5f963cdefe6d53p-4) } },
#endif
  };

static void
sincos_test (void)
{
  FLOAT sin_res, cos_res;

  ALL_RM_TEST (sincos, 0, sincos_test_data, RUN_TEST_LOOP_fFF_11, END, sin_res, cos_res);
}

static void
do_test (void)
{
  sincos_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

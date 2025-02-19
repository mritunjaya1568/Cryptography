/* Test cpow.
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

static const struct test_cc_c_data cpow_test_data[] =
  {
    { "qNaN + qNaN i, qNaN + qNaN i", qnan_value, qnan_value, qnan_value, qnan_value, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 }, { qnan_value, qnan_value, 0 } },

#if (TEST_COND_binary128)
    { "0x1p+0 + +0 i, +0 + +0 i", LIT (0x1p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x0p+0), { LIT (0x1p+0), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.59f9df735e5a8186bf2689fbf714p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735e5a8186bf2689fbf714p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.59f9df735e5a8186bf2689fbf71p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735e5a8186bf2689fbf71p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.59f9df735e5e8186bf2689fbf71p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735e5e8186bf2689fbf71p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.59f9df735e5e8186bf2689fbf70cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735e5e8186bf2689fbf70cp-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.59f9df735f3e8186bf2689fbf63p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735f3e8186bf2689fbf62cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.59f9df735f3e8186bf2689fbf62cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735f3e8186bf2689fbf62cp-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.59f9df735d3e8186bf2689fbf834p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735d3e8186bf2689fbf834p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.59f9df735d3e8186bf2689fbf83p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735d3e8186bf2689fbf83p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x4.802cf3cf653e81889e19a21520f8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.802cf3cf653e81889e19a21520f4p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x4.802cf3cf653e81889e19a21520f4p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.802cf3cf653e81889e19a21520f4p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0xc.802cf3cf653e818087d7d5a37f78p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.802cf3cf653e818087d7d5a37f78p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0xc.802cf3cf653e818087d7d5a37f7p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.802cf3cf653e818087d7d5a37f7p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbce8p-4), LIT (0x2.e537fd30c309ac14f9e72bb0767ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcfp-4), LIT (0x2.e537fd30c309ac14f9e72bb0767ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbce8p-4), LIT (0x2.e537fd30c309ac14f9e72bb0767ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcfp-4), LIT (0x2.e537fd30c309ac14f9e72bb0767cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff638p-4), LIT (-0x1.1ac802cf3cf653e6faf7ee16b482p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1ac802cf3cf653e6faf7ee16b482p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff638p-4), LIT (-0x1.1ac802cf3cf653e6faf7ee16b481p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1ac802cf3cf653e6faf7ee16b481p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e4cb5da7p-4), LIT (0x2.eef4b9ee537b9e0b6e4ebf7ea0e8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e4cb5da7p-4), LIT (0x2.eef4b9ee537b9e0b6e4ebf7ea0e8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e4cb5da7p-4), LIT (0x2.eef4b9ee537b9e0b6e4ebf7ea0e8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e4cb5da708p-4), LIT (0x2.eef4b9ee537b9e0b6e4ebf7ea0eap-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c0e8ccd1f98p-4), LIT (-0x5.110b4611ac6a7fb2f656f46890acp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c0e8ccd1f98p-4), LIT (-0x5.110b4611ac6a7fb2f656f46890acp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c0e8ccd1f98p-4), LIT (-0x5.110b4611ac6a7fb2f656f46890a8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c0e8ccd1fap-4), LIT (-0x5.110b4611ac6a7fb2f656f46890a8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0xe.5fadf3d34d330ccf5693ad882e68p-116), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xe.5fadf3d34d330ccf5693ad882e68p-116), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0xe.5fadf3d34d330ccf5693ad882e68p-116), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xe.5fadf3d34d330ccf5693ad882e7p-116), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x3.1a0520c2cb2ccf330a96c5277d18p-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.1a0520c2cb2ccf330a96c5277d18p-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x3.1a0520c2cb2ccf330a96c5277d16p-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.1a0520c2cb2ccf330a96c5277d16p-112), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0xe.31a0520c2cb2ccf330a96c5277dp-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xe.31a0520c2cb2ccf330a96c5277dp-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0xe.31a0520c2cb2ccf330a96c5277c8p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xe.31a0520c2cb2ccf330a96c5277c8p-108), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.1ce5fadf3d34d330ccf5693ad882p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.1ce5fadf3d34d330ccf5693ad883p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.1ce5fadf3d34d330ccf5693ad882p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.1ce5fadf3d34d330ccf5693ad883p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.d9cceba3f91ce5fadf3d34d330ccp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f91ce5fadf3d34d330ccp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.d9cceba3f91ce5fadf3d34d330ccp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f91ce5fadf3d34d330cdp-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.2633145c06e31a0520c2cb2ccf34p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c06e31a0520c2cb2ccf3p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.2633145c06e31a0520c2cb2ccf3p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c06e31a0520c2cb2ccf3p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e59d9cceba3f91ce5fadf3d34924p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcep-4), LIT (0x2.e59d9cceba3f91ce5fadf3d34924p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e59d9cceba3f91ce5fadf3d34924p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcep-4), LIT (0x2.e59d9cceba3f91ce5fadf3d34926p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a62633145c06e31a0520c2cb294p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a62633145c06e31a0520c2cb293p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a62633145c06e31a0520c2cb293p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a62633145c06e31a0520c2cb293p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8cafafb8214p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8cafafb8216p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8cafafb8214p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfcp-4), LIT (0x2.eef4b9ee59d597edd8cafafb8216p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c108faf46fp-4), LIT (-0x5.110b4611a61085d8a21cbb8f293cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46f8p-4), LIT (-0x5.110b4611a61085d8a21cbb8f2938p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46fp-4), LIT (-0x5.110b4611a61085d8a21cbb8f2938p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46f8p-4), LIT (-0x5.110b4611a61085d8a21cbb8f2938p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x5.8571dcc6fc42acc4044b87cbaaacp-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x5.8571dcc6fc42acc4044b87cbaaacp-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x5.8571dcc6fc42acc4044b87cbaaacp-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x5.8571dcc6fc42acc4044b87cbaabp-112), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.8571dcc6fc42acc4044b87cbaaabp-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.8571dcc6fc42acc4044b87cbaaacp-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.8571dcc6fc42acc4044b87cbaaabp-112), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.8571dcc6fc42acc4044b87cbaaacp-112), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0xd.e7a8e233903bd533bfbb4783456p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xd.e7a8e233903bd533bfbb47834558p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0xd.e7a8e233903bd533bfbb47834558p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xd.e7a8e233903bd533bfbb47834558p-108), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.218571dcc6fc42acc4044b87cbabp-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.218571dcc6fc42acc4044b87cbabp-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.218571dcc6fc42acc4044b87cbabp-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.218571dcc6fc42acc4044b87cbacp-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.d9cceba3f9218571dcc6fc42acc4p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f9218571dcc6fc42acc5p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.d9cceba3f9218571dcc6fc42acc4p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f9218571dcc6fc42acc5p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.2633145c06de7a8e233903bd534p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c06de7a8e233903bd534p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.2633145c06de7a8e233903bd533cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c06de7a8e233903bd533cp-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e59d9cceba3f9218571dcc6fc01ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcep-4), LIT (0x2.e59d9cceba3f9218571dcc6fc01ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e59d9cceba3f9218571dcc6fc01ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcep-4), LIT (0x2.e59d9cceba3f9218571dcc6fc02p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a62633145c06de7a8e233903b9dp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a62633145c06de7a8e233903b9cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a62633145c06de7a8e233903b9cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a62633145c06de7a8e233903b9cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8caff9af914p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8caff9af914p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8caff9af914p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfcp-4), LIT (0x2.eef4b9ee59d597edd8caff9af916p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c108faf46fp-4), LIT (-0x5.110b4611a61085d8a21cb6efb24p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46f8p-4), LIT (-0x5.110b4611a61085d8a21cb6efb24p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46fp-4), LIT (-0x5.110b4611a61085d8a21cb6efb23cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46f8p-4), LIT (-0x5.110b4611a61085d8a21cb6efb23cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x2.3318b9f46bd64de2f0226f7108d6p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.3318b9f46bd64de2f0226f7108d6p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x2.3318b9f46bd64de2f0226f7108d4p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.3318b9f46bd64de2f0226f7108d4p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x2.3718b9f46bd64de2f0226f7108d6p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.3718b9f46bd64de2f0226f7108d4p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x2.3718b9f46bd64de2f0226f7108d4p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.3718b9f46bd64de2f0226f7108d4p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x3.1718b9f46bd64de2f0226f710886p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.1718b9f46bd64de2f0226f710886p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x3.1718b9f46bd64de2f0226f710884p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.1718b9f46bd64de2f0226f710884p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x1.1718b9f46bd64de2f0226f71093ap-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1718b9f46bd64de2f0226f710939p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x1.1718b9f46bd64de2f0226f710939p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1718b9f46bd64de2f0226f710939p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.d9cceba3f6e8e7460b9429b21c69p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f6e8e7460b9429b21c69p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.d9cceba3f6e8e7460b9429b21c69p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f6e8e7460b9429b21c6ap-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.2633145c091718b9f46bd64de0c8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c091718b9f46bd64de0c8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.2633145c091718b9f46bd64de0c4p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c091718b9f46bd64de0c4p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e59d9cceba3f6e8e7460b942960ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcep-4), LIT (0x2.e59d9cceba3f6e8e7460b942961p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e59d9cceba3f6e8e7460b942960ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcep-4), LIT (0x2.e59d9cceba3f6e8e7460b942961p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a62633145c091718b9f46bd6442p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a62633145c091718b9f46bd6442p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a62633145c091718b9f46bd6441p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a62633145c091718b9f46bd6441p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8c8c6fccc3ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8c8c6fccc3ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8c8c6fccc3ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfcp-4), LIT (0x2.eef4b9ee59d597edd8c8c6fccc3cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c108faf46fp-4), LIT (-0x5.110b4611a61085d8a21eef8ddc48p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46f8p-4), LIT (-0x5.110b4611a61085d8a21eef8ddc48p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46fp-4), LIT (-0x5.110b4611a61085d8a21eef8ddc44p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46f8p-4), LIT (-0x5.110b4611a61085d8a21eef8ddc44p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.ca2c4d077e17018974eb7088b715p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.ca2c4d077e17018974eb7088b716p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.ca2c4d077e17018974eb7088b715p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.ca2c4d077e17018974eb7088b716p-108), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.8a2c4d077e17018974eb7088b714p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.8a2c4d077e17018974eb7088b715p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.8a2c4d077e17018974eb7088b714p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.8a2c4d077e17018974eb7088b715p-108), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0xc.75d3b2f881e8fe768b148f774928p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.75d3b2f881e8fe768b148f774928p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0xc.75d3b2f881e8fe768b148f77492p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.75d3b2f881e8fe768b148f77492p-108), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.38a2c4d077e17018974eb7088b75p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.38a2c4d077e17018974eb7088b76p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.38a2c4d077e17018974eb7088b75p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.38a2c4d077e17018974eb7088b76p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.d9cceba3f938a2c4d077e170189ep-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f938a2c4d077e170189fp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x1.d9cceba3f938a2c4d077e170189ep-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f938a2c4d077e170189fp-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.2633145c06c75d3b2f881e8fe784p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c06c75d3b2f881e8fe78p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x6.2633145c06c75d3b2f881e8fe78p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c06c75d3b2f881e8fe78p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e59d9cceba3f938a2c4d077e13p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcep-4), LIT (0x2.e59d9cceba3f938a2c4d077e13p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e59d9cceba3f938a2c4d077e13p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcep-4), LIT (0x2.e59d9cceba3f938a2c4d077e1302p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a62633145c06c75d3b2f881e8cap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a62633145c06c75d3b2f881e8cap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a62633145c06c75d3b2f881e8c9p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a62633145c06c75d3b2f881e8c9p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8cb16b84c12p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8cb16b84c14p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfb8p-4), LIT (0x2.eef4b9ee59d597edd8cb16b84c12p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dfcp-4), LIT (0x2.eef4b9ee59d597edd8cb16b84c14p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c108faf46fp-4), LIT (-0x5.110b4611a61085d8a21c9fd25f6p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46f8p-4), LIT (-0x5.110b4611a61085d8a21c9fd25f6p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46fp-4), LIT (-0x5.110b4611a61085d8a21c9fd25f5cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf46f8p-4), LIT (-0x5.110b4611a61085d8a21c9fd25f5cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x2.e4f41ba030847669e9c7d60e918p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba030847669e9c7d60e9182p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x2.e4f41ba030847669e9c7d60e918p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba030847669e9c7d60e9182p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x2.e4f41ba030807669e9c7d60e917ep-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba030807669e9c7d60e918p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x2.e4f41ba030807669e9c7d60e917ep-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba030807669e9c7d60e918p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x2.e4f41ba02fa07669e9c7d60e9118p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba02fa07669e9c7d60e9118p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x2.e4f41ba02fa07669e9c7d60e9118p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba02fa07669e9c7d60e911ap-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x2.e4f41ba031a07669e9c7d60e9202p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba031a07669e9c7d60e9204p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x2.e4f41ba031a07669e9c7d60e9202p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba031a07669e9c7d60e9204p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x4.bec1074429a0766ac4096de1f708p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4.bec1074429a0766ac4096de1f708p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (0x4.bec1074429a0766ac4096de1f708p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4.bec1074429a0766ac4096de1f70cp-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x3.413ef8bbd65f8998eb5fe0c2df16p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.413ef8bbd65f8998eb5fe0c2df16p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), LIT (-0x3.413ef8bbd65f8998eb5fe0c2df14p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.413ef8bbd65f8998eb5fe0c2df14p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcdp-4), LIT (0x2.e5cbec1074429a08bc3eb1402856p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e5cbec1074429a08bc3eb1402858p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcdp-4), LIT (0x2.e5cbec1074429a08bc3eb1402856p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcd8p-4), LIT (0x2.e5cbec1074429a08bc3eb1402858p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a3413ef8bbd65f91b75f6123e71p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a3413ef8bbd65f91b75f6123e71p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff64p-4), LIT (-0x1.1a3413ef8bbd65f91b75f6123e7p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff648p-4), LIT (-0x1.1a3413ef8bbd65f91b75f6123e7p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e3196a67b8p-4), LIT (0x2.eef4b9ee5cba8c0ad2e8fe56ebe4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3196a67cp-4), LIT (0x2.eef4b9ee5cba8c0ad2e8fe56ebe6p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3196a67b8p-4), LIT (0x2.eef4b9ee5cba8c0ad2e8fe56ebe4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3196a67cp-4), LIT (0x2.eef4b9ee5cba8c0ad2e8fe56ebe6p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c117a50dc48p-4), LIT (-0x5.110b4611a32b91bf57681f8addp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c117a50dc5p-4), LIT (-0x5.110b4611a32b91bf57681f8adcfcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c117a50dc48p-4), LIT (-0x5.110b4611a32b91bf57681f8adcfcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c117a50dc5p-4), LIT (-0x5.110b4611a32b91bf57681f8adcfcp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550e99a5f041d45fdbep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550e99a5f041d45fdbep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550e99a5f041d45fdbdp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffede8p-4), LIT (-0x1.814111910550e99a5f041d45fdbdp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550e9da5f041d45fdbdp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550e9da5f041d45fdbdp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550e9da5f041d45fdbcp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffede8p-4), LIT (-0x1.814111910550e9da5f041d45fdbcp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550f7da5f041d45fd87p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550f7da5f041d45fd87p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550f7da5f041d45fd86p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffede8p-4), LIT (-0x1.814111910550f7da5f041d45fd86p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550d7da5f041d45fe02p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550d7da5f041d45fe02p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.814111910550d7da5f041d45fe01p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffede8p-4), LIT (-0x1.814111910550d7da5f041d45fe01p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.812374c24b1157dad07f3d925622p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffede8p-4), LIT (-0x1.812374c24b1157dad07f3d925622p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.812374c24b1157dad07f3d925621p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffede8p-4), LIT (-0x1.812374c24b1157dad07f3d925621p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.ffffffffffffffffffffffffedd8p-4), LIT (-0x1.81a374c24b1157d8e5f9e72e07d5p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedd8p-4), LIT (-0x1.81a374c24b1157d8e5f9e72e07d4p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedd8p-4), LIT (-0x1.81a374c24b1157d8e5f9e72e07d4p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffedep-4), LIT (-0x1.81a374c24b1157d8e5f9e72e07d4p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffffffffffff078p-4), LIT (0x1.645c8b3db4ee9d0b9d154b5c11c7p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff08p-4), LIT (0x1.645c8b3db4ee9d0b9d154b5c11c8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff078p-4), LIT (0x1.645c8b3db4ee9d0b9d154b5c11c7p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff08p-4), LIT (0x1.645c8b3db4ee9d0b9d154b5c11c8p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffffffffffffffffc99p-4), LIT (-0x2.9ba374c24b1153a038379231842ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffc998p-4), LIT (-0x2.9ba374c24b1153a038379231842ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffc99p-4), LIT (-0x2.9ba374c24b1153a038379231842cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffc998p-4), LIT (-0x2.9ba374c24b1153a038379231842cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb2909294dbe302788p-4), LIT (0x2.eef4b9d645c4739fb50712af351p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb2909294dbe30279p-4), LIT (0x2.eef4b9d645c4739fb50712af3512p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb2909294dbe302788p-4), LIT (0x2.eef4b9d645c4739fb50712af351p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb2909294dbe30279p-4), LIT (0x2.eef4b9d645c4739fb50712af3512p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661470a4141cf8p-4), LIT (-0x5.110b4629ba218b7e6faceb4a4cap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661470a4141cf8p-4), LIT (-0x5.110b4629ba218b7e6faceb4a4c9cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661470a4141cf8p-4), LIT (-0x5.110b4629ba218b7e6faceb4a4c9cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661470a4141dp-4), LIT (-0x5.110b4629ba218b7e6faceb4a4c9cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e88ddfef54c3a6c44p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e88ddfef54c3a6c44p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e88ddfef54c3a6c44p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb24p-4), LIT (0x3.1e35ebf8c21e88ddfef54c3a6c46p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e889dfef54c3a6c42p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e889dfef54c3a6c42p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e889dfef54c3a6c42p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb24p-4), LIT (0x3.1e35ebf8c21e889dfef54c3a6c44p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e7a9dfef54c3a6bd2p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e7a9dfef54c3a6bd4p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e7a9dfef54c3a6bd2p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb24p-4), LIT (0x3.1e35ebf8c21e7a9dfef54c3a6bd4p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e9a9dfef54c3a6cdp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e9a9dfef54c3a6cd2p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e35ebf8c21e9a9dfef54c3a6cdp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb24p-4), LIT (0x3.1e35ebf8c21e9a9dfef54c3a6cd2p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.ffffffffffffffffffffffffb23p-4), LIT (0x3.1e5388c77c5e1a9eea1483e45b92p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb23p-4), LIT (0x3.1e5388c77c5e1a9eea1483e45b94p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb23p-4), LIT (0x3.1e5388c77c5e1a9eea1483e45b92p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb238p-4), LIT (0x3.1e5388c77c5e1a9eea1483e45b94p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.ffffffffffffffffffffffffb248p-4), LIT (0x3.1dd388c77c5e1a9af1c44cbd6e14p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb25p-4), LIT (0x3.1dd388c77c5e1a9af1c44cbd6e16p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb248p-4), LIT (0x3.1dd388c77c5e1a9af1c44cbd6e14p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb25p-4), LIT (0x3.1dd388c77c5e1a9af1c44cbd6e16p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffffffffffede9p-4), LIT (0x6.03d388c77c5e319e62c402661708p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffede9p-4), LIT (0x6.03d388c77c5e319e62c40266170cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffede9p-4), LIT (0x6.03d388c77c5e319e62c402661708p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffede98p-4), LIT (0x6.03d388c77c5e319e62c40266170cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffffffffffffffffdf8p-4), LIT (0x2.03d388c77c5e11dbe10acafa3168p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffdf88p-4), LIT (0x2.03d388c77c5e11dbe10acafa316ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffdf8p-4), LIT (0x2.03d388c77c5e11dbe10acafa3168p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffdf88p-4), LIT (0x2.03d388c77c5e11dbe10acafa316ap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29091bbe2435d8fp-4), LIT (0x2.eef4ba203d346ec486fd3d07aaa4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29091bbe2435d8fp-4), LIT (0x2.eef4ba203d346ec486fd3d07aaa4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29091bbe2435d8fp-4), LIT (0x2.eef4ba203d346ec486fd3d07aaa4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29091bbe2435d8f8p-4), LIT (0x2.eef4ba203d346ec486fd3d07aaa6p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3662bdcc1f98e48p-4), LIT (-0x5.110b45dfc2b1ee86f90695ac39ecp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3662bdcc1f98e48p-4), LIT (-0x5.110b45dfc2b1ee86f90695ac39ecp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3662bdcc1f98e48p-4), LIT (-0x5.110b45dfc2b1ee86f90695ac39e8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3662bdcc1f98e5p-4), LIT (-0x5.110b45dfc2b1ee86f90695ac39e8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fdb4fd151p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fdb4fd1514p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fdb4fd151p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b1p-4), LIT (0x6.0b6b939a00d5748348fdb4fd1514p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fdb0fd150cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fdb0fd151p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fdb0fd150cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b1p-4), LIT (0x6.0b6b939a00d5748348fdb0fd151p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fcd0fd1434p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fcd0fd1438p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fcd0fd1434p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b1p-4), LIT (0x6.0b6b939a00d5748348fcd0fd1438p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fed0fd1624p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fed0fd1624p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b08p-4), LIT (0x6.0b6b939a00d5748348fed0fd1624p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3b1p-4), LIT (0x6.0b6b939a00d5748348fed0fd1628p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffedbb395471f533d338p-4), LIT (0x6.0b6b939a02af4170b4c610596148p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395471f533d338p-4), LIT (0x6.0b6b939a02af4170b4c610596148p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395471f533d338p-4), LIT (0x6.0b6b939a02af4170b4c610596148p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395471f533d3388p-4), LIT (0x6.0b6b939a02af4170b4c61059614cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffedbb395472258f30038p-4), LIT (0x6.0b6b9399faaf4169028a0f85f0bp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395472258f30038p-4), LIT (0x6.0b6b9399faaf4169028a0f85f0bp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395472258f30038p-4), LIT (0x6.0b6b9399faaf4169028a0f85f0bp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395472258f3004p-4), LIT (0x6.0b6b9399faaf4169028a0f85f0b4p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffedbb395359d3f1411e8p-4), LIT (0x6.0b6b93c85aaf6e06365ed9368c68p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395359d3f1411e8p-4), LIT (0x6.0b6b93c85aaf6e06365ed9368c6cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395359d3f1411e8p-4), LIT (0x6.0b6b93c85aaf6e06365ed9368c68p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395359d3f1411fp-4), LIT (0x6.0b6b93c85aaf6e06365ed9368c6cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffedbb3954dcaed79f5f8p-4), LIT (0x6.0b6b93885aaf307456583db1dcap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954dcaed79f6p-4), LIT (0x6.0b6b93885aaf307456583db1dcap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954dcaed79f5f8p-4), LIT (0x6.0b6b93885aaf307456583db1dcap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954dcaed79f6p-4), LIT (0x6.0b6b93885aaf307456583db1dca4p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.fffffffffd7b28d5c92c7abae9bp-4), LIT (0x8.fa60505acb795d31d8828462e6ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28d5c92c7abae9bp-4), LIT (0x8.fa60505acb795d31d8828462e6a8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28d5c92c7abae9bp-4), LIT (0x8.fa60505acb795d31d8828462e6ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28d5c92c7abae9b8p-4), LIT (0x8.fa60505acb795d31d8828462e6a8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffff858fe6f01a77dffdp-4), LIT (0xf.a6048a88f5ed86bbfddbf1bd8208p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff858fe6f01a77dffdp-4), LIT (0xf.a6048a88f5ed86bbfddbf1bd821p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff858fe6f01a77dffdp-4), LIT (0xf.a6048a88f5ed86bbfddbf1bd8208p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff858fe6f01a77dffd8p-4), LIT (0xf.a6048a88f5ed86bbfddbf1bd821p-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06e4p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06e4p+0), { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265db08251f52p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265db08251f5p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265db08251f5p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0dp-4), LIT (-0x3.33826561fcbf77a265db08251f5p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06ep+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06ep+0), { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265db0c251f5p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265db0c251f4ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265db0c251f4ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0dp-4), LIT (-0x3.33826561fcbf77a265db0c251f4ep-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265dbec251edep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265dbec251edcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265dbec251edcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0dp-4), LIT (-0x3.33826561fcbf77a265dbec251edcp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265d9ec251fe2p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265d9ec251fe2p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0c8p-4), LIT (-0x3.33826561fcbf77a265d9ec251fep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf0dp-4), LIT (-0x3.33826561fcbf77a265d9ec251fep-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.ffffffffffae04a3471fa717af5p-4), LIT (-0x3.33826561fae5aab7b34743c39eb2p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471fa717af5p-4), LIT (-0x3.33826561fae5aab7b34743c39ebp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471fa717af5p-4), LIT (-0x3.33826561fae5aab7b34743c39ebp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471fa717af58p-4), LIT (-0x3.33826561fae5aab7b34743c39ebp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.ffffffffffae04a3471e0d567d7p-4), LIT (-0x3.3382656202e5aab39fd8955306fap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471e0d567d7p-4), LIT (-0x3.3382656202e5aab39fd8955306f8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471e0d567d7p-4), LIT (-0x3.3382656202e5aab39fd8955306f8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471e0d567d78p-4), LIT (-0x3.3382656202e5aab39fd8955306f8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffae04a3506559435a2p-4), LIT (-0x3.33826533a2e5c2544573ca0273fep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3506559435a2p-4), LIT (-0x3.33826533a2e5c2544573ca0273fcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3506559435a2p-4), LIT (-0x3.33826533a2e5c2544573ca0273fcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3506559435a28p-4), LIT (-0x3.33826533a2e5c2544573ca0273fcp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffae04a343974fb491bp-4), LIT (-0x3.33826573a2e5a1b8d0004544c53ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a343974fb491b8p-4), LIT (-0x3.33826573a2e5a1b8d0004544c53ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a343974fb491bp-4), LIT (-0x3.33826573a2e5a1b8d0004544c53cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a343974fb491b8p-4), LIT (-0x3.33826573a2e5a1b8d0004544c53cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffff6d236dbabdebbbp-4), LIT (-0x4.48dacf23d53e61b713c9d2f46438p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d236dbabdebbb08p-4), LIT (-0x4.48dacf23d53e61b713c9d2f46434p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d236dbabdebbbp-4), LIT (-0x4.48dacf23d53e61b713c9d2f46434p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d236dbabdebbb08p-4), LIT (-0x4.48dacf23d53e61b713c9d2f46434p-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffddd264f0fca0f5b9908p-4), LIT (-0x8.448da8dece7042b950121c28a19p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd264f0fca0f5b9908p-4), LIT (-0x8.448da8dece7042b950121c28a188p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd264f0fca0f5b9908p-4), LIT (-0x8.448da8dece7042b950121c28a188p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd264f0fca0f5b991p-4), LIT (-0x8.448da8dece7042b950121c28a188p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+0 + +0 i, 0xap+0 + +0 i", LIT (0x2p+0), LIT (0x0p+0), LIT (0xap+0), LIT (0x0p+0), { LIT (0x4p+8), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+0 + 0x3p+0 i, 0x4p+0 + +0 i", LIT (0x2p+0), LIT (0x3p+0), LIT (0x4p+0), LIT (0x0p+0), { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4 + 0x1.4p+0 i, +0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x0p+0), LIT (0x1p+0), { LIT (0x5.4f283113fa8a525b30b312aa4efp-4), LIT (0x2.19f6810e8fdb408ac45c5250ac92p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a525b30b312aa4efp-4), LIT (0x2.19f6810e8fdb408ac45c5250ac94p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a525b30b312aa4efp-4), LIT (0x2.19f6810e8fdb408ac45c5250ac92p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a525b30b312aa4ef4p-4), LIT (0x2.19f6810e8fdb408ac45c5250ac94p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + +0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x0p+0), { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x1p+0), { LIT (0x1.5aea037cc815ad16ef12e71ae37cp-4), LIT (0x8.366b1e23e511575a102515116418p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16ef12e71ae37dp-4), LIT (0x8.366b1e23e511575a102515116418p-4), ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16ef12e71ae37cp-4), LIT (0x8.366b1e23e511575a102515116418p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16ef12e71ae37dp-4), LIT (0x8.366b1e23e511575a10251511642p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4 + 0x1.4p+0 i, 0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.e14e4796fd3f16019f9eb01485e3p-4), LIT (0x5.8b7ae4dbf0a7933416f4a46c0bb8p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f16019f9eb01485e3p-4), LIT (0x5.8b7ae4dbf0a7933416f4a46c0bbcp-4), ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f16019f9eb01485e3p-4), LIT (0x5.8b7ae4dbf0a7933416f4a46c0bb8p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f16019f9eb01485e4p-4), LIT (0x5.8b7ae4dbf0a7933416f4a46c0bbcp-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0 + +0 i, +0 + +0 i", LIT (0x1p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x0p+0), { LIT (0x1p+0), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.fffffp-4), LIT (0x8.fa605p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.fa605p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), LIT (0x8.fa605p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x8.fa606p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffp-4), LIT (0xf.a6048p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xf.a6049p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), LIT (0xf.a6048p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0xf.a6049p-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.fffffp-4), LIT (-0x4.48dadp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.48dadp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), LIT (-0x4.48dac8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.48dac8p-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffp-4), LIT (-0x8.448dbp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x8.448dbp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), LIT (-0x8.448dap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x8.448dap-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+0 + +0 i, 0xap+0 + +0 i", LIT (0x2p+0), LIT (0x0p+0), LIT (0xap+0), LIT (0x0p+0), { LIT (0x4p+8), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+0 + 0x3p+0 i, 0x4p+0 + +0 i", LIT (0x2p+0), LIT (0x3p+0), LIT (0x4p+0), LIT (0x0p+0), { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4 + 0x1.4p+0 i, +0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x0p+0), LIT (0x1p+0), { LIT (0x5.4f283p-4), LIT (0x2.19f68p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283p-4), LIT (0x2.19f68p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283p-4), LIT (0x2.19f68p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f2838p-4), LIT (0x2.19f684p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + +0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x0p+0), { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x1p+0), { LIT (0x1.5aea02p-4), LIT (0x8.366b1p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea04p-4), LIT (0x8.366b2p-4), ERRNO_UNCHANGED }, { LIT (0x1.5aea02p-4), LIT (0x8.366b1p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea04p-4), LIT (0x8.366b2p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4 + 0x1.4p+0 i, 0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.e14e46p-4), LIT (0x5.8b7aep-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e48p-4), LIT (0x5.8b7ae8p-4), ERRNO_UNCHANGED }, { LIT (0x1.e14e46p-4), LIT (0x5.8b7aep-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e48p-4), LIT (0x5.8b7ae8p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0 + +0 i, +0 + +0 i", LIT (0x1p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x0p+0), { LIT (0x1p+0), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffff8p-4), LIT (0x1.645c8b3db4ee9p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.645c8b3db4eeap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), LIT (0x1.645c8b3db4ee9p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.645c8b3db4eeap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffff8p-4), LIT (-0x2.9ba374c24b116p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.9ba374c24b116p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), LIT (-0x2.9ba374c24b114p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.9ba374c24b114p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbbp-4), LIT (0x2.eef4b9d645c46p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbbp-4), LIT (0x2.eef4b9d645c48p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbbp-4), LIT (0x2.eef4b9d645c46p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb8p-4), LIT (0x2.eef4b9d645c48p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff328p-4), LIT (-0x5.110b4629ba21cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff328p-4), LIT (-0x5.110b4629ba218p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff328p-4), LIT (-0x5.110b4629ba218p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff33p-4), LIT (-0x5.110b4629ba218p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffff8p-4), LIT (0x6.03d388c77c5ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x6.03d388c77c5e4p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), LIT (0x6.03d388c77c5ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x6.03d388c77c5e4p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffff8p-4), LIT (0x2.03d388c77c5ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.03d388c77c5e2p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), LIT (0x2.03d388c77c5ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.03d388c77c5e2p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbbp-4), LIT (0x2.eef4ba203d346p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbbp-4), LIT (0x2.eef4ba203d346p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbbp-4), LIT (0x2.eef4ba203d346p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb8p-4), LIT (0x2.eef4ba203d348p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff328p-4), LIT (-0x5.110b45dfc2b2p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff328p-4), LIT (-0x5.110b45dfc2b2p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff328p-4), LIT (-0x5.110b45dfc2b1cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff33p-4), LIT (-0x5.110b45dfc2b1cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffedb8p-4), LIT (0x6.0b6b93c85aaf4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedb8p-4), LIT (0x6.0b6b93c85aaf8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedb8p-4), LIT (0x6.0b6b93c85aaf4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedcp-4), LIT (0x6.0b6b93c85aaf8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffedb8p-4), LIT (0x6.0b6b93885aafp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedb8p-4), LIT (0x6.0b6b93885aaf4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedb8p-4), LIT (0x6.0b6b93885aafp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedcp-4), LIT (0x6.0b6b93885aaf4p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.fffffffffd7bp-4), LIT (0x8.fa60505acb79p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7bp-4), LIT (0x8.fa60505acb798p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7bp-4), LIT (0x8.fa60505acb79p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b8p-4), LIT (0x8.fa60505acb798p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffff8p-4), LIT (0xf.a6048a88f5ed8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff88p-4), LIT (0xf.a6048a88f5ed8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff8p-4), LIT (0xf.a6048a88f5ed8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff88p-4), LIT (0xf.a6048a88f5eep-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffaep-4), LIT (-0x3.33826533a2e5ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffaep-4), LIT (-0x3.33826533a2e5cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffaep-4), LIT (-0x3.33826533a2e5cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae8p-4), LIT (-0x3.33826533a2e5cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffaep-4), LIT (-0x3.33826573a2e5cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffaep-4), LIT (-0x3.33826573a2e5ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffaep-4), LIT (-0x3.33826573a2e5ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae8p-4), LIT (-0x3.33826573a2e5ap-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffffp-4), LIT (-0x4.48dacf23d53e8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), LIT (-0x4.48dacf23d53e8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffp-4), LIT (-0x4.48dacf23d53e4p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), LIT (-0x4.48dacf23d53e4p-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffdddp-4), LIT (-0x8.448da8dece708p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffdddp-4), LIT (-0x8.448da8dece708p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffdddp-4), LIT (-0x8.448da8dece7p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd8p-4), LIT (-0x8.448da8dece7p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+0 + +0 i, 0xap+0 + +0 i", LIT (0x2p+0), LIT (0x0p+0), LIT (0xap+0), LIT (0x0p+0), { LIT (0x4p+8), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+0 + 0x3p+0 i, 0x4p+0 + +0 i", LIT (0x2p+0), LIT (0x3p+0), LIT (0x4p+0), LIT (0x0p+0), { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4 + 0x1.4p+0 i, +0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x0p+0), LIT (0x1p+0), { LIT (0x5.4f283113fa8a4p-4), LIT (0x2.19f6810e8fdb4p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a4p-4), LIT (0x2.19f6810e8fdb4p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a4p-4), LIT (0x2.19f6810e8fdb4p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a8p-4), LIT (0x2.19f6810e8fdb6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + +0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x0p+0), { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x1p+0), { LIT (0x1.5aea037cc815ap-4), LIT (0x8.366b1e23e511p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815bp-4), LIT (0x8.366b1e23e5118p-4), ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ap-4), LIT (0x8.366b1e23e511p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815bp-4), LIT (0x8.366b1e23e5118p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4 + 0x1.4p+0 i, 0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.e14e4796fd3f1p-4), LIT (0x5.8b7ae4dbf0a78p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f1p-4), LIT (0x5.8b7ae4dbf0a78p-4), ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f1p-4), LIT (0x5.8b7ae4dbf0a78p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f2p-4), LIT (0x5.8b7ae4dbf0a7cp-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0 + +0 i, +0 + +0 i", LIT (0x1p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x0p+0), { LIT (0x1p+0), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x6.59f9df735f3e8186bf2689fbf8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735f3e8186bf2689fbf6p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x6.59f9df735f3e8186bf2689fbf6p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735f3e8186bf2689fbf6p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x6.59f9df735d3e8186bf2689fbfap-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735d3e8186bf2689fbf8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x6.59f9df735d3e8186bf2689fbf8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.59f9df735d3e8186bf2689fbf8p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x4.802cf3cf653e81889e19a21522p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.802cf3cf653e81889e19a2152p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x4.802cf3cf653e81889e19a2152p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.802cf3cf653e81889e19a2152p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0xc.802cf3cf653e818087d7d5a38p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.802cf3cf653e818087d7d5a38p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0xc.802cf3cf653e818087d7d5a37cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.802cf3cf653e818087d7d5a37cp-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e537fd30c309ac14f9e72bb076p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e537fd30c309ac14f9e72bb076p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e537fd30c309ac14f9e72bb076p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffcp-4), LIT (0x2.e537fd30c309ac14f9e72bb077p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (-0x1.1ac802cf3cf653e6faf7ee16b5p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), LIT (-0x1.1ac802cf3cf653e6faf7ee16b48p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (-0x1.1ac802cf3cf653e6faf7ee16b48p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), LIT (-0x1.1ac802cf3cf653e6faf7ee16b48p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e4cb5da4p-4), LIT (0x2.eef4b9ee537b9e0b6e4ebf7eap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e4cb5da8p-4), LIT (0x2.eef4b9ee537b9e0b6e4ebf7ea1p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e4cb5da4p-4), LIT (0x2.eef4b9ee537b9e0b6e4ebf7eap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e4cb5da8p-4), LIT (0x2.eef4b9ee537b9e0b6e4ebf7ea1p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c0e8ccd1cp-4), LIT (-0x5.110b4611ac6a7fb2f656f46892p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c0e8ccd2p-4), LIT (-0x5.110b4611ac6a7fb2f656f4689p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c0e8ccd1cp-4), LIT (-0x5.110b4611ac6a7fb2f656f4689p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c0e8ccd2p-4), LIT (-0x5.110b4611ac6a7fb2f656f4689p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x3.1718b9f46bd64de2f0226f7109p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.1718b9f46bd64de2f0226f7109p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x3.1718b9f46bd64de2f0226f7108p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.1718b9f46bd64de2f0226f7108p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x1.1718b9f46bd64de2f0226f71098p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1718b9f46bd64de2f0226f7109p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x1.1718b9f46bd64de2f0226f7109p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1718b9f46bd64de2f0226f7109p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x1.d9cceba3f6e8e7460b9429b21cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f6e8e7460b9429b21c8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x1.d9cceba3f6e8e7460b9429b21cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f6e8e7460b9429b21c8p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x6.2633145c091718b9f46bd64de2p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c091718b9f46bd64dep-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x6.2633145c091718b9f46bd64dep-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c091718b9f46bd64dep-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e59d9cceba3f6e8e7460b94296p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e59d9cceba3f6e8e7460b94296p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e59d9cceba3f6e8e7460b94296p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffcp-4), LIT (0x2.e59d9cceba3f6e8e7460b94297p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (-0x1.1a62633145c091718b9f46bd648p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), LIT (-0x1.1a62633145c091718b9f46bd648p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (-0x1.1a62633145c091718b9f46bd64p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), LIT (-0x1.1a62633145c091718b9f46bd64p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e3a142dcp-4), LIT (0x2.eef4b9ee59d597edd8c8c6fcccp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142ep-4), LIT (0x2.eef4b9ee59d597edd8c8c6fcccp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dcp-4), LIT (0x2.eef4b9ee59d597edd8c8c6fcccp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142ep-4), LIT (0x2.eef4b9ee59d597edd8c8c6fccdp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6abf7158809cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c108faf44p-4), LIT (-0x5.110b4611a61085d8a21eef8ddep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf48p-4), LIT (-0x5.110b4611a61085d8a21eef8ddcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf44p-4), LIT (-0x5.110b4611a61085d8a21eef8ddcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf48p-4), LIT (-0x5.110b4611a61085d8a21eef8ddcp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0xc.75d3b2f881e8fe768b148f774cp-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.75d3b2f881e8fe768b148f7748p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0xc.75d3b2f881e8fe768b148f7748p-108), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.75d3b2f881e8fe768b148f7748p-108), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x1.38a2c4d077e17018974eb7088bp-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.38a2c4d077e17018974eb7088b8p-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x1.38a2c4d077e17018974eb7088bp-104), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.38a2c4d077e17018974eb7088b8p-104), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x1.d9cceba3f938a2c4d077e170188p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f938a2c4d077e170188p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x1.d9cceba3f938a2c4d077e170188p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.d9cceba3f938a2c4d077e17019p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x6.2633145c06c75d3b2f881e8fe8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c06c75d3b2f881e8fe8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x6.2633145c06c75d3b2f881e8fe6p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x6.2633145c06c75d3b2f881e8fe6p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e59d9cceba3f938a2c4d077e13p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e59d9cceba3f938a2c4d077e13p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e59d9cceba3f938a2c4d077e13p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffcp-4), LIT (0x2.e59d9cceba3f938a2c4d077e14p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (-0x1.1a62633145c06c75d3b2f881e9p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), LIT (-0x1.1a62633145c06c75d3b2f881e9p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (-0x1.1a62633145c06c75d3b2f881e88p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), LIT (-0x1.1a62633145c06c75d3b2f881e88p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e3a142dcp-4), LIT (0x2.eef4b9ee59d597edd8cb16b84cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142ep-4), LIT (0x2.eef4b9ee59d597edd8cb16b84cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142dcp-4), LIT (0x2.eef4b9ee59d597edd8cb16b84cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3a142ep-4), LIT (0x2.eef4b9ee59d597edd8cb16b84dp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6abf7158809dp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c108faf44p-4), LIT (-0x5.110b4611a61085d8a21c9fd26p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf48p-4), LIT (-0x5.110b4611a61085d8a21c9fd26p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf44p-4), LIT (-0x5.110b4611a61085d8a21c9fd25ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c108faf48p-4), LIT (-0x5.110b4611a61085d8a21c9fd25ep-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x2.e4f41ba02fa07669e9c7d60e91p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba02fa07669e9c7d60e91p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x2.e4f41ba02fa07669e9c7d60e91p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba02fa07669e9c7d60e92p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x2.e4f41ba031a07669e9c7d60e92p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba031a07669e9c7d60e92p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x2.e4f41ba031a07669e9c7d60e92p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e4f41ba031a07669e9c7d60e93p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x4.bec1074429a0766ac4096de1f6p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4.bec1074429a0766ac4096de1f8p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (0x4.bec1074429a0766ac4096de1f6p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4.bec1074429a0766ac4096de1f8p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x3.413ef8bbd65f8998eb5fe0c2ep-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.413ef8bbd65f8998eb5fe0c2dfp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), LIT (-0x3.413ef8bbd65f8998eb5fe0c2dfp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.413ef8bbd65f8998eb5fe0c2dfp-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e5cbec1074429a08bc3eb14028p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e5cbec1074429a08bc3eb14028p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbcp-4), LIT (0x2.e5cbec1074429a08bc3eb14028p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffcp-4), LIT (0x2.e5cbec1074429a08bc3eb14029p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (-0x1.1a3413ef8bbd65f91b75f6123e8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), LIT (-0x1.1a3413ef8bbd65f91b75f6123e8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (-0x1.1a3413ef8bbd65f91b75f6123ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), LIT (-0x1.1a3413ef8bbd65f91b75f6123ep-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb290924e3196a64p-4), LIT (0x2.eef4b9ee5cba8c0ad2e8fe56ebp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3196a68p-4), LIT (0x2.eef4b9ee5cba8c0ad2e8fe56ecp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3196a64p-4), LIT (0x2.eef4b9ee5cba8c0ad2e8fe56ebp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb290924e3196a68p-4), LIT (0x2.eef4b9ee5cba8c0ad2e8fe56ecp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661c117a50dcp-4), LIT (-0x5.110b4611a32b91bf57681f8adep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c117a50dcp-4), LIT (-0x5.110b4611a32b91bf57681f8adcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c117a50dcp-4), LIT (-0x5.110b4611a32b91bf57681f8adcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661c117a50ep-4), LIT (-0x5.110b4611a32b91bf57681f8adcp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.814111910550f7da5f041d45fep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.814111910550f7da5f041d45fd8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.814111910550f7da5f041d45fd8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffp-4), LIT (-0x1.814111910550f7da5f041d45fd8p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.814111910550d7da5f041d45fe8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.814111910550d7da5f041d45fep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.814111910550d7da5f041d45fep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffp-4), LIT (-0x1.814111910550d7da5f041d45fep-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.812374c24b1157dad07f3d92568p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.812374c24b1157dad07f3d9256p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.812374c24b1157dad07f3d9256p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffp-4), LIT (-0x1.812374c24b1157dad07f3d9256p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.81a374c24b1157d8e5f9e72e08p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.81a374c24b1157d8e5f9e72e08p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffecp-4), LIT (-0x1.81a374c24b1157d8e5f9e72e078p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffp-4), LIT (-0x1.81a374c24b1157d8e5f9e72e078p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffffffffffffp-4), LIT (0x1.645c8b3db4ee9d0b9d154b5c118p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffp-4), LIT (0x1.645c8b3db4ee9d0b9d154b5c12p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffp-4), LIT (0x1.645c8b3db4ee9d0b9d154b5c118p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff4p-4), LIT (0x1.645c8b3db4ee9d0b9d154b5c12p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffffffffffffffffc8p-4), LIT (-0x2.9ba374c24b1153a03837923185p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffc8p-4), LIT (-0x2.9ba374c24b1153a03837923184p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffc8p-4), LIT (-0x2.9ba374c24b1153a03837923184p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffccp-4), LIT (-0x2.9ba374c24b1153a03837923184p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb2909294dbe3024p-4), LIT (0x2.eef4b9d645c4739fb50712af35p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb2909294dbe3028p-4), LIT (0x2.eef4b9d645c4739fb50712af35p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb2909294dbe3024p-4), LIT (0x2.eef4b9d645c4739fb50712af35p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb2909294dbe3028p-4), LIT (0x2.eef4b9d645c4739fb50712af36p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3661470a4141cp-4), LIT (-0x5.110b4629ba218b7e6faceb4a4ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661470a4141cp-4), LIT (-0x5.110b4629ba218b7e6faceb4a4cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661470a4141cp-4), LIT (-0x5.110b4629ba218b7e6faceb4a4cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3661470a4142p-4), LIT (-0x5.110b4629ba218b7e6faceb4a4cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.ffffffffffffffffffffffffbp-4), LIT (0x3.1e35ebf8c21e7a9dfef54c3a6bp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb4p-4), LIT (0x3.1e35ebf8c21e7a9dfef54c3a6cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbp-4), LIT (0x3.1e35ebf8c21e7a9dfef54c3a6bp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb4p-4), LIT (0x3.1e35ebf8c21e7a9dfef54c3a6cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.ffffffffffffffffffffffffbp-4), LIT (0x3.1e35ebf8c21e9a9dfef54c3a6cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb4p-4), LIT (0x3.1e35ebf8c21e9a9dfef54c3a6dp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbp-4), LIT (0x3.1e35ebf8c21e9a9dfef54c3a6cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb4p-4), LIT (0x3.1e35ebf8c21e9a9dfef54c3a6dp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.ffffffffffffffffffffffffbp-4), LIT (0x3.1e5388c77c5e1a9eea1483e45bp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb4p-4), LIT (0x3.1e5388c77c5e1a9eea1483e45cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbp-4), LIT (0x3.1e5388c77c5e1a9eea1483e45bp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb4p-4), LIT (0x3.1e5388c77c5e1a9eea1483e45cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.ffffffffffffffffffffffffbp-4), LIT (0x3.1dd388c77c5e1a9af1c44cbd6ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb4p-4), LIT (0x3.1dd388c77c5e1a9af1c44cbd6ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffbp-4), LIT (0x3.1dd388c77c5e1a9af1c44cbd6ep-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffb4p-4), LIT (0x3.1dd388c77c5e1a9af1c44cbd6fp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffffffffffedcp-4), LIT (0x6.03d388c77c5e319e62c4026616p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffeep-4), LIT (0x6.03d388c77c5e319e62c4026618p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffedcp-4), LIT (0x6.03d388c77c5e319e62c4026616p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffeep-4), LIT (0x6.03d388c77c5e319e62c4026618p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffffffffffffffffdcp-4), LIT (0x2.03d388c77c5e11dbe10acafa31p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffep-4), LIT (0x2.03d388c77c5e11dbe10acafa31p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffdcp-4), LIT (0x2.03d388c77c5e11dbe10acafa31p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffffffffffffep-4), LIT (0x2.03d388c77c5e11dbe10acafa32p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29091bbe2435d8p-4), LIT (0x2.eef4ba203d346ec486fd3d07aap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29091bbe2435d8p-4), LIT (0x2.eef4ba203d346ec486fd3d07abp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29091bbe2435d8p-4), LIT (0x2.eef4ba203d346ec486fd3d07aap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29091bbe2435dcp-4), LIT (0x2.eef4ba203d346ec486fd3d07abp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a3662bdcc1f98cp-4), LIT (-0x5.110b45dfc2b1ee86f90695ac3ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3662bdcc1f99p-4), LIT (-0x5.110b45dfc2b1ee86f90695ac3ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3662bdcc1f98cp-4), LIT (-0x5.110b45dfc2b1ee86f90695ac38p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a3662bdcc1f99p-4), LIT (-0x5.110b45dfc2b1ee86f90695ac38p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.fffffffffedbb3954720063c38p-4), LIT (0x6.0b6b939a00d5748348fcd0fd14p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3cp-4), LIT (0x6.0b6b939a00d5748348fcd0fd14p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c38p-4), LIT (0x6.0b6b939a00d5748348fcd0fd14p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3cp-4), LIT (0x6.0b6b939a00d5748348fcd0fd16p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.fffffffffedbb3954720063c38p-4), LIT (0x6.0b6b939a00d5748348fed0fd16p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3cp-4), LIT (0x6.0b6b939a00d5748348fed0fd16p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c38p-4), LIT (0x6.0b6b939a00d5748348fed0fd16p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954720063c3cp-4), LIT (0x6.0b6b939a00d5748348fed0fd18p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffedbb395471f533d3p-4), LIT (0x6.0b6b939a02af4170b4c610596p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395471f533d34p-4), LIT (0x6.0b6b939a02af4170b4c6105962p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395471f533d3p-4), LIT (0x6.0b6b939a02af4170b4c610596p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395471f533d34p-4), LIT (0x6.0b6b939a02af4170b4c6105962p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffedbb395472258f3p-4), LIT (0x6.0b6b9399faaf4169028a0f85fp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395472258f3p-4), LIT (0x6.0b6b9399faaf4169028a0f85fp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395472258f3p-4), LIT (0x6.0b6b9399faaf4169028a0f85fp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395472258f304p-4), LIT (0x6.0b6b9399faaf4169028a0f85f2p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffedbb395359d3f141p-4), LIT (0x6.0b6b93c85aaf6e06365ed9368cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395359d3f141p-4), LIT (0x6.0b6b93c85aaf6e06365ed9368cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395359d3f141p-4), LIT (0x6.0b6b93c85aaf6e06365ed9368cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb395359d3f1414p-4), LIT (0x6.0b6b93c85aaf6e06365ed9368ep-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffedbb3954dcaed79f4p-4), LIT (0x6.0b6b93885aaf307456583db1dcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954dcaed79f4p-4), LIT (0x6.0b6b93885aaf307456583db1dcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954dcaed79f4p-4), LIT (0x6.0b6b93885aaf307456583db1dcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3954dcaed79f8p-4), LIT (0x6.0b6b93885aaf307456583db1dep-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.fffffffffd7b28d5c92c7abae8p-4), LIT (0x8.fa60505acb795d31d8828462e4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28d5c92c7abae8p-4), LIT (0x8.fa60505acb795d31d8828462e8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28d5c92c7abae8p-4), LIT (0x8.fa60505acb795d31d8828462e4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28d5c92c7abaecp-4), LIT (0x8.fa60505acb795d31d8828462e8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffff858fe6f01a77dfcp-4), LIT (0xf.a6048a88f5ed86bbfddbf1bd8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff858fe6f01a77ep-4), LIT (0xf.a6048a88f5ed86bbfddbf1bd84p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff858fe6f01a77dfcp-4), LIT (0xf.a6048a88f5ed86bbfddbf1bd8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff858fe6f01a77ep-4), LIT (0xf.a6048a88f5ed86bbfddbf1bd84p-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c06p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c06p+0), { LIT (0xf.ffffffffffae04a3471f484bfp-4), LIT (-0x3.33826561fcbf77a265dbec251fp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bfp-4), LIT (-0x3.33826561fcbf77a265dbec251fp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bfp-4), LIT (-0x3.33826561fcbf77a265dbec251ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf4p-4), LIT (-0x3.33826561fcbf77a265dbec251ep-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a62633145c08p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a62633145c08p+0), { LIT (0xf.ffffffffffae04a3471f484bfp-4), LIT (-0x3.33826561fcbf77a265d9ec252p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bfp-4), LIT (-0x3.33826561fcbf77a265d9ec252p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bfp-4), LIT (-0x3.33826561fcbf77a265d9ec251fp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471f484bf4p-4), LIT (-0x3.33826561fcbf77a265d9ec251fp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.ffffffffffae04a3471fa717acp-4), LIT (-0x3.33826561fae5aab7b34743c39fp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471fa717bp-4), LIT (-0x3.33826561fae5aab7b34743c39fp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471fa717acp-4), LIT (-0x3.33826561fae5aab7b34743c39ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471fa717bp-4), LIT (-0x3.33826561fae5aab7b34743c39ep-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.ffffffffffae04a3471e0d567cp-4), LIT (-0x3.3382656202e5aab39fd8955307p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471e0d567cp-4), LIT (-0x3.3382656202e5aab39fd8955307p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471e0d567cp-4), LIT (-0x3.3382656202e5aab39fd8955306p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3471e0d568p-4), LIT (-0x3.3382656202e5aab39fd8955306p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffae04a35065594358p-4), LIT (-0x3.33826533a2e5c2544573ca0274p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3506559435cp-4), LIT (-0x3.33826533a2e5c2544573ca0274p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a35065594358p-4), LIT (-0x3.33826533a2e5c2544573ca0273p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a3506559435cp-4), LIT (-0x3.33826533a2e5c2544573ca0273p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffae04a343974fb49p-4), LIT (-0x3.33826573a2e5a1b8d0004544c6p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a343974fb49p-4), LIT (-0x3.33826573a2e5a1b8d0004544c5p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a343974fb49p-4), LIT (-0x3.33826573a2e5a1b8d0004544c5p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04a343974fb494p-4), LIT (-0x3.33826573a2e5a1b8d0004544c5p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffff6d236dbabdebb8p-4), LIT (-0x4.48dacf23d53e61b713c9d2f466p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d236dbabdebbcp-4), LIT (-0x4.48dacf23d53e61b713c9d2f464p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d236dbabdebb8p-4), LIT (-0x4.48dacf23d53e61b713c9d2f464p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d236dbabdebbcp-4), LIT (-0x4.48dacf23d53e61b713c9d2f464p-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffddd264f0fca0f5b98p-4), LIT (-0x8.448da8dece7042b950121c28a4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd264f0fca0f5b98p-4), LIT (-0x8.448da8dece7042b950121c28ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd264f0fca0f5b98p-4), LIT (-0x8.448da8dece7042b950121c28ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd264f0fca0f5b9cp-4), LIT (-0x8.448da8dece7042b950121c28ap-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+0 + +0 i, 0xap+0 + +0 i", LIT (0x2p+0), LIT (0x0p+0), LIT (0xap+0), LIT (0x0p+0), { LIT (0x4p+8), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+0 + 0x3p+0 i, 0x4p+0 + +0 i", LIT (0x2p+0), LIT (0x3p+0), LIT (0x4p+0), LIT (0x0p+0), { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4 + 0x1.4p+0 i, +0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x0p+0), LIT (0x1p+0), { LIT (0x5.4f283113fa8a525b30b312aa4ep-4), LIT (0x2.19f6810e8fdb408ac45c5250acp-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a525b30b312aa4ep-4), LIT (0x2.19f6810e8fdb408ac45c5250adp-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a525b30b312aa4ep-4), LIT (0x2.19f6810e8fdb408ac45c5250acp-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a525b30b312aa5p-4), LIT (0x2.19f6810e8fdb408ac45c5250adp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + +0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x0p+0), { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x1p+0), { LIT (0x1.5aea037cc815ad16ef12e71ae3p-4), LIT (0x8.366b1e23e511575a1025151164p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16ef12e71ae38p-4), LIT (0x8.366b1e23e511575a1025151164p-4), ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16ef12e71ae3p-4), LIT (0x8.366b1e23e511575a1025151164p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16ef12e71ae38p-4), LIT (0x8.366b1e23e511575a1025151168p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4 + 0x1.4p+0 i, 0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.e14e4796fd3f16019f9eb014858p-4), LIT (0x5.8b7ae4dbf0a7933416f4a46c0ap-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f16019f9eb01486p-4), LIT (0x5.8b7ae4dbf0a7933416f4a46c0cp-4), ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f16019f9eb014858p-4), LIT (0x5.8b7ae4dbf0a7933416f4a46c0ap-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f16019f9eb01486p-4), LIT (0x5.8b7ae4dbf0a7933416f4a46c0cp-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0 + +0 i, +0 + +0 i", LIT (0x1p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x0p+0), { LIT (0x1p+0), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x4.802cf3cf653e819p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.802cf3cf653e8188p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x4.802cf3cf653e8188p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.802cf3cf653e8188p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0xc.802cf3cf653e819p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.802cf3cf653e818p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0xc.802cf3cf653e818p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.802cf3cf653e818p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x2.e537fd30c309ac14p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e537fd30c309ac14p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x2.e537fd30c309ac14p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e537fd30c309ac18p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.1ac802cf3cf653e8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1ac802cf3cf653e6p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.1ac802cf3cf653e6p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1ac802cf3cf653e6p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9ee537b9e08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9ee537b9e0cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9ee537b9e08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9ee537b9e0cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611ac6a7fb8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611ac6a7fbp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611ac6a7fbp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a37p-4), LIT (-0x5.110b4611ac6a7fbp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x4.bec1074429a07668p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4.bec1074429a07668p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x4.bec1074429a07668p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4.bec1074429a0767p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x3.413ef8bbd65f899cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.413ef8bbd65f8998p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x3.413ef8bbd65f8998p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.413ef8bbd65f8998p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x2.e5cbec1074429a08p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e5cbec1074429a08p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x2.e5cbec1074429a08p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e5cbec1074429a0cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.1a3413ef8bbd65fap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1a3413ef8bbd65fap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.1a3413ef8bbd65f8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1a3413ef8bbd65f8p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9ee5cba8c08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9ee5cba8c0cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9ee5cba8c08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9ee5cba8c0cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611a32b91cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611a32b91cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611a32b91b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a37p-4), LIT (-0x5.110b4611a32b91b8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.812374c24b1157dcp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.812374c24b1157dap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.812374c24b1157dap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.812374c24b1157dap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.81a374c24b1157dap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.81a374c24b1157d8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.81a374c24b1157d8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.81a374c24b1157d8p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x1.645c8b3db4ee9d0ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.645c8b3db4ee9d0cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x1.645c8b3db4ee9d0ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.645c8b3db4ee9d0cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x2.9ba374c24b1153a4p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.9ba374c24b1153ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x2.9ba374c24b1153ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.9ba374c24b1153ap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9d645c4739cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9d645c473ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9d645c4739cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9d645c473ap-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4629ba218b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4629ba218b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4629ba218b78p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a37p-4), LIT (-0x5.110b4629ba218b78p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x3.1e5388c77c5e1a9cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.1e5388c77c5e1aap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x3.1e5388c77c5e1a9cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.1e5388c77c5e1aap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x3.1dd388c77c5e1a98p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.1dd388c77c5e1a9cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x3.1dd388c77c5e1a98p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.1dd388c77c5e1a9cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x6.03d388c77c5e3198p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x6.03d388c77c5e31ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x6.03d388c77c5e3198p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x6.03d388c77c5e31ap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x2.03d388c77c5e11d8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.03d388c77c5e11dcp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x2.03d388c77c5e11d8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.03d388c77c5e11dcp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4ba203d346ec4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4ba203d346ec4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4ba203d346ec4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4ba203d346ec8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b45dfc2b1ee88p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b45dfc2b1ee88p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b45dfc2b1ee8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a37p-4), LIT (-0x5.110b45dfc2b1ee8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b939a02af417p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b939a02af417p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b939a02af417p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3ap-4), LIT (0x6.0b6b939a02af4178p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b9399faaf4168p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b9399faaf4168p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b9399faaf4168p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3ap-4), LIT (0x6.0b6b9399faaf417p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93c85aaf6ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93c85aaf6e08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93c85aaf6ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3ap-4), LIT (0x6.0b6b93c85aaf6e08p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93885aaf307p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93885aaf3078p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93885aaf307p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3ap-4), LIT (0x6.0b6b93885aaf3078p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.fffffffffd7b28dp-4), LIT (0x8.fa60505acb795d3p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28dp-4), LIT (0x8.fa60505acb795d3p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28dp-4), LIT (0x8.fa60505acb795d3p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28ep-4), LIT (0x8.fa60505acb795d4p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffff858fp-4), LIT (0xf.a6048a88f5ed86bp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff859p-4), LIT (0xf.a6048a88f5ed86cp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff858fp-4), LIT (0xf.a6048a88f5ed86bp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff859p-4), LIT (0xf.a6048a88f5ed86cp-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826561fae5aab8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826561fae5aab8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826561fae5aab4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04bp-4), LIT (-0x3.33826561fae5aab4p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.3382656202e5aab4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.3382656202e5aab4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.3382656202e5aabp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04bp-4), LIT (-0x3.3382656202e5aabp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826533a2e5c258p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826533a2e5c254p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826533a2e5c254p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04bp-4), LIT (-0x3.33826533a2e5c254p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826573a2e5a1bcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826573a2e5a1b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826573a2e5a1b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04bp-4), LIT (-0x3.33826573a2e5a1b8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffff6d2p-4), LIT (-0x4.48dacf23d53e61b8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d2p-4), LIT (-0x4.48dacf23d53e61b8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d2p-4), LIT (-0x4.48dacf23d53e61bp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d3p-4), LIT (-0x4.48dacf23d53e61bp-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffddd264p-4), LIT (-0x8.448da8dece7042cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd265p-4), LIT (-0x8.448da8dece7042cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd264p-4), LIT (-0x8.448da8dece7042bp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd265p-4), LIT (-0x8.448da8dece7042bp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+0 + +0 i, 0xap+0 + +0 i", LIT (0x2p+0), LIT (0x0p+0), LIT (0xap+0), LIT (0x0p+0), { LIT (0x4p+8), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+0 + 0x3p+0 i, 0x4p+0 + +0 i", LIT (0x2p+0), LIT (0x3p+0), LIT (0x4p+0), LIT (0x0p+0), { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4 + 0x1.4p+0 i, +0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x0p+0), LIT (0x1p+0), { LIT (0x5.4f283113fa8a5258p-4), LIT (0x2.19f6810e8fdb4088p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a5258p-4), LIT (0x2.19f6810e8fdb408cp-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a5258p-4), LIT (0x2.19f6810e8fdb4088p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a526p-4), LIT (0x2.19f6810e8fdb408cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + +0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x0p+0), { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x1p+0), { LIT (0x1.5aea037cc815ad16p-4), LIT (0x8.366b1e23e511575p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16p-4), LIT (0x8.366b1e23e511576p-4), ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16p-4), LIT (0x8.366b1e23e511575p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad18p-4), LIT (0x8.366b1e23e511576p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4 + 0x1.4p+0 i, 0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.e14e4796fd3f16p-4), LIT (0x5.8b7ae4dbf0a7933p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f1602p-4), LIT (0x5.8b7ae4dbf0a79338p-4), ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f16p-4), LIT (0x5.8b7ae4dbf0a7933p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f1602p-4), LIT (0x5.8b7ae4dbf0a79338p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0 + +0 i, +0 + +0 i", LIT (0x1p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x0p+0), { LIT (0x1p+0), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x4.802cf3cf653e819p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.802cf3cf653e8188p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x4.802cf3cf653e8188p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x4.802cf3cf653e8188p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0xc.802cf3cf653e819p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.802cf3cf653e818p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0xc.802cf3cf653e818p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0xc.802cf3cf653e818p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x2.e537fd30c309ac14p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e537fd30c309ac14p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x2.e537fd30c309ac14p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e537fd30c309ac18p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.1ac802cf3cf653e8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1ac802cf3cf653e6p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.1ac802cf3cf653e6p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1ac802cf3cf653e6p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9ee537b9e08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9ee537b9e0cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9ee537b9e08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9ee537b9e0cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a68p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a68p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611ac6a7fb8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611ac6a7fbp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611ac6a7fbp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a37p-4), LIT (-0x5.110b4611ac6a7fbp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x4.bec1074429a07668p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4.bec1074429a07668p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x4.bec1074429a07668p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x4.bec1074429a0767p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x3.413ef8bbd65f899cp-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.413ef8bbd65f8998p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x3.413ef8bbd65f8998p-64), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x3.413ef8bbd65f8998p-64), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x2.e5cbec1074429a08p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e5cbec1074429a08p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x2.e5cbec1074429a08p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.e5cbec1074429a0cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.1a3413ef8bbd65fap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1a3413ef8bbd65fap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.1a3413ef8bbd65f8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.1a3413ef8bbd65f8p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9ee5cba8c08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9ee5cba8c0cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9ee5cba8c08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9ee5cba8c0cp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a6cp+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2a6cp+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611a32b91cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611a32b91cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4611a32b91b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a37p-4), LIT (-0x5.110b4611a32b91b8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.812374c24b1157dcp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.812374c24b1157dap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.812374c24b1157dap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.812374c24b1157dap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.81a374c24b1157dap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.81a374c24b1157d8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x1.81a374c24b1157d8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x1.81a374c24b1157d8p-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x1.645c8b3db4ee9d0ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.645c8b3db4ee9d0cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x1.645c8b3db4ee9d0ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x1.645c8b3db4ee9d0cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffp-4), LIT (-0x2.9ba374c24b1153a4p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.9ba374c24b1153ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (-0x2.9ba374c24b1153ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (-0x2.9ba374c24b1153ap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9d645c4739cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9d645c473ap-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4b9d645c4739cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4b9d645c473ap-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed2p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4629ba218b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4629ba218b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b4629ba218b78p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a37p-4), LIT (-0x5.110b4629ba218b78p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x3.1e5388c77c5e1a9cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.1e5388c77c5e1aap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x3.1e5388c77c5e1a9cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.1e5388c77c5e1aap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x3.1dd388c77c5e1a98p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.1dd388c77c5e1a9cp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x3.1dd388c77c5e1a98p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x3.1dd388c77c5e1a9cp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x6.03d388c77c5e3198p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x6.03d388c77c5e31ap-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x6.03d388c77c5e3198p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x6.03d388c77c5e31ap-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffffffffp-4), LIT (0x2.03d388c77c5e11d8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.03d388c77c5e11dcp-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), LIT (0x2.03d388c77c5e11d8p-52), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1p+0), LIT (0x2.03d388c77c5e11dcp-52), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4ba203d346ec4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4ba203d346ec4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb29p-4), LIT (0x2.eef4ba203d346ec4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffbb291p-4), LIT (0x2.eef4ba203d346ec8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed4p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e151628aed4p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b45dfc2b1ee88p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b45dfc2b1ee88p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a36p-4), LIT (-0x5.110b45dfc2b1ee8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff32a37p-4), LIT (-0x5.110b45dfc2b1ee8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b939a02af417p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b939a02af417p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b939a02af417p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3ap-4), LIT (0x6.0b6b939a02af4178p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b9399faaf4168p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b9399faaf4168p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b9399faaf4168p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3ap-4), LIT (0x6.0b6b9399faaf417p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93c85aaf6ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93c85aaf6e08p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93c85aaf6ep-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3ap-4), LIT (0x6.0b6b93c85aaf6e08p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93885aaf307p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93885aaf3078p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb39p-4), LIT (0x6.0b6b93885aaf307p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffedbb3ap-4), LIT (0x6.0b6b93885aaf3078p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.fffffffffd7b28dp-4), LIT (0x8.fa60505acb795d3p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28dp-4), LIT (0x8.fa60505acb795d3p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28dp-4), LIT (0x8.fa60505acb795d3p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffd7b28ep-4), LIT (0x8.fa60505acb795d4p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e154p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e154p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffff858fp-4), LIT (0xf.a6048a88f5ed86bp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff859p-4), LIT (0xf.a6048a88f5ed86cp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff858fp-4), LIT (0xf.a6048a88f5ed86bp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffff859p-4), LIT (0xf.a6048a88f5ed86cp-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611a8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611a8p+0), { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826561fae5aab8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826561fae5aab8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826561fae5aab4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04bp-4), LIT (-0x3.33826561fae5aab4p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b4611ap+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b4611ap+0), { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.3382656202e5aab4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.3382656202e5aab4p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.3382656202e5aabp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04bp-4), LIT (-0x3.3382656202e5aabp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b464p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b464p+0), { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826533a2e5c258p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826533a2e5c254p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826533a2e5c254p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04bp-4), LIT (-0x3.33826533a2e5c254p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed5110b46p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed5110b46p+0), { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826573a2e5a1bcp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826573a2e5a1b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04ap-4), LIT (-0x3.33826573a2e5a1b8p-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffae04bp-4), LIT (-0x3.33826573a2e5a1b8p-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487ed8p+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487ed8p+0), { LIT (0xf.ffffffffffff6d2p-4), LIT (-0x4.48dacf23d53e61b8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d2p-4), LIT (-0x4.48dacf23d53e61b8p-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d2p-4), LIT (-0x4.48dacf23d53e61bp-28), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff6d3p-4), LIT (-0x4.48dacf23d53e61bp-28), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e15p+0 + +0 i, +0 + 0x6.487edp+0 i", LIT (0x2.b7e15p+0), LIT (0x0p+0), LIT (0x0p+0), LIT (0x6.487edp+0), { LIT (0xf.fffffffffddd264p-4), LIT (-0x8.448da8dece7042cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd265p-4), LIT (-0x8.448da8dece7042cp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd264p-4), LIT (-0x8.448da8dece7042bp-24), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0xf.fffffffffddd265p-4), LIT (-0x8.448da8dece7042bp-24), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+0 + +0 i, 0xap+0 + +0 i", LIT (0x2p+0), LIT (0x0p+0), LIT (0xap+0), LIT (0x0p+0), { LIT (0x4p+8), LIT (-0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED }, { LIT (0x4p+8), LIT (0x0p+0), IGNORE_ZERO_INF_SIGN | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+0 + 0x3p+0 i, 0x4p+0 + +0 i", LIT (0x2p+0), LIT (0x3p+0), LIT (0x4p+0), LIT (0x0p+0), { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (-0x7.7p+4), LIT (-0x7.8p+4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4 + 0x1.4p+0 i, +0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x0p+0), LIT (0x1p+0), { LIT (0x5.4f283113fa8a5258p-4), LIT (0x2.19f6810e8fdb4088p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a5258p-4), LIT (0x2.19f6810e8fdb408cp-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a5258p-4), LIT (0x2.19f6810e8fdb4088p-4), ERRNO_UNCHANGED }, { LIT (0x5.4f283113fa8a526p-4), LIT (0x2.19f6810e8fdb408cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + +0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x0p+0), { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED }, { LIT (0xcp-4), LIT (0x1.4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4 + 0x1.4p+0 i, 0x1p+0 + 0x1p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0x1p+0), LIT (0x1p+0), { LIT (0x1.5aea037cc815ad16p-4), LIT (0x8.366b1e23e511575p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16p-4), LIT (0x8.366b1e23e511576p-4), ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad16p-4), LIT (0x8.366b1e23e511575p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.5aea037cc815ad18p-4), LIT (0x8.366b1e23e511576p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4 + 0x1.4p+0 i, 0xcp-4 + 0x1.4p+0 i", LIT (0xcp-4), LIT (0x1.4p+0), LIT (0xcp-4), LIT (0x1.4p+0), { LIT (0x1.e14e4796fd3f16p-4), LIT (0x5.8b7ae4dbf0a7933p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f1602p-4), LIT (0x5.8b7ae4dbf0a79338p-4), ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f16p-4), LIT (0x5.8b7ae4dbf0a7933p-4), XFAIL_TEST | ERRNO_UNCHANGED }, { LIT (0x1.e14e4796fd3f1602p-4), LIT (0x5.8b7ae4dbf0a79338p-4), XFAIL_TEST | ERRNO_UNCHANGED } },
#endif
  };

static void
cpow_test (void)
{
  ALL_RM_TEST (cpow, 0, cpow_test_data, RUN_TEST_LOOP_cc_c, END_COMPLEX);
}

static void
do_test (void)
{
  cpow_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

/* Test log.
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

static const struct test_f_f_data log_test_data[] =
  {
    { "0", 0, { minus_infty, DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE }, { minus_infty, DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE }, { minus_infty, DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE }, { minus_infty, DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE } },
    { "-0", minus_zero, { minus_infty, DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE }, { minus_infty, DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE }, { minus_infty, DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE }, { minus_infty, DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE } },

    { "-1", -1, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM } },
    { "-min_subnorm_value", -min_subnorm_value, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM } },
    { "-min_value", -min_value, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM } },
    { "-max_value", -max_value, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM } },
    { "-inf", minus_infty, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM }, { qnan_value, INVALID_EXCEPTION|ERRNO_EDOM } },
    { "inf", plus_infty, { plus_infty, ERRNO_UNCHANGED }, { plus_infty, ERRNO_UNCHANGED }, { plus_infty, ERRNO_UNCHANGED }, { plus_infty, ERRNO_UNCHANGED } },
    { "qNaN", qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "sNaN", snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },
    { "-sNaN", -snan_value, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION }, { qnan_value, TEST_SNAN|INVALID_EXCEPTION } },

#if (TEST_COND_binary128)
    { "0x1.0000000000000000000000000001p+0", LIT (0x1.0000000000000000000000000001p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-116), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-116), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-116), ERRNO_UNCHANGED }, { LIT (0x1p-112), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.000000000000000000000000008p+0", LIT (0x1.000000000000000000000000008p+0), { LIT (0x7.fffffffffffffffffffffffffep-108), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-108), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-108), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffe04p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0000000000000002p+0", LIT (0x1.0000000000000002p+0), { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffe000000000001p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0000000000001p+0", LIT (0x1.0000000000001p+0), { LIT (0xf.ffffffffffff800000000000055p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8000000000000558p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff800000000000055p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8000000000000558p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x1.fffffe000002aaaaa6aaaab11111p-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaaa6aaaab11111p-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaaa6aaaab11111p-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaaa6aaaab11112p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.017f8ap+44", LIT (0x1.017f8ap+44), { LIT (0x1.e811a8a66aa569880c5e8ea2ec2p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa569880c5e8ea2ec2p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa569880c5e8ea2ec2p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa569880c5e8ea2ec21p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.0b5c1ep+36", LIT (0x1.0b5c1ep+36), { LIT (0x1.8ff28cfed79a1001419ce243f3acp+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1001419ce243f3acp+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1001419ce243f3acp+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1001419ce243f3adp+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.6c3f6p+0", LIT (0x1.6c3f6p+0), { LIT (0x5.a47aee2b5c34f7fed8c38bb73dcp-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f7fed8c38bb73dc4p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f7fed8c38bb73dcp-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f7fed8c38bb73dc4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.770072p+0", LIT (0x1.770072p+0), { LIT (0x6.1ba943bb20434dc4abd932bca66p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc4abd932bca664p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc4abd932bca66p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc4abd932bca664p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.929d9cp+0", LIT (0x1.929d9cp+0), { LIT (0x7.3eb06c60714c5ffbcdb915af266p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ffbcdb915af2664p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ffbcdb915af266p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ffbcdb915af2664p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.1b17c2887e938p+928", LIT (0x2.1b17c2887e938p+928), { LIT (0x2.83fc3c37fc58ffff8f99749ff1e4p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58ffff8f99749ff1e6p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58ffff8f99749ff1e4p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58ffff8f99749ff1e6p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a68p+0", LIT (0x2.b7e151628aed2a68p+0), { LIT (0xf.ffffffffffffffefd37c671cbdp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffefd37c671cbd08p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffefd37c671cbdp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffefd37c671cbd08p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf4p+0", LIT (0x2.b7e151628aed2a6abf7158809cf4p+0), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cf6p+0", LIT (0x2.b7e151628aed2a6abf7158809cf6p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809cp+0", LIT (0x2.b7e151628aed2a6abf7158809cp+0), { LIT (0xf.fffffffffffffffffffffffffa58p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffa6p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffa58p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffa6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6abf7158809dp+0", LIT (0x2.b7e151628aed2a6abf7158809dp+0), { LIT (0x1.0000000000000000000000000004p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000004p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000004p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000005p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2a6cp+0", LIT (0x2.b7e151628aed2a6cp+0), { LIT (0x1.000000000000000075ed29d49ac3p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000075ed29d49ac4p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000075ed29d49ac3p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000075ed29d49ac4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed2p+0", LIT (0x2.b7e151628aed2p+0), { LIT (0xf.ffffffffffffc2af55337636657p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2af553376366578p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2af55337636657p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2af553376366578p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e151628aed4p+0", LIT (0x2.b7e151628aed4p+0), { LIT (0x1.00000000000007f0a06e4ddb0222p+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007f0a06e4ddb0222p+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007f0a06e4ddb0222p+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007f0a06e4ddb0223p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e154p+0", LIT (0x2.b7e154p+0), { LIT (0x1.000000f647925f34d03716a8b6ccp+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34d03716a8b6ccp+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34d03716a8b6ccp+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34d03716a8b6cdp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7e15p+0", LIT (0x2.b7e15p+0), { LIT (0xf.fffff7d922f51a2d208d1c4e821p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a2d208d1c4e821p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a2d208d1c4e821p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a2d208d1c4e8218p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xb.17217f7d1cf79abc9e3b39803f28p-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79abc9e3b39803f3p-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79abc9e3b39803f28p-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79abc9e3b39803f3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (-0x2.c5bd48bdc7c0c9b78cd23024d64cp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b78cd23024d64cp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b78cd23024d64ap+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b78cd23024d64ap+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (-0x2.c4657baf579a47bbcffb06f8dfc4p+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47bbcffb06f8dfc4p+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47bbcffb06f8dfc2p+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47bbcffb06f8dfc2p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (-0x2.e870a88dae386c72b4fd4773c092p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c72b4fd4773c092p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c72b4fd4773c09p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c72b4fd4773c09p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-128", LIT (0x4p-128), { LIT (-0x5.75627cbf9441de28d5e1264d1f1cp+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28d5e1264d1f18p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28d5e1264d1f18p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28d5e1264d1f18p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (-0x2.c5b2319c4843acbff21591e99cccp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843acbff21591e99cccp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843acbff21591e99ccap+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843acbff21591e99ccap+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (-0x2.c877f9fc278aeaa6a13d20b7fcdcp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c877f9fc278aeaa6a13d20b7fcdcp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c877f9fc278aeaa6a13d20b7fcdap+12), ERRNO_UNCHANGED }, { LIT (-0x2.c877f9fc278aeaa6a13d20b7fcdap+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496", LIT (0x4p-16496), { LIT (-0x2.ca8c50440f005913a49acbd2c4e8p+12), ERRNO_UNCHANGED }, { LIT (-0x2.ca8c50440f005913a49acbd2c4e8p+12), ERRNO_UNCHANGED }, { LIT (-0x2.ca8c50440f005913a49acbd2c4e6p+12), ERRNO_UNCHANGED }, { LIT (-0x2.ca8c50440f005913a49acbd2c4e6p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d588p-4", LIT (0x5.e2d588p-4), { LIT (-0x1.000000f11e085f422347d5acdb97p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f422347d5acdb97p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f422347d5acdb96p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f422347d5acdb96p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d58d8b3bcdcp-4", LIT (0x5.e2d58d8b3bcdcp-4), { LIT (-0x1.00000000000008704ccdb47c1f23p+0), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000008704ccdb47c1f23p+0), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000008704ccdb47c1f22p+0), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000008704ccdb47c1f22p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d58d8b3bcdf1a8p-4", LIT (0x5.e2d58d8b3bcdf1a8p-4), { LIT (-0x1.0000000000000000a006a027f5f3p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000a006a027f5f3p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000a006a027f5f2p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000a006a027f5f2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d58d8b3bcdf1abadec782904p-4", LIT (0x5.e2d58d8b3bcdf1abadec782904p-4), { LIT (-0x1.000000000000000000000000003ap+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000000000000039p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000000000000039p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000000000000039p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d58d8b3bcdf1abadec7829054cp-4", LIT (0x5.e2d58d8b3bcdf1abadec7829054cp-4), { LIT (-0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d58d8b3bcdf1abadec7829055p-4", LIT (0x5.e2d58d8b3bcdf1abadec7829055p-4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d58d8b3bcdf1abadec782906p-4", LIT (0x5.e2d58d8b3bcdf1abadec782906p-4), { LIT (-0xf.fffffffffffffffffffffffffe28p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffe2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffe2p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffe2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d58d8b3bcdf1bp-4", LIT (0x5.e2d58d8b3bcdf1bp-4), { LIT (-0xf.fffffffffffffff4415f776b07c8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff4415f776b07c8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff4415f776b07cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff4415f776b07cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d58d8b3bcep-4", LIT (0x5.e2d58d8b3bcep-4), { LIT (-0xf.ffffffffffffd90c7882a506a588p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd90c7882a506a588p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd90c7882a506a58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd90c7882a506a58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5.e2d59p-4", LIT (0x5.e2d59p-4), { LIT (-0xf.fffff952d5f52b972627765c7b88p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b972627765c7b8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b972627765c7b8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b972627765c7b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152", LIT (0x8p-152), { LIT (-0x6.74767f33d1dc1d0fc8187877a4c8p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d0fc8187877a4c8p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d0fc8187877a4c4p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d0fc8187877a4c4p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (-0x2.c86ce2daa80dcdaf0680827cc35cp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdaf0680827cc35ap+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdaf0680827cc35ap+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdaf0680827cc35ap+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-972", LIT (0x8p-972), { LIT (-0x2.9fa8dcb9092a538b3f2ee2ca66f4p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a538b3f2ee2ca66f2p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a538b3f2ee2ca66f2p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a538b3f2ee2ca66f2p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xa.ae688p-4", LIT (0xa.ae688p-4), { LIT (-0x6.772d36f0dd28c26cc42127335308p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c26cc42127335304p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c26cc42127335304p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c26cc42127335304p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xap+0", LIT (0xap+0), { LIT (0x2.4d763776aaa2b05ba95b58ae0b4cp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05ba95b58ae0b4cp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05ba95b58ae0b4cp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05ba95b58ae0b4ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xb.0d5dfp-4", LIT (0xb.0d5dfp-4), { LIT (-0x5.eb58f885a32d893cb272dbe106p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d893cb272dbe106p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d893cb272dbe105fcp-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d893cb272dbe105fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4", LIT (0xcp-4), { LIT (-0x4.9a58844d36e49e0efadd9db02aa8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e0efadd9db02aa8p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e0efadd9db02aa4p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e0efadd9db02aa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.a0288c3cb5ecp-4", LIT (0xe.a0288c3cb5ecp-4), { LIT (-0x1.6fe0d4c40097884d86068c297d0cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884d86068c297d0cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884d86068c297d0bp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884d86068c297d0bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.a0288p-4", LIT (0xe.a0288p-4), { LIT (-0x1.6fe0e22718ad77516665df92f5dbp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad77516665df92f5dbp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad77516665df92f5dap-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad77516665df92f5dap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xe.a0289p-4", LIT (0xe.a0289p-4), { LIT (-0x1.6fe0d0a6311e31f19855212ae415p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31f19855212ae415p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31f19855212ae414p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31f19855212ae414p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x2.c5c85fdf473de6a7278ece600fcap+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a7278ece600fccp+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a7278ece600fcap+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a7278ece600fccp+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p-4", LIT (0xf.ffffffffffff8p-4), { LIT (-0x8.00000000000020000000000000bp-56), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000020000000000000a8p-56), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000020000000000000a8p-56), ERRNO_UNCHANGED }, { LIT (-0x8.00000000000020000000000000a8p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x2.c5c85fdf473de6ab278ece600fcap+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6ab278ece600fccp+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6ab278ece600fcap+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6ab278ece600fccp+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffcp-4", LIT (0xf.fffffffffffffffffffffffffcp-4), { LIT (-0x4.0000000000000000000000000084p-108), ERRNO_UNCHANGED }, { LIT (-0x4.000000000000000000000000008p-108), ERRNO_UNCHANGED }, { LIT (-0x4.000000000000000000000000008p-108), ERRNO_UNCHANGED }, { LIT (-0x4.000000000000000000000000008p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffff8p+16380", LIT (0xf.fffffffffffffffffffffffffff8p+16380), { LIT (0x2.c5c85fdf473de6af278ece600fcap+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6af278ece600fccp+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6af278ece600fcap+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6af278ece600fccp+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffff8p-4", LIT (0xf.fffffffffffffffffffffffffff8p-4), { LIT (-0x8.0000000000000000000000000008p-116), ERRNO_UNCHANGED }, { LIT (-0x8p-116), ERRNO_UNCHANGED }, { LIT (-0x8p-116), ERRNO_UNCHANGED }, { LIT (-0x8p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0x2.c5c85fdf473de6af277ece600fcap+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6af277ece600fccp+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6af277ece600fcap+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6af277ece600fccp+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffp-4", LIT (0xf.fffffffffffffffp-4), { LIT (-0x1.0000000000000000800000000001p-64), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000000008p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x5.8b90bfae8e7bc55e4f18476ac64p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc55e4f18476ac644p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc55e4f18476ac64p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc55e4f18476ac644p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp-4", LIT (0xf.fffffp-4), { LIT (-0x1.0000008000005555559555558889p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005555559555558889p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005555559555558888p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005555559555558888p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x1.fffffep-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffep-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffep-24), ERRNO_UNCHANGED }, { LIT (0x2p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.017f8ap+44", LIT (0x1.017f8ap+44), { LIT (0x1.e811a8p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811aap+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.0b5c1ep+36", LIT (0x1.0b5c1ep+36), { LIT (0x1.8ff28cp+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cp+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cp+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28ep+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.6c3f6p+0", LIT (0x1.6c3f6p+0), { LIT (0x5.a47ae8p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47afp-4), ERRNO_UNCHANGED }, { LIT (0x5.a47ae8p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47afp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.770072p+0", LIT (0x1.770072p+0), { LIT (0x6.1ba94p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba94p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba94p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba948p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.929d9cp+0", LIT (0x1.929d9cp+0), { LIT (0x7.3eb068p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb07p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb068p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb07p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.b7e154p+0", LIT (0x2.b7e154p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.b7e15p+0", LIT (0x2.b7e15p+0), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xb.17217p-4), ERRNO_UNCHANGED }, { LIT (0xb.17218p-4), ERRNO_UNCHANGED }, { LIT (0xb.17217p-4), ERRNO_UNCHANGED }, { LIT (0xb.17218p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-128", LIT (0x4p-128), { LIT (-0x5.75628p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75628p+4), ERRNO_UNCHANGED }, { LIT (-0x5.756278p+4), ERRNO_UNCHANGED }, { LIT (-0x5.756278p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.e2d588p-4", LIT (0x5.e2d588p-4), { LIT (-0x1.000002p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5.e2d59p-4", LIT (0x5.e2d59p-4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152", LIT (0x8p-152), { LIT (-0x6.74768p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74768p+4), ERRNO_UNCHANGED }, { LIT (-0x6.747678p+4), ERRNO_UNCHANGED }, { LIT (-0x6.747678p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xa.ae688p-4", LIT (0xa.ae688p-4), { LIT (-0x6.772d38p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d38p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d3p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xap+0", LIT (0xap+0), { LIT (0x2.4d7634p+0), ERRNO_UNCHANGED }, { LIT (0x2.4d7638p+0), ERRNO_UNCHANGED }, { LIT (0x2.4d7634p+0), ERRNO_UNCHANGED }, { LIT (0x2.4d7638p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xb.0d5dfp-4", LIT (0xb.0d5dfp-4), { LIT (-0x5.eb59p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4", LIT (0xcp-4), { LIT (-0x4.9a5888p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a5888p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a588p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a588p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.a0288p-4", LIT (0xe.a0288p-4), { LIT (-0x1.6fe0e4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xe.a0289p-4", LIT (0xe.a0289p-4), { LIT (-0x1.6fe0d2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0dp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0dp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x5.8b90b8p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90cp+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90b8p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90cp+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp-4", LIT (0xf.fffffp-4), { LIT (-0x1.000002p-24), ERRNO_UNCHANGED }, { LIT (-0x1p-24), ERRNO_UNCHANGED }, { LIT (-0x1p-24), ERRNO_UNCHANGED }, { LIT (-0x1p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0000000000001p+0", LIT (0x1.0000000000001p+0), { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0x1p-52), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x1.fffffe000002ap-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002bp-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002ap-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002bp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.017f8ap+44", LIT (0x1.017f8ap+44), { LIT (0x1.e811a8a66aa56p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa57p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa56p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa57p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.0b5c1ep+36", LIT (0x1.0b5c1ep+36), { LIT (0x1.8ff28cfed79a1p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a2p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.6c3f6p+0", LIT (0x1.6c3f6p+0), { LIT (0x5.a47aee2b5c34cp-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c35p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34cp-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c35p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.770072p+0", LIT (0x1.770072p+0), { LIT (0x6.1ba943bb20434p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20438p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.929d9cp+0", LIT (0x1.929d9cp+0), { LIT (0x7.3eb06c60714c4p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c4p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c4p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.1b17c2887e938p+928", LIT (0x2.1b17c2887e938p+928), { LIT (0x2.83fc3c37fc58ep+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc59p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58ep+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc59p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed2p+0", LIT (0x2.b7e151628aed2p+0), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e151628aed4p+0", LIT (0x2.b7e151628aed4p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e154p+0", LIT (0x2.b7e154p+0), { LIT (0x1.000000f647925p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647926p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647926p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7e15p+0", LIT (0x2.b7e15p+0), { LIT (0xf.fffff7d922f5p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f5p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f5p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xb.17217f7d1cf78p-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf78p-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf78p-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (-0x2.c4657baf579a6p+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a4p+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a4p+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a4p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (-0x2.e870a88dae388p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-128", LIT (0x4p-128), { LIT (-0x5.75627cbf9442p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441cp+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441cp+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441cp+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.e2d588p-4", LIT (0x5.e2d588p-4), { LIT (-0x1.000000f11e086p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e086p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.e2d58d8b3bcdcp-4", LIT (0x5.e2d58d8b3bcdcp-4), { LIT (-0x1.0000000000001p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000001p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.e2d58d8b3bcep-4", LIT (0x5.e2d58d8b3bcep-4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffff8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5.e2d59p-4", LIT (0x5.e2d59p-4), { LIT (-0xf.fffff952d5f58p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f5p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152", LIT (0x8p-152), { LIT (-0x6.74767f33d1dc4p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dcp+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dcp+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dcp+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-972", LIT (0x8p-972), { LIT (-0x2.9fa8dcb9092a6p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a6p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a4p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a4p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xa.ae688p-4", LIT (0xa.ae688p-4), { LIT (-0x6.772d36f0dd29p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28cp-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xap+0", LIT (0xap+0), { LIT (0x2.4d763776aaa2ap+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2cp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2ap+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xb.0d5dfp-4", LIT (0xb.0d5dfp-4), { LIT (-0x5.eb58f885a32dcp-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d8p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4", LIT (0xcp-4), { LIT (-0x4.9a58844d36e4cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e48p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e48p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.a0288c3cb5ecp-4", LIT (0xe.a0288c3cb5ecp-4), { LIT (-0x1.6fe0d4c400979p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c400979p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c400978p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c400978p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.a0288p-4", LIT (0xe.a0288p-4), { LIT (-0x1.6fe0e22718ad8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad7p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad7p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xe.a0289p-4", LIT (0xe.a0289p-4), { LIT (-0x1.6fe0d0a6311e4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e3p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e3p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x2.c5c85fdf473dep+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473dep+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473dep+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473ep+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p-4", LIT (0xf.ffffffffffff8p-4), { LIT (-0x8.0000000000008p-56), ERRNO_UNCHANGED }, { LIT (-0x8p-56), ERRNO_UNCHANGED }, { LIT (-0x8p-56), ERRNO_UNCHANGED }, { LIT (-0x8p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x5.8b90bfae8e7bcp+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bcp+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bcp+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7cp+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp-4", LIT (0xf.fffffp-4), { LIT (-0x1.0000008000006p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.000000000000000000000000008p+0", LIT (0x1.000000000000000000000000008p+0), { LIT (0x7.fffffffffffffffffffffffffep-108), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-108), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffffffep-108), ERRNO_UNCHANGED }, { LIT (0x8p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0000000000000002p+0", LIT (0x1.0000000000000002p+0), { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffe00000000008p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0000000000001p+0", LIT (0x1.0000000000001p+0), { LIT (0xf.ffffffffffff80000000000004p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff80000000000004p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff80000000000004p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff80000000000008p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x1.fffffe000002aaaaa6aaaab111p-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaaa6aaaab111p-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaaa6aaaab111p-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaaa6aaaab1118p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.017f8ap+44", LIT (0x1.017f8ap+44), { LIT (0x1.e811a8a66aa569880c5e8ea2ecp+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa569880c5e8ea2ecp+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa569880c5e8ea2ecp+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa569880c5e8ea2ec8p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.0b5c1ep+36", LIT (0x1.0b5c1ep+36), { LIT (0x1.8ff28cfed79a1001419ce243f38p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1001419ce243f38p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1001419ce243f38p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1001419ce243f4p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.6c3f6p+0", LIT (0x1.6c3f6p+0), { LIT (0x5.a47aee2b5c34f7fed8c38bb73cp-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f7fed8c38bb73ep-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f7fed8c38bb73cp-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f7fed8c38bb73ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.770072p+0", LIT (0x1.770072p+0), { LIT (0x6.1ba943bb20434dc4abd932bca6p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc4abd932bca6p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc4abd932bca6p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc4abd932bca8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.929d9cp+0", LIT (0x1.929d9cp+0), { LIT (0x7.3eb06c60714c5ffbcdb915af26p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ffbcdb915af26p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ffbcdb915af26p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ffbcdb915af28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.1b17c2887e938p+928", LIT (0x2.1b17c2887e938p+928), { LIT (0x2.83fc3c37fc58ffff8f99749ff1p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58ffff8f99749ff2p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58ffff8f99749ff1p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58ffff8f99749ff2p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a68p+0", LIT (0x2.b7e151628aed2a68p+0), { LIT (0xf.ffffffffffffffefd37c671cbcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffefd37c671cbcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffefd37c671cbcp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffefd37c671ccp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809cp+0", LIT (0x2.b7e151628aed2a6abf7158809cp+0), { LIT (0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6abf7158809dp+0", LIT (0x2.b7e151628aed2a6abf7158809dp+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2a6cp+0", LIT (0x2.b7e151628aed2a6cp+0), { LIT (0x1.000000000000000075ed29d49a8p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000075ed29d49bp+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000075ed29d49a8p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000075ed29d49bp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed2p+0", LIT (0x2.b7e151628aed2p+0), { LIT (0xf.ffffffffffffc2af5533763664p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2af5533763664p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2af5533763664p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2af5533763668p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e151628aed4p+0", LIT (0x2.b7e151628aed4p+0), { LIT (0x1.00000000000007f0a06e4ddb02p+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007f0a06e4ddb02p+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007f0a06e4ddb02p+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007f0a06e4ddb028p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e154p+0", LIT (0x2.b7e154p+0), { LIT (0x1.000000f647925f34d03716a8b68p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34d03716a8b7p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34d03716a8b68p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34d03716a8b7p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7e15p+0", LIT (0x2.b7e15p+0), { LIT (0xf.fffff7d922f51a2d208d1c4e8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a2d208d1c4e84p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a2d208d1c4e8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a2d208d1c4e84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xb.17217f7d1cf79abc9e3b39803cp-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79abc9e3b39804p-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79abc9e3b39803cp-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79abc9e3b39804p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (-0x2.c4657baf579a47bbcffb06f8ep+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47bbcffb06f8ep+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47bbcffb06f8dfp+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47bbcffb06f8dfp+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (-0x2.e870a88dae386c72b4fd4773c1p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c72b4fd4773c1p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c72b4fd4773cp+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c72b4fd4773cp+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-128", LIT (0x4p-128), { LIT (-0x5.75627cbf9441de28d5e1264d2p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28d5e1264d2p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28d5e1264d1ep+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28d5e1264d1ep+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.e2d588p-4", LIT (0x5.e2d588p-4), { LIT (-0x1.000000f11e085f422347d5acdcp+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f422347d5acdb8p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f422347d5acdb8p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f422347d5acdb8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.e2d58d8b3bcdcp-4", LIT (0x5.e2d58d8b3bcdcp-4), { LIT (-0x1.00000000000008704ccdb47c1f8p+0), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000008704ccdb47c1fp+0), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000008704ccdb47c1fp+0), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000008704ccdb47c1fp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.e2d58d8b3bcdf1a8p-4", LIT (0x5.e2d58d8b3bcdf1a8p-4), { LIT (-0x1.0000000000000000a006a027f6p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000a006a027f6p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000a006a027f58p+0), ERRNO_UNCHANGED }, { LIT (-0x1.0000000000000000a006a027f58p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.e2d58d8b3bcdf1abadec782904p-4", LIT (0x5.e2d58d8b3bcdf1abadec782904p-4), { LIT (-0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.e2d58d8b3bcdf1abadec782906p-4", LIT (0x5.e2d58d8b3bcdf1abadec782906p-4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.e2d58d8b3bcdf1bp-4", LIT (0x5.e2d58d8b3bcdf1bp-4), { LIT (-0xf.fffffffffffffff4415f776b08p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff4415f776b08p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff4415f776b04p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffff4415f776b04p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.e2d58d8b3bcep-4", LIT (0x5.e2d58d8b3bcep-4), { LIT (-0xf.ffffffffffffd90c7882a506a8p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd90c7882a506a4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd90c7882a506a4p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd90c7882a506a4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5.e2d59p-4", LIT (0x5.e2d59p-4), { LIT (-0xf.fffff952d5f52b972627765c7cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b972627765c7cp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b972627765c78p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b972627765c78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152", LIT (0x8p-152), { LIT (-0x6.74767f33d1dc1d0fc8187877a6p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d0fc8187877a4p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d0fc8187877a4p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d0fc8187877a4p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-972", LIT (0x8p-972), { LIT (-0x2.9fa8dcb9092a538b3f2ee2ca67p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a538b3f2ee2ca67p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a538b3f2ee2ca66p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a538b3f2ee2ca66p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xa.ae688p-4", LIT (0xa.ae688p-4), { LIT (-0x6.772d36f0dd28c26cc421273354p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c26cc421273354p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c26cc421273352p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c26cc421273352p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xap+0", LIT (0xap+0), { LIT (0x2.4d763776aaa2b05ba95b58ae0bp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05ba95b58ae0bp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05ba95b58ae0bp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05ba95b58ae0cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xb.0d5dfp-4", LIT (0xb.0d5dfp-4), { LIT (-0x5.eb58f885a32d893cb272dbe106p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d893cb272dbe106p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d893cb272dbe104p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d893cb272dbe104p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4", LIT (0xcp-4), { LIT (-0x4.9a58844d36e49e0efadd9db02cp-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e0efadd9db02ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e0efadd9db02ap-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e0efadd9db02ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.a0288c3cb5ecp-4", LIT (0xe.a0288c3cb5ecp-4), { LIT (-0x1.6fe0d4c40097884d86068c297d8p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884d86068c297dp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884d86068c297dp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884d86068c297dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.a0288p-4", LIT (0xe.a0288p-4), { LIT (-0x1.6fe0e22718ad77516665df92f6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad77516665df92f6p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad77516665df92f58p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad77516665df92f58p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xe.a0289p-4", LIT (0xe.a0289p-4), { LIT (-0x1.6fe0d0a6311e31f19855212ae48p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31f19855212ae4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31f19855212ae4p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31f19855212ae4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x2.c5c85fdf473de6a7278ece600fp+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a7278ece601p+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a7278ece600fp+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a7278ece601p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p-4", LIT (0xf.ffffffffffff8p-4), { LIT (-0x8.00000000000020000000000004p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x2.c5c85fdf473de6ab278ece600fp+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6ab278ece601p+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6ab278ece600fp+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6ab278ece601p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffffffffffffffffffffffcp-4", LIT (0xf.fffffffffffffffffffffffffcp-4), { LIT (-0x4.00000000000000000000000002p-108), ERRNO_UNCHANGED }, { LIT (-0x4p-108), ERRNO_UNCHANGED }, { LIT (-0x4p-108), ERRNO_UNCHANGED }, { LIT (-0x4p-108), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffffffffffffp-4", LIT (0xf.fffffffffffffffp-4), { LIT (-0x1.000000000000000080000000008p-64), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000000008p-64), ERRNO_UNCHANGED }, { LIT (-0x1.00000000000000008p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x5.8b90bfae8e7bc55e4f18476ac6p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc55e4f18476ac6p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc55e4f18476ac6p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc55e4f18476ac8p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp-4", LIT (0xf.fffffp-4), { LIT (-0x1.00000080000055555595555589p-24), ERRNO_UNCHANGED }, { LIT (-0x1.000000800000555555955555888p-24), ERRNO_UNCHANGED }, { LIT (-0x1.000000800000555555955555888p-24), ERRNO_UNCHANGED }, { LIT (-0x1.000000800000555555955555888p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0000000000000002p+0", LIT (0x1.0000000000000002p+0), { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x2p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0000000000001p+0", LIT (0x1.0000000000001p+0), { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff801p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x1.fffffe000002aaaap-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaap-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaap-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaacp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.017f8ap+44", LIT (0x1.017f8ap+44), { LIT (0x1.e811a8a66aa56988p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa56988p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa56988p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa5698ap+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.0b5c1ep+36", LIT (0x1.0b5c1ep+36), { LIT (0x1.8ff28cfed79a1p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1002p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1002p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.6c3f6p+0", LIT (0x1.6c3f6p+0), { LIT (0x5.a47aee2b5c34f7f8p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f8p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f7f8p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.770072p+0", LIT (0x1.770072p+0), { LIT (0x6.1ba943bb20434dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc8p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.929d9cp+0", LIT (0x1.929d9cp+0), { LIT (0x7.3eb06c60714c5ff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.1b17c2887e938p+928", LIT (0x2.1b17c2887e938p+928), { LIT (0x2.83fc3c37fc58fffcp+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc59p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58fffcp+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc59p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a68p+0", LIT (0x2.b7e151628aed2a68p+0), { LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2a6cp+0", LIT (0x2.b7e151628aed2a6cp+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed2p+0", LIT (0x2.b7e151628aed2p+0), { LIT (0xf.ffffffffffffc2ap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2bp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2ap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e151628aed4p+0", LIT (0x2.b7e151628aed4p+0), { LIT (0x1.00000000000007fp+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007fp+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007fp+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007f2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e154p+0", LIT (0x2.b7e154p+0), { LIT (0x1.000000f647925f34p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f36p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7e15p+0", LIT (0x2.b7e15p+0), { LIT (0xf.fffff7d922f51a2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xb.17217f7d1cf79abp-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79acp-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79abp-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (-0x2.c5bd48bdc7c0c9b8p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b8p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b4p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b4p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (-0x2.c4657baf579a47bcp+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47bcp+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47b8p+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47b8p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (-0x2.e870a88dae386c74p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c74p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c7p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c7p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-128", LIT (0x4p-128), { LIT (-0x5.75627cbf9441de3p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (-0x2.c5b2319c4843accp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843accp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843acbcp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843acbcp+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.e2d588p-4", LIT (0x5.e2d588p-4), { LIT (-0x1.000000f11e085f44p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f42p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f42p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f42p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.e2d58d8b3bcdcp-4", LIT (0x5.e2d58d8b3bcdcp-4), { LIT (-0x1.0000000000000872p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000000000087p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000000000087p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000000000087p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.e2d58d8b3bcdf1a8p-4", LIT (0x5.e2d58d8b3bcdf1a8p-4), { LIT (-0x1.0000000000000002p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.e2d58d8b3bcdf1bp-4", LIT (0x5.e2d58d8b3bcdf1bp-4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.e2d58d8b3bcep-4", LIT (0x5.e2d58d8b3bcep-4), { LIT (-0xf.ffffffffffffd91p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd91p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5.e2d59p-4", LIT (0x5.e2d59p-4), { LIT (-0xf.fffff952d5f52bap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152", LIT (0x8p-152), { LIT (-0x6.74767f33d1dc1d1p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d1p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d08p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d08p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (-0x2.c86ce2daa80dcdbp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdbp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdacp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdacp+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-972", LIT (0x8p-972), { LIT (-0x2.9fa8dcb9092a538cp+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a538cp+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a5388p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a5388p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xa.ae688p-4", LIT (0xa.ae688p-4), { LIT (-0x6.772d36f0dd28c27p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c27p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c268p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c268p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xap+0", LIT (0xap+0), { LIT (0x2.4d763776aaa2b058p+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05cp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b058p+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xb.0d5dfp-4", LIT (0xb.0d5dfp-4), { LIT (-0x5.eb58f885a32d894p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d894p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d8938p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d8938p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4", LIT (0xcp-4), { LIT (-0x4.9a58844d36e49e1p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e1p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e08p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e08p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.a0288c3cb5ecp-4", LIT (0xe.a0288c3cb5ecp-4), { LIT (-0x1.6fe0d4c40097884ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.a0288p-4", LIT (0xe.a0288p-4), { LIT (-0x1.6fe0e22718ad7752p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad7752p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad775p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad775p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xe.a0289p-4", LIT (0xe.a0289p-4), { LIT (-0x1.6fe0d0a6311e31f2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31f2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31fp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x2.c5c85fdf473de6a4p+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a8p+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a4p+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a8p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p-4", LIT (0xf.ffffffffffff8p-4), { LIT (-0x8.000000000000201p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0x2.c5c85fdf473de6acp+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6bp+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6acp+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6bp+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffffffffffffp-4", LIT (0xf.fffffffffffffffp-4), { LIT (-0x1.0000000000000002p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x5.8b90bfae8e7bc558p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc56p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc558p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc56p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp-4", LIT (0xf.fffffp-4), { LIT (-0x1.0000008000005556p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005556p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005554p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005554p-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0000000000000002p+0", LIT (0x1.0000000000000002p+0), { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep-64), ERRNO_UNCHANGED }, { LIT (0x2p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0000000000001p+0", LIT (0x1.0000000000001p+0), { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-56), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff801p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.000002p+0", LIT (0x1.000002p+0), { LIT (0x1.fffffe000002aaaap-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaap-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaaap-24), ERRNO_UNCHANGED }, { LIT (0x1.fffffe000002aaacp-24), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.017f8ap+44", LIT (0x1.017f8ap+44), { LIT (0x1.e811a8a66aa56988p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa56988p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa56988p+4), ERRNO_UNCHANGED }, { LIT (0x1.e811a8a66aa5698ap+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.0b5c1ep+36", LIT (0x1.0b5c1ep+36), { LIT (0x1.8ff28cfed79a1p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1002p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1p+4), ERRNO_UNCHANGED }, { LIT (0x1.8ff28cfed79a1002p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.6c3f6p+0", LIT (0x1.6c3f6p+0), { LIT (0x5.a47aee2b5c34f7f8p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f8p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f7f8p-4), ERRNO_UNCHANGED }, { LIT (0x5.a47aee2b5c34f8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.770072p+0", LIT (0x1.770072p+0), { LIT (0x6.1ba943bb20434dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc8p-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dcp-4), ERRNO_UNCHANGED }, { LIT (0x6.1ba943bb20434dc8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.929d9cp+0", LIT (0x1.929d9cp+0), { LIT (0x7.3eb06c60714c5ff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c5ff8p-4), ERRNO_UNCHANGED }, { LIT (0x7.3eb06c60714c6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED }, { LIT (0x0p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.1b17c2887e938p+928", LIT (0x2.1b17c2887e938p+928), { LIT (0x2.83fc3c37fc58fffcp+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc59p+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc58fffcp+8), ERRNO_UNCHANGED }, { LIT (0x2.83fc3c37fc59p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a68p+0", LIT (0x2.b7e151628aed2a68p+0), { LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffffep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2a6cp+0", LIT (0x2.b7e151628aed2a6cp+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed2p+0", LIT (0x2.b7e151628aed2p+0), { LIT (0xf.ffffffffffffc2ap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2bp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2ap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffc2bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e151628aed4p+0", LIT (0x2.b7e151628aed4p+0), { LIT (0x1.00000000000007fp+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007fp+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007fp+0), ERRNO_UNCHANGED }, { LIT (0x1.00000000000007f2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e154p+0", LIT (0x2.b7e154p+0), { LIT (0x1.000000f647925f34p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f34p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000f647925f36p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7e15p+0", LIT (0x2.b7e15p+0), { LIT (0xf.fffff7d922f51a2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff7d922f51a3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0xb.17217f7d1cf79abp-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79acp-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79abp-4), ERRNO_UNCHANGED }, { LIT (0xb.17217f7d1cf79acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (-0x2.c5bd48bdc7c0c9b8p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b8p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b4p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5bd48bdc7c0c9b4p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (-0x2.c4657baf579a47bcp+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47bcp+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47b8p+8), ERRNO_UNCHANGED }, { LIT (-0x2.c4657baf579a47b8p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (-0x2.e870a88dae386c74p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c74p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c7p+8), ERRNO_UNCHANGED }, { LIT (-0x2.e870a88dae386c7p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-128", LIT (0x4p-128), { LIT (-0x5.75627cbf9441de3p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28p+4), ERRNO_UNCHANGED }, { LIT (-0x5.75627cbf9441de28p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (-0x2.c5b2319c4843accp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843accp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843acbcp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c5b2319c4843acbcp+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (-0x2.c877f9fc278aeaa8p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c877f9fc278aeaa8p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c877f9fc278aeaa4p+12), ERRNO_UNCHANGED }, { LIT (-0x2.c877f9fc278aeaa4p+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.e2d588p-4", LIT (0x5.e2d588p-4), { LIT (-0x1.000000f11e085f44p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f42p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f42p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000f11e085f42p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.e2d58d8b3bcdcp-4", LIT (0x5.e2d58d8b3bcdcp-4), { LIT (-0x1.0000000000000872p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000000000087p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000000000087p+0), ERRNO_UNCHANGED }, { LIT (-0x1.000000000000087p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.e2d58d8b3bcdf1a8p-4", LIT (0x5.e2d58d8b3bcdf1a8p-4), { LIT (-0x1.0000000000000002p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.e2d58d8b3bcdf1bp-4", LIT (0x5.e2d58d8b3bcdf1bp-4), { LIT (-0x1p+0), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffffffffffffffp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.e2d58d8b3bcep-4", LIT (0x5.e2d58d8b3bcep-4), { LIT (-0xf.ffffffffffffd91p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd91p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.ffffffffffffd9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5.e2d59p-4", LIT (0x5.e2d59p-4), { LIT (-0xf.fffff952d5f52bap-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b9p-4), ERRNO_UNCHANGED }, { LIT (-0xf.fffff952d5f52b9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152", LIT (0x8p-152), { LIT (-0x6.74767f33d1dc1d1p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d1p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d08p+4), ERRNO_UNCHANGED }, { LIT (-0x6.74767f33d1dc1d08p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (-0x2.c86ce2daa80dcdbp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdbp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdacp+12), ERRNO_UNCHANGED }, { LIT (-0x2.c86ce2daa80dcdacp+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-972", LIT (0x8p-972), { LIT (-0x2.9fa8dcb9092a538cp+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a538cp+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a5388p+8), ERRNO_UNCHANGED }, { LIT (-0x2.9fa8dcb9092a5388p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xa.ae688p-4", LIT (0xa.ae688p-4), { LIT (-0x6.772d36f0dd28c27p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c27p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c268p-4), ERRNO_UNCHANGED }, { LIT (-0x6.772d36f0dd28c268p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xap+0", LIT (0xap+0), { LIT (0x2.4d763776aaa2b058p+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05cp+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b058p+0), ERRNO_UNCHANGED }, { LIT (0x2.4d763776aaa2b05cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xb.0d5dfp-4", LIT (0xb.0d5dfp-4), { LIT (-0x5.eb58f885a32d894p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d894p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d8938p-4), ERRNO_UNCHANGED }, { LIT (-0x5.eb58f885a32d8938p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4", LIT (0xcp-4), { LIT (-0x4.9a58844d36e49e1p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e1p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e08p-4), ERRNO_UNCHANGED }, { LIT (-0x4.9a58844d36e49e08p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.a0288c3cb5ecp-4", LIT (0xe.a0288c3cb5ecp-4), { LIT (-0x1.6fe0d4c40097884ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884ep-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884cp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d4c40097884cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.a0288p-4", LIT (0xe.a0288p-4), { LIT (-0x1.6fe0e22718ad7752p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad7752p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad775p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0e22718ad775p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xe.a0289p-4", LIT (0xe.a0289p-4), { LIT (-0x1.6fe0d0a6311e31f2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31f2p-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31fp-4), ERRNO_UNCHANGED }, { LIT (-0x1.6fe0d0a6311e31fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x2.c5c85fdf473de6a4p+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a8p+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a4p+8), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6a8p+8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p-4", LIT (0xf.ffffffffffff8p-4), { LIT (-0x8.000000000000201p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED }, { LIT (-0x8.0000000000002p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0x2.c5c85fdf473de6acp+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6bp+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6acp+12), ERRNO_UNCHANGED }, { LIT (0x2.c5c85fdf473de6bp+12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffffffffffffp-4", LIT (0xf.fffffffffffffffp-4), { LIT (-0x1.0000000000000002p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED }, { LIT (-0x1p-64), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x5.8b90bfae8e7bc558p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc56p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc558p+4), ERRNO_UNCHANGED }, { LIT (0x5.8b90bfae8e7bc56p+4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp-4", LIT (0xf.fffffp-4), { LIT (-0x1.0000008000005556p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005556p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005554p-24), ERRNO_UNCHANGED }, { LIT (-0x1.0000008000005554p-24), ERRNO_UNCHANGED } },
#endif
  };

static void
log_test (void)
{
  ALL_RM_TEST (log, 0, log_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  log_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

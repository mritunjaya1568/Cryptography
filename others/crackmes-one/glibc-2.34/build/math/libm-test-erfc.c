/* Test erfc.
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

static const struct test_f_f_data erfc_test_data[] =
  {
    { "inf", plus_infty, { LIT (0.0), ERRNO_UNCHANGED }, { LIT (0.0), ERRNO_UNCHANGED }, { LIT (0.0), ERRNO_UNCHANGED }, { LIT (0.0), ERRNO_UNCHANGED } },
    { "-inf", minus_infty, { LIT (2.0), ERRNO_UNCHANGED }, { LIT (2.0), ERRNO_UNCHANGED }, { LIT (2.0), ERRNO_UNCHANGED }, { LIT (2.0), ERRNO_UNCHANGED } },
    { "qNaN", qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },
    { "-qNaN", -qnan_value, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED }, { qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED } },

#if (TEST_COND_binary128)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (0x1.d7bb3d3a0844563680887edd8693p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a0844563680887edd8693p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a0844563680887edd8693p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a0844563680887edd8694p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (0x1.fecd70a13caf19972801904b9a33p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf19972801904b9a34p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf19972801904b9a33p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf19972801904b9a34p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x2p-56", LIT (-0x2p-56), { LIT (0x1.0000000000000241baea08536da2p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000241baea08536da2p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000241baea08536da2p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000241baea08536da3p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (0x1.fffe8d6209afcbdd5f43d9ad9debp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdd5f43d9ad9debp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdd5f43d9ad9debp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdd5f43d9ad9decp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (0x1.ffffffbdc88bb10b2865615db403p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10b2865615db403p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10b2865615db403p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10b2865615db404p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16448", LIT (-0x4p-16448), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x4p-16496", LIT (-0x4p-16496), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (0x1.fffffffffe4f3e58a6088c76ca15p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58a6088c76ca16p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58a6088c76ca15p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58a6088c76ca16p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (0x1.fffffffffffffe7307eaa82df49ep+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe7307eaa82df49ep+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe7307eaa82df49ep+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe7307eaa82df49fp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.fffff8p-4", LIT (-0x7.fffff8p-4), { LIT (0x1.853f7a704b7be2d643b9e3ae3cafp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d643b9e3ae3cbp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d643b9e3ae3cafp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d643b9e3ae3cbp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.ffffffffffffcp-4", LIT (-0x7.ffffffffffffcp-4), { LIT (0x1.853f7ae0c76e8ddaa10a86e7a049p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddaa10a86e7a049p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddaa10a86e7a049p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddaa10a86e7a04ap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7.ffffffffffffep-4", LIT (-0x7.ffffffffffffep-4), { LIT (0x1.853f7ae0c76e8f9c90d4d08ca163p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9c90d4d08ca164p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9c90d4d08ca163p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9c90d4d08ca164p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (0x1.ffffffffffffffffffcd6bafd92p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffcd6bafd921p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffcd6bafd92p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffcd6bafd921p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (0x1.ffffffffffffffffffffffff1c58p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffff1c58p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffff1c58p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffff1c59p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-4", LIT (-0x8p-4), { LIT (0x1.853f7ae0c76e915e809f1a31a27ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915e809f1a31a27bp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915e809f1a31a27ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915e809f1a31a27bp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-8", LIT (-0x8p-8), { LIT (0x1.09062b22ee929bfc9c18d570fce4p+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfc9c18d570fce4p+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfc9c18d570fce4p+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfc9c18d570fce5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000000000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xap+0", LIT (-0xap+0), { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffffffffffffff8p+16380", LIT (-0xf.fffffffffffffffffffffffffff8p+16380), { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.2f644ep+0", LIT (0x1.2f644ep+0), { LIT (0x1.7fefc09137c9485d5871f07f9464p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485d5871f07f9465p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485d5871f07f9464p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485d5871f07f9465p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.3ffcbep+0", LIT (0x1.3ffcbep+0), { LIT (0x1.3bd9679020a687bf0ac713ffaf7ap-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687bf0ac713ffaf7bp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687bf0ac713ffaf7ap-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687bf0ac713ffaf7bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.3ffcbf39febb4p+0", LIT (0x1.3ffcbf39febb4p+0), { LIT (0x1.3bd962ebb773644beafd5d55b35fp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644beafd5d55b35fp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644beafd5d55b35fp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644beafd5d55b36p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.3ffccp+0", LIT (0x1.3ffccp+0), { LIT (0x1.3bd95ffe4e5561c5991cb64b6573p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c5991cb64b6573p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c5991cb64b6573p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c5991cb64b6574p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.4p+0", LIT (0x1.4p+0), { LIT (0x1.3bcd133aa0ffbf9d895f72e9b1d3p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9d895f72e9b1d3p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9d895f72e9b1d3p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9d895f72e9b1d4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.514548p+0", LIT (0x1.514548p+0), { LIT (0xf.fbeadad5a51f774a6aa2da69dadp-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f774a6aa2da69dad8p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f774a6aa2da69dadp-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f774a6aa2da69dad8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166e0efc44a9dfc79b8c8873a8p+0", LIT (0x1.5166e0efc44a9dfc79b8c8873a8p+0), { LIT (0xf.f53d3d6dfa747dd2cb91abfde4e8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfde4fp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfde4e8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfde4fp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166e0efc44a9dfc79b8c8873a99p+0", LIT (0x1.5166e0efc44a9dfc79b8c8873a99p+0), { LIT (0xf.f53d3d6dfa747dd2cb91abfddffp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfddff8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfddffp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfddff8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166e0efc44a9dfc79b8c8873bp+0", LIT (0x1.5166e0efc44a9dfc79b8c8873bp+0), { LIT (0xf.f53d3d6dfa747dd2cb91abfdcb78p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfdcb8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfdcb78p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfdcb8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166e0efc44a9dfcp+0", LIT (0x1.5166e0efc44a9dfcp+0), { LIT (0xf.f53d3d6dfa747deaf93d1ace235p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747deaf93d1ace2358p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747deaf93d1ace235p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747deaf93d1ace2358p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166e0efc44a9dfep+0", LIT (0x1.5166e0efc44a9dfep+0), { LIT (0xf.f53d3d6dfa747d85458d645dd238p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d85458d645dd238p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d85458d645dd238p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d85458d645dd24p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166e0efc44a9p+0", LIT (0x1.5166e0efc44a9p+0), { LIT (0xf.f53d3d6dfa7745095fdac02562dp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa7745095fdac02562dp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa7745095fdac02562dp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa7745095fdac02562d8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166e0efc44aap+0", LIT (0x1.5166e0efc44aap+0), { LIT (0xf.f53d3d6dfa74176be2273d9c694p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74176be2273d9c6948p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74176be2273d9c694p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74176be2273d9c6948p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166e2p+0", LIT (0x1.5166e2p+0), { LIT (0xf.f53d075aa92b1f075d1f393d6668p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1f075d1f393d667p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1f075d1f393d6668p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1f075d1f393d667p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5166ep+0", LIT (0x1.5166ep+0), { LIT (0xf.f53d6d0e58d08f84e4986455328p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f84e4986455328p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f84e4986455328p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f84e49864553288p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5289fep+0", LIT (0x1.5289fep+0), { LIT (0xf.bbc04428a3d30e77d2315d0046a8p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e77d2315d0046a8p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e77d2315d0046a8p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e77d2315d0046bp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5cf2167efe9207d2p+0", LIT (0x1.5cf2167efe9207d2p+0), { LIT (0xd.cc22a7f131804ea9510443197f9p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ea9510443197f9p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ea9510443197f9p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ea9510443197f98p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5cf2167efe921p+0", LIT (0x1.5cf2167efe921p+0), { LIT (0xd.cc22a7f1317ede14f24f95f12c68p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede14f24f95f12c7p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede14f24f95f12c68p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede14f24f95f12c7p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5cf2167efe92p+0", LIT (0x1.5cf2167efe92p+0), { LIT (0xd.cc22a7f13181af0c2264782d18d8p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af0c2264782d18d8p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af0c2264782d18d8p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af0c2264782d18ep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5cf216p+0", LIT (0x1.5cf216p+0), { LIT (0xd.cc22be4b9b325bc5efb8f07224p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bc5efb8f07224p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bc5efb8f07224p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bc5efb8f0722408p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.5cf218p+0", LIT (0x1.5cf218p+0), { LIT (0xd.cc22642cb5ab8dc55a1975e03bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dc55a1975e03bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dc55a1975e03bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dc55a1975e03bc8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.64dafap+0", LIT (0x1.64dafap+0), { LIT (0xc.766cbf61fd6480afed02bf2b206p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480afed02bf2b2068p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480afed02bf2b206p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480afed02bf2b2068p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.65e31p+0", LIT (0x1.65e31p+0), { LIT (0xc.4bf9de451e5fced9d5e2d18c20b8p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fced9d5e2d18c20b8p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fced9d5e2d18c20b8p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fced9d5e2d18c20cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8a0c62p+0", LIT (0x1.8a0c62p+0), { LIT (0x7.8cde5963040180b50eb9ef7f8a04p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b50eb9ef7f8a04p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b50eb9ef7f8a04p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b50eb9ef7f8a08p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.8a0c64p+0", LIT (0x1.8a0c64p+0), { LIT (0x7.8cde235791e7d0dfc843bc26d50cp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0dfc843bc26d51p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0dfc843bc26d50cp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0dfc843bc26d51p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9d7adac608e85862p+4", LIT (0x1.9d7adac608e85862p+4), { LIT (0x8.00000000000019f3f043fe66cfa8p-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019f3f043fe66cfa8p-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019f3f043fe66cfa8p-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019f3f043fe66cfbp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9d7adac608e8586300e6c8b99e8p+4", LIT (0x1.9d7adac608e8586300e6c8b99e8p+4), { LIT (0x7.fffffffffffffffffffffff54e7cp-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffff54e7cp-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffff54e7cp-972), ERRNO_UNCHANGED }, { LIT (0x7.fffffffffffffffffffffff54e8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9d7adac608e8586300e6c8b99ep+4", LIT (0x1.9d7adac608e8586300e6c8b99ep+4), { LIT (0x8.0000000000000000000000023cc8p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000023cdp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000023cc8p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000023cdp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9d7adac608e85864p+4", LIT (0x1.9d7adac608e85864p+4), { LIT (0x7.ffffffffffffe63ab0b952a39248p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe63ab0b952a3924cp-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe63ab0b952a39248p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe63ab0b952a3924cp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9d7adac608e85p+4", LIT (0x1.9d7adac608e85p+4), { LIT (0x8.0000000000d8e567447df7350c68p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e567447df7350c7p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e567447df7350c68p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e567447df7350c7p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9d7adac608e86p+4", LIT (0x1.9d7adac608e86p+4), { LIT (0x7.ffffffffff3b1b6aef1fdb453a1p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b6aef1fdb453a14p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b6aef1fdb453a1p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b6aef1fdb453a14p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9d7adap+4", LIT (0x1.9d7adap+4), { LIT (0x8.001401a2efa2624d0e762da1397p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2624d0e762da13978p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2624d0e762da1397p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2624d0e762da13978p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.9d7adcp+4", LIT (0x1.9d7adcp+4), { LIT (0x7.ffe048893995703e6ead0de50f7cp-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe048893995703e6ead0de50f7cp-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe048893995703e6ead0de50f7cp-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe048893995703e6ead0de50f8p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.a8b12ep+4", LIT (0x1.a8b12ep+4), { LIT (0x4.001799b7b63bbeff7d28fedc0014p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbeff7d28fedc0018p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbeff7d28fedc0014p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbeff7d28fedc0018p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.a8b12fc6e4891p+4", LIT (0x1.a8b12fc6e4891p+4), { LIT (0x4.0000000000cc9079f71a2f32ab1p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc9079f71a2f32ab1p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc9079f71a2f32ab1p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc9079f71a2f32ab14p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.a8b12fc6e4892p+4", LIT (0x1.a8b12fc6e4892p+4), { LIT (0x3.fffffffffff8115bf0b754d4fe0ep-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff8115bf0b754d4fe1p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff8115bf0b754d4fe0ep-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff8115bf0b754d4fe1p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.a8b13p+4", LIT (0x1.a8b13p+4), { LIT (0x3.fffd098f7c63a42c4181f6fca376p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a42c4181f6fca376p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a42c4181f6fca376p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a42c4181f6fca378p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.ap+4", LIT (0x1.ap+4), { LIT (0x9.425ff0e6f511d74db40cfbbceffp-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d74db40cfbbceffp-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d74db40cfbbceffp-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d74db40cfbbceff8p-984), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.bp+4", LIT (0x1.bp+4), { LIT (0x6.783c337e0e9d7e84c2c58243308cp-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e84c2c58243308cp-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e84c2c58243308cp-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e84c2c58243309p-1060), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.cp+4", LIT (0x1.cp+4), { LIT (0x9.cd4b80875a8ec6603b9a1f1beadp-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec6603b9a1f1bead8p-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec6603b9a1f1beadp-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec6603b9a1f1bead8p-1140), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1.e33c9ep+0", LIT (0x1.e33c9ep+0), { LIT (0x1.f1cb04b622e6f4d5035449633b46p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d5035449633b46p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d5035449633b46p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d5035449633b47p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x2.844c2c5f7bba9c97f778122796c8p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c97f778122796c8p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c97f778122796c8p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c97f778122796cap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffffffffffedf2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffedf2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffedf2p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffedf28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffedf228afbd6a978b6c864b5b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6a978b6c864b5b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6a978b6c864b5b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6a978b6c864b5cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.ffffffffedf228afbd6492ee51cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228afbd6492ee51c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228afbd6492ee51cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228afbd6492ee51c8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffedf228afbd64928p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffedf228afbd6493p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffedf228afbd64928p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffedf228afbd6493p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.36c504p+0", LIT (0x2.36c504p+0), { LIT (0x7.22d059993f3f46d0e0daa16357p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46d0e0daa16357p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46d0e0daa16357p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46d0e0daa1635704p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.56af04p+0", LIT (0x2.56af04p+0), { LIT (0x3.dbca059c7e73a1239dd52028280cp-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a1239dd52028280cp-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a1239dd52028280cp-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a1239dd52028280ep-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.586f1cp+0", LIT (0x2.586f1cp+0), { LIT (0x3.ba3ac339ed1902051ea00716754ep-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed1902051ea00716755p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed1902051ea00716754ep-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed1902051ea00716755p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8c8p+0", LIT (0x2.b7f8c8p+0), { LIT (0x7.e8b3a6276f03f7798c2a7c4e628p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f7798c2a7c4e6284p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f7798c2a7c4e628p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f7798c2a7c4e6284p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8cb76737d2af8p+0", LIT (0x2.b7f8cb76737d2af8p+0), { LIT (0x7.e8b308381e001502525c2ab33254p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001502525c2ab33258p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001502525c2ab33254p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001502525c2ab33258p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8cb76737d2af98dead7c4c5eep+0", LIT (0x2.b7f8cb76737d2af98dead7c4c5eep+0), { LIT (0x7.e8b308381e0014bb6d3bd6db5998p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db599cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db5998p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db599cp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8cb76737d2af98dead7c4c5p+0", LIT (0x2.b7f8cb76737d2af98dead7c4c5p+0), { LIT (0x7.e8b308381e0014bb6d3bd6db84p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db8404p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db84p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db8404p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8cb76737d2af98dead7c4c6p+0", LIT (0x2.b7f8cb76737d2af98dead7c4c6p+0), { LIT (0x7.e8b308381e0014bb6d3bd6db5664p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db5664p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db5664p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db5668p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8cb76737d2afcp+0", LIT (0x2.b7f8cb76737d2afcp+0), { LIT (0x7.e8b308381e00144be16c16cf88ep-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e00144be16c16cf88ep-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e00144be16c16cf88ep-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e00144be16c16cf88e4p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8cb76737d2p+0", LIT (0x2.b7f8cb76737d2p+0), { LIT (0x7.e8b308381e02094c04b2b4fe1dccp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02094c04b2b4fe1ddp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02094c04b2b4fe1dccp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02094c04b2b4fe1ddp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8cb76737d4p+0", LIT (0x2.b7f8cb76737d4p+0), { LIT (0x7.e8b308381dfc55c4841397b30ae4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c4841397b30ae4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c4841397b30ae4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c4841397b30ae8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.b7f8ccp+0", LIT (0x2.b7f8ccp+0), { LIT (0x7.e8b2efb679451a42955c7a94bfbcp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a42955c7a94bfbcp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a42955c7a94bfbcp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a42955c7a94bfcp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.dfb9b4p+0", LIT (0x2.dfb9b4p+0), { LIT (0x3.281c2d7e470e5082e42097886928p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5082e4209788692ap-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5082e42097886928p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5082e4209788692ap-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2.f8646cp+0", LIT (0x2.f8646cp+0), { LIT (0x1.be98de114e174b501b7acff72e8p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b501b7acff72e8p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b501b7acff72e8p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b501b7acff72e81p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x1.328f5ec350e668d7fe6fb465cc11p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d7fe6fb465cc11p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d7fe6fb465cc11p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d7fe6fb465cc12p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffdbe4515faaee0eb270b8c6b0c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee0eb270b8c6b0dp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee0eb270b8c6b0c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee0eb270b8c6b0dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffffdbe4515f7ac925dca3bbp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515f7ac925dca3bbp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515f7ac925dca3bbp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515f7ac925dca3bb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-4", LIT (0x2p-4), { LIT (0xd.c143cb94788ed17a494db60f8618p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed17a494db60f862p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed17a494db60f8618p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed17a494db60f862p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.ffffffffffffdbe4515f7ac925d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbe4515f7ac925ep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbe4515f7ac925d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbe4515f7ac925ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3.e8p+8", LIT (0x3.e8p+8), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x3.ee6078p+0", LIT (0x3.ee6078p+0), { LIT (0x7.4334a54e1208ae1b8bfa15647bc4p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae1b8bfa15647bc4p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae1b8bfa15647bc4p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae1b8bfa15647bc8p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.729df6503422a0bc26526214d0a4p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bc26526214d0a4p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bc26526214d0a4p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bc26526214d0a5p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.2p+0", LIT (0x4.2p+0), { LIT (0x1.74b179d1eba809f2e32224074101p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2e32224074102p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2e32224074101p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2e32224074102p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4.b48498p+0", LIT (0x4.b48498p+0), { LIT (0x1.f57fab6c3db3ce7e0bd2fb137938p-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7e0bd2fb137939p-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7e0bd2fb137938p-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7e0bd2fb137939p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x4.237744ef4d79a9ea24bfce6c7e88p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9ea24bfce6c7e8cp-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9ea24bfce6c7e88p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9ea24bfce6c7e8cp-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.fb7c8a4401cd1c3347a83a17da48p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3347a83a17da5p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3347a83a17da48p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3347a83a17da5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-16496", LIT (0x4p-16496), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffb7c8a2bef5924bbac83dp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2bef5924bbac83dp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2bef5924bbac83dp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2bef5924bbac83d08p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffffffffb7c8a2bef5924bb9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c8a2bef5924bb98p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c8a2bef5924bb9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c8a2bef5924bb98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x1.b0c1a759f7738935ea5dea8e17aap-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738935ea5dea8e17aap-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738935ea5dea8e17aap-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738935ea5dea8e17abp-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x2.fd514cef7750e58906601ff35dcp-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e58906601ff35dcp-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e58906601ff35dcp-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e58906601ff35dc2p-14436), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.88fb08p+0", LIT (0x6.88fb08p+0), { LIT (0x7.23ff79ae0f25a135a4973efb8bep-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a135a4973efb8be4p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a135a4973efb8bep-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a135a4973efb8be4p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893032db905274042fb05c664p+4", LIT (0x6.a893032db905274042fb05c664p+4), { LIT (0x4.0000000000000000000000637ap-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000637ap-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000637ap-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000637a04p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893032db905274042fb05c665dcp+4", LIT (0x6.a893032db905274042fb05c665dcp+4), { LIT (0x4.0000000000000000000000006d58p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000006d58p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000006d58p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000000000000006d5cp-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893032db905274042fb05c665ep+4", LIT (0x6.a893032db905274042fb05c665ep+4), { LIT (0x3.ffffffffffffffffffffffff984p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffffffffffffffffffffffff9844p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffffffffffffffffffffffff984p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffffffffffffffffffffffff9844p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893032db905274042fb05c666p+4", LIT (0x6.a893032db905274042fb05c666p+4), { LIT (0x3.fffffffffffffffffffffff8ef9cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffffffffffffff8ef9cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffffffffffffff8ef9cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffffffffffffff8efap-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893032db9052748p+4", LIT (0x6.a893032db9052748p+4), { LIT (0x3.fffffffffffe63c683e89c3c2e14p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffe63c683e89c3c2e14p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffe63c683e89c3c2e14p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffe63c683e89c3c2e18p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893032db905274p+4", LIT (0x6.a893032db905274p+4), { LIT (0x4.0000000000000df012e73ddae2bp-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000df012e73ddae2b4p-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000df012e73ddae2bp-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000df012e73ddae2b4p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893032db9054p+4", LIT (0x6.a893032db9054p+4), { LIT (0x3.fffffffffad99d5daf268a859d94p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffad99d5daf268a859d98p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffad99d5daf268a859d94p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffad99d5daf268a859d98p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893032db905p+4", LIT (0x6.a893032db905p+4), { LIT (0x4.00000000082ae9d5a43888b96c7p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9d5a43888b96c74p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9d5a43888b96c7p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9d5a43888b96c74p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a89308p+4", LIT (0x6.a89308p+4), { LIT (0x3.feff49e314f6ecdbbfebc2b34f24p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.feff49e314f6ecdbbfebc2b34f24p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.feff49e314f6ecdbbfebc2b34f24p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.feff49e314f6ecdbbfebc2b34f28p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a893p+4", LIT (0x6.a893p+4), { LIT (0x4.00a9613ff5224411b6349cce295cp-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff5224411b6349cce295cp-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff5224411b6349cce295cp-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff5224411b6349cce296p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a8a0561d8bbe8p+4", LIT (0x6.a8a0561d8bbe8p+4), { LIT (0x2.00000000021824dbaeba00661e58p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000021824dbaeba00661e58p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000021824dbaeba00661e58p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000021824dbaeba00661e5cp-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a8a0561d8bbe9428p+4", LIT (0x6.a8a0561d8bbe9428p+4), { LIT (0x1.ffffffffffff434ed847125bd788p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff434ed847125bd78cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff434ed847125bd788p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff434ed847125bd78cp-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a8a0561d8bbe942p+4", LIT (0x6.a8a0561d8bbe942p+4), { LIT (0x2.00000000000018654a1f8eeb1fb4p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000000018654a1f8eeb1fb8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000000018654a1f8eeb1fb4p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000000018654a1f8eeb1fb8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a8a0561d8bbecp+4", LIT (0x6.a8a0561d8bbecp+4), { LIT (0x1.fffffffffb6f714cead9a1d65bcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f714cead9a1d65bc4p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f714cead9a1d65bcp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f714cead9a1d65bc4p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a8a058p+4", LIT (0x6.a8a058p+4), { LIT (0x1.ffcdcfd4f9515ad5d9921562ca2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515ad5d9921562ca2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515ad5d9921562ca2p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515ad5d9921562ca24p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a8a05p+4", LIT (0x6.a8a05p+4), { LIT (0x2.00a2fdbcb5dc489cd9c18d5c3254p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00a2fdbcb5dc489cd9c18d5c3254p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00a2fdbcb5dc489cd9c18d5c3254p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00a2fdbcb5dc489cd9c18d5c3258p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.a8p+4", LIT (0x6.a8p+4), { LIT (0x2.0b5b5b3bbf7d96a5e595291fc8c4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a5e595291fc8c4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a5e595291fc8c4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a5e595291fc8c6p-16372), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.aap+4", LIT (0x6.aap+4), { LIT (0x6.0b6ee997d3343b5bf2f08p-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee997d3343b5bf2f08p-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee997d3343b5bf2f08p-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee997d3343b5bf2f0cp-16412), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.ap+4", LIT (0x6.ap+4), { LIT (0x5.028a2f1656a432d79f76a6f2df48p-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432d79f76a6f2df48p-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432d79f76a6f2df48p-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432d79f76a6f2df4cp-16220), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x6.bp+4", LIT (0x6.bp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6.cp+4", LIT (0x6.cp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0x6p+0", LIT (0x6p+0), { LIT (0x1.8cf81557d20b61a7fff0cc732bf9p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a7fff0cc732bfap-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a7fff0cc732bf9p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a7fff0cc732bfap-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fe8008p+0", LIT (0x7.fe8008p+0), { LIT (0xf.a33725bea2f7d7abe8b7461d621p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7abe8b7461d621p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7abe8b7461d621p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7abe8b7461d6218p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fffd58p+0", LIT (0x7.fffd58p+0), { LIT (0xe.3cdfb051e6943150a3c2f2e70a58p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e6943150a3c2f2e70a58p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e6943150a3c2f2e70a58p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e6943150a3c2f2e70a6p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fffd59e26af34p+0", LIT (0x7.fffd59e26af34p+0), { LIT (0xe.3cddffbbe88543bb57f5bfbbaa7p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543bb57f5bfbbaa78p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543bb57f5bfbbaa7p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543bb57f5bfbbaa78p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fffd59e26af37bc048d159e26ap+0", LIT (0x7.fffd59e26af37bc048d159e26ap+0), { LIT (0xe.3cddffbbe84faf818649c237713p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84faf818649c2377138p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84faf818649c237713p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84faf818649c2377138p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fffd59e26af37bc8p+0", LIT (0x7.fffd59e26af37bc8p+0), { LIT (0xe.3cddffbbe84fa8965f5d5ffd399p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa8965f5d5ffd3998p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa8965f5d5ffd399p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa8965f5d5ffd3998p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fffd59e26af37bcp+0", LIT (0x7.fffd59e26af37bcp+0), { LIT (0xe.3cddffbbe84fafc2d20bb0997108p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafc2d20bb0997108p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafc2d20bb0997108p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafc2d20bb099711p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fffd59e26af38p+0", LIT (0x7.fffd59e26af38p+0), { LIT (0xe.3cddffbbe84be025e570dd9c7cap-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be025e570dd9c7cap-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be025e570dd9c7cap-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be025e570dd9c7ca8p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.fffd6p+0", LIT (0x7.fffd6p+0), { LIT (0xe.3cd883e02b14daf90f0f812035b8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14daf90f0f812035cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14daf90f0f812035b8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14daf90f0f812035cp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7.ffff2p+0", LIT (0x7.ffff2p+0), { LIT (0xe.3b46e15ad97825d129852878feb8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825d129852878fecp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825d129852878feb8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825d129852878fecp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x7p+0", LIT (0x7p+0), { LIT (0x3.2945026df4e62a48fcf382c1cfc8p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48fcf382c1cfc8p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48fcf382c1cfc8p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48fcf382c1cfcap-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.c66b44ca40038p+0", LIT (0x8.c66b44ca40038p+0), { LIT (0x1.eb97b1f20867c35eff191bbeca3ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35eff191bbeca3ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35eff191bbeca3ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35eff191bbeca3fp-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.c66b4p+0", LIT (0x8.c66b4p+0), { LIT (0x1.eb98546946cb2525a4905a3b1381p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2525a4905a3b1382p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2525a4905a3b1381p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2525a4905a3b1382p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8.c66b5p+0", LIT (0x8.c66b5p+0), { LIT (0x1.eb9635bc51eb7a94581f979ead1cp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94581f979ead1dp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94581f979ead1cp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94581f979ead1dp-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xe.3a7e2090befdbb5c007d16c48e8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb5c007d16c48e88p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb5c007d16c48e8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb5c007d16c48e88p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffff6f91457deb24a37bc860f7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457deb24a37bc860f7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457deb24a37bc860f7p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457deb24a37bc860f78p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.ffffffffff6f91457deb24977288p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f91457deb2497729p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f91457deb24977288p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f91457deb2497729p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.6f9d4dd116d640363e72a8f031b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d640363e72a8f031b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d640363e72a8f031b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d640363e72a8f031cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x9.31cdfp+0", LIT (0x9.31cdfp+0), { LIT (0x4.0004157f2239d721e27728e0acacp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d721e27728e0acacp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d721e27728e0acacp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d721e27728e0acbp-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x9.31cep+0", LIT (0x9.31cep+0), { LIT (0x3.ffff75b4a7f71721b89fe0646f56p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f71721b89fe0646f56p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f71721b89fe0646f56p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f71721b89fe0646f58p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x8.cc6a115f1fc6136ba610a005ff18p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6136ba610a005ff2p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6136ba610a005ff18p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6136ba610a005ff2p-124), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xap+0", LIT (0xap+0), { LIT (0xb.ec53f9545167ce9b9c460ae3b26p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ce9b9c460ae3b268p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ce9b9c460ae3b26p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ce9b9c460ae3b268p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xb.2274991033578p+0", LIT (0xb.2274991033578p+0), { LIT (0x1.c6479753dddf2401559c4dbabe7p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2401559c4dbabe7p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2401559c4dbabe7p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2401559c4dbabe71p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xb.227499103357d84p+0", LIT (0xb.227499103357d84p+0), { LIT (0x1.c6479753ddd176a5bf5193bad771p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a5bf5193bad771p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a5bf5193bad771p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a5bf5193bad772p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xb.227499103358p+0", LIT (0xb.227499103358p+0), { LIT (0x1.c6479753ddcb4d8c72ebbfb8ec28p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8c72ebbfb8ec29p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8c72ebbfb8ec28p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8c72ebbfb8ec29p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xb.22749p+0", LIT (0xb.22749p+0), { LIT (0x1.c648feeb672e8e57298792150dd9p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e57298792150dd9p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e57298792150dd9p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e57298792150ddap-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xb.2274ap+0", LIT (0xb.2274ap+0), { LIT (0x1.c646841c902106e7ce3048dea084p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e7ce3048dea085p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e7ce3048dea084p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e7ce3048dea085p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xb.acb72p+0", LIT (0xb.acb72p+0), { LIT (0x7.ee2d2ec57315040047a2a1252e7cp-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec57315040047a2a1252e8p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec57315040047a2a1252e7cp-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec57315040047a2a1252e8p-204), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x4.9f1b453178d049d79a1a6877559p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d79a1a68775594p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d79a1a6877559p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d79a1a68775594p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xd.03d06p-4", LIT (0xd.03d06p-4), { LIT (0x3.fff91a7d782b006458655c2be87cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b006458655c2be87cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b006458655c2be87cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b006458655c2be87ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xd.28abfp-4", LIT (0xd.28abfp-4), { LIT (0x3.eaab96d5a2e294b81fff40fde9a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b81fff40fde9aap-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b81fff40fde9a8p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b81fff40fde9aap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xd.361d9p-4", LIT (0xd.361d9p-4), { LIT (0x3.e2fa6064d589347b0f2f7aa6e388p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347b0f2f7aa6e388p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347b0f2f7aa6e388p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347b0f2f7aa6e38ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xd.44cd3p-4", LIT (0xd.44cd3p-4), { LIT (0x3.da9f608f1dd7ee3168650dc2fb9cp-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3168650dc2fb9ep-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3168650dc2fb9cp-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3168650dc2fb9ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xd.47425b3cafa48p-4", LIT (0xd.47425b3cafa48p-4), { LIT (0x3.d93aa84f87a9ffa04577ca7dbb26p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffa04577ca7dbb28p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffa04577ca7dbb26p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffa04577ca7dbb28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xd.47425p-4", LIT (0xd.47425p-4), { LIT (0x3.d93aaeadb64d00e8ad67712ba71p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8ad67712ba71p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8ad67712ba71p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8ad67712ba712p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xd.47426p-4", LIT (0xd.47426p-4), { LIT (0x3.d93aa59c8f5abb821749e8017aep-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb821749e8017ae2p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb821749e8017aep-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb821749e8017ae2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffffffffffffff8p+16380", LIT (0xf.fffffffffffffffffffffffffff8p+16380), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16496), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (0x1.d7bb3cp+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3ep+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3cp+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (0x1.fecd7p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd7p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd7p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd72p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x2p-56", LIT (-0x2p-56), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (0x1.fffe8cp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8ep+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8cp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x7.fffff8p-4", LIT (-0x7.fffff8p-4), { LIT (0x1.853f7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-4", LIT (-0x8p-4), { LIT (0x1.853f7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x8p-8", LIT (-0x8p-8), { LIT (0x1.09062ap+0), ERRNO_UNCHANGED }, { LIT (0x1.09062cp+0), ERRNO_UNCHANGED }, { LIT (0x1.09062ap+0), ERRNO_UNCHANGED }, { LIT (0x1.09062cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xap+0", LIT (-0xap+0), { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.2f644ep+0", LIT (0x1.2f644ep+0), { LIT (0x1.7fefcp-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefcp-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefcp-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.3ffcbep+0", LIT (0x1.3ffcbep+0), { LIT (0x1.3bd966p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd968p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd966p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd968p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.3ffccp+0", LIT (0x1.3ffccp+0), { LIT (0x1.3bd95ep-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd96p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ep-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd96p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.4p+0", LIT (0x1.4p+0), { LIT (0x1.3bcd12p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd14p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd12p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd14p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.514548p+0", LIT (0x1.514548p+0), { LIT (0xf.fbeadp-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeaep-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadp-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeaep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.5166e2p+0", LIT (0x1.5166e2p+0), { LIT (0xf.f53dp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53dp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53dp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.5166ep+0", LIT (0x1.5166ep+0), { LIT (0xf.f53d6p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d7p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d7p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.5289fep+0", LIT (0x1.5289fep+0), { LIT (0xf.bbc04p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc05p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.5cf216p+0", LIT (0x1.5cf216p+0), { LIT (0xd.cc22bp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22cp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22bp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.5cf218p+0", LIT (0x1.5cf218p+0), { LIT (0xd.cc226p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc226p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc226p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc227p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.64dafap+0", LIT (0x1.64dafap+0), { LIT (0xc.766cbp-8), ERRNO_UNCHANGED }, { LIT (0xc.766ccp-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbp-8), ERRNO_UNCHANGED }, { LIT (0xc.766ccp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.65e31p+0", LIT (0x1.65e31p+0), { LIT (0xc.4bf9dp-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9ep-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9dp-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9ep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.8a0c62p+0", LIT (0x1.8a0c62p+0), { LIT (0x7.8cde58p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde58p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde58p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.8a0c64p+0", LIT (0x1.8a0c64p+0), { LIT (0x7.8cde2p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde2p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde2p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde28p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1.9d7adap+4", LIT (0x1.9d7adap+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.9d7adcp+4", LIT (0x1.9d7adcp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.a8b12ep+4", LIT (0x1.a8b12ep+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.a8b13p+4", LIT (0x1.a8b13p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.ap+4", LIT (0x1.ap+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.bp+4", LIT (0x1.bp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.cp+4", LIT (0x1.cp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x1.e33c9ep+0", LIT (0x1.e33c9ep+0), { LIT (0x1.f1cb04p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb06p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x2.844c2cp-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2cp-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2cp-4), ERRNO_UNCHANGED }, { LIT (0x2.844c3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffeep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffeep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.36c504p+0", LIT (0x2.36c504p+0), { LIT (0x7.22d058p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d058p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d058p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d06p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.56af04p+0", LIT (0x2.56af04p+0), { LIT (0x3.dbca04p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca04p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca04p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca08p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.586f1cp+0", LIT (0x2.586f1cp+0), { LIT (0x3.ba3acp-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac4p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3acp-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac4p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.b7f8c8p+0", LIT (0x2.b7f8c8p+0), { LIT (0x7.e8b3ap-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a8p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3ap-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.b7f8ccp+0", LIT (0x2.b7f8ccp+0), { LIT (0x7.e8b2e8p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2fp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2e8p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2fp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.dfb9b4p+0", LIT (0x2.dfb9b4p+0), { LIT (0x3.281c2cp-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2cp-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2cp-16), ERRNO_UNCHANGED }, { LIT (0x3.281c3p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2.f8646cp+0", LIT (0x2.f8646cp+0), { LIT (0x1.be98dep-16), ERRNO_UNCHANGED }, { LIT (0x1.be98dep-16), ERRNO_UNCHANGED }, { LIT (0x1.be98dep-16), ERRNO_UNCHANGED }, { LIT (0x1.be98ep-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x1.328f5ep-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ep-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ep-8), ERRNO_UNCHANGED }, { LIT (0x1.328f6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-4", LIT (0x2p-4), { LIT (0xd.c143cp-4), ERRNO_UNCHANGED }, { LIT (0xd.c143dp-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cp-4), ERRNO_UNCHANGED }, { LIT (0xd.c143dp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3.e8p+8", LIT (0x3.e8p+8), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x3.ee6078p+0", LIT (0x3.ee6078p+0), { LIT (0x7.4334ap-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a8p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334ap-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a8p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.729df6p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.2p+0", LIT (0x4.2p+0), { LIT (0x1.74b178p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b17ap-28), ERRNO_UNCHANGED }, { LIT (0x1.74b178p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b17ap-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4.b48498p+0", LIT (0x4.b48498p+0), { LIT (0x1.f57faap-36), ERRNO_UNCHANGED }, { LIT (0x1.f57facp-36), ERRNO_UNCHANGED }, { LIT (0x1.f57faap-36), ERRNO_UNCHANGED }, { LIT (0x1.f57facp-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x4.23774p-28), ERRNO_UNCHANGED }, { LIT (0x4.237748p-28), ERRNO_UNCHANGED }, { LIT (0x4.23774p-28), ERRNO_UNCHANGED }, { LIT (0x4.237748p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.fb7c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x1.b0c1a6p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a8p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a6p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a8p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.88fb08p+0", LIT (0x6.88fb08p+0), { LIT (0x7.23ff78p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff78p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff78p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff8p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x6.a89308p+4", LIT (0x6.a89308p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.a893p+4", LIT (0x6.a893p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.a8a058p+4", LIT (0x6.a8a058p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.a8a05p+4", LIT (0x6.a8a05p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.a8p+4", LIT (0x6.a8p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.aap+4", LIT (0x6.aap+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.ap+4", LIT (0x6.ap+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.bp+4", LIT (0x6.bp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6.cp+4", LIT (0x6.cp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x6p+0", LIT (0x6p+0), { LIT (0x1.8cf814p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf816p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf814p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf816p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7.fe8008p+0", LIT (0x7.fe8008p+0), { LIT (0xf.a3372p-100), ERRNO_UNCHANGED }, { LIT (0xf.a3372p-100), ERRNO_UNCHANGED }, { LIT (0xf.a3372p-100), ERRNO_UNCHANGED }, { LIT (0xf.a3373p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7.fffd58p+0", LIT (0x7.fffd58p+0), { LIT (0xe.3cdfbp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfbp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfbp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfcp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7.fffd6p+0", LIT (0x7.fffd6p+0), { LIT (0xe.3cd88p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd88p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd88p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd89p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7.ffff2p+0", LIT (0x7.ffff2p+0), { LIT (0xe.3b46ep-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46ep-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46ep-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46fp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x7p+0", LIT (0x7p+0), { LIT (0x3.2945p-76), ERRNO_UNCHANGED }, { LIT (0x3.294504p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945p-76), ERRNO_UNCHANGED }, { LIT (0x3.294504p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8.c66b4p+0", LIT (0x8.c66b4p+0), { LIT (0x1.eb9854p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9854p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9854p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9856p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8.c66b5p+0", LIT (0x8.c66b5p+0), { LIT (0x1.eb9634p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9636p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9634p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9636p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xe.3a7e2p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e3p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.6f9d4p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d5p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d5p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x9.31cdfp+0", LIT (0x9.31cdfp+0), { LIT (0x4.00041p-128), ERRNO_UNCHANGED }, { LIT (0x4.000418p-128), ERRNO_UNCHANGED }, { LIT (0x4.00041p-128), ERRNO_UNCHANGED }, { LIT (0x4.000418p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0x9.31cep+0", LIT (0x9.31cep+0), { LIT (0x3.ffff7p-128), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffff78p-128), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffff7p-128), UNDERFLOW_EXCEPTION }, { LIT (0x3.ffff78p-128), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x8.cc6a1p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a1p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a1p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a2p-124), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xap+0", LIT (0xap+0), { LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION }, { LIT (0x1p-148), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0xb.22749p+0", LIT (0xb.22749p+0), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0xb.2274ap+0", LIT (0xb.2274ap+0), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0xb.acb72p+0", LIT (0xb.acb72p+0), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary32)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x4.9f1b4p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b48p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b4p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b48p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xd.03d06p-4", LIT (0xd.03d06p-4), { LIT (0x3.fff918p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91cp-4), ERRNO_UNCHANGED }, { LIT (0x3.fff918p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xd.28abfp-4", LIT (0xd.28abfp-4), { LIT (0x3.eaab94p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab98p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab94p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xd.361d9p-4", LIT (0xd.361d9p-4), { LIT (0x3.e2fa6p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xd.44cd3p-4", LIT (0xd.44cd3p-4), { LIT (0x3.da9f6p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f6p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f6p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f64p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xd.47425p-4", LIT (0xd.47425p-4), { LIT (0x3.d93aacp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93abp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aacp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93abp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xd.47426p-4", LIT (0xd.47426p-4), { LIT (0x3.d93aa4p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa4p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa4p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary32)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-152), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (0x1.d7bb3d3a08445p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08445p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08445p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08446p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (0x1.fecd70a13caf1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf1p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x2p-56", LIT (-0x2p-56), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (0x1.fffe8d6209afcp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afdp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afdp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (0x1.ffffffbdc88bbp+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bbp+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bbp+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bcp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (0x1.fffffffffe4f3p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f4p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f4p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.fffff8p-4", LIT (-0x7.fffff8p-4), { LIT (0x1.853f7a704b7bep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7bep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7bep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7bfp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7.ffffffffffffcp-4", LIT (-0x7.ffffffffffffcp-4), { LIT (0x1.853f7ae0c76e8p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e9p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e9p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-4", LIT (-0x8p-4), { LIT (0x1.853f7ae0c76e9p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e9p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e9p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76eap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-8", LIT (-0x8p-8), { LIT (0x1.09062b22ee929p+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee92ap+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929p+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee92ap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000001p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xap+0", LIT (-0xap+0), { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffp+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.2f644ep+0", LIT (0x1.2f644ep+0), { LIT (0x1.7fefc09137c94p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c95p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c94p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c95p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.3ffcbep+0", LIT (0x1.3ffcbep+0), { LIT (0x1.3bd9679020a68p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a68p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a68p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a69p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.3ffcbf39febb4p+0", LIT (0x1.3ffcbf39febb4p+0), { LIT (0x1.3bd962ebb7736p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb7736p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb7736p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb7737p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.3ffccp+0", LIT (0x1.3ffccp+0), { LIT (0x1.3bd95ffe4e556p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e556p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e556p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e557p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.4p+0", LIT (0x1.4p+0), { LIT (0x1.3bcd133aa0ffbp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffcp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.514548p+0", LIT (0x1.514548p+0), { LIT (0xf.fbeadad5a51fp-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f8p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51fp-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5166e0efc44a9p+0", LIT (0x1.5166e0efc44a9p+0), { LIT (0xf.f53d3d6dfa77p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa778p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa77p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa778p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5166e0efc44aap+0", LIT (0x1.5166e0efc44aap+0), { LIT (0xf.f53d3d6dfa74p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa748p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5166e2p+0", LIT (0x1.5166e2p+0), { LIT (0xf.f53d075aa92bp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92bp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92bp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5166ep+0", LIT (0x1.5166ep+0), { LIT (0xf.f53d6d0e58d08p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5289fep+0", LIT (0x1.5289fep+0), { LIT (0xf.bbc04428a3d3p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d3p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d3p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d38p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5cf2167efe921p+0", LIT (0x1.5cf2167efe921p+0), { LIT (0xd.cc22a7f1317e8p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317fp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317e8p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317fp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5cf2167efe92p+0", LIT (0x1.5cf2167efe92p+0), { LIT (0xd.cc22a7f131818p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131818p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131818p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13182p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5cf216p+0", LIT (0x1.5cf216p+0), { LIT (0xd.cc22be4b9b32p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b328p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b32p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b328p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.5cf218p+0", LIT (0x1.5cf218p+0), { LIT (0xd.cc22642cb5ab8p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5acp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.64dafap+0", LIT (0x1.64dafap+0), { LIT (0xc.766cbf61fd648p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd648p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd648p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd65p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.65e31p+0", LIT (0x1.65e31p+0), { LIT (0xc.4bf9de451e5f8p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e6p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5f8p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8a0c62p+0", LIT (0x1.8a0c62p+0), { LIT (0x7.8cde596304018p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde596304018p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde596304018p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde59630401cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.8a0c64p+0", LIT (0x1.8a0c64p+0), { LIT (0x7.8cde235791e7cp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7cp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7cp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.9d7adac608e85p+4", LIT (0x1.9d7adac608e85p+4), { LIT (0x8.0000000000d88p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d9p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d88p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d9p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.9d7adac608e86p+4", LIT (0x1.9d7adac608e86p+4), { LIT (0x7.ffffffffff3bp-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3bp-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3bp-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b4p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.9d7adap+4", LIT (0x1.9d7adap+4), { LIT (0x8.001401a2efa2p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa28p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa28p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.9d7adcp+4", LIT (0x1.9d7adcp+4), { LIT (0x7.ffe0488939954p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe0488939958p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe0488939954p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe0488939958p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.a8b12ep+4", LIT (0x1.a8b12ep+4), { LIT (0x4.001799b7b63b8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bcp-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63b8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bcp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.a8b12fc6e4891p+4", LIT (0x1.a8b12fc6e4891p+4), { LIT (0x4.0000000000cc8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cccp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.a8b12fc6e4892p+4", LIT (0x1.a8b12fc6e4892p+4), { LIT (0x3.fffffffffff8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffff8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffff8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffff84p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1.a8b13p+4", LIT (0x1.a8b13p+4), { LIT (0x3.fffd098f7c638p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffd098f7c63cp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffd098f7c638p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffd098f7c63cp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1.ap+4", LIT (0x1.ap+4), { LIT (0x9.425ff0e6f5118p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f512p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f5118p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f512p-984), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1.bp+4", LIT (0x1.bp+4), { LIT (0x6.783cp-1060), UNDERFLOW_EXCEPTION }, { LIT (0x6.783cp-1060), UNDERFLOW_EXCEPTION }, { LIT (0x6.783cp-1060), UNDERFLOW_EXCEPTION }, { LIT (0x6.784p-1060), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1.cp+4", LIT (0x1.cp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x1.e33c9ep+0", LIT (0x1.e33c9ep+0), { LIT (0x1.f1cb04b622e6fp-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6fp-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6fp-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e7p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x2.844c2c5f7bba8p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bbaap-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba8p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bbaap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffedf228afb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.ffffffffedf2p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf2p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf2p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf28p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.36c504p+0", LIT (0x2.36c504p+0), { LIT (0x7.22d059993f3f4p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f4p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f4p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.56af04p+0", LIT (0x2.56af04p+0), { LIT (0x3.dbca059c7e73ap-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73ap-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73ap-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73cp-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.586f1cp+0", LIT (0x2.586f1cp+0), { LIT (0x3.ba3ac339ed19p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed19p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed19p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed192p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7f8c8p+0", LIT (0x2.b7f8c8p+0), { LIT (0x7.e8b3a6276f03cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f04p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f04p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7f8cb76737d2p+0", LIT (0x2.b7f8cb76737d2p+0), { LIT (0x7.e8b308381e02p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e024p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7f8cb76737d4p+0", LIT (0x2.b7f8cb76737d4p+0), { LIT (0x7.e8b308381dfc4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.b7f8ccp+0", LIT (0x2.b7f8ccp+0), { LIT (0x7.e8b2efb67945p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb67945p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb67945p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679454p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.dfb9b4p+0", LIT (0x2.dfb9b4p+0), { LIT (0x3.281c2d7e470e4p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e6p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e4p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e6p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2.f8646cp+0", LIT (0x2.f8646cp+0), { LIT (0x1.be98de114e174p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e175p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e175p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x1.328f5ec350e66p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e67p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e66p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e67p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffdbe4515faa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515fabp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faa8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515fabp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffffdbe45p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe45p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe45p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe458p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-4", LIT (0x2p-4), { LIT (0xd.c143cb94788e8p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788fp-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788e8p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788fp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3.e8p+8", LIT (0x3.e8p+8), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x3.ee6078p+0", LIT (0x3.ee6078p+0), { LIT (0x7.4334a54e12088p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208cp-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e12088p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208cp-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.729df6503422ap-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422ap-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422ap-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422bp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.2p+0", LIT (0x4.2p+0), { LIT (0x1.74b179d1eba8p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba81p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba8p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba81p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4.b48498p+0", LIT (0x4.b48498p+0), { LIT (0x1.f57fab6c3db3cp-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3dp-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3cp-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3dp-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x4.237744ef4d798p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79cp-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d798p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79cp-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.fb7c8a4401cdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cdp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffb7c8a28p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a28p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a28p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a3p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffffffffbp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffbp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x1.b0c1a759f7738p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7739p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7739p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.88fb08p+0", LIT (0x6.88fb08p+0), { LIT (0x7.23ff79ae0f258p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25cp-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f258p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25cp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a893032db9054p+4", LIT (0x6.a893032db9054p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a893032db905p+4", LIT (0x6.a893032db905p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a89308p+4", LIT (0x6.a89308p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a893p+4", LIT (0x6.a893p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a8a0561d8bbe8p+4", LIT (0x6.a8a0561d8bbe8p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a8a0561d8bbecp+4", LIT (0x6.a8a0561d8bbecp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a8a058p+4", LIT (0x6.a8a058p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a8a05p+4", LIT (0x6.a8a05p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.a8p+4", LIT (0x6.a8p+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.aap+4", LIT (0x6.aap+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.ap+4", LIT (0x6.ap+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.bp+4", LIT (0x6.bp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6.cp+4", LIT (0x6.cp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0x6p+0", LIT (0x6p+0), { LIT (0x1.8cf81557d20b6p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b6p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b6p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b7p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.fe8008p+0", LIT (0x7.fe8008p+0), { LIT (0xf.a33725bea2f78p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f8p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f78p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f8p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.fffd58p+0", LIT (0x7.fffd58p+0), { LIT (0xe.3cdfb051e694p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e694p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e694p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e6948p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.fffd59e26af34p+0", LIT (0x7.fffd59e26af34p+0), { LIT (0xe.3cddffbbe885p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe8858p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe885p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe8858p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.fffd59e26af38p+0", LIT (0x7.fffd59e26af38p+0), { LIT (0xe.3cddffbbe84b8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84b8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84cp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.fffd6p+0", LIT (0x7.fffd6p+0), { LIT (0xe.3cd883e02b148p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b15p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b148p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b15p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7.ffff2p+0", LIT (0x7.ffff2p+0), { LIT (0xe.3b46e15ad978p-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad978p-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad978p-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad9788p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x7p+0", LIT (0x7p+0), { LIT (0x3.2945026df4e62p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e64p-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.c66b44ca40038p+0", LIT (0x8.c66b44ca40038p+0), { LIT (0x1.eb97b1f20867cp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867cp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867cp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867dp-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.c66b4p+0", LIT (0x8.c66b4p+0), { LIT (0x1.eb98546946cb2p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb3p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8.c66b5p+0", LIT (0x8.c66b5p+0), { LIT (0x1.eb9635bc51eb7p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb8p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb8p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xe.3a7e2090befd8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befd8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befd8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befep-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffff6f914578p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91458p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f914578p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91458p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.ffffffffff6f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f8p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff7p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.6f9d4dd116d6p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d68p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d6p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d68p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffff8p-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x9.31cdfp+0", LIT (0x9.31cdfp+0), { LIT (0x4.0004157f2239cp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239cp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239cp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f223ap-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x9.31cep+0", LIT (0x9.31cep+0), { LIT (0x3.ffff75b4a7f7p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f72p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f7p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f72p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x8.cc6a115f1fc6p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc68p-124), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xap+0", LIT (0xap+0), { LIT (0xb.ec53f95451678p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545168p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f95451678p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545168p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xb.2274991033578p+0", LIT (0xb.2274991033578p+0), { LIT (0x1.c6479753dddf2p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf3p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xb.227499103358p+0", LIT (0xb.227499103358p+0), { LIT (0x1.c6479753ddcb4p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb5p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb5p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xb.22749p+0", LIT (0xb.22749p+0), { LIT (0x1.c648feeb672e8p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e9p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e9p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xb.2274ap+0", LIT (0xb.2274ap+0), { LIT (0x1.c646841c9021p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c9021p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c9021p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c90211p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xb.acb72p+0", LIT (0xb.acb72p+0), { LIT (0x7.ee2d2ec57315p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec57315p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec57315p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec573154p-204), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x4.9f1b453178d04p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d04p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d04p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d08p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xd.03d06p-4", LIT (0xd.03d06p-4), { LIT (0x3.fff91a7d782bp-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782bp-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782bp-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xd.28abfp-4", LIT (0xd.28abfp-4), { LIT (0x3.eaab96d5a2e28p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e2ap-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e28p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e2ap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xd.361d9p-4", LIT (0xd.361d9p-4), { LIT (0x3.e2fa6064d5892p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d5894p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d5892p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d5894p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xd.44cd3p-4", LIT (0xd.44cd3p-4), { LIT (0x3.da9f608f1dd7ep-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ep-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ep-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xd.47425b3cafa48p-4", LIT (0xd.47425b3cafa48p-4), { LIT (0x3.d93aa84f87a9ep-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ep-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87aap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xd.47425p-4", LIT (0xd.47425p-4), { LIT (0x3.d93aaeadb64dp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64dp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64dp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xd.47426p-4", LIT (0xd.47426p-4), { LIT (0x3.d93aa59c8f5aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5acp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5aap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5acp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_binary64)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_binary64)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (0x1.d7bb3d3a0844563680887edd868p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a0844563680887edd868p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a0844563680887edd868p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a0844563680887edd87p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (0x1.fecd70a13caf19972801904b9ap+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf19972801904b9ap+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf19972801904b9ap+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf19972801904b9a8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x2p-56", LIT (-0x2p-56), { LIT (0x1.0000000000000241baea08536d8p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000241baea08536d8p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000241baea08536d8p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000241baea08536ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (0x1.fffe8d6209afcbdd5f43d9ad9d8p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdd5f43d9ad9ep+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdd5f43d9ad9d8p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdd5f43d9ad9ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (0x1.ffffffbdc88bb10b2865615db4p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10b2865615db4p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10b2865615db4p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10b2865615db48p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (0x1.fffffffffe4f3e58a6088c76cap+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58a6088c76cap+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58a6088c76cap+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58a6088c76ca8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (0x1.fffffffffffffe7307eaa82df48p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe7307eaa82df48p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe7307eaa82df48p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe7307eaa82df5p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.fffff8p-4", LIT (-0x7.fffff8p-4), { LIT (0x1.853f7a704b7be2d643b9e3ae3c8p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d643b9e3ae3c8p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d643b9e3ae3c8p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d643b9e3ae3dp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.ffffffffffffcp-4", LIT (-0x7.ffffffffffffcp-4), { LIT (0x1.853f7ae0c76e8ddaa10a86e7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddaa10a86e7a08p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddaa10a86e7ap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddaa10a86e7a08p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7.ffffffffffffep-4", LIT (-0x7.ffffffffffffep-4), { LIT (0x1.853f7ae0c76e8f9c90d4d08ca1p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9c90d4d08ca18p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9c90d4d08ca1p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9c90d4d08ca18p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (0x1.ffffffffffffffffffcd6bafd9p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffcd6bafd9p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffcd6bafd9p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffcd6bafd98p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (0x1.ffffffffffffffffffffffff1cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffff1c8p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffff1cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffff1c8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-4", LIT (-0x8p-4), { LIT (0x1.853f7ae0c76e915e809f1a31a2p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915e809f1a31a28p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915e809f1a31a2p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915e809f1a31a28p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-8", LIT (-0x8p-8), { LIT (0x1.09062b22ee929bfc9c18d570fc8p+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfc9c18d570fdp+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfc9c18d570fc8p+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfc9c18d570fdp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000000000000000008p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xap+0", LIT (-0xap+0), { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.ffffffffffffbffffffffffffcp+1020", LIT (-0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffffffffffffffffffffff8p+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.2f644ep+0", LIT (0x1.2f644ep+0), { LIT (0x1.7fefc09137c9485d5871f07f94p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485d5871f07f948p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485d5871f07f94p-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485d5871f07f948p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.3ffcbep+0", LIT (0x1.3ffcbep+0), { LIT (0x1.3bd9679020a687bf0ac713ffafp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687bf0ac713ffaf8p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687bf0ac713ffafp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687bf0ac713ffaf8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.3ffcbf39febb4p+0", LIT (0x1.3ffcbf39febb4p+0), { LIT (0x1.3bd962ebb773644beafd5d55b3p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644beafd5d55b38p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644beafd5d55b3p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644beafd5d55b38p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.3ffccp+0", LIT (0x1.3ffccp+0), { LIT (0x1.3bd95ffe4e5561c5991cb64b65p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c5991cb64b658p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c5991cb64b65p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c5991cb64b658p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.4p+0", LIT (0x1.4p+0), { LIT (0x1.3bcd133aa0ffbf9d895f72e9b18p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9d895f72e9b2p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9d895f72e9b18p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9d895f72e9b2p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.514548p+0", LIT (0x1.514548p+0), { LIT (0xf.fbeadad5a51f774a6aa2da69d8p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f774a6aa2da69dcp-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f774a6aa2da69d8p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f774a6aa2da69dcp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5166e0efc44a9dfc79b8c8873a8p+0", LIT (0x1.5166e0efc44a9dfc79b8c8873a8p+0), { LIT (0xf.f53d3d6dfa747dd2cb91abfde4p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfde4p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfde4p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfde8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5166e0efc44a9dfc79b8c8873bp+0", LIT (0x1.5166e0efc44a9dfc79b8c8873bp+0), { LIT (0xf.f53d3d6dfa747dd2cb91abfdc8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfdccp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfdc8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dd2cb91abfdccp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5166e0efc44a9dfcp+0", LIT (0x1.5166e0efc44a9dfcp+0), { LIT (0xf.f53d3d6dfa747deaf93d1ace2p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747deaf93d1ace24p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747deaf93d1ace2p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747deaf93d1ace24p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5166e0efc44a9dfep+0", LIT (0x1.5166e0efc44a9dfep+0), { LIT (0xf.f53d3d6dfa747d85458d645ddp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d85458d645dd4p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d85458d645ddp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d85458d645dd4p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5166e0efc44a9p+0", LIT (0x1.5166e0efc44a9p+0), { LIT (0xf.f53d3d6dfa7745095fdac0256p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa7745095fdac02564p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa7745095fdac0256p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa7745095fdac02564p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5166e0efc44aap+0", LIT (0x1.5166e0efc44aap+0), { LIT (0xf.f53d3d6dfa74176be2273d9c68p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74176be2273d9c68p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74176be2273d9c68p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74176be2273d9c6cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5166e2p+0", LIT (0x1.5166e2p+0), { LIT (0xf.f53d075aa92b1f075d1f393d64p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1f075d1f393d68p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1f075d1f393d64p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1f075d1f393d68p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5166ep+0", LIT (0x1.5166ep+0), { LIT (0xf.f53d6d0e58d08f84e49864553p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f84e498645534p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f84e49864553p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f84e498645534p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5289fep+0", LIT (0x1.5289fep+0), { LIT (0xf.bbc04428a3d30e77d2315d0044p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e77d2315d0048p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e77d2315d0044p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e77d2315d0048p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5cf2167efe9207d2p+0", LIT (0x1.5cf2167efe9207d2p+0), { LIT (0xd.cc22a7f131804ea9510443197cp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ea9510443198p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ea9510443197cp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ea9510443198p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5cf2167efe921p+0", LIT (0x1.5cf2167efe921p+0), { LIT (0xd.cc22a7f1317ede14f24f95f12cp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede14f24f95f12cp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede14f24f95f12cp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede14f24f95f13p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5cf2167efe92p+0", LIT (0x1.5cf2167efe92p+0), { LIT (0xd.cc22a7f13181af0c2264782d18p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af0c2264782d18p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af0c2264782d18p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af0c2264782d1cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5cf216p+0", LIT (0x1.5cf216p+0), { LIT (0xd.cc22be4b9b325bc5efb8f07224p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bc5efb8f07224p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bc5efb8f07224p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bc5efb8f07228p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.5cf218p+0", LIT (0x1.5cf218p+0), { LIT (0xd.cc22642cb5ab8dc55a1975e038p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dc55a1975e03cp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dc55a1975e038p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dc55a1975e03cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.64dafap+0", LIT (0x1.64dafap+0), { LIT (0xc.766cbf61fd6480afed02bf2b2p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480afed02bf2b2p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480afed02bf2b2p-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480afed02bf2b24p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.65e31p+0", LIT (0x1.65e31p+0), { LIT (0xc.4bf9de451e5fced9d5e2d18c2p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fced9d5e2d18c2p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fced9d5e2d18c2p-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fced9d5e2d18c24p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8a0c62p+0", LIT (0x1.8a0c62p+0), { LIT (0x7.8cde5963040180b50eb9ef7f8ap-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b50eb9ef7f8ap-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b50eb9ef7f8ap-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b50eb9ef7f8cp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.8a0c64p+0", LIT (0x1.8a0c64p+0), { LIT (0x7.8cde235791e7d0dfc843bc26d4p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0dfc843bc26d6p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0dfc843bc26d4p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0dfc843bc26d6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9d7adac608e85862p+4", LIT (0x1.9d7adac608e85862p+4), { LIT (0x8.00000000000019f3f043fe66ccp-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019f3f043fe66dp-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019f3f043fe66ccp-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019f3f043fe66dp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9d7adac608e8586300e6c8b99e8p+4", LIT (0x1.9d7adac608e8586300e6c8b99e8p+4), { LIT (0x7.fffffffffffffffffffffff54cp-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.fffffffffffffffffffffff55p-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.fffffffffffffffffffffff54cp-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.fffffffffffffffffffffff55p-972), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9d7adac608e8586300e6c8b99ep+4", LIT (0x1.9d7adac608e8586300e6c8b99ep+4), { LIT (0x8.0000000000000000000000023cp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000023cp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000023cp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000000000000000024p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9d7adac608e85864p+4", LIT (0x1.9d7adac608e85864p+4), { LIT (0x7.ffffffffffffe63ab0b952a39p-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffffffffffffe63ab0b952a394p-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffffffffffffe63ab0b952a39p-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffffffffffffe63ab0b952a394p-972), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9d7adac608e85p+4", LIT (0x1.9d7adac608e85p+4), { LIT (0x8.0000000000d8e567447df7350cp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e567447df7350cp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e567447df7350cp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e567447df7351p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9d7adac608e86p+4", LIT (0x1.9d7adac608e86p+4), { LIT (0x7.ffffffffff3b1b6aef1fdb4538p-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffffffffff3b1b6aef1fdb453cp-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffffffffff3b1b6aef1fdb4538p-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffffffffff3b1b6aef1fdb453cp-972), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9d7adap+4", LIT (0x1.9d7adap+4), { LIT (0x8.001401a2efa2624d0e762da138p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2624d0e762da138p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2624d0e762da138p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2624d0e762da13cp-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.9d7adcp+4", LIT (0x1.9d7adcp+4), { LIT (0x7.ffe048893995703e6ead0de50cp-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffe048893995703e6ead0de51p-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffe048893995703e6ead0de50cp-972), UNDERFLOW_EXCEPTION }, { LIT (0x7.ffe048893995703e6ead0de51p-972), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.a8b12ep+4", LIT (0x1.a8b12ep+4), { LIT (0x4.001799b7b63b8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4.001799b7b63bcp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4.001799b7b63b8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4.001799b7b63bcp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.a8b12fc6e4891p+4", LIT (0x1.a8b12fc6e4891p+4), { LIT (0x4.0000000000cc8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4.0000000000cc8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4.0000000000cc8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x4.0000000000cccp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.a8b12fc6e4892p+4", LIT (0x1.a8b12fc6e4892p+4), { LIT (0x3.fffffffffff8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffff8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffff8p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffff84p-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.a8b13p+4", LIT (0x1.a8b13p+4), { LIT (0x3.fffd098f7c638p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffd098f7c63cp-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffd098f7c638p-1024), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffd098f7c63cp-1024), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.ap+4", LIT (0x1.ap+4), { LIT (0x9.425ff0e6f511d74db40cfb8p-984), UNDERFLOW_EXCEPTION }, { LIT (0x9.425ff0e6f511d74db40cfbcp-984), UNDERFLOW_EXCEPTION }, { LIT (0x9.425ff0e6f511d74db40cfb8p-984), UNDERFLOW_EXCEPTION }, { LIT (0x9.425ff0e6f511d74db40cfbcp-984), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.bp+4", LIT (0x1.bp+4), { LIT (0x6.783cp-1060), UNDERFLOW_EXCEPTION }, { LIT (0x6.783cp-1060), UNDERFLOW_EXCEPTION }, { LIT (0x6.783cp-1060), UNDERFLOW_EXCEPTION }, { LIT (0x6.784p-1060), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.cp+4", LIT (0x1.cp+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x1.e33c9ep+0", LIT (0x1.e33c9ep+0), { LIT (0x1.f1cb04b622e6f4d5035449633bp-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d5035449633b8p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d5035449633bp-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d5035449633b8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x2.844c2c5f7bba9c97f778122796p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c97f778122797p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c97f778122796p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c97f778122797p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffffffffffedcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffeep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffedcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffeep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffedf228afbd6a978b6c864b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6a978b6c864b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6a978b6c864b4p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6a978b6c864b8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.ffffffffedf228afbd6492ee5p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228afbd6492ee5p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228afbd6492ee5p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228afbd6492ee54p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffedf228afbd648p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffedf228afbd648p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffedf228afbd648p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffedf228afbd64cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.36c504p+0", LIT (0x2.36c504p+0), { LIT (0x7.22d059993f3f46d0e0daa16356p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46d0e0daa16358p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46d0e0daa16356p-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46d0e0daa16358p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.56af04p+0", LIT (0x2.56af04p+0), { LIT (0x3.dbca059c7e73a1239dd5202828p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a1239dd5202828p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a1239dd5202828p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a1239dd5202829p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.586f1cp+0", LIT (0x2.586f1cp+0), { LIT (0x3.ba3ac339ed1902051ea0071675p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed1902051ea0071675p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed1902051ea0071675p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed1902051ea0071676p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7f8c8p+0", LIT (0x2.b7f8c8p+0), { LIT (0x7.e8b3a6276f03f7798c2a7c4e62p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f7798c2a7c4e62p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f7798c2a7c4e62p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f7798c2a7c4e64p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7f8cb76737d2af8p+0", LIT (0x2.b7f8cb76737d2af8p+0), { LIT (0x7.e8b308381e001502525c2ab332p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001502525c2ab332p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001502525c2ab332p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001502525c2ab334p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7f8cb76737d2af98dead7c4c5p+0", LIT (0x2.b7f8cb76737d2af98dead7c4c5p+0), { LIT (0x7.e8b308381e0014bb6d3bd6db84p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db84p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db84p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db86p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7f8cb76737d2af98dead7c4c6p+0", LIT (0x2.b7f8cb76737d2af98dead7c4c6p+0), { LIT (0x7.e8b308381e0014bb6d3bd6db56p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db56p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db56p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0014bb6d3bd6db58p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7f8cb76737d2afcp+0", LIT (0x2.b7f8cb76737d2afcp+0), { LIT (0x7.e8b308381e00144be16c16cf88p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e00144be16c16cf88p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e00144be16c16cf88p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e00144be16c16cf8ap-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7f8cb76737d2p+0", LIT (0x2.b7f8cb76737d2p+0), { LIT (0x7.e8b308381e02094c04b2b4fe1cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02094c04b2b4fe1ep-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02094c04b2b4fe1cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02094c04b2b4fe1ep-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7f8cb76737d4p+0", LIT (0x2.b7f8cb76737d4p+0), { LIT (0x7.e8b308381dfc55c4841397b30ap-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c4841397b30ap-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c4841397b30ap-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c4841397b30cp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.b7f8ccp+0", LIT (0x2.b7f8ccp+0), { LIT (0x7.e8b2efb679451a42955c7a94bep-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a42955c7a94cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a42955c7a94bep-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a42955c7a94cp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.dfb9b4p+0", LIT (0x2.dfb9b4p+0), { LIT (0x3.281c2d7e470e5082e420978869p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5082e420978869p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5082e420978869p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5082e42097886ap-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2.f8646cp+0", LIT (0x2.f8646cp+0), { LIT (0x1.be98de114e174b501b7acff72e8p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b501b7acff72e8p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b501b7acff72e8p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b501b7acff72fp-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x1.328f5ec350e668d7fe6fb465ccp-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d7fe6fb465ccp-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d7fe6fb465ccp-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d7fe6fb465cc8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffdbe4515faaee0eb270b8c6bp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee0eb270b8c6bp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee0eb270b8c6bp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee0eb270b8c6b4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffffdbe4515f7ac925dca38p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515f7ac925dca3cp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515f7ac925dca38p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515f7ac925dca3cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-4", LIT (0x2p-4), { LIT (0xd.c143cb94788ed17a494db60f84p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed17a494db60f88p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed17a494db60f84p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed17a494db60f88p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.ffffffffffffdbe4515f7ac924p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbe4515f7ac924p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbe4515f7ac924p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbe4515f7ac928p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.e8p+8", LIT (0x3.e8p+8), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x3.ee6078p+0", LIT (0x3.ee6078p+0), { LIT (0x7.4334a54e1208ae1b8bfa15647ap-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae1b8bfa15647cp-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae1b8bfa15647ap-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae1b8bfa15647cp-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.729df6503422a0bc26526214d08p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bc26526214d08p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bc26526214d08p-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bc26526214d1p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.2p+0", LIT (0x4.2p+0), { LIT (0x1.74b179d1eba809f2e322240741p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2e322240741p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2e322240741p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2e3222407418p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4.b48498p+0", LIT (0x4.b48498p+0), { LIT (0x1.f57fab6c3db3ce7e0bd2fb1379p-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7e0bd2fb1379p-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7e0bd2fb1379p-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7e0bd2fb13798p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x4.237744ef4d79a9ea24bfce6c7ep-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9ea24bfce6c7ep-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9ea24bfce6c7ep-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9ea24bfce6c8p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.fb7c8a4401cd1c3347a83a17d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3347a83a17dcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3347a83a17d8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3347a83a17dcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffb7c8a2bef5924bbac83cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2bef5924bbac83cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2bef5924bbac83cp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2bef5924bbac84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffffffffb7c8a2bef5924b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c8a2bef5924bcp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c8a2bef5924b8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c8a2bef5924bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x1.b0c1a759f7738935ea5dea8e178p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738935ea5dea8e178p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738935ea5dea8e178p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738935ea5dea8e18p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.88fb08p+0", LIT (0x6.88fb08p+0), { LIT (0x7.23ff79ae0f25a135a4973efb8ap-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a135a4973efb8cp-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a135a4973efb8ap-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a135a4973efb8cp-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a893032db905274042fb05c664p+4", LIT (0x6.a893032db905274042fb05c664p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a893032db905274042fb05c666p+4", LIT (0x6.a893032db905274042fb05c666p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a893032db9052748p+4", LIT (0x6.a893032db9052748p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a893032db905274p+4", LIT (0x6.a893032db905274p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a893032db9054p+4", LIT (0x6.a893032db9054p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a893032db905p+4", LIT (0x6.a893032db905p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a89308p+4", LIT (0x6.a89308p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a893p+4", LIT (0x6.a893p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a8a0561d8bbe8p+4", LIT (0x6.a8a0561d8bbe8p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a8a0561d8bbe9428p+4", LIT (0x6.a8a0561d8bbe9428p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a8a0561d8bbe942p+4", LIT (0x6.a8a0561d8bbe942p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a8a0561d8bbecp+4", LIT (0x6.a8a0561d8bbecp+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a8a058p+4", LIT (0x6.a8a058p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a8a05p+4", LIT (0x6.a8a05p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.a8p+4", LIT (0x6.a8p+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.aap+4", LIT (0x6.aap+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.ap+4", LIT (0x6.ap+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.bp+4", LIT (0x6.bp+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6.cp+4", LIT (0x6.cp+4), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0x6p+0", LIT (0x6p+0), { LIT (0x1.8cf81557d20b61a7fff0cc732b8p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a7fff0cc732cp-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a7fff0cc732b8p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a7fff0cc732cp-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fe8008p+0", LIT (0x7.fe8008p+0), { LIT (0xf.a33725bea2f7d7abe8b7461d6p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7abe8b7461d64p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7abe8b7461d6p-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7abe8b7461d64p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fffd58p+0", LIT (0x7.fffd58p+0), { LIT (0xe.3cdfb051e6943150a3c2f2e708p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e6943150a3c2f2e70cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e6943150a3c2f2e708p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e6943150a3c2f2e70cp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fffd59e26af34p+0", LIT (0x7.fffd59e26af34p+0), { LIT (0xe.3cddffbbe88543bb57f5bfbba8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543bb57f5bfbbacp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543bb57f5bfbba8p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543bb57f5bfbbacp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fffd59e26af37bc048d159e26ap+0", LIT (0x7.fffd59e26af37bc048d159e26ap+0), { LIT (0xe.3cddffbbe84faf818649c2377p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84faf818649c2377p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84faf818649c2377p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84faf818649c23774p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fffd59e26af37bc8p+0", LIT (0x7.fffd59e26af37bc8p+0), { LIT (0xe.3cddffbbe84fa8965f5d5ffd38p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa8965f5d5ffd38p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa8965f5d5ffd38p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa8965f5d5ffd3cp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fffd59e26af37bcp+0", LIT (0x7.fffd59e26af37bcp+0), { LIT (0xe.3cddffbbe84fafc2d20bb0997p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafc2d20bb0997p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafc2d20bb0997p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafc2d20bb09974p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fffd59e26af38p+0", LIT (0x7.fffd59e26af38p+0), { LIT (0xe.3cddffbbe84be025e570dd9c7cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be025e570dd9c7cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be025e570dd9c7cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be025e570dd9c8p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.fffd6p+0", LIT (0x7.fffd6p+0), { LIT (0xe.3cd883e02b14daf90f0f812034p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14daf90f0f812034p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14daf90f0f812034p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14daf90f0f812038p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7.ffff2p+0", LIT (0x7.ffff2p+0), { LIT (0xe.3b46e15ad97825d129852878fcp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825d129852879p-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825d129852878fcp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825d129852879p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x7p+0", LIT (0x7p+0), { LIT (0x3.2945026df4e62a48fcf382c1cfp-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48fcf382c1dp-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48fcf382c1cfp-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48fcf382c1dp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.c66b44ca40038p+0", LIT (0x8.c66b44ca40038p+0), { LIT (0x1.eb97b1f20867c35eff191bbecap-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35eff191bbecap-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35eff191bbecap-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35eff191bbeca8p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.c66b4p+0", LIT (0x8.c66b4p+0), { LIT (0x1.eb98546946cb2525a4905a3b138p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2525a4905a3b138p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2525a4905a3b138p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2525a4905a3b14p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8.c66b5p+0", LIT (0x8.c66b5p+0), { LIT (0x1.eb9635bc51eb7a94581f979eadp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94581f979eadp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94581f979eadp-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94581f979ead8p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xe.3a7e2090befdbb5c007d16c48cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb5c007d16c49p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb5c007d16c48cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb5c007d16c49p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffff6f91457deb24a37bc860cp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457deb24a37bc861p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457deb24a37bc860cp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457deb24a37bc861p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.ffffffffff6f91457deb24977p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f91457deb249774p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f91457deb24977p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f91457deb249774p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.6f9d4dd116d640363e72a8f03p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d640363e72a8f03p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d640363e72a8f03p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d640363e72a8f034p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffffffffffffcp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x9.31cdfp+0", LIT (0x9.31cdfp+0), { LIT (0x4.0004157f2239d721e27728e0acp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d721e27728e0acp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d721e27728e0acp-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d721e27728e0aep-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x9.31cep+0", LIT (0x9.31cep+0), { LIT (0x3.ffff75b4a7f71721b89fe0646fp-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f71721b89fe0646fp-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f71721b89fe0646fp-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f71721b89fe0647p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x8.cc6a115f1fc6136ba610a005fcp-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6136ba610a006p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6136ba610a005fcp-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6136ba610a006p-124), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xap+0", LIT (0xap+0), { LIT (0xb.ec53f9545167ce9b9c460ae3bp-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ce9b9c460ae3b4p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ce9b9c460ae3bp-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ce9b9c460ae3b4p-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xb.2274991033578p+0", LIT (0xb.2274991033578p+0), { LIT (0x1.c6479753dddf2401559c4dbabep-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2401559c4dbabe8p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2401559c4dbabep-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2401559c4dbabe8p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xb.227499103357d84p+0", LIT (0xb.227499103357d84p+0), { LIT (0x1.c6479753ddd176a5bf5193bad7p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a5bf5193bad78p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a5bf5193bad7p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a5bf5193bad78p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xb.227499103358p+0", LIT (0xb.227499103358p+0), { LIT (0x1.c6479753ddcb4d8c72ebbfb8ecp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8c72ebbfb8ecp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8c72ebbfb8ecp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8c72ebbfb8ec8p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xb.22749p+0", LIT (0xb.22749p+0), { LIT (0x1.c648feeb672e8e57298792150d8p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e57298792150ep-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e57298792150d8p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e57298792150ep-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xb.2274ap+0", LIT (0xb.2274ap+0), { LIT (0x1.c646841c902106e7ce3048dea08p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e7ce3048dea08p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e7ce3048dea08p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e7ce3048dea1p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xb.acb72p+0", LIT (0xb.acb72p+0), { LIT (0x7.ee2d2ec57315040047a2a1252ep-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec57315040047a2a1252ep-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec57315040047a2a1252ep-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec57315040047a2a1253p-204), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x4.9f1b453178d049d79a1a687754p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d79a1a687756p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d79a1a687754p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d79a1a687756p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xd.03d06p-4", LIT (0xd.03d06p-4), { LIT (0x3.fff91a7d782b006458655c2be8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b006458655c2be8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b006458655c2be8p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b006458655c2be9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xd.28abfp-4", LIT (0xd.28abfp-4), { LIT (0x3.eaab96d5a2e294b81fff40fde9p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b81fff40fdeap-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b81fff40fde9p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b81fff40fdeap-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xd.361d9p-4", LIT (0xd.361d9p-4), { LIT (0x3.e2fa6064d589347b0f2f7aa6e3p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347b0f2f7aa6e4p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347b0f2f7aa6e3p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347b0f2f7aa6e4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xd.44cd3p-4", LIT (0xd.44cd3p-4), { LIT (0x3.da9f608f1dd7ee3168650dc2fbp-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3168650dc2fcp-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3168650dc2fbp-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3168650dc2fcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xd.47425b3cafa48p-4", LIT (0xd.47425b3cafa48p-4), { LIT (0x3.d93aa84f87a9ffa04577ca7dbbp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffa04577ca7dbbp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffa04577ca7dbbp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffa04577ca7dbcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xd.47425p-4", LIT (0xd.47425p-4), { LIT (0x3.d93aaeadb64d00e8ad67712ba7p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8ad67712ba7p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8ad67712ba7p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8ad67712ba8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xd.47426p-4", LIT (0xd.47426p-4), { LIT (0x3.d93aa59c8f5abb821749e8017ap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb821749e8017bp-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb821749e8017ap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb821749e8017bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.ffffffffffffbffffffffffffcp+1020", LIT (0xf.ffffffffffffbffffffffffffcp+1020), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_ibm128)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-1076), ((TEST_COND_ibm128_libgcc) ? XFAIL_TEST : 0) | UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (0x1.d7bb3d3a08445636p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08445636p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08445636p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08445638p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (0x1.fecd70a13caf1996p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf1998p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf1996p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf1998p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x2p-56", LIT (-0x2p-56), { LIT (0x1.000000000000024p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000242p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000024p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000242p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (0x1.fffe8d6209afcbdcp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdep+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdcp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (0x1.ffffffbdc88bb10ap+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10ap+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (0x1.fffffffffe4f3e58p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e5ap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (0x1.fffffffffffffe72p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe74p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe72p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe74p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.fffff8p-4", LIT (-0x7.fffff8p-4), { LIT (0x1.853f7a704b7be2d6p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d6p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d6p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.ffffffffffffcp-4", LIT (-0x7.ffffffffffffcp-4), { LIT (0x1.853f7ae0c76e8ddap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddcp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7.ffffffffffffep-4", LIT (-0x7.ffffffffffffep-4), { LIT (0x1.853f7ae0c76e8f9cp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9cp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9cp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-4", LIT (-0x8p-4), { LIT (0x1.853f7ae0c76e915ep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915ep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915ep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e916p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-8", LIT (-0x8p-8), { LIT (0x1.09062b22ee929bfcp+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfcp+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfcp+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xap+0", LIT (-0xap+0), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.2f644ep+0", LIT (0x1.2f644ep+0), { LIT (0x1.7fefc09137c9485cp-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485ep-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485cp-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.3ffcbep+0", LIT (0x1.3ffcbep+0), { LIT (0x1.3bd9679020a687bep-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687cp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687bep-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.3ffcbf39febb4p+0", LIT (0x1.3ffcbf39febb4p+0), { LIT (0x1.3bd962ebb773644ap-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644cp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644ap-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.3ffccp+0", LIT (0x1.3ffccp+0), { LIT (0x1.3bd95ffe4e5561c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c6p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.4p+0", LIT (0x1.4p+0), { LIT (0x1.3bcd133aa0ffbf9cp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9ep-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9cp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.514548p+0", LIT (0x1.514548p+0), { LIT (0xf.fbeadad5a51f774p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f775p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f774p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f775p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5166e0efc44a9dfcp+0", LIT (0x1.5166e0efc44a9dfcp+0), { LIT (0xf.f53d3d6dfa747dep-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dfp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dep-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dfp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5166e0efc44a9dfep+0", LIT (0x1.5166e0efc44a9dfep+0), { LIT (0xf.f53d3d6dfa747d8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d9p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5166e0efc44a9p+0", LIT (0x1.5166e0efc44a9p+0), { LIT (0xf.f53d3d6dfa7745p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa77451p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa7745p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa77451p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5166e0efc44aap+0", LIT (0x1.5166e0efc44aap+0), { LIT (0xf.f53d3d6dfa74176p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74177p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74176p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74177p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5166e2p+0", LIT (0x1.5166e2p+0), { LIT (0xf.f53d075aa92b1fp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1fp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1fp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1f1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5166ep+0", LIT (0x1.5166ep+0), { LIT (0xf.f53d6d0e58d08f8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f9p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5289fep+0", LIT (0x1.5289fep+0), { LIT (0xf.bbc04428a3d30e7p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e7p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e7p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5cf2167efe9207d2p+0", LIT (0x1.5cf2167efe9207d2p+0), { LIT (0xd.cc22a7f131804eap-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ebp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804eap-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ebp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5cf2167efe921p+0", LIT (0x1.5cf2167efe921p+0), { LIT (0xd.cc22a7f1317ede1p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede1p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede1p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede2p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5cf2167efe92p+0", LIT (0x1.5cf2167efe92p+0), { LIT (0xd.cc22a7f13181afp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af1p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181afp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5cf216p+0", LIT (0x1.5cf216p+0), { LIT (0xd.cc22be4b9b325bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bdp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.5cf218p+0", LIT (0x1.5cf218p+0), { LIT (0xd.cc22642cb5ab8dcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8ddp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.64dafap+0", LIT (0x1.64dafap+0), { LIT (0xc.766cbf61fd6480ap-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480bp-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480ap-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480bp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.65e31p+0", LIT (0x1.65e31p+0), { LIT (0xc.4bf9de451e5fcedp-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fceep-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fcedp-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fceep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8a0c62p+0", LIT (0x1.8a0c62p+0), { LIT (0x7.8cde5963040180bp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b8p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180bp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.8a0c64p+0", LIT (0x1.8a0c64p+0), { LIT (0x7.8cde235791e7d0d8p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0ep-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0d8p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0ep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.9d7adac608e85862p+4", LIT (0x1.9d7adac608e85862p+4), { LIT (0x8.00000000000019fp-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019fp-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019fp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000001ap-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.9d7adac608e85864p+4", LIT (0x1.9d7adac608e85864p+4), { LIT (0x7.ffffffffffffe638p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe638p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe638p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe64p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.9d7adac608e85p+4", LIT (0x1.9d7adac608e85p+4), { LIT (0x8.0000000000d8e56p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e56p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e56p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e57p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.9d7adac608e86p+4", LIT (0x1.9d7adac608e86p+4), { LIT (0x7.ffffffffff3b1b68p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b68p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b68p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b7p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.9d7adap+4", LIT (0x1.9d7adap+4), { LIT (0x8.001401a2efa2624p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2625p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2624p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2625p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.9d7adcp+4", LIT (0x1.9d7adcp+4), { LIT (0x7.ffe0488939957038p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe048893995704p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe0488939957038p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe048893995704p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.a8b12ep+4", LIT (0x1.a8b12ep+4), { LIT (0x4.001799b7b63bbef8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbfp-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbef8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbfp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.a8b12fc6e4891p+4", LIT (0x1.a8b12fc6e4891p+4), { LIT (0x4.0000000000cc9078p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc9078p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc9078p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc908p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.a8b12fc6e4892p+4", LIT (0x1.a8b12fc6e4892p+4), { LIT (0x3.fffffffffff81158p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff8115cp-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff81158p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff8115cp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.a8b13p+4", LIT (0x1.a8b13p+4), { LIT (0x3.fffd098f7c63a42cp-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a42cp-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a42cp-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a43p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.ap+4", LIT (0x1.ap+4), { LIT (0x9.425ff0e6f511d74p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d75p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d74p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d75p-984), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.bp+4", LIT (0x1.bp+4), { LIT (0x6.783c337e0e9d7e8p-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e88p-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e8p-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e88p-1060), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.cp+4", LIT (0x1.cp+4), { LIT (0x9.cd4b80875a8ec66p-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec66p-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec66p-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec67p-1140), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1.e33c9ep+0", LIT (0x1.e33c9ep+0), { LIT (0x1.f1cb04b622e6f4d4p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d6p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d4p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x2.844c2c5f7bba9c94p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c98p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c94p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffedf228afbd6ap-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6bp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6ap-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.ffffffffedf228ap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228bp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228ap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffeep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffeep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.36c504p+0", LIT (0x2.36c504p+0), { LIT (0x7.22d059993f3f46dp-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46dp-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46dp-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46d8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.56af04p+0", LIT (0x2.56af04p+0), { LIT (0x3.dbca059c7e73a12p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a124p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a12p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a124p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.586f1cp+0", LIT (0x2.586f1cp+0), { LIT (0x3.ba3ac339ed190204p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed190204p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed190204p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed190208p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7f8c8p+0", LIT (0x2.b7f8c8p+0), { LIT (0x7.e8b3a6276f03f778p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f778p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f778p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f78p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7f8cb76737d2af8p+0", LIT (0x2.b7f8cb76737d2af8p+0), { LIT (0x7.e8b308381e0015p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0015p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0015p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001508p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7f8cb76737d2afcp+0", LIT (0x2.b7f8cb76737d2afcp+0), { LIT (0x7.e8b308381e001448p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001448p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001448p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e00145p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7f8cb76737d2p+0", LIT (0x2.b7f8cb76737d2p+0), { LIT (0x7.e8b308381e020948p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02095p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e020948p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02095p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7f8cb76737d4p+0", LIT (0x2.b7f8cb76737d4p+0), { LIT (0x7.e8b308381dfc55cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c8p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.b7f8ccp+0", LIT (0x2.b7f8ccp+0), { LIT (0x7.e8b2efb679451a4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a48p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.dfb9b4p+0", LIT (0x2.dfb9b4p+0), { LIT (0x3.281c2d7e470e508p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5084p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e508p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5084p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2.f8646cp+0", LIT (0x2.f8646cp+0), { LIT (0x1.be98de114e174b5p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b5p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b5p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b52p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x1.328f5ec350e668d6p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d8p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d6p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffdbe4515faaeep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee1p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaeep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffffdbe4515fp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515fp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515fp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4516p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-4", LIT (0x2p-4), { LIT (0xd.c143cb94788ed17p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed18p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed17p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.ffffffffffffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3.e8p+8", LIT (0x3.e8p+8), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x3.ee6078p+0", LIT (0x3.ee6078p+0), { LIT (0x7.4334a54e1208ae18p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae18p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae18p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae2p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.729df6503422a0bcp-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bcp-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bcp-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bep-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.2p+0", LIT (0x4.2p+0), { LIT (0x1.74b179d1eba809f2p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f4p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4.b48498p+0", LIT (0x4.b48498p+0), { LIT (0x1.f57fab6c3db3ce7ep-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7ep-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7ep-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce8p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x4.237744ef4d79a9e8p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9e8p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9e8p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9fp-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.fb7c8a4401cd1c3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffb7c8a2befp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2befp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2befp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2bfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffffffffb7c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x1.b0c1a759f7738934p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738936p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738934p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738936p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x2.fd514cef7750e588p-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e588p-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e588p-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e58cp-14436), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.88fb08p+0", LIT (0x6.88fb08p+0), { LIT (0x7.23ff79ae0f25a13p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a138p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a13p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a138p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a893032db9052748p+4", LIT (0x6.a893032db9052748p+4), { LIT (0x3.fffffffffffe63cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffe63c8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffe63cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffffe63c8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a893032db905274p+4", LIT (0x6.a893032db905274p+4), { LIT (0x4.0000000000000dfp-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000dfp-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000dfp-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000df8p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a893032db9054p+4", LIT (0x6.a893032db9054p+4), { LIT (0x3.fffffffffad99d58p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffad99d6p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffad99d58p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.fffffffffad99d6p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a893032db905p+4", LIT (0x6.a893032db905p+4), { LIT (0x4.00000000082ae9dp-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9d8p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9dp-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9d8p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a89308p+4", LIT (0x6.a89308p+4), { LIT (0x3.feff49e314f6ecd8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.feff49e314f6ecd8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.feff49e314f6ecd8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x3.feff49e314f6ecep-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a893p+4", LIT (0x6.a893p+4), { LIT (0x4.00a9613ff522441p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff522441p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff522441p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff5224418p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a8a0561d8bbe8p+4", LIT (0x6.a8a0561d8bbe8p+4), { LIT (0x2.00000000021824d8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000021824d8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000021824d8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00000000021824ep-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a8a0561d8bbe9428p+4", LIT (0x6.a8a0561d8bbe9428p+4), { LIT (0x1.ffffffffffff4348p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff435p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff4348p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff435p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a8a0561d8bbe942p+4", LIT (0x6.a8a0561d8bbe942p+4), { LIT (0x2.000000000000186p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.0000000000001868p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.000000000000186p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.0000000000001868p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a8a0561d8bbecp+4", LIT (0x6.a8a0561d8bbecp+4), { LIT (0x1.fffffffffb6f7148p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f715p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f7148p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f715p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a8a058p+4", LIT (0x6.a8a058p+4), { LIT (0x1.ffcdcfd4f9515adp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515ad8p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515adp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515ad8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a8a05p+4", LIT (0x6.a8a05p+4), { LIT (0x2.00a2fdbcb5dc4898p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00a2fdbcb5dc48ap-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00a2fdbcb5dc4898p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x2.00a2fdbcb5dc48ap-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.a8p+4", LIT (0x6.a8p+4), { LIT (0x2.0b5b5b3bbf7d96a4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a8p-16372), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.aap+4", LIT (0x6.aap+4), { LIT (0x6.0b6ee9978p-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee998p-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee9978p-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee998p-16412), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.ap+4", LIT (0x6.ap+4), { LIT (0x5.028a2f1656a432dp-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432d8p-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432dp-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432d8p-16220), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x6.bp+4", LIT (0x6.bp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6.cp+4", LIT (0x6.cp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0x6p+0", LIT (0x6p+0), { LIT (0x1.8cf81557d20b61a6p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a8p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a6p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a8p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.fe8008p+0", LIT (0x7.fe8008p+0), { LIT (0xf.a33725bea2f7d7ap-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7bp-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7ap-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7bp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.fffd58p+0", LIT (0x7.fffd58p+0), { LIT (0xe.3cdfb051e694315p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e694315p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e694315p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e694316p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.fffd59e26af34p+0", LIT (0x7.fffd59e26af34p+0), { LIT (0xe.3cddffbbe88543bp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543bp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543cp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.fffd59e26af37bc8p+0", LIT (0x7.fffd59e26af37bc8p+0), { LIT (0xe.3cddffbbe84fa89p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa89p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa89p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa8ap-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.fffd59e26af37bcp+0", LIT (0x7.fffd59e26af37bcp+0), { LIT (0xe.3cddffbbe84fafcp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafcp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafcp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafdp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.fffd59e26af38p+0", LIT (0x7.fffd59e26af38p+0), { LIT (0xe.3cddffbbe84be02p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be02p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be02p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be03p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.fffd6p+0", LIT (0x7.fffd6p+0), { LIT (0xe.3cd883e02b14dafp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14dbp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14dafp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14dbp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7.ffff2p+0", LIT (0x7.ffff2p+0), { LIT (0xe.3b46e15ad97825dp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825dp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825dp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825ep-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x7p+0", LIT (0x7p+0), { LIT (0x3.2945026df4e62a48p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a4cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.c66b44ca40038p+0", LIT (0x8.c66b44ca40038p+0), { LIT (0x1.eb97b1f20867c35ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c36p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.c66b4p+0", LIT (0x8.c66b4p+0), { LIT (0x1.eb98546946cb2524p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2526p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2524p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2526p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8.c66b5p+0", LIT (0x8.c66b5p+0), { LIT (0x1.eb9635bc51eb7a94p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a96p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xe.3a7e2090befdbb5p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb6p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb5p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb6p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffff6f91457debp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457debp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457debp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457decp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.ffffffffff6f914p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f914p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f914p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f915p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.6f9d4dd116d6403p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d6403p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d6403p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d6404p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x9.31cdfp+0", LIT (0x9.31cdfp+0), { LIT (0x4.0004157f2239d72p-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d72p-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d72p-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d728p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x9.31cep+0", LIT (0x9.31cep+0), { LIT (0x3.ffff75b4a7f7172p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f7172p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f7172p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f71724p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x8.cc6a115f1fc6136p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6137p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6136p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6137p-124), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xap+0", LIT (0xap+0), { LIT (0xb.ec53f9545167ce9p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ceap-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ce9p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ceap-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xb.2274991033578p+0", LIT (0xb.2274991033578p+0), { LIT (0x1.c6479753dddf24p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2402p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf24p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2402p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xb.227499103357d84p+0", LIT (0xb.227499103357d84p+0), { LIT (0x1.c6479753ddd176a4p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a6p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a4p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a6p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xb.227499103358p+0", LIT (0xb.227499103358p+0), { LIT (0x1.c6479753ddcb4d8cp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8cp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8cp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8ep-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xb.22749p+0", LIT (0xb.22749p+0), { LIT (0x1.c648feeb672e8e56p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e58p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e56p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e58p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xb.2274ap+0", LIT (0xb.2274ap+0), { LIT (0x1.c646841c902106e6p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e8p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e6p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e8p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xb.acb72p+0", LIT (0xb.acb72p+0), { LIT (0x7.ee2d2ec5731504p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec5731504p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec5731504p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec573150408p-204), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x4.9f1b453178d049dp-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d8p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049dp-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xd.03d06p-4", LIT (0xd.03d06p-4), { LIT (0x3.fff91a7d782b0064p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b0064p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b0064p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b0068p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xd.28abfp-4", LIT (0xd.28abfp-4), { LIT (0x3.eaab96d5a2e294b8p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b8p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b8p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xd.361d9p-4", LIT (0xd.361d9p-4), { LIT (0x3.e2fa6064d5893478p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347cp-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d5893478p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xd.44cd3p-4", LIT (0xd.44cd3p-4), { LIT (0x3.da9f608f1dd7ee3p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee34p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xd.47425b3cafa48p-4", LIT (0xd.47425b3cafa48p-4), { LIT (0x3.d93aa84f87a9ffap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xd.47425p-4", LIT (0xd.47425p-4), { LIT (0x3.d93aaeadb64d00e8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xd.47426p-4", LIT (0xd.47426p-4), { LIT (0x3.d93aa59c8f5abb8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb84p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_intel96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_intel96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x8p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "-0", LIT (-0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x1p+0", LIT (-0x1p+0), { LIT (0x1.d7bb3d3a08445636p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08445636p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08445636p+0), ERRNO_UNCHANGED }, { LIT (0x1.d7bb3d3a08445638p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p+0", LIT (-0x2p+0), { LIT (0x1.fecd70a13caf1996p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf1998p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf1996p+0), ERRNO_UNCHANGED }, { LIT (0x1.fecd70a13caf1998p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p-16384", LIT (-0x2p-16384), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x2p-56", LIT (-0x2p-56), { LIT (0x1.000000000000024p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000242p+0), ERRNO_UNCHANGED }, { LIT (0x1.000000000000024p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000242p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x3p+0", LIT (-0x3p+0), { LIT (0x1.fffe8d6209afcbdcp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdep+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdcp+0), ERRNO_UNCHANGED }, { LIT (0x1.fffe8d6209afcbdep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p+0", LIT (-0x4p+0), { LIT (0x1.ffffffbdc88bb10ap+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10cp+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10ap+0), ERRNO_UNCHANGED }, { LIT (0x1.ffffffbdc88bb10cp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1024", LIT (-0x4p-1024), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-1076", LIT (-0x4p-1076), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-128", LIT (-0x4p-128), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16384", LIT (-0x4p-16384), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x4p-16448", LIT (-0x4p-16448), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x5p+0", LIT (-0x5p+0), { LIT (0x1.fffffffffe4f3e58p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e58p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffe4f3e5ap+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x6p+0", LIT (-0x6p+0), { LIT (0x1.fffffffffffffe72p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe74p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe72p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffe74p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.fffff8p-4", LIT (-0x7.fffff8p-4), { LIT (0x1.853f7a704b7be2d6p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d6p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d6p+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7a704b7be2d8p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.ffffffffffffcp-4", LIT (-0x7.ffffffffffffcp-4), { LIT (0x1.853f7ae0c76e8ddap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddap+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8ddcp+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7.ffffffffffffep-4", LIT (-0x7.ffffffffffffep-4), { LIT (0x1.853f7ae0c76e8f9cp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9cp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9cp+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e8f9ep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x7p+0", LIT (-0x7p+0), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p+0", LIT (-0x8p+0), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-152", LIT (-0x8p-152), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-16448", LIT (-0x8p-16448), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-4", LIT (-0x8p-4), { LIT (0x1.853f7ae0c76e915ep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915ep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e915ep+0), ERRNO_UNCHANGED }, { LIT (0x1.853f7ae0c76e916p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-8", LIT (-0x8p-8), { LIT (0x1.09062b22ee929bfcp+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfcp+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfcp+0), ERRNO_UNCHANGED }, { LIT (0x1.09062b22ee929bfep+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x8p-972", LIT (-0x8p-972), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1.0000000000000002p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0x9p+0", LIT (-0x9p+0), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xap+0", LIT (-0xap+0), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.ffffffffffff8p+1020", LIT (-0xf.ffffffffffff8p+1020), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffffffffffffp+16380", LIT (-0xf.fffffffffffffffp+16380), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "-0xf.fffffp+124", LIT (-0xf.fffffp+124), { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED }, { LIT (0x1.fffffffffffffffep+0), ERRNO_UNCHANGED }, { LIT (0x2p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "+0", LIT (0x0p+0), { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.2f644ep+0", LIT (0x1.2f644ep+0), { LIT (0x1.7fefc09137c9485cp-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485ep-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485cp-4), ERRNO_UNCHANGED }, { LIT (0x1.7fefc09137c9485ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.3ffcbep+0", LIT (0x1.3ffcbep+0), { LIT (0x1.3bd9679020a687bep-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687cp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687bep-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd9679020a687cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.3ffcbf39febb4p+0", LIT (0x1.3ffcbf39febb4p+0), { LIT (0x1.3bd962ebb773644ap-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644cp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644ap-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd962ebb773644cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.3ffccp+0", LIT (0x1.3ffccp+0), { LIT (0x1.3bd95ffe4e5561c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c6p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c4p-4), ERRNO_UNCHANGED }, { LIT (0x1.3bd95ffe4e5561c6p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.4p+0", LIT (0x1.4p+0), { LIT (0x1.3bcd133aa0ffbf9cp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9ep-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9cp-4), ERRNO_UNCHANGED }, { LIT (0x1.3bcd133aa0ffbf9ep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.514548p+0", LIT (0x1.514548p+0), { LIT (0xf.fbeadad5a51f774p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f775p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f774p-8), ERRNO_UNCHANGED }, { LIT (0xf.fbeadad5a51f775p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5166e0efc44a9dfcp+0", LIT (0x1.5166e0efc44a9dfcp+0), { LIT (0xf.f53d3d6dfa747dep-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dfp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dep-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747dfp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5166e0efc44a9dfep+0", LIT (0x1.5166e0efc44a9dfep+0), { LIT (0xf.f53d3d6dfa747d8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa747d9p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5166e0efc44a9p+0", LIT (0x1.5166e0efc44a9p+0), { LIT (0xf.f53d3d6dfa7745p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa77451p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa7745p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa77451p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5166e0efc44aap+0", LIT (0x1.5166e0efc44aap+0), { LIT (0xf.f53d3d6dfa74176p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74177p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74176p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d3d6dfa74177p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5166e2p+0", LIT (0x1.5166e2p+0), { LIT (0xf.f53d075aa92b1fp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1fp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1fp-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d075aa92b1f1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5166ep+0", LIT (0x1.5166ep+0), { LIT (0xf.f53d6d0e58d08f8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f8p-8), ERRNO_UNCHANGED }, { LIT (0xf.f53d6d0e58d08f9p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5289fep+0", LIT (0x1.5289fep+0), { LIT (0xf.bbc04428a3d30e7p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e7p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e7p-8), ERRNO_UNCHANGED }, { LIT (0xf.bbc04428a3d30e8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5cf2167efe9207d2p+0", LIT (0x1.5cf2167efe9207d2p+0), { LIT (0xd.cc22a7f131804eap-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ebp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804eap-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f131804ebp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5cf2167efe921p+0", LIT (0x1.5cf2167efe921p+0), { LIT (0xd.cc22a7f1317ede1p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede1p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede1p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f1317ede2p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5cf2167efe92p+0", LIT (0x1.5cf2167efe92p+0), { LIT (0xd.cc22a7f13181afp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af1p-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181afp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22a7f13181af1p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5cf216p+0", LIT (0x1.5cf216p+0), { LIT (0xd.cc22be4b9b325bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22be4b9b325bdp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.5cf218p+0", LIT (0x1.5cf218p+0), { LIT (0xd.cc22642cb5ab8dcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8dcp-8), ERRNO_UNCHANGED }, { LIT (0xd.cc22642cb5ab8ddp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.64dafap+0", LIT (0x1.64dafap+0), { LIT (0xc.766cbf61fd6480ap-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480bp-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480ap-8), ERRNO_UNCHANGED }, { LIT (0xc.766cbf61fd6480bp-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.65e31p+0", LIT (0x1.65e31p+0), { LIT (0xc.4bf9de451e5fcedp-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fceep-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fcedp-8), ERRNO_UNCHANGED }, { LIT (0xc.4bf9de451e5fceep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8a0c62p+0", LIT (0x1.8a0c62p+0), { LIT (0x7.8cde5963040180bp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b8p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180bp-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde5963040180b8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.8a0c64p+0", LIT (0x1.8a0c64p+0), { LIT (0x7.8cde235791e7d0d8p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0ep-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0d8p-8), ERRNO_UNCHANGED }, { LIT (0x7.8cde235791e7d0ep-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.9d7adac608e85862p+4", LIT (0x1.9d7adac608e85862p+4), { LIT (0x8.00000000000019fp-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019fp-972), ERRNO_UNCHANGED }, { LIT (0x8.00000000000019fp-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000001ap-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.9d7adac608e85864p+4", LIT (0x1.9d7adac608e85864p+4), { LIT (0x7.ffffffffffffe638p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe638p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe638p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffffffe64p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.9d7adac608e85p+4", LIT (0x1.9d7adac608e85p+4), { LIT (0x8.0000000000d8e56p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e56p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e56p-972), ERRNO_UNCHANGED }, { LIT (0x8.0000000000d8e57p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.9d7adac608e86p+4", LIT (0x1.9d7adac608e86p+4), { LIT (0x7.ffffffffff3b1b68p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b68p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b68p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffffffffff3b1b7p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.9d7adap+4", LIT (0x1.9d7adap+4), { LIT (0x8.001401a2efa2624p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2625p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2624p-972), ERRNO_UNCHANGED }, { LIT (0x8.001401a2efa2625p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.9d7adcp+4", LIT (0x1.9d7adcp+4), { LIT (0x7.ffe0488939957038p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe048893995704p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe0488939957038p-972), ERRNO_UNCHANGED }, { LIT (0x7.ffe048893995704p-972), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.a8b12ep+4", LIT (0x1.a8b12ep+4), { LIT (0x4.001799b7b63bbef8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbfp-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbef8p-1024), ERRNO_UNCHANGED }, { LIT (0x4.001799b7b63bbfp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.a8b12fc6e4891p+4", LIT (0x1.a8b12fc6e4891p+4), { LIT (0x4.0000000000cc9078p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc9078p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc9078p-1024), ERRNO_UNCHANGED }, { LIT (0x4.0000000000cc908p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.a8b12fc6e4892p+4", LIT (0x1.a8b12fc6e4892p+4), { LIT (0x3.fffffffffff81158p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff8115cp-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff81158p-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffff8115cp-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.a8b13p+4", LIT (0x1.a8b13p+4), { LIT (0x3.fffd098f7c63a42cp-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a42cp-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a42cp-1024), ERRNO_UNCHANGED }, { LIT (0x3.fffd098f7c63a43p-1024), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.ap+4", LIT (0x1.ap+4), { LIT (0x9.425ff0e6f511d74p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d75p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d74p-984), ERRNO_UNCHANGED }, { LIT (0x9.425ff0e6f511d75p-984), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.bp+4", LIT (0x1.bp+4), { LIT (0x6.783c337e0e9d7e8p-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e88p-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e8p-1060), ERRNO_UNCHANGED }, { LIT (0x6.783c337e0e9d7e88p-1060), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.cp+4", LIT (0x1.cp+4), { LIT (0x9.cd4b80875a8ec66p-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec66p-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec66p-1140), ERRNO_UNCHANGED }, { LIT (0x9.cd4b80875a8ec67p-1140), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1.e33c9ep+0", LIT (0x1.e33c9ep+0), { LIT (0x1.f1cb04b622e6f4d4p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d6p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d4p-8), ERRNO_UNCHANGED }, { LIT (0x1.f1cb04b622e6f4d6p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p+0", LIT (0x1p+0), { LIT (0x2.844c2c5f7bba9c94p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c98p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c94p-4), ERRNO_UNCHANGED }, { LIT (0x2.844c2c5f7bba9c98p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-100", LIT (0x1p-100), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-10000", LIT (0x1p-10000), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-20", LIT (0x1p-20), { LIT (0xf.fffedf228afbd6ap-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6bp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6ap-4), ERRNO_UNCHANGED }, { LIT (0xf.fffedf228afbd6bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-40", LIT (0x1p-40), { LIT (0xf.ffffffffedf228ap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228bp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228ap-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffedf228bp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-60", LIT (0x1p-60), { LIT (0xf.fffffffffffffedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffeep-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffedp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffeep-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x1p-600", LIT (0x1p-600), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.36c504p+0", LIT (0x2.36c504p+0), { LIT (0x7.22d059993f3f46dp-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46dp-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46dp-12), ERRNO_UNCHANGED }, { LIT (0x7.22d059993f3f46d8p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.56af04p+0", LIT (0x2.56af04p+0), { LIT (0x3.dbca059c7e73a12p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a124p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a12p-12), ERRNO_UNCHANGED }, { LIT (0x3.dbca059c7e73a124p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.586f1cp+0", LIT (0x2.586f1cp+0), { LIT (0x3.ba3ac339ed190204p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed190204p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed190204p-12), ERRNO_UNCHANGED }, { LIT (0x3.ba3ac339ed190208p-12), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7f8c8p+0", LIT (0x2.b7f8c8p+0), { LIT (0x7.e8b3a6276f03f778p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f778p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f778p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b3a6276f03f78p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7f8cb76737d2af8p+0", LIT (0x2.b7f8cb76737d2af8p+0), { LIT (0x7.e8b308381e0015p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0015p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e0015p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001508p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7f8cb76737d2afcp+0", LIT (0x2.b7f8cb76737d2afcp+0), { LIT (0x7.e8b308381e001448p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001448p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e001448p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e00145p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7f8cb76737d2p+0", LIT (0x2.b7f8cb76737d2p+0), { LIT (0x7.e8b308381e020948p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02095p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e020948p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381e02095p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7f8cb76737d4p+0", LIT (0x2.b7f8cb76737d4p+0), { LIT (0x7.e8b308381dfc55cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c8p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55cp-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b308381dfc55c8p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.b7f8ccp+0", LIT (0x2.b7f8ccp+0), { LIT (0x7.e8b2efb679451a4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a4p-16), ERRNO_UNCHANGED }, { LIT (0x7.e8b2efb679451a48p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.dfb9b4p+0", LIT (0x2.dfb9b4p+0), { LIT (0x3.281c2d7e470e508p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5084p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e508p-16), ERRNO_UNCHANGED }, { LIT (0x3.281c2d7e470e5084p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2.f8646cp+0", LIT (0x2.f8646cp+0), { LIT (0x1.be98de114e174b5p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b5p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b5p-16), ERRNO_UNCHANGED }, { LIT (0x1.be98de114e174b52p-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p+0", LIT (0x2p+0), { LIT (0x1.328f5ec350e668d6p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d8p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d6p-8), ERRNO_UNCHANGED }, { LIT (0x1.328f5ec350e668d8p-8), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16", LIT (0x2p-16), { LIT (0xf.ffdbe4515faaeep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee1p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaeep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffdbe4515faaee1p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-16384", LIT (0x2p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-36", LIT (0x2p-36), { LIT (0xf.fffffffdbe4515fp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515fp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4515fp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffdbe4516p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-4", LIT (0x2p-4), { LIT (0xd.c143cb94788ed17p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed18p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed17p-4), ERRNO_UNCHANGED }, { LIT (0xd.c143cb94788ed18p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x2p-56", LIT (0x2p-56), { LIT (0xf.ffffffffffffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbep-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffffffdbfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.e8p+8", LIT (0x3.e8p+8), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x3.ee6078p+0", LIT (0x3.ee6078p+0), { LIT (0x7.4334a54e1208ae18p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae18p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae18p-28), ERRNO_UNCHANGED }, { LIT (0x7.4334a54e1208ae2p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x3p+0", LIT (0x3p+0), { LIT (0x1.729df6503422a0bcp-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bcp-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bcp-16), ERRNO_UNCHANGED }, { LIT (0x1.729df6503422a0bep-16), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.2p+0", LIT (0x4.2p+0), { LIT (0x1.74b179d1eba809f2p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f2p-28), ERRNO_UNCHANGED }, { LIT (0x1.74b179d1eba809f4p-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4.b48498p+0", LIT (0x4.b48498p+0), { LIT (0x1.f57fab6c3db3ce7ep-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7ep-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce7ep-36), ERRNO_UNCHANGED }, { LIT (0x1.f57fab6c3db3ce8p-36), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p+0", LIT (0x4p+0), { LIT (0x4.237744ef4d79a9e8p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9e8p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9e8p-28), ERRNO_UNCHANGED }, { LIT (0x4.237744ef4d79a9fp-28), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1024", LIT (0x4p-1024), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-1076", LIT (0x4p-1076), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-12", LIT (0x4p-12), { LIT (0xf.fb7c8a4401cd1c3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c3p-4), ERRNO_UNCHANGED }, { LIT (0xf.fb7c8a4401cd1c4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-128", LIT (0x4p-128), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16384", LIT (0x4p-16384), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-16448", LIT (0x4p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-32", LIT (0x4p-32), { LIT (0xf.ffffffb7c8a2befp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2befp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2befp-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffb7c8a2bfp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x4p-52", LIT (0x4p-52), { LIT (0xf.fffffffffffb7c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c9p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c8p-4), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffb7c9p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x5p+0", LIT (0x5p+0), { LIT (0x1.b0c1a759f7738934p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738936p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738934p-40), ERRNO_UNCHANGED }, { LIT (0x1.b0c1a759f7738936p-40), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.4p+4", LIT (0x6.4p+4), { LIT (0x2.fd514cef7750e588p-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e588p-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e588p-14436), ERRNO_UNCHANGED }, { LIT (0x2.fd514cef7750e58cp-14436), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.88fb08p+0", LIT (0x6.88fb08p+0), { LIT (0x7.23ff79ae0f25a13p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a138p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a13p-68), ERRNO_UNCHANGED }, { LIT (0x7.23ff79ae0f25a138p-68), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a893032db9052748p+4", LIT (0x6.a893032db9052748p+4), { LIT (0x3.fffffffffffe63c4p-16384), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffe63c8p-16384), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffe63c4p-16384), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffffe63c8p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a893032db905274p+4", LIT (0x6.a893032db905274p+4), { LIT (0x4.0000000000000dfp-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000dfp-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000dfp-16384), ERRNO_UNCHANGED }, { LIT (0x4.0000000000000df8p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a893032db9054p+4", LIT (0x6.a893032db9054p+4), { LIT (0x3.fffffffffad99d5cp-16384), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffad99d5cp-16384), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffad99d5cp-16384), ERRNO_UNCHANGED }, { LIT (0x3.fffffffffad99d6p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a893032db905p+4", LIT (0x6.a893032db905p+4), { LIT (0x4.00000000082ae9dp-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9d8p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9dp-16384), ERRNO_UNCHANGED }, { LIT (0x4.00000000082ae9d8p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a89308p+4", LIT (0x6.a89308p+4), { LIT (0x3.feff49e314f6ecd8p-16384), ERRNO_UNCHANGED }, { LIT (0x3.feff49e314f6ecdcp-16384), ERRNO_UNCHANGED }, { LIT (0x3.feff49e314f6ecd8p-16384), ERRNO_UNCHANGED }, { LIT (0x3.feff49e314f6ecdcp-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a893p+4", LIT (0x6.a893p+4), { LIT (0x4.00a9613ff522441p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff522441p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff522441p-16384), ERRNO_UNCHANGED }, { LIT (0x4.00a9613ff5224418p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a8a0561d8bbe8p+4", LIT (0x6.a8a0561d8bbe8p+4), { LIT (0x2.00000000021824d8p-16384), ERRNO_UNCHANGED }, { LIT (0x2.00000000021824dcp-16384), ERRNO_UNCHANGED }, { LIT (0x2.00000000021824d8p-16384), ERRNO_UNCHANGED }, { LIT (0x2.00000000021824dcp-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a8a0561d8bbe9428p+4", LIT (0x6.a8a0561d8bbe9428p+4), { LIT (0x1.ffffffffffff434cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff435p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff434cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffffffffffff435p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a8a0561d8bbe942p+4", LIT (0x6.a8a0561d8bbe942p+4), { LIT (0x2.0000000000001864p-16384), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001864p-16384), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001864p-16384), ERRNO_UNCHANGED }, { LIT (0x2.0000000000001868p-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a8a0561d8bbecp+4", LIT (0x6.a8a0561d8bbecp+4), { LIT (0x1.fffffffffb6f714cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f714cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f714cp-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.fffffffffb6f715p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a8a058p+4", LIT (0x6.a8a058p+4), { LIT (0x1.ffcdcfd4f9515ad4p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515ad4p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515ad4p-16384), UNDERFLOW_EXCEPTION }, { LIT (0x1.ffcdcfd4f9515ad8p-16384), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a8a05p+4", LIT (0x6.a8a05p+4), { LIT (0x2.00a2fdbcb5dc489cp-16384), ERRNO_UNCHANGED }, { LIT (0x2.00a2fdbcb5dc489cp-16384), ERRNO_UNCHANGED }, { LIT (0x2.00a2fdbcb5dc489cp-16384), ERRNO_UNCHANGED }, { LIT (0x2.00a2fdbcb5dc48ap-16384), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.a8p+4", LIT (0x6.a8p+4), { LIT (0x2.0b5b5b3bbf7d96a4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a4p-16372), ERRNO_UNCHANGED }, { LIT (0x2.0b5b5b3bbf7d96a8p-16372), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.aap+4", LIT (0x6.aap+4), { LIT (0x6.0b6ee997cp-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee997cp-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee997cp-16412), UNDERFLOW_EXCEPTION }, { LIT (0x6.0b6ee998p-16412), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.ap+4", LIT (0x6.ap+4), { LIT (0x5.028a2f1656a432dp-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432d8p-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432dp-16220), ERRNO_UNCHANGED }, { LIT (0x5.028a2f1656a432d8p-16220), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.bp+4", LIT (0x6.bp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x6.cp+4", LIT (0x6.cp+4), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0x6p+0", LIT (0x6p+0), { LIT (0x1.8cf81557d20b61a6p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a8p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a6p-56), ERRNO_UNCHANGED }, { LIT (0x1.8cf81557d20b61a8p-56), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.fe8008p+0", LIT (0x7.fe8008p+0), { LIT (0xf.a33725bea2f7d7ap-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7bp-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7ap-100), ERRNO_UNCHANGED }, { LIT (0xf.a33725bea2f7d7bp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.fffd58p+0", LIT (0x7.fffd58p+0), { LIT (0xe.3cdfb051e694315p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e694315p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e694315p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cdfb051e694316p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.fffd59e26af34p+0", LIT (0x7.fffd59e26af34p+0), { LIT (0xe.3cddffbbe88543bp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543cp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543bp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe88543cp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.fffd59e26af37bc8p+0", LIT (0x7.fffd59e26af37bc8p+0), { LIT (0xe.3cddffbbe84fa89p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa89p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa89p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fa8ap-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.fffd59e26af37bcp+0", LIT (0x7.fffd59e26af37bcp+0), { LIT (0xe.3cddffbbe84fafcp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafcp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafcp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84fafdp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.fffd59e26af38p+0", LIT (0x7.fffd59e26af38p+0), { LIT (0xe.3cddffbbe84be02p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be02p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be02p-100), ERRNO_UNCHANGED }, { LIT (0xe.3cddffbbe84be03p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.fffd6p+0", LIT (0x7.fffd6p+0), { LIT (0xe.3cd883e02b14dafp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14dbp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14dafp-100), ERRNO_UNCHANGED }, { LIT (0xe.3cd883e02b14dbp-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7.ffff2p+0", LIT (0x7.ffff2p+0), { LIT (0xe.3b46e15ad97825dp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825dp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825dp-100), ERRNO_UNCHANGED }, { LIT (0xe.3b46e15ad97825ep-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x7p+0", LIT (0x7p+0), { LIT (0x3.2945026df4e62a48p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a48p-76), ERRNO_UNCHANGED }, { LIT (0x3.2945026df4e62a4cp-76), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.c66b44ca40038p+0", LIT (0x8.c66b44ca40038p+0), { LIT (0x1.eb97b1f20867c35ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c35ep-116), ERRNO_UNCHANGED }, { LIT (0x1.eb97b1f20867c36p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.c66b4p+0", LIT (0x8.c66b4p+0), { LIT (0x1.eb98546946cb2524p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2526p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2524p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb98546946cb2526p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8.c66b5p+0", LIT (0x8.c66b5p+0), { LIT (0x1.eb9635bc51eb7a94p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a94p-116), ERRNO_UNCHANGED }, { LIT (0x1.eb9635bc51eb7a96p-116), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p+0", LIT (0x8p+0), { LIT (0xe.3a7e2090befdbb5p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb6p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb5p-100), ERRNO_UNCHANGED }, { LIT (0xe.3a7e2090befdbb6p-100), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-152", LIT (0x8p-152), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-16448", LIT (0x8p-16448), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-28", LIT (0x8p-28), { LIT (0xf.fffff6f91457debp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457debp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457debp-4), ERRNO_UNCHANGED }, { LIT (0xf.fffff6f91457decp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-48", LIT (0x8p-48), { LIT (0xf.ffffffffff6f914p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f914p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f914p-4), ERRNO_UNCHANGED }, { LIT (0xf.ffffffffff6f915p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-8", LIT (0x8p-8), { LIT (0xf.6f9d4dd116d6403p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d6403p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d6403p-4), ERRNO_UNCHANGED }, { LIT (0xf.6f9d4dd116d6404p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x8p-972", LIT (0x8p-972), { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED }, { LIT (0xf.fffffffffffffffp-4), ERRNO_UNCHANGED }, { LIT (0x1p+0), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x9.31cdfp+0", LIT (0x9.31cdfp+0), { LIT (0x4.0004157f2239d72p-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d72p-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d72p-128), ERRNO_UNCHANGED }, { LIT (0x4.0004157f2239d728p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x9.31cep+0", LIT (0x9.31cep+0), { LIT (0x3.ffff75b4a7f7172p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f7172p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f7172p-128), ERRNO_UNCHANGED }, { LIT (0x3.ffff75b4a7f71724p-128), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0x9p+0", LIT (0x9p+0), { LIT (0x8.cc6a115f1fc6136p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6137p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6136p-124), ERRNO_UNCHANGED }, { LIT (0x8.cc6a115f1fc6137p-124), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xap+0", LIT (0xap+0), { LIT (0xb.ec53f9545167ce9p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ceap-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ce9p-152), ERRNO_UNCHANGED }, { LIT (0xb.ec53f9545167ceap-152), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xb.2274991033578p+0", LIT (0xb.2274991033578p+0), { LIT (0x1.c6479753dddf24p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2402p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf24p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753dddf2402p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xb.227499103357d84p+0", LIT (0xb.227499103357d84p+0), { LIT (0x1.c6479753ddd176a4p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a6p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a4p-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddd176a6p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xb.227499103358p+0", LIT (0xb.227499103358p+0), { LIT (0x1.c6479753ddcb4d8cp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8cp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8cp-184), ERRNO_UNCHANGED }, { LIT (0x1.c6479753ddcb4d8ep-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xb.22749p+0", LIT (0xb.22749p+0), { LIT (0x1.c648feeb672e8e56p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e58p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e56p-184), ERRNO_UNCHANGED }, { LIT (0x1.c648feeb672e8e58p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xb.2274ap+0", LIT (0xb.2274ap+0), { LIT (0x1.c646841c902106e6p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e8p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e6p-184), ERRNO_UNCHANGED }, { LIT (0x1.c646841c902106e8p-184), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xb.acb72p+0", LIT (0xb.acb72p+0), { LIT (0x7.ee2d2ec5731504p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec5731504p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec5731504p-204), ERRNO_UNCHANGED }, { LIT (0x7.ee2d2ec573150408p-204), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xcp-4", LIT (0xcp-4), { LIT (0x4.9f1b453178d049dp-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d8p-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049dp-4), ERRNO_UNCHANGED }, { LIT (0x4.9f1b453178d049d8p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xd.03d06p-4", LIT (0xd.03d06p-4), { LIT (0x3.fff91a7d782b0064p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b0064p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b0064p-4), ERRNO_UNCHANGED }, { LIT (0x3.fff91a7d782b0068p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xd.28abfp-4", LIT (0xd.28abfp-4), { LIT (0x3.eaab96d5a2e294b8p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b8p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294b8p-4), ERRNO_UNCHANGED }, { LIT (0x3.eaab96d5a2e294bcp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xd.361d9p-4", LIT (0xd.361d9p-4), { LIT (0x3.e2fa6064d5893478p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347cp-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d5893478p-4), ERRNO_UNCHANGED }, { LIT (0x3.e2fa6064d589347cp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xd.44cd3p-4", LIT (0xd.44cd3p-4), { LIT (0x3.da9f608f1dd7ee3p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee3p-4), ERRNO_UNCHANGED }, { LIT (0x3.da9f608f1dd7ee34p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xd.47425b3cafa48p-4", LIT (0xd.47425b3cafa48p-4), { LIT (0x3.d93aa84f87a9ffap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffap-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa84f87a9ffa4p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xd.47425p-4", LIT (0xd.47425p-4), { LIT (0x3.d93aaeadb64d00e8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00e8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aaeadb64d00ecp-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xd.47426p-4", LIT (0xd.47426p-4), { LIT (0x3.d93aa59c8f5abb8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb84p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb8p-4), ERRNO_UNCHANGED }, { LIT (0x3.d93aa59c8f5abb84p-4), ERRNO_UNCHANGED } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.ffffffffffff8p+1020", LIT (0xf.ffffffffffff8p+1020), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffffffffffffp+16380", LIT (0xf.fffffffffffffffp+16380), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
#if (TEST_COND_m68k96)
    { "0xf.fffffp+124", LIT (0xf.fffffp+124), { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x0p+0), UNDERFLOW_EXCEPTION | ERRNO_ERANGE }, { LIT (0x4p-16448), UNDERFLOW_EXCEPTION } },
#endif
  };

static void
erfc_test (void)
{
  ALL_RM_TEST (erfc, 0, erfc_test_data, RUN_TEST_LOOP_f_f, END);
}

static void
do_test (void)
{
  erfc_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */

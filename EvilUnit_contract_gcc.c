/*
 * This file is part of EvilUnit.
 *
 * EvilUnit is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the 
 * Free Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * EvilUnit is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR 
 * A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more 
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License along 
 * with EvilUnit. If not, see <http://www.gnu.org/licenses/>.
 */
/*
 * Copyright Jon Chesterfield. All rights reserved.
 */
#define CONTRACT_IMPLEMENTATION_LIBC_AVAILABLE __STDC_HOSTED__
#ifdef __clang__
#define CONTRACT_IMPLEMENTATION_CLANG_AVAILABLE 1
#define CONTRACT_IMPLEMENTATION_GCC_AVAILABLE 0
#elif defined(__GNUC__)
#define CONTRACT_IMPLEMENTATION_CLANG_AVAILABLE 0
#define CONTRACT_IMPLEMENTATION_GCC_AVAILABLE 1
#endif

#if !CONTRACT_IMPLEMENTATION_GCC_AVAILABLE

#define EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION EVILUNIT_CONTRACT_IMPLEMENTATION_NONE
#include "EvilUnit.h"
MODULE(evilunit_contract_gcc)
{
  CHECK(1);
}

#else

#define EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION EVILUNIT_CONTRACT_IMPLEMENTATION_GCC

#include "EvilUnit.h"

EVILUNIT_INLINE_ATTRIBUTE unsigned long depth(void)
{
  return *evilunit_contract_gcc_state_depth_pointer();
}

EVILUNIT_INLINE_ATTRIBUTE void depth_incr(void)
{
  ++(*evilunit_contract_gcc_state_depth_pointer());
}

EVILUNIT_INLINE_ATTRIBUTE void depth_decr(void)
{
  --(*evilunit_contract_gcc_state_depth_pointer());
}

static MODULE(evilunit_contract_explicit_gcc)
{
  enum {is_none = 0};
  CHECK(depth() == 0);

  TEST("setjmp without longjmp")
  {
    int x = 0;
    if (EVILUNIT_CONTRACT_GCC_SETJUMP_IMPL() == 0)
      {
        CHECK(depth() == 1);
        x = 1;
      }
    else
      {
        x = 0;
      }
    CHECK(x == 1);
    CHECK(depth() == 1);
    depth_decr();
    CHECK(depth() == 0);
  }

  TEST("setjmp with longjmp")
  {
    int x = 0;
    if (EVILUNIT_CONTRACT_GCC_SETJUMP_IMPL() == 0)
      {
        CHECK(depth() == 1);
        x = 1;
        evilunit_contract_gcc_longjump();
        x = 2;
      }
    else
      {
        CHECK(depth() == 0);
        x = 3;
      }
    CHECK(depth() == 0);

    CHECK(x == (is_none ? 2 : 3));
  }

  TEST("longjump without setjmp")
    {
      CHECK(depth() == 0);
      evilunit_contract_gcc_longjump();
      CHECK(depth() == 0);
    }

  CHECK(depth() == 0);
}

static MODULE(evilunit_contract_default_gcc)
{
  enum {is_none = 0};
  CHECK(depth() == 0);

  TEST("default setjmp without longjmp")
  {
    int x = 2;
    if (EVILUNIT_CONTRACT_SETJUMP() == 0)
      {
        CHECK(depth() == 1);
        x = 4;
      }
    else
      {
        x = 6;
      }
    CHECK(x == 4);
    CHECK(depth() == 1);
    depth_decr();
    CHECK(depth() == 0);
  }

  TEST("default setjmp with longjmp")
  {
    int x = 2;
    if (EVILUNIT_CONTRACT_SETJUMP() == 0)
      {
        CHECK(depth() == 1);
        x = 4;
        evilunit_contract_longjump();
        x = 6;
      }
    else
      {
        CHECK(depth() == 0);
        x = 8;
      }

    CHECK(x == (is_none ? 6 : 8));
    CHECK(depth() == 0);
  }

  TEST("default longjump without setjmp")
    {
      CHECK(depth() == 0);
      evilunit_contract_longjump();
      CHECK(depth() == 0);
    }

  CHECK(depth() == 0);
}

static MODULE(evilunit_contract_cross_gcc)
{
  enum {is_none = 0};
  CHECK(depth() == 0);

  TEST("cross default to explicit, default set")
  {
    int x = 2;
    if (EVILUNIT_CONTRACT_SETJUMP() == 0)
      {
        CHECK(depth() == 1);
        x = 4;
        evilunit_contract_gcc_longjump();
        x = 6;
      }
    else
      {
        CHECK(depth() == 0);
        x = 8;
      }

    CHECK(x == (is_none ? 6 : 8));
    CHECK(depth() == 0);
  }

  TEST("cross default to explicit, default jump")
  {
    int x = 2;
    if (EVILUNIT_CONTRACT_GCC_SETJUMP_IMPL() == 0)
      {
        CHECK(depth() == 1);
        x = 4;
        evilunit_contract_longjump();
        x = 6;
      }
    else
      {
        CHECK(depth() == 0);
        x = 8;
      }

    CHECK(x == (is_none ? 6 : 8));
    CHECK(depth() == 0);
  }

  CHECK(depth() == 0);
}

static MODULE(evilunit_contract_death_gcc)
{
  CHECK(depth() == 0);
  DEATH(evilunit_contract_longjump());
  LIVES(3 == 4);
}

MODULE(evilunit_contract_gcc)
{
  DEPENDS(evilunit_contract_explicit_gcc);
  DEPENDS(evilunit_contract_default_gcc);
  DEPENDS(evilunit_contract_cross_gcc);
  DEPENDS(evilunit_contract_death_gcc);
}

#endif


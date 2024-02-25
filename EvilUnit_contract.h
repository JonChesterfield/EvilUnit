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
#ifndef EVILUNIT_CONTRACT_HEADER
#define EVILUNIT_CONTRACT_HEADER

/*
 * Minimal contracts implementation, set up for integration with the associated
 * test framework. Defines functions (and one object) inline with the attribute
 * macro.
 */

/*
 * List of defined jump implementations, with "none" at 0
 */
#define EVILUNIT_CONTRACT_IMPLEMENTATION_NONE 0
#define EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC 1
#define EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG 2
#define EVILUNIT_CONTRACT_IMPLEMENTATION_GCC 3

#ifndef __STDC_VERSION__
#define EVILUNIT_INLINE
#else
#if __STDC_VERSION__ == 199409L
#define EVILUNIT_INLINE
#else
#define EVILUNIT_INLINE inline
#endif
#endif
#define EVILUNIT_INLINE_ATTRIBUTE static __attribute__((unused)) EVILUNIT_INLINE

/*
 * Expands to something with the semantic constraints of libc's setjmp
 */
#define EVILUNIT_CONTRACT_SETJUMP() EVILUNIT_CONTRACT_SETJUMP_IMPL()

/*
 * Calling this jumps to a frame set up by SETJUMP()
 */
EVILUNIT_INLINE_ATTRIBUTE
void evilunit_contract_longjump(void);

/*
 * Factor out the common construction. This would also permit an equivalent
 * transform based on exceptions instead of setjump
 */

EVILUNIT_INLINE_ATTRIBUTE
unsigned long* evilunit_contract_depth_pointer(void);

#define EVILUNIT_CONTRACT_FRAME(BLOCK, CONTINUATION) \
  if (EVILUNIT_CONTRACT_SETJUMP() == 0)              \
    {                                                \
      BLOCK;                                         \
      --(*evilunit_contract_depth_pointer());        \
    }                                                \
  else                                               \
    {                                                \
      CONTINUATION                                   \
    }

/*
 * Implementation follows.
 * Chooses a value for EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION if none given,
 * does various preprocess-scoped sanity checks, defines the above interface.
 */

/*
 * Choose a default EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION if not specified.
 * The default is the set of operations used if more specific ones are not
 * requested.
 * Prefers compiler builtins to libc.
 */

#ifndef EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION
#if defined(__has_builtin)
#if __has_builtin(__builtin_setjmp) && __has_builtin(__builtin_longjmp)
#ifdef __clang__
#define EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION \
  EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG
#elif defined(__GNUC__)
#define EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION \
  EVILUNIT_CONTRACT_IMPLEMENTATION_GCC
#endif
#endif
#endif
#endif

#ifndef EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION
#if __STDC_HOSTED__
#define EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION \
  EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC
#endif
#endif

#ifndef EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION
#define EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION \
  EVILUNIT_CONTRACT_IMPLEMENTATION_NONE
#endif

#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION !=   \
        EVILUNIT_CONTRACT_IMPLEMENTATION_NONE &&  \
    EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION !=   \
        EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC &&  \
    EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION !=   \
        EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG && \
    EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION !=   \
        EVILUNIT_CONTRACT_IMPLEMENTATION_GCC
#error "Unknown contract default implementation"
#endif

#define EVILUNIT_CONTRACT_IMPLEMENTATION_NONE_AVAILABLE 1
#define EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC_AVAILABLE __STDC_HOSTED__
#ifdef __clang__
#define EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG_AVAILABLE 1
#define EVILUNIT_CONTRACT_IMPLEMENTATION_GCC_AVAILABLE 0
#elif defined(__GNUC__)
#define EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG_AVAILABLE 0
#define EVILUNIT_CONTRACT_IMPLEMENTATION_GCC_AVAILABLE 1
#endif

/*
 * Any implementation can be enabled by defining the corresponding macro,
 * though things like asking for libc on a freestanding build will #error out
 * Otherwise only the one used for the default implementation is enabled
 */
#ifndef EVILUNIT_CONTRACT_IMPLEMENTATION_NONE_ENABLED
#define EVILUNIT_CONTRACT_IMPLEMENTATION_NONE_ENABLED \
  (EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION ==        \
   EVILUNIT_CONTRACT_IMPLEMENTATION_NONE)
#endif
#ifndef EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC_ENABLED
#define EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC_ENABLED \
  (EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION ==        \
   EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC)
#endif
#ifndef EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG_ENABLED
#define EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG_ENABLED \
  (EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION ==         \
   EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG)
#endif
#ifndef EVILUNIT_CONTRACT_IMPLEMENTATION_GCC_ENABLED
#define EVILUNIT_CONTRACT_IMPLEMENTATION_GCC_ENABLED \
  (EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION ==       \
   EVILUNIT_CONTRACT_IMPLEMENTATION_GCC)
#endif

#if EVILUNIT_CONTRACT_IMPLEMENTATION_NONE_ENABLED && \
    !EVILUNIT_CONTRACT_IMPLEMENTATION_NONE_AVAILABLE
#error "Trying to enable implementation none but it is not available"
#endif
#if EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC_ENABLED && \
    !EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC_AVAILABLE
#error "Trying to enable implementation libc but it is not available"
#endif
#if EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG_ENABLED && \
    !EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG_AVAILABLE
#error "Trying to enable implementation clang but it is not available"
#endif
#if EVILUNIT_CONTRACT_IMPLEMENTATION_GCC_ENABLED && \
    !EVILUNIT_CONTRACT_IMPLEMENTATION_GCC_AVAILABLE
#error "Trying to enable implementation gcc but it is not available"
#endif

/* __thread */
/* gcc accepts thread and common on a global, puts it in common */
/* clang is putting it in bss, and dropping common from the IR annotation */
/* clang seems happy to combine thread and weak, gcc does not */
/* tis a bug. */
/* todo, pick attributes more carefully for this global */

#define EVILUNIT_CONTRACT_GLOBAL_ATTRIBUTE __thread __attribute__((weak))

#if EVILUNIT_CONTRACT_IMPLEMENTATION_NONE_ENABLED

#define EVILUNIT_CONTRACT_NONE_SETJUMP_IMPL() \
  evilunit_contract_none_setjmp_argument()

struct evilunit_contract_none_state_type
{
  unsigned long depth;
};
EVILUNIT_CONTRACT_GLOBAL_ATTRIBUTE struct evilunit_contract_none_state_type
    evilunit_contract_none_state_value;

typedef void* evilunit_contract_none_state_pointer_type;
EVILUNIT_INLINE_ATTRIBUTE evilunit_contract_none_state_pointer_type
evilunit_contract_none_state(void)
{
  return 0;
}

EVILUNIT_INLINE_ATTRIBUTE
unsigned long* evilunit_contract_none_state_depth_pointer(void)
{
  return &evilunit_contract_none_state_value.depth;
}

EVILUNIT_INLINE_ATTRIBUTE
evilunit_contract_none_state_pointer_type
evilunit_contract_none_setjmp_argument(void)
{
  ++(*evilunit_contract_none_state_depth_pointer());
  return evilunit_contract_none_state();
}

EVILUNIT_INLINE_ATTRIBUTE
void evilunit_contract_none_longjump(void)
{
  if (*evilunit_contract_none_state_depth_pointer() == 1)
    {
      *evilunit_contract_none_state_depth_pointer() = 0;
    }
}
#endif

#if EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC_ENABLED

#include <setjmp.h>
#define EVILUNIT_CONTRACT_LIBC_SETJUMP_IMPL() \
  setjmp(*evilunit_contract_libc_setjmp_argument())

struct evilunit_contract_libc_state_type
{
  unsigned long depth;
  jmp_buf state;
};

EVILUNIT_CONTRACT_GLOBAL_ATTRIBUTE struct evilunit_contract_libc_state_type
    evilunit_contract_libc_state_value;

typedef jmp_buf* evilunit_contract_libc_state_pointer_type;
EVILUNIT_INLINE_ATTRIBUTE evilunit_contract_libc_state_pointer_type
evilunit_contract_libc_state(void)
{
  return &evilunit_contract_libc_state_value.state;
}

EVILUNIT_INLINE_ATTRIBUTE
unsigned long* evilunit_contract_libc_state_depth_pointer(void)
{
  return &evilunit_contract_libc_state_value.depth;
}

EVILUNIT_INLINE_ATTRIBUTE
evilunit_contract_libc_state_pointer_type
evilunit_contract_libc_setjmp_argument(void)
{
  ++(*evilunit_contract_libc_state_depth_pointer());
  return evilunit_contract_libc_state();
}

EVILUNIT_INLINE_ATTRIBUTE
void evilunit_contract_libc_longjump(void)
{
  if (*evilunit_contract_libc_state_depth_pointer() == 1)
    {
      *evilunit_contract_libc_state_depth_pointer() = 0;
      longjmp(*evilunit_contract_libc_state(), 1);
    }
}
#endif

#if EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG_ENABLED

#define EVILUNIT_CONTRACT_CLANG_SETJUMP_IMPL() \
  __builtin_setjmp(evilunit_contract_clang_setjmp_argument())
struct evilunit_contract_clang_state_type
{
  unsigned long depth;
  void* state[5];
};

EVILUNIT_CONTRACT_GLOBAL_ATTRIBUTE struct evilunit_contract_clang_state_type
    evilunit_contract_clang_state_value;

typedef void** evilunit_contract_clang_state_pointer_type;
EVILUNIT_INLINE_ATTRIBUTE evilunit_contract_clang_state_pointer_type
evilunit_contract_clang_state(void)
{
  return &evilunit_contract_clang_state_value.state[0];
}

EVILUNIT_INLINE_ATTRIBUTE
unsigned long* evilunit_contract_clang_state_depth_pointer(void)
{
  return &evilunit_contract_clang_state_value.depth;
}

EVILUNIT_INLINE_ATTRIBUTE
evilunit_contract_clang_state_pointer_type
evilunit_contract_clang_setjmp_argument(void)
{
  ++(*evilunit_contract_clang_state_depth_pointer());
  return evilunit_contract_clang_state();
}

EVILUNIT_INLINE_ATTRIBUTE
void evilunit_contract_clang_longjump(void)
{
  if (*evilunit_contract_clang_state_depth_pointer() == 1)
    {
      *evilunit_contract_clang_state_depth_pointer() = 0;
      __builtin_longjmp(evilunit_contract_clang_state(), 1);
    }
}
#endif

#if EVILUNIT_CONTRACT_IMPLEMENTATION_GCC_ENABLED

#define EVILUNIT_CONTRACT_GCC_SETJUMP_IMPL() \
  __builtin_setjmp(evilunit_contract_gcc_setjmp_argument())

struct evilunit_contract_gcc_state_type
{
  unsigned long depth;
  long int state[5];
};

EVILUNIT_CONTRACT_GLOBAL_ATTRIBUTE struct evilunit_contract_gcc_state_type
    evilunit_contract_gcc_state_value;

typedef long int* evilunit_contract_gcc_state_pointer_type;

EVILUNIT_INLINE_ATTRIBUTE evilunit_contract_gcc_state_pointer_type
evilunit_contract_gcc_state(void)
{
  return &evilunit_contract_gcc_state_value.state[0];
}

EVILUNIT_INLINE_ATTRIBUTE
unsigned long* evilunit_contract_gcc_state_depth_pointer(void)
{
  return &evilunit_contract_gcc_state_value.depth;
}

EVILUNIT_INLINE_ATTRIBUTE
evilunit_contract_gcc_state_pointer_type evilunit_contract_gcc_setjmp_argument(
    void)
{
  ++(*evilunit_contract_gcc_state_depth_pointer());
  return evilunit_contract_gcc_state();
}

EVILUNIT_INLINE_ATTRIBUTE
void evilunit_contract_gcc_longjump(void)
{
  if (*evilunit_contract_gcc_state_depth_pointer() == 1)
    {
      *evilunit_contract_gcc_state_depth_pointer() = 0;
      __builtin_longjmp(evilunit_contract_gcc_state(), 1);
    }
}
#endif

/*
 * Define accessors to the default implementation
 */

#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_NONE
#define EVILUNIT_CONTRACT_SETJUMP_IMPL() EVILUNIT_CONTRACT_NONE_SETJUMP_IMPL()
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC
#define EVILUNIT_CONTRACT_SETJUMP_IMPL() EVILUNIT_CONTRACT_LIBC_SETJUMP_IMPL()
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG
#define EVILUNIT_CONTRACT_SETJUMP_IMPL() EVILUNIT_CONTRACT_CLANG_SETJUMP_IMPL()
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_GCC
#define EVILUNIT_CONTRACT_SETJUMP_IMPL() EVILUNIT_CONTRACT_GCC_SETJUMP_IMPL()
#endif

#ifndef EVILUNIT_CONTRACT_SETJUMP_IMPL
#error "Missing definition EVILUNIT_CONTRACT_SETJUMP_IMPL"
#endif

EVILUNIT_INLINE_ATTRIBUTE
void evilunit_contract_longjump(void)
{
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_NONE
  evilunit_contract_none_longjump();
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC
  evilunit_contract_libc_longjump();
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG
  evilunit_contract_clang_longjump();
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_GCC
  evilunit_contract_gcc_longjump();
#endif
}

EVILUNIT_INLINE_ATTRIBUTE
unsigned long* evilunit_contract_depth_pointer(void)
{
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_NONE
  return evilunit_contract_none_state_depth_pointer();
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_LIBC
  return evilunit_contract_libc_state_depth_pointer();
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_CLANG
  return evilunit_contract_clang_state_depth_pointer();
#endif
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION == \
    EVILUNIT_CONTRACT_IMPLEMENTATION_GCC
  return evilunit_contract_gcc_state_depth_pointer();
#endif
}

#endif

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
#ifndef EVILUNIT_TEST_FRAMEWORK_HEADER
#define EVILUNIT_TEST_FRAMEWORK_HEADER

#if 0
/*
 * The user facing macros can be easily redefined here, e.g. #define SUITE(X) EVILUNIT_MODULE(X)
 */
#endif
#define CHECK(X) EVILUNIT_CHECK(X)
#define TEST(X) EVILUNIT_TEST(X)
#define DEPENDS(X) EVILUNIT_DEPENDS(X)
#define MODULE(X) EVILUNIT_MODULE(X)
#define MODULE_DECLARE(X) EVILUNIT_MODULE_DECLARE(X)
#define MAIN_MODULE() EVILUNIT_MAIN_MODULE()
#define DEATH(X) EVILUNIT_DEATH(X)
#define LIVES(X) EVILUNIT_LIVES(X)

#ifndef EVILUNIT_USE_STDIO
#define EVILUNIT_USE_STDIO 1
#endif

#ifndef EVILUNIT_HAVE_PRINTF
#define EVILUNIT_HAVE_PRINTF EVILUNIT_USE_STDIO
#endif

#if 0
/*
 * Implementation follows
 */
#endif

#if EVILUNIT_USE_STDIO
#ifdef EVILUNIT_PRECOMPILE_ONLY
#define EVILUNIT_TMP #include <stdio.h>
EVILUNIT_TMP
#undef EVILUNIT_TMP
#else
#include <stdio.h>
#endif
#endif

#if 0
/*
 * The default behaviour is execute_all_tests
 * argc is most likely to be 1 so execute_all_tests maps to this
 * Other constants are negative so that no number of arguments passed
 * on the command line can trigger one of these. 
 */
#endif

enum
{
  evilunit_traverse_command_execute_all_tests = 1,
  evilunit_traverse_command_get_number_of_tests = -1,
  evilunit_traverse_command_get_number_of_dependencies = -2,
  evilunit_traverse_command_get_test_name_from_number = -3,
  evilunit_traverse_command_get_dependency_from_number = -4,
  evilunit_traverse_command_run_specific_test = -5,
  evilunit_traverse_command_get_module_name = -6,
  evilunit_traverse_command_get_module_filename = -7,
  evilunit_traverse_command_store_result = -8,
  evilunit_traverse_command_retrieve_result = -9,
  evilunit_traverse_command_mark_colour_white = -10,
  evilunit_traverse_command_mark_colour_grey = -11,
  evilunit_traverse_command_is_colour_white = -12,
  evilunit_traverse_command_is_colour_grey = -13
};
struct evilunit_module_state;
typedef int (*evilunit_node_type)(int instruction, char **state);
typedef struct evilunit_test_state (*evilunit_visit)(evilunit_node_type);

typedef struct evilunit_test_state (*evilunit_reduce)(
    struct evilunit_test_state, struct evilunit_test_state);

struct evilunit_test_state
{
  const char *check_string;    /* e.g. "oh no!" */
  const char *testname_string; /* e.g. "foobar" */
  const char *module_string;   /* e.g. "my_module" */
  int result;
  int line;
  int number_failure;
  int number_success;
};

enum evilunit_command
{
  uninitialised = 0,
  how_many_tests,
  how_many_dependencies,
  run_one,
  get_name,
  get_dependency
};
struct evilunit_module_state
{
  struct evilunit_test_state test; /* store the result */
  enum evilunit_command Q;         /* what shall we do? */
  unsigned int test_counter;       /* count some tests */
  unsigned int dependency_counter; /* count some dependencies */
  unsigned int numeric_parameter;  /* reused for various things */
  const char *string_parameter;
  evilunit_node_type traverse_parameter;
};

enum
{
  evilunit_test_result_init = 0,
  evilunit_test_result_pass = 1,
  evilunit_test_result_fail = 2
};

#ifdef __cplusplus
extern "C"
{
#endif

  static int evilunit_implementation_test(struct evilunit_module_state *state,
                                          const char *blockname);
  static void evilunit_implementation_depends(
      struct evilunit_module_state *state, evilunit_node_type proposed);
  static void evilunit_implementation_check(struct evilunit_module_state *S,
                                            int check_resolved_to_this,
                                            int line, const char *check_string);
  static void evilunit_implementation_set_string_parameter(
      struct evilunit_module_state *S, const char *str);
  static void evilunit_implementation_set_numeric_parameter(
      struct evilunit_module_state *S, unsigned int num);
  static int evilunit_implementation(evilunit_node_type root);

#ifdef __cplusplus
}
#endif

#define EVILUNIT_CONCAT(a__, b__) EVILUNIT_CONCAT_DO(a__, b__)
#define EVILUNIT_CONCAT_DO(a__, b__) a__##b__
#define EVILUNIT_MODULE_MANGLE(MODNAME) EVILUNIT_CONCAT(evilunit_node_, MODNAME)
#define EVILUNIT_MODULE_DECLARE(MODNAME) \
  int EVILUNIT_MODULE_MANGLE(MODNAME)(int instruction, char **vstate)

#ifdef __cplusplus
#define EVILUNIT_CAST(TYPE, VARIABLE) reinterpret_cast<TYPE>(VARIABLE)
#else
#define EVILUNIT_CAST(TYPE, VARIABLE) (TYPE)(VARIABLE)
#endif

int evilunit_implementation_test(struct evilunit_module_state *state,
                                 const char *blockname)
{
  state->test_counter++;
  {
    int is_matching_test_number =
        (state->numeric_parameter == state->test_counter);

    if (state->Q == run_one)
      {
        if (is_matching_test_number)
          {
            state->string_parameter = blockname;
            state->test.testname_string = blockname;
          }
        return is_matching_test_number;
      }

    if (state->Q == get_name)
      {
        if (is_matching_test_number)
          {
            state->string_parameter = blockname;
            state->test.testname_string = blockname;
          }
      }
  }
  return 0;
}

void evilunit_implementation_depends(struct evilunit_module_state *state,
                                     evilunit_node_type proposed)
{
  state->dependency_counter++;
  if (state->Q == get_dependency)
    {
      if (state->numeric_parameter == state->dependency_counter)
        {
          state->traverse_parameter = proposed;
        }
    }
}

void evilunit_implementation_check(struct evilunit_module_state *S,
                                   int check_resolved_to_this, int line,
                                   const char *check_string)
{
  struct evilunit_test_state *ongoing = &(S->test);

  if (check_resolved_to_this)
    {
      ongoing->number_success += 1;
    }
  else
    {
      ongoing->number_failure += 1;
    }

  if (ongoing->result == evilunit_test_result_fail)
    {
      return;
    }

  ongoing->result = (check_resolved_to_this) ? evilunit_test_result_pass
                                             : evilunit_test_result_fail;
  ongoing->line = line;
  ongoing->check_string = check_string;
  ongoing->testname_string = S->string_parameter;
  return;
}

void evilunit_implementation_set_string_parameter(
    struct evilunit_module_state *S, const char *str)
{
  S->string_parameter = str;
  return;
}

void evilunit_implementation_set_numeric_parameter(
    struct evilunit_module_state *S, unsigned int num)
{
  S->numeric_parameter = num;
  return;
}

/*
 * Queries
 */

static struct evilunit_test_state evilunit_make_test_state(
    const char *module_name)
{
  struct evilunit_test_state retval;
  retval.check_string = "";
  retval.testname_string = module_name;
  retval.module_string = module_name;
  retval.result = evilunit_test_result_init;
  retval.line = 0;
  retval.number_failure = 0;
  retval.number_success = 0;
  return retval;
}

static void evilunit_store_test_state(
    struct evilunit_module_state const *const module,
    struct evilunit_test_state *test)
{
  test->result = module->test.result;
  test->line = module->test.line;
  test->check_string = module->test.check_string;
  test->testname_string = module->test.testname_string;
  test->module_string = module->test.module_string;
  test->number_failure = module->test.number_failure;
  test->number_success = module->test.number_success;
}

static void evilunit_retrieve_test_state(
    struct evilunit_test_state const *const test,
    struct evilunit_module_state *module)
{
  module->test.result = test->result;
  module->test.line = test->line;
  module->test.check_string = test->check_string;
  module->test.testname_string = test->testname_string;
  module->test.module_string = test->module_string;
  module->test.number_failure = test->number_failure;
  module->test.number_success = test->number_success;
}

static const char *evilunit_query_module_name(evilunit_node_type node);
static const char *evilunit_query_module_filename(evilunit_node_type node);

static void evilunit_clear_module_state(evilunit_node_type node,
                                        struct evilunit_module_state *module)
{
  const char *module_name = evilunit_query_module_name(node);
  module->test = evilunit_make_test_state(module_name);
  module->Q = uninitialised;
  module->test_counter = 0;
  module->dependency_counter = 0;
  module->numeric_parameter = 0;
  module->string_parameter = module_name;
  module->traverse_parameter = node;
}

static void evilunit_call_state_only(evilunit_node_type node, int instruction,
                                     struct evilunit_module_state *S)
{
  (void)node(instruction, EVILUNIT_CAST(char **, S));
}

static const char *evilunit_query_module_name(evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_get_module_name;
  struct evilunit_module_state S;
  (void)node(instruction, EVILUNIT_CAST(char **, (&S)));
  return S.string_parameter;
}

static const char *evilunit_query_module_filename(evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_get_module_filename;
  struct evilunit_module_state S;
  (void)node(instruction, EVILUNIT_CAST(char **, (&S)));
  return S.string_parameter;
}

static evilunit_node_type evilunit_query_dependency(evilunit_node_type node,
                                                    unsigned int dependency)
{
  int instruction = evilunit_traverse_command_get_dependency_from_number;
  struct evilunit_module_state S;
  evilunit_node_type retval = node;
  evilunit_clear_module_state(node, &S);
  S.Q = get_dependency;
  S.numeric_parameter = dependency;
  if (dependency > 0)
    {
      evilunit_call_state_only(node, instruction, &S);
      retval = S.traverse_parameter;
    }
  return retval;
}

static unsigned int evilunit_query_number_of_tests(evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_get_number_of_tests;
  struct evilunit_module_state S;
  evilunit_clear_module_state(node, &S);
  S.Q = how_many_tests;
  evilunit_call_state_only(node, instruction, &S);
  return S.test_counter;
}

static unsigned int evilunit_query_number_of_dependencies(
    evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_get_number_of_dependencies;
  struct evilunit_module_state S;
  evilunit_clear_module_state(node, &S);
  S.Q = how_many_dependencies;
  evilunit_call_state_only(node, instruction, &S);
  return S.dependency_counter;
}

static struct evilunit_test_state evilunit_query_result(evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_retrieve_result;
  struct evilunit_module_state S;
  evilunit_call_state_only(node, instruction, &S);
  return S.test;
}

static void evilunit_store_result(evilunit_node_type node,
                                  struct evilunit_test_state result)
{
  int instruction = evilunit_traverse_command_store_result;
  struct evilunit_module_state S;
  S.test = result;
  evilunit_call_state_only(node, instruction, &S);
}

static struct evilunit_test_state evilunit_execute_specific_test(
    evilunit_node_type node, unsigned int test)
{
  int instruction = evilunit_traverse_command_run_specific_test;
  struct evilunit_module_state S;
  evilunit_clear_module_state(node, &S);
  S.Q = run_one;
  S.numeric_parameter = test;
  evilunit_call_state_only(node, instruction, &S);
  if (S.test.result == evilunit_test_result_init)
    {
      S.test.result = evilunit_test_result_pass;
    }
  return S.test;
}

/*
 * Graph traversal
 */

static void evilunit_execute_mark_white(evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_mark_colour_white;
  struct evilunit_module_state S;
  evilunit_call_state_only(node, instruction, &S);
}

static void evilunit_execute_mark_grey(evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_mark_colour_grey;
  struct evilunit_module_state S;
  evilunit_call_state_only(node, instruction, &S);
}

static int evilunit_query_is_grey(evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_is_colour_grey;
  struct evilunit_module_state S;
  (void)node(instruction, EVILUNIT_CAST(char **, (&S)));
  return S.numeric_parameter == 1;
}

static struct evilunit_test_state evilunit_walk_graph_recursive(
    evilunit_node_type node, evilunit_visit visitor, evilunit_reduce reducor)
{
  unsigned int numdeps = evilunit_query_number_of_dependencies(node);
  unsigned int i = 0;
  evilunit_node_type dependency = node;
  struct evilunit_test_state retval =
      evilunit_make_test_state(evilunit_query_module_name(node));
  struct evilunit_test_state result =
      evilunit_make_test_state(evilunit_query_module_name(node));

  evilunit_execute_mark_grey(node);

  for (i = 1; i <= numdeps; i++)
    {
      dependency = evilunit_query_dependency(node, i);
      if (evilunit_query_is_grey(dependency))
        {
          /* In a cycle, don't walk down this edge */
          continue;
        }
      result = evilunit_walk_graph_recursive(dependency, visitor, reducor);
      retval = reducor(retval, result);
    }

  /* Finally visit ourself */
  result = visitor(node);
  retval = reducor(retval, result);

  /* And mark as no longer grey */
  evilunit_execute_mark_white(node);
  return retval;
}

static struct evilunit_test_state evilunit_walk_graph(evilunit_node_type node,
                                                      evilunit_visit visitor,
                                                      evilunit_reduce reducor)
{
  struct evilunit_test_state res =
      evilunit_walk_graph_recursive(node, visitor, reducor);
  res = reducor(evilunit_query_result(node), res);
  return res;
}

static struct evilunit_test_state evilunit_nop_reducor(
    struct evilunit_test_state previous, struct evilunit_test_state current)
{
  struct evilunit_test_state nop = evilunit_make_test_state("nop");
  (void)previous;
  (void)current;
  return nop;
}

static struct evilunit_test_state evilunit_combine_test_state(
    struct evilunit_test_state previous, struct evilunit_test_state current)
{
  if ((previous.number_failure == 0) &&
      (current.result == evilunit_test_result_fail))
    {
      previous.check_string = current.check_string;
      previous.line = current.line;
      previous.testname_string = current.testname_string;
    }

  previous.number_failure += current.number_failure;
  previous.number_success += current.number_success;
  return previous;
}

static struct evilunit_test_state evilunit_execute_all_tests(
    evilunit_node_type node)
{
  unsigned int numtests = evilunit_query_number_of_tests(node);
  unsigned int i = 0;
  struct evilunit_test_state result =
      evilunit_make_test_state(evilunit_query_module_name(node));

  struct evilunit_test_state retval =
      evilunit_make_test_state(evilunit_query_module_name(node));

  struct evilunit_test_state already_executed = evilunit_query_result(node);
  if (already_executed.result != evilunit_test_result_init)
    {
      return already_executed;
    }

  /* The zeroth test executes the module in isolation */
  for (i = 0; i <= numtests; i++)
    {
      result = evilunit_execute_specific_test(node, i);
      retval = evilunit_combine_test_state(retval, result);
    }

  evilunit_store_result(node, retval);

  return retval;
}

static struct evilunit_test_state evilunit_collapse_visitor(
    evilunit_node_type node)
{
  struct evilunit_test_state result = evilunit_query_result(node);
  if (result.number_failure == 0)
    {
      struct evilunit_test_state erasure =
          evilunit_make_test_state(evilunit_query_module_name(node));
      evilunit_store_result(node, erasure);
    }

  return result;
}

static struct evilunit_test_state evilunit_collapse_reducor(
    struct evilunit_test_state previous, struct evilunit_test_state current)
{
  struct evilunit_test_state result = previous;

  if ((current.number_failure == 0) && (current.number_success > 0))
    {
      result.number_failure += current.number_failure;
      result.number_success += current.number_success;
    }

  return result;
}

#if EVILUNIT_HAVE_PRINTF
#define EVILUNIT_ANSI_COLOUR_RED "\x1b[31m"
#define EVILUNIT_ANSI_COLOUR_GREEN "\x1b[32m"
#define EVILUNIT_ANSI_COLOUR_RESET "\x1b[0m"
static struct evilunit_test_state evilunit_output_visitor(
    evilunit_node_type node)
{
  struct evilunit_test_state state = evilunit_query_result(node);
  const char *modulename = state.module_string;
  const char *filename = evilunit_query_module_filename(node);
  int have_failure =
      state.number_failure > 0 || state.result == evilunit_test_result_fail;

  int number_checks = state.number_failure + state.number_success;
  if (number_checks > 0)
    {
      if (!have_failure)
        {
          printf("[ " EVILUNIT_ANSI_COLOUR_GREEN
                 "Pass" EVILUNIT_ANSI_COLOUR_RESET " ] %u/%u %s\n",
                 state.number_failure, number_checks, modulename);
        }
      else
        {
          /* format filename:line is understood by emacs compilation buffer */
          printf("[ " EVILUNIT_ANSI_COLOUR_RED "Fail" EVILUNIT_ANSI_COLOUR_RESET
                 " ] %u/%u %s %s:%u \"%s\" %s\n",
                 state.number_failure, number_checks, modulename, filename,
                 state.line, state.testname_string, state.check_string);
        }
    }

  return state;
}
#undef EVILUNIT_ANSI_COLOUR_RED
#undef EVILUNIT_ANSI_COLOUR_GREEN
#undef EVILUNIT_ANSI_COLOUR_RESET

static void evilunit_blat_output(evilunit_node_type root)
{
  struct evilunit_test_state res =
      evilunit_walk_graph(root, evilunit_output_visitor, evilunit_nop_reducor);
  (void)res;
}

#else /* ! EVILUNIT_HAVE_PRINTF */
static void evilunit_blat_output(evilunit_node_type root)
{
  struct evilunit_test_state nop = evilunit_make_test_state("nop");
  /* Avoid unused-function warnings with no STDIO */
  (void)evilunit_query_module_filename(root);
  (void)evilunit_nop_reducor(nop, nop);
}
#endif

static struct evilunit_test_state evilunit_execute_everything(
    evilunit_node_type node)
{
  return evilunit_walk_graph(node, evilunit_execute_all_tests,
                             evilunit_combine_test_state);
}

static void evilunit_collapse_graph(evilunit_node_type root)
{
  struct evilunit_test_state res = evilunit_walk_graph(
      root, evilunit_collapse_visitor, evilunit_collapse_reducor);
  evilunit_store_result(root, res);
}

/*
 * Evaluate from entry node
 */

static int evilunit_implementation(evilunit_node_type root)
{
  struct evilunit_test_state result = evilunit_execute_everything(root);
  evilunit_collapse_graph(root);
  evilunit_blat_output(root);
  return result.number_failure;
}

#if 0
/*
 * The primary macros - these rewrite the user's code.
 */
#endif

#define EVILUNIT_CHECK(X) \
  evilunit_implementation_check(evilunit_internal_state, (X), __LINE__, #X)

#define EVILUNIT_TEST(blockname) \
  if (evilunit_implementation_test(evilunit_internal_state, blockname))

/* New, undocumented - dig out the name from the surrounding TEST("") or
 * MODULE() */
#define EVILUNIT_CURRENT_TEST_NAME() \
  evilunit_internal_state->test.testname_string

/*
 * Include the contract header if available and implement DEATH() using it
 * death tests need to compile to no code if longjmp is unavailable
 *
 */

#define EVILUNIT_DEATH(X) \
  do                      \
    {                     \
    }                     \
  while (0)
#define EVILUNIT_LIVES(X) \
  do                      \
    {                     \
    }                     \
  while (0)

#if __has_include("EvilUnit_contract.h")
#include "EvilUnit_contract.h"
#if EVILUNIT_CONTRACT_DEFAULT_IMPLEMENTATION != \
    EVILUNIT_CONTRACT_IMPLEMENTATION_NONE

#undef EVILUNIT_DEATH
#undef EVILUNIT_LIVES

#define EVILUNIT_DEATH(X)                                                    \
  do                                                                         \
    {                                                                        \
      int evilunit_contract_reached_continuation = 0;                        \
      EVILUNIT_CONTRACT_FRAME((void)(X);                                     \
                              evilunit_contract_reached_continuation = 0;    \
                              , evilunit_contract_reached_continuation = 1;) \
      evilunit_implementation_check(evilunit_internal_state,                 \
                                    evilunit_contract_reached_continuation,  \
                                    __LINE__, #X);                           \
    }                                                                        \
  while (0)

#define EVILUNIT_LIVES(X)                                                    \
  do                                                                         \
    {                                                                        \
      int evilunit_contract_reached_continuation = 0;                        \
      EVILUNIT_CONTRACT_FRAME((void)(X);                                     \
                              evilunit_contract_reached_continuation = 1;    \
                              , evilunit_contract_reached_continuation = 0;) \
      evilunit_implementation_check(evilunit_internal_state,                 \
                                    evilunit_contract_reached_continuation,  \
                                    __LINE__, #X);                           \
    }                                                                        \
  while (0)

#endif
#endif

#if 0
/* Declaration and call within a block to support C89 */
#endif
#define EVILUNIT_DEPENDS(X)                                        \
  {                                                                \
    EVILUNIT_MODULE_DECLARE(X);                                    \
    evilunit_implementation_depends(evilunit_internal_state,       \
                                    &(EVILUNIT_MODULE_MANGLE(X))); \
  }                                                                \
  (void)0

#if 0
/* get_simt_lane returns value in [0 EVILUNIT_SIMT_WIDTH), defaults to 0/1*/
#endif

#ifdef __AMDGCN__
#define EVILUNIT_SIMT_WIDTH __AMDGCN_WAVEFRONT_SIZE
static unsigned evilunit_get_simt_lane(void)
{
#if EVILUNIT_SIMT_WIDTH == 64
  return __builtin_amdgcn_mbcnt_hi(~0u, __builtin_amdgcn_mbcnt_lo(~0u, 0u));
#elif EVILUNIT_SIMT_WIDTH == 32
  return __builtin_amdgcn_mbcnt_lo(~0u, 0u);
#else
#error "Unimplemented get_simt_lane on amdgcn"
#endif
}
#endif

#ifndef EVILUNIT_SIMT_WIDTH
#define EVILUNIT_SIMT_WIDTH 1
static unsigned evilunit_get_simt_lane(void) { return 0; }
#endif

/* Avoid unused parameter warning on empty module */
#ifndef __has_attribute
#define __has_attribute(x) 0
#endif

#ifdef __clang__
#if __has_attribute(maybe_unused)
#define EVILUNIT_MAYBE_UNUSED __attribute__((maybe_unused))
#endif
#endif

#ifndef EVILUNIT_MAYBE_UNUSED
#define EVILUNIT_MAYBE_UNUSED
#endif

#define EVILUNIT_MODULE(MODNAME)                                               \
  EVILUNIT_MODULE_DECLARE(MODNAME);                                            \
  static void EVILUNIT_CONCAT(module_, MODNAME)(struct evilunit_module_state * \
                                                evilunit_internal_state);      \
  EVILUNIT_MODULE_DECLARE(MODNAME)                                             \
  {                                                                            \
    struct evilunit_module_state *state =                                      \
        EVILUNIT_CAST(struct evilunit_module_state *, vstate);                 \
    static struct evilunit_test_state stored_test_state[EVILUNIT_SIMT_WIDTH];  \
    static int stored_node_colour[EVILUNIT_SIMT_WIDTH];                        \
    enum                                                                       \
    {                                                                          \
      white_colour = 0,                                                        \
      grey_colour = 1                                                          \
    };                                                                         \
    const unsigned lane = evilunit_get_simt_lane();                            \
    switch (instruction)                                                       \
      {                                                                        \
        case evilunit_traverse_command_get_number_of_tests:                    \
        case evilunit_traverse_command_get_number_of_dependencies:             \
        case evilunit_traverse_command_get_dependency_from_number:             \
        case evilunit_traverse_command_get_test_name_from_number:              \
        case evilunit_traverse_command_run_specific_test:                      \
          {                                                                    \
            EVILUNIT_CONCAT(module_, MODNAME)(state);                          \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_get_module_name:                        \
          {                                                                    \
            evilunit_implementation_set_string_parameter(state, #MODNAME);     \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_get_module_filename:                    \
          {                                                                    \
            evilunit_implementation_set_string_parameter(state, __FILE__);     \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_store_result:                           \
          {                                                                    \
            evilunit_store_test_state(state, &stored_test_state[lane]);        \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_retrieve_result:                        \
          {                                                                    \
            evilunit_retrieve_test_state(&stored_test_state[lane], state);     \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_mark_colour_white:                      \
          {                                                                    \
            stored_node_colour[lane] = white_colour;                           \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_mark_colour_grey:                       \
          {                                                                    \
            stored_node_colour[lane] = grey_colour;                            \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_is_colour_white:                        \
          {                                                                    \
            evilunit_implementation_set_numeric_parameter(                     \
                state, (stored_node_colour[lane] == white_colour) ? 1 : 0);    \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_is_colour_grey:                         \
          {                                                                    \
            evilunit_implementation_set_numeric_parameter(                     \
                state, (stored_node_colour[lane] == grey_colour) ? 1 : 0);     \
            break;                                                             \
          }                                                                    \
        case evilunit_traverse_command_execute_all_tests:                      \
        default:                                                               \
          {                                                                    \
            return evilunit_implementation(EVILUNIT_MODULE_MANGLE(MODNAME));   \
          }                                                                    \
      }                                                                        \
    return 0;                                                                  \
  }                                                                            \
  void EVILUNIT_CONCAT(                                                        \
      module_, MODNAME)(EVILUNIT_MAYBE_UNUSED struct evilunit_module_state *   \
                        evilunit_internal_state)

static MODULE(create_a_module_or_delete_the_include_to_silence_warning)
{
  DEPENDS(create_a_module_or_delete_the_include_to_silence_warning);
  TEST("")
  {
    CHECK(evilunit_test_result_init == 0);
    CHECK(evilunit_test_result_pass == 1);
    CHECK(evilunit_test_result_fail == 2);
  }
}

#ifdef __cplusplus
#define EVILUNIT_MAIN_MODULE()                          \
  extern "C"                                            \
  {                                                     \
    EVILUNIT_MODULE_DECLARE(main_module);               \
    int main(int argc, char **argv)                     \
    {                                                   \
      (void)argc;                                       \
      (void)argv;                                       \
      return EVILUNIT_MODULE_MANGLE(main_module)(1, 0); \
    }                                                   \
  }                                                     \
  MODULE(main_module)
#else
#define EVILUNIT_MAIN_MODULE()                        \
  EVILUNIT_MODULE_DECLARE(main_module);               \
  int main(int argc, char **argv)                     \
  {                                                   \
    (void)argc;                                       \
    (void)argv;                                       \
    return EVILUNIT_MODULE_MANGLE(main_module)(1, 0); \
  }                                                   \
  MODULE(main_module)
#endif

#endif /* EVILUNIT_TEST_FRAMEWORK_HEADER */

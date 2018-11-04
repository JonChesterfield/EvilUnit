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
 * Copyright 2015-2018 Jon Chesterfield. All rights reserved.
 */
#include "EvilUnit.h"

/*
 * The user may have rewritten these macros. This will cause the included
 * selftest modules to fail.
 */

#ifdef CHECK
#undef CHECK
#endif
#define CHECK(X) EVILUNIT_CHECK(X)
#ifdef TEST
#undef TEST
#endif
#define TEST(X) EVILUNIT_TEST(X)
#ifdef DEPENDS
#undef DEPENDS
#endif
#define DEPENDS(X) EVILUNIT_DEPENDS(X)
#ifdef MODULE
#undef MODULE
#endif
#define MODULE(X) EVILUNIT_MODULE(X)


/*
 * Helper functions
 */

static const char * evilunit_query_test_name(evilunit_node_type node, unsigned int test)
{
  int instruction = evilunit_traverse_command_get_test_name_from_number;
  struct evilunit_module_state S;
  if (test == 0)
    {
      return evilunit_query_module_name(node);
    }
  evilunit_clear_module_state(node,&S);
  S.Q = get_name;
  S.numeric_parameter = test;
  (void)node(instruction,EVILUNIT_CAST(char**,(&S)));
  return S.string_parameter;
}

static int evilunit_query_is_white(evilunit_node_type node)
{
  int instruction = evilunit_traverse_command_is_colour_white;
  struct evilunit_module_state S;
  (void)node(instruction,EVILUNIT_CAST(char**,(&S)));
  return S.numeric_parameter == 1;
}

static struct evilunit_test_state evilunit_nop_visitor(evilunit_node_type node)
{
  struct evilunit_test_state nop = evilunit_make_test_state("nop");
  (void)node;
  return nop;
}

static void evilunit_nop_traverse(evilunit_node_type node)
{
  (void)evilunit_walk_graph(node,evilunit_nop_visitor,evilunit_nop_reducor);
}

static MODULE(direct)
{
  DEPENDS(direct);
  CHECK(42==42);
}

static EVILUNIT_MODULE_DECLARE(indirect_first);

static MODULE(indirect_second)
{
  DEPENDS(indirect_first);
  CHECK(2!=42);
}

static MODULE(indirect_first)
{
  DEPENDS(indirect_second);
  CHECK(1!=42);
}

static MODULE(evilunit_selftest_recursive)
{
  CHECK(1!=2);
  DEPENDS(direct);
  DEPENDS(indirect_first);
  DEPENDS(indirect_second);
}

/* Helper functions for included test modules */
static EVILUNIT_MODULE_DECLARE(evilunit_string_equal);
#include "evilunit_string_equal.i"
static int evilunit_test_states_match(struct evilunit_test_state * lhs, struct evilunit_test_state * rhs)
{
  /* Ignoring line field as it's likely to be a pain to maintain */
  return ((lhs->result == rhs->result) &&
          (evilunit_string_equal(lhs->check_string,rhs->check_string)) &&
          (evilunit_string_equal(lhs->testname_string,rhs->testname_string)));
}

/* Test files are out of line for convenience only */
#include "evilunit_selftest_implementation_check.i"
#include "evilunit_selftest_counting_dependencies.i"
#include "evilunit_selftest_get_module_name.i"
#include "evilunit_selftest_graph.i"
#include "evilunit_selftest_module_contains_no_tests.i"
#include "evilunit_selftest_multiple_checks_per_test.i"
#include "evilunit_selftest_number_recording.i"
#include "evilunit_selftest_run_specific_test.i"
#include "evilunit_selftest_counting_tests.i"
#include "evilunit_selftest_macros_for_names.i"

static MODULE(evilunit_selftest_nonrecursive)
{
  DEPENDS(evilunit_selftest_implementation_check);
  DEPENDS(evilunit_selftest_counting_dependencies);
  DEPENDS(evilunit_selftest_get_module_name);
  DEPENDS(evilunit_selftest_graph);
  DEPENDS(evilunit_selftest_module_contains_no_tests);
  DEPENDS(evilunit_selftest_multiple_checks_per_test);
  DEPENDS(evilunit_selftest_number_recording);
  DEPENDS(evilunit_selftest_run_specific_test);
  DEPENDS(evilunit_selftest_counting_tests);
  DEPENDS(evilunit_selftest_macros_for_names);
  DEPENDS(evilunit_selftest); /* Recursive sanity check */
}

MODULE(evilunit_selftest)
{
  DEPENDS(evilunit_selftest_nonrecursive);
  DEPENDS(evilunit_selftest_recursive);
}

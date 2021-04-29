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
#include "EvilUnit.h"

static MODULE(set_containing_no_checks)
{
  (void)evilunit_internal_state;
}

static MODULE(set_containing_passing_check)
{
  CHECK(42==42);
}

static MODULE(set_containing_failing_check)
{
  CHECK(42!=42);
}

static MODULE(set_containing_passing_then_failing_check)
{
  CHECK(10==10);
  CHECK(42!=42);
}

static MODULE(set_containing_failing_then_passing_check)
{
  CHECK(42!=42);
  CHECK(10==10);
}

static MODULE(set_containing_passing_then_passing_check)
{
  CHECK(10==10);
  CHECK(42==42);
}

static MODULE(set_containing_failing_then_failing_check)
{
  CHECK(42!=42);
  CHECK(10!=10);
}

static MODULE(set_containing_passing_then_failing_then_passing_check)
{
  CHECK(10==10);
  CHECK(42!=42);
  CHECK(10==10);
}

static MODULE(set_containing_failing_then_passing_then_failing_check)
{
  CHECK(42!=42);
  CHECK(10==10);
  CHECK(10!=10);
}

static MODULE(evilunit_selftest_module_contains_no_tests)
{
  unsigned int test_to_run = 42; /* For these tests, any number will do */
  struct evilunit_test_state answer = evilunit_make_test_state("");
  struct evilunit_test_state expect = evilunit_make_test_state("");
  TEST("module with no checks returns pass")
    {
      expect.result = evilunit_test_pass();
      expect.testname_string = "set_containing_no_checks";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_no_checks),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("module with passing check returns pass and the checked string")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "42==42";
      expect.testname_string = "set_containing_passing_check";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_passing_check),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("module with failing check returns fail and the checked string")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "42!=42";
      expect.testname_string = "set_containing_failing_check";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_failing_check),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("module with a passing then a failing test fails with the failed string")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "42!=42";
      expect.testname_string = "set_containing_passing_then_failing_check";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_passing_then_failing_check),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("module with a failing then a passing test fails with the failed string")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "42!=42";
      expect.testname_string = "set_containing_failing_then_passing_check";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_failing_then_passing_check),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("multiple passing checks, last wins")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "42==42";
      expect.testname_string = "set_containing_passing_then_passing_check";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_passing_then_passing_check),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("multiple failing checks, first wins")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "42!=42";
      expect.testname_string = "set_containing_failing_then_failing_check";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_failing_then_failing_check),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("module with {pass/fail/pass} tests fails with the failed string")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "42!=42";
      expect.testname_string = "set_containing_passing_then_failing_then_passing_check";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_passing_then_failing_then_passing_check),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("module with {fail/pass/fail} first fail wins")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "42!=42";
      expect.testname_string = "set_containing_failing_then_passing_then_failing_check";
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(set_containing_failing_then_passing_then_failing_check),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

}

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

static MODULE(multiple_checks)
{

  TEST("no checks")
    {
    }

  TEST("one passing")
    {
      CHECK(1==1);
    }

  TEST("one failing")
    {
      CHECK(2!=2);
    }

  TEST("{pass,fail}")
    {
      CHECK(1==1);
      CHECK(3!=3);
    }

  TEST("{fail,pass}")
    {
      CHECK(4!=4);
      CHECK(1==1);
    }

  TEST("{pass,pass}")
    {
      CHECK(1==1);
      CHECK(5==5);
    }

  TEST("{fail,fail}")
    {
      CHECK(6!=6);
      CHECK(1!=1);
    }

  TEST("{pass,fail,pass}")
    {
      CHECK(1==1);
      CHECK(7!=7);
      CHECK(1==1);
    }

  TEST("{fail,pass,fail}")
    {
      CHECK(8!=8);
      CHECK(1==1);
      CHECK(1!=1);
    }

}

static MODULE(evilunit_selftest_multiple_checks_per_test)
{
  unsigned int test_to_run = 0;
  struct evilunit_test_state answer = evilunit_make_test_state("multiple_checks");
  /*
   * CHECK() runs even when no test is active.
   * This test makes unusual use of CHECK, by using one call to evaluate every
   * test case. Consequently, expect must be set to the value that will pass
   * when no test cases are active to avoid a somewhat spurious failure
   */

  struct evilunit_test_state expect = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(multiple_checks),test_to_run);

  TEST("module with no checks or tests returns pass")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "";
      expect.testname_string = "multiple_checks";
      test_to_run = 0;
    }

  TEST("test with no checks returns pass")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "";
      expect.testname_string = "no checks";
      test_to_run = 1;
    }

  TEST("single check can pass")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "1==1";
      expect.testname_string = "one passing";
      test_to_run = 2;
    }

  TEST("single check can fail")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "2!=2";
      expect.testname_string = "one failing";
      test_to_run = 3;
    }

  TEST("pass then fail, fail wins")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "3!=3";
      expect.testname_string = "{pass,fail}";
      test_to_run = 4;
    }

  TEST("fail then pass, fail wins")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "4!=4";
      expect.testname_string = "{fail,pass}";
      test_to_run = 5;
    }

  TEST("pass then pass, second wins")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "5==5";
      expect.testname_string = "{pass,pass}";
      test_to_run = 6;
    }

  TEST("fail then fail, first wins")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "6!=6";
      expect.testname_string = "{fail,fail}";
      test_to_run = 7;
    }

  TEST("fail wins even when passes before and after")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "7!=7";
      expect.testname_string = "{pass,fail,pass}";
      test_to_run = 8;
    }

  TEST("first fail wins even when separated by passes")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "8!=8";
      expect.testname_string = "{fail,pass,fail}";
      test_to_run = 9;
    }

  {
    unsigned int num_tests = evilunit_query_number_of_tests(EVILUNIT_MODULE_MANGLE(multiple_checks));
    CHECK(num_tests == 9);
  }

  answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(multiple_checks),test_to_run);
  CHECK(evilunit_test_states_match(&expect,&answer));
}

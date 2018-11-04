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

static MODULE(module_containing_no_tests)
{
  CHECK(42 == 42);
}

static MODULE(module_containing_one_test)
{
  TEST("only test")
    {
      CHECK(42 == 42);
    }
}

static MODULE(module_containing_multiple_tests)
{
  TEST("first test")
    {
      CHECK(42 == 42);
    }
  TEST("second test")
    {
      CHECK(42 != 43);
    }
}

static MODULE(get_number_of_tests)
{
  unsigned int number = 0;
    TEST("can count the number of tests in a module containing no tests")
    {
      number = evilunit_query_number_of_tests(EVILUNIT_MODULE_MANGLE(module_containing_no_tests));
      CHECK(number == 0);
    }

  TEST("can count the number of tests in a module containing one test")
    {
      number = evilunit_query_number_of_tests(EVILUNIT_MODULE_MANGLE(module_containing_one_test));
      CHECK(number == 1);
    }

  TEST("can count the number of tests in a module containing multiple tests")
    {
      number = evilunit_query_number_of_tests(EVILUNIT_MODULE_MANGLE(module_containing_multiple_tests));
      CHECK(number == 2);
    }

}

static MODULE(get_test_name_from_number)
{
  unsigned int number = 0;
  const char * testname = 0;

  DEPENDS(evilunit_string_equal);

  TEST("get test name from number == 0 returns module name when there are no tests")
    {
      testname = evilunit_query_test_name(EVILUNIT_MODULE_MANGLE(module_containing_no_tests),number);
      CHECK(evilunit_string_equal("module_containing_no_tests",testname));
    }

  TEST("get test name from number > number of tests returns module name")
    {
      number = 2;
      testname = evilunit_query_test_name(EVILUNIT_MODULE_MANGLE(module_containing_one_test),number);
      CHECK(evilunit_string_equal("module_containing_one_test",testname));
    }

  TEST("get test name from number returns module name when told to run test zero")
    {
      number = 0;
      testname = evilunit_query_test_name(EVILUNIT_MODULE_MANGLE(module_containing_one_test),number);
      CHECK(evilunit_string_equal("module_containing_one_test",testname));
    }
    
  TEST("get test name from number can return the test name when there is one test")
    {
      number = 1;
      testname = evilunit_query_test_name(EVILUNIT_MODULE_MANGLE(module_containing_one_test),number);
      CHECK(evilunit_string_equal("only test",testname));
    }

  TEST("get test name from number can return both test names when there are two tests")
    {
      number = 1;
      testname = evilunit_query_test_name(EVILUNIT_MODULE_MANGLE(module_containing_multiple_tests),number);
      CHECK(evilunit_string_equal("first test",testname));

      number = 2;
      testname = evilunit_query_test_name(EVILUNIT_MODULE_MANGLE(module_containing_multiple_tests),number);
      CHECK(evilunit_string_equal("second test",testname));
    }
}

static MODULE(evilunit_selftest_counting_tests)
{
  DEPENDS(get_number_of_tests);
  DEPENDS(get_test_name_from_number);
}

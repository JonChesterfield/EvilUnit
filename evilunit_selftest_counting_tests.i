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

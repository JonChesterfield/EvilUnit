#include "EvilUnit.h"

static MODULE(uninteresting_module)
{
  (void)state;
}

static MODULE(get_module_name_from_function)
{
  unsigned int number = 1;
  evilunit_node_type dependency = 0;

  DEPENDS(uninteresting_module);
  DEPENDS(evilunit_string_equal);

  TEST("Retrieve name of a different module")
    {
      const char * modulename = evilunit_query_module_name(EVILUNIT_MODULE_MANGLE(uninteresting_module));
      CHECK(evilunit_string_equal(modulename, "uninteresting_module"));
    }
 

  TEST("Retrieve name of this module")
    {
      CHECK(evilunit_string_equal(evilunit_query_module_name(EVILUNIT_MODULE_MANGLE(get_module_name_from_function)), "get_module_name_from_function"));
    }

  TEST("Retrieve name of dependency")
    {
      dependency = evilunit_query_dependency(EVILUNIT_MODULE_MANGLE(get_module_name_from_function),number);
      CHECK(dependency != 0);
      CHECK(evilunit_string_equal(evilunit_query_module_name(dependency), "uninteresting_module"));
    }
}

static MODULE(uninteresting_single_test)
{
  TEST("single_test")
    {
    }
}

static MODULE(module_that_fails)
{
  CHECK(0);
}

static MODULE(module_with_dependency)
{
  DEPENDS(uninteresting_module);
}

static MODULE(get_module_name_from_test)
{
  struct evilunit_test_state expect = make_test_state("");
  struct evilunit_test_state result = make_test_state("");

  DEPENDS(evilunit_string_equal);

  TEST("Retrieve name by calling a non-existent test in an empty module")
    {
      expect.testname_string = "uninteresting_module";
      result = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(uninteresting_module),0);
    }

  TEST("Retrieve name by calling test zero a module that has tests")
    {
      expect.testname_string = "uninteresting_single_test";
      result = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(uninteresting_single_test),0);
    }

  TEST("Retrieve name by calling a non-existent test in a module that fails")
    {
      expect.testname_string = "module_that_fails";
      result = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(module_that_fails),0);
    }

  TEST("Retrieve name by calling a non-existent test in a module that has a dependency")
    {
      expect.testname_string = "module_with_dependency";
      result = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(module_with_dependency),0);
    }

  CHECK(evilunit_string_equal(expect.testname_string, result.testname_string));
}

static MODULE(evilunit_selftest_get_module_name)
{
  DEPENDS(get_module_name_from_function);
  DEPENDS(get_module_name_from_test);
}

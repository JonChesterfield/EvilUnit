#include "EvilUnit.h"

static MODULE(set_of_unary_tests)
{
  CHECK(42==42);

  TEST("test one")
    {
      CHECK(0!=0);
    }

  TEST("test two")
    {
      CHECK(1==1);
    }

  TEST("test three")
    {
      CHECK(2!=2);
    }
}

static MODULE(call_a_test_that_does_not_exist)
{
  TEST("test one")
    {
      CHECK(0!=0);
    }
}

static MODULE(evilunit_selftest_run_specific_test)
{
  unsigned int test_to_run = 0;
  struct evilunit_test_state answer = make_test_state("set_of_unary_tests");
  struct evilunit_test_state expect = make_test_state("set_of_unary_tests");
  evilunit_node_type unary = EVILUNIT_MODULE_MANGLE(set_of_unary_tests);

  TEST("Can call the zeroth test explicitly")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "42==42";
      expect.testname_string = "set_of_unary_tests";
      test_to_run = 0;
      answer = evilunit_execute_specific_test(unary,test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("Can call the first test explicitly")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "0!=0";
      expect.testname_string = "test one";
      test_to_run = 1;
      answer = evilunit_execute_specific_test(unary,test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("Can call the second test explicitly")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "1==1";
      expect.testname_string = "test two";
      test_to_run = 2;
      answer = evilunit_execute_specific_test(unary,test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("Can call the third test explicitly")
    {
      expect.result = evilunit_test_fail();
      expect.check_string = "2!=2";
      expect.testname_string = "test three";
      test_to_run = 3;
      answer = evilunit_execute_specific_test(unary,test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }

  TEST("Calling a test that does not exist (when there are also no checks) returns pass and an empty string")
    {
      expect.result = evilunit_test_pass();
      expect.check_string = "";
      expect.testname_string = "call_a_test_that_does_not_exist";
      test_to_run = 2;
      answer = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(call_a_test_that_does_not_exist),test_to_run);
      CHECK(evilunit_test_states_match(&expect,&answer));
    }
}

#include "EvilUnit.h"

static MODULE(count_empty_target)
{
  (void)state;
}

static MODULE(count_checks_passing_target)
{
  CHECK(0 == 0);
  TEST("first")
    {
      CHECK(1 == 1);
    }
  TEST("second")
    {
      CHECK(2 == 2);
      CHECK(3 == 3);
    }
  CHECK(4 == 4);
}

static MODULE(count_checks_failing_target)
{
  CHECK(0 != 0);
  TEST("first")
    {
      CHECK(1 != 1);
    }
  TEST("second")
    {
      CHECK(2 != 2);
      CHECK(3 != 3);
    }
  CHECK(4 != 4);
}

static MODULE(count_checks_mixture_target)
{
  CHECK(0 == 0);
  CHECK(0 != 0);
  TEST("first")
    {
      CHECK(1 == 1);
      CHECK(1 != 1);
    }
  TEST("second")
    {
      CHECK(2 == 2);
      CHECK(2 != 2);
      CHECK(3 == 3);
      CHECK(3 != 3);
    }
  CHECK(4 == 4);
  CHECK(4 != 4);
}

static MODULE(number_recording_specific_test)
{
  evilunit_node_type passing = EVILUNIT_MODULE_MANGLE(count_checks_passing_target);
  evilunit_node_type failing = EVILUNIT_MODULE_MANGLE(count_checks_failing_target);
  evilunit_node_type mixture = EVILUNIT_MODULE_MANGLE(count_checks_mixture_target);
  struct evilunit_test_state expect = make_test_state("");
  struct evilunit_test_state result = make_test_state("");

  TEST("no checks in empty module")
    {
      expect.number_success = 0;
      expect.number_failure = 0;
      result = evilunit_execute_specific_test(EVILUNIT_MODULE_MANGLE(count_empty_target),0);
    }
  
  TEST("two checks in module-only passing case")
    {
      expect.number_success = 2;
      expect.number_failure = 0;
      result = evilunit_execute_specific_test(passing,0);
    }

  TEST("two checks in module-only failing case")
    {
      expect.number_success = 0;
      expect.number_failure = 2;
      result = evilunit_execute_specific_test(failing,0);
    }

  TEST("four checks in module-only mixture case")
    {
      expect.number_success = 2;
      expect.number_failure = 2;
      result = evilunit_execute_specific_test(mixture,0);
    }

  TEST("three checks in first test passing case")
    {
      expect.number_success = 3;
      expect.number_failure = 0;
      result = evilunit_execute_specific_test(passing,1);
    }

  TEST("three checks in first test failing case")
    {
      expect.number_success = 0;
      expect.number_failure = 3;
      result = evilunit_execute_specific_test(failing,1);
    }

  TEST("six checks in first test mixture case")
    {
      expect.number_success = 3;
      expect.number_failure = 3;
      result = evilunit_execute_specific_test(mixture,1);
    }

  TEST("four checks in second test passing case")
    {
      expect.number_success = 4;
      expect.number_failure = 0;
      result = evilunit_execute_specific_test(passing,2);
    }

  TEST("four checks in second test failing case")
    {
      expect.number_success = 0;
      expect.number_failure = 4;
      result = evilunit_execute_specific_test(failing,2);
    }

  TEST("eight checks in second test mixture case")
    {
      expect.number_success = 4;
      expect.number_failure = 4;
      result = evilunit_execute_specific_test(mixture,2);
    }

  CHECK(expect.number_success == result.number_success);
  CHECK(expect.number_failure == result.number_failure);
}

static MODULE(number_recording_execute_all_tests)
{
  struct evilunit_test_state expect = make_test_state("");
  struct evilunit_test_state result = make_test_state("");

   TEST("no checks in empty module")
    {
      expect.number_success = 0;
      expect.number_failure = 0;
      result = evilunit_execute_all_tests(EVILUNIT_MODULE_MANGLE(count_empty_target));
    }
  
  TEST("nine checks in passing case")
    {
      expect.number_success = 9;
      expect.number_failure = 0;
      result = evilunit_execute_all_tests(EVILUNIT_MODULE_MANGLE(count_checks_passing_target));
    }

  TEST("nine checks in failing case")
    {
      expect.number_success = 0;
      expect.number_failure = 9;
      result = evilunit_execute_all_tests(EVILUNIT_MODULE_MANGLE(count_checks_failing_target));
    }

  TEST("eighteen checks in mixture case")
    {
      expect.number_success = 9;
      expect.number_failure = 9;
      result = evilunit_execute_all_tests(EVILUNIT_MODULE_MANGLE(count_checks_mixture_target));
    }

  CHECK(expect.number_success == result.number_success);
  CHECK(expect.number_failure == result.number_failure);
}

static MODULE(evilunit_selftest_number_recording)
{
  DEPENDS(number_recording_specific_test);
  DEPENDS(number_recording_execute_all_tests);
}

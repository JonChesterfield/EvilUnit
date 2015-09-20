#include "EvilUnit.h"

static MODULE(fake_module)
{
  (void)state;
}

static MODULE(evilunit_selftest_implementation_check)
{
  
  struct evilunit_module_state S;
  int check_state = 1;
  int line = 42;
  const char teststring [] = "foo";
  clear_module_state(EVILUNIT_MODULE_MANGLE(fake_module),&S);
  
  TEST("A true result passed to a new module_state sets flag to PASS")
    {
      check_state = 1;
      evilunit_implementation_check(&S,check_state,line,teststring);
      CHECK(S.test.result == evilunit_test_pass());
    }

    TEST("A false result passed to a new module_state sets flag to FAIL")
    {
      check_state = 0;
      evilunit_implementation_check(&S,check_state,line,teststring);
      CHECK(S.test.result == evilunit_test_fail());
    }
}

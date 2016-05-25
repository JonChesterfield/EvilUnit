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
 * Copyright 2015 Jon Chesterfield. All rights reserved.
 */
#include "EvilUnit.h"

static MODULE(fake_module)
{
  (void)evilunit_internal_state;
}

static MODULE(evilunit_selftest_implementation_check)
{
  
  struct evilunit_module_state S;
  int check_state = 1;
  int line = 42;
  const char teststring [] = "foo";
  evilunit_clear_module_state(EVILUNIT_MODULE_MANGLE(fake_module),&S);
  
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

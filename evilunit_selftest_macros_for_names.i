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



static MODULE(macro_manual)
{
  CHECK(0);
}

#define EVILUNIT_TEST_STRINGIFY(X) EVILUNIT_TEST_STRINGIFY_HELPER(X)
#define EVILUNIT_TEST_STRINGIFY_HELPER(X) #X
#define EVILUNIT_TEST_LOCALNAME manual

static MODULE(macros_for_module_names)
{
  char const * name = evilunit_query_module_name(EVILUNIT_MODULE_MANGLE(macro_manual));

  TEST("explicit")
    {
      CHECK(evilunit_string_equal(name,"macro_manual"));
    }

  TEST("composing string literal for string compare")
    {

      CHECK(evilunit_string_equal(name,"macro_" EVILUNIT_TEST_STRINGIFY(EVILUNIT_TEST_LOCALNAME) ));
    }

  TEST("composing name of argument to module mangle from tokens")
    {
      CHECK(evilunit_string_equal(name,evilunit_query_module_name(EVILUNIT_MODULE_MANGLE(EVILUNIT_CONCAT(macro_,manual)))));
    }

  TEST("composing name of argument to module mangle from a token and a macro")
    {
      CHECK(evilunit_string_equal(name,evilunit_query_module_name(EVILUNIT_MODULE_MANGLE(EVILUNIT_CONCAT(macro_,EVILUNIT_TEST_LOCALNAME)))));
    }
}

#undef EVILUNIT_TEST_LOCALNAME
#undef EVILUNIT_TEST_STRINGIFY_HELPER
#undef EVILUNIT_TEST_STRINGIFY

#define EVILUNIT_TEST_DEPNAME foobar

static MODULE(EVILUNIT_CONCAT(macro_,EVILUNIT_TEST_DEPNAME))
{
  TEST("check my name is set correctly")
    {
      char const * name = evilunit_query_module_name(EVILUNIT_MODULE_MANGLE(EVILUNIT_CONCAT(macro_,EVILUNIT_TEST_DEPNAME)));

      CHECK(evilunit_string_equal(name,"macro_foobar"));
    }
}

static MODULE(evilunit_selftest_macros_for_names)
{
  DEPENDS(macros_for_module_names);
  DEPENDS(EVILUNIT_CONCAT(macro_,EVILUNIT_TEST_DEPNAME));
  CHECK(3==3);
}

#undef EVILUNIT_TEST_DEPNAME

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

static MODULE(first_module_with_no_dependencies)
{
  CHECK(42 == 42);
}

static MODULE(second_module_with_one_dependency)
{
  DEPENDS(first_module_with_no_dependencies);
}

static MODULE(third_module_with_two_unique_dependencies)
{
  DEPENDS(first_module_with_no_dependencies);
  DEPENDS(second_module_with_one_dependency);
}

static MODULE(forth_module_with_two_identical_dependencies)
{
  DEPENDS(first_module_with_no_dependencies);
  DEPENDS(first_module_with_no_dependencies);
}

static MODULE(fifth_module_with_self_dependency)
{
  DEPENDS(fifth_module_with_self_dependency);
}

static MODULE(get_number_of_dependencies)
{
  unsigned int number = 0;
  TEST("can count the number of dependencies in a module containing no dependencies")
    {
      number = evilunit_query_number_of_dependencies(EVILUNIT_MODULE_MANGLE(first_module_with_no_dependencies));
      CHECK(number == 0);
    }

  TEST("can count the number of dependencies in a module containing one test")
    {
      number = evilunit_query_number_of_dependencies(EVILUNIT_MODULE_MANGLE(second_module_with_one_dependency));
      CHECK(number == 1);
    }

  TEST("can count the number of dependencies in a module containing two unique dependencies")
    {
      number = evilunit_query_number_of_dependencies(EVILUNIT_MODULE_MANGLE(third_module_with_two_unique_dependencies));
      CHECK(number == 2);
    }

  TEST("repeated dependencies are counted as if they were unique")
    {
      number = evilunit_query_number_of_dependencies(EVILUNIT_MODULE_MANGLE(forth_module_with_two_identical_dependencies));
      CHECK(number == 2);
    }

  TEST("depending on oneself counts as one dependency")
    {
      number = evilunit_query_number_of_dependencies(EVILUNIT_MODULE_MANGLE(fifth_module_with_self_dependency));
      CHECK(number == 1);
    }
}

static MODULE(get_dependency_from_number)
{
  unsigned int number = 0;
  evilunit_node_type modulenode = 0;
  evilunit_node_type dependency = 0;  
  
  TEST("Getting a non-existent dependency using number == 0 returns the module itself")
    {
      modulenode = EVILUNIT_MODULE_MANGLE(first_module_with_no_dependencies);
      dependency = evilunit_query_dependency(modulenode,number);
      CHECK(dependency != 0);
      CHECK(dependency == modulenode);
    }
  
  TEST("Number == 0 returns module when there is one dependency")
    {
      modulenode = EVILUNIT_MODULE_MANGLE(second_module_with_one_dependency);
      number = 0;
      dependency = evilunit_query_dependency(modulenode,number);
      CHECK(dependency != 0);
      CHECK(dependency == modulenode);
    }

  TEST("Number == 0 returns module when there are multiple dependencies")
    {
      modulenode = EVILUNIT_MODULE_MANGLE(third_module_with_two_unique_dependencies);
      number = 0;
      dependency = evilunit_query_dependency(modulenode,number);
      CHECK(dependency != 0);
      CHECK(dependency == modulenode);
    }

  TEST("Number == 1 returns pointer to only dependency")
    {
      number = 1;
      dependency = evilunit_query_dependency(EVILUNIT_MODULE_MANGLE(second_module_with_one_dependency),number);
      CHECK(dependency != 0);
      CHECK(dependency == EVILUNIT_MODULE_MANGLE(first_module_with_no_dependencies));
    }

  TEST("Number == 1 returns pointer to first of multiple dependencies")
    {
      number = 1;
      dependency = evilunit_query_dependency(EVILUNIT_MODULE_MANGLE(third_module_with_two_unique_dependencies),number);
      CHECK(dependency != 0);
      CHECK(dependency == EVILUNIT_MODULE_MANGLE(first_module_with_no_dependencies));
    }

  TEST("Number == 2 returns pointer to second of multiple dependencies")
    {
      number = 2;
      dependency = evilunit_query_dependency(EVILUNIT_MODULE_MANGLE(third_module_with_two_unique_dependencies),number);
      CHECK(dependency != 0);
      CHECK(dependency == EVILUNIT_MODULE_MANGLE(second_module_with_one_dependency));
    }

  TEST("Can retrieve pointer to oneself in the case of self-dependency")
    {
      number = 1;
      dependency = evilunit_query_dependency(EVILUNIT_MODULE_MANGLE(fifth_module_with_self_dependency),number);
      CHECK(dependency != 0);
      CHECK(dependency == EVILUNIT_MODULE_MANGLE(fifth_module_with_self_dependency));
    }
}

static MODULE(evilunit_selftest_counting_dependencies)
{
  DEPENDS(get_number_of_dependencies);
  DEPENDS(get_dependency_from_number);
}

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
 * Copyright Jon Chesterfield. All rights reserved.
 */
#include "EvilUnit.h"

/* Lets write a string equal function */
/* 
 * The self tests could use strcmp(,) == 0 to 
 * test strings for equality, but this 
 * pulls in <strings.h>
 */

static int evilunit_string_equal(const char * lhs, const char * rhs)
{
  if ((lhs && !rhs) || (!lhs && rhs))
    {
      return 0;
    }

  if (!lhs && !rhs)
    {
      return 1;
    }

  while (*lhs != '\0' && *rhs != '\0')
    {
      if (*lhs != *rhs)
	{
	  return 0;
	}
      lhs++;
      rhs++;
    }
  return (*lhs == *rhs);
}

static MODULE(strings_simple_examples)
{
  TEST("Single char")
    {
      CHECK(evilunit_string_equal("",""));
      CHECK(evilunit_string_equal("A","A"));
      CHECK(!evilunit_string_equal("","A"));
    }

  TEST("Equal")
    {
      CHECK(evilunit_string_equal("foo","foo"));
      CHECK(evilunit_string_equal("foo bar","foo bar"));
    }
  
  TEST("Differ in first char")
    {
      CHECK(!evilunit_string_equal("foo","Xfoo"));
      CHECK(!evilunit_string_equal("foo bar","Xfoo bar"));
    }
  
  TEST("Differ in final char")
    {
      CHECK(!evilunit_string_equal("foo","fooX"));
      CHECK(!evilunit_string_equal("foo bar","foo barX"));
    }
  
  TEST("Differ in intermediate char")
    {
      CHECK(!evilunit_string_equal("foo","foXo"));
      CHECK(!evilunit_string_equal("foo bar","fooXbar"));
    }
}

static MODULE(strings_null_pointers)
{
  const char * v = 0;
  TEST("null differs from non-null strings")
    {
      CHECK(!evilunit_string_equal(v,""));
      CHECK(!evilunit_string_equal("",v));
      CHECK(!evilunit_string_equal(v," "));
      CHECK(!evilunit_string_equal(" ",v));
      CHECK(!evilunit_string_equal(v,"foo"));
      CHECK(!evilunit_string_equal("foo",v));
    }

  TEST("null equals null")
    {
      CHECK(evilunit_string_equal(v,v));
      CHECK(evilunit_string_equal(v,0));
      CHECK(evilunit_string_equal(0,v));
      CHECK(evilunit_string_equal(0,0));
    }

  TEST("null chars mark end of strings")
    {
      CHECK(evilunit_string_equal("","\0"));
      CHECK(evilunit_string_equal("foo","foo\0"));
      CHECK(evilunit_string_equal("foo","foo\0bar"));
    }
}

MODULE(evilunit_string_equal)
{
  DEPENDS(strings_simple_examples);
  DEPENDS(strings_null_pointers);
}

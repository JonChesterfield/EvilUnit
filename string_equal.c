#include "EvilUnit.h"

/* Lets write a string equal function */
/* 
 * The self tests use strcmp(,) == 0 to 
 * test strings for equality, but this 
 * pulls in <strings.h>
 */

int string_equal(const char * lhs, const char * rhs)
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
      CHECK(string_equal("",""));
      CHECK(string_equal("A","A"));
      CHECK(!string_equal("","A"));
    }

  TEST("Equal")
    {
      CHECK(string_equal("foo","foo"));
      CHECK(string_equal("foo bar","foo bar"));
    }
  
  TEST("Differ in first char")
    {
      CHECK(!string_equal("foo","Xfoo"));
      CHECK(!string_equal("foo bar","Xfoo bar"));
    }
  
  TEST("Differ in final char")
    {
      CHECK(!string_equal("foo","fooX"));
      CHECK(!string_equal("foo bar","foo barX"));
    }
  
  TEST("Differ in intermediate char")
    {
      CHECK(!string_equal("foo","foXo"));
      CHECK(!string_equal("foo bar","fooXbar"));
    }
}

static MODULE(strings_null_pointers)
{
  const char * v = 0;
  TEST("null differs from non-null strings")
    {
      CHECK(!string_equal(v,""));
      CHECK(!string_equal("",v));
      CHECK(!string_equal(v," "));
      CHECK(!string_equal(" ",v));
      CHECK(!string_equal(v,"foo"));
      CHECK(!string_equal("foo",v));
    }

  TEST("null equals null")
    {
      CHECK(string_equal(v,v));
      CHECK(string_equal(v,0));
      CHECK(string_equal(0,v));
      CHECK(string_equal(0,0));
    }

  TEST("null chars mark end of strings")
    {
      CHECK(string_equal("","\0"));
      CHECK(string_equal("foo","foo\0"));
      CHECK(string_equal("foo","foo\0bar"));
    }
}

MAIN_MODULE()
{
  DEPENDS(strings_simple_examples);
  DEPENDS(strings_null_pointers);
}

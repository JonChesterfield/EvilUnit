#ifndef EVILUNIT_DATASTRUCTURES_H
#define EVILUNIT_DATASTRUCTURES_H

/*
 * A check comprises a string and a boolean result
 * A test comprises a string and {one | vector} check
 * A module comprises a string and {one | vector} test
 */

struct evilunit_check
{
  const char * string;
  int result;
};

struct evilunit_test
{
  const char * string;
  struct vector_evilunit_check checks;
  int result;
};

struct evilunit_module
{
  const char * string;
  struct evilunit_test;
  struct vector_evilunit_test tests;
  int result;
};

/*
 * A module also contains [0,N) DEPENDS() statements. 
 */

/*
 * In addition to this there is a compile time state:
 * A module may be queried to ask:
 * Who are you?                       Returns a evilunit_module with empty tests vector
 * How many tests do you have?        Returns a size_t
 * What is your nth test?             Returns a evilunit_test with empty checks vector
 * How many dependencies do you have? Returns a size_t
 * What is your nth dependency?       Returns a evilunit_module with empty tests vector
 */

/*
 * A test can be asked to evaluate all its checks
 * A module can be asked to evaluate all its tests
 */

#endif /* EVILUNIT_DATASTRUCTURES_H */

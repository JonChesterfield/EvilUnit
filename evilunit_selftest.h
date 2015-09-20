#ifndef EVILUNIT_SELFTEST_H
#define EVILUNIT_SELFTEST_H
#include <string.h>

static int test_states_match(struct evilunit_test_state * lhs, struct evilunit_test_state * rhs)
{
  /* Ignoring line field as it's likely to be a pain to maintain */
  return ((lhs->result == rhs->result) &&
          (strcmp(lhs->check_string,rhs->check_string) == 0) &&
	  (strcmp(lhs->testname_string,rhs->testname_string) == 0));
}

#endif /* EVILUNIT_SELFTEST_H */

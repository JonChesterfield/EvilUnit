#ifndef EVILUNIT_SELFTEST_H
#define EVILUNIT_SELFTEST_H

static int test_states_match(struct evilunit_test_state * lhs, struct evilunit_test_state * rhs)
{
  /* Ignoring line field as it's likely to be a pain to maintain */
  return ((lhs->result == rhs->result) &&
          (evilunit_string_equal(lhs->check_string,rhs->check_string)) &&
	  (evilunit_string_equal(lhs->testname_string,rhs->testname_string)));
}

#endif /* EVILUNIT_SELFTEST_H */

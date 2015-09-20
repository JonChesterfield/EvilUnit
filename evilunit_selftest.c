#include "EvilUnit.h"

static MODULE(direct)
{
  DEPENDS(direct);
  CHECK(42==42);
}

static EVILUNIT_MODULE_DECLARE(indirect_first);

static MODULE(indirect_second)
{
  DEPENDS(indirect_first);
  CHECK(2!=42);
}

static MODULE(indirect_first)
{
  DEPENDS(indirect_second);
  CHECK(1!=42);
}

static MODULE(evilunit_selftest_recursive)
{
  CHECK(1!=2);
  DEPENDS(direct);
  DEPENDS(indirect_first);
  DEPENDS(indirect_second);
}


MAIN_MODULE()
{
  DEPENDS(evilunit_selftest);
  DEPENDS(evilunit_selftest_recursive);
}

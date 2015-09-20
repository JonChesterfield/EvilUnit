#include "EvilUnit.h"


MAIN_MODULE()
{
  CHECK(42 == 42);

  TEST("true")
    {
      CHECK(42 != 43);
    }

  TEST("lies")
    {
      CHECK(2+2 == 5);
    }
}

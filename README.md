EvilUnit is a library for facilitating unit testing in C89.

Copyright 2015 Jon Chesterfield. All rights reserved.

This library is licensed under the LGPL v3, see LICENSE. The source files should all have an appropriate header to this effect, but where this is missing the intention is still for the code to be under the LGPL v3.

This is considered alpha quality, in that I've been using it for about a year. It's on github seeking a second or even third user - feedback is welcome, especially on changes to the API. I should write better docs at some point.

The purpose is to minimise the boilerplate involved in writing unit tests in the lowest common demoninator of programming languages. The design goals and constraints may be considered eccentric, in which case I'd recommend the excellent Catch project (URL).

To use
* Compile EvilUnit.c
* Include EvilUnit.h
* Read and imitate evilunit_selftest_main.c to create a main() function
* Link everything and run

Features
* Adding a test case does not require manual registration
* Dependencies between tests are written with the tests themselves
* Common setup/teardown code is easily shared between tests
* Useful for testing static functions
* Implemented in the common subset of C and C++
* No dynamic memory allocation
* Works without standard libraries (slightly better with stdio)

The interface is the set of macros defined in EvilUnit.h which provide the following
```
MODULE(X){} // Names some unit of functionality. Contains the other constructs.
DEPENDS(X)  // This module depend on functionality tested by module X
TEST(X){}   // Names an individual unit test. Can contain CHECK().
CHECK(X)    // Takes an integer boolean. Failure if it evaluates as false.
```

Example
```
#include "EvilUnit.h"
MODULE(demo)
{
  int life = 42;
  DEPENDS(another_module);
  CHECK(life == 42);
  TEST("truth")
    {
      CHECK(life != 43);
    }
  TEST("lies")
    {
      int four = 2+2;
      CHECK(four == 5);
    }
}
```

Known limitations
* The console printing is quite crude as I tend to view failing tests in a debugger. This will probably improve later.
* The graph walking code is not thread safe.
* Setting up the driver using MAIN_MODULE() is crude.
* Linking tests in C with tests in C++ doesn't work (haven't yet set up the name mangling appropriately).

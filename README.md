EvilUnit is a library for facilitating unit testing in C89.

Copyright 2015-2018 Jon Chesterfield. All rights reserved.

This library is licensed under the LGPL v3, see LICENSE. The source files should all have an appropriate header to this effect, but where this is missing the intention is still for the code to be under the LGPL v3.

The purpose is to minimise the boilerplate involved in writing unit tests in the lowest common demoninator of programming languages. The design goals and constraints may be considered eccentric, in which case I'd recommend the excellent Catch project (https://github.com/philsquared/Catch).

This is considered beta quality. I've been using it for several years without any problem but there are probably some corner cases I've missed.

I may write better docs at some point, until then the various .i files contain examples in the form of self test code. evilunit_string_equal.i is a good self contained example. EvilUnit_main.c contains an example of providing a top level main.

To use
* Include EvilUnit.h
* Compile EvilUnit*.c if you want to run the self tests
* Any module you define has signature `int (*)(int, char**)` so is a valid C entry point
* Link everything and call one of the entry points

Features
* Adding a test case does not require manual registration
* Dependencies between tests are written with the tests themselves
* No dynamic memory allocation
* Common setup/teardown code is easily shared between tests
* Useful for testing static functions
* Implemented in the common subset of C and C++
* Works without standard libraries (slightly better with stdio)
* static MODULE(foo) {} marks the test module as internal

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
* The console printing is quite crude as I tend to view failing tests in a debugger
* The graph walking code is not thread safe
* Linking tests in C with tests in C++ doesn't work (haven't worked out how to inject extern C without preventing static modules)
* Providing your own main may be considered undesirable

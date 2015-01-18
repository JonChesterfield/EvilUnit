EvilUnit is a library for facilitating unit testing in C89.

Copyright 2015 Jon Chesterfield. All rights reserved.

Not ready for production use. Presently difficult to use even for evaluation use while I shake out bugs in the single header file distribution format. 

The premise is to minimise the boilerplate involved in writing unit tests in the lowest common denominator of programming languages. It arises from the frustration involved in writing a test function in one file, then a function prototype in another file, then adding a function call to a test suite in a third file. Most C++ test frameworks will register tests for you. Some Fortran test frameworks come with external scripts which automate this. EvilUnit leans hard on the C preprocessor to achieve the same result. 

Macros are evil. Metaprogramming is good. The combination is surprisingly effective.

Test cases resemble:

TEST(my_first_test)
{
  return SKIP("Not actually testing anything yet");
}

Initial code available in EvilUnit.h. This is currently more complicated than necessary after deciding to distribute as a single header file. Use examples and self-tests to follow.

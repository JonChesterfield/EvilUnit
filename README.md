# EvilUnit
A library for facilitating unit testing in C89.

Not ready for production use. 

The premise is to minimise the boilerplate involved in writing unit tests in the lowest common denominator of programming languages. It arises from the frustration involved in writing a test function in one file, then a function prototype in another file, then adding a function call to a test suite in a third file. Most C++ test frameworks will register tests for you. Some Fortran test frameworks come with external scripts which automate this. EvilUnit leans hard on the C preprocessor to achieve the same result. 

Macros are evil. Metaprogramming is good. The combination is surprisingly effective. 

Test cases resemble:

TEST(my_first_test)
{
  return SKIP("Not actually testing anything yet");
}

Code and examples to follow. 

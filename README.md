EvilUnit is a library for facilitating unit testing in C89.

Copyright 2015 Jon Chesterfield. All rights reserved.

This library is licensed under the LGPL v3, see LICENSE. The source files should all have an appropriate header to this effect, but where this is missing the intention is still for the code to be under the LGPL v3.

Not ready for production use. Presently difficult to use even for evaluation use while I shake out bugs in the single header file distribution format. 

The premise is to minimise the boilerplate involved in writing unit tests in the lowest common denominator of programming languages. It arises from the frustration involved in writing a test function in one file, then a function prototype in another file, then adding a function call to a test suite in a third file. Most C++ test frameworks will register tests for you. Some Fortran test frameworks come with external scripts which automate this. EvilUnit leans hard on the C preprocessor to achieve the same result. 


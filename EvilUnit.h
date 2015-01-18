/*
 * This file is part of EvilUnit.
 *
 * EvilUnit is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the 
 * Free Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * EvilUnit is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR 
 * A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more 
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License along 
 * with EvilUnit. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE

/* 
 * Supporting two modes of operation.
 * If MODULETESTFILE is defined, then we know the name of the file to include,
 * and assume we are being compiled linearly. 
 * Otherwise, assume we are being compiled recursively.
 */

#ifdef STANDALONE
#define DEFINETESTMAIN 1
#define DISABLEDEPENDS 1
#endif

/* 
 * Require a means of discarding the contents of this file on subsequent
 * inclusions, specifically when compiling given a specific MODULETESTFILE
 * but using a file set up for simple compilation using the standard boilerplate:
 * #include "EvilUnit.h"
 * #ifdef RECURSIVE
 * content
 * #include __FILE__
 * #endif
 * where said boilerplate will trigger multiple inclusions of template_test
 * Also require careful handling of the RECURSIVE statement
 */

#ifndef SKIP_TEMPLATE_TEST_INCLUSION

#ifdef MODULETESTFILE
/* Compiling in one pass, enable all the phases */
#define BUILD_PHASE_01
#define BUILD_PHASE_02
#define BUILD_PHASE_03
#define BUILD_PHASE_04
#define BUILD_PHASE_05
#define BUILD_PHASE_06
#define BUILD_PHASE_07
#define BUILD_PHASE_08
#define BUILD_PHASE_09
#define BUILD_PHASE_10
#define BUILD_PHASE_11
#define BUILD_PHASE_12
#define BUILD_PHASE_13
#define BUILD_PHASE_14
#define BUILD_PHASE_15
#define BUILD_PHASE_16

#define SKIP_TEMPLATE_TEST_INCLUSION

#else /* MODULETESTFILE */

/* Compiling one pass at a time, enable passes sequentially */

#ifndef EVILUNIT_RECURSIVE_STARTUP
#define EVILUNIT_RECURSIVE_STARTUP
#define BUILD_PHASE_00
#define RECURSIVE
#endif

#ifdef BUILD_PHASE_16
#undef BUILD_PHASE_16
#endif

#ifdef BUILD_PHASE_15
#undef BUILD_PHASE_15
#define BUILD_PHASE_16
#undef RECURSIVE
#endif

#ifdef BUILD_PHASE_14
#undef BUILD_PHASE_14
#define BUILD_PHASE_15
#endif

#ifdef BUILD_PHASE_13
#undef BUILD_PHASE_13
#define BUILD_PHASE_14
#endif

#ifdef BUILD_PHASE_12
#undef BUILD_PHASE_12
#define BUILD_PHASE_13
#endif

#ifdef BUILD_PHASE_11
#undef BUILD_PHASE_11
#define BUILD_PHASE_12
#endif

#ifdef BUILD_PHASE_10
#undef BUILD_PHASE_10
#define BUILD_PHASE_11
#endif

#ifdef BUILD_PHASE_09
#undef BUILD_PHASE_09
#define BUILD_PHASE_10
#endif

#ifdef BUILD_PHASE_08
#undef BUILD_PHASE_08
#define BUILD_PHASE_09
#endif

#ifdef BUILD_PHASE_07
#undef BUILD_PHASE_07
#define BUILD_PHASE_08
#endif

#ifdef BUILD_PHASE_06
#undef BUILD_PHASE_06
#define BUILD_PHASE_07
#endif

#ifdef BUILD_PHASE_05
#undef BUILD_PHASE_05
#define BUILD_PHASE_06
#endif

#ifdef BUILD_PHASE_04
#undef BUILD_PHASE_04
#define BUILD_PHASE_05
#endif

#ifdef BUILD_PHASE_03
#undef BUILD_PHASE_03
#define BUILD_PHASE_04
#endif

#ifdef BUILD_PHASE_02
#undef BUILD_PHASE_02
#define BUILD_PHASE_03
#endif

#ifdef BUILD_PHASE_01
#undef BUILD_PHASE_01
#define BUILD_PHASE_02
#endif

#ifdef BUILD_PHASE_00
#undef BUILD_PHASE_00
#define BUILD_PHASE_01
#endif

#endif /* MODULETESTFILE */



#ifdef BUILD_PHASE_01
/* Set up test file */






#include <assert.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>


#ifndef OBJECT_MODEL_H
#define OBJECT_MODEL_H
#endif /* OBJECT_MODEL_H */













enum RESULT
{ flag_PASS, flag_FAIL, flag_SKIP, flag_INIT, flag_FAKE };




enum DESIGNCONTRACT
{ INITIALISED, CONSTRUCTED };


struct EvilUnitTestResult
{
  enum DESIGNCONTRACT contract_state;
  char string[(127 + 1)];
  char testname[(127 + 1)];
  enum RESULT res;
};







enum TRAVERSE_FUNCTION
{ EnumGetIdentity, EnumGetNumberOfDependencies, EnumGetNumberOfLocalTests, EnumGetNthDependency, EnumRunAllTests };

struct EvilUnitTraverseFunction
{
  enum TRAVERSE_FUNCTION func;
};



int isPass (struct EvilUnitTestResult retval);
int isFail (struct EvilUnitTestResult retval);
int isSkip (struct EvilUnitTestResult retval);
int isOther (struct EvilUnitTestResult retval);

void EvilUnit_print_result_summary (struct EvilUnitTestResult *results, size_t num_results, const char *modulename);

void EvilUnit_print_result_standard (struct EvilUnitTestResult *results, size_t num_results, const char *modulename);

void EvilUnit_print_result_detailed (struct EvilUnitTestResult *results, size_t num_results, const char *modulename);

void EvilUnit_SetTestName (struct EvilUnitTestResult *retval, char *testname);

struct EvilUnitTestResult PASS (const char *msg, ...);
struct EvilUnitTestResult FAIL (const char *msg, ...);
struct EvilUnitTestResult SKIP (const char *msg, ...);
struct EvilUnitTestResult INIT (const char *msg, ...);
struct EvilUnitTestResult FAKE (const char *msg, ...);

struct EvilUnitAddress;
struct EvilUnitTestModule;

int EvilUnit_insert_result (struct EvilUnitTestResult *result, struct EvilUnitTestModule *module, size_t test_number);
int EvilUnit_retrieve_result (struct EvilUnitTestModule *module, size_t test_number, struct EvilUnitTestResult *result);

bool EvilUnit_traverse_at_destination (struct EvilUnitAddress *address, size_t depth);
int EvilUnit_traverse_next_route (struct EvilUnitAddress *address, size_t depth, size_t * next);

int EvilUnit_execute (void);

int EvilUnitGetIdentity (struct EvilUnitAddress *address, struct EvilUnitTestModule *module, const char *modulename);

int EvilUnitGetNthDependency (struct EvilUnitAddress *address, size_t * N, struct EvilUnitTestModule *module);

#define MAKETEST_QUOTE(str) #str
#define MAKETEST_EXPAND_AND_QUOTE(str) MAKETEST_QUOTE(str)
#define MAKETEST_CONCAT(a__, b__) MAKETEST_CONCAT_DO(a__, b__)
#define MAKETEST_CONCAT_DO(a__, b__) a__##b__

enum EvilUnit_PHASE
  {
    FRAMEWORK_SETUP, UNITTEST_SETUP, UNITTEST_CODE, UNITTEST_TEARDOWN, FRAMEWORK_TEARDOWN, FRAMEWORK_FINAL_RETURN
  };


/* Create SETUP and TEARDOWN values in order to disguise whether the macros are in use */
static void SETUP(void) {return;}
static void TEARDOWN(void) {return;}
static void EvilUnit_Disguise_setup_teardown(void)
{
  SETUP();
  TEARDOWN();
  return;
}
/*
 * Don't want to include a new file here - macros aren't active yet
 * TODO: Consolidate build phase 1 & 2 
 */

#ifdef BUILD_PHASE_00
#undef BUILD_PHASE_00
#endif
#ifdef BUILD_PHASE_01
#undef BUILD_PHASE_01
#endif
#ifndef BUILD_PHASE_02
#define BUILD_PHASE_02
#endif


#endif

#ifdef BUILD_PHASE_02
/* First pass - declarations based on DEPENDS() and internal_get_number_of_tests */
/* Cannot use MODULE definition or test whether the test file is empty or not */
#define DEPENDS(X) int MAKETEST_CONCAT(run_all_tests_,X)(void);
#define METHOD_PROLOG() static struct EvilUnitTestResult internal_get_number_of_tests(size_t * running_total) {size_t local_total = 0; SETUP();

#define TEST_BLOCK_HEADER(X,Y) local_total++; if (0)
#define METHOD_EPILOG() *running_total = local_total; TEARDOWN(); return PASS("Tests enumerated");}

#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE

#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif

#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_03

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif

/* 
 * The file has now been included once, reading in all the macros. If MODULE is still not
 * defined, we'll give it a default value. Can now also declare a file static variable
 * holding the name.
 */
#ifndef MODULE
#define MODULE anonymous
#endif
static const char LOCALMODULENAME[] = MAKETEST_EXPAND_AND_QUOTE(MODULE);

/* Declare a few function prototypes for the graph traversal scheme*/
static int GetNumberOfDependencies(size_t * number);
static int GetNumberOfLocalTests(size_t * number);
static int RunAllTests(struct EvilUnitTestModule * module);


/* Second pass - return will be overloaded to something terrible, so don't attempt to use DEPENDS() */
/* Generate the test functions */
#define GENERATE_TEST_FUNCTIONS 1
#define TEST_BLOCK_HEADER(X,Y) static struct EvilUnitTestResult GENTESTNAME(X,Y)(void)
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif

#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_04

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif
/* Third pass - generate run_all_tests_dependencies() */
#define DEPEND_PROLOG() static size_t get_number_of_dependencies(void) {size_t local = 0;
#define DEPENDS(X) local++;
#define DEPEND_EPILOG() return local;}

#define METHOD_PROLOG() static struct EvilUnitTestResult internal_get_test_number_from_name(const char * test_name, size_t * test_number) {size_t local_number = 0; (void)local_number; (void)test_name;
#define TEST_BLOCK_HEADER(X,Y) if (strcmp(test_name,MAKETEST_EXPAND_AND_QUOTE(GENTESTNAME(X,Y))) == 0) {*test_number = local_number; return PASS("Found test number"); } local_number++; if (0)
#define METHOD_EPILOG() *test_number = local_number; return FAIL("Did not identify test number");}
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif

#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_05

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif

#define METHOD_PROLOG() static struct EvilUnitTestResult internal_get_test_name_from_number(size_t test_number, char ** test_name) {size_t local_number = 0; (void)local_number; (void)test_number;
#define TEST_BLOCK_HEADER(X,Y) if (test_number == local_number) { *test_name = MAKETEST_EXPAND_AND_QUOTE(GENTESTNAME(X,Y)); return PASS("Found test name"); } local_number++; if (0)
#define METHOD_EPILOG() *test_name = NULL; return FAIL("Did not identify test name");}
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif

#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

/* #define ENABLECALLBYNAME */

#ifdef ENABLECALLBYNAME
#undef ENABLECALLBYNAME

#ifdef BUILD_PHASE_06

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif

#define METHOD_PROLOG() static struct EvilUnitTestResult call_test_by_name(const char * test_name) {(void)test_name;
#define TEST_BLOCK_HEADER(X,Y) if (strcmp(test_name,MAKETEST_EXPAND_AND_QUOTE(GENTESTNAME(X,Y))) == 0) { return GENTESTNAME(X,Y)(); } if (0)
#define METHOD_EPILOG() return FAIL("Could not call test named %s",test_name);}
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif

#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#endif /* ENABLECALLBYNAME */

#ifdef BUILD_PHASE_07

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif

#define METHOD_PROLOG() static struct EvilUnitTestResult call_test_by_number(size_t test_number) { size_t local_number = 0; (void)local_number;
#define TEST_BLOCK_HEADER(X,Y) if (test_number == local_number) { return GENTESTNAME(X,Y)(); } local_number++; if (0)
#define METHOD_EPILOG() return FAIL("Could not call test number %li",(long)test_number);}
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif

#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif


#ifdef BUILD_PHASE_08

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif

#define METHOD_PROLOG() static struct EvilUnitTestResult null_function_08(void) {
#define TEST_BLOCK_HEADER(X,Y) if (0)
#define METHOD_EPILOG() return FAIL("Called null_function_08"); }

#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif

#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif


#ifdef BUILD_PHASE_09

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif

#define METHOD_PROLOG() static struct EvilUnitTestResult null_function_09(void) {
#define TEST_BLOCK_HEADER(X,Y) if (0)
#define METHOD_EPILOG() return FAIL("Called null_function_09"); }

#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif

#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif



#ifdef BUILD_PHASE_10

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif

#define DEPENDS(X) int MAKETEST_CONCAT(EvilUnitTraverse_,X)(struct EvilUnitAddress * address, size_t depth, struct EvilUnitTraverseFunction * function_to_call, size_t * numeric_parameter, struct EvilUnitTestModule * module_parameter);

#define METHOD_PROLOG() static struct EvilUnitTestResult null_function_10(void) {
#define TEST_BLOCK_HEADER(X,Y) if (0)
#define METHOD_EPILOG() return FAIL("Called null_function_10"); }
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif
#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_11

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif

#define DEPEND_PROLOG() int MAKETEST_CONCAT(EvilUnitTraverse_,MODULE)(struct EvilUnitAddress * address, size_t depth, struct EvilUnitTraverseFunction * function_to_call, size_t * numeric_parameter, struct EvilUnitTestModule * module_parameter) { size_t next_route; size_t local_number = 0; int rc; if (EvilUnit_traverse_at_destination(address,depth)) { switch (function_to_call->func) { case EnumGetIdentity: return EvilUnitGetIdentity(address, module_parameter,LOCALMODULENAME); case EnumGetNumberOfDependencies: return GetNumberOfDependencies(numeric_parameter); case EnumGetNumberOfLocalTests: return GetNumberOfLocalTests(numeric_parameter); case EnumGetNthDependency: return EvilUnitGetNthDependency(address, numeric_parameter, module_parameter); case EnumRunAllTests: return RunAllTests(module_parameter); default: assert(false); } } else { rc = EvilUnit_traverse_next_route(address,depth,&next_route); if (rc) {return rc;}
#define DEPENDS(X) if (next_route == local_number) { return MAKETEST_CONCAT(EvilUnitTraverse_,X)(address,depth+1,function_to_call,numeric_parameter,module_parameter); } local_number++;

#define DEPEND_EPILOG() (void)local_number; } return 1; }

#define METHOD_PROLOG() static struct EvilUnitTestResult null_function_11(void) {
#define TEST_BLOCK_HEADER(X,Y) if (0)
#define METHOD_EPILOG() return FAIL("Called null_function_11"); }
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif
#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_12

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif
#define METHOD_PROLOG() static struct EvilUnitTestResult null_function_12(void) {
#define TEST_BLOCK_HEADER(X,Y) if (0)
#define METHOD_EPILOG() return FAIL("Called null_function_12"); }
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif
#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_13

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif
#define METHOD_PROLOG() static struct EvilUnitTestResult null_function_13(void) {
#define TEST_BLOCK_HEADER(X,Y) if (0)
#define METHOD_EPILOG() return FAIL("Called null_function_13"); }
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif
#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_14

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif
#define METHOD_PROLOG() static struct EvilUnitTestResult null_function_14(void) {
#define TEST_BLOCK_HEADER(X,Y) if (0)
#define METHOD_EPILOG() return FAIL("Called null_function_14"); }
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif
#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_15

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif
#define METHOD_PROLOG() static struct EvilUnitTestResult null_function_15(void) {
#define TEST_BLOCK_HEADER(X,Y) if (0)
#define METHOD_EPILOG() return FAIL("Called null_function_15"); }
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE


#ifndef MACROLEVEL
#define MACROLEVEL 10
#endif

#if (defined (GENERATE_SINGLE_FUNCTION) && defined (GENERATE_TEST_FUNCTIONS))
#error "Cannot define both generate_single_function and generate_test_functions"
#endif

#ifndef GENERATE_TEST_FUNCTIONS
#define GENERATE_SINGLE_FUNCTION
#endif

#ifdef DISABLEDEPENDS
#ifdef DEPENDS
#undef DEPENDS
#endif
#endif

#ifndef DEPEND_PROLOG
#define DEPEND_PROLOG()
#endif
#ifndef DEPENDS
#define DEPENDS(X)
#endif
#ifndef DEPEND_EPILOG
#define DEPEND_EPILOG()
#endif

#ifndef METHOD_PROLOG
#define METHOD_PROLOG()
#endif
#ifndef TEST_BLOCK_HEADER
#error "Require macro definition of TEST_BLOCK_HEADER"
#endif
#ifndef METHOD_EPILOG
#define METHOD_EPILOG()
#endif

#define FIRST_TEST_RUN(X,Y) DEPEND_EPILOG() METHOD_PROLOG() SIMPLE_TEST_RUN(X,Y)
#define OTHER_TEST_RUN(X,Y) FINALISE_TEST_RUN() SIMPLE_TEST_RUN(X,Y)

#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP(); EvilUnit_Phase = UNITTEST_CODE;







#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK OPTIONAL_USER_SETUP_LABEL() SETUP();





#endif

#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif

#define FINALISE_TEST_RUN() OPTIONAL_USER_TEARDOWN_LABEL() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }






/* There is currently no setup label as nothing needs to jump to there */
#if defined(GENERATE_TEST_FUNCTIONS)
#define OPTIONAL_USER_TEARDOWN_LABEL() LABEL_UNITTEST_TEARDOWN:EvilUnit_Phase = UNITTEST_TEARDOWN;
#define OPTIONAL_USER_SETUP_LABEL()
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define OPTIONAL_USER_TEARDOWN_LABEL()
#define OPTIONAL_USER_SETUP_LABEL()
#endif

#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EvilUnit_Phase = UNITTEST_SETUP;{



#define EvilUnit_TEARDOWN_BLOCK } LABEL_FRAMEWORK_TEARDOWN:EvilUnit_Phase = FRAMEWORK_TEARDOWN; EvilUnit_FINAL_RETURN; LABEL_FRAMEWORK_ERROR: RETURNVALUE = FAIL("FrameworkError"); EvilUnit_FINAL_RETURN; EvilUnit_JUNCTION_CODE;







#endif

#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif


#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); (void) RETURNVALUE; (void) RETURNFLAG





#endif

#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")



#endif

#if (MACROLEVEL > 4)
#define EvilUnit_JUNCTION_CODE LABEL_FRAMEWORK_JUNCTION: ; switch (EvilUnit_Phase) { case FRAMEWORK_SETUP: goto LABEL_FRAMEWORK_ERROR; case UNITTEST_SETUP: goto LABEL_FRAMEWORK_TEARDOWN; case UNITTEST_CODE: goto LABEL_UNITTEST_TEARDOWN; case UNITTEST_TEARDOWN: goto LABEL_FRAMEWORK_TEARDOWN; case FRAMEWORK_TEARDOWN: goto LABEL_FRAMEWORK_ERROR; case FRAMEWORK_FINAL_RETURN: goto LABEL_FRAMEWORK_ERROR; default: goto LABEL_FRAMEWORK_ERROR; }
#endif

#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) goto LABEL_FRAMEWORK_JUNCTION; else RETURNVALUE =
#endif
#endif

DEPEND_PROLOG()

#endif
#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif

#ifdef BUILD_PHASE_16

/* Now conclude and clean up the macros */

#ifndef TESTMODULE_IS_EMPTY
#if (PREDICTED_COUNTER == __COUNTER__) /* Only true if there are no tests listed */
#define TESTMODULE_IS_EMPTY 1
#endif
#endif

#ifdef TESTMODULE_IS_EMPTY
DEPEND_EPILOG()
METHOD_PROLOG()
METHOD_EPILOG()
#else
FINALISE_TEST_RUN()
METHOD_EPILOG()
#endif

#undef CLEANUP_MACROS
#ifdef DEPEND_PROLOG
#undef DEPEND_PROLOG
#endif
#ifdef DEPENDS
#undef DEPENDS
#endif
#ifdef DEPEND_EPILOG
#undef DEPEND_EPILOG
#endif
#ifdef METHOD_PROLOG
#undef METHOD_PROLOG
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef METHOD_EPILOG
#undef METHOD_EPILOG
#endif
#ifdef EvilUnit_FINAL_RETURN
#undef EvilUnit_FINAL_RETURN
#endif
#ifdef EvilUnit_JUNCTION_CODE
#undef EvilUnit_JUNCTION_CODE
#endif
#ifdef EvilUnit_LOCAL_VARIABLES
#undef EvilUnit_LOCAL_VARIABLES
#endif
#ifdef EvilUnit_STARTUP_BLOCK
#undef EvilUnit_STARTUP_BLOCK
#endif
#ifdef EvilUnit_TEARDOWN_BLOCK
#undef EvilUnit_TEARDOWN_BLOCK
#endif
#ifdef FINALISE_TEST_RUN
#undef FINALISE_TEST_RUN
#endif
#ifdef FIRST_TEST_RUN
#undef FIRST_TEST_RUN
#endif
#ifdef GENERATE_SINGLE_FUNCTION
#undef GENERATE_SINGLE_FUNCTION
#endif
#ifdef GENERATE_TEST_FUNCTIONS
#undef GENERATE_TEST_FUNCTIONS
#endif
#ifdef MACROLEVEL
#undef MACROLEVEL
#endif
#ifdef OPTIONAL_USER_SETUP_LABEL
#undef OPTIONAL_USER_SETUP_LABEL
#endif
#ifdef OPTIONAL_USER_TEARDOWN_LABEL
#undef OPTIONAL_USER_TEARDOWN_LABEL
#endif
#ifdef OTHER_TEST_RUN
#undef OTHER_TEST_RUN
#endif
#ifdef SIMPLE_TEST_RUN
#undef SIMPLE_TEST_RUN
#endif
#ifdef TEST_BLOCK_HEADER
#undef TEST_BLOCK_HEADER
#endif
#ifdef return
#undef return
#endif
/* Finally write out the functions that require no file inclusion */

/* The functions which don't need access to DEPENDS() or TEST(){} macros */

/*
 * The call to disguise the unused setup/teardown functions is currently here as this is the
 * first function that is certain to be defined
 */

static size_t get_number_of_tests(void)
{
  struct EvilUnitTestResult discarded_result;
  size_t number = 0;
  discarded_result = internal_get_number_of_tests(&number);
  assert(isPass(discarded_result));
  (void)discarded_result;
  return number;
}

static size_t get_test_number_from_name(const char *test_name)
{
  struct EvilUnitTestResult discarded_result;
  size_t number = 0;
  discarded_result = internal_get_test_number_from_name(test_name,&number);
  (void)discarded_result;
  return number;
}
static const char * get_test_name_from_number(size_t test_number)
{
  struct EvilUnitTestResult discarded_result;
  char * test_name = NULL;
  discarded_result = internal_get_test_name_from_number(test_number,&test_name);
  (void)discarded_result;
  return (const char *)test_name;
}
static int internal_self_test(void)
{
  const size_t number_tests = get_number_of_tests();
  size_t idx;
  size_t num;
  for (idx = 0; idx < number_tests; idx++)
    {
      num = get_test_number_from_name(get_test_name_from_number(idx));
      if (num != idx)
        {
          return 1;
        }
    }
  return 0;
}

static void silence_compiler(void)
{
  EvilUnit_Disguise_setup_teardown();
  (void)LOCALMODULENAME;
  (void)null_function_08();
  (void)null_function_09();
  (void)null_function_10();
  (void)null_function_11();
  (void)null_function_12();
  (void)null_function_13();
  (void)null_function_14();
  (void)null_function_15();
  return;
}



/* Graph traversal wrapper functions */
static int GetNumberOfDependencies(size_t * number)
{
  const size_t number_dependencies = get_number_of_dependencies();
  *number = number_dependencies;
  return 0;
}

static int GetNumberOfLocalTests(size_t * number)
{
  const size_t number_tests = get_number_of_tests();
  *number = number_tests;
  return 0;
}

static int RunAllTests(struct EvilUnitTestModule * module)
{
  struct EvilUnitTestResult result;
  const size_t number_tests = get_number_of_tests();
  size_t i;
  int rc;

  silence_compiler();
  assert(internal_self_test() == 0);

  for (i = 0; i < number_tests; i++)
    {
      result = call_test_by_number(i);
      rc = EvilUnit_insert_result(&result,module,i);
      if (rc) {return rc;}
    }

  return 0;
}

#ifdef DEFINETESTMAIN
#ifndef MODULE
#error "Require a definition for MODULE in order to know which tests to run"
#endif

/* Embed the nocstl_EvilUnitAmalgamation implementation here, for the main module only */




static char init_stack_char (void)
{
  char local = 0;
  return local;
}

static int dtor_stack_char (char *data)
{
  if (data == NULL)
    {
      return 1;
    }
  *data = init_stack_char ();
  return 0;
}

static int ctor_stack_char (char *data)
{
  int rc;
  rc = dtor_stack_char (data);
  return rc;
}

static bool equal_char (const char *lhs, const char *rhs)
{
  return ((*lhs) == (*rhs));
}

static int copy_char (const char *in, char *out)
{
  int rc;
  rc = ctor_stack_char (out);
  if (rc)
    {
      return rc;
    }
  *out = (char) *in;
  if (!equal_char (in, out))
    {
      return 1;
    }
  return 0;
}

static int move_char (char *in, char *out)
{
  int rc;
  rc = copy_char (in, out);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_char (in);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static size_t init_stack_size_t (void)
{
  size_t local = 0;
  return local;
}

static int dtor_stack_size_t (size_t * data)
{
  if (data == NULL)
    {
      return 1;
    }
  *data = init_stack_size_t ();
  return 0;
}

static int ctor_stack_size_t (size_t * data)
{
  int rc;
  rc = dtor_stack_size_t (data);
  return rc;
}

static bool equal_size_t (const size_t * lhs, const size_t * rhs)
{
  return ((*lhs) == (*rhs));
}

static int copy_size_t (const size_t * in, size_t * out)
{
  int rc;
  rc = ctor_stack_size_t (out);
  if (rc)
    {
      return rc;
    }
  *out = (size_t) * in;
  if (!equal_size_t (in, out))
    {
      return 1;
    }
  return 0;
}

static int move_size_t (size_t * in, size_t * out)
{
  int rc;
  rc = copy_size_t (in, out);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_size_t (in);
  if (rc)
    {
      return rc;
    }
  return 0;
}
struct array_size_t
{
  enum DESIGNCONTRACT contract_state;
  size_t *data;
  size_t allocated;
};

struct vector_size_t
{
  enum DESIGNCONTRACT contract_state;
  size_t size;
  struct array_size_t data;
};

struct EvilUnitAddress
{
  enum DESIGNCONTRACT contract_state;
  struct vector_size_t data;
};

static struct EvilUnitAddress init_stack_EvilUnitAddress (void);
static int ctor_stack_EvilUnitAddress (struct EvilUnitAddress *);
static int dtor_stack_EvilUnitAddress (struct EvilUnitAddress *);

static bool equal_EvilUnitAddress (const struct EvilUnitAddress *lhs, const struct EvilUnitAddress *rhs);

static int copy_EvilUnitAddress (const struct EvilUnitAddress *in, struct EvilUnitAddress *out);

static int move_EvilUnitAddress (struct EvilUnitAddress *in, struct EvilUnitAddress *out);

static size_t get_capacity_array_size_t (const struct array_size_t *array);

static int resize_array_size_t (struct array_size_t *array, size_t len);

static int resize_atleast_array_size_t (struct array_size_t *array, size_t new_size);

static struct array_size_t init_stack_array_size_t (void);
static int ctor_stack_array_size_t (struct array_size_t *);
static int dtor_stack_array_size_t (struct array_size_t *);

static bool equal_array_size_t (const struct array_size_t *lhs, const struct array_size_t *rhs);

static int copy_array_size_t (const struct array_size_t *in, struct array_size_t *out);

static int move_array_size_t (struct array_size_t *in, struct array_size_t *out);

static bool is_power_two (size_t value)
{
  return (value != 0) && ((value & (value - 1)) == 0);
}

static size_t next_power_of_two (size_t n)
{
  if (n == 0)
    {
      return 1;
    }
  n--;
  n |= n >> 1;
  n |= n >> 2;
  if (sizeof (size_t) >= sizeof (uint8_t))
    {
      n |= n >> 4;
    }
  if (sizeof (size_t) >= sizeof (uint16_t))
    {
      n |= n >> 8;
    }
  if (sizeof (size_t) >= sizeof (uint32_t))
    {
      n |= n >> 16;
    }

  n++;
  assert (is_power_two (n));
  return n;
}

static size_t *init_stack_size_t_ptr (void)
{
  size_t *local = 0;
  return local;
}

static int dtor_stack_size_t_ptr (size_t * *data)
{
  if (data == NULL)
    {
      return 1;
    }
  *data = init_stack_size_t_ptr ();
  return 0;
}

static int ctor_stack_size_t_ptr (size_t * *data)
{
  int rc;
  rc = dtor_stack_size_t_ptr (data);
  return rc;
}

static size_t get_capacity_array_size_t (const struct array_size_t *array)
{
  return array->allocated;
}

enum RETCODE
{ SUCCESS = 0, FAILURE = 1 };

static void initialise_array_size_t (struct array_size_t *data);
static enum RETCODE constructor_array_size_t (struct array_size_t *data);
static enum RETCODE destructor_array_size_t (struct array_size_t *data);

static void set_contract_state_initialised_array_size_t (struct array_size_t *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_array_size_t (struct array_size_t *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_array_size_t (struct array_size_t *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_array_size_t (struct array_size_t *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_array_size_t (struct array_size_t *data)
{
  size_t i = 0;
  (void) i;

  data->data = init_stack_size_t_ptr ();
  data->allocated = init_stack_size_t ();

  set_contract_state_initialised_array_size_t (data);
  assert (contract_state_is_initialised_array_size_t (data));
  return;
}

static enum RETCODE constructor_array_size_t (struct array_size_t *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_array_size_t (data) || contract_state_is_constructed_array_size_t (data));

  rc = destructor_array_size_t (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  ext_rc = ctor_stack_size_t_ptr (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_size_t (&(data->allocated));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_array_size_t (data);
  assert (contract_state_is_constructed_array_size_t (data));
  return SUCCESS;
}

static enum RETCODE destructor_array_size_t (struct array_size_t *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_array_size_t (data) || contract_state_is_constructed_array_size_t (data));

  ext_rc = dtor_stack_size_t_ptr (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_size_t (&(data->allocated));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_array_size_t (data);
  assert (contract_state_is_initialised_array_size_t (data));
  return SUCCESS;
}

static int pointer_valid_block_size_t (size_t * data)
{
  if (data == NULL)
    {
      return 0;
    }

  return 1;
}

static enum RETCODE allocate_block_size_t (size_t ** data, size_t len)
{

  assert (*data == NULL);

  assert (len > 0);

  *data = malloc ((sizeof **data) * len);

  assert (*data != NULL);
  assert (pointer_valid_block_size_t (*data));

  if (*data == NULL)
    {
      return FAILURE;
    }
  else
    {
      return SUCCESS;
    }
}

static enum RETCODE reallocate_block_size_t (size_t ** data, size_t len)
{
  size_t *newpointer;

  assert (*data != NULL);

  assert (len > 0);

  newpointer = realloc (*data, len * (sizeof **data));

  assert (*data != NULL);

  if (newpointer == NULL)
    {
      return FAILURE;
    }

  *data = newpointer;
  assert (*data != NULL);
  return SUCCESS;
}

static enum RETCODE deallocate_block_size_t (size_t ** data, size_t len)
{

  (void) len;

  assert ((*data == NULL) || (pointer_valid_block_size_t (*data)));
  if (*data != NULL)
    {
      free (*data);
      *data = NULL;
    }
  assert (*data == NULL);

  return SUCCESS;
}

static int apply_init_ctor_range_array_size_t (size_t * array, size_t start, size_t end)
{
  size_t i;
  int rc;
  if (start > end)
    {
      return 1;
    }
  for (i = start; i != end; i++)
    {
      array[i] = init_stack_size_t ();
      rc = ctor_stack_size_t (&(array[i]));
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static int apply_dtor_range_array_size_t (size_t * array, size_t start, size_t end)
{
  size_t i;
  int rc;
  if (start > end)
    {
      return 1;
    }

  for (i = start; i != end; i++)
    {
      rc = dtor_stack_size_t (&(array[i]));
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static struct array_size_t init_stack_array_size_t (void);
static int ctor_stack_array_size_t (struct array_size_t *);
static int dtor_stack_array_size_t (struct array_size_t *);

struct array_size_t init_stack_array_size_t (void)
{
  struct array_size_t data;
  initialise_array_size_t (&data);
  return data;
}

static int ctor_stack_array_size_t (struct array_size_t *data)
{
  if (constructor_array_size_t (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_array_size_t (struct array_size_t *array)
{
  int rc;

  if (array->allocated > 0)
    {
      rc = apply_dtor_range_array_size_t (array->data, 0, array->allocated);
      if (rc)
        {
          return rc;
        }

      if (deallocate_block_size_t (&(array->data), array->allocated) != SUCCESS)
        {
          return 1;
        }
    }
  if (destructor_array_size_t (array) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int resize_array_size_t (struct array_size_t *array, size_t len)
{
  int rc;
  if (len == array->allocated)
    {
      return 0;
    }

  if (len == 0)
    {
      return dtor_stack_array_size_t (array);
    }

  if (array->allocated == 0)
    {

      if (allocate_block_size_t (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      rc = apply_init_ctor_range_array_size_t (array->data, 0, len);
      if (rc)
        {
          return rc;
        }
      array->allocated = len;
      return 0;
    }

  if (len > array->allocated)
    {
      if (reallocate_block_size_t (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      rc = apply_init_ctor_range_array_size_t (array->data, array->allocated, len);
      if (rc)
        {
          return rc;
        }
      array->allocated = len;
      return 0;
    }

  if (len < array->allocated)
    {
      rc = apply_dtor_range_array_size_t (array->data, len, array->allocated);
      if (rc)
        {
          return rc;
        }
      if (reallocate_block_size_t (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      array->allocated = len;
      return 0;
    }
  return 1;
}

static bool resize_required_atleast_array_size_t (size_t current, size_t required)
{
  assert (current == 0 || is_power_two (current));
  return (required > current);
}

static int resize_atleast_array_size_t (struct array_size_t *array, size_t new_size)
{

  size_t capacity = get_capacity_array_size_t (array);
  size_t expanded = next_power_of_two (new_size);
  int rc;

  if (resize_required_atleast_array_size_t (capacity, new_size))
    {
      rc = resize_array_size_t (array, expanded);
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static bool equal_array_size_t (const struct array_size_t *lhs, const struct array_size_t *rhs)
{
  size_t i = 0;
  size_t allocated;

  if (lhs->allocated != rhs->allocated)
    {
      return false;
    }

  allocated = lhs->allocated;

  for (i = 0; i < allocated; i++)
    {
      if (!equal_size_t (&(lhs->data[i]), &(rhs->data[i])))
        {
          return false;
        }
    }
  return true;
}

static int copy_array_size_t (const struct array_size_t *in, struct array_size_t *out)
{
  int rc;
  size_t i;
  size_t capacity;

  rc = ctor_stack_array_size_t (out);
  if (rc)
    {
      return rc;
    }

  capacity = get_capacity_array_size_t (in);
  rc = resize_array_size_t (out, capacity);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < capacity; i++)
    {
      rc = copy_size_t (&(in->data[i]), &(out->data[i]));
      if (rc)
        {
          return rc;
        }
    }

  assert (get_capacity_array_size_t (in) == get_capacity_array_size_t (out));

  for (i = 0; i < capacity; i++)
    {
      assert (equal_size_t (&(in->data[i]), &(out->data[i])));
    }

  return 0;
}

static int move_array_size_t (struct array_size_t *in, struct array_size_t *out)
{
  int rc;
  const size_t capacity = get_capacity_array_size_t (in);

  rc = ctor_stack_array_size_t (out);
  if (rc)
    {
      return rc;
    }

  out->data = in->data;

  in->data = NULL;

  out->allocated = capacity;
  in->allocated = 0;

  rc = dtor_stack_array_size_t (in);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int get_by_index_vector_size_t (struct vector_size_t *vector, size_t index, size_t * value);

static int set_by_index_vector_size_t (size_t * value, struct vector_size_t *vector, size_t index);

static int push_back_vector_size_t (size_t * value, struct vector_size_t *vector);

static struct vector_size_t init_stack_vector_size_t (void);
static int ctor_stack_vector_size_t (struct vector_size_t *);
static int dtor_stack_vector_size_t (struct vector_size_t *);

static bool equal_vector_size_t (const struct vector_size_t *lhs, const struct vector_size_t *rhs);

static int copy_vector_size_t (const struct vector_size_t *in, struct vector_size_t *out);

static int move_vector_size_t (struct vector_size_t *in, struct vector_size_t *out);

static int get_by_index_impl_vector_size_t (struct vector_size_t *vector, size_t index, size_t * value)
{
  int rc;
  rc = resize_atleast_array_size_t (&(vector->data), index + 1);
  if (rc)
    {
      return rc;
    }
  rc = copy_size_t (&((vector->data).data[index]), value);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static int get_by_index_vector_size_t (struct vector_size_t *vector, size_t index, size_t * value)
{
  int rc;
  size_t new_array_capacity;

  rc = get_by_index_impl_vector_size_t (vector, index, value);
  if (rc)
    {
      return rc;
    }

  new_array_capacity = get_capacity_array_size_t (&(vector->data));

  assert (new_array_capacity > index);
  return 0;
}

static int set_by_index_impl_vector_size_t (size_t * value, struct vector_size_t *vector, size_t index)
{
  int rc;
  rc = resize_atleast_array_size_t (&(vector->data), index + 1);
  if (rc)
    {
      return rc;
    }

  if (index >= vector->size)
    {
      vector->size = index + 1;
    }

  rc = copy_size_t (value, &((vector->data).data[index]));
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int set_by_index_vector_size_t (size_t * value, struct vector_size_t *vector, size_t index)
{
  size_t localcopy = init_stack_size_t ();
  size_t retrieved = init_stack_size_t ();
  struct vector_size_t vector_before = init_stack_vector_size_t ();
  int rc;
  size_t i;
  size_t new_array_capacity;
  size_t old_array_capacity = get_capacity_array_size_t (&(vector->data));
  rc = copy_size_t (value, &localcopy);
  if (rc)
    {
      return rc;
    }

  rc = copy_vector_size_t (vector, &vector_before);
  if (rc)
    {
      return rc;
    }

  rc = set_by_index_impl_vector_size_t (value, vector, index);
  if (rc)
    {
      return rc;
    }

  new_array_capacity = get_capacity_array_size_t (&(vector->data));
  assert (new_array_capacity > index);

  rc = get_by_index_vector_size_t (vector, index, &retrieved);
  if (rc)
    {
      return rc;
    }
  assert (equal_size_t (&localcopy, &retrieved));

  for (i = 0; i < old_array_capacity; i++)
    {
      if (i == index)
        {
          continue;
        }
      assert (equal_size_t (&(vector->data).data[i], &(vector_before.data).data[i]));
    }

  assert (equal_size_t (&(vector->data).data[index], &localcopy));

  rc = dtor_stack_size_t (&localcopy);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_size_t (&retrieved);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_vector_size_t (&vector_before);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int push_back_impl_vector_size_t (size_t * value, struct vector_size_t *vector)
{
  return set_by_index_vector_size_t (value, vector, vector->size);
}

static int push_back_vector_size_t (size_t * value, struct vector_size_t *vector)
{
  size_t size_before = vector->size;
  size_t size_after;
  struct vector_size_t vector_before = init_stack_vector_size_t ();
  size_t value_before = init_stack_size_t ();
  size_t value_check = init_stack_size_t ();
  int rc;
  size_t i;

  rc = copy_vector_size_t (vector, &vector_before);
  if (rc)
    {
      return rc;
    }
  rc = copy_size_t (value, &value_before);
  if (rc)
    {
      return rc;
    }
  rc = ctor_stack_size_t (&value_check);
  if (rc)
    {
      return rc;
    }

  rc = push_back_impl_vector_size_t (value, vector);
  if (rc)
    {
      return rc;
    }

  size_after = vector->size;
  assert (size_after == size_before + 1);

  for (i = 0; i < size_before; i++)
    {
      assert (equal_size_t (&((vector->data).data[i]), &(vector_before.data).data[i]));
    }

  assert (equal_size_t (&((vector->data).data[size_after - 1]), &(value_before)));

  rc = get_by_index_vector_size_t (vector, size_after - 1, &value_check);
  if (rc)
    {
      return rc;
    }
  assert (equal_size_t (&(value_check), &(value_before)));

  rc = dtor_stack_size_t (&value_check);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_size_t (&value_before);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_vector_size_t (&vector_before);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static void initialise_vector_size_t (struct vector_size_t *data);
static enum RETCODE constructor_vector_size_t (struct vector_size_t *data);
static enum RETCODE destructor_vector_size_t (struct vector_size_t *data);

static void set_contract_state_initialised_vector_size_t (struct vector_size_t *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_vector_size_t (struct vector_size_t *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_vector_size_t (struct vector_size_t *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_vector_size_t (struct vector_size_t *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_vector_size_t (struct vector_size_t *data)
{
  size_t i = 0;
  (void) i;

  data->size = init_stack_size_t ();
  data->data = init_stack_array_size_t ();

  set_contract_state_initialised_vector_size_t (data);
  assert (contract_state_is_initialised_vector_size_t (data));
  return;
}

static enum RETCODE constructor_vector_size_t (struct vector_size_t *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_vector_size_t (data) || contract_state_is_constructed_vector_size_t (data));

  rc = destructor_vector_size_t (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  ext_rc = ctor_stack_size_t (&(data->size));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_array_size_t (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_vector_size_t (data);
  assert (contract_state_is_constructed_vector_size_t (data));
  return SUCCESS;
}

static enum RETCODE destructor_vector_size_t (struct vector_size_t *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_vector_size_t (data) || contract_state_is_constructed_vector_size_t (data));

  ext_rc = dtor_stack_size_t (&(data->size));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_array_size_t (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_vector_size_t (data);
  assert (contract_state_is_initialised_vector_size_t (data));
  return SUCCESS;
}

static struct vector_size_t init_stack_vector_size_t (void);
static int ctor_stack_vector_size_t (struct vector_size_t *);
static int dtor_stack_vector_size_t (struct vector_size_t *);

struct vector_size_t init_stack_vector_size_t (void)
{
  struct vector_size_t data;
  initialise_vector_size_t (&data);
  return data;
}

static int ctor_stack_vector_size_t (struct vector_size_t *data)
{
  if (constructor_vector_size_t (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_vector_size_t (struct vector_size_t *data)
{
  if (destructor_vector_size_t (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static bool equal_vector_size_t (const struct vector_size_t *lhs, const struct vector_size_t *rhs)
{
  size_t i = 0;
  (void) i;

  if (!equal_size_t (&(lhs->size), &(rhs->size)))
    {
      return false;
    }
  if (!equal_array_size_t (&(lhs->data), &(rhs->data)))
    {
      return false;
    }

  return true;
}

static int copy_vector_size_t (const struct vector_size_t *in, struct vector_size_t *out)
{
  int rc;
  size_t i = 0;
  (void) i;
  rc = ctor_stack_vector_size_t (out);
  if (rc)
    {
      return rc;
    }

  rc = copy_size_t (&(in->size), &(out->size));
  if (rc)
    {
      return rc;
    }
  rc = copy_array_size_t (&(in->data), &(out->data));
  if (rc)
    {
      return rc;
    }

  assert (equal_vector_size_t (in, out));

  return 0;
}

static int move_vector_size_t (struct vector_size_t *in, struct vector_size_t *out)
{
  int rc;
  size_t i = 0;
  (void) i;

  rc = ctor_stack_vector_size_t (out);
  if (rc)
    {
      return rc;
    }

  rc = move_size_t (&(in->size), &(out->size));
  if (rc)
    {
      return rc;
    }
  rc = move_array_size_t (&(in->data), &(out->data));
  if (rc)
    {
      return rc;
    }

  rc = dtor_stack_vector_size_t (in);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static void initialise_EvilUnitAddress (struct EvilUnitAddress *data);
static enum RETCODE constructor_EvilUnitAddress (struct EvilUnitAddress *data);
static enum RETCODE destructor_EvilUnitAddress (struct EvilUnitAddress *data);

static void set_contract_state_initialised_EvilUnitAddress (struct EvilUnitAddress *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_EvilUnitAddress (struct EvilUnitAddress *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_EvilUnitAddress (struct EvilUnitAddress *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_EvilUnitAddress (struct EvilUnitAddress *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_EvilUnitAddress (struct EvilUnitAddress *data)
{
  size_t i = 0;
  (void) i;

  data->data = init_stack_vector_size_t ();

  set_contract_state_initialised_EvilUnitAddress (data);
  assert (contract_state_is_initialised_EvilUnitAddress (data));
  return;
}

static enum RETCODE constructor_EvilUnitAddress (struct EvilUnitAddress *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_EvilUnitAddress (data) || contract_state_is_constructed_EvilUnitAddress (data));

  rc = destructor_EvilUnitAddress (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  ext_rc = ctor_stack_vector_size_t (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_EvilUnitAddress (data);
  assert (contract_state_is_constructed_EvilUnitAddress (data));
  return SUCCESS;
}

static enum RETCODE destructor_EvilUnitAddress (struct EvilUnitAddress *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_EvilUnitAddress (data) || contract_state_is_constructed_EvilUnitAddress (data));

  ext_rc = dtor_stack_vector_size_t (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_EvilUnitAddress (data);
  assert (contract_state_is_initialised_EvilUnitAddress (data));
  return SUCCESS;
}

static struct EvilUnitAddress init_stack_EvilUnitAddress (void);
static int ctor_stack_EvilUnitAddress (struct EvilUnitAddress *);
static int dtor_stack_EvilUnitAddress (struct EvilUnitAddress *);

struct EvilUnitAddress init_stack_EvilUnitAddress (void)
{
  struct EvilUnitAddress data;
  initialise_EvilUnitAddress (&data);
  return data;
}

static int ctor_stack_EvilUnitAddress (struct EvilUnitAddress *data)
{
  if (constructor_EvilUnitAddress (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_EvilUnitAddress (struct EvilUnitAddress *data)
{
  if (destructor_EvilUnitAddress (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static bool equal_EvilUnitAddress (const struct EvilUnitAddress *lhs, const struct EvilUnitAddress *rhs)
{
  size_t i = 0;
  (void) i;

  if (!equal_vector_size_t (&(lhs->data), &(rhs->data)))
    {
      return false;
    }

  return true;
}

static int copy_EvilUnitAddress (const struct EvilUnitAddress *in, struct EvilUnitAddress *out)
{
  int rc;
  size_t i = 0;
  (void) i;
  rc = ctor_stack_EvilUnitAddress (out);
  if (rc)
    {
      return rc;
    }

  rc = copy_vector_size_t (&(in->data), &(out->data));
  if (rc)
    {
      return rc;
    }

  assert (equal_EvilUnitAddress (in, out));

  return 0;
}

static int move_EvilUnitAddress (struct EvilUnitAddress *in, struct EvilUnitAddress *out)
{
  int rc;
  size_t i = 0;
  (void) i;

  rc = ctor_stack_EvilUnitAddress (out);
  if (rc)
    {
      return rc;
    }

  rc = move_vector_size_t (&(in->data), &(out->data));
  if (rc)
    {
      return rc;
    }

  rc = dtor_stack_EvilUnitAddress (in);
  if (rc)
    {
      return rc;
    }
  return 0;
}





static int append_to_address (size_t * location, struct EvilUnitAddress *address);
static int retrieve_next_address (struct EvilUnitAddress *address, size_t * index, size_t * next);
static bool at_destination_address (struct EvilUnitAddress *address, size_t * index);



static int append_to_address (size_t * location, struct EvilUnitAddress *address)
{
  return push_back_vector_size_t (location, &(address->data));
}

static int retrieve_next_address (struct EvilUnitAddress *address, size_t * index, size_t * next)
{
  size_t vector_size = (address->data).size;
  if (*index >= vector_size)
    {
      return 1;
    }
  return get_by_index_vector_size_t (&(address->data), *index, next);
}

static bool at_destination_address (struct EvilUnitAddress *address, size_t * index)
{
  size_t vector_size = (address->data).size;
  return (*index == vector_size);
}
struct array_EvilUnitTestResult
{
  enum DESIGNCONTRACT contract_state;
  struct EvilUnitTestResult *data;
  size_t allocated;
};

struct vector_EvilUnitTestResult
{
  enum DESIGNCONTRACT contract_state;
  size_t size;
  struct array_EvilUnitTestResult data;
};

static struct EvilUnitTestResult init_stack_EvilUnitTestResult (void);
static int ctor_stack_EvilUnitTestResult (struct EvilUnitTestResult *);
static int dtor_stack_EvilUnitTestResult (struct EvilUnitTestResult *);

static bool equal_EvilUnitTestResult (const struct EvilUnitTestResult *lhs, const struct EvilUnitTestResult *rhs);

static int copy_EvilUnitTestResult (const struct EvilUnitTestResult *in, struct EvilUnitTestResult *out);

static int get_by_index_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *vector, size_t index, struct EvilUnitTestResult *value);

static int set_by_index_vector_EvilUnitTestResult (struct EvilUnitTestResult *value, struct vector_EvilUnitTestResult *vector, size_t index);

static struct vector_EvilUnitTestResult init_stack_vector_EvilUnitTestResult (void);
static int ctor_stack_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *);
static int dtor_stack_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *);

static bool equal_vector_EvilUnitTestResult (const struct vector_EvilUnitTestResult *lhs, const struct vector_EvilUnitTestResult *rhs);

static int copy_vector_EvilUnitTestResult (const struct vector_EvilUnitTestResult *in, struct vector_EvilUnitTestResult *out);

static int move_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *in, struct vector_EvilUnitTestResult *out);

static enum RESULT init_stack_enum_Result (void)
{
  enum RESULT local = 0;
  return local;
}

static int dtor_stack_enum_Result (enum RESULT *data)
{
  if (data == NULL)
    {
      return 1;
    }
  *data = init_stack_enum_Result ();
  return 0;
}

static int ctor_stack_enum_Result (enum RESULT *data)
{
  int rc;
  rc = dtor_stack_enum_Result (data);
  return rc;
}

static bool equal_enum_Result (const enum RESULT *lhs, const enum RESULT *rhs)
{
  return ((*lhs) == (*rhs));
}

static int copy_enum_Result (const enum RESULT *in, enum RESULT *out)
{
  int rc;
  rc = ctor_stack_enum_Result (out);
  if (rc)
    {
      return rc;
    }
  *out = (enum RESULT) *in;
  if (!equal_enum_Result (in, out))
    {
      return 1;
    }
  return 0;
}

static void initialise_EvilUnitTestResult (struct EvilUnitTestResult *data);
static enum RETCODE constructor_EvilUnitTestResult (struct EvilUnitTestResult *data);
static enum RETCODE destructor_EvilUnitTestResult (struct EvilUnitTestResult *data);

static void set_contract_state_initialised_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  size_t i = 0;
  (void) i;

  for (i = 0; i < (127 + 1); i++)
    {
      data->string[i] = init_stack_char ();
    }
  for (i = 0; i < (127 + 1); i++)
    {
      data->testname[i] = init_stack_char ();
    }
  data->res = init_stack_enum_Result ();

  set_contract_state_initialised_EvilUnitTestResult (data);
  assert (contract_state_is_initialised_EvilUnitTestResult (data));
  return;
}

static enum RETCODE constructor_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_EvilUnitTestResult (data) || contract_state_is_constructed_EvilUnitTestResult (data));

  rc = destructor_EvilUnitTestResult (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  for (i = 0; i < (127 + 1); i++)
    {
      ext_rc = ctor_stack_char (&(data->string[i]));
      if (ext_rc)
        {
          return FAILURE;
        }
    }
  for (i = 0; i < (127 + 1); i++)
    {
      ext_rc = ctor_stack_char (&(data->testname[i]));
      if (ext_rc)
        {
          return FAILURE;
        }
    }
  ext_rc = ctor_stack_enum_Result (&(data->res));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_EvilUnitTestResult (data);
  assert (contract_state_is_constructed_EvilUnitTestResult (data));
  return SUCCESS;
}

static enum RETCODE destructor_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_EvilUnitTestResult (data) || contract_state_is_constructed_EvilUnitTestResult (data));

  for (i = 0; i < (127 + 1); i++)
    {
      ext_rc = dtor_stack_char (&(data->string[i]));
      if (ext_rc)
        {
          return FAILURE;
        }
    }
  for (i = 0; i < (127 + 1); i++)
    {
      ext_rc = dtor_stack_char (&(data->testname[i]));
      if (ext_rc)
        {
          return FAILURE;
        }
    }
  ext_rc = dtor_stack_enum_Result (&(data->res));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_EvilUnitTestResult (data);
  assert (contract_state_is_initialised_EvilUnitTestResult (data));
  return SUCCESS;
}

static struct EvilUnitTestResult init_stack_EvilUnitTestResult (void);
static int ctor_stack_EvilUnitTestResult (struct EvilUnitTestResult *);
static int dtor_stack_EvilUnitTestResult (struct EvilUnitTestResult *);

struct EvilUnitTestResult init_stack_EvilUnitTestResult (void)
{
  struct EvilUnitTestResult data;
  initialise_EvilUnitTestResult (&data);
  return data;
}

static int ctor_stack_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  if (constructor_EvilUnitTestResult (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  if (destructor_EvilUnitTestResult (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static bool equal_EvilUnitTestResult (const struct EvilUnitTestResult *lhs, const struct EvilUnitTestResult *rhs)
{
  size_t i = 0;
  (void) i;

  for (i = 0; i < (127 + 1); i++)
    {
      if (!equal_char (&(lhs->string[i]), &(rhs->string[i])))
        {
          return false;
        }
    }
  for (i = 0; i < (127 + 1); i++)
    {
      if (!equal_char (&(lhs->testname[i]), &(rhs->testname[i])))
        {
          return false;
        }
    }
  if (!equal_enum_Result (&(lhs->res), &(rhs->res)))
    {
      return false;
    }

  return true;
}

static int copy_EvilUnitTestResult (const struct EvilUnitTestResult *in, struct EvilUnitTestResult *out)
{
  int rc;
  size_t i = 0;
  (void) i;
  rc = ctor_stack_EvilUnitTestResult (out);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < (127 + 1); i++)
    {
      rc = copy_char (&(in->string[i]), &(out->string[i]));
      if (rc)
        {
          return rc;
        }
    }
  for (i = 0; i < (127 + 1); i++)
    {
      rc = copy_char (&(in->testname[i]), &(out->testname[i]));
      if (rc)
        {
          return rc;
        }
    }
  rc = copy_enum_Result (&(in->res), &(out->res));
  if (rc)
    {
      return rc;
    }

  assert (equal_EvilUnitTestResult (in, out));

  return 0;
}

static size_t get_capacity_array_EvilUnitTestResult (const struct array_EvilUnitTestResult *array);

static int resize_array_EvilUnitTestResult (struct array_EvilUnitTestResult *array, size_t len);

static int resize_atleast_array_EvilUnitTestResult (struct array_EvilUnitTestResult *array, size_t new_size);

static struct array_EvilUnitTestResult init_stack_array_EvilUnitTestResult (void);
static int ctor_stack_array_EvilUnitTestResult (struct array_EvilUnitTestResult *);
static int dtor_stack_array_EvilUnitTestResult (struct array_EvilUnitTestResult *);

static bool equal_array_EvilUnitTestResult (const struct array_EvilUnitTestResult *lhs, const struct array_EvilUnitTestResult *rhs);

static int copy_array_EvilUnitTestResult (const struct array_EvilUnitTestResult *in, struct array_EvilUnitTestResult *out);

static int move_array_EvilUnitTestResult (struct array_EvilUnitTestResult *in, struct array_EvilUnitTestResult *out);

static struct EvilUnitTestResult *init_stack_EvilUnitTestResult_ptr (void)
{
  struct EvilUnitTestResult *local = 0;
  return local;
}

static int dtor_stack_EvilUnitTestResult_ptr (struct EvilUnitTestResult **data)
{
  if (data == NULL)
    {
      return 1;
    }
  *data = init_stack_EvilUnitTestResult_ptr ();
  return 0;
}

static int ctor_stack_EvilUnitTestResult_ptr (struct EvilUnitTestResult **data)
{
  int rc;
  rc = dtor_stack_EvilUnitTestResult_ptr (data);
  return rc;
}

static size_t get_capacity_array_EvilUnitTestResult (const struct array_EvilUnitTestResult *array)
{
  return array->allocated;
}

static void initialise_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data);
static enum RETCODE constructor_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data);
static enum RETCODE destructor_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data);

static void set_contract_state_initialised_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data)
{
  size_t i = 0;
  (void) i;

  data->data = init_stack_EvilUnitTestResult_ptr ();
  data->allocated = init_stack_size_t ();

  set_contract_state_initialised_array_EvilUnitTestResult (data);
  assert (contract_state_is_initialised_array_EvilUnitTestResult (data));
  return;
}

static enum RETCODE constructor_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_array_EvilUnitTestResult (data) || contract_state_is_constructed_array_EvilUnitTestResult (data));

  rc = destructor_array_EvilUnitTestResult (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  ext_rc = ctor_stack_EvilUnitTestResult_ptr (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_size_t (&(data->allocated));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_array_EvilUnitTestResult (data);
  assert (contract_state_is_constructed_array_EvilUnitTestResult (data));
  return SUCCESS;
}

static enum RETCODE destructor_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_array_EvilUnitTestResult (data) || contract_state_is_constructed_array_EvilUnitTestResult (data));

  ext_rc = dtor_stack_EvilUnitTestResult_ptr (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_size_t (&(data->allocated));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_array_EvilUnitTestResult (data);
  assert (contract_state_is_initialised_array_EvilUnitTestResult (data));
  return SUCCESS;
}

static int pointer_valid_block_EvilUnitTestResult (struct EvilUnitTestResult *data)
{
  if (data == NULL)
    {
      return 0;
    }

  return 1;
}

static enum RETCODE allocate_block_EvilUnitTestResult (struct EvilUnitTestResult **data, size_t len)
{

  assert (*data == NULL);

  assert (len > 0);

  *data = malloc ((sizeof **data) * len);

  assert (*data != NULL);
  assert (pointer_valid_block_EvilUnitTestResult (*data));

  if (*data == NULL)
    {
      return FAILURE;
    }
  else
    {
      return SUCCESS;
    }
}

static enum RETCODE reallocate_block_EvilUnitTestResult (struct EvilUnitTestResult **data, size_t len)
{
  struct EvilUnitTestResult *newpointer;

  assert (*data != NULL);

  assert (len > 0);

  newpointer = realloc (*data, len * (sizeof **data));

  assert (*data != NULL);

  if (newpointer == NULL)
    {
      return FAILURE;
    }

  *data = newpointer;
  assert (*data != NULL);
  return SUCCESS;
}

static enum RETCODE deallocate_block_EvilUnitTestResult (struct EvilUnitTestResult **data, size_t len)
{

  (void) len;

  assert ((*data == NULL) || (pointer_valid_block_EvilUnitTestResult (*data)));
  if (*data != NULL)
    {
      free (*data);
      *data = NULL;
    }
  assert (*data == NULL);

  return SUCCESS;
}

static int apply_init_ctor_range_array_EvilUnitTestResult (struct EvilUnitTestResult *array, size_t start, size_t end)
{
  size_t i;
  int rc;
  if (start > end)
    {
      return 1;
    }
  for (i = start; i != end; i++)
    {
      array[i] = init_stack_EvilUnitTestResult ();
      rc = ctor_stack_EvilUnitTestResult (&(array[i]));
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static int apply_dtor_range_array_EvilUnitTestResult (struct EvilUnitTestResult *array, size_t start, size_t end)
{
  size_t i;
  int rc;
  if (start > end)
    {
      return 1;
    }

  for (i = start; i != end; i++)
    {
      rc = dtor_stack_EvilUnitTestResult (&(array[i]));
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static struct array_EvilUnitTestResult init_stack_array_EvilUnitTestResult (void);
static int ctor_stack_array_EvilUnitTestResult (struct array_EvilUnitTestResult *);
static int dtor_stack_array_EvilUnitTestResult (struct array_EvilUnitTestResult *);

struct array_EvilUnitTestResult init_stack_array_EvilUnitTestResult (void)
{
  struct array_EvilUnitTestResult data;
  initialise_array_EvilUnitTestResult (&data);
  return data;
}

static int ctor_stack_array_EvilUnitTestResult (struct array_EvilUnitTestResult *data)
{
  if (constructor_array_EvilUnitTestResult (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_array_EvilUnitTestResult (struct array_EvilUnitTestResult *array)
{
  int rc;

  if (array->allocated > 0)
    {
      rc = apply_dtor_range_array_EvilUnitTestResult (array->data, 0, array->allocated);
      if (rc)
        {
          return rc;
        }

      if (deallocate_block_EvilUnitTestResult (&(array->data), array->allocated) != SUCCESS)
        {
          return 1;
        }
    }
  if (destructor_array_EvilUnitTestResult (array) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int resize_array_EvilUnitTestResult (struct array_EvilUnitTestResult *array, size_t len)
{
  int rc;
  if (len == array->allocated)
    {
      return 0;
    }

  if (len == 0)
    {
      return dtor_stack_array_EvilUnitTestResult (array);
    }

  if (array->allocated == 0)
    {

      if (allocate_block_EvilUnitTestResult (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      rc = apply_init_ctor_range_array_EvilUnitTestResult (array->data, 0, len);
      if (rc)
        {
          return rc;
        }
      array->allocated = len;
      return 0;
    }

  if (len > array->allocated)
    {
      if (reallocate_block_EvilUnitTestResult (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      rc = apply_init_ctor_range_array_EvilUnitTestResult (array->data, array->allocated, len);
      if (rc)
        {
          return rc;
        }
      array->allocated = len;
      return 0;
    }

  if (len < array->allocated)
    {
      rc = apply_dtor_range_array_EvilUnitTestResult (array->data, len, array->allocated);
      if (rc)
        {
          return rc;
        }
      if (reallocate_block_EvilUnitTestResult (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      array->allocated = len;
      return 0;
    }
  return 1;
}

static bool resize_required_atleast_array_EvilUnitTestResult (size_t current, size_t required)
{
  assert (current == 0 || is_power_two (current));
  return (required > current);
}

static int resize_atleast_array_EvilUnitTestResult (struct array_EvilUnitTestResult *array, size_t new_size)
{

  size_t capacity = get_capacity_array_EvilUnitTestResult (array);
  size_t expanded = next_power_of_two (new_size);
  int rc;

  if (resize_required_atleast_array_EvilUnitTestResult (capacity, new_size))
    {
      rc = resize_array_EvilUnitTestResult (array, expanded);
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static bool equal_array_EvilUnitTestResult (const struct array_EvilUnitTestResult *lhs, const struct array_EvilUnitTestResult *rhs)
{
  size_t i = 0;
  size_t allocated;

  if (lhs->allocated != rhs->allocated)
    {
      return false;
    }

  allocated = lhs->allocated;

  for (i = 0; i < allocated; i++)
    {
      if (!equal_EvilUnitTestResult (&(lhs->data[i]), &(rhs->data[i])))
        {
          return false;
        }
    }
  return true;
}

static int copy_array_EvilUnitTestResult (const struct array_EvilUnitTestResult *in, struct array_EvilUnitTestResult *out)
{
  int rc;
  size_t i;
  size_t capacity;

  rc = ctor_stack_array_EvilUnitTestResult (out);
  if (rc)
    {
      return rc;
    }

  capacity = get_capacity_array_EvilUnitTestResult (in);
  rc = resize_array_EvilUnitTestResult (out, capacity);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < capacity; i++)
    {
      rc = copy_EvilUnitTestResult (&(in->data[i]), &(out->data[i]));
      if (rc)
        {
          return rc;
        }
    }

  assert (get_capacity_array_EvilUnitTestResult (in) == get_capacity_array_EvilUnitTestResult (out));

  for (i = 0; i < capacity; i++)
    {
      assert (equal_EvilUnitTestResult (&(in->data[i]), &(out->data[i])));
    }

  return 0;
}

static int move_array_EvilUnitTestResult (struct array_EvilUnitTestResult *in, struct array_EvilUnitTestResult *out)
{
  int rc;
  const size_t capacity = get_capacity_array_EvilUnitTestResult (in);

  rc = ctor_stack_array_EvilUnitTestResult (out);
  if (rc)
    {
      return rc;
    }

  out->data = in->data;

  in->data = NULL;

  out->allocated = capacity;
  in->allocated = 0;

  rc = dtor_stack_array_EvilUnitTestResult (in);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int get_by_index_impl_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *vector, size_t index, struct EvilUnitTestResult *value)
{
  int rc;
  rc = resize_atleast_array_EvilUnitTestResult (&(vector->data), index + 1);
  if (rc)
    {
      return rc;
    }
  rc = copy_EvilUnitTestResult (&((vector->data).data[index]), value);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static int get_by_index_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *vector, size_t index, struct EvilUnitTestResult *value)
{
  int rc;
  size_t new_array_capacity;

  rc = get_by_index_impl_vector_EvilUnitTestResult (vector, index, value);
  if (rc)
    {
      return rc;
    }

  new_array_capacity = get_capacity_array_EvilUnitTestResult (&(vector->data));

  assert (new_array_capacity > index);
  return 0;
}

static int set_by_index_impl_vector_EvilUnitTestResult (struct EvilUnitTestResult *value, struct vector_EvilUnitTestResult *vector, size_t index)
{
  int rc;
  rc = resize_atleast_array_EvilUnitTestResult (&(vector->data), index + 1);
  if (rc)
    {
      return rc;
    }

  if (index >= vector->size)
    {
      vector->size = index + 1;
    }

  rc = copy_EvilUnitTestResult (value, &((vector->data).data[index]));
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int set_by_index_vector_EvilUnitTestResult (struct EvilUnitTestResult *value, struct vector_EvilUnitTestResult *vector, size_t index)
{
  struct EvilUnitTestResult localcopy = init_stack_EvilUnitTestResult ();
  struct EvilUnitTestResult retrieved = init_stack_EvilUnitTestResult ();
  struct vector_EvilUnitTestResult vector_before = init_stack_vector_EvilUnitTestResult ();
  int rc;
  size_t i;
  size_t new_array_capacity;
  size_t old_array_capacity = get_capacity_array_EvilUnitTestResult (&(vector->data));
  rc = copy_EvilUnitTestResult (value, &localcopy);
  if (rc)
    {
      return rc;
    }

  rc = copy_vector_EvilUnitTestResult (vector, &vector_before);
  if (rc)
    {
      return rc;
    }

  rc = set_by_index_impl_vector_EvilUnitTestResult (value, vector, index);
  if (rc)
    {
      return rc;
    }

  new_array_capacity = get_capacity_array_EvilUnitTestResult (&(vector->data));
  assert (new_array_capacity > index);

  rc = get_by_index_vector_EvilUnitTestResult (vector, index, &retrieved);
  if (rc)
    {
      return rc;
    }
  assert (equal_EvilUnitTestResult (&localcopy, &retrieved));

  for (i = 0; i < old_array_capacity; i++)
    {
      if (i == index)
        {
          continue;
        }
      assert (equal_EvilUnitTestResult (&(vector->data).data[i], &(vector_before.data).data[i]));
    }

  assert (equal_EvilUnitTestResult (&(vector->data).data[index], &localcopy));

  rc = dtor_stack_EvilUnitTestResult (&localcopy);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_EvilUnitTestResult (&retrieved);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_vector_EvilUnitTestResult (&vector_before);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static void initialise_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data);
static enum RETCODE constructor_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data);
static enum RETCODE destructor_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data);

static void set_contract_state_initialised_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  size_t i = 0;
  (void) i;

  data->size = init_stack_size_t ();
  data->data = init_stack_array_EvilUnitTestResult ();

  set_contract_state_initialised_vector_EvilUnitTestResult (data);
  assert (contract_state_is_initialised_vector_EvilUnitTestResult (data));
  return;
}

static enum RETCODE constructor_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_vector_EvilUnitTestResult (data) || contract_state_is_constructed_vector_EvilUnitTestResult (data));

  rc = destructor_vector_EvilUnitTestResult (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  ext_rc = ctor_stack_size_t (&(data->size));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_array_EvilUnitTestResult (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_vector_EvilUnitTestResult (data);
  assert (contract_state_is_constructed_vector_EvilUnitTestResult (data));
  return SUCCESS;
}

static enum RETCODE destructor_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_vector_EvilUnitTestResult (data) || contract_state_is_constructed_vector_EvilUnitTestResult (data));

  ext_rc = dtor_stack_size_t (&(data->size));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_array_EvilUnitTestResult (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_vector_EvilUnitTestResult (data);
  assert (contract_state_is_initialised_vector_EvilUnitTestResult (data));
  return SUCCESS;
}

static struct vector_EvilUnitTestResult init_stack_vector_EvilUnitTestResult (void);
static int ctor_stack_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *);
static int dtor_stack_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *);

struct vector_EvilUnitTestResult init_stack_vector_EvilUnitTestResult (void)
{
  struct vector_EvilUnitTestResult data;
  initialise_vector_EvilUnitTestResult (&data);
  return data;
}

static int ctor_stack_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  if (constructor_vector_EvilUnitTestResult (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *data)
{
  if (destructor_vector_EvilUnitTestResult (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static bool equal_vector_EvilUnitTestResult (const struct vector_EvilUnitTestResult *lhs, const struct vector_EvilUnitTestResult *rhs)
{
  size_t i = 0;
  (void) i;

  if (!equal_size_t (&(lhs->size), &(rhs->size)))
    {
      return false;
    }
  if (!equal_array_EvilUnitTestResult (&(lhs->data), &(rhs->data)))
    {
      return false;
    }

  return true;
}

static int copy_vector_EvilUnitTestResult (const struct vector_EvilUnitTestResult *in, struct vector_EvilUnitTestResult *out)
{
  int rc;
  size_t i = 0;
  (void) i;
  rc = ctor_stack_vector_EvilUnitTestResult (out);
  if (rc)
    {
      return rc;
    }

  rc = copy_size_t (&(in->size), &(out->size));
  if (rc)
    {
      return rc;
    }
  rc = copy_array_EvilUnitTestResult (&(in->data), &(out->data));
  if (rc)
    {
      return rc;
    }

  assert (equal_vector_EvilUnitTestResult (in, out));

  return 0;
}

static int move_vector_EvilUnitTestResult (struct vector_EvilUnitTestResult *in, struct vector_EvilUnitTestResult *out)
{
  int rc;
  size_t i = 0;
  (void) i;

  rc = ctor_stack_vector_EvilUnitTestResult (out);
  if (rc)
    {
      return rc;
    }

  rc = move_size_t (&(in->size), &(out->size));
  if (rc)
    {
      return rc;
    }
  rc = move_array_EvilUnitTestResult (&(in->data), &(out->data));
  if (rc)
    {
      return rc;
    }

  rc = dtor_stack_vector_EvilUnitTestResult (in);
  if (rc)
    {
      return rc;
    }
  return 0;
}




int isPass (struct EvilUnitTestResult retval);
int isFail (struct EvilUnitTestResult retval);
int isSkip (struct EvilUnitTestResult retval);
int isOther (struct EvilUnitTestResult retval);

void EvilUnit_print_result_summary (struct EvilUnitTestResult *results, size_t num_results, const char *modulename);

void EvilUnit_print_result_standard (struct EvilUnitTestResult *results, size_t num_results, const char *modulename);

void EvilUnit_print_result_detailed (struct EvilUnitTestResult *results, size_t num_results, const char *modulename);

void EvilUnit_SetTestName (struct EvilUnitTestResult *retval, char *testname);

struct EvilUnitTestResult PASS (const char *msg, ...);
struct EvilUnitTestResult FAIL (const char *msg, ...);
struct EvilUnitTestResult SKIP (const char *msg, ...);
struct EvilUnitTestResult INIT (const char *msg, ...);
struct EvilUnitTestResult FAKE (const char *msg, ...);



static int EvilUnit_vsnprintf (char *str, size_t size, const char *format, va_list arg)
{
  (void) size;
  vsprintf (str, format, arg);
  return -1;
}

static const char *colour_pass (void)
{
  return "\x1b[32m";
};

static const char *colour_fail (void)
{
  return "\x1b[31m";
};

static const char *colour_skip (void)
{
  return "\x1b[34m";
};

static const char *colour_other (void)
{
  return "\x1b[31m";
};

static const char *string_pass (void)
{
  return "PASS";
};

static const char *string_fail (void)
{
  return "FAIL";
};

static char *string_skip (void)
{
  return "SKIP";
};

static char *string_other (void)
{
  return "????";
};

int isPass (struct EvilUnitTestResult retval)
{
  return (retval.res == flag_PASS);
}

int isFail (struct EvilUnitTestResult retval)
{
  return (retval.res == flag_FAIL);
}

int isSkip (struct EvilUnitTestResult retval)
{
  return (retval.res == flag_SKIP);
}

int isOther (struct EvilUnitTestResult retval)
{
  return !(isPass (retval) || isFail (retval) || isSkip (retval));
}

static const char *colour_result (struct EvilUnitTestResult data)
{
  if (isPass (data))
    {
      return colour_pass ();
    }
  if (isSkip (data))
    {
      return colour_skip ();
    }
  if (isFail (data))
    {
      return colour_fail ();
    }
  return colour_other ();
};

static const char *string_result (struct EvilUnitTestResult data)
{
  if (isPass (data))
    {
      return string_pass ();
    }
  if (isSkip (data))
    {
      return string_skip ();
    }
  if (isFail (data))
    {
      return string_fail ();
    }
  return string_other ();
};

static void print_module_result (const char *res_name, const char *res_colour, const char *modulename, size_t numerator, size_t denominator)
{

  unsigned long ul_numerator = numerator;
  unsigned long ul_denominator = denominator;
  if ((numerator > 0) || (denominator == 0))
    {
      printf ("[ %s%s%s ] %-20s %lu/%lu\n", res_colour, res_name, "\x1b[0m", modulename, ul_numerator, ul_denominator);
    }
  return;
}

static void print_test_result (const char *res_name, const char *res_colour, const char *modulename, const char *test_name, const char *test_string)
{
  printf ("[ %s%s%s ] %-20s %-20s %-20s\n", res_colour, res_name, "\x1b[0m", modulename, test_name, test_string);
  return;
}

static void print_result_general (struct EvilUnitTestResult *results, size_t num_results, const char *modulename, int detail_level)
{
  size_t idx;
  size_t num_pass = 0;
  size_t num_fail = 0;
  size_t num_skip = 0;
  size_t num_other = 0;

  if (detail_level < 1)
    {
      return;
    }

  if (num_results == 0)
    {
      num_pass = 0;
      print_module_result ("VOID", colour_skip (), modulename, num_pass, num_results);
      return;
    }

  for (idx = 0; idx < num_results; idx++)
    {
      if (isPass (results[idx]))
        {
          num_pass++;
        }
      if (isFail (results[idx]))
        {
          num_fail++;
        }
      if (isSkip (results[idx]))
        {
          num_skip++;
        }
      if (isOther (results[idx]))
        {
          num_other++;
        }
    }

  print_module_result (string_fail (), colour_fail (), modulename, num_fail, num_results);
  print_module_result (string_skip (), colour_skip (), modulename, num_skip, num_results);
  print_module_result (string_pass (), colour_pass (), modulename, num_pass, num_results);
  print_module_result (string_other (), colour_other (), modulename, num_other, num_results);

  if (detail_level < 2)
    {
      return;
    }

  for (idx = 0; idx < num_results; idx++)
    {
      if ((detail_level == 3) || (!isPass (results[idx])))
        {
          print_test_result (string_result (results[idx]), colour_result (results[idx]), modulename, results[idx].testname, results[idx].string);

        }
    }

  return;
}

void EvilUnit_print_result_summary (struct EvilUnitTestResult *results, size_t num_results, const char *modulename)
{
  print_result_general (results, num_results, modulename, 1);
  return;
}

void EvilUnit_print_result_standard (struct EvilUnitTestResult *results, size_t num_results, const char *modulename)
{
  print_result_general (results, num_results, modulename, 2);
  return;
}

void EvilUnit_print_result_detailed (struct EvilUnitTestResult *results, size_t num_results, const char *modulename)
{
  print_result_general (results, num_results, modulename, 3);
  return;
}

void EvilUnit_SetTestName (struct EvilUnitTestResult *retval, char *testname)
{
  strncpy (retval->testname, testname, 127);
  return;
}

struct EvilUnitTestResult PASS (const char *msg, ...)
{
  enum RESULT flag = flag_PASS;
  struct EvilUnitTestResult retval = init_stack_EvilUnitTestResult ();
  va_list args;
  va_start (args, msg);
  EvilUnit_vsnprintf (retval.string, 127, msg, args);
  retval.res = flag;
  va_end (args);
  return retval;
}

struct EvilUnitTestResult FAIL (const char *msg, ...)
{
  enum RESULT flag = flag_FAIL;
  struct EvilUnitTestResult retval = init_stack_EvilUnitTestResult ();
  va_list args;
  va_start (args, msg);
  EvilUnit_vsnprintf (retval.string, 127, msg, args);
  retval.res = flag;
  va_end (args);
  return retval;
}

struct EvilUnitTestResult SKIP (const char *msg, ...)
{
  enum RESULT flag = flag_SKIP;
  struct EvilUnitTestResult retval = init_stack_EvilUnitTestResult ();
  va_list args;
  va_start (args, msg);
  EvilUnit_vsnprintf (retval.string, 127, msg, args);
  retval.res = flag;
  va_end (args);
  return retval;
}

struct EvilUnitTestResult INIT (const char *msg, ...)
{
  enum RESULT flag = flag_INIT;
  struct EvilUnitTestResult retval = init_stack_EvilUnitTestResult ();
  va_list args;
  va_start (args, msg);
  EvilUnit_vsnprintf (retval.string, 127, msg, args);
  retval.res = flag;
  va_end (args);
  return retval;
}

struct EvilUnitTestResult FAKE (const char *msg, ...)
{
  enum RESULT flag = flag_FAKE;
  struct EvilUnitTestResult retval = init_stack_EvilUnitTestResult ();
  va_list args;
  va_start (args, msg);
  EvilUnit_vsnprintf (retval.string, 127, msg, args);
  retval.res = flag;
  va_end (args);
  return retval;
}



struct EvilUnitTestModule
{
  enum DESIGNCONTRACT contract_state;
  char modulename[(127 + 1)];
  struct EvilUnitAddress address;
  struct vector_EvilUnitTestResult result;
};

struct array_EvilUnitTestModule
{
  enum DESIGNCONTRACT contract_state;
  struct EvilUnitTestModule *data;
  size_t allocated;
};

struct vector_EvilUnitTestModule
{
  enum DESIGNCONTRACT contract_state;
  size_t size;
  struct array_EvilUnitTestModule data;
};

struct queue_EvilUnitTestModule
{
  enum DESIGNCONTRACT contract_state;
  size_t root;
  size_t size;
  struct array_EvilUnitTestModule data;
};

static struct EvilUnitTestModule init_stack_EvilUnitTestModule (void);
static int ctor_stack_EvilUnitTestModule (struct EvilUnitTestModule *);
static int dtor_stack_EvilUnitTestModule (struct EvilUnitTestModule *);

static bool equal_EvilUnitTestModule (const struct EvilUnitTestModule *lhs, const struct EvilUnitTestModule *rhs);

static int copy_EvilUnitTestModule (const struct EvilUnitTestModule *in, struct EvilUnitTestModule *out);

static int move_EvilUnitTestModule (struct EvilUnitTestModule *in, struct EvilUnitTestModule *out);

static int get_by_index_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *vector, size_t index, struct EvilUnitTestModule *value);

static int set_by_index_vector_EvilUnitTestModule (struct EvilUnitTestModule *value, struct vector_EvilUnitTestModule *vector, size_t index);

static int push_back_vector_EvilUnitTestModule (struct EvilUnitTestModule *value, struct vector_EvilUnitTestModule *vector);

static size_t find_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *vector, struct EvilUnitTestModule *value);

static bool contains_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *vector, struct EvilUnitTestModule *value);

static struct vector_EvilUnitTestModule init_stack_vector_EvilUnitTestModule (void);
static int ctor_stack_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *);
static int dtor_stack_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *);

static bool equal_vector_EvilUnitTestModule (const struct vector_EvilUnitTestModule *lhs, const struct vector_EvilUnitTestModule *rhs);

static int copy_vector_EvilUnitTestModule (const struct vector_EvilUnitTestModule *in, struct vector_EvilUnitTestModule *out);

static int push_queue_EvilUnitTestModule (struct EvilUnitTestModule *value, struct queue_EvilUnitTestModule *queue);

static int pop_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *queue, struct EvilUnitTestModule *value);

static struct queue_EvilUnitTestModule init_stack_queue_EvilUnitTestModule (void);
static int ctor_stack_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *);
static int dtor_stack_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *);

static bool equal_queue_EvilUnitTestModule (const struct queue_EvilUnitTestModule *lhs, const struct queue_EvilUnitTestModule *rhs);

static int copy_queue_EvilUnitTestModule (const struct queue_EvilUnitTestModule *in, struct queue_EvilUnitTestModule *out);

static void initialise_EvilUnitTestModule (struct EvilUnitTestModule *data);
static enum RETCODE constructor_EvilUnitTestModule (struct EvilUnitTestModule *data);
static enum RETCODE destructor_EvilUnitTestModule (struct EvilUnitTestModule *data);

static void set_contract_state_initialised_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  size_t i = 0;
  (void) i;

  for (i = 0; i < (127 + 1); i++)
    {
      data->modulename[i] = init_stack_char ();
    }
  data->address = init_stack_EvilUnitAddress ();
  data->result = init_stack_vector_EvilUnitTestResult ();

  set_contract_state_initialised_EvilUnitTestModule (data);
  assert (contract_state_is_initialised_EvilUnitTestModule (data));
  return;
}

static enum RETCODE constructor_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_EvilUnitTestModule (data) || contract_state_is_constructed_EvilUnitTestModule (data));

  rc = destructor_EvilUnitTestModule (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  for (i = 0; i < (127 + 1); i++)
    {
      ext_rc = ctor_stack_char (&(data->modulename[i]));
      if (ext_rc)
        {
          return FAILURE;
        }
    }
  ext_rc = ctor_stack_EvilUnitAddress (&(data->address));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_vector_EvilUnitTestResult (&(data->result));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_EvilUnitTestModule (data);
  assert (contract_state_is_constructed_EvilUnitTestModule (data));
  return SUCCESS;
}

static enum RETCODE destructor_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_EvilUnitTestModule (data) || contract_state_is_constructed_EvilUnitTestModule (data));

  for (i = 0; i < (127 + 1); i++)
    {
      ext_rc = dtor_stack_char (&(data->modulename[i]));
      if (ext_rc)
        {
          return FAILURE;
        }
    }
  ext_rc = dtor_stack_EvilUnitAddress (&(data->address));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_vector_EvilUnitTestResult (&(data->result));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_EvilUnitTestModule (data);
  assert (contract_state_is_initialised_EvilUnitTestModule (data));
  return SUCCESS;
}

static struct EvilUnitTestModule init_stack_EvilUnitTestModule (void);
static int ctor_stack_EvilUnitTestModule (struct EvilUnitTestModule *);
static int dtor_stack_EvilUnitTestModule (struct EvilUnitTestModule *);

struct EvilUnitTestModule init_stack_EvilUnitTestModule (void)
{
  struct EvilUnitTestModule data;
  initialise_EvilUnitTestModule (&data);
  return data;
}

static int ctor_stack_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  if (constructor_EvilUnitTestModule (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  if (destructor_EvilUnitTestModule (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int copy_EvilUnitTestModule (const struct EvilUnitTestModule *in, struct EvilUnitTestModule *out)
{
  int rc;
  size_t i = 0;
  (void) i;
  rc = ctor_stack_EvilUnitTestModule (out);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < (127 + 1); i++)
    {
      rc = copy_char (&(in->modulename[i]), &(out->modulename[i]));
      if (rc)
        {
          return rc;
        }
    }
  rc = copy_EvilUnitAddress (&(in->address), &(out->address));
  if (rc)
    {
      return rc;
    }
  rc = copy_vector_EvilUnitTestResult (&(in->result), &(out->result));
  if (rc)
    {
      return rc;
    }

  assert (equal_EvilUnitTestModule (in, out));

  return 0;
}

static int move_EvilUnitTestModule (struct EvilUnitTestModule *in, struct EvilUnitTestModule *out)
{
  int rc;
  size_t i = 0;
  (void) i;

  rc = ctor_stack_EvilUnitTestModule (out);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < (127 + 1); i++)
    {
      rc = move_char (&(in->modulename[i]), &(out->modulename[i]));
      if (rc)
        {
          return rc;
        }
    }
  rc = move_EvilUnitAddress (&(in->address), &(out->address));
  if (rc)
    {
      return rc;
    }
  rc = move_vector_EvilUnitTestResult (&(in->result), &(out->result));
  if (rc)
    {
      return rc;
    }

  rc = dtor_stack_EvilUnitTestModule (in);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static bool equal_EvilUnitTestModule (const struct EvilUnitTestModule *lhs, const struct EvilUnitTestModule *rhs)
{
  size_t i;
  for (i = 0; i < (127 + 1); i++)
    {
      if (lhs->modulename[i] != rhs->modulename[i])
        {
          return false;
        }
    }

  if (!equal_vector_EvilUnitTestResult (&(lhs->result), &(rhs->result)))
    {
      return false;
    }

  return true;
}

static size_t get_capacity_array_EvilUnitTestModule (const struct array_EvilUnitTestModule *array);

static int resize_array_EvilUnitTestModule (struct array_EvilUnitTestModule *array, size_t len);

static int resize_atleast_array_EvilUnitTestModule (struct array_EvilUnitTestModule *array, size_t new_size);

static struct array_EvilUnitTestModule init_stack_array_EvilUnitTestModule (void);
static int ctor_stack_array_EvilUnitTestModule (struct array_EvilUnitTestModule *);
static int dtor_stack_array_EvilUnitTestModule (struct array_EvilUnitTestModule *);

static bool equal_array_EvilUnitTestModule (const struct array_EvilUnitTestModule *lhs, const struct array_EvilUnitTestModule *rhs);

static int copy_array_EvilUnitTestModule (const struct array_EvilUnitTestModule *in, struct array_EvilUnitTestModule *out);

static struct EvilUnitTestModule *init_stack_EvilUnitTestModule_ptr (void)
{
  struct EvilUnitTestModule *local = 0;
  return local;
}

static int dtor_stack_EvilUnitTestModule_ptr (struct EvilUnitTestModule **data)
{
  if (data == NULL)
    {
      return 1;
    }
  *data = init_stack_EvilUnitTestModule_ptr ();
  return 0;
}

static int ctor_stack_EvilUnitTestModule_ptr (struct EvilUnitTestModule **data)
{
  int rc;
  rc = dtor_stack_EvilUnitTestModule_ptr (data);
  return rc;
}

static size_t get_capacity_array_EvilUnitTestModule (const struct array_EvilUnitTestModule *array)
{
  return array->allocated;
}

static void initialise_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data);
static enum RETCODE constructor_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data);
static enum RETCODE destructor_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data);

static void set_contract_state_initialised_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data)
{
  size_t i = 0;
  (void) i;

  data->data = init_stack_EvilUnitTestModule_ptr ();
  data->allocated = init_stack_size_t ();

  set_contract_state_initialised_array_EvilUnitTestModule (data);
  assert (contract_state_is_initialised_array_EvilUnitTestModule (data));
  return;
}

static enum RETCODE constructor_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_array_EvilUnitTestModule (data) || contract_state_is_constructed_array_EvilUnitTestModule (data));

  rc = destructor_array_EvilUnitTestModule (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  ext_rc = ctor_stack_EvilUnitTestModule_ptr (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_size_t (&(data->allocated));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_array_EvilUnitTestModule (data);
  assert (contract_state_is_constructed_array_EvilUnitTestModule (data));
  return SUCCESS;
}

static enum RETCODE destructor_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_array_EvilUnitTestModule (data) || contract_state_is_constructed_array_EvilUnitTestModule (data));

  ext_rc = dtor_stack_EvilUnitTestModule_ptr (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_size_t (&(data->allocated));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_array_EvilUnitTestModule (data);
  assert (contract_state_is_initialised_array_EvilUnitTestModule (data));
  return SUCCESS;
}

static int pointer_valid_block_EvilUnitTestModule (struct EvilUnitTestModule *data)
{
  if (data == NULL)
    {
      return 0;
    }

  return 1;
}

static enum RETCODE allocate_block_EvilUnitTestModule (struct EvilUnitTestModule **data, size_t len)
{

  assert (*data == NULL);

  assert (len > 0);

  *data = malloc ((sizeof **data) * len);

  assert (*data != NULL);
  assert (pointer_valid_block_EvilUnitTestModule (*data));

  if (*data == NULL)
    {
      return FAILURE;
    }
  else
    {
      return SUCCESS;
    }
}

static enum RETCODE reallocate_block_EvilUnitTestModule (struct EvilUnitTestModule **data, size_t len)
{
  struct EvilUnitTestModule *newpointer;

  assert (*data != NULL);

  assert (len > 0);

  newpointer = realloc (*data, len * (sizeof **data));

  assert (*data != NULL);

  if (newpointer == NULL)
    {
      return FAILURE;
    }

  *data = newpointer;
  assert (*data != NULL);
  return SUCCESS;
}

static enum RETCODE deallocate_block_EvilUnitTestModule (struct EvilUnitTestModule **data, size_t len)
{

  (void) len;

  assert ((*data == NULL) || (pointer_valid_block_EvilUnitTestModule (*data)));
  if (*data != NULL)
    {
      free (*data);
      *data = NULL;
    }
  assert (*data == NULL);

  return SUCCESS;
}

static int apply_init_ctor_range_array_EvilUnitTestModule (struct EvilUnitTestModule *array, size_t start, size_t end)
{
  size_t i;
  int rc;
  if (start > end)
    {
      return 1;
    }
  for (i = start; i != end; i++)
    {
      array[i] = init_stack_EvilUnitTestModule ();
      rc = ctor_stack_EvilUnitTestModule (&(array[i]));
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static int apply_dtor_range_array_EvilUnitTestModule (struct EvilUnitTestModule *array, size_t start, size_t end)
{
  size_t i;
  int rc;
  if (start > end)
    {
      return 1;
    }

  for (i = start; i != end; i++)
    {
      rc = dtor_stack_EvilUnitTestModule (&(array[i]));
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static struct array_EvilUnitTestModule init_stack_array_EvilUnitTestModule (void);
static int ctor_stack_array_EvilUnitTestModule (struct array_EvilUnitTestModule *);
static int dtor_stack_array_EvilUnitTestModule (struct array_EvilUnitTestModule *);

struct array_EvilUnitTestModule init_stack_array_EvilUnitTestModule (void)
{
  struct array_EvilUnitTestModule data;
  initialise_array_EvilUnitTestModule (&data);
  return data;
}

static int ctor_stack_array_EvilUnitTestModule (struct array_EvilUnitTestModule *data)
{
  if (constructor_array_EvilUnitTestModule (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_array_EvilUnitTestModule (struct array_EvilUnitTestModule *array)
{
  int rc;

  if (array->allocated > 0)
    {
      rc = apply_dtor_range_array_EvilUnitTestModule (array->data, 0, array->allocated);
      if (rc)
        {
          return rc;
        }

      if (deallocate_block_EvilUnitTestModule (&(array->data), array->allocated) != SUCCESS)
        {
          return 1;
        }
    }
  if (destructor_array_EvilUnitTestModule (array) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int resize_array_EvilUnitTestModule (struct array_EvilUnitTestModule *array, size_t len)
{
  int rc;
  if (len == array->allocated)
    {
      return 0;
    }

  if (len == 0)
    {
      return dtor_stack_array_EvilUnitTestModule (array);
    }

  if (array->allocated == 0)
    {

      if (allocate_block_EvilUnitTestModule (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      rc = apply_init_ctor_range_array_EvilUnitTestModule (array->data, 0, len);
      if (rc)
        {
          return rc;
        }
      array->allocated = len;
      return 0;
    }

  if (len > array->allocated)
    {
      if (reallocate_block_EvilUnitTestModule (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      rc = apply_init_ctor_range_array_EvilUnitTestModule (array->data, array->allocated, len);
      if (rc)
        {
          return rc;
        }
      array->allocated = len;
      return 0;
    }

  if (len < array->allocated)
    {
      rc = apply_dtor_range_array_EvilUnitTestModule (array->data, len, array->allocated);
      if (rc)
        {
          return rc;
        }
      if (reallocate_block_EvilUnitTestModule (&(array->data), len) != SUCCESS)
        {
          return 1;
        }
      array->allocated = len;
      return 0;
    }
  return 1;
}

static bool resize_required_atleast_array_EvilUnitTestModule (size_t current, size_t required)
{
  assert (current == 0 || is_power_two (current));
  return (required > current);
}

static int resize_atleast_array_EvilUnitTestModule (struct array_EvilUnitTestModule *array, size_t new_size)
{

  size_t capacity = get_capacity_array_EvilUnitTestModule (array);
  size_t expanded = next_power_of_two (new_size);
  int rc;

  if (resize_required_atleast_array_EvilUnitTestModule (capacity, new_size))
    {
      rc = resize_array_EvilUnitTestModule (array, expanded);
      if (rc)
        {
          return rc;
        }
    }
  return 0;
}

static bool equal_array_EvilUnitTestModule (const struct array_EvilUnitTestModule *lhs, const struct array_EvilUnitTestModule *rhs)
{
  size_t i = 0;
  size_t allocated;

  if (lhs->allocated != rhs->allocated)
    {
      return false;
    }

  allocated = lhs->allocated;

  for (i = 0; i < allocated; i++)
    {
      if (!equal_EvilUnitTestModule (&(lhs->data[i]), &(rhs->data[i])))
        {
          return false;
        }
    }
  return true;
}

static int copy_array_EvilUnitTestModule (const struct array_EvilUnitTestModule *in, struct array_EvilUnitTestModule *out)
{
  int rc;
  size_t i;
  size_t capacity;

  rc = ctor_stack_array_EvilUnitTestModule (out);
  if (rc)
    {
      return rc;
    }

  capacity = get_capacity_array_EvilUnitTestModule (in);
  rc = resize_array_EvilUnitTestModule (out, capacity);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < capacity; i++)
    {
      rc = copy_EvilUnitTestModule (&(in->data[i]), &(out->data[i]));
      if (rc)
        {
          return rc;
        }
    }

  assert (get_capacity_array_EvilUnitTestModule (in) == get_capacity_array_EvilUnitTestModule (out));

  for (i = 0; i < capacity; i++)
    {
      assert (equal_EvilUnitTestModule (&(in->data[i]), &(out->data[i])));
    }

  return 0;
}

static int get_by_index_impl_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *vector, size_t index, struct EvilUnitTestModule *value)
{
  int rc;
  rc = resize_atleast_array_EvilUnitTestModule (&(vector->data), index + 1);
  if (rc)
    {
      return rc;
    }
  rc = copy_EvilUnitTestModule (&((vector->data).data[index]), value);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static int get_by_index_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *vector, size_t index, struct EvilUnitTestModule *value)
{
  int rc;
  size_t new_array_capacity;

  rc = get_by_index_impl_vector_EvilUnitTestModule (vector, index, value);
  if (rc)
    {
      return rc;
    }

  new_array_capacity = get_capacity_array_EvilUnitTestModule (&(vector->data));

  assert (new_array_capacity > index);
  return 0;
}

static int set_by_index_impl_vector_EvilUnitTestModule (struct EvilUnitTestModule *value, struct vector_EvilUnitTestModule *vector, size_t index)
{
  int rc;
  rc = resize_atleast_array_EvilUnitTestModule (&(vector->data), index + 1);
  if (rc)
    {
      return rc;
    }

  if (index >= vector->size)
    {
      vector->size = index + 1;
    }

  rc = copy_EvilUnitTestModule (value, &((vector->data).data[index]));
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int set_by_index_vector_EvilUnitTestModule (struct EvilUnitTestModule *value, struct vector_EvilUnitTestModule *vector, size_t index)
{
  struct EvilUnitTestModule localcopy = init_stack_EvilUnitTestModule ();
  struct EvilUnitTestModule retrieved = init_stack_EvilUnitTestModule ();
  struct vector_EvilUnitTestModule vector_before = init_stack_vector_EvilUnitTestModule ();
  int rc;
  size_t i;
  size_t new_array_capacity;
  size_t old_array_capacity = get_capacity_array_EvilUnitTestModule (&(vector->data));
  rc = copy_EvilUnitTestModule (value, &localcopy);
  if (rc)
    {
      return rc;
    }

  rc = copy_vector_EvilUnitTestModule (vector, &vector_before);
  if (rc)
    {
      return rc;
    }

  rc = set_by_index_impl_vector_EvilUnitTestModule (value, vector, index);
  if (rc)
    {
      return rc;
    }

  new_array_capacity = get_capacity_array_EvilUnitTestModule (&(vector->data));
  assert (new_array_capacity > index);

  rc = get_by_index_vector_EvilUnitTestModule (vector, index, &retrieved);
  if (rc)
    {
      return rc;
    }
  assert (equal_EvilUnitTestModule (&localcopy, &retrieved));

  for (i = 0; i < old_array_capacity; i++)
    {
      if (i == index)
        {
          continue;
        }
      assert (equal_EvilUnitTestModule (&(vector->data).data[i], &(vector_before.data).data[i]));
    }

  assert (equal_EvilUnitTestModule (&(vector->data).data[index], &localcopy));

  rc = dtor_stack_EvilUnitTestModule (&localcopy);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_EvilUnitTestModule (&retrieved);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_vector_EvilUnitTestModule (&vector_before);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int push_back_impl_vector_EvilUnitTestModule (struct EvilUnitTestModule *value, struct vector_EvilUnitTestModule *vector)
{
  return set_by_index_vector_EvilUnitTestModule (value, vector, vector->size);
}

static int push_back_vector_EvilUnitTestModule (struct EvilUnitTestModule *value, struct vector_EvilUnitTestModule *vector)
{
  size_t size_before = vector->size;
  size_t size_after;
  struct vector_EvilUnitTestModule vector_before = init_stack_vector_EvilUnitTestModule ();
  struct EvilUnitTestModule value_before = init_stack_EvilUnitTestModule ();
  struct EvilUnitTestModule value_check = init_stack_EvilUnitTestModule ();
  int rc;
  size_t i;

  rc = copy_vector_EvilUnitTestModule (vector, &vector_before);
  if (rc)
    {
      return rc;
    }
  rc = copy_EvilUnitTestModule (value, &value_before);
  if (rc)
    {
      return rc;
    }
  rc = ctor_stack_EvilUnitTestModule (&value_check);
  if (rc)
    {
      return rc;
    }

  rc = push_back_impl_vector_EvilUnitTestModule (value, vector);
  if (rc)
    {
      return rc;
    }

  size_after = vector->size;
  assert (size_after == size_before + 1);

  for (i = 0; i < size_before; i++)
    {
      assert (equal_EvilUnitTestModule (&((vector->data).data[i]), &(vector_before.data).data[i]));
    }

  assert (equal_EvilUnitTestModule (&((vector->data).data[size_after - 1]), &(value_before)));

  rc = get_by_index_vector_EvilUnitTestModule (vector, size_after - 1, &value_check);
  if (rc)
    {
      return rc;
    }
  assert (equal_EvilUnitTestModule (&(value_check), &(value_before)));

  rc = dtor_stack_EvilUnitTestModule (&value_check);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_EvilUnitTestModule (&value_before);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_vector_EvilUnitTestModule (&vector_before);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static size_t find_impl_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *vector, struct EvilUnitTestModule *value)
{
  size_t sentinel = vector->size;
  size_t i;

  for (i = 0; i < sentinel; i++)
    {
      if (equal_EvilUnitTestModule (value, &((vector->data).data[i])))
        {
          return i;
        }
    }
  return sentinel;
}

static size_t find_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *vector, struct EvilUnitTestModule *value)
{
  struct EvilUnitTestModule localcopy = init_stack_EvilUnitTestModule ();
  struct EvilUnitTestModule retrieved = init_stack_EvilUnitTestModule ();
  size_t location;
  int rc;

  rc = ctor_stack_EvilUnitTestModule (&localcopy);
  if (rc)
    {
      return rc;
    }
  rc = ctor_stack_EvilUnitTestModule (&retrieved);
  if (rc)
    {
      return rc;
    }

  rc = copy_EvilUnitTestModule (value, &localcopy);
  if (rc)
    {
      return rc;
    }

  location = find_impl_vector_EvilUnitTestModule (vector, value);

  if (location != vector->size)
    {
      rc = get_by_index_vector_EvilUnitTestModule (vector, location, &retrieved);
      if (rc)
        {
          return rc;
        }
      assert (equal_EvilUnitTestModule (&localcopy, &retrieved));
    }

  rc = dtor_stack_EvilUnitTestModule (&localcopy);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_EvilUnitTestModule (&retrieved);
  if (rc)
    {
      return rc;
    }

  return location;
}

static bool contains_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *vector, struct EvilUnitTestModule *value)
{
  size_t sentinel = vector->size;
  size_t location = find_vector_EvilUnitTestModule (vector, value);
  return (location != sentinel);
}

static void initialise_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data);
static enum RETCODE constructor_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data);
static enum RETCODE destructor_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data);

static void set_contract_state_initialised_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  size_t i = 0;
  (void) i;

  data->size = init_stack_size_t ();
  data->data = init_stack_array_EvilUnitTestModule ();

  set_contract_state_initialised_vector_EvilUnitTestModule (data);
  assert (contract_state_is_initialised_vector_EvilUnitTestModule (data));
  return;
}

static enum RETCODE constructor_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_vector_EvilUnitTestModule (data) || contract_state_is_constructed_vector_EvilUnitTestModule (data));

  rc = destructor_vector_EvilUnitTestModule (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  ext_rc = ctor_stack_size_t (&(data->size));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_array_EvilUnitTestModule (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_vector_EvilUnitTestModule (data);
  assert (contract_state_is_constructed_vector_EvilUnitTestModule (data));
  return SUCCESS;
}

static enum RETCODE destructor_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_vector_EvilUnitTestModule (data) || contract_state_is_constructed_vector_EvilUnitTestModule (data));

  ext_rc = dtor_stack_size_t (&(data->size));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_array_EvilUnitTestModule (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_vector_EvilUnitTestModule (data);
  assert (contract_state_is_initialised_vector_EvilUnitTestModule (data));
  return SUCCESS;
}

static struct vector_EvilUnitTestModule init_stack_vector_EvilUnitTestModule (void);
static int ctor_stack_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *);
static int dtor_stack_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *);

struct vector_EvilUnitTestModule init_stack_vector_EvilUnitTestModule (void)
{
  struct vector_EvilUnitTestModule data;
  initialise_vector_EvilUnitTestModule (&data);
  return data;
}

static int ctor_stack_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  if (constructor_vector_EvilUnitTestModule (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_vector_EvilUnitTestModule (struct vector_EvilUnitTestModule *data)
{
  if (destructor_vector_EvilUnitTestModule (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static bool equal_vector_EvilUnitTestModule (const struct vector_EvilUnitTestModule *lhs, const struct vector_EvilUnitTestModule *rhs)
{
  size_t i = 0;
  (void) i;

  if (!equal_size_t (&(lhs->size), &(rhs->size)))
    {
      return false;
    }
  if (!equal_array_EvilUnitTestModule (&(lhs->data), &(rhs->data)))
    {
      return false;
    }

  return true;
}

static int copy_vector_EvilUnitTestModule (const struct vector_EvilUnitTestModule *in, struct vector_EvilUnitTestModule *out)
{
  int rc;
  size_t i = 0;
  (void) i;
  rc = ctor_stack_vector_EvilUnitTestModule (out);
  if (rc)
    {
      return rc;
    }

  rc = copy_size_t (&(in->size), &(out->size));
  if (rc)
    {
      return rc;
    }
  rc = copy_array_EvilUnitTestModule (&(in->data), &(out->data));
  if (rc)
    {
      return rc;
    }

  assert (equal_vector_EvilUnitTestModule (in, out));

  return 0;
}

static size_t queue_capacity (struct queue_EvilUnitTestModule *queue)
{
  return get_capacity_array_EvilUnitTestModule (&(queue->data));
}

static size_t get_real_index (struct queue_EvilUnitTestModule *queue, size_t index)
{
  size_t root = queue->root;
  size_t capacity = queue_capacity (queue);
  assert (capacity > 0);
  return (root + index) % capacity;
}

static int cycle_queue_impl (struct queue_EvilUnitTestModule *queue)
{

  struct queue_EvilUnitTestModule local_copy = init_stack_queue_EvilUnitTestModule ();
  size_t capacity = queue_capacity (queue);
  size_t old_index;
  size_t i;
  int rc;

  if (queue->root == 0)
    {
      return 0;
    }
  rc = copy_queue_EvilUnitTestModule (queue, &local_copy);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < capacity; i++)
    {
      old_index = get_real_index (&local_copy, i);
      rc = move_EvilUnitTestModule (&((local_copy.data).data[old_index]), &(queue->data).data[i]);
      if (rc)
        {
          return rc;
        }
    }

  rc = dtor_stack_queue_EvilUnitTestModule (&local_copy);
  if (rc)
    {
      return rc;
    }

  queue->root = 0;
  return 0;
}

static int cycle_queue (struct queue_EvilUnitTestModule *queue)
{
  struct queue_EvilUnitTestModule old_queue = init_stack_queue_EvilUnitTestModule ();
  int rc;
  size_t i;
  size_t new_index;
  size_t old_index;

  rc = copy_queue_EvilUnitTestModule (queue, &old_queue);
  if (rc)
    {
      return rc;
    }

  assert (queue->size == old_queue.size);
  assert (queue_capacity (queue) == queue_capacity (&old_queue));
  assert (equal_queue_EvilUnitTestModule (queue, &old_queue));

  rc = cycle_queue_impl (queue);
  if (rc)
    {
      return rc;
    }

  assert (queue->size == old_queue.size);
  assert (queue_capacity (queue) == queue_capacity (&old_queue));

  for (i = 0; i < old_queue.size; i++)
    {
      new_index = get_real_index (queue, i);
      old_index = get_real_index (&old_queue, i);
      assert (equal_EvilUnitTestModule (&((queue->data).data[new_index]), &((old_queue.data).data[old_index])));
    }

  assert (queue->root == 0);

  rc = dtor_stack_queue_EvilUnitTestModule (&old_queue);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static int resize_queue (struct queue_EvilUnitTestModule *queue, size_t new_size)
{
  int rc;
  rc = cycle_queue (queue);
  if (rc)
    {
      return rc;
    }
  rc = resize_atleast_array_EvilUnitTestModule (&(queue->data), new_size);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static int push_impl_queue_EvilUnitTestModule (struct EvilUnitTestModule *value, struct queue_EvilUnitTestModule *queue)
{

  size_t capacity = queue_capacity (queue);
  size_t push_index;
  int rc;

  if (queue->size == capacity)
    {
      rc = resize_queue (queue, queue->size + 1);
      if (rc)
        {
          return rc;
        }
      capacity = queue_capacity (queue);
    }

  push_index = get_real_index (queue, queue->size);

  rc = copy_EvilUnitTestModule (value, &((queue->data).data[push_index]));
  (queue->size)++;
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int push_queue_EvilUnitTestModule (struct EvilUnitTestModule *value, struct queue_EvilUnitTestModule *queue)
{
  size_t old_size = queue->size;
  size_t old_index;
  size_t new_size;
  size_t new_index;
  struct queue_EvilUnitTestModule old_queue = init_stack_queue_EvilUnitTestModule ();
  struct EvilUnitTestModule old_value = init_stack_EvilUnitTestModule ();
  int rc;
  size_t i;

  rc = copy_queue_EvilUnitTestModule (queue, &old_queue);
  if (rc)
    {
      return rc;
    }

  rc = copy_EvilUnitTestModule (value, &old_value);
  if (rc)
    {
      return rc;
    }

  rc = push_impl_queue_EvilUnitTestModule (value, queue);
  if (rc)
    {
      return rc;
    }

  new_size = queue->size;

  assert (new_size == old_size + 1);

  for (i = 0; i < old_size; i++)
    {
      new_index = get_real_index (queue, i);
      old_index = get_real_index (&old_queue, i);
      assert (equal_EvilUnitTestModule (&((queue->data).data[new_index]), &((old_queue.data).data[old_index])));
    }

  assert (equal_EvilUnitTestModule (&((queue->data).data[old_size]), &old_value));

  rc = dtor_stack_EvilUnitTestModule (&old_value);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_queue_EvilUnitTestModule (&old_queue);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int pop_impl_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *queue, struct EvilUnitTestModule *value)
{

  size_t capacity = queue_capacity (queue);
  size_t new_root;
  size_t pop_index;
  int rc;

  if (queue->size == 0)
    {
      return 1;
    }

  if (queue->size < capacity / 4)
    {
      rc = resize_queue (queue, queue->size + 1);
      if (rc)
        {
          return rc;
        }
      capacity = get_capacity_array_EvilUnitTestModule (&(queue->data));
    }

  pop_index = queue->root;
  new_root = (queue->root + 1) % capacity;

  rc = move_EvilUnitTestModule (&((queue->data).data[pop_index]), value);
  (queue->size)--;
  (queue->root) = new_root;
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int pop_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *queue, struct EvilUnitTestModule *value)
{
  size_t old_size = queue->size;
  size_t old_index;
  size_t new_size;
  size_t new_index;
  struct queue_EvilUnitTestModule old_queue = init_stack_queue_EvilUnitTestModule ();
  int rc;
  size_t i;

  rc = copy_queue_EvilUnitTestModule (queue, &old_queue);
  if (rc)
    {
      return rc;
    }

  rc = pop_impl_queue_EvilUnitTestModule (queue, value);
  if (rc)
    {
      return rc;
    }

  new_size = queue->size;

  assert (new_size + 1 == old_size);

  for (i = 1; i < old_size; i++)
    {
      new_index = get_real_index (queue, i - 1);
      old_index = get_real_index (&old_queue, i);
      assert (equal_EvilUnitTestModule (&((queue->data).data[new_index]), &((old_queue.data).data[old_index])));
    }

  old_index = get_real_index (&old_queue, 0);
  assert (equal_EvilUnitTestModule (&((old_queue.data).data[old_index]), value));

  rc = dtor_stack_queue_EvilUnitTestModule (&old_queue);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static void initialise_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data);
static enum RETCODE constructor_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data);
static enum RETCODE destructor_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data);

static void set_contract_state_initialised_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  data->contract_state = INITIALISED;
  return;
}

static void set_contract_state_constructed_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  data->contract_state = CONSTRUCTED;
  return;
}

static int contract_state_is_initialised_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  return (data->contract_state == INITIALISED);
}

static int contract_state_is_constructed_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  return (data->contract_state == CONSTRUCTED);
}

static void initialise_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  size_t i = 0;
  (void) i;

  data->root = init_stack_size_t ();
  data->size = init_stack_size_t ();
  data->data = init_stack_array_EvilUnitTestModule ();

  set_contract_state_initialised_queue_EvilUnitTestModule (data);
  assert (contract_state_is_initialised_queue_EvilUnitTestModule (data));
  return;
}

static enum RETCODE constructor_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  enum RETCODE rc;
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_queue_EvilUnitTestModule (data) || contract_state_is_constructed_queue_EvilUnitTestModule (data));

  rc = destructor_queue_EvilUnitTestModule (data);
  if (rc != SUCCESS)
    {
      return rc;
    }

  ext_rc = ctor_stack_size_t (&(data->root));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_size_t (&(data->size));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = ctor_stack_array_EvilUnitTestModule (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  set_contract_state_constructed_queue_EvilUnitTestModule (data);
  assert (contract_state_is_constructed_queue_EvilUnitTestModule (data));
  return SUCCESS;
}

static enum RETCODE destructor_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  int ext_rc;
  size_t i = 0;
  (void) i;
  assert (contract_state_is_initialised_queue_EvilUnitTestModule (data) || contract_state_is_constructed_queue_EvilUnitTestModule (data));

  ext_rc = dtor_stack_size_t (&(data->root));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_size_t (&(data->size));
  if (ext_rc)
    {
      return FAILURE;
    }
  ext_rc = dtor_stack_array_EvilUnitTestModule (&(data->data));
  if (ext_rc)
    {
      return FAILURE;
    }

  initialise_queue_EvilUnitTestModule (data);
  assert (contract_state_is_initialised_queue_EvilUnitTestModule (data));
  return SUCCESS;
}

static struct queue_EvilUnitTestModule init_stack_queue_EvilUnitTestModule (void);
static int ctor_stack_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *);
static int dtor_stack_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *);

struct queue_EvilUnitTestModule init_stack_queue_EvilUnitTestModule (void)
{
  struct queue_EvilUnitTestModule data;
  initialise_queue_EvilUnitTestModule (&data);
  return data;
}

static int ctor_stack_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  if (constructor_queue_EvilUnitTestModule (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static int dtor_stack_queue_EvilUnitTestModule (struct queue_EvilUnitTestModule *data)
{
  if (destructor_queue_EvilUnitTestModule (data) != SUCCESS)
    {
      return 1;
    }
  return 0;
}

static bool equal_queue_EvilUnitTestModule (const struct queue_EvilUnitTestModule *lhs, const struct queue_EvilUnitTestModule *rhs)
{
  size_t i = 0;
  (void) i;

  if (!equal_size_t (&(lhs->root), &(rhs->root)))
    {
      return false;
    }
  if (!equal_size_t (&(lhs->size), &(rhs->size)))
    {
      return false;
    }
  if (!equal_array_EvilUnitTestModule (&(lhs->data), &(rhs->data)))
    {
      return false;
    }

  return true;
}

static int copy_queue_EvilUnitTestModule (const struct queue_EvilUnitTestModule *in, struct queue_EvilUnitTestModule *out)
{
  int rc;
  size_t i = 0;
  (void) i;
  rc = ctor_stack_queue_EvilUnitTestModule (out);
  if (rc)
    {
      return rc;
    }

  rc = copy_size_t (&(in->root), &(out->root));
  if (rc)
    {
      return rc;
    }
  rc = copy_size_t (&(in->size), &(out->size));
  if (rc)
    {
      return rc;
    }
  rc = copy_array_EvilUnitTestModule (&(in->data), &(out->data));
  if (rc)
    {
      return rc;
    }

  assert (equal_queue_EvilUnitTestModule (in, out));

  return 0;
}




int EvilUnit_insert_result (struct EvilUnitTestResult *result, struct EvilUnitTestModule *module, size_t test_number);
int EvilUnit_retrieve_result (struct EvilUnitTestModule *module, size_t test_number, struct EvilUnitTestResult *result);
bool EvilUnit_traverse_at_destination (struct EvilUnitAddress *address, size_t depth);
int EvilUnit_traverse_next_route (struct EvilUnitAddress *address, size_t depth, size_t * next);
int EvilUnit_create_root_module (struct EvilUnitTestModule *module, const char *modulename);
int EvilUnit_create_test_module (struct EvilUnitTestModule *parent, int dependency_number, struct EvilUnitTestModule *module, const char *modulename);

int EvilUnit_execute (void);

int EvilUnitGetIdentity (struct EvilUnitAddress *address, struct EvilUnitTestModule *module, const char *modulename);
int EvilUnitGetNthDependency (struct EvilUnitAddress *address, size_t * N, struct EvilUnitTestModule *module);



int EvilUnit_insert_result (struct EvilUnitTestResult *result, struct EvilUnitTestModule *module, size_t test_number)
{
  return set_by_index_vector_EvilUnitTestResult (result, &(module->result), test_number);
}

int EvilUnit_retrieve_result (struct EvilUnitTestModule *module, size_t test_number, struct EvilUnitTestResult *result)
{
  return get_by_index_vector_EvilUnitTestResult (&(module->result), test_number, result);
}

bool EvilUnit_traverse_at_destination (struct EvilUnitAddress * address, size_t depth)
{
  return at_destination_address (address, &depth);
}

int EvilUnit_traverse_next_route (struct EvilUnitAddress *address, size_t depth, size_t * next)
{
  return retrieve_next_address (address, &depth, next);
}

int EvilUnitTraverseFromRoot (struct EvilUnitAddress *address, struct EvilUnitTraverseFunction *function_to_call, size_t * numeric_parameter,
                              struct EvilUnitTestModule *module_parameter);

static int ByAddress_GetIdentity (struct EvilUnitAddress *address, struct EvilUnitTestModule *module)
{
  struct EvilUnitTraverseFunction function_to_call = { EnumGetIdentity };
  size_t numeric_parameter = 0;
  return EvilUnitTraverseFromRoot (address, &function_to_call, &numeric_parameter, module);
}

static int ByAddress_GetNumberOfDependencies (struct EvilUnitAddress *address, size_t * number)
{
  struct EvilUnitTraverseFunction function_to_call = { EnumGetNumberOfDependencies };
  struct EvilUnitTestModule module_parameter = init_stack_EvilUnitTestModule ();
  return EvilUnitTraverseFromRoot (address, &function_to_call, number, &module_parameter);
}

static int ByAddress_GetNthDependency (struct EvilUnitAddress *address, size_t * N, struct EvilUnitTestModule *module)
{
  struct EvilUnitTraverseFunction function_to_call = { EnumGetNthDependency };
  return EvilUnitTraverseFromRoot (address, &function_to_call, N, module);
}

static int ByAddress_RunAllTests (struct EvilUnitAddress *address, struct EvilUnitTestModule *module)
{
  struct EvilUnitTraverseFunction function_to_call = { EnumRunAllTests };
  size_t numeric_parameter = 0;
  return EvilUnitTraverseFromRoot (address, &function_to_call, &numeric_parameter, module);
}

static int conditional_push (struct EvilUnitTestModule *current, struct vector_EvilUnitTestModule *set, struct queue_EvilUnitTestModule *queue)
{
  int rc;
  const bool verbose = false;
  if (!contains_vector_EvilUnitTestModule (set, current))
    {
      if (verbose)
        {
          printf ("Pushing new module %s\n", current->modulename);
        }

      rc = push_back_vector_EvilUnitTestModule (current, set);
      if (rc)
        {
          return rc;
        }
      rc = push_queue_EvilUnitTestModule (current, queue);
      if (rc)
        {
          return rc;
        }
    }
  else
    {
      if (verbose)
        {
          printf ("Rejecting known module %s\n", current->modulename);
        }
    }
  return 0;
}

static int EvilUnit_create_test_set_with_resources (struct EvilUnitTestModule *current, struct queue_EvilUnitTestModule *queue, struct EvilUnitAddress *address,
                                                    struct vector_EvilUnitTestModule *set)
{
  int rc;
  size_t i;
  size_t num_dependencies;

  rc = ByAddress_GetIdentity (address, current);
  if (rc)
    {
      return rc;
    }

  rc = conditional_push (current, set, queue);
  if (rc)
    {
      return rc;
    }

  while (queue->size > 0)
    {
      rc = pop_queue_EvilUnitTestModule (queue, current);
      if (rc)
        {
          return rc;
        }

      rc = copy_EvilUnitAddress (&(current->address), address);
      if (rc)
        {
          return rc;
        }

      rc = ByAddress_GetNumberOfDependencies (address, &num_dependencies);
      if (rc)
        {
          return rc;
        }

      for (i = 0; i < num_dependencies; i++)
        {
          rc = ByAddress_GetNthDependency (address, &i, current);
          if (rc)
            {
              return rc;
            }

          rc = conditional_push (current, set, queue);
          if (rc)
            {
              return rc;
            }
        }
    }

  return 0;
}

static int EvilUnit_create_test_set (struct vector_EvilUnitTestModule *set)
{
  struct EvilUnitTestModule module = init_stack_EvilUnitTestModule ();
  struct queue_EvilUnitTestModule queue = init_stack_queue_EvilUnitTestModule ();
  struct EvilUnitAddress address = init_stack_EvilUnitAddress ();

  int rc;
  rc = ctor_stack_EvilUnitTestModule (&module);
  if (rc)
    {
      return rc;
    }
  rc = ctor_stack_queue_EvilUnitTestModule (&queue);
  if (rc)
    {
      return rc;
    }
  rc = ctor_stack_EvilUnitAddress (&address);
  if (rc)
    {
      return rc;
    }

  rc = EvilUnit_create_test_set_with_resources (&module, &queue, &address, set);
  if (rc)
    {
      return rc;
    }

  rc = dtor_stack_EvilUnitAddress (&address);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_queue_EvilUnitTestModule (&queue);
  if (rc)
    {
      return rc;
    }
  rc = dtor_stack_EvilUnitTestModule (&module);
  if (rc)
    {
      return rc;
    }

  return 0;
}

static int EvilUnit_print_test_module (struct EvilUnitTestModule *module)
{

  EvilUnit_print_result_standard (&(module->result.data.data[0]), (module->result).size, module->modulename);
  return 0;
}

static int EvilUnit_print_test_set (struct vector_EvilUnitTestModule *set)
{
  struct EvilUnitTestModule module = init_stack_EvilUnitTestModule ();
  size_t number_modules = set->size;
  size_t i;
  int rc;

  rc = ctor_stack_EvilUnitTestModule (&module);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < number_modules; i++)
    {
      rc = get_by_index_vector_EvilUnitTestModule (set, i, &module);
      if (rc)
        {
          return rc;
        }
      rc = EvilUnit_print_test_module (&module);
      if (rc)
        {
          return rc;
        }
    }

  rc = dtor_stack_EvilUnitTestModule (&module);
  if (rc)
    {
      return rc;
    }
  return 0;
}

static int EvilUnit_evaluate_test_set (struct vector_EvilUnitTestModule *set)
{
  struct EvilUnitTestModule module = init_stack_EvilUnitTestModule ();
  size_t number_modules = set->size;
  size_t i;
  int rc;
  rc = ctor_stack_EvilUnitTestModule (&module);
  if (rc)
    {
      return rc;
    }

  for (i = 0; i < number_modules; i++)
    {
      rc = get_by_index_vector_EvilUnitTestModule (set, i, &module);
      if (rc)
        {
          return rc;
        }

      rc = ByAddress_RunAllTests (&(module.address), &module);
      if (rc)
        {
          return rc;
        }

      rc = set_by_index_vector_EvilUnitTestModule (&module, set, i);
      if (rc)
        {
          return rc;
        }
    }

  rc = dtor_stack_EvilUnitTestModule (&module);
  if (rc)
    {
      return rc;
    }
  return 0;
}

int EvilUnit_execute (void)
{
  struct vector_EvilUnitTestModule test_set = init_stack_vector_EvilUnitTestModule ();
  int rc;
  rc = ctor_stack_vector_EvilUnitTestModule (&test_set);
  if (rc)
    {
      return rc;
    }

  rc = EvilUnit_create_test_set (&test_set);
  if (rc)
    {
      return rc;
    }

  rc = EvilUnit_evaluate_test_set (&test_set);
  if (rc)
    {
      return rc;
    }

  rc = EvilUnit_print_test_set (&test_set);
  if (rc)
    {
      return rc;
    }

  rc = dtor_stack_vector_EvilUnitTestModule (&test_set);
  if (rc)
    {
      return rc;
    }
  return 0;
}

int EvilUnitGetIdentity (struct EvilUnitAddress *address, struct EvilUnitTestModule *module, const char *modulename)
{
  struct EvilUnitTestModule local = init_stack_EvilUnitTestModule ();
  int rc;

  rc = ctor_stack_EvilUnitTestModule (&local);
  if (rc)
    {
      return rc;
    }

  strncpy (local.modulename, modulename, 127);

  rc = copy_EvilUnitAddress (address, &(local.address));
  if (rc)
    {
      return rc;
    }

  rc = move_EvilUnitTestModule (&local, module);
  if (rc)
    {
      return rc;
    }

  return 0;
}

int EvilUnitGetNthDependency (struct EvilUnitAddress *address, size_t * N, struct EvilUnitTestModule *module)
{

  struct EvilUnitAddress newaddress = init_stack_EvilUnitAddress ();
  int rc;

  rc = copy_EvilUnitAddress (address, &newaddress);
  if (rc)
    {
      return rc;
    }

  rc = append_to_address (N, &newaddress);
  if (rc)
    {
      return rc;
    }

  rc = ByAddress_GetIdentity (&newaddress, module);
  if (rc)
    {
      return rc;
    }

  rc = dtor_stack_EvilUnitAddress (&newaddress);
  if (rc)
    {
      return rc;
    }

  return 0;
}

/* Declare structures that are defined elsewhere */
struct EvilUnitAddress;
struct EvilUnitTestModule;
struct EvilUnitTraverseFunction;

/* Declare functions that are defined elsewhere */
int EvilUnit_execute(void);

int MAKETEST_CONCAT(EvilUnitTraverse_,MODULE)(struct EvilUnitAddress * address, size_t depth, struct EvilUnitTraverseFunction * function_to_call, size_t * numeric_parameter, struct EvilUnitTestModule * module_parameter);

int EvilUnitTraverseFromRoot(struct EvilUnitAddress * address, struct EvilUnitTraverseFunction * function_to_call, size_t * numeric_parameter, struct EvilUnitTestModule * module_parameter)
{
  size_t depth = 0;
  return MAKETEST_CONCAT(EvilUnitTraverse_,MODULE)(address,depth,function_to_call,numeric_parameter,module_parameter);
}

int main(void)
{
  return EvilUnit_execute();
}
#endif /* DEFINETESTMAIN */
#endif


#endif /* SKIP_TEMPLATE_TEST_INCLUSION */

#endif /* EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE */


#ifdef EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE
#undef EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE
/* 
 * The multiple file variant of this library includes a file named MANGLE_TESTS
 * in several places. It is a large file. To bring the size of the single file
 * variant of the library down to a more reasonable figure, MANGLE_TESTS is 
 * included in exactly one place, below, and self-recursion is used to execute
 * the contents when required.
 */

/* This file was generated by executing gen_mangle_tests.c */

#ifndef MAKETEST_CONCAT
#error "Expect definition of MAKETEST_CONCAT before inclusion"
#endif
#define TEST(X) TEST_WITHLINE(X,__LINE__)
#define GENTESTNAME(X,Y) MAKETEST_CONCAT(test## _ ## X ## _, Y)

#define TEST_WITHLINE(X,Y) MAKETEST_CONCAT(TEST_COUNT_,__COUNTER__)(X,Y)

/* Search for initial value of counter, up to a maximum of 2^10 = 1024 */
/* Will increment counter by exactly 11 */
#ifdef ORIGINAL_COUNTER
  #undef ORIGINAL_COUNTER
#endif
#ifdef VERIFICATION_COUNTER
  #undef VERIFICATION_COUNTER
#endif
#ifdef PREDICTED_COUNTER
  #undef PREDICTED_COUNTER
#endif
#if (__COUNTER__ == 0)
  #define ORIGINAL_COUNTER 0
  #define PREDICTED_COUNTER 1
#else
  #if (__COUNTER__ <= (512+1)) /* Was [1-512] */
    #if (__COUNTER__ <= (256+2)) /* Was [1-256] */
      #if (__COUNTER__ <= (128+3)) /* Was [1-128] */
        #if (__COUNTER__ <= (64+4)) /* Was [1-64] */
          #if (__COUNTER__ <= (32+5)) /* Was [1-32] */
            #if (__COUNTER__ <= (16+6)) /* Was [1-16] */
              #if (__COUNTER__ <= (8+7)) /* Was [1-8] */
                #if (__COUNTER__ <= (4+8)) /* Was [1-4] */
                  #if (__COUNTER__ <= (2+9)) /* Was [1-2] */
                    #if (__COUNTER__ <= (1+10)) /* Was [1-1] */
                      #define ORIGINAL_COUNTER 1
                      #define VERIFICATION_COUNTER 12
                      #define PREDICTED_COUNTER 13
                    #else /* Was [2-2] */
                      #define ORIGINAL_COUNTER 2
                      #define VERIFICATION_COUNTER 13
                      #define PREDICTED_COUNTER 14
                    #endif
                  #else /* Was [3-4] */
                    #if (__COUNTER__ <= (3+10)) /* Was [3-3] */
                      #define ORIGINAL_COUNTER 3
                      #define VERIFICATION_COUNTER 14
                      #define PREDICTED_COUNTER 15
                    #else /* Was [4-4] */
                      #define ORIGINAL_COUNTER 4
                      #define VERIFICATION_COUNTER 15
                      #define PREDICTED_COUNTER 16
                    #endif
                  #endif
                #else /* Was [5-8] */
                  #if (__COUNTER__ <= (6+9)) /* Was [5-6] */
                    #if (__COUNTER__ <= (5+10)) /* Was [5-5] */
                      #define ORIGINAL_COUNTER 5
                      #define VERIFICATION_COUNTER 16
                      #define PREDICTED_COUNTER 17
                    #else /* Was [6-6] */
                      #define ORIGINAL_COUNTER 6
                      #define VERIFICATION_COUNTER 17
                      #define PREDICTED_COUNTER 18
                    #endif
                  #else /* Was [7-8] */
                    #if (__COUNTER__ <= (7+10)) /* Was [7-7] */
                      #define ORIGINAL_COUNTER 7
                      #define VERIFICATION_COUNTER 18
                      #define PREDICTED_COUNTER 19
                    #else /* Was [8-8] */
                      #define ORIGINAL_COUNTER 8
                      #define VERIFICATION_COUNTER 19
                      #define PREDICTED_COUNTER 20
                    #endif
                  #endif
                #endif
              #else /* Was [9-16] */
                #if (__COUNTER__ <= (12+8)) /* Was [9-12] */
                  #if (__COUNTER__ <= (10+9)) /* Was [9-10] */
                    #if (__COUNTER__ <= (9+10)) /* Was [9-9] */
                      #define ORIGINAL_COUNTER 9
                      #define VERIFICATION_COUNTER 20
                      #define PREDICTED_COUNTER 21
                    #else /* Was [10-10] */
                      #define ORIGINAL_COUNTER 10
                      #define VERIFICATION_COUNTER 21
                      #define PREDICTED_COUNTER 22
                    #endif
                  #else /* Was [11-12] */
                    #if (__COUNTER__ <= (11+10)) /* Was [11-11] */
                      #define ORIGINAL_COUNTER 11
                      #define VERIFICATION_COUNTER 22
                      #define PREDICTED_COUNTER 23
                    #else /* Was [12-12] */
                      #define ORIGINAL_COUNTER 12
                      #define VERIFICATION_COUNTER 23
                      #define PREDICTED_COUNTER 24
                    #endif
                  #endif
                #else /* Was [13-16] */
                  #if (__COUNTER__ <= (14+9)) /* Was [13-14] */
                    #if (__COUNTER__ <= (13+10)) /* Was [13-13] */
                      #define ORIGINAL_COUNTER 13
                      #define VERIFICATION_COUNTER 24
                      #define PREDICTED_COUNTER 25
                    #else /* Was [14-14] */
                      #define ORIGINAL_COUNTER 14
                      #define VERIFICATION_COUNTER 25
                      #define PREDICTED_COUNTER 26
                    #endif
                  #else /* Was [15-16] */
                    #if (__COUNTER__ <= (15+10)) /* Was [15-15] */
                      #define ORIGINAL_COUNTER 15
                      #define VERIFICATION_COUNTER 26
                      #define PREDICTED_COUNTER 27
                    #else /* Was [16-16] */
                      #define ORIGINAL_COUNTER 16
                      #define VERIFICATION_COUNTER 27
                      #define PREDICTED_COUNTER 28
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [17-32] */
              #if (__COUNTER__ <= (24+7)) /* Was [17-24] */
                #if (__COUNTER__ <= (20+8)) /* Was [17-20] */
                  #if (__COUNTER__ <= (18+9)) /* Was [17-18] */
                    #if (__COUNTER__ <= (17+10)) /* Was [17-17] */
                      #define ORIGINAL_COUNTER 17
                      #define VERIFICATION_COUNTER 28
                      #define PREDICTED_COUNTER 29
                    #else /* Was [18-18] */
                      #define ORIGINAL_COUNTER 18
                      #define VERIFICATION_COUNTER 29
                      #define PREDICTED_COUNTER 30
                    #endif
                  #else /* Was [19-20] */
                    #if (__COUNTER__ <= (19+10)) /* Was [19-19] */
                      #define ORIGINAL_COUNTER 19
                      #define VERIFICATION_COUNTER 30
                      #define PREDICTED_COUNTER 31
                    #else /* Was [20-20] */
                      #define ORIGINAL_COUNTER 20
                      #define VERIFICATION_COUNTER 31
                      #define PREDICTED_COUNTER 32
                    #endif
                  #endif
                #else /* Was [21-24] */
                  #if (__COUNTER__ <= (22+9)) /* Was [21-22] */
                    #if (__COUNTER__ <= (21+10)) /* Was [21-21] */
                      #define ORIGINAL_COUNTER 21
                      #define VERIFICATION_COUNTER 32
                      #define PREDICTED_COUNTER 33
                    #else /* Was [22-22] */
                      #define ORIGINAL_COUNTER 22
                      #define VERIFICATION_COUNTER 33
                      #define PREDICTED_COUNTER 34
                    #endif
                  #else /* Was [23-24] */
                    #if (__COUNTER__ <= (23+10)) /* Was [23-23] */
                      #define ORIGINAL_COUNTER 23
                      #define VERIFICATION_COUNTER 34
                      #define PREDICTED_COUNTER 35
                    #else /* Was [24-24] */
                      #define ORIGINAL_COUNTER 24
                      #define VERIFICATION_COUNTER 35
                      #define PREDICTED_COUNTER 36
                    #endif
                  #endif
                #endif
              #else /* Was [25-32] */
                #if (__COUNTER__ <= (28+8)) /* Was [25-28] */
                  #if (__COUNTER__ <= (26+9)) /* Was [25-26] */
                    #if (__COUNTER__ <= (25+10)) /* Was [25-25] */
                      #define ORIGINAL_COUNTER 25
                      #define VERIFICATION_COUNTER 36
                      #define PREDICTED_COUNTER 37
                    #else /* Was [26-26] */
                      #define ORIGINAL_COUNTER 26
                      #define VERIFICATION_COUNTER 37
                      #define PREDICTED_COUNTER 38
                    #endif
                  #else /* Was [27-28] */
                    #if (__COUNTER__ <= (27+10)) /* Was [27-27] */
                      #define ORIGINAL_COUNTER 27
                      #define VERIFICATION_COUNTER 38
                      #define PREDICTED_COUNTER 39
                    #else /* Was [28-28] */
                      #define ORIGINAL_COUNTER 28
                      #define VERIFICATION_COUNTER 39
                      #define PREDICTED_COUNTER 40
                    #endif
                  #endif
                #else /* Was [29-32] */
                  #if (__COUNTER__ <= (30+9)) /* Was [29-30] */
                    #if (__COUNTER__ <= (29+10)) /* Was [29-29] */
                      #define ORIGINAL_COUNTER 29
                      #define VERIFICATION_COUNTER 40
                      #define PREDICTED_COUNTER 41
                    #else /* Was [30-30] */
                      #define ORIGINAL_COUNTER 30
                      #define VERIFICATION_COUNTER 41
                      #define PREDICTED_COUNTER 42
                    #endif
                  #else /* Was [31-32] */
                    #if (__COUNTER__ <= (31+10)) /* Was [31-31] */
                      #define ORIGINAL_COUNTER 31
                      #define VERIFICATION_COUNTER 42
                      #define PREDICTED_COUNTER 43
                    #else /* Was [32-32] */
                      #define ORIGINAL_COUNTER 32
                      #define VERIFICATION_COUNTER 43
                      #define PREDICTED_COUNTER 44
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [33-64] */
            #if (__COUNTER__ <= (48+6)) /* Was [33-48] */
              #if (__COUNTER__ <= (40+7)) /* Was [33-40] */
                #if (__COUNTER__ <= (36+8)) /* Was [33-36] */
                  #if (__COUNTER__ <= (34+9)) /* Was [33-34] */
                    #if (__COUNTER__ <= (33+10)) /* Was [33-33] */
                      #define ORIGINAL_COUNTER 33
                      #define VERIFICATION_COUNTER 44
                      #define PREDICTED_COUNTER 45
                    #else /* Was [34-34] */
                      #define ORIGINAL_COUNTER 34
                      #define VERIFICATION_COUNTER 45
                      #define PREDICTED_COUNTER 46
                    #endif
                  #else /* Was [35-36] */
                    #if (__COUNTER__ <= (35+10)) /* Was [35-35] */
                      #define ORIGINAL_COUNTER 35
                      #define VERIFICATION_COUNTER 46
                      #define PREDICTED_COUNTER 47
                    #else /* Was [36-36] */
                      #define ORIGINAL_COUNTER 36
                      #define VERIFICATION_COUNTER 47
                      #define PREDICTED_COUNTER 48
                    #endif
                  #endif
                #else /* Was [37-40] */
                  #if (__COUNTER__ <= (38+9)) /* Was [37-38] */
                    #if (__COUNTER__ <= (37+10)) /* Was [37-37] */
                      #define ORIGINAL_COUNTER 37
                      #define VERIFICATION_COUNTER 48
                      #define PREDICTED_COUNTER 49
                    #else /* Was [38-38] */
                      #define ORIGINAL_COUNTER 38
                      #define VERIFICATION_COUNTER 49
                      #define PREDICTED_COUNTER 50
                    #endif
                  #else /* Was [39-40] */
                    #if (__COUNTER__ <= (39+10)) /* Was [39-39] */
                      #define ORIGINAL_COUNTER 39
                      #define VERIFICATION_COUNTER 50
                      #define PREDICTED_COUNTER 51
                    #else /* Was [40-40] */
                      #define ORIGINAL_COUNTER 40
                      #define VERIFICATION_COUNTER 51
                      #define PREDICTED_COUNTER 52
                    #endif
                  #endif
                #endif
              #else /* Was [41-48] */
                #if (__COUNTER__ <= (44+8)) /* Was [41-44] */
                  #if (__COUNTER__ <= (42+9)) /* Was [41-42] */
                    #if (__COUNTER__ <= (41+10)) /* Was [41-41] */
                      #define ORIGINAL_COUNTER 41
                      #define VERIFICATION_COUNTER 52
                      #define PREDICTED_COUNTER 53
                    #else /* Was [42-42] */
                      #define ORIGINAL_COUNTER 42
                      #define VERIFICATION_COUNTER 53
                      #define PREDICTED_COUNTER 54
                    #endif
                  #else /* Was [43-44] */
                    #if (__COUNTER__ <= (43+10)) /* Was [43-43] */
                      #define ORIGINAL_COUNTER 43
                      #define VERIFICATION_COUNTER 54
                      #define PREDICTED_COUNTER 55
                    #else /* Was [44-44] */
                      #define ORIGINAL_COUNTER 44
                      #define VERIFICATION_COUNTER 55
                      #define PREDICTED_COUNTER 56
                    #endif
                  #endif
                #else /* Was [45-48] */
                  #if (__COUNTER__ <= (46+9)) /* Was [45-46] */
                    #if (__COUNTER__ <= (45+10)) /* Was [45-45] */
                      #define ORIGINAL_COUNTER 45
                      #define VERIFICATION_COUNTER 56
                      #define PREDICTED_COUNTER 57
                    #else /* Was [46-46] */
                      #define ORIGINAL_COUNTER 46
                      #define VERIFICATION_COUNTER 57
                      #define PREDICTED_COUNTER 58
                    #endif
                  #else /* Was [47-48] */
                    #if (__COUNTER__ <= (47+10)) /* Was [47-47] */
                      #define ORIGINAL_COUNTER 47
                      #define VERIFICATION_COUNTER 58
                      #define PREDICTED_COUNTER 59
                    #else /* Was [48-48] */
                      #define ORIGINAL_COUNTER 48
                      #define VERIFICATION_COUNTER 59
                      #define PREDICTED_COUNTER 60
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [49-64] */
              #if (__COUNTER__ <= (56+7)) /* Was [49-56] */
                #if (__COUNTER__ <= (52+8)) /* Was [49-52] */
                  #if (__COUNTER__ <= (50+9)) /* Was [49-50] */
                    #if (__COUNTER__ <= (49+10)) /* Was [49-49] */
                      #define ORIGINAL_COUNTER 49
                      #define VERIFICATION_COUNTER 60
                      #define PREDICTED_COUNTER 61
                    #else /* Was [50-50] */
                      #define ORIGINAL_COUNTER 50
                      #define VERIFICATION_COUNTER 61
                      #define PREDICTED_COUNTER 62
                    #endif
                  #else /* Was [51-52] */
                    #if (__COUNTER__ <= (51+10)) /* Was [51-51] */
                      #define ORIGINAL_COUNTER 51
                      #define VERIFICATION_COUNTER 62
                      #define PREDICTED_COUNTER 63
                    #else /* Was [52-52] */
                      #define ORIGINAL_COUNTER 52
                      #define VERIFICATION_COUNTER 63
                      #define PREDICTED_COUNTER 64
                    #endif
                  #endif
                #else /* Was [53-56] */
                  #if (__COUNTER__ <= (54+9)) /* Was [53-54] */
                    #if (__COUNTER__ <= (53+10)) /* Was [53-53] */
                      #define ORIGINAL_COUNTER 53
                      #define VERIFICATION_COUNTER 64
                      #define PREDICTED_COUNTER 65
                    #else /* Was [54-54] */
                      #define ORIGINAL_COUNTER 54
                      #define VERIFICATION_COUNTER 65
                      #define PREDICTED_COUNTER 66
                    #endif
                  #else /* Was [55-56] */
                    #if (__COUNTER__ <= (55+10)) /* Was [55-55] */
                      #define ORIGINAL_COUNTER 55
                      #define VERIFICATION_COUNTER 66
                      #define PREDICTED_COUNTER 67
                    #else /* Was [56-56] */
                      #define ORIGINAL_COUNTER 56
                      #define VERIFICATION_COUNTER 67
                      #define PREDICTED_COUNTER 68
                    #endif
                  #endif
                #endif
              #else /* Was [57-64] */
                #if (__COUNTER__ <= (60+8)) /* Was [57-60] */
                  #if (__COUNTER__ <= (58+9)) /* Was [57-58] */
                    #if (__COUNTER__ <= (57+10)) /* Was [57-57] */
                      #define ORIGINAL_COUNTER 57
                      #define VERIFICATION_COUNTER 68
                      #define PREDICTED_COUNTER 69
                    #else /* Was [58-58] */
                      #define ORIGINAL_COUNTER 58
                      #define VERIFICATION_COUNTER 69
                      #define PREDICTED_COUNTER 70
                    #endif
                  #else /* Was [59-60] */
                    #if (__COUNTER__ <= (59+10)) /* Was [59-59] */
                      #define ORIGINAL_COUNTER 59
                      #define VERIFICATION_COUNTER 70
                      #define PREDICTED_COUNTER 71
                    #else /* Was [60-60] */
                      #define ORIGINAL_COUNTER 60
                      #define VERIFICATION_COUNTER 71
                      #define PREDICTED_COUNTER 72
                    #endif
                  #endif
                #else /* Was [61-64] */
                  #if (__COUNTER__ <= (62+9)) /* Was [61-62] */
                    #if (__COUNTER__ <= (61+10)) /* Was [61-61] */
                      #define ORIGINAL_COUNTER 61
                      #define VERIFICATION_COUNTER 72
                      #define PREDICTED_COUNTER 73
                    #else /* Was [62-62] */
                      #define ORIGINAL_COUNTER 62
                      #define VERIFICATION_COUNTER 73
                      #define PREDICTED_COUNTER 74
                    #endif
                  #else /* Was [63-64] */
                    #if (__COUNTER__ <= (63+10)) /* Was [63-63] */
                      #define ORIGINAL_COUNTER 63
                      #define VERIFICATION_COUNTER 74
                      #define PREDICTED_COUNTER 75
                    #else /* Was [64-64] */
                      #define ORIGINAL_COUNTER 64
                      #define VERIFICATION_COUNTER 75
                      #define PREDICTED_COUNTER 76
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #else /* Was [65-128] */
          #if (__COUNTER__ <= (96+5)) /* Was [65-96] */
            #if (__COUNTER__ <= (80+6)) /* Was [65-80] */
              #if (__COUNTER__ <= (72+7)) /* Was [65-72] */
                #if (__COUNTER__ <= (68+8)) /* Was [65-68] */
                  #if (__COUNTER__ <= (66+9)) /* Was [65-66] */
                    #if (__COUNTER__ <= (65+10)) /* Was [65-65] */
                      #define ORIGINAL_COUNTER 65
                      #define VERIFICATION_COUNTER 76
                      #define PREDICTED_COUNTER 77
                    #else /* Was [66-66] */
                      #define ORIGINAL_COUNTER 66
                      #define VERIFICATION_COUNTER 77
                      #define PREDICTED_COUNTER 78
                    #endif
                  #else /* Was [67-68] */
                    #if (__COUNTER__ <= (67+10)) /* Was [67-67] */
                      #define ORIGINAL_COUNTER 67
                      #define VERIFICATION_COUNTER 78
                      #define PREDICTED_COUNTER 79
                    #else /* Was [68-68] */
                      #define ORIGINAL_COUNTER 68
                      #define VERIFICATION_COUNTER 79
                      #define PREDICTED_COUNTER 80
                    #endif
                  #endif
                #else /* Was [69-72] */
                  #if (__COUNTER__ <= (70+9)) /* Was [69-70] */
                    #if (__COUNTER__ <= (69+10)) /* Was [69-69] */
                      #define ORIGINAL_COUNTER 69
                      #define VERIFICATION_COUNTER 80
                      #define PREDICTED_COUNTER 81
                    #else /* Was [70-70] */
                      #define ORIGINAL_COUNTER 70
                      #define VERIFICATION_COUNTER 81
                      #define PREDICTED_COUNTER 82
                    #endif
                  #else /* Was [71-72] */
                    #if (__COUNTER__ <= (71+10)) /* Was [71-71] */
                      #define ORIGINAL_COUNTER 71
                      #define VERIFICATION_COUNTER 82
                      #define PREDICTED_COUNTER 83
                    #else /* Was [72-72] */
                      #define ORIGINAL_COUNTER 72
                      #define VERIFICATION_COUNTER 83
                      #define PREDICTED_COUNTER 84
                    #endif
                  #endif
                #endif
              #else /* Was [73-80] */
                #if (__COUNTER__ <= (76+8)) /* Was [73-76] */
                  #if (__COUNTER__ <= (74+9)) /* Was [73-74] */
                    #if (__COUNTER__ <= (73+10)) /* Was [73-73] */
                      #define ORIGINAL_COUNTER 73
                      #define VERIFICATION_COUNTER 84
                      #define PREDICTED_COUNTER 85
                    #else /* Was [74-74] */
                      #define ORIGINAL_COUNTER 74
                      #define VERIFICATION_COUNTER 85
                      #define PREDICTED_COUNTER 86
                    #endif
                  #else /* Was [75-76] */
                    #if (__COUNTER__ <= (75+10)) /* Was [75-75] */
                      #define ORIGINAL_COUNTER 75
                      #define VERIFICATION_COUNTER 86
                      #define PREDICTED_COUNTER 87
                    #else /* Was [76-76] */
                      #define ORIGINAL_COUNTER 76
                      #define VERIFICATION_COUNTER 87
                      #define PREDICTED_COUNTER 88
                    #endif
                  #endif
                #else /* Was [77-80] */
                  #if (__COUNTER__ <= (78+9)) /* Was [77-78] */
                    #if (__COUNTER__ <= (77+10)) /* Was [77-77] */
                      #define ORIGINAL_COUNTER 77
                      #define VERIFICATION_COUNTER 88
                      #define PREDICTED_COUNTER 89
                    #else /* Was [78-78] */
                      #define ORIGINAL_COUNTER 78
                      #define VERIFICATION_COUNTER 89
                      #define PREDICTED_COUNTER 90
                    #endif
                  #else /* Was [79-80] */
                    #if (__COUNTER__ <= (79+10)) /* Was [79-79] */
                      #define ORIGINAL_COUNTER 79
                      #define VERIFICATION_COUNTER 90
                      #define PREDICTED_COUNTER 91
                    #else /* Was [80-80] */
                      #define ORIGINAL_COUNTER 80
                      #define VERIFICATION_COUNTER 91
                      #define PREDICTED_COUNTER 92
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [81-96] */
              #if (__COUNTER__ <= (88+7)) /* Was [81-88] */
                #if (__COUNTER__ <= (84+8)) /* Was [81-84] */
                  #if (__COUNTER__ <= (82+9)) /* Was [81-82] */
                    #if (__COUNTER__ <= (81+10)) /* Was [81-81] */
                      #define ORIGINAL_COUNTER 81
                      #define VERIFICATION_COUNTER 92
                      #define PREDICTED_COUNTER 93
                    #else /* Was [82-82] */
                      #define ORIGINAL_COUNTER 82
                      #define VERIFICATION_COUNTER 93
                      #define PREDICTED_COUNTER 94
                    #endif
                  #else /* Was [83-84] */
                    #if (__COUNTER__ <= (83+10)) /* Was [83-83] */
                      #define ORIGINAL_COUNTER 83
                      #define VERIFICATION_COUNTER 94
                      #define PREDICTED_COUNTER 95
                    #else /* Was [84-84] */
                      #define ORIGINAL_COUNTER 84
                      #define VERIFICATION_COUNTER 95
                      #define PREDICTED_COUNTER 96
                    #endif
                  #endif
                #else /* Was [85-88] */
                  #if (__COUNTER__ <= (86+9)) /* Was [85-86] */
                    #if (__COUNTER__ <= (85+10)) /* Was [85-85] */
                      #define ORIGINAL_COUNTER 85
                      #define VERIFICATION_COUNTER 96
                      #define PREDICTED_COUNTER 97
                    #else /* Was [86-86] */
                      #define ORIGINAL_COUNTER 86
                      #define VERIFICATION_COUNTER 97
                      #define PREDICTED_COUNTER 98
                    #endif
                  #else /* Was [87-88] */
                    #if (__COUNTER__ <= (87+10)) /* Was [87-87] */
                      #define ORIGINAL_COUNTER 87
                      #define VERIFICATION_COUNTER 98
                      #define PREDICTED_COUNTER 99
                    #else /* Was [88-88] */
                      #define ORIGINAL_COUNTER 88
                      #define VERIFICATION_COUNTER 99
                      #define PREDICTED_COUNTER 100
                    #endif
                  #endif
                #endif
              #else /* Was [89-96] */
                #if (__COUNTER__ <= (92+8)) /* Was [89-92] */
                  #if (__COUNTER__ <= (90+9)) /* Was [89-90] */
                    #if (__COUNTER__ <= (89+10)) /* Was [89-89] */
                      #define ORIGINAL_COUNTER 89
                      #define VERIFICATION_COUNTER 100
                      #define PREDICTED_COUNTER 101
                    #else /* Was [90-90] */
                      #define ORIGINAL_COUNTER 90
                      #define VERIFICATION_COUNTER 101
                      #define PREDICTED_COUNTER 102
                    #endif
                  #else /* Was [91-92] */
                    #if (__COUNTER__ <= (91+10)) /* Was [91-91] */
                      #define ORIGINAL_COUNTER 91
                      #define VERIFICATION_COUNTER 102
                      #define PREDICTED_COUNTER 103
                    #else /* Was [92-92] */
                      #define ORIGINAL_COUNTER 92
                      #define VERIFICATION_COUNTER 103
                      #define PREDICTED_COUNTER 104
                    #endif
                  #endif
                #else /* Was [93-96] */
                  #if (__COUNTER__ <= (94+9)) /* Was [93-94] */
                    #if (__COUNTER__ <= (93+10)) /* Was [93-93] */
                      #define ORIGINAL_COUNTER 93
                      #define VERIFICATION_COUNTER 104
                      #define PREDICTED_COUNTER 105
                    #else /* Was [94-94] */
                      #define ORIGINAL_COUNTER 94
                      #define VERIFICATION_COUNTER 105
                      #define PREDICTED_COUNTER 106
                    #endif
                  #else /* Was [95-96] */
                    #if (__COUNTER__ <= (95+10)) /* Was [95-95] */
                      #define ORIGINAL_COUNTER 95
                      #define VERIFICATION_COUNTER 106
                      #define PREDICTED_COUNTER 107
                    #else /* Was [96-96] */
                      #define ORIGINAL_COUNTER 96
                      #define VERIFICATION_COUNTER 107
                      #define PREDICTED_COUNTER 108
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [97-128] */
            #if (__COUNTER__ <= (112+6)) /* Was [97-112] */
              #if (__COUNTER__ <= (104+7)) /* Was [97-104] */
                #if (__COUNTER__ <= (100+8)) /* Was [97-100] */
                  #if (__COUNTER__ <= (98+9)) /* Was [97-98] */
                    #if (__COUNTER__ <= (97+10)) /* Was [97-97] */
                      #define ORIGINAL_COUNTER 97
                      #define VERIFICATION_COUNTER 108
                      #define PREDICTED_COUNTER 109
                    #else /* Was [98-98] */
                      #define ORIGINAL_COUNTER 98
                      #define VERIFICATION_COUNTER 109
                      #define PREDICTED_COUNTER 110
                    #endif
                  #else /* Was [99-100] */
                    #if (__COUNTER__ <= (99+10)) /* Was [99-99] */
                      #define ORIGINAL_COUNTER 99
                      #define VERIFICATION_COUNTER 110
                      #define PREDICTED_COUNTER 111
                    #else /* Was [100-100] */
                      #define ORIGINAL_COUNTER 100
                      #define VERIFICATION_COUNTER 111
                      #define PREDICTED_COUNTER 112
                    #endif
                  #endif
                #else /* Was [101-104] */
                  #if (__COUNTER__ <= (102+9)) /* Was [101-102] */
                    #if (__COUNTER__ <= (101+10)) /* Was [101-101] */
                      #define ORIGINAL_COUNTER 101
                      #define VERIFICATION_COUNTER 112
                      #define PREDICTED_COUNTER 113
                    #else /* Was [102-102] */
                      #define ORIGINAL_COUNTER 102
                      #define VERIFICATION_COUNTER 113
                      #define PREDICTED_COUNTER 114
                    #endif
                  #else /* Was [103-104] */
                    #if (__COUNTER__ <= (103+10)) /* Was [103-103] */
                      #define ORIGINAL_COUNTER 103
                      #define VERIFICATION_COUNTER 114
                      #define PREDICTED_COUNTER 115
                    #else /* Was [104-104] */
                      #define ORIGINAL_COUNTER 104
                      #define VERIFICATION_COUNTER 115
                      #define PREDICTED_COUNTER 116
                    #endif
                  #endif
                #endif
              #else /* Was [105-112] */
                #if (__COUNTER__ <= (108+8)) /* Was [105-108] */
                  #if (__COUNTER__ <= (106+9)) /* Was [105-106] */
                    #if (__COUNTER__ <= (105+10)) /* Was [105-105] */
                      #define ORIGINAL_COUNTER 105
                      #define VERIFICATION_COUNTER 116
                      #define PREDICTED_COUNTER 117
                    #else /* Was [106-106] */
                      #define ORIGINAL_COUNTER 106
                      #define VERIFICATION_COUNTER 117
                      #define PREDICTED_COUNTER 118
                    #endif
                  #else /* Was [107-108] */
                    #if (__COUNTER__ <= (107+10)) /* Was [107-107] */
                      #define ORIGINAL_COUNTER 107
                      #define VERIFICATION_COUNTER 118
                      #define PREDICTED_COUNTER 119
                    #else /* Was [108-108] */
                      #define ORIGINAL_COUNTER 108
                      #define VERIFICATION_COUNTER 119
                      #define PREDICTED_COUNTER 120
                    #endif
                  #endif
                #else /* Was [109-112] */
                  #if (__COUNTER__ <= (110+9)) /* Was [109-110] */
                    #if (__COUNTER__ <= (109+10)) /* Was [109-109] */
                      #define ORIGINAL_COUNTER 109
                      #define VERIFICATION_COUNTER 120
                      #define PREDICTED_COUNTER 121
                    #else /* Was [110-110] */
                      #define ORIGINAL_COUNTER 110
                      #define VERIFICATION_COUNTER 121
                      #define PREDICTED_COUNTER 122
                    #endif
                  #else /* Was [111-112] */
                    #if (__COUNTER__ <= (111+10)) /* Was [111-111] */
                      #define ORIGINAL_COUNTER 111
                      #define VERIFICATION_COUNTER 122
                      #define PREDICTED_COUNTER 123
                    #else /* Was [112-112] */
                      #define ORIGINAL_COUNTER 112
                      #define VERIFICATION_COUNTER 123
                      #define PREDICTED_COUNTER 124
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [113-128] */
              #if (__COUNTER__ <= (120+7)) /* Was [113-120] */
                #if (__COUNTER__ <= (116+8)) /* Was [113-116] */
                  #if (__COUNTER__ <= (114+9)) /* Was [113-114] */
                    #if (__COUNTER__ <= (113+10)) /* Was [113-113] */
                      #define ORIGINAL_COUNTER 113
                      #define VERIFICATION_COUNTER 124
                      #define PREDICTED_COUNTER 125
                    #else /* Was [114-114] */
                      #define ORIGINAL_COUNTER 114
                      #define VERIFICATION_COUNTER 125
                      #define PREDICTED_COUNTER 126
                    #endif
                  #else /* Was [115-116] */
                    #if (__COUNTER__ <= (115+10)) /* Was [115-115] */
                      #define ORIGINAL_COUNTER 115
                      #define VERIFICATION_COUNTER 126
                      #define PREDICTED_COUNTER 127
                    #else /* Was [116-116] */
                      #define ORIGINAL_COUNTER 116
                      #define VERIFICATION_COUNTER 127
                      #define PREDICTED_COUNTER 128
                    #endif
                  #endif
                #else /* Was [117-120] */
                  #if (__COUNTER__ <= (118+9)) /* Was [117-118] */
                    #if (__COUNTER__ <= (117+10)) /* Was [117-117] */
                      #define ORIGINAL_COUNTER 117
                      #define VERIFICATION_COUNTER 128
                      #define PREDICTED_COUNTER 129
                    #else /* Was [118-118] */
                      #define ORIGINAL_COUNTER 118
                      #define VERIFICATION_COUNTER 129
                      #define PREDICTED_COUNTER 130
                    #endif
                  #else /* Was [119-120] */
                    #if (__COUNTER__ <= (119+10)) /* Was [119-119] */
                      #define ORIGINAL_COUNTER 119
                      #define VERIFICATION_COUNTER 130
                      #define PREDICTED_COUNTER 131
                    #else /* Was [120-120] */
                      #define ORIGINAL_COUNTER 120
                      #define VERIFICATION_COUNTER 131
                      #define PREDICTED_COUNTER 132
                    #endif
                  #endif
                #endif
              #else /* Was [121-128] */
                #if (__COUNTER__ <= (124+8)) /* Was [121-124] */
                  #if (__COUNTER__ <= (122+9)) /* Was [121-122] */
                    #if (__COUNTER__ <= (121+10)) /* Was [121-121] */
                      #define ORIGINAL_COUNTER 121
                      #define VERIFICATION_COUNTER 132
                      #define PREDICTED_COUNTER 133
                    #else /* Was [122-122] */
                      #define ORIGINAL_COUNTER 122
                      #define VERIFICATION_COUNTER 133
                      #define PREDICTED_COUNTER 134
                    #endif
                  #else /* Was [123-124] */
                    #if (__COUNTER__ <= (123+10)) /* Was [123-123] */
                      #define ORIGINAL_COUNTER 123
                      #define VERIFICATION_COUNTER 134
                      #define PREDICTED_COUNTER 135
                    #else /* Was [124-124] */
                      #define ORIGINAL_COUNTER 124
                      #define VERIFICATION_COUNTER 135
                      #define PREDICTED_COUNTER 136
                    #endif
                  #endif
                #else /* Was [125-128] */
                  #if (__COUNTER__ <= (126+9)) /* Was [125-126] */
                    #if (__COUNTER__ <= (125+10)) /* Was [125-125] */
                      #define ORIGINAL_COUNTER 125
                      #define VERIFICATION_COUNTER 136
                      #define PREDICTED_COUNTER 137
                    #else /* Was [126-126] */
                      #define ORIGINAL_COUNTER 126
                      #define VERIFICATION_COUNTER 137
                      #define PREDICTED_COUNTER 138
                    #endif
                  #else /* Was [127-128] */
                    #if (__COUNTER__ <= (127+10)) /* Was [127-127] */
                      #define ORIGINAL_COUNTER 127
                      #define VERIFICATION_COUNTER 138
                      #define PREDICTED_COUNTER 139
                    #else /* Was [128-128] */
                      #define ORIGINAL_COUNTER 128
                      #define VERIFICATION_COUNTER 139
                      #define PREDICTED_COUNTER 140
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #endif
      #else /* Was [129-256] */
        #if (__COUNTER__ <= (192+4)) /* Was [129-192] */
          #if (__COUNTER__ <= (160+5)) /* Was [129-160] */
            #if (__COUNTER__ <= (144+6)) /* Was [129-144] */
              #if (__COUNTER__ <= (136+7)) /* Was [129-136] */
                #if (__COUNTER__ <= (132+8)) /* Was [129-132] */
                  #if (__COUNTER__ <= (130+9)) /* Was [129-130] */
                    #if (__COUNTER__ <= (129+10)) /* Was [129-129] */
                      #define ORIGINAL_COUNTER 129
                      #define VERIFICATION_COUNTER 140
                      #define PREDICTED_COUNTER 141
                    #else /* Was [130-130] */
                      #define ORIGINAL_COUNTER 130
                      #define VERIFICATION_COUNTER 141
                      #define PREDICTED_COUNTER 142
                    #endif
                  #else /* Was [131-132] */
                    #if (__COUNTER__ <= (131+10)) /* Was [131-131] */
                      #define ORIGINAL_COUNTER 131
                      #define VERIFICATION_COUNTER 142
                      #define PREDICTED_COUNTER 143
                    #else /* Was [132-132] */
                      #define ORIGINAL_COUNTER 132
                      #define VERIFICATION_COUNTER 143
                      #define PREDICTED_COUNTER 144
                    #endif
                  #endif
                #else /* Was [133-136] */
                  #if (__COUNTER__ <= (134+9)) /* Was [133-134] */
                    #if (__COUNTER__ <= (133+10)) /* Was [133-133] */
                      #define ORIGINAL_COUNTER 133
                      #define VERIFICATION_COUNTER 144
                      #define PREDICTED_COUNTER 145
                    #else /* Was [134-134] */
                      #define ORIGINAL_COUNTER 134
                      #define VERIFICATION_COUNTER 145
                      #define PREDICTED_COUNTER 146
                    #endif
                  #else /* Was [135-136] */
                    #if (__COUNTER__ <= (135+10)) /* Was [135-135] */
                      #define ORIGINAL_COUNTER 135
                      #define VERIFICATION_COUNTER 146
                      #define PREDICTED_COUNTER 147
                    #else /* Was [136-136] */
                      #define ORIGINAL_COUNTER 136
                      #define VERIFICATION_COUNTER 147
                      #define PREDICTED_COUNTER 148
                    #endif
                  #endif
                #endif
              #else /* Was [137-144] */
                #if (__COUNTER__ <= (140+8)) /* Was [137-140] */
                  #if (__COUNTER__ <= (138+9)) /* Was [137-138] */
                    #if (__COUNTER__ <= (137+10)) /* Was [137-137] */
                      #define ORIGINAL_COUNTER 137
                      #define VERIFICATION_COUNTER 148
                      #define PREDICTED_COUNTER 149
                    #else /* Was [138-138] */
                      #define ORIGINAL_COUNTER 138
                      #define VERIFICATION_COUNTER 149
                      #define PREDICTED_COUNTER 150
                    #endif
                  #else /* Was [139-140] */
                    #if (__COUNTER__ <= (139+10)) /* Was [139-139] */
                      #define ORIGINAL_COUNTER 139
                      #define VERIFICATION_COUNTER 150
                      #define PREDICTED_COUNTER 151
                    #else /* Was [140-140] */
                      #define ORIGINAL_COUNTER 140
                      #define VERIFICATION_COUNTER 151
                      #define PREDICTED_COUNTER 152
                    #endif
                  #endif
                #else /* Was [141-144] */
                  #if (__COUNTER__ <= (142+9)) /* Was [141-142] */
                    #if (__COUNTER__ <= (141+10)) /* Was [141-141] */
                      #define ORIGINAL_COUNTER 141
                      #define VERIFICATION_COUNTER 152
                      #define PREDICTED_COUNTER 153
                    #else /* Was [142-142] */
                      #define ORIGINAL_COUNTER 142
                      #define VERIFICATION_COUNTER 153
                      #define PREDICTED_COUNTER 154
                    #endif
                  #else /* Was [143-144] */
                    #if (__COUNTER__ <= (143+10)) /* Was [143-143] */
                      #define ORIGINAL_COUNTER 143
                      #define VERIFICATION_COUNTER 154
                      #define PREDICTED_COUNTER 155
                    #else /* Was [144-144] */
                      #define ORIGINAL_COUNTER 144
                      #define VERIFICATION_COUNTER 155
                      #define PREDICTED_COUNTER 156
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [145-160] */
              #if (__COUNTER__ <= (152+7)) /* Was [145-152] */
                #if (__COUNTER__ <= (148+8)) /* Was [145-148] */
                  #if (__COUNTER__ <= (146+9)) /* Was [145-146] */
                    #if (__COUNTER__ <= (145+10)) /* Was [145-145] */
                      #define ORIGINAL_COUNTER 145
                      #define VERIFICATION_COUNTER 156
                      #define PREDICTED_COUNTER 157
                    #else /* Was [146-146] */
                      #define ORIGINAL_COUNTER 146
                      #define VERIFICATION_COUNTER 157
                      #define PREDICTED_COUNTER 158
                    #endif
                  #else /* Was [147-148] */
                    #if (__COUNTER__ <= (147+10)) /* Was [147-147] */
                      #define ORIGINAL_COUNTER 147
                      #define VERIFICATION_COUNTER 158
                      #define PREDICTED_COUNTER 159
                    #else /* Was [148-148] */
                      #define ORIGINAL_COUNTER 148
                      #define VERIFICATION_COUNTER 159
                      #define PREDICTED_COUNTER 160
                    #endif
                  #endif
                #else /* Was [149-152] */
                  #if (__COUNTER__ <= (150+9)) /* Was [149-150] */
                    #if (__COUNTER__ <= (149+10)) /* Was [149-149] */
                      #define ORIGINAL_COUNTER 149
                      #define VERIFICATION_COUNTER 160
                      #define PREDICTED_COUNTER 161
                    #else /* Was [150-150] */
                      #define ORIGINAL_COUNTER 150
                      #define VERIFICATION_COUNTER 161
                      #define PREDICTED_COUNTER 162
                    #endif
                  #else /* Was [151-152] */
                    #if (__COUNTER__ <= (151+10)) /* Was [151-151] */
                      #define ORIGINAL_COUNTER 151
                      #define VERIFICATION_COUNTER 162
                      #define PREDICTED_COUNTER 163
                    #else /* Was [152-152] */
                      #define ORIGINAL_COUNTER 152
                      #define VERIFICATION_COUNTER 163
                      #define PREDICTED_COUNTER 164
                    #endif
                  #endif
                #endif
              #else /* Was [153-160] */
                #if (__COUNTER__ <= (156+8)) /* Was [153-156] */
                  #if (__COUNTER__ <= (154+9)) /* Was [153-154] */
                    #if (__COUNTER__ <= (153+10)) /* Was [153-153] */
                      #define ORIGINAL_COUNTER 153
                      #define VERIFICATION_COUNTER 164
                      #define PREDICTED_COUNTER 165
                    #else /* Was [154-154] */
                      #define ORIGINAL_COUNTER 154
                      #define VERIFICATION_COUNTER 165
                      #define PREDICTED_COUNTER 166
                    #endif
                  #else /* Was [155-156] */
                    #if (__COUNTER__ <= (155+10)) /* Was [155-155] */
                      #define ORIGINAL_COUNTER 155
                      #define VERIFICATION_COUNTER 166
                      #define PREDICTED_COUNTER 167
                    #else /* Was [156-156] */
                      #define ORIGINAL_COUNTER 156
                      #define VERIFICATION_COUNTER 167
                      #define PREDICTED_COUNTER 168
                    #endif
                  #endif
                #else /* Was [157-160] */
                  #if (__COUNTER__ <= (158+9)) /* Was [157-158] */
                    #if (__COUNTER__ <= (157+10)) /* Was [157-157] */
                      #define ORIGINAL_COUNTER 157
                      #define VERIFICATION_COUNTER 168
                      #define PREDICTED_COUNTER 169
                    #else /* Was [158-158] */
                      #define ORIGINAL_COUNTER 158
                      #define VERIFICATION_COUNTER 169
                      #define PREDICTED_COUNTER 170
                    #endif
                  #else /* Was [159-160] */
                    #if (__COUNTER__ <= (159+10)) /* Was [159-159] */
                      #define ORIGINAL_COUNTER 159
                      #define VERIFICATION_COUNTER 170
                      #define PREDICTED_COUNTER 171
                    #else /* Was [160-160] */
                      #define ORIGINAL_COUNTER 160
                      #define VERIFICATION_COUNTER 171
                      #define PREDICTED_COUNTER 172
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [161-192] */
            #if (__COUNTER__ <= (176+6)) /* Was [161-176] */
              #if (__COUNTER__ <= (168+7)) /* Was [161-168] */
                #if (__COUNTER__ <= (164+8)) /* Was [161-164] */
                  #if (__COUNTER__ <= (162+9)) /* Was [161-162] */
                    #if (__COUNTER__ <= (161+10)) /* Was [161-161] */
                      #define ORIGINAL_COUNTER 161
                      #define VERIFICATION_COUNTER 172
                      #define PREDICTED_COUNTER 173
                    #else /* Was [162-162] */
                      #define ORIGINAL_COUNTER 162
                      #define VERIFICATION_COUNTER 173
                      #define PREDICTED_COUNTER 174
                    #endif
                  #else /* Was [163-164] */
                    #if (__COUNTER__ <= (163+10)) /* Was [163-163] */
                      #define ORIGINAL_COUNTER 163
                      #define VERIFICATION_COUNTER 174
                      #define PREDICTED_COUNTER 175
                    #else /* Was [164-164] */
                      #define ORIGINAL_COUNTER 164
                      #define VERIFICATION_COUNTER 175
                      #define PREDICTED_COUNTER 176
                    #endif
                  #endif
                #else /* Was [165-168] */
                  #if (__COUNTER__ <= (166+9)) /* Was [165-166] */
                    #if (__COUNTER__ <= (165+10)) /* Was [165-165] */
                      #define ORIGINAL_COUNTER 165
                      #define VERIFICATION_COUNTER 176
                      #define PREDICTED_COUNTER 177
                    #else /* Was [166-166] */
                      #define ORIGINAL_COUNTER 166
                      #define VERIFICATION_COUNTER 177
                      #define PREDICTED_COUNTER 178
                    #endif
                  #else /* Was [167-168] */
                    #if (__COUNTER__ <= (167+10)) /* Was [167-167] */
                      #define ORIGINAL_COUNTER 167
                      #define VERIFICATION_COUNTER 178
                      #define PREDICTED_COUNTER 179
                    #else /* Was [168-168] */
                      #define ORIGINAL_COUNTER 168
                      #define VERIFICATION_COUNTER 179
                      #define PREDICTED_COUNTER 180
                    #endif
                  #endif
                #endif
              #else /* Was [169-176] */
                #if (__COUNTER__ <= (172+8)) /* Was [169-172] */
                  #if (__COUNTER__ <= (170+9)) /* Was [169-170] */
                    #if (__COUNTER__ <= (169+10)) /* Was [169-169] */
                      #define ORIGINAL_COUNTER 169
                      #define VERIFICATION_COUNTER 180
                      #define PREDICTED_COUNTER 181
                    #else /* Was [170-170] */
                      #define ORIGINAL_COUNTER 170
                      #define VERIFICATION_COUNTER 181
                      #define PREDICTED_COUNTER 182
                    #endif
                  #else /* Was [171-172] */
                    #if (__COUNTER__ <= (171+10)) /* Was [171-171] */
                      #define ORIGINAL_COUNTER 171
                      #define VERIFICATION_COUNTER 182
                      #define PREDICTED_COUNTER 183
                    #else /* Was [172-172] */
                      #define ORIGINAL_COUNTER 172
                      #define VERIFICATION_COUNTER 183
                      #define PREDICTED_COUNTER 184
                    #endif
                  #endif
                #else /* Was [173-176] */
                  #if (__COUNTER__ <= (174+9)) /* Was [173-174] */
                    #if (__COUNTER__ <= (173+10)) /* Was [173-173] */
                      #define ORIGINAL_COUNTER 173
                      #define VERIFICATION_COUNTER 184
                      #define PREDICTED_COUNTER 185
                    #else /* Was [174-174] */
                      #define ORIGINAL_COUNTER 174
                      #define VERIFICATION_COUNTER 185
                      #define PREDICTED_COUNTER 186
                    #endif
                  #else /* Was [175-176] */
                    #if (__COUNTER__ <= (175+10)) /* Was [175-175] */
                      #define ORIGINAL_COUNTER 175
                      #define VERIFICATION_COUNTER 186
                      #define PREDICTED_COUNTER 187
                    #else /* Was [176-176] */
                      #define ORIGINAL_COUNTER 176
                      #define VERIFICATION_COUNTER 187
                      #define PREDICTED_COUNTER 188
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [177-192] */
              #if (__COUNTER__ <= (184+7)) /* Was [177-184] */
                #if (__COUNTER__ <= (180+8)) /* Was [177-180] */
                  #if (__COUNTER__ <= (178+9)) /* Was [177-178] */
                    #if (__COUNTER__ <= (177+10)) /* Was [177-177] */
                      #define ORIGINAL_COUNTER 177
                      #define VERIFICATION_COUNTER 188
                      #define PREDICTED_COUNTER 189
                    #else /* Was [178-178] */
                      #define ORIGINAL_COUNTER 178
                      #define VERIFICATION_COUNTER 189
                      #define PREDICTED_COUNTER 190
                    #endif
                  #else /* Was [179-180] */
                    #if (__COUNTER__ <= (179+10)) /* Was [179-179] */
                      #define ORIGINAL_COUNTER 179
                      #define VERIFICATION_COUNTER 190
                      #define PREDICTED_COUNTER 191
                    #else /* Was [180-180] */
                      #define ORIGINAL_COUNTER 180
                      #define VERIFICATION_COUNTER 191
                      #define PREDICTED_COUNTER 192
                    #endif
                  #endif
                #else /* Was [181-184] */
                  #if (__COUNTER__ <= (182+9)) /* Was [181-182] */
                    #if (__COUNTER__ <= (181+10)) /* Was [181-181] */
                      #define ORIGINAL_COUNTER 181
                      #define VERIFICATION_COUNTER 192
                      #define PREDICTED_COUNTER 193
                    #else /* Was [182-182] */
                      #define ORIGINAL_COUNTER 182
                      #define VERIFICATION_COUNTER 193
                      #define PREDICTED_COUNTER 194
                    #endif
                  #else /* Was [183-184] */
                    #if (__COUNTER__ <= (183+10)) /* Was [183-183] */
                      #define ORIGINAL_COUNTER 183
                      #define VERIFICATION_COUNTER 194
                      #define PREDICTED_COUNTER 195
                    #else /* Was [184-184] */
                      #define ORIGINAL_COUNTER 184
                      #define VERIFICATION_COUNTER 195
                      #define PREDICTED_COUNTER 196
                    #endif
                  #endif
                #endif
              #else /* Was [185-192] */
                #if (__COUNTER__ <= (188+8)) /* Was [185-188] */
                  #if (__COUNTER__ <= (186+9)) /* Was [185-186] */
                    #if (__COUNTER__ <= (185+10)) /* Was [185-185] */
                      #define ORIGINAL_COUNTER 185
                      #define VERIFICATION_COUNTER 196
                      #define PREDICTED_COUNTER 197
                    #else /* Was [186-186] */
                      #define ORIGINAL_COUNTER 186
                      #define VERIFICATION_COUNTER 197
                      #define PREDICTED_COUNTER 198
                    #endif
                  #else /* Was [187-188] */
                    #if (__COUNTER__ <= (187+10)) /* Was [187-187] */
                      #define ORIGINAL_COUNTER 187
                      #define VERIFICATION_COUNTER 198
                      #define PREDICTED_COUNTER 199
                    #else /* Was [188-188] */
                      #define ORIGINAL_COUNTER 188
                      #define VERIFICATION_COUNTER 199
                      #define PREDICTED_COUNTER 200
                    #endif
                  #endif
                #else /* Was [189-192] */
                  #if (__COUNTER__ <= (190+9)) /* Was [189-190] */
                    #if (__COUNTER__ <= (189+10)) /* Was [189-189] */
                      #define ORIGINAL_COUNTER 189
                      #define VERIFICATION_COUNTER 200
                      #define PREDICTED_COUNTER 201
                    #else /* Was [190-190] */
                      #define ORIGINAL_COUNTER 190
                      #define VERIFICATION_COUNTER 201
                      #define PREDICTED_COUNTER 202
                    #endif
                  #else /* Was [191-192] */
                    #if (__COUNTER__ <= (191+10)) /* Was [191-191] */
                      #define ORIGINAL_COUNTER 191
                      #define VERIFICATION_COUNTER 202
                      #define PREDICTED_COUNTER 203
                    #else /* Was [192-192] */
                      #define ORIGINAL_COUNTER 192
                      #define VERIFICATION_COUNTER 203
                      #define PREDICTED_COUNTER 204
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #else /* Was [193-256] */
          #if (__COUNTER__ <= (224+5)) /* Was [193-224] */
            #if (__COUNTER__ <= (208+6)) /* Was [193-208] */
              #if (__COUNTER__ <= (200+7)) /* Was [193-200] */
                #if (__COUNTER__ <= (196+8)) /* Was [193-196] */
                  #if (__COUNTER__ <= (194+9)) /* Was [193-194] */
                    #if (__COUNTER__ <= (193+10)) /* Was [193-193] */
                      #define ORIGINAL_COUNTER 193
                      #define VERIFICATION_COUNTER 204
                      #define PREDICTED_COUNTER 205
                    #else /* Was [194-194] */
                      #define ORIGINAL_COUNTER 194
                      #define VERIFICATION_COUNTER 205
                      #define PREDICTED_COUNTER 206
                    #endif
                  #else /* Was [195-196] */
                    #if (__COUNTER__ <= (195+10)) /* Was [195-195] */
                      #define ORIGINAL_COUNTER 195
                      #define VERIFICATION_COUNTER 206
                      #define PREDICTED_COUNTER 207
                    #else /* Was [196-196] */
                      #define ORIGINAL_COUNTER 196
                      #define VERIFICATION_COUNTER 207
                      #define PREDICTED_COUNTER 208
                    #endif
                  #endif
                #else /* Was [197-200] */
                  #if (__COUNTER__ <= (198+9)) /* Was [197-198] */
                    #if (__COUNTER__ <= (197+10)) /* Was [197-197] */
                      #define ORIGINAL_COUNTER 197
                      #define VERIFICATION_COUNTER 208
                      #define PREDICTED_COUNTER 209
                    #else /* Was [198-198] */
                      #define ORIGINAL_COUNTER 198
                      #define VERIFICATION_COUNTER 209
                      #define PREDICTED_COUNTER 210
                    #endif
                  #else /* Was [199-200] */
                    #if (__COUNTER__ <= (199+10)) /* Was [199-199] */
                      #define ORIGINAL_COUNTER 199
                      #define VERIFICATION_COUNTER 210
                      #define PREDICTED_COUNTER 211
                    #else /* Was [200-200] */
                      #define ORIGINAL_COUNTER 200
                      #define VERIFICATION_COUNTER 211
                      #define PREDICTED_COUNTER 212
                    #endif
                  #endif
                #endif
              #else /* Was [201-208] */
                #if (__COUNTER__ <= (204+8)) /* Was [201-204] */
                  #if (__COUNTER__ <= (202+9)) /* Was [201-202] */
                    #if (__COUNTER__ <= (201+10)) /* Was [201-201] */
                      #define ORIGINAL_COUNTER 201
                      #define VERIFICATION_COUNTER 212
                      #define PREDICTED_COUNTER 213
                    #else /* Was [202-202] */
                      #define ORIGINAL_COUNTER 202
                      #define VERIFICATION_COUNTER 213
                      #define PREDICTED_COUNTER 214
                    #endif
                  #else /* Was [203-204] */
                    #if (__COUNTER__ <= (203+10)) /* Was [203-203] */
                      #define ORIGINAL_COUNTER 203
                      #define VERIFICATION_COUNTER 214
                      #define PREDICTED_COUNTER 215
                    #else /* Was [204-204] */
                      #define ORIGINAL_COUNTER 204
                      #define VERIFICATION_COUNTER 215
                      #define PREDICTED_COUNTER 216
                    #endif
                  #endif
                #else /* Was [205-208] */
                  #if (__COUNTER__ <= (206+9)) /* Was [205-206] */
                    #if (__COUNTER__ <= (205+10)) /* Was [205-205] */
                      #define ORIGINAL_COUNTER 205
                      #define VERIFICATION_COUNTER 216
                      #define PREDICTED_COUNTER 217
                    #else /* Was [206-206] */
                      #define ORIGINAL_COUNTER 206
                      #define VERIFICATION_COUNTER 217
                      #define PREDICTED_COUNTER 218
                    #endif
                  #else /* Was [207-208] */
                    #if (__COUNTER__ <= (207+10)) /* Was [207-207] */
                      #define ORIGINAL_COUNTER 207
                      #define VERIFICATION_COUNTER 218
                      #define PREDICTED_COUNTER 219
                    #else /* Was [208-208] */
                      #define ORIGINAL_COUNTER 208
                      #define VERIFICATION_COUNTER 219
                      #define PREDICTED_COUNTER 220
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [209-224] */
              #if (__COUNTER__ <= (216+7)) /* Was [209-216] */
                #if (__COUNTER__ <= (212+8)) /* Was [209-212] */
                  #if (__COUNTER__ <= (210+9)) /* Was [209-210] */
                    #if (__COUNTER__ <= (209+10)) /* Was [209-209] */
                      #define ORIGINAL_COUNTER 209
                      #define VERIFICATION_COUNTER 220
                      #define PREDICTED_COUNTER 221
                    #else /* Was [210-210] */
                      #define ORIGINAL_COUNTER 210
                      #define VERIFICATION_COUNTER 221
                      #define PREDICTED_COUNTER 222
                    #endif
                  #else /* Was [211-212] */
                    #if (__COUNTER__ <= (211+10)) /* Was [211-211] */
                      #define ORIGINAL_COUNTER 211
                      #define VERIFICATION_COUNTER 222
                      #define PREDICTED_COUNTER 223
                    #else /* Was [212-212] */
                      #define ORIGINAL_COUNTER 212
                      #define VERIFICATION_COUNTER 223
                      #define PREDICTED_COUNTER 224
                    #endif
                  #endif
                #else /* Was [213-216] */
                  #if (__COUNTER__ <= (214+9)) /* Was [213-214] */
                    #if (__COUNTER__ <= (213+10)) /* Was [213-213] */
                      #define ORIGINAL_COUNTER 213
                      #define VERIFICATION_COUNTER 224
                      #define PREDICTED_COUNTER 225
                    #else /* Was [214-214] */
                      #define ORIGINAL_COUNTER 214
                      #define VERIFICATION_COUNTER 225
                      #define PREDICTED_COUNTER 226
                    #endif
                  #else /* Was [215-216] */
                    #if (__COUNTER__ <= (215+10)) /* Was [215-215] */
                      #define ORIGINAL_COUNTER 215
                      #define VERIFICATION_COUNTER 226
                      #define PREDICTED_COUNTER 227
                    #else /* Was [216-216] */
                      #define ORIGINAL_COUNTER 216
                      #define VERIFICATION_COUNTER 227
                      #define PREDICTED_COUNTER 228
                    #endif
                  #endif
                #endif
              #else /* Was [217-224] */
                #if (__COUNTER__ <= (220+8)) /* Was [217-220] */
                  #if (__COUNTER__ <= (218+9)) /* Was [217-218] */
                    #if (__COUNTER__ <= (217+10)) /* Was [217-217] */
                      #define ORIGINAL_COUNTER 217
                      #define VERIFICATION_COUNTER 228
                      #define PREDICTED_COUNTER 229
                    #else /* Was [218-218] */
                      #define ORIGINAL_COUNTER 218
                      #define VERIFICATION_COUNTER 229
                      #define PREDICTED_COUNTER 230
                    #endif
                  #else /* Was [219-220] */
                    #if (__COUNTER__ <= (219+10)) /* Was [219-219] */
                      #define ORIGINAL_COUNTER 219
                      #define VERIFICATION_COUNTER 230
                      #define PREDICTED_COUNTER 231
                    #else /* Was [220-220] */
                      #define ORIGINAL_COUNTER 220
                      #define VERIFICATION_COUNTER 231
                      #define PREDICTED_COUNTER 232
                    #endif
                  #endif
                #else /* Was [221-224] */
                  #if (__COUNTER__ <= (222+9)) /* Was [221-222] */
                    #if (__COUNTER__ <= (221+10)) /* Was [221-221] */
                      #define ORIGINAL_COUNTER 221
                      #define VERIFICATION_COUNTER 232
                      #define PREDICTED_COUNTER 233
                    #else /* Was [222-222] */
                      #define ORIGINAL_COUNTER 222
                      #define VERIFICATION_COUNTER 233
                      #define PREDICTED_COUNTER 234
                    #endif
                  #else /* Was [223-224] */
                    #if (__COUNTER__ <= (223+10)) /* Was [223-223] */
                      #define ORIGINAL_COUNTER 223
                      #define VERIFICATION_COUNTER 234
                      #define PREDICTED_COUNTER 235
                    #else /* Was [224-224] */
                      #define ORIGINAL_COUNTER 224
                      #define VERIFICATION_COUNTER 235
                      #define PREDICTED_COUNTER 236
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [225-256] */
            #if (__COUNTER__ <= (240+6)) /* Was [225-240] */
              #if (__COUNTER__ <= (232+7)) /* Was [225-232] */
                #if (__COUNTER__ <= (228+8)) /* Was [225-228] */
                  #if (__COUNTER__ <= (226+9)) /* Was [225-226] */
                    #if (__COUNTER__ <= (225+10)) /* Was [225-225] */
                      #define ORIGINAL_COUNTER 225
                      #define VERIFICATION_COUNTER 236
                      #define PREDICTED_COUNTER 237
                    #else /* Was [226-226] */
                      #define ORIGINAL_COUNTER 226
                      #define VERIFICATION_COUNTER 237
                      #define PREDICTED_COUNTER 238
                    #endif
                  #else /* Was [227-228] */
                    #if (__COUNTER__ <= (227+10)) /* Was [227-227] */
                      #define ORIGINAL_COUNTER 227
                      #define VERIFICATION_COUNTER 238
                      #define PREDICTED_COUNTER 239
                    #else /* Was [228-228] */
                      #define ORIGINAL_COUNTER 228
                      #define VERIFICATION_COUNTER 239
                      #define PREDICTED_COUNTER 240
                    #endif
                  #endif
                #else /* Was [229-232] */
                  #if (__COUNTER__ <= (230+9)) /* Was [229-230] */
                    #if (__COUNTER__ <= (229+10)) /* Was [229-229] */
                      #define ORIGINAL_COUNTER 229
                      #define VERIFICATION_COUNTER 240
                      #define PREDICTED_COUNTER 241
                    #else /* Was [230-230] */
                      #define ORIGINAL_COUNTER 230
                      #define VERIFICATION_COUNTER 241
                      #define PREDICTED_COUNTER 242
                    #endif
                  #else /* Was [231-232] */
                    #if (__COUNTER__ <= (231+10)) /* Was [231-231] */
                      #define ORIGINAL_COUNTER 231
                      #define VERIFICATION_COUNTER 242
                      #define PREDICTED_COUNTER 243
                    #else /* Was [232-232] */
                      #define ORIGINAL_COUNTER 232
                      #define VERIFICATION_COUNTER 243
                      #define PREDICTED_COUNTER 244
                    #endif
                  #endif
                #endif
              #else /* Was [233-240] */
                #if (__COUNTER__ <= (236+8)) /* Was [233-236] */
                  #if (__COUNTER__ <= (234+9)) /* Was [233-234] */
                    #if (__COUNTER__ <= (233+10)) /* Was [233-233] */
                      #define ORIGINAL_COUNTER 233
                      #define VERIFICATION_COUNTER 244
                      #define PREDICTED_COUNTER 245
                    #else /* Was [234-234] */
                      #define ORIGINAL_COUNTER 234
                      #define VERIFICATION_COUNTER 245
                      #define PREDICTED_COUNTER 246
                    #endif
                  #else /* Was [235-236] */
                    #if (__COUNTER__ <= (235+10)) /* Was [235-235] */
                      #define ORIGINAL_COUNTER 235
                      #define VERIFICATION_COUNTER 246
                      #define PREDICTED_COUNTER 247
                    #else /* Was [236-236] */
                      #define ORIGINAL_COUNTER 236
                      #define VERIFICATION_COUNTER 247
                      #define PREDICTED_COUNTER 248
                    #endif
                  #endif
                #else /* Was [237-240] */
                  #if (__COUNTER__ <= (238+9)) /* Was [237-238] */
                    #if (__COUNTER__ <= (237+10)) /* Was [237-237] */
                      #define ORIGINAL_COUNTER 237
                      #define VERIFICATION_COUNTER 248
                      #define PREDICTED_COUNTER 249
                    #else /* Was [238-238] */
                      #define ORIGINAL_COUNTER 238
                      #define VERIFICATION_COUNTER 249
                      #define PREDICTED_COUNTER 250
                    #endif
                  #else /* Was [239-240] */
                    #if (__COUNTER__ <= (239+10)) /* Was [239-239] */
                      #define ORIGINAL_COUNTER 239
                      #define VERIFICATION_COUNTER 250
                      #define PREDICTED_COUNTER 251
                    #else /* Was [240-240] */
                      #define ORIGINAL_COUNTER 240
                      #define VERIFICATION_COUNTER 251
                      #define PREDICTED_COUNTER 252
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [241-256] */
              #if (__COUNTER__ <= (248+7)) /* Was [241-248] */
                #if (__COUNTER__ <= (244+8)) /* Was [241-244] */
                  #if (__COUNTER__ <= (242+9)) /* Was [241-242] */
                    #if (__COUNTER__ <= (241+10)) /* Was [241-241] */
                      #define ORIGINAL_COUNTER 241
                      #define VERIFICATION_COUNTER 252
                      #define PREDICTED_COUNTER 253
                    #else /* Was [242-242] */
                      #define ORIGINAL_COUNTER 242
                      #define VERIFICATION_COUNTER 253
                      #define PREDICTED_COUNTER 254
                    #endif
                  #else /* Was [243-244] */
                    #if (__COUNTER__ <= (243+10)) /* Was [243-243] */
                      #define ORIGINAL_COUNTER 243
                      #define VERIFICATION_COUNTER 254
                      #define PREDICTED_COUNTER 255
                    #else /* Was [244-244] */
                      #define ORIGINAL_COUNTER 244
                      #define VERIFICATION_COUNTER 255
                      #define PREDICTED_COUNTER 256
                    #endif
                  #endif
                #else /* Was [245-248] */
                  #if (__COUNTER__ <= (246+9)) /* Was [245-246] */
                    #if (__COUNTER__ <= (245+10)) /* Was [245-245] */
                      #define ORIGINAL_COUNTER 245
                      #define VERIFICATION_COUNTER 256
                      #define PREDICTED_COUNTER 257
                    #else /* Was [246-246] */
                      #define ORIGINAL_COUNTER 246
                      #define VERIFICATION_COUNTER 257
                      #define PREDICTED_COUNTER 258
                    #endif
                  #else /* Was [247-248] */
                    #if (__COUNTER__ <= (247+10)) /* Was [247-247] */
                      #define ORIGINAL_COUNTER 247
                      #define VERIFICATION_COUNTER 258
                      #define PREDICTED_COUNTER 259
                    #else /* Was [248-248] */
                      #define ORIGINAL_COUNTER 248
                      #define VERIFICATION_COUNTER 259
                      #define PREDICTED_COUNTER 260
                    #endif
                  #endif
                #endif
              #else /* Was [249-256] */
                #if (__COUNTER__ <= (252+8)) /* Was [249-252] */
                  #if (__COUNTER__ <= (250+9)) /* Was [249-250] */
                    #if (__COUNTER__ <= (249+10)) /* Was [249-249] */
                      #define ORIGINAL_COUNTER 249
                      #define VERIFICATION_COUNTER 260
                      #define PREDICTED_COUNTER 261
                    #else /* Was [250-250] */
                      #define ORIGINAL_COUNTER 250
                      #define VERIFICATION_COUNTER 261
                      #define PREDICTED_COUNTER 262
                    #endif
                  #else /* Was [251-252] */
                    #if (__COUNTER__ <= (251+10)) /* Was [251-251] */
                      #define ORIGINAL_COUNTER 251
                      #define VERIFICATION_COUNTER 262
                      #define PREDICTED_COUNTER 263
                    #else /* Was [252-252] */
                      #define ORIGINAL_COUNTER 252
                      #define VERIFICATION_COUNTER 263
                      #define PREDICTED_COUNTER 264
                    #endif
                  #endif
                #else /* Was [253-256] */
                  #if (__COUNTER__ <= (254+9)) /* Was [253-254] */
                    #if (__COUNTER__ <= (253+10)) /* Was [253-253] */
                      #define ORIGINAL_COUNTER 253
                      #define VERIFICATION_COUNTER 264
                      #define PREDICTED_COUNTER 265
                    #else /* Was [254-254] */
                      #define ORIGINAL_COUNTER 254
                      #define VERIFICATION_COUNTER 265
                      #define PREDICTED_COUNTER 266
                    #endif
                  #else /* Was [255-256] */
                    #if (__COUNTER__ <= (255+10)) /* Was [255-255] */
                      #define ORIGINAL_COUNTER 255
                      #define VERIFICATION_COUNTER 266
                      #define PREDICTED_COUNTER 267
                    #else /* Was [256-256] */
                      #define ORIGINAL_COUNTER 256
                      #define VERIFICATION_COUNTER 267
                      #define PREDICTED_COUNTER 268
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #endif
      #endif
    #else /* Was [257-512] */
      #if (__COUNTER__ <= (384+3)) /* Was [257-384] */
        #if (__COUNTER__ <= (320+4)) /* Was [257-320] */
          #if (__COUNTER__ <= (288+5)) /* Was [257-288] */
            #if (__COUNTER__ <= (272+6)) /* Was [257-272] */
              #if (__COUNTER__ <= (264+7)) /* Was [257-264] */
                #if (__COUNTER__ <= (260+8)) /* Was [257-260] */
                  #if (__COUNTER__ <= (258+9)) /* Was [257-258] */
                    #if (__COUNTER__ <= (257+10)) /* Was [257-257] */
                      #define ORIGINAL_COUNTER 257
                      #define VERIFICATION_COUNTER 268
                      #define PREDICTED_COUNTER 269
                    #else /* Was [258-258] */
                      #define ORIGINAL_COUNTER 258
                      #define VERIFICATION_COUNTER 269
                      #define PREDICTED_COUNTER 270
                    #endif
                  #else /* Was [259-260] */
                    #if (__COUNTER__ <= (259+10)) /* Was [259-259] */
                      #define ORIGINAL_COUNTER 259
                      #define VERIFICATION_COUNTER 270
                      #define PREDICTED_COUNTER 271
                    #else /* Was [260-260] */
                      #define ORIGINAL_COUNTER 260
                      #define VERIFICATION_COUNTER 271
                      #define PREDICTED_COUNTER 272
                    #endif
                  #endif
                #else /* Was [261-264] */
                  #if (__COUNTER__ <= (262+9)) /* Was [261-262] */
                    #if (__COUNTER__ <= (261+10)) /* Was [261-261] */
                      #define ORIGINAL_COUNTER 261
                      #define VERIFICATION_COUNTER 272
                      #define PREDICTED_COUNTER 273
                    #else /* Was [262-262] */
                      #define ORIGINAL_COUNTER 262
                      #define VERIFICATION_COUNTER 273
                      #define PREDICTED_COUNTER 274
                    #endif
                  #else /* Was [263-264] */
                    #if (__COUNTER__ <= (263+10)) /* Was [263-263] */
                      #define ORIGINAL_COUNTER 263
                      #define VERIFICATION_COUNTER 274
                      #define PREDICTED_COUNTER 275
                    #else /* Was [264-264] */
                      #define ORIGINAL_COUNTER 264
                      #define VERIFICATION_COUNTER 275
                      #define PREDICTED_COUNTER 276
                    #endif
                  #endif
                #endif
              #else /* Was [265-272] */
                #if (__COUNTER__ <= (268+8)) /* Was [265-268] */
                  #if (__COUNTER__ <= (266+9)) /* Was [265-266] */
                    #if (__COUNTER__ <= (265+10)) /* Was [265-265] */
                      #define ORIGINAL_COUNTER 265
                      #define VERIFICATION_COUNTER 276
                      #define PREDICTED_COUNTER 277
                    #else /* Was [266-266] */
                      #define ORIGINAL_COUNTER 266
                      #define VERIFICATION_COUNTER 277
                      #define PREDICTED_COUNTER 278
                    #endif
                  #else /* Was [267-268] */
                    #if (__COUNTER__ <= (267+10)) /* Was [267-267] */
                      #define ORIGINAL_COUNTER 267
                      #define VERIFICATION_COUNTER 278
                      #define PREDICTED_COUNTER 279
                    #else /* Was [268-268] */
                      #define ORIGINAL_COUNTER 268
                      #define VERIFICATION_COUNTER 279
                      #define PREDICTED_COUNTER 280
                    #endif
                  #endif
                #else /* Was [269-272] */
                  #if (__COUNTER__ <= (270+9)) /* Was [269-270] */
                    #if (__COUNTER__ <= (269+10)) /* Was [269-269] */
                      #define ORIGINAL_COUNTER 269
                      #define VERIFICATION_COUNTER 280
                      #define PREDICTED_COUNTER 281
                    #else /* Was [270-270] */
                      #define ORIGINAL_COUNTER 270
                      #define VERIFICATION_COUNTER 281
                      #define PREDICTED_COUNTER 282
                    #endif
                  #else /* Was [271-272] */
                    #if (__COUNTER__ <= (271+10)) /* Was [271-271] */
                      #define ORIGINAL_COUNTER 271
                      #define VERIFICATION_COUNTER 282
                      #define PREDICTED_COUNTER 283
                    #else /* Was [272-272] */
                      #define ORIGINAL_COUNTER 272
                      #define VERIFICATION_COUNTER 283
                      #define PREDICTED_COUNTER 284
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [273-288] */
              #if (__COUNTER__ <= (280+7)) /* Was [273-280] */
                #if (__COUNTER__ <= (276+8)) /* Was [273-276] */
                  #if (__COUNTER__ <= (274+9)) /* Was [273-274] */
                    #if (__COUNTER__ <= (273+10)) /* Was [273-273] */
                      #define ORIGINAL_COUNTER 273
                      #define VERIFICATION_COUNTER 284
                      #define PREDICTED_COUNTER 285
                    #else /* Was [274-274] */
                      #define ORIGINAL_COUNTER 274
                      #define VERIFICATION_COUNTER 285
                      #define PREDICTED_COUNTER 286
                    #endif
                  #else /* Was [275-276] */
                    #if (__COUNTER__ <= (275+10)) /* Was [275-275] */
                      #define ORIGINAL_COUNTER 275
                      #define VERIFICATION_COUNTER 286
                      #define PREDICTED_COUNTER 287
                    #else /* Was [276-276] */
                      #define ORIGINAL_COUNTER 276
                      #define VERIFICATION_COUNTER 287
                      #define PREDICTED_COUNTER 288
                    #endif
                  #endif
                #else /* Was [277-280] */
                  #if (__COUNTER__ <= (278+9)) /* Was [277-278] */
                    #if (__COUNTER__ <= (277+10)) /* Was [277-277] */
                      #define ORIGINAL_COUNTER 277
                      #define VERIFICATION_COUNTER 288
                      #define PREDICTED_COUNTER 289
                    #else /* Was [278-278] */
                      #define ORIGINAL_COUNTER 278
                      #define VERIFICATION_COUNTER 289
                      #define PREDICTED_COUNTER 290
                    #endif
                  #else /* Was [279-280] */
                    #if (__COUNTER__ <= (279+10)) /* Was [279-279] */
                      #define ORIGINAL_COUNTER 279
                      #define VERIFICATION_COUNTER 290
                      #define PREDICTED_COUNTER 291
                    #else /* Was [280-280] */
                      #define ORIGINAL_COUNTER 280
                      #define VERIFICATION_COUNTER 291
                      #define PREDICTED_COUNTER 292
                    #endif
                  #endif
                #endif
              #else /* Was [281-288] */
                #if (__COUNTER__ <= (284+8)) /* Was [281-284] */
                  #if (__COUNTER__ <= (282+9)) /* Was [281-282] */
                    #if (__COUNTER__ <= (281+10)) /* Was [281-281] */
                      #define ORIGINAL_COUNTER 281
                      #define VERIFICATION_COUNTER 292
                      #define PREDICTED_COUNTER 293
                    #else /* Was [282-282] */
                      #define ORIGINAL_COUNTER 282
                      #define VERIFICATION_COUNTER 293
                      #define PREDICTED_COUNTER 294
                    #endif
                  #else /* Was [283-284] */
                    #if (__COUNTER__ <= (283+10)) /* Was [283-283] */
                      #define ORIGINAL_COUNTER 283
                      #define VERIFICATION_COUNTER 294
                      #define PREDICTED_COUNTER 295
                    #else /* Was [284-284] */
                      #define ORIGINAL_COUNTER 284
                      #define VERIFICATION_COUNTER 295
                      #define PREDICTED_COUNTER 296
                    #endif
                  #endif
                #else /* Was [285-288] */
                  #if (__COUNTER__ <= (286+9)) /* Was [285-286] */
                    #if (__COUNTER__ <= (285+10)) /* Was [285-285] */
                      #define ORIGINAL_COUNTER 285
                      #define VERIFICATION_COUNTER 296
                      #define PREDICTED_COUNTER 297
                    #else /* Was [286-286] */
                      #define ORIGINAL_COUNTER 286
                      #define VERIFICATION_COUNTER 297
                      #define PREDICTED_COUNTER 298
                    #endif
                  #else /* Was [287-288] */
                    #if (__COUNTER__ <= (287+10)) /* Was [287-287] */
                      #define ORIGINAL_COUNTER 287
                      #define VERIFICATION_COUNTER 298
                      #define PREDICTED_COUNTER 299
                    #else /* Was [288-288] */
                      #define ORIGINAL_COUNTER 288
                      #define VERIFICATION_COUNTER 299
                      #define PREDICTED_COUNTER 300
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [289-320] */
            #if (__COUNTER__ <= (304+6)) /* Was [289-304] */
              #if (__COUNTER__ <= (296+7)) /* Was [289-296] */
                #if (__COUNTER__ <= (292+8)) /* Was [289-292] */
                  #if (__COUNTER__ <= (290+9)) /* Was [289-290] */
                    #if (__COUNTER__ <= (289+10)) /* Was [289-289] */
                      #define ORIGINAL_COUNTER 289
                      #define VERIFICATION_COUNTER 300
                      #define PREDICTED_COUNTER 301
                    #else /* Was [290-290] */
                      #define ORIGINAL_COUNTER 290
                      #define VERIFICATION_COUNTER 301
                      #define PREDICTED_COUNTER 302
                    #endif
                  #else /* Was [291-292] */
                    #if (__COUNTER__ <= (291+10)) /* Was [291-291] */
                      #define ORIGINAL_COUNTER 291
                      #define VERIFICATION_COUNTER 302
                      #define PREDICTED_COUNTER 303
                    #else /* Was [292-292] */
                      #define ORIGINAL_COUNTER 292
                      #define VERIFICATION_COUNTER 303
                      #define PREDICTED_COUNTER 304
                    #endif
                  #endif
                #else /* Was [293-296] */
                  #if (__COUNTER__ <= (294+9)) /* Was [293-294] */
                    #if (__COUNTER__ <= (293+10)) /* Was [293-293] */
                      #define ORIGINAL_COUNTER 293
                      #define VERIFICATION_COUNTER 304
                      #define PREDICTED_COUNTER 305
                    #else /* Was [294-294] */
                      #define ORIGINAL_COUNTER 294
                      #define VERIFICATION_COUNTER 305
                      #define PREDICTED_COUNTER 306
                    #endif
                  #else /* Was [295-296] */
                    #if (__COUNTER__ <= (295+10)) /* Was [295-295] */
                      #define ORIGINAL_COUNTER 295
                      #define VERIFICATION_COUNTER 306
                      #define PREDICTED_COUNTER 307
                    #else /* Was [296-296] */
                      #define ORIGINAL_COUNTER 296
                      #define VERIFICATION_COUNTER 307
                      #define PREDICTED_COUNTER 308
                    #endif
                  #endif
                #endif
              #else /* Was [297-304] */
                #if (__COUNTER__ <= (300+8)) /* Was [297-300] */
                  #if (__COUNTER__ <= (298+9)) /* Was [297-298] */
                    #if (__COUNTER__ <= (297+10)) /* Was [297-297] */
                      #define ORIGINAL_COUNTER 297
                      #define VERIFICATION_COUNTER 308
                      #define PREDICTED_COUNTER 309
                    #else /* Was [298-298] */
                      #define ORIGINAL_COUNTER 298
                      #define VERIFICATION_COUNTER 309
                      #define PREDICTED_COUNTER 310
                    #endif
                  #else /* Was [299-300] */
                    #if (__COUNTER__ <= (299+10)) /* Was [299-299] */
                      #define ORIGINAL_COUNTER 299
                      #define VERIFICATION_COUNTER 310
                      #define PREDICTED_COUNTER 311
                    #else /* Was [300-300] */
                      #define ORIGINAL_COUNTER 300
                      #define VERIFICATION_COUNTER 311
                      #define PREDICTED_COUNTER 312
                    #endif
                  #endif
                #else /* Was [301-304] */
                  #if (__COUNTER__ <= (302+9)) /* Was [301-302] */
                    #if (__COUNTER__ <= (301+10)) /* Was [301-301] */
                      #define ORIGINAL_COUNTER 301
                      #define VERIFICATION_COUNTER 312
                      #define PREDICTED_COUNTER 313
                    #else /* Was [302-302] */
                      #define ORIGINAL_COUNTER 302
                      #define VERIFICATION_COUNTER 313
                      #define PREDICTED_COUNTER 314
                    #endif
                  #else /* Was [303-304] */
                    #if (__COUNTER__ <= (303+10)) /* Was [303-303] */
                      #define ORIGINAL_COUNTER 303
                      #define VERIFICATION_COUNTER 314
                      #define PREDICTED_COUNTER 315
                    #else /* Was [304-304] */
                      #define ORIGINAL_COUNTER 304
                      #define VERIFICATION_COUNTER 315
                      #define PREDICTED_COUNTER 316
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [305-320] */
              #if (__COUNTER__ <= (312+7)) /* Was [305-312] */
                #if (__COUNTER__ <= (308+8)) /* Was [305-308] */
                  #if (__COUNTER__ <= (306+9)) /* Was [305-306] */
                    #if (__COUNTER__ <= (305+10)) /* Was [305-305] */
                      #define ORIGINAL_COUNTER 305
                      #define VERIFICATION_COUNTER 316
                      #define PREDICTED_COUNTER 317
                    #else /* Was [306-306] */
                      #define ORIGINAL_COUNTER 306
                      #define VERIFICATION_COUNTER 317
                      #define PREDICTED_COUNTER 318
                    #endif
                  #else /* Was [307-308] */
                    #if (__COUNTER__ <= (307+10)) /* Was [307-307] */
                      #define ORIGINAL_COUNTER 307
                      #define VERIFICATION_COUNTER 318
                      #define PREDICTED_COUNTER 319
                    #else /* Was [308-308] */
                      #define ORIGINAL_COUNTER 308
                      #define VERIFICATION_COUNTER 319
                      #define PREDICTED_COUNTER 320
                    #endif
                  #endif
                #else /* Was [309-312] */
                  #if (__COUNTER__ <= (310+9)) /* Was [309-310] */
                    #if (__COUNTER__ <= (309+10)) /* Was [309-309] */
                      #define ORIGINAL_COUNTER 309
                      #define VERIFICATION_COUNTER 320
                      #define PREDICTED_COUNTER 321
                    #else /* Was [310-310] */
                      #define ORIGINAL_COUNTER 310
                      #define VERIFICATION_COUNTER 321
                      #define PREDICTED_COUNTER 322
                    #endif
                  #else /* Was [311-312] */
                    #if (__COUNTER__ <= (311+10)) /* Was [311-311] */
                      #define ORIGINAL_COUNTER 311
                      #define VERIFICATION_COUNTER 322
                      #define PREDICTED_COUNTER 323
                    #else /* Was [312-312] */
                      #define ORIGINAL_COUNTER 312
                      #define VERIFICATION_COUNTER 323
                      #define PREDICTED_COUNTER 324
                    #endif
                  #endif
                #endif
              #else /* Was [313-320] */
                #if (__COUNTER__ <= (316+8)) /* Was [313-316] */
                  #if (__COUNTER__ <= (314+9)) /* Was [313-314] */
                    #if (__COUNTER__ <= (313+10)) /* Was [313-313] */
                      #define ORIGINAL_COUNTER 313
                      #define VERIFICATION_COUNTER 324
                      #define PREDICTED_COUNTER 325
                    #else /* Was [314-314] */
                      #define ORIGINAL_COUNTER 314
                      #define VERIFICATION_COUNTER 325
                      #define PREDICTED_COUNTER 326
                    #endif
                  #else /* Was [315-316] */
                    #if (__COUNTER__ <= (315+10)) /* Was [315-315] */
                      #define ORIGINAL_COUNTER 315
                      #define VERIFICATION_COUNTER 326
                      #define PREDICTED_COUNTER 327
                    #else /* Was [316-316] */
                      #define ORIGINAL_COUNTER 316
                      #define VERIFICATION_COUNTER 327
                      #define PREDICTED_COUNTER 328
                    #endif
                  #endif
                #else /* Was [317-320] */
                  #if (__COUNTER__ <= (318+9)) /* Was [317-318] */
                    #if (__COUNTER__ <= (317+10)) /* Was [317-317] */
                      #define ORIGINAL_COUNTER 317
                      #define VERIFICATION_COUNTER 328
                      #define PREDICTED_COUNTER 329
                    #else /* Was [318-318] */
                      #define ORIGINAL_COUNTER 318
                      #define VERIFICATION_COUNTER 329
                      #define PREDICTED_COUNTER 330
                    #endif
                  #else /* Was [319-320] */
                    #if (__COUNTER__ <= (319+10)) /* Was [319-319] */
                      #define ORIGINAL_COUNTER 319
                      #define VERIFICATION_COUNTER 330
                      #define PREDICTED_COUNTER 331
                    #else /* Was [320-320] */
                      #define ORIGINAL_COUNTER 320
                      #define VERIFICATION_COUNTER 331
                      #define PREDICTED_COUNTER 332
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #else /* Was [321-384] */
          #if (__COUNTER__ <= (352+5)) /* Was [321-352] */
            #if (__COUNTER__ <= (336+6)) /* Was [321-336] */
              #if (__COUNTER__ <= (328+7)) /* Was [321-328] */
                #if (__COUNTER__ <= (324+8)) /* Was [321-324] */
                  #if (__COUNTER__ <= (322+9)) /* Was [321-322] */
                    #if (__COUNTER__ <= (321+10)) /* Was [321-321] */
                      #define ORIGINAL_COUNTER 321
                      #define VERIFICATION_COUNTER 332
                      #define PREDICTED_COUNTER 333
                    #else /* Was [322-322] */
                      #define ORIGINAL_COUNTER 322
                      #define VERIFICATION_COUNTER 333
                      #define PREDICTED_COUNTER 334
                    #endif
                  #else /* Was [323-324] */
                    #if (__COUNTER__ <= (323+10)) /* Was [323-323] */
                      #define ORIGINAL_COUNTER 323
                      #define VERIFICATION_COUNTER 334
                      #define PREDICTED_COUNTER 335
                    #else /* Was [324-324] */
                      #define ORIGINAL_COUNTER 324
                      #define VERIFICATION_COUNTER 335
                      #define PREDICTED_COUNTER 336
                    #endif
                  #endif
                #else /* Was [325-328] */
                  #if (__COUNTER__ <= (326+9)) /* Was [325-326] */
                    #if (__COUNTER__ <= (325+10)) /* Was [325-325] */
                      #define ORIGINAL_COUNTER 325
                      #define VERIFICATION_COUNTER 336
                      #define PREDICTED_COUNTER 337
                    #else /* Was [326-326] */
                      #define ORIGINAL_COUNTER 326
                      #define VERIFICATION_COUNTER 337
                      #define PREDICTED_COUNTER 338
                    #endif
                  #else /* Was [327-328] */
                    #if (__COUNTER__ <= (327+10)) /* Was [327-327] */
                      #define ORIGINAL_COUNTER 327
                      #define VERIFICATION_COUNTER 338
                      #define PREDICTED_COUNTER 339
                    #else /* Was [328-328] */
                      #define ORIGINAL_COUNTER 328
                      #define VERIFICATION_COUNTER 339
                      #define PREDICTED_COUNTER 340
                    #endif
                  #endif
                #endif
              #else /* Was [329-336] */
                #if (__COUNTER__ <= (332+8)) /* Was [329-332] */
                  #if (__COUNTER__ <= (330+9)) /* Was [329-330] */
                    #if (__COUNTER__ <= (329+10)) /* Was [329-329] */
                      #define ORIGINAL_COUNTER 329
                      #define VERIFICATION_COUNTER 340
                      #define PREDICTED_COUNTER 341
                    #else /* Was [330-330] */
                      #define ORIGINAL_COUNTER 330
                      #define VERIFICATION_COUNTER 341
                      #define PREDICTED_COUNTER 342
                    #endif
                  #else /* Was [331-332] */
                    #if (__COUNTER__ <= (331+10)) /* Was [331-331] */
                      #define ORIGINAL_COUNTER 331
                      #define VERIFICATION_COUNTER 342
                      #define PREDICTED_COUNTER 343
                    #else /* Was [332-332] */
                      #define ORIGINAL_COUNTER 332
                      #define VERIFICATION_COUNTER 343
                      #define PREDICTED_COUNTER 344
                    #endif
                  #endif
                #else /* Was [333-336] */
                  #if (__COUNTER__ <= (334+9)) /* Was [333-334] */
                    #if (__COUNTER__ <= (333+10)) /* Was [333-333] */
                      #define ORIGINAL_COUNTER 333
                      #define VERIFICATION_COUNTER 344
                      #define PREDICTED_COUNTER 345
                    #else /* Was [334-334] */
                      #define ORIGINAL_COUNTER 334
                      #define VERIFICATION_COUNTER 345
                      #define PREDICTED_COUNTER 346
                    #endif
                  #else /* Was [335-336] */
                    #if (__COUNTER__ <= (335+10)) /* Was [335-335] */
                      #define ORIGINAL_COUNTER 335
                      #define VERIFICATION_COUNTER 346
                      #define PREDICTED_COUNTER 347
                    #else /* Was [336-336] */
                      #define ORIGINAL_COUNTER 336
                      #define VERIFICATION_COUNTER 347
                      #define PREDICTED_COUNTER 348
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [337-352] */
              #if (__COUNTER__ <= (344+7)) /* Was [337-344] */
                #if (__COUNTER__ <= (340+8)) /* Was [337-340] */
                  #if (__COUNTER__ <= (338+9)) /* Was [337-338] */
                    #if (__COUNTER__ <= (337+10)) /* Was [337-337] */
                      #define ORIGINAL_COUNTER 337
                      #define VERIFICATION_COUNTER 348
                      #define PREDICTED_COUNTER 349
                    #else /* Was [338-338] */
                      #define ORIGINAL_COUNTER 338
                      #define VERIFICATION_COUNTER 349
                      #define PREDICTED_COUNTER 350
                    #endif
                  #else /* Was [339-340] */
                    #if (__COUNTER__ <= (339+10)) /* Was [339-339] */
                      #define ORIGINAL_COUNTER 339
                      #define VERIFICATION_COUNTER 350
                      #define PREDICTED_COUNTER 351
                    #else /* Was [340-340] */
                      #define ORIGINAL_COUNTER 340
                      #define VERIFICATION_COUNTER 351
                      #define PREDICTED_COUNTER 352
                    #endif
                  #endif
                #else /* Was [341-344] */
                  #if (__COUNTER__ <= (342+9)) /* Was [341-342] */
                    #if (__COUNTER__ <= (341+10)) /* Was [341-341] */
                      #define ORIGINAL_COUNTER 341
                      #define VERIFICATION_COUNTER 352
                      #define PREDICTED_COUNTER 353
                    #else /* Was [342-342] */
                      #define ORIGINAL_COUNTER 342
                      #define VERIFICATION_COUNTER 353
                      #define PREDICTED_COUNTER 354
                    #endif
                  #else /* Was [343-344] */
                    #if (__COUNTER__ <= (343+10)) /* Was [343-343] */
                      #define ORIGINAL_COUNTER 343
                      #define VERIFICATION_COUNTER 354
                      #define PREDICTED_COUNTER 355
                    #else /* Was [344-344] */
                      #define ORIGINAL_COUNTER 344
                      #define VERIFICATION_COUNTER 355
                      #define PREDICTED_COUNTER 356
                    #endif
                  #endif
                #endif
              #else /* Was [345-352] */
                #if (__COUNTER__ <= (348+8)) /* Was [345-348] */
                  #if (__COUNTER__ <= (346+9)) /* Was [345-346] */
                    #if (__COUNTER__ <= (345+10)) /* Was [345-345] */
                      #define ORIGINAL_COUNTER 345
                      #define VERIFICATION_COUNTER 356
                      #define PREDICTED_COUNTER 357
                    #else /* Was [346-346] */
                      #define ORIGINAL_COUNTER 346
                      #define VERIFICATION_COUNTER 357
                      #define PREDICTED_COUNTER 358
                    #endif
                  #else /* Was [347-348] */
                    #if (__COUNTER__ <= (347+10)) /* Was [347-347] */
                      #define ORIGINAL_COUNTER 347
                      #define VERIFICATION_COUNTER 358
                      #define PREDICTED_COUNTER 359
                    #else /* Was [348-348] */
                      #define ORIGINAL_COUNTER 348
                      #define VERIFICATION_COUNTER 359
                      #define PREDICTED_COUNTER 360
                    #endif
                  #endif
                #else /* Was [349-352] */
                  #if (__COUNTER__ <= (350+9)) /* Was [349-350] */
                    #if (__COUNTER__ <= (349+10)) /* Was [349-349] */
                      #define ORIGINAL_COUNTER 349
                      #define VERIFICATION_COUNTER 360
                      #define PREDICTED_COUNTER 361
                    #else /* Was [350-350] */
                      #define ORIGINAL_COUNTER 350
                      #define VERIFICATION_COUNTER 361
                      #define PREDICTED_COUNTER 362
                    #endif
                  #else /* Was [351-352] */
                    #if (__COUNTER__ <= (351+10)) /* Was [351-351] */
                      #define ORIGINAL_COUNTER 351
                      #define VERIFICATION_COUNTER 362
                      #define PREDICTED_COUNTER 363
                    #else /* Was [352-352] */
                      #define ORIGINAL_COUNTER 352
                      #define VERIFICATION_COUNTER 363
                      #define PREDICTED_COUNTER 364
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [353-384] */
            #if (__COUNTER__ <= (368+6)) /* Was [353-368] */
              #if (__COUNTER__ <= (360+7)) /* Was [353-360] */
                #if (__COUNTER__ <= (356+8)) /* Was [353-356] */
                  #if (__COUNTER__ <= (354+9)) /* Was [353-354] */
                    #if (__COUNTER__ <= (353+10)) /* Was [353-353] */
                      #define ORIGINAL_COUNTER 353
                      #define VERIFICATION_COUNTER 364
                      #define PREDICTED_COUNTER 365
                    #else /* Was [354-354] */
                      #define ORIGINAL_COUNTER 354
                      #define VERIFICATION_COUNTER 365
                      #define PREDICTED_COUNTER 366
                    #endif
                  #else /* Was [355-356] */
                    #if (__COUNTER__ <= (355+10)) /* Was [355-355] */
                      #define ORIGINAL_COUNTER 355
                      #define VERIFICATION_COUNTER 366
                      #define PREDICTED_COUNTER 367
                    #else /* Was [356-356] */
                      #define ORIGINAL_COUNTER 356
                      #define VERIFICATION_COUNTER 367
                      #define PREDICTED_COUNTER 368
                    #endif
                  #endif
                #else /* Was [357-360] */
                  #if (__COUNTER__ <= (358+9)) /* Was [357-358] */
                    #if (__COUNTER__ <= (357+10)) /* Was [357-357] */
                      #define ORIGINAL_COUNTER 357
                      #define VERIFICATION_COUNTER 368
                      #define PREDICTED_COUNTER 369
                    #else /* Was [358-358] */
                      #define ORIGINAL_COUNTER 358
                      #define VERIFICATION_COUNTER 369
                      #define PREDICTED_COUNTER 370
                    #endif
                  #else /* Was [359-360] */
                    #if (__COUNTER__ <= (359+10)) /* Was [359-359] */
                      #define ORIGINAL_COUNTER 359
                      #define VERIFICATION_COUNTER 370
                      #define PREDICTED_COUNTER 371
                    #else /* Was [360-360] */
                      #define ORIGINAL_COUNTER 360
                      #define VERIFICATION_COUNTER 371
                      #define PREDICTED_COUNTER 372
                    #endif
                  #endif
                #endif
              #else /* Was [361-368] */
                #if (__COUNTER__ <= (364+8)) /* Was [361-364] */
                  #if (__COUNTER__ <= (362+9)) /* Was [361-362] */
                    #if (__COUNTER__ <= (361+10)) /* Was [361-361] */
                      #define ORIGINAL_COUNTER 361
                      #define VERIFICATION_COUNTER 372
                      #define PREDICTED_COUNTER 373
                    #else /* Was [362-362] */
                      #define ORIGINAL_COUNTER 362
                      #define VERIFICATION_COUNTER 373
                      #define PREDICTED_COUNTER 374
                    #endif
                  #else /* Was [363-364] */
                    #if (__COUNTER__ <= (363+10)) /* Was [363-363] */
                      #define ORIGINAL_COUNTER 363
                      #define VERIFICATION_COUNTER 374
                      #define PREDICTED_COUNTER 375
                    #else /* Was [364-364] */
                      #define ORIGINAL_COUNTER 364
                      #define VERIFICATION_COUNTER 375
                      #define PREDICTED_COUNTER 376
                    #endif
                  #endif
                #else /* Was [365-368] */
                  #if (__COUNTER__ <= (366+9)) /* Was [365-366] */
                    #if (__COUNTER__ <= (365+10)) /* Was [365-365] */
                      #define ORIGINAL_COUNTER 365
                      #define VERIFICATION_COUNTER 376
                      #define PREDICTED_COUNTER 377
                    #else /* Was [366-366] */
                      #define ORIGINAL_COUNTER 366
                      #define VERIFICATION_COUNTER 377
                      #define PREDICTED_COUNTER 378
                    #endif
                  #else /* Was [367-368] */
                    #if (__COUNTER__ <= (367+10)) /* Was [367-367] */
                      #define ORIGINAL_COUNTER 367
                      #define VERIFICATION_COUNTER 378
                      #define PREDICTED_COUNTER 379
                    #else /* Was [368-368] */
                      #define ORIGINAL_COUNTER 368
                      #define VERIFICATION_COUNTER 379
                      #define PREDICTED_COUNTER 380
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [369-384] */
              #if (__COUNTER__ <= (376+7)) /* Was [369-376] */
                #if (__COUNTER__ <= (372+8)) /* Was [369-372] */
                  #if (__COUNTER__ <= (370+9)) /* Was [369-370] */
                    #if (__COUNTER__ <= (369+10)) /* Was [369-369] */
                      #define ORIGINAL_COUNTER 369
                      #define VERIFICATION_COUNTER 380
                      #define PREDICTED_COUNTER 381
                    #else /* Was [370-370] */
                      #define ORIGINAL_COUNTER 370
                      #define VERIFICATION_COUNTER 381
                      #define PREDICTED_COUNTER 382
                    #endif
                  #else /* Was [371-372] */
                    #if (__COUNTER__ <= (371+10)) /* Was [371-371] */
                      #define ORIGINAL_COUNTER 371
                      #define VERIFICATION_COUNTER 382
                      #define PREDICTED_COUNTER 383
                    #else /* Was [372-372] */
                      #define ORIGINAL_COUNTER 372
                      #define VERIFICATION_COUNTER 383
                      #define PREDICTED_COUNTER 384
                    #endif
                  #endif
                #else /* Was [373-376] */
                  #if (__COUNTER__ <= (374+9)) /* Was [373-374] */
                    #if (__COUNTER__ <= (373+10)) /* Was [373-373] */
                      #define ORIGINAL_COUNTER 373
                      #define VERIFICATION_COUNTER 384
                      #define PREDICTED_COUNTER 385
                    #else /* Was [374-374] */
                      #define ORIGINAL_COUNTER 374
                      #define VERIFICATION_COUNTER 385
                      #define PREDICTED_COUNTER 386
                    #endif
                  #else /* Was [375-376] */
                    #if (__COUNTER__ <= (375+10)) /* Was [375-375] */
                      #define ORIGINAL_COUNTER 375
                      #define VERIFICATION_COUNTER 386
                      #define PREDICTED_COUNTER 387
                    #else /* Was [376-376] */
                      #define ORIGINAL_COUNTER 376
                      #define VERIFICATION_COUNTER 387
                      #define PREDICTED_COUNTER 388
                    #endif
                  #endif
                #endif
              #else /* Was [377-384] */
                #if (__COUNTER__ <= (380+8)) /* Was [377-380] */
                  #if (__COUNTER__ <= (378+9)) /* Was [377-378] */
                    #if (__COUNTER__ <= (377+10)) /* Was [377-377] */
                      #define ORIGINAL_COUNTER 377
                      #define VERIFICATION_COUNTER 388
                      #define PREDICTED_COUNTER 389
                    #else /* Was [378-378] */
                      #define ORIGINAL_COUNTER 378
                      #define VERIFICATION_COUNTER 389
                      #define PREDICTED_COUNTER 390
                    #endif
                  #else /* Was [379-380] */
                    #if (__COUNTER__ <= (379+10)) /* Was [379-379] */
                      #define ORIGINAL_COUNTER 379
                      #define VERIFICATION_COUNTER 390
                      #define PREDICTED_COUNTER 391
                    #else /* Was [380-380] */
                      #define ORIGINAL_COUNTER 380
                      #define VERIFICATION_COUNTER 391
                      #define PREDICTED_COUNTER 392
                    #endif
                  #endif
                #else /* Was [381-384] */
                  #if (__COUNTER__ <= (382+9)) /* Was [381-382] */
                    #if (__COUNTER__ <= (381+10)) /* Was [381-381] */
                      #define ORIGINAL_COUNTER 381
                      #define VERIFICATION_COUNTER 392
                      #define PREDICTED_COUNTER 393
                    #else /* Was [382-382] */
                      #define ORIGINAL_COUNTER 382
                      #define VERIFICATION_COUNTER 393
                      #define PREDICTED_COUNTER 394
                    #endif
                  #else /* Was [383-384] */
                    #if (__COUNTER__ <= (383+10)) /* Was [383-383] */
                      #define ORIGINAL_COUNTER 383
                      #define VERIFICATION_COUNTER 394
                      #define PREDICTED_COUNTER 395
                    #else /* Was [384-384] */
                      #define ORIGINAL_COUNTER 384
                      #define VERIFICATION_COUNTER 395
                      #define PREDICTED_COUNTER 396
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #endif
      #else /* Was [385-512] */
        #if (__COUNTER__ <= (448+4)) /* Was [385-448] */
          #if (__COUNTER__ <= (416+5)) /* Was [385-416] */
            #if (__COUNTER__ <= (400+6)) /* Was [385-400] */
              #if (__COUNTER__ <= (392+7)) /* Was [385-392] */
                #if (__COUNTER__ <= (388+8)) /* Was [385-388] */
                  #if (__COUNTER__ <= (386+9)) /* Was [385-386] */
                    #if (__COUNTER__ <= (385+10)) /* Was [385-385] */
                      #define ORIGINAL_COUNTER 385
                      #define VERIFICATION_COUNTER 396
                      #define PREDICTED_COUNTER 397
                    #else /* Was [386-386] */
                      #define ORIGINAL_COUNTER 386
                      #define VERIFICATION_COUNTER 397
                      #define PREDICTED_COUNTER 398
                    #endif
                  #else /* Was [387-388] */
                    #if (__COUNTER__ <= (387+10)) /* Was [387-387] */
                      #define ORIGINAL_COUNTER 387
                      #define VERIFICATION_COUNTER 398
                      #define PREDICTED_COUNTER 399
                    #else /* Was [388-388] */
                      #define ORIGINAL_COUNTER 388
                      #define VERIFICATION_COUNTER 399
                      #define PREDICTED_COUNTER 400
                    #endif
                  #endif
                #else /* Was [389-392] */
                  #if (__COUNTER__ <= (390+9)) /* Was [389-390] */
                    #if (__COUNTER__ <= (389+10)) /* Was [389-389] */
                      #define ORIGINAL_COUNTER 389
                      #define VERIFICATION_COUNTER 400
                      #define PREDICTED_COUNTER 401
                    #else /* Was [390-390] */
                      #define ORIGINAL_COUNTER 390
                      #define VERIFICATION_COUNTER 401
                      #define PREDICTED_COUNTER 402
                    #endif
                  #else /* Was [391-392] */
                    #if (__COUNTER__ <= (391+10)) /* Was [391-391] */
                      #define ORIGINAL_COUNTER 391
                      #define VERIFICATION_COUNTER 402
                      #define PREDICTED_COUNTER 403
                    #else /* Was [392-392] */
                      #define ORIGINAL_COUNTER 392
                      #define VERIFICATION_COUNTER 403
                      #define PREDICTED_COUNTER 404
                    #endif
                  #endif
                #endif
              #else /* Was [393-400] */
                #if (__COUNTER__ <= (396+8)) /* Was [393-396] */
                  #if (__COUNTER__ <= (394+9)) /* Was [393-394] */
                    #if (__COUNTER__ <= (393+10)) /* Was [393-393] */
                      #define ORIGINAL_COUNTER 393
                      #define VERIFICATION_COUNTER 404
                      #define PREDICTED_COUNTER 405
                    #else /* Was [394-394] */
                      #define ORIGINAL_COUNTER 394
                      #define VERIFICATION_COUNTER 405
                      #define PREDICTED_COUNTER 406
                    #endif
                  #else /* Was [395-396] */
                    #if (__COUNTER__ <= (395+10)) /* Was [395-395] */
                      #define ORIGINAL_COUNTER 395
                      #define VERIFICATION_COUNTER 406
                      #define PREDICTED_COUNTER 407
                    #else /* Was [396-396] */
                      #define ORIGINAL_COUNTER 396
                      #define VERIFICATION_COUNTER 407
                      #define PREDICTED_COUNTER 408
                    #endif
                  #endif
                #else /* Was [397-400] */
                  #if (__COUNTER__ <= (398+9)) /* Was [397-398] */
                    #if (__COUNTER__ <= (397+10)) /* Was [397-397] */
                      #define ORIGINAL_COUNTER 397
                      #define VERIFICATION_COUNTER 408
                      #define PREDICTED_COUNTER 409
                    #else /* Was [398-398] */
                      #define ORIGINAL_COUNTER 398
                      #define VERIFICATION_COUNTER 409
                      #define PREDICTED_COUNTER 410
                    #endif
                  #else /* Was [399-400] */
                    #if (__COUNTER__ <= (399+10)) /* Was [399-399] */
                      #define ORIGINAL_COUNTER 399
                      #define VERIFICATION_COUNTER 410
                      #define PREDICTED_COUNTER 411
                    #else /* Was [400-400] */
                      #define ORIGINAL_COUNTER 400
                      #define VERIFICATION_COUNTER 411
                      #define PREDICTED_COUNTER 412
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [401-416] */
              #if (__COUNTER__ <= (408+7)) /* Was [401-408] */
                #if (__COUNTER__ <= (404+8)) /* Was [401-404] */
                  #if (__COUNTER__ <= (402+9)) /* Was [401-402] */
                    #if (__COUNTER__ <= (401+10)) /* Was [401-401] */
                      #define ORIGINAL_COUNTER 401
                      #define VERIFICATION_COUNTER 412
                      #define PREDICTED_COUNTER 413
                    #else /* Was [402-402] */
                      #define ORIGINAL_COUNTER 402
                      #define VERIFICATION_COUNTER 413
                      #define PREDICTED_COUNTER 414
                    #endif
                  #else /* Was [403-404] */
                    #if (__COUNTER__ <= (403+10)) /* Was [403-403] */
                      #define ORIGINAL_COUNTER 403
                      #define VERIFICATION_COUNTER 414
                      #define PREDICTED_COUNTER 415
                    #else /* Was [404-404] */
                      #define ORIGINAL_COUNTER 404
                      #define VERIFICATION_COUNTER 415
                      #define PREDICTED_COUNTER 416
                    #endif
                  #endif
                #else /* Was [405-408] */
                  #if (__COUNTER__ <= (406+9)) /* Was [405-406] */
                    #if (__COUNTER__ <= (405+10)) /* Was [405-405] */
                      #define ORIGINAL_COUNTER 405
                      #define VERIFICATION_COUNTER 416
                      #define PREDICTED_COUNTER 417
                    #else /* Was [406-406] */
                      #define ORIGINAL_COUNTER 406
                      #define VERIFICATION_COUNTER 417
                      #define PREDICTED_COUNTER 418
                    #endif
                  #else /* Was [407-408] */
                    #if (__COUNTER__ <= (407+10)) /* Was [407-407] */
                      #define ORIGINAL_COUNTER 407
                      #define VERIFICATION_COUNTER 418
                      #define PREDICTED_COUNTER 419
                    #else /* Was [408-408] */
                      #define ORIGINAL_COUNTER 408
                      #define VERIFICATION_COUNTER 419
                      #define PREDICTED_COUNTER 420
                    #endif
                  #endif
                #endif
              #else /* Was [409-416] */
                #if (__COUNTER__ <= (412+8)) /* Was [409-412] */
                  #if (__COUNTER__ <= (410+9)) /* Was [409-410] */
                    #if (__COUNTER__ <= (409+10)) /* Was [409-409] */
                      #define ORIGINAL_COUNTER 409
                      #define VERIFICATION_COUNTER 420
                      #define PREDICTED_COUNTER 421
                    #else /* Was [410-410] */
                      #define ORIGINAL_COUNTER 410
                      #define VERIFICATION_COUNTER 421
                      #define PREDICTED_COUNTER 422
                    #endif
                  #else /* Was [411-412] */
                    #if (__COUNTER__ <= (411+10)) /* Was [411-411] */
                      #define ORIGINAL_COUNTER 411
                      #define VERIFICATION_COUNTER 422
                      #define PREDICTED_COUNTER 423
                    #else /* Was [412-412] */
                      #define ORIGINAL_COUNTER 412
                      #define VERIFICATION_COUNTER 423
                      #define PREDICTED_COUNTER 424
                    #endif
                  #endif
                #else /* Was [413-416] */
                  #if (__COUNTER__ <= (414+9)) /* Was [413-414] */
                    #if (__COUNTER__ <= (413+10)) /* Was [413-413] */
                      #define ORIGINAL_COUNTER 413
                      #define VERIFICATION_COUNTER 424
                      #define PREDICTED_COUNTER 425
                    #else /* Was [414-414] */
                      #define ORIGINAL_COUNTER 414
                      #define VERIFICATION_COUNTER 425
                      #define PREDICTED_COUNTER 426
                    #endif
                  #else /* Was [415-416] */
                    #if (__COUNTER__ <= (415+10)) /* Was [415-415] */
                      #define ORIGINAL_COUNTER 415
                      #define VERIFICATION_COUNTER 426
                      #define PREDICTED_COUNTER 427
                    #else /* Was [416-416] */
                      #define ORIGINAL_COUNTER 416
                      #define VERIFICATION_COUNTER 427
                      #define PREDICTED_COUNTER 428
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [417-448] */
            #if (__COUNTER__ <= (432+6)) /* Was [417-432] */
              #if (__COUNTER__ <= (424+7)) /* Was [417-424] */
                #if (__COUNTER__ <= (420+8)) /* Was [417-420] */
                  #if (__COUNTER__ <= (418+9)) /* Was [417-418] */
                    #if (__COUNTER__ <= (417+10)) /* Was [417-417] */
                      #define ORIGINAL_COUNTER 417
                      #define VERIFICATION_COUNTER 428
                      #define PREDICTED_COUNTER 429
                    #else /* Was [418-418] */
                      #define ORIGINAL_COUNTER 418
                      #define VERIFICATION_COUNTER 429
                      #define PREDICTED_COUNTER 430
                    #endif
                  #else /* Was [419-420] */
                    #if (__COUNTER__ <= (419+10)) /* Was [419-419] */
                      #define ORIGINAL_COUNTER 419
                      #define VERIFICATION_COUNTER 430
                      #define PREDICTED_COUNTER 431
                    #else /* Was [420-420] */
                      #define ORIGINAL_COUNTER 420
                      #define VERIFICATION_COUNTER 431
                      #define PREDICTED_COUNTER 432
                    #endif
                  #endif
                #else /* Was [421-424] */
                  #if (__COUNTER__ <= (422+9)) /* Was [421-422] */
                    #if (__COUNTER__ <= (421+10)) /* Was [421-421] */
                      #define ORIGINAL_COUNTER 421
                      #define VERIFICATION_COUNTER 432
                      #define PREDICTED_COUNTER 433
                    #else /* Was [422-422] */
                      #define ORIGINAL_COUNTER 422
                      #define VERIFICATION_COUNTER 433
                      #define PREDICTED_COUNTER 434
                    #endif
                  #else /* Was [423-424] */
                    #if (__COUNTER__ <= (423+10)) /* Was [423-423] */
                      #define ORIGINAL_COUNTER 423
                      #define VERIFICATION_COUNTER 434
                      #define PREDICTED_COUNTER 435
                    #else /* Was [424-424] */
                      #define ORIGINAL_COUNTER 424
                      #define VERIFICATION_COUNTER 435
                      #define PREDICTED_COUNTER 436
                    #endif
                  #endif
                #endif
              #else /* Was [425-432] */
                #if (__COUNTER__ <= (428+8)) /* Was [425-428] */
                  #if (__COUNTER__ <= (426+9)) /* Was [425-426] */
                    #if (__COUNTER__ <= (425+10)) /* Was [425-425] */
                      #define ORIGINAL_COUNTER 425
                      #define VERIFICATION_COUNTER 436
                      #define PREDICTED_COUNTER 437
                    #else /* Was [426-426] */
                      #define ORIGINAL_COUNTER 426
                      #define VERIFICATION_COUNTER 437
                      #define PREDICTED_COUNTER 438
                    #endif
                  #else /* Was [427-428] */
                    #if (__COUNTER__ <= (427+10)) /* Was [427-427] */
                      #define ORIGINAL_COUNTER 427
                      #define VERIFICATION_COUNTER 438
                      #define PREDICTED_COUNTER 439
                    #else /* Was [428-428] */
                      #define ORIGINAL_COUNTER 428
                      #define VERIFICATION_COUNTER 439
                      #define PREDICTED_COUNTER 440
                    #endif
                  #endif
                #else /* Was [429-432] */
                  #if (__COUNTER__ <= (430+9)) /* Was [429-430] */
                    #if (__COUNTER__ <= (429+10)) /* Was [429-429] */
                      #define ORIGINAL_COUNTER 429
                      #define VERIFICATION_COUNTER 440
                      #define PREDICTED_COUNTER 441
                    #else /* Was [430-430] */
                      #define ORIGINAL_COUNTER 430
                      #define VERIFICATION_COUNTER 441
                      #define PREDICTED_COUNTER 442
                    #endif
                  #else /* Was [431-432] */
                    #if (__COUNTER__ <= (431+10)) /* Was [431-431] */
                      #define ORIGINAL_COUNTER 431
                      #define VERIFICATION_COUNTER 442
                      #define PREDICTED_COUNTER 443
                    #else /* Was [432-432] */
                      #define ORIGINAL_COUNTER 432
                      #define VERIFICATION_COUNTER 443
                      #define PREDICTED_COUNTER 444
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [433-448] */
              #if (__COUNTER__ <= (440+7)) /* Was [433-440] */
                #if (__COUNTER__ <= (436+8)) /* Was [433-436] */
                  #if (__COUNTER__ <= (434+9)) /* Was [433-434] */
                    #if (__COUNTER__ <= (433+10)) /* Was [433-433] */
                      #define ORIGINAL_COUNTER 433
                      #define VERIFICATION_COUNTER 444
                      #define PREDICTED_COUNTER 445
                    #else /* Was [434-434] */
                      #define ORIGINAL_COUNTER 434
                      #define VERIFICATION_COUNTER 445
                      #define PREDICTED_COUNTER 446
                    #endif
                  #else /* Was [435-436] */
                    #if (__COUNTER__ <= (435+10)) /* Was [435-435] */
                      #define ORIGINAL_COUNTER 435
                      #define VERIFICATION_COUNTER 446
                      #define PREDICTED_COUNTER 447
                    #else /* Was [436-436] */
                      #define ORIGINAL_COUNTER 436
                      #define VERIFICATION_COUNTER 447
                      #define PREDICTED_COUNTER 448
                    #endif
                  #endif
                #else /* Was [437-440] */
                  #if (__COUNTER__ <= (438+9)) /* Was [437-438] */
                    #if (__COUNTER__ <= (437+10)) /* Was [437-437] */
                      #define ORIGINAL_COUNTER 437
                      #define VERIFICATION_COUNTER 448
                      #define PREDICTED_COUNTER 449
                    #else /* Was [438-438] */
                      #define ORIGINAL_COUNTER 438
                      #define VERIFICATION_COUNTER 449
                      #define PREDICTED_COUNTER 450
                    #endif
                  #else /* Was [439-440] */
                    #if (__COUNTER__ <= (439+10)) /* Was [439-439] */
                      #define ORIGINAL_COUNTER 439
                      #define VERIFICATION_COUNTER 450
                      #define PREDICTED_COUNTER 451
                    #else /* Was [440-440] */
                      #define ORIGINAL_COUNTER 440
                      #define VERIFICATION_COUNTER 451
                      #define PREDICTED_COUNTER 452
                    #endif
                  #endif
                #endif
              #else /* Was [441-448] */
                #if (__COUNTER__ <= (444+8)) /* Was [441-444] */
                  #if (__COUNTER__ <= (442+9)) /* Was [441-442] */
                    #if (__COUNTER__ <= (441+10)) /* Was [441-441] */
                      #define ORIGINAL_COUNTER 441
                      #define VERIFICATION_COUNTER 452
                      #define PREDICTED_COUNTER 453
                    #else /* Was [442-442] */
                      #define ORIGINAL_COUNTER 442
                      #define VERIFICATION_COUNTER 453
                      #define PREDICTED_COUNTER 454
                    #endif
                  #else /* Was [443-444] */
                    #if (__COUNTER__ <= (443+10)) /* Was [443-443] */
                      #define ORIGINAL_COUNTER 443
                      #define VERIFICATION_COUNTER 454
                      #define PREDICTED_COUNTER 455
                    #else /* Was [444-444] */
                      #define ORIGINAL_COUNTER 444
                      #define VERIFICATION_COUNTER 455
                      #define PREDICTED_COUNTER 456
                    #endif
                  #endif
                #else /* Was [445-448] */
                  #if (__COUNTER__ <= (446+9)) /* Was [445-446] */
                    #if (__COUNTER__ <= (445+10)) /* Was [445-445] */
                      #define ORIGINAL_COUNTER 445
                      #define VERIFICATION_COUNTER 456
                      #define PREDICTED_COUNTER 457
                    #else /* Was [446-446] */
                      #define ORIGINAL_COUNTER 446
                      #define VERIFICATION_COUNTER 457
                      #define PREDICTED_COUNTER 458
                    #endif
                  #else /* Was [447-448] */
                    #if (__COUNTER__ <= (447+10)) /* Was [447-447] */
                      #define ORIGINAL_COUNTER 447
                      #define VERIFICATION_COUNTER 458
                      #define PREDICTED_COUNTER 459
                    #else /* Was [448-448] */
                      #define ORIGINAL_COUNTER 448
                      #define VERIFICATION_COUNTER 459
                      #define PREDICTED_COUNTER 460
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #else /* Was [449-512] */
          #if (__COUNTER__ <= (480+5)) /* Was [449-480] */
            #if (__COUNTER__ <= (464+6)) /* Was [449-464] */
              #if (__COUNTER__ <= (456+7)) /* Was [449-456] */
                #if (__COUNTER__ <= (452+8)) /* Was [449-452] */
                  #if (__COUNTER__ <= (450+9)) /* Was [449-450] */
                    #if (__COUNTER__ <= (449+10)) /* Was [449-449] */
                      #define ORIGINAL_COUNTER 449
                      #define VERIFICATION_COUNTER 460
                      #define PREDICTED_COUNTER 461
                    #else /* Was [450-450] */
                      #define ORIGINAL_COUNTER 450
                      #define VERIFICATION_COUNTER 461
                      #define PREDICTED_COUNTER 462
                    #endif
                  #else /* Was [451-452] */
                    #if (__COUNTER__ <= (451+10)) /* Was [451-451] */
                      #define ORIGINAL_COUNTER 451
                      #define VERIFICATION_COUNTER 462
                      #define PREDICTED_COUNTER 463
                    #else /* Was [452-452] */
                      #define ORIGINAL_COUNTER 452
                      #define VERIFICATION_COUNTER 463
                      #define PREDICTED_COUNTER 464
                    #endif
                  #endif
                #else /* Was [453-456] */
                  #if (__COUNTER__ <= (454+9)) /* Was [453-454] */
                    #if (__COUNTER__ <= (453+10)) /* Was [453-453] */
                      #define ORIGINAL_COUNTER 453
                      #define VERIFICATION_COUNTER 464
                      #define PREDICTED_COUNTER 465
                    #else /* Was [454-454] */
                      #define ORIGINAL_COUNTER 454
                      #define VERIFICATION_COUNTER 465
                      #define PREDICTED_COUNTER 466
                    #endif
                  #else /* Was [455-456] */
                    #if (__COUNTER__ <= (455+10)) /* Was [455-455] */
                      #define ORIGINAL_COUNTER 455
                      #define VERIFICATION_COUNTER 466
                      #define PREDICTED_COUNTER 467
                    #else /* Was [456-456] */
                      #define ORIGINAL_COUNTER 456
                      #define VERIFICATION_COUNTER 467
                      #define PREDICTED_COUNTER 468
                    #endif
                  #endif
                #endif
              #else /* Was [457-464] */
                #if (__COUNTER__ <= (460+8)) /* Was [457-460] */
                  #if (__COUNTER__ <= (458+9)) /* Was [457-458] */
                    #if (__COUNTER__ <= (457+10)) /* Was [457-457] */
                      #define ORIGINAL_COUNTER 457
                      #define VERIFICATION_COUNTER 468
                      #define PREDICTED_COUNTER 469
                    #else /* Was [458-458] */
                      #define ORIGINAL_COUNTER 458
                      #define VERIFICATION_COUNTER 469
                      #define PREDICTED_COUNTER 470
                    #endif
                  #else /* Was [459-460] */
                    #if (__COUNTER__ <= (459+10)) /* Was [459-459] */
                      #define ORIGINAL_COUNTER 459
                      #define VERIFICATION_COUNTER 470
                      #define PREDICTED_COUNTER 471
                    #else /* Was [460-460] */
                      #define ORIGINAL_COUNTER 460
                      #define VERIFICATION_COUNTER 471
                      #define PREDICTED_COUNTER 472
                    #endif
                  #endif
                #else /* Was [461-464] */
                  #if (__COUNTER__ <= (462+9)) /* Was [461-462] */
                    #if (__COUNTER__ <= (461+10)) /* Was [461-461] */
                      #define ORIGINAL_COUNTER 461
                      #define VERIFICATION_COUNTER 472
                      #define PREDICTED_COUNTER 473
                    #else /* Was [462-462] */
                      #define ORIGINAL_COUNTER 462
                      #define VERIFICATION_COUNTER 473
                      #define PREDICTED_COUNTER 474
                    #endif
                  #else /* Was [463-464] */
                    #if (__COUNTER__ <= (463+10)) /* Was [463-463] */
                      #define ORIGINAL_COUNTER 463
                      #define VERIFICATION_COUNTER 474
                      #define PREDICTED_COUNTER 475
                    #else /* Was [464-464] */
                      #define ORIGINAL_COUNTER 464
                      #define VERIFICATION_COUNTER 475
                      #define PREDICTED_COUNTER 476
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [465-480] */
              #if (__COUNTER__ <= (472+7)) /* Was [465-472] */
                #if (__COUNTER__ <= (468+8)) /* Was [465-468] */
                  #if (__COUNTER__ <= (466+9)) /* Was [465-466] */
                    #if (__COUNTER__ <= (465+10)) /* Was [465-465] */
                      #define ORIGINAL_COUNTER 465
                      #define VERIFICATION_COUNTER 476
                      #define PREDICTED_COUNTER 477
                    #else /* Was [466-466] */
                      #define ORIGINAL_COUNTER 466
                      #define VERIFICATION_COUNTER 477
                      #define PREDICTED_COUNTER 478
                    #endif
                  #else /* Was [467-468] */
                    #if (__COUNTER__ <= (467+10)) /* Was [467-467] */
                      #define ORIGINAL_COUNTER 467
                      #define VERIFICATION_COUNTER 478
                      #define PREDICTED_COUNTER 479
                    #else /* Was [468-468] */
                      #define ORIGINAL_COUNTER 468
                      #define VERIFICATION_COUNTER 479
                      #define PREDICTED_COUNTER 480
                    #endif
                  #endif
                #else /* Was [469-472] */
                  #if (__COUNTER__ <= (470+9)) /* Was [469-470] */
                    #if (__COUNTER__ <= (469+10)) /* Was [469-469] */
                      #define ORIGINAL_COUNTER 469
                      #define VERIFICATION_COUNTER 480
                      #define PREDICTED_COUNTER 481
                    #else /* Was [470-470] */
                      #define ORIGINAL_COUNTER 470
                      #define VERIFICATION_COUNTER 481
                      #define PREDICTED_COUNTER 482
                    #endif
                  #else /* Was [471-472] */
                    #if (__COUNTER__ <= (471+10)) /* Was [471-471] */
                      #define ORIGINAL_COUNTER 471
                      #define VERIFICATION_COUNTER 482
                      #define PREDICTED_COUNTER 483
                    #else /* Was [472-472] */
                      #define ORIGINAL_COUNTER 472
                      #define VERIFICATION_COUNTER 483
                      #define PREDICTED_COUNTER 484
                    #endif
                  #endif
                #endif
              #else /* Was [473-480] */
                #if (__COUNTER__ <= (476+8)) /* Was [473-476] */
                  #if (__COUNTER__ <= (474+9)) /* Was [473-474] */
                    #if (__COUNTER__ <= (473+10)) /* Was [473-473] */
                      #define ORIGINAL_COUNTER 473
                      #define VERIFICATION_COUNTER 484
                      #define PREDICTED_COUNTER 485
                    #else /* Was [474-474] */
                      #define ORIGINAL_COUNTER 474
                      #define VERIFICATION_COUNTER 485
                      #define PREDICTED_COUNTER 486
                    #endif
                  #else /* Was [475-476] */
                    #if (__COUNTER__ <= (475+10)) /* Was [475-475] */
                      #define ORIGINAL_COUNTER 475
                      #define VERIFICATION_COUNTER 486
                      #define PREDICTED_COUNTER 487
                    #else /* Was [476-476] */
                      #define ORIGINAL_COUNTER 476
                      #define VERIFICATION_COUNTER 487
                      #define PREDICTED_COUNTER 488
                    #endif
                  #endif
                #else /* Was [477-480] */
                  #if (__COUNTER__ <= (478+9)) /* Was [477-478] */
                    #if (__COUNTER__ <= (477+10)) /* Was [477-477] */
                      #define ORIGINAL_COUNTER 477
                      #define VERIFICATION_COUNTER 488
                      #define PREDICTED_COUNTER 489
                    #else /* Was [478-478] */
                      #define ORIGINAL_COUNTER 478
                      #define VERIFICATION_COUNTER 489
                      #define PREDICTED_COUNTER 490
                    #endif
                  #else /* Was [479-480] */
                    #if (__COUNTER__ <= (479+10)) /* Was [479-479] */
                      #define ORIGINAL_COUNTER 479
                      #define VERIFICATION_COUNTER 490
                      #define PREDICTED_COUNTER 491
                    #else /* Was [480-480] */
                      #define ORIGINAL_COUNTER 480
                      #define VERIFICATION_COUNTER 491
                      #define PREDICTED_COUNTER 492
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [481-512] */
            #if (__COUNTER__ <= (496+6)) /* Was [481-496] */
              #if (__COUNTER__ <= (488+7)) /* Was [481-488] */
                #if (__COUNTER__ <= (484+8)) /* Was [481-484] */
                  #if (__COUNTER__ <= (482+9)) /* Was [481-482] */
                    #if (__COUNTER__ <= (481+10)) /* Was [481-481] */
                      #define ORIGINAL_COUNTER 481
                      #define VERIFICATION_COUNTER 492
                      #define PREDICTED_COUNTER 493
                    #else /* Was [482-482] */
                      #define ORIGINAL_COUNTER 482
                      #define VERIFICATION_COUNTER 493
                      #define PREDICTED_COUNTER 494
                    #endif
                  #else /* Was [483-484] */
                    #if (__COUNTER__ <= (483+10)) /* Was [483-483] */
                      #define ORIGINAL_COUNTER 483
                      #define VERIFICATION_COUNTER 494
                      #define PREDICTED_COUNTER 495
                    #else /* Was [484-484] */
                      #define ORIGINAL_COUNTER 484
                      #define VERIFICATION_COUNTER 495
                      #define PREDICTED_COUNTER 496
                    #endif
                  #endif
                #else /* Was [485-488] */
                  #if (__COUNTER__ <= (486+9)) /* Was [485-486] */
                    #if (__COUNTER__ <= (485+10)) /* Was [485-485] */
                      #define ORIGINAL_COUNTER 485
                      #define VERIFICATION_COUNTER 496
                      #define PREDICTED_COUNTER 497
                    #else /* Was [486-486] */
                      #define ORIGINAL_COUNTER 486
                      #define VERIFICATION_COUNTER 497
                      #define PREDICTED_COUNTER 498
                    #endif
                  #else /* Was [487-488] */
                    #if (__COUNTER__ <= (487+10)) /* Was [487-487] */
                      #define ORIGINAL_COUNTER 487
                      #define VERIFICATION_COUNTER 498
                      #define PREDICTED_COUNTER 499
                    #else /* Was [488-488] */
                      #define ORIGINAL_COUNTER 488
                      #define VERIFICATION_COUNTER 499
                      #define PREDICTED_COUNTER 500
                    #endif
                  #endif
                #endif
              #else /* Was [489-496] */
                #if (__COUNTER__ <= (492+8)) /* Was [489-492] */
                  #if (__COUNTER__ <= (490+9)) /* Was [489-490] */
                    #if (__COUNTER__ <= (489+10)) /* Was [489-489] */
                      #define ORIGINAL_COUNTER 489
                      #define VERIFICATION_COUNTER 500
                      #define PREDICTED_COUNTER 501
                    #else /* Was [490-490] */
                      #define ORIGINAL_COUNTER 490
                      #define VERIFICATION_COUNTER 501
                      #define PREDICTED_COUNTER 502
                    #endif
                  #else /* Was [491-492] */
                    #if (__COUNTER__ <= (491+10)) /* Was [491-491] */
                      #define ORIGINAL_COUNTER 491
                      #define VERIFICATION_COUNTER 502
                      #define PREDICTED_COUNTER 503
                    #else /* Was [492-492] */
                      #define ORIGINAL_COUNTER 492
                      #define VERIFICATION_COUNTER 503
                      #define PREDICTED_COUNTER 504
                    #endif
                  #endif
                #else /* Was [493-496] */
                  #if (__COUNTER__ <= (494+9)) /* Was [493-494] */
                    #if (__COUNTER__ <= (493+10)) /* Was [493-493] */
                      #define ORIGINAL_COUNTER 493
                      #define VERIFICATION_COUNTER 504
                      #define PREDICTED_COUNTER 505
                    #else /* Was [494-494] */
                      #define ORIGINAL_COUNTER 494
                      #define VERIFICATION_COUNTER 505
                      #define PREDICTED_COUNTER 506
                    #endif
                  #else /* Was [495-496] */
                    #if (__COUNTER__ <= (495+10)) /* Was [495-495] */
                      #define ORIGINAL_COUNTER 495
                      #define VERIFICATION_COUNTER 506
                      #define PREDICTED_COUNTER 507
                    #else /* Was [496-496] */
                      #define ORIGINAL_COUNTER 496
                      #define VERIFICATION_COUNTER 507
                      #define PREDICTED_COUNTER 508
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [497-512] */
              #if (__COUNTER__ <= (504+7)) /* Was [497-504] */
                #if (__COUNTER__ <= (500+8)) /* Was [497-500] */
                  #if (__COUNTER__ <= (498+9)) /* Was [497-498] */
                    #if (__COUNTER__ <= (497+10)) /* Was [497-497] */
                      #define ORIGINAL_COUNTER 497
                      #define VERIFICATION_COUNTER 508
                      #define PREDICTED_COUNTER 509
                    #else /* Was [498-498] */
                      #define ORIGINAL_COUNTER 498
                      #define VERIFICATION_COUNTER 509
                      #define PREDICTED_COUNTER 510
                    #endif
                  #else /* Was [499-500] */
                    #if (__COUNTER__ <= (499+10)) /* Was [499-499] */
                      #define ORIGINAL_COUNTER 499
                      #define VERIFICATION_COUNTER 510
                      #define PREDICTED_COUNTER 511
                    #else /* Was [500-500] */
                      #define ORIGINAL_COUNTER 500
                      #define VERIFICATION_COUNTER 511
                      #define PREDICTED_COUNTER 512
                    #endif
                  #endif
                #else /* Was [501-504] */
                  #if (__COUNTER__ <= (502+9)) /* Was [501-502] */
                    #if (__COUNTER__ <= (501+10)) /* Was [501-501] */
                      #define ORIGINAL_COUNTER 501
                      #define VERIFICATION_COUNTER 512
                      #define PREDICTED_COUNTER 513
                    #else /* Was [502-502] */
                      #define ORIGINAL_COUNTER 502
                      #define VERIFICATION_COUNTER 513
                      #define PREDICTED_COUNTER 514
                    #endif
                  #else /* Was [503-504] */
                    #if (__COUNTER__ <= (503+10)) /* Was [503-503] */
                      #define ORIGINAL_COUNTER 503
                      #define VERIFICATION_COUNTER 514
                      #define PREDICTED_COUNTER 515
                    #else /* Was [504-504] */
                      #define ORIGINAL_COUNTER 504
                      #define VERIFICATION_COUNTER 515
                      #define PREDICTED_COUNTER 516
                    #endif
                  #endif
                #endif
              #else /* Was [505-512] */
                #if (__COUNTER__ <= (508+8)) /* Was [505-508] */
                  #if (__COUNTER__ <= (506+9)) /* Was [505-506] */
                    #if (__COUNTER__ <= (505+10)) /* Was [505-505] */
                      #define ORIGINAL_COUNTER 505
                      #define VERIFICATION_COUNTER 516
                      #define PREDICTED_COUNTER 517
                    #else /* Was [506-506] */
                      #define ORIGINAL_COUNTER 506
                      #define VERIFICATION_COUNTER 517
                      #define PREDICTED_COUNTER 518
                    #endif
                  #else /* Was [507-508] */
                    #if (__COUNTER__ <= (507+10)) /* Was [507-507] */
                      #define ORIGINAL_COUNTER 507
                      #define VERIFICATION_COUNTER 518
                      #define PREDICTED_COUNTER 519
                    #else /* Was [508-508] */
                      #define ORIGINAL_COUNTER 508
                      #define VERIFICATION_COUNTER 519
                      #define PREDICTED_COUNTER 520
                    #endif
                  #endif
                #else /* Was [509-512] */
                  #if (__COUNTER__ <= (510+9)) /* Was [509-510] */
                    #if (__COUNTER__ <= (509+10)) /* Was [509-509] */
                      #define ORIGINAL_COUNTER 509
                      #define VERIFICATION_COUNTER 520
                      #define PREDICTED_COUNTER 521
                    #else /* Was [510-510] */
                      #define ORIGINAL_COUNTER 510
                      #define VERIFICATION_COUNTER 521
                      #define PREDICTED_COUNTER 522
                    #endif
                  #else /* Was [511-512] */
                    #if (__COUNTER__ <= (511+10)) /* Was [511-511] */
                      #define ORIGINAL_COUNTER 511
                      #define VERIFICATION_COUNTER 522
                      #define PREDICTED_COUNTER 523
                    #else /* Was [512-512] */
                      #define ORIGINAL_COUNTER 512
                      #define VERIFICATION_COUNTER 523
                      #define PREDICTED_COUNTER 524
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #endif
      #endif
    #endif
  #else /* Was [513-1024] */
    #if (__COUNTER__ <= (768+2)) /* Was [513-768] */
      #if (__COUNTER__ <= (640+3)) /* Was [513-640] */
        #if (__COUNTER__ <= (576+4)) /* Was [513-576] */
          #if (__COUNTER__ <= (544+5)) /* Was [513-544] */
            #if (__COUNTER__ <= (528+6)) /* Was [513-528] */
              #if (__COUNTER__ <= (520+7)) /* Was [513-520] */
                #if (__COUNTER__ <= (516+8)) /* Was [513-516] */
                  #if (__COUNTER__ <= (514+9)) /* Was [513-514] */
                    #if (__COUNTER__ <= (513+10)) /* Was [513-513] */
                      #define ORIGINAL_COUNTER 513
                      #define VERIFICATION_COUNTER 524
                      #define PREDICTED_COUNTER 525
                    #else /* Was [514-514] */
                      #define ORIGINAL_COUNTER 514
                      #define VERIFICATION_COUNTER 525
                      #define PREDICTED_COUNTER 526
                    #endif
                  #else /* Was [515-516] */
                    #if (__COUNTER__ <= (515+10)) /* Was [515-515] */
                      #define ORIGINAL_COUNTER 515
                      #define VERIFICATION_COUNTER 526
                      #define PREDICTED_COUNTER 527
                    #else /* Was [516-516] */
                      #define ORIGINAL_COUNTER 516
                      #define VERIFICATION_COUNTER 527
                      #define PREDICTED_COUNTER 528
                    #endif
                  #endif
                #else /* Was [517-520] */
                  #if (__COUNTER__ <= (518+9)) /* Was [517-518] */
                    #if (__COUNTER__ <= (517+10)) /* Was [517-517] */
                      #define ORIGINAL_COUNTER 517
                      #define VERIFICATION_COUNTER 528
                      #define PREDICTED_COUNTER 529
                    #else /* Was [518-518] */
                      #define ORIGINAL_COUNTER 518
                      #define VERIFICATION_COUNTER 529
                      #define PREDICTED_COUNTER 530
                    #endif
                  #else /* Was [519-520] */
                    #if (__COUNTER__ <= (519+10)) /* Was [519-519] */
                      #define ORIGINAL_COUNTER 519
                      #define VERIFICATION_COUNTER 530
                      #define PREDICTED_COUNTER 531
                    #else /* Was [520-520] */
                      #define ORIGINAL_COUNTER 520
                      #define VERIFICATION_COUNTER 531
                      #define PREDICTED_COUNTER 532
                    #endif
                  #endif
                #endif
              #else /* Was [521-528] */
                #if (__COUNTER__ <= (524+8)) /* Was [521-524] */
                  #if (__COUNTER__ <= (522+9)) /* Was [521-522] */
                    #if (__COUNTER__ <= (521+10)) /* Was [521-521] */
                      #define ORIGINAL_COUNTER 521
                      #define VERIFICATION_COUNTER 532
                      #define PREDICTED_COUNTER 533
                    #else /* Was [522-522] */
                      #define ORIGINAL_COUNTER 522
                      #define VERIFICATION_COUNTER 533
                      #define PREDICTED_COUNTER 534
                    #endif
                  #else /* Was [523-524] */
                    #if (__COUNTER__ <= (523+10)) /* Was [523-523] */
                      #define ORIGINAL_COUNTER 523
                      #define VERIFICATION_COUNTER 534
                      #define PREDICTED_COUNTER 535
                    #else /* Was [524-524] */
                      #define ORIGINAL_COUNTER 524
                      #define VERIFICATION_COUNTER 535
                      #define PREDICTED_COUNTER 536
                    #endif
                  #endif
                #else /* Was [525-528] */
                  #if (__COUNTER__ <= (526+9)) /* Was [525-526] */
                    #if (__COUNTER__ <= (525+10)) /* Was [525-525] */
                      #define ORIGINAL_COUNTER 525
                      #define VERIFICATION_COUNTER 536
                      #define PREDICTED_COUNTER 537
                    #else /* Was [526-526] */
                      #define ORIGINAL_COUNTER 526
                      #define VERIFICATION_COUNTER 537
                      #define PREDICTED_COUNTER 538
                    #endif
                  #else /* Was [527-528] */
                    #if (__COUNTER__ <= (527+10)) /* Was [527-527] */
                      #define ORIGINAL_COUNTER 527
                      #define VERIFICATION_COUNTER 538
                      #define PREDICTED_COUNTER 539
                    #else /* Was [528-528] */
                      #define ORIGINAL_COUNTER 528
                      #define VERIFICATION_COUNTER 539
                      #define PREDICTED_COUNTER 540
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [529-544] */
              #if (__COUNTER__ <= (536+7)) /* Was [529-536] */
                #if (__COUNTER__ <= (532+8)) /* Was [529-532] */
                  #if (__COUNTER__ <= (530+9)) /* Was [529-530] */
                    #if (__COUNTER__ <= (529+10)) /* Was [529-529] */
                      #define ORIGINAL_COUNTER 529
                      #define VERIFICATION_COUNTER 540
                      #define PREDICTED_COUNTER 541
                    #else /* Was [530-530] */
                      #define ORIGINAL_COUNTER 530
                      #define VERIFICATION_COUNTER 541
                      #define PREDICTED_COUNTER 542
                    #endif
                  #else /* Was [531-532] */
                    #if (__COUNTER__ <= (531+10)) /* Was [531-531] */
                      #define ORIGINAL_COUNTER 531
                      #define VERIFICATION_COUNTER 542
                      #define PREDICTED_COUNTER 543
                    #else /* Was [532-532] */
                      #define ORIGINAL_COUNTER 532
                      #define VERIFICATION_COUNTER 543
                      #define PREDICTED_COUNTER 544
                    #endif
                  #endif
                #else /* Was [533-536] */
                  #if (__COUNTER__ <= (534+9)) /* Was [533-534] */
                    #if (__COUNTER__ <= (533+10)) /* Was [533-533] */
                      #define ORIGINAL_COUNTER 533
                      #define VERIFICATION_COUNTER 544
                      #define PREDICTED_COUNTER 545
                    #else /* Was [534-534] */
                      #define ORIGINAL_COUNTER 534
                      #define VERIFICATION_COUNTER 545
                      #define PREDICTED_COUNTER 546
                    #endif
                  #else /* Was [535-536] */
                    #if (__COUNTER__ <= (535+10)) /* Was [535-535] */
                      #define ORIGINAL_COUNTER 535
                      #define VERIFICATION_COUNTER 546
                      #define PREDICTED_COUNTER 547
                    #else /* Was [536-536] */
                      #define ORIGINAL_COUNTER 536
                      #define VERIFICATION_COUNTER 547
                      #define PREDICTED_COUNTER 548
                    #endif
                  #endif
                #endif
              #else /* Was [537-544] */
                #if (__COUNTER__ <= (540+8)) /* Was [537-540] */
                  #if (__COUNTER__ <= (538+9)) /* Was [537-538] */
                    #if (__COUNTER__ <= (537+10)) /* Was [537-537] */
                      #define ORIGINAL_COUNTER 537
                      #define VERIFICATION_COUNTER 548
                      #define PREDICTED_COUNTER 549
                    #else /* Was [538-538] */
                      #define ORIGINAL_COUNTER 538
                      #define VERIFICATION_COUNTER 549
                      #define PREDICTED_COUNTER 550
                    #endif
                  #else /* Was [539-540] */
                    #if (__COUNTER__ <= (539+10)) /* Was [539-539] */
                      #define ORIGINAL_COUNTER 539
                      #define VERIFICATION_COUNTER 550
                      #define PREDICTED_COUNTER 551
                    #else /* Was [540-540] */
                      #define ORIGINAL_COUNTER 540
                      #define VERIFICATION_COUNTER 551
                      #define PREDICTED_COUNTER 552
                    #endif
                  #endif
                #else /* Was [541-544] */
                  #if (__COUNTER__ <= (542+9)) /* Was [541-542] */
                    #if (__COUNTER__ <= (541+10)) /* Was [541-541] */
                      #define ORIGINAL_COUNTER 541
                      #define VERIFICATION_COUNTER 552
                      #define PREDICTED_COUNTER 553
                    #else /* Was [542-542] */
                      #define ORIGINAL_COUNTER 542
                      #define VERIFICATION_COUNTER 553
                      #define PREDICTED_COUNTER 554
                    #endif
                  #else /* Was [543-544] */
                    #if (__COUNTER__ <= (543+10)) /* Was [543-543] */
                      #define ORIGINAL_COUNTER 543
                      #define VERIFICATION_COUNTER 554
                      #define PREDICTED_COUNTER 555
                    #else /* Was [544-544] */
                      #define ORIGINAL_COUNTER 544
                      #define VERIFICATION_COUNTER 555
                      #define PREDICTED_COUNTER 556
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [545-576] */
            #if (__COUNTER__ <= (560+6)) /* Was [545-560] */
              #if (__COUNTER__ <= (552+7)) /* Was [545-552] */
                #if (__COUNTER__ <= (548+8)) /* Was [545-548] */
                  #if (__COUNTER__ <= (546+9)) /* Was [545-546] */
                    #if (__COUNTER__ <= (545+10)) /* Was [545-545] */
                      #define ORIGINAL_COUNTER 545
                      #define VERIFICATION_COUNTER 556
                      #define PREDICTED_COUNTER 557
                    #else /* Was [546-546] */
                      #define ORIGINAL_COUNTER 546
                      #define VERIFICATION_COUNTER 557
                      #define PREDICTED_COUNTER 558
                    #endif
                  #else /* Was [547-548] */
                    #if (__COUNTER__ <= (547+10)) /* Was [547-547] */
                      #define ORIGINAL_COUNTER 547
                      #define VERIFICATION_COUNTER 558
                      #define PREDICTED_COUNTER 559
                    #else /* Was [548-548] */
                      #define ORIGINAL_COUNTER 548
                      #define VERIFICATION_COUNTER 559
                      #define PREDICTED_COUNTER 560
                    #endif
                  #endif
                #else /* Was [549-552] */
                  #if (__COUNTER__ <= (550+9)) /* Was [549-550] */
                    #if (__COUNTER__ <= (549+10)) /* Was [549-549] */
                      #define ORIGINAL_COUNTER 549
                      #define VERIFICATION_COUNTER 560
                      #define PREDICTED_COUNTER 561
                    #else /* Was [550-550] */
                      #define ORIGINAL_COUNTER 550
                      #define VERIFICATION_COUNTER 561
                      #define PREDICTED_COUNTER 562
                    #endif
                  #else /* Was [551-552] */
                    #if (__COUNTER__ <= (551+10)) /* Was [551-551] */
                      #define ORIGINAL_COUNTER 551
                      #define VERIFICATION_COUNTER 562
                      #define PREDICTED_COUNTER 563
                    #else /* Was [552-552] */
                      #define ORIGINAL_COUNTER 552
                      #define VERIFICATION_COUNTER 563
                      #define PREDICTED_COUNTER 564
                    #endif
                  #endif
                #endif
              #else /* Was [553-560] */
                #if (__COUNTER__ <= (556+8)) /* Was [553-556] */
                  #if (__COUNTER__ <= (554+9)) /* Was [553-554] */
                    #if (__COUNTER__ <= (553+10)) /* Was [553-553] */
                      #define ORIGINAL_COUNTER 553
                      #define VERIFICATION_COUNTER 564
                      #define PREDICTED_COUNTER 565
                    #else /* Was [554-554] */
                      #define ORIGINAL_COUNTER 554
                      #define VERIFICATION_COUNTER 565
                      #define PREDICTED_COUNTER 566
                    #endif
                  #else /* Was [555-556] */
                    #if (__COUNTER__ <= (555+10)) /* Was [555-555] */
                      #define ORIGINAL_COUNTER 555
                      #define VERIFICATION_COUNTER 566
                      #define PREDICTED_COUNTER 567
                    #else /* Was [556-556] */
                      #define ORIGINAL_COUNTER 556
                      #define VERIFICATION_COUNTER 567
                      #define PREDICTED_COUNTER 568
                    #endif
                  #endif
                #else /* Was [557-560] */
                  #if (__COUNTER__ <= (558+9)) /* Was [557-558] */
                    #if (__COUNTER__ <= (557+10)) /* Was [557-557] */
                      #define ORIGINAL_COUNTER 557
                      #define VERIFICATION_COUNTER 568
                      #define PREDICTED_COUNTER 569
                    #else /* Was [558-558] */
                      #define ORIGINAL_COUNTER 558
                      #define VERIFICATION_COUNTER 569
                      #define PREDICTED_COUNTER 570
                    #endif
                  #else /* Was [559-560] */
                    #if (__COUNTER__ <= (559+10)) /* Was [559-559] */
                      #define ORIGINAL_COUNTER 559
                      #define VERIFICATION_COUNTER 570
                      #define PREDICTED_COUNTER 571
                    #else /* Was [560-560] */
                      #define ORIGINAL_COUNTER 560
                      #define VERIFICATION_COUNTER 571
                      #define PREDICTED_COUNTER 572
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [561-576] */
              #if (__COUNTER__ <= (568+7)) /* Was [561-568] */
                #if (__COUNTER__ <= (564+8)) /* Was [561-564] */
                  #if (__COUNTER__ <= (562+9)) /* Was [561-562] */
                    #if (__COUNTER__ <= (561+10)) /* Was [561-561] */
                      #define ORIGINAL_COUNTER 561
                      #define VERIFICATION_COUNTER 572
                      #define PREDICTED_COUNTER 573
                    #else /* Was [562-562] */
                      #define ORIGINAL_COUNTER 562
                      #define VERIFICATION_COUNTER 573
                      #define PREDICTED_COUNTER 574
                    #endif
                  #else /* Was [563-564] */
                    #if (__COUNTER__ <= (563+10)) /* Was [563-563] */
                      #define ORIGINAL_COUNTER 563
                      #define VERIFICATION_COUNTER 574
                      #define PREDICTED_COUNTER 575
                    #else /* Was [564-564] */
                      #define ORIGINAL_COUNTER 564
                      #define VERIFICATION_COUNTER 575
                      #define PREDICTED_COUNTER 576
                    #endif
                  #endif
                #else /* Was [565-568] */
                  #if (__COUNTER__ <= (566+9)) /* Was [565-566] */
                    #if (__COUNTER__ <= (565+10)) /* Was [565-565] */
                      #define ORIGINAL_COUNTER 565
                      #define VERIFICATION_COUNTER 576
                      #define PREDICTED_COUNTER 577
                    #else /* Was [566-566] */
                      #define ORIGINAL_COUNTER 566
                      #define VERIFICATION_COUNTER 577
                      #define PREDICTED_COUNTER 578
                    #endif
                  #else /* Was [567-568] */
                    #if (__COUNTER__ <= (567+10)) /* Was [567-567] */
                      #define ORIGINAL_COUNTER 567
                      #define VERIFICATION_COUNTER 578
                      #define PREDICTED_COUNTER 579
                    #else /* Was [568-568] */
                      #define ORIGINAL_COUNTER 568
                      #define VERIFICATION_COUNTER 579
                      #define PREDICTED_COUNTER 580
                    #endif
                  #endif
                #endif
              #else /* Was [569-576] */
                #if (__COUNTER__ <= (572+8)) /* Was [569-572] */
                  #if (__COUNTER__ <= (570+9)) /* Was [569-570] */
                    #if (__COUNTER__ <= (569+10)) /* Was [569-569] */
                      #define ORIGINAL_COUNTER 569
                      #define VERIFICATION_COUNTER 580
                      #define PREDICTED_COUNTER 581
                    #else /* Was [570-570] */
                      #define ORIGINAL_COUNTER 570
                      #define VERIFICATION_COUNTER 581
                      #define PREDICTED_COUNTER 582
                    #endif
                  #else /* Was [571-572] */
                    #if (__COUNTER__ <= (571+10)) /* Was [571-571] */
                      #define ORIGINAL_COUNTER 571
                      #define VERIFICATION_COUNTER 582
                      #define PREDICTED_COUNTER 583
                    #else /* Was [572-572] */
                      #define ORIGINAL_COUNTER 572
                      #define VERIFICATION_COUNTER 583
                      #define PREDICTED_COUNTER 584
                    #endif
                  #endif
                #else /* Was [573-576] */
                  #if (__COUNTER__ <= (574+9)) /* Was [573-574] */
                    #if (__COUNTER__ <= (573+10)) /* Was [573-573] */
                      #define ORIGINAL_COUNTER 573
                      #define VERIFICATION_COUNTER 584
                      #define PREDICTED_COUNTER 585
                    #else /* Was [574-574] */
                      #define ORIGINAL_COUNTER 574
                      #define VERIFICATION_COUNTER 585
                      #define PREDICTED_COUNTER 586
                    #endif
                  #else /* Was [575-576] */
                    #if (__COUNTER__ <= (575+10)) /* Was [575-575] */
                      #define ORIGINAL_COUNTER 575
                      #define VERIFICATION_COUNTER 586
                      #define PREDICTED_COUNTER 587
                    #else /* Was [576-576] */
                      #define ORIGINAL_COUNTER 576
                      #define VERIFICATION_COUNTER 587
                      #define PREDICTED_COUNTER 588
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #else /* Was [577-640] */
          #if (__COUNTER__ <= (608+5)) /* Was [577-608] */
            #if (__COUNTER__ <= (592+6)) /* Was [577-592] */
              #if (__COUNTER__ <= (584+7)) /* Was [577-584] */
                #if (__COUNTER__ <= (580+8)) /* Was [577-580] */
                  #if (__COUNTER__ <= (578+9)) /* Was [577-578] */
                    #if (__COUNTER__ <= (577+10)) /* Was [577-577] */
                      #define ORIGINAL_COUNTER 577
                      #define VERIFICATION_COUNTER 588
                      #define PREDICTED_COUNTER 589
                    #else /* Was [578-578] */
                      #define ORIGINAL_COUNTER 578
                      #define VERIFICATION_COUNTER 589
                      #define PREDICTED_COUNTER 590
                    #endif
                  #else /* Was [579-580] */
                    #if (__COUNTER__ <= (579+10)) /* Was [579-579] */
                      #define ORIGINAL_COUNTER 579
                      #define VERIFICATION_COUNTER 590
                      #define PREDICTED_COUNTER 591
                    #else /* Was [580-580] */
                      #define ORIGINAL_COUNTER 580
                      #define VERIFICATION_COUNTER 591
                      #define PREDICTED_COUNTER 592
                    #endif
                  #endif
                #else /* Was [581-584] */
                  #if (__COUNTER__ <= (582+9)) /* Was [581-582] */
                    #if (__COUNTER__ <= (581+10)) /* Was [581-581] */
                      #define ORIGINAL_COUNTER 581
                      #define VERIFICATION_COUNTER 592
                      #define PREDICTED_COUNTER 593
                    #else /* Was [582-582] */
                      #define ORIGINAL_COUNTER 582
                      #define VERIFICATION_COUNTER 593
                      #define PREDICTED_COUNTER 594
                    #endif
                  #else /* Was [583-584] */
                    #if (__COUNTER__ <= (583+10)) /* Was [583-583] */
                      #define ORIGINAL_COUNTER 583
                      #define VERIFICATION_COUNTER 594
                      #define PREDICTED_COUNTER 595
                    #else /* Was [584-584] */
                      #define ORIGINAL_COUNTER 584
                      #define VERIFICATION_COUNTER 595
                      #define PREDICTED_COUNTER 596
                    #endif
                  #endif
                #endif
              #else /* Was [585-592] */
                #if (__COUNTER__ <= (588+8)) /* Was [585-588] */
                  #if (__COUNTER__ <= (586+9)) /* Was [585-586] */
                    #if (__COUNTER__ <= (585+10)) /* Was [585-585] */
                      #define ORIGINAL_COUNTER 585
                      #define VERIFICATION_COUNTER 596
                      #define PREDICTED_COUNTER 597
                    #else /* Was [586-586] */
                      #define ORIGINAL_COUNTER 586
                      #define VERIFICATION_COUNTER 597
                      #define PREDICTED_COUNTER 598
                    #endif
                  #else /* Was [587-588] */
                    #if (__COUNTER__ <= (587+10)) /* Was [587-587] */
                      #define ORIGINAL_COUNTER 587
                      #define VERIFICATION_COUNTER 598
                      #define PREDICTED_COUNTER 599
                    #else /* Was [588-588] */
                      #define ORIGINAL_COUNTER 588
                      #define VERIFICATION_COUNTER 599
                      #define PREDICTED_COUNTER 600
                    #endif
                  #endif
                #else /* Was [589-592] */
                  #if (__COUNTER__ <= (590+9)) /* Was [589-590] */
                    #if (__COUNTER__ <= (589+10)) /* Was [589-589] */
                      #define ORIGINAL_COUNTER 589
                      #define VERIFICATION_COUNTER 600
                      #define PREDICTED_COUNTER 601
                    #else /* Was [590-590] */
                      #define ORIGINAL_COUNTER 590
                      #define VERIFICATION_COUNTER 601
                      #define PREDICTED_COUNTER 602
                    #endif
                  #else /* Was [591-592] */
                    #if (__COUNTER__ <= (591+10)) /* Was [591-591] */
                      #define ORIGINAL_COUNTER 591
                      #define VERIFICATION_COUNTER 602
                      #define PREDICTED_COUNTER 603
                    #else /* Was [592-592] */
                      #define ORIGINAL_COUNTER 592
                      #define VERIFICATION_COUNTER 603
                      #define PREDICTED_COUNTER 604
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [593-608] */
              #if (__COUNTER__ <= (600+7)) /* Was [593-600] */
                #if (__COUNTER__ <= (596+8)) /* Was [593-596] */
                  #if (__COUNTER__ <= (594+9)) /* Was [593-594] */
                    #if (__COUNTER__ <= (593+10)) /* Was [593-593] */
                      #define ORIGINAL_COUNTER 593
                      #define VERIFICATION_COUNTER 604
                      #define PREDICTED_COUNTER 605
                    #else /* Was [594-594] */
                      #define ORIGINAL_COUNTER 594
                      #define VERIFICATION_COUNTER 605
                      #define PREDICTED_COUNTER 606
                    #endif
                  #else /* Was [595-596] */
                    #if (__COUNTER__ <= (595+10)) /* Was [595-595] */
                      #define ORIGINAL_COUNTER 595
                      #define VERIFICATION_COUNTER 606
                      #define PREDICTED_COUNTER 607
                    #else /* Was [596-596] */
                      #define ORIGINAL_COUNTER 596
                      #define VERIFICATION_COUNTER 607
                      #define PREDICTED_COUNTER 608
                    #endif
                  #endif
                #else /* Was [597-600] */
                  #if (__COUNTER__ <= (598+9)) /* Was [597-598] */
                    #if (__COUNTER__ <= (597+10)) /* Was [597-597] */
                      #define ORIGINAL_COUNTER 597
                      #define VERIFICATION_COUNTER 608
                      #define PREDICTED_COUNTER 609
                    #else /* Was [598-598] */
                      #define ORIGINAL_COUNTER 598
                      #define VERIFICATION_COUNTER 609
                      #define PREDICTED_COUNTER 610
                    #endif
                  #else /* Was [599-600] */
                    #if (__COUNTER__ <= (599+10)) /* Was [599-599] */
                      #define ORIGINAL_COUNTER 599
                      #define VERIFICATION_COUNTER 610
                      #define PREDICTED_COUNTER 611
                    #else /* Was [600-600] */
                      #define ORIGINAL_COUNTER 600
                      #define VERIFICATION_COUNTER 611
                      #define PREDICTED_COUNTER 612
                    #endif
                  #endif
                #endif
              #else /* Was [601-608] */
                #if (__COUNTER__ <= (604+8)) /* Was [601-604] */
                  #if (__COUNTER__ <= (602+9)) /* Was [601-602] */
                    #if (__COUNTER__ <= (601+10)) /* Was [601-601] */
                      #define ORIGINAL_COUNTER 601
                      #define VERIFICATION_COUNTER 612
                      #define PREDICTED_COUNTER 613
                    #else /* Was [602-602] */
                      #define ORIGINAL_COUNTER 602
                      #define VERIFICATION_COUNTER 613
                      #define PREDICTED_COUNTER 614
                    #endif
                  #else /* Was [603-604] */
                    #if (__COUNTER__ <= (603+10)) /* Was [603-603] */
                      #define ORIGINAL_COUNTER 603
                      #define VERIFICATION_COUNTER 614
                      #define PREDICTED_COUNTER 615
                    #else /* Was [604-604] */
                      #define ORIGINAL_COUNTER 604
                      #define VERIFICATION_COUNTER 615
                      #define PREDICTED_COUNTER 616
                    #endif
                  #endif
                #else /* Was [605-608] */
                  #if (__COUNTER__ <= (606+9)) /* Was [605-606] */
                    #if (__COUNTER__ <= (605+10)) /* Was [605-605] */
                      #define ORIGINAL_COUNTER 605
                      #define VERIFICATION_COUNTER 616
                      #define PREDICTED_COUNTER 617
                    #else /* Was [606-606] */
                      #define ORIGINAL_COUNTER 606
                      #define VERIFICATION_COUNTER 617
                      #define PREDICTED_COUNTER 618
                    #endif
                  #else /* Was [607-608] */
                    #if (__COUNTER__ <= (607+10)) /* Was [607-607] */
                      #define ORIGINAL_COUNTER 607
                      #define VERIFICATION_COUNTER 618
                      #define PREDICTED_COUNTER 619
                    #else /* Was [608-608] */
                      #define ORIGINAL_COUNTER 608
                      #define VERIFICATION_COUNTER 619
                      #define PREDICTED_COUNTER 620
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [609-640] */
            #if (__COUNTER__ <= (624+6)) /* Was [609-624] */
              #if (__COUNTER__ <= (616+7)) /* Was [609-616] */
                #if (__COUNTER__ <= (612+8)) /* Was [609-612] */
                  #if (__COUNTER__ <= (610+9)) /* Was [609-610] */
                    #if (__COUNTER__ <= (609+10)) /* Was [609-609] */
                      #define ORIGINAL_COUNTER 609
                      #define VERIFICATION_COUNTER 620
                      #define PREDICTED_COUNTER 621
                    #else /* Was [610-610] */
                      #define ORIGINAL_COUNTER 610
                      #define VERIFICATION_COUNTER 621
                      #define PREDICTED_COUNTER 622
                    #endif
                  #else /* Was [611-612] */
                    #if (__COUNTER__ <= (611+10)) /* Was [611-611] */
                      #define ORIGINAL_COUNTER 611
                      #define VERIFICATION_COUNTER 622
                      #define PREDICTED_COUNTER 623
                    #else /* Was [612-612] */
                      #define ORIGINAL_COUNTER 612
                      #define VERIFICATION_COUNTER 623
                      #define PREDICTED_COUNTER 624
                    #endif
                  #endif
                #else /* Was [613-616] */
                  #if (__COUNTER__ <= (614+9)) /* Was [613-614] */
                    #if (__COUNTER__ <= (613+10)) /* Was [613-613] */
                      #define ORIGINAL_COUNTER 613
                      #define VERIFICATION_COUNTER 624
                      #define PREDICTED_COUNTER 625
                    #else /* Was [614-614] */
                      #define ORIGINAL_COUNTER 614
                      #define VERIFICATION_COUNTER 625
                      #define PREDICTED_COUNTER 626
                    #endif
                  #else /* Was [615-616] */
                    #if (__COUNTER__ <= (615+10)) /* Was [615-615] */
                      #define ORIGINAL_COUNTER 615
                      #define VERIFICATION_COUNTER 626
                      #define PREDICTED_COUNTER 627
                    #else /* Was [616-616] */
                      #define ORIGINAL_COUNTER 616
                      #define VERIFICATION_COUNTER 627
                      #define PREDICTED_COUNTER 628
                    #endif
                  #endif
                #endif
              #else /* Was [617-624] */
                #if (__COUNTER__ <= (620+8)) /* Was [617-620] */
                  #if (__COUNTER__ <= (618+9)) /* Was [617-618] */
                    #if (__COUNTER__ <= (617+10)) /* Was [617-617] */
                      #define ORIGINAL_COUNTER 617
                      #define VERIFICATION_COUNTER 628
                      #define PREDICTED_COUNTER 629
                    #else /* Was [618-618] */
                      #define ORIGINAL_COUNTER 618
                      #define VERIFICATION_COUNTER 629
                      #define PREDICTED_COUNTER 630
                    #endif
                  #else /* Was [619-620] */
                    #if (__COUNTER__ <= (619+10)) /* Was [619-619] */
                      #define ORIGINAL_COUNTER 619
                      #define VERIFICATION_COUNTER 630
                      #define PREDICTED_COUNTER 631
                    #else /* Was [620-620] */
                      #define ORIGINAL_COUNTER 620
                      #define VERIFICATION_COUNTER 631
                      #define PREDICTED_COUNTER 632
                    #endif
                  #endif
                #else /* Was [621-624] */
                  #if (__COUNTER__ <= (622+9)) /* Was [621-622] */
                    #if (__COUNTER__ <= (621+10)) /* Was [621-621] */
                      #define ORIGINAL_COUNTER 621
                      #define VERIFICATION_COUNTER 632
                      #define PREDICTED_COUNTER 633
                    #else /* Was [622-622] */
                      #define ORIGINAL_COUNTER 622
                      #define VERIFICATION_COUNTER 633
                      #define PREDICTED_COUNTER 634
                    #endif
                  #else /* Was [623-624] */
                    #if (__COUNTER__ <= (623+10)) /* Was [623-623] */
                      #define ORIGINAL_COUNTER 623
                      #define VERIFICATION_COUNTER 634
                      #define PREDICTED_COUNTER 635
                    #else /* Was [624-624] */
                      #define ORIGINAL_COUNTER 624
                      #define VERIFICATION_COUNTER 635
                      #define PREDICTED_COUNTER 636
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [625-640] */
              #if (__COUNTER__ <= (632+7)) /* Was [625-632] */
                #if (__COUNTER__ <= (628+8)) /* Was [625-628] */
                  #if (__COUNTER__ <= (626+9)) /* Was [625-626] */
                    #if (__COUNTER__ <= (625+10)) /* Was [625-625] */
                      #define ORIGINAL_COUNTER 625
                      #define VERIFICATION_COUNTER 636
                      #define PREDICTED_COUNTER 637
                    #else /* Was [626-626] */
                      #define ORIGINAL_COUNTER 626
                      #define VERIFICATION_COUNTER 637
                      #define PREDICTED_COUNTER 638
                    #endif
                  #else /* Was [627-628] */
                    #if (__COUNTER__ <= (627+10)) /* Was [627-627] */
                      #define ORIGINAL_COUNTER 627
                      #define VERIFICATION_COUNTER 638
                      #define PREDICTED_COUNTER 639
                    #else /* Was [628-628] */
                      #define ORIGINAL_COUNTER 628
                      #define VERIFICATION_COUNTER 639
                      #define PREDICTED_COUNTER 640
                    #endif
                  #endif
                #else /* Was [629-632] */
                  #if (__COUNTER__ <= (630+9)) /* Was [629-630] */
                    #if (__COUNTER__ <= (629+10)) /* Was [629-629] */
                      #define ORIGINAL_COUNTER 629
                      #define VERIFICATION_COUNTER 640
                      #define PREDICTED_COUNTER 641
                    #else /* Was [630-630] */
                      #define ORIGINAL_COUNTER 630
                      #define VERIFICATION_COUNTER 641
                      #define PREDICTED_COUNTER 642
                    #endif
                  #else /* Was [631-632] */
                    #if (__COUNTER__ <= (631+10)) /* Was [631-631] */
                      #define ORIGINAL_COUNTER 631
                      #define VERIFICATION_COUNTER 642
                      #define PREDICTED_COUNTER 643
                    #else /* Was [632-632] */
                      #define ORIGINAL_COUNTER 632
                      #define VERIFICATION_COUNTER 643
                      #define PREDICTED_COUNTER 644
                    #endif
                  #endif
                #endif
              #else /* Was [633-640] */
                #if (__COUNTER__ <= (636+8)) /* Was [633-636] */
                  #if (__COUNTER__ <= (634+9)) /* Was [633-634] */
                    #if (__COUNTER__ <= (633+10)) /* Was [633-633] */
                      #define ORIGINAL_COUNTER 633
                      #define VERIFICATION_COUNTER 644
                      #define PREDICTED_COUNTER 645
                    #else /* Was [634-634] */
                      #define ORIGINAL_COUNTER 634
                      #define VERIFICATION_COUNTER 645
                      #define PREDICTED_COUNTER 646
                    #endif
                  #else /* Was [635-636] */
                    #if (__COUNTER__ <= (635+10)) /* Was [635-635] */
                      #define ORIGINAL_COUNTER 635
                      #define VERIFICATION_COUNTER 646
                      #define PREDICTED_COUNTER 647
                    #else /* Was [636-636] */
                      #define ORIGINAL_COUNTER 636
                      #define VERIFICATION_COUNTER 647
                      #define PREDICTED_COUNTER 648
                    #endif
                  #endif
                #else /* Was [637-640] */
                  #if (__COUNTER__ <= (638+9)) /* Was [637-638] */
                    #if (__COUNTER__ <= (637+10)) /* Was [637-637] */
                      #define ORIGINAL_COUNTER 637
                      #define VERIFICATION_COUNTER 648
                      #define PREDICTED_COUNTER 649
                    #else /* Was [638-638] */
                      #define ORIGINAL_COUNTER 638
                      #define VERIFICATION_COUNTER 649
                      #define PREDICTED_COUNTER 650
                    #endif
                  #else /* Was [639-640] */
                    #if (__COUNTER__ <= (639+10)) /* Was [639-639] */
                      #define ORIGINAL_COUNTER 639
                      #define VERIFICATION_COUNTER 650
                      #define PREDICTED_COUNTER 651
                    #else /* Was [640-640] */
                      #define ORIGINAL_COUNTER 640
                      #define VERIFICATION_COUNTER 651
                      #define PREDICTED_COUNTER 652
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #endif
      #else /* Was [641-768] */
        #if (__COUNTER__ <= (704+4)) /* Was [641-704] */
          #if (__COUNTER__ <= (672+5)) /* Was [641-672] */
            #if (__COUNTER__ <= (656+6)) /* Was [641-656] */
              #if (__COUNTER__ <= (648+7)) /* Was [641-648] */
                #if (__COUNTER__ <= (644+8)) /* Was [641-644] */
                  #if (__COUNTER__ <= (642+9)) /* Was [641-642] */
                    #if (__COUNTER__ <= (641+10)) /* Was [641-641] */
                      #define ORIGINAL_COUNTER 641
                      #define VERIFICATION_COUNTER 652
                      #define PREDICTED_COUNTER 653
                    #else /* Was [642-642] */
                      #define ORIGINAL_COUNTER 642
                      #define VERIFICATION_COUNTER 653
                      #define PREDICTED_COUNTER 654
                    #endif
                  #else /* Was [643-644] */
                    #if (__COUNTER__ <= (643+10)) /* Was [643-643] */
                      #define ORIGINAL_COUNTER 643
                      #define VERIFICATION_COUNTER 654
                      #define PREDICTED_COUNTER 655
                    #else /* Was [644-644] */
                      #define ORIGINAL_COUNTER 644
                      #define VERIFICATION_COUNTER 655
                      #define PREDICTED_COUNTER 656
                    #endif
                  #endif
                #else /* Was [645-648] */
                  #if (__COUNTER__ <= (646+9)) /* Was [645-646] */
                    #if (__COUNTER__ <= (645+10)) /* Was [645-645] */
                      #define ORIGINAL_COUNTER 645
                      #define VERIFICATION_COUNTER 656
                      #define PREDICTED_COUNTER 657
                    #else /* Was [646-646] */
                      #define ORIGINAL_COUNTER 646
                      #define VERIFICATION_COUNTER 657
                      #define PREDICTED_COUNTER 658
                    #endif
                  #else /* Was [647-648] */
                    #if (__COUNTER__ <= (647+10)) /* Was [647-647] */
                      #define ORIGINAL_COUNTER 647
                      #define VERIFICATION_COUNTER 658
                      #define PREDICTED_COUNTER 659
                    #else /* Was [648-648] */
                      #define ORIGINAL_COUNTER 648
                      #define VERIFICATION_COUNTER 659
                      #define PREDICTED_COUNTER 660
                    #endif
                  #endif
                #endif
              #else /* Was [649-656] */
                #if (__COUNTER__ <= (652+8)) /* Was [649-652] */
                  #if (__COUNTER__ <= (650+9)) /* Was [649-650] */
                    #if (__COUNTER__ <= (649+10)) /* Was [649-649] */
                      #define ORIGINAL_COUNTER 649
                      #define VERIFICATION_COUNTER 660
                      #define PREDICTED_COUNTER 661
                    #else /* Was [650-650] */
                      #define ORIGINAL_COUNTER 650
                      #define VERIFICATION_COUNTER 661
                      #define PREDICTED_COUNTER 662
                    #endif
                  #else /* Was [651-652] */
                    #if (__COUNTER__ <= (651+10)) /* Was [651-651] */
                      #define ORIGINAL_COUNTER 651
                      #define VERIFICATION_COUNTER 662
                      #define PREDICTED_COUNTER 663
                    #else /* Was [652-652] */
                      #define ORIGINAL_COUNTER 652
                      #define VERIFICATION_COUNTER 663
                      #define PREDICTED_COUNTER 664
                    #endif
                  #endif
                #else /* Was [653-656] */
                  #if (__COUNTER__ <= (654+9)) /* Was [653-654] */
                    #if (__COUNTER__ <= (653+10)) /* Was [653-653] */
                      #define ORIGINAL_COUNTER 653
                      #define VERIFICATION_COUNTER 664
                      #define PREDICTED_COUNTER 665
                    #else /* Was [654-654] */
                      #define ORIGINAL_COUNTER 654
                      #define VERIFICATION_COUNTER 665
                      #define PREDICTED_COUNTER 666
                    #endif
                  #else /* Was [655-656] */
                    #if (__COUNTER__ <= (655+10)) /* Was [655-655] */
                      #define ORIGINAL_COUNTER 655
                      #define VERIFICATION_COUNTER 666
                      #define PREDICTED_COUNTER 667
                    #else /* Was [656-656] */
                      #define ORIGINAL_COUNTER 656
                      #define VERIFICATION_COUNTER 667
                      #define PREDICTED_COUNTER 668
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [657-672] */
              #if (__COUNTER__ <= (664+7)) /* Was [657-664] */
                #if (__COUNTER__ <= (660+8)) /* Was [657-660] */
                  #if (__COUNTER__ <= (658+9)) /* Was [657-658] */
                    #if (__COUNTER__ <= (657+10)) /* Was [657-657] */
                      #define ORIGINAL_COUNTER 657
                      #define VERIFICATION_COUNTER 668
                      #define PREDICTED_COUNTER 669
                    #else /* Was [658-658] */
                      #define ORIGINAL_COUNTER 658
                      #define VERIFICATION_COUNTER 669
                      #define PREDICTED_COUNTER 670
                    #endif
                  #else /* Was [659-660] */
                    #if (__COUNTER__ <= (659+10)) /* Was [659-659] */
                      #define ORIGINAL_COUNTER 659
                      #define VERIFICATION_COUNTER 670
                      #define PREDICTED_COUNTER 671
                    #else /* Was [660-660] */
                      #define ORIGINAL_COUNTER 660
                      #define VERIFICATION_COUNTER 671
                      #define PREDICTED_COUNTER 672
                    #endif
                  #endif
                #else /* Was [661-664] */
                  #if (__COUNTER__ <= (662+9)) /* Was [661-662] */
                    #if (__COUNTER__ <= (661+10)) /* Was [661-661] */
                      #define ORIGINAL_COUNTER 661
                      #define VERIFICATION_COUNTER 672
                      #define PREDICTED_COUNTER 673
                    #else /* Was [662-662] */
                      #define ORIGINAL_COUNTER 662
                      #define VERIFICATION_COUNTER 673
                      #define PREDICTED_COUNTER 674
                    #endif
                  #else /* Was [663-664] */
                    #if (__COUNTER__ <= (663+10)) /* Was [663-663] */
                      #define ORIGINAL_COUNTER 663
                      #define VERIFICATION_COUNTER 674
                      #define PREDICTED_COUNTER 675
                    #else /* Was [664-664] */
                      #define ORIGINAL_COUNTER 664
                      #define VERIFICATION_COUNTER 675
                      #define PREDICTED_COUNTER 676
                    #endif
                  #endif
                #endif
              #else /* Was [665-672] */
                #if (__COUNTER__ <= (668+8)) /* Was [665-668] */
                  #if (__COUNTER__ <= (666+9)) /* Was [665-666] */
                    #if (__COUNTER__ <= (665+10)) /* Was [665-665] */
                      #define ORIGINAL_COUNTER 665
                      #define VERIFICATION_COUNTER 676
                      #define PREDICTED_COUNTER 677
                    #else /* Was [666-666] */
                      #define ORIGINAL_COUNTER 666
                      #define VERIFICATION_COUNTER 677
                      #define PREDICTED_COUNTER 678
                    #endif
                  #else /* Was [667-668] */
                    #if (__COUNTER__ <= (667+10)) /* Was [667-667] */
                      #define ORIGINAL_COUNTER 667
                      #define VERIFICATION_COUNTER 678
                      #define PREDICTED_COUNTER 679
                    #else /* Was [668-668] */
                      #define ORIGINAL_COUNTER 668
                      #define VERIFICATION_COUNTER 679
                      #define PREDICTED_COUNTER 680
                    #endif
                  #endif
                #else /* Was [669-672] */
                  #if (__COUNTER__ <= (670+9)) /* Was [669-670] */
                    #if (__COUNTER__ <= (669+10)) /* Was [669-669] */
                      #define ORIGINAL_COUNTER 669
                      #define VERIFICATION_COUNTER 680
                      #define PREDICTED_COUNTER 681
                    #else /* Was [670-670] */
                      #define ORIGINAL_COUNTER 670
                      #define VERIFICATION_COUNTER 681
                      #define PREDICTED_COUNTER 682
                    #endif
                  #else /* Was [671-672] */
                    #if (__COUNTER__ <= (671+10)) /* Was [671-671] */
                      #define ORIGINAL_COUNTER 671
                      #define VERIFICATION_COUNTER 682
                      #define PREDICTED_COUNTER 683
                    #else /* Was [672-672] */
                      #define ORIGINAL_COUNTER 672
                      #define VERIFICATION_COUNTER 683
                      #define PREDICTED_COUNTER 684
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [673-704] */
            #if (__COUNTER__ <= (688+6)) /* Was [673-688] */
              #if (__COUNTER__ <= (680+7)) /* Was [673-680] */
                #if (__COUNTER__ <= (676+8)) /* Was [673-676] */
                  #if (__COUNTER__ <= (674+9)) /* Was [673-674] */
                    #if (__COUNTER__ <= (673+10)) /* Was [673-673] */
                      #define ORIGINAL_COUNTER 673
                      #define VERIFICATION_COUNTER 684
                      #define PREDICTED_COUNTER 685
                    #else /* Was [674-674] */
                      #define ORIGINAL_COUNTER 674
                      #define VERIFICATION_COUNTER 685
                      #define PREDICTED_COUNTER 686
                    #endif
                  #else /* Was [675-676] */
                    #if (__COUNTER__ <= (675+10)) /* Was [675-675] */
                      #define ORIGINAL_COUNTER 675
                      #define VERIFICATION_COUNTER 686
                      #define PREDICTED_COUNTER 687
                    #else /* Was [676-676] */
                      #define ORIGINAL_COUNTER 676
                      #define VERIFICATION_COUNTER 687
                      #define PREDICTED_COUNTER 688
                    #endif
                  #endif
                #else /* Was [677-680] */
                  #if (__COUNTER__ <= (678+9)) /* Was [677-678] */
                    #if (__COUNTER__ <= (677+10)) /* Was [677-677] */
                      #define ORIGINAL_COUNTER 677
                      #define VERIFICATION_COUNTER 688
                      #define PREDICTED_COUNTER 689
                    #else /* Was [678-678] */
                      #define ORIGINAL_COUNTER 678
                      #define VERIFICATION_COUNTER 689
                      #define PREDICTED_COUNTER 690
                    #endif
                  #else /* Was [679-680] */
                    #if (__COUNTER__ <= (679+10)) /* Was [679-679] */
                      #define ORIGINAL_COUNTER 679
                      #define VERIFICATION_COUNTER 690
                      #define PREDICTED_COUNTER 691
                    #else /* Was [680-680] */
                      #define ORIGINAL_COUNTER 680
                      #define VERIFICATION_COUNTER 691
                      #define PREDICTED_COUNTER 692
                    #endif
                  #endif
                #endif
              #else /* Was [681-688] */
                #if (__COUNTER__ <= (684+8)) /* Was [681-684] */
                  #if (__COUNTER__ <= (682+9)) /* Was [681-682] */
                    #if (__COUNTER__ <= (681+10)) /* Was [681-681] */
                      #define ORIGINAL_COUNTER 681
                      #define VERIFICATION_COUNTER 692
                      #define PREDICTED_COUNTER 693
                    #else /* Was [682-682] */
                      #define ORIGINAL_COUNTER 682
                      #define VERIFICATION_COUNTER 693
                      #define PREDICTED_COUNTER 694
                    #endif
                  #else /* Was [683-684] */
                    #if (__COUNTER__ <= (683+10)) /* Was [683-683] */
                      #define ORIGINAL_COUNTER 683
                      #define VERIFICATION_COUNTER 694
                      #define PREDICTED_COUNTER 695
                    #else /* Was [684-684] */
                      #define ORIGINAL_COUNTER 684
                      #define VERIFICATION_COUNTER 695
                      #define PREDICTED_COUNTER 696
                    #endif
                  #endif
                #else /* Was [685-688] */
                  #if (__COUNTER__ <= (686+9)) /* Was [685-686] */
                    #if (__COUNTER__ <= (685+10)) /* Was [685-685] */
                      #define ORIGINAL_COUNTER 685
                      #define VERIFICATION_COUNTER 696
                      #define PREDICTED_COUNTER 697
                    #else /* Was [686-686] */
                      #define ORIGINAL_COUNTER 686
                      #define VERIFICATION_COUNTER 697
                      #define PREDICTED_COUNTER 698
                    #endif
                  #else /* Was [687-688] */
                    #if (__COUNTER__ <= (687+10)) /* Was [687-687] */
                      #define ORIGINAL_COUNTER 687
                      #define VERIFICATION_COUNTER 698
                      #define PREDICTED_COUNTER 699
                    #else /* Was [688-688] */
                      #define ORIGINAL_COUNTER 688
                      #define VERIFICATION_COUNTER 699
                      #define PREDICTED_COUNTER 700
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [689-704] */
              #if (__COUNTER__ <= (696+7)) /* Was [689-696] */
                #if (__COUNTER__ <= (692+8)) /* Was [689-692] */
                  #if (__COUNTER__ <= (690+9)) /* Was [689-690] */
                    #if (__COUNTER__ <= (689+10)) /* Was [689-689] */
                      #define ORIGINAL_COUNTER 689
                      #define VERIFICATION_COUNTER 700
                      #define PREDICTED_COUNTER 701
                    #else /* Was [690-690] */
                      #define ORIGINAL_COUNTER 690
                      #define VERIFICATION_COUNTER 701
                      #define PREDICTED_COUNTER 702
                    #endif
                  #else /* Was [691-692] */
                    #if (__COUNTER__ <= (691+10)) /* Was [691-691] */
                      #define ORIGINAL_COUNTER 691
                      #define VERIFICATION_COUNTER 702
                      #define PREDICTED_COUNTER 703
                    #else /* Was [692-692] */
                      #define ORIGINAL_COUNTER 692
                      #define VERIFICATION_COUNTER 703
                      #define PREDICTED_COUNTER 704
                    #endif
                  #endif
                #else /* Was [693-696] */
                  #if (__COUNTER__ <= (694+9)) /* Was [693-694] */
                    #if (__COUNTER__ <= (693+10)) /* Was [693-693] */
                      #define ORIGINAL_COUNTER 693
                      #define VERIFICATION_COUNTER 704
                      #define PREDICTED_COUNTER 705
                    #else /* Was [694-694] */
                      #define ORIGINAL_COUNTER 694
                      #define VERIFICATION_COUNTER 705
                      #define PREDICTED_COUNTER 706
                    #endif
                  #else /* Was [695-696] */
                    #if (__COUNTER__ <= (695+10)) /* Was [695-695] */
                      #define ORIGINAL_COUNTER 695
                      #define VERIFICATION_COUNTER 706
                      #define PREDICTED_COUNTER 707
                    #else /* Was [696-696] */
                      #define ORIGINAL_COUNTER 696
                      #define VERIFICATION_COUNTER 707
                      #define PREDICTED_COUNTER 708
                    #endif
                  #endif
                #endif
              #else /* Was [697-704] */
                #if (__COUNTER__ <= (700+8)) /* Was [697-700] */
                  #if (__COUNTER__ <= (698+9)) /* Was [697-698] */
                    #if (__COUNTER__ <= (697+10)) /* Was [697-697] */
                      #define ORIGINAL_COUNTER 697
                      #define VERIFICATION_COUNTER 708
                      #define PREDICTED_COUNTER 709
                    #else /* Was [698-698] */
                      #define ORIGINAL_COUNTER 698
                      #define VERIFICATION_COUNTER 709
                      #define PREDICTED_COUNTER 710
                    #endif
                  #else /* Was [699-700] */
                    #if (__COUNTER__ <= (699+10)) /* Was [699-699] */
                      #define ORIGINAL_COUNTER 699
                      #define VERIFICATION_COUNTER 710
                      #define PREDICTED_COUNTER 711
                    #else /* Was [700-700] */
                      #define ORIGINAL_COUNTER 700
                      #define VERIFICATION_COUNTER 711
                      #define PREDICTED_COUNTER 712
                    #endif
                  #endif
                #else /* Was [701-704] */
                  #if (__COUNTER__ <= (702+9)) /* Was [701-702] */
                    #if (__COUNTER__ <= (701+10)) /* Was [701-701] */
                      #define ORIGINAL_COUNTER 701
                      #define VERIFICATION_COUNTER 712
                      #define PREDICTED_COUNTER 713
                    #else /* Was [702-702] */
                      #define ORIGINAL_COUNTER 702
                      #define VERIFICATION_COUNTER 713
                      #define PREDICTED_COUNTER 714
                    #endif
                  #else /* Was [703-704] */
                    #if (__COUNTER__ <= (703+10)) /* Was [703-703] */
                      #define ORIGINAL_COUNTER 703
                      #define VERIFICATION_COUNTER 714
                      #define PREDICTED_COUNTER 715
                    #else /* Was [704-704] */
                      #define ORIGINAL_COUNTER 704
                      #define VERIFICATION_COUNTER 715
                      #define PREDICTED_COUNTER 716
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #else /* Was [705-768] */
          #if (__COUNTER__ <= (736+5)) /* Was [705-736] */
            #if (__COUNTER__ <= (720+6)) /* Was [705-720] */
              #if (__COUNTER__ <= (712+7)) /* Was [705-712] */
                #if (__COUNTER__ <= (708+8)) /* Was [705-708] */
                  #if (__COUNTER__ <= (706+9)) /* Was [705-706] */
                    #if (__COUNTER__ <= (705+10)) /* Was [705-705] */
                      #define ORIGINAL_COUNTER 705
                      #define VERIFICATION_COUNTER 716
                      #define PREDICTED_COUNTER 717
                    #else /* Was [706-706] */
                      #define ORIGINAL_COUNTER 706
                      #define VERIFICATION_COUNTER 717
                      #define PREDICTED_COUNTER 718
                    #endif
                  #else /* Was [707-708] */
                    #if (__COUNTER__ <= (707+10)) /* Was [707-707] */
                      #define ORIGINAL_COUNTER 707
                      #define VERIFICATION_COUNTER 718
                      #define PREDICTED_COUNTER 719
                    #else /* Was [708-708] */
                      #define ORIGINAL_COUNTER 708
                      #define VERIFICATION_COUNTER 719
                      #define PREDICTED_COUNTER 720
                    #endif
                  #endif
                #else /* Was [709-712] */
                  #if (__COUNTER__ <= (710+9)) /* Was [709-710] */
                    #if (__COUNTER__ <= (709+10)) /* Was [709-709] */
                      #define ORIGINAL_COUNTER 709
                      #define VERIFICATION_COUNTER 720
                      #define PREDICTED_COUNTER 721
                    #else /* Was [710-710] */
                      #define ORIGINAL_COUNTER 710
                      #define VERIFICATION_COUNTER 721
                      #define PREDICTED_COUNTER 722
                    #endif
                  #else /* Was [711-712] */
                    #if (__COUNTER__ <= (711+10)) /* Was [711-711] */
                      #define ORIGINAL_COUNTER 711
                      #define VERIFICATION_COUNTER 722
                      #define PREDICTED_COUNTER 723
                    #else /* Was [712-712] */
                      #define ORIGINAL_COUNTER 712
                      #define VERIFICATION_COUNTER 723
                      #define PREDICTED_COUNTER 724
                    #endif
                  #endif
                #endif
              #else /* Was [713-720] */
                #if (__COUNTER__ <= (716+8)) /* Was [713-716] */
                  #if (__COUNTER__ <= (714+9)) /* Was [713-714] */
                    #if (__COUNTER__ <= (713+10)) /* Was [713-713] */
                      #define ORIGINAL_COUNTER 713
                      #define VERIFICATION_COUNTER 724
                      #define PREDICTED_COUNTER 725
                    #else /* Was [714-714] */
                      #define ORIGINAL_COUNTER 714
                      #define VERIFICATION_COUNTER 725
                      #define PREDICTED_COUNTER 726
                    #endif
                  #else /* Was [715-716] */
                    #if (__COUNTER__ <= (715+10)) /* Was [715-715] */
                      #define ORIGINAL_COUNTER 715
                      #define VERIFICATION_COUNTER 726
                      #define PREDICTED_COUNTER 727
                    #else /* Was [716-716] */
                      #define ORIGINAL_COUNTER 716
                      #define VERIFICATION_COUNTER 727
                      #define PREDICTED_COUNTER 728
                    #endif
                  #endif
                #else /* Was [717-720] */
                  #if (__COUNTER__ <= (718+9)) /* Was [717-718] */
                    #if (__COUNTER__ <= (717+10)) /* Was [717-717] */
                      #define ORIGINAL_COUNTER 717
                      #define VERIFICATION_COUNTER 728
                      #define PREDICTED_COUNTER 729
                    #else /* Was [718-718] */
                      #define ORIGINAL_COUNTER 718
                      #define VERIFICATION_COUNTER 729
                      #define PREDICTED_COUNTER 730
                    #endif
                  #else /* Was [719-720] */
                    #if (__COUNTER__ <= (719+10)) /* Was [719-719] */
                      #define ORIGINAL_COUNTER 719
                      #define VERIFICATION_COUNTER 730
                      #define PREDICTED_COUNTER 731
                    #else /* Was [720-720] */
                      #define ORIGINAL_COUNTER 720
                      #define VERIFICATION_COUNTER 731
                      #define PREDICTED_COUNTER 732
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [721-736] */
              #if (__COUNTER__ <= (728+7)) /* Was [721-728] */
                #if (__COUNTER__ <= (724+8)) /* Was [721-724] */
                  #if (__COUNTER__ <= (722+9)) /* Was [721-722] */
                    #if (__COUNTER__ <= (721+10)) /* Was [721-721] */
                      #define ORIGINAL_COUNTER 721
                      #define VERIFICATION_COUNTER 732
                      #define PREDICTED_COUNTER 733
                    #else /* Was [722-722] */
                      #define ORIGINAL_COUNTER 722
                      #define VERIFICATION_COUNTER 733
                      #define PREDICTED_COUNTER 734
                    #endif
                  #else /* Was [723-724] */
                    #if (__COUNTER__ <= (723+10)) /* Was [723-723] */
                      #define ORIGINAL_COUNTER 723
                      #define VERIFICATION_COUNTER 734
                      #define PREDICTED_COUNTER 735
                    #else /* Was [724-724] */
                      #define ORIGINAL_COUNTER 724
                      #define VERIFICATION_COUNTER 735
                      #define PREDICTED_COUNTER 736
                    #endif
                  #endif
                #else /* Was [725-728] */
                  #if (__COUNTER__ <= (726+9)) /* Was [725-726] */
                    #if (__COUNTER__ <= (725+10)) /* Was [725-725] */
                      #define ORIGINAL_COUNTER 725
                      #define VERIFICATION_COUNTER 736
                      #define PREDICTED_COUNTER 737
                    #else /* Was [726-726] */
                      #define ORIGINAL_COUNTER 726
                      #define VERIFICATION_COUNTER 737
                      #define PREDICTED_COUNTER 738
                    #endif
                  #else /* Was [727-728] */
                    #if (__COUNTER__ <= (727+10)) /* Was [727-727] */
                      #define ORIGINAL_COUNTER 727
                      #define VERIFICATION_COUNTER 738
                      #define PREDICTED_COUNTER 739
                    #else /* Was [728-728] */
                      #define ORIGINAL_COUNTER 728
                      #define VERIFICATION_COUNTER 739
                      #define PREDICTED_COUNTER 740
                    #endif
                  #endif
                #endif
              #else /* Was [729-736] */
                #if (__COUNTER__ <= (732+8)) /* Was [729-732] */
                  #if (__COUNTER__ <= (730+9)) /* Was [729-730] */
                    #if (__COUNTER__ <= (729+10)) /* Was [729-729] */
                      #define ORIGINAL_COUNTER 729
                      #define VERIFICATION_COUNTER 740
                      #define PREDICTED_COUNTER 741
                    #else /* Was [730-730] */
                      #define ORIGINAL_COUNTER 730
                      #define VERIFICATION_COUNTER 741
                      #define PREDICTED_COUNTER 742
                    #endif
                  #else /* Was [731-732] */
                    #if (__COUNTER__ <= (731+10)) /* Was [731-731] */
                      #define ORIGINAL_COUNTER 731
                      #define VERIFICATION_COUNTER 742
                      #define PREDICTED_COUNTER 743
                    #else /* Was [732-732] */
                      #define ORIGINAL_COUNTER 732
                      #define VERIFICATION_COUNTER 743
                      #define PREDICTED_COUNTER 744
                    #endif
                  #endif
                #else /* Was [733-736] */
                  #if (__COUNTER__ <= (734+9)) /* Was [733-734] */
                    #if (__COUNTER__ <= (733+10)) /* Was [733-733] */
                      #define ORIGINAL_COUNTER 733
                      #define VERIFICATION_COUNTER 744
                      #define PREDICTED_COUNTER 745
                    #else /* Was [734-734] */
                      #define ORIGINAL_COUNTER 734
                      #define VERIFICATION_COUNTER 745
                      #define PREDICTED_COUNTER 746
                    #endif
                  #else /* Was [735-736] */
                    #if (__COUNTER__ <= (735+10)) /* Was [735-735] */
                      #define ORIGINAL_COUNTER 735
                      #define VERIFICATION_COUNTER 746
                      #define PREDICTED_COUNTER 747
                    #else /* Was [736-736] */
                      #define ORIGINAL_COUNTER 736
                      #define VERIFICATION_COUNTER 747
                      #define PREDICTED_COUNTER 748
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [737-768] */
            #if (__COUNTER__ <= (752+6)) /* Was [737-752] */
              #if (__COUNTER__ <= (744+7)) /* Was [737-744] */
                #if (__COUNTER__ <= (740+8)) /* Was [737-740] */
                  #if (__COUNTER__ <= (738+9)) /* Was [737-738] */
                    #if (__COUNTER__ <= (737+10)) /* Was [737-737] */
                      #define ORIGINAL_COUNTER 737
                      #define VERIFICATION_COUNTER 748
                      #define PREDICTED_COUNTER 749
                    #else /* Was [738-738] */
                      #define ORIGINAL_COUNTER 738
                      #define VERIFICATION_COUNTER 749
                      #define PREDICTED_COUNTER 750
                    #endif
                  #else /* Was [739-740] */
                    #if (__COUNTER__ <= (739+10)) /* Was [739-739] */
                      #define ORIGINAL_COUNTER 739
                      #define VERIFICATION_COUNTER 750
                      #define PREDICTED_COUNTER 751
                    #else /* Was [740-740] */
                      #define ORIGINAL_COUNTER 740
                      #define VERIFICATION_COUNTER 751
                      #define PREDICTED_COUNTER 752
                    #endif
                  #endif
                #else /* Was [741-744] */
                  #if (__COUNTER__ <= (742+9)) /* Was [741-742] */
                    #if (__COUNTER__ <= (741+10)) /* Was [741-741] */
                      #define ORIGINAL_COUNTER 741
                      #define VERIFICATION_COUNTER 752
                      #define PREDICTED_COUNTER 753
                    #else /* Was [742-742] */
                      #define ORIGINAL_COUNTER 742
                      #define VERIFICATION_COUNTER 753
                      #define PREDICTED_COUNTER 754
                    #endif
                  #else /* Was [743-744] */
                    #if (__COUNTER__ <= (743+10)) /* Was [743-743] */
                      #define ORIGINAL_COUNTER 743
                      #define VERIFICATION_COUNTER 754
                      #define PREDICTED_COUNTER 755
                    #else /* Was [744-744] */
                      #define ORIGINAL_COUNTER 744
                      #define VERIFICATION_COUNTER 755
                      #define PREDICTED_COUNTER 756
                    #endif
                  #endif
                #endif
              #else /* Was [745-752] */
                #if (__COUNTER__ <= (748+8)) /* Was [745-748] */
                  #if (__COUNTER__ <= (746+9)) /* Was [745-746] */
                    #if (__COUNTER__ <= (745+10)) /* Was [745-745] */
                      #define ORIGINAL_COUNTER 745
                      #define VERIFICATION_COUNTER 756
                      #define PREDICTED_COUNTER 757
                    #else /* Was [746-746] */
                      #define ORIGINAL_COUNTER 746
                      #define VERIFICATION_COUNTER 757
                      #define PREDICTED_COUNTER 758
                    #endif
                  #else /* Was [747-748] */
                    #if (__COUNTER__ <= (747+10)) /* Was [747-747] */
                      #define ORIGINAL_COUNTER 747
                      #define VERIFICATION_COUNTER 758
                      #define PREDICTED_COUNTER 759
                    #else /* Was [748-748] */
                      #define ORIGINAL_COUNTER 748
                      #define VERIFICATION_COUNTER 759
                      #define PREDICTED_COUNTER 760
                    #endif
                  #endif
                #else /* Was [749-752] */
                  #if (__COUNTER__ <= (750+9)) /* Was [749-750] */
                    #if (__COUNTER__ <= (749+10)) /* Was [749-749] */
                      #define ORIGINAL_COUNTER 749
                      #define VERIFICATION_COUNTER 760
                      #define PREDICTED_COUNTER 761
                    #else /* Was [750-750] */
                      #define ORIGINAL_COUNTER 750
                      #define VERIFICATION_COUNTER 761
                      #define PREDICTED_COUNTER 762
                    #endif
                  #else /* Was [751-752] */
                    #if (__COUNTER__ <= (751+10)) /* Was [751-751] */
                      #define ORIGINAL_COUNTER 751
                      #define VERIFICATION_COUNTER 762
                      #define PREDICTED_COUNTER 763
                    #else /* Was [752-752] */
                      #define ORIGINAL_COUNTER 752
                      #define VERIFICATION_COUNTER 763
                      #define PREDICTED_COUNTER 764
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [753-768] */
              #if (__COUNTER__ <= (760+7)) /* Was [753-760] */
                #if (__COUNTER__ <= (756+8)) /* Was [753-756] */
                  #if (__COUNTER__ <= (754+9)) /* Was [753-754] */
                    #if (__COUNTER__ <= (753+10)) /* Was [753-753] */
                      #define ORIGINAL_COUNTER 753
                      #define VERIFICATION_COUNTER 764
                      #define PREDICTED_COUNTER 765
                    #else /* Was [754-754] */
                      #define ORIGINAL_COUNTER 754
                      #define VERIFICATION_COUNTER 765
                      #define PREDICTED_COUNTER 766
                    #endif
                  #else /* Was [755-756] */
                    #if (__COUNTER__ <= (755+10)) /* Was [755-755] */
                      #define ORIGINAL_COUNTER 755
                      #define VERIFICATION_COUNTER 766
                      #define PREDICTED_COUNTER 767
                    #else /* Was [756-756] */
                      #define ORIGINAL_COUNTER 756
                      #define VERIFICATION_COUNTER 767
                      #define PREDICTED_COUNTER 768
                    #endif
                  #endif
                #else /* Was [757-760] */
                  #if (__COUNTER__ <= (758+9)) /* Was [757-758] */
                    #if (__COUNTER__ <= (757+10)) /* Was [757-757] */
                      #define ORIGINAL_COUNTER 757
                      #define VERIFICATION_COUNTER 768
                      #define PREDICTED_COUNTER 769
                    #else /* Was [758-758] */
                      #define ORIGINAL_COUNTER 758
                      #define VERIFICATION_COUNTER 769
                      #define PREDICTED_COUNTER 770
                    #endif
                  #else /* Was [759-760] */
                    #if (__COUNTER__ <= (759+10)) /* Was [759-759] */
                      #define ORIGINAL_COUNTER 759
                      #define VERIFICATION_COUNTER 770
                      #define PREDICTED_COUNTER 771
                    #else /* Was [760-760] */
                      #define ORIGINAL_COUNTER 760
                      #define VERIFICATION_COUNTER 771
                      #define PREDICTED_COUNTER 772
                    #endif
                  #endif
                #endif
              #else /* Was [761-768] */
                #if (__COUNTER__ <= (764+8)) /* Was [761-764] */
                  #if (__COUNTER__ <= (762+9)) /* Was [761-762] */
                    #if (__COUNTER__ <= (761+10)) /* Was [761-761] */
                      #define ORIGINAL_COUNTER 761
                      #define VERIFICATION_COUNTER 772
                      #define PREDICTED_COUNTER 773
                    #else /* Was [762-762] */
                      #define ORIGINAL_COUNTER 762
                      #define VERIFICATION_COUNTER 773
                      #define PREDICTED_COUNTER 774
                    #endif
                  #else /* Was [763-764] */
                    #if (__COUNTER__ <= (763+10)) /* Was [763-763] */
                      #define ORIGINAL_COUNTER 763
                      #define VERIFICATION_COUNTER 774
                      #define PREDICTED_COUNTER 775
                    #else /* Was [764-764] */
                      #define ORIGINAL_COUNTER 764
                      #define VERIFICATION_COUNTER 775
                      #define PREDICTED_COUNTER 776
                    #endif
                  #endif
                #else /* Was [765-768] */
                  #if (__COUNTER__ <= (766+9)) /* Was [765-766] */
                    #if (__COUNTER__ <= (765+10)) /* Was [765-765] */
                      #define ORIGINAL_COUNTER 765
                      #define VERIFICATION_COUNTER 776
                      #define PREDICTED_COUNTER 777
                    #else /* Was [766-766] */
                      #define ORIGINAL_COUNTER 766
                      #define VERIFICATION_COUNTER 777
                      #define PREDICTED_COUNTER 778
                    #endif
                  #else /* Was [767-768] */
                    #if (__COUNTER__ <= (767+10)) /* Was [767-767] */
                      #define ORIGINAL_COUNTER 767
                      #define VERIFICATION_COUNTER 778
                      #define PREDICTED_COUNTER 779
                    #else /* Was [768-768] */
                      #define ORIGINAL_COUNTER 768
                      #define VERIFICATION_COUNTER 779
                      #define PREDICTED_COUNTER 780
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #endif
      #endif
    #else /* Was [769-1024] */
      #if (__COUNTER__ <= (896+3)) /* Was [769-896] */
        #if (__COUNTER__ <= (832+4)) /* Was [769-832] */
          #if (__COUNTER__ <= (800+5)) /* Was [769-800] */
            #if (__COUNTER__ <= (784+6)) /* Was [769-784] */
              #if (__COUNTER__ <= (776+7)) /* Was [769-776] */
                #if (__COUNTER__ <= (772+8)) /* Was [769-772] */
                  #if (__COUNTER__ <= (770+9)) /* Was [769-770] */
                    #if (__COUNTER__ <= (769+10)) /* Was [769-769] */
                      #define ORIGINAL_COUNTER 769
                      #define VERIFICATION_COUNTER 780
                      #define PREDICTED_COUNTER 781
                    #else /* Was [770-770] */
                      #define ORIGINAL_COUNTER 770
                      #define VERIFICATION_COUNTER 781
                      #define PREDICTED_COUNTER 782
                    #endif
                  #else /* Was [771-772] */
                    #if (__COUNTER__ <= (771+10)) /* Was [771-771] */
                      #define ORIGINAL_COUNTER 771
                      #define VERIFICATION_COUNTER 782
                      #define PREDICTED_COUNTER 783
                    #else /* Was [772-772] */
                      #define ORIGINAL_COUNTER 772
                      #define VERIFICATION_COUNTER 783
                      #define PREDICTED_COUNTER 784
                    #endif
                  #endif
                #else /* Was [773-776] */
                  #if (__COUNTER__ <= (774+9)) /* Was [773-774] */
                    #if (__COUNTER__ <= (773+10)) /* Was [773-773] */
                      #define ORIGINAL_COUNTER 773
                      #define VERIFICATION_COUNTER 784
                      #define PREDICTED_COUNTER 785
                    #else /* Was [774-774] */
                      #define ORIGINAL_COUNTER 774
                      #define VERIFICATION_COUNTER 785
                      #define PREDICTED_COUNTER 786
                    #endif
                  #else /* Was [775-776] */
                    #if (__COUNTER__ <= (775+10)) /* Was [775-775] */
                      #define ORIGINAL_COUNTER 775
                      #define VERIFICATION_COUNTER 786
                      #define PREDICTED_COUNTER 787
                    #else /* Was [776-776] */
                      #define ORIGINAL_COUNTER 776
                      #define VERIFICATION_COUNTER 787
                      #define PREDICTED_COUNTER 788
                    #endif
                  #endif
                #endif
              #else /* Was [777-784] */
                #if (__COUNTER__ <= (780+8)) /* Was [777-780] */
                  #if (__COUNTER__ <= (778+9)) /* Was [777-778] */
                    #if (__COUNTER__ <= (777+10)) /* Was [777-777] */
                      #define ORIGINAL_COUNTER 777
                      #define VERIFICATION_COUNTER 788
                      #define PREDICTED_COUNTER 789
                    #else /* Was [778-778] */
                      #define ORIGINAL_COUNTER 778
                      #define VERIFICATION_COUNTER 789
                      #define PREDICTED_COUNTER 790
                    #endif
                  #else /* Was [779-780] */
                    #if (__COUNTER__ <= (779+10)) /* Was [779-779] */
                      #define ORIGINAL_COUNTER 779
                      #define VERIFICATION_COUNTER 790
                      #define PREDICTED_COUNTER 791
                    #else /* Was [780-780] */
                      #define ORIGINAL_COUNTER 780
                      #define VERIFICATION_COUNTER 791
                      #define PREDICTED_COUNTER 792
                    #endif
                  #endif
                #else /* Was [781-784] */
                  #if (__COUNTER__ <= (782+9)) /* Was [781-782] */
                    #if (__COUNTER__ <= (781+10)) /* Was [781-781] */
                      #define ORIGINAL_COUNTER 781
                      #define VERIFICATION_COUNTER 792
                      #define PREDICTED_COUNTER 793
                    #else /* Was [782-782] */
                      #define ORIGINAL_COUNTER 782
                      #define VERIFICATION_COUNTER 793
                      #define PREDICTED_COUNTER 794
                    #endif
                  #else /* Was [783-784] */
                    #if (__COUNTER__ <= (783+10)) /* Was [783-783] */
                      #define ORIGINAL_COUNTER 783
                      #define VERIFICATION_COUNTER 794
                      #define PREDICTED_COUNTER 795
                    #else /* Was [784-784] */
                      #define ORIGINAL_COUNTER 784
                      #define VERIFICATION_COUNTER 795
                      #define PREDICTED_COUNTER 796
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [785-800] */
              #if (__COUNTER__ <= (792+7)) /* Was [785-792] */
                #if (__COUNTER__ <= (788+8)) /* Was [785-788] */
                  #if (__COUNTER__ <= (786+9)) /* Was [785-786] */
                    #if (__COUNTER__ <= (785+10)) /* Was [785-785] */
                      #define ORIGINAL_COUNTER 785
                      #define VERIFICATION_COUNTER 796
                      #define PREDICTED_COUNTER 797
                    #else /* Was [786-786] */
                      #define ORIGINAL_COUNTER 786
                      #define VERIFICATION_COUNTER 797
                      #define PREDICTED_COUNTER 798
                    #endif
                  #else /* Was [787-788] */
                    #if (__COUNTER__ <= (787+10)) /* Was [787-787] */
                      #define ORIGINAL_COUNTER 787
                      #define VERIFICATION_COUNTER 798
                      #define PREDICTED_COUNTER 799
                    #else /* Was [788-788] */
                      #define ORIGINAL_COUNTER 788
                      #define VERIFICATION_COUNTER 799
                      #define PREDICTED_COUNTER 800
                    #endif
                  #endif
                #else /* Was [789-792] */
                  #if (__COUNTER__ <= (790+9)) /* Was [789-790] */
                    #if (__COUNTER__ <= (789+10)) /* Was [789-789] */
                      #define ORIGINAL_COUNTER 789
                      #define VERIFICATION_COUNTER 800
                      #define PREDICTED_COUNTER 801
                    #else /* Was [790-790] */
                      #define ORIGINAL_COUNTER 790
                      #define VERIFICATION_COUNTER 801
                      #define PREDICTED_COUNTER 802
                    #endif
                  #else /* Was [791-792] */
                    #if (__COUNTER__ <= (791+10)) /* Was [791-791] */
                      #define ORIGINAL_COUNTER 791
                      #define VERIFICATION_COUNTER 802
                      #define PREDICTED_COUNTER 803
                    #else /* Was [792-792] */
                      #define ORIGINAL_COUNTER 792
                      #define VERIFICATION_COUNTER 803
                      #define PREDICTED_COUNTER 804
                    #endif
                  #endif
                #endif
              #else /* Was [793-800] */
                #if (__COUNTER__ <= (796+8)) /* Was [793-796] */
                  #if (__COUNTER__ <= (794+9)) /* Was [793-794] */
                    #if (__COUNTER__ <= (793+10)) /* Was [793-793] */
                      #define ORIGINAL_COUNTER 793
                      #define VERIFICATION_COUNTER 804
                      #define PREDICTED_COUNTER 805
                    #else /* Was [794-794] */
                      #define ORIGINAL_COUNTER 794
                      #define VERIFICATION_COUNTER 805
                      #define PREDICTED_COUNTER 806
                    #endif
                  #else /* Was [795-796] */
                    #if (__COUNTER__ <= (795+10)) /* Was [795-795] */
                      #define ORIGINAL_COUNTER 795
                      #define VERIFICATION_COUNTER 806
                      #define PREDICTED_COUNTER 807
                    #else /* Was [796-796] */
                      #define ORIGINAL_COUNTER 796
                      #define VERIFICATION_COUNTER 807
                      #define PREDICTED_COUNTER 808
                    #endif
                  #endif
                #else /* Was [797-800] */
                  #if (__COUNTER__ <= (798+9)) /* Was [797-798] */
                    #if (__COUNTER__ <= (797+10)) /* Was [797-797] */
                      #define ORIGINAL_COUNTER 797
                      #define VERIFICATION_COUNTER 808
                      #define PREDICTED_COUNTER 809
                    #else /* Was [798-798] */
                      #define ORIGINAL_COUNTER 798
                      #define VERIFICATION_COUNTER 809
                      #define PREDICTED_COUNTER 810
                    #endif
                  #else /* Was [799-800] */
                    #if (__COUNTER__ <= (799+10)) /* Was [799-799] */
                      #define ORIGINAL_COUNTER 799
                      #define VERIFICATION_COUNTER 810
                      #define PREDICTED_COUNTER 811
                    #else /* Was [800-800] */
                      #define ORIGINAL_COUNTER 800
                      #define VERIFICATION_COUNTER 811
                      #define PREDICTED_COUNTER 812
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [801-832] */
            #if (__COUNTER__ <= (816+6)) /* Was [801-816] */
              #if (__COUNTER__ <= (808+7)) /* Was [801-808] */
                #if (__COUNTER__ <= (804+8)) /* Was [801-804] */
                  #if (__COUNTER__ <= (802+9)) /* Was [801-802] */
                    #if (__COUNTER__ <= (801+10)) /* Was [801-801] */
                      #define ORIGINAL_COUNTER 801
                      #define VERIFICATION_COUNTER 812
                      #define PREDICTED_COUNTER 813
                    #else /* Was [802-802] */
                      #define ORIGINAL_COUNTER 802
                      #define VERIFICATION_COUNTER 813
                      #define PREDICTED_COUNTER 814
                    #endif
                  #else /* Was [803-804] */
                    #if (__COUNTER__ <= (803+10)) /* Was [803-803] */
                      #define ORIGINAL_COUNTER 803
                      #define VERIFICATION_COUNTER 814
                      #define PREDICTED_COUNTER 815
                    #else /* Was [804-804] */
                      #define ORIGINAL_COUNTER 804
                      #define VERIFICATION_COUNTER 815
                      #define PREDICTED_COUNTER 816
                    #endif
                  #endif
                #else /* Was [805-808] */
                  #if (__COUNTER__ <= (806+9)) /* Was [805-806] */
                    #if (__COUNTER__ <= (805+10)) /* Was [805-805] */
                      #define ORIGINAL_COUNTER 805
                      #define VERIFICATION_COUNTER 816
                      #define PREDICTED_COUNTER 817
                    #else /* Was [806-806] */
                      #define ORIGINAL_COUNTER 806
                      #define VERIFICATION_COUNTER 817
                      #define PREDICTED_COUNTER 818
                    #endif
                  #else /* Was [807-808] */
                    #if (__COUNTER__ <= (807+10)) /* Was [807-807] */
                      #define ORIGINAL_COUNTER 807
                      #define VERIFICATION_COUNTER 818
                      #define PREDICTED_COUNTER 819
                    #else /* Was [808-808] */
                      #define ORIGINAL_COUNTER 808
                      #define VERIFICATION_COUNTER 819
                      #define PREDICTED_COUNTER 820
                    #endif
                  #endif
                #endif
              #else /* Was [809-816] */
                #if (__COUNTER__ <= (812+8)) /* Was [809-812] */
                  #if (__COUNTER__ <= (810+9)) /* Was [809-810] */
                    #if (__COUNTER__ <= (809+10)) /* Was [809-809] */
                      #define ORIGINAL_COUNTER 809
                      #define VERIFICATION_COUNTER 820
                      #define PREDICTED_COUNTER 821
                    #else /* Was [810-810] */
                      #define ORIGINAL_COUNTER 810
                      #define VERIFICATION_COUNTER 821
                      #define PREDICTED_COUNTER 822
                    #endif
                  #else /* Was [811-812] */
                    #if (__COUNTER__ <= (811+10)) /* Was [811-811] */
                      #define ORIGINAL_COUNTER 811
                      #define VERIFICATION_COUNTER 822
                      #define PREDICTED_COUNTER 823
                    #else /* Was [812-812] */
                      #define ORIGINAL_COUNTER 812
                      #define VERIFICATION_COUNTER 823
                      #define PREDICTED_COUNTER 824
                    #endif
                  #endif
                #else /* Was [813-816] */
                  #if (__COUNTER__ <= (814+9)) /* Was [813-814] */
                    #if (__COUNTER__ <= (813+10)) /* Was [813-813] */
                      #define ORIGINAL_COUNTER 813
                      #define VERIFICATION_COUNTER 824
                      #define PREDICTED_COUNTER 825
                    #else /* Was [814-814] */
                      #define ORIGINAL_COUNTER 814
                      #define VERIFICATION_COUNTER 825
                      #define PREDICTED_COUNTER 826
                    #endif
                  #else /* Was [815-816] */
                    #if (__COUNTER__ <= (815+10)) /* Was [815-815] */
                      #define ORIGINAL_COUNTER 815
                      #define VERIFICATION_COUNTER 826
                      #define PREDICTED_COUNTER 827
                    #else /* Was [816-816] */
                      #define ORIGINAL_COUNTER 816
                      #define VERIFICATION_COUNTER 827
                      #define PREDICTED_COUNTER 828
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [817-832] */
              #if (__COUNTER__ <= (824+7)) /* Was [817-824] */
                #if (__COUNTER__ <= (820+8)) /* Was [817-820] */
                  #if (__COUNTER__ <= (818+9)) /* Was [817-818] */
                    #if (__COUNTER__ <= (817+10)) /* Was [817-817] */
                      #define ORIGINAL_COUNTER 817
                      #define VERIFICATION_COUNTER 828
                      #define PREDICTED_COUNTER 829
                    #else /* Was [818-818] */
                      #define ORIGINAL_COUNTER 818
                      #define VERIFICATION_COUNTER 829
                      #define PREDICTED_COUNTER 830
                    #endif
                  #else /* Was [819-820] */
                    #if (__COUNTER__ <= (819+10)) /* Was [819-819] */
                      #define ORIGINAL_COUNTER 819
                      #define VERIFICATION_COUNTER 830
                      #define PREDICTED_COUNTER 831
                    #else /* Was [820-820] */
                      #define ORIGINAL_COUNTER 820
                      #define VERIFICATION_COUNTER 831
                      #define PREDICTED_COUNTER 832
                    #endif
                  #endif
                #else /* Was [821-824] */
                  #if (__COUNTER__ <= (822+9)) /* Was [821-822] */
                    #if (__COUNTER__ <= (821+10)) /* Was [821-821] */
                      #define ORIGINAL_COUNTER 821
                      #define VERIFICATION_COUNTER 832
                      #define PREDICTED_COUNTER 833
                    #else /* Was [822-822] */
                      #define ORIGINAL_COUNTER 822
                      #define VERIFICATION_COUNTER 833
                      #define PREDICTED_COUNTER 834
                    #endif
                  #else /* Was [823-824] */
                    #if (__COUNTER__ <= (823+10)) /* Was [823-823] */
                      #define ORIGINAL_COUNTER 823
                      #define VERIFICATION_COUNTER 834
                      #define PREDICTED_COUNTER 835
                    #else /* Was [824-824] */
                      #define ORIGINAL_COUNTER 824
                      #define VERIFICATION_COUNTER 835
                      #define PREDICTED_COUNTER 836
                    #endif
                  #endif
                #endif
              #else /* Was [825-832] */
                #if (__COUNTER__ <= (828+8)) /* Was [825-828] */
                  #if (__COUNTER__ <= (826+9)) /* Was [825-826] */
                    #if (__COUNTER__ <= (825+10)) /* Was [825-825] */
                      #define ORIGINAL_COUNTER 825
                      #define VERIFICATION_COUNTER 836
                      #define PREDICTED_COUNTER 837
                    #else /* Was [826-826] */
                      #define ORIGINAL_COUNTER 826
                      #define VERIFICATION_COUNTER 837
                      #define PREDICTED_COUNTER 838
                    #endif
                  #else /* Was [827-828] */
                    #if (__COUNTER__ <= (827+10)) /* Was [827-827] */
                      #define ORIGINAL_COUNTER 827
                      #define VERIFICATION_COUNTER 838
                      #define PREDICTED_COUNTER 839
                    #else /* Was [828-828] */
                      #define ORIGINAL_COUNTER 828
                      #define VERIFICATION_COUNTER 839
                      #define PREDICTED_COUNTER 840
                    #endif
                  #endif
                #else /* Was [829-832] */
                  #if (__COUNTER__ <= (830+9)) /* Was [829-830] */
                    #if (__COUNTER__ <= (829+10)) /* Was [829-829] */
                      #define ORIGINAL_COUNTER 829
                      #define VERIFICATION_COUNTER 840
                      #define PREDICTED_COUNTER 841
                    #else /* Was [830-830] */
                      #define ORIGINAL_COUNTER 830
                      #define VERIFICATION_COUNTER 841
                      #define PREDICTED_COUNTER 842
                    #endif
                  #else /* Was [831-832] */
                    #if (__COUNTER__ <= (831+10)) /* Was [831-831] */
                      #define ORIGINAL_COUNTER 831
                      #define VERIFICATION_COUNTER 842
                      #define PREDICTED_COUNTER 843
                    #else /* Was [832-832] */
                      #define ORIGINAL_COUNTER 832
                      #define VERIFICATION_COUNTER 843
                      #define PREDICTED_COUNTER 844
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #else /* Was [833-896] */
          #if (__COUNTER__ <= (864+5)) /* Was [833-864] */
            #if (__COUNTER__ <= (848+6)) /* Was [833-848] */
              #if (__COUNTER__ <= (840+7)) /* Was [833-840] */
                #if (__COUNTER__ <= (836+8)) /* Was [833-836] */
                  #if (__COUNTER__ <= (834+9)) /* Was [833-834] */
                    #if (__COUNTER__ <= (833+10)) /* Was [833-833] */
                      #define ORIGINAL_COUNTER 833
                      #define VERIFICATION_COUNTER 844
                      #define PREDICTED_COUNTER 845
                    #else /* Was [834-834] */
                      #define ORIGINAL_COUNTER 834
                      #define VERIFICATION_COUNTER 845
                      #define PREDICTED_COUNTER 846
                    #endif
                  #else /* Was [835-836] */
                    #if (__COUNTER__ <= (835+10)) /* Was [835-835] */
                      #define ORIGINAL_COUNTER 835
                      #define VERIFICATION_COUNTER 846
                      #define PREDICTED_COUNTER 847
                    #else /* Was [836-836] */
                      #define ORIGINAL_COUNTER 836
                      #define VERIFICATION_COUNTER 847
                      #define PREDICTED_COUNTER 848
                    #endif
                  #endif
                #else /* Was [837-840] */
                  #if (__COUNTER__ <= (838+9)) /* Was [837-838] */
                    #if (__COUNTER__ <= (837+10)) /* Was [837-837] */
                      #define ORIGINAL_COUNTER 837
                      #define VERIFICATION_COUNTER 848
                      #define PREDICTED_COUNTER 849
                    #else /* Was [838-838] */
                      #define ORIGINAL_COUNTER 838
                      #define VERIFICATION_COUNTER 849
                      #define PREDICTED_COUNTER 850
                    #endif
                  #else /* Was [839-840] */
                    #if (__COUNTER__ <= (839+10)) /* Was [839-839] */
                      #define ORIGINAL_COUNTER 839
                      #define VERIFICATION_COUNTER 850
                      #define PREDICTED_COUNTER 851
                    #else /* Was [840-840] */
                      #define ORIGINAL_COUNTER 840
                      #define VERIFICATION_COUNTER 851
                      #define PREDICTED_COUNTER 852
                    #endif
                  #endif
                #endif
              #else /* Was [841-848] */
                #if (__COUNTER__ <= (844+8)) /* Was [841-844] */
                  #if (__COUNTER__ <= (842+9)) /* Was [841-842] */
                    #if (__COUNTER__ <= (841+10)) /* Was [841-841] */
                      #define ORIGINAL_COUNTER 841
                      #define VERIFICATION_COUNTER 852
                      #define PREDICTED_COUNTER 853
                    #else /* Was [842-842] */
                      #define ORIGINAL_COUNTER 842
                      #define VERIFICATION_COUNTER 853
                      #define PREDICTED_COUNTER 854
                    #endif
                  #else /* Was [843-844] */
                    #if (__COUNTER__ <= (843+10)) /* Was [843-843] */
                      #define ORIGINAL_COUNTER 843
                      #define VERIFICATION_COUNTER 854
                      #define PREDICTED_COUNTER 855
                    #else /* Was [844-844] */
                      #define ORIGINAL_COUNTER 844
                      #define VERIFICATION_COUNTER 855
                      #define PREDICTED_COUNTER 856
                    #endif
                  #endif
                #else /* Was [845-848] */
                  #if (__COUNTER__ <= (846+9)) /* Was [845-846] */
                    #if (__COUNTER__ <= (845+10)) /* Was [845-845] */
                      #define ORIGINAL_COUNTER 845
                      #define VERIFICATION_COUNTER 856
                      #define PREDICTED_COUNTER 857
                    #else /* Was [846-846] */
                      #define ORIGINAL_COUNTER 846
                      #define VERIFICATION_COUNTER 857
                      #define PREDICTED_COUNTER 858
                    #endif
                  #else /* Was [847-848] */
                    #if (__COUNTER__ <= (847+10)) /* Was [847-847] */
                      #define ORIGINAL_COUNTER 847
                      #define VERIFICATION_COUNTER 858
                      #define PREDICTED_COUNTER 859
                    #else /* Was [848-848] */
                      #define ORIGINAL_COUNTER 848
                      #define VERIFICATION_COUNTER 859
                      #define PREDICTED_COUNTER 860
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [849-864] */
              #if (__COUNTER__ <= (856+7)) /* Was [849-856] */
                #if (__COUNTER__ <= (852+8)) /* Was [849-852] */
                  #if (__COUNTER__ <= (850+9)) /* Was [849-850] */
                    #if (__COUNTER__ <= (849+10)) /* Was [849-849] */
                      #define ORIGINAL_COUNTER 849
                      #define VERIFICATION_COUNTER 860
                      #define PREDICTED_COUNTER 861
                    #else /* Was [850-850] */
                      #define ORIGINAL_COUNTER 850
                      #define VERIFICATION_COUNTER 861
                      #define PREDICTED_COUNTER 862
                    #endif
                  #else /* Was [851-852] */
                    #if (__COUNTER__ <= (851+10)) /* Was [851-851] */
                      #define ORIGINAL_COUNTER 851
                      #define VERIFICATION_COUNTER 862
                      #define PREDICTED_COUNTER 863
                    #else /* Was [852-852] */
                      #define ORIGINAL_COUNTER 852
                      #define VERIFICATION_COUNTER 863
                      #define PREDICTED_COUNTER 864
                    #endif
                  #endif
                #else /* Was [853-856] */
                  #if (__COUNTER__ <= (854+9)) /* Was [853-854] */
                    #if (__COUNTER__ <= (853+10)) /* Was [853-853] */
                      #define ORIGINAL_COUNTER 853
                      #define VERIFICATION_COUNTER 864
                      #define PREDICTED_COUNTER 865
                    #else /* Was [854-854] */
                      #define ORIGINAL_COUNTER 854
                      #define VERIFICATION_COUNTER 865
                      #define PREDICTED_COUNTER 866
                    #endif
                  #else /* Was [855-856] */
                    #if (__COUNTER__ <= (855+10)) /* Was [855-855] */
                      #define ORIGINAL_COUNTER 855
                      #define VERIFICATION_COUNTER 866
                      #define PREDICTED_COUNTER 867
                    #else /* Was [856-856] */
                      #define ORIGINAL_COUNTER 856
                      #define VERIFICATION_COUNTER 867
                      #define PREDICTED_COUNTER 868
                    #endif
                  #endif
                #endif
              #else /* Was [857-864] */
                #if (__COUNTER__ <= (860+8)) /* Was [857-860] */
                  #if (__COUNTER__ <= (858+9)) /* Was [857-858] */
                    #if (__COUNTER__ <= (857+10)) /* Was [857-857] */
                      #define ORIGINAL_COUNTER 857
                      #define VERIFICATION_COUNTER 868
                      #define PREDICTED_COUNTER 869
                    #else /* Was [858-858] */
                      #define ORIGINAL_COUNTER 858
                      #define VERIFICATION_COUNTER 869
                      #define PREDICTED_COUNTER 870
                    #endif
                  #else /* Was [859-860] */
                    #if (__COUNTER__ <= (859+10)) /* Was [859-859] */
                      #define ORIGINAL_COUNTER 859
                      #define VERIFICATION_COUNTER 870
                      #define PREDICTED_COUNTER 871
                    #else /* Was [860-860] */
                      #define ORIGINAL_COUNTER 860
                      #define VERIFICATION_COUNTER 871
                      #define PREDICTED_COUNTER 872
                    #endif
                  #endif
                #else /* Was [861-864] */
                  #if (__COUNTER__ <= (862+9)) /* Was [861-862] */
                    #if (__COUNTER__ <= (861+10)) /* Was [861-861] */
                      #define ORIGINAL_COUNTER 861
                      #define VERIFICATION_COUNTER 872
                      #define PREDICTED_COUNTER 873
                    #else /* Was [862-862] */
                      #define ORIGINAL_COUNTER 862
                      #define VERIFICATION_COUNTER 873
                      #define PREDICTED_COUNTER 874
                    #endif
                  #else /* Was [863-864] */
                    #if (__COUNTER__ <= (863+10)) /* Was [863-863] */
                      #define ORIGINAL_COUNTER 863
                      #define VERIFICATION_COUNTER 874
                      #define PREDICTED_COUNTER 875
                    #else /* Was [864-864] */
                      #define ORIGINAL_COUNTER 864
                      #define VERIFICATION_COUNTER 875
                      #define PREDICTED_COUNTER 876
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [865-896] */
            #if (__COUNTER__ <= (880+6)) /* Was [865-880] */
              #if (__COUNTER__ <= (872+7)) /* Was [865-872] */
                #if (__COUNTER__ <= (868+8)) /* Was [865-868] */
                  #if (__COUNTER__ <= (866+9)) /* Was [865-866] */
                    #if (__COUNTER__ <= (865+10)) /* Was [865-865] */
                      #define ORIGINAL_COUNTER 865
                      #define VERIFICATION_COUNTER 876
                      #define PREDICTED_COUNTER 877
                    #else /* Was [866-866] */
                      #define ORIGINAL_COUNTER 866
                      #define VERIFICATION_COUNTER 877
                      #define PREDICTED_COUNTER 878
                    #endif
                  #else /* Was [867-868] */
                    #if (__COUNTER__ <= (867+10)) /* Was [867-867] */
                      #define ORIGINAL_COUNTER 867
                      #define VERIFICATION_COUNTER 878
                      #define PREDICTED_COUNTER 879
                    #else /* Was [868-868] */
                      #define ORIGINAL_COUNTER 868
                      #define VERIFICATION_COUNTER 879
                      #define PREDICTED_COUNTER 880
                    #endif
                  #endif
                #else /* Was [869-872] */
                  #if (__COUNTER__ <= (870+9)) /* Was [869-870] */
                    #if (__COUNTER__ <= (869+10)) /* Was [869-869] */
                      #define ORIGINAL_COUNTER 869
                      #define VERIFICATION_COUNTER 880
                      #define PREDICTED_COUNTER 881
                    #else /* Was [870-870] */
                      #define ORIGINAL_COUNTER 870
                      #define VERIFICATION_COUNTER 881
                      #define PREDICTED_COUNTER 882
                    #endif
                  #else /* Was [871-872] */
                    #if (__COUNTER__ <= (871+10)) /* Was [871-871] */
                      #define ORIGINAL_COUNTER 871
                      #define VERIFICATION_COUNTER 882
                      #define PREDICTED_COUNTER 883
                    #else /* Was [872-872] */
                      #define ORIGINAL_COUNTER 872
                      #define VERIFICATION_COUNTER 883
                      #define PREDICTED_COUNTER 884
                    #endif
                  #endif
                #endif
              #else /* Was [873-880] */
                #if (__COUNTER__ <= (876+8)) /* Was [873-876] */
                  #if (__COUNTER__ <= (874+9)) /* Was [873-874] */
                    #if (__COUNTER__ <= (873+10)) /* Was [873-873] */
                      #define ORIGINAL_COUNTER 873
                      #define VERIFICATION_COUNTER 884
                      #define PREDICTED_COUNTER 885
                    #else /* Was [874-874] */
                      #define ORIGINAL_COUNTER 874
                      #define VERIFICATION_COUNTER 885
                      #define PREDICTED_COUNTER 886
                    #endif
                  #else /* Was [875-876] */
                    #if (__COUNTER__ <= (875+10)) /* Was [875-875] */
                      #define ORIGINAL_COUNTER 875
                      #define VERIFICATION_COUNTER 886
                      #define PREDICTED_COUNTER 887
                    #else /* Was [876-876] */
                      #define ORIGINAL_COUNTER 876
                      #define VERIFICATION_COUNTER 887
                      #define PREDICTED_COUNTER 888
                    #endif
                  #endif
                #else /* Was [877-880] */
                  #if (__COUNTER__ <= (878+9)) /* Was [877-878] */
                    #if (__COUNTER__ <= (877+10)) /* Was [877-877] */
                      #define ORIGINAL_COUNTER 877
                      #define VERIFICATION_COUNTER 888
                      #define PREDICTED_COUNTER 889
                    #else /* Was [878-878] */
                      #define ORIGINAL_COUNTER 878
                      #define VERIFICATION_COUNTER 889
                      #define PREDICTED_COUNTER 890
                    #endif
                  #else /* Was [879-880] */
                    #if (__COUNTER__ <= (879+10)) /* Was [879-879] */
                      #define ORIGINAL_COUNTER 879
                      #define VERIFICATION_COUNTER 890
                      #define PREDICTED_COUNTER 891
                    #else /* Was [880-880] */
                      #define ORIGINAL_COUNTER 880
                      #define VERIFICATION_COUNTER 891
                      #define PREDICTED_COUNTER 892
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [881-896] */
              #if (__COUNTER__ <= (888+7)) /* Was [881-888] */
                #if (__COUNTER__ <= (884+8)) /* Was [881-884] */
                  #if (__COUNTER__ <= (882+9)) /* Was [881-882] */
                    #if (__COUNTER__ <= (881+10)) /* Was [881-881] */
                      #define ORIGINAL_COUNTER 881
                      #define VERIFICATION_COUNTER 892
                      #define PREDICTED_COUNTER 893
                    #else /* Was [882-882] */
                      #define ORIGINAL_COUNTER 882
                      #define VERIFICATION_COUNTER 893
                      #define PREDICTED_COUNTER 894
                    #endif
                  #else /* Was [883-884] */
                    #if (__COUNTER__ <= (883+10)) /* Was [883-883] */
                      #define ORIGINAL_COUNTER 883
                      #define VERIFICATION_COUNTER 894
                      #define PREDICTED_COUNTER 895
                    #else /* Was [884-884] */
                      #define ORIGINAL_COUNTER 884
                      #define VERIFICATION_COUNTER 895
                      #define PREDICTED_COUNTER 896
                    #endif
                  #endif
                #else /* Was [885-888] */
                  #if (__COUNTER__ <= (886+9)) /* Was [885-886] */
                    #if (__COUNTER__ <= (885+10)) /* Was [885-885] */
                      #define ORIGINAL_COUNTER 885
                      #define VERIFICATION_COUNTER 896
                      #define PREDICTED_COUNTER 897
                    #else /* Was [886-886] */
                      #define ORIGINAL_COUNTER 886
                      #define VERIFICATION_COUNTER 897
                      #define PREDICTED_COUNTER 898
                    #endif
                  #else /* Was [887-888] */
                    #if (__COUNTER__ <= (887+10)) /* Was [887-887] */
                      #define ORIGINAL_COUNTER 887
                      #define VERIFICATION_COUNTER 898
                      #define PREDICTED_COUNTER 899
                    #else /* Was [888-888] */
                      #define ORIGINAL_COUNTER 888
                      #define VERIFICATION_COUNTER 899
                      #define PREDICTED_COUNTER 900
                    #endif
                  #endif
                #endif
              #else /* Was [889-896] */
                #if (__COUNTER__ <= (892+8)) /* Was [889-892] */
                  #if (__COUNTER__ <= (890+9)) /* Was [889-890] */
                    #if (__COUNTER__ <= (889+10)) /* Was [889-889] */
                      #define ORIGINAL_COUNTER 889
                      #define VERIFICATION_COUNTER 900
                      #define PREDICTED_COUNTER 901
                    #else /* Was [890-890] */
                      #define ORIGINAL_COUNTER 890
                      #define VERIFICATION_COUNTER 901
                      #define PREDICTED_COUNTER 902
                    #endif
                  #else /* Was [891-892] */
                    #if (__COUNTER__ <= (891+10)) /* Was [891-891] */
                      #define ORIGINAL_COUNTER 891
                      #define VERIFICATION_COUNTER 902
                      #define PREDICTED_COUNTER 903
                    #else /* Was [892-892] */
                      #define ORIGINAL_COUNTER 892
                      #define VERIFICATION_COUNTER 903
                      #define PREDICTED_COUNTER 904
                    #endif
                  #endif
                #else /* Was [893-896] */
                  #if (__COUNTER__ <= (894+9)) /* Was [893-894] */
                    #if (__COUNTER__ <= (893+10)) /* Was [893-893] */
                      #define ORIGINAL_COUNTER 893
                      #define VERIFICATION_COUNTER 904
                      #define PREDICTED_COUNTER 905
                    #else /* Was [894-894] */
                      #define ORIGINAL_COUNTER 894
                      #define VERIFICATION_COUNTER 905
                      #define PREDICTED_COUNTER 906
                    #endif
                  #else /* Was [895-896] */
                    #if (__COUNTER__ <= (895+10)) /* Was [895-895] */
                      #define ORIGINAL_COUNTER 895
                      #define VERIFICATION_COUNTER 906
                      #define PREDICTED_COUNTER 907
                    #else /* Was [896-896] */
                      #define ORIGINAL_COUNTER 896
                      #define VERIFICATION_COUNTER 907
                      #define PREDICTED_COUNTER 908
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #endif
      #else /* Was [897-1024] */
        #if (__COUNTER__ <= (960+4)) /* Was [897-960] */
          #if (__COUNTER__ <= (928+5)) /* Was [897-928] */
            #if (__COUNTER__ <= (912+6)) /* Was [897-912] */
              #if (__COUNTER__ <= (904+7)) /* Was [897-904] */
                #if (__COUNTER__ <= (900+8)) /* Was [897-900] */
                  #if (__COUNTER__ <= (898+9)) /* Was [897-898] */
                    #if (__COUNTER__ <= (897+10)) /* Was [897-897] */
                      #define ORIGINAL_COUNTER 897
                      #define VERIFICATION_COUNTER 908
                      #define PREDICTED_COUNTER 909
                    #else /* Was [898-898] */
                      #define ORIGINAL_COUNTER 898
                      #define VERIFICATION_COUNTER 909
                      #define PREDICTED_COUNTER 910
                    #endif
                  #else /* Was [899-900] */
                    #if (__COUNTER__ <= (899+10)) /* Was [899-899] */
                      #define ORIGINAL_COUNTER 899
                      #define VERIFICATION_COUNTER 910
                      #define PREDICTED_COUNTER 911
                    #else /* Was [900-900] */
                      #define ORIGINAL_COUNTER 900
                      #define VERIFICATION_COUNTER 911
                      #define PREDICTED_COUNTER 912
                    #endif
                  #endif
                #else /* Was [901-904] */
                  #if (__COUNTER__ <= (902+9)) /* Was [901-902] */
                    #if (__COUNTER__ <= (901+10)) /* Was [901-901] */
                      #define ORIGINAL_COUNTER 901
                      #define VERIFICATION_COUNTER 912
                      #define PREDICTED_COUNTER 913
                    #else /* Was [902-902] */
                      #define ORIGINAL_COUNTER 902
                      #define VERIFICATION_COUNTER 913
                      #define PREDICTED_COUNTER 914
                    #endif
                  #else /* Was [903-904] */
                    #if (__COUNTER__ <= (903+10)) /* Was [903-903] */
                      #define ORIGINAL_COUNTER 903
                      #define VERIFICATION_COUNTER 914
                      #define PREDICTED_COUNTER 915
                    #else /* Was [904-904] */
                      #define ORIGINAL_COUNTER 904
                      #define VERIFICATION_COUNTER 915
                      #define PREDICTED_COUNTER 916
                    #endif
                  #endif
                #endif
              #else /* Was [905-912] */
                #if (__COUNTER__ <= (908+8)) /* Was [905-908] */
                  #if (__COUNTER__ <= (906+9)) /* Was [905-906] */
                    #if (__COUNTER__ <= (905+10)) /* Was [905-905] */
                      #define ORIGINAL_COUNTER 905
                      #define VERIFICATION_COUNTER 916
                      #define PREDICTED_COUNTER 917
                    #else /* Was [906-906] */
                      #define ORIGINAL_COUNTER 906
                      #define VERIFICATION_COUNTER 917
                      #define PREDICTED_COUNTER 918
                    #endif
                  #else /* Was [907-908] */
                    #if (__COUNTER__ <= (907+10)) /* Was [907-907] */
                      #define ORIGINAL_COUNTER 907
                      #define VERIFICATION_COUNTER 918
                      #define PREDICTED_COUNTER 919
                    #else /* Was [908-908] */
                      #define ORIGINAL_COUNTER 908
                      #define VERIFICATION_COUNTER 919
                      #define PREDICTED_COUNTER 920
                    #endif
                  #endif
                #else /* Was [909-912] */
                  #if (__COUNTER__ <= (910+9)) /* Was [909-910] */
                    #if (__COUNTER__ <= (909+10)) /* Was [909-909] */
                      #define ORIGINAL_COUNTER 909
                      #define VERIFICATION_COUNTER 920
                      #define PREDICTED_COUNTER 921
                    #else /* Was [910-910] */
                      #define ORIGINAL_COUNTER 910
                      #define VERIFICATION_COUNTER 921
                      #define PREDICTED_COUNTER 922
                    #endif
                  #else /* Was [911-912] */
                    #if (__COUNTER__ <= (911+10)) /* Was [911-911] */
                      #define ORIGINAL_COUNTER 911
                      #define VERIFICATION_COUNTER 922
                      #define PREDICTED_COUNTER 923
                    #else /* Was [912-912] */
                      #define ORIGINAL_COUNTER 912
                      #define VERIFICATION_COUNTER 923
                      #define PREDICTED_COUNTER 924
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [913-928] */
              #if (__COUNTER__ <= (920+7)) /* Was [913-920] */
                #if (__COUNTER__ <= (916+8)) /* Was [913-916] */
                  #if (__COUNTER__ <= (914+9)) /* Was [913-914] */
                    #if (__COUNTER__ <= (913+10)) /* Was [913-913] */
                      #define ORIGINAL_COUNTER 913
                      #define VERIFICATION_COUNTER 924
                      #define PREDICTED_COUNTER 925
                    #else /* Was [914-914] */
                      #define ORIGINAL_COUNTER 914
                      #define VERIFICATION_COUNTER 925
                      #define PREDICTED_COUNTER 926
                    #endif
                  #else /* Was [915-916] */
                    #if (__COUNTER__ <= (915+10)) /* Was [915-915] */
                      #define ORIGINAL_COUNTER 915
                      #define VERIFICATION_COUNTER 926
                      #define PREDICTED_COUNTER 927
                    #else /* Was [916-916] */
                      #define ORIGINAL_COUNTER 916
                      #define VERIFICATION_COUNTER 927
                      #define PREDICTED_COUNTER 928
                    #endif
                  #endif
                #else /* Was [917-920] */
                  #if (__COUNTER__ <= (918+9)) /* Was [917-918] */
                    #if (__COUNTER__ <= (917+10)) /* Was [917-917] */
                      #define ORIGINAL_COUNTER 917
                      #define VERIFICATION_COUNTER 928
                      #define PREDICTED_COUNTER 929
                    #else /* Was [918-918] */
                      #define ORIGINAL_COUNTER 918
                      #define VERIFICATION_COUNTER 929
                      #define PREDICTED_COUNTER 930
                    #endif
                  #else /* Was [919-920] */
                    #if (__COUNTER__ <= (919+10)) /* Was [919-919] */
                      #define ORIGINAL_COUNTER 919
                      #define VERIFICATION_COUNTER 930
                      #define PREDICTED_COUNTER 931
                    #else /* Was [920-920] */
                      #define ORIGINAL_COUNTER 920
                      #define VERIFICATION_COUNTER 931
                      #define PREDICTED_COUNTER 932
                    #endif
                  #endif
                #endif
              #else /* Was [921-928] */
                #if (__COUNTER__ <= (924+8)) /* Was [921-924] */
                  #if (__COUNTER__ <= (922+9)) /* Was [921-922] */
                    #if (__COUNTER__ <= (921+10)) /* Was [921-921] */
                      #define ORIGINAL_COUNTER 921
                      #define VERIFICATION_COUNTER 932
                      #define PREDICTED_COUNTER 933
                    #else /* Was [922-922] */
                      #define ORIGINAL_COUNTER 922
                      #define VERIFICATION_COUNTER 933
                      #define PREDICTED_COUNTER 934
                    #endif
                  #else /* Was [923-924] */
                    #if (__COUNTER__ <= (923+10)) /* Was [923-923] */
                      #define ORIGINAL_COUNTER 923
                      #define VERIFICATION_COUNTER 934
                      #define PREDICTED_COUNTER 935
                    #else /* Was [924-924] */
                      #define ORIGINAL_COUNTER 924
                      #define VERIFICATION_COUNTER 935
                      #define PREDICTED_COUNTER 936
                    #endif
                  #endif
                #else /* Was [925-928] */
                  #if (__COUNTER__ <= (926+9)) /* Was [925-926] */
                    #if (__COUNTER__ <= (925+10)) /* Was [925-925] */
                      #define ORIGINAL_COUNTER 925
                      #define VERIFICATION_COUNTER 936
                      #define PREDICTED_COUNTER 937
                    #else /* Was [926-926] */
                      #define ORIGINAL_COUNTER 926
                      #define VERIFICATION_COUNTER 937
                      #define PREDICTED_COUNTER 938
                    #endif
                  #else /* Was [927-928] */
                    #if (__COUNTER__ <= (927+10)) /* Was [927-927] */
                      #define ORIGINAL_COUNTER 927
                      #define VERIFICATION_COUNTER 938
                      #define PREDICTED_COUNTER 939
                    #else /* Was [928-928] */
                      #define ORIGINAL_COUNTER 928
                      #define VERIFICATION_COUNTER 939
                      #define PREDICTED_COUNTER 940
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [929-960] */
            #if (__COUNTER__ <= (944+6)) /* Was [929-944] */
              #if (__COUNTER__ <= (936+7)) /* Was [929-936] */
                #if (__COUNTER__ <= (932+8)) /* Was [929-932] */
                  #if (__COUNTER__ <= (930+9)) /* Was [929-930] */
                    #if (__COUNTER__ <= (929+10)) /* Was [929-929] */
                      #define ORIGINAL_COUNTER 929
                      #define VERIFICATION_COUNTER 940
                      #define PREDICTED_COUNTER 941
                    #else /* Was [930-930] */
                      #define ORIGINAL_COUNTER 930
                      #define VERIFICATION_COUNTER 941
                      #define PREDICTED_COUNTER 942
                    #endif
                  #else /* Was [931-932] */
                    #if (__COUNTER__ <= (931+10)) /* Was [931-931] */
                      #define ORIGINAL_COUNTER 931
                      #define VERIFICATION_COUNTER 942
                      #define PREDICTED_COUNTER 943
                    #else /* Was [932-932] */
                      #define ORIGINAL_COUNTER 932
                      #define VERIFICATION_COUNTER 943
                      #define PREDICTED_COUNTER 944
                    #endif
                  #endif
                #else /* Was [933-936] */
                  #if (__COUNTER__ <= (934+9)) /* Was [933-934] */
                    #if (__COUNTER__ <= (933+10)) /* Was [933-933] */
                      #define ORIGINAL_COUNTER 933
                      #define VERIFICATION_COUNTER 944
                      #define PREDICTED_COUNTER 945
                    #else /* Was [934-934] */
                      #define ORIGINAL_COUNTER 934
                      #define VERIFICATION_COUNTER 945
                      #define PREDICTED_COUNTER 946
                    #endif
                  #else /* Was [935-936] */
                    #if (__COUNTER__ <= (935+10)) /* Was [935-935] */
                      #define ORIGINAL_COUNTER 935
                      #define VERIFICATION_COUNTER 946
                      #define PREDICTED_COUNTER 947
                    #else /* Was [936-936] */
                      #define ORIGINAL_COUNTER 936
                      #define VERIFICATION_COUNTER 947
                      #define PREDICTED_COUNTER 948
                    #endif
                  #endif
                #endif
              #else /* Was [937-944] */
                #if (__COUNTER__ <= (940+8)) /* Was [937-940] */
                  #if (__COUNTER__ <= (938+9)) /* Was [937-938] */
                    #if (__COUNTER__ <= (937+10)) /* Was [937-937] */
                      #define ORIGINAL_COUNTER 937
                      #define VERIFICATION_COUNTER 948
                      #define PREDICTED_COUNTER 949
                    #else /* Was [938-938] */
                      #define ORIGINAL_COUNTER 938
                      #define VERIFICATION_COUNTER 949
                      #define PREDICTED_COUNTER 950
                    #endif
                  #else /* Was [939-940] */
                    #if (__COUNTER__ <= (939+10)) /* Was [939-939] */
                      #define ORIGINAL_COUNTER 939
                      #define VERIFICATION_COUNTER 950
                      #define PREDICTED_COUNTER 951
                    #else /* Was [940-940] */
                      #define ORIGINAL_COUNTER 940
                      #define VERIFICATION_COUNTER 951
                      #define PREDICTED_COUNTER 952
                    #endif
                  #endif
                #else /* Was [941-944] */
                  #if (__COUNTER__ <= (942+9)) /* Was [941-942] */
                    #if (__COUNTER__ <= (941+10)) /* Was [941-941] */
                      #define ORIGINAL_COUNTER 941
                      #define VERIFICATION_COUNTER 952
                      #define PREDICTED_COUNTER 953
                    #else /* Was [942-942] */
                      #define ORIGINAL_COUNTER 942
                      #define VERIFICATION_COUNTER 953
                      #define PREDICTED_COUNTER 954
                    #endif
                  #else /* Was [943-944] */
                    #if (__COUNTER__ <= (943+10)) /* Was [943-943] */
                      #define ORIGINAL_COUNTER 943
                      #define VERIFICATION_COUNTER 954
                      #define PREDICTED_COUNTER 955
                    #else /* Was [944-944] */
                      #define ORIGINAL_COUNTER 944
                      #define VERIFICATION_COUNTER 955
                      #define PREDICTED_COUNTER 956
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [945-960] */
              #if (__COUNTER__ <= (952+7)) /* Was [945-952] */
                #if (__COUNTER__ <= (948+8)) /* Was [945-948] */
                  #if (__COUNTER__ <= (946+9)) /* Was [945-946] */
                    #if (__COUNTER__ <= (945+10)) /* Was [945-945] */
                      #define ORIGINAL_COUNTER 945
                      #define VERIFICATION_COUNTER 956
                      #define PREDICTED_COUNTER 957
                    #else /* Was [946-946] */
                      #define ORIGINAL_COUNTER 946
                      #define VERIFICATION_COUNTER 957
                      #define PREDICTED_COUNTER 958
                    #endif
                  #else /* Was [947-948] */
                    #if (__COUNTER__ <= (947+10)) /* Was [947-947] */
                      #define ORIGINAL_COUNTER 947
                      #define VERIFICATION_COUNTER 958
                      #define PREDICTED_COUNTER 959
                    #else /* Was [948-948] */
                      #define ORIGINAL_COUNTER 948
                      #define VERIFICATION_COUNTER 959
                      #define PREDICTED_COUNTER 960
                    #endif
                  #endif
                #else /* Was [949-952] */
                  #if (__COUNTER__ <= (950+9)) /* Was [949-950] */
                    #if (__COUNTER__ <= (949+10)) /* Was [949-949] */
                      #define ORIGINAL_COUNTER 949
                      #define VERIFICATION_COUNTER 960
                      #define PREDICTED_COUNTER 961
                    #else /* Was [950-950] */
                      #define ORIGINAL_COUNTER 950
                      #define VERIFICATION_COUNTER 961
                      #define PREDICTED_COUNTER 962
                    #endif
                  #else /* Was [951-952] */
                    #if (__COUNTER__ <= (951+10)) /* Was [951-951] */
                      #define ORIGINAL_COUNTER 951
                      #define VERIFICATION_COUNTER 962
                      #define PREDICTED_COUNTER 963
                    #else /* Was [952-952] */
                      #define ORIGINAL_COUNTER 952
                      #define VERIFICATION_COUNTER 963
                      #define PREDICTED_COUNTER 964
                    #endif
                  #endif
                #endif
              #else /* Was [953-960] */
                #if (__COUNTER__ <= (956+8)) /* Was [953-956] */
                  #if (__COUNTER__ <= (954+9)) /* Was [953-954] */
                    #if (__COUNTER__ <= (953+10)) /* Was [953-953] */
                      #define ORIGINAL_COUNTER 953
                      #define VERIFICATION_COUNTER 964
                      #define PREDICTED_COUNTER 965
                    #else /* Was [954-954] */
                      #define ORIGINAL_COUNTER 954
                      #define VERIFICATION_COUNTER 965
                      #define PREDICTED_COUNTER 966
                    #endif
                  #else /* Was [955-956] */
                    #if (__COUNTER__ <= (955+10)) /* Was [955-955] */
                      #define ORIGINAL_COUNTER 955
                      #define VERIFICATION_COUNTER 966
                      #define PREDICTED_COUNTER 967
                    #else /* Was [956-956] */
                      #define ORIGINAL_COUNTER 956
                      #define VERIFICATION_COUNTER 967
                      #define PREDICTED_COUNTER 968
                    #endif
                  #endif
                #else /* Was [957-960] */
                  #if (__COUNTER__ <= (958+9)) /* Was [957-958] */
                    #if (__COUNTER__ <= (957+10)) /* Was [957-957] */
                      #define ORIGINAL_COUNTER 957
                      #define VERIFICATION_COUNTER 968
                      #define PREDICTED_COUNTER 969
                    #else /* Was [958-958] */
                      #define ORIGINAL_COUNTER 958
                      #define VERIFICATION_COUNTER 969
                      #define PREDICTED_COUNTER 970
                    #endif
                  #else /* Was [959-960] */
                    #if (__COUNTER__ <= (959+10)) /* Was [959-959] */
                      #define ORIGINAL_COUNTER 959
                      #define VERIFICATION_COUNTER 970
                      #define PREDICTED_COUNTER 971
                    #else /* Was [960-960] */
                      #define ORIGINAL_COUNTER 960
                      #define VERIFICATION_COUNTER 971
                      #define PREDICTED_COUNTER 972
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #else /* Was [961-1024] */
          #if (__COUNTER__ <= (992+5)) /* Was [961-992] */
            #if (__COUNTER__ <= (976+6)) /* Was [961-976] */
              #if (__COUNTER__ <= (968+7)) /* Was [961-968] */
                #if (__COUNTER__ <= (964+8)) /* Was [961-964] */
                  #if (__COUNTER__ <= (962+9)) /* Was [961-962] */
                    #if (__COUNTER__ <= (961+10)) /* Was [961-961] */
                      #define ORIGINAL_COUNTER 961
                      #define VERIFICATION_COUNTER 972
                      #define PREDICTED_COUNTER 973
                    #else /* Was [962-962] */
                      #define ORIGINAL_COUNTER 962
                      #define VERIFICATION_COUNTER 973
                      #define PREDICTED_COUNTER 974
                    #endif
                  #else /* Was [963-964] */
                    #if (__COUNTER__ <= (963+10)) /* Was [963-963] */
                      #define ORIGINAL_COUNTER 963
                      #define VERIFICATION_COUNTER 974
                      #define PREDICTED_COUNTER 975
                    #else /* Was [964-964] */
                      #define ORIGINAL_COUNTER 964
                      #define VERIFICATION_COUNTER 975
                      #define PREDICTED_COUNTER 976
                    #endif
                  #endif
                #else /* Was [965-968] */
                  #if (__COUNTER__ <= (966+9)) /* Was [965-966] */
                    #if (__COUNTER__ <= (965+10)) /* Was [965-965] */
                      #define ORIGINAL_COUNTER 965
                      #define VERIFICATION_COUNTER 976
                      #define PREDICTED_COUNTER 977
                    #else /* Was [966-966] */
                      #define ORIGINAL_COUNTER 966
                      #define VERIFICATION_COUNTER 977
                      #define PREDICTED_COUNTER 978
                    #endif
                  #else /* Was [967-968] */
                    #if (__COUNTER__ <= (967+10)) /* Was [967-967] */
                      #define ORIGINAL_COUNTER 967
                      #define VERIFICATION_COUNTER 978
                      #define PREDICTED_COUNTER 979
                    #else /* Was [968-968] */
                      #define ORIGINAL_COUNTER 968
                      #define VERIFICATION_COUNTER 979
                      #define PREDICTED_COUNTER 980
                    #endif
                  #endif
                #endif
              #else /* Was [969-976] */
                #if (__COUNTER__ <= (972+8)) /* Was [969-972] */
                  #if (__COUNTER__ <= (970+9)) /* Was [969-970] */
                    #if (__COUNTER__ <= (969+10)) /* Was [969-969] */
                      #define ORIGINAL_COUNTER 969
                      #define VERIFICATION_COUNTER 980
                      #define PREDICTED_COUNTER 981
                    #else /* Was [970-970] */
                      #define ORIGINAL_COUNTER 970
                      #define VERIFICATION_COUNTER 981
                      #define PREDICTED_COUNTER 982
                    #endif
                  #else /* Was [971-972] */
                    #if (__COUNTER__ <= (971+10)) /* Was [971-971] */
                      #define ORIGINAL_COUNTER 971
                      #define VERIFICATION_COUNTER 982
                      #define PREDICTED_COUNTER 983
                    #else /* Was [972-972] */
                      #define ORIGINAL_COUNTER 972
                      #define VERIFICATION_COUNTER 983
                      #define PREDICTED_COUNTER 984
                    #endif
                  #endif
                #else /* Was [973-976] */
                  #if (__COUNTER__ <= (974+9)) /* Was [973-974] */
                    #if (__COUNTER__ <= (973+10)) /* Was [973-973] */
                      #define ORIGINAL_COUNTER 973
                      #define VERIFICATION_COUNTER 984
                      #define PREDICTED_COUNTER 985
                    #else /* Was [974-974] */
                      #define ORIGINAL_COUNTER 974
                      #define VERIFICATION_COUNTER 985
                      #define PREDICTED_COUNTER 986
                    #endif
                  #else /* Was [975-976] */
                    #if (__COUNTER__ <= (975+10)) /* Was [975-975] */
                      #define ORIGINAL_COUNTER 975
                      #define VERIFICATION_COUNTER 986
                      #define PREDICTED_COUNTER 987
                    #else /* Was [976-976] */
                      #define ORIGINAL_COUNTER 976
                      #define VERIFICATION_COUNTER 987
                      #define PREDICTED_COUNTER 988
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [977-992] */
              #if (__COUNTER__ <= (984+7)) /* Was [977-984] */
                #if (__COUNTER__ <= (980+8)) /* Was [977-980] */
                  #if (__COUNTER__ <= (978+9)) /* Was [977-978] */
                    #if (__COUNTER__ <= (977+10)) /* Was [977-977] */
                      #define ORIGINAL_COUNTER 977
                      #define VERIFICATION_COUNTER 988
                      #define PREDICTED_COUNTER 989
                    #else /* Was [978-978] */
                      #define ORIGINAL_COUNTER 978
                      #define VERIFICATION_COUNTER 989
                      #define PREDICTED_COUNTER 990
                    #endif
                  #else /* Was [979-980] */
                    #if (__COUNTER__ <= (979+10)) /* Was [979-979] */
                      #define ORIGINAL_COUNTER 979
                      #define VERIFICATION_COUNTER 990
                      #define PREDICTED_COUNTER 991
                    #else /* Was [980-980] */
                      #define ORIGINAL_COUNTER 980
                      #define VERIFICATION_COUNTER 991
                      #define PREDICTED_COUNTER 992
                    #endif
                  #endif
                #else /* Was [981-984] */
                  #if (__COUNTER__ <= (982+9)) /* Was [981-982] */
                    #if (__COUNTER__ <= (981+10)) /* Was [981-981] */
                      #define ORIGINAL_COUNTER 981
                      #define VERIFICATION_COUNTER 992
                      #define PREDICTED_COUNTER 993
                    #else /* Was [982-982] */
                      #define ORIGINAL_COUNTER 982
                      #define VERIFICATION_COUNTER 993
                      #define PREDICTED_COUNTER 994
                    #endif
                  #else /* Was [983-984] */
                    #if (__COUNTER__ <= (983+10)) /* Was [983-983] */
                      #define ORIGINAL_COUNTER 983
                      #define VERIFICATION_COUNTER 994
                      #define PREDICTED_COUNTER 995
                    #else /* Was [984-984] */
                      #define ORIGINAL_COUNTER 984
                      #define VERIFICATION_COUNTER 995
                      #define PREDICTED_COUNTER 996
                    #endif
                  #endif
                #endif
              #else /* Was [985-992] */
                #if (__COUNTER__ <= (988+8)) /* Was [985-988] */
                  #if (__COUNTER__ <= (986+9)) /* Was [985-986] */
                    #if (__COUNTER__ <= (985+10)) /* Was [985-985] */
                      #define ORIGINAL_COUNTER 985
                      #define VERIFICATION_COUNTER 996
                      #define PREDICTED_COUNTER 997
                    #else /* Was [986-986] */
                      #define ORIGINAL_COUNTER 986
                      #define VERIFICATION_COUNTER 997
                      #define PREDICTED_COUNTER 998
                    #endif
                  #else /* Was [987-988] */
                    #if (__COUNTER__ <= (987+10)) /* Was [987-987] */
                      #define ORIGINAL_COUNTER 987
                      #define VERIFICATION_COUNTER 998
                      #define PREDICTED_COUNTER 999
                    #else /* Was [988-988] */
                      #define ORIGINAL_COUNTER 988
                      #define VERIFICATION_COUNTER 999
                      #define PREDICTED_COUNTER 1000
                    #endif
                  #endif
                #else /* Was [989-992] */
                  #if (__COUNTER__ <= (990+9)) /* Was [989-990] */
                    #if (__COUNTER__ <= (989+10)) /* Was [989-989] */
                      #define ORIGINAL_COUNTER 989
                      #define VERIFICATION_COUNTER 1000
                      #define PREDICTED_COUNTER 1001
                    #else /* Was [990-990] */
                      #define ORIGINAL_COUNTER 990
                      #define VERIFICATION_COUNTER 1001
                      #define PREDICTED_COUNTER 1002
                    #endif
                  #else /* Was [991-992] */
                    #if (__COUNTER__ <= (991+10)) /* Was [991-991] */
                      #define ORIGINAL_COUNTER 991
                      #define VERIFICATION_COUNTER 1002
                      #define PREDICTED_COUNTER 1003
                    #else /* Was [992-992] */
                      #define ORIGINAL_COUNTER 992
                      #define VERIFICATION_COUNTER 1003
                      #define PREDICTED_COUNTER 1004
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #else /* Was [993-1024] */
            #if (__COUNTER__ <= (1008+6)) /* Was [993-1008] */
              #if (__COUNTER__ <= (1000+7)) /* Was [993-1000] */
                #if (__COUNTER__ <= (996+8)) /* Was [993-996] */
                  #if (__COUNTER__ <= (994+9)) /* Was [993-994] */
                    #if (__COUNTER__ <= (993+10)) /* Was [993-993] */
                      #define ORIGINAL_COUNTER 993
                      #define VERIFICATION_COUNTER 1004
                      #define PREDICTED_COUNTER 1005
                    #else /* Was [994-994] */
                      #define ORIGINAL_COUNTER 994
                      #define VERIFICATION_COUNTER 1005
                      #define PREDICTED_COUNTER 1006
                    #endif
                  #else /* Was [995-996] */
                    #if (__COUNTER__ <= (995+10)) /* Was [995-995] */
                      #define ORIGINAL_COUNTER 995
                      #define VERIFICATION_COUNTER 1006
                      #define PREDICTED_COUNTER 1007
                    #else /* Was [996-996] */
                      #define ORIGINAL_COUNTER 996
                      #define VERIFICATION_COUNTER 1007
                      #define PREDICTED_COUNTER 1008
                    #endif
                  #endif
                #else /* Was [997-1000] */
                  #if (__COUNTER__ <= (998+9)) /* Was [997-998] */
                    #if (__COUNTER__ <= (997+10)) /* Was [997-997] */
                      #define ORIGINAL_COUNTER 997
                      #define VERIFICATION_COUNTER 1008
                      #define PREDICTED_COUNTER 1009
                    #else /* Was [998-998] */
                      #define ORIGINAL_COUNTER 998
                      #define VERIFICATION_COUNTER 1009
                      #define PREDICTED_COUNTER 1010
                    #endif
                  #else /* Was [999-1000] */
                    #if (__COUNTER__ <= (999+10)) /* Was [999-999] */
                      #define ORIGINAL_COUNTER 999
                      #define VERIFICATION_COUNTER 1010
                      #define PREDICTED_COUNTER 1011
                    #else /* Was [1000-1000] */
                      #define ORIGINAL_COUNTER 1000
                      #define VERIFICATION_COUNTER 1011
                      #define PREDICTED_COUNTER 1012
                    #endif
                  #endif
                #endif
              #else /* Was [1001-1008] */
                #if (__COUNTER__ <= (1004+8)) /* Was [1001-1004] */
                  #if (__COUNTER__ <= (1002+9)) /* Was [1001-1002] */
                    #if (__COUNTER__ <= (1001+10)) /* Was [1001-1001] */
                      #define ORIGINAL_COUNTER 1001
                      #define VERIFICATION_COUNTER 1012
                      #define PREDICTED_COUNTER 1013
                    #else /* Was [1002-1002] */
                      #define ORIGINAL_COUNTER 1002
                      #define VERIFICATION_COUNTER 1013
                      #define PREDICTED_COUNTER 1014
                    #endif
                  #else /* Was [1003-1004] */
                    #if (__COUNTER__ <= (1003+10)) /* Was [1003-1003] */
                      #define ORIGINAL_COUNTER 1003
                      #define VERIFICATION_COUNTER 1014
                      #define PREDICTED_COUNTER 1015
                    #else /* Was [1004-1004] */
                      #define ORIGINAL_COUNTER 1004
                      #define VERIFICATION_COUNTER 1015
                      #define PREDICTED_COUNTER 1016
                    #endif
                  #endif
                #else /* Was [1005-1008] */
                  #if (__COUNTER__ <= (1006+9)) /* Was [1005-1006] */
                    #if (__COUNTER__ <= (1005+10)) /* Was [1005-1005] */
                      #define ORIGINAL_COUNTER 1005
                      #define VERIFICATION_COUNTER 1016
                      #define PREDICTED_COUNTER 1017
                    #else /* Was [1006-1006] */
                      #define ORIGINAL_COUNTER 1006
                      #define VERIFICATION_COUNTER 1017
                      #define PREDICTED_COUNTER 1018
                    #endif
                  #else /* Was [1007-1008] */
                    #if (__COUNTER__ <= (1007+10)) /* Was [1007-1007] */
                      #define ORIGINAL_COUNTER 1007
                      #define VERIFICATION_COUNTER 1018
                      #define PREDICTED_COUNTER 1019
                    #else /* Was [1008-1008] */
                      #define ORIGINAL_COUNTER 1008
                      #define VERIFICATION_COUNTER 1019
                      #define PREDICTED_COUNTER 1020
                    #endif
                  #endif
                #endif
              #endif
            #else /* Was [1009-1024] */
              #if (__COUNTER__ <= (1016+7)) /* Was [1009-1016] */
                #if (__COUNTER__ <= (1012+8)) /* Was [1009-1012] */
                  #if (__COUNTER__ <= (1010+9)) /* Was [1009-1010] */
                    #if (__COUNTER__ <= (1009+10)) /* Was [1009-1009] */
                      #define ORIGINAL_COUNTER 1009
                      #define VERIFICATION_COUNTER 1020
                      #define PREDICTED_COUNTER 1021
                    #else /* Was [1010-1010] */
                      #define ORIGINAL_COUNTER 1010
                      #define VERIFICATION_COUNTER 1021
                      #define PREDICTED_COUNTER 1022
                    #endif
                  #else /* Was [1011-1012] */
                    #if (__COUNTER__ <= (1011+10)) /* Was [1011-1011] */
                      #define ORIGINAL_COUNTER 1011
                      #define VERIFICATION_COUNTER 1022
                      #define PREDICTED_COUNTER 1023
                    #else /* Was [1012-1012] */
                      #define ORIGINAL_COUNTER 1012
                      #define VERIFICATION_COUNTER 1023
                      #define PREDICTED_COUNTER 1024
                    #endif
                  #endif
                #else /* Was [1013-1016] */
                  #if (__COUNTER__ <= (1014+9)) /* Was [1013-1014] */
                    #if (__COUNTER__ <= (1013+10)) /* Was [1013-1013] */
                      #define ORIGINAL_COUNTER 1013
                      #define VERIFICATION_COUNTER 1024
                      #define PREDICTED_COUNTER 1025
                    #else /* Was [1014-1014] */
                      #define ORIGINAL_COUNTER 1014
                      #define VERIFICATION_COUNTER 1025
                      #define PREDICTED_COUNTER 1026
                    #endif
                  #else /* Was [1015-1016] */
                    #if (__COUNTER__ <= (1015+10)) /* Was [1015-1015] */
                      #define ORIGINAL_COUNTER 1015
                      #define VERIFICATION_COUNTER 1026
                      #define PREDICTED_COUNTER 1027
                    #else /* Was [1016-1016] */
                      #define ORIGINAL_COUNTER 1016
                      #define VERIFICATION_COUNTER 1027
                      #define PREDICTED_COUNTER 1028
                    #endif
                  #endif
                #endif
              #else /* Was [1017-1024] */
                #if (__COUNTER__ <= (1020+8)) /* Was [1017-1020] */
                  #if (__COUNTER__ <= (1018+9)) /* Was [1017-1018] */
                    #if (__COUNTER__ <= (1017+10)) /* Was [1017-1017] */
                      #define ORIGINAL_COUNTER 1017
                      #define VERIFICATION_COUNTER 1028
                      #define PREDICTED_COUNTER 1029
                    #else /* Was [1018-1018] */
                      #define ORIGINAL_COUNTER 1018
                      #define VERIFICATION_COUNTER 1029
                      #define PREDICTED_COUNTER 1030
                    #endif
                  #else /* Was [1019-1020] */
                    #if (__COUNTER__ <= (1019+10)) /* Was [1019-1019] */
                      #define ORIGINAL_COUNTER 1019
                      #define VERIFICATION_COUNTER 1030
                      #define PREDICTED_COUNTER 1031
                    #else /* Was [1020-1020] */
                      #define ORIGINAL_COUNTER 1020
                      #define VERIFICATION_COUNTER 1031
                      #define PREDICTED_COUNTER 1032
                    #endif
                  #endif
                #else /* Was [1021-1024] */
                  #if (__COUNTER__ <= (1022+9)) /* Was [1021-1022] */
                    #if (__COUNTER__ <= (1021+10)) /* Was [1021-1021] */
                      #define ORIGINAL_COUNTER 1021
                      #define VERIFICATION_COUNTER 1032
                      #define PREDICTED_COUNTER 1033
                    #else /* Was [1022-1022] */
                      #define ORIGINAL_COUNTER 1022
                      #define VERIFICATION_COUNTER 1033
                      #define PREDICTED_COUNTER 1034
                    #endif
                  #else /* Was [1023-1024] */
                    #if (__COUNTER__ <= (1023+10)) /* Was [1023-1023] */
                      #define ORIGINAL_COUNTER 1023
                      #define VERIFICATION_COUNTER 1034
                      #define PREDICTED_COUNTER 1035
                    #else /* Was [1024-1024] */
                      #define ORIGINAL_COUNTER 1024
                      #define VERIFICATION_COUNTER 1035
                      #define PREDICTED_COUNTER 1036
                    #endif
                  #endif
                #endif
              #endif
            #endif
          #endif
        #endif
      #endif
    #endif
  #endif
  #if (VERIFICATION_COUNTER != __COUNTER__)
    #error "Verification check failed"
  #endif
#endif
#ifdef ORIGINAL_COUNTER
  #undef ORIGINAL_COUNTER
#endif
#ifdef VERIFICATION_COUNTER
  #undef VERIFICATION_COUNTER
#endif

#ifndef PREDICTED_COUNTER
  #error "Set PREDICTED_COUNTER before including this file"
#endif
#if (PREDICTED_COUNTER >= 1024)
  #error "Counter too high. Consider regenerating file"
#endif
#ifdef TEST_COUNT_0
  #undef TEST_COUNT_0
#endif
#if (PREDICTED_COUNTER == 0)
  #define TEST_COUNT_0(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_0(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1
  #undef TEST_COUNT_1
#endif
#if (PREDICTED_COUNTER == 1)
  #define TEST_COUNT_1(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_2
  #undef TEST_COUNT_2
#endif
#if (PREDICTED_COUNTER == 2)
  #define TEST_COUNT_2(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_2(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_3
  #undef TEST_COUNT_3
#endif
#if (PREDICTED_COUNTER == 3)
  #define TEST_COUNT_3(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_3(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_4
  #undef TEST_COUNT_4
#endif
#if (PREDICTED_COUNTER == 4)
  #define TEST_COUNT_4(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_4(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_5
  #undef TEST_COUNT_5
#endif
#if (PREDICTED_COUNTER == 5)
  #define TEST_COUNT_5(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_5(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_6
  #undef TEST_COUNT_6
#endif
#if (PREDICTED_COUNTER == 6)
  #define TEST_COUNT_6(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_6(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_7
  #undef TEST_COUNT_7
#endif
#if (PREDICTED_COUNTER == 7)
  #define TEST_COUNT_7(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_7(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_8
  #undef TEST_COUNT_8
#endif
#if (PREDICTED_COUNTER == 8)
  #define TEST_COUNT_8(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_8(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_9
  #undef TEST_COUNT_9
#endif
#if (PREDICTED_COUNTER == 9)
  #define TEST_COUNT_9(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_9(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_10
  #undef TEST_COUNT_10
#endif
#if (PREDICTED_COUNTER == 10)
  #define TEST_COUNT_10(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_10(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_11
  #undef TEST_COUNT_11
#endif
#if (PREDICTED_COUNTER == 11)
  #define TEST_COUNT_11(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_11(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_12
  #undef TEST_COUNT_12
#endif
#if (PREDICTED_COUNTER == 12)
  #define TEST_COUNT_12(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_12(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_13
  #undef TEST_COUNT_13
#endif
#if (PREDICTED_COUNTER == 13)
  #define TEST_COUNT_13(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_13(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_14
  #undef TEST_COUNT_14
#endif
#if (PREDICTED_COUNTER == 14)
  #define TEST_COUNT_14(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_14(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_15
  #undef TEST_COUNT_15
#endif
#if (PREDICTED_COUNTER == 15)
  #define TEST_COUNT_15(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_15(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_16
  #undef TEST_COUNT_16
#endif
#if (PREDICTED_COUNTER == 16)
  #define TEST_COUNT_16(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_16(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_17
  #undef TEST_COUNT_17
#endif
#if (PREDICTED_COUNTER == 17)
  #define TEST_COUNT_17(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_17(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_18
  #undef TEST_COUNT_18
#endif
#if (PREDICTED_COUNTER == 18)
  #define TEST_COUNT_18(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_18(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_19
  #undef TEST_COUNT_19
#endif
#if (PREDICTED_COUNTER == 19)
  #define TEST_COUNT_19(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_19(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_20
  #undef TEST_COUNT_20
#endif
#if (PREDICTED_COUNTER == 20)
  #define TEST_COUNT_20(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_20(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_21
  #undef TEST_COUNT_21
#endif
#if (PREDICTED_COUNTER == 21)
  #define TEST_COUNT_21(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_21(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_22
  #undef TEST_COUNT_22
#endif
#if (PREDICTED_COUNTER == 22)
  #define TEST_COUNT_22(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_22(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_23
  #undef TEST_COUNT_23
#endif
#if (PREDICTED_COUNTER == 23)
  #define TEST_COUNT_23(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_23(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_24
  #undef TEST_COUNT_24
#endif
#if (PREDICTED_COUNTER == 24)
  #define TEST_COUNT_24(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_24(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_25
  #undef TEST_COUNT_25
#endif
#if (PREDICTED_COUNTER == 25)
  #define TEST_COUNT_25(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_25(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_26
  #undef TEST_COUNT_26
#endif
#if (PREDICTED_COUNTER == 26)
  #define TEST_COUNT_26(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_26(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_27
  #undef TEST_COUNT_27
#endif
#if (PREDICTED_COUNTER == 27)
  #define TEST_COUNT_27(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_27(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_28
  #undef TEST_COUNT_28
#endif
#if (PREDICTED_COUNTER == 28)
  #define TEST_COUNT_28(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_28(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_29
  #undef TEST_COUNT_29
#endif
#if (PREDICTED_COUNTER == 29)
  #define TEST_COUNT_29(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_29(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_30
  #undef TEST_COUNT_30
#endif
#if (PREDICTED_COUNTER == 30)
  #define TEST_COUNT_30(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_30(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_31
  #undef TEST_COUNT_31
#endif
#if (PREDICTED_COUNTER == 31)
  #define TEST_COUNT_31(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_31(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_32
  #undef TEST_COUNT_32
#endif
#if (PREDICTED_COUNTER == 32)
  #define TEST_COUNT_32(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_32(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_33
  #undef TEST_COUNT_33
#endif
#if (PREDICTED_COUNTER == 33)
  #define TEST_COUNT_33(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_33(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_34
  #undef TEST_COUNT_34
#endif
#if (PREDICTED_COUNTER == 34)
  #define TEST_COUNT_34(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_34(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_35
  #undef TEST_COUNT_35
#endif
#if (PREDICTED_COUNTER == 35)
  #define TEST_COUNT_35(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_35(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_36
  #undef TEST_COUNT_36
#endif
#if (PREDICTED_COUNTER == 36)
  #define TEST_COUNT_36(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_36(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_37
  #undef TEST_COUNT_37
#endif
#if (PREDICTED_COUNTER == 37)
  #define TEST_COUNT_37(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_37(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_38
  #undef TEST_COUNT_38
#endif
#if (PREDICTED_COUNTER == 38)
  #define TEST_COUNT_38(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_38(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_39
  #undef TEST_COUNT_39
#endif
#if (PREDICTED_COUNTER == 39)
  #define TEST_COUNT_39(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_39(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_40
  #undef TEST_COUNT_40
#endif
#if (PREDICTED_COUNTER == 40)
  #define TEST_COUNT_40(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_40(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_41
  #undef TEST_COUNT_41
#endif
#if (PREDICTED_COUNTER == 41)
  #define TEST_COUNT_41(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_41(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_42
  #undef TEST_COUNT_42
#endif
#if (PREDICTED_COUNTER == 42)
  #define TEST_COUNT_42(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_42(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_43
  #undef TEST_COUNT_43
#endif
#if (PREDICTED_COUNTER == 43)
  #define TEST_COUNT_43(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_43(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_44
  #undef TEST_COUNT_44
#endif
#if (PREDICTED_COUNTER == 44)
  #define TEST_COUNT_44(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_44(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_45
  #undef TEST_COUNT_45
#endif
#if (PREDICTED_COUNTER == 45)
  #define TEST_COUNT_45(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_45(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_46
  #undef TEST_COUNT_46
#endif
#if (PREDICTED_COUNTER == 46)
  #define TEST_COUNT_46(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_46(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_47
  #undef TEST_COUNT_47
#endif
#if (PREDICTED_COUNTER == 47)
  #define TEST_COUNT_47(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_47(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_48
  #undef TEST_COUNT_48
#endif
#if (PREDICTED_COUNTER == 48)
  #define TEST_COUNT_48(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_48(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_49
  #undef TEST_COUNT_49
#endif
#if (PREDICTED_COUNTER == 49)
  #define TEST_COUNT_49(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_49(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_50
  #undef TEST_COUNT_50
#endif
#if (PREDICTED_COUNTER == 50)
  #define TEST_COUNT_50(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_50(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_51
  #undef TEST_COUNT_51
#endif
#if (PREDICTED_COUNTER == 51)
  #define TEST_COUNT_51(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_51(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_52
  #undef TEST_COUNT_52
#endif
#if (PREDICTED_COUNTER == 52)
  #define TEST_COUNT_52(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_52(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_53
  #undef TEST_COUNT_53
#endif
#if (PREDICTED_COUNTER == 53)
  #define TEST_COUNT_53(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_53(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_54
  #undef TEST_COUNT_54
#endif
#if (PREDICTED_COUNTER == 54)
  #define TEST_COUNT_54(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_54(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_55
  #undef TEST_COUNT_55
#endif
#if (PREDICTED_COUNTER == 55)
  #define TEST_COUNT_55(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_55(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_56
  #undef TEST_COUNT_56
#endif
#if (PREDICTED_COUNTER == 56)
  #define TEST_COUNT_56(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_56(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_57
  #undef TEST_COUNT_57
#endif
#if (PREDICTED_COUNTER == 57)
  #define TEST_COUNT_57(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_57(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_58
  #undef TEST_COUNT_58
#endif
#if (PREDICTED_COUNTER == 58)
  #define TEST_COUNT_58(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_58(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_59
  #undef TEST_COUNT_59
#endif
#if (PREDICTED_COUNTER == 59)
  #define TEST_COUNT_59(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_59(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_60
  #undef TEST_COUNT_60
#endif
#if (PREDICTED_COUNTER == 60)
  #define TEST_COUNT_60(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_60(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_61
  #undef TEST_COUNT_61
#endif
#if (PREDICTED_COUNTER == 61)
  #define TEST_COUNT_61(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_61(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_62
  #undef TEST_COUNT_62
#endif
#if (PREDICTED_COUNTER == 62)
  #define TEST_COUNT_62(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_62(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_63
  #undef TEST_COUNT_63
#endif
#if (PREDICTED_COUNTER == 63)
  #define TEST_COUNT_63(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_63(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_64
  #undef TEST_COUNT_64
#endif
#if (PREDICTED_COUNTER == 64)
  #define TEST_COUNT_64(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_64(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_65
  #undef TEST_COUNT_65
#endif
#if (PREDICTED_COUNTER == 65)
  #define TEST_COUNT_65(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_65(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_66
  #undef TEST_COUNT_66
#endif
#if (PREDICTED_COUNTER == 66)
  #define TEST_COUNT_66(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_66(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_67
  #undef TEST_COUNT_67
#endif
#if (PREDICTED_COUNTER == 67)
  #define TEST_COUNT_67(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_67(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_68
  #undef TEST_COUNT_68
#endif
#if (PREDICTED_COUNTER == 68)
  #define TEST_COUNT_68(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_68(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_69
  #undef TEST_COUNT_69
#endif
#if (PREDICTED_COUNTER == 69)
  #define TEST_COUNT_69(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_69(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_70
  #undef TEST_COUNT_70
#endif
#if (PREDICTED_COUNTER == 70)
  #define TEST_COUNT_70(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_70(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_71
  #undef TEST_COUNT_71
#endif
#if (PREDICTED_COUNTER == 71)
  #define TEST_COUNT_71(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_71(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_72
  #undef TEST_COUNT_72
#endif
#if (PREDICTED_COUNTER == 72)
  #define TEST_COUNT_72(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_72(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_73
  #undef TEST_COUNT_73
#endif
#if (PREDICTED_COUNTER == 73)
  #define TEST_COUNT_73(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_73(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_74
  #undef TEST_COUNT_74
#endif
#if (PREDICTED_COUNTER == 74)
  #define TEST_COUNT_74(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_74(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_75
  #undef TEST_COUNT_75
#endif
#if (PREDICTED_COUNTER == 75)
  #define TEST_COUNT_75(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_75(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_76
  #undef TEST_COUNT_76
#endif
#if (PREDICTED_COUNTER == 76)
  #define TEST_COUNT_76(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_76(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_77
  #undef TEST_COUNT_77
#endif
#if (PREDICTED_COUNTER == 77)
  #define TEST_COUNT_77(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_77(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_78
  #undef TEST_COUNT_78
#endif
#if (PREDICTED_COUNTER == 78)
  #define TEST_COUNT_78(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_78(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_79
  #undef TEST_COUNT_79
#endif
#if (PREDICTED_COUNTER == 79)
  #define TEST_COUNT_79(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_79(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_80
  #undef TEST_COUNT_80
#endif
#if (PREDICTED_COUNTER == 80)
  #define TEST_COUNT_80(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_80(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_81
  #undef TEST_COUNT_81
#endif
#if (PREDICTED_COUNTER == 81)
  #define TEST_COUNT_81(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_81(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_82
  #undef TEST_COUNT_82
#endif
#if (PREDICTED_COUNTER == 82)
  #define TEST_COUNT_82(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_82(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_83
  #undef TEST_COUNT_83
#endif
#if (PREDICTED_COUNTER == 83)
  #define TEST_COUNT_83(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_83(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_84
  #undef TEST_COUNT_84
#endif
#if (PREDICTED_COUNTER == 84)
  #define TEST_COUNT_84(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_84(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_85
  #undef TEST_COUNT_85
#endif
#if (PREDICTED_COUNTER == 85)
  #define TEST_COUNT_85(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_85(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_86
  #undef TEST_COUNT_86
#endif
#if (PREDICTED_COUNTER == 86)
  #define TEST_COUNT_86(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_86(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_87
  #undef TEST_COUNT_87
#endif
#if (PREDICTED_COUNTER == 87)
  #define TEST_COUNT_87(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_87(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_88
  #undef TEST_COUNT_88
#endif
#if (PREDICTED_COUNTER == 88)
  #define TEST_COUNT_88(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_88(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_89
  #undef TEST_COUNT_89
#endif
#if (PREDICTED_COUNTER == 89)
  #define TEST_COUNT_89(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_89(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_90
  #undef TEST_COUNT_90
#endif
#if (PREDICTED_COUNTER == 90)
  #define TEST_COUNT_90(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_90(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_91
  #undef TEST_COUNT_91
#endif
#if (PREDICTED_COUNTER == 91)
  #define TEST_COUNT_91(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_91(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_92
  #undef TEST_COUNT_92
#endif
#if (PREDICTED_COUNTER == 92)
  #define TEST_COUNT_92(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_92(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_93
  #undef TEST_COUNT_93
#endif
#if (PREDICTED_COUNTER == 93)
  #define TEST_COUNT_93(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_93(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_94
  #undef TEST_COUNT_94
#endif
#if (PREDICTED_COUNTER == 94)
  #define TEST_COUNT_94(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_94(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_95
  #undef TEST_COUNT_95
#endif
#if (PREDICTED_COUNTER == 95)
  #define TEST_COUNT_95(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_95(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_96
  #undef TEST_COUNT_96
#endif
#if (PREDICTED_COUNTER == 96)
  #define TEST_COUNT_96(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_96(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_97
  #undef TEST_COUNT_97
#endif
#if (PREDICTED_COUNTER == 97)
  #define TEST_COUNT_97(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_97(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_98
  #undef TEST_COUNT_98
#endif
#if (PREDICTED_COUNTER == 98)
  #define TEST_COUNT_98(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_98(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_99
  #undef TEST_COUNT_99
#endif
#if (PREDICTED_COUNTER == 99)
  #define TEST_COUNT_99(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_99(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_100
  #undef TEST_COUNT_100
#endif
#if (PREDICTED_COUNTER == 100)
  #define TEST_COUNT_100(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_100(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_101
  #undef TEST_COUNT_101
#endif
#if (PREDICTED_COUNTER == 101)
  #define TEST_COUNT_101(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_101(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_102
  #undef TEST_COUNT_102
#endif
#if (PREDICTED_COUNTER == 102)
  #define TEST_COUNT_102(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_102(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_103
  #undef TEST_COUNT_103
#endif
#if (PREDICTED_COUNTER == 103)
  #define TEST_COUNT_103(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_103(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_104
  #undef TEST_COUNT_104
#endif
#if (PREDICTED_COUNTER == 104)
  #define TEST_COUNT_104(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_104(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_105
  #undef TEST_COUNT_105
#endif
#if (PREDICTED_COUNTER == 105)
  #define TEST_COUNT_105(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_105(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_106
  #undef TEST_COUNT_106
#endif
#if (PREDICTED_COUNTER == 106)
  #define TEST_COUNT_106(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_106(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_107
  #undef TEST_COUNT_107
#endif
#if (PREDICTED_COUNTER == 107)
  #define TEST_COUNT_107(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_107(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_108
  #undef TEST_COUNT_108
#endif
#if (PREDICTED_COUNTER == 108)
  #define TEST_COUNT_108(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_108(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_109
  #undef TEST_COUNT_109
#endif
#if (PREDICTED_COUNTER == 109)
  #define TEST_COUNT_109(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_109(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_110
  #undef TEST_COUNT_110
#endif
#if (PREDICTED_COUNTER == 110)
  #define TEST_COUNT_110(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_110(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_111
  #undef TEST_COUNT_111
#endif
#if (PREDICTED_COUNTER == 111)
  #define TEST_COUNT_111(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_111(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_112
  #undef TEST_COUNT_112
#endif
#if (PREDICTED_COUNTER == 112)
  #define TEST_COUNT_112(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_112(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_113
  #undef TEST_COUNT_113
#endif
#if (PREDICTED_COUNTER == 113)
  #define TEST_COUNT_113(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_113(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_114
  #undef TEST_COUNT_114
#endif
#if (PREDICTED_COUNTER == 114)
  #define TEST_COUNT_114(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_114(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_115
  #undef TEST_COUNT_115
#endif
#if (PREDICTED_COUNTER == 115)
  #define TEST_COUNT_115(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_115(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_116
  #undef TEST_COUNT_116
#endif
#if (PREDICTED_COUNTER == 116)
  #define TEST_COUNT_116(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_116(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_117
  #undef TEST_COUNT_117
#endif
#if (PREDICTED_COUNTER == 117)
  #define TEST_COUNT_117(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_117(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_118
  #undef TEST_COUNT_118
#endif
#if (PREDICTED_COUNTER == 118)
  #define TEST_COUNT_118(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_118(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_119
  #undef TEST_COUNT_119
#endif
#if (PREDICTED_COUNTER == 119)
  #define TEST_COUNT_119(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_119(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_120
  #undef TEST_COUNT_120
#endif
#if (PREDICTED_COUNTER == 120)
  #define TEST_COUNT_120(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_120(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_121
  #undef TEST_COUNT_121
#endif
#if (PREDICTED_COUNTER == 121)
  #define TEST_COUNT_121(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_121(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_122
  #undef TEST_COUNT_122
#endif
#if (PREDICTED_COUNTER == 122)
  #define TEST_COUNT_122(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_122(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_123
  #undef TEST_COUNT_123
#endif
#if (PREDICTED_COUNTER == 123)
  #define TEST_COUNT_123(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_123(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_124
  #undef TEST_COUNT_124
#endif
#if (PREDICTED_COUNTER == 124)
  #define TEST_COUNT_124(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_124(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_125
  #undef TEST_COUNT_125
#endif
#if (PREDICTED_COUNTER == 125)
  #define TEST_COUNT_125(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_125(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_126
  #undef TEST_COUNT_126
#endif
#if (PREDICTED_COUNTER == 126)
  #define TEST_COUNT_126(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_126(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_127
  #undef TEST_COUNT_127
#endif
#if (PREDICTED_COUNTER == 127)
  #define TEST_COUNT_127(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_127(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_128
  #undef TEST_COUNT_128
#endif
#if (PREDICTED_COUNTER == 128)
  #define TEST_COUNT_128(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_128(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_129
  #undef TEST_COUNT_129
#endif
#if (PREDICTED_COUNTER == 129)
  #define TEST_COUNT_129(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_129(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_130
  #undef TEST_COUNT_130
#endif
#if (PREDICTED_COUNTER == 130)
  #define TEST_COUNT_130(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_130(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_131
  #undef TEST_COUNT_131
#endif
#if (PREDICTED_COUNTER == 131)
  #define TEST_COUNT_131(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_131(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_132
  #undef TEST_COUNT_132
#endif
#if (PREDICTED_COUNTER == 132)
  #define TEST_COUNT_132(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_132(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_133
  #undef TEST_COUNT_133
#endif
#if (PREDICTED_COUNTER == 133)
  #define TEST_COUNT_133(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_133(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_134
  #undef TEST_COUNT_134
#endif
#if (PREDICTED_COUNTER == 134)
  #define TEST_COUNT_134(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_134(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_135
  #undef TEST_COUNT_135
#endif
#if (PREDICTED_COUNTER == 135)
  #define TEST_COUNT_135(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_135(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_136
  #undef TEST_COUNT_136
#endif
#if (PREDICTED_COUNTER == 136)
  #define TEST_COUNT_136(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_136(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_137
  #undef TEST_COUNT_137
#endif
#if (PREDICTED_COUNTER == 137)
  #define TEST_COUNT_137(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_137(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_138
  #undef TEST_COUNT_138
#endif
#if (PREDICTED_COUNTER == 138)
  #define TEST_COUNT_138(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_138(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_139
  #undef TEST_COUNT_139
#endif
#if (PREDICTED_COUNTER == 139)
  #define TEST_COUNT_139(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_139(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_140
  #undef TEST_COUNT_140
#endif
#if (PREDICTED_COUNTER == 140)
  #define TEST_COUNT_140(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_140(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_141
  #undef TEST_COUNT_141
#endif
#if (PREDICTED_COUNTER == 141)
  #define TEST_COUNT_141(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_141(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_142
  #undef TEST_COUNT_142
#endif
#if (PREDICTED_COUNTER == 142)
  #define TEST_COUNT_142(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_142(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_143
  #undef TEST_COUNT_143
#endif
#if (PREDICTED_COUNTER == 143)
  #define TEST_COUNT_143(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_143(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_144
  #undef TEST_COUNT_144
#endif
#if (PREDICTED_COUNTER == 144)
  #define TEST_COUNT_144(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_144(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_145
  #undef TEST_COUNT_145
#endif
#if (PREDICTED_COUNTER == 145)
  #define TEST_COUNT_145(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_145(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_146
  #undef TEST_COUNT_146
#endif
#if (PREDICTED_COUNTER == 146)
  #define TEST_COUNT_146(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_146(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_147
  #undef TEST_COUNT_147
#endif
#if (PREDICTED_COUNTER == 147)
  #define TEST_COUNT_147(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_147(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_148
  #undef TEST_COUNT_148
#endif
#if (PREDICTED_COUNTER == 148)
  #define TEST_COUNT_148(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_148(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_149
  #undef TEST_COUNT_149
#endif
#if (PREDICTED_COUNTER == 149)
  #define TEST_COUNT_149(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_149(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_150
  #undef TEST_COUNT_150
#endif
#if (PREDICTED_COUNTER == 150)
  #define TEST_COUNT_150(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_150(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_151
  #undef TEST_COUNT_151
#endif
#if (PREDICTED_COUNTER == 151)
  #define TEST_COUNT_151(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_151(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_152
  #undef TEST_COUNT_152
#endif
#if (PREDICTED_COUNTER == 152)
  #define TEST_COUNT_152(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_152(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_153
  #undef TEST_COUNT_153
#endif
#if (PREDICTED_COUNTER == 153)
  #define TEST_COUNT_153(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_153(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_154
  #undef TEST_COUNT_154
#endif
#if (PREDICTED_COUNTER == 154)
  #define TEST_COUNT_154(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_154(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_155
  #undef TEST_COUNT_155
#endif
#if (PREDICTED_COUNTER == 155)
  #define TEST_COUNT_155(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_155(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_156
  #undef TEST_COUNT_156
#endif
#if (PREDICTED_COUNTER == 156)
  #define TEST_COUNT_156(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_156(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_157
  #undef TEST_COUNT_157
#endif
#if (PREDICTED_COUNTER == 157)
  #define TEST_COUNT_157(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_157(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_158
  #undef TEST_COUNT_158
#endif
#if (PREDICTED_COUNTER == 158)
  #define TEST_COUNT_158(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_158(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_159
  #undef TEST_COUNT_159
#endif
#if (PREDICTED_COUNTER == 159)
  #define TEST_COUNT_159(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_159(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_160
  #undef TEST_COUNT_160
#endif
#if (PREDICTED_COUNTER == 160)
  #define TEST_COUNT_160(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_160(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_161
  #undef TEST_COUNT_161
#endif
#if (PREDICTED_COUNTER == 161)
  #define TEST_COUNT_161(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_161(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_162
  #undef TEST_COUNT_162
#endif
#if (PREDICTED_COUNTER == 162)
  #define TEST_COUNT_162(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_162(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_163
  #undef TEST_COUNT_163
#endif
#if (PREDICTED_COUNTER == 163)
  #define TEST_COUNT_163(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_163(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_164
  #undef TEST_COUNT_164
#endif
#if (PREDICTED_COUNTER == 164)
  #define TEST_COUNT_164(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_164(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_165
  #undef TEST_COUNT_165
#endif
#if (PREDICTED_COUNTER == 165)
  #define TEST_COUNT_165(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_165(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_166
  #undef TEST_COUNT_166
#endif
#if (PREDICTED_COUNTER == 166)
  #define TEST_COUNT_166(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_166(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_167
  #undef TEST_COUNT_167
#endif
#if (PREDICTED_COUNTER == 167)
  #define TEST_COUNT_167(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_167(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_168
  #undef TEST_COUNT_168
#endif
#if (PREDICTED_COUNTER == 168)
  #define TEST_COUNT_168(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_168(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_169
  #undef TEST_COUNT_169
#endif
#if (PREDICTED_COUNTER == 169)
  #define TEST_COUNT_169(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_169(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_170
  #undef TEST_COUNT_170
#endif
#if (PREDICTED_COUNTER == 170)
  #define TEST_COUNT_170(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_170(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_171
  #undef TEST_COUNT_171
#endif
#if (PREDICTED_COUNTER == 171)
  #define TEST_COUNT_171(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_171(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_172
  #undef TEST_COUNT_172
#endif
#if (PREDICTED_COUNTER == 172)
  #define TEST_COUNT_172(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_172(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_173
  #undef TEST_COUNT_173
#endif
#if (PREDICTED_COUNTER == 173)
  #define TEST_COUNT_173(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_173(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_174
  #undef TEST_COUNT_174
#endif
#if (PREDICTED_COUNTER == 174)
  #define TEST_COUNT_174(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_174(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_175
  #undef TEST_COUNT_175
#endif
#if (PREDICTED_COUNTER == 175)
  #define TEST_COUNT_175(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_175(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_176
  #undef TEST_COUNT_176
#endif
#if (PREDICTED_COUNTER == 176)
  #define TEST_COUNT_176(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_176(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_177
  #undef TEST_COUNT_177
#endif
#if (PREDICTED_COUNTER == 177)
  #define TEST_COUNT_177(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_177(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_178
  #undef TEST_COUNT_178
#endif
#if (PREDICTED_COUNTER == 178)
  #define TEST_COUNT_178(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_178(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_179
  #undef TEST_COUNT_179
#endif
#if (PREDICTED_COUNTER == 179)
  #define TEST_COUNT_179(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_179(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_180
  #undef TEST_COUNT_180
#endif
#if (PREDICTED_COUNTER == 180)
  #define TEST_COUNT_180(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_180(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_181
  #undef TEST_COUNT_181
#endif
#if (PREDICTED_COUNTER == 181)
  #define TEST_COUNT_181(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_181(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_182
  #undef TEST_COUNT_182
#endif
#if (PREDICTED_COUNTER == 182)
  #define TEST_COUNT_182(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_182(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_183
  #undef TEST_COUNT_183
#endif
#if (PREDICTED_COUNTER == 183)
  #define TEST_COUNT_183(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_183(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_184
  #undef TEST_COUNT_184
#endif
#if (PREDICTED_COUNTER == 184)
  #define TEST_COUNT_184(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_184(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_185
  #undef TEST_COUNT_185
#endif
#if (PREDICTED_COUNTER == 185)
  #define TEST_COUNT_185(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_185(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_186
  #undef TEST_COUNT_186
#endif
#if (PREDICTED_COUNTER == 186)
  #define TEST_COUNT_186(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_186(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_187
  #undef TEST_COUNT_187
#endif
#if (PREDICTED_COUNTER == 187)
  #define TEST_COUNT_187(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_187(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_188
  #undef TEST_COUNT_188
#endif
#if (PREDICTED_COUNTER == 188)
  #define TEST_COUNT_188(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_188(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_189
  #undef TEST_COUNT_189
#endif
#if (PREDICTED_COUNTER == 189)
  #define TEST_COUNT_189(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_189(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_190
  #undef TEST_COUNT_190
#endif
#if (PREDICTED_COUNTER == 190)
  #define TEST_COUNT_190(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_190(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_191
  #undef TEST_COUNT_191
#endif
#if (PREDICTED_COUNTER == 191)
  #define TEST_COUNT_191(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_191(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_192
  #undef TEST_COUNT_192
#endif
#if (PREDICTED_COUNTER == 192)
  #define TEST_COUNT_192(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_192(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_193
  #undef TEST_COUNT_193
#endif
#if (PREDICTED_COUNTER == 193)
  #define TEST_COUNT_193(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_193(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_194
  #undef TEST_COUNT_194
#endif
#if (PREDICTED_COUNTER == 194)
  #define TEST_COUNT_194(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_194(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_195
  #undef TEST_COUNT_195
#endif
#if (PREDICTED_COUNTER == 195)
  #define TEST_COUNT_195(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_195(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_196
  #undef TEST_COUNT_196
#endif
#if (PREDICTED_COUNTER == 196)
  #define TEST_COUNT_196(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_196(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_197
  #undef TEST_COUNT_197
#endif
#if (PREDICTED_COUNTER == 197)
  #define TEST_COUNT_197(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_197(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_198
  #undef TEST_COUNT_198
#endif
#if (PREDICTED_COUNTER == 198)
  #define TEST_COUNT_198(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_198(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_199
  #undef TEST_COUNT_199
#endif
#if (PREDICTED_COUNTER == 199)
  #define TEST_COUNT_199(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_199(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_200
  #undef TEST_COUNT_200
#endif
#if (PREDICTED_COUNTER == 200)
  #define TEST_COUNT_200(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_200(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_201
  #undef TEST_COUNT_201
#endif
#if (PREDICTED_COUNTER == 201)
  #define TEST_COUNT_201(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_201(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_202
  #undef TEST_COUNT_202
#endif
#if (PREDICTED_COUNTER == 202)
  #define TEST_COUNT_202(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_202(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_203
  #undef TEST_COUNT_203
#endif
#if (PREDICTED_COUNTER == 203)
  #define TEST_COUNT_203(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_203(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_204
  #undef TEST_COUNT_204
#endif
#if (PREDICTED_COUNTER == 204)
  #define TEST_COUNT_204(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_204(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_205
  #undef TEST_COUNT_205
#endif
#if (PREDICTED_COUNTER == 205)
  #define TEST_COUNT_205(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_205(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_206
  #undef TEST_COUNT_206
#endif
#if (PREDICTED_COUNTER == 206)
  #define TEST_COUNT_206(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_206(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_207
  #undef TEST_COUNT_207
#endif
#if (PREDICTED_COUNTER == 207)
  #define TEST_COUNT_207(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_207(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_208
  #undef TEST_COUNT_208
#endif
#if (PREDICTED_COUNTER == 208)
  #define TEST_COUNT_208(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_208(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_209
  #undef TEST_COUNT_209
#endif
#if (PREDICTED_COUNTER == 209)
  #define TEST_COUNT_209(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_209(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_210
  #undef TEST_COUNT_210
#endif
#if (PREDICTED_COUNTER == 210)
  #define TEST_COUNT_210(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_210(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_211
  #undef TEST_COUNT_211
#endif
#if (PREDICTED_COUNTER == 211)
  #define TEST_COUNT_211(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_211(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_212
  #undef TEST_COUNT_212
#endif
#if (PREDICTED_COUNTER == 212)
  #define TEST_COUNT_212(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_212(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_213
  #undef TEST_COUNT_213
#endif
#if (PREDICTED_COUNTER == 213)
  #define TEST_COUNT_213(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_213(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_214
  #undef TEST_COUNT_214
#endif
#if (PREDICTED_COUNTER == 214)
  #define TEST_COUNT_214(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_214(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_215
  #undef TEST_COUNT_215
#endif
#if (PREDICTED_COUNTER == 215)
  #define TEST_COUNT_215(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_215(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_216
  #undef TEST_COUNT_216
#endif
#if (PREDICTED_COUNTER == 216)
  #define TEST_COUNT_216(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_216(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_217
  #undef TEST_COUNT_217
#endif
#if (PREDICTED_COUNTER == 217)
  #define TEST_COUNT_217(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_217(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_218
  #undef TEST_COUNT_218
#endif
#if (PREDICTED_COUNTER == 218)
  #define TEST_COUNT_218(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_218(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_219
  #undef TEST_COUNT_219
#endif
#if (PREDICTED_COUNTER == 219)
  #define TEST_COUNT_219(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_219(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_220
  #undef TEST_COUNT_220
#endif
#if (PREDICTED_COUNTER == 220)
  #define TEST_COUNT_220(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_220(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_221
  #undef TEST_COUNT_221
#endif
#if (PREDICTED_COUNTER == 221)
  #define TEST_COUNT_221(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_221(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_222
  #undef TEST_COUNT_222
#endif
#if (PREDICTED_COUNTER == 222)
  #define TEST_COUNT_222(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_222(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_223
  #undef TEST_COUNT_223
#endif
#if (PREDICTED_COUNTER == 223)
  #define TEST_COUNT_223(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_223(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_224
  #undef TEST_COUNT_224
#endif
#if (PREDICTED_COUNTER == 224)
  #define TEST_COUNT_224(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_224(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_225
  #undef TEST_COUNT_225
#endif
#if (PREDICTED_COUNTER == 225)
  #define TEST_COUNT_225(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_225(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_226
  #undef TEST_COUNT_226
#endif
#if (PREDICTED_COUNTER == 226)
  #define TEST_COUNT_226(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_226(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_227
  #undef TEST_COUNT_227
#endif
#if (PREDICTED_COUNTER == 227)
  #define TEST_COUNT_227(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_227(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_228
  #undef TEST_COUNT_228
#endif
#if (PREDICTED_COUNTER == 228)
  #define TEST_COUNT_228(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_228(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_229
  #undef TEST_COUNT_229
#endif
#if (PREDICTED_COUNTER == 229)
  #define TEST_COUNT_229(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_229(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_230
  #undef TEST_COUNT_230
#endif
#if (PREDICTED_COUNTER == 230)
  #define TEST_COUNT_230(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_230(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_231
  #undef TEST_COUNT_231
#endif
#if (PREDICTED_COUNTER == 231)
  #define TEST_COUNT_231(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_231(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_232
  #undef TEST_COUNT_232
#endif
#if (PREDICTED_COUNTER == 232)
  #define TEST_COUNT_232(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_232(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_233
  #undef TEST_COUNT_233
#endif
#if (PREDICTED_COUNTER == 233)
  #define TEST_COUNT_233(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_233(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_234
  #undef TEST_COUNT_234
#endif
#if (PREDICTED_COUNTER == 234)
  #define TEST_COUNT_234(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_234(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_235
  #undef TEST_COUNT_235
#endif
#if (PREDICTED_COUNTER == 235)
  #define TEST_COUNT_235(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_235(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_236
  #undef TEST_COUNT_236
#endif
#if (PREDICTED_COUNTER == 236)
  #define TEST_COUNT_236(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_236(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_237
  #undef TEST_COUNT_237
#endif
#if (PREDICTED_COUNTER == 237)
  #define TEST_COUNT_237(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_237(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_238
  #undef TEST_COUNT_238
#endif
#if (PREDICTED_COUNTER == 238)
  #define TEST_COUNT_238(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_238(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_239
  #undef TEST_COUNT_239
#endif
#if (PREDICTED_COUNTER == 239)
  #define TEST_COUNT_239(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_239(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_240
  #undef TEST_COUNT_240
#endif
#if (PREDICTED_COUNTER == 240)
  #define TEST_COUNT_240(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_240(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_241
  #undef TEST_COUNT_241
#endif
#if (PREDICTED_COUNTER == 241)
  #define TEST_COUNT_241(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_241(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_242
  #undef TEST_COUNT_242
#endif
#if (PREDICTED_COUNTER == 242)
  #define TEST_COUNT_242(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_242(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_243
  #undef TEST_COUNT_243
#endif
#if (PREDICTED_COUNTER == 243)
  #define TEST_COUNT_243(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_243(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_244
  #undef TEST_COUNT_244
#endif
#if (PREDICTED_COUNTER == 244)
  #define TEST_COUNT_244(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_244(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_245
  #undef TEST_COUNT_245
#endif
#if (PREDICTED_COUNTER == 245)
  #define TEST_COUNT_245(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_245(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_246
  #undef TEST_COUNT_246
#endif
#if (PREDICTED_COUNTER == 246)
  #define TEST_COUNT_246(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_246(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_247
  #undef TEST_COUNT_247
#endif
#if (PREDICTED_COUNTER == 247)
  #define TEST_COUNT_247(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_247(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_248
  #undef TEST_COUNT_248
#endif
#if (PREDICTED_COUNTER == 248)
  #define TEST_COUNT_248(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_248(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_249
  #undef TEST_COUNT_249
#endif
#if (PREDICTED_COUNTER == 249)
  #define TEST_COUNT_249(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_249(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_250
  #undef TEST_COUNT_250
#endif
#if (PREDICTED_COUNTER == 250)
  #define TEST_COUNT_250(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_250(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_251
  #undef TEST_COUNT_251
#endif
#if (PREDICTED_COUNTER == 251)
  #define TEST_COUNT_251(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_251(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_252
  #undef TEST_COUNT_252
#endif
#if (PREDICTED_COUNTER == 252)
  #define TEST_COUNT_252(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_252(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_253
  #undef TEST_COUNT_253
#endif
#if (PREDICTED_COUNTER == 253)
  #define TEST_COUNT_253(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_253(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_254
  #undef TEST_COUNT_254
#endif
#if (PREDICTED_COUNTER == 254)
  #define TEST_COUNT_254(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_254(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_255
  #undef TEST_COUNT_255
#endif
#if (PREDICTED_COUNTER == 255)
  #define TEST_COUNT_255(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_255(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_256
  #undef TEST_COUNT_256
#endif
#if (PREDICTED_COUNTER == 256)
  #define TEST_COUNT_256(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_256(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_257
  #undef TEST_COUNT_257
#endif
#if (PREDICTED_COUNTER == 257)
  #define TEST_COUNT_257(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_257(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_258
  #undef TEST_COUNT_258
#endif
#if (PREDICTED_COUNTER == 258)
  #define TEST_COUNT_258(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_258(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_259
  #undef TEST_COUNT_259
#endif
#if (PREDICTED_COUNTER == 259)
  #define TEST_COUNT_259(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_259(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_260
  #undef TEST_COUNT_260
#endif
#if (PREDICTED_COUNTER == 260)
  #define TEST_COUNT_260(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_260(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_261
  #undef TEST_COUNT_261
#endif
#if (PREDICTED_COUNTER == 261)
  #define TEST_COUNT_261(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_261(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_262
  #undef TEST_COUNT_262
#endif
#if (PREDICTED_COUNTER == 262)
  #define TEST_COUNT_262(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_262(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_263
  #undef TEST_COUNT_263
#endif
#if (PREDICTED_COUNTER == 263)
  #define TEST_COUNT_263(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_263(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_264
  #undef TEST_COUNT_264
#endif
#if (PREDICTED_COUNTER == 264)
  #define TEST_COUNT_264(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_264(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_265
  #undef TEST_COUNT_265
#endif
#if (PREDICTED_COUNTER == 265)
  #define TEST_COUNT_265(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_265(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_266
  #undef TEST_COUNT_266
#endif
#if (PREDICTED_COUNTER == 266)
  #define TEST_COUNT_266(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_266(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_267
  #undef TEST_COUNT_267
#endif
#if (PREDICTED_COUNTER == 267)
  #define TEST_COUNT_267(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_267(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_268
  #undef TEST_COUNT_268
#endif
#if (PREDICTED_COUNTER == 268)
  #define TEST_COUNT_268(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_268(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_269
  #undef TEST_COUNT_269
#endif
#if (PREDICTED_COUNTER == 269)
  #define TEST_COUNT_269(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_269(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_270
  #undef TEST_COUNT_270
#endif
#if (PREDICTED_COUNTER == 270)
  #define TEST_COUNT_270(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_270(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_271
  #undef TEST_COUNT_271
#endif
#if (PREDICTED_COUNTER == 271)
  #define TEST_COUNT_271(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_271(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_272
  #undef TEST_COUNT_272
#endif
#if (PREDICTED_COUNTER == 272)
  #define TEST_COUNT_272(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_272(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_273
  #undef TEST_COUNT_273
#endif
#if (PREDICTED_COUNTER == 273)
  #define TEST_COUNT_273(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_273(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_274
  #undef TEST_COUNT_274
#endif
#if (PREDICTED_COUNTER == 274)
  #define TEST_COUNT_274(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_274(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_275
  #undef TEST_COUNT_275
#endif
#if (PREDICTED_COUNTER == 275)
  #define TEST_COUNT_275(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_275(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_276
  #undef TEST_COUNT_276
#endif
#if (PREDICTED_COUNTER == 276)
  #define TEST_COUNT_276(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_276(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_277
  #undef TEST_COUNT_277
#endif
#if (PREDICTED_COUNTER == 277)
  #define TEST_COUNT_277(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_277(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_278
  #undef TEST_COUNT_278
#endif
#if (PREDICTED_COUNTER == 278)
  #define TEST_COUNT_278(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_278(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_279
  #undef TEST_COUNT_279
#endif
#if (PREDICTED_COUNTER == 279)
  #define TEST_COUNT_279(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_279(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_280
  #undef TEST_COUNT_280
#endif
#if (PREDICTED_COUNTER == 280)
  #define TEST_COUNT_280(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_280(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_281
  #undef TEST_COUNT_281
#endif
#if (PREDICTED_COUNTER == 281)
  #define TEST_COUNT_281(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_281(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_282
  #undef TEST_COUNT_282
#endif
#if (PREDICTED_COUNTER == 282)
  #define TEST_COUNT_282(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_282(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_283
  #undef TEST_COUNT_283
#endif
#if (PREDICTED_COUNTER == 283)
  #define TEST_COUNT_283(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_283(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_284
  #undef TEST_COUNT_284
#endif
#if (PREDICTED_COUNTER == 284)
  #define TEST_COUNT_284(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_284(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_285
  #undef TEST_COUNT_285
#endif
#if (PREDICTED_COUNTER == 285)
  #define TEST_COUNT_285(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_285(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_286
  #undef TEST_COUNT_286
#endif
#if (PREDICTED_COUNTER == 286)
  #define TEST_COUNT_286(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_286(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_287
  #undef TEST_COUNT_287
#endif
#if (PREDICTED_COUNTER == 287)
  #define TEST_COUNT_287(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_287(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_288
  #undef TEST_COUNT_288
#endif
#if (PREDICTED_COUNTER == 288)
  #define TEST_COUNT_288(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_288(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_289
  #undef TEST_COUNT_289
#endif
#if (PREDICTED_COUNTER == 289)
  #define TEST_COUNT_289(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_289(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_290
  #undef TEST_COUNT_290
#endif
#if (PREDICTED_COUNTER == 290)
  #define TEST_COUNT_290(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_290(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_291
  #undef TEST_COUNT_291
#endif
#if (PREDICTED_COUNTER == 291)
  #define TEST_COUNT_291(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_291(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_292
  #undef TEST_COUNT_292
#endif
#if (PREDICTED_COUNTER == 292)
  #define TEST_COUNT_292(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_292(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_293
  #undef TEST_COUNT_293
#endif
#if (PREDICTED_COUNTER == 293)
  #define TEST_COUNT_293(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_293(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_294
  #undef TEST_COUNT_294
#endif
#if (PREDICTED_COUNTER == 294)
  #define TEST_COUNT_294(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_294(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_295
  #undef TEST_COUNT_295
#endif
#if (PREDICTED_COUNTER == 295)
  #define TEST_COUNT_295(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_295(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_296
  #undef TEST_COUNT_296
#endif
#if (PREDICTED_COUNTER == 296)
  #define TEST_COUNT_296(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_296(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_297
  #undef TEST_COUNT_297
#endif
#if (PREDICTED_COUNTER == 297)
  #define TEST_COUNT_297(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_297(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_298
  #undef TEST_COUNT_298
#endif
#if (PREDICTED_COUNTER == 298)
  #define TEST_COUNT_298(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_298(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_299
  #undef TEST_COUNT_299
#endif
#if (PREDICTED_COUNTER == 299)
  #define TEST_COUNT_299(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_299(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_300
  #undef TEST_COUNT_300
#endif
#if (PREDICTED_COUNTER == 300)
  #define TEST_COUNT_300(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_300(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_301
  #undef TEST_COUNT_301
#endif
#if (PREDICTED_COUNTER == 301)
  #define TEST_COUNT_301(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_301(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_302
  #undef TEST_COUNT_302
#endif
#if (PREDICTED_COUNTER == 302)
  #define TEST_COUNT_302(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_302(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_303
  #undef TEST_COUNT_303
#endif
#if (PREDICTED_COUNTER == 303)
  #define TEST_COUNT_303(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_303(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_304
  #undef TEST_COUNT_304
#endif
#if (PREDICTED_COUNTER == 304)
  #define TEST_COUNT_304(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_304(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_305
  #undef TEST_COUNT_305
#endif
#if (PREDICTED_COUNTER == 305)
  #define TEST_COUNT_305(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_305(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_306
  #undef TEST_COUNT_306
#endif
#if (PREDICTED_COUNTER == 306)
  #define TEST_COUNT_306(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_306(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_307
  #undef TEST_COUNT_307
#endif
#if (PREDICTED_COUNTER == 307)
  #define TEST_COUNT_307(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_307(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_308
  #undef TEST_COUNT_308
#endif
#if (PREDICTED_COUNTER == 308)
  #define TEST_COUNT_308(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_308(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_309
  #undef TEST_COUNT_309
#endif
#if (PREDICTED_COUNTER == 309)
  #define TEST_COUNT_309(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_309(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_310
  #undef TEST_COUNT_310
#endif
#if (PREDICTED_COUNTER == 310)
  #define TEST_COUNT_310(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_310(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_311
  #undef TEST_COUNT_311
#endif
#if (PREDICTED_COUNTER == 311)
  #define TEST_COUNT_311(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_311(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_312
  #undef TEST_COUNT_312
#endif
#if (PREDICTED_COUNTER == 312)
  #define TEST_COUNT_312(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_312(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_313
  #undef TEST_COUNT_313
#endif
#if (PREDICTED_COUNTER == 313)
  #define TEST_COUNT_313(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_313(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_314
  #undef TEST_COUNT_314
#endif
#if (PREDICTED_COUNTER == 314)
  #define TEST_COUNT_314(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_314(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_315
  #undef TEST_COUNT_315
#endif
#if (PREDICTED_COUNTER == 315)
  #define TEST_COUNT_315(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_315(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_316
  #undef TEST_COUNT_316
#endif
#if (PREDICTED_COUNTER == 316)
  #define TEST_COUNT_316(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_316(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_317
  #undef TEST_COUNT_317
#endif
#if (PREDICTED_COUNTER == 317)
  #define TEST_COUNT_317(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_317(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_318
  #undef TEST_COUNT_318
#endif
#if (PREDICTED_COUNTER == 318)
  #define TEST_COUNT_318(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_318(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_319
  #undef TEST_COUNT_319
#endif
#if (PREDICTED_COUNTER == 319)
  #define TEST_COUNT_319(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_319(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_320
  #undef TEST_COUNT_320
#endif
#if (PREDICTED_COUNTER == 320)
  #define TEST_COUNT_320(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_320(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_321
  #undef TEST_COUNT_321
#endif
#if (PREDICTED_COUNTER == 321)
  #define TEST_COUNT_321(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_321(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_322
  #undef TEST_COUNT_322
#endif
#if (PREDICTED_COUNTER == 322)
  #define TEST_COUNT_322(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_322(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_323
  #undef TEST_COUNT_323
#endif
#if (PREDICTED_COUNTER == 323)
  #define TEST_COUNT_323(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_323(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_324
  #undef TEST_COUNT_324
#endif
#if (PREDICTED_COUNTER == 324)
  #define TEST_COUNT_324(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_324(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_325
  #undef TEST_COUNT_325
#endif
#if (PREDICTED_COUNTER == 325)
  #define TEST_COUNT_325(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_325(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_326
  #undef TEST_COUNT_326
#endif
#if (PREDICTED_COUNTER == 326)
  #define TEST_COUNT_326(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_326(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_327
  #undef TEST_COUNT_327
#endif
#if (PREDICTED_COUNTER == 327)
  #define TEST_COUNT_327(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_327(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_328
  #undef TEST_COUNT_328
#endif
#if (PREDICTED_COUNTER == 328)
  #define TEST_COUNT_328(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_328(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_329
  #undef TEST_COUNT_329
#endif
#if (PREDICTED_COUNTER == 329)
  #define TEST_COUNT_329(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_329(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_330
  #undef TEST_COUNT_330
#endif
#if (PREDICTED_COUNTER == 330)
  #define TEST_COUNT_330(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_330(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_331
  #undef TEST_COUNT_331
#endif
#if (PREDICTED_COUNTER == 331)
  #define TEST_COUNT_331(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_331(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_332
  #undef TEST_COUNT_332
#endif
#if (PREDICTED_COUNTER == 332)
  #define TEST_COUNT_332(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_332(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_333
  #undef TEST_COUNT_333
#endif
#if (PREDICTED_COUNTER == 333)
  #define TEST_COUNT_333(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_333(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_334
  #undef TEST_COUNT_334
#endif
#if (PREDICTED_COUNTER == 334)
  #define TEST_COUNT_334(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_334(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_335
  #undef TEST_COUNT_335
#endif
#if (PREDICTED_COUNTER == 335)
  #define TEST_COUNT_335(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_335(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_336
  #undef TEST_COUNT_336
#endif
#if (PREDICTED_COUNTER == 336)
  #define TEST_COUNT_336(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_336(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_337
  #undef TEST_COUNT_337
#endif
#if (PREDICTED_COUNTER == 337)
  #define TEST_COUNT_337(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_337(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_338
  #undef TEST_COUNT_338
#endif
#if (PREDICTED_COUNTER == 338)
  #define TEST_COUNT_338(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_338(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_339
  #undef TEST_COUNT_339
#endif
#if (PREDICTED_COUNTER == 339)
  #define TEST_COUNT_339(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_339(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_340
  #undef TEST_COUNT_340
#endif
#if (PREDICTED_COUNTER == 340)
  #define TEST_COUNT_340(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_340(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_341
  #undef TEST_COUNT_341
#endif
#if (PREDICTED_COUNTER == 341)
  #define TEST_COUNT_341(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_341(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_342
  #undef TEST_COUNT_342
#endif
#if (PREDICTED_COUNTER == 342)
  #define TEST_COUNT_342(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_342(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_343
  #undef TEST_COUNT_343
#endif
#if (PREDICTED_COUNTER == 343)
  #define TEST_COUNT_343(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_343(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_344
  #undef TEST_COUNT_344
#endif
#if (PREDICTED_COUNTER == 344)
  #define TEST_COUNT_344(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_344(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_345
  #undef TEST_COUNT_345
#endif
#if (PREDICTED_COUNTER == 345)
  #define TEST_COUNT_345(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_345(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_346
  #undef TEST_COUNT_346
#endif
#if (PREDICTED_COUNTER == 346)
  #define TEST_COUNT_346(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_346(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_347
  #undef TEST_COUNT_347
#endif
#if (PREDICTED_COUNTER == 347)
  #define TEST_COUNT_347(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_347(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_348
  #undef TEST_COUNT_348
#endif
#if (PREDICTED_COUNTER == 348)
  #define TEST_COUNT_348(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_348(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_349
  #undef TEST_COUNT_349
#endif
#if (PREDICTED_COUNTER == 349)
  #define TEST_COUNT_349(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_349(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_350
  #undef TEST_COUNT_350
#endif
#if (PREDICTED_COUNTER == 350)
  #define TEST_COUNT_350(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_350(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_351
  #undef TEST_COUNT_351
#endif
#if (PREDICTED_COUNTER == 351)
  #define TEST_COUNT_351(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_351(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_352
  #undef TEST_COUNT_352
#endif
#if (PREDICTED_COUNTER == 352)
  #define TEST_COUNT_352(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_352(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_353
  #undef TEST_COUNT_353
#endif
#if (PREDICTED_COUNTER == 353)
  #define TEST_COUNT_353(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_353(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_354
  #undef TEST_COUNT_354
#endif
#if (PREDICTED_COUNTER == 354)
  #define TEST_COUNT_354(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_354(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_355
  #undef TEST_COUNT_355
#endif
#if (PREDICTED_COUNTER == 355)
  #define TEST_COUNT_355(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_355(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_356
  #undef TEST_COUNT_356
#endif
#if (PREDICTED_COUNTER == 356)
  #define TEST_COUNT_356(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_356(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_357
  #undef TEST_COUNT_357
#endif
#if (PREDICTED_COUNTER == 357)
  #define TEST_COUNT_357(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_357(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_358
  #undef TEST_COUNT_358
#endif
#if (PREDICTED_COUNTER == 358)
  #define TEST_COUNT_358(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_358(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_359
  #undef TEST_COUNT_359
#endif
#if (PREDICTED_COUNTER == 359)
  #define TEST_COUNT_359(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_359(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_360
  #undef TEST_COUNT_360
#endif
#if (PREDICTED_COUNTER == 360)
  #define TEST_COUNT_360(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_360(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_361
  #undef TEST_COUNT_361
#endif
#if (PREDICTED_COUNTER == 361)
  #define TEST_COUNT_361(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_361(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_362
  #undef TEST_COUNT_362
#endif
#if (PREDICTED_COUNTER == 362)
  #define TEST_COUNT_362(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_362(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_363
  #undef TEST_COUNT_363
#endif
#if (PREDICTED_COUNTER == 363)
  #define TEST_COUNT_363(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_363(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_364
  #undef TEST_COUNT_364
#endif
#if (PREDICTED_COUNTER == 364)
  #define TEST_COUNT_364(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_364(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_365
  #undef TEST_COUNT_365
#endif
#if (PREDICTED_COUNTER == 365)
  #define TEST_COUNT_365(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_365(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_366
  #undef TEST_COUNT_366
#endif
#if (PREDICTED_COUNTER == 366)
  #define TEST_COUNT_366(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_366(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_367
  #undef TEST_COUNT_367
#endif
#if (PREDICTED_COUNTER == 367)
  #define TEST_COUNT_367(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_367(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_368
  #undef TEST_COUNT_368
#endif
#if (PREDICTED_COUNTER == 368)
  #define TEST_COUNT_368(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_368(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_369
  #undef TEST_COUNT_369
#endif
#if (PREDICTED_COUNTER == 369)
  #define TEST_COUNT_369(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_369(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_370
  #undef TEST_COUNT_370
#endif
#if (PREDICTED_COUNTER == 370)
  #define TEST_COUNT_370(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_370(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_371
  #undef TEST_COUNT_371
#endif
#if (PREDICTED_COUNTER == 371)
  #define TEST_COUNT_371(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_371(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_372
  #undef TEST_COUNT_372
#endif
#if (PREDICTED_COUNTER == 372)
  #define TEST_COUNT_372(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_372(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_373
  #undef TEST_COUNT_373
#endif
#if (PREDICTED_COUNTER == 373)
  #define TEST_COUNT_373(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_373(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_374
  #undef TEST_COUNT_374
#endif
#if (PREDICTED_COUNTER == 374)
  #define TEST_COUNT_374(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_374(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_375
  #undef TEST_COUNT_375
#endif
#if (PREDICTED_COUNTER == 375)
  #define TEST_COUNT_375(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_375(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_376
  #undef TEST_COUNT_376
#endif
#if (PREDICTED_COUNTER == 376)
  #define TEST_COUNT_376(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_376(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_377
  #undef TEST_COUNT_377
#endif
#if (PREDICTED_COUNTER == 377)
  #define TEST_COUNT_377(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_377(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_378
  #undef TEST_COUNT_378
#endif
#if (PREDICTED_COUNTER == 378)
  #define TEST_COUNT_378(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_378(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_379
  #undef TEST_COUNT_379
#endif
#if (PREDICTED_COUNTER == 379)
  #define TEST_COUNT_379(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_379(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_380
  #undef TEST_COUNT_380
#endif
#if (PREDICTED_COUNTER == 380)
  #define TEST_COUNT_380(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_380(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_381
  #undef TEST_COUNT_381
#endif
#if (PREDICTED_COUNTER == 381)
  #define TEST_COUNT_381(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_381(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_382
  #undef TEST_COUNT_382
#endif
#if (PREDICTED_COUNTER == 382)
  #define TEST_COUNT_382(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_382(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_383
  #undef TEST_COUNT_383
#endif
#if (PREDICTED_COUNTER == 383)
  #define TEST_COUNT_383(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_383(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_384
  #undef TEST_COUNT_384
#endif
#if (PREDICTED_COUNTER == 384)
  #define TEST_COUNT_384(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_384(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_385
  #undef TEST_COUNT_385
#endif
#if (PREDICTED_COUNTER == 385)
  #define TEST_COUNT_385(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_385(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_386
  #undef TEST_COUNT_386
#endif
#if (PREDICTED_COUNTER == 386)
  #define TEST_COUNT_386(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_386(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_387
  #undef TEST_COUNT_387
#endif
#if (PREDICTED_COUNTER == 387)
  #define TEST_COUNT_387(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_387(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_388
  #undef TEST_COUNT_388
#endif
#if (PREDICTED_COUNTER == 388)
  #define TEST_COUNT_388(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_388(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_389
  #undef TEST_COUNT_389
#endif
#if (PREDICTED_COUNTER == 389)
  #define TEST_COUNT_389(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_389(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_390
  #undef TEST_COUNT_390
#endif
#if (PREDICTED_COUNTER == 390)
  #define TEST_COUNT_390(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_390(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_391
  #undef TEST_COUNT_391
#endif
#if (PREDICTED_COUNTER == 391)
  #define TEST_COUNT_391(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_391(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_392
  #undef TEST_COUNT_392
#endif
#if (PREDICTED_COUNTER == 392)
  #define TEST_COUNT_392(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_392(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_393
  #undef TEST_COUNT_393
#endif
#if (PREDICTED_COUNTER == 393)
  #define TEST_COUNT_393(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_393(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_394
  #undef TEST_COUNT_394
#endif
#if (PREDICTED_COUNTER == 394)
  #define TEST_COUNT_394(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_394(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_395
  #undef TEST_COUNT_395
#endif
#if (PREDICTED_COUNTER == 395)
  #define TEST_COUNT_395(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_395(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_396
  #undef TEST_COUNT_396
#endif
#if (PREDICTED_COUNTER == 396)
  #define TEST_COUNT_396(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_396(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_397
  #undef TEST_COUNT_397
#endif
#if (PREDICTED_COUNTER == 397)
  #define TEST_COUNT_397(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_397(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_398
  #undef TEST_COUNT_398
#endif
#if (PREDICTED_COUNTER == 398)
  #define TEST_COUNT_398(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_398(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_399
  #undef TEST_COUNT_399
#endif
#if (PREDICTED_COUNTER == 399)
  #define TEST_COUNT_399(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_399(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_400
  #undef TEST_COUNT_400
#endif
#if (PREDICTED_COUNTER == 400)
  #define TEST_COUNT_400(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_400(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_401
  #undef TEST_COUNT_401
#endif
#if (PREDICTED_COUNTER == 401)
  #define TEST_COUNT_401(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_401(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_402
  #undef TEST_COUNT_402
#endif
#if (PREDICTED_COUNTER == 402)
  #define TEST_COUNT_402(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_402(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_403
  #undef TEST_COUNT_403
#endif
#if (PREDICTED_COUNTER == 403)
  #define TEST_COUNT_403(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_403(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_404
  #undef TEST_COUNT_404
#endif
#if (PREDICTED_COUNTER == 404)
  #define TEST_COUNT_404(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_404(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_405
  #undef TEST_COUNT_405
#endif
#if (PREDICTED_COUNTER == 405)
  #define TEST_COUNT_405(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_405(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_406
  #undef TEST_COUNT_406
#endif
#if (PREDICTED_COUNTER == 406)
  #define TEST_COUNT_406(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_406(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_407
  #undef TEST_COUNT_407
#endif
#if (PREDICTED_COUNTER == 407)
  #define TEST_COUNT_407(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_407(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_408
  #undef TEST_COUNT_408
#endif
#if (PREDICTED_COUNTER == 408)
  #define TEST_COUNT_408(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_408(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_409
  #undef TEST_COUNT_409
#endif
#if (PREDICTED_COUNTER == 409)
  #define TEST_COUNT_409(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_409(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_410
  #undef TEST_COUNT_410
#endif
#if (PREDICTED_COUNTER == 410)
  #define TEST_COUNT_410(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_410(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_411
  #undef TEST_COUNT_411
#endif
#if (PREDICTED_COUNTER == 411)
  #define TEST_COUNT_411(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_411(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_412
  #undef TEST_COUNT_412
#endif
#if (PREDICTED_COUNTER == 412)
  #define TEST_COUNT_412(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_412(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_413
  #undef TEST_COUNT_413
#endif
#if (PREDICTED_COUNTER == 413)
  #define TEST_COUNT_413(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_413(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_414
  #undef TEST_COUNT_414
#endif
#if (PREDICTED_COUNTER == 414)
  #define TEST_COUNT_414(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_414(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_415
  #undef TEST_COUNT_415
#endif
#if (PREDICTED_COUNTER == 415)
  #define TEST_COUNT_415(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_415(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_416
  #undef TEST_COUNT_416
#endif
#if (PREDICTED_COUNTER == 416)
  #define TEST_COUNT_416(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_416(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_417
  #undef TEST_COUNT_417
#endif
#if (PREDICTED_COUNTER == 417)
  #define TEST_COUNT_417(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_417(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_418
  #undef TEST_COUNT_418
#endif
#if (PREDICTED_COUNTER == 418)
  #define TEST_COUNT_418(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_418(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_419
  #undef TEST_COUNT_419
#endif
#if (PREDICTED_COUNTER == 419)
  #define TEST_COUNT_419(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_419(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_420
  #undef TEST_COUNT_420
#endif
#if (PREDICTED_COUNTER == 420)
  #define TEST_COUNT_420(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_420(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_421
  #undef TEST_COUNT_421
#endif
#if (PREDICTED_COUNTER == 421)
  #define TEST_COUNT_421(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_421(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_422
  #undef TEST_COUNT_422
#endif
#if (PREDICTED_COUNTER == 422)
  #define TEST_COUNT_422(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_422(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_423
  #undef TEST_COUNT_423
#endif
#if (PREDICTED_COUNTER == 423)
  #define TEST_COUNT_423(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_423(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_424
  #undef TEST_COUNT_424
#endif
#if (PREDICTED_COUNTER == 424)
  #define TEST_COUNT_424(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_424(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_425
  #undef TEST_COUNT_425
#endif
#if (PREDICTED_COUNTER == 425)
  #define TEST_COUNT_425(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_425(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_426
  #undef TEST_COUNT_426
#endif
#if (PREDICTED_COUNTER == 426)
  #define TEST_COUNT_426(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_426(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_427
  #undef TEST_COUNT_427
#endif
#if (PREDICTED_COUNTER == 427)
  #define TEST_COUNT_427(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_427(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_428
  #undef TEST_COUNT_428
#endif
#if (PREDICTED_COUNTER == 428)
  #define TEST_COUNT_428(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_428(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_429
  #undef TEST_COUNT_429
#endif
#if (PREDICTED_COUNTER == 429)
  #define TEST_COUNT_429(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_429(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_430
  #undef TEST_COUNT_430
#endif
#if (PREDICTED_COUNTER == 430)
  #define TEST_COUNT_430(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_430(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_431
  #undef TEST_COUNT_431
#endif
#if (PREDICTED_COUNTER == 431)
  #define TEST_COUNT_431(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_431(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_432
  #undef TEST_COUNT_432
#endif
#if (PREDICTED_COUNTER == 432)
  #define TEST_COUNT_432(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_432(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_433
  #undef TEST_COUNT_433
#endif
#if (PREDICTED_COUNTER == 433)
  #define TEST_COUNT_433(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_433(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_434
  #undef TEST_COUNT_434
#endif
#if (PREDICTED_COUNTER == 434)
  #define TEST_COUNT_434(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_434(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_435
  #undef TEST_COUNT_435
#endif
#if (PREDICTED_COUNTER == 435)
  #define TEST_COUNT_435(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_435(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_436
  #undef TEST_COUNT_436
#endif
#if (PREDICTED_COUNTER == 436)
  #define TEST_COUNT_436(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_436(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_437
  #undef TEST_COUNT_437
#endif
#if (PREDICTED_COUNTER == 437)
  #define TEST_COUNT_437(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_437(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_438
  #undef TEST_COUNT_438
#endif
#if (PREDICTED_COUNTER == 438)
  #define TEST_COUNT_438(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_438(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_439
  #undef TEST_COUNT_439
#endif
#if (PREDICTED_COUNTER == 439)
  #define TEST_COUNT_439(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_439(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_440
  #undef TEST_COUNT_440
#endif
#if (PREDICTED_COUNTER == 440)
  #define TEST_COUNT_440(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_440(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_441
  #undef TEST_COUNT_441
#endif
#if (PREDICTED_COUNTER == 441)
  #define TEST_COUNT_441(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_441(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_442
  #undef TEST_COUNT_442
#endif
#if (PREDICTED_COUNTER == 442)
  #define TEST_COUNT_442(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_442(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_443
  #undef TEST_COUNT_443
#endif
#if (PREDICTED_COUNTER == 443)
  #define TEST_COUNT_443(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_443(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_444
  #undef TEST_COUNT_444
#endif
#if (PREDICTED_COUNTER == 444)
  #define TEST_COUNT_444(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_444(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_445
  #undef TEST_COUNT_445
#endif
#if (PREDICTED_COUNTER == 445)
  #define TEST_COUNT_445(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_445(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_446
  #undef TEST_COUNT_446
#endif
#if (PREDICTED_COUNTER == 446)
  #define TEST_COUNT_446(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_446(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_447
  #undef TEST_COUNT_447
#endif
#if (PREDICTED_COUNTER == 447)
  #define TEST_COUNT_447(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_447(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_448
  #undef TEST_COUNT_448
#endif
#if (PREDICTED_COUNTER == 448)
  #define TEST_COUNT_448(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_448(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_449
  #undef TEST_COUNT_449
#endif
#if (PREDICTED_COUNTER == 449)
  #define TEST_COUNT_449(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_449(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_450
  #undef TEST_COUNT_450
#endif
#if (PREDICTED_COUNTER == 450)
  #define TEST_COUNT_450(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_450(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_451
  #undef TEST_COUNT_451
#endif
#if (PREDICTED_COUNTER == 451)
  #define TEST_COUNT_451(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_451(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_452
  #undef TEST_COUNT_452
#endif
#if (PREDICTED_COUNTER == 452)
  #define TEST_COUNT_452(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_452(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_453
  #undef TEST_COUNT_453
#endif
#if (PREDICTED_COUNTER == 453)
  #define TEST_COUNT_453(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_453(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_454
  #undef TEST_COUNT_454
#endif
#if (PREDICTED_COUNTER == 454)
  #define TEST_COUNT_454(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_454(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_455
  #undef TEST_COUNT_455
#endif
#if (PREDICTED_COUNTER == 455)
  #define TEST_COUNT_455(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_455(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_456
  #undef TEST_COUNT_456
#endif
#if (PREDICTED_COUNTER == 456)
  #define TEST_COUNT_456(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_456(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_457
  #undef TEST_COUNT_457
#endif
#if (PREDICTED_COUNTER == 457)
  #define TEST_COUNT_457(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_457(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_458
  #undef TEST_COUNT_458
#endif
#if (PREDICTED_COUNTER == 458)
  #define TEST_COUNT_458(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_458(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_459
  #undef TEST_COUNT_459
#endif
#if (PREDICTED_COUNTER == 459)
  #define TEST_COUNT_459(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_459(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_460
  #undef TEST_COUNT_460
#endif
#if (PREDICTED_COUNTER == 460)
  #define TEST_COUNT_460(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_460(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_461
  #undef TEST_COUNT_461
#endif
#if (PREDICTED_COUNTER == 461)
  #define TEST_COUNT_461(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_461(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_462
  #undef TEST_COUNT_462
#endif
#if (PREDICTED_COUNTER == 462)
  #define TEST_COUNT_462(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_462(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_463
  #undef TEST_COUNT_463
#endif
#if (PREDICTED_COUNTER == 463)
  #define TEST_COUNT_463(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_463(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_464
  #undef TEST_COUNT_464
#endif
#if (PREDICTED_COUNTER == 464)
  #define TEST_COUNT_464(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_464(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_465
  #undef TEST_COUNT_465
#endif
#if (PREDICTED_COUNTER == 465)
  #define TEST_COUNT_465(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_465(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_466
  #undef TEST_COUNT_466
#endif
#if (PREDICTED_COUNTER == 466)
  #define TEST_COUNT_466(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_466(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_467
  #undef TEST_COUNT_467
#endif
#if (PREDICTED_COUNTER == 467)
  #define TEST_COUNT_467(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_467(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_468
  #undef TEST_COUNT_468
#endif
#if (PREDICTED_COUNTER == 468)
  #define TEST_COUNT_468(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_468(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_469
  #undef TEST_COUNT_469
#endif
#if (PREDICTED_COUNTER == 469)
  #define TEST_COUNT_469(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_469(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_470
  #undef TEST_COUNT_470
#endif
#if (PREDICTED_COUNTER == 470)
  #define TEST_COUNT_470(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_470(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_471
  #undef TEST_COUNT_471
#endif
#if (PREDICTED_COUNTER == 471)
  #define TEST_COUNT_471(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_471(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_472
  #undef TEST_COUNT_472
#endif
#if (PREDICTED_COUNTER == 472)
  #define TEST_COUNT_472(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_472(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_473
  #undef TEST_COUNT_473
#endif
#if (PREDICTED_COUNTER == 473)
  #define TEST_COUNT_473(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_473(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_474
  #undef TEST_COUNT_474
#endif
#if (PREDICTED_COUNTER == 474)
  #define TEST_COUNT_474(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_474(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_475
  #undef TEST_COUNT_475
#endif
#if (PREDICTED_COUNTER == 475)
  #define TEST_COUNT_475(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_475(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_476
  #undef TEST_COUNT_476
#endif
#if (PREDICTED_COUNTER == 476)
  #define TEST_COUNT_476(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_476(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_477
  #undef TEST_COUNT_477
#endif
#if (PREDICTED_COUNTER == 477)
  #define TEST_COUNT_477(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_477(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_478
  #undef TEST_COUNT_478
#endif
#if (PREDICTED_COUNTER == 478)
  #define TEST_COUNT_478(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_478(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_479
  #undef TEST_COUNT_479
#endif
#if (PREDICTED_COUNTER == 479)
  #define TEST_COUNT_479(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_479(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_480
  #undef TEST_COUNT_480
#endif
#if (PREDICTED_COUNTER == 480)
  #define TEST_COUNT_480(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_480(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_481
  #undef TEST_COUNT_481
#endif
#if (PREDICTED_COUNTER == 481)
  #define TEST_COUNT_481(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_481(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_482
  #undef TEST_COUNT_482
#endif
#if (PREDICTED_COUNTER == 482)
  #define TEST_COUNT_482(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_482(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_483
  #undef TEST_COUNT_483
#endif
#if (PREDICTED_COUNTER == 483)
  #define TEST_COUNT_483(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_483(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_484
  #undef TEST_COUNT_484
#endif
#if (PREDICTED_COUNTER == 484)
  #define TEST_COUNT_484(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_484(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_485
  #undef TEST_COUNT_485
#endif
#if (PREDICTED_COUNTER == 485)
  #define TEST_COUNT_485(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_485(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_486
  #undef TEST_COUNT_486
#endif
#if (PREDICTED_COUNTER == 486)
  #define TEST_COUNT_486(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_486(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_487
  #undef TEST_COUNT_487
#endif
#if (PREDICTED_COUNTER == 487)
  #define TEST_COUNT_487(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_487(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_488
  #undef TEST_COUNT_488
#endif
#if (PREDICTED_COUNTER == 488)
  #define TEST_COUNT_488(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_488(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_489
  #undef TEST_COUNT_489
#endif
#if (PREDICTED_COUNTER == 489)
  #define TEST_COUNT_489(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_489(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_490
  #undef TEST_COUNT_490
#endif
#if (PREDICTED_COUNTER == 490)
  #define TEST_COUNT_490(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_490(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_491
  #undef TEST_COUNT_491
#endif
#if (PREDICTED_COUNTER == 491)
  #define TEST_COUNT_491(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_491(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_492
  #undef TEST_COUNT_492
#endif
#if (PREDICTED_COUNTER == 492)
  #define TEST_COUNT_492(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_492(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_493
  #undef TEST_COUNT_493
#endif
#if (PREDICTED_COUNTER == 493)
  #define TEST_COUNT_493(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_493(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_494
  #undef TEST_COUNT_494
#endif
#if (PREDICTED_COUNTER == 494)
  #define TEST_COUNT_494(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_494(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_495
  #undef TEST_COUNT_495
#endif
#if (PREDICTED_COUNTER == 495)
  #define TEST_COUNT_495(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_495(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_496
  #undef TEST_COUNT_496
#endif
#if (PREDICTED_COUNTER == 496)
  #define TEST_COUNT_496(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_496(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_497
  #undef TEST_COUNT_497
#endif
#if (PREDICTED_COUNTER == 497)
  #define TEST_COUNT_497(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_497(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_498
  #undef TEST_COUNT_498
#endif
#if (PREDICTED_COUNTER == 498)
  #define TEST_COUNT_498(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_498(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_499
  #undef TEST_COUNT_499
#endif
#if (PREDICTED_COUNTER == 499)
  #define TEST_COUNT_499(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_499(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_500
  #undef TEST_COUNT_500
#endif
#if (PREDICTED_COUNTER == 500)
  #define TEST_COUNT_500(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_500(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_501
  #undef TEST_COUNT_501
#endif
#if (PREDICTED_COUNTER == 501)
  #define TEST_COUNT_501(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_501(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_502
  #undef TEST_COUNT_502
#endif
#if (PREDICTED_COUNTER == 502)
  #define TEST_COUNT_502(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_502(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_503
  #undef TEST_COUNT_503
#endif
#if (PREDICTED_COUNTER == 503)
  #define TEST_COUNT_503(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_503(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_504
  #undef TEST_COUNT_504
#endif
#if (PREDICTED_COUNTER == 504)
  #define TEST_COUNT_504(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_504(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_505
  #undef TEST_COUNT_505
#endif
#if (PREDICTED_COUNTER == 505)
  #define TEST_COUNT_505(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_505(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_506
  #undef TEST_COUNT_506
#endif
#if (PREDICTED_COUNTER == 506)
  #define TEST_COUNT_506(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_506(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_507
  #undef TEST_COUNT_507
#endif
#if (PREDICTED_COUNTER == 507)
  #define TEST_COUNT_507(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_507(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_508
  #undef TEST_COUNT_508
#endif
#if (PREDICTED_COUNTER == 508)
  #define TEST_COUNT_508(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_508(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_509
  #undef TEST_COUNT_509
#endif
#if (PREDICTED_COUNTER == 509)
  #define TEST_COUNT_509(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_509(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_510
  #undef TEST_COUNT_510
#endif
#if (PREDICTED_COUNTER == 510)
  #define TEST_COUNT_510(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_510(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_511
  #undef TEST_COUNT_511
#endif
#if (PREDICTED_COUNTER == 511)
  #define TEST_COUNT_511(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_511(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_512
  #undef TEST_COUNT_512
#endif
#if (PREDICTED_COUNTER == 512)
  #define TEST_COUNT_512(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_512(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_513
  #undef TEST_COUNT_513
#endif
#if (PREDICTED_COUNTER == 513)
  #define TEST_COUNT_513(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_513(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_514
  #undef TEST_COUNT_514
#endif
#if (PREDICTED_COUNTER == 514)
  #define TEST_COUNT_514(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_514(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_515
  #undef TEST_COUNT_515
#endif
#if (PREDICTED_COUNTER == 515)
  #define TEST_COUNT_515(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_515(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_516
  #undef TEST_COUNT_516
#endif
#if (PREDICTED_COUNTER == 516)
  #define TEST_COUNT_516(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_516(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_517
  #undef TEST_COUNT_517
#endif
#if (PREDICTED_COUNTER == 517)
  #define TEST_COUNT_517(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_517(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_518
  #undef TEST_COUNT_518
#endif
#if (PREDICTED_COUNTER == 518)
  #define TEST_COUNT_518(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_518(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_519
  #undef TEST_COUNT_519
#endif
#if (PREDICTED_COUNTER == 519)
  #define TEST_COUNT_519(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_519(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_520
  #undef TEST_COUNT_520
#endif
#if (PREDICTED_COUNTER == 520)
  #define TEST_COUNT_520(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_520(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_521
  #undef TEST_COUNT_521
#endif
#if (PREDICTED_COUNTER == 521)
  #define TEST_COUNT_521(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_521(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_522
  #undef TEST_COUNT_522
#endif
#if (PREDICTED_COUNTER == 522)
  #define TEST_COUNT_522(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_522(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_523
  #undef TEST_COUNT_523
#endif
#if (PREDICTED_COUNTER == 523)
  #define TEST_COUNT_523(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_523(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_524
  #undef TEST_COUNT_524
#endif
#if (PREDICTED_COUNTER == 524)
  #define TEST_COUNT_524(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_524(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_525
  #undef TEST_COUNT_525
#endif
#if (PREDICTED_COUNTER == 525)
  #define TEST_COUNT_525(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_525(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_526
  #undef TEST_COUNT_526
#endif
#if (PREDICTED_COUNTER == 526)
  #define TEST_COUNT_526(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_526(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_527
  #undef TEST_COUNT_527
#endif
#if (PREDICTED_COUNTER == 527)
  #define TEST_COUNT_527(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_527(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_528
  #undef TEST_COUNT_528
#endif
#if (PREDICTED_COUNTER == 528)
  #define TEST_COUNT_528(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_528(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_529
  #undef TEST_COUNT_529
#endif
#if (PREDICTED_COUNTER == 529)
  #define TEST_COUNT_529(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_529(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_530
  #undef TEST_COUNT_530
#endif
#if (PREDICTED_COUNTER == 530)
  #define TEST_COUNT_530(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_530(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_531
  #undef TEST_COUNT_531
#endif
#if (PREDICTED_COUNTER == 531)
  #define TEST_COUNT_531(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_531(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_532
  #undef TEST_COUNT_532
#endif
#if (PREDICTED_COUNTER == 532)
  #define TEST_COUNT_532(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_532(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_533
  #undef TEST_COUNT_533
#endif
#if (PREDICTED_COUNTER == 533)
  #define TEST_COUNT_533(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_533(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_534
  #undef TEST_COUNT_534
#endif
#if (PREDICTED_COUNTER == 534)
  #define TEST_COUNT_534(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_534(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_535
  #undef TEST_COUNT_535
#endif
#if (PREDICTED_COUNTER == 535)
  #define TEST_COUNT_535(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_535(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_536
  #undef TEST_COUNT_536
#endif
#if (PREDICTED_COUNTER == 536)
  #define TEST_COUNT_536(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_536(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_537
  #undef TEST_COUNT_537
#endif
#if (PREDICTED_COUNTER == 537)
  #define TEST_COUNT_537(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_537(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_538
  #undef TEST_COUNT_538
#endif
#if (PREDICTED_COUNTER == 538)
  #define TEST_COUNT_538(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_538(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_539
  #undef TEST_COUNT_539
#endif
#if (PREDICTED_COUNTER == 539)
  #define TEST_COUNT_539(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_539(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_540
  #undef TEST_COUNT_540
#endif
#if (PREDICTED_COUNTER == 540)
  #define TEST_COUNT_540(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_540(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_541
  #undef TEST_COUNT_541
#endif
#if (PREDICTED_COUNTER == 541)
  #define TEST_COUNT_541(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_541(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_542
  #undef TEST_COUNT_542
#endif
#if (PREDICTED_COUNTER == 542)
  #define TEST_COUNT_542(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_542(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_543
  #undef TEST_COUNT_543
#endif
#if (PREDICTED_COUNTER == 543)
  #define TEST_COUNT_543(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_543(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_544
  #undef TEST_COUNT_544
#endif
#if (PREDICTED_COUNTER == 544)
  #define TEST_COUNT_544(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_544(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_545
  #undef TEST_COUNT_545
#endif
#if (PREDICTED_COUNTER == 545)
  #define TEST_COUNT_545(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_545(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_546
  #undef TEST_COUNT_546
#endif
#if (PREDICTED_COUNTER == 546)
  #define TEST_COUNT_546(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_546(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_547
  #undef TEST_COUNT_547
#endif
#if (PREDICTED_COUNTER == 547)
  #define TEST_COUNT_547(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_547(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_548
  #undef TEST_COUNT_548
#endif
#if (PREDICTED_COUNTER == 548)
  #define TEST_COUNT_548(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_548(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_549
  #undef TEST_COUNT_549
#endif
#if (PREDICTED_COUNTER == 549)
  #define TEST_COUNT_549(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_549(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_550
  #undef TEST_COUNT_550
#endif
#if (PREDICTED_COUNTER == 550)
  #define TEST_COUNT_550(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_550(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_551
  #undef TEST_COUNT_551
#endif
#if (PREDICTED_COUNTER == 551)
  #define TEST_COUNT_551(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_551(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_552
  #undef TEST_COUNT_552
#endif
#if (PREDICTED_COUNTER == 552)
  #define TEST_COUNT_552(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_552(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_553
  #undef TEST_COUNT_553
#endif
#if (PREDICTED_COUNTER == 553)
  #define TEST_COUNT_553(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_553(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_554
  #undef TEST_COUNT_554
#endif
#if (PREDICTED_COUNTER == 554)
  #define TEST_COUNT_554(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_554(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_555
  #undef TEST_COUNT_555
#endif
#if (PREDICTED_COUNTER == 555)
  #define TEST_COUNT_555(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_555(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_556
  #undef TEST_COUNT_556
#endif
#if (PREDICTED_COUNTER == 556)
  #define TEST_COUNT_556(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_556(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_557
  #undef TEST_COUNT_557
#endif
#if (PREDICTED_COUNTER == 557)
  #define TEST_COUNT_557(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_557(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_558
  #undef TEST_COUNT_558
#endif
#if (PREDICTED_COUNTER == 558)
  #define TEST_COUNT_558(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_558(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_559
  #undef TEST_COUNT_559
#endif
#if (PREDICTED_COUNTER == 559)
  #define TEST_COUNT_559(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_559(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_560
  #undef TEST_COUNT_560
#endif
#if (PREDICTED_COUNTER == 560)
  #define TEST_COUNT_560(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_560(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_561
  #undef TEST_COUNT_561
#endif
#if (PREDICTED_COUNTER == 561)
  #define TEST_COUNT_561(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_561(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_562
  #undef TEST_COUNT_562
#endif
#if (PREDICTED_COUNTER == 562)
  #define TEST_COUNT_562(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_562(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_563
  #undef TEST_COUNT_563
#endif
#if (PREDICTED_COUNTER == 563)
  #define TEST_COUNT_563(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_563(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_564
  #undef TEST_COUNT_564
#endif
#if (PREDICTED_COUNTER == 564)
  #define TEST_COUNT_564(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_564(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_565
  #undef TEST_COUNT_565
#endif
#if (PREDICTED_COUNTER == 565)
  #define TEST_COUNT_565(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_565(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_566
  #undef TEST_COUNT_566
#endif
#if (PREDICTED_COUNTER == 566)
  #define TEST_COUNT_566(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_566(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_567
  #undef TEST_COUNT_567
#endif
#if (PREDICTED_COUNTER == 567)
  #define TEST_COUNT_567(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_567(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_568
  #undef TEST_COUNT_568
#endif
#if (PREDICTED_COUNTER == 568)
  #define TEST_COUNT_568(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_568(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_569
  #undef TEST_COUNT_569
#endif
#if (PREDICTED_COUNTER == 569)
  #define TEST_COUNT_569(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_569(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_570
  #undef TEST_COUNT_570
#endif
#if (PREDICTED_COUNTER == 570)
  #define TEST_COUNT_570(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_570(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_571
  #undef TEST_COUNT_571
#endif
#if (PREDICTED_COUNTER == 571)
  #define TEST_COUNT_571(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_571(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_572
  #undef TEST_COUNT_572
#endif
#if (PREDICTED_COUNTER == 572)
  #define TEST_COUNT_572(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_572(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_573
  #undef TEST_COUNT_573
#endif
#if (PREDICTED_COUNTER == 573)
  #define TEST_COUNT_573(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_573(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_574
  #undef TEST_COUNT_574
#endif
#if (PREDICTED_COUNTER == 574)
  #define TEST_COUNT_574(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_574(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_575
  #undef TEST_COUNT_575
#endif
#if (PREDICTED_COUNTER == 575)
  #define TEST_COUNT_575(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_575(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_576
  #undef TEST_COUNT_576
#endif
#if (PREDICTED_COUNTER == 576)
  #define TEST_COUNT_576(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_576(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_577
  #undef TEST_COUNT_577
#endif
#if (PREDICTED_COUNTER == 577)
  #define TEST_COUNT_577(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_577(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_578
  #undef TEST_COUNT_578
#endif
#if (PREDICTED_COUNTER == 578)
  #define TEST_COUNT_578(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_578(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_579
  #undef TEST_COUNT_579
#endif
#if (PREDICTED_COUNTER == 579)
  #define TEST_COUNT_579(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_579(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_580
  #undef TEST_COUNT_580
#endif
#if (PREDICTED_COUNTER == 580)
  #define TEST_COUNT_580(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_580(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_581
  #undef TEST_COUNT_581
#endif
#if (PREDICTED_COUNTER == 581)
  #define TEST_COUNT_581(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_581(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_582
  #undef TEST_COUNT_582
#endif
#if (PREDICTED_COUNTER == 582)
  #define TEST_COUNT_582(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_582(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_583
  #undef TEST_COUNT_583
#endif
#if (PREDICTED_COUNTER == 583)
  #define TEST_COUNT_583(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_583(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_584
  #undef TEST_COUNT_584
#endif
#if (PREDICTED_COUNTER == 584)
  #define TEST_COUNT_584(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_584(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_585
  #undef TEST_COUNT_585
#endif
#if (PREDICTED_COUNTER == 585)
  #define TEST_COUNT_585(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_585(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_586
  #undef TEST_COUNT_586
#endif
#if (PREDICTED_COUNTER == 586)
  #define TEST_COUNT_586(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_586(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_587
  #undef TEST_COUNT_587
#endif
#if (PREDICTED_COUNTER == 587)
  #define TEST_COUNT_587(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_587(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_588
  #undef TEST_COUNT_588
#endif
#if (PREDICTED_COUNTER == 588)
  #define TEST_COUNT_588(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_588(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_589
  #undef TEST_COUNT_589
#endif
#if (PREDICTED_COUNTER == 589)
  #define TEST_COUNT_589(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_589(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_590
  #undef TEST_COUNT_590
#endif
#if (PREDICTED_COUNTER == 590)
  #define TEST_COUNT_590(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_590(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_591
  #undef TEST_COUNT_591
#endif
#if (PREDICTED_COUNTER == 591)
  #define TEST_COUNT_591(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_591(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_592
  #undef TEST_COUNT_592
#endif
#if (PREDICTED_COUNTER == 592)
  #define TEST_COUNT_592(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_592(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_593
  #undef TEST_COUNT_593
#endif
#if (PREDICTED_COUNTER == 593)
  #define TEST_COUNT_593(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_593(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_594
  #undef TEST_COUNT_594
#endif
#if (PREDICTED_COUNTER == 594)
  #define TEST_COUNT_594(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_594(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_595
  #undef TEST_COUNT_595
#endif
#if (PREDICTED_COUNTER == 595)
  #define TEST_COUNT_595(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_595(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_596
  #undef TEST_COUNT_596
#endif
#if (PREDICTED_COUNTER == 596)
  #define TEST_COUNT_596(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_596(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_597
  #undef TEST_COUNT_597
#endif
#if (PREDICTED_COUNTER == 597)
  #define TEST_COUNT_597(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_597(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_598
  #undef TEST_COUNT_598
#endif
#if (PREDICTED_COUNTER == 598)
  #define TEST_COUNT_598(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_598(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_599
  #undef TEST_COUNT_599
#endif
#if (PREDICTED_COUNTER == 599)
  #define TEST_COUNT_599(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_599(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_600
  #undef TEST_COUNT_600
#endif
#if (PREDICTED_COUNTER == 600)
  #define TEST_COUNT_600(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_600(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_601
  #undef TEST_COUNT_601
#endif
#if (PREDICTED_COUNTER == 601)
  #define TEST_COUNT_601(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_601(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_602
  #undef TEST_COUNT_602
#endif
#if (PREDICTED_COUNTER == 602)
  #define TEST_COUNT_602(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_602(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_603
  #undef TEST_COUNT_603
#endif
#if (PREDICTED_COUNTER == 603)
  #define TEST_COUNT_603(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_603(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_604
  #undef TEST_COUNT_604
#endif
#if (PREDICTED_COUNTER == 604)
  #define TEST_COUNT_604(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_604(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_605
  #undef TEST_COUNT_605
#endif
#if (PREDICTED_COUNTER == 605)
  #define TEST_COUNT_605(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_605(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_606
  #undef TEST_COUNT_606
#endif
#if (PREDICTED_COUNTER == 606)
  #define TEST_COUNT_606(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_606(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_607
  #undef TEST_COUNT_607
#endif
#if (PREDICTED_COUNTER == 607)
  #define TEST_COUNT_607(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_607(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_608
  #undef TEST_COUNT_608
#endif
#if (PREDICTED_COUNTER == 608)
  #define TEST_COUNT_608(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_608(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_609
  #undef TEST_COUNT_609
#endif
#if (PREDICTED_COUNTER == 609)
  #define TEST_COUNT_609(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_609(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_610
  #undef TEST_COUNT_610
#endif
#if (PREDICTED_COUNTER == 610)
  #define TEST_COUNT_610(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_610(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_611
  #undef TEST_COUNT_611
#endif
#if (PREDICTED_COUNTER == 611)
  #define TEST_COUNT_611(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_611(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_612
  #undef TEST_COUNT_612
#endif
#if (PREDICTED_COUNTER == 612)
  #define TEST_COUNT_612(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_612(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_613
  #undef TEST_COUNT_613
#endif
#if (PREDICTED_COUNTER == 613)
  #define TEST_COUNT_613(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_613(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_614
  #undef TEST_COUNT_614
#endif
#if (PREDICTED_COUNTER == 614)
  #define TEST_COUNT_614(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_614(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_615
  #undef TEST_COUNT_615
#endif
#if (PREDICTED_COUNTER == 615)
  #define TEST_COUNT_615(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_615(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_616
  #undef TEST_COUNT_616
#endif
#if (PREDICTED_COUNTER == 616)
  #define TEST_COUNT_616(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_616(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_617
  #undef TEST_COUNT_617
#endif
#if (PREDICTED_COUNTER == 617)
  #define TEST_COUNT_617(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_617(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_618
  #undef TEST_COUNT_618
#endif
#if (PREDICTED_COUNTER == 618)
  #define TEST_COUNT_618(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_618(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_619
  #undef TEST_COUNT_619
#endif
#if (PREDICTED_COUNTER == 619)
  #define TEST_COUNT_619(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_619(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_620
  #undef TEST_COUNT_620
#endif
#if (PREDICTED_COUNTER == 620)
  #define TEST_COUNT_620(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_620(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_621
  #undef TEST_COUNT_621
#endif
#if (PREDICTED_COUNTER == 621)
  #define TEST_COUNT_621(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_621(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_622
  #undef TEST_COUNT_622
#endif
#if (PREDICTED_COUNTER == 622)
  #define TEST_COUNT_622(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_622(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_623
  #undef TEST_COUNT_623
#endif
#if (PREDICTED_COUNTER == 623)
  #define TEST_COUNT_623(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_623(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_624
  #undef TEST_COUNT_624
#endif
#if (PREDICTED_COUNTER == 624)
  #define TEST_COUNT_624(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_624(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_625
  #undef TEST_COUNT_625
#endif
#if (PREDICTED_COUNTER == 625)
  #define TEST_COUNT_625(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_625(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_626
  #undef TEST_COUNT_626
#endif
#if (PREDICTED_COUNTER == 626)
  #define TEST_COUNT_626(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_626(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_627
  #undef TEST_COUNT_627
#endif
#if (PREDICTED_COUNTER == 627)
  #define TEST_COUNT_627(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_627(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_628
  #undef TEST_COUNT_628
#endif
#if (PREDICTED_COUNTER == 628)
  #define TEST_COUNT_628(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_628(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_629
  #undef TEST_COUNT_629
#endif
#if (PREDICTED_COUNTER == 629)
  #define TEST_COUNT_629(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_629(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_630
  #undef TEST_COUNT_630
#endif
#if (PREDICTED_COUNTER == 630)
  #define TEST_COUNT_630(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_630(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_631
  #undef TEST_COUNT_631
#endif
#if (PREDICTED_COUNTER == 631)
  #define TEST_COUNT_631(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_631(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_632
  #undef TEST_COUNT_632
#endif
#if (PREDICTED_COUNTER == 632)
  #define TEST_COUNT_632(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_632(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_633
  #undef TEST_COUNT_633
#endif
#if (PREDICTED_COUNTER == 633)
  #define TEST_COUNT_633(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_633(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_634
  #undef TEST_COUNT_634
#endif
#if (PREDICTED_COUNTER == 634)
  #define TEST_COUNT_634(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_634(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_635
  #undef TEST_COUNT_635
#endif
#if (PREDICTED_COUNTER == 635)
  #define TEST_COUNT_635(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_635(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_636
  #undef TEST_COUNT_636
#endif
#if (PREDICTED_COUNTER == 636)
  #define TEST_COUNT_636(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_636(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_637
  #undef TEST_COUNT_637
#endif
#if (PREDICTED_COUNTER == 637)
  #define TEST_COUNT_637(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_637(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_638
  #undef TEST_COUNT_638
#endif
#if (PREDICTED_COUNTER == 638)
  #define TEST_COUNT_638(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_638(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_639
  #undef TEST_COUNT_639
#endif
#if (PREDICTED_COUNTER == 639)
  #define TEST_COUNT_639(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_639(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_640
  #undef TEST_COUNT_640
#endif
#if (PREDICTED_COUNTER == 640)
  #define TEST_COUNT_640(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_640(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_641
  #undef TEST_COUNT_641
#endif
#if (PREDICTED_COUNTER == 641)
  #define TEST_COUNT_641(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_641(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_642
  #undef TEST_COUNT_642
#endif
#if (PREDICTED_COUNTER == 642)
  #define TEST_COUNT_642(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_642(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_643
  #undef TEST_COUNT_643
#endif
#if (PREDICTED_COUNTER == 643)
  #define TEST_COUNT_643(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_643(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_644
  #undef TEST_COUNT_644
#endif
#if (PREDICTED_COUNTER == 644)
  #define TEST_COUNT_644(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_644(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_645
  #undef TEST_COUNT_645
#endif
#if (PREDICTED_COUNTER == 645)
  #define TEST_COUNT_645(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_645(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_646
  #undef TEST_COUNT_646
#endif
#if (PREDICTED_COUNTER == 646)
  #define TEST_COUNT_646(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_646(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_647
  #undef TEST_COUNT_647
#endif
#if (PREDICTED_COUNTER == 647)
  #define TEST_COUNT_647(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_647(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_648
  #undef TEST_COUNT_648
#endif
#if (PREDICTED_COUNTER == 648)
  #define TEST_COUNT_648(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_648(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_649
  #undef TEST_COUNT_649
#endif
#if (PREDICTED_COUNTER == 649)
  #define TEST_COUNT_649(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_649(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_650
  #undef TEST_COUNT_650
#endif
#if (PREDICTED_COUNTER == 650)
  #define TEST_COUNT_650(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_650(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_651
  #undef TEST_COUNT_651
#endif
#if (PREDICTED_COUNTER == 651)
  #define TEST_COUNT_651(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_651(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_652
  #undef TEST_COUNT_652
#endif
#if (PREDICTED_COUNTER == 652)
  #define TEST_COUNT_652(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_652(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_653
  #undef TEST_COUNT_653
#endif
#if (PREDICTED_COUNTER == 653)
  #define TEST_COUNT_653(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_653(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_654
  #undef TEST_COUNT_654
#endif
#if (PREDICTED_COUNTER == 654)
  #define TEST_COUNT_654(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_654(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_655
  #undef TEST_COUNT_655
#endif
#if (PREDICTED_COUNTER == 655)
  #define TEST_COUNT_655(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_655(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_656
  #undef TEST_COUNT_656
#endif
#if (PREDICTED_COUNTER == 656)
  #define TEST_COUNT_656(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_656(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_657
  #undef TEST_COUNT_657
#endif
#if (PREDICTED_COUNTER == 657)
  #define TEST_COUNT_657(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_657(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_658
  #undef TEST_COUNT_658
#endif
#if (PREDICTED_COUNTER == 658)
  #define TEST_COUNT_658(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_658(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_659
  #undef TEST_COUNT_659
#endif
#if (PREDICTED_COUNTER == 659)
  #define TEST_COUNT_659(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_659(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_660
  #undef TEST_COUNT_660
#endif
#if (PREDICTED_COUNTER == 660)
  #define TEST_COUNT_660(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_660(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_661
  #undef TEST_COUNT_661
#endif
#if (PREDICTED_COUNTER == 661)
  #define TEST_COUNT_661(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_661(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_662
  #undef TEST_COUNT_662
#endif
#if (PREDICTED_COUNTER == 662)
  #define TEST_COUNT_662(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_662(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_663
  #undef TEST_COUNT_663
#endif
#if (PREDICTED_COUNTER == 663)
  #define TEST_COUNT_663(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_663(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_664
  #undef TEST_COUNT_664
#endif
#if (PREDICTED_COUNTER == 664)
  #define TEST_COUNT_664(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_664(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_665
  #undef TEST_COUNT_665
#endif
#if (PREDICTED_COUNTER == 665)
  #define TEST_COUNT_665(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_665(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_666
  #undef TEST_COUNT_666
#endif
#if (PREDICTED_COUNTER == 666)
  #define TEST_COUNT_666(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_666(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_667
  #undef TEST_COUNT_667
#endif
#if (PREDICTED_COUNTER == 667)
  #define TEST_COUNT_667(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_667(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_668
  #undef TEST_COUNT_668
#endif
#if (PREDICTED_COUNTER == 668)
  #define TEST_COUNT_668(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_668(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_669
  #undef TEST_COUNT_669
#endif
#if (PREDICTED_COUNTER == 669)
  #define TEST_COUNT_669(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_669(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_670
  #undef TEST_COUNT_670
#endif
#if (PREDICTED_COUNTER == 670)
  #define TEST_COUNT_670(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_670(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_671
  #undef TEST_COUNT_671
#endif
#if (PREDICTED_COUNTER == 671)
  #define TEST_COUNT_671(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_671(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_672
  #undef TEST_COUNT_672
#endif
#if (PREDICTED_COUNTER == 672)
  #define TEST_COUNT_672(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_672(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_673
  #undef TEST_COUNT_673
#endif
#if (PREDICTED_COUNTER == 673)
  #define TEST_COUNT_673(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_673(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_674
  #undef TEST_COUNT_674
#endif
#if (PREDICTED_COUNTER == 674)
  #define TEST_COUNT_674(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_674(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_675
  #undef TEST_COUNT_675
#endif
#if (PREDICTED_COUNTER == 675)
  #define TEST_COUNT_675(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_675(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_676
  #undef TEST_COUNT_676
#endif
#if (PREDICTED_COUNTER == 676)
  #define TEST_COUNT_676(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_676(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_677
  #undef TEST_COUNT_677
#endif
#if (PREDICTED_COUNTER == 677)
  #define TEST_COUNT_677(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_677(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_678
  #undef TEST_COUNT_678
#endif
#if (PREDICTED_COUNTER == 678)
  #define TEST_COUNT_678(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_678(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_679
  #undef TEST_COUNT_679
#endif
#if (PREDICTED_COUNTER == 679)
  #define TEST_COUNT_679(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_679(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_680
  #undef TEST_COUNT_680
#endif
#if (PREDICTED_COUNTER == 680)
  #define TEST_COUNT_680(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_680(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_681
  #undef TEST_COUNT_681
#endif
#if (PREDICTED_COUNTER == 681)
  #define TEST_COUNT_681(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_681(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_682
  #undef TEST_COUNT_682
#endif
#if (PREDICTED_COUNTER == 682)
  #define TEST_COUNT_682(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_682(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_683
  #undef TEST_COUNT_683
#endif
#if (PREDICTED_COUNTER == 683)
  #define TEST_COUNT_683(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_683(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_684
  #undef TEST_COUNT_684
#endif
#if (PREDICTED_COUNTER == 684)
  #define TEST_COUNT_684(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_684(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_685
  #undef TEST_COUNT_685
#endif
#if (PREDICTED_COUNTER == 685)
  #define TEST_COUNT_685(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_685(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_686
  #undef TEST_COUNT_686
#endif
#if (PREDICTED_COUNTER == 686)
  #define TEST_COUNT_686(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_686(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_687
  #undef TEST_COUNT_687
#endif
#if (PREDICTED_COUNTER == 687)
  #define TEST_COUNT_687(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_687(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_688
  #undef TEST_COUNT_688
#endif
#if (PREDICTED_COUNTER == 688)
  #define TEST_COUNT_688(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_688(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_689
  #undef TEST_COUNT_689
#endif
#if (PREDICTED_COUNTER == 689)
  #define TEST_COUNT_689(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_689(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_690
  #undef TEST_COUNT_690
#endif
#if (PREDICTED_COUNTER == 690)
  #define TEST_COUNT_690(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_690(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_691
  #undef TEST_COUNT_691
#endif
#if (PREDICTED_COUNTER == 691)
  #define TEST_COUNT_691(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_691(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_692
  #undef TEST_COUNT_692
#endif
#if (PREDICTED_COUNTER == 692)
  #define TEST_COUNT_692(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_692(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_693
  #undef TEST_COUNT_693
#endif
#if (PREDICTED_COUNTER == 693)
  #define TEST_COUNT_693(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_693(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_694
  #undef TEST_COUNT_694
#endif
#if (PREDICTED_COUNTER == 694)
  #define TEST_COUNT_694(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_694(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_695
  #undef TEST_COUNT_695
#endif
#if (PREDICTED_COUNTER == 695)
  #define TEST_COUNT_695(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_695(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_696
  #undef TEST_COUNT_696
#endif
#if (PREDICTED_COUNTER == 696)
  #define TEST_COUNT_696(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_696(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_697
  #undef TEST_COUNT_697
#endif
#if (PREDICTED_COUNTER == 697)
  #define TEST_COUNT_697(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_697(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_698
  #undef TEST_COUNT_698
#endif
#if (PREDICTED_COUNTER == 698)
  #define TEST_COUNT_698(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_698(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_699
  #undef TEST_COUNT_699
#endif
#if (PREDICTED_COUNTER == 699)
  #define TEST_COUNT_699(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_699(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_700
  #undef TEST_COUNT_700
#endif
#if (PREDICTED_COUNTER == 700)
  #define TEST_COUNT_700(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_700(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_701
  #undef TEST_COUNT_701
#endif
#if (PREDICTED_COUNTER == 701)
  #define TEST_COUNT_701(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_701(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_702
  #undef TEST_COUNT_702
#endif
#if (PREDICTED_COUNTER == 702)
  #define TEST_COUNT_702(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_702(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_703
  #undef TEST_COUNT_703
#endif
#if (PREDICTED_COUNTER == 703)
  #define TEST_COUNT_703(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_703(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_704
  #undef TEST_COUNT_704
#endif
#if (PREDICTED_COUNTER == 704)
  #define TEST_COUNT_704(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_704(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_705
  #undef TEST_COUNT_705
#endif
#if (PREDICTED_COUNTER == 705)
  #define TEST_COUNT_705(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_705(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_706
  #undef TEST_COUNT_706
#endif
#if (PREDICTED_COUNTER == 706)
  #define TEST_COUNT_706(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_706(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_707
  #undef TEST_COUNT_707
#endif
#if (PREDICTED_COUNTER == 707)
  #define TEST_COUNT_707(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_707(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_708
  #undef TEST_COUNT_708
#endif
#if (PREDICTED_COUNTER == 708)
  #define TEST_COUNT_708(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_708(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_709
  #undef TEST_COUNT_709
#endif
#if (PREDICTED_COUNTER == 709)
  #define TEST_COUNT_709(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_709(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_710
  #undef TEST_COUNT_710
#endif
#if (PREDICTED_COUNTER == 710)
  #define TEST_COUNT_710(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_710(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_711
  #undef TEST_COUNT_711
#endif
#if (PREDICTED_COUNTER == 711)
  #define TEST_COUNT_711(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_711(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_712
  #undef TEST_COUNT_712
#endif
#if (PREDICTED_COUNTER == 712)
  #define TEST_COUNT_712(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_712(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_713
  #undef TEST_COUNT_713
#endif
#if (PREDICTED_COUNTER == 713)
  #define TEST_COUNT_713(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_713(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_714
  #undef TEST_COUNT_714
#endif
#if (PREDICTED_COUNTER == 714)
  #define TEST_COUNT_714(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_714(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_715
  #undef TEST_COUNT_715
#endif
#if (PREDICTED_COUNTER == 715)
  #define TEST_COUNT_715(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_715(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_716
  #undef TEST_COUNT_716
#endif
#if (PREDICTED_COUNTER == 716)
  #define TEST_COUNT_716(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_716(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_717
  #undef TEST_COUNT_717
#endif
#if (PREDICTED_COUNTER == 717)
  #define TEST_COUNT_717(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_717(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_718
  #undef TEST_COUNT_718
#endif
#if (PREDICTED_COUNTER == 718)
  #define TEST_COUNT_718(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_718(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_719
  #undef TEST_COUNT_719
#endif
#if (PREDICTED_COUNTER == 719)
  #define TEST_COUNT_719(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_719(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_720
  #undef TEST_COUNT_720
#endif
#if (PREDICTED_COUNTER == 720)
  #define TEST_COUNT_720(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_720(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_721
  #undef TEST_COUNT_721
#endif
#if (PREDICTED_COUNTER == 721)
  #define TEST_COUNT_721(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_721(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_722
  #undef TEST_COUNT_722
#endif
#if (PREDICTED_COUNTER == 722)
  #define TEST_COUNT_722(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_722(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_723
  #undef TEST_COUNT_723
#endif
#if (PREDICTED_COUNTER == 723)
  #define TEST_COUNT_723(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_723(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_724
  #undef TEST_COUNT_724
#endif
#if (PREDICTED_COUNTER == 724)
  #define TEST_COUNT_724(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_724(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_725
  #undef TEST_COUNT_725
#endif
#if (PREDICTED_COUNTER == 725)
  #define TEST_COUNT_725(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_725(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_726
  #undef TEST_COUNT_726
#endif
#if (PREDICTED_COUNTER == 726)
  #define TEST_COUNT_726(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_726(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_727
  #undef TEST_COUNT_727
#endif
#if (PREDICTED_COUNTER == 727)
  #define TEST_COUNT_727(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_727(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_728
  #undef TEST_COUNT_728
#endif
#if (PREDICTED_COUNTER == 728)
  #define TEST_COUNT_728(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_728(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_729
  #undef TEST_COUNT_729
#endif
#if (PREDICTED_COUNTER == 729)
  #define TEST_COUNT_729(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_729(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_730
  #undef TEST_COUNT_730
#endif
#if (PREDICTED_COUNTER == 730)
  #define TEST_COUNT_730(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_730(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_731
  #undef TEST_COUNT_731
#endif
#if (PREDICTED_COUNTER == 731)
  #define TEST_COUNT_731(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_731(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_732
  #undef TEST_COUNT_732
#endif
#if (PREDICTED_COUNTER == 732)
  #define TEST_COUNT_732(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_732(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_733
  #undef TEST_COUNT_733
#endif
#if (PREDICTED_COUNTER == 733)
  #define TEST_COUNT_733(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_733(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_734
  #undef TEST_COUNT_734
#endif
#if (PREDICTED_COUNTER == 734)
  #define TEST_COUNT_734(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_734(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_735
  #undef TEST_COUNT_735
#endif
#if (PREDICTED_COUNTER == 735)
  #define TEST_COUNT_735(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_735(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_736
  #undef TEST_COUNT_736
#endif
#if (PREDICTED_COUNTER == 736)
  #define TEST_COUNT_736(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_736(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_737
  #undef TEST_COUNT_737
#endif
#if (PREDICTED_COUNTER == 737)
  #define TEST_COUNT_737(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_737(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_738
  #undef TEST_COUNT_738
#endif
#if (PREDICTED_COUNTER == 738)
  #define TEST_COUNT_738(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_738(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_739
  #undef TEST_COUNT_739
#endif
#if (PREDICTED_COUNTER == 739)
  #define TEST_COUNT_739(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_739(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_740
  #undef TEST_COUNT_740
#endif
#if (PREDICTED_COUNTER == 740)
  #define TEST_COUNT_740(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_740(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_741
  #undef TEST_COUNT_741
#endif
#if (PREDICTED_COUNTER == 741)
  #define TEST_COUNT_741(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_741(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_742
  #undef TEST_COUNT_742
#endif
#if (PREDICTED_COUNTER == 742)
  #define TEST_COUNT_742(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_742(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_743
  #undef TEST_COUNT_743
#endif
#if (PREDICTED_COUNTER == 743)
  #define TEST_COUNT_743(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_743(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_744
  #undef TEST_COUNT_744
#endif
#if (PREDICTED_COUNTER == 744)
  #define TEST_COUNT_744(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_744(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_745
  #undef TEST_COUNT_745
#endif
#if (PREDICTED_COUNTER == 745)
  #define TEST_COUNT_745(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_745(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_746
  #undef TEST_COUNT_746
#endif
#if (PREDICTED_COUNTER == 746)
  #define TEST_COUNT_746(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_746(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_747
  #undef TEST_COUNT_747
#endif
#if (PREDICTED_COUNTER == 747)
  #define TEST_COUNT_747(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_747(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_748
  #undef TEST_COUNT_748
#endif
#if (PREDICTED_COUNTER == 748)
  #define TEST_COUNT_748(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_748(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_749
  #undef TEST_COUNT_749
#endif
#if (PREDICTED_COUNTER == 749)
  #define TEST_COUNT_749(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_749(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_750
  #undef TEST_COUNT_750
#endif
#if (PREDICTED_COUNTER == 750)
  #define TEST_COUNT_750(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_750(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_751
  #undef TEST_COUNT_751
#endif
#if (PREDICTED_COUNTER == 751)
  #define TEST_COUNT_751(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_751(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_752
  #undef TEST_COUNT_752
#endif
#if (PREDICTED_COUNTER == 752)
  #define TEST_COUNT_752(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_752(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_753
  #undef TEST_COUNT_753
#endif
#if (PREDICTED_COUNTER == 753)
  #define TEST_COUNT_753(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_753(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_754
  #undef TEST_COUNT_754
#endif
#if (PREDICTED_COUNTER == 754)
  #define TEST_COUNT_754(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_754(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_755
  #undef TEST_COUNT_755
#endif
#if (PREDICTED_COUNTER == 755)
  #define TEST_COUNT_755(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_755(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_756
  #undef TEST_COUNT_756
#endif
#if (PREDICTED_COUNTER == 756)
  #define TEST_COUNT_756(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_756(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_757
  #undef TEST_COUNT_757
#endif
#if (PREDICTED_COUNTER == 757)
  #define TEST_COUNT_757(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_757(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_758
  #undef TEST_COUNT_758
#endif
#if (PREDICTED_COUNTER == 758)
  #define TEST_COUNT_758(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_758(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_759
  #undef TEST_COUNT_759
#endif
#if (PREDICTED_COUNTER == 759)
  #define TEST_COUNT_759(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_759(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_760
  #undef TEST_COUNT_760
#endif
#if (PREDICTED_COUNTER == 760)
  #define TEST_COUNT_760(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_760(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_761
  #undef TEST_COUNT_761
#endif
#if (PREDICTED_COUNTER == 761)
  #define TEST_COUNT_761(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_761(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_762
  #undef TEST_COUNT_762
#endif
#if (PREDICTED_COUNTER == 762)
  #define TEST_COUNT_762(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_762(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_763
  #undef TEST_COUNT_763
#endif
#if (PREDICTED_COUNTER == 763)
  #define TEST_COUNT_763(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_763(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_764
  #undef TEST_COUNT_764
#endif
#if (PREDICTED_COUNTER == 764)
  #define TEST_COUNT_764(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_764(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_765
  #undef TEST_COUNT_765
#endif
#if (PREDICTED_COUNTER == 765)
  #define TEST_COUNT_765(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_765(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_766
  #undef TEST_COUNT_766
#endif
#if (PREDICTED_COUNTER == 766)
  #define TEST_COUNT_766(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_766(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_767
  #undef TEST_COUNT_767
#endif
#if (PREDICTED_COUNTER == 767)
  #define TEST_COUNT_767(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_767(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_768
  #undef TEST_COUNT_768
#endif
#if (PREDICTED_COUNTER == 768)
  #define TEST_COUNT_768(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_768(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_769
  #undef TEST_COUNT_769
#endif
#if (PREDICTED_COUNTER == 769)
  #define TEST_COUNT_769(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_769(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_770
  #undef TEST_COUNT_770
#endif
#if (PREDICTED_COUNTER == 770)
  #define TEST_COUNT_770(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_770(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_771
  #undef TEST_COUNT_771
#endif
#if (PREDICTED_COUNTER == 771)
  #define TEST_COUNT_771(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_771(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_772
  #undef TEST_COUNT_772
#endif
#if (PREDICTED_COUNTER == 772)
  #define TEST_COUNT_772(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_772(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_773
  #undef TEST_COUNT_773
#endif
#if (PREDICTED_COUNTER == 773)
  #define TEST_COUNT_773(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_773(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_774
  #undef TEST_COUNT_774
#endif
#if (PREDICTED_COUNTER == 774)
  #define TEST_COUNT_774(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_774(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_775
  #undef TEST_COUNT_775
#endif
#if (PREDICTED_COUNTER == 775)
  #define TEST_COUNT_775(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_775(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_776
  #undef TEST_COUNT_776
#endif
#if (PREDICTED_COUNTER == 776)
  #define TEST_COUNT_776(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_776(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_777
  #undef TEST_COUNT_777
#endif
#if (PREDICTED_COUNTER == 777)
  #define TEST_COUNT_777(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_777(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_778
  #undef TEST_COUNT_778
#endif
#if (PREDICTED_COUNTER == 778)
  #define TEST_COUNT_778(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_778(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_779
  #undef TEST_COUNT_779
#endif
#if (PREDICTED_COUNTER == 779)
  #define TEST_COUNT_779(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_779(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_780
  #undef TEST_COUNT_780
#endif
#if (PREDICTED_COUNTER == 780)
  #define TEST_COUNT_780(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_780(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_781
  #undef TEST_COUNT_781
#endif
#if (PREDICTED_COUNTER == 781)
  #define TEST_COUNT_781(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_781(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_782
  #undef TEST_COUNT_782
#endif
#if (PREDICTED_COUNTER == 782)
  #define TEST_COUNT_782(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_782(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_783
  #undef TEST_COUNT_783
#endif
#if (PREDICTED_COUNTER == 783)
  #define TEST_COUNT_783(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_783(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_784
  #undef TEST_COUNT_784
#endif
#if (PREDICTED_COUNTER == 784)
  #define TEST_COUNT_784(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_784(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_785
  #undef TEST_COUNT_785
#endif
#if (PREDICTED_COUNTER == 785)
  #define TEST_COUNT_785(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_785(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_786
  #undef TEST_COUNT_786
#endif
#if (PREDICTED_COUNTER == 786)
  #define TEST_COUNT_786(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_786(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_787
  #undef TEST_COUNT_787
#endif
#if (PREDICTED_COUNTER == 787)
  #define TEST_COUNT_787(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_787(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_788
  #undef TEST_COUNT_788
#endif
#if (PREDICTED_COUNTER == 788)
  #define TEST_COUNT_788(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_788(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_789
  #undef TEST_COUNT_789
#endif
#if (PREDICTED_COUNTER == 789)
  #define TEST_COUNT_789(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_789(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_790
  #undef TEST_COUNT_790
#endif
#if (PREDICTED_COUNTER == 790)
  #define TEST_COUNT_790(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_790(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_791
  #undef TEST_COUNT_791
#endif
#if (PREDICTED_COUNTER == 791)
  #define TEST_COUNT_791(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_791(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_792
  #undef TEST_COUNT_792
#endif
#if (PREDICTED_COUNTER == 792)
  #define TEST_COUNT_792(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_792(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_793
  #undef TEST_COUNT_793
#endif
#if (PREDICTED_COUNTER == 793)
  #define TEST_COUNT_793(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_793(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_794
  #undef TEST_COUNT_794
#endif
#if (PREDICTED_COUNTER == 794)
  #define TEST_COUNT_794(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_794(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_795
  #undef TEST_COUNT_795
#endif
#if (PREDICTED_COUNTER == 795)
  #define TEST_COUNT_795(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_795(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_796
  #undef TEST_COUNT_796
#endif
#if (PREDICTED_COUNTER == 796)
  #define TEST_COUNT_796(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_796(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_797
  #undef TEST_COUNT_797
#endif
#if (PREDICTED_COUNTER == 797)
  #define TEST_COUNT_797(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_797(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_798
  #undef TEST_COUNT_798
#endif
#if (PREDICTED_COUNTER == 798)
  #define TEST_COUNT_798(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_798(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_799
  #undef TEST_COUNT_799
#endif
#if (PREDICTED_COUNTER == 799)
  #define TEST_COUNT_799(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_799(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_800
  #undef TEST_COUNT_800
#endif
#if (PREDICTED_COUNTER == 800)
  #define TEST_COUNT_800(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_800(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_801
  #undef TEST_COUNT_801
#endif
#if (PREDICTED_COUNTER == 801)
  #define TEST_COUNT_801(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_801(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_802
  #undef TEST_COUNT_802
#endif
#if (PREDICTED_COUNTER == 802)
  #define TEST_COUNT_802(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_802(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_803
  #undef TEST_COUNT_803
#endif
#if (PREDICTED_COUNTER == 803)
  #define TEST_COUNT_803(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_803(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_804
  #undef TEST_COUNT_804
#endif
#if (PREDICTED_COUNTER == 804)
  #define TEST_COUNT_804(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_804(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_805
  #undef TEST_COUNT_805
#endif
#if (PREDICTED_COUNTER == 805)
  #define TEST_COUNT_805(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_805(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_806
  #undef TEST_COUNT_806
#endif
#if (PREDICTED_COUNTER == 806)
  #define TEST_COUNT_806(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_806(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_807
  #undef TEST_COUNT_807
#endif
#if (PREDICTED_COUNTER == 807)
  #define TEST_COUNT_807(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_807(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_808
  #undef TEST_COUNT_808
#endif
#if (PREDICTED_COUNTER == 808)
  #define TEST_COUNT_808(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_808(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_809
  #undef TEST_COUNT_809
#endif
#if (PREDICTED_COUNTER == 809)
  #define TEST_COUNT_809(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_809(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_810
  #undef TEST_COUNT_810
#endif
#if (PREDICTED_COUNTER == 810)
  #define TEST_COUNT_810(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_810(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_811
  #undef TEST_COUNT_811
#endif
#if (PREDICTED_COUNTER == 811)
  #define TEST_COUNT_811(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_811(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_812
  #undef TEST_COUNT_812
#endif
#if (PREDICTED_COUNTER == 812)
  #define TEST_COUNT_812(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_812(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_813
  #undef TEST_COUNT_813
#endif
#if (PREDICTED_COUNTER == 813)
  #define TEST_COUNT_813(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_813(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_814
  #undef TEST_COUNT_814
#endif
#if (PREDICTED_COUNTER == 814)
  #define TEST_COUNT_814(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_814(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_815
  #undef TEST_COUNT_815
#endif
#if (PREDICTED_COUNTER == 815)
  #define TEST_COUNT_815(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_815(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_816
  #undef TEST_COUNT_816
#endif
#if (PREDICTED_COUNTER == 816)
  #define TEST_COUNT_816(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_816(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_817
  #undef TEST_COUNT_817
#endif
#if (PREDICTED_COUNTER == 817)
  #define TEST_COUNT_817(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_817(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_818
  #undef TEST_COUNT_818
#endif
#if (PREDICTED_COUNTER == 818)
  #define TEST_COUNT_818(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_818(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_819
  #undef TEST_COUNT_819
#endif
#if (PREDICTED_COUNTER == 819)
  #define TEST_COUNT_819(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_819(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_820
  #undef TEST_COUNT_820
#endif
#if (PREDICTED_COUNTER == 820)
  #define TEST_COUNT_820(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_820(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_821
  #undef TEST_COUNT_821
#endif
#if (PREDICTED_COUNTER == 821)
  #define TEST_COUNT_821(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_821(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_822
  #undef TEST_COUNT_822
#endif
#if (PREDICTED_COUNTER == 822)
  #define TEST_COUNT_822(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_822(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_823
  #undef TEST_COUNT_823
#endif
#if (PREDICTED_COUNTER == 823)
  #define TEST_COUNT_823(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_823(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_824
  #undef TEST_COUNT_824
#endif
#if (PREDICTED_COUNTER == 824)
  #define TEST_COUNT_824(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_824(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_825
  #undef TEST_COUNT_825
#endif
#if (PREDICTED_COUNTER == 825)
  #define TEST_COUNT_825(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_825(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_826
  #undef TEST_COUNT_826
#endif
#if (PREDICTED_COUNTER == 826)
  #define TEST_COUNT_826(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_826(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_827
  #undef TEST_COUNT_827
#endif
#if (PREDICTED_COUNTER == 827)
  #define TEST_COUNT_827(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_827(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_828
  #undef TEST_COUNT_828
#endif
#if (PREDICTED_COUNTER == 828)
  #define TEST_COUNT_828(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_828(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_829
  #undef TEST_COUNT_829
#endif
#if (PREDICTED_COUNTER == 829)
  #define TEST_COUNT_829(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_829(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_830
  #undef TEST_COUNT_830
#endif
#if (PREDICTED_COUNTER == 830)
  #define TEST_COUNT_830(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_830(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_831
  #undef TEST_COUNT_831
#endif
#if (PREDICTED_COUNTER == 831)
  #define TEST_COUNT_831(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_831(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_832
  #undef TEST_COUNT_832
#endif
#if (PREDICTED_COUNTER == 832)
  #define TEST_COUNT_832(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_832(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_833
  #undef TEST_COUNT_833
#endif
#if (PREDICTED_COUNTER == 833)
  #define TEST_COUNT_833(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_833(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_834
  #undef TEST_COUNT_834
#endif
#if (PREDICTED_COUNTER == 834)
  #define TEST_COUNT_834(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_834(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_835
  #undef TEST_COUNT_835
#endif
#if (PREDICTED_COUNTER == 835)
  #define TEST_COUNT_835(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_835(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_836
  #undef TEST_COUNT_836
#endif
#if (PREDICTED_COUNTER == 836)
  #define TEST_COUNT_836(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_836(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_837
  #undef TEST_COUNT_837
#endif
#if (PREDICTED_COUNTER == 837)
  #define TEST_COUNT_837(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_837(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_838
  #undef TEST_COUNT_838
#endif
#if (PREDICTED_COUNTER == 838)
  #define TEST_COUNT_838(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_838(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_839
  #undef TEST_COUNT_839
#endif
#if (PREDICTED_COUNTER == 839)
  #define TEST_COUNT_839(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_839(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_840
  #undef TEST_COUNT_840
#endif
#if (PREDICTED_COUNTER == 840)
  #define TEST_COUNT_840(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_840(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_841
  #undef TEST_COUNT_841
#endif
#if (PREDICTED_COUNTER == 841)
  #define TEST_COUNT_841(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_841(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_842
  #undef TEST_COUNT_842
#endif
#if (PREDICTED_COUNTER == 842)
  #define TEST_COUNT_842(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_842(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_843
  #undef TEST_COUNT_843
#endif
#if (PREDICTED_COUNTER == 843)
  #define TEST_COUNT_843(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_843(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_844
  #undef TEST_COUNT_844
#endif
#if (PREDICTED_COUNTER == 844)
  #define TEST_COUNT_844(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_844(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_845
  #undef TEST_COUNT_845
#endif
#if (PREDICTED_COUNTER == 845)
  #define TEST_COUNT_845(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_845(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_846
  #undef TEST_COUNT_846
#endif
#if (PREDICTED_COUNTER == 846)
  #define TEST_COUNT_846(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_846(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_847
  #undef TEST_COUNT_847
#endif
#if (PREDICTED_COUNTER == 847)
  #define TEST_COUNT_847(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_847(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_848
  #undef TEST_COUNT_848
#endif
#if (PREDICTED_COUNTER == 848)
  #define TEST_COUNT_848(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_848(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_849
  #undef TEST_COUNT_849
#endif
#if (PREDICTED_COUNTER == 849)
  #define TEST_COUNT_849(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_849(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_850
  #undef TEST_COUNT_850
#endif
#if (PREDICTED_COUNTER == 850)
  #define TEST_COUNT_850(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_850(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_851
  #undef TEST_COUNT_851
#endif
#if (PREDICTED_COUNTER == 851)
  #define TEST_COUNT_851(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_851(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_852
  #undef TEST_COUNT_852
#endif
#if (PREDICTED_COUNTER == 852)
  #define TEST_COUNT_852(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_852(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_853
  #undef TEST_COUNT_853
#endif
#if (PREDICTED_COUNTER == 853)
  #define TEST_COUNT_853(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_853(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_854
  #undef TEST_COUNT_854
#endif
#if (PREDICTED_COUNTER == 854)
  #define TEST_COUNT_854(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_854(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_855
  #undef TEST_COUNT_855
#endif
#if (PREDICTED_COUNTER == 855)
  #define TEST_COUNT_855(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_855(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_856
  #undef TEST_COUNT_856
#endif
#if (PREDICTED_COUNTER == 856)
  #define TEST_COUNT_856(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_856(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_857
  #undef TEST_COUNT_857
#endif
#if (PREDICTED_COUNTER == 857)
  #define TEST_COUNT_857(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_857(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_858
  #undef TEST_COUNT_858
#endif
#if (PREDICTED_COUNTER == 858)
  #define TEST_COUNT_858(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_858(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_859
  #undef TEST_COUNT_859
#endif
#if (PREDICTED_COUNTER == 859)
  #define TEST_COUNT_859(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_859(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_860
  #undef TEST_COUNT_860
#endif
#if (PREDICTED_COUNTER == 860)
  #define TEST_COUNT_860(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_860(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_861
  #undef TEST_COUNT_861
#endif
#if (PREDICTED_COUNTER == 861)
  #define TEST_COUNT_861(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_861(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_862
  #undef TEST_COUNT_862
#endif
#if (PREDICTED_COUNTER == 862)
  #define TEST_COUNT_862(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_862(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_863
  #undef TEST_COUNT_863
#endif
#if (PREDICTED_COUNTER == 863)
  #define TEST_COUNT_863(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_863(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_864
  #undef TEST_COUNT_864
#endif
#if (PREDICTED_COUNTER == 864)
  #define TEST_COUNT_864(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_864(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_865
  #undef TEST_COUNT_865
#endif
#if (PREDICTED_COUNTER == 865)
  #define TEST_COUNT_865(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_865(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_866
  #undef TEST_COUNT_866
#endif
#if (PREDICTED_COUNTER == 866)
  #define TEST_COUNT_866(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_866(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_867
  #undef TEST_COUNT_867
#endif
#if (PREDICTED_COUNTER == 867)
  #define TEST_COUNT_867(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_867(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_868
  #undef TEST_COUNT_868
#endif
#if (PREDICTED_COUNTER == 868)
  #define TEST_COUNT_868(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_868(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_869
  #undef TEST_COUNT_869
#endif
#if (PREDICTED_COUNTER == 869)
  #define TEST_COUNT_869(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_869(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_870
  #undef TEST_COUNT_870
#endif
#if (PREDICTED_COUNTER == 870)
  #define TEST_COUNT_870(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_870(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_871
  #undef TEST_COUNT_871
#endif
#if (PREDICTED_COUNTER == 871)
  #define TEST_COUNT_871(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_871(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_872
  #undef TEST_COUNT_872
#endif
#if (PREDICTED_COUNTER == 872)
  #define TEST_COUNT_872(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_872(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_873
  #undef TEST_COUNT_873
#endif
#if (PREDICTED_COUNTER == 873)
  #define TEST_COUNT_873(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_873(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_874
  #undef TEST_COUNT_874
#endif
#if (PREDICTED_COUNTER == 874)
  #define TEST_COUNT_874(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_874(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_875
  #undef TEST_COUNT_875
#endif
#if (PREDICTED_COUNTER == 875)
  #define TEST_COUNT_875(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_875(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_876
  #undef TEST_COUNT_876
#endif
#if (PREDICTED_COUNTER == 876)
  #define TEST_COUNT_876(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_876(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_877
  #undef TEST_COUNT_877
#endif
#if (PREDICTED_COUNTER == 877)
  #define TEST_COUNT_877(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_877(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_878
  #undef TEST_COUNT_878
#endif
#if (PREDICTED_COUNTER == 878)
  #define TEST_COUNT_878(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_878(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_879
  #undef TEST_COUNT_879
#endif
#if (PREDICTED_COUNTER == 879)
  #define TEST_COUNT_879(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_879(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_880
  #undef TEST_COUNT_880
#endif
#if (PREDICTED_COUNTER == 880)
  #define TEST_COUNT_880(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_880(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_881
  #undef TEST_COUNT_881
#endif
#if (PREDICTED_COUNTER == 881)
  #define TEST_COUNT_881(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_881(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_882
  #undef TEST_COUNT_882
#endif
#if (PREDICTED_COUNTER == 882)
  #define TEST_COUNT_882(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_882(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_883
  #undef TEST_COUNT_883
#endif
#if (PREDICTED_COUNTER == 883)
  #define TEST_COUNT_883(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_883(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_884
  #undef TEST_COUNT_884
#endif
#if (PREDICTED_COUNTER == 884)
  #define TEST_COUNT_884(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_884(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_885
  #undef TEST_COUNT_885
#endif
#if (PREDICTED_COUNTER == 885)
  #define TEST_COUNT_885(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_885(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_886
  #undef TEST_COUNT_886
#endif
#if (PREDICTED_COUNTER == 886)
  #define TEST_COUNT_886(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_886(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_887
  #undef TEST_COUNT_887
#endif
#if (PREDICTED_COUNTER == 887)
  #define TEST_COUNT_887(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_887(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_888
  #undef TEST_COUNT_888
#endif
#if (PREDICTED_COUNTER == 888)
  #define TEST_COUNT_888(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_888(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_889
  #undef TEST_COUNT_889
#endif
#if (PREDICTED_COUNTER == 889)
  #define TEST_COUNT_889(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_889(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_890
  #undef TEST_COUNT_890
#endif
#if (PREDICTED_COUNTER == 890)
  #define TEST_COUNT_890(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_890(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_891
  #undef TEST_COUNT_891
#endif
#if (PREDICTED_COUNTER == 891)
  #define TEST_COUNT_891(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_891(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_892
  #undef TEST_COUNT_892
#endif
#if (PREDICTED_COUNTER == 892)
  #define TEST_COUNT_892(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_892(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_893
  #undef TEST_COUNT_893
#endif
#if (PREDICTED_COUNTER == 893)
  #define TEST_COUNT_893(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_893(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_894
  #undef TEST_COUNT_894
#endif
#if (PREDICTED_COUNTER == 894)
  #define TEST_COUNT_894(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_894(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_895
  #undef TEST_COUNT_895
#endif
#if (PREDICTED_COUNTER == 895)
  #define TEST_COUNT_895(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_895(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_896
  #undef TEST_COUNT_896
#endif
#if (PREDICTED_COUNTER == 896)
  #define TEST_COUNT_896(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_896(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_897
  #undef TEST_COUNT_897
#endif
#if (PREDICTED_COUNTER == 897)
  #define TEST_COUNT_897(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_897(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_898
  #undef TEST_COUNT_898
#endif
#if (PREDICTED_COUNTER == 898)
  #define TEST_COUNT_898(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_898(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_899
  #undef TEST_COUNT_899
#endif
#if (PREDICTED_COUNTER == 899)
  #define TEST_COUNT_899(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_899(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_900
  #undef TEST_COUNT_900
#endif
#if (PREDICTED_COUNTER == 900)
  #define TEST_COUNT_900(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_900(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_901
  #undef TEST_COUNT_901
#endif
#if (PREDICTED_COUNTER == 901)
  #define TEST_COUNT_901(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_901(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_902
  #undef TEST_COUNT_902
#endif
#if (PREDICTED_COUNTER == 902)
  #define TEST_COUNT_902(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_902(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_903
  #undef TEST_COUNT_903
#endif
#if (PREDICTED_COUNTER == 903)
  #define TEST_COUNT_903(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_903(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_904
  #undef TEST_COUNT_904
#endif
#if (PREDICTED_COUNTER == 904)
  #define TEST_COUNT_904(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_904(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_905
  #undef TEST_COUNT_905
#endif
#if (PREDICTED_COUNTER == 905)
  #define TEST_COUNT_905(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_905(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_906
  #undef TEST_COUNT_906
#endif
#if (PREDICTED_COUNTER == 906)
  #define TEST_COUNT_906(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_906(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_907
  #undef TEST_COUNT_907
#endif
#if (PREDICTED_COUNTER == 907)
  #define TEST_COUNT_907(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_907(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_908
  #undef TEST_COUNT_908
#endif
#if (PREDICTED_COUNTER == 908)
  #define TEST_COUNT_908(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_908(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_909
  #undef TEST_COUNT_909
#endif
#if (PREDICTED_COUNTER == 909)
  #define TEST_COUNT_909(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_909(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_910
  #undef TEST_COUNT_910
#endif
#if (PREDICTED_COUNTER == 910)
  #define TEST_COUNT_910(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_910(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_911
  #undef TEST_COUNT_911
#endif
#if (PREDICTED_COUNTER == 911)
  #define TEST_COUNT_911(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_911(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_912
  #undef TEST_COUNT_912
#endif
#if (PREDICTED_COUNTER == 912)
  #define TEST_COUNT_912(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_912(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_913
  #undef TEST_COUNT_913
#endif
#if (PREDICTED_COUNTER == 913)
  #define TEST_COUNT_913(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_913(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_914
  #undef TEST_COUNT_914
#endif
#if (PREDICTED_COUNTER == 914)
  #define TEST_COUNT_914(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_914(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_915
  #undef TEST_COUNT_915
#endif
#if (PREDICTED_COUNTER == 915)
  #define TEST_COUNT_915(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_915(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_916
  #undef TEST_COUNT_916
#endif
#if (PREDICTED_COUNTER == 916)
  #define TEST_COUNT_916(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_916(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_917
  #undef TEST_COUNT_917
#endif
#if (PREDICTED_COUNTER == 917)
  #define TEST_COUNT_917(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_917(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_918
  #undef TEST_COUNT_918
#endif
#if (PREDICTED_COUNTER == 918)
  #define TEST_COUNT_918(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_918(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_919
  #undef TEST_COUNT_919
#endif
#if (PREDICTED_COUNTER == 919)
  #define TEST_COUNT_919(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_919(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_920
  #undef TEST_COUNT_920
#endif
#if (PREDICTED_COUNTER == 920)
  #define TEST_COUNT_920(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_920(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_921
  #undef TEST_COUNT_921
#endif
#if (PREDICTED_COUNTER == 921)
  #define TEST_COUNT_921(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_921(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_922
  #undef TEST_COUNT_922
#endif
#if (PREDICTED_COUNTER == 922)
  #define TEST_COUNT_922(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_922(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_923
  #undef TEST_COUNT_923
#endif
#if (PREDICTED_COUNTER == 923)
  #define TEST_COUNT_923(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_923(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_924
  #undef TEST_COUNT_924
#endif
#if (PREDICTED_COUNTER == 924)
  #define TEST_COUNT_924(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_924(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_925
  #undef TEST_COUNT_925
#endif
#if (PREDICTED_COUNTER == 925)
  #define TEST_COUNT_925(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_925(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_926
  #undef TEST_COUNT_926
#endif
#if (PREDICTED_COUNTER == 926)
  #define TEST_COUNT_926(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_926(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_927
  #undef TEST_COUNT_927
#endif
#if (PREDICTED_COUNTER == 927)
  #define TEST_COUNT_927(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_927(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_928
  #undef TEST_COUNT_928
#endif
#if (PREDICTED_COUNTER == 928)
  #define TEST_COUNT_928(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_928(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_929
  #undef TEST_COUNT_929
#endif
#if (PREDICTED_COUNTER == 929)
  #define TEST_COUNT_929(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_929(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_930
  #undef TEST_COUNT_930
#endif
#if (PREDICTED_COUNTER == 930)
  #define TEST_COUNT_930(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_930(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_931
  #undef TEST_COUNT_931
#endif
#if (PREDICTED_COUNTER == 931)
  #define TEST_COUNT_931(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_931(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_932
  #undef TEST_COUNT_932
#endif
#if (PREDICTED_COUNTER == 932)
  #define TEST_COUNT_932(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_932(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_933
  #undef TEST_COUNT_933
#endif
#if (PREDICTED_COUNTER == 933)
  #define TEST_COUNT_933(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_933(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_934
  #undef TEST_COUNT_934
#endif
#if (PREDICTED_COUNTER == 934)
  #define TEST_COUNT_934(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_934(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_935
  #undef TEST_COUNT_935
#endif
#if (PREDICTED_COUNTER == 935)
  #define TEST_COUNT_935(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_935(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_936
  #undef TEST_COUNT_936
#endif
#if (PREDICTED_COUNTER == 936)
  #define TEST_COUNT_936(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_936(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_937
  #undef TEST_COUNT_937
#endif
#if (PREDICTED_COUNTER == 937)
  #define TEST_COUNT_937(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_937(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_938
  #undef TEST_COUNT_938
#endif
#if (PREDICTED_COUNTER == 938)
  #define TEST_COUNT_938(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_938(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_939
  #undef TEST_COUNT_939
#endif
#if (PREDICTED_COUNTER == 939)
  #define TEST_COUNT_939(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_939(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_940
  #undef TEST_COUNT_940
#endif
#if (PREDICTED_COUNTER == 940)
  #define TEST_COUNT_940(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_940(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_941
  #undef TEST_COUNT_941
#endif
#if (PREDICTED_COUNTER == 941)
  #define TEST_COUNT_941(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_941(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_942
  #undef TEST_COUNT_942
#endif
#if (PREDICTED_COUNTER == 942)
  #define TEST_COUNT_942(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_942(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_943
  #undef TEST_COUNT_943
#endif
#if (PREDICTED_COUNTER == 943)
  #define TEST_COUNT_943(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_943(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_944
  #undef TEST_COUNT_944
#endif
#if (PREDICTED_COUNTER == 944)
  #define TEST_COUNT_944(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_944(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_945
  #undef TEST_COUNT_945
#endif
#if (PREDICTED_COUNTER == 945)
  #define TEST_COUNT_945(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_945(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_946
  #undef TEST_COUNT_946
#endif
#if (PREDICTED_COUNTER == 946)
  #define TEST_COUNT_946(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_946(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_947
  #undef TEST_COUNT_947
#endif
#if (PREDICTED_COUNTER == 947)
  #define TEST_COUNT_947(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_947(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_948
  #undef TEST_COUNT_948
#endif
#if (PREDICTED_COUNTER == 948)
  #define TEST_COUNT_948(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_948(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_949
  #undef TEST_COUNT_949
#endif
#if (PREDICTED_COUNTER == 949)
  #define TEST_COUNT_949(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_949(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_950
  #undef TEST_COUNT_950
#endif
#if (PREDICTED_COUNTER == 950)
  #define TEST_COUNT_950(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_950(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_951
  #undef TEST_COUNT_951
#endif
#if (PREDICTED_COUNTER == 951)
  #define TEST_COUNT_951(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_951(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_952
  #undef TEST_COUNT_952
#endif
#if (PREDICTED_COUNTER == 952)
  #define TEST_COUNT_952(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_952(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_953
  #undef TEST_COUNT_953
#endif
#if (PREDICTED_COUNTER == 953)
  #define TEST_COUNT_953(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_953(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_954
  #undef TEST_COUNT_954
#endif
#if (PREDICTED_COUNTER == 954)
  #define TEST_COUNT_954(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_954(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_955
  #undef TEST_COUNT_955
#endif
#if (PREDICTED_COUNTER == 955)
  #define TEST_COUNT_955(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_955(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_956
  #undef TEST_COUNT_956
#endif
#if (PREDICTED_COUNTER == 956)
  #define TEST_COUNT_956(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_956(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_957
  #undef TEST_COUNT_957
#endif
#if (PREDICTED_COUNTER == 957)
  #define TEST_COUNT_957(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_957(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_958
  #undef TEST_COUNT_958
#endif
#if (PREDICTED_COUNTER == 958)
  #define TEST_COUNT_958(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_958(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_959
  #undef TEST_COUNT_959
#endif
#if (PREDICTED_COUNTER == 959)
  #define TEST_COUNT_959(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_959(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_960
  #undef TEST_COUNT_960
#endif
#if (PREDICTED_COUNTER == 960)
  #define TEST_COUNT_960(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_960(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_961
  #undef TEST_COUNT_961
#endif
#if (PREDICTED_COUNTER == 961)
  #define TEST_COUNT_961(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_961(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_962
  #undef TEST_COUNT_962
#endif
#if (PREDICTED_COUNTER == 962)
  #define TEST_COUNT_962(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_962(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_963
  #undef TEST_COUNT_963
#endif
#if (PREDICTED_COUNTER == 963)
  #define TEST_COUNT_963(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_963(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_964
  #undef TEST_COUNT_964
#endif
#if (PREDICTED_COUNTER == 964)
  #define TEST_COUNT_964(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_964(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_965
  #undef TEST_COUNT_965
#endif
#if (PREDICTED_COUNTER == 965)
  #define TEST_COUNT_965(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_965(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_966
  #undef TEST_COUNT_966
#endif
#if (PREDICTED_COUNTER == 966)
  #define TEST_COUNT_966(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_966(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_967
  #undef TEST_COUNT_967
#endif
#if (PREDICTED_COUNTER == 967)
  #define TEST_COUNT_967(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_967(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_968
  #undef TEST_COUNT_968
#endif
#if (PREDICTED_COUNTER == 968)
  #define TEST_COUNT_968(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_968(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_969
  #undef TEST_COUNT_969
#endif
#if (PREDICTED_COUNTER == 969)
  #define TEST_COUNT_969(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_969(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_970
  #undef TEST_COUNT_970
#endif
#if (PREDICTED_COUNTER == 970)
  #define TEST_COUNT_970(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_970(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_971
  #undef TEST_COUNT_971
#endif
#if (PREDICTED_COUNTER == 971)
  #define TEST_COUNT_971(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_971(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_972
  #undef TEST_COUNT_972
#endif
#if (PREDICTED_COUNTER == 972)
  #define TEST_COUNT_972(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_972(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_973
  #undef TEST_COUNT_973
#endif
#if (PREDICTED_COUNTER == 973)
  #define TEST_COUNT_973(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_973(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_974
  #undef TEST_COUNT_974
#endif
#if (PREDICTED_COUNTER == 974)
  #define TEST_COUNT_974(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_974(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_975
  #undef TEST_COUNT_975
#endif
#if (PREDICTED_COUNTER == 975)
  #define TEST_COUNT_975(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_975(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_976
  #undef TEST_COUNT_976
#endif
#if (PREDICTED_COUNTER == 976)
  #define TEST_COUNT_976(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_976(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_977
  #undef TEST_COUNT_977
#endif
#if (PREDICTED_COUNTER == 977)
  #define TEST_COUNT_977(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_977(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_978
  #undef TEST_COUNT_978
#endif
#if (PREDICTED_COUNTER == 978)
  #define TEST_COUNT_978(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_978(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_979
  #undef TEST_COUNT_979
#endif
#if (PREDICTED_COUNTER == 979)
  #define TEST_COUNT_979(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_979(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_980
  #undef TEST_COUNT_980
#endif
#if (PREDICTED_COUNTER == 980)
  #define TEST_COUNT_980(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_980(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_981
  #undef TEST_COUNT_981
#endif
#if (PREDICTED_COUNTER == 981)
  #define TEST_COUNT_981(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_981(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_982
  #undef TEST_COUNT_982
#endif
#if (PREDICTED_COUNTER == 982)
  #define TEST_COUNT_982(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_982(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_983
  #undef TEST_COUNT_983
#endif
#if (PREDICTED_COUNTER == 983)
  #define TEST_COUNT_983(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_983(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_984
  #undef TEST_COUNT_984
#endif
#if (PREDICTED_COUNTER == 984)
  #define TEST_COUNT_984(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_984(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_985
  #undef TEST_COUNT_985
#endif
#if (PREDICTED_COUNTER == 985)
  #define TEST_COUNT_985(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_985(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_986
  #undef TEST_COUNT_986
#endif
#if (PREDICTED_COUNTER == 986)
  #define TEST_COUNT_986(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_986(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_987
  #undef TEST_COUNT_987
#endif
#if (PREDICTED_COUNTER == 987)
  #define TEST_COUNT_987(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_987(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_988
  #undef TEST_COUNT_988
#endif
#if (PREDICTED_COUNTER == 988)
  #define TEST_COUNT_988(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_988(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_989
  #undef TEST_COUNT_989
#endif
#if (PREDICTED_COUNTER == 989)
  #define TEST_COUNT_989(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_989(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_990
  #undef TEST_COUNT_990
#endif
#if (PREDICTED_COUNTER == 990)
  #define TEST_COUNT_990(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_990(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_991
  #undef TEST_COUNT_991
#endif
#if (PREDICTED_COUNTER == 991)
  #define TEST_COUNT_991(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_991(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_992
  #undef TEST_COUNT_992
#endif
#if (PREDICTED_COUNTER == 992)
  #define TEST_COUNT_992(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_992(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_993
  #undef TEST_COUNT_993
#endif
#if (PREDICTED_COUNTER == 993)
  #define TEST_COUNT_993(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_993(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_994
  #undef TEST_COUNT_994
#endif
#if (PREDICTED_COUNTER == 994)
  #define TEST_COUNT_994(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_994(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_995
  #undef TEST_COUNT_995
#endif
#if (PREDICTED_COUNTER == 995)
  #define TEST_COUNT_995(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_995(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_996
  #undef TEST_COUNT_996
#endif
#if (PREDICTED_COUNTER == 996)
  #define TEST_COUNT_996(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_996(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_997
  #undef TEST_COUNT_997
#endif
#if (PREDICTED_COUNTER == 997)
  #define TEST_COUNT_997(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_997(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_998
  #undef TEST_COUNT_998
#endif
#if (PREDICTED_COUNTER == 998)
  #define TEST_COUNT_998(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_998(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_999
  #undef TEST_COUNT_999
#endif
#if (PREDICTED_COUNTER == 999)
  #define TEST_COUNT_999(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_999(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1000
  #undef TEST_COUNT_1000
#endif
#if (PREDICTED_COUNTER == 1000)
  #define TEST_COUNT_1000(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1000(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1001
  #undef TEST_COUNT_1001
#endif
#if (PREDICTED_COUNTER == 1001)
  #define TEST_COUNT_1001(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1001(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1002
  #undef TEST_COUNT_1002
#endif
#if (PREDICTED_COUNTER == 1002)
  #define TEST_COUNT_1002(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1002(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1003
  #undef TEST_COUNT_1003
#endif
#if (PREDICTED_COUNTER == 1003)
  #define TEST_COUNT_1003(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1003(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1004
  #undef TEST_COUNT_1004
#endif
#if (PREDICTED_COUNTER == 1004)
  #define TEST_COUNT_1004(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1004(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1005
  #undef TEST_COUNT_1005
#endif
#if (PREDICTED_COUNTER == 1005)
  #define TEST_COUNT_1005(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1005(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1006
  #undef TEST_COUNT_1006
#endif
#if (PREDICTED_COUNTER == 1006)
  #define TEST_COUNT_1006(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1006(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1007
  #undef TEST_COUNT_1007
#endif
#if (PREDICTED_COUNTER == 1007)
  #define TEST_COUNT_1007(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1007(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1008
  #undef TEST_COUNT_1008
#endif
#if (PREDICTED_COUNTER == 1008)
  #define TEST_COUNT_1008(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1008(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1009
  #undef TEST_COUNT_1009
#endif
#if (PREDICTED_COUNTER == 1009)
  #define TEST_COUNT_1009(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1009(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1010
  #undef TEST_COUNT_1010
#endif
#if (PREDICTED_COUNTER == 1010)
  #define TEST_COUNT_1010(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1010(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1011
  #undef TEST_COUNT_1011
#endif
#if (PREDICTED_COUNTER == 1011)
  #define TEST_COUNT_1011(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1011(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1012
  #undef TEST_COUNT_1012
#endif
#if (PREDICTED_COUNTER == 1012)
  #define TEST_COUNT_1012(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1012(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1013
  #undef TEST_COUNT_1013
#endif
#if (PREDICTED_COUNTER == 1013)
  #define TEST_COUNT_1013(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1013(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1014
  #undef TEST_COUNT_1014
#endif
#if (PREDICTED_COUNTER == 1014)
  #define TEST_COUNT_1014(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1014(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1015
  #undef TEST_COUNT_1015
#endif
#if (PREDICTED_COUNTER == 1015)
  #define TEST_COUNT_1015(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1015(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1016
  #undef TEST_COUNT_1016
#endif
#if (PREDICTED_COUNTER == 1016)
  #define TEST_COUNT_1016(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1016(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1017
  #undef TEST_COUNT_1017
#endif
#if (PREDICTED_COUNTER == 1017)
  #define TEST_COUNT_1017(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1017(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1018
  #undef TEST_COUNT_1018
#endif
#if (PREDICTED_COUNTER == 1018)
  #define TEST_COUNT_1018(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1018(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1019
  #undef TEST_COUNT_1019
#endif
#if (PREDICTED_COUNTER == 1019)
  #define TEST_COUNT_1019(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1019(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1020
  #undef TEST_COUNT_1020
#endif
#if (PREDICTED_COUNTER == 1020)
  #define TEST_COUNT_1020(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1020(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1021
  #undef TEST_COUNT_1021
#endif
#if (PREDICTED_COUNTER == 1021)
  #define TEST_COUNT_1021(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1021(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1022
  #undef TEST_COUNT_1022
#endif
#if (PREDICTED_COUNTER == 1022)
  #define TEST_COUNT_1022(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1022(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1023
  #undef TEST_COUNT_1023
#endif
#if (PREDICTED_COUNTER == 1023)
  #define TEST_COUNT_1023(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1023(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#ifdef TEST_COUNT_1024
  #undef TEST_COUNT_1024
#endif
#if (PREDICTED_COUNTER == 1024)
  #define TEST_COUNT_1024(X,Y) FIRST_TEST_RUN(X,Y)
#else
  #define TEST_COUNT_1024(X,Y) OTHER_TEST_RUN(X,Y)
#endif
#endif /* EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE */

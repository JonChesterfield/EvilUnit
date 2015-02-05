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
#define SKIP_TEMPLATE_TEST_INCLUSION
#else /* MODULETESTFILE */
/* Compiling one pass at a time, enable passes sequentially */
#ifndef EVILUNIT_RECURSIVE_STARTUP
#define EVILUNIT_RECURSIVE_STARTUP
#define BUILD_PHASE_00
#define RECURSIVE
#endif
#ifdef BUILD_PHASE_06
#undef BUILD_PHASE_06
#endif
#ifdef BUILD_PHASE_05
#undef BUILD_PHASE_05
#define BUILD_PHASE_06
#undef RECURSIVE
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
#if defined(WITHOUTSYSTEMHEADERS) || defined(PRECOMPILATION)
#define TMPINCLUDE #include <assert.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <stdbool.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <stdarg.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <stddef.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <stdio.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <stdint.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <stdlib.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <string.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <limits.h>
TMPINCLUDE
#undef TMPINCLUDE
#define TMPINCLUDE #include <float.h>
TMPINCLUDE
#undef TMPINCLUDE
#else
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
#endif
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
/* 
 * This control mechanism is triggered by return. If return is not called, will run straight through 
 * the five phases. Calling return during one phase will change the contents of the control struct to
 * control which blocks are subsequently executed
 * All zeros will trigger an unconditional framework error
 */
struct EvilUnit_Control
{
  int do_fixture_setup;
  int do_setup;
  int do_test;
  int do_teardown;
  int do_fixture_teardown;
};
static struct EvilUnit_Control EvilUnit_Control_Initial(void)
{
  struct EvilUnit_Control local;
  local.do_fixture_setup = 1;
  local.do_setup = 1;
  local.do_test = 1;
  local.do_teardown = 1;
  local.do_fixture_teardown = 1;
  return local;
}
static struct EvilUnit_Control EvilUnit_Control_Zeros(void)
{
  struct EvilUnit_Control local;
  local.do_fixture_setup = 0;
  local.do_setup = 0;
  local.do_test = 0;
  local.do_teardown = 0;
  local.do_fixture_teardown = 0;
  return local;
}
static struct EvilUnit_Control EvilUnit_Control_Enable_Error(void)
{
  return EvilUnit_Control_Zeros();
}
static struct EvilUnit_Control EvilUnit_Control_Enable_Teardown(void)
{
  struct EvilUnit_Control local = EvilUnit_Control_Zeros();
  local.do_fixture_teardown = 1;
  return local;
}
static struct EvilUnit_Control EvilUnit_Control_Test_Returned(void)
{
  struct EvilUnit_Control local = EvilUnit_Control_Zeros();
  local.do_teardown = 0;
  local.do_fixture_teardown = 1;
  return local;
}
static struct EvilUnit_Control EvilUnit_Control_Update(enum EvilUnit_PHASE phase)
{
  switch (phase)
    {
    case FRAMEWORK_SETUP: return EvilUnit_Control_Enable_Error();
    case UNITTEST_SETUP: return EvilUnit_Control_Enable_Teardown();
    case UNITTEST_CODE: return EvilUnit_Control_Test_Returned();
    case UNITTEST_TEARDOWN: return EvilUnit_Control_Enable_Teardown();
    case FRAMEWORK_TEARDOWN: return EvilUnit_Control_Enable_Error();
    case FRAMEWORK_FINAL_RETURN: return EvilUnit_Control_Enable_Error();
    default: return EvilUnit_Control_Enable_Error();
    }
};
/* Create SETUP and TEARDOWN values in order to disguise whether the macros are in use */
static void SETUP(void) {return;}
static void TEARDOWN(void) {return;}
static void EvilUnit_Disguise_setup_teardown(void)
{
  SETUP();
  TEARDOWN();
  (void)EvilUnit_Control_Initial();
  (void)EvilUnit_Control_Update(FRAMEWORK_FINAL_RETURN);
  return;
}
/* First pass - declarations based on DEPENDS() and internal_get_number_of_tests */
/* Cannot use MODULE definition or test whether the test file is empty or not */
/* Can declare external function prototypes */
#ifdef __cplusplus
#define DEPENDS(X) extern "C" { int MAKETEST_CONCAT(EvilUnitTraverse_,X)(struct EvilUnitAddress * address, size_t depth, struct EvilUnitTraverseFunction * function_to_call, size_t * numeric_parameter, struct EvilUnitTestModule * module_parameter); }
#else
#define DEPENDS(X) int MAKETEST_CONCAT(EvilUnitTraverse_,X)(struct EvilUnitAddress * address, size_t depth, struct EvilUnitTraverseFunction * function_to_call, size_t * numeric_parameter, struct EvilUnitTestModule * module_parameter);
#endif
#define METHOD_PROLOG() static struct EvilUnitTestResult internal_get_number_of_tests(size_t * running_total) {size_t local_total = 0; SETUP();
#define TEST_BLOCK_HEADER(X,Y) local_total++; if (0)
#define METHOD_EPILOG() *running_total = local_total; TEARDOWN(); return PASS("Tests enumerated");}
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE
#include "EvilUnit.h"
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
#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK if (EvilUnit_ctrl.do_setup) { SETUP();{ EvilUnit_Phase = UNITTEST_CODE; if (EvilUnit_ctrl.do_test) {
#define FINALISE_TEST_RUN() }} EvilUnit_Phase = UNITTEST_TEARDOWN; if (EvilUnit_ctrl.do_teardown) { TEARDOWN(); } EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK SETUP();
#define FINALISE_TEST_RUN() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EVILUNIT_LABEL_FRAMEWORK_BEGINNING: ; EvilUnit_Phase = UNITTEST_SETUP;{
#define EvilUnit_TEARDOWN_BLOCK }} EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); if (EvilUnit_ctrl.do_fixture_teardown) { return FAKE(""); } RETURNVALUE = FAIL("FrameworkError"); return FAKE("");
#endif
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); struct EvilUnit_Control EvilUnit_ctrl = EvilUnit_Control_Initial(); (void) RETURNVALUE; (void) RETURNFLAG
#endif
#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")
#endif
#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) { EvilUnit_ctrl = EvilUnit_Control_Update(EvilUnit_Phase); goto EVILUNIT_LABEL_FRAMEWORK_BEGINNING; } else RETURNVALUE =
#endif
#endif
DEPEND_PROLOG()
#endif
#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif
#ifdef BUILD_PHASE_02
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
#ifdef __cplusplus
/* Prototype is declared here because it is otherwise difficult to wrap in extern "C" */
extern "C" {
int MAKETEST_CONCAT(EvilUnitTraverse_,MODULE)(struct EvilUnitAddress * address, size_t depth, struct EvilUnitTraverseFunction * function_to_call, size_t * numeric_parameter, struct EvilUnitTestModule * module_parameter);
}
#endif
/* Second pass - return will be overloaded to something terrible, so don't attempt to use DEPENDS() */
/* Generate the test functions */
#define GENERATE_TEST_FUNCTIONS 1
#define TEST_BLOCK_HEADER(X,Y) static struct EvilUnitTestResult GENTESTNAME(X,Y)(void)
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE
#include "EvilUnit.h"
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
#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK if (EvilUnit_ctrl.do_setup) { SETUP();{ EvilUnit_Phase = UNITTEST_CODE; if (EvilUnit_ctrl.do_test) {
#define FINALISE_TEST_RUN() }} EvilUnit_Phase = UNITTEST_TEARDOWN; if (EvilUnit_ctrl.do_teardown) { TEARDOWN(); } EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK SETUP();
#define FINALISE_TEST_RUN() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EVILUNIT_LABEL_FRAMEWORK_BEGINNING: ; EvilUnit_Phase = UNITTEST_SETUP;{
#define EvilUnit_TEARDOWN_BLOCK }} EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); if (EvilUnit_ctrl.do_fixture_teardown) { return FAKE(""); } RETURNVALUE = FAIL("FrameworkError"); return FAKE("");
#endif
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); struct EvilUnit_Control EvilUnit_ctrl = EvilUnit_Control_Initial(); (void) RETURNVALUE; (void) RETURNFLAG
#endif
#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")
#endif
#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) { EvilUnit_ctrl = EvilUnit_Control_Update(EvilUnit_Phase); goto EVILUNIT_LABEL_FRAMEWORK_BEGINNING; } else RETURNVALUE =
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
/* Third pass - generate run_all_tests_dependencies() */
#define DEPEND_PROLOG() static size_t get_number_of_dependencies(void) {size_t local = 0;
#define DEPENDS(X) local++;
#define DEPEND_EPILOG() return local;}
#define METHOD_PROLOG() static struct EvilUnitTestResult internal_get_test_number_from_name(const char * test_name, size_t * test_number) {size_t local_number = 0; (void)local_number; (void)test_name;
#define TEST_BLOCK_HEADER(X,Y) if (strcmp(test_name,MAKETEST_EXPAND_AND_QUOTE(GENTESTNAME(X,Y))) == 0) {*test_number = local_number; return PASS("Found test number"); } local_number++; if (0)
#define METHOD_EPILOG() *test_number = local_number; return FAIL("Did not identify test number");}
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE
#include "EvilUnit.h"
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
#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK if (EvilUnit_ctrl.do_setup) { SETUP();{ EvilUnit_Phase = UNITTEST_CODE; if (EvilUnit_ctrl.do_test) {
#define FINALISE_TEST_RUN() }} EvilUnit_Phase = UNITTEST_TEARDOWN; if (EvilUnit_ctrl.do_teardown) { TEARDOWN(); } EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK SETUP();
#define FINALISE_TEST_RUN() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EVILUNIT_LABEL_FRAMEWORK_BEGINNING: ; EvilUnit_Phase = UNITTEST_SETUP;{
#define EvilUnit_TEARDOWN_BLOCK }} EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); if (EvilUnit_ctrl.do_fixture_teardown) { return FAKE(""); } RETURNVALUE = FAIL("FrameworkError"); return FAKE("");
#endif
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); struct EvilUnit_Control EvilUnit_ctrl = EvilUnit_Control_Initial(); (void) RETURNVALUE; (void) RETURNFLAG
#endif
#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")
#endif
#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) { EvilUnit_ctrl = EvilUnit_Control_Update(EvilUnit_Phase); goto EVILUNIT_LABEL_FRAMEWORK_BEGINNING; } else RETURNVALUE =
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
#define METHOD_PROLOG() static struct EvilUnitTestResult internal_get_test_name_from_number(size_t test_number, const char ** test_name) {size_t local_number = 0; (void)local_number; (void)test_number;
#define TEST_BLOCK_HEADER(X,Y) if (test_number == local_number) { *test_name = MAKETEST_EXPAND_AND_QUOTE(GENTESTNAME(X,Y)); return PASS("Found test name"); } local_number++; if (0)
#define METHOD_EPILOG() *test_name = NULL; return FAIL("Did not identify test name");}
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE
#include "EvilUnit.h"
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
#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK if (EvilUnit_ctrl.do_setup) { SETUP();{ EvilUnit_Phase = UNITTEST_CODE; if (EvilUnit_ctrl.do_test) {
#define FINALISE_TEST_RUN() }} EvilUnit_Phase = UNITTEST_TEARDOWN; if (EvilUnit_ctrl.do_teardown) { TEARDOWN(); } EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK SETUP();
#define FINALISE_TEST_RUN() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EVILUNIT_LABEL_FRAMEWORK_BEGINNING: ; EvilUnit_Phase = UNITTEST_SETUP;{
#define EvilUnit_TEARDOWN_BLOCK }} EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); if (EvilUnit_ctrl.do_fixture_teardown) { return FAKE(""); } RETURNVALUE = FAIL("FrameworkError"); return FAKE("");
#endif
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); struct EvilUnit_Control EvilUnit_ctrl = EvilUnit_Control_Initial(); (void) RETURNVALUE; (void) RETURNFLAG
#endif
#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")
#endif
#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) { EvilUnit_ctrl = EvilUnit_Control_Update(EvilUnit_Phase); goto EVILUNIT_LABEL_FRAMEWORK_BEGINNING; } else RETURNVALUE =
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
#define DEPEND_PROLOG() int MAKETEST_CONCAT(EvilUnitTraverse_,MODULE)(struct EvilUnitAddress * address, size_t depth, struct EvilUnitTraverseFunction * function_to_call, size_t * numeric_parameter, struct EvilUnitTestModule * module_parameter) { size_t next_route; size_t local_number = 0; int rc; if (EvilUnit_traverse_at_destination(address,depth)) { switch (function_to_call->func) { case EnumGetIdentity: return EvilUnitGetIdentity(address, module_parameter,LOCALMODULENAME); case EnumGetNumberOfDependencies: return GetNumberOfDependencies(numeric_parameter); case EnumGetNumberOfLocalTests: return GetNumberOfLocalTests(numeric_parameter); case EnumGetNthDependency: return EvilUnitGetNthDependency(address, numeric_parameter, module_parameter); case EnumRunAllTests: return RunAllTests(module_parameter); default: assert(false); } } else { rc = EvilUnit_traverse_next_route(address,depth,&next_route); if (rc) {return rc;}
#define DEPENDS(X) if (next_route == local_number) { return MAKETEST_CONCAT(EvilUnitTraverse_,X)(address,depth+1,function_to_call,numeric_parameter,module_parameter); } local_number++;
#define DEPEND_EPILOG() (void)local_number; } return 1; }
#define METHOD_PROLOG() static struct EvilUnitTestResult call_test_by_number(size_t test_number) { size_t local_number = 0; (void)local_number;
#define TEST_BLOCK_HEADER(X,Y) if (test_number == local_number) { return GENTESTNAME(X,Y)(); } local_number++; if (0)
#define METHOD_EPILOG() return FAIL("Could not call test number %li",(long)test_number);}
#define EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE
#include "EvilUnit.h"
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
#if (! defined (GENERATE_TEST_FUNCTIONS) && ! defined (GENERATE_SINGLE_FUNCTION) )
#error "Need to define one of GENERATE_TEST_FUNCTIONS or GENERATE_SINGLE_FUNCTION";
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { char LOCALTESTNAME[] = MAKETEST_QUOTE(X); EvilUnit_STARTUP_BLOCK if (EvilUnit_ctrl.do_setup) { SETUP();{ EvilUnit_Phase = UNITTEST_CODE; if (EvilUnit_ctrl.do_test) {
#define FINALISE_TEST_RUN() }} EvilUnit_Phase = UNITTEST_TEARDOWN; if (EvilUnit_ctrl.do_teardown) { TEARDOWN(); } EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define SIMPLE_TEST_RUN(X,Y) TEST_BLOCK_HEADER(X,Y) { EvilUnit_STARTUP_BLOCK SETUP();
#define FINALISE_TEST_RUN() TEARDOWN(); EvilUnit_TEARDOWN_BLOCK }
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 2)
#define EvilUnit_STARTUP_BLOCK EvilUnit_LOCAL_VARIABLES; EVILUNIT_LABEL_FRAMEWORK_BEGINNING: ; EvilUnit_Phase = UNITTEST_SETUP;{
#define EvilUnit_TEARDOWN_BLOCK }} EvilUnit_Phase = FRAMEWORK_FINAL_RETURN; EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); if (EvilUnit_ctrl.do_fixture_teardown) { return FAKE(""); } RETURNVALUE = FAIL("FrameworkError"); return FAKE("");
#endif
#endif
#if defined(GENERATE_SINGLE_FUNCTION)
#define EvilUnit_STARTUP_BLOCK
#define EvilUnit_TEARDOWN_BLOCK
#endif
#if defined(GENERATE_TEST_FUNCTIONS)
#if (MACROLEVEL > 3)
#define EvilUnit_LOCAL_VARIABLES enum EvilUnit_PHASE EvilUnit_Phase = FRAMEWORK_SETUP; bool RETURNFLAG = true; struct EvilUnitTestResult RETURNVALUE = FAIL("Did not set return value"); struct EvilUnit_Control EvilUnit_ctrl = EvilUnit_Control_Initial(); (void) RETURNVALUE; (void) RETURNFLAG
#endif
#if (MACROLEVEL > 3)
#define EvilUnit_FINAL_RETURN EvilUnit_SetTestName(&RETURNVALUE,LOCALTESTNAME); return FAKE("")
#endif
#if (MACROLEVEL > 4)
#define return if (RETURNFLAG = false, EvilUnit_Phase==FRAMEWORK_FINAL_RETURN) return RETURNVALUE; else while(1) if (RETURNFLAG = !RETURNFLAG, !RETURNFLAG) { EvilUnit_ctrl = EvilUnit_Control_Update(EvilUnit_Phase); goto EVILUNIT_LABEL_FRAMEWORK_BEGINNING; } else RETURNVALUE =
#endif
#endif
DEPEND_PROLOG()
#endif
#ifdef MODULETESTFILE
#include MAKETEST_EXPAND_AND_QUOTE(MODULETESTFILE)
#endif
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
  const char * test_name = NULL;
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
  *data = (size_t *) malloc ((sizeof **data) * len);
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
  newpointer = (size_t *) realloc (*data, len * (sizeof **data));
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
  enum RESULT local = flag_INIT;
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
  *data = (struct EvilUnitTestResult *) malloc ((sizeof **data) * len);
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
  newpointer = (struct EvilUnitTestResult *) realloc (*data, len * (sizeof **data));
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
static const char *string_skip (void)
{
  return "SKIP";
};
static const char *string_other (void)
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
  *data = (struct EvilUnitTestModule *) malloc ((sizeof **data) * len);
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
  newpointer = (struct EvilUnitTestModule *) realloc (*data, len * (sizeof **data));
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
/* Search for initial value of counter, up to a maximum of 2^8 = 256 */
/* Will increment counter by exactly 9 */
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
  #if (__COUNTER__ <= (128+1)) /* Was [1-128] */
    #if (__COUNTER__ <= (64+2)) /* Was [1-64] */
      #if (__COUNTER__ <= (32+3)) /* Was [1-32] */
        #if (__COUNTER__ <= (16+4)) /* Was [1-16] */
          #if (__COUNTER__ <= (8+5)) /* Was [1-8] */
            #if (__COUNTER__ <= (4+6)) /* Was [1-4] */
              #if (__COUNTER__ <= (2+7)) /* Was [1-2] */
                #if (__COUNTER__ <= (1+8)) /* Was [1-1] */
                  #define ORIGINAL_COUNTER 1
                  #define VERIFICATION_COUNTER 10
                  #define PREDICTED_COUNTER 11
                #else /* Was [2-2] */
                  #define ORIGINAL_COUNTER 2
                  #define VERIFICATION_COUNTER 11
                  #define PREDICTED_COUNTER 12
                #endif
              #else /* Was [3-4] */
                #if (__COUNTER__ <= (3+8)) /* Was [3-3] */
                  #define ORIGINAL_COUNTER 3
                  #define VERIFICATION_COUNTER 12
                  #define PREDICTED_COUNTER 13
                #else /* Was [4-4] */
                  #define ORIGINAL_COUNTER 4
                  #define VERIFICATION_COUNTER 13
                  #define PREDICTED_COUNTER 14
                #endif
              #endif
            #else /* Was [5-8] */
              #if (__COUNTER__ <= (6+7)) /* Was [5-6] */
                #if (__COUNTER__ <= (5+8)) /* Was [5-5] */
                  #define ORIGINAL_COUNTER 5
                  #define VERIFICATION_COUNTER 14
                  #define PREDICTED_COUNTER 15
                #else /* Was [6-6] */
                  #define ORIGINAL_COUNTER 6
                  #define VERIFICATION_COUNTER 15
                  #define PREDICTED_COUNTER 16
                #endif
              #else /* Was [7-8] */
                #if (__COUNTER__ <= (7+8)) /* Was [7-7] */
                  #define ORIGINAL_COUNTER 7
                  #define VERIFICATION_COUNTER 16
                  #define PREDICTED_COUNTER 17
                #else /* Was [8-8] */
                  #define ORIGINAL_COUNTER 8
                  #define VERIFICATION_COUNTER 17
                  #define PREDICTED_COUNTER 18
                #endif
              #endif
            #endif
          #else /* Was [9-16] */
            #if (__COUNTER__ <= (12+6)) /* Was [9-12] */
              #if (__COUNTER__ <= (10+7)) /* Was [9-10] */
                #if (__COUNTER__ <= (9+8)) /* Was [9-9] */
                  #define ORIGINAL_COUNTER 9
                  #define VERIFICATION_COUNTER 18
                  #define PREDICTED_COUNTER 19
                #else /* Was [10-10] */
                  #define ORIGINAL_COUNTER 10
                  #define VERIFICATION_COUNTER 19
                  #define PREDICTED_COUNTER 20
                #endif
              #else /* Was [11-12] */
                #if (__COUNTER__ <= (11+8)) /* Was [11-11] */
                  #define ORIGINAL_COUNTER 11
                  #define VERIFICATION_COUNTER 20
                  #define PREDICTED_COUNTER 21
                #else /* Was [12-12] */
                  #define ORIGINAL_COUNTER 12
                  #define VERIFICATION_COUNTER 21
                  #define PREDICTED_COUNTER 22
                #endif
              #endif
            #else /* Was [13-16] */
              #if (__COUNTER__ <= (14+7)) /* Was [13-14] */
                #if (__COUNTER__ <= (13+8)) /* Was [13-13] */
                  #define ORIGINAL_COUNTER 13
                  #define VERIFICATION_COUNTER 22
                  #define PREDICTED_COUNTER 23
                #else /* Was [14-14] */
                  #define ORIGINAL_COUNTER 14
                  #define VERIFICATION_COUNTER 23
                  #define PREDICTED_COUNTER 24
                #endif
              #else /* Was [15-16] */
                #if (__COUNTER__ <= (15+8)) /* Was [15-15] */
                  #define ORIGINAL_COUNTER 15
                  #define VERIFICATION_COUNTER 24
                  #define PREDICTED_COUNTER 25
                #else /* Was [16-16] */
                  #define ORIGINAL_COUNTER 16
                  #define VERIFICATION_COUNTER 25
                  #define PREDICTED_COUNTER 26
                #endif
              #endif
            #endif
          #endif
        #else /* Was [17-32] */
          #if (__COUNTER__ <= (24+5)) /* Was [17-24] */
            #if (__COUNTER__ <= (20+6)) /* Was [17-20] */
              #if (__COUNTER__ <= (18+7)) /* Was [17-18] */
                #if (__COUNTER__ <= (17+8)) /* Was [17-17] */
                  #define ORIGINAL_COUNTER 17
                  #define VERIFICATION_COUNTER 26
                  #define PREDICTED_COUNTER 27
                #else /* Was [18-18] */
                  #define ORIGINAL_COUNTER 18
                  #define VERIFICATION_COUNTER 27
                  #define PREDICTED_COUNTER 28
                #endif
              #else /* Was [19-20] */
                #if (__COUNTER__ <= (19+8)) /* Was [19-19] */
                  #define ORIGINAL_COUNTER 19
                  #define VERIFICATION_COUNTER 28
                  #define PREDICTED_COUNTER 29
                #else /* Was [20-20] */
                  #define ORIGINAL_COUNTER 20
                  #define VERIFICATION_COUNTER 29
                  #define PREDICTED_COUNTER 30
                #endif
              #endif
            #else /* Was [21-24] */
              #if (__COUNTER__ <= (22+7)) /* Was [21-22] */
                #if (__COUNTER__ <= (21+8)) /* Was [21-21] */
                  #define ORIGINAL_COUNTER 21
                  #define VERIFICATION_COUNTER 30
                  #define PREDICTED_COUNTER 31
                #else /* Was [22-22] */
                  #define ORIGINAL_COUNTER 22
                  #define VERIFICATION_COUNTER 31
                  #define PREDICTED_COUNTER 32
                #endif
              #else /* Was [23-24] */
                #if (__COUNTER__ <= (23+8)) /* Was [23-23] */
                  #define ORIGINAL_COUNTER 23
                  #define VERIFICATION_COUNTER 32
                  #define PREDICTED_COUNTER 33
                #else /* Was [24-24] */
                  #define ORIGINAL_COUNTER 24
                  #define VERIFICATION_COUNTER 33
                  #define PREDICTED_COUNTER 34
                #endif
              #endif
            #endif
          #else /* Was [25-32] */
            #if (__COUNTER__ <= (28+6)) /* Was [25-28] */
              #if (__COUNTER__ <= (26+7)) /* Was [25-26] */
                #if (__COUNTER__ <= (25+8)) /* Was [25-25] */
                  #define ORIGINAL_COUNTER 25
                  #define VERIFICATION_COUNTER 34
                  #define PREDICTED_COUNTER 35
                #else /* Was [26-26] */
                  #define ORIGINAL_COUNTER 26
                  #define VERIFICATION_COUNTER 35
                  #define PREDICTED_COUNTER 36
                #endif
              #else /* Was [27-28] */
                #if (__COUNTER__ <= (27+8)) /* Was [27-27] */
                  #define ORIGINAL_COUNTER 27
                  #define VERIFICATION_COUNTER 36
                  #define PREDICTED_COUNTER 37
                #else /* Was [28-28] */
                  #define ORIGINAL_COUNTER 28
                  #define VERIFICATION_COUNTER 37
                  #define PREDICTED_COUNTER 38
                #endif
              #endif
            #else /* Was [29-32] */
              #if (__COUNTER__ <= (30+7)) /* Was [29-30] */
                #if (__COUNTER__ <= (29+8)) /* Was [29-29] */
                  #define ORIGINAL_COUNTER 29
                  #define VERIFICATION_COUNTER 38
                  #define PREDICTED_COUNTER 39
                #else /* Was [30-30] */
                  #define ORIGINAL_COUNTER 30
                  #define VERIFICATION_COUNTER 39
                  #define PREDICTED_COUNTER 40
                #endif
              #else /* Was [31-32] */
                #if (__COUNTER__ <= (31+8)) /* Was [31-31] */
                  #define ORIGINAL_COUNTER 31
                  #define VERIFICATION_COUNTER 40
                  #define PREDICTED_COUNTER 41
                #else /* Was [32-32] */
                  #define ORIGINAL_COUNTER 32
                  #define VERIFICATION_COUNTER 41
                  #define PREDICTED_COUNTER 42
                #endif
              #endif
            #endif
          #endif
        #endif
      #else /* Was [33-64] */
        #if (__COUNTER__ <= (48+4)) /* Was [33-48] */
          #if (__COUNTER__ <= (40+5)) /* Was [33-40] */
            #if (__COUNTER__ <= (36+6)) /* Was [33-36] */
              #if (__COUNTER__ <= (34+7)) /* Was [33-34] */
                #if (__COUNTER__ <= (33+8)) /* Was [33-33] */
                  #define ORIGINAL_COUNTER 33
                  #define VERIFICATION_COUNTER 42
                  #define PREDICTED_COUNTER 43
                #else /* Was [34-34] */
                  #define ORIGINAL_COUNTER 34
                  #define VERIFICATION_COUNTER 43
                  #define PREDICTED_COUNTER 44
                #endif
              #else /* Was [35-36] */
                #if (__COUNTER__ <= (35+8)) /* Was [35-35] */
                  #define ORIGINAL_COUNTER 35
                  #define VERIFICATION_COUNTER 44
                  #define PREDICTED_COUNTER 45
                #else /* Was [36-36] */
                  #define ORIGINAL_COUNTER 36
                  #define VERIFICATION_COUNTER 45
                  #define PREDICTED_COUNTER 46
                #endif
              #endif
            #else /* Was [37-40] */
              #if (__COUNTER__ <= (38+7)) /* Was [37-38] */
                #if (__COUNTER__ <= (37+8)) /* Was [37-37] */
                  #define ORIGINAL_COUNTER 37
                  #define VERIFICATION_COUNTER 46
                  #define PREDICTED_COUNTER 47
                #else /* Was [38-38] */
                  #define ORIGINAL_COUNTER 38
                  #define VERIFICATION_COUNTER 47
                  #define PREDICTED_COUNTER 48
                #endif
              #else /* Was [39-40] */
                #if (__COUNTER__ <= (39+8)) /* Was [39-39] */
                  #define ORIGINAL_COUNTER 39
                  #define VERIFICATION_COUNTER 48
                  #define PREDICTED_COUNTER 49
                #else /* Was [40-40] */
                  #define ORIGINAL_COUNTER 40
                  #define VERIFICATION_COUNTER 49
                  #define PREDICTED_COUNTER 50
                #endif
              #endif
            #endif
          #else /* Was [41-48] */
            #if (__COUNTER__ <= (44+6)) /* Was [41-44] */
              #if (__COUNTER__ <= (42+7)) /* Was [41-42] */
                #if (__COUNTER__ <= (41+8)) /* Was [41-41] */
                  #define ORIGINAL_COUNTER 41
                  #define VERIFICATION_COUNTER 50
                  #define PREDICTED_COUNTER 51
                #else /* Was [42-42] */
                  #define ORIGINAL_COUNTER 42
                  #define VERIFICATION_COUNTER 51
                  #define PREDICTED_COUNTER 52
                #endif
              #else /* Was [43-44] */
                #if (__COUNTER__ <= (43+8)) /* Was [43-43] */
                  #define ORIGINAL_COUNTER 43
                  #define VERIFICATION_COUNTER 52
                  #define PREDICTED_COUNTER 53
                #else /* Was [44-44] */
                  #define ORIGINAL_COUNTER 44
                  #define VERIFICATION_COUNTER 53
                  #define PREDICTED_COUNTER 54
                #endif
              #endif
            #else /* Was [45-48] */
              #if (__COUNTER__ <= (46+7)) /* Was [45-46] */
                #if (__COUNTER__ <= (45+8)) /* Was [45-45] */
                  #define ORIGINAL_COUNTER 45
                  #define VERIFICATION_COUNTER 54
                  #define PREDICTED_COUNTER 55
                #else /* Was [46-46] */
                  #define ORIGINAL_COUNTER 46
                  #define VERIFICATION_COUNTER 55
                  #define PREDICTED_COUNTER 56
                #endif
              #else /* Was [47-48] */
                #if (__COUNTER__ <= (47+8)) /* Was [47-47] */
                  #define ORIGINAL_COUNTER 47
                  #define VERIFICATION_COUNTER 56
                  #define PREDICTED_COUNTER 57
                #else /* Was [48-48] */
                  #define ORIGINAL_COUNTER 48
                  #define VERIFICATION_COUNTER 57
                  #define PREDICTED_COUNTER 58
                #endif
              #endif
            #endif
          #endif
        #else /* Was [49-64] */
          #if (__COUNTER__ <= (56+5)) /* Was [49-56] */
            #if (__COUNTER__ <= (52+6)) /* Was [49-52] */
              #if (__COUNTER__ <= (50+7)) /* Was [49-50] */
                #if (__COUNTER__ <= (49+8)) /* Was [49-49] */
                  #define ORIGINAL_COUNTER 49
                  #define VERIFICATION_COUNTER 58
                  #define PREDICTED_COUNTER 59
                #else /* Was [50-50] */
                  #define ORIGINAL_COUNTER 50
                  #define VERIFICATION_COUNTER 59
                  #define PREDICTED_COUNTER 60
                #endif
              #else /* Was [51-52] */
                #if (__COUNTER__ <= (51+8)) /* Was [51-51] */
                  #define ORIGINAL_COUNTER 51
                  #define VERIFICATION_COUNTER 60
                  #define PREDICTED_COUNTER 61
                #else /* Was [52-52] */
                  #define ORIGINAL_COUNTER 52
                  #define VERIFICATION_COUNTER 61
                  #define PREDICTED_COUNTER 62
                #endif
              #endif
            #else /* Was [53-56] */
              #if (__COUNTER__ <= (54+7)) /* Was [53-54] */
                #if (__COUNTER__ <= (53+8)) /* Was [53-53] */
                  #define ORIGINAL_COUNTER 53
                  #define VERIFICATION_COUNTER 62
                  #define PREDICTED_COUNTER 63
                #else /* Was [54-54] */
                  #define ORIGINAL_COUNTER 54
                  #define VERIFICATION_COUNTER 63
                  #define PREDICTED_COUNTER 64
                #endif
              #else /* Was [55-56] */
                #if (__COUNTER__ <= (55+8)) /* Was [55-55] */
                  #define ORIGINAL_COUNTER 55
                  #define VERIFICATION_COUNTER 64
                  #define PREDICTED_COUNTER 65
                #else /* Was [56-56] */
                  #define ORIGINAL_COUNTER 56
                  #define VERIFICATION_COUNTER 65
                  #define PREDICTED_COUNTER 66
                #endif
              #endif
            #endif
          #else /* Was [57-64] */
            #if (__COUNTER__ <= (60+6)) /* Was [57-60] */
              #if (__COUNTER__ <= (58+7)) /* Was [57-58] */
                #if (__COUNTER__ <= (57+8)) /* Was [57-57] */
                  #define ORIGINAL_COUNTER 57
                  #define VERIFICATION_COUNTER 66
                  #define PREDICTED_COUNTER 67
                #else /* Was [58-58] */
                  #define ORIGINAL_COUNTER 58
                  #define VERIFICATION_COUNTER 67
                  #define PREDICTED_COUNTER 68
                #endif
              #else /* Was [59-60] */
                #if (__COUNTER__ <= (59+8)) /* Was [59-59] */
                  #define ORIGINAL_COUNTER 59
                  #define VERIFICATION_COUNTER 68
                  #define PREDICTED_COUNTER 69
                #else /* Was [60-60] */
                  #define ORIGINAL_COUNTER 60
                  #define VERIFICATION_COUNTER 69
                  #define PREDICTED_COUNTER 70
                #endif
              #endif
            #else /* Was [61-64] */
              #if (__COUNTER__ <= (62+7)) /* Was [61-62] */
                #if (__COUNTER__ <= (61+8)) /* Was [61-61] */
                  #define ORIGINAL_COUNTER 61
                  #define VERIFICATION_COUNTER 70
                  #define PREDICTED_COUNTER 71
                #else /* Was [62-62] */
                  #define ORIGINAL_COUNTER 62
                  #define VERIFICATION_COUNTER 71
                  #define PREDICTED_COUNTER 72
                #endif
              #else /* Was [63-64] */
                #if (__COUNTER__ <= (63+8)) /* Was [63-63] */
                  #define ORIGINAL_COUNTER 63
                  #define VERIFICATION_COUNTER 72
                  #define PREDICTED_COUNTER 73
                #else /* Was [64-64] */
                  #define ORIGINAL_COUNTER 64
                  #define VERIFICATION_COUNTER 73
                  #define PREDICTED_COUNTER 74
                #endif
              #endif
            #endif
          #endif
        #endif
      #endif
    #else /* Was [65-128] */
      #if (__COUNTER__ <= (96+3)) /* Was [65-96] */
        #if (__COUNTER__ <= (80+4)) /* Was [65-80] */
          #if (__COUNTER__ <= (72+5)) /* Was [65-72] */
            #if (__COUNTER__ <= (68+6)) /* Was [65-68] */
              #if (__COUNTER__ <= (66+7)) /* Was [65-66] */
                #if (__COUNTER__ <= (65+8)) /* Was [65-65] */
                  #define ORIGINAL_COUNTER 65
                  #define VERIFICATION_COUNTER 74
                  #define PREDICTED_COUNTER 75
                #else /* Was [66-66] */
                  #define ORIGINAL_COUNTER 66
                  #define VERIFICATION_COUNTER 75
                  #define PREDICTED_COUNTER 76
                #endif
              #else /* Was [67-68] */
                #if (__COUNTER__ <= (67+8)) /* Was [67-67] */
                  #define ORIGINAL_COUNTER 67
                  #define VERIFICATION_COUNTER 76
                  #define PREDICTED_COUNTER 77
                #else /* Was [68-68] */
                  #define ORIGINAL_COUNTER 68
                  #define VERIFICATION_COUNTER 77
                  #define PREDICTED_COUNTER 78
                #endif
              #endif
            #else /* Was [69-72] */
              #if (__COUNTER__ <= (70+7)) /* Was [69-70] */
                #if (__COUNTER__ <= (69+8)) /* Was [69-69] */
                  #define ORIGINAL_COUNTER 69
                  #define VERIFICATION_COUNTER 78
                  #define PREDICTED_COUNTER 79
                #else /* Was [70-70] */
                  #define ORIGINAL_COUNTER 70
                  #define VERIFICATION_COUNTER 79
                  #define PREDICTED_COUNTER 80
                #endif
              #else /* Was [71-72] */
                #if (__COUNTER__ <= (71+8)) /* Was [71-71] */
                  #define ORIGINAL_COUNTER 71
                  #define VERIFICATION_COUNTER 80
                  #define PREDICTED_COUNTER 81
                #else /* Was [72-72] */
                  #define ORIGINAL_COUNTER 72
                  #define VERIFICATION_COUNTER 81
                  #define PREDICTED_COUNTER 82
                #endif
              #endif
            #endif
          #else /* Was [73-80] */
            #if (__COUNTER__ <= (76+6)) /* Was [73-76] */
              #if (__COUNTER__ <= (74+7)) /* Was [73-74] */
                #if (__COUNTER__ <= (73+8)) /* Was [73-73] */
                  #define ORIGINAL_COUNTER 73
                  #define VERIFICATION_COUNTER 82
                  #define PREDICTED_COUNTER 83
                #else /* Was [74-74] */
                  #define ORIGINAL_COUNTER 74
                  #define VERIFICATION_COUNTER 83
                  #define PREDICTED_COUNTER 84
                #endif
              #else /* Was [75-76] */
                #if (__COUNTER__ <= (75+8)) /* Was [75-75] */
                  #define ORIGINAL_COUNTER 75
                  #define VERIFICATION_COUNTER 84
                  #define PREDICTED_COUNTER 85
                #else /* Was [76-76] */
                  #define ORIGINAL_COUNTER 76
                  #define VERIFICATION_COUNTER 85
                  #define PREDICTED_COUNTER 86
                #endif
              #endif
            #else /* Was [77-80] */
              #if (__COUNTER__ <= (78+7)) /* Was [77-78] */
                #if (__COUNTER__ <= (77+8)) /* Was [77-77] */
                  #define ORIGINAL_COUNTER 77
                  #define VERIFICATION_COUNTER 86
                  #define PREDICTED_COUNTER 87
                #else /* Was [78-78] */
                  #define ORIGINAL_COUNTER 78
                  #define VERIFICATION_COUNTER 87
                  #define PREDICTED_COUNTER 88
                #endif
              #else /* Was [79-80] */
                #if (__COUNTER__ <= (79+8)) /* Was [79-79] */
                  #define ORIGINAL_COUNTER 79
                  #define VERIFICATION_COUNTER 88
                  #define PREDICTED_COUNTER 89
                #else /* Was [80-80] */
                  #define ORIGINAL_COUNTER 80
                  #define VERIFICATION_COUNTER 89
                  #define PREDICTED_COUNTER 90
                #endif
              #endif
            #endif
          #endif
        #else /* Was [81-96] */
          #if (__COUNTER__ <= (88+5)) /* Was [81-88] */
            #if (__COUNTER__ <= (84+6)) /* Was [81-84] */
              #if (__COUNTER__ <= (82+7)) /* Was [81-82] */
                #if (__COUNTER__ <= (81+8)) /* Was [81-81] */
                  #define ORIGINAL_COUNTER 81
                  #define VERIFICATION_COUNTER 90
                  #define PREDICTED_COUNTER 91
                #else /* Was [82-82] */
                  #define ORIGINAL_COUNTER 82
                  #define VERIFICATION_COUNTER 91
                  #define PREDICTED_COUNTER 92
                #endif
              #else /* Was [83-84] */
                #if (__COUNTER__ <= (83+8)) /* Was [83-83] */
                  #define ORIGINAL_COUNTER 83
                  #define VERIFICATION_COUNTER 92
                  #define PREDICTED_COUNTER 93
                #else /* Was [84-84] */
                  #define ORIGINAL_COUNTER 84
                  #define VERIFICATION_COUNTER 93
                  #define PREDICTED_COUNTER 94
                #endif
              #endif
            #else /* Was [85-88] */
              #if (__COUNTER__ <= (86+7)) /* Was [85-86] */
                #if (__COUNTER__ <= (85+8)) /* Was [85-85] */
                  #define ORIGINAL_COUNTER 85
                  #define VERIFICATION_COUNTER 94
                  #define PREDICTED_COUNTER 95
                #else /* Was [86-86] */
                  #define ORIGINAL_COUNTER 86
                  #define VERIFICATION_COUNTER 95
                  #define PREDICTED_COUNTER 96
                #endif
              #else /* Was [87-88] */
                #if (__COUNTER__ <= (87+8)) /* Was [87-87] */
                  #define ORIGINAL_COUNTER 87
                  #define VERIFICATION_COUNTER 96
                  #define PREDICTED_COUNTER 97
                #else /* Was [88-88] */
                  #define ORIGINAL_COUNTER 88
                  #define VERIFICATION_COUNTER 97
                  #define PREDICTED_COUNTER 98
                #endif
              #endif
            #endif
          #else /* Was [89-96] */
            #if (__COUNTER__ <= (92+6)) /* Was [89-92] */
              #if (__COUNTER__ <= (90+7)) /* Was [89-90] */
                #if (__COUNTER__ <= (89+8)) /* Was [89-89] */
                  #define ORIGINAL_COUNTER 89
                  #define VERIFICATION_COUNTER 98
                  #define PREDICTED_COUNTER 99
                #else /* Was [90-90] */
                  #define ORIGINAL_COUNTER 90
                  #define VERIFICATION_COUNTER 99
                  #define PREDICTED_COUNTER 100
                #endif
              #else /* Was [91-92] */
                #if (__COUNTER__ <= (91+8)) /* Was [91-91] */
                  #define ORIGINAL_COUNTER 91
                  #define VERIFICATION_COUNTER 100
                  #define PREDICTED_COUNTER 101
                #else /* Was [92-92] */
                  #define ORIGINAL_COUNTER 92
                  #define VERIFICATION_COUNTER 101
                  #define PREDICTED_COUNTER 102
                #endif
              #endif
            #else /* Was [93-96] */
              #if (__COUNTER__ <= (94+7)) /* Was [93-94] */
                #if (__COUNTER__ <= (93+8)) /* Was [93-93] */
                  #define ORIGINAL_COUNTER 93
                  #define VERIFICATION_COUNTER 102
                  #define PREDICTED_COUNTER 103
                #else /* Was [94-94] */
                  #define ORIGINAL_COUNTER 94
                  #define VERIFICATION_COUNTER 103
                  #define PREDICTED_COUNTER 104
                #endif
              #else /* Was [95-96] */
                #if (__COUNTER__ <= (95+8)) /* Was [95-95] */
                  #define ORIGINAL_COUNTER 95
                  #define VERIFICATION_COUNTER 104
                  #define PREDICTED_COUNTER 105
                #else /* Was [96-96] */
                  #define ORIGINAL_COUNTER 96
                  #define VERIFICATION_COUNTER 105
                  #define PREDICTED_COUNTER 106
                #endif
              #endif
            #endif
          #endif
        #endif
      #else /* Was [97-128] */
        #if (__COUNTER__ <= (112+4)) /* Was [97-112] */
          #if (__COUNTER__ <= (104+5)) /* Was [97-104] */
            #if (__COUNTER__ <= (100+6)) /* Was [97-100] */
              #if (__COUNTER__ <= (98+7)) /* Was [97-98] */
                #if (__COUNTER__ <= (97+8)) /* Was [97-97] */
                  #define ORIGINAL_COUNTER 97
                  #define VERIFICATION_COUNTER 106
                  #define PREDICTED_COUNTER 107
                #else /* Was [98-98] */
                  #define ORIGINAL_COUNTER 98
                  #define VERIFICATION_COUNTER 107
                  #define PREDICTED_COUNTER 108
                #endif
              #else /* Was [99-100] */
                #if (__COUNTER__ <= (99+8)) /* Was [99-99] */
                  #define ORIGINAL_COUNTER 99
                  #define VERIFICATION_COUNTER 108
                  #define PREDICTED_COUNTER 109
                #else /* Was [100-100] */
                  #define ORIGINAL_COUNTER 100
                  #define VERIFICATION_COUNTER 109
                  #define PREDICTED_COUNTER 110
                #endif
              #endif
            #else /* Was [101-104] */
              #if (__COUNTER__ <= (102+7)) /* Was [101-102] */
                #if (__COUNTER__ <= (101+8)) /* Was [101-101] */
                  #define ORIGINAL_COUNTER 101
                  #define VERIFICATION_COUNTER 110
                  #define PREDICTED_COUNTER 111
                #else /* Was [102-102] */
                  #define ORIGINAL_COUNTER 102
                  #define VERIFICATION_COUNTER 111
                  #define PREDICTED_COUNTER 112
                #endif
              #else /* Was [103-104] */
                #if (__COUNTER__ <= (103+8)) /* Was [103-103] */
                  #define ORIGINAL_COUNTER 103
                  #define VERIFICATION_COUNTER 112
                  #define PREDICTED_COUNTER 113
                #else /* Was [104-104] */
                  #define ORIGINAL_COUNTER 104
                  #define VERIFICATION_COUNTER 113
                  #define PREDICTED_COUNTER 114
                #endif
              #endif
            #endif
          #else /* Was [105-112] */
            #if (__COUNTER__ <= (108+6)) /* Was [105-108] */
              #if (__COUNTER__ <= (106+7)) /* Was [105-106] */
                #if (__COUNTER__ <= (105+8)) /* Was [105-105] */
                  #define ORIGINAL_COUNTER 105
                  #define VERIFICATION_COUNTER 114
                  #define PREDICTED_COUNTER 115
                #else /* Was [106-106] */
                  #define ORIGINAL_COUNTER 106
                  #define VERIFICATION_COUNTER 115
                  #define PREDICTED_COUNTER 116
                #endif
              #else /* Was [107-108] */
                #if (__COUNTER__ <= (107+8)) /* Was [107-107] */
                  #define ORIGINAL_COUNTER 107
                  #define VERIFICATION_COUNTER 116
                  #define PREDICTED_COUNTER 117
                #else /* Was [108-108] */
                  #define ORIGINAL_COUNTER 108
                  #define VERIFICATION_COUNTER 117
                  #define PREDICTED_COUNTER 118
                #endif
              #endif
            #else /* Was [109-112] */
              #if (__COUNTER__ <= (110+7)) /* Was [109-110] */
                #if (__COUNTER__ <= (109+8)) /* Was [109-109] */
                  #define ORIGINAL_COUNTER 109
                  #define VERIFICATION_COUNTER 118
                  #define PREDICTED_COUNTER 119
                #else /* Was [110-110] */
                  #define ORIGINAL_COUNTER 110
                  #define VERIFICATION_COUNTER 119
                  #define PREDICTED_COUNTER 120
                #endif
              #else /* Was [111-112] */
                #if (__COUNTER__ <= (111+8)) /* Was [111-111] */
                  #define ORIGINAL_COUNTER 111
                  #define VERIFICATION_COUNTER 120
                  #define PREDICTED_COUNTER 121
                #else /* Was [112-112] */
                  #define ORIGINAL_COUNTER 112
                  #define VERIFICATION_COUNTER 121
                  #define PREDICTED_COUNTER 122
                #endif
              #endif
            #endif
          #endif
        #else /* Was [113-128] */
          #if (__COUNTER__ <= (120+5)) /* Was [113-120] */
            #if (__COUNTER__ <= (116+6)) /* Was [113-116] */
              #if (__COUNTER__ <= (114+7)) /* Was [113-114] */
                #if (__COUNTER__ <= (113+8)) /* Was [113-113] */
                  #define ORIGINAL_COUNTER 113
                  #define VERIFICATION_COUNTER 122
                  #define PREDICTED_COUNTER 123
                #else /* Was [114-114] */
                  #define ORIGINAL_COUNTER 114
                  #define VERIFICATION_COUNTER 123
                  #define PREDICTED_COUNTER 124
                #endif
              #else /* Was [115-116] */
                #if (__COUNTER__ <= (115+8)) /* Was [115-115] */
                  #define ORIGINAL_COUNTER 115
                  #define VERIFICATION_COUNTER 124
                  #define PREDICTED_COUNTER 125
                #else /* Was [116-116] */
                  #define ORIGINAL_COUNTER 116
                  #define VERIFICATION_COUNTER 125
                  #define PREDICTED_COUNTER 126
                #endif
              #endif
            #else /* Was [117-120] */
              #if (__COUNTER__ <= (118+7)) /* Was [117-118] */
                #if (__COUNTER__ <= (117+8)) /* Was [117-117] */
                  #define ORIGINAL_COUNTER 117
                  #define VERIFICATION_COUNTER 126
                  #define PREDICTED_COUNTER 127
                #else /* Was [118-118] */
                  #define ORIGINAL_COUNTER 118
                  #define VERIFICATION_COUNTER 127
                  #define PREDICTED_COUNTER 128
                #endif
              #else /* Was [119-120] */
                #if (__COUNTER__ <= (119+8)) /* Was [119-119] */
                  #define ORIGINAL_COUNTER 119
                  #define VERIFICATION_COUNTER 128
                  #define PREDICTED_COUNTER 129
                #else /* Was [120-120] */
                  #define ORIGINAL_COUNTER 120
                  #define VERIFICATION_COUNTER 129
                  #define PREDICTED_COUNTER 130
                #endif
              #endif
            #endif
          #else /* Was [121-128] */
            #if (__COUNTER__ <= (124+6)) /* Was [121-124] */
              #if (__COUNTER__ <= (122+7)) /* Was [121-122] */
                #if (__COUNTER__ <= (121+8)) /* Was [121-121] */
                  #define ORIGINAL_COUNTER 121
                  #define VERIFICATION_COUNTER 130
                  #define PREDICTED_COUNTER 131
                #else /* Was [122-122] */
                  #define ORIGINAL_COUNTER 122
                  #define VERIFICATION_COUNTER 131
                  #define PREDICTED_COUNTER 132
                #endif
              #else /* Was [123-124] */
                #if (__COUNTER__ <= (123+8)) /* Was [123-123] */
                  #define ORIGINAL_COUNTER 123
                  #define VERIFICATION_COUNTER 132
                  #define PREDICTED_COUNTER 133
                #else /* Was [124-124] */
                  #define ORIGINAL_COUNTER 124
                  #define VERIFICATION_COUNTER 133
                  #define PREDICTED_COUNTER 134
                #endif
              #endif
            #else /* Was [125-128] */
              #if (__COUNTER__ <= (126+7)) /* Was [125-126] */
                #if (__COUNTER__ <= (125+8)) /* Was [125-125] */
                  #define ORIGINAL_COUNTER 125
                  #define VERIFICATION_COUNTER 134
                  #define PREDICTED_COUNTER 135
                #else /* Was [126-126] */
                  #define ORIGINAL_COUNTER 126
                  #define VERIFICATION_COUNTER 135
                  #define PREDICTED_COUNTER 136
                #endif
              #else /* Was [127-128] */
                #if (__COUNTER__ <= (127+8)) /* Was [127-127] */
                  #define ORIGINAL_COUNTER 127
                  #define VERIFICATION_COUNTER 136
                  #define PREDICTED_COUNTER 137
                #else /* Was [128-128] */
                  #define ORIGINAL_COUNTER 128
                  #define VERIFICATION_COUNTER 137
                  #define PREDICTED_COUNTER 138
                #endif
              #endif
            #endif
          #endif
        #endif
      #endif
    #endif
  #else /* Was [129-256] */
    #if (__COUNTER__ <= (192+2)) /* Was [129-192] */
      #if (__COUNTER__ <= (160+3)) /* Was [129-160] */
        #if (__COUNTER__ <= (144+4)) /* Was [129-144] */
          #if (__COUNTER__ <= (136+5)) /* Was [129-136] */
            #if (__COUNTER__ <= (132+6)) /* Was [129-132] */
              #if (__COUNTER__ <= (130+7)) /* Was [129-130] */
                #if (__COUNTER__ <= (129+8)) /* Was [129-129] */
                  #define ORIGINAL_COUNTER 129
                  #define VERIFICATION_COUNTER 138
                  #define PREDICTED_COUNTER 139
                #else /* Was [130-130] */
                  #define ORIGINAL_COUNTER 130
                  #define VERIFICATION_COUNTER 139
                  #define PREDICTED_COUNTER 140
                #endif
              #else /* Was [131-132] */
                #if (__COUNTER__ <= (131+8)) /* Was [131-131] */
                  #define ORIGINAL_COUNTER 131
                  #define VERIFICATION_COUNTER 140
                  #define PREDICTED_COUNTER 141
                #else /* Was [132-132] */
                  #define ORIGINAL_COUNTER 132
                  #define VERIFICATION_COUNTER 141
                  #define PREDICTED_COUNTER 142
                #endif
              #endif
            #else /* Was [133-136] */
              #if (__COUNTER__ <= (134+7)) /* Was [133-134] */
                #if (__COUNTER__ <= (133+8)) /* Was [133-133] */
                  #define ORIGINAL_COUNTER 133
                  #define VERIFICATION_COUNTER 142
                  #define PREDICTED_COUNTER 143
                #else /* Was [134-134] */
                  #define ORIGINAL_COUNTER 134
                  #define VERIFICATION_COUNTER 143
                  #define PREDICTED_COUNTER 144
                #endif
              #else /* Was [135-136] */
                #if (__COUNTER__ <= (135+8)) /* Was [135-135] */
                  #define ORIGINAL_COUNTER 135
                  #define VERIFICATION_COUNTER 144
                  #define PREDICTED_COUNTER 145
                #else /* Was [136-136] */
                  #define ORIGINAL_COUNTER 136
                  #define VERIFICATION_COUNTER 145
                  #define PREDICTED_COUNTER 146
                #endif
              #endif
            #endif
          #else /* Was [137-144] */
            #if (__COUNTER__ <= (140+6)) /* Was [137-140] */
              #if (__COUNTER__ <= (138+7)) /* Was [137-138] */
                #if (__COUNTER__ <= (137+8)) /* Was [137-137] */
                  #define ORIGINAL_COUNTER 137
                  #define VERIFICATION_COUNTER 146
                  #define PREDICTED_COUNTER 147
                #else /* Was [138-138] */
                  #define ORIGINAL_COUNTER 138
                  #define VERIFICATION_COUNTER 147
                  #define PREDICTED_COUNTER 148
                #endif
              #else /* Was [139-140] */
                #if (__COUNTER__ <= (139+8)) /* Was [139-139] */
                  #define ORIGINAL_COUNTER 139
                  #define VERIFICATION_COUNTER 148
                  #define PREDICTED_COUNTER 149
                #else /* Was [140-140] */
                  #define ORIGINAL_COUNTER 140
                  #define VERIFICATION_COUNTER 149
                  #define PREDICTED_COUNTER 150
                #endif
              #endif
            #else /* Was [141-144] */
              #if (__COUNTER__ <= (142+7)) /* Was [141-142] */
                #if (__COUNTER__ <= (141+8)) /* Was [141-141] */
                  #define ORIGINAL_COUNTER 141
                  #define VERIFICATION_COUNTER 150
                  #define PREDICTED_COUNTER 151
                #else /* Was [142-142] */
                  #define ORIGINAL_COUNTER 142
                  #define VERIFICATION_COUNTER 151
                  #define PREDICTED_COUNTER 152
                #endif
              #else /* Was [143-144] */
                #if (__COUNTER__ <= (143+8)) /* Was [143-143] */
                  #define ORIGINAL_COUNTER 143
                  #define VERIFICATION_COUNTER 152
                  #define PREDICTED_COUNTER 153
                #else /* Was [144-144] */
                  #define ORIGINAL_COUNTER 144
                  #define VERIFICATION_COUNTER 153
                  #define PREDICTED_COUNTER 154
                #endif
              #endif
            #endif
          #endif
        #else /* Was [145-160] */
          #if (__COUNTER__ <= (152+5)) /* Was [145-152] */
            #if (__COUNTER__ <= (148+6)) /* Was [145-148] */
              #if (__COUNTER__ <= (146+7)) /* Was [145-146] */
                #if (__COUNTER__ <= (145+8)) /* Was [145-145] */
                  #define ORIGINAL_COUNTER 145
                  #define VERIFICATION_COUNTER 154
                  #define PREDICTED_COUNTER 155
                #else /* Was [146-146] */
                  #define ORIGINAL_COUNTER 146
                  #define VERIFICATION_COUNTER 155
                  #define PREDICTED_COUNTER 156
                #endif
              #else /* Was [147-148] */
                #if (__COUNTER__ <= (147+8)) /* Was [147-147] */
                  #define ORIGINAL_COUNTER 147
                  #define VERIFICATION_COUNTER 156
                  #define PREDICTED_COUNTER 157
                #else /* Was [148-148] */
                  #define ORIGINAL_COUNTER 148
                  #define VERIFICATION_COUNTER 157
                  #define PREDICTED_COUNTER 158
                #endif
              #endif
            #else /* Was [149-152] */
              #if (__COUNTER__ <= (150+7)) /* Was [149-150] */
                #if (__COUNTER__ <= (149+8)) /* Was [149-149] */
                  #define ORIGINAL_COUNTER 149
                  #define VERIFICATION_COUNTER 158
                  #define PREDICTED_COUNTER 159
                #else /* Was [150-150] */
                  #define ORIGINAL_COUNTER 150
                  #define VERIFICATION_COUNTER 159
                  #define PREDICTED_COUNTER 160
                #endif
              #else /* Was [151-152] */
                #if (__COUNTER__ <= (151+8)) /* Was [151-151] */
                  #define ORIGINAL_COUNTER 151
                  #define VERIFICATION_COUNTER 160
                  #define PREDICTED_COUNTER 161
                #else /* Was [152-152] */
                  #define ORIGINAL_COUNTER 152
                  #define VERIFICATION_COUNTER 161
                  #define PREDICTED_COUNTER 162
                #endif
              #endif
            #endif
          #else /* Was [153-160] */
            #if (__COUNTER__ <= (156+6)) /* Was [153-156] */
              #if (__COUNTER__ <= (154+7)) /* Was [153-154] */
                #if (__COUNTER__ <= (153+8)) /* Was [153-153] */
                  #define ORIGINAL_COUNTER 153
                  #define VERIFICATION_COUNTER 162
                  #define PREDICTED_COUNTER 163
                #else /* Was [154-154] */
                  #define ORIGINAL_COUNTER 154
                  #define VERIFICATION_COUNTER 163
                  #define PREDICTED_COUNTER 164
                #endif
              #else /* Was [155-156] */
                #if (__COUNTER__ <= (155+8)) /* Was [155-155] */
                  #define ORIGINAL_COUNTER 155
                  #define VERIFICATION_COUNTER 164
                  #define PREDICTED_COUNTER 165
                #else /* Was [156-156] */
                  #define ORIGINAL_COUNTER 156
                  #define VERIFICATION_COUNTER 165
                  #define PREDICTED_COUNTER 166
                #endif
              #endif
            #else /* Was [157-160] */
              #if (__COUNTER__ <= (158+7)) /* Was [157-158] */
                #if (__COUNTER__ <= (157+8)) /* Was [157-157] */
                  #define ORIGINAL_COUNTER 157
                  #define VERIFICATION_COUNTER 166
                  #define PREDICTED_COUNTER 167
                #else /* Was [158-158] */
                  #define ORIGINAL_COUNTER 158
                  #define VERIFICATION_COUNTER 167
                  #define PREDICTED_COUNTER 168
                #endif
              #else /* Was [159-160] */
                #if (__COUNTER__ <= (159+8)) /* Was [159-159] */
                  #define ORIGINAL_COUNTER 159
                  #define VERIFICATION_COUNTER 168
                  #define PREDICTED_COUNTER 169
                #else /* Was [160-160] */
                  #define ORIGINAL_COUNTER 160
                  #define VERIFICATION_COUNTER 169
                  #define PREDICTED_COUNTER 170
                #endif
              #endif
            #endif
          #endif
        #endif
      #else /* Was [161-192] */
        #if (__COUNTER__ <= (176+4)) /* Was [161-176] */
          #if (__COUNTER__ <= (168+5)) /* Was [161-168] */
            #if (__COUNTER__ <= (164+6)) /* Was [161-164] */
              #if (__COUNTER__ <= (162+7)) /* Was [161-162] */
                #if (__COUNTER__ <= (161+8)) /* Was [161-161] */
                  #define ORIGINAL_COUNTER 161
                  #define VERIFICATION_COUNTER 170
                  #define PREDICTED_COUNTER 171
                #else /* Was [162-162] */
                  #define ORIGINAL_COUNTER 162
                  #define VERIFICATION_COUNTER 171
                  #define PREDICTED_COUNTER 172
                #endif
              #else /* Was [163-164] */
                #if (__COUNTER__ <= (163+8)) /* Was [163-163] */
                  #define ORIGINAL_COUNTER 163
                  #define VERIFICATION_COUNTER 172
                  #define PREDICTED_COUNTER 173
                #else /* Was [164-164] */
                  #define ORIGINAL_COUNTER 164
                  #define VERIFICATION_COUNTER 173
                  #define PREDICTED_COUNTER 174
                #endif
              #endif
            #else /* Was [165-168] */
              #if (__COUNTER__ <= (166+7)) /* Was [165-166] */
                #if (__COUNTER__ <= (165+8)) /* Was [165-165] */
                  #define ORIGINAL_COUNTER 165
                  #define VERIFICATION_COUNTER 174
                  #define PREDICTED_COUNTER 175
                #else /* Was [166-166] */
                  #define ORIGINAL_COUNTER 166
                  #define VERIFICATION_COUNTER 175
                  #define PREDICTED_COUNTER 176
                #endif
              #else /* Was [167-168] */
                #if (__COUNTER__ <= (167+8)) /* Was [167-167] */
                  #define ORIGINAL_COUNTER 167
                  #define VERIFICATION_COUNTER 176
                  #define PREDICTED_COUNTER 177
                #else /* Was [168-168] */
                  #define ORIGINAL_COUNTER 168
                  #define VERIFICATION_COUNTER 177
                  #define PREDICTED_COUNTER 178
                #endif
              #endif
            #endif
          #else /* Was [169-176] */
            #if (__COUNTER__ <= (172+6)) /* Was [169-172] */
              #if (__COUNTER__ <= (170+7)) /* Was [169-170] */
                #if (__COUNTER__ <= (169+8)) /* Was [169-169] */
                  #define ORIGINAL_COUNTER 169
                  #define VERIFICATION_COUNTER 178
                  #define PREDICTED_COUNTER 179
                #else /* Was [170-170] */
                  #define ORIGINAL_COUNTER 170
                  #define VERIFICATION_COUNTER 179
                  #define PREDICTED_COUNTER 180
                #endif
              #else /* Was [171-172] */
                #if (__COUNTER__ <= (171+8)) /* Was [171-171] */
                  #define ORIGINAL_COUNTER 171
                  #define VERIFICATION_COUNTER 180
                  #define PREDICTED_COUNTER 181
                #else /* Was [172-172] */
                  #define ORIGINAL_COUNTER 172
                  #define VERIFICATION_COUNTER 181
                  #define PREDICTED_COUNTER 182
                #endif
              #endif
            #else /* Was [173-176] */
              #if (__COUNTER__ <= (174+7)) /* Was [173-174] */
                #if (__COUNTER__ <= (173+8)) /* Was [173-173] */
                  #define ORIGINAL_COUNTER 173
                  #define VERIFICATION_COUNTER 182
                  #define PREDICTED_COUNTER 183
                #else /* Was [174-174] */
                  #define ORIGINAL_COUNTER 174
                  #define VERIFICATION_COUNTER 183
                  #define PREDICTED_COUNTER 184
                #endif
              #else /* Was [175-176] */
                #if (__COUNTER__ <= (175+8)) /* Was [175-175] */
                  #define ORIGINAL_COUNTER 175
                  #define VERIFICATION_COUNTER 184
                  #define PREDICTED_COUNTER 185
                #else /* Was [176-176] */
                  #define ORIGINAL_COUNTER 176
                  #define VERIFICATION_COUNTER 185
                  #define PREDICTED_COUNTER 186
                #endif
              #endif
            #endif
          #endif
        #else /* Was [177-192] */
          #if (__COUNTER__ <= (184+5)) /* Was [177-184] */
            #if (__COUNTER__ <= (180+6)) /* Was [177-180] */
              #if (__COUNTER__ <= (178+7)) /* Was [177-178] */
                #if (__COUNTER__ <= (177+8)) /* Was [177-177] */
                  #define ORIGINAL_COUNTER 177
                  #define VERIFICATION_COUNTER 186
                  #define PREDICTED_COUNTER 187
                #else /* Was [178-178] */
                  #define ORIGINAL_COUNTER 178
                  #define VERIFICATION_COUNTER 187
                  #define PREDICTED_COUNTER 188
                #endif
              #else /* Was [179-180] */
                #if (__COUNTER__ <= (179+8)) /* Was [179-179] */
                  #define ORIGINAL_COUNTER 179
                  #define VERIFICATION_COUNTER 188
                  #define PREDICTED_COUNTER 189
                #else /* Was [180-180] */
                  #define ORIGINAL_COUNTER 180
                  #define VERIFICATION_COUNTER 189
                  #define PREDICTED_COUNTER 190
                #endif
              #endif
            #else /* Was [181-184] */
              #if (__COUNTER__ <= (182+7)) /* Was [181-182] */
                #if (__COUNTER__ <= (181+8)) /* Was [181-181] */
                  #define ORIGINAL_COUNTER 181
                  #define VERIFICATION_COUNTER 190
                  #define PREDICTED_COUNTER 191
                #else /* Was [182-182] */
                  #define ORIGINAL_COUNTER 182
                  #define VERIFICATION_COUNTER 191
                  #define PREDICTED_COUNTER 192
                #endif
              #else /* Was [183-184] */
                #if (__COUNTER__ <= (183+8)) /* Was [183-183] */
                  #define ORIGINAL_COUNTER 183
                  #define VERIFICATION_COUNTER 192
                  #define PREDICTED_COUNTER 193
                #else /* Was [184-184] */
                  #define ORIGINAL_COUNTER 184
                  #define VERIFICATION_COUNTER 193
                  #define PREDICTED_COUNTER 194
                #endif
              #endif
            #endif
          #else /* Was [185-192] */
            #if (__COUNTER__ <= (188+6)) /* Was [185-188] */
              #if (__COUNTER__ <= (186+7)) /* Was [185-186] */
                #if (__COUNTER__ <= (185+8)) /* Was [185-185] */
                  #define ORIGINAL_COUNTER 185
                  #define VERIFICATION_COUNTER 194
                  #define PREDICTED_COUNTER 195
                #else /* Was [186-186] */
                  #define ORIGINAL_COUNTER 186
                  #define VERIFICATION_COUNTER 195
                  #define PREDICTED_COUNTER 196
                #endif
              #else /* Was [187-188] */
                #if (__COUNTER__ <= (187+8)) /* Was [187-187] */
                  #define ORIGINAL_COUNTER 187
                  #define VERIFICATION_COUNTER 196
                  #define PREDICTED_COUNTER 197
                #else /* Was [188-188] */
                  #define ORIGINAL_COUNTER 188
                  #define VERIFICATION_COUNTER 197
                  #define PREDICTED_COUNTER 198
                #endif
              #endif
            #else /* Was [189-192] */
              #if (__COUNTER__ <= (190+7)) /* Was [189-190] */
                #if (__COUNTER__ <= (189+8)) /* Was [189-189] */
                  #define ORIGINAL_COUNTER 189
                  #define VERIFICATION_COUNTER 198
                  #define PREDICTED_COUNTER 199
                #else /* Was [190-190] */
                  #define ORIGINAL_COUNTER 190
                  #define VERIFICATION_COUNTER 199
                  #define PREDICTED_COUNTER 200
                #endif
              #else /* Was [191-192] */
                #if (__COUNTER__ <= (191+8)) /* Was [191-191] */
                  #define ORIGINAL_COUNTER 191
                  #define VERIFICATION_COUNTER 200
                  #define PREDICTED_COUNTER 201
                #else /* Was [192-192] */
                  #define ORIGINAL_COUNTER 192
                  #define VERIFICATION_COUNTER 201
                  #define PREDICTED_COUNTER 202
                #endif
              #endif
            #endif
          #endif
        #endif
      #endif
    #else /* Was [193-256] */
      #if (__COUNTER__ <= (224+3)) /* Was [193-224] */
        #if (__COUNTER__ <= (208+4)) /* Was [193-208] */
          #if (__COUNTER__ <= (200+5)) /* Was [193-200] */
            #if (__COUNTER__ <= (196+6)) /* Was [193-196] */
              #if (__COUNTER__ <= (194+7)) /* Was [193-194] */
                #if (__COUNTER__ <= (193+8)) /* Was [193-193] */
                  #define ORIGINAL_COUNTER 193
                  #define VERIFICATION_COUNTER 202
                  #define PREDICTED_COUNTER 203
                #else /* Was [194-194] */
                  #define ORIGINAL_COUNTER 194
                  #define VERIFICATION_COUNTER 203
                  #define PREDICTED_COUNTER 204
                #endif
              #else /* Was [195-196] */
                #if (__COUNTER__ <= (195+8)) /* Was [195-195] */
                  #define ORIGINAL_COUNTER 195
                  #define VERIFICATION_COUNTER 204
                  #define PREDICTED_COUNTER 205
                #else /* Was [196-196] */
                  #define ORIGINAL_COUNTER 196
                  #define VERIFICATION_COUNTER 205
                  #define PREDICTED_COUNTER 206
                #endif
              #endif
            #else /* Was [197-200] */
              #if (__COUNTER__ <= (198+7)) /* Was [197-198] */
                #if (__COUNTER__ <= (197+8)) /* Was [197-197] */
                  #define ORIGINAL_COUNTER 197
                  #define VERIFICATION_COUNTER 206
                  #define PREDICTED_COUNTER 207
                #else /* Was [198-198] */
                  #define ORIGINAL_COUNTER 198
                  #define VERIFICATION_COUNTER 207
                  #define PREDICTED_COUNTER 208
                #endif
              #else /* Was [199-200] */
                #if (__COUNTER__ <= (199+8)) /* Was [199-199] */
                  #define ORIGINAL_COUNTER 199
                  #define VERIFICATION_COUNTER 208
                  #define PREDICTED_COUNTER 209
                #else /* Was [200-200] */
                  #define ORIGINAL_COUNTER 200
                  #define VERIFICATION_COUNTER 209
                  #define PREDICTED_COUNTER 210
                #endif
              #endif
            #endif
          #else /* Was [201-208] */
            #if (__COUNTER__ <= (204+6)) /* Was [201-204] */
              #if (__COUNTER__ <= (202+7)) /* Was [201-202] */
                #if (__COUNTER__ <= (201+8)) /* Was [201-201] */
                  #define ORIGINAL_COUNTER 201
                  #define VERIFICATION_COUNTER 210
                  #define PREDICTED_COUNTER 211
                #else /* Was [202-202] */
                  #define ORIGINAL_COUNTER 202
                  #define VERIFICATION_COUNTER 211
                  #define PREDICTED_COUNTER 212
                #endif
              #else /* Was [203-204] */
                #if (__COUNTER__ <= (203+8)) /* Was [203-203] */
                  #define ORIGINAL_COUNTER 203
                  #define VERIFICATION_COUNTER 212
                  #define PREDICTED_COUNTER 213
                #else /* Was [204-204] */
                  #define ORIGINAL_COUNTER 204
                  #define VERIFICATION_COUNTER 213
                  #define PREDICTED_COUNTER 214
                #endif
              #endif
            #else /* Was [205-208] */
              #if (__COUNTER__ <= (206+7)) /* Was [205-206] */
                #if (__COUNTER__ <= (205+8)) /* Was [205-205] */
                  #define ORIGINAL_COUNTER 205
                  #define VERIFICATION_COUNTER 214
                  #define PREDICTED_COUNTER 215
                #else /* Was [206-206] */
                  #define ORIGINAL_COUNTER 206
                  #define VERIFICATION_COUNTER 215
                  #define PREDICTED_COUNTER 216
                #endif
              #else /* Was [207-208] */
                #if (__COUNTER__ <= (207+8)) /* Was [207-207] */
                  #define ORIGINAL_COUNTER 207
                  #define VERIFICATION_COUNTER 216
                  #define PREDICTED_COUNTER 217
                #else /* Was [208-208] */
                  #define ORIGINAL_COUNTER 208
                  #define VERIFICATION_COUNTER 217
                  #define PREDICTED_COUNTER 218
                #endif
              #endif
            #endif
          #endif
        #else /* Was [209-224] */
          #if (__COUNTER__ <= (216+5)) /* Was [209-216] */
            #if (__COUNTER__ <= (212+6)) /* Was [209-212] */
              #if (__COUNTER__ <= (210+7)) /* Was [209-210] */
                #if (__COUNTER__ <= (209+8)) /* Was [209-209] */
                  #define ORIGINAL_COUNTER 209
                  #define VERIFICATION_COUNTER 218
                  #define PREDICTED_COUNTER 219
                #else /* Was [210-210] */
                  #define ORIGINAL_COUNTER 210
                  #define VERIFICATION_COUNTER 219
                  #define PREDICTED_COUNTER 220
                #endif
              #else /* Was [211-212] */
                #if (__COUNTER__ <= (211+8)) /* Was [211-211] */
                  #define ORIGINAL_COUNTER 211
                  #define VERIFICATION_COUNTER 220
                  #define PREDICTED_COUNTER 221
                #else /* Was [212-212] */
                  #define ORIGINAL_COUNTER 212
                  #define VERIFICATION_COUNTER 221
                  #define PREDICTED_COUNTER 222
                #endif
              #endif
            #else /* Was [213-216] */
              #if (__COUNTER__ <= (214+7)) /* Was [213-214] */
                #if (__COUNTER__ <= (213+8)) /* Was [213-213] */
                  #define ORIGINAL_COUNTER 213
                  #define VERIFICATION_COUNTER 222
                  #define PREDICTED_COUNTER 223
                #else /* Was [214-214] */
                  #define ORIGINAL_COUNTER 214
                  #define VERIFICATION_COUNTER 223
                  #define PREDICTED_COUNTER 224
                #endif
              #else /* Was [215-216] */
                #if (__COUNTER__ <= (215+8)) /* Was [215-215] */
                  #define ORIGINAL_COUNTER 215
                  #define VERIFICATION_COUNTER 224
                  #define PREDICTED_COUNTER 225
                #else /* Was [216-216] */
                  #define ORIGINAL_COUNTER 216
                  #define VERIFICATION_COUNTER 225
                  #define PREDICTED_COUNTER 226
                #endif
              #endif
            #endif
          #else /* Was [217-224] */
            #if (__COUNTER__ <= (220+6)) /* Was [217-220] */
              #if (__COUNTER__ <= (218+7)) /* Was [217-218] */
                #if (__COUNTER__ <= (217+8)) /* Was [217-217] */
                  #define ORIGINAL_COUNTER 217
                  #define VERIFICATION_COUNTER 226
                  #define PREDICTED_COUNTER 227
                #else /* Was [218-218] */
                  #define ORIGINAL_COUNTER 218
                  #define VERIFICATION_COUNTER 227
                  #define PREDICTED_COUNTER 228
                #endif
              #else /* Was [219-220] */
                #if (__COUNTER__ <= (219+8)) /* Was [219-219] */
                  #define ORIGINAL_COUNTER 219
                  #define VERIFICATION_COUNTER 228
                  #define PREDICTED_COUNTER 229
                #else /* Was [220-220] */
                  #define ORIGINAL_COUNTER 220
                  #define VERIFICATION_COUNTER 229
                  #define PREDICTED_COUNTER 230
                #endif
              #endif
            #else /* Was [221-224] */
              #if (__COUNTER__ <= (222+7)) /* Was [221-222] */
                #if (__COUNTER__ <= (221+8)) /* Was [221-221] */
                  #define ORIGINAL_COUNTER 221
                  #define VERIFICATION_COUNTER 230
                  #define PREDICTED_COUNTER 231
                #else /* Was [222-222] */
                  #define ORIGINAL_COUNTER 222
                  #define VERIFICATION_COUNTER 231
                  #define PREDICTED_COUNTER 232
                #endif
              #else /* Was [223-224] */
                #if (__COUNTER__ <= (223+8)) /* Was [223-223] */
                  #define ORIGINAL_COUNTER 223
                  #define VERIFICATION_COUNTER 232
                  #define PREDICTED_COUNTER 233
                #else /* Was [224-224] */
                  #define ORIGINAL_COUNTER 224
                  #define VERIFICATION_COUNTER 233
                  #define PREDICTED_COUNTER 234
                #endif
              #endif
            #endif
          #endif
        #endif
      #else /* Was [225-256] */
        #if (__COUNTER__ <= (240+4)) /* Was [225-240] */
          #if (__COUNTER__ <= (232+5)) /* Was [225-232] */
            #if (__COUNTER__ <= (228+6)) /* Was [225-228] */
              #if (__COUNTER__ <= (226+7)) /* Was [225-226] */
                #if (__COUNTER__ <= (225+8)) /* Was [225-225] */
                  #define ORIGINAL_COUNTER 225
                  #define VERIFICATION_COUNTER 234
                  #define PREDICTED_COUNTER 235
                #else /* Was [226-226] */
                  #define ORIGINAL_COUNTER 226
                  #define VERIFICATION_COUNTER 235
                  #define PREDICTED_COUNTER 236
                #endif
              #else /* Was [227-228] */
                #if (__COUNTER__ <= (227+8)) /* Was [227-227] */
                  #define ORIGINAL_COUNTER 227
                  #define VERIFICATION_COUNTER 236
                  #define PREDICTED_COUNTER 237
                #else /* Was [228-228] */
                  #define ORIGINAL_COUNTER 228
                  #define VERIFICATION_COUNTER 237
                  #define PREDICTED_COUNTER 238
                #endif
              #endif
            #else /* Was [229-232] */
              #if (__COUNTER__ <= (230+7)) /* Was [229-230] */
                #if (__COUNTER__ <= (229+8)) /* Was [229-229] */
                  #define ORIGINAL_COUNTER 229
                  #define VERIFICATION_COUNTER 238
                  #define PREDICTED_COUNTER 239
                #else /* Was [230-230] */
                  #define ORIGINAL_COUNTER 230
                  #define VERIFICATION_COUNTER 239
                  #define PREDICTED_COUNTER 240
                #endif
              #else /* Was [231-232] */
                #if (__COUNTER__ <= (231+8)) /* Was [231-231] */
                  #define ORIGINAL_COUNTER 231
                  #define VERIFICATION_COUNTER 240
                  #define PREDICTED_COUNTER 241
                #else /* Was [232-232] */
                  #define ORIGINAL_COUNTER 232
                  #define VERIFICATION_COUNTER 241
                  #define PREDICTED_COUNTER 242
                #endif
              #endif
            #endif
          #else /* Was [233-240] */
            #if (__COUNTER__ <= (236+6)) /* Was [233-236] */
              #if (__COUNTER__ <= (234+7)) /* Was [233-234] */
                #if (__COUNTER__ <= (233+8)) /* Was [233-233] */
                  #define ORIGINAL_COUNTER 233
                  #define VERIFICATION_COUNTER 242
                  #define PREDICTED_COUNTER 243
                #else /* Was [234-234] */
                  #define ORIGINAL_COUNTER 234
                  #define VERIFICATION_COUNTER 243
                  #define PREDICTED_COUNTER 244
                #endif
              #else /* Was [235-236] */
                #if (__COUNTER__ <= (235+8)) /* Was [235-235] */
                  #define ORIGINAL_COUNTER 235
                  #define VERIFICATION_COUNTER 244
                  #define PREDICTED_COUNTER 245
                #else /* Was [236-236] */
                  #define ORIGINAL_COUNTER 236
                  #define VERIFICATION_COUNTER 245
                  #define PREDICTED_COUNTER 246
                #endif
              #endif
            #else /* Was [237-240] */
              #if (__COUNTER__ <= (238+7)) /* Was [237-238] */
                #if (__COUNTER__ <= (237+8)) /* Was [237-237] */
                  #define ORIGINAL_COUNTER 237
                  #define VERIFICATION_COUNTER 246
                  #define PREDICTED_COUNTER 247
                #else /* Was [238-238] */
                  #define ORIGINAL_COUNTER 238
                  #define VERIFICATION_COUNTER 247
                  #define PREDICTED_COUNTER 248
                #endif
              #else /* Was [239-240] */
                #if (__COUNTER__ <= (239+8)) /* Was [239-239] */
                  #define ORIGINAL_COUNTER 239
                  #define VERIFICATION_COUNTER 248
                  #define PREDICTED_COUNTER 249
                #else /* Was [240-240] */
                  #define ORIGINAL_COUNTER 240
                  #define VERIFICATION_COUNTER 249
                  #define PREDICTED_COUNTER 250
                #endif
              #endif
            #endif
          #endif
        #else /* Was [241-256] */
          #if (__COUNTER__ <= (248+5)) /* Was [241-248] */
            #if (__COUNTER__ <= (244+6)) /* Was [241-244] */
              #if (__COUNTER__ <= (242+7)) /* Was [241-242] */
                #if (__COUNTER__ <= (241+8)) /* Was [241-241] */
                  #define ORIGINAL_COUNTER 241
                  #define VERIFICATION_COUNTER 250
                  #define PREDICTED_COUNTER 251
                #else /* Was [242-242] */
                  #define ORIGINAL_COUNTER 242
                  #define VERIFICATION_COUNTER 251
                  #define PREDICTED_COUNTER 252
                #endif
              #else /* Was [243-244] */
                #if (__COUNTER__ <= (243+8)) /* Was [243-243] */
                  #define ORIGINAL_COUNTER 243
                  #define VERIFICATION_COUNTER 252
                  #define PREDICTED_COUNTER 253
                #else /* Was [244-244] */
                  #define ORIGINAL_COUNTER 244
                  #define VERIFICATION_COUNTER 253
                  #define PREDICTED_COUNTER 254
                #endif
              #endif
            #else /* Was [245-248] */
              #if (__COUNTER__ <= (246+7)) /* Was [245-246] */
                #if (__COUNTER__ <= (245+8)) /* Was [245-245] */
                  #define ORIGINAL_COUNTER 245
                  #define VERIFICATION_COUNTER 254
                  #define PREDICTED_COUNTER 255
                #else /* Was [246-246] */
                  #define ORIGINAL_COUNTER 246
                  #define VERIFICATION_COUNTER 255
                  #define PREDICTED_COUNTER 256
                #endif
              #else /* Was [247-248] */
                #if (__COUNTER__ <= (247+8)) /* Was [247-247] */
                  #define ORIGINAL_COUNTER 247
                  #define VERIFICATION_COUNTER 256
                  #define PREDICTED_COUNTER 257
                #else /* Was [248-248] */
                  #define ORIGINAL_COUNTER 248
                  #define VERIFICATION_COUNTER 257
                  #define PREDICTED_COUNTER 258
                #endif
              #endif
            #endif
          #else /* Was [249-256] */
            #if (__COUNTER__ <= (252+6)) /* Was [249-252] */
              #if (__COUNTER__ <= (250+7)) /* Was [249-250] */
                #if (__COUNTER__ <= (249+8)) /* Was [249-249] */
                  #define ORIGINAL_COUNTER 249
                  #define VERIFICATION_COUNTER 258
                  #define PREDICTED_COUNTER 259
                #else /* Was [250-250] */
                  #define ORIGINAL_COUNTER 250
                  #define VERIFICATION_COUNTER 259
                  #define PREDICTED_COUNTER 260
                #endif
              #else /* Was [251-252] */
                #if (__COUNTER__ <= (251+8)) /* Was [251-251] */
                  #define ORIGINAL_COUNTER 251
                  #define VERIFICATION_COUNTER 260
                  #define PREDICTED_COUNTER 261
                #else /* Was [252-252] */
                  #define ORIGINAL_COUNTER 252
                  #define VERIFICATION_COUNTER 261
                  #define PREDICTED_COUNTER 262
                #endif
              #endif
            #else /* Was [253-256] */
              #if (__COUNTER__ <= (254+7)) /* Was [253-254] */
                #if (__COUNTER__ <= (253+8)) /* Was [253-253] */
                  #define ORIGINAL_COUNTER 253
                  #define VERIFICATION_COUNTER 262
                  #define PREDICTED_COUNTER 263
                #else /* Was [254-254] */
                  #define ORIGINAL_COUNTER 254
                  #define VERIFICATION_COUNTER 263
                  #define PREDICTED_COUNTER 264
                #endif
              #else /* Was [255-256] */
                #if (__COUNTER__ <= (255+8)) /* Was [255-255] */
                  #define ORIGINAL_COUNTER 255
                  #define VERIFICATION_COUNTER 264
                  #define PREDICTED_COUNTER 265
                #else /* Was [256-256] */
                  #define ORIGINAL_COUNTER 256
                  #define VERIFICATION_COUNTER 265
                  #define PREDICTED_COUNTER 266
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
#if (PREDICTED_COUNTER >= 256)
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
#endif /* EVILUNIT_EQUIVALENT_INCLUDE_MANGLE_TESTS_HERE */

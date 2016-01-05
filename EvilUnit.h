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
/*
 * Copyright 2015 Jon Chesterfield. All rights reserved.
 */
#ifndef EVILUNIT_TEST_FRAMEWORK_HEADER
#define EVILUNIT_TEST_FRAMEWORK_HEADER

#if 0
/*
 * The user facing macros can be easily redefined here, e.g. #define SUITE(X) EVILUNIT_MODULE(X)
 */
#endif
#define CHECK(X) EVILUNIT_CHECK(X)
#define TEST(X) EVILUNIT_TEST(X)
#define DEPENDS(X) EVILUNIT_DEPENDS(X)
#define MODULE(X) EVILUNIT_MODULE(X)
#define MAIN_MODULE() EVILUNIT_MAIN_MODULE()

#if 0
/*
 * Implementation follows
 */
#endif

#if 0
/* This kind of sucks. Perhaps an enum would still be better. */
/* Execute all tests is keyed to 1 as that's the default for argc */
#endif
#define evilunit_traverse_command_execute_all_tests (1)
#define evilunit_traverse_command_get_number_of_tests (0)
#define evilunit_traverse_command_get_number_of_dependencies (2)
#define evilunit_traverse_command_get_test_name_from_number (3)
#define evilunit_traverse_command_get_dependency_from_number (4)
#define evilunit_traverse_command_run_specific_test (5)
#define evilunit_traverse_command_get_module_name (6)
#define evilunit_traverse_command_get_module_filename (7)
#define evilunit_traverse_command_store_result (8)
#define evilunit_traverse_command_retrieve_result (9)
#define evilunit_traverse_command_mark_colour_white (10)
#define evilunit_traverse_command_mark_colour_grey (11)
#define evilunit_traverse_command_is_colour_white (12)
#define evilunit_traverse_command_is_colour_grey (13)

#if 0
/* External functions, implemented in evilunit.c */
#endif
#define EVILUNIT_EXTERNAL_FUNCTIONS                                     \
  struct evilunit_test_state;                                           \
  struct evilunit_module_state;                                         \
  void evilunit_implementation_manage_test_state(struct evilunit_module_state * module, void * test, int direction); \
  int evilunit_implementation_test(struct evilunit_module_state * state, const char *blockname); \
  void evilunit_implementation_depends(struct evilunit_module_state * state, int (*proposed)(int instruction, char** state)); \
  void evilunit_implementation_check(struct evilunit_module_state * S, int check_resolved_to_this, int line, const char * check_string); \
  void evilunit_implementation_set_string_parameter(struct evilunit_module_state * S, const char * str); \
  void evilunit_implementation_set_numeric_parameter(struct evilunit_module_state * S, unsigned int num);\
int evilunit_implementation(int (*root) (int, char **));

#ifdef _cplusplus
#define EVILUNIT_EXTERNAL extern "C" { EVILUNIT_EXTERNAL_FUNCTIONS }
#else
#define EVILUNIT_EXTERNAL EVILUNIT_EXTERNAL_FUNCTIONS
#endif

#define EVILUNIT_CONCAT(a__, b__) EVILUNIT_CONCAT_DO(a__, b__)
#define EVILUNIT_CONCAT_DO(a__, b__) a__##b__
#define EVILUNIT_MODULE_MANGLE(MODNAME) EVILUNIT_CONCAT(evilunit_node_,MODNAME)
#define EVILUNIT_MODULE_DECLARE(MODNAME) int EVILUNIT_MODULE_MANGLE(MODNAME)(int instruction, char ** vstate)
#ifdef __cplusplus
#define EVILUNIT_CAST(TYPE,VARIABLE) reinterpret_cast<TYPE>(VARIABLE)
#else
#define EVILUNIT_CAST(TYPE,VARIABLE) (TYPE) (VARIABLE)
#endif

#if 0
/*
 * The primary macros - these rewrite the user's code.
 */
#endif

#define EVILUNIT_CHECK(X) evilunit_implementation_check(evilunit_internal_state,(X),__LINE__,#X);

#define EVILUNIT_TEST(blockname) if (evilunit_implementation_test(evilunit_internal_state,blockname))

#define EVILUNIT_DEPENDS(X)                                             \
  {EVILUNIT_MODULE_DECLARE(X);                                          \
    evilunit_implementation_depends(evilunit_internal_state, &(EVILUNIT_MODULE_MANGLE(X)));}
#if 0
/*
 * MODULE expands to a function containing a union used to avoid exposing
 * the implementation of struct evilunit_test_state to the user code.
 * The obvious pointer to use is one to the char array, data. This however
 * triggers warnings about the different alignment requirements (e.g. 1 vs 8)
 * Since the union is providing a block of appropriately aligned storage,
 * and is never initialised or read through any of its members, we may as
 * well cast a pointer to the union itself.
 */
#endif

#define EVILUNIT_MODULE(MODNAME)                                        \
  EVILUNIT_MODULE_DECLARE(MODNAME);                                     \
  EVILUNIT_EXTERNAL                                                     \
  static void EVILUNIT_CONCAT(module_,MODNAME)                          \
       (struct evilunit_module_state * evilunit_internal_state);        \
       EVILUNIT_MODULE_DECLARE(MODNAME)                                 \
  {                                                                     \
    struct evilunit_module_state * state =                              \
      EVILUNIT_CAST(struct evilunit_module_state *,vstate);             \
    static union                                                        \
    {                                                                   \
      char data[4*sizeof(int) + 3*sizeof(const char *)];                \
      int align0;                                                       \
      unsigned int align1;                                              \
      const char * align3;                                              \
    } stored_test_state_storage;                                        \
    void * stored_test_state = &stored_test_state_storage;              \
    static int stored_node_colour;                                      \
    const unsigned int white_colour = 0;                                \
    const unsigned int grey_colour = 1;                                 \
    switch(instruction)                                                 \
      {                                                                 \
      case evilunit_traverse_command_execute_all_tests:                 \
        {                                                               \
          return evilunit_implementation(EVILUNIT_MODULE_MANGLE(MODNAME));\
        }                                                               \
      case evilunit_traverse_command_get_number_of_tests:               \
      case evilunit_traverse_command_get_number_of_dependencies:        \
      case evilunit_traverse_command_get_dependency_from_number:        \
      case evilunit_traverse_command_get_test_name_from_number:         \
      case evilunit_traverse_command_run_specific_test:                 \
        {                                                               \
          EVILUNIT_CONCAT(module_,MODNAME)(state);                      \
          break;                                                        \
        }                                                               \
      case evilunit_traverse_command_get_module_name:                   \
        {                                                               \
          evilunit_implementation_set_string_parameter(state,#MODNAME); \
          break;                                                        \
        }                                                               \
      case evilunit_traverse_command_get_module_filename:               \
        {                                                               \
          evilunit_implementation_set_string_parameter(state,__FILE__); \
          break;                                                        \
        }                                                               \
      case evilunit_traverse_command_store_result:                      \
        {                                                               \
          evilunit_implementation_manage_test_state(state,stored_test_state,0); \
          break;                                                        \
        }                                                               \
      case evilunit_traverse_command_retrieve_result:                   \
        {                                                               \
          evilunit_implementation_manage_test_state(state,stored_test_state,1); \
          break;                                                        \
        }                                                               \
      case evilunit_traverse_command_mark_colour_white:                 \
        {                                                               \
          stored_node_colour = white_colour;                            \
          break;                                                        \
        }                                                               \
      case evilunit_traverse_command_mark_colour_grey:                  \
        {                                                               \
          stored_node_colour = grey_colour;                             \
          break;                                                        \
        }                                                               \
      case evilunit_traverse_command_is_colour_white:                   \
        {                                                               \
          evilunit_implementation_set_numeric_parameter                 \
            (state,(stored_node_colour == white_colour) ? 1 : 0);       \
          break;                                                        \
        }                                                               \
      case evilunit_traverse_command_is_colour_grey:                    \
        {                                                               \
          evilunit_implementation_set_numeric_parameter                 \
            (state,(stored_node_colour == grey_colour) ? 1 : 0);        \
          break;                                                        \
        }                                                               \
      }                                                                 \
    return 0;                                                           \
  }                                                                     \
       void EVILUNIT_CONCAT(module_,MODNAME)(struct evilunit_module_state * evilunit_internal_state)


#ifdef _cplusplus
#define EVILUNIT_MAIN_MODULE()                                  \
  extern "C" {                                                  \
    EVILUNIT_MODULE_DECLARE(main_module);                       \
  }                                                             \
  int main(void)                                                \
  {                                                             \
    return EVILUNIT_MODULE_MANGLE(main_module)(1,0);            \
  } MODULE(main_module)
#else
#define EVILUNIT_MAIN_MODULE()                                  \
  EVILUNIT_MODULE_DECLARE(main_module);                         \
  int main(void)                                                \
  {                                                             \
    return EVILUNIT_MODULE_MANGLE(main_module)(1,0);            \
  } MODULE(main_module)
#endif








#endif /* EVILUNIT_TEST_FRAMEWORK_HEADER */

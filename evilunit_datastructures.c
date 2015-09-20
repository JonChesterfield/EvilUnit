#if 0
/*
struct evilunit_check
{
  const char * string;
  int result;
};
struct evilunit_test
{
  const char * string;
  struct vector_evilunit_check checks;
  int result;
};
struct evilunit_module
{
  const char * string;
  struct evilunit_test;
  struct vector_evilunit_test tests;
  int result;
};
*/
#endif

/* Fast string is currently hacked together in the included file */
#define FAST_STRING_SCOPE static
#include "fast_string.c"
#undef FAST_STRING_SCOPE

/* Set up required primitives */
#include "cstl.kill"
#include "primitive_types.spec"

#include "require_primitive_int_init_stack.h"
#include "require_primitive_int_ctor_stack.h"
#include "require_primitive_int_dtor_stack.h"
#include "require_primitive_int_copy.h"

#include "require_primitive_size_t_init_stack.h"
#include "require_primitive_size_t_ctor_stack.h"
#include "require_primitive_size_t_dtor_stack.h"
#include "require_primitive_size_t_copy.h"

#include "primitive_types.c"
#include "primitive_types.kill"


/* Set up evilunit_check structure */
#include "cstl.kill"

#define CONTENT_TYPENAME evilunit_check
#define CONTENT_TYPEDECL struct CONTENT_TYPENAME

#define STRUCT_DEFINITION                       \
  N(CONTENT_TYPENAME)                           \
  S(struct fast_string, fast_string, string)	\
  S(int, int, result)



#include "struct.spec"
/* Slight abstraction leak here */
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_functions_copy.h"
#include "require_functions_equal.h"

#include "struct.c"
#include "struct.kill"

#include "array.spec"
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_functions_copy.h"
#include "require_functions_equal.h"
#include "require_array_resize_atleast.h"
#include "array.c"
#include "array.kill"

#include "vector.spec"
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_functions_equal.h"
#include "require_vector_push_back.h"
#include "require_vector_contains.h"

#include "vector.c"
#include "vector.kill"


/* Set up evilunit_test structure */
#include "cstl.kill"

#define CONTENT_TYPENAME evilunit_test
#define CONTENT_TYPEDECL struct CONTENT_TYPENAME

#define STRUCT_DEFINITION						\
  N(CONTENT_TYPENAME)							\
  S(struct fast_string, fast_string, string)				\
  S(struct vector_evilunit_check, vector_evilunit_check, checks)	\
  S(int, int, result)

#include "struct.spec"
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_functions_copy.h"
#include "require_functions_equal.h"

#include "struct.c"
#include "struct.kill"

#include "array.spec"
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_functions_copy.h"
#include "require_functions_equal.h"
#include "require_array_resize_atleast.h"
#include "array.c"
#include "array.kill"

#include "vector.spec"
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_functions_equal.h"
#include "require_vector_push_back.h"
#include "require_vector_contains.h"
#include "vector.c"
#include "vector.kill"

/* Set up evilunit_module structure */
#include "cstl.kill"

#define CONTENT_TYPENAME evilunit_module
#define CONTENT_TYPEDECL struct CONTENT_TYPENAME

#define STRUCT_DEFINITION						\
  N(CONTENT_TYPENAME)							\
  S(struct fast_string, fast_string, string)				\
  S(struct vector_evilunit_test, vector_evilunit_test, tests)	\
  S(int, int, result)


#include "struct.spec"
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_functions_copy.h"
#include "require_functions_equal.h"

#include "struct.c"
#include "struct.kill"

#include "array.spec"
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_functions_copy.h"
#include "require_array_resize_atleast.h"
#include "array.c"
#include "array.kill"

#include "vector.spec"
#include "require_memory_init_stack.h"
#include "require_memory_ctor_stack.h"
#include "require_memory_dtor_stack.h"
#include "require_vector_push_back.h"
#include "require_vector_contains.h"

#include "vector.c"
#include "vector.kill"

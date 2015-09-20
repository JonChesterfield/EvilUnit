#include "EvilUnit.h"

static MODULE(single_node)
{
  CHECK(1);
}

static MODULE(node_colouring)
{
  evilunit_node_type target = EVILUNIT_MODULE_MANGLE(single_node);

  CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(single_node)));

  TEST("single node starts off white and remains white when tested for colour")
    {
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(single_node)));
      CHECK(!evilunit_query_is_grey(EVILUNIT_MODULE_MANGLE(single_node)));
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(single_node)));
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(single_node)));
    }

  TEST("can mark node grey")
    {
      evilunit_execute_mark_grey(target);
      CHECK(evilunit_query_is_grey(target));
    }

  TEST("can mark node white")
    {
      evilunit_execute_mark_grey(target);
      CHECK(evilunit_query_is_grey(target));
      evilunit_execute_mark_white(target);
      CHECK(evilunit_query_is_white(target));
    }

  evilunit_execute_mark_white(target);
}

static EVILUNIT_MODULE_DECLARE(level_1a_leaf);
static EVILUNIT_MODULE_DECLARE(level_1b_leaf);
static EVILUNIT_MODULE_DECLARE(level_1c_node);
static EVILUNIT_MODULE_DECLARE(level_2a_leaf);
static EVILUNIT_MODULE_DECLARE(level_2b_leaf);
static MODULE(simple_tree)
{
  DEPENDS(level_1a_leaf);
  DEPENDS(level_1b_leaf);
  DEPENDS(level_1c_node);
}
static MODULE(level_1a_leaf)
{
  CHECK(1);
}
static MODULE(level_1b_leaf)
{
  CHECK(1);
}
static MODULE(level_1c_node)
{
  DEPENDS(level_2a_leaf);
  DEPENDS(level_2b_leaf);
}
static MODULE(level_2a_leaf)
{
  CHECK(1);
}
static MODULE(level_2b_leaf)
{
  CHECK(1);
}

static MODULE(tree_colouring)
{
  /* Tree starts out white */
  CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(simple_tree)));
  CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_1a_leaf)));
  CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_1b_leaf)));
  CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_1c_node)));
  CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_2a_leaf)));
  CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_2b_leaf)));

  TEST("walking the tree from the root leaves every node white")
    {
      evilunit_nop_traverse(EVILUNIT_MODULE_MANGLE(simple_tree));
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(simple_tree)));
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_1a_leaf)));
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_1b_leaf)));
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_1c_node)));
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_2a_leaf)));
      CHECK(evilunit_query_is_white(EVILUNIT_MODULE_MANGLE(level_2b_leaf)));
    }
  
  evilunit_execute_mark_white(EVILUNIT_MODULE_MANGLE(simple_tree));
  evilunit_execute_mark_white(EVILUNIT_MODULE_MANGLE(level_1a_leaf));
  evilunit_execute_mark_white(EVILUNIT_MODULE_MANGLE(level_1b_leaf));
  evilunit_execute_mark_white(EVILUNIT_MODULE_MANGLE(level_1c_node));
  evilunit_execute_mark_white(EVILUNIT_MODULE_MANGLE(level_2a_leaf));
  evilunit_execute_mark_white(EVILUNIT_MODULE_MANGLE(level_2b_leaf));

}

static MODULE(evilunit_selftest_graph)
{
  DEPENDS(node_colouring);
  DEPENDS(tree_colouring);
}

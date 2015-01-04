
#ifndef FW_H
# define FW_H

# include <mt.h>

#define assert_msg(cond, msg) test_assert_prep(test, #cond, msg); test_assert(test, (cond))
#define assert(cond) assert_msg(cond, NULL)
#define MT_ADD_SUITE(mt, name, suite_fn) lst_push(mt->suites, lst_create_elem(suite_create(#name, suite_fn)))
#define SUITE_ADD_TEST(suite, test_fn) lst_push(suite->tests, lst_create_elem(test_create(#test_fn, test_fn)))

#endif

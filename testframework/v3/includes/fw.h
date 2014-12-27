
#ifndef FW_H
# define FW_H

# include <mt.h>

#define assert(cond) test_assert_prep(test, #cond); test_assert(test, (cond))
#define MT_ADD_SUITE(mt, name, suite_fn) lst_push(mt->suites, suite_create(#name, suite_fn))
#define SUITE_ADD_TEST(suite, test_fn) lst_push(suite->tests, test_create(#test_fn, test_fn))

#endif

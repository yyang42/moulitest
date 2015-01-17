
#ifndef FW_H
# define FW_H

# include <mt.h>

#define mt_assert_base(cond, msg, signum) test_assert_prep(test, #cond, msg, signum); test_assert(test, (cond))
#define mt_assert_msg(cond, msg) mt_assert_base(cond, msg, 0)
#define mt_assert(cond) mt_assert_base(cond, NULL, 0)
#define mt_assert_signal(cond, signum) mt_assert_base(cond, NULL, signum)
#define MT_ADD_SUITE(mt, name, suite_fn) lst_push(mt->suites, lst_create_elem(suite_create(#name, suite_fn)))
#define SUITE_ADD_TEST_BASE(suite, test_fn, timeout) lst_push(suite->tests, lst_create_elem(test_create(#test_fn, test_fn, timeout)))
#define SUITE_ADD_TEST(suite, test_fn) SUITE_ADD_TEST_BASE(suite, test_fn, DEFAULT_TIMEOUT_UTIME)
#define SUITE_ADD_TEST_TIMEOUT(suite, test_fn, timeout) SUITE_ADD_TEST_BASE(suite, test_fn, timeout)

#endif

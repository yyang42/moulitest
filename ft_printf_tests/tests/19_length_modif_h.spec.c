#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_simple(t_test *test)
{
	// debug_next_assert();
	raise(SIGSEGV);
	assert_printf("%d", 42);
}

static void test_simple2(t_test *test)
{
	// debug_next_assert();
	assert_printf("%s", "42");
}

void	suite_19_length_modif_h(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_simple2);

}

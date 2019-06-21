#include <project.h>
#include <limits.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%s %d %p %% %x", "bonjour ", 42, &free, 42);
}

static void test_hard(t_test *test)
{
	// test->debug = 1;
	char c;
	assert_printf("%s%d%p%%%i%o%u%x%X%c","bonjour", 42, &c, 42, 42, 42, 42, 42, 'c');
}

void	suite_18_mix_all_previous(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_hard);
}

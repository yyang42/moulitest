#include <project.h>

#include <signal.h>

static void test_percent_alone(t_test *test)
{
	// test->debug = 1;
	assert_printf("%%");
}

static void test_percent_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("aa%%bb");
}

static void test_many_percent(t_test *test)
{
	// test->debug = 1;
	assert_printf("%%%%%%%%%%");
}

static void test_more_percent(t_test *test)
{
	// test->debug = 1;
	assert_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
}

static void test_modulo_without_valid_specifier(t_test *test)
{
	// test->debug = 1;
	assert_printf("%");
}

static void percentSpaceZoo(t_test *test)
{
	// test->debug = 1;
	assert_printf("% Zoooo");
}

static void percentAlone(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%}");
}

static void multiplePercent(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% %}");
}

void	suite_05_percent_escape(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_percent_alone);
	SUITE_ADD_TEST(suite, test_percent_simple);
	SUITE_ADD_TEST(suite, test_many_percent);
	SUITE_ADD_TEST(suite, test_more_percent);
	SUITE_ADD_TEST(suite, test_modulo_without_valid_specifier);
	SUITE_ADD_TEST(suite, percentSpaceZoo);
	SUITE_ADD_TEST(suite, percentAlone);
	SUITE_ADD_TEST(suite, multiplePercent);
}

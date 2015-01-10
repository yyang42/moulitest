#include <project.h>

#define mt_assert_atoi(str) mt_assert(ft_atoi(str) == atoi(str))

static void test_misc(t_test *test)
{
	mt_assert(ft_atoi(" -sfecf") == atoi(" -sfecf"));
	mt_assert(ft_atoi("") == atoi(""));
	mt_assert(ft_atoi("+2798") == atoi("+2798"));
	mt_assert(ft_atoi("+0089") == atoi("+0089"));
	mt_assert(ft_atoi("a56") == atoi("a56"));
	mt_assert(ft_atoi("      --s8") == atoi("      --s8"));
	mt_assert(ft_atoi("0001020304") == atoi("0001020304"));
	mt_assert(ft_atoi("000000000000000110") == atoi("000000000000000110"));
	mt_assert(ft_atoi("-153") == atoi("-153"));
	mt_assert(ft_atoi("+132") == atoi("+132"));
	mt_assert(ft_atoi("++876") == atoi("++876"));
	mt_assert(ft_atoi("--132") == atoi("--132"));
	mt_assert(ft_atoi("dwbk ") == atoi("dwbk "));
	mt_assert(ft_atoi(" 1") == atoi(" 1"));
	mt_assert(ft_atoi("42jk ") == atoi("42jk "));
	mt_assert(ft_atoi(" 21") == atoi(" 21"));
	mt_assert(ft_atoi("     32 ") == atoi("     32 "));
	mt_assert(ft_atoi("\n          42 24") == atoi("\n          42 24"));
	mt_assert(ft_atoi("1-2") == atoi("1-2"));
	mt_assert(ft_atoi("4+2") == atoi("4+2"));
	mt_assert(ft_atoi("  +442") == atoi("  +442"));
	mt_assert(ft_atoi("  -4232") == atoi("  -4232"));
	mt_assert(ft_atoi("4,5") == atoi("4,5"));
	mt_assert(ft_atoi("+") == atoi("+"));
	mt_assert(ft_atoi("-") == atoi("-"));
	mt_assert(ft_atoi("-+1") == atoi("-+1"));
	mt_assert(ft_atoi("+-1") == atoi("+-1"));
	mt_assert(ft_atoi("\200123") == atoi("\200123"));
	mt_assert(ft_atoi("123\200") == atoi("123\200"));
}

static void test_trim(t_test *test)
{
	mt_assert_atoi("  \t\n  \r\r\v\f-899");
}

static void test_extrem_values(t_test *test)
{
	mt_assert_atoi("-2147483648");
	mt_assert_atoi("2147483647");
}

void	suite_00_part1_ft_atoi(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_misc);
	SUITE_ADD_TEST(suite, test_trim);
	SUITE_ADD_TEST(suite, test_extrem_values);
}

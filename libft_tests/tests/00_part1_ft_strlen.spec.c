#include <project.h>

#define mt_test_strlen(test_name, tested_str) \
	static void unit## test_name(t_test *test) \
	{ \
		mt_assert(ft_strlen(tested_str) == strlen(tested_str)); \
	}

mt_test_strlen(test1, "chat");
mt_test_strlen(test2, "");
mt_test_strlen(test3, "aaa\0aaa");

static void test_10_million_chars_string(t_test *test)
{
	int test_len = 10 * 1000 * 1000;
	char str[test_len];
	memset(str, 'a', test_len);

	str[test_len - 1] = '0';
	mt_assert(ft_strlen(str) == strlen(str));
}
void	suite_00_part1_ft_strlen(t_suite *suite)
{
	SUITE_ADD_TEST(suite, unittest1);
	SUITE_ADD_TEST(suite, unittest2);
	SUITE_ADD_TEST(suite, unittest3);
	SUITE_ADD_TEST(suite, test_10_million_chars_string);
}

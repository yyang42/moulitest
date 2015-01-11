#include "project.h"

#define mt_test_strstr(test_name, s1, s2) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(ft_strstr(s1, s2) == strstr(s1, s2)); \
	}

static char	buf[] = "Ceci n'est pas une pipe.";
static char	buf2[] = "ozarabozaraboze";

mt_test_strstr(num1, buf, "une");
mt_test_strstr(num2, buf, "C");
mt_test_strstr(num3, buf, ".");
mt_test_strstr(num4, buf, "");
mt_test_strstr(num5, buf, "aaaaa");
mt_test_strstr(num6, buf2, "ozaraboze");
mt_test_strstr(num7, buf, "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
mt_test_strstr(num8, "", "");
mt_test_strstr(num9, buf, "une");

void	suite_00_part1_ft_strstr(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
	SUITE_ADD_TEST(suite, test_num9);
}

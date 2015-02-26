#include <project.h>

#define mt_test_tolower(test_name, tested_char)								\
	static void test_## test_name(t_test *test)								\
	{																		\
		mt_assert(ft_tolower(tested_char) == tolower(tested_char));			\
	}

mt_test_tolower(num1, 'a');
mt_test_tolower(num2, 'a' + 0x100);
mt_test_tolower(num3, '2');
mt_test_tolower(num4, 'Z');
mt_test_tolower(num5, 't');
mt_test_tolower(num6, 0);
mt_test_tolower(num7, 1);
mt_test_tolower(num8, 9999);
mt_test_tolower(num9, '1');
mt_test_tolower(num10, '2');
mt_test_tolower(num11, 'A');
mt_test_tolower(num12, 'Z');
mt_test_tolower(num13, ' ');
mt_test_tolower(num14, '%');
mt_test_tolower(num15, '\t');
mt_test_tolower(num16, '\n');
mt_test_tolower(num17, '\v');
mt_test_tolower(num18, '\b');
mt_test_tolower(num19, 7);

void	suite_00_part1_ft_tolower(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);
	SUITE_ADD_TEST(suite, test_num13);
	SUITE_ADD_TEST(suite, test_num14);
	SUITE_ADD_TEST(suite, test_num15);
	SUITE_ADD_TEST(suite, test_num16);
	SUITE_ADD_TEST(suite, test_num17);
	SUITE_ADD_TEST(suite, test_num18);
	SUITE_ADD_TEST(suite, test_num19);
}

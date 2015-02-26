#include <project.h>

#define mt_test_toupper(test_name, tested_char)								\
	static void test_## test_name(t_test *test)								\
	{																		\
		mt_assert(ft_toupper(tested_char) == toupper(tested_char));			\
	}

mt_test_toupper(num1, 'a');
mt_test_toupper(num2, 'a' + 0x100);
mt_test_toupper(num3, '2');
mt_test_toupper(num4, 'Z');
mt_test_toupper(num5, 't');
mt_test_toupper(num6, 0);
mt_test_toupper(num7, 1);
mt_test_toupper(num8, 9999);
mt_test_toupper(num9, '1');
mt_test_toupper(num10, '2');
mt_test_toupper(num11, 'A');
mt_test_toupper(num12, 'Z');
mt_test_toupper(num13, ' ');
mt_test_toupper(num14, '%');
mt_test_toupper(num15, '\t');
mt_test_toupper(num16, '\n');
mt_test_toupper(num17, '\v');
mt_test_toupper(num18, '\b');
mt_test_toupper(num19, 7);

void	suite_00_part1_ft_toupper(t_suite *suite)
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

#include <project.h>

#define mt_test_isascii(test_name, tested_char)												\
	static void test_## test_name(t_test *test)												\
	{																						\
		mt_assert((ft_isascii(tested_char) != 0) == (isascii(tested_char) != 0));			\
	}

mt_test_isascii(num1, 'a');
mt_test_isascii(num2, 'a' + 0x100);
mt_test_isascii(num3, '2');
mt_test_isascii(num4, 'Z');
mt_test_isascii(num5, 't');
mt_test_isascii(num6, 0);
mt_test_isascii(num7, 1);
mt_test_isascii(num8, 9999);
mt_test_isascii(num9, '1');
mt_test_isascii(num10, '2');
mt_test_isascii(num11, 'A');
mt_test_isascii(num12, 'Z');
mt_test_isascii(num13, ' ');
mt_test_isascii(num14, '%');
mt_test_isascii(num15, '\t');
mt_test_isascii(num16, '\n');
mt_test_isascii(num17, '\v');
mt_test_isascii(num18, '\b');
mt_test_isascii(num19, 7);
mt_test_isascii(num20, -42);

static void	big_test(t_test *test)
{
	int i;

	i = -300;
	while (!ft_isascii(i) == !isascii(i) && i < 255)
		++i;
	mt_assert(i == 255);
}

void	suite_00_part1_ft_isascii(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num20);
	SUITE_ADD_TEST(suite, big_test);
}

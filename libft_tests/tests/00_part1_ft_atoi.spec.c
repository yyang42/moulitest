#include <project.h>

#define mt_test_atoi(test_name, tested_str) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(ft_atoi(tested_str) == atoi(tested_str)); \
	}

mt_test_atoi(num1, " -sfecf");
mt_test_atoi(num2, "");
mt_test_atoi(num3, "+2798");
mt_test_atoi(num4, "+0089");
mt_test_atoi(num5, "a56");
mt_test_atoi(num6, "      --s8");
mt_test_atoi(num7, "0001020304");
mt_test_atoi(num8, "000000000000000110");
mt_test_atoi(num9, "-153");
mt_test_atoi(num10, "+132");
mt_test_atoi(num11, "++876");
mt_test_atoi(num12, "--132");
mt_test_atoi(num13, "dwbk ");
mt_test_atoi(num14, " 1");
mt_test_atoi(num15, "42jk ");
mt_test_atoi(num16, " 21");
mt_test_atoi(num17, "     32 ");
mt_test_atoi(num18, "\n          42 24");
mt_test_atoi(num19, "1-2");
mt_test_atoi(num20, "4+2");
mt_test_atoi(num21, "  +442");
mt_test_atoi(num22, "  -4232");
mt_test_atoi(num23, "4,5");
mt_test_atoi(num24, "+");
mt_test_atoi(num25, "-");
mt_test_atoi(num26, "-+1");
mt_test_atoi(num27, "+-1");
mt_test_atoi(num28, "\200123");
mt_test_atoi(num29, "123\200");
mt_test_atoi(num30, "  \t\n  \r\r\v\f-899");
mt_test_atoi(num31, "-2147483648");
mt_test_atoi(num32, "2147483647");

void	suite_00_part1_ft_atoi(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num21);
	SUITE_ADD_TEST(suite, test_num22);
	SUITE_ADD_TEST(suite, test_num23);
	SUITE_ADD_TEST(suite, test_num24);
	SUITE_ADD_TEST(suite, test_num25);
	SUITE_ADD_TEST(suite, test_num26);
	SUITE_ADD_TEST(suite, test_num27);
	SUITE_ADD_TEST(suite, test_num28);
	SUITE_ADD_TEST(suite, test_num29);
	SUITE_ADD_TEST(suite, test_num30);
	SUITE_ADD_TEST(suite, test_num31);
	SUITE_ADD_TEST(suite, test_num32);
}

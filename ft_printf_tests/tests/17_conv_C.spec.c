#include <project.h>

static void test_simple_char(t_test *test)
{
	// test->debug = 1;
	assert_printf("%C", 'c');
}

static void test_two_chars(t_test *test)
{
	// debug_next_a	ssert();
	assert_printf("%C%C", '4', '2');
}

static void test_ascii_printable_chars(t_test *test)
{
	// test->debug = 1;
	assert_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
}

static void test_chinese(t_test *test)
{
	// test->debug = 1;
	assert_printf("%C", L'猫');
}

static void test_greek(t_test *test)
{
	// test->debug = 1;
	assert_printf("%C", L'δ');
}


static void test_korean(t_test *test)
{
	// test->debug = 1;
	assert_printf("%C", L'요');
}

static void test_japanese(t_test *test)
{
	// test->debug = 1;
	assert_printf("%C", L'莨');
}

static void test_arabic(t_test *test)
{
	// test->debug = 1;
	assert_printf("%C", L'ي');
}

static void test_nullChar(t_test *test)
{
	// test->debug = 1;
	assert_printf("%C", 0);
}

void	suite_17_conv_C(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_char);
	SUITE_ADD_TEST(suite, test_two_chars);
	SUITE_ADD_TEST(suite, test_ascii_printable_chars);
	SUITE_ADD_TEST(suite, test_chinese);
	SUITE_ADD_TEST(suite, test_greek);
	SUITE_ADD_TEST(suite, test_korean);
	SUITE_ADD_TEST(suite, test_japanese);
	SUITE_ADD_TEST(suite, test_arabic);
	SUITE_ADD_TEST(suite, test_nullChar);
}

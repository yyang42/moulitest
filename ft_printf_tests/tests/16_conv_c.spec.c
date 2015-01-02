#include <project.h>

static void test_simple_char(t_test *test)
{
	// test->debug = 1;
	assert_printf("%c", 'c');
}

static void test_two_chars(t_test *test)
{
	// test->debug = 1;
	assert_printf("%c%c", '4', '2');
}

static void test_ascii_printable_chars(t_test *test)
{
	// test->debug = 1;
	assert_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
}

static void test_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("%c", 0);
}	

void	suite_16_conv_c(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_char);
	SUITE_ADD_TEST(suite, test_two_chars);
	SUITE_ADD_TEST(suite, test_ascii_printable_chars);
	SUITE_ADD_TEST(suite, test_zero);
}

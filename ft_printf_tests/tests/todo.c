#include <project.h>

static void todo(t_test *test)
{
	// error handling
	assert_printf("%o", -42);
	assert_printf("%O", LONG_MIN);
	assert_printf("%u", -42);
	assert_printf("%u", UINT_MAX + 1);
	assert_printf("%U", ULONG_MAX + 1);
}

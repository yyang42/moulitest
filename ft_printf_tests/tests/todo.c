#include <project.h>

static void todo(t_test *test)
{
	// error handling
	assert_printf("%o", -42);
	assert_printf("%o", LONG_MAX);
	assert_printf("%O", LONG_MIN);
	assert_printf("%u", -42);
	assert_printf("%u", UINT_MAX + 1);
	assert_printf("%U", ULONG_MAX + 1);
	assert_printf("%c", 200);
	assert_printf("%lx, %lx", 0, ULONG_MAX * 0.75);
	assert_printf("%hhd", SHRT_MAX);
	assert_printf("%zi", LLONG_MIN);
	assert_printf("%zd", LLONG_MIN);
	assert_printf("%+o", 42);
	assert_printf("%#+12.45llp", 42645454564);
}

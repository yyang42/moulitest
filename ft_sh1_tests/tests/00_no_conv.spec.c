#include <project.h>
#include <stdio.h>
#include <mt_xstdio.h>

static void failing_test(t_test *test)
{
	system("printf 'cd /usr\npwd\nexit\n' | "RENDU_PATH"/ft_sh1 > output_raw");
	system("cat output_raw | grep /usr > output_test");
	mt_assert(!mt_xstdio_isempty("./output_test"));
}

void	suite_00_no_conv(t_suite *suite)
{
	SUITE_ADD_TEST(suite, failing_test);
}

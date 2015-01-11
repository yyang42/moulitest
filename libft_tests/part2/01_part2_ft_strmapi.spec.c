#include "project.h"

UT_TEST(ft_strmapi)
{
	char	*src;
	char	*dst;

	src = strdup("abcde");
	dst = ft_strmapi(src, mapi_test);

	free(src); src = NULL;

	UT_ASSERT_EQ(strcmp(dst, "acegi"), 0);
}

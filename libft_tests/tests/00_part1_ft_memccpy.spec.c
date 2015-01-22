#include <project.h>

#define mt_test_memccpy(test_name, src, c, size) \
	static void test_## test_name(t_test *test) \
	{ \
		char ft_memccpy_buf[size], memccpy_buf[size]; \
		char *ft_memccpy_ret, *memccpy_ret; \
		bzero(ft_memccpy_buf, size); \
		bzero(memccpy_buf, size); \
		ft_memccpy_ret = ft_memccpy(ft_memccpy_buf, src, c, size); \
		memccpy_ret = memccpy(memccpy_buf, src, c, size); \
		mt_assert((!!ft_memccpy_ret == !!memccpy_ret)); \
		if (!!ft_memccpy_ret && !!memccpy_ret) \
			mt_assert(memcmp(ft_memccpy_ret, memccpy_ret, size) == 0); \
		mt_assert((!!ft_memccpy_ret == !!memccpy_ret) || (memcmp(ft_memccpy_ret, memccpy_ret, size) == 0)); \
		mt_assert(memcmp(ft_memccpy_buf, memccpy_buf, size) == 0); \
	}

mt_test_memccpy(01, "Ceci est un test.", 'i', 10);
mt_test_memccpy(02, "Ceci est un test.", 'k', 5);
mt_test_memccpy(03, "Ceci est un test.", 0, 0);
mt_test_memccpy(04, "Ceci est un test.", 'C', 10);
mt_test_memccpy(05, "", ' ', 0);

static void another_test(t_test *test)
{
	char dest[] = "abcdefghijklmnopqrstuvwxyz";
	mt_assert(ft_memccpy(dest, strdup("test\200string"), '\200', 12) ==
		memccpy(dest, strdup("test\200string"), '\200', 12));
}

void	suite_00_part1_ft_memccpy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, another_test);
}

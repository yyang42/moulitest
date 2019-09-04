#include <project.h>

static void test1(t_test *test)
{
	t_list	*list;
	int		ft;

	ft = 42;
	list = ft_lstnew(&ft, sizeof(int));
	mt_assert(!!list);
	mt_assert((*(int*)(list->content)) == 42);
	list = ft_lstnew(NULL, 386);
	mt_assert((list->content_size) == 0);
}

static void test2(t_test *test)
{
	t_list	*lst;
	size_t	tl = 50;
	char	t[tl];
	char	*bjr;

	memset(t, 'k', tl);
	lst = ft_lstnew(t, tl);
	bjr = malloc(10);
	mt_assert(lst->content != t);
	mt_assert(memcmp(lst->content, t, tl) == 0);
	mt_assert(lst->content_size == tl);
	mt_assert(memcmp(bjr, "kkkkkkkkkk", 10));
	free(bjr);
}

void	suite_02_bonus_ft_lstnew(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
}

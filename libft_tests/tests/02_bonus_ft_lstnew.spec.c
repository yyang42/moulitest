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

void	suite_02_bonus_ft_lstnew(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}

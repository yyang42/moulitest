#include <project.h>

void	lstiter_test(t_list *ppp)
{
	ppp->content_size = 42;
}

static void test1(t_test *test)
{
	t_list	*list;

	bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
	bzero(((list->next) = malloc(sizeof(t_list))), sizeof(t_list));
	ft_lstiter(list, lstiter_test);
	mt_assert(list->content_size == 42);
	mt_assert(list->next->content_size == 42);
}

void	suite_02_bonus_ft_lstiter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}

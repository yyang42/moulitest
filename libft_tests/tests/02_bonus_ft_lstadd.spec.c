#include <project.h>

static void test1(t_test *test)
{
	t_list	*list;
	t_list	*list2;

	list = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	bzero(list, sizeof(t_list));
	bzero(list2, sizeof(t_list));
	ft_lstadd(&list2, list);
	mt_assert(list == list2);
	mt_assert(list->next != NULL);
}

void	suite_02_bonus_ft_lstadd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}

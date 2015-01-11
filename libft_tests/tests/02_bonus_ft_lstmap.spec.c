#include <project.h>

t_list	*lstmap_test_fn(t_list *list)
{
	t_list	*l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}

static void test1(t_test *test)
{
	t_list	*list;
	t_list	*map;

	bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
	bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
	list->content_size = 21;
	list->content = strdup("abc");
	list->next->content_size = 100;
	list->next->content = strdup("abc");
	map = ft_lstmap(list, lstmap_test_fn);
	mt_assert(list->content_size == 21);
	mt_assert(list->next->content_size == 100);
	mt_assert(map->content_size == 42);
	mt_assert(map->next->content_size == 200);
}

void	suite_02_bonus_ft_lstmap(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
}

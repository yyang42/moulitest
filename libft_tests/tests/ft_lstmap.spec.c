t_list	*list;
t_list	*map;

bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
list->content_size = 21;
list->next->content_size = 100;
map = ft_lstmap(list, lstmap_test);
UT_ASSERT_EQ(list->content_size, 21);
UT_ASSERT_EQ(list->next->content_size, 100);
UT_ASSERT_EQ(map->content_size, 42);
UT_ASSERT_EQ(map->next->content_size, 200);
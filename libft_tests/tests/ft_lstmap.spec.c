t_list	*list;
t_list	*list2;
t_list	*map;

bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
list->content_size = 21;
list->content = strdup("abc");
list->next->content_size = 100;
list->next->content = strdup("abc");
map = ft_lstmap(list, lstmap_test);
UT_ASSERT_EQ(list->content_size, 21);
UT_ASSERT_EQ(list->next->content_size, 100);
UT_ASSERT_EQ(map->content_size, 42);
UT_ASSERT_EQ(map->next->content_size, 200);

/* NE PAS TENIR COMPTE

bzero((list2 = malloc(sizeof(t_list))), sizeof(t_list)); list2->content_size = 10; map = ft_lstmap(list2, lstmap_test); UT_ASSERT_EQ(map->content_size, 0);

*/

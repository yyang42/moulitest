/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 18:58:31 by celegran          #+#    #+#             */
/*   Updated: 2015/02/27 10:37:35 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <fw.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isalpha(int i);
int		ft_isalnum(int i);
int		ft_isprint(int i);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strcat(char *s1, char *s2);
void	ft_bzero(void *s, int n);
void	*ft_memset(void *s, int c, int n);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strdup(char *s);
void	ft_cat(int fd);
int		ft_puts(const char *s);;


#define mt_test_is_something_one(fn_name, test_name, tested_char)								\
	static void test_## test_name(t_test *test)								\
	{																		\
		mt_assert(ft_ ##fn_name(tested_char) == fn_name(tested_char));			\
	}

#define mt_test_is_something(fn_name) \
	mt_test_is_something_one(fn_name, num1, 'a'); \
	mt_test_is_something_one(fn_name, num2, 'a' - 1); \
	mt_test_is_something_one(fn_name, num3, 'm'); \
	mt_test_is_something_one(fn_name, num4, 'z'); \
	mt_test_is_something_one(fn_name, num5, 'z' + 1); \
	mt_test_is_something_one(fn_name, num6, 'A'); \
	mt_test_is_something_one(fn_name, num7, 'A' - 1); \
	mt_test_is_something_one(fn_name, num8, 'M'); \
	mt_test_is_something_one(fn_name, num9, 'Z'); \
	mt_test_is_something_one(fn_name, num10, 'Z' + 1); \
	mt_test_is_something_one(fn_name, num11, ' '); \
	mt_test_is_something_one(fn_name, num12, '%'); \
	mt_test_is_something_one(fn_name, num13, '\t'); \
	mt_test_is_something_one(fn_name, num14, '\n'); \
	mt_test_is_something_one(fn_name, num15, '\v'); \
	mt_test_is_something_one(fn_name, num16, '\b'); \
	mt_test_is_something_one(fn_name, num17, '0'); \
	mt_test_is_something_one(fn_name, num18, '0' - 1); \
	mt_test_is_something_one(fn_name, num19, '5'); \
	mt_test_is_something_one(fn_name, num20, '9'); \
	mt_test_is_something_one(fn_name, num21, '9' + 1); \
	mt_test_is_something_one(fn_name, num22, 0); \
	mt_test_is_something_one(fn_name, num23, 1); \
	mt_test_is_something_one(fn_name, num24, 127); \
	mt_test_is_something_one(fn_name, num25, 128); \
	mt_test_is_something_one(fn_name, num26, -128); \
	mt_test_is_something_one(fn_name, num27, -129); \
	mt_test_is_something_one(fn_name, num28, 9999); \
	mt_test_is_something_one(fn_name, num29, -42); \
	mt_test_is_something_one(fn_name, num30, 31); \
	mt_test_is_something_one(fn_name, num31, 32); \
	mt_test_is_something_one(fn_name, num32, 33); \
	void	suite_01_part1_ft_ ##fn_name(t_suite *suite) \
	{ \
		SUITE_ADD_TEST(suite, test_num1); \
		SUITE_ADD_TEST(suite, test_num2); \
		SUITE_ADD_TEST(suite, test_num3); \
		SUITE_ADD_TEST(suite, test_num4); \
		SUITE_ADD_TEST(suite, test_num5); \
		SUITE_ADD_TEST(suite, test_num6); \
		SUITE_ADD_TEST(suite, test_num7); \
		SUITE_ADD_TEST(suite, test_num8); \
		SUITE_ADD_TEST(suite, test_num9); \
		SUITE_ADD_TEST(suite, test_num10); \
		SUITE_ADD_TEST(suite, test_num11); \
		SUITE_ADD_TEST(suite, test_num12); \
		SUITE_ADD_TEST(suite, test_num13); \
		SUITE_ADD_TEST(suite, test_num14); \
		SUITE_ADD_TEST(suite, test_num15); \
		SUITE_ADD_TEST(suite, test_num16); \
		SUITE_ADD_TEST(suite, test_num17); \
		SUITE_ADD_TEST(suite, test_num18); \
		SUITE_ADD_TEST(suite, test_num19); \
		SUITE_ADD_TEST(suite, test_num20); \
		SUITE_ADD_TEST(suite, test_num21); \
		SUITE_ADD_TEST(suite, test_num22); \
		SUITE_ADD_TEST(suite, test_num23); \
		SUITE_ADD_TEST(suite, test_num24); \
		SUITE_ADD_TEST(suite, test_num25); \
		SUITE_ADD_TEST(suite, test_num26); \
		SUITE_ADD_TEST(suite, test_num27); \
		SUITE_ADD_TEST(suite, test_num28); \
		SUITE_ADD_TEST(suite, test_num29); \
		SUITE_ADD_TEST(suite, test_num30); \
		SUITE_ADD_TEST(suite, test_num31); \
		SUITE_ADD_TEST(suite, test_num32); \
	}


#endif
